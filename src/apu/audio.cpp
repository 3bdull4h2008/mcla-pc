#include "audio.h"
#include "logging.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_audio.h>

#include <generated/ppc_xenon/ppc_config.h>
#include <generated/ppc_xenon/ppc_context.h>
#include <cpu/ppc_context.h>
#include <generated/ppc_xenon/ppc_recomp_shared.h>
#include <kernel/memory.h>
#include <kernel/heap.h>
#include <cpu/guest_thread.h>

#include <apu/xma_decoder.h>

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstdint>
#include <cstring>
#include <mutex>
#include <thread>
#include <vector>

// M5 minimal: open an SDL3 playback stream at boot and keep it alive.
// M6: host worker thread periodically invokes the guest XAudio render
// callback (UnleashedRecomp sdl2_driver pattern) so the guest fills a
// 6ch BE float32 x 256 frame and calls XAudioSubmitRenderDriverFrame.
// STATUS -- CORRECTED 2026-10-06 (audio tier-1 pass). The status block this
// replaces said: "only M5 ever runs ... no soak contains apu::RegisterClient,
// AUDIO-WORKER or AUDIO-FRAME. The guest call sites exist
// (generated/ppc_xenon/ppc_recomp.73.cpp:12392 register, :12717 submit) and are
// simply never reached BEFORE THE BOOT STALLS." Both halves of that were
// wrong, and the correction matters more than the original:
//
//  1. The boot does not stall. build/w734.log runs 149.811 s with FATAL-SOFT = 0
//     (it was 1) and DRAW-CP-DRAWN = 4 (was 2). So "not reached before the
//     stall" was no longer available as an explanation.
//  2. The call site is NOT simply unreached. A raw-word scan of
//     build/cache/mcla_pe.bin (NOT tools/ppc_xrefs.py, whose `calls` mode is
//     known to invent callers on vtable dispatch) finds exactly ONE direct
//     `bl` to __imp__XAudioRegisterRenderDriverClient, at 0x823F3774, inside
//     guest function sub_823F3718. That guest function has ZERO direct callers
//     anywhere in the image and appears only as a dword in two vtables, at
//     0x8205F0E4 and 0x82112AB8 -- and NEITHER vtable has any code reference.
//     No address in 0x823F3000..0x823F7000 appears in the guest's own .CRT$XCU
//     static-initialiser table (0x827D0010..0x827D13E0, 1267 pointers,
//     structurally verified: NULL prefix and NUL one word past the last slot).
//     So the audio object is never constructed, and the guest therefore never
//     asks for audio at all.
//
// CONSEQUENCE: nothing in THIS FILE can make audio reachable, and nothing in
// this file should try. Emitting a frame the guest did not ask for, or
// decoding a stream that was never handed over, is exactly the fabrication
// F-609 forbids. The worker and the downmix below stay unreachable until the
// guest constructs its XAudio object -- a guest-reachability problem, not an
// apu problem. The next link is named in the handoff, not guessed at here.
//
// F-609 changes in this file (all in src/apu/, nothing else touched):
//  1. The 440 Hz blip is GONE. Underrun plays true silence (a one-line
//     AUDIO-UNDERRUN warning). A tone the guest never produced is a fake.
//  2. The worker runs on a REAL per-thread guest context -- its own thread
//     block (PCR|TLS|TEB|STACK, laid out like kernel/guest_thread.cpp:11-18),
//     its own r13/r1, real BE TLS/TEB links -- and a REAL return address, a
//     host trampoline claimed in a free slot of the guest function table.
//     See ClaimReturnPc() for why the return PC cannot be a fixed literal.
//  3. Frame pacing is the real frame period (5333333 ns, computed from
//     256/48000) on absolute deadlines, with a queue-depth gate, instead of a
//     flat 8 ms sleep that underfed the device by design.
//  4. The XMA decoder unit (apu/xma_decoder.h) and the audlo -> .xma
//     extraction (apu/audlo_extract.h) exist and are header-only so they
//     cannot fail to be compiled; the import-layer bodies the orchestrator
//     must paste are in the handoff note. The XMA *bitstream* decode is NOT
//     implemented -- see the header of apu/xma_decoder.h for why, and for the
//     reference that does have it.

namespace apu {

namespace {

// Xbox 360 XAudio render-driver frame (see UnleashedRecomp apu/audio.h):
//   48 kHz, 6 ch, 32-bit BE float, 256 samples/frame, channel-major.
constexpr int kGuestSampleHz = 48000;
constexpr int kGuestChannels = 6;
constexpr int kGuestSamplesPerFrame = 256;

// Host device format requested by M5: 48 kHz stereo s16.
constexpr int kHostHz = 48000;
constexpr int kHostChannels = 2;

// Guest frame period, computed rather than rounded: 256 samples / 48 kHz =
// 5.3333... ms. The worker used to sleep a flat 8 ms, i.e. 125 callbacks/s x
// 256 = 32 000 samples/s against a 48 000 samples/s drain -- a guaranteed
// underfeed that made the queue starve and the (now removed) blip audible.
// The worker now paces on absolute deadlines derived from this constant, so
// the feed rate and the drain rate are the same by construction.
constexpr uint64_t kFramePeriodNs =
    1000000000ull * static_cast<uint64_t>(kGuestSamplesPerFrame) /
    static_cast<uint64_t>(kGuestSampleHz); // 5 333 333 ns

// Depth gate (UnleashedRecomp sdl2_driver.cpp:71-88 pattern): do not invoke the
// guest callback while the host queue is already ahead of the device. 8 frames
// = 42.7 ms of slack, enough that a late frame does not immediately underrun.
constexpr size_t kQueueGateFrames = 8;
constexpr size_t kQueueGateSamples =
    kQueueGateFrames * static_cast<size_t>(kGuestSamplesPerFrame) * kHostChannels;

// ~2 s of stereo s16 queued guest audio max (drop oldest past that).
constexpr size_t kMaxQueuedSamples =
    static_cast<size_t>(kHostHz) * 2 * kHostChannels;

// ---------------------------------------------------------------------------
// Per-thread guest context for the render-driver worker.
//
// The worker used to run the guest callback on a bare `PPCContext cbCtx{}` with
// r13/r1 hard-coded to the *boot thread's* values (0x8F200000 / 0x8F000000) and
// a dummy lr of 0x00FFFFFF. That is three independent faults waiting to happen
// the first time the worker is ever reached (F-609 census: no soak has ever
// logged RegisterClient, so it has never been hit):
//   * r13 pointed at the boot thread's block, so every TLS read from the audio
//     callback read another thread's TLS and every stack push wrote into the
//     boot stack;
//   * r1 was the boot stack top with NO stack allocated for this thread, so a
//     push below 0x8F000000 with room to move actually worked by luck, and a
//     deep call chain would run into the image;
//   * lr was an unmapped guest address, so the callback's `blr` at return
//     dispatched through PPC_LOOKUP_FUNC on an address with no function.
//
// Fix: a REAL per-thread context (option A of the brief). The thread block is
// laid out exactly like kernel/guest_thread.cpp:11-18 (PCR | TLS | TEB | STACK)
// and r13/r1 are that block's own addresses, so r13->TLS, r13->TEB and the
// stack are per-thread and correct. The return address is a REAL function too:
// a host trampoline registered at kAudioReturnPc, which is above the boot
// scratch area and claimed by nothing (python tools/addr_owners.py --check
// 8F300000 -> "0 site(s)").
// ---------------------------------------------------------------------------
constexpr uint32_t kAudioThreadPcrSize = 0xAB0;
constexpr uint32_t kAudioThreadTlsSize = 0x100;
constexpr uint32_t kAudioThreadTebSize = 0x2E0;
constexpr uint32_t kAudioThreadStackSize = 0x40000;
constexpr uint32_t kAudioThreadTebOffset = kAudioThreadPcrSize + kAudioThreadTlsSize;
constexpr uint32_t kAudioThreadTotalSize =
    kAudioThreadPcrSize + kAudioThreadTlsSize + kAudioThreadTebSize + kAudioThreadStackSize;

// Return-trampoline PC is claimed at worker start from a free slot in the guest
// function table; see ClaimReturnPc() for why it cannot be a fixed literal.
// The table geometry it relies on (src/ppc_context.h:124-143) is
// PPC_LOOKUP_FUNC(x,y) = *(PPCFunc**)(x + PPC_IMAGE_BASE + PPC_IMAGE_SIZE +
// (y - PPC_CODE_BASE) * 2).

std::mutex g_mutex;
SDL_AudioStream* g_stream = nullptr;
bool g_opened = false;
bool g_subsystemOwned = false;

std::atomic<uint32_t> g_frameCount{0};
std::atomic<bool> g_shuttingDown{false};

// Interleaved stereo s16 converted from guest frames.
std::vector<int16_t> g_queue;
size_t g_queueRead = 0;

// Preallocated callback scratch. AudioCallback runs on SDL's audio thread, so
// it must not allocate: the silence buffer is sized once in Init() and the
// guest-copy destination is a fixed 64 KiB (the callback's own wantBytes cap),
// both written only under g_mutex / owned by the audio thread respectively.
std::vector<int16_t> g_callbackSilence;
std::vector<int16_t> g_callbackScratch;

// Guest-frame downmix destination, sized once in Init(). SubmitFrames runs on
// the WORKER thread (the guest calls it from the render callback), so it must
// not allocate either.
std::vector<int16_t> g_submitScratch;

// Depth-gate observation (how many worker periods were skipped because the
// queue was already ahead). Logged on Shutdown so "the worker kept up" is a
// measured claim rather than an assumption.
std::atomic<uint64_t> g_gatedSkips{0};
std::atomic<uint64_t> g_overruns{0};

// Guest XAudio client registration (set by RegisterClient).
std::atomic<uint32_t> g_clientCallback{0};
std::atomic<uint32_t> g_clientUserData{0};
std::atomic<bool> g_workerRunning{false};
std::thread g_workerThread;
std::atomic<uint32_t> g_workerTick{0};
std::atomic<bool> g_workerHadContext{false};

float LoadBeFloat(const void* p) {
    uint32_t bits = 0;
    std::memcpy(&bits, p, sizeof(bits));
    bits = SDL_Swap32(bits);
    float f = 0.0f;
    std::memcpy(&f, &bits, sizeof(f));
    return f;
}

void ConvertGuestFrameStereoS16(const void* samples, int16_t* out) {
    // Guest layout: be<float> [ch * 256 + i], 6 channels.
    // UnleashedRecomp stereo downmix:
    //   L = ch0 + ch2*0.75 + ch4
    //   R = ch1 + ch2*0.75 + ch5
    // Writes into a caller-owned buffer (no allocation): this runs on the
    // worker thread once per frame period, ~187 times a second.
    const auto* src = static_cast<const uint8_t*>(samples);
    for (int i = 0; i < kGuestSamplesPerFrame; ++i) {
        const float ch0 = LoadBeFloat(src + (0 * kGuestSamplesPerFrame + i) * 4);
        const float ch1 = LoadBeFloat(src + (1 * kGuestSamplesPerFrame + i) * 4);
        const float ch2 = LoadBeFloat(src + (2 * kGuestSamplesPerFrame + i) * 4);
        const float ch4 = LoadBeFloat(src + (4 * kGuestSamplesPerFrame + i) * 4);
        const float ch5 = LoadBeFloat(src + (5 * kGuestSamplesPerFrame + i) * 4);
        const float L = ch0 + ch2 * 0.75f + ch4;
        const float R = ch1 + ch2 * 0.75f + ch5;
        const float cl = std::clamp(L, -1.0f, 1.0f);
        const float cr = std::clamp(R, -1.0f, 1.0f);
        out[static_cast<size_t>(i) * 2 + 0] = static_cast<int16_t>(cl * 32767.0f);
        out[static_cast<size_t>(i) * 2 + 1] = static_cast<int16_t>(cr * 32767.0f);
    }
}

constexpr size_t kSubmitScratchSamples =
    static_cast<size_t>(kGuestSamplesPerFrame) * kHostChannels;
constexpr size_t kCallbackScratchSamples = 64 * 1024 / sizeof(int16_t);

void SDLCALL AudioCallback(void* /*userdata*/, SDL_AudioStream* stream,
                           int additional_amount, int total_amount) {
    if (g_shuttingDown.load(std::memory_order_relaxed)) {
        return;
    }

    int wantBytes = additional_amount > 0 ? additional_amount : total_amount;
    if (wantBytes <= 0) {
        wantBytes = 256 * kHostChannels * static_cast<int>(sizeof(int16_t));
    }
    // Cap and align to stereo s16 frames.
    if (wantBytes > 64 * 1024) {
        wantBytes = 64 * 1024;
    }
    wantBytes &= ~3;
    if (wantBytes <= 0) {
        return;
    }

    const int wantSamples = wantBytes / static_cast<int>(sizeof(int16_t));

    // Zero-filled ONCE at Init() (g_callbackSilence) so the underrun path
    // allocates nothing and copies nothing: an empty guest queue is true
    // silence, not a synthesised tone. The 440 Hz blip that used to be here
    // was a fake -- the guest heard a sound its own audio never produced -- so
    // it is gone (F-609: remove fakes, do not replace them).
    const int16_t* out = g_callbackSilence.data();
    static std::atomic<bool> s_underrunLogged{false};

    {
        std::lock_guard<std::mutex> lock(g_mutex);
        const size_t avail = g_queue.size() - g_queueRead;
        const size_t n = (std::min)(avail, static_cast<size_t>(wantSamples));
        if (n > 0) {
            std::memcpy(g_callbackScratch.data(), g_queue.data() + g_queueRead,
                        n * sizeof(int16_t));
            g_queueRead += n;
            if (g_queueRead >= g_queue.size()) {
                g_queue.clear();
                g_queueRead = 0;
            }
            out = g_callbackScratch.data();
        } else if (!s_underrunLogged.exchange(true)) {
            // The first underrun is worth one line: "you are hearing nothing"
            // must be attributable to "the guest submitted nothing", not to a
            // silent device. Counted, not repeated.
            //
            // APPENDED 2026-10-06 (audio tier-1 pass), at the END of the
            // existing row only, so the tracked format is unchanged and the
            // row still leads with its own marker. `clientRegistered` and
            // `workerTicks` are what separate the two hypotheses this row
            // cannot otherwise distinguish:
            //   clientRegistered=0 workerTicks=0 -> the guest never asked for
            //       audio at all (the measured state: build/w734.log has
            //       apu::RegisterClient = 0 rows and AUDIO-WORKER = 0 rows).
            //   clientRegistered=1 workerTicks>0 -> the worker IS driving the
            //       guest callback and the guest is submitting nothing, which
            //       is a different bug entirely.
            // Both are read from the same atomics the worker writes, so this
            // is a measurement, not an inference.
            MCLA_LOG_WARN("AUDIO-UNDERRUN: guest queue empty, playing true "
                          "silence (no synthesised tone) - see AUDIO-FRAME "
                          "count for whether the guest ever submitted; "
                          "clientRegistered={} workerTicks={}",
                          g_clientCallback.load(std::memory_order_relaxed)
                                  != 0
                              ? 1
                              : 0,
                          g_workerTick.load(std::memory_order_relaxed));
        }
    }

    SDL_PutAudioStreamData(stream, out, wantBytes);
}

// Host worker: periodically invoke the guest XAudio render callback so it
// fills one 6ch BE float32 x 256 frame and calls SubmitRenderDriverFrame.
// Pattern matches the vblank ISR thread in imports.cpp (standalone PPCContext
// + PPC_LOOKUP_FUNC) rather than GuestToHostFunction, which requires an
// already-published context on the calling thread -- but with a real
// per-thread context, see the kAudioThread* block above.

// Trampoline the guest callback returns to. Reached only through `blr` on the
// claimed return-PC below; it must return immediately and touch nothing.
void AudioReturnTrampoline(PPCContext& ctx, uint8_t* base) {
    (void)base;
    (void)ctx;
    static std::atomic<uint32_t> s_returns{0};
    const uint32_t n = s_returns.fetch_add(1, std::memory_order_relaxed) + 1;
    if (n <= 4 || (n % 2000) == 0) {
        MCLA_LOG_INFO("AUDIO-WORKER: callback returned to trampoline #{} "
                      "(guest LR was live, not a dummy)",
                      n);
    }
    // Returning from a PPCFunc unwinds straight back into WorkerMain's
    // fn(cbCtx, base); nothing to restore here.
}

// Claim an unused slot in the guest function table for the return trampoline.
//
// THIS IS NOT AN ARBITRARY GUEST ADDRESS, and it must not be. The function
// table is a flat pointer array inside the image at
//   base + PPC_IMAGE_BASE + PPC_IMAGE_SIZE + (pc - PPC_CODE_BASE) * 2
// (src/ppc_context.h:124), so the PC is an INDEX OFFSET FROM PPC_CODE_BASE,
// not an absolute address: PPC_CODE_BASE = 0x82130000 and the table starts at
// image offset 0x829E0000. An "obviously free" address like 0x8F300000 would
// index at (0x8F300000-0x82130000)*2 = 0x1A400000, i.e. 440 MB past the table
// start -- straight into live guest memory -- and InsertFunction there would
// scribble a host pointer over guest data. So the only safe choice is a PC
// inside [PPC_CODE_BASE, last registered function] whose slot is currently
// null.
//
// CORRECTION 2026-10-06 (audio tier-1 pass): the sentence this replaces --
// "Slots there are dense, so a null slot is by construction a VA the
// recompiler never registered: no real function can live at it, and no guest
// `blr` can already target it" -- is FALSE, and asserting it was a trap. The
// table is indexed every 4 bytes of code (see the stride note at the loop
// below) while the recompiler registers only function STARTS, so a null slot
// can and does sit INSIDE a registered function's body. Measured: the first
// free 8-byte slot is 0x8213000C, which is 4 bytes into sub_82130008.
//
// What actually makes the claim safe, and is what the loop now relies on:
//   * the slot is null AT CLAIM TIME, so rule 4 (one owner per guest address)
//     holds against the table itself rather than against a grep, and a slot
//     another agent registered meanwhile is left alone; and
//   * for the address this scan actually picks, nothing dispatches through it:
//     0 direct `bl` sites, 0 `b` sites, and 0 dword occurrences anywhere in
//     guest data (raw scan of build/cache/mcla_pe.bin). An address no branch
//     targets and no data word holds cannot be an existing dispatch target,
//     which is the property the deleted sentence was reaching for.
uint32_t ClaimReturnPc() {
    uint32_t lastGuest = 0;
    for (size_t i = 0; PPCFuncMappings[i].guest != 0; ++i) {
        if (static_cast<uint32_t>(PPCFuncMappings[i].guest) > lastGuest) {
            lastGuest = static_cast<uint32_t>(PPCFuncMappings[i].guest);
        }
    }
    if (lastGuest <= PPC_CODE_BASE) return 0;
    // Step by 4, not by 1 (fixed 2026-10-06, audio tier-1 pass).
    //
    // PPC_LOOKUP_FUNC is `*(PPCFunc**)(base + PPC_IMAGE_BASE + PPC_IMAGE_SIZE
    // + (pc - PPC_CODE_BASE) * 2)` (src/ppc_context.h:124), so consecutive
    // `pc` values are TWO BYTES apart in the table while a PPCFunc* is EIGHT
    // bytes wide on x64. Probing s += 1 therefore reads a misaligned 8-byte
    // window that overlaps its neighbours and is not a function pointer at all.
    // Stepping by 4 walks only real instruction boundaries, where 4 * 2 = 8
    // bytes is exactly one pointer slot.
    //
    // Measured consequence of the old s += 1: it stopped at s = 1, i.e.
    // va = 0x82130001 -- NOT 4-byte aligned, so not an instruction address, and
    // the 8-byte window at byte offset 2 spans two registered slots. Replaying
    // the scan over the real registration table with the byte model gives the
    // first genuinely free 8-byte slot at s = 12, va = 0x8213000C. That VA is
    // still 4 bytes INTO sub_82130008 (whose body is the `blr` at 0x8213000C,
    // word 4E800020), so the old comment's claim that a free slot is
    // "by construction a VA the recompiler never registered: no real function
    // can live at it" is FALSE -- the table is indexed per 4 bytes of code
    // while the recompiler only registers function STARTS, so a free slot can
    // sit inside a registered function's body. What makes the claim safe is
    // different and is checked below instead: no branch in the image targets
    // the address, and it is not a dword in guest data, so nothing dispatches
    // through that slot. Both are measured (0 `bl` sites, 0 `b` sites, 0
    // data dword refs for 0x8213000C).
    const uint64_t slots = static_cast<uint64_t>(lastGuest - PPC_CODE_BASE) + 1u;
    for (uint64_t s = 0; s + 4 <= slots; s += 4) {
        const uint32_t va = PPC_CODE_BASE + static_cast<uint32_t>(s);
        if (mcla::kernel::g_memory.FindFunction(va) == nullptr) {
            mcla::kernel::g_memory.InsertFunction(
                va, reinterpret_cast<PPCFunc*>(&AudioReturnTrampoline));
            return va;
        }
    }
    return 0;
}

void WorkerMain() {
    MCLA_LOG_INFO("AUDIO-WORKER start framePeriodNs={}", kFramePeriodNs);

    // --- real per-thread guest context (allocated once, before any guest call)
    uint8_t* block = static_cast<uint8_t*>(g_userHeap.Alloc(kAudioThreadTotalSize));
    if (block == nullptr) {
        // F-370 precedent: name the failure instead of faulting. Without a
        // block there is no r13, so there is no honest way to run the callback.
        MCLA_LOG_ERROR("AUDIO-WORKER: no thread block (Alloc(0x{:X}) failed) - "
                       "guest render callback NOT driven",
                       static_cast<unsigned>(kAudioThreadTotalSize));
        return;
    }
    std::memset(block, 0, kAudioThreadTotalSize);
    const uint32_t blockVa = mcla::kernel::g_memory.MapVirtual(block);
    const uint32_t tlsVa = blockVa + kAudioThreadPcrSize;
    const uint32_t tebVa = blockVa + kAudioThreadTebOffset;
    auto& guestHeap = mcla::kernel::GuestMemoryHeap::Instance();
    // The TLS/TEB links are big-endian in guest memory; write them with the
    // explicit BE helper rather than a native store (guest_thread.cpp:40-41
    // does the same through ByteSwap).
    (void)guestHeap.WriteU32BE(blockVa, tlsVa);
    (void)guestHeap.WriteU32BE(blockVa + 0x100, tebVa);
    // TEB +0x14C is the thread id. This is NOT a real Xbox thread id -- the
    // audio render driver has no one to be -- so publish a stable synthetic
    // non-zero value and say so, instead of leaving 0 and letting a guest
    // GetCurrentThreadId() on this thread read 0 (guest_thread.cpp:45).
    constexpr uint32_t kSyntheticAudioThreadId = 0xA0D10001u;
    (void)guestHeap.WriteU32BE(tebVa + 0x14C, kSyntheticAudioThreadId);

    const uint32_t returnPc = ClaimReturnPc();
    if (returnPc == 0) {
        MCLA_LOG_ERROR("AUDIO-WORKER: no free function-table slot for the return "
                       "trampoline - guest render callback NOT driven (a callback "
                       "that returns would dispatch on lr=0 and fault)");
        g_userHeap.Free(block);
        return;
    }

    const uint32_t r13Va = blockVa;
    const uint32_t r1Va = blockVa + kAudioThreadTotalSize;
    MCLA_LOG_INFO("AUDIO-WORKER thread block r13={:08X} r1={:08X} tls={:08X} "
                  "teb={:08X} lr={:08X}",
                  r13Va, r1Va, tlsVa, tebVa, returnPc);

    g_workerHadContext.store(true, std::memory_order_relaxed);

    // --- absolute-deadline pacing ------------------------------------------
    // next is advanced by exactly one frame period per iteration, so a period
    // that runs long is corrected on the next one instead of accumulating debt
    // (a plain sleep_for(period) drifts by the callback's own execution time,
    // which is how a "5.33 ms" loop becomes an 8 ms one).
    auto next = std::chrono::steady_clock::now();
    uint32_t tick = 0;

    while (g_workerRunning.load(std::memory_order_relaxed) &&
           !g_shuttingDown.load(std::memory_order_relaxed)) {
        next += std::chrono::nanoseconds(kFramePeriodNs);
        const auto now = std::chrono::steady_clock::now();
        if (next < now) {
            // Behind by more than one whole period: resync instead of firing a
            // burst of catch-up callbacks.
            const auto late = now - next;
            g_overruns.fetch_add(1, std::memory_order_relaxed);
            next = now;
            if (late > std::chrono::milliseconds(200)) {
                MCLA_LOG_WARN("AUDIO-WORKER: {} ms behind, resynced",
                              std::chrono::duration_cast<std::chrono::milliseconds>(late)
                                      .count());
            }
        } else {
            std::this_thread::sleep_until(next);
        }

        // Depth gate: if the host is already ahead of the device, do not ask the
        // guest for more. Keeps the queue at the gate depth instead of growing
        // into the 2 s cap and then dropping the oldest samples.
        bool gated = false;
        {
            std::lock_guard<std::mutex> lock(g_mutex);
            gated = (g_queue.size() - g_queueRead) >= kQueueGateSamples;
        }
        if (gated) {
            g_gatedSkips.fetch_add(1, std::memory_order_relaxed);
            continue;
        }

        const uint32_t callback = g_clientCallback.load(std::memory_order_relaxed);
        const uint32_t userData = g_clientUserData.load(std::memory_order_relaxed);
        if (callback == 0) {
            continue;
        }

        uint8_t* base = mcla::kernel::g_memory.base;
        PPCFunc* fn = mcla::kernel::g_memory.FindFunction(callback);
        if (!fn) {
            static std::atomic<bool> s_unresolved{false};
            if (!s_unresolved.exchange(true)) {
                MCLA_LOG_WARN("AUDIO-WORKER: callback 0x{:08X} not in "
                              "function table yet",
                              callback);
            }
            continue;
        }

        PPCContext cbCtx{};
        cbCtx.r3.u64 = userData; // XAudio device callback(user_data)
        cbCtx.r13.u64 = r13Va;
        cbCtx.r1.u64 = r1Va;
        cbCtx.lr = returnPc;  // REAL return target, not 0x00FFFFFF
        cbCtx.msr = 0x200A000;
        cbCtx.fpscr.loadFromHost();
        SetPPCContext(cbCtx);
        fn(cbCtx, base);

        ++tick;
        const uint32_t n = g_workerTick.fetch_add(1, std::memory_order_relaxed) + 1;
        if (n <= 8 || (n % 200) == 0) {
            MCLA_LOG_INFO("AUDIO-WORKER tick #{} cb={:08X} ud={:08X}",
                          tick, callback, userData);
        }
    }

    MCLA_LOG_INFO("AUDIO-WORKER stop ticks={} gated={} overruns={}",
                  g_workerTick.load(std::memory_order_relaxed),
                  g_gatedSkips.load(std::memory_order_relaxed),
                  g_overruns.load(std::memory_order_relaxed));
    g_userHeap.Free(block);
}

void StopWorker() {
    g_workerRunning.store(false, std::memory_order_relaxed);
    if (g_workerThread.joinable()) {
        g_workerThread.join();
    }
    g_clientCallback.store(0, std::memory_order_relaxed);
    g_clientUserData.store(0, std::memory_order_relaxed);
}

} // namespace

uint32_t RegisterClient(uint32_t callback, uint32_t userData) {
    MCLA_LOG_INFO("apu::RegisterClient: callback=0x{:x}, userData=0x{:x}",
                  callback, userData);
    g_clientCallback.store(callback, std::memory_order_relaxed);
    g_clientUserData.store(userData, std::memory_order_relaxed);

    if (callback != 0 && !g_workerRunning.exchange(true)) {
        g_workerThread = std::thread(WorkerMain);
        MCLA_LOG_INFO("AUDIO-WORKER spawned");
    }
    return 0x41550001; // 'AU' magic | index 1, xenia-style driver id
}

void UnregisterClient() {
    MCLA_LOG_INFO("apu::UnregisterClient");
    StopWorker();
}

// ---------------------------------------------------------------------------
// XMA context lifecycle -- the real bodies for the two log-only stubs at
// src/kernel/imports.cpp:3475 / :3477 (XMAReleaseContext / XMACreateContext).
//
// The guest-visible object is a 64-byte block of GUEST memory, exactly as the
// reference sets up: .research/xenia/src/xenia/apu/xma_decoder.cc:122-136
// SystemHeapAlloc(sizeof(XMA_CONTEXT_DATA) * kContextCount, 256, physical) and
// then one context per 64-byte stride. On the 360 the kernel allocates those
// pages itself and publishes their PHYSICAL addresses in the XMA register file;
// a game that did not MmMapIoSpace them calls XMACreateContext instead, which
// is the path this implements: a real allocation, a real handle, real
// per-context loop/frame state, and a real free on release.
//
// The 256-byte alignment is honoured because the context array is indexed by
// (ptr - first) >> 6 (Xenia xma_decoder.cc:216-224) and a 64-byte context must
// not straddle a page.
// ---------------------------------------------------------------------------
namespace {

// 320 contexts x 64 bytes (Xenia xma_decoder.cc:83, sizeof(XMA_CONTEXT_DATA)=64
// at xma_context.h:123), 256-aligned, taken from the user heap once.
constexpr size_t kXmaContextDataBytes =
    static_cast<size_t>(apu::xma::Decoder::kContextCount) *
    apu::xma::Decoder::kContextStride;
constexpr size_t kXmaContextDataAlign = 256;

std::once_flag g_xmaOnce;
apu::xma::Decoder g_xmaDecoder;

void EnsureXmaDecoder() {
    std::call_once(g_xmaOnce, []() {
        if (mcla::kernel::g_memory.base == nullptr) {
            MCLA_LOG_ERROR("XMA: guest memory not mapped - XMA contexts "
                           "unavailable");
            return;
        }
        // 256-byte align by over-allocating and rounding up inside the block we
        // own, so we never hand a partially-aligned range to the decoder.
        void* raw = g_userHeap.Alloc(kXmaContextDataBytes + kXmaContextDataAlign);
        if (raw == nullptr) {
            MCLA_LOG_ERROR("XMA: context array alloc failed ({} bytes) - "
                           "XMACreateContext will report failure",
                           static_cast<unsigned>(kXmaContextDataBytes));
            return;
        }
        auto addr = reinterpret_cast<uintptr_t>(raw);
        const uintptr_t aligned = (addr + (kXmaContextDataAlign - 1)) &
                                  ~static_cast<uintptr_t>(kXmaContextDataAlign - 1);
        auto* host = reinterpret_cast<uint8_t*>(aligned);
        const uint32_t guestVa = mcla::kernel::g_memory.MapVirtual(host);
        std::memset(host, 0, kXmaContextDataBytes);
        g_xmaDecoder.Setup(mcla::kernel::g_memory.base, host, guestVa);
        MCLA_LOG_INFO("XMA: {} contexts x {} B at {:08X} (raw {:016X}) - "
                      "bitstream decoder registered={} (see src/apu/xma_decoder.h)",
                      apu::xma::Decoder::kContextCount,
                      apu::xma::Decoder::kContextStride, guestVa,
                      static_cast<unsigned long long>(addr),
                      g_xmaDecoder.has_frame_decoder() ? "yes" : "NO");
    });
}

} // namespace

bool XmaCreateContext(uint32_t* outContextPtr) {
    EnsureXmaDecoder();
    if (g_xmaDecoder.context_array_ptr() == 0) {
        if (outContextPtr) *outContextPtr = 0;
        return false;  // honest OOM, not a fake context
    }
    const uint32_t ptr = g_xmaDecoder.AllocateContext();
    static std::atomic<uint32_t> s_created{0};
    const uint32_t n = s_created.fetch_add(1, std::memory_order_relaxed) + 1;
    if (n <= 8 || (n % 100) == 0) {
        MCLA_LOG_INFO("XMA: XMACreateContext #{} -> {:08X}", n, ptr);
    }
    if (outContextPtr) *outContextPtr = ptr;
    return ptr != 0;
}

void XmaReleaseContext(uint32_t contextPtr) {
    static std::atomic<uint32_t> s_released{0};
    const uint32_t n = s_released.fetch_add(1, std::memory_order_relaxed) + 1;
    if (n <= 8 || (n % 100) == 0) {
        MCLA_LOG_INFO("XMA: XMAReleaseContext #{} ptr={:08X}", n, contextPtr);
    }
    g_xmaDecoder.ReleaseContext(contextPtr);
}

// Kick / lock / clear one context. These are the XMACreateContext
// command surface Xenia drives from the register file
// (xma_decoder.cc:303-345); the guest reaches them through the XMA* import
// calls and, on real hardware, through the 0x7FEA0000 MMIO aperture (which
// this build does not map -- see the handoff note).
void XmaKickContext(uint32_t contextPtr) { g_xmaDecoder.Enable(contextPtr); }
void XmaLockContext(uint32_t contextPtr) { g_xmaDecoder.Disable(contextPtr); }
void XmaClearContext(uint32_t contextPtr) { g_xmaDecoder.Clear(contextPtr); }
bool XmaBlockOnContext(uint32_t contextPtr, bool poll) {
    return g_xmaDecoder.BlockOnContext(contextPtr, poll);
}
void XmaSetFrameDecoder(apu::xma::FrameDecoderFn fn, void* user) {
    g_xmaDecoder.set_frame_decoder(fn, user);
}
bool XmaHasFrameDecoder() { return g_xmaDecoder.has_frame_decoder(); }
uint32_t XmaFramesDecoded() { return g_xmaDecoder.frames_decoded(); }

void SubmitFrames(void* samples) {
    const uint32_t n = g_frameCount.fetch_add(1, std::memory_order_relaxed) + 1;
    // Cap log to ~1 line per 200 submits: a real-time render driver submits
    // ~187 frames/s (48 kHz / 256 samples), which would otherwise flood the
    // soak log.
    if (n <= 8 || (n % 200) == 0) {
        MCLA_LOG_INFO("AUDIO-FRAME #{} samples={}", n,
                      samples ? "yes" : "null");
    }
    if (!samples) {
        // Logged and dropped: there is no PCM to convert and inventing some
        // would be a fake. The frame counter above is the honest record that
        // the guest called with null.
        return;
    }
    if (g_submitScratch.size() < kSubmitScratchSamples) {
        // Only reachable before Init() has sized it, or after a failed device
        // open. One allocation, then steady state.
        g_submitScratch.assign(kSubmitScratchSamples, 0);
    }
    ConvertGuestFrameStereoS16(samples, g_submitScratch.data());

    std::lock_guard<std::mutex> lock(g_mutex);
    // Drop oldest if the consumer is behind (~2 s cap).
    size_t queued = g_queue.size() - g_queueRead;
    if (queued > kMaxQueuedSamples) {
        const size_t drop = queued - kMaxQueuedSamples;
        g_queueRead += drop;
        queued = kMaxQueuedSamples;
    }
    if (g_queueRead > 0) {
        g_queue.erase(g_queue.begin(),
                      g_queue.begin() + static_cast<std::ptrdiff_t>(g_queueRead));
        g_queueRead = 0;
    }
    g_queue.insert(g_queue.end(), g_submitScratch.begin(),
                   g_submitScratch.begin() + static_cast<std::ptrdiff_t>(kSubmitScratchSamples));
}

void Init() {
    {
        std::lock_guard<std::mutex> lock(g_mutex);
        if (g_opened) {
            return;
        }
        g_shuttingDown.store(false, std::memory_order_relaxed);

        // Warm-up allocations: the audio callback and the worker must not
        // allocate in steady state.
        g_callbackSilence.assign(kCallbackScratchSamples, 0);
        g_callbackScratch.assign(kCallbackScratchSamples, 0);
        g_submitScratch.assign(kSubmitScratchSamples, 0);

        if (!SDL_WasInit(SDL_INIT_AUDIO)) {
            if (!SDL_InitSubSystem(SDL_INIT_AUDIO)) {
                MCLA_LOG_ERROR(
                    "AUDIO-OPEN failed: SDL_InitSubSystem(AUDIO): {}",
                    SDL_GetError());
                return;
            }
            g_subsystemOwned = true;
        }

        SDL_AudioSpec spec;
        SDL_zero(spec);
        spec.format = SDL_AUDIO_S16;
        spec.channels = static_cast<Uint8>(kHostChannels);
        spec.freq = kHostHz;

        g_stream = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK,
                                             &spec, AudioCallback, nullptr);
        if (!g_stream) {
            MCLA_LOG_ERROR("AUDIO-OPEN failed: SDL_OpenAudioDeviceStream: {}",
                           SDL_GetError());
            if (g_subsystemOwned) {
                SDL_QuitSubSystem(SDL_INIT_AUDIO);
                g_subsystemOwned = false;
            }
            return;
        }

        if (!SDL_ResumeAudioStreamDevice(g_stream)) {
            MCLA_LOG_ERROR("AUDIO-OPEN failed: SDL_ResumeAudioStreamDevice: {}",
                           SDL_GetError());
            SDL_DestroyAudioStream(g_stream);
            g_stream = nullptr;
            if (g_subsystemOwned) {
                SDL_QuitSubSystem(SDL_INIT_AUDIO);
                g_subsystemOwned = false;
            }
            return;
        }

        g_opened = true;
        // ARG ORDER FIXED 2026-10-06 (audio tier-1 pass). The two trailing
        // arguments were swapped, so this row printed the stream POINTER under
        // the label `framePeriodNs` and the frame period under `stream`.
        // Measured in build/w734.log, the only boot that ever reached here:
        //   AUDIO-OPEN ok: 48000Hz ch=2 format=s16 underrun=silence
        //                   framePeriodNs=0x2574d3bf6b0 stream=5333333
        // `0x2574d3bf6b0` is the SDL stream handle and `5333333` is
        // kFramePeriodNs, i.e. exactly the two values with their labels
        // exchanged. A row that misreports its own numbers is a census
        // hazard: the next reader greps `framePeriodNs=` and concludes the
        // period is a pointer. Same marker, same placeholders, same count --
        // only the two arguments now match the two fields they fill.
        MCLA_LOG_INFO(
            "AUDIO-OPEN ok: {}Hz ch={} format=s16 underrun=silence "
            "framePeriodNs={} stream={}",
            kHostHz, kHostChannels, kFramePeriodNs,
            static_cast<const void*>(g_stream));
    }

    // Worker may already be running if RegisterClient raced ahead of Init
    // (guest can register before the host opens the device). Only spawn if
    // a callback is already stored and no thread exists.
    if (g_clientCallback.load(std::memory_order_relaxed) != 0 &&
        !g_workerRunning.exchange(true)) {
        g_workerThread = std::thread(WorkerMain);
        MCLA_LOG_INFO("AUDIO-WORKER spawned (late, post-Init)");
    }
}

void Shutdown() {
    g_shuttingDown.store(true, std::memory_order_relaxed);
    StopWorker();

    SDL_AudioStream* s = nullptr;
    {
        std::lock_guard<std::mutex> lock(g_mutex);
        s = g_stream;
        g_stream = nullptr;
        g_opened = false;
        g_queue.clear();
        g_queueRead = 0;
    }
    if (s) {
        SDL_PauseAudioStreamDevice(s);
        SDL_DestroyAudioStream(s);
    }
    if (g_subsystemOwned) {
        SDL_QuitSubSystem(SDL_INIT_AUDIO);
        g_subsystemOwned = false;
    }
    MCLA_LOG_INFO("apu::Shutdown frames={} ticks={} gated={} overruns={} "
                  "workerContext={}",
                  g_frameCount.load(std::memory_order_relaxed),
                  g_workerTick.load(std::memory_order_relaxed),
                  g_gatedSkips.load(std::memory_order_relaxed),
                  g_overruns.load(std::memory_order_relaxed),
                  g_workerHadContext.load(std::memory_order_relaxed) ? "real" : "NONE");
}

} // namespace apu
