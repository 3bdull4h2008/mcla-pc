#include "render_thread.h"
#include "logging.h"
#include "generated/ppc_xenon/ppc_recomp_shared.h"
#include "kernel/memory.h"
#include "kernel/xdm.h"  // T43.18: g_mainParkHandle/Lr/Ns for the HB tail-light
#include "renderer/shader_translator.h"
#include "renderer/pipeline_cache.h"
#include "renderer/xenos_shader_ir.h"
#include "renderer/grc_fvf_decode.h"
#include "d3d12_backend.h"
#include "gpu_cp.h"  // F-647: CpReadGuestRegisters + the Xenos register indices
#include "render_queue.h"
#include <array>   // F-647: the fixed 4,096-byte constant-bank buffer
#include <atomic>
#include <cstring> // F-652: std::memcpy for the kFloat register reinterpretation
#include <chrono>
#include <thread>
#include <unordered_map>
#include <vector>

namespace mcla::native {

// F-610: heartbeat cadence. This is the ONLY software clock left in the
// render path — the per-PRESENT Sleep pacer that used to sit at
// kTargetFrameSeconds is gone (see the PRESENT case). The real frame deadline
// is the swapchain's Present(1,0) in the backend
// (src/d3d12_backend.cpp:1496, :1922), which blocks on vsync; pacing a
// second time in software only added up to 33 ms of latency to every guest
// present. The heartbeat is a LIVENESS watchdog (it proves the consumer is
// still turning when the guest goes quiet), not a pacer.
static constexpr uint32_t kHeartbeatIntervalMs = 33;
// F-610: suppress a heartbeat when a guest NATIVE-PRESENT was consumed within
// this window. A heartbeat present is a clear-only frame, so issuing one
// while the guest is presenting real frames both halves the guest's effective
// framerate and burns a vsync slot on a clear. The window is 15 beats: long
// enough that the heartbeat cannot flicker between two guest frames, short
// enough that a guest going quiet is covered by the next beat after the
// window. REMOVAL TRIGGER: delete the heartbeat entirely once the guest
// PresentKick path is proven in a soak (a run whose PRESENT count tracks the
// guest's own frame counter, not our timer).
static constexpr uint32_t kHeartbeatGuestSuppressMs = 500;
// Queue depth warning threshold
static constexpr uint32_t kQueueDepthWarning = 30;
// Queue depth drop threshold: if queue is this deep, skip non-critical commands
static constexpr uint32_t kQueueDepthDrop = 60;
// F-610: the consumer threshold and the producer's are the same number on
// purpose. CommandQueue::kShedDepth (render_queue.h) is 60 to match this, so
// the producer stops offering work exactly when the consumer starts refusing
// it. A producer that shed later would just fill a queue the consumer drops.
static_assert(kQueueDepthDrop == CommandQueue::kShedDepth,
              "producer shed depth must equal the consumer drop depth");

// F-610: steady_clock nanoseconds of the last CONSUMED guest (non-heartbeat)
// PRESENT. Written by the PRESENT case, read by the heartbeat thread to
// implement the suppression policy. 0 = none seen yet, which the heartbeat
// reads as "not fresh" so the first beats still fire — a guest that never
// presents must not produce a dead window.
static std::atomic<int64_t> g_lastGuestPresentNs{0};

static int64_t NowNs() {
    return std::chrono::duration_cast<std::chrono::nanoseconds>(
               std::chrono::steady_clock::now().time_since_epoch())
        .count();
}

RenderThread g_renderThread;
CommandQueue g_commandQueue;

RenderThread::RenderThread() : running_(false), shouldStop_(false) {}

RenderThread::~RenderThread() {
    stop();
}

void RenderThread::SetWindowParams(void* hwnd, uint32_t width, uint32_t height) {
    pendingHwnd_ = hwnd;
    pendingWidth_ = width;
    pendingHeight_ = height;
}

void RenderThread::start() {
    if (running_) return;

    running_ = true;
    shouldStop_ = false;
    MCLA_LOG_INFO("RenderThread: started");
    thread_ = std::thread(&RenderThread::threadMain, this);
}

void RenderThread::stop() {
    if (!running_) return;

    shouldStop_ = true;
    g_commandQueue.shutdown();

    if (heartbeat_.joinable()) {
        heartbeat_.join();
    }
    if (thread_.joinable()) {
        thread_.join();
    }

    if (d3d12Initialized_) {
        backend_.GetPipelineCache().StopWorker();
        backend_.Shutdown();
        d3d12Initialized_ = false;
    }

    running_ = false;
    MCLA_LOG_INFO("RenderThread: stopped");
}

void RenderThread::threadMain() {
    MCLA_LOG_INFO("RenderThread: entering command loop");

    if (pendingHwnd_ && !d3d12Initialized_) {
        if (backend_.Initialize(static_cast<HWND>(pendingHwnd_), pendingWidth_, pendingHeight_)) {
            d3d12Initialized_ = true;
            MCLA_LOG_INFO("RenderThread: D3D12 initialized on thread start ({}x{})",
                          pendingWidth_, pendingHeight_);
            // Start the pipeline cache async compilation worker
            backend_.GetPipelineCache().StartWorker(
                backend_.GetDevice(), backend_.GetRootSignature());
            MCLA_LOG_INFO("RenderThread: PipelineCache worker started");
            // F-610: SYNTHETIC startup content, one shot, before any guest frame.
            // REMOVAL TRIGGER: delete this block and the heartbeat below once a
            // soak shows "PRESENT-BLIT #1 ... va=<non-zero>" — i.e. the guest's
            // own NATIVE-PRESENT produced a real blit. Until then a synthetic
            // frame is the only thing separating "window is alive" from "window
            // is black because nothing works", which is the ambiguity this
            // exists to remove. It fires once per Initialize(), so it can never
            // paint over a guest frame — the guest-content latch in the PRESENT
            // case below is what guarantees that.
            if (backend_.BeginFrame()) {
                backend_.ClearAndPresent(0.06f, 0.10f, 0.22f, 1.0f);
                // 2026-10-02: the FIRST of four sites in this file that could
                // wedge the whole backend. BeginFrame() sets the backend's
                // m_inFrame latch; ClearAndPresent can return false BEFORE its
                // own BeginFrame (its !m_initialized test and its F-650 arbiter
                // refusal both precede it), and on that path nothing is
                // presented and the latch is still set -- so every later
                // BeginFrame() refuses on already-in-frame forever.
                // AbandonFrame is guarded on m_inFrame and so is a no-op when
                // the clear did present. It releases state; it does not make the
                // clear succeed and it does not bypass a gate.
                backend_.AbandonFrame("startup-clear");
                MCLA_LOG_INFO("RenderThread: initial clear+present (dark blue)");
            }
            // F-758: THE W6 ONE-SHOT GRADIENT IS DELETED too. It is the same
            // synthetic image as the fallback that stood at :1733, painted once at
            // startup, and F-609 forbids it for the same reason. It survived the
            // first deletion precisely because it is a DIFFERENT site: its own
            // comment said "Same removal trigger as the clear above", which was
            // never a trigger anyone evaluated. Two synthetics existed and one
            // deletion would have left the other painting.
            //
            // MEASURED in build/w713.log: `PRESENT-BLIT-SYNTH ok 1280x720
            // (gradient)`, 1 row, and it SUCCEEDS -- so it is the one frame the
            // user saw a gradient on before the fallback took over.
            //
            // WHAT REPLACES IT: nothing. The startup clear immediately above is
            // retained -- it presents a real colour the code chose deliberately and
            // says so in its own log line -- and after this the frame loop reports
            // PRESENT-SURFACE-UNREADABLE rather than painting over the guest.
            // REMOVAL TRIGGER: none.
            // F-610: heartbeat. A heartbeat PRESENT is a clear-only frame, so
            // firing one while the guest is already presenting real frames both
            // halves the guest's effective framerate and spends a vsync slot on
            // a clear. POLICY (stated, not guessed): SKIP the beat when
            //   (a) a guest (non-heartbeat) PRESENT was consumed within the last
            //       kHeartbeatGuestSuppressMs, or
            //   (b) the queue is at or past kQueueDepthWarning (the consumer is
            //       already behind; a liveness ping is not worth depth).
            // Skipping loses nothing: the beat is idempotent, and the first beat
            // after the window closes restores liveness within <=500 ms. The old
            // unconditional 30 Hz version raced a guest-presenting soak and made
            // the soak's PRESENT count measure our timer instead of the guest.
            // REMOVAL TRIGGER: kHeartbeatIntervalMs (see the constant).
            heartbeat_ = std::thread([this]() {
                const auto kInterval = std::chrono::milliseconds(kHeartbeatIntervalMs);
                const int64_t kSuppressNs =
                    static_cast<int64_t>(kHeartbeatGuestSuppressMs) * 1000000;
                uint32_t ticks = 0, skipped = 0;
                while (!shouldStop_) {
                    std::this_thread::sleep_for(kInterval);
                    if (shouldStop_ || !d3d12Initialized_) continue;

                    ticks++;
                    const int64_t now = NowNs();
                    const int64_t lastGuest =
                        g_lastGuestPresentNs.load(std::memory_order_relaxed);
                    const bool guestFresh =
                        lastGuest != 0 && (now - lastGuest) < kSuppressNs;
                    const size_t depth = g_commandQueue.size();
                    if (guestFresh || depth >= kQueueDepthWarning) {
                        skipped++;
                        if (skipped <= 3 || (skipped % 200) == 0)
                            MCLA_LOG_INFO("RenderThread: HB skip #{} of {} ticks "
                                          "guestFresh={} depth={}",
                                          skipped, ticks,
                                          static_cast<int>(guestFresh), depth);
                        continue;
                    }
                    // push() is non-blocking and refuses sheddable commands past
                    // CommandQueue::kShedDepth, so a stalled backend can neither
                    // block this thread nor grow the backlog from here.
                    RenderCommand cmd;
                    cmd.type = RenderCommand::PRESENT;
                    auto& p = cmd.data.emplace<PresentCommand>();
                    p.frameNumber = 0;
                    p.obj = 0;
                    p.swapInfo = 0;
                    p.surfaceVA = 0;
                    g_commandQueue.push(std::move(cmd));
                }
            });
        } else {
            MCLA_LOG_ERROR("RenderThread: D3D12 initialization failed on thread start");
        }
    }

    while (!shouldStop_) {
        RenderCommand cmd;
        if (!g_commandQueue.pop(cmd)) {
            break;
        }

        // Queue depth monitoring
        const size_t qDepth = g_commandQueue.size();

        // F-610: the producer no longer blocks, so everything it discarded has
        // to be visible here or a shed frame is indistinguishable from a guest
        // that stopped drawing. Logged on change, then bounded (first 3, then
        // every 200th change) so a long stall cannot flood the soak.
        {
            const ShedCounters shed = g_commandQueue.Shed();
            const uint64_t shedTotal = shed.depth();
            static uint64_t lastShedTotal = 0;
            if (shedTotal != lastShedTotal) {
                lastShedTotal = shedTotal;
                static std::atomic<uint64_t> shedLines{0};
                const uint64_t n = shedLines.fetch_add(1) + 1;
                if (n <= 3 || (n % 200) == 0)
                    MCLA_LOG_WARN("QUEUE-SHED total={} refused={} evictSheddable={} "
                                  "evictDurable={} consumerDrop={} depth={}",
                                  shedTotal, shed.refusedSheddable,
                                  shed.evictedSheddable, shed.evictedDurable,
                                  shed.consumerDropped, qDepth);
            }
        }

        if (qDepth >= kQueueDepthDrop) {
            // Queue dangerously deep — skip non-critical commands. F-610: the
            // list is now IsSheddable() from render_queue.h, the same six types
            // as before PLUS the two it was missing: DRAW_MARKER and the
            // heartbeat PRESENT. Those two are why a marker/heartbeat flood
            // could keep a stalled queue full while the consumer was already
            // refusing everything else. INIT, RESIZE, DRAW_CAPTURED and guest
            // PRESENT are never dropped.
            if (IsSheddable(cmd)) {
                static std::atomic<uint32_t> dropCount{0};
                const uint32_t n = dropCount.fetch_add(1) + 1;
                if (n <= 5 || (n % 100) == 0)
                    MCLA_LOG_WARN("RenderThread: DROPPED cmd type={} queueDepth={} (total dropped={})",
                                  static_cast<int>(cmd.type), qDepth, n);
                // F-610: fold consumer-side drops into the same QUEUE-SHED
                // accounting as the producer's, so one number answers "how much
                // work did the pipeline throw away" no matter which side
                // decided. Read-modify-write races between the two writers can
                // lose a count, which is acceptable for a lossy tally.
                g_commandQueue.NoteConsumerDrop();
                continue;
            }
        } else if (qDepth >= kQueueDepthWarning) {
            static std::atomic<uint32_t> warnCount{0};
            const uint32_t n = warnCount.fetch_add(1) + 1;
            if (n <= 5 || (n % 100) == 0)
                MCLA_LOG_WARN("RenderThread: queue depth {} (warning threshold={})",
                              qDepth, kQueueDepthWarning);
        }

        processCommand(cmd);
    }

    if (d3d12Initialized_) {
        backend_.WaitForGpu();
    }

    MCLA_LOG_INFO("RenderThread: exiting command loop");
}

// ---------------------------------------------------------------------------
// Shader container reader: reads a Xenos .fxc container from guest memory.
// Returns the raw container bytes. Returns empty on failure.
// ---------------------------------------------------------------------------
static std::vector<uint8_t> ReadShaderContainer(mcla::kernel::GuestMemoryHeap& mem,
                                                 uint32_t guestAddr) {
    if (guestAddr == 0) return {};

    uint32_t header[9] = {};
    if (!mem.IsValid(guestAddr, 36) ||
        !mem.ReadBytes(guestAddr, header, 36)) {
        return {};
    }

    // Validate container header: flags field must have (flags & 0xFFFFFF00) == 0x102A1100
    const uint32_t flags = mcla::renderer::AssembleBE32(
        reinterpret_cast<const uint8_t*>(header));
    if ((flags & 0xFFFFFF00) != 0x102A1100) {
        return {};
    }

    const uint32_t vsize = mcla::renderer::AssembleBE32(
        reinterpret_cast<const uint8_t*>(&header[1]));
    const uint32_t psize = mcla::renderer::AssembleBE32(
        reinterpret_cast<const uint8_t*>(header + 2));
    if (vsize + psize < vsize || vsize + psize < psize) {
        return {};
    }

    const uint32_t totalSize = 36 + vsize + psize;  // header(36) + virtual + physical
    std::vector<uint8_t> container(totalSize);
    // Copy the already-read header
    std::memcpy(container.data(), header, 36);
    // Read the rest
    if (!mem.ReadBytes(guestAddr + 36, container.data() + 36, totalSize - 36)) {
        return {};
    }

    return container;
}

// ---------------------------------------------------------------------------
// PSO lookup stats
// ---------------------------------------------------------------------------
static std::atomic<uint32_t> s_psoCacheHits{0};
static std::atomic<uint32_t> s_psoCacheMisses{0};
static std::atomic<uint32_t> s_psoTranslateFailures{0};

// ---------------------------------------------------------------------------
// F-611: Xenos index-stream transcode.
//
// A PM4 index buffer is a big-endian guest byte stream that the hardware
// reorders per VGT_DMA_SIZE.swap_mode (registers.h:301-309, xenos::Endian at
// xenos.h:193-198), and D3D12 accepts only R16_UINT / R32_UINT. So the bytes
// come out of the checked ReadBytes helper and are assembled BY HAND, element
// by element, in the order the swap mode dictates. There is deliberately no
// reinterpret_cast over guest memory and no assumption about host endianness:
// the only byte order in this function is the one spelled out in b0..b3, and it
// is big-endian because the guest is.
//
// An unhandled swap mode is a refusal, never a guess - a coin flip on byte
// order is a silently wrong draw, which is the failure mode this whole file is
// being rebuilt to avoid.
//
// Buffers are reused across draws: the render thread is the only writer and the
// draw path must not allocate per frame.
// ---------------------------------------------------------------------------
struct IndexTranscode {
    std::vector<uint16_t> narrow;
    std::vector<uint32_t> wide;
    bool isWide = false;
    uint32_t count = 0;
    uint32_t maxIndex = 0;
};

// Byte stride of one element in the RAW guest stream, and whether the value
// needs 32 bits. False for a swap mode with no D3D12 element equivalent.
// Exposed separately because the caller must size-check num_indices*stride
// against ibSize BEFORE reading anything.
bool XenosIndexElement(uint32_t swap, uint32_t& stride, bool& wide) {
    switch (swap) {
    case 0: stride = 2; wide = false; return true; // kNone   - 16-bit BE
    case 1: stride = 2; wide = false; return true; // k8in16  - halfword swapped
    case 2: stride = 4; wide = true;  return true; // k8in32  - word swapped
    case 3: stride = 4; wide = false; return true; // k16in32 - 16-bit in the
                                                   //           high halfword
    default: return false;
    }
}

bool TranscodeXenosIndices(const uint8_t* raw, uint32_t numIndices, uint32_t swap,
                           IndexTranscode& out) {
    uint32_t stride = 0;
    bool wide = false;
    if (!XenosIndexElement(swap, stride, wide)) return false;
    // Byte offsets of the value's bytes inside one element, most significant
    // first. This table IS the endianness model.
    uint32_t b0 = 0, b1 = 0, b2 = 0, b3 = 0;
    switch (swap) {
    case 0: b0 = 0; b1 = 1; break;
    case 1: b0 = 1; b1 = 0; break;
    case 2: b0 = 3; b1 = 2; b2 = 1; b3 = 0; break;
    default: b0 = 2; b1 = 3; break; // swap == 3
    }
    out.isWide = wide;
    out.count = numIndices;
    out.maxIndex = 0;
    if (wide) {
        if (out.wide.size() < numIndices) out.wide.resize(numIndices);
        for (uint32_t i = 0; i < numIndices; ++i) {
            const uint8_t* e = raw + static_cast<size_t>(i) * stride;
            const uint32_t v = (static_cast<uint32_t>(e[b0]) << 24) |
                               (static_cast<uint32_t>(e[b1]) << 16) |
                               (static_cast<uint32_t>(e[b2]) << 8) |
                               static_cast<uint32_t>(e[b3]);
            out.wide[i] = v;
            if (v > out.maxIndex) out.maxIndex = v;
        }
    } else {
        if (out.narrow.size() < numIndices) out.narrow.resize(numIndices);
        for (uint32_t i = 0; i < numIndices; ++i) {
            const uint8_t* e = raw + static_cast<size_t>(i) * stride;
            const uint16_t v = static_cast<uint16_t>(
                (static_cast<uint32_t>(e[b0]) << 8) | static_cast<uint32_t>(e[b1]));
            out.narrow[i] = v;
            if (v > out.maxIndex) out.maxIndex = v;
        }
    }
    return true;
}

// F-723: the XENOS ColorRenderTargetFormat -> DXGI_FORMAT table.
//
// THE VALUE SPACE IS SPARSE, AND THAT IS THE WHOLE POINT OF THIS FUNCTION.
// `color_format` is 4 bits wide (registers.h:745, xenos.h:409
// kColorRenderTargetFormatBits) but the architected enum assigns only 0-7, 10,
// 12, 14, 15 (.research/xenia/src/xenia/gpu/xenos.h:299-319). Codes 8, 9, 11
// and 13 are UNASSIGNED - they are not "reserved for later", they are values no
// hardware produces. So a default arm here would not be a convenience, it would
// be a fabrication: it would hand the guest a render target format the guest
// never asked for, and the PSO built from it would render into a format that
// disagrees with the RTV it is used with (pipeline_cache.cpp:1726-1729 names
// exactly that failure). There is therefore NO default arm, and the caller
// REFUSES on DXGI_FORMAT_UNKNOWN.
//
// The mapping is the reference's, not a guess. Xenia resolves a colour format to
// a host format in two steps: GetColorDrawDXGIFormat
// (d3d12_render_target_cache.cc:1719-1737) handles the formats whose DRAW
// representation differs from their RESOURCE representation, and defers
// everything else to GetColorResourceDXGIFormat (:1680-1716). Both are cited
// per code below. That two-step shape is reproduced here because collapsing it
// would pick the wrong format for six of the thirteen assigned codes.
//
// ONE DEVIATION, STATED: k_8_8_8_8_GAMMA (code 1) is conditional in the
// reference -- GetColorResourceDXGIFormat returns R16G16B16A16_UNORM or
// R8G8B8A8_UNORM depending on the runtime cvar
// `gamma_render_target_as_unorm16` (d3d12_render_target_cache.cc:1687-1689;
// the field defaults to false at d3d12_render_target_cache.h:715, and Xenia
// only ever RAISES it when the device supports R16G16B16A16_UNORM blending,
// :486). This host has no such cvar, so it takes the reference's DEFAULT arm,
// R8G8B8A8_UNORM. That is the same value the reference itself produces with
// its default configuration; it is a stated host-capability choice, not a
// guest-fact guess. The alternative - refusing every gamma target - would
// refuse the single most common render target on the hardware.
//
// RETURNS: a DXGI_FORMAT as a uint32_t, or DXGI_FORMAT_UNKNOWN (0) for every
// code with no measured mapping. 0 is the right sentinel here because the
// consumer chain treats 0 as absent by construction: pipeline_cache.cpp:841-842
// copies colorFormats[] into targetFormats[] verbatim and :1731-1733 counts
// `RTVFormats[i] != DXGI_FORMAT_UNKNOWN`, so a 0 is counted as "no render
// target" rather than silently becoming slot 0 of the PSO.
uint32_t MapXenosColorFormatToDxgi(uint32_t colorFormat) {
    switch (colorFormat) {
        // --- GetColorDrawDXGIFormat: format differs between draw and resource ---
        // d3d12_render_target_cache.cc:1722-1723
        case 4:  // k_16_16
            return DXGI_FORMAT_R16G16_SNORM;
        // :1724-1725
        case 5:  // k_16_16_16_16
            return DXGI_FORMAT_R16G16B16A16_SNORM;
        // :1726-1727
        case 6:  // k_16_16_FLOAT
            return DXGI_FORMAT_R16G16_FLOAT;
        // :1728-1729
        case 7:  // k_16_16_16_16_FLOAT
            return DXGI_FORMAT_R16G16B16A16_FLOAT;
        // :1730-1731
        case 14:  // k_32_FLOAT
            return DXGI_FORMAT_R32_FLOAT;
        // :1732-1733
        case 15:  // k_32_32_FLOAT
            return DXGI_FORMAT_R32G32_FLOAT;
        // --- GetColorResourceDXGIFormat: draw == resource ---
        // :1685-1686
        case 0:  // k_8_8_8_8
            return DXGI_FORMAT_R8G8B8A8_UNORM;
        // :1687-1689 -- conditional in the reference on the gamma cvar; this
        // host takes the cvar's DEFAULT arm. See the note above.
        case 1:  // k_8_8_8_8_GAMMA
            return DXGI_FORMAT_R8G8B8A8_UNORM;
        // :1690-1692 -- both codes share the arm
        case 2:   // k_2_10_10_10
        case 10:  // k_2_10_10_10_AS_10_10_10_10
            return DXGI_FORMAT_R10G10B10A2_UNORM;
        // :1693-1695 -- both codes share the arm
        case 3:   // k_2_10_10_10_FLOAT
        case 12:  // k_2_10_10_10_FLOAT_AS_16_16_16_16
            return DXGI_FORMAT_R16G16B16A16_FLOAT;
        default:
            // 8, 9, 11, 13 (unassigned in xenos.h:299-319) and 16+ (not
            // representable in the 4-bit field). The reference asserts here
            // (d3d12_render_target_cache.cc:1713-1715); this host refuses
            // instead of crashing, because an assert in a draw loop would take
            // the process down on a guest value rather than refusing the draw.
            return DXGI_FORMAT_UNKNOWN;
    }
}

// F-611: DRAW_CAPTURED gate census. One counter per named refusal, so a soak
// reports WHICH piece is missing rather than only that something was. All of
// them are logged bounded (n <= 8 || n % 200 == 0).
std::atomic<uint32_t> s_cpRefuseSrc{0};
std::atomic<uint32_t> s_cpRefuseIbEmpty{0};
std::atomic<uint32_t> s_cpRefuseIbWrap{0};
std::atomic<uint32_t> s_cpRefuseNumIdx{0};
std::atomic<uint32_t> s_cpRefuseSwap{0};
std::atomic<uint32_t> s_cpRefuseIbShort{0};
std::atomic<uint32_t> s_cpRefuseIbUnreadable{0};
std::atomic<uint32_t> s_cpRefuseVbMissing{0};
// F-648: the vertex-format and primitive-type refusals. Separate counters, not
// folds into s_cpRefuseVbMissing, because each answers a different question and
// a soak has to be able to tell "the format did not decode" from "the format and
// the stride disagree" from "the guest drew rectangles".
// F-720: s_cpRefuseVbElemOutOfRange is the vbElementCount bound check, kept as
// its OWN counter rather than folded into vb-fmt-unmapped because it answers a
// different question: "the captured element table and the array holding it
// disagree" is not "a format failed to decode", and a soak that cannot tell them
// apart cannot tell a decode bug from a producer bug. It is deliberately NOT a
// field on DRAW-CP-CENSUS: that row's format is consumed, and every refusal name
// is already countable from DRAW-CP-REFUSE's `what=`, which is where this one is
// named. So no marker's format changes anywhere in this change.
std::atomic<uint32_t> s_cpRefuseVbElemOutOfRange{0};  // vbElementCount > the array
std::atomic<uint32_t> s_cpRefuseVbFmtUnmapped{0};  // format never mapped to a size
std::atomic<uint32_t> s_cpRefuseVbFmtStride{0};    // stride < format: impossible
std::atomic<uint32_t> s_cpRefuseVbFmtShort{0};     // numIdx * formatBytes > vbSize
// F-648: the pre-existing `vb-short` check (num_indices * vbStride > vbSize)
// keeps its original s_cpRefuseVbMissing bump - that tracker is shared with
// vb-missing and vb-unreadable and its meaning is not mine to change - and
// ALSO bumps this one, purely so vb-short is separately countable in
// DRAW-CP-CENSUS. Additive: no existing counter changes meaning.
std::atomic<uint32_t> s_cpRefuseVbShortRefused{0};
// F-751: the vertex-stream byte-order refusals. Three counters, not one, on the
// same reasoning as the four above (F-720): each answers a DIFFERENT question,
// and a soak that cannot tell them apart cannot tell a producer bug from a
// consumer bug. Deliberately NOT fields on DRAW-CP-CENSUS - that row's format is
// consumed - so each is named only through DRAW-CP-REFUSE's `what=`, which is
// where the existing element-bound refusal is named too. No marker's format
// changes in this change.
//   absent : the command carries NO vertex element, so there is no fetch
//            constant on it and therefore no selector. Not "assume no swap".
//   unknown: an element carries a selector outside the four architected values.
//            The guest field is 2 bits (xenos.h:1122), so this cannot be a
//            guest fact - it can only be a producer bug, and it is NOT rounded,
//            masked or clamped into 0..3.
//   split  : two elements of the SAME command disagree. There is exactly ONE
//            copy of the stream (one vbBase/vbSize pair) and therefore only one
//            transform that can be applied to it, so a disagreement has no
//            single correct answer to pick.
std::atomic<uint32_t> s_cpRefuseVbEndianAbsent{0};   // no element -> no selector
std::atomic<uint32_t> s_cpRefuseVbEndianUnknown{0};  // selector outside 0..3
std::atomic<uint32_t> s_cpRefuseVbEndianSplit{0};    // elements disagree
std::atomic<uint32_t> s_cpRefusePrimRect{0};       // prim_type 0x08 kRectangleList
std::atomic<uint32_t> s_cpRefusePrimOther{0};      // any other unmappable prim_type
std::atomic<uint32_t> s_cpIndexMeasured{0};
// s_cpDrawn: draws whose DRAW CALL WAS RECORDED -- the backend's own
// m_stats.drawsIssued advanced across DrawDynamicMeshWithPipeline -- and
// nothing else. 2026-10-02: this counter used to be bumped unconditionally at
// the draw site, outside the BeginFrame gate, so it counted commands that
// REACHED the site rather than draws that happened, and because
// DRAW-CP-CENSUS prints it as `drawn=` it made a skipped path read as a
// success. It is now gated on the draw call, which is also what its own
// adjacent comment at s_cpTopologyAssigned below always claimed it meant.
// The count it used to carry is not lost: it is s_cpDrawnSkipped.
std::atomic<uint32_t> s_cpDrawn{0};
// s_cpDrawnSkipped: commands that reached the draw site and recorded NO draw
// call. The complement of s_cpDrawn, on its own counter, so that "the draw was
// refused" and "the draw was never attempted" remain two different numbers and
// a reader can divide one by the other to get the real pass rate. Backs the
// new DRAW-CP-DRAWN-SKIPPED row; nothing existing is renamed or removed.
std::atomic<uint32_t> s_cpDrawnSkipped{0};
// F-648: draws that reached the draw call, i.e. the denominator of the
// topology/format gate. Without it a soak sees refusals but cannot tell whether
// the draws that DID issue were correctly shaped or merely few.
std::atomic<uint32_t> s_cpTopologyAssigned{0};

// ---------------------------------------------------------------------------
// F-652: pipeline-state DERIVATION, counted on the live path.
// ---------------------------------------------------------------------------
// DerivePipelineState (renderer/pipeline_cache.h:541) had NO caller anywhere in
// src/ before this: the whole guest-register -> blend/depth/cull/topology mapping
// was unreachable code that read as alive. It is called below, on the live
// DRAW_CAPTURED path, and its outcome is counted THREE ways, because the whole
// point of the exercise is that a soak must be able to tell these apart:
//
//   s_deriveAttempted  - DerivePipelineState was entered. THE gate: this is what
//                        distinguishes "no pipeline was ever requested" from
//                        "every pipeline was refused". Both read as zero today.
//   s_deriveOk         - it returned a state with refuseMask == kRefuseNone.
//   s_deriveRefused    - it returned refuseMask != 0.
//
// And the refusal is NEVER an unnamed code. s_deriveRefusedByBit is indexed by
// the bit in renderer::PipelineRefusal (pipeline_cache.h:157-194), so a soak
// reads a per-reason TOTAL and never has to parse a log line; the NAME for each
// bit comes from FormatPipelineRefusal (pipeline_cache.h:202), the one owner of
// the name table (pipeline_cache.cpp:196-252). One named reason at a time is
// NOT enough here: a single mask can carry four, and a histogram that collapsed
// them would lose exactly the attribution this is for.
//
// This is not hypothetical defensiveness. pipeline_cache.cpp:226-234 records a
// guard that sat BEFORE its loop, tested an always-zero variable, and made every
// refusal in the file render as "unnamed-0x%08X"; two agents were misled by
// hex-only reasons. So the histogram is filled per bit from the enum, and the
// bounded row prints the formatted names alongside it.
std::atomic<uint32_t> s_deriveAttempted{0};
std::atomic<uint32_t> s_deriveOk{0};
std::atomic<uint32_t> s_deriveRefused{0};
std::atomic<uint32_t> s_deriveRefusedByBit[32] = {};
// The run-wide OR of every refusal mask seen, so the PC-DERIVE row can name the
// reasons the WHOLE run produced rather than only the last draw's. Paired with
// the histogram above: the histogram is exact per reason, this is what lets a
// row render names at all.
std::atomic<uint32_t> s_deriveMaskOr{0};
// Refusals that are NOT a pipeline-state derivation failure: the draw was
// refused AFTER a successful derivation, for a reason about the program rather
// than the state. Kept apart from s_deriveRefused so "the state was wrong" and
// "the state was right and there is still no shader" cannot be conflated.
std::atomic<uint32_t> s_deriveNoVsProgram{0};   // no vertex program for this draw
std::atomic<uint32_t> s_deriveNoPsProgram{0};   // no pixel program for this draw
std::atomic<uint32_t> s_deriveNoTranslatedPso{0};  // state derived, no PSO to bind
// The refusal COUNTERS for those three, so DRAW-CP-CENSUS names each one
// without borrowing a vertex-buffer counter whose meaning it has nothing to do
// with (s_cpRefuseVbMissing counts missing geometry, not missing shaders).
std::atomic<uint32_t> s_cpRefuseNoVsProgram{0};
std::atomic<uint32_t> s_cpRefuseNoPsProgram{0};
std::atomic<uint32_t> s_cpRefuseNoPso{0};
// A DerivePipelineState refusal on a prim_type that IS a geometry type - so not
// the rectangle list and not the "unmappable topology" family. Distinct from
// s_cpRefusePrimOther (which means "D3D12 has no topology for this prim_type"):
// that column would otherwise absorb a rasteriser refusal and make the two
// questions indistinguishable.
std::atomic<uint32_t> s_cpRefuseStateRefused{0};
// F-723: the colour-format refusals. Three SEPARATE counters, because "the
// guest never presented RB_COLOR_INFO" and "the guest presented a code with no
// DXGI equivalent" are different facts and a soak must be able to tell them
// apart -- collapsing them would make a future fix for the second look like a
// success on the first.
//   noColorInfo     - RB_COLOR_INFO 0x2001 was NOT in the snapshot's
//                     presentMask: the guest never wrote it before this draw.
//                     A REFUSAL, not a zero format (see render_queue.h's
//                     kCpSnapColorInfo note on why code 0 is legal).
//   colorFmtUnmapped- RB_COLOR_INFO WAS presented and its 4-bit color_format is
//                     a code with no DXGI_FORMAT (8/9/11/13 unassigned).
//                     NOT defaulted; see MapXenosColorFormatToDxgi.
std::atomic<uint32_t> s_cpRefuseNoColorInfo{0};
std::atomic<uint32_t> s_cpRefuseColorFmtUnmapped{0};
// F-652: the program census, counted CONSUMER-side from the command's own
// fields so it reports what the draw really carried. Distinct from the
// producer's identical census in CP-DRAW-CENSUS on purpose: the producer row
// counts what was enqueued, this row counts what survived the queue's shed and
// eviction policies, and a gap between them is a queue defect neither row can
// see alone.
std::atomic<uint32_t> s_cpProgVsAddr{0};     // draw carried a vertex program ADDRESS
std::atomic<uint32_t> s_cpProgPsAddr{0};     // draw carried a pixel program ADDRESS
std::atomic<uint32_t> s_cpProgVsAbsent{0};   // no vertex program: a refusal
std::atomic<uint32_t> s_cpProgPsAbsent{0};   // no pixel program: a refusal
// Raster-state COVERAGE of what was consumed: one total per register that
// matters to the derivation, plus the all-three case that sets haveRegisters.
// These are TOTALS, never "the value": a missing register must be visible as a
// missing register.
std::atomic<uint32_t> s_cpRsCovPaClipCntl{0};
std::atomic<uint32_t> s_cpRsCovPaSuScModeCntl{0};
std::atomic<uint32_t> s_cpRsCovPaClVteCntl{0};
std::atomic<uint32_t> s_cpRsAll3{0};
// F-652: the rectangle-list expansion decision. `expanded` is 0 on every build
// that refuses; it exists as a counter so the refusal and a future expansion
// are the same column and a soak can see the gate flip rather than infer it from
// a marker's disappearance. `refused` keeps its own reason named on the row.
std::atomic<uint32_t> s_rectListExpanded{0};
std::atomic<uint32_t> s_rectListRefused{0};

// ---------------------------------------------------------------------------
// step 4: the vertex INPUT LAYOUT, counted on the live DRAW_CAPTURED path.
// ---------------------------------------------------------------------------
// Four totals, so a soak can tell four DIFFERENT failures apart instead of
// reading one "no layout" that could mean any of them:
//   s_layoutBuilt        - a real D3D12_INPUT_ELEMENT_DESC list came out of the
//                          authoritative builder. This is the only one of the
//                          four that means pixels are possible.
//   s_layoutNoDecl       - the draw carried no grcFvf declaration at all. THIS
//                          is the measured state of every draw in w682.log.
//   s_layoutDeclRefused  - a declaration WAS carried and the builder refused it
//                          (unknown channel, or fvfSize disagreeing with the
//                          computed stride, pipeline_cache.cpp:1247-1251).
//   s_layoutLogged       - rows PRINTED. Bounded like every other row here, so
//                          it is not a census; the three above are.
//
// `s_layoutDeclRefused` is currently unreachable, and it is kept anyway for the
// same reason s_rectListExpanded is kept: a gate and its own "it worked" total
// have to exist together or a soak can only ever infer the flip.
std::atomic<uint32_t> s_layoutBuilt{0};
std::atomic<uint32_t> s_layoutNoDecl{0};
std::atomic<uint32_t> s_layoutDeclRefused{0};
std::atomic<uint32_t> s_layoutLogged{0};

// ---------------------------------------------------------------------------
// F-716: the program -> pipeline chain's own census, one counter per gate, so a
// soak can read how far a captured draw got instead of inferring it from the
// absence of a pixel. Uncapped, process-lifetime; the ROW is bounded.
//
//   s_pipeVsCode / s_pipePsCode   -- the stage's OWN bytes were recovered
//   s_pipeEnvelopeBuilt           -- the host-side envelope wrapped them
//   s_pipeParsed                  -- ParseShaderProgram accepted the envelope
//   s_pipeTranslatedVs/Ps         -- TranslateShaderPinned produced HLSL
//   s_pipeLayoutFromVertexElements-- a semantic came from the program's OWN
//                                    element table, not from a fallback
//   s_pipeLayoutNoVertexElements  -- the element table was empty, so every
//                                    semantic would be the POSITION fallback
//   s_pipePsoRequested / s_pipePsoNull -- GetOrCompile asked / refused
//   s_pipePsoCarriesGeomStage     -- a returned PSO is known to have the
//                                    expansion stage bound (cache hit on a
//                                    rectangle key; see pipeline_cache.h)
//   s_pipeLogged                  -- rows PRINTED
std::atomic<uint32_t> s_pipeVsCode{0};
std::atomic<uint32_t> s_pipePsCode{0};
std::atomic<uint32_t> s_pipeEnvelopeBuilt{0};
std::atomic<uint32_t> s_pipeParsed{0};
std::atomic<uint32_t> s_pipeTranslatedVs{0};
std::atomic<uint32_t> s_pipeTranslatedPs{0};
std::atomic<uint32_t> s_pipeLayoutFromVertexElements{0};
std::atomic<uint32_t> s_pipeLayoutNoVertexElements{0};
std::atomic<uint32_t> s_pipePsoRequested{0};
std::atomic<uint32_t> s_pipePsoNull{0};
std::atomic<uint32_t> s_pipePsoCarriesGeomStage{0};
std::atomic<uint32_t> s_pipeLogged{0};
// 2026-10-02: rows PRINTED by the new `DRAW-CP-ISSUED` row, which is the
// only place a draw's own outcome is reported (BeginFrame, whether the draw
// call was made, what it returned, and the guest's RB_COLOR_INFO colour_format
// the PSO's RTVFormats[0] was built from). Its own counter, NOT s_pipeLogged:
// DRAW-CP-PIPE is a tracked marker and sharing a budget with a new row would
// let either one suppress the other.
std::atomic<uint32_t> s_cpIssuedLogged{0};

// ---------------------------------------------------------------------------
// F-647: the Xenos constant bank, produced here and ONLY here.
// ---------------------------------------------------------------------------
// d3d12_backend.cpp:2645-2646 already states the division of labour: "The
// producer (render_thread) owns the guest read, because that layer has the
// validity check; this layer only consumes host bytes." This is that read.
// Before it, D3D12Backend::DynamicMeshDesc::guestConstBytes stayed nullptr for
// every draw, so the backend took its `else` branch and memset a ZERO bank
// (d3d12_backend.cpp:2656). Measured in build/w661.log: 8 rows, all
// `CONST-BANK #N src=ZEROS regs=0 guestBytes=0 zeroFilled=0 truncated=0 ok=0`.
// A zero bank is not a neutral default -- it is a specific wrong answer a
// translated shader consumes silently.
//
// WHERE THE ADDRESS COMES FROM, and why it is the register file: the brief said
// "sqVsConst / sqPsConst are captured into the draw packet", and that is true of
// native::DrawPacket (src/renderer/trace_types.h:96,98), but that packet is
// built by DrawPacketAccumulator::OnDrawBuild in src/capture_hooks.cpp, which
// is a file this stream does not own, and it feeds the frame-trace writer, not
// this command loop. Neither draw command carries the field either:
// DrawIndexedCommand and DrawCapturedCommand (src/render_queue.h:12-35,
// :108-137) have no constant-bank member, and render_queue.h is likewise not
// this stream's to edit. The one producer that DOES hold these values and is
// reachable from here is the CP register file: SQ_VS_CONST is register 0x2307
// and SQ_PS_CONST is 0x2308 (.research/xenia/src/xenia/gpu/register_table.inc:
// 578-579), both poked by the same TYPE-0 traffic that writes 0x2204..0x2206.
// So the address is read by index through F-647's export.
//
// MEASURED, and this is a real limit not an assumption: `r2307` and `r2308`
// have ZERO occurrences in build/w660.log and build/w661.log. That is NOT proof
// the guest never writes them -- CP-DRAW-REGS is a 64-entry ring printed for the
// first 3 draws only and it skips zero values, so absence there is absence of
// evidence, not evidence of absence. What it does establish is that this read
// will most likely report `absent` for a while, and that must be a COUNTED
// refusal, not a silent zero-fill. The marker below is how a soak tells the
// two apart.
//
// BUFFER STRATEGY -- a fixed-size function-local `static` array, NOT a vector
// and NOT a ring, and the reason is that the size is a compile-time constant:
// kShaderConstantBankBytes is 256 * 16 = 4096 (renderer/pipeline_cache.h:73),
// which is exactly the 1,024-word Xenos float4 bank the task describes. A
// std::array of that size is allocated ONCE, on first use, and never again: the
// render path performs no per-frame allocation at all, which is the constraint
// the previous stream was given explicitly and the one that `static std::vector
// vb;` / `static std::vector ibRaw;` above already honour by growing only when
// a bigger capture arrives. A ring would be wrong here for a second reason: the
// bytes are consumed by MapUpload inside the backend call on this very stack
// frame, so a ring would have to be sized to the in-flight depth for no benefit
// over one buffer. Thread-safety: processCommand runs on the single render
// thread (RenderThread::threadMain), so one static buffer with no lock is
// correct -- same assumption the existing `static std::vector vb` relies on.
//
// BYTE ORDER, end to end: SQ_VS_CONST is a 32-bit GUEST VA. It is read with
// mem.IsValid (checked, no reinterpret_cast) and then mem.ReadBytes, which is
// the checked bulk read (kernel/memory.cpp: IsValid + __try/__except memcpy).
// ReadBytes performs NO byte swapping -- it is a verbatim copy of the guest's
// bytes out of the guest window -- so what lands in the buffer is still
// BIG-ENDIAN Xenos data, which is exactly what renderer::PackXenosConstantBank
// documents that it expects (pipeline_cache.h:550-554, and the BE assembly at
// pipeline_cache.cpp:989-993). This producer therefore does NO byte assembly
// and adds NO second endian site: the swap happens once, inside the packer, at
// the point that owns it. ReadBytes is chosen over a ReadU32BE loop precisely
// because a loop would make this file look like a second endian site.
//
// ALL-OR-NOTHING: either the whole 4,096-byte bank is read and both descriptor
// fields are set, or the read is abandoned, the reason is counted, and BOTH
// fields are left at their zero-initialised value (nullptr / 0) so the backend
// takes its existing no-bank path and reports `src=ZEROS`. A half-filled bank is
// worse than a zero one because it is partly right, so the packer is called by
// the backend with a size this function chose; the size is either the full
// kShaderConstantBankBytes or zero, never something in between.
//
// BOUNDED READ: the whole bank is one 4,096-byte read at (va, va+4095). A guest
// VA plus 4 KB can leave the 4 GiB window, so the range is checked BEFORE the
// read and the read itself is the checked helper. There is no clamp: a short
// read is a refusal, not a partial bank.

// The one buffer. 4,096 bytes = 256 Xenos float4 = kShaderConstantBankBytes.
static std::array<uint8_t, mcla::renderer::kShaderConstantBankBytes>
    s_constBank{};

// F-647 census: attempts and each named outcome, counted separately so a soak
// can read "the producer never ran" and "the producer ran and the guest address
// was not written" as two different facts.
std::atomic<uint32_t> s_constBankAttempts{0};
std::atomic<uint32_t> s_constBankFilled{0};
std::atomic<uint32_t> s_constBankRefNoRegister{0};  // 0x2307 not present in the CP file
std::atomic<uint32_t> s_constBankRefNoAddr{0};      // present, value == 0
std::atomic<uint32_t> s_constBankRefWrap{0};        // va + 4096 leaves the 4 GiB window
std::atomic<uint32_t> s_constBankRefUnmapped{0};    // IsValid() false
std::atomic<uint32_t> s_constBankRefReadFailed{0};  // ReadBytes() failed
// F-647: the descriptor can carry ONE bank (DynamicMeshDesc has a single
// guestConstBytes/guestConstBytesSize pair, d3d12_backend.h:88-89, and the root
// signature binds ONE b0 CBV, d3d12_backend.cpp:2676). So the pixel bank is
// read and REPORTED but not handed over, and this counter is how a soak proves
// that is a deliberate single-slot decision rather than the pixel bank being
// invisible. It is not a claim that VS is the correct choice -- it is the only
// one the descriptor can express.
std::atomic<uint32_t> s_constBankPsPresent{0};
std::atomic<uint32_t> s_constBankPsDroppedNoSlot{0};

// ---------------------------------------------------------------------------
// F-716 STEP 2, THE INTERPOLATOR REGISTER STATE -- the ONE piece of SQ_PROGRAM_CNTL
// the pixel interpolant count reads.
//
// THE CAPTURE END, CITED. src/gpu_cp.cpp:1170 `CpRegPoke(target, v)` stores every
// guest TYPE-0/REGISTER write into g_xenosReg[] (gpu_cp.cpp:1043-1061), and
// src/gpu_cp.cpp:658-661 `CpRegPeek` reads it back; the file's own marker prints
// the write at gpu_cp.cpp:1179-1182. SQ_PROGRAM_CNTL is register 0x2180
// (.research/xenia/src/xenia/gpu/register_table.inc:523), and MEASURED on the live
// boot in build/w704.log:
//
//   CP-REG-T0 #17 op=IB base=2180 n=2 written=2 val=1000000E writes=26
//
// so the guest DOES write it and it IS captured. Decoded against
// .research/xenia/src/xenia/gpu/registers.h:127-150 (each *_num_reg is stored
// MINUS 1): vs_num_reg = 0xE = 14 -> 15 GPRs, ps_num_reg = (val>>8)&0x3F = 0 -> 1
// GPR, vs_export_count = (val>>20)&0xF = 0 -> 1 interpolator output.
//
// 2026-10-05 CORRECTION. That line read "= 1 -> 2 interpolator outputs".
// Both numbers were wrong, and hand arithmetic catches it: the guest wrote
// 0x1000000E (CP-REG-T0 #17 base=2180 writes=26, and CP-DRAW-REGS #1 [24/57]
// r2180=1000000E), so (val>>20)&0xF is 0, not 1 -- the only set bit above
// bit 19 is bit 28. And registers.h:127-150 documents the field as
// "Interpolator output count minus 1", so 0 means ONE output.
//
// NOT A BEHAVIOURAL DEFECT: vs_export_count appears in this tree only in
// COMMENTS -- render_thread.cpp, gpu_mmio.h and render_queue.h, zero code
// reads it. Corrected because a false decode sitting next to a real one is
// how the next reader repeats it.
//
// A CORRECTION WORTH RECORDING, because the obvious index is the wrong one. The
// name SQ_PGM_RESOURCES_PS = 0x2301 in src/gpu_mmio.h (the enum moved to
// :79 on 2026-10-05 when a census comment was added above it) is NOT
// SQ_PROGRAM_CNTL:
// .research/xenia/src/xenia/gpu/register_table.inc:572 puts 0x2301 at PA_SC_AA_CONFIG
// and :571 puts 0x2300 at PA_SC_LINE_CNTL, while SQ_PROGRAM_CNTL is 0x2180. The
// w704 row `CP-REG-T0 #519000 op=IB base=2301 n=1 written=1 val=0000C003` is real
// and captured, but it is a PA_SC_AA_CONFIG write and its value must not be read as
// ps_num_reg. src/gpu_mmio.h is not this file's to correct; the note belongs here so
// the next reader does not repeat it.
//
// THE READ END, CITED. CpReadGuestRegisters (declared src/gpu_cp.h:107, defined
// src/gpu_cp.cpp:5920-5947) is the file's sanctioned read-only, presence-reporting
// export of that same array; this file already uses it for the constant banks
// (:830-841). `present == 0` means the guest never wrote the register and the value
// MUST be treated as meaningless, so this returns 0 -- which is the INITIALISER and
// NOT "the guest said zero" (see ShaderProgram::psNumReg). Returning 0 there is
// safe because GetDynamicAddressableRegisterCount ignores ps_num_reg entirely for a
// program that does not use register dynamic addressing
// (.research/xenia/src/xenia/gpu/shader.h:938-945).
//
// NOT A NEW MARKER. The plumbing is observable on the existing SHADER-UNWRITTEN-REG-
// READ row's appended `seedRule=` clause, which carries psNumReg and the two masks,
// so a new marker here would be a second place to census the same fact.
static uint32_t ReadPsNumRegField() {
    using mcla::gpu::CpReadGuestRegisters;
    constexpr uint32_t kRegSqProgramCntl = 0x2180u;
    constexpr uint32_t kIdx[1] = {kRegSqProgramCntl};
    uint32_t val[1] = {0};
    uint32_t pres[1] = {0};
    (void)CpReadGuestRegisters(kIdx, 1u, val, pres);
    // ps_num_reg occupies bits 8-13 (registers.h:136) and is stored MINUS 1.
    return pres[0] ? ((val[0] >> 8) & 0x3Fu) : 0u;
}

// Fills `out` (a DynamicMeshDesc) with the Xenos constant bank, or leaves it
// untouched. Returns true when a bank was handed over.
bool FillGuestConstantBank(D3D12Backend::DynamicMeshDesc& out) {
    using mcla::gpu::CpReadGuestRegisters;
    using mcla::gpu::kCpRegSqVsConst;
    using mcla::gpu::kCpRegSqPsConst;
    constexpr uint32_t kBankBytes = mcla::renderer::kShaderConstantBankBytes;

    // Both banks' addresses in ONE export call, so the marker and the CP-REGS-
    // EXPORT row agree on the same snapshot. VS is the one we can hand over.
    static constexpr uint32_t kIdx[2] = {kCpRegSqVsConst, kCpRegSqPsConst};
    uint32_t val[2] = {0, 0};
    uint32_t pres[2] = {0, 0};
    (void)CpReadGuestRegisters(kIdx, 2u, val, pres);

    const uint32_t n =
        s_constBankAttempts.fetch_add(1, std::memory_order_relaxed) + 1u;
    if (pres[1]) {
        s_constBankPsPresent.fetch_add(1, std::memory_order_relaxed);
    }

    // Named refusal, bounded log, one row per attempt for the first 8 then
    // every 200th (house pattern). `filled` and `reason` are on the SAME row so
    // an outcome and its cause can never be read from different lines.
    const char* reason = nullptr;
    std::atomic<uint32_t>* counter = nullptr;
    uint32_t vsVa = val[0];

    if (!pres[0]) {
        reason = "vs-reg-absent";
        counter = &s_constBankRefNoRegister;
    } else if (vsVa == 0u) {
        reason = "vs-addr-zero";
        counter = &s_constBankRefNoAddr;
    } else if (static_cast<uint64_t>(vsVa) + static_cast<uint64_t>(kBankBytes) >
               0x100000000ull) {
        // Guest VA + 4 KB leaves the 32-bit window. Same test the index buffer
        // uses (DRAW_CAPTURED's `ib-wrap` gate): refuse, never wrap.
        reason = "vs-wrap-4g";
        counter = &s_constBankRefWrap;
    }

    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
    if (!reason && !mem.IsValid(vsVa, kBankBytes)) {
        reason = "vs-unmapped";
        counter = &s_constBankRefUnmapped;
    }
    if (!reason && !mem.ReadBytes(vsVa, s_constBank.data(), kBankBytes)) {
        // The range was validated and the read still failed: the page was
        // unmapped between the two calls, or the SEH guard tripped. Either way
        // the buffer now holds PARTIAL guest bytes, so it must not be handed
        // over -- which is why this returns without touching `out`.
        reason = "vs-read-failed";
        counter = &s_constBankRefReadFailed;
    }

    if (reason) {
        counter->fetch_add(1, std::memory_order_relaxed);
        if (n <= 8u || (n % 200u) == 0u) {
            MCLA_LOG_WARN("CONST-BANK-PRODUCE #{} filled=0 reason={} vsRegPresent={} "
                          "vsVa={:08X} psRegPresent={} psVa={:08X} bankBytes={} "
                          "| totals attempts={} filled={} noReg={} noAddr={} "
                          "wrap={} unmapped={} readFailed={} psPresent={}",
                          n, reason, pres[0], vsVa, pres[1], val[1], kBankBytes,
                          s_constBankAttempts.load(std::memory_order_relaxed),
                          s_constBankFilled.load(std::memory_order_relaxed),
                          s_constBankRefNoRegister.load(std::memory_order_relaxed),
                          s_constBankRefNoAddr.load(std::memory_order_relaxed),
                          s_constBankRefWrap.load(std::memory_order_relaxed),
                          s_constBankRefUnmapped.load(std::memory_order_relaxed),
                          s_constBankRefReadFailed.load(std::memory_order_relaxed),
                          s_constBankPsPresent.load(std::memory_order_relaxed));
        }
        return false;
    }

    // The only success path. Both fields are set together or neither is, so the
    // backend can never see a pointer without its size.
    out.guestConstBytes = s_constBank.data();
    out.guestConstBytesSize = kBankBytes;
    if (pres[1] && val[1] != 0u) {
        s_constBankPsDroppedNoSlot.fetch_add(1, std::memory_order_relaxed);
    }
    s_constBankFilled.fetch_add(1, std::memory_order_relaxed);
    if (n <= 8u || (n % 200u) == 0u) {
        MCLA_LOG_WARN("CONST-BANK-PRODUCE #{} filled=1 reason=- vsRegPresent={} "
                      "vsVa={:08X} psRegPresent={} psVa={:08X} bankBytes={} "
                      "(big-endian, packed by PackXenosConstantBank) "
                      "| totals attempts={} filled={} noReg={} noAddr={} "
                      "wrap={} unmapped={} readFailed={} psDroppedNoSlot={}",
                      n, pres[0], vsVa, pres[1], val[1], kBankBytes,
                      s_constBankAttempts.load(std::memory_order_relaxed),
                      s_constBankFilled.load(std::memory_order_relaxed),
                      s_constBankRefNoRegister.load(std::memory_order_relaxed),
                      s_constBankRefNoAddr.load(std::memory_order_relaxed),
                      s_constBankRefWrap.load(std::memory_order_relaxed),
                      s_constBankRefUnmapped.load(std::memory_order_relaxed),
                      s_constBankRefReadFailed.load(std::memory_order_relaxed),
                      s_constBankPsDroppedNoSlot.load(std::memory_order_relaxed));
    }
    return true;
}

// ---------------------------------------------------------------------------
// F-716: program IDENTITY, and the envelope this project's translator needs to
// read it. Both steps were missing, and the second one is a documented DEVIATION
// from the reference, so it is spelled out here rather than discovered later.
// ---------------------------------------------------------------------------
//
// STEP 1, IDENTITY. The identity of a program is its own BYTES, and the bytes
// are already on the command: DrawCapturedCommand carries one CpShaderProgram
// per stage (render_queue.h:411-412) and that record carries the body itself
// (render_queue.h:322, `body[kCpShaderBodyDwords]`) plus the dword count the
// PM4_IM_LOAD packet declared (`dwords`, render_queue.h:307). So identity needs
// no container, no address and no lookup: `body[0..captured)` IS the program.
//
// STEP 2, THE ENVELOPE, AND WHY IT IS NOT A PORT. The reference never has one.
// Measured, in four places:
//   * command_processor.cc:1574-1576 -- the embedded form hands LoadShader the
//     RAW PACKET POINTER plus size_dwords: `LoadShader(shader_type,
//     uint32_t(reader->read_ptr()), reinterpret_cast<uint32_t*>(
//     reader->read_ptr()), size_dwords)`;
//   * command_processor.cc:1542-1544 -- the pointer form is the same shape, and
//     the guest address is a program ADDRESS, not a container address;
//   * d3d12/pipeline_cache.cc:846-847 -- the shader's identity is a hash of the
//     raw dwords alone, `XXH3_64bits(host_address, dword_count * sizeof(uint32_t))`,
//     with no header, no flags and no metadata-size term;
//   * shader.cc:27-37 -- `Shader` stores the program as a plain
//     `std::vector<uint32_t> ucode_data_` of that many dwords. There is no
//     container object anywhere in the reference's shader path.
// A container is therefore THIS PROJECT'S TRANSLATOR'S PREMISE, not the
// hardware's: ParseShaderProgram rejects anything whose first dword does not
// carry the 0x102A11 magic (xenos_shader_ir.cpp:37), and the entry point this
// stream is required to use, TranslateShaderPinned, goes through it
// (shader_translator.cpp:1269 -> :1351).
//
// So the envelope below is a HOST-SIDE ADAPTER whose only purpose is to hand
// the existing entry point the guest's own bytes. Its fields split by provenance
// and the split is not negotiable:
//   MEASURED, guest data, byte-for-byte:
//     * the code bytes. Copied, never regenerated.
//     * shaderSize = the captured dword count * 4. That count is
//       `size_dwords = start_size & 0xFFFF` (command_processor.cc:1570), the
//       same field render_queue.h:307 names.
//     * flags bit 0 (isVertex), from the stage tag the guest's own packet
//       carried (xenos::ShaderType, command_processor.cc:1567-1568).
//   HOST-SIDE LAYOUT, chosen so ParseShaderProgram's own arithmetic resolves the
// code and NOTHING ELSE resolves:
//     * virtualSize / physicalSize / `so` / physicalOffset, all below.
//   ZERO, and this is the part that COSTS:
//     * the metadata tables. fieldC (the svPos register), field10 and
//       interpolatorInfo are 0, so out.constants is empty (xenos_shader_ir.cpp
//       :94-98, cto == 0 skips the table) and out.interpolators is empty
//       (:180-192, :206-216). The vertex-element table is ABSENT BY GUARD, not
//       by omission: the guard at :167-168 is
//       `so + 36 + (veStart + veCount + 32) * 4 <= virtualSize`, and the sizes
//       below make 72 > 60, so it fails and no element is invented.
//
// THE COST, STATED PLAINLY, because it is what stops the draw downstream and a
// reader must not have to rediscover it: with no vertex-element table the
// program's `vertexElements` is empty, and ReferencedVertexInputs resolves EVERY
// fetch to usage 0 = POSITION by its own documented fallback
// (shader_translator.cpp:68-78 -- it matches against vertexElements, and when
// that list is empty it returns element [0], which does not exist, so the
// initialised 0 stands). That is a FALLBACK, not a measurement, and the layout
// gate below refuses on exactly that condition rather than binding a semantic
// the guest never declared. On the reference this information does not come
// from the program at all: the vertex elements are the vertex-FETCH hardware's,
// and the interpolant set is read from the register file
// (d3d12/pipeline_cache.cc:882 and :915, `interpolator_mask` from
// SQ_INTERPOLATOR_CNTL). Neither register is captured by this project, which is
// the named blocker.

// Envelope geometry. Internal linkage (const), and each value is either a
// constant of the format being adapted or arithmetic on measured fields.
constexpr uint32_t kEnvMagic        = 0x102A1100u;  // ParseShaderProgram's (flags & 0xFFFFFF00)
constexpr uint32_t kEnvShaderHdrOff = 36u;           // the `so` we hand it
constexpr uint32_t kEnvShaderHdrLen = 24u;           // xenos_shader_ir.cpp kShaderHeaderSize
// virtualSize only has to cover the container header plus the shader header, and
// it MUST stay below the vertex-element guard's threshold (72 bytes) so the
// element table is skipped rather than invented.
constexpr uint32_t kEnvVirtualSize  = kEnvShaderHdrOff + kEnvShaderHdrLen;  // 60

// One stage's program CODE BYTES, in the byte order ParseShaderProgram reads
// (big-endian, ReadBE32 at xenos_shader_ir.cpp:9-11), plus the name of where
// they came from. Returns 0 and sets `sourceOut` to a refusal reason when this
// stage has no usable bytes; the caller refuses by that name.
static size_t ResolveStageCode(const CpShaderProgram& p,
                              std::vector<uint8_t>& codeOut,
                              const char*& sourceOut,
                              mcla::kernel::GuestMemoryHeap& mem) {
    sourceOut = "absent";
    if (p.present == 0u) {
        sourceOut = "no-im-load";
        return 0;
    }
    // `captured` may EXCEED the array (render_queue.h:314-315), so the cap is a
    // precondition, not a clamp: reading past body[255] is an out-of-bounds read.
    if (p.captured == 0u || p.captured > kCpShaderBodyDwords) {
        sourceOut = "captured-out-of-range";
        return 0;
    }
    const size_t useDwords = p.captured;
    if (p.embedded != 0u) {
        // PM4_IM_LOAD_IMMEDIATE (0x2B): the body is in the packet, i.e. here.
        // body[] holds LOGICAL dwords in HOST order (render_queue.h:297-299), so
        // the wire order is written out big-endian by hand rather than memcpy'd.
        codeOut.resize(useDwords * 4u);
        for (size_t i = 0; i < useDwords; ++i) {
            const uint32_t v = p.body[i];
            codeOut[i * 4 + 0] = static_cast<uint8_t>(v >> 24);
            codeOut[i * 4 + 1] = static_cast<uint8_t>(v >> 16);
            codeOut[i * 4 + 2] = static_cast<uint8_t>(v >> 8);
            codeOut[i * 4 + 3] = static_cast<uint8_t>(v);
        }
        sourceOut = "embedded";
        return codeOut.size();
    }
    // PM4_IM_LOAD (0x27): the body is in guest memory at `guestAddr`, and it is
    // read through the checked helper, never reinterpret_cast. Per the reference
    // (command_processor.cc:1542-1544) that address holds RAW MICROCODE, so the
    // bytes come out in wire order already and are copied verbatim.
    if (p.guestAddr == 0u) {
        sourceOut = "no-address";
        return 0;
    }
    const uint64_t want = static_cast<uint64_t>(useDwords) * 4ull;
    if (static_cast<uint64_t>(p.guestAddr) + want > 0x100000000ull) {
        sourceOut = "address-wraps";
        return 0;
    }
    codeOut.resize(useDwords * 4u);
    if (!mem.ReadBytes(p.guestAddr, codeOut.data(), codeOut.size())) {
        sourceOut = "read-failed";
        return 0;
    }
    sourceOut = "guest-memory";
    return codeOut.size();
}

// Wraps guest code bytes in the minimum container ParseShaderProgram accepts.
// Returns false if the code is empty. `isVertex` comes from the guest's own
// stage tag; nothing else here is a guest fact.
static bool BuildProgramEnvelope(const uint8_t* code, size_t codeBytes,
                                 bool isVertex, std::vector<uint8_t>& envOut) {
    if (code == nullptr || codeBytes == 0u) return false;
    envOut.assign(kEnvVirtualSize + codeBytes, 0u);
    uint8_t* const d = envOut.data();
    const auto put = [d](size_t off, uint32_t v) {
        d[off + 0] = static_cast<uint8_t>(v >> 24);
        d[off + 1] = static_cast<uint8_t>(v >> 16);
        d[off + 2] = static_cast<uint8_t>(v >> 8);
        d[off + 3] = static_cast<uint8_t>(v);
    };
    put(0,  kEnvMagic | (isVertex ? 1u : 0u));  // bit 0 == isVertex (xenos_shader_ir.cpp:44)
    put(4,  kEnvVirtualSize);                   // >= so + 24 (guard at :47)
    put(8,  static_cast<uint32_t>(codeBytes));   // physicalSize; :41 wants vsize+psize <= size
    // +12/+16/+20 are not read by the parser; 0x10 (cto) must be 0 so the
    // constant table is skipped rather than read (:94-98).
    put(24, kEnvShaderHdrOff);                   // `so`
    put(28, 0);                                  // f1C: must be 0 (:40)
    put(32, 0);                                  // f20: must be 0 (:40)
    put(kEnvShaderHdrOff + 0,  0);               // physicalOffset -> code sits at virtualSize
    put(kEnvShaderHdrOff + 4,  static_cast<uint32_t>(codeBytes));  // shaderSize, MEASURED
    put(kEnvShaderHdrOff + 8,  0);               // unused by the parser
    put(kEnvShaderHdrOff + 12, 0);               // fieldC: the svPos register -- NOT MEASURED
    put(kEnvShaderHdrOff + 16, 0);               // field10 -- NOT MEASURED
    put(kEnvShaderHdrOff + 20, 0);               // interpolatorInfo: 0 interpolants
    std::memcpy(d + kEnvVirtualSize, code, codeBytes);
    return true;
}

// F-720: how many BYTES one vfetch instruction actually consumes of the vertex,
// as the reference computes it.
//
// WHY THIS IS NOT `CpXenosFormatBytes`. That function IS exported
// (render_queue.h:785) and it is the right table -- but its signature is
// `uint32_t(uint32_t fmt)`: ONE argument, NO components. It is therefore
// GetVertexFormatNeededWords(fmt, 0b1111) * 4, the size for ALL FOUR components,
// which is NOT what the fetch reads when the destination swizzle selects a
// subset. The reference does not use the all-components size: it builds
// `used_result_components` from the destination swizzle FIRST
// (.research/xenia/src/xenia/gpu/shader_interpreter.cc:1019-1026) and only then
// asks for the words (:1027-1028). So the components argument this arithmetic
// needs does not exist in the form available, and the raw-word formula below is
// used instead, transcribed from xenos.h:648-683 -- as instructed, because
// recomputing the popcount is the only way to honour the swizzle.
//
// WHY NOT `el.fmt.bytes` EITHER, even though it is on the struct already:
// it is the same all-components number, carried once at the producer
// (gpu_cp.cpp:3898, `CpXenosFormatBytes(e.formatXenos)`). Using it would make
// the accounting over-count any swizzle that drops a component, which would
// understate bytesUnaccounted -- i.e. the check would stop being able to fail.
//
// MEASURED (build/w686.log, CP-FETCHVB-DESC #1 / #3, the two live streams):
//   element 0  vf=57 dstSwizzle=0xA88 -> used=0b0111 -> mask 0b0111 -> 3 -> 12 B
//   element 1  vf=38 dstSwizzle=0x688 -> used=0b1111 -> mask 0b1111 -> 4 -> 16 B
//   draw 2 e0  vf=37 dstSwizzle=0xB48 -> used=0b0011 -> mask 0b0011 -> 2 ->  8 B
// and the same two vfetch words appear verbatim in the guest microcode itself,
// CP-SHADER-BODY #3 body[9..11] = 30081000 00393A88 00000007 and body[12..14]
// = 00080000 40263688 00000300, which decode to the same five fields.
// so draw 1 accounts 12 + 16 = 28 = its stride and draw 2 accounts 8 = its
// stride, both exactly. For THESE three elements all-components and
// swizzle-narrowed happen to AGREE (each swizzle selects every component its
// format carries), so CpXenosFormatBytes would print the same numbers today;
// over all 16 ids x 4096 swizzles the two disagree on 53.59% of the pairs
// (e.g. vf=6 swizzle=0x924: 0 B here vs 4 B there), which is why the
// distinction is a comment and not a bug report.
//
// GetVertexFormatNeededWords returns a 4-BIT MASK of needed dwords, NOT a
// COUNT (xenos.h:665-667 return `0b0010` for two words, and the reference
// iterates it as a mask at shader_interpreter.cc:1036-1039). The byte count is
// therefore popcount(mask) * 4. Passing the mask through as a count would give
// 28 and 60 bytes here, i.e. 7x and 15x the truth.
//
// Every id outside the 16 of xenos.h:602-619 (including kUndefined == 0) hits
// the reference's `default: assert_unhandled_case` arm, so this returns 0 and
// the CALLER refuses on it rather than inventing a size.
static uint32_t CpVfetchBytesForSwizzle(uint32_t xenosFormat, uint32_t dstSwizzle) {
    // used_result_components, shader_interpreter.cc:1020-1026 verbatim: four
    // 3-bit selectors, each naming a component when its value is <= 3.
    uint32_t used = 0u;
    for (uint32_t i = 0u; i < 4u; ++i) {
        const uint32_t sel = (dstSwizzle >> (3u * i)) & 0x7u;
        if (sel <= 3u) {
            used |= (1u << sel);
        }
    }
    // xenos.h:651-653 returns 0 for used_components == 0 BEFORE the switch, so
    // this guard is not cosmetic: without it k_8_8_8_8 / k_2_10_10_10 would
    // report one dword for a swizzle that selects no component at all. Found by
    // the differential test over all 16 ids x 4096 swizzles (512 mismatches,
    // exactly 2 formats x the 256 swizzles whose four selectors are all > 3).
    if (used == 0u) {
        return 0u;
    }
    uint32_t mask = 0u;  // the 4-bit dword mask of xenos.h:648-683
    switch (xenosFormat) {
        case 6: case 7:                                   // k_8_8_8_8, k_2_10_10_10
            mask = 0b0001; break;
        case 16: case 17:                                 // k_10_11_11, k_11_11_10
            mask = (used & 0b0111) ? 0b0001 : 0b0000; break;
        case 25: case 31:                                 // k_16_16, k_16_16_FLOAT
            mask = (used & 0b0011) ? 0b0001 : 0b0000; break;
        case 26: case 32:                                 // k_16_16_16_16(_FLOAT)
            mask = ((used & 0b0011) ? 0b0001 : 0b0000) |
                   ((used & 0b1100) ? 0b0010 : 0b0000); break;
        case 33: case 36:                                 // k_32, k_32_FLOAT
            mask = used & 0b0001; break;
        case 34: case 37:                                 // k_32_32(_FLOAT)
            mask = used & 0b0011; break;
        case 35: case 38:                                 // k_32_32_32_32(_FLOAT)
            mask = used; break;
        case 57:                                          // k_32_32_32_FLOAT
            mask = used & 0b0111; break;
        default:
            return 0u;  // kUndefined and every unnamed id: a refusal, not a size
    }
    // popcount of a 4-bit mask, written out rather than <bit>'s so this file
    // gains no include.
    return ((mask & 1u) + ((mask >> 1) & 1u) + ((mask >> 2) & 1u) +
            ((mask >> 3) & 1u)) * 4u;
}

void RenderThread::processCommand(const RenderCommand& cmd) {
    switch (cmd.type) {
        case RenderCommand::INIT_D3D12: {
            const auto& init = std::get<InitD3D12Command>(cmd.data);
            if (!d3d12Initialized_) {
                if (backend_.Initialize(static_cast<HWND>(init.hwnd), init.width, init.height)) {
                    d3d12Initialized_ = true;
                    MCLA_LOG_INFO("RenderThread: D3D12 initialized ({}x{})", init.width, init.height);
                } else {
                    MCLA_LOG_ERROR("RenderThread: D3D12 initialization failed");
                }
            }
            break;
        }
        case RenderCommand::DRAW_INDEXED: {
            if (!d3d12Initialized_) break;
            const auto& d = std::get<DrawIndexedCommand>(cmd.data);
            static std::atomic<uint32_t> drawCount{0};
            const uint32_t n = drawCount.fetch_add(1) + 1;
            if (n <= 20 || (n % 1000) == 0)
                MCLA_LOG_INFO("RenderThread: DRAW_INDEXED #{} prim={} vb={:08X} ib={:08X} "
                              "count={} stride={} vbSize={} ibSize={} vs={:08X} ps={:08X}",
                              n, d.primitiveTopology, d.vbAddr, d.ibAddr,
                              d.indexCount, d.vbStride, d.vbSize, d.ibSize,
                              d.vsProgram, d.psProgram);

            if (d.vbAddr == 0 || d.vbSize == 0 || d.ibAddr == 0 || d.ibSize == 0 || d.indexCount == 0) break;

            auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
            std::vector<uint8_t> vb(d.vbSize);
            std::vector<uint8_t> ib(d.ibSize);
            if (!mem.ReadBytes(d.vbAddr, vb.data(), d.vbSize)) break;
            if (!mem.ReadBytes(d.ibAddr, ib.data(), d.ibSize)) break;

            // Attempt PSO lookup from shader programs
            ID3D12PipelineState* pipeline = nullptr;
            Microsoft::WRL::ComPtr<ID3D12PipelineState> cachedPso;

            if (d.vsProgram != 0 && d.psProgram != 0) {
                // Read shader containers from guest memory
                auto vsContainer = ReadShaderContainer(mem, d.vsProgram);
                auto psContainer = ReadShaderContainer(mem, d.psProgram);

                if (!vsContainer.empty() && !psContainer.empty()) {
                    // Translate shaders to HLSL
                    mcla::renderer::TranslatedShader vsOut, psOut;
                    bool vsOk = mcla::renderer::TranslateShader(
                        vsContainer.data(), vsContainer.size(), {}, vsOut);
                    bool psOk = mcla::renderer::TranslateShader(
                        psContainer.data(), psContainer.size(), {}, psOut);

                    if (vsOk && psOk && !vsOut.hlsl.empty() && !psOut.hlsl.empty()) {
                        // Parse VS IR for vertex input layout
                        mcla::renderer::ShaderProgram vsProg;
                        if (mcla::renderer::ParseShaderProgram(
                                vsContainer.data(), vsContainer.size(), vsProg)) {

                            // Build input layout: prefer grcFvf if available,
                            // otherwise fall back to VS reflection
                            std::vector<D3D12_INPUT_ELEMENT_DESC> inputLayout;
                            uint64_t vertexDeclHash = 0;

                            if (d.hasGrcFvf && d.fvfMask != 0 && d.fvfSize != 0) {
                                // Build from grcFvf
                                GrcFvfDesc fvf{};
                                fvf.fvfMask = d.fvfMask;
                                fvf.fvfSize = d.fvfSize;
                                fvf.flags = d.fvfFlags;
                                fvf.dynamicOrder = d.fvfDynamicOrder;
                                fvf.channelCount = d.fvfChannelCount;
                                fvf.types = d.fvfTypes;
                                inputLayout = backend_.BuildInputLayoutFromGrcFvf(fvf);
                                if (!inputLayout.empty()) {
                                    vertexDeclHash = mcla::native::HashGrcFvfDeclaration(
                                        mcla::native::DecodeGrcFvf(fvf));
                                }
                            }

                            // Fallback: build from VS reflection
                            if (inputLayout.empty()) {
                                const auto refs = mcla::renderer::ReferencedVertexInputs(vsProg);
                                for (const auto& r : refs) {
                                    D3D12_INPUT_ELEMENT_DESC desc = {};
                                    desc.SemanticName = mcla::renderer::VertexUsageSemanticName(r.usage);
                                    desc.SemanticIndex = r.usageIndex;
                                    desc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
                                    desc.InputSlot = 0;
                                    desc.InputSlotClass = D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA;
                                    desc.AlignedByteOffset = D3D12_APPEND_ALIGNED_ELEMENT;
                                    inputLayout.push_back(desc);
                                }
                                // Hash from VS vertex declaration
                                std::vector<uint32_t> vf;
                                std::vector<uint8_t> usage, usageIndex;
                                for (const auto& r : refs) {
                                    vf.push_back(r.vertexFormat);
                                    usage.push_back(static_cast<uint8_t>(r.usage));
                                    usageIndex.push_back(static_cast<uint8_t>(r.usageIndex));
                                }
                                if (!vf.empty()) {
                                    vertexDeclHash = mcla::renderer::HashShaderBytecode(
                                        std::vector<uint8_t>(
                                            reinterpret_cast<const uint8_t*>(vf.data()),
                                            reinterpret_cast<const uint8_t*>(vf.data() + vf.size())));
                                }
                            }

                            if (!inputLayout.empty()) {
                                // Build pipeline state
                                mcla::renderer::PipelineState state = {};
                                state.targetFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM;
                                state.depthStencilFormat = DXGI_FORMAT_D24_UNORM_S8_UINT;
                                state.blendState = 0;
                                state.rasterState = 0;
                                state.depthStencilState = 0;
                                state.topology = 0; // triangle
                                state.sampleCount = 1;

                                // Compute pipeline key
                                mcla::renderer::PipelineKey key = mcla::renderer::ComputePipelineKey(
                                    vsOut.programHash, psOut.programHash,
                                    vertexDeclHash, state);

                                // Look up or compile PSO
                                auto& cache = backend_.GetPipelineCache();
                                cachedPso = cache.GetOrCompile(
                                    key, vsOut.hlsl, psOut.hlsl, inputLayout);
                                if (cachedPso) {
                                    pipeline = cachedPso.Get();
                                    s_psoCacheHits.fetch_add(1, std::memory_order_relaxed);
                                    if (n <= 5 || (n % 500) == 0)
                                        MCLA_LOG_INFO("RenderThread: PSO HIT #{} vs={:016X} ps={:016X}",
                                                      n, vsOut.programHash, psOut.programHash);
                                } else {
                                    s_psoCacheMisses.fetch_add(1, std::memory_order_relaxed);
                                    if (n <= 5 || (n % 500) == 0)
                                        MCLA_LOG_INFO("RenderThread: PSO MISS #{} (async compile in progress)",
                                                      n);
                                }
                            }
                        }
                    } else {
                        s_psoTranslateFailures.fetch_add(1, std::memory_order_relaxed);
                        if (n <= 3 || (n % 1000) == 0)
                            MCLA_LOG_WARN("RenderThread: shader translate failed #{} vs={} ps={}",
                                          n, d.vsProgram, d.psProgram);
                    }
                } else {
                    if (n <= 3 || (n % 1000) == 0)
                        MCLA_LOG_WARN("RenderThread: shader container read failed #{} vs={} ps={}",
                                      n, d.vsProgram, d.psProgram);
                }
            }

            // Stats logging
            if (n == 1 || (n % 2000) == 0) {
                MCLA_LOG_INFO("RenderThread: PSO stats — hits={} misses={} translate_fails={}",
                              s_psoCacheHits.load(), s_psoCacheMisses.load(),
                              s_psoTranslateFailures.load());
            }

            D3D12Backend::DynamicMeshDesc desc = {};
            desc.vertexBytes = vb.data();
            desc.vertexBytesSize = d.vbSize;
            desc.vertexStride = d.vbStride;
            desc.vertexCount = (d.vbStride > 0) ? (d.vbSize / d.vbStride) : 0;
            desc.indexed = true;
            desc.indexBytes = ib.data();
            desc.indexBytesSize = d.ibSize;
            desc.indexFormat = (d.ibFormat & 1) ? DXGI_FORMAT_R32_UINT : DXGI_FORMAT_R16_UINT;
            desc.indexCount = d.indexCount;
            // F-648: desc.topology is DELIBERATELY still unset on this path, and
            // that is not an oversight. The DRAW_CAPTURED path sets it from
            // VGT_DRAW_INITIATOR.prim_type (the architected xenos::PrimitiveType,
            // xenos.h:44-59), but THIS command's primitiveTopology is filled at
            // src/gpu_device.cpp:3289 as `ctx.r4.u32 & 7u` - three bits of a PPC
            // context register, and capture_hooks.cpp:227 builds the sibling
            // DrawPacket::primType the same way (`drawFlags & 7`). That is a
            // different value space: a 3-bit field cannot even represent
            // kRectangleList = 0x08. Running it through MapXenosPrimType would
            // apply an architected enum mapping to an undecoded register field,
            // which is the substitution F-609 forbids, so it is left unset and the
            // backend's F-650 UNDEFINED refusal (src/d3d12_backend.cpp:2608-2619)
            // reports it honestly. Measured dead in build/w662.log: the
            // DRAW_INDEXED marker is 0, so this path issues nothing today. The
            // named blocker is gpu_device.cpp:3289's `& 7u` mask - when that
            // field is decoded as prim_type, this line is a one-liner.
            // F-647: same constant-bank producer as DRAW_CAPTURED. This path's
            // command (DrawIndexedCommand, render_queue.h:12-35) carries no
            // constant-bank member, so the address is read from the CP register
            // file there too -- SQ_VS_CONST, register 0x2307. Non-fatal on
            // refusal; see the DRAW_CAPTURED call for the rationale.
            (void)FillGuestConstantBank(desc);

            // B4 (T41.4b): one present per drawn frame. DrawDynamicMesh* already
            // closes, executes, presents and advances the frame index, so the
            // old ClearAndPresent() here was a SECOND present of the same frame
            // whose first act is ClearRenderTargetView — it erased whatever the
            // draw had just rendered. The present belongs to the draw path until
            // the backend grows a real EndFrame.
            if (backend_.BeginFrame()) {
                if (pipeline) {
                    backend_.DrawDynamicMeshWithPipeline(desc, pipeline);
                } else {
                    backend_.DrawDynamicMesh(desc);
                }
                // 2026-10-02: THIS IS THE ONE THAT CANNOT RECOVER ON ITS OWN.
                // DrawDynamicMesh (the no-pipeline entry) REFUSES by design --
                // it returns false at d3d12_backend.cpp:2710 after counting the
                // refusal, and never presents. So on the `else` branch this
                // frame was begun and is then dropped with the latch still set,
                // and from that moment every BeginFrame() in the process
                // returns false. That is the exact shape of the measured symptom
                // (DRAW-CP-ISSUED beginFrame=0 with no other marker moving), and
                // it is reachable from this file today, so it is closed rather
                // than merely noted. DrawDynamicMeshWithPipeline presents
                // through PresentOwnedFrame, which clears the latch itself, so
                // the AbandonFrame on that branch is a no-op.
                backend_.AbandonFrame("draw-indexed");
            }
            break;
        }
        case RenderCommand::SET_PIPELINE_STATE: {
            const auto& p = std::get<SetPipelineStateCommand>(cmd.data);
            MCLA_LOG_DEBUG("RenderThread: SetPipelineState hash={:016X}", p.psoHash);
            break;
        }
        case RenderCommand::SET_RENDER_STATE: {
            const auto& rs = std::get<SetRenderStateCommand>(cmd.data);
            static std::atomic<uint32_t> rsCount{0};
            const uint32_t n = rsCount.fetch_add(1) + 1;
            if (n <= 20 || (n % 1000) == 0)
                MCLA_LOG_INFO("RenderThread: SET_RENDER_STATE #{} dev={:08X} value={:08X}",
                              n, rs.deviceAddr, rs.value);
            break;
        }
        case RenderCommand::PRESENT: {
            if (!d3d12Initialized_) break;
            const auto& p = std::get<PresentCommand>(cmd.data);
            static std::atomic<uint32_t> presentCount{0};
            const uint32_t n = presentCount.fetch_add(1) + 1;
            // B4 (T41.4b): the 33 ms heartbeat enqueues exactly
            // {frameNumber=0, obj=0, swapInfo=0}, so it can be told apart from a
            // guest PresentKick without guessing. Counting them as PRESENT made
            // the marker measure our own timer, not the guest (w102: 60 PRESENT
            // lines, all heartbeat). The heartbeat line deliberately avoids the
            // substring "PRESENT" because soak_census counts matching LINES
            // (F-054 discipline): a guest-driven PRESENT count is now real.
            // F-610: that test is now the single IsHeartbeatPresent() in
            // render_queue.h, shared with the queue's shed policy so the two
            // cannot drift and disagree about which PRESENT is which.
            const bool heartbeat = IsHeartbeatPresent(cmd);
            if (n <= 10 || (n % 120) == 0) {
                // T43.18 (2026-10-13): mainwait=* is the TAIL-LIGHT for the
                // main thread's latest park (published uncapped by the
                // main-park probes; xdm.h). The probe rows cap at 200 early
                // in the run, so without this the TAIL of a soak is dark.
                // mainwait_age_ms = heartbeat-now minus stamp: large age =
                // stale stamp (thread moved on or died), small age = parked
                // there now. 0 handle = no main park observed yet.
                const uint32_t mwH =
                    g_mainParkHandle.load(std::memory_order_relaxed);
                const uint32_t mwLr =
                    g_mainParkLr.load(std::memory_order_relaxed);
                const uint64_t mwNs =
                    g_mainParkNs.load(std::memory_order_relaxed);
                const uint64_t mwAge =
                    (mwH != 0) ? static_cast<uint64_t>(NowNs() / 1000000) >= mwNs
                                     ? static_cast<uint64_t>(NowNs() / 1000000) - mwNs
                                     : 0u
                               : 0u;
                MCLA_LOG_INFO(
                    "RenderThread: {} #{} frame={} obj={:08X} fb={:08X} "
                    "surf={:08X} mainwait={:08X} mainwaitlr={:08X} "
                    "mainwait_age_ms={}",
                    heartbeat ? "HB-FLICKER" : "PRESENT", n, p.frameNumber,
                    p.obj, p.swapInfo, p.surfaceVA, mwH, mwLr, mwAge);
            }

            // F-610: stamp a guest present for the heartbeat's suppression
            // window. Without this the 30 Hz beat competes with a guest that
            // is already presenting and both are counted as the same signal.
            if (!heartbeat) {
                g_lastGuestPresentNs.store(NowNs(), std::memory_order_relaxed);
            }

            // F-610: the software per-PRESENT pacer (Sleep to kTargetFrameSeconds
            // here) is REMOVED. It was the third of three throttles stacked on
            // one frame: the 33 ms heartbeat thread, this Sleep, and
            // Present(1,0) in the backend (src/d3d12_backend.cpp:1496, :1922).
            // Present(1,0) blocks on the real vsync deadline, so the Sleep
            // could only add up to 33 ms of pure latency per guest frame on top
            // of a wait that already enforces the frame period. The heartbeat
            // cadence (kHeartbeatIntervalMs) is now the only software clock, and
            // the swapchain is the only frame deadline.

            // W5: sample average color for logs. W6: full-viewport blit of
            // the guest framebuffer when swapInfo is a high guest VA.
            // W7: if swapInfo is a swap-table slot (C71D81xx family or
            // samples as near-zero), use the resolved surface VA instead.
            float cr = 0.06f, cg = 0.10f, cb = 0.22f;
            bool blitOk = false;
            // F-762: set when the whole-surface census refused this VA. It is
            // separate from blitOk on purpose: blitOk=false means "no guest
            // pixels reached the buffer", and the block below answers that by
            // showing the measured clear colour. surfaceRefused means "the
            // bytes we read are not a surface", and the honest answer to THAT
            // is to touch nothing at all, so the two must not share a branch.
            bool surfaceRefused = false;
            bool coherent = false;

            // F-610: one-way latch, declared ahead of the blit so the success
            // path below can set it. Once any real guest framebuffer has been
            // blitted, no synthetic fallback may ever paint again.
            static std::atomic<bool> s_guestContentSeen{false};

            // Determine which VA to blit from.
            // Heartbeat (swapInfo=0): don't blit, just clear.
            // Guest present with swap-table swapInfo: use resolved surface.
            // Guest present with real surface swapInfo: use swapInfo directly.
            uint32_t blitVA = 0;
            if (p.swapInfo >= 0x80000000u && p.swapInfo < 0x100000000u) {
                // Heuristic: swap-table slots are in the C71D81xx family
                // (table at C71D8180, slots at +0x40..+0x5C).
                const bool isSwapTable =
                    (p.swapInfo >= 0xC71D8180u && p.swapInfo < 0xC71D81E0u);
                if (isSwapTable) {
                    // Swap-table slot — use resolved surface if available.
                    blitVA = p.surfaceVA;
                } else {
                    // Might be a real surface — try it directly.
                    blitVA = p.swapInfo;
                }
            }
            // Note: swapInfo=0 (heartbeat) leaves blitVA=0 → clear-only.

            if (blitVA != 0) {
                auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
                // Prefer full 1280x720 linear 32bpp; fall back to 640x360 if
                // the larger ReadBytes is not valid (page still uncommitted).
                static std::vector<uint8_t> fbBuf;
                constexpr uint32_t kFullW = 1280, kFullH = 720;
                constexpr uint32_t kHalfW = 640, kHalfH = 360;
                constexpr uint32_t kFullBytes = kFullW * kFullH * 4;
                constexpr uint32_t kHalfBytes = kHalfW * kHalfH * 4;
                if (fbBuf.size() < kFullBytes) fbBuf.resize(kFullBytes);

                uint32_t fbW = 0, fbH = 0;
                if (mem.ReadBytes(blitVA, fbBuf.data(), kFullBytes)) {
                    fbW = kFullW;
                    fbH = kFullH;
                } else if (mem.ReadBytes(blitVA, fbBuf.data(), kHalfBytes)) {
                    fbW = kHalfW;
                    fbH = kHalfH;
                }

                if (fbW != 0) {
                    // =================================================================
                    // F-762: THE GATE. Refusing, by name, a surface whose bytes do
                    // not describe anything the guest drew.
                    //
                    // WHAT WAS HERE AND WHY IT GATED NOTHING. Directly below this
                    // block sat a 16x16 grid sampler (sampleCount = 16*16 = 256
                    // points, sx = x * (fbW / 16)). It read 256 of 921600 pixels
                    // = 0.0278% of the surface, averaged them into cr/cg/cb, and
                    // from that average derived a boolean named nearBlack. Two
                    // things are wrong with that and they are separate defects:
                    //
                    //   (a) IT GATED NOTHING. nearBlack's only consumer was a log
                    //       line. The upload call sat outside any test of it, so
                    //       3,686,400 bytes reached the back buffer on the
                    //       strength of a number that was only ever printed. The
                    //       real gate on this path is a frame-OWNERSHIP test
                    //       further down (does the draw path own the buffer), which
                    //       is a different question and answered "yes, go ahead".
                    //   (b) IT COULD NOT HAVE GATED ANYTHING. A mean of 256 points
                    //       estimates the surface's MODAL value, and the modal
                    //       value of never-written memory is zero, which is also
                    //       the modal value of a legitimately black frame. No
                    //       threshold on a modal estimate separates those two. The
                    //       measured disagreement is in the block comment on
                    //       GuestSurfaceCensus in d3d12_backend.h.
                    //
                    // WHAT REPLACES IT. A whole-surface census (every pixel, no
                    // stride, no sampling) and one placement-invariant statistic
                    // derived from it, because the log records which colours a
                    // surface holds but not which pixel holds which colour, so a
                    // geometric test would be answering a question nobody
                    // measured. rareFraction asks how much of the non-background
                    // mass sits in colours that occur at most 8 times in the
                    // whole surface. A drawn region is one colour repeated
                    // thousands of times and scores 0.000000; allocator debris
                    // scores 0.388073. Both numbers are read off rows in
                    // build/w717.log; the derivation and the measured error rate
                    // are on the struct.
                    //
                    // WHAT A REFUSAL DOES. Nothing. Not a substitute colour, not
                    // a held copy of the last good frame, not a clamp, not the
                    // placeholder constant -- charter F-609 forbids inventing a
                    // pixel and the placeholder is the synthetic image F-758
                    // deleted. surfaceRefused carries that decision past the
                    // fallback block below so the fallback is skipped entirely:
                    // the back buffer keeps the bytes it already holds and the
                    // window keeps what it was already showing, which is the only
                    // honest state when there is no guest content to put there.
                    // =================================================================
                    GuestSurfaceCensus census{};
                    CensusGuestSurface(fbBuf.data(), fbW, fbH, &census);
                    coherent = GuestSurfaceIsCoherent(census);
                    if (coherent) {
                        // Logged on the accepting side too, and deliberately: the
                        // threshold is calibrated on the two drawn surfaces this
                        // log contains and on nothing else, so every acceptance has
                        // to carry the numbers it was accepted on. A threshold
                        // moved on evidence needs the evidence in the log.
                        static std::atomic<uint64_t> coherentCount{0};
                        const uint64_t cn = coherentCount.fetch_add(1) + 1;
                        if (cn <= 8 || (cn % 120) == 0)
                            MCLA_LOG_INFO("GUEST-SURFACE-COHERENT #{} va={:08X} wh={}x{} "
                                          "total={} distinct={} modalCount={} "
                                          "contaminated={} rareCount={} "
                                          "rareFraction={:.6f} rareFractionMax={:.6f} "
                                          "-- ACCEPTED for upload: every pixel was "
                                          "walked (stride 1, no sampling) and this "
                                          "fraction of the non-background mass sits "
                                          "in colours occurring at most {} times in "
                                          "the whole surface. contaminated=0 is the "
                                          "uniform branch, where there is no "
                                          "scattered mass to be wrong about",
                                          cn, blitVA, fbW, fbH, census.total,
                                          census.distinct, census.modalCount,
                                          census.contaminated, census.rareCount,
                                          census.rareFraction,
                                          kGuestCensusRareFractionMax,
                                          kGuestCensusRareCount);
                    } else {
                        surfaceRefused = true;
                        static std::atomic<uint64_t> uncoherentCount{0};
                        const uint64_t rn = uncoherentCount.fetch_add(1) + 1;
                        if (rn <= 8 || (rn % 120) == 0)
                            MCLA_LOG_ERROR(
                                "GUEST-SURFACE-UNCOHERENT-REFUSED #{} va={:08X} wh={}x{} "
                                "total={} distinct={} distinctOverflow={} modalCount={} "
                                "contaminated={} rareCount={} rareFraction={:.6f} "
                                "rareFractionMax={:.6f} rareCountMax={} "
                                "distinctNonModal={} largestNonModal={} "
                                "pxPerNonModalColour={} -- REFUSED, and this is the "
                                "honest answer rather than a fix: {} of {} "
                                "non-background pixels sit in colours occurring at "
                                "most {} times in the whole surface, so this is "
                                "scattered bright debris rather than a region the "
                                "guest drew, and {} of the surface was walked with "
                                "no stride. NOTHING WAS BLITTED AND NOTHING WAS "
                                "SUBSTITUTED: the back buffer keeps the bytes it "
                                "already holds and the window keeps what it was "
                                "already showing. Not a substitute colour, not a "
                                "held copy of the last good frame, not a clamp, and "
                                "not the placeholder constant. A previous sampler "
                                "read {} of {} pixels on this same path and its "
                                "mean could not have separated this surface from a "
                                "black one, because a mean estimates the modal "
                                "value and both surfaces are mostly modal zero. "
                                "distinctOverflow or a zero-pixel surface refuses "
                                "for the same reason: a full histogram cannot prove "
                                "uniformity and an empty walk measured nothing",
                                rn, blitVA, fbW, fbH, census.total, census.distinct,
                                census.distinctOverflow, census.modalCount,
                                census.contaminated, census.rareCount,
                                census.rareFraction, kGuestCensusRareFractionMax,
                                kGuestCensusRareCount, census.distinctNonModal,
                                census.largestNonModal,
                                census.distinctNonModal
                                    ? census.contaminated / census.distinctNonModal
                                    : 0,
                                census.contaminated, census.total,
                                kGuestCensusRareCount, census.total,
                                static_cast<uint64_t>(16u * 16u), census.total);
                    }
                }

                if (fbW != 0) {
                  if (coherent) {
                    uint64_t sumR = 0, sumG = 0, sumB = 0;
                    const uint32_t sampleCount = 16 * 16;
                    for (uint32_t y = 0; y < 16; ++y) {
                        for (uint32_t x = 0; x < 16; ++x) {
                            const uint32_t sx = x * (fbW / 16);
                            const uint32_t sy = y * (fbH / 16);
                            const uint32_t off = (sy * fbW + sx) * 4;
                            // LE 32bpp in guest memory: treat as RGBA bytes.
                            sumR += fbBuf[off + 0];
                            sumG += fbBuf[off + 1];
                            sumB += fbBuf[off + 2];
                        }
                    }
                    cr = static_cast<float>(sumR / sampleCount) / 255.0f;
                    cg = static_cast<float>(sumG / sampleCount) / 255.0f;
                    cb = static_cast<float>(sumB / sampleCount) / 255.0f;
                    // F-610: the near-black clamp that used to live here
                    // (0.02 -> dark blue) is REMOVED. It rewrote the measured
                    // colour, so a genuinely black guest frame and a frame that
                    // never rendered were reported as the same dark blue, in
                    // the log AND in the fallback clear. cr/cg/cb now carry the
                    // sampled value unmodified; near-black is flagged as a
                    // separate signal instead of being repainted.
                    const bool nearBlack = (cr + cg + cb) < 0.02f;
                    if (nearBlack) {
                        static std::atomic<uint32_t> blackCount{0};
                        const uint64_t bn = blackCount.fetch_add(1) + 1;
                        if (bn <= 8 || (bn % 240) == 0)
                            MCLA_LOG_INFO("PRESENT-FB NEAR-BLAME #{} va={:08X} "
                                          "rgb=({:.3f},{:.3f},{:.3f}) — sampled as "
                                          "black, NOT rewritten",
                                          bn, blitVA, cr, cg, cb);
                    }
                    static std::atomic<uint32_t> presentFbCount{0};
                    const uint32_t pfn = presentFbCount.fetch_add(1) + 1;
                    if (pfn <= 16 || (pfn % 60) == 0)
                        MCLA_LOG_INFO("PRESENT-FB sample rgb=({:.2f},{:.2f},{:.2f}) va={:08X} (fb={:08X}) wh={}x{}",
                                      cr, cg, cb, blitVA, p.swapInfo, fbW, fbH);

                    if (!backend_.PresentBgra(fbW, fbH, fbBuf.data())) {
                        static std::atomic<uint32_t> blitFail{0};
                        const uint32_t fn = blitFail.fetch_add(1) + 1;
                        if (fn <= 5 || (fn % 120) == 0)
                            MCLA_LOG_WARN("PRESENT-BLIT fail #{} va={:08X} wh={}x{}",
                                          fn, blitVA, fbW, fbH);
                    } else {
                        blitOk = true;
                        // F-610: latch the gradient fallback off for good. From
                        // here on the fallback path can only clear, never paint
                        // synthetic pixels over a guest frame.
                        s_guestContentSeen.store(true, std::memory_order_relaxed);
                        static std::atomic<uint32_t> blitCount{0};
                        const uint32_t bn = blitCount.fetch_add(1) + 1;
                        if (bn <= 10 || (bn % 60) == 0)
                            MCLA_LOG_INFO("PRESENT-BLIT #{} {}x{} va={:08X} (fb={:08X})",
                                          bn, fbW, fbH, blitVA, p.swapInfo);
                    }
                  }
                } else if (n <= 8 || (n % 240) == 0) {
                    // F-762: this arm is reached ONLY when fbW == 0, i.e. the
                    // guest read itself failed. It used to hang off the same
                    // condition as the upload, and with the census gate in
                    // between that would have made a REFUSED surface report
                    // "read failed" -- a false statement about a read that
                    // succeeded and returned 3,686,400 bytes. The two are now
                    // nested so the arm keeps meaning exactly what it says.
                    MCLA_LOG_WARN("PRESENT-FB read failed va={:08X} (fb={:08X})",
                                  blitVA, p.swapInfo);
                }
            }

            // F-762: surfaceRefused short-circuits this whole block. Everything
            // below answers "no guest pixels arrived", and its answer is to show
            // the measured clear colour, which is a SUBSTITUTION for a surface
            // that was read successfully and found not to be one. For a refusal
            // there is no measured colour to show and nothing to substitute, so
            // the frame is left alone: no upload, no clear, no synthetic image,
            // and the back buffer keeps the bytes it already holds. That is the
            // same contract the ledger-driven refusal downstream already uses,
            // for the same reason.
            if (!blitOk && !surfaceRefused) {
                // F-610: the gradient fallback is GATED on a one-way latch. It
                // used to run on every present with no blitVA (heartbeat) or a
                // failed read, which meant a guest frame that was genuinely
                // black, or a guest frame whose surface read failed, got a
                // synthetic image painted over it — the one case where a
                // diagnostic must not be allowed to speak. Now: once ANY real
                // guest framebuffer has blitted successfully (s_guestContentSeen,
                // set at the PRESENT-BLIT success below and never cleared), the
                // gradient is never painted again; the fallback degrades to a
                // plain clear of the MEASURED colour, so black stays black and a
                // read failure stays a read failure (already logged as
                // PRESENT-FB read failed). SYNTHETIC: REMOVAL TRIGGER: delete
                // this whole block once every present carries a readable
                // surface VA, i.e. no soak ever hits PRESENT-FB read failed and
                // blitVA is never 0 outside the heartbeat.
                if (s_guestContentSeen.load(std::memory_order_relaxed)) {
                    // F-725: THE REDUNDANT FRAME IS GONE, and the measurement is
                    // structural rather than statistical.
                    //
                    // This used to be:
                    //     if (backend_.BeginFrame()) {
                    //         backend_.ClearAndPresent(cr, cg, cb, 1.0f);
                    //         backend_.AbandonFrame("present-fallback-clear");
                    //     }
                    //
                    // ClearAndPresent's FIRST act is MayWriteBackBuffer
                    // (d3d12_backend.cpp:3918), which is where a clear that loses
                    // to the draw path is refused and counted. Its BeginFrame()
                    // is at :3921, i.e. AFTER the refusal test, and it is
                    // guarded by `if (!m_inFrame)`. So once a draw has presented:
                    //     outer BeginFrame()   -> succeeds, sets m_inFrame
                    //     ClearAndPresent()    -> refused at :3918, returns false,
                    //                            having reached neither its own
                    //                            BeginFrame nor any command
                    //     outer AbandonFrame()  -> closes the list, releases the
                    //                            latch, counts an abandon
                    // The frame that was opened had no recorded command in it and
                    // was never executed. It is a pure open/close pair, once per
                    // heartbeat present, forever.
                    //
                    // MEASURED on build/w699.log. FRAME-OWNER REFUSED runs
                    // #1..#4800 at 30.058/s (05:28:28.696 -> 05:31:08.364,
                    // 159.668 s) and D3D12-FRAME-ABANDONED #200..#5000 at
                    // 30.055/s (05:28:34.449 -> 05:31:14.160, 159.711 s). Those
                    // two rates are the same to three decimal places and the two
                    // counters are the same magnitude, so one refused clear
                    // produced exactly one abandon, every time. The `beganFrame`
                    // field proves the accounting closes: 5381-581 = 4800
                    // BeginFrame successes across exactly 5000-200 = 4800
                    // abandons.
                    //
                    // The rate is not a spin and does not have to be treated as
                    // one: it is exactly the heartbeat present cadence
                    // (kHeartbeatIntervalMs = 33 ms -> 30.3 Hz), one iteration
                    // per tick, each completing and returning to the timer. So
                    // this is BENIGN -- it neither livelocks nor starves -- and
                    // it is also 30 BeginFrame + command-allocator-Reset +
                    // command-list-Reset + Close round trips per second that
                    // record nothing. That is the waste being removed.
                    //
                    // WHAT IS NOT CHANGED. MayWriteBackBuffer still refuses the
                    // clear and still counts it, and FRAME-OWNER REFUSED still
                    // prints on exactly the same occasions with exactly the same
                    // numbers. Nothing about the precedence between the draw and
                    // the clear is touched: `writer=clear may not touch the back
                    // buffer; owner=draw` remains the outcome, and a clear can
                    // still never destroy a drawn frame. ClearAndPresent opens
                    // and closes its own frame -- it calls BeginFrame at :3921
                    // when none is open and PresentOwnedFrame releases
                    // m_inFrame -- so it never needed a caller-side pair, and
                    // calling it bare is correct whether the clear is allowed or
                    // refused.
                    backend_.ClearAndPresent(cr, cg, cb, 1.0f);
                    break;
                }
                // F-758: THE SYNTHETIC GRADIENT IS DELETED, not gated.
                //
                // WHAT IT WAS. F-567/F-569 painted a host-generated 1280x720 gradient
                // ("pre-guest-content only. Proves the display pipeline end-to-end while
                // the real rendering path is built") into the swapchain on the !blitOk
                // branch. It is a synthetic image painted over the guest's window, which
                // charter F-609 forbids in the boot path -- and it was the ONLY thing the
                // user could see.
                //
                // MEASURED in build/w713.log, 150 s soak:
                //   PRESENT-BLIT-SYNTH ok 1280x720 (gradient)   1 row
                //   PRESENT-BLIT #                             2 rows
                //   PRESENT-GRADIENT #1..#4, #240              5 rows = 240 paints
                //   FRAME-OWNER #1..#6 owner=blit drawn=0     drawn=0 on EVERY row
                // The guest's draw DID rasterise into the back buffer (DRAW-CP-DRAWN 4, and
                // the census saw it: distinctRgba=2, changedPx=230400,
                // changedBox=x0..639, changedCols=640) and was still never shown. The
                // gradient is what the window displayed.
                //
                // F-610 LATCHED THE WRONG BRANCH. Its s_guestContentSeen guard sits at
                // render_thread.cpp:1671, INSIDE this same `if (!blitOk)` and above this
                // code, and it breaks. So it only suppresses the gradient once a real
                // guest blit has SUCCEEDED -- and on this boot that essentially never
                // happens, so the latch never arms and the gradient runs 240 times. One
                // fallback was gated and the other left running.
                //
                // WHAT REPLACES IT. Nothing synthetic. The fallback presents the MEASURED
                // colour (cr/cg/cb, sampled from guest memory at :1596-1607 and
                // deliberately unclamped since F-610), which is exactly what the sibling
                // branch above already does. Nothing is drawn over the guest's window, and
                // "no surface was presented" is visible in the log instead of being
                // papered over with a picture the guest never drew.
                //
                // REMOVAL TRIGGER: none. This is a synthetic image standing in for no
                // guest state at all; restoring it would reintroduce the F-609
                // violation.
                static std::atomic<uint32_t> noSurface{0};
                const uint32_t ns = noSurface.fetch_add(1) + 1;
                if (backend_.BeginFrame()) {
                    backend_.ClearAndPresent(cr, cg, cb, 1.0f);
                    // Reached whenever the clear itself is refused, so this is a
                    // refusal-shaped path and the frame latch must be released on it
                    // explicitly -- the same reasoning the deleted gradient block gave.
                    backend_.AbandonFrame("present-no-surface");
                }
                if (ns <= 4 || (ns % 240) == 0) {
                    MCLA_LOG_WARN("PRESENT-SURFACE-UNREADABLE #{} -- no guest surface was "
                                   "presented this frame; the window shows the measured "
                                   "clear cr={:.4f} cg={:.4f} cb={:.4f}, NOT guest pixels. "
                                   "The synthetic gradient that used to stand here is "
                                   "deleted (F-758); nothing is drawn over the guest's "
                                   "window any more.",
                                   ns, cr, cg, cb);
                }
            }
            break;
        }
        case RenderCommand::DRAW_CAPTURED: {
            if (!d3d12Initialized_) break;
            const auto& dc = std::get<DrawCapturedCommand>(cmd.data);
            static std::atomic<uint32_t> drawCount{0};
            const uint32_t n = drawCount.fetch_add(1) + 1;
            if (n <= 10 || (n % 500) == 0)
                MCLA_LOG_INFO("RenderThread: DRAW_CAPTURED #{} op=0x{:02X} src={} "
                              "prim={} ib={:08X}+{}B fmt={}B swap={} numIdx={} "
                              "idxOff={:08X} vb={:08X}+{}B stride={} "
                              "vbFmt=vf{}/dxgi{}/{}B descs={}/{} "
                              "psoHash={:016X}",
                              n, dc.opcode, dc.sourceSelect, dc.primitiveTopology,
                              dc.ibBase, dc.ibSize, dc.ibFmt, dc.ibSwap,
                              dc.numIndices, dc.idxOffset, dc.vbBase, dc.vbSize,
                              dc.vbStride, dc.vbFormat.xenos, dc.vbFormat.dxgi,
                              dc.vbFormat.bytes, dc.vbFullCount, dc.vbDescCount,
                              dc.psoHash);

            auto& mem = mcla::kernel::GuestMemoryHeap::Instance();

            // --- F-652: program + raster-state census, before every gate ----
            // Placed with the rest of the census block, above every refusal
            // gate, so the row reports the class of the draw that is ABOUT to be
            // judged and not only of the ones that got far enough to be refused
            // downstream. Bounding the log (this row prints 4 then every 200th)
            // must not bound the census, so every number here is a process-
            // lifetime total that keeps incrementing whether or not this line
            // ever prints again.
            {
                const auto& rs = dc.rasterState;
                const bool vsAddr = (dc.vsProgram.present != 0u &&
                                     dc.vsProgram.embedded == 0u);
                const bool psAddr = (dc.psProgram.present != 0u &&
                                     dc.psProgram.embedded == 0u);
                (vsAddr ? s_cpProgVsAddr : s_cpProgVsAbsent)
                    .fetch_add(1, std::memory_order_relaxed);
                (psAddr ? s_cpProgPsAddr : s_cpProgPsAbsent)
                    .fetch_add(1, std::memory_order_relaxed);
                const bool c0 =
                    (rs.presentMask & (1u << CpSnapshotReg::kCpSnapPaClipCntl)) != 0u;
                const bool c1 = (rs.presentMask &
                                 (1u << CpSnapshotReg::kCpSnapPaSuScModeCntl)) != 0u;
                const bool c2 =
                    (rs.presentMask & (1u << CpSnapshotReg::kCpSnapPaClVteCntl)) != 0u;
                if (c0) s_cpRsCovPaClipCntl.fetch_add(1, std::memory_order_relaxed);
                if (c1) s_cpRsCovPaSuScModeCntl.fetch_add(1, std::memory_order_relaxed);
                if (c2) s_cpRsCovPaClVteCntl.fetch_add(1, std::memory_order_relaxed);
                if (c0 && c1 && c2) s_cpRsAll3.fetch_add(1, std::memory_order_relaxed);
            }

            // F-611: one bounded, fully identified refusal line per reason.
            // Never a synthetic fallback - if a field is missing the draw stops
            // here and says which field, so the next step is obvious and a soak
            // can count the reason (F-609, native-only charter).
            auto refuse = [&](const char *what, std::atomic<uint32_t> &c,
                              const char *detail) {
                const uint32_t k = c.fetch_add(1, std::memory_order_relaxed) + 1;
                if (k <= 8 || (k % 200) == 0)
                    MCLA_LOG_WARN("DRAW-CP-REFUSE #{} what={} draw={} ib={:08X}+{}B "
                                  "numIdx={} vb={:08X}+{}B stride={} {}",
                                  k, what, n, dc.ibBase, dc.ibSize, dc.numIndices,
                                  dc.vbBase, dc.vbSize, dc.vbStride, detail);
            };

            // F-648: the AUTHORITATIVE total row for this gate. Every counter
            // the DRAW_CAPTURED path keeps is printed here, including the ones
            // whose per-reason DRAW-CP-REFUSE line is suppressed.
            //
            // Why this row had to be added rather than reusing refuse(): refuse()
            // prints rows 1..8 and then every 200th, so a reason whose count is
            // 137 leaves 129 unprinted firings and a reason whose count is 0
            // leaves none - the log alone cannot tell "never fired" from "fired
            // an awkward number of times". Bounding a log must not bound a
            // census. The producer solved exactly this with CP-DRAW-CENSUS
            // (src/gpu_cp.cpp, "Bounding the log must not bound the census, so
            // the totals live here and are printed every 200th draw"); this is
            // the consumer half, which never had one.
            //
            // It is placed before every gate so the row reports the class of the
            // draw that is about to be judged, not only of the ones that got
            // far enough to reach a later gate.
            static std::atomic<uint32_t> s_cpCensus{0};
            const uint32_t cc = s_cpCensus.fetch_add(1, std::memory_order_relaxed) + 1u;
            if (cc <= 4u || (cc % 200u) == 0u) {
                // F-652: the PC-DERIVE row is the one that answers "was a
                // pipeline ever REQUESTED, and what happened to the ones that
                // were". It is a separate line, not extra columns on this one,
                // for the same reason F-648 put topologyAssigned next to drawn:
                // a question about a different stage of the chain must not be
                // answered by a number about another one. Every refusal bit has
                // its OWN total (s_deriveRefusedByBit, 32 slots, one per
                // renderer::PipelineRefusal bit), so this row is a histogram of
                // named reasons and never a lumped "refused=N".
                uint32_t ds = s_deriveAttempted.load(std::memory_order_relaxed);
                uint32_t dok = s_deriveOk.load(std::memory_order_relaxed);
                uint32_t drf = s_deriveRefused.load(std::memory_order_relaxed);
                // The aggregate refuseMask over the whole run, OR-ed at the
                // refusal site (lock-free fetch_or), so the row can be formatted
                // through the ONE owner of the name table and a soak reads real
                // names even if it kept only the last 200th copy of this line.
                const uint32_t maskSoFar =
                    s_deriveMaskOr.load(std::memory_order_relaxed);
                char reasons[512] = {};
                mcla::renderer::FormatPipelineRefusal(maskSoFar, reasons,
                                                      sizeof(reasons));
                MCLA_LOG_WARN(
                    "PC-DERIVE #{} attempted={} ok={} refused={} "
                    "refusedMaskSoFar=0x{:08X} reasons={} "
                    "|| byReason(stateNotDerived={} emptyHlsl={} noDevice={} "
                    "noRootSig={} emptyInputLayout={} layoutDeclMismatch={} "
                    "unsupportedPolyMode={} unsupportedTopology={} "
                    "srvOutsideT0T3={} samplerNotS0={} "
                    "unmeasuredDepthRequired={} queueSaturated={} "
                    "no2205={} no2204={} no2206={} viewportExtents={} "
                    "noPolyOffsetFront={} noPolyOffsetBack={} noDepthInfo={}) "
                    "|| noVsProgram={} noPsProgram={} noTranslatedPso={} "
                    "rectList(expanded={} refused={})",
                    cc, ds, dok, drf, maskSoFar, reasons,
                    s_deriveRefusedByBit[0].load(std::memory_order_relaxed),
                    s_deriveRefusedByBit[1].load(std::memory_order_relaxed),
                    s_deriveRefusedByBit[2].load(std::memory_order_relaxed),
                    s_deriveRefusedByBit[3].load(std::memory_order_relaxed),
                    s_deriveRefusedByBit[4].load(std::memory_order_relaxed),
                    s_deriveRefusedByBit[5].load(std::memory_order_relaxed),
                    s_deriveRefusedByBit[6].load(std::memory_order_relaxed),
                    s_deriveRefusedByBit[7].load(std::memory_order_relaxed),
                    s_deriveRefusedByBit[8].load(std::memory_order_relaxed),
                    s_deriveRefusedByBit[9].load(std::memory_order_relaxed),
                    s_deriveRefusedByBit[10].load(std::memory_order_relaxed),
                    s_deriveRefusedByBit[11].load(std::memory_order_relaxed),
                    s_deriveRefusedByBit[12].load(std::memory_order_relaxed),
                    s_deriveRefusedByBit[13].load(std::memory_order_relaxed),
                    s_deriveRefusedByBit[14].load(std::memory_order_relaxed),
                    s_deriveRefusedByBit[15].load(std::memory_order_relaxed),
                    s_deriveRefusedByBit[16].load(std::memory_order_relaxed),
                    s_deriveRefusedByBit[17].load(std::memory_order_relaxed),
                    s_deriveRefusedByBit[18].load(std::memory_order_relaxed),
                    s_deriveNoVsProgram.load(std::memory_order_relaxed),
                    s_deriveNoPsProgram.load(std::memory_order_relaxed),
                    s_deriveNoTranslatedPso.load(std::memory_order_relaxed),
                    s_rectListExpanded.load(std::memory_order_relaxed),
                    s_rectListRefused.load(std::memory_order_relaxed));

                // PrimTypeRefusalCount/Total are the backend's OWN per-prim_type
                // census (d3d12_backend.h:125-126), surfaced here so one line
                // answers "did the rectangle list get refused, and how often".
                MCLA_LOG_WARN(
                    "DRAW-CP-CENSUS #{} consumed={} drawn={} topologyAssigned={} "
                    "|| src-unsupported={} ib-empty={} ib-wrap={} numidx-zero={} "
                    "ib-swap-unhandled={} ib-short={} ib-unreadable={} "
                    "vb-missing={} vb-fmt-unmapped={} vb-fmt-stride={} "
                    "vb-fmt-short={} vb-short={} || prim-rect-list={} "
                    "prim-unmappable={} state-refused={} no-vs-program={} "
                    "no-ps-program={} no-translated-pso={} backendPrimRect={} "
                    "backendPrimTotal={} | vsProgAddr={} psProgAddr={} "
                    "vsProgAbsent={} psProgAbsent={} rsCov2204={} rsCov2205={} "
                    "rsCov2206={} rsAll3={} noColorInfo={} colorFmtUnmapped={}",
                    cc, n - 1u,
                    s_cpDrawn.load(std::memory_order_relaxed),
                    s_cpTopologyAssigned.load(std::memory_order_relaxed),
                    s_cpRefuseSrc.load(std::memory_order_relaxed),
                    s_cpRefuseIbEmpty.load(std::memory_order_relaxed),
                    s_cpRefuseIbWrap.load(std::memory_order_relaxed),
                    s_cpRefuseNumIdx.load(std::memory_order_relaxed),
                    s_cpRefuseSwap.load(std::memory_order_relaxed),
                    s_cpRefuseIbShort.load(std::memory_order_relaxed),
                    s_cpRefuseIbUnreadable.load(std::memory_order_relaxed),
                    s_cpRefuseVbMissing.load(std::memory_order_relaxed),
                    s_cpRefuseVbFmtUnmapped.load(std::memory_order_relaxed),
                    s_cpRefuseVbFmtStride.load(std::memory_order_relaxed),
                    s_cpRefuseVbFmtShort.load(std::memory_order_relaxed),
                    s_cpRefuseVbShortRefused.load(std::memory_order_relaxed),
                    s_cpRefusePrimRect.load(std::memory_order_relaxed),
                    s_cpRefusePrimOther.load(std::memory_order_relaxed),
                    s_cpRefuseStateRefused.load(std::memory_order_relaxed),
                    s_cpRefuseNoVsProgram.load(std::memory_order_relaxed),
                    s_cpRefuseNoPsProgram.load(std::memory_order_relaxed),
                    s_cpRefuseNoPso.load(std::memory_order_relaxed),
                    D3D12Backend::PrimTypeRefusalCount(0x08u),
                    D3D12Backend::PrimTypeRefusalTotal(),
                    // F-652: the program census, counted from what the draw
                    // ACTUALLY carried on the command - not re-derived from a
                    // register file that may have moved on - and the raster-state
                    // COVERAGE of what was consumed, per register and for the
                    // all-three case that gates `haveRegisters`.
                    s_cpProgVsAddr.load(std::memory_order_relaxed),
                    s_cpProgPsAddr.load(std::memory_order_relaxed),
                    s_cpProgVsAbsent.load(std::memory_order_relaxed),
                    s_cpProgPsAbsent.load(std::memory_order_relaxed),
                    s_cpRsCovPaClipCntl.load(std::memory_order_relaxed),
                    s_cpRsCovPaSuScModeCntl.load(std::memory_order_relaxed),
                    s_cpRsCovPaClVteCntl.load(std::memory_order_relaxed),
                    s_cpRsAll3.load(std::memory_order_relaxed),
                    // F-723: appended at the very END of the row. Two separate
                    // totals because "RB_COLOR_INFO was never presented" and
                    // "its color_format has no DXGI equivalent" are different
                    // faults with different fixes, and one lumped number would
                    // make either fix look like it worked for the other.
                    s_cpRefuseNoColorInfo.load(std::memory_order_relaxed),
                    s_cpRefuseColorFmtUnmapped.load(std::memory_order_relaxed));
            }

            // --- index gate, in the order the data is needed ---------------
            // F-633: source_select=2 (kAutoIndex) is a REAL, NON-INDEXED draw,
            // not a malformed one. Upstream sets index_buffer_info.guest_base=0
            // and .length=0 (command_processor.cc:1357-1361), leaves
            // is_indexed=false (:1308) and calls IssueDraw(prim_type,
            // num_indices, /*index_buffer=*/nullptr, ...) (:1380-1384): the
            // indices are implicit 0..num_indices-1. The old gate here refused
            // every such draw with src-not-dma, which is the same misreading one
            // hop downstream of the CP bridge and would have kept
            // DRAW-CP-REFUSE at 100% after that bridge started enqueueing.
            // So the index gate below is conditioned on `indexed`, and
            // num_indices becomes the VERTEX count for the non-indexed class -
            // which is exactly what IssueDraw receives upstream.
            const bool indexed = (dc.sourceSelect == 0u);  // SourceSelect::kDMA
            if (!indexed && dc.sourceSelect != 2u) {
                refuse("src-unsupported", s_cpRefuseSrc,
                       "- source_select is kImmediate (1) or the invalid class "
                         "(3). Upstream issues no draw for either: it logs and "
                         "sets draw_succeeded=0 (command_processor.cc:1348-1356), "
                         "or takes the default arm (:1362-1366). NOT treated as "
                         "kAutoIndex, because upstream does not either.");
                break;
            }
            if (indexed && dc.ibSize == 0u) {
                refuse("ib-empty", s_cpRefuseIbEmpty,
                       "- kDMA draw with VGT_DMA_SIZE.num_words == 0: no index "
                         "elements. A kAutoIndex draw has ibSize == 0 by "
                         "construction and is NOT this case.");
                break;
            }
            if (indexed &&
                static_cast<uint64_t>(dc.ibBase) + static_cast<uint64_t>(dc.ibSize) >
                    0x100000000ull) {
                refuse("ib-wrap", s_cpRefuseIbWrap,
                       "- index range leaves the 4 GiB guest window; NOT read.");
                break;
            }
            // num_indices == 0 is a draw of nothing for BOTH classes: indexed, it
            // is an empty index stream; non-indexed, an empty vertex stream.
            if (dc.numIndices == 0u) {
                refuse("numidx-zero", s_cpRefuseNumIdx,
                       "- VGT_DRAW_INITIATOR.num_indices == 0: a draw of nothing.");
                break;
            }
            // F-633: everything from here to the transcode is about the INDEX
            // buffer, so it is kDMA-only. A non-indexed draw has no index bytes
            // to bound, swap-transcode or read, and fabricating an implicit
            // 0..n-1 index buffer here would be exactly the substitution
            // F-609 forbids - the backend already has a non-indexed path
            // (DrawInstanced, d3d12_backend.cpp:2701) and it is used below.
            static IndexTranscode tc;
            if (indexed) {
                uint32_t ibStrideBytes = 0;
                bool wideIndex = false;
                if (!XenosIndexElement(dc.ibSwap, ibStrideBytes, wideIndex)) {
                    refuse("ib-swap-unhandled", s_cpRefuseSwap,
                           "- VGT_DMA_SIZE.swap_mode has no D3D12 index element; "
                             "refusing rather than guessing a byte order.");
                    break;
                }
                // The draw claims more indices than the buffer holds. Upstream
                // would read past the end; here it is a refusal.
                const uint64_t want = static_cast<uint64_t>(dc.numIndices) *
                                      static_cast<uint64_t>(ibStrideBytes);
                if (want > static_cast<uint64_t>(dc.ibSize)) {
                    refuse("ib-short", s_cpRefuseIbShort,
                           wideIndex
                               ? "- num_indices * 4B element stride exceeds the "
                                 "resolved index buffer; the draw would read past its "
                                 "own end."
                               : "- num_indices * element stride exceeds the resolved "
                                 "index buffer; the draw would read past its own end.");
                    break;
                }
                if (!mem.IsValid(dc.ibBase, dc.ibSize)) {
                    refuse("ib-unreadable", s_cpRefuseIbUnreadable,
                           "- resolved index buffer is outside the guest window.");
                    break;
                }

                // --- FETCH WHAT IS AVAILABLE --------------------------------
                // One static buffer, grown only when a bigger capture arrives (the
                // F-610 discipline, same as the vertex buffer further down): the
                // index bytes come out of guest memory through the checked
                // ReadBytes helper and are transcoded by hand into the element
                // D3D12 accepts. The transcode is not a convenience - the
                // hardware's swap_mode has no D3D12 equivalent, so a host-side
                // reorder is required to be correct, and a k16in32 stream must be
                // narrowed before an IBV can describe it at all.
                static std::vector<uint8_t> ibRaw;
                if (ibRaw.size() < dc.ibSize) ibRaw.resize(dc.ibSize);
                if (!mem.ReadBytes(dc.ibBase, ibRaw.data(), dc.ibSize)) {
                    refuse("ib-read-failed", s_cpRefuseIbUnreadable,
                           "- ReadBytes on the validated index buffer failed.");
                    break;
                }
                if (!TranscodeXenosIndices(ibRaw.data(), dc.numIndices, dc.ibSwap, tc)) {
                    refuse("ib-transcode-failed", s_cpRefuseSwap,
                           "- index transcode refused the swap mode after the gate "
                             "accepted it (unreachable; kept so a future swap mode "
                             "cannot slip through silently).");
                    break;
                }
                // maxIndex is the real vertex count this draw needs, measured
                // from guest bytes. It is what sizes the missing vertex fetch, so
                // it is reported on its own line and is deliberately NOT gated on
                // the vertex decision below.
                {
                    const uint32_t m =
                        s_cpIndexMeasured.fetch_add(1, std::memory_order_relaxed) + 1;
                    if (m <= 8 || (m % 200) == 0)
                        MCLA_LOG_INFO("DRAW-CP-INDEX #{} va={:08X} elem={}B swap={} "
                                      "count={} maxIndex={} ({} bit) - vertex bytes "
                                      "needed >= {} * stride",
                                      m, dc.ibBase, ibStrideBytes, dc.ibSwap, tc.count,
                                      tc.maxIndex, tc.isWide ? 32 : 16, tc.maxIndex);
                }
            }

            // --- vertex gate: the part that is genuinely missing ------------
            if (dc.vbBase == 0u || dc.vbSize == 0u || dc.vbStride == 0u) {
                refuse("vb-missing", s_cpRefuseVbMissing,
                       indexed
                           ? "- index data is REAL and measured (see "
                             "DRAW-CP-INDEX), but no vertex buffer descriptor "
                             "exists: on the Xenos the VB addresses are computed "
                             "by executing the fetch-shader program, and "
                             "src/gpu_cp.cpp's CpExecImLoad reads the PM4_IM_LOAD "
                             "payloads and discards them, so there is no program "
                             "and therefore no address. NOT substituted with a "
                             "synthetic shape."
                           : "- a NON-INDEXED draw needs no index buffer, so this "
                             "is the whole geometry: the fetch/VB descriptor the CP "
                             "bridge decoded is absent or incomplete (vbBase/vbSize/"
                             "vbStride), so there is no vertex stream to draw. NOT "
                             "substituted with a synthetic shape.");
                break;
            }

            // --- both halves real -> issue the draw -------------------------
// --- both halves real -> issue the draw -------------------------
            // F-747: THIS COPY IS A RAW BYTE COPY AND THE VERTEX STREAM IS
            // BIG-ENDIAN, so every float the backend reads out of it is
            // byte-reversed. F-751 IS WHAT CLOSED THAT: the selector now crosses
            // the queue boundary (CpVertexElement::endianness, render_queue.h),
            // and the transform is applied to `vb` immediately below - in the
            // same place the raw copy is made, and before `desc.vertexBytes`
            // ever points at it.
            //
            // MEASURED. build/w708.log, draw #1: the guest's own fetch constant
            // for this stream carries endianness = 2, xenos::Endian::k8in32
            // (xenos.h:196, GpuSwap :1061-1064 = a full 32-bit reversal), and
            // that guest memory image is big-endian - `CP-FETCHVB #1 reg=4800
            // val=17C8A2BF` is the architected address 0x17C8A2BC OR two endian
            // bits, read big-endian-correct by src/gpu_cp.cpp:1211-1217; a
            // host-order read of the same four bytes would print BFA2C817.
            // MEASURED, TWICE OVER: all 8 CP-FETCHVB-DECODE rows and all 6
            // CP-FETCHVB-DESC rows in that log carry endian=2, so this is what
            // EVERY fetch constant in this boot says, not one draw's oddity.
            //
            // THE TRANSFORM IS THE REFERENCE'S, NOT AN INVENTED ONE. The
            // reference does not read the stream through a byte-order-aware
            // accessor: it takes a RAW host-order dword load
            // (.research/xenia/src/xenia/gpu/shader_interpreter.cc:1031-1032)
            // and then applies `xenos::GpuSwap(dword, fetch_constant.endian)` to
            // EVERY dword it reads (:1048-1049). draw_util.cc:839-849 is the
            // same shape through the float overload (xenos.h:1071-1079). The
            // four selectors are transcribed one for one from xenos.h:1052-1069
            // into mcla::gpu::CpGpuSwap32 (render_queue.h) and are NOT guessed:
            // the harness in %TEMP%\opencode\bytemark compiles the reference's
            // own definition next to the shipped one and finds them identical on
            // all four selectors over 262,144 values.
            //
            // (PROVENANCE: .research/xenia has no .git, is gitignored at
            // .gitignore:14, and has 0 files in HEAD - an untracked snapshot with
            // NO recorded provenance. Its xenos.h was read at SHA-256
            // EF00180E1B69A6233AD07161BDD42A9A623CB2EE88C732CE7FE69C611DFD6389.)
            //
            // WHAT IT BUYS, ON THE REAL BYTES. Vertex 0 lane 0 is four guest
            // bytes BF 00 00 00. Read host-order that is 0x000000BF = 2.68e-43, a
            // denormal no guest writes as a position; read as the guest wrote it
            // it is 0xBF000000 = -0.5. The probe in the backend prints that row
            // verbatim, so the next soak answers it directly.
            static std::vector<uint8_t> vb;
            if (vb.size() < dc.vbSize) vb.resize(dc.vbSize);
            if (!mem.ReadBytes(dc.vbBase, vb.data(), dc.vbSize)) {
                refuse("vb-unreadable", s_cpRefuseVbMissing,
                       "- vertex buffer range validated but ReadBytes failed.");
                break;
            }

            // F-751: read the selector, then APPLY IT. Everything above is the
            // raw copy; this is the transform, and it precedes every use of `vb`
            // (the first is `desc.vertexBytes = vb.data()` far below).
            //
            // ONE SELECTOR PER ELEMENT, AND THEY MUST AGREE. The selector is a
            // property of the fetch CONSTANT SLOT (xenos.h:1122), and two vfetch
            // instructions can in principle bind two different slots - which is
            // why the field is per-element rather than on the command. But the
            // command carries ONE (vbBase, vbSize) pair, so there is only ONE
            // copy of the stream and therefore only ONE transform that can be
            // applied to it. A disagreement has no correct single answer, so it
            // is refused rather than resolved in favour of element 0.
            uint32_t vbEndianness = mcla::native::kCpVertexEndianNone;
            bool vbEndianSeen = false;
            bool vbEndianSplit = false;
            for (uint32_t fe = 0u; fe < dc.vbElementCount; ++fe) {
                if (fe >= mcla::native::kCpVertexElementMax) {
                    break;  // the vb-elem-out-of-range refusal below judges it
                }
                const uint32_t e = dc.vbElements[fe].endianness;
                if (!vbEndianSeen) {
                    vbEndianness = e;
                    vbEndianSeen = true;
                } else if (e != vbEndianness) {
                    vbEndianSplit = true;
                    break;
                }
            }
            if (!vbEndianSeen) {
                // Unreachable on the measured path: a command only exists if the
                // producer decoded at least one vfetch (it refuses a
                // zero-descriptor fetch block by name), and build/w708.log shows
                // nDesc=2 and nDesc=1 on its two surviving draws. Named anyway,
                // on the F-720 precedent, because "no element" and "the guest
                // said kNone" both read as 0 here and only one of them means the
                // stream is already in host order.
                refuse("vb-endian-absent", s_cpRefuseVbEndianAbsent,
                       "- the command carries no vertex element, so it carries "
                         "no fetch constant and therefore no byte-order selector. "
                         "NOT assumed to be kNone: a missing selector is not the "
                         "same fact as a guest that stated one.");
                break;
            }
            if (vbEndianSplit) {
                refuse("vb-endian-split", s_cpRefuseVbEndianSplit,
                       "- two elements of this draw name different byte orders, "
                         "and the command carries one vertex range, so only one "
                         "transform can be applied to it. NOT resolved in favour "
                         "of element 0; the per-element values are on the "
                         "producer's descriptor row.");
                break;
            }
            if (!mcla::native::CpVertexEndianIsArchitected(vbEndianness)) {
                // 2 bits in the guest (xenos.h:1122), so this is not a guest
                // fact. Refused by name rather than masked into 0..3, because
                // masking would pick a byte order nobody stated.
                refuse("vb-endian-unknown", s_cpRefuseVbEndianUnknown,
                       "- the carried byte-order selector is outside the four "
                         "architected values, and the guest field is 2 bits wide, "
                         "so this is a producer value, not a guest one. NOT "
                         "masked, rounded or clamped into 0..3.");
                break;
            }
            // THE BOUNDS CHECK IS BEFORE THE SWAP, and it is the reference's
            // shape. The reference bounds `address + size`
            // (shader_interpreter.cc:1033) and tests each dword against that
            // window (:1042-1043) BEFORE loading it; its load at :1048 - the one
            // GpuSwap is applied to - is inside the test, so a reversed read can
            // never reach a byte the reference would not have read. Here `vb` is
            // exactly `dc.vbSize` bytes (resized on the line above, filled by one
            // bounded ReadBytes), so the bound is `i < vbSize / 4`: whole dwords
            // only. A trailing partial dword is left exactly as it was read
            // rather than swapped from bytes that are not there.
            // MEASURED: the real stream is sizeBytes=84 = 3 vertices x
            // strideBytes=28, and 84 / 4 == 21 with no remainder, so the tail is
            // empty on the path that matters; the producer builds sizeBytes as
            // `sizeWords << 2`, so it always is.
            if (vbEndianness != mcla::native::kCpVertexEndianNone) {
                const uint32_t dwords = dc.vbSize / 4u;
                for (uint32_t i = 0u; i < dwords; ++i) {
                    uint8_t *p = vb.data() + static_cast<size_t>(i) * 4u;
                    uint32_t raw = 0;
                    std::memcpy(&raw, p, 4);
                    raw = mcla::gpu::CpGpuSwap32(raw, vbEndianness);
                    std::memcpy(p, &raw, 4);
                }
            }            // F-633: the VERTEX count. For kAutoIndex it is
            // VGT_DRAW_INITIATOR.num_indices, which is what IssueDraw is handed
            // upstream (:1381) - deriving it from vbSize/vbStride instead would
            // invent a count the guest never stated, and the two are not required
            // to agree. Same refusal discipline as the indexed `ib-short` row: if
            // the stated count does not fit the descriptor's own length, the draw
            // would read past its end, so it refuses.
            uint32_t vertexCount = dc.vbSize / dc.vbStride;
            if (!indexed) {
                const uint64_t vbWant =
                    static_cast<uint64_t>(dc.numIndices) *
                    static_cast<uint64_t>(dc.vbStride);
                if (vbWant > static_cast<uint64_t>(dc.vbSize)) {
                    // The numbers are already on this refusal's own line
                    // (numIdx=, vb=+B, stride=), so the detail is a literal -
                    // the refuse() lambda takes a const char*, and building a
                    // std::string here would need a <string> this file does not
                    // include.
                    refuse("vb-short", s_cpRefuseVbMissing,
                           "- non-indexed draw: num_indices * vbStride exceeds the "
                             "resolved vertex buffer, so the draw would read past "
                             "its own end. See numIdx/vb/stride on this line.");
                    s_cpRefuseVbShortRefused.fetch_add(1, std::memory_order_relaxed);
                    break;
                }
                vertexCount = dc.numIndices;
            }

            // F-648: the FORMAT gate, which did not exist because the format was
            // never carried (F-632 printed it and dropped it). Three checks, in
            // order, each with its own counter.
            //
            // (1) unmapped. known == 0 means the 6-bit data_format() is not one of
            //     the named xenos::VertexFormats, and bytes == 0 means no tight
            //     size can be stated. There is no defensible substitute and no
            //     default that would be honest, so the draw stops here. This is
            //     what makes dxgi == 0 (DXGI_FORMAT_UNKNOWN) a refusal rather
            //     than a silent layout.
            //
            //     THE SAME TEST, ON EVERY ELEMENT (F-720). `dc.vbFormat` is
            //     element 0's summary (render_queue.h:441, 453) and is all this
            //     gate ever read, so before F-720 an element 1..n with
            //     known == 0 was not refused here -- it was not read here at all.
            //     That is a real hole, not a hypothetical one: the walk below is
            //     over dc.vbElements[0..vbElementCount), and the measured stream
            //     carries 2 elements (build/w686.log DRAW-CP-LAYOUT #1,
            //     nDesc=2), so the gap is live on the first draw of every boot.
            //     The fix is unambiguous because the rule is already written
            //     three lines above for element 0 and needs no new judgement:
            //     apply it to every element, and name the offending ordinal so
            //     the census says WHICH fetch was unmapped rather than only that
            //     one was.
            bool vbFmtUnmapped = false;
            bool vbElemOutOfRange = false;
            for (uint32_t fe = 0u; fe < dc.vbElementCount; ++fe) {
                if (fe >= mcla::native::kCpVertexElementMax) {
                    // Unreachable: the producer fills at most kCpVertexElementMax
                    // (gpu_cp.cpp:3872-3874). A count that exceeded its own bound
                    // would mean the two disagree, and walking it is out of
                    // bounds, so the draw is refused by name instead.
                    vbElemOutOfRange = true;
                    break;
                }
                if (dc.vbElements[fe].fmt.known == 0u ||
                    dc.vbElements[fe].fmt.bytes == 0u) {
                    vbFmtUnmapped = true;
                    break;
                }
            }
            if (vbElemOutOfRange) {
                refuse("vb-elem-out-of-range", s_cpRefuseVbElemOutOfRange,
                       "- vbElementCount exceeds kCpVertexElementMax, so the "
                         "captured element table and the array holding it "
                         "disagree. NOT walked; NOT drawn.");
                break;
            }
            if (vbFmtUnmapped) {
                refuse("vb-fmt-unmapped", s_cpRefuseVbFmtUnmapped,
                       "- the vfetch's 6-bit data_format() is not one of the "
                         "named xenos::VertexFormats, so it has no byte size "
                         "and no DXGI equivalent. NOT defaulted to any format. "
                         "(element ordinal and format id are on "
                         "CP-FETCHVB-DESC / DRAW-CP-LAYOUT.)");
                break;
            }
            // Element 0 is additionally summarised at the top of the command
            // (dc.vbFormat), so that summary is checked too, for the case where
            // the walk above found nothing to check. vbElementCount == 0 is
            // possible and is NOT refused here on its own: a command with no
            // captured element still has to be accounted for below, and the
            // layout completeness check is where a count of 0 is judged. What is
            // refused is an element-0 summary that is ITSELF unmapped.
            if (dc.vbElementCount == 0u &&
                (dc.vbFormat.known == 0u || dc.vbFormat.bytes == 0u)) {
                refuse("vb-fmt-unmapped", s_cpRefuseVbFmtUnmapped,
                       "- the vfetch's 6-bit data_format() is not one of the named "
                         "xenos::VertexFormats, so it has no byte size and no DXGI "
                         "equivalent. NOT defaulted to any format.");
                break;
            }
            // (2) the mutual-consistency check. A stream whose per-vertex advance
            //     is smaller than the element it fetches is not a stream: the
            //     fetch would not fit inside one vertex's stride. `bytes` is the
            //     TIGHT size and the stride is the ADVANCE, so the legal
            //     direction is stride >= bytes - stride > bytes is ordinary
            //     (padding, or attributes fetched by other vfetch instructions).
            //     This is the check that makes "a format and a stride that cannot
            //     both be true" unshippable.
            if (dc.vbStride < dc.vbFormat.bytes) {
                refuse("vb-fmt-stride", s_cpRefuseVbFmtStride,
                       "- vbStride is smaller than the decoded format's own size, "
                         "so one vertex cannot hold one element. NOT drawn; the "
                         "decode is wrong, not the draw.");
                break;
            }
            // (3) the format-size bound, alongside the stride bound above. With
            //     (2) holding this is implied (numIdx*stride >= numIdx*bytes),
            //     so it cannot fire where `vb-short` did not - it is checked
            //     separately so the CENSUS names the format when a length is
            //     wrong, rather than leaving the reader to infer it.
            if (!indexed &&
                static_cast<uint64_t>(dc.numIndices) *
                        static_cast<uint64_t>(dc.vbFormat.bytes) >
                    static_cast<uint64_t>(dc.vbSize)) {
                refuse("vb-fmt-short", s_cpRefuseVbFmtShort,
                       "- non-indexed draw: num_indices * the decoded format's size "
                         "exceeds the resolved vertex buffer. See numIdx/vb on this "
                         "line and stride/fmtB on CP-DRAW-BRIDGE.");
                break;
            }

            D3D12Backend::DynamicMeshDesc desc = {};
            desc.vertexBytes = vb.data();
            desc.vertexBytesSize = dc.vbSize;
            desc.vertexStride = dc.vbStride;
            desc.vertexCount = vertexCount;
            // F-633: the index half exists only for kDMA. For kAutoIndex these
            // stay at their zero-initialised values and the backend takes its
            // non-indexed branch, DrawInstanced(desc.vertexCount, 1, 0, 0)
            // (d3d12_backend.cpp:2701). No implicit 0..n-1 index buffer is
            // manufactured: upstream passes index_buffer=nullptr for this class.
            desc.indexed = indexed;
            if (indexed) {
                desc.indexBytes = tc.isWide ? static_cast<const void*>(tc.wide.data())
                                            : static_cast<const void*>(tc.narrow.data());
                desc.indexBytesSize = tc.count * (tc.isWide ? 4u : 2u);
                desc.indexFormat = tc.isWide ? DXGI_FORMAT_R32_UINT : DXGI_FORMAT_R16_UINT;
                // F-611: num_indices from VGT_DRAW_INITIATOR, NOT ibSize/elemSize.
                // The old handler derived it from the buffer length, which
                // over-drew every real index buffer by its unused tail.
                desc.indexCount = tc.count;
            }
            // F-647: hand the backend the guest's real constant bank. A refusal
            // here is NOT fatal to the draw: the descriptor keeps its
            // zero-initialised nullptr/0 and the backend reports `src=ZEROS` on
            // its own CONST-BANK row, which is the honest state. The draw still
            // issues, because refusing the whole draw over a constant bank would
            // hide the pixels the index buffer already proved are real.
            (void)FillGuestConstantBank(desc);

            // --- step 4: the vertex INPUT LAYOUT, on the LIVE path ------------
            //
            // WHAT THIS IS. The DRAW_INDEXED case above runs a complete,
            // fully-built translator sequence (ReadShaderContainer ->
            // TranslateShader -> ParseShaderProgram ->
            // BuildInputLayoutFromGrcFvf -> ComputePipelineKey ->
            // cache.GetOrCompile, :767-892) and it has never executed once: in
            // build/w682.log (9,724,301 B) the literal "RenderThread:
            // DRAW_INDEXED" counts 0, and so do "PSO HIT", "PSO MISS" and
            // "shader container read failed". The LIVE case is DRAW_CAPTURED
            // (:1166), and on it the only input-layout builder in the tree -
            // D3D12Backend::BuildInputLayoutFromGrcFvf (d3d12_backend.h:366),
            // whose only caller in the whole tree is :804, inside that dead
            // path - was never called either, so its two markers
            // ("BuildInputLayoutFromGrcFvf refused #{}" /
            // "BuildInputLayoutFromGrcFvf: {} elements from mask=",
            // d3d12_backend.cpp:4005/4012) count 0 in the same log.
            //
            // WHAT IS ACTUALLY AVAILABLE TO BUILD ONE. Measured, not assumed:
            // the authoritative builder takes a mcla::native::GrcFvfDesc - a
            // RAGE grcFvf declaration (trace_types.h:36-63: fvfMask, fvfSize,
            // flags, dynamicOrder, channelCount, 16 x 4-bit "types"), which
            // mcla::native::DecodeGrcFvf turns into lanes and
            // renderer::BuildGrcFvfInputLayout turns into
            // D3D12_INPUT_ELEMENT_DESC with ascending byteOffset
            // (pipeline_cache.cpp:1242-1280). THE ONLY PRODUCER OF A grcFvf
            // ANYWHERE IN THIS TREE is capture_hooks.cpp:538-591, and it fills
            // a native::DrawPacket's grcFvf/hasGrcFvf, never a
            // DrawCapturedCommand. A grep for fvfMask/fvfTypes/fvfChannelCount
            // across src/ returns exactly that one producer plus the consumers,
            // so the declaration is not missing a decode on this path - it does
            // not exist here, and nothing in this file can conjure it.
            //
            // WHY IT IS NOT SYNTHESISED FROM dc.vbFormat. The command DOES
            // carry one fully-specified vertex element (render_queue.h:131-136,
            // F-648: xenos/dxgi/bytes/known; measured in w682.log as
            // "vf=57 dxgi=6 fmtB=12 stride=28 nDesc=2 nFull=1" on four draws
            // and "vf=37 dxgi=16 fmtB=8 stride=8 nDesc=1 nFull=1" on two).
            // That is a STREAM element, not a LAYOUT element: a
            // D3D12_INPUT_ELEMENT_DESC additionally needs an AlignedByteOffset
            // and a SemanticName, and BOTH ARE ABSENT HERE:
            //   * the byte offset is decoded by the producer - it is on the
            //     bridge line as "vbOff=" and it is d0.offsetBytes (gpu_cp.cpp
            //     :1001, printed at :3661, measured 0 on all six) - but
            //     DrawCapturedCommand has no field for it (render_queue.h:
            //     232-288 carries vbBase/vbSize/vbStride/vbFormat/vbDescCount/
            //     vbFullCount and no offset), so a literal 0 here would be a
            //     zero standing in for a fact, which is the exact defect F-648
            //     documents for dxgi == 0 and refuses rather than defaults.
            //   * the SEMANTIC does not exist anywhere on this path and cannot
            //     be derived from what is carried. It is not a property of the
            //     format: the grcFvf lane number IS the semantic
            //     (grc_fvf_decode.cpp:49-63 - lane 0 = POSITION, 6-13 =
            //     TexCoord0-7), and gpu_cp.cpp does not decode the instruction's
            //     dst_reg at all. CpVertexFetchInstr (gpu_cp.cpp:981-993)
            //     carries execBlock/execIndex/slotIndex/opcode/formatXenos/
            //     strideDwords/offsetDwords/destSwizzle/isMiniFetch/
            //     isPredicated/conditional and no destination register, and
            //     gpu_cp.cpp:1352 states the omission as deliberate ("the
            //     vfetch's own dst_reg/dest() and the per-component
            //     num_format_all/signed_rf_mode_all decodes are not folded
            //     into the descriptor - this describes the STREAM, and the
            //     attribute-level decode is the renderer's job").
            //     native::VertexFormatDesc (renderer/vertex_decode.h:36-53),
            //     the module that comment names, carries no semantic either.
            //     The one source of a semantic in this tree is
            //     ReferencedVertexInputs(vsProg) (:813, dead path) - i.e. the
            //     guest's own vertex shader - which is the step-5 chain.
            // So a layout built here would have to invent a lane number AND a
            // 4-bit grcFvf type code from a 6-bit xenos::VertexFormat, and
            // those are two different enumerations from two different APIs
            // (xenos.h:602-619 vs grc_fvf_decode.h:44-57). They agree in size
            // for the measured formats - dxgi 6 is 12 B, dxgi 2 is 16 B, dxgi 16
            // is 8 B - and that agreement is a COINCIDENCE of two encodings,
            // not a documented correspondence: nothing in this repo states it,
            // so acting on it is inference where the charter demands a
            // measurement (F-609, Golden Rule 5). It would also be a
            // plausible-but-wrong vertex, the failure mode this gate exists to
            // stop.
            //
            // SO: the layout is attempted, the absence is REFUSED BY NAME, and
            // the refusal is countable. inputLayout and inputDeclHash are
            // declared HERE, in the same scope as desc and the F-652
            // derivation below, so the step-5 consumer that replaces
            // no-translated-pso reads them with no restructuring of this case.
            // The draw's fate is UNCHANGED: this adds no refuse() call and bumps
            // no existing counter, so DRAW-CP-REFUSE stays at its measured 12
            // and DRAW-CP-DRAWN stays 0.
            std::vector<D3D12_INPUT_ELEMENT_DESC> inputLayout;
            // The SAME layout in the numbering TranslateShaderPinned pins against
            // (shader_translator.h:72-75: usage/usageIndex are the DeclUsage
            // numbering VertexUsageSemanticName and grc_fvf_decode's lane table
            // share, so a semantic computed here and a lane decoded there name the
            // same thing). It is carried beside the D3D12 array rather than
            // recovered from it, because SemanticName is a STRING in the D3D12
            // form and re-deriving the number from it would be a guess.
            std::vector<mcla::renderer::VertexInputSemantic> pinnedLayout;
            uint64_t inputDeclHash = 0;
            const char *layoutRefusal = "none";

            // F-716: the pipeline state this chain produces, declared HERE so the
            // F-652 derivation below (and the topology gate and the draw after it)
            // read it with no restructuring. `pipeStop` is the ONE word that says
            // how far this draw got; "none" means it may draw.
            Microsoft::WRL::ComPtr<ID3D12PipelineState> pipePso;
            bool pipeHasGeomStage = false;   // CARRIED, never queried (pipeline_cache.h)
            const char *pipeStop = "none";
            uint32_t pipeVsCodeBytes = 0, pipePsCodeBytes = 0;
            uint32_t pipeVsElements = 0;     // the VS's OWN vertex-element table size
            uint32_t pipeVsInstructions = 0, pipeVsInterpolants = 0;
            uint64_t pipeVsHash = 0, pipePsHash = 0;
            const char *pipeVsSrc = "absent", *pipePsSrc = "absent";
            std::string pipeVsHlsl, pipePsHlsl;
            std::string pipeTranslateError;
            // WHICH STAGE the refusal string below came from. Set immediately
            // before each TranslateShaderPinned call, so a non-empty
            // pipeTranslateError is attributed to the stage that produced it
            // rather than to "something". "none" until the first attempt.
            const char *pipeTrStage = "none";
            // 2026-10-02: the GUEST's own render-target format, hoisted out of
            // the derivation scope (where `psi` is local, render_thread.cpp
            // :2884) so the draw site can report it. These two are the missing
            // half of the only comparison that decides whether the draw can
            // rasterize at all: the PSO's RTVFormats[0] and
            // NumRenderTargets are computed from this value
            // (renderer/pipeline_cache.cpp:1921-1945), while the render target
            // the draw path actually binds is the swapchain back buffer,
            // DXGI_FORMAT_R8G8B8A8_UNORM (src/d3d12_backend.cpp:711, :763).
            // MapXenosColorFormatToDxgi (:456-501) returns R8G8B8A8_UNORM for
            // guest codes 0 and 1 ONLY; every other assigned code -- 2,3,4,5,6,
            // 7,10,12,14,15 -- maps to a different DXGI format, and a D3D12 PSO
            // whose RTVFormats[0] disagrees with the bound RTV rasterizes
            // nothing and reports no error. Nobody could check that before,
            // because the code was consumed inside the derivation and never
            // printed.
            // 0xFFFFFFFF = RB_COLOR_INFO was never presented; 0 = k_8_8_8_8,
            // which is a legal and common render target and NOT an absence.
            uint32_t pipeColorFormatCode = 0xFFFFFFFFu;
            uint32_t pipeColorFormatDxgi = 0u;
            // The register-present mask, hoisted for the same reason: `rs` is
            // local to the derivation block (:2905) and the draw site is
            // outside it. Bit 8 is CpSnapshotReg::kCpSnapColorInfo, i.e. this
            // mask is what says whether RB_COLOR_INFO was presented at all --
            // which is a DIFFERENT question from what its colour_format was
            // (code 0 is present and legal, so "non-zero" is not a presence
            // test; see the note at the colour block).
            uint32_t pipeRsPresent = 0u;
            {
                // THE FILL SITE, first source: a grcFvf DECLARATION carried on the
                // command. It is still not carried -- DrawCapturedCommand has no
                // such member (render_queue.h:232-288) and capture_hooks.cpp:538-
                // 591 only fills a native::DrawPacket -- so this arm is dead and
                // is kept as the PREFERRED source, not deleted: when the
                // declaration lands, this block starts producing elements with no
                // edit to the builder, the marker or the counters. The guard is
                // written against the DECLARATION rather than omitted so the shape
                // of that fix stays visible in one place.
                mcla::native::GrcFvfDesc liveDecl{};
                if (liveDecl.fvfMask != 0u && liveDecl.fvfSize != 0u) {
                    inputLayout = backend_.BuildInputLayoutFromGrcFvf(liveDecl);
                    if (inputLayout.empty()) {
                        layoutRefusal = "decl-refused";
                        s_layoutDeclRefused.fetch_add(1,
                                                      std::memory_order_relaxed);
                    } else {
                        inputDeclHash = mcla::native::HashGrcFvfDeclaration(
                            mcla::native::DecodeGrcFvf(liveDecl));
                        s_layoutBuilt.fetch_add(1, std::memory_order_relaxed);
                    }
                } else {
                    layoutRefusal = "no-decl-carried";
                    s_layoutNoDecl.fetch_add(1, std::memory_order_relaxed);

                    // F-716, SECOND SOURCE: the guest's OWN vertex shader. This is
                    // the step-5 chain the note above names, and it is the ONLY
                    // source of a semantic anywhere in this tree. It is attempted
                    // for real now, and it is REFUSED by the measurement rather
                    // than by an assumption:
                    //
                    //   1. recover each stage's own code bytes (ResolveStageCode),
                    //      which is identity -- the bytes are on the command;
                    //   2. wrap them in the host-side envelope and PARSE it, so the
                    //      program's decoded form is measured, not assumed;
                    //   3. read `vertexElements` OUT OF THE PARSE. That vector is
                    //      the only place a semantic can come from
                    //      (ReferencedVertexInputs matches against it,
                    //      shader_translator.cpp:68-74). If it is EMPTY then every
                    //      semantic that function would hand back is its POSITION
                    //      fallback, and binding that is exactly the plausible-wrong
                    //      vertex this gate exists to stop, so the draw refuses.
                    //
                    // The step that CANNOT be done here, and is the blocker: the
                    // reference does not get vertex elements from the program
                    // either -- they are the vertex-FETCH hardware's -- and its
                    // interpolant set comes from the register file
                    // (d3d12/pipeline_cache.cc:882, :915). An embedded program
                    // therefore carries no element table at all, and this project
                    // captures neither the vfetch dst_reg (gpu_cp.cpp:1352 states
                    // the omission as deliberate) nor SQ_INTERPOLATOR_CNTL.
                    std::vector<uint8_t> vsCode, psCode, vsEnv, psEnv;
                    pipeVsCodeBytes = static_cast<uint32_t>(
                        ResolveStageCode(dc.vsProgram, vsCode, pipeVsSrc, mem));
                    pipePsCodeBytes = static_cast<uint32_t>(
                        ResolveStageCode(dc.psProgram, psCode, pipePsSrc, mem));
                    if (pipeVsCodeBytes != 0u)
                        s_pipeVsCode.fetch_add(1, std::memory_order_relaxed);
                    if (pipePsCodeBytes != 0u)
                        s_pipePsCode.fetch_add(1, std::memory_order_relaxed);
                    if (pipeVsCodeBytes != 0u &&
                        BuildProgramEnvelope(vsCode.data(), vsCode.size(), true, vsEnv)) {
                        s_pipeEnvelopeBuilt.fetch_add(1, std::memory_order_relaxed);
                        if (BuildProgramEnvelope(psCode.data(), psCode.size(), false, psEnv)) {
                            mcla::renderer::ShaderProgram vsProg;
                            if (mcla::renderer::ParseShaderProgram(
                                    vsEnv.data(), vsEnv.size(), vsProg)) {
                                s_pipeParsed.fetch_add(1, std::memory_order_relaxed);
                                // THE MEASUREMENT THAT DECIDES THE DRAW.
                                pipeVsElements = static_cast<uint32_t>(vsProg.vertexElements.size());
                                pipeVsInstructions = static_cast<uint32_t>(vsProg.instructions.size());
                                pipeVsInterpolants = static_cast<uint32_t>(vsProg.interpolators.size());
                                if (pipeVsElements == 0u) {
                                    // Every semantic ReferencedVertexInputs could
                                    // return is the POSITION fallback. Refuse.
                                    s_pipeLayoutNoVertexElements.fetch_add(
                                        1, std::memory_order_relaxed);
                                    layoutRefusal = "no-vertex-elements";
                                } else {
                                    // A REAL element table. Build the layout from
                                    // the guest's own declaration and PROVE it is
                                    // complete against the draw before using it.
                                    //
                                    // RESET THE REFUSAL NAME HERE. This is the fix for
                                    // a LIVE LANDMINE, and the gate below proves it
                                    // was armed.
                                    //
                                    // `no-decl-carried` (:2130) describes the ABSENCE
                                    // OF THE FIRST SOURCE -- the grcFvf DECLARATION
                                    // -- and it is set UNCONDITIONALLY. Nothing in the
                                    // tree ever put `layoutRefusal` back to "none".
                                    // The completeness proof below is gated on
                                    // `strcmp(layoutRefusal, "none") == 0`, so on the
                                    // live path it could not run on ANY draw, ever.
                                    // Measured on build/w690.log (105,187,535 B,
                                    // sha256 1d5ac2ab...348641, 677,188 lines):
                                    //   DRAW-CP-LAYOUT #2 draw=2 elements=1
                                    //     refusal=no-decl-carried declHash=0000...0000
                                    //   DRAW-CP-PIPE  #2 draw=2 layFromVE=0 declHash=0000
                                    // A ONE-ELEMENT LAYOUT WAS BUILT and the proof did
                                    // not run, so `inputDeclHash` stayed 0 and
                                    // ComputePipelineKeyForLayout folded a ZERO
                                    // DECLARATION HASH into the pipeline key for a
                                    // layout nothing had checked. Draw 2's layout was
                                    // UNPROVEN, and a PSO built from it would have
                                    // meant nothing.
                                    //
                                    // WHAT IS NOT LOST. The absence of the declaration
                                    // stays countable exactly as before, and this
                                    // assignment does not touch either of its two homes:
                                    //   s_layoutNoDecl, bumped at :2131, and the
                                    //   `noDecl=` field of every DRAW-CP-LAYOUT row.
                                    // Both are process-lifetime totals independent of
                                    // this string. What changes is only the MEANING:
                                    // `layoutRefusal` goes back to "no layout refusal
                                    // on this draw", which is what lets the proof run
                                    // and refuse in its OWN name.
                                    //
                                    // NOTHING HERE IS WEAKENED. Every refusal this arm
                                    // sets -- no-vertex-elements, no-format-for-element,
                                    // no-carried-element-for-fmt,
                                    // layout-element-count-mismatch, layout-past-stride
                                    // -- OVERWRITES the reset, and GATE A reports
                                    // whatever this string ends up holding. The proof
                                    // that was dead now runs, and if it refuses, that
                                    // refusal is the CORRECT answer and is left in
                                    // place: a refusal that names its blocker beats a
                                    // pipeline that lies (charter F-609).
                                    layoutRefusal = "none";
                                    //
                                    // FIELD PROVENANCE, one line per field, because
                                    // a wrong layout is a fake and this is where
                                    // that risk lives:
                                    //   SemanticName       <- vsProg.vertexElements
                                    //                         .usage, via
                                    //                         VertexUsageSemanticName
                                    //   SemanticIndex      <- .usageIndex
                                    //   AlignedByteOffset  <- VertexInputRef::offset,
                                    //                         i.e. the OFFSET THE
                                    //                         GUEST'S OWN FETCH
                                    //                         INSTRUCTION STATES
                                    //   InputSlotClass     <- PER_VERTEX_DATA: a
                                    //                         vertex buffer, stated
                                    //                         not inferred
                                    //   InputSlot          <- 0: this stream is
                                    //                         the one bound at slot 0
                                    //                         (dc.vbBase is the
                                    //                         slot-0 address the
                                    //                         producer resolved)
                                    //   Format             <- dc.vbElements[].fmt.dxgi,
                                    //                         PER ELEMENT, and
                                    //                         only after that
                                    //                         element's own 6-bit
                                    //                         format code was
                                    //                         matched against the
                                    //                         code the VS's own
                                    //                         fetch named. The
                                    //                         provenance rule and
                                    //                         the two refusals are
                                    //                         at the lookup below.
                                    //                         dc.vbFormat (element
                                    //                         0's summary) is no
                                    //                         longer read here at
                                    //                         all; it is still
                                    //                         printed on the
                                    //                         DRAW-CP-LAYOUT row.
                                    const auto refs =
                                        mcla::renderer::ReferencedVertexInputs(vsProg);
                                    for (size_t ri = 0; ri < refs.size(); ++ri) {
                                        const auto& r = refs[ri];
                                        // THE FORMAT FOR THIS ELEMENT, from the
                                        // CAPTURE. Not from element 0.
                                        //
                                        // WAS: "Only the element the command
                                        // actually carried has a measured FORMAT",
                                        // i.e. `(ri == 0) && (dc.vbFormat.dxgi !=
                                        // 0u)`. That grants a DXGI format to element
                                        // 0 ALONE, so with the two derived
                                        // elements of build/w690.log `ri == 1` could
                                        // never be true. Measured on that log:
                                        //   DRAW-CP-PIPE #1 draw=1
                                        //     stop=no-format-for-element
                                        //     vsElements=2
                                        //   DRAW-CP-LAYOUT #1 draw=1 elements=0
                                        //     nDesc=2 descriptorsNotCarried=1
                                        // TWO descriptors were DECODED by the
                                        // producer and the second was dropped here.
                                        // That is this gate keeping draw 1 from a
                                        // pixel.
                                        //
                                        // THE JUSTIFYING COMMENT WAS FALSE AND IS
                                        // CORRECTED, because a false sentence is
                                        // what the gate was resting on. It read: "this
                                        // project captures neither the vfetch
                                        // dst_reg (gpu_cp.cpp:1352 states the
                                        // omission as deliberate) nor
                                        // SQ_INTERPOLATOR_CNTL".
                                        //
                                        // WITHDRAWN: the dst_reg half. DrawCaptured-
                                        // Command carries `vbElements[]`
                                        // (src/render_queue.h:191-211 for the
                                        // element, :464-465 for the array and its
                                        // bound) with `elementIndex`, `dstReg`,
                                        // `dstRegAm`, `srcReg`, `srcSwizzle`,
                                        // `dstSwizzle`, `slotIndex`, `strideBytes`,
                                        // `offsetBytes`, `miniFetch`, `predicated`,
                                        // `conditional`, `predCondition`,
                                        // `indexRounded` and a PER-ELEMENT `fmt`
                                        // (xenos / dxgi / bytes / known). It is
                                        // filled at capture and printed as
                                        // CP-FETCHVB-ELEM. On the very draws this
                                        // gate refused, build/w690.log prints:
                                        //   #1 elem=0/2 dstReg=1 dstSwiz=A88 vf=57
                                        //      dxgi=6  fmtB=12 known=1 strideB=28
                                        //      offB=0  mini=0
                                        //   #1 elem=1/2 dstReg=0 dstSwiz=688 vf=38
                                        //      dxgi=2  fmtB=16 known=1 strideB=0
                                        //      offB=12 mini=1
                                        //   #2 elem=0/1 dstReg=0 dstSwiz=B48 vf=37
                                        //      dxgi=16 fmtB=8  known=1 strideB=8
                                        //      offB=0  mini=0
                                        // BOTH of draw 1's elements carry a real
                                        // DXGI mapping, and both are captured. So
                                        // this was never a capture gap: it was the
                                        // layout builder reading the wrong field.
                                        //
                                        // NOT WITHDRAWN: the SQ_INTERPOLATOR_CNTL
                                        // half. It is still uncarried, and nothing
                                        // in the format path needs it -- the comment
                                        // above the layout block (the grc_fvf
                                        // lane-code note) is the thing that does.
                                        //
                                        // HOW THE PROGRAM'S INPUT PAIRED WITH THE
                                        // CAPTURED ELEMENT, and why it invents
                                        // nothing. Two INDEPENDENT decoders read
                                        // the same guest fetch:
                                        //   refs[ri].vertexFormat -- the 6-bit
                                        //     data_format() the VS's OWN fetch
                                        //     named for this input, already
                                        //     masked at the decode
                                        //     (src/renderer/xenos_microcode.cpp:
                                        //     164, `instr.vertexFormat =
                                        //     (word1 >> 16) & 0x3F`);
                                        //   dc.vbElements[ae].fmt.xenos -- the same
                                        //     6-bit code the CP decoder read out
                                        //     of that fetch (src/gpu_cp.cpp; the
                                        //     field is carried at
                                        //     src/render_queue.h:210).
                                        // The pair is accepted ONLY when the two
                                        // name the SAME 6-bit code, and the format
                                        // used is then that element's CAPTURED
                                        // `fmt`. This file never calls a vf->DXGI
                                        // table here, never defaults, and never
                                        // lends element 0's format to another
                                        // element. When the two decoders disagree,
                                        // the refusal below is the correct answer,
                                        // not a mismatch to be papered over.
                                        //
                                        // TWO REFUSALS, because they are DIFFERENT
                                        // blockers and a refusal that misdescribes
                                        // its own cause is the defect this whole
                                        // chain exists to prevent:
                                        //   no-carried-element-for-fmt -- no element
                                        //     the CP captured on THIS draw names
                                        //     that 6-bit code. The VS and the CP
                                        //     disagree about this vertex.
                                        //   no-format-for-element       -- the code WAS
                                        //     captured but is UNMAPPED
                                        //     (`fmt.known == 0`) or has no DXGI
                                        //     mapping (`fmt.dxgi == 0`). NOT
                                        //     NEGOTIABLE: an unmapped format is a
                                        //     refusal, never a default. The NAME is
                                        //     the one w690 already printed for that
                                        //     case, so the census of this refusal
                                        //     keeps its vocabulary; the MEANING is
                                        //     now the per-element one rather than
                                        //     "only element 0 has a format".
                                        //
                                        // Both are countable by value on two existing
                                        // rows (`stop=` on DRAW-CP-PIPE, `refusal=`
                                        // on DRAW-CP-LAYOUT), so neither needs a new
                                        // counter and no existing marker changes
                                        // format.
                                        const uint32_t wantVf = r.vertexFormat & 0x3Fu;
                                        const mcla::native::CpVertexFormat *carried =
                                            nullptr;
                                        for (uint32_t ae = 0u;
                                             ae < dc.vbElementCount &&
                                             ae < mcla::native::kCpVertexElementMax;
                                             ++ae) {
                                            if ((dc.vbElements[ae].fmt.xenos & 0x3Fu) ==
                                                wantVf) {
                                                carried = &dc.vbElements[ae].fmt;
                                                break;
                                            }
                                        }
                                        if (carried == nullptr) {
                                            layoutRefusal = "no-carried-element-for-fmt";
                                            inputLayout.clear();
                                            pinnedLayout.clear();
                                            break;
                                        }
                                        // BOTH `known` and `dxgi` are required, and
                                        // that is what makes this unable to
                                        // substitute a format: `known` is the
                                        // capture's own statement that the 6-bit
                                        // code is one of the named
                                        // xenos::VertexFormats (render_queue.h:
                                        // 135), and `dxgi` is the mapping itself.
                                        const bool haveFormat =
                                            (carried->known != 0u) &&
                                            (carried->dxgi != 0u);
                                        if (!haveFormat) {
                                            layoutRefusal = "no-format-for-element";
                                            inputLayout.clear();
                                            pinnedLayout.clear();
                                            break;
                                        }
                                        D3D12_INPUT_ELEMENT_DESC e = {};
                                        e.SemanticName =
                                            mcla::renderer::VertexUsageSemanticName(r.usage);
                                        e.SemanticIndex = r.usageIndex;
                                        e.Format =
                                            static_cast<DXGI_FORMAT>(carried->dxgi);
                                        e.InputSlot = 0;
                                        e.InputSlotClass =
                                            D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA;
                                        // AlignedByteOffset <- VertexInputRef::offset,
                                        // the OFFSET THE GUEST'S OWN FETCH
                                        // INSTRUCTION STATES, IN BYTES.
                                        //
                                        // WAS: `static_cast<UINT>(r.offset)`, no
                                        // scale. That is a UNIT ERROR and it is
                                        // measured, not suspected:
                                        // src/renderer/xenos_microcode.cpp:171-172
                                        // decodes the field as `(word2 >> 8) &
                                        // 0x7FFFFF` sign-extended, which is DWORDS
                                        // -- the same field is documented as
                                        // "offset() :742, DWORDS" at
                                        // src/render_queue.h:175, and the
                                        // neighbouring `stride` is `word2 & 0xFF`
                                        // dwords at :170. The CP side scales it
                                        // exactly ONCE, at capture:
                                        // CP-FETCHVB-ELEM #1 in build/w690.log
                                        // prints `offB=12` for the fetch whose own
                                        // word2 holds `offsetDwords=3`
                                        // (CP-FETCHVB-DESC #1 instr=1, the same
                                        // log). Passing the dword count as a byte
                                        // offset therefore placed draw 1's second
                                        // element at byte 3, INSIDE element 0's
                                        // 12-byte payload, and it also made the
                                        // completeness check's `top` four times
                                        // too small -- a check that could not
                                        // fail. The scale is 4 because the field
                                        // is in dwords; it is the same scale
                                        // CpVertexElement::strideBytes applies
                                        // (src/render_queue.h:203, "stride() * 4;
                                        // DWORDS scaled ONCE here"). A negative
                                        // offset keeps its existing meaning (append)
                                        // and is not scaled.
                                        e.AlignedByteOffset =
                                            (r.offset >= 0)
                                                ? (static_cast<UINT>(r.offset) * 4u)
                                                : D3D12_APPEND_ALIGNED_ELEMENT;
                                        inputLayout.push_back(e);
                                        mcla::renderer::VertexInputSemantic sem;
                                        sem.usage = r.usage;
                                        sem.usageIndex = r.usageIndex;
                                        pinnedLayout.push_back(sem);
                                    }
                                    if (!inputLayout.empty() &&
                                        std::strcmp(layoutRefusal, "none") == 0) {
                                        // COMPLETENESS, measured against the draw
                                        // and not assumed. Two independent facts
                                        // have to agree: the number of elements the
                                        // program reads must be the number the
                                        // producer decoded, and the top of the
                                        // layout must reach the stride. Either
                                        // mismatch means the draw would read
                                        // attributes this PSO does not supply, or
                                        // would read past the vertex.
                                        const uint32_t wantDesc =
                                            (dc.vbDescCount > 0u) ? dc.vbDescCount
                                                                   : inputLayout.size();
                                        uint32_t top = 0;
                                        for (const auto& e : inputLayout) {
                                            if (e.AlignedByteOffset !=
                                                D3D12_APPEND_ALIGNED_ELEMENT) {
                                                top = (e.AlignedByteOffset >
                                                       top) ? e.AlignedByteOffset + 1u
                                                            : top + 1u;
                                            }
                                        }
                                        if (inputLayout.size() != wantDesc) {
                                            layoutRefusal = "layout-element-count-mismatch";
                                            inputLayout.clear();
                                            pinnedLayout.clear();
                                        } else if (top > dc.vbStride) {
                                            layoutRefusal = "layout-past-stride";
                                            inputLayout.clear();
                                            pinnedLayout.clear();
                                        } else {
                                            s_pipeLayoutFromVertexElements.fetch_add(
                                                1, std::memory_order_relaxed);
                                            // vertexDeclHash, the same shape the dead
                                            // path used (:849-861): a hash of the
                                            // xenos 6-bit format CODES the guest's own
                                            // fetches named, not of bytes we invented.
                                            // It is a second key field alongside
                                            // inputLayoutHash (which
                                            // ComputePipelineKeyForLayout folds in),
                                            // so the key still cannot claim one
                                            // declaration and hand the PSO another.
                                            std::vector<uint8_t> vfCodes;
                                            vfCodes.reserve(refs.size() * 4u);
                                            for (const auto& r2 : refs) {
                                                const uint32_t be = r2.vertexFormat;
                                                vfCodes.push_back(static_cast<uint8_t>(be >> 24));
                                                vfCodes.push_back(static_cast<uint8_t>(be >> 16));
                                                vfCodes.push_back(static_cast<uint8_t>(be >> 8));
                                                vfCodes.push_back(static_cast<uint8_t>(be));
                                            }
                                            inputDeclHash = mcla::renderer::HashShaderBytecode(vfCodes);
                                        }
                                    }
                                }
                            } else {
                                layoutRefusal = "vs-parse-refused";
                            }
                        }
                    }
                }

                // The row. bytesUnaccounted is the load-bearing number and it is
                // ARITHMETIC ON CARRIED FIELDS. It is the per-vertex stride the
                // program's OWN vertex fetches do not account for, and it is the
                // completeness check on the stride: if the fetches do not cover
                // the whole vertex then the input layout does not describe the
                // stream and nothing downstream may treat it as if it did.
                //
                // WHAT WAS WRONG (F-720). This summed ONE number --
                // dc.vbFormat.bytes, element 0's summary -- and therefore dropped
                // the vfetch_mini the producer had already decoded and carried.
                // Measured in build/w686.log it printed bytesUnaccounted=16 of a
                // 28 B vertex on the stride-28 draws and 0 of an 8 B vertex on the
                // stride-8 draws. The 16 B was not padding and not a second copy
                // of element 0: CP-FETCHVB-DESC #1 in the same log carries TWO
                // descriptors for that stream, and the arithmetic closes exactly
                // when both are counted:
                //
                //   element 0 dword_0=30081000  vf=57(k_32_32_32_FLOAT)
                //           dstSwizzle=0xA88 -> used=0b0111 -> mask 0b0111
                //           -> 3 dwords -> 12 B   miniFetch=0
                //   element 1 dword_0=00080000  vf=38(k_32_32_32_32_FLOAT)
                //           dstSwizzle=0x688 -> used=0b1111 -> mask 0b1111
                //           -> 4 dwords -> 16 B   miniFetch=1
                //   12 + 16 = 28 = the stride. Unaccounted = 0.
                //
                //   draw 2, one element: vf=37(k_32_32_FLOAT)
                //           dstSwizzle=0xB48 -> used=0b0011 -> mask 0b0011
                //           -> 2 dwords ->  8 B = the stride. Unaccounted = 0,
                //           which is why that draw already read 0 and hid the bug.
                //
                // The destination-swizzle narrowing is the reference's own
                // (shader_interpreter.cc:1019-1028 over xenos.h:648-683); see
                // CpVfetchBytesForSwizzle for why CpXenosFormatBytes cannot
                // express it.
                //
                // THE CHECK IS NOT WEAKENED, IT IS STRENGTHENED. Before, ANY
                // second element was worth a fixed 16 B of unexplained stride,
                // so the only draw that could read 0 was a one-element one whose
                // single element happened to equal the whole stride. Now a
                // mismatch can ONLY come from the guest's own fetches failing to
                // cover its own vertex, and that case still reads non-zero. There
                // is no path by which summing more elements turns a refusal into
                // a pass: this number is a REPORT either way, and the refusal
                // that depends on it is the layout-element-count /
                // layout-past-stride check above, which this change does not
                // touch.
                //
                // Saturating, not wrapping: `accounted` is accumulated in
                // uint64 and clamped, so a stream whose fetches exceed the stride
                // reports the whole stride accounted (unaccounted = 0) rather
                // than a wrapped 0xFFFF... The wrap would be a bigger lie than
                // either.
                uint64_t accountedRaw = 0;
                uint32_t countedElems = 0;
                for (uint32_t ae = 0u;
                     ae < dc.vbElementCount && ae < mcla::native::kCpVertexElementMax;
                     ++ae) {
                    accountedRaw += CpVfetchBytesForSwizzle(
                        dc.vbElements[ae].fmt.xenos,
                        dc.vbElements[ae].dstSwizzle);
                    ++countedElems;
                }
                if (countedElems == 0u) {
                    // No element was carried, so there is nothing to sum. Element
                    // 0's summary is then the only thing on the command and it is
                    // what a reader would use; it was ALREADY refused as
                    // unmapped above if it had no size.
                    accountedRaw = dc.vbFormat.bytes;
                }
                const uint32_t accounted =
                    (accountedRaw > static_cast<uint64_t>(dc.vbStride))
                        ? dc.vbStride
                        : static_cast<uint32_t>(accountedRaw);
                const uint32_t lb =
                    s_layoutLogged.fetch_add(1, std::memory_order_relaxed) + 1u;
                if (lb <= 8u || (lb % 200u) == 0u) {
                    MCLA_LOG_WARN(
                        "DRAW-CP-LAYOUT #{} draw={} elements={} declHash={:016X} "
                        "refusal={} | vf={} dxgi={} fmtB={} stride={} "
                        "bytesUnaccounted={} nDesc={} nFull={} "
                        "descriptorsNotCarried={} built={} noDecl={} "
                        "declRefused={}",
                        lb, n, inputLayout.size(), inputDeclHash,
                        layoutRefusal, dc.vbFormat.xenos, dc.vbFormat.dxgi,
                        dc.vbFormat.bytes, dc.vbStride,
                        dc.vbStride - accounted, dc.vbDescCount,
                        dc.vbFullCount,
                        (dc.vbDescCount > 1u) ? (dc.vbDescCount - 1u) : 0u,
                        s_layoutBuilt.load(std::memory_order_relaxed),
                        s_layoutNoDecl.load(std::memory_order_relaxed),
                        s_layoutDeclRefused.load(std::memory_order_relaxed));
                }
            }
            // inputLayout / inputDeclHash are the seam step 5 consumes. They are
            // read here so the pair cannot be deleted as unused before then, and
            // so this file states in one place what the next change has to do: a
            // PSO cannot be built from a stream format, and the F-652
            // no-translated-pso gate still stands unchanged above them.
            //
            // F-716: NO LONGER A SEAM. The (void) reads below are gone because the
            // F-652 derivation block now CONSUMES all three -- it builds the key
            // with inputDeclHash, refuses on an empty inputLayout, pins the VS
            // against pinnedLayout, and asks the cache for a PSO. They are not
            // deleted, they are used.

            // F-716: THE CHAIN'S OWN ROW. A new marker name, because the existing
            // ones are tracked (tools/soak_census.py) and their formats must not
            // change; this one answers "how far did this draw get" in one place,
            // which is otherwise spread over five refusal reasons. Bounded like
            // every other row here (n <= 8, then every 200th) while every number
            // on it is a process-lifetime total, so bounding the log does not
            // bound the census (F-054 / F-648).
            auto pipeRow = [&]() {
                const uint32_t pn =
                    s_pipeLogged.fetch_add(1, std::memory_order_relaxed) + 1u;
                if (pn > 8u && (pn % 200u) != 0u) return;
                MCLA_LOG_WARN(
                    "DRAW-CP-PIPE #{} draw={} stop={} | vsSrc={} vsB={} psSrc={} "
                    "psB={} | envelope={} parsed={} vsElements={} vsInstrs={} "
                    "vsInterp={} | vsHlsl={} psHlsl={} vsHash={:016X} "
                    "psHash={:016X} | layout={} declHash={:016X} | "
                    "psoReq={} psoNull={} psoGeomStage={} || "
                    "vsCode={} psCode={} envBuilt={} parsed={} vsTr={} psTr={} "
                    "layFromVE={} layNoVE={} pso={} geom={}",
                    pn, n, pipeStop, pipeVsSrc, pipeVsCodeBytes, pipePsSrc,
                    pipePsCodeBytes,
                    s_pipeEnvelopeBuilt.load(std::memory_order_relaxed),
                    s_pipeParsed.load(std::memory_order_relaxed),
                    pipeVsElements, pipeVsInstructions, pipeVsInterpolants,
                    pipeVsHlsl.size(), pipePsHlsl.size(), pipeVsHash, pipePsHash,
                    inputLayout.size(), inputDeclHash,
                    s_pipePsoRequested.load(std::memory_order_relaxed),
                    s_pipePsoNull.load(std::memory_order_relaxed),
                    pipeHasGeomStage ? 1u : 0u,
                    s_pipeVsCode.load(std::memory_order_relaxed),
                    s_pipePsCode.load(std::memory_order_relaxed),
                    s_pipeEnvelopeBuilt.load(std::memory_order_relaxed),
                    s_pipeParsed.load(std::memory_order_relaxed),
                    s_pipeTranslatedVs.load(std::memory_order_relaxed),
                    s_pipeTranslatedPs.load(std::memory_order_relaxed),
                    s_pipeLayoutFromVertexElements.load(std::memory_order_relaxed),
                    s_pipeLayoutNoVertexElements.load(std::memory_order_relaxed),
                    s_pipePsoRequested.load(std::memory_order_relaxed),
                    s_pipePsoCarriesGeomStage.load(std::memory_order_relaxed));
                // THE REFUSAL STRING, WHICH HAD NO READER IN THE TREE.
                //
                // Measured before this line existed: `pipeTranslateError`
                // had THREE occurrences in the whole repository -- its
                // declaration (:2106) and the two TranslateShaderPinned calls
                // that hand it over as an out-parameter. NOTHING READ IT. The
                // translator does fill it on every refusal path
                // (src/renderer/shader_translator.cpp:1362 "container parse
                // failed", :1399 the pixel-shader/layout refusal, :1422
                // `gen.error()`, :1428 "translation produced no HLSL"), so the
                // string was produced and then dropped on the floor: a
                // `stop=ps-translate-refused` row said THAT it stopped and
                // never WHY.
                //
                // A NEW MARKER NAME, NOT A FIELD ON THIS ROW. DRAW-CP-PIPE is
                // one of the tracked markers (its §9 inventory is re-parsed
                // by tools/soak_census.py) and appending a field to it would
                // change a tracked format. `DRAW-CP-PIPE-ERR` is a name of its
                // own, measured at 0 hits across src/**/*.cpp, src/**/*.h and
                // docs/*.md before this line was written, so it cannot collide
                // with a marker, a row or a doc heading.
                //
                // Bounded by the same `pn` and printed only when the string is
                // non-empty, from inside the same pipeRow() call, so a
                // DRAW-CP-PIPE-ERR line ALWAYS follows its DRAW-CP-PIPE line and
                // the two shapes cannot disagree about which draws they
                // describe. F-054 (one shape owning a log) is not at risk: at
                // most one extra line per bounded row.
                if (!pipeTranslateError.empty()) {
                    MCLA_LOG_WARN(
                        "DRAW-CP-PIPE-ERR #{} draw={} stop={} stage={} err={}",
                        pn, n, pipeStop, pipeTrStage, pipeTranslateError);
                }
            };

            // --- F-652: pipeline-state derivation, ON THE LIVE PATH ----------
            //
            // Placed HERE - after every data-integrity gate, BEFORE the topology
            // gate - for a reason that is not cosmetic. The measured stream is
            // 100% prim=0x08 kRectangleList (build/w664.log), and if the
            // derivation sat below the MapXenosPrimType gate it would be dead
            // code again on exactly the stream it exists to explain: the
            // topology gate would break first, every time. So the derivation
            // runs first, refuses prim=0x08 by its OWN named reason
            // (unsupported-topology, pipeline_cache.cpp:898-912), and the
            // existing prim-rect-list counter is still bumped below so neither
            // marker goes dark.
            //
            // WHAT POPULATES PipelineStateInputs, field by field:
            //   paClipCntl/paSuScModeCntl/paClVteCntl  <- dc.rasterState.regs[],
            //     snapshotted by the CP at enqueue (src/gpu_cp.cpp,
            //     CpSnapshotDrawState). NOT re-read here.
            //   registersPresent  <- dc.rasterState.presentMask, mapped onto the
            //     renderer::kGuestReg* bits by POSITION below. This is the fact
            //     the whole refusal chain rests on, and it comes from the
            //     export's per-index presence bitmap (src/gpu_cp.cpp:144, read
            //     at snapshot time) - NEVER from "the value is non-zero". Those
            //     are different facts: PA_SU_SC_MODE_CNTL = 0 is a LEGAL and
            //     DIFFERENT rasteriser (pipeline_cache.h:132-136), so a
            //     value-derived presence bit would turn "never written" into a
            //     confident, wrong rasteriser.
            //   primType          <- dc.primitiveTopology, which is
            //     VGT_DRAW_INITIATOR.prim_type read at 6 bits
            //     (src/gpu_cp.cpp DrawInitiatorField(di, 0, 6), registers.h:315)
            //     - i.e. the ARCHITECTED xenos::PrimitiveType. This settles, for
            //     this path, the "UNMEASURED PREMISE" F-645 left open at
            //     pipeline_cache.cpp:857-871: the stale `ctx.r4.u32 & 7` premise
            //     belongs to capture_hooks.cpp/DRAW_INDEXED, NOT to this one. A
            //     3-bit field could not even express 0x08.
            //   polyOffset*       <- the four kFloat magnitudes, host-order.
            //   depthFormat       <- RB_DEPTH_INFO bit 16, ONLY when present.
            //   colorFormats[0]    <- F-723: RB_COLOR_INFO.color_format (4 bits
            //     at +16), mapped to a DXGI_FORMAT by
            //     MapXenosColorFormatToDxgi, ONLY when the register is PRESENT.
            //     colorFormats[1..7] and depthStencilFormat: STILL LEFT AT ZERO.
            //     RB_COLOR1/2/3_INFO (0x2003/0x2004/0x2005) have no slot in
            //     CpSnapshotReg, so slots 1..7 are not captured rather than
            //     guessed, and DerivePipelineState's numRt therefore counts only
            //     the targets this stream really measured. Viewport extents
            //     remain zero too, which DerivePipelineState refuses itself if
            //     the guest enabled a viewport transform
            //     (pipeline_cache.cpp:787), and it folds DepthEnable off when
            //     there is no depth format (:1144-1149) rather than inventing
            //     one.
            {
                s_deriveAttempted.fetch_add(1, std::memory_order_relaxed);
                mcla::renderer::PipelineStateInputs psi;
                const auto& rs = dc.rasterState;
                psi.paClipCntl = rs.regs[CpSnapshotReg::kCpSnapPaClipCntl];
                psi.paSuScModeCntl =
                    rs.regs[CpSnapshotReg::kCpSnapPaSuScModeCntl];
                psi.paClVteCntl = rs.regs[CpSnapshotReg::kCpSnapPaClVteCntl];
                psi.primType = static_cast<uint8_t>(dc.primitiveTopology);
                // haveRegisters is the DERIVATION's precondition, not the
                // guest's: it says "these three values are the guest's", which is
                // only true when all three presence bits are set. Any subset and
                // the answer is kRefuseStateNotDerived, which is precisely the
                // refusal that keeps a partially-snapshotted draw from building
                // a half-default rasteriser.
                psi.haveRegisters = (rs.presentMask &
                                     (mcla::renderer::kGuestRegPaClipCntl |
                                      mcla::renderer::kGuestRegPaSuScModeCntl |
                                      mcla::renderer::kGuestRegPaClVteCntl)) ==
                                    (mcla::renderer::kGuestRegPaClipCntl |
                                     mcla::renderer::kGuestRegPaSuScModeCntl |
                                     mcla::renderer::kGuestRegPaClVteCntl);
                // POSITION, not VALUES: bit i of the producer's mask -> bit k of
                // the renderer's GuestRegisterPresent. The two enums number
                // things differently on purpose (kCpSnapPaClipCntl = 0 vs
                // kGuestRegPaClipCntl = 1<<1), so this table is the ONE place the
                // correspondence exists and it cannot be "obvious" enough to
                // drift.
                psi.registersPresent =
                    ((rs.presentMask &
                      (1u << CpSnapshotReg::kCpSnapPaClipCntl))
                         ? mcla::renderer::kGuestRegPaClipCntl
                         : mcla::renderer::kGuestRegNone) |
                    ((rs.presentMask &
                      (1u << CpSnapshotReg::kCpSnapPaSuScModeCntl))
                         ? mcla::renderer::kGuestRegPaSuScModeCntl
                         : mcla::renderer::kGuestRegNone) |
                    ((rs.presentMask &
                      (1u << CpSnapshotReg::kCpSnapPaClVteCntl))
                         ? mcla::renderer::kGuestRegPaClVteCntl
                         : mcla::renderer::kGuestRegNone) |
                    ((rs.presentMask & ((1u << CpSnapshotReg::kCpSnapPolyOffFrontScale) |
                                        (1u << CpSnapshotReg::kCpSnapPolyOffFrontOffset)))
                         ? mcla::renderer::kGuestRegPolyOffsetFront
                         : mcla::renderer::kGuestRegNone) |
                    ((rs.presentMask & ((1u << CpSnapshotReg::kCpSnapPolyOffBackScale) |
                                        (1u << CpSnapshotReg::kCpSnapPolyOffBackOffset)))
                         ? mcla::renderer::kGuestRegPolyOffsetBack
                         : mcla::renderer::kGuestRegNone) |
                    ((rs.presentMask & (1u << CpSnapshotReg::kCpSnapDepthInfo))
                         ? mcla::renderer::kGuestRegDepthInfo
                         : mcla::renderer::kGuestRegNone);
                // kFloat registers: the file's register values are the LOGICAL
                // dwords (a big-endian READ produced them, which is byte-for-byte
                // the reference's ReadAndSwap result), so the bits reinterpret as
                // a host float with NO byte swap. memcpy, never a union pun and
                // never a reinterpret_cast of a guest address.
                const uint32_t poFloats[4] = {
                    rs.regs[CpSnapshotReg::kCpSnapPolyOffFrontScale],
                    rs.regs[CpSnapshotReg::kCpSnapPolyOffFrontOffset],
                    rs.regs[CpSnapshotReg::kCpSnapPolyOffBackScale],
                    rs.regs[CpSnapshotReg::kCpSnapPolyOffBackOffset]};
                std::memcpy(&psi.polyOffsetFrontScale, &poFloats[0],
                            sizeof(psi.polyOffsetFrontScale));
                std::memcpy(&psi.polyOffsetFrontOffset, &poFloats[1],
                            sizeof(psi.polyOffsetFrontOffset));
                std::memcpy(&psi.polyOffsetBackScale, &poFloats[2],
                            sizeof(psi.polyOffsetBackScale));
                std::memcpy(&psi.polyOffsetBackOffset, &poFloats[3],
                            sizeof(psi.polyOffsetBackOffset));
                // depth_format is ONE bit at +16 of RB_DEPTH_INFO
                // (registers.h:844). Read it ONLY when the register is present,
                // which is what PipelineStateInputs documents.
                psi.depthFormat =
                    (psi.registersPresent & mcla::renderer::kGuestRegDepthInfo)
                        ? ((rs.regs[CpSnapshotReg::kCpSnapDepthInfo] >> 16) & 1u)
                        : 0u;
                // The Xenos ztest lives in RB_DEPTHCONTROL, which this tree does
                // not capture (pipeline_cache.h:435-446). The caller therefore
                // does NOT demand measured depth state here, so the derivation
                // emits its DOCUMENTED always-pass/no-write placeholder and flags
                // it kStateFlagUnmeasuredDepth rather than refusing every draw -
                // a stated placeholder is countable, an unbuildable PSO is not.

                // --- F-723: the render-target format, from RB_COLOR_INFO ------
                //
                // This is what unblocks the PSO. Until it existed,
                // PipelineStateInputs::colorFormats[] was left all-zero on
                // purpose (the "LEFT AT ZERO" note above), DerivePipelineState
                // copied those zeroes into targetFormats[] verbatim
                // (pipeline_cache.cpp:841-842), and the worker's own gate then
                // refused the key with kRefuseEmptyHlsl / "key names no render
                // target format" (pipeline_cache.cpp:1730-1747) - the
                // DRAW-CP-DRAWN=0 state measured in build/w691_err.log.
                //
                // THE PRESENCE BIT IS LOAD-BEARING, and this is the same
                // discipline kCpSnapDepthInfo uses two lines above. The trap is
                // concrete: color_format 0 is k_8_8_8_8 (xenos.h:300), a legal
                // and common render target, so a test written as "the value is
                // non-zero" would refuse every k_8_8_8_8 draw -- and a test that
                // ignored presence would build a PSO naming a target the guest
                // never declared. Neither fact may be inferred from the other.
                //
                // ONLY RT0 IS FILLED, and that is the measured limit of the
                // snapshot, not a choice: RB_COLOR1/2/3_INFO (0x2003/0x2004/
                // 0x2005) have no slot in CpSnapshotReg, so slots 1..3 of
                // colorFormats[] stay zero and the worker's numRt counts what was
                // really captured. A multi-RT draw is therefore reported as
                // numRt=1 rather than four guessed formats -- see
                // s_cpRefuseColorFmtUnmapped's row below for what happens when
                // even RT0 cannot be named.
                {
                    const bool colorInfoPresent =
                        (rs.presentMask &
                         (1u << CpSnapshotReg::kCpSnapColorInfo)) != 0u;
                    if (colorInfoPresent) {
                        // color_format is 4 bits at +16 of RB_COLOR_INFO
                        // (registers.h:745, docs/ref/xenos_registers.md:281).
                        const uint32_t code =
                            (rs.regs[CpSnapshotReg::kCpSnapColorInfo] >> 16) & 0xFu;
                        const uint32_t dxgi = MapXenosColorFormatToDxgi(code);
                        if (dxgi == DXGI_FORMAT_UNKNOWN) {
                            // Codes 8/9/11/13 are UNASSIGNED (xenos.h:299-319).
                            // Refused by name, NOT defaulted: a default here
                            // would name a render target format the guest never
                            // produced, which is the fabrication F-609 forbids.
                            s_cpRefuseColorFmtUnmapped.fetch_add(
                                1, std::memory_order_relaxed);
                            const uint32_t rn = dc.cpSeq;
                            if (rn <= 8u || (rn % 200u) == 0u) {
                                MCLA_LOG_WARN(
                                    "CP-COLORFMT-UNMAPPED #{} drawSeq={} "
                                    "colorFormat={} (unassigned in "
                                    "xenos::ColorRenderTargetFormat, "
                                    "xenos.h:299-319) rbColorInfo={:08X} "
                                    "rsPresent={:08X} -- NO render target format "
                                    "exists for this code; NOT defaulted",
                                    rn, rn, code,
                                    rs.regs[CpSnapshotReg::kCpSnapColorInfo],
                                    rs.presentMask);
                            }
                            refuse("color-fmt-unmapped", s_cpRefuseColorFmtUnmapped,
                                   "- RB_COLOR_INFO.color_format is a code with "
                                   "no DXGI_FORMAT (8/9/11/13 are unassigned, "
                                   "xenos.h:299-319). NOT defaulted to any "
                                   "format; the draw has no render target to "
                                   "name, so no PSO can be built from it.");
                            break;
                        }
                        psi.colorFormats[0] = dxgi;
                        // 2026-10-02: keep the guest's own three numbers for the
                        // draw site's row. The mapping table at
                        // MapXenosColorFormatToDxgi (:456-501) reaches
                        // DXGI_FORMAT_R8G8B8A8_UNORM -- the format of the bound
                        // swapchain back buffer -- for codes 0 and 1 only, so
                        // `dxgi` is the single fact that decides whether the
                        // PSO and the RTV agree. Without it the value was
                        // consumed here and never printed anywhere.
                        pipeColorFormatCode = code;
                        pipeColorFormatDxgi = dxgi;
                        pipeRsPresent = rs.presentMask;
                    } else {
                        // The guest never presented RB_COLOR_INFO before this
                        // draw. Naming a format here would be inventing one.
                        // NOTE this is deliberately NOT the same refusal as
                        // color-fmt-unmapped: see the two counters' declaration.
                        s_cpRefuseNoColorInfo.fetch_add(1, std::memory_order_relaxed);
                        const uint32_t rn = dc.cpSeq;
                        if (rn <= 8u || (rn % 200u) == 0u) {
                            MCLA_LOG_WARN(
                                "CP-COLORFMT-NOINFO #{} drawSeq={} rsPresent={:08X}"
                                " -- RB_COLOR_INFO (0x2001) was NOT presented "
                                "before this draw, so no render target format is "
                                "the guest's. NOT defaulted",
                                rn, rn, rs.presentMask);
                        }
                        refuse("no-color-info", s_cpRefuseNoColorInfo,
                               "- the state derived and no RB_COLOR_INFO (0x2001) "
                               "was presented before this draw, so there is no "
                               "render target format to name. NOT defaulted to "
                               "any format.");
                        break;
                    }
                }

                uint32_t refuseMask = mcla::renderer::kRefuseNone;
                const mcla::renderer::PipelineState derived =
                    mcla::renderer::DerivePipelineState(psi, refuseMask);
                if (refuseMask != mcla::renderer::kRefuseNone) {
                    s_deriveRefused.fetch_add(1, std::memory_order_relaxed);
                    // The run-wide OR of every refusal mask, so the PC-DERIVE row
                    // can print real NAMES for the whole run rather than only for
                    // whichever mask the last draw happened to produce. Lock-free
                    // fetch_or; a lost update here would only ever under-report,
                    // never invent a reason, and the per-bit histogram above is
                    // the exact authority anyway.
                    s_deriveMaskOr.fetch_or(refuseMask,
                                            std::memory_order_relaxed);
                    // Per-BIT totals, so the census is a histogram of named
                    // reasons and not one lumped "refused" number. A mask can
                    // legitimately carry several bits at once (an absent 0x2205
                    // gives kRefuseNoPaSuScModeCntl AND the poly-offset/depth
                    // consequences of a rasteriser nobody measured), and
                    // counting the mask once would understate the reasons that
                    // matter.
                    for (uint32_t bit = 0; bit < 32u; ++bit) {
                        if ((refuseMask & (1u << bit)) == 0u) continue;
                        s_deriveRefusedByBit[bit].fetch_add(
                            1, std::memory_order_relaxed);
                    }
                    // The NAME, from the one owner of the name table. Never a
                    // bare hex code: pipeline_cache.cpp:226-234 records the guard
                    // that once made every refusal in that file print
                    // "unnamed-0x%08X", and two agents were misled by it.
                    char reasons[512] = {};
                    mcla::renderer::FormatPipelineRefusal(refuseMask, reasons,
                                                          sizeof(reasons));
                    if (dc.primitiveTopology == 0x08u) {
                        // Keep the rectangle list countable on ITS OWN counter
                        // too. This is not a second refusal of the same draw: it
                        // is the same draw, refused once, recorded under both the
                        // reason the derivation gives and the gate that has
                        // always named it - so neither marker can be lost by the
                        // reordering, and neither can be double-counted as two
                        // draws (there is exactly one `break` below).
                        s_rectListRefused.fetch_add(1, std::memory_order_relaxed);
                        refuse("prim-rect-list", s_cpRefusePrimRect,
                               "- xenos::PrimitiveType::kRectangleList "
                               "(xenos.h:53) has no D3D12 primitive type, so "
                               "DerivePipelineState refused the key with "
                               "reason(s)=");
                        // refuse() above cannot take the formatted string (it is
                        // std::string_view), so the names are printed on their own
                        // bounded row rather than being dropped. Bounded, but the
                        // HISTOGRAM above is the authority and is uncapped.
                        const uint32_t rn = dc.cpSeq;
                        if (rn <= 8u || (rn % 200u) == 0u) {
                            MCLA_LOG_WARN(
                                "PC-DERIVE-REFUSE #{} drawSeq={} prim=0x{:02X} "
                                "refuseMask=0x{:08X} reasons={} | "
                                "rsPresent={:08X} haveRegisters={}",
                                rn, rn, dc.primitiveTopology, refuseMask,
                                reasons, rs.presentMask,
                                psi.haveRegisters ? 1u : 0u);
                        }
                    } else {
                        refuse("state-refused", s_cpRefuseStateRefused,
                               "- DerivePipelineState refused the pipeline key; "
                               "the named reasons are on PC-DERIVE-REFUSE and the "
                               "per-bit totals on PC-DERIVE. NOT drawn on a "
                               "default rasteriser.");
                    }
                    // REFUSE. The draw stops here. It does not fall through to
                    // DrawDynamicMesh, because that resolves to the TEST PSO
                    // (src/d3d12_backend.cpp:2537-2539) and a test PSO against a
                    // rasteriser we could not derive is the plausible-but-wrong
                    // picture this project's charter (F-609) exists to prevent.
                    break;
                }
                s_deriveOk.fetch_add(1, std::memory_order_relaxed);
                // The derivation stamps its own provenance
                // (pipeline_cache.h:242, kStateDerivedGuest). Checking it here
                // is not ceremony: it is the ONLY thing that distinguishes "the
                // state was derived from the guest's registers" from the one
                // path where DerivePipelineState returns a ZERO state with
                // refuseMask already overwritten - the layout self-check
                // failure (pipeline_cache.cpp:804-816), which is the one case
                // where a non-zero mask is NOT set. A zero state there would
                // otherwise sail past `refuseMask != 0` and reach the draw call
                // with an empty rasteriser.
                if (derived.derivation == mcla::renderer::kStateDerivedNone) {
                    s_cpRefuseStateRefused.fetch_add(1, std::memory_order_relaxed);
                    s_deriveMaskOr.fetch_or(
                        static_cast<uint32_t>(mcla::renderer::kRefuseStateNotDerived),
                        std::memory_order_relaxed);
                    refuse("state-not-derived", s_cpRefuseStateRefused,
                           "- DerivePipelineState returned a state with no "
                           "derivation provenance (kStateDerivedNone). That is "
                           "the PC-REG-LAYOUT-BAD self-check path: the register "
                           "overlays do not decode the measured guest values, so "
                           "every shift in the derivation is wrong somewhere. "
                           "NOT drawn on the returned state.");
                    break;
                }

                // The state derived. Two things can still legitimately stop the
                // draw, and both are NAMED rather than defaulted past:
                //   (1) no program. The command carries the programs this draw
                //       selects (F-652). A missing stage is a refusal, not a
                //       zero program address - address 0 is a readable guest page
                //       in this window, so it would be the cheapest plausible-
                //       wrong shader there is.
                //   (2) no PSO. Building one needs translated HLSL and an input
                //       layout from the guest's own program.
                //
                // F-716 REPLACED (2). It used to be an unconditional refusal with
                // the comment "until src/renderer/** lands it is the SEAM", and it
                // was: the block that follows ended in `break` on every path, which
                // made EVERY statement after the derivation scope -- the topology
                // gate, BeginFrame, the draw call and the DRAW-CP-DRAWN row itself
                // -- unreachable, so the compiler discarded them. That is measured,
                // not inferred: a probe literal inserted immediately before the
                // derivation block IS in render_thread.cpp.obj, and identical
                // probes immediately after it and at the DRAW-CP-DRAWN row are
                // NOT, at /O2 and at /Od alike, while `DRAW-CP-DRAWN` itself is
                // present in the source and absent from the shipped
                // build/mcla.exe. So the marker's zero was never "uninformative
                // until it ships": the code that prints it did not exist in the
                // binary. The chain below is what makes it exist.
                //
                // The chain, in order, ONE path, no second mechanism:
                //   code bytes (identity, already resolved) -> envelope -> parse
                //   (done in the layout block, because the VS's entry signature
                //   has to be pinned to the layout) -> TranslateShaderPinned ->
                //   ComputePipelineKeyForLayout -> GetOrCompile -> PSO.
                if (dc.vsProgram.present == 0u) {
                    s_deriveNoVsProgram.fetch_add(1, std::memory_order_relaxed);
                    refuse("no-vs-program", s_cpRefuseNoVsProgram,
                           "- the state derived, but no PM4_IM_LOAD has ever "
                           "delivered a vertex program, so there is no shader to "
                           "translate. NOT defaulted to any program.");
                    break;
                }
                if (dc.psProgram.present == 0u) {
                    s_deriveNoPsProgram.fetch_add(1, std::memory_order_relaxed);
                    refuse("no-ps-program", s_cpRefuseNoPsProgram,
                           "- the state derived, but no PM4_IM_LOAD has ever "
                           "delivered a pixel program, so there is no shader to "
                           "translate. NOT defaulted to any program.");
                    break;
                }
                {
                    // F-716: THE CHAIN. Everything the old unconditional refusal
                    // said about itself is preserved below, because it is a correct
                    // account of the OLD state and it is the reason the code after
                    // this block was dead code.
                    //
                    // WHAT THE OLD BLOCK WAS, verbatim in substance: "the state
                    // DERIVED (refuseMask == 0) and both stages name a program, but
                    // no translated HLSL / input layout exists for them yet, so
                    // there is no pipeline to bind." Its `break` is what made the
                    // refusal a refusal -- with no break this block fell THROUGH
                    // out of the derivation scope, past MapXenosPrimType and into
                    // DrawDynamicMesh(desc), so every draw reaching this gate was
                    // refused TWICE and counted twice (once as no-translated-pso
                    // and again as prim-rect-list). Measured in build/w682.log:
                    // 6/6 captured draws, refusals-per-draw exactly [2] for all
                    // six. So the `break` was correct AND the block was wrong: the
                    // chain it was standing in for now exists, so the refusal is
                    // no longer unconditional and the break is no longer free.
                    //
                    // F-653 already removed the backend-side half of the old
                    // fallback: DrawDynamicMesh no longer forwards to the test PSO,
                    // it refuses (d3d12_backend.cpp:2622-2634), and the 28-byte
                    // layout gate moved to :2674-2698 and fires only for a test PSO
                    // a caller passed deliberately. A refusal in this file still has
                    // to be a refusal HERE, and each gate below is one.

                    // GATE A -- the input layout. If this is empty there is nothing
                    // to pin the VS to and GetOrCompile would refuse it anyway
                    // (kRefuseEmptyInputLayout, pipeline_cache.cpp:2204-2208), so
                    // it is refused here where the REASON is known. `layoutRefusal`
                    // is the name of the specific gap, measured in the layout block
                    // above, not a guess.
                    if (inputLayout.empty()) {
                        pipeStop = layoutRefusal;
                        pipeRow();
                        s_deriveNoTranslatedPso.fetch_add(1, std::memory_order_relaxed);
                        refuse("no-translated-pso", s_cpRefuseNoPso,
                               "- the state DERIVED (refuseMask == 0) and both stages "
                               "named a program, and the program's OWN code was "
                               "recovered and parsed, but no D3D12 input layout could "
                               "be derived from it, so there is no pipeline to bind. "
                               "See DRAW-CP-PIPE for the gate that stopped it. NOT "
                               "drawn on any substitute: the break ends the draw "
                               "here, so this command reaches neither "
                               "MapXenosPrimType nor any draw call and is never read "
                               "through an input layout the guest never declared.");
                        break;
                    }

                    // GATE B -- the vertex shader, TRANSLATED, with its entry
                    // signature PINNED to the layout above. Pinned, not free: with
                    // a pin the signature can only use semantics the input
                    // assembler actually supplies (shader_translator.h:77-97),
                    // which is what removes the second naming that F-609 item 4
                    // describes. `TranslateShaderPinned` is the required entry
                    // point and the ONLY one used here; `TranslateShader` (the dead
                    // path's, :803) is not, because it would re-derive semantics
                    // from a fetch walk and could disagree with the layout.
                    {
                        std::vector<uint8_t> vsCode, vsEnv;
                        const char *vsSrc = "absent";
                        (void)ResolveStageCode(dc.vsProgram, vsCode, vsSrc, mem);
                        std::vector<uint8_t> psCode, psEnv;
                        const char *psSrc = "absent";
                        (void)ResolveStageCode(dc.psProgram, psCode, psSrc, mem);
                        if (!BuildProgramEnvelope(vsCode.data(), vsCode.size(), true, vsEnv) ||
                            !BuildProgramEnvelope(psCode.data(), psCode.size(), false, psEnv)) {
                            pipeStop = "envelope-refused";
                            pipeRow();
                            refuse("no-translated-pso", s_cpRefuseNoPso,
                                   "- a stage had no usable program bytes to wrap. "
                                   "See DRAW-CP-PIPE. NOT translated from nothing.");
                            break;
                        }
                        mcla::renderer::TranslatedShader vsOut;
                        pipeTrStage = "vs";
                        if (!mcla::renderer::TranslateShaderPinned(
                                vsEnv.data(), vsEnv.size(), pinnedLayout.data(),
                                pinnedLayout.size(), vsOut, pipeTranslateError)) {
                            pipeStop = "vs-translate-refused";
                            pipeRow();
                            refuse("no-translated-pso", s_cpRefuseNoPso,
                                   "- TranslateShaderPinned refused the vertex "
                                   "shader. See DRAW-CP-PIPE. NOT drawn on a "
                                   "default shader.");
                            break;
                        }
                        s_pipeTranslatedVs.fetch_add(1, std::memory_order_relaxed);
                        // HOISTED HERE, immediately after the stage that
                        // produced them. WAS: eleven lines below the `break`
                        // the PS refusal takes, which made every pipeRow()
                        // call above it read `pipeVsHlsl` BEFORE its only
                        // writer. Measured on build/w690.log,
                        // DRAW-CP-PIPE #2 printed `vsTr=1 vsHlsl=0` -- a counter
                        // read before its writer, NOT a discarded translation
                        // and NOT an empty one: the translator emitted 1,138
                        // bytes for that VS and nothing on the row could say so,
                        // because the row was written first.
                        //
                        // The `empty-hlsl` gate below is NOT bypassed by the
                        // move: it reads `vsOut.hlsl` / `psOut.hlsl` directly,
                        // so a stage that translated to nothing still refuses.
                        // What changes is only WHEN the row is told.
                        pipeVsHlsl = vsOut.hlsl;
                        pipeVsHash = vsOut.programHash;
                        // A pixel shader is not a vertex shader, so it is handed NO
                        // layout: TranslateShaderPinned returns false for exactly
                        // that mismatch (shader_translator.cpp:1311), and passing
                        // one would be asking it to resolve vertex inputs on a
                        // program that has none.
                        //
                        // WHY IT IS ALSO HANDED THE VS. The reference's GPR seed is a
                        // PER-DRAW value -- `VS.writes_interpolators() &
                        // PS.GetInterpolatorInputMask(SQ_PROGRAM_CNTL, ...)`
                        // (vulkan_command_processor.cc:2206-2211,
                        // d3d12/d3d12_command_processor.cc:2081-2086) -- so a PS
                        // translated without its VS takes the reference's mask-0
                        // branch and every unwritten GPR seeds from 0.0. That is
                        // honest, and it is NOT what the guest supplied on draw #1:
                        // its VS (CP-SHADER-BODY #3, hash D99385F5E67A3EB1) exports
                        // interpolant 0 at instruction [5] (word0 = C80F8000: bit 15
                        // export, bits 5:0 dest = 0, bits 19:16 write mask = 0xF),
                        // and the paired PS reads r0 and writes nothing, so the
                        // reference seeds r0 from interpolant 0 there. Draw #2's VS
                        // (CP-SHADER-BODY #5, hash AEAF1F096E09B347) exports only
                        // vectorDest 62 = POSITION, contributes no bit, and 0.0 is
                        // correct there.
                        //
                        // The envelope handed over is the SAME `vsEnv` bytes the
                        // vertex stage above was translated from, so no second copy
                        // of the guest's bytes exists; ApplyInterpolatorIntersection
                        // parses it inside the translator and, if it will not parse,
                        // falls back to mask 0 rather than to an invented pairing.
                        mcla::renderer::TranslatedShader psOut;
                        pipeTrStage = "ps";
                        // THE PAIRED VERTEX SHADER, which is a different thing from
                        // the layout above and does not replace it. See the block
                        // comment that follows this call.
                        mcla::renderer::PixelShaderPairing psPairing;
                        psPairing.vsContainer = vsEnv.data();
                        psPairing.vsContainerSize = vsEnv.size();
                        psPairing.psNumReg = ReadPsNumRegField();
                        if (!mcla::renderer::TranslateShaderPinned(
                                psEnv.data(), psEnv.size(), nullptr, 0, psOut,
                                pipeTranslateError, &psPairing)) {
                            pipeStop = "ps-translate-refused";
                            pipeRow();
                            refuse("no-translated-pso", s_cpRefuseNoPso,
                                   "- TranslateShaderPinned refused the pixel "
                                   "shader. See DRAW-CP-PIPE. NOT drawn on a "
                                   "default shader.");
                            break;
                        }
                        s_pipeTranslatedPs.fetch_add(1, std::memory_order_relaxed);
                        // HOISTED HERE, for the same reason and with the same
                        // consequence as the VS pair above: the assignments sat
                        // BELOW the `empty-hlsl` break, so a `stop=empty-hlsl`
                        // row printed `vsHlsl=0 psHlsl=0` for two stages that had
                        // both translated, and the reader could not tell "no
                                        // HLSL" from "the row was written first".
                        pipePsHlsl = psOut.hlsl;
                        pipePsHash = psOut.programHash;
                        if (vsOut.hlsl.empty() || psOut.hlsl.empty()) {
                            pipeStop = "empty-hlsl";
                            pipeRow();
                            refuse("no-translated-pso", s_cpRefuseNoPso,
                                   "- a stage translated but produced no HLSL. See "
                                   "DRAW-CP-PIPE. NOT drawn on empty source.");
                            break;
                        }
                        // The four assignments that used to live here are
                        // GONE, hoisted to the two `fetch_add`s above. They are
                        // not deleted, they are read at the right time.
                    }

                    // GATE D -- the key and the PSO.
                    //
                    // ComputePipelineKeyForLayout, NOT ComputePipelineKey: GetOrCompile
                    // re-hashes the layout it is handed and refuses a key whose
                    // inputLayoutHash disagrees (pipeline_cache.cpp:2209-2213), so
                    // folding the layout in here is what keeps the key from claiming
                    // one declaration and handing the worker another.
                    //
                    // The sixth argument is the CARRIED geometry-stage capability
                    // (pipeline_cache.h, GetOrCompile). It is false on any cache
                    // miss, which is the point: the fallback PSO has no stage, and a
                    // rectangle draw mapped to TRIANGLELIST against it would draw one
                    // of the rectangle's two triangles. Reading the DEVICE's
                    // capability instead would be true on every draw, because the
                    // device is measured capable (0xB000/11.0, F-653), and would
                    // therefore be the F-609 fake.
                    {
                        const mcla::renderer::PipelineKey key =
                            mcla::renderer::ComputePipelineKeyForLayout(
                                pipeVsHash, pipePsHash, inputDeclHash, derived,
                                inputLayout);
                        s_pipePsoRequested.fetch_add(1, std::memory_order_relaxed);
                        pipePso = backend_.GetPipelineCache().GetOrCompile(
                            key, pipeVsHlsl, pipePsHlsl, inputLayout,
                            "render_thread.cpp:F-716", &pipeHasGeomStage);
                        if (!pipePso) {
                            pipeStop = "pso-refused";
                            pipeRow();
                            s_pipePsoNull.fetch_add(1, std::memory_order_relaxed);
                            s_cpRefuseNoPso.fetch_add(1, std::memory_order_relaxed);
                            refuse("no-translated-pso", s_cpRefuseNoPso,
                                   "- the key was built from the guest's own "
                                   "translated shaders and input layout and "
                                   "GetOrCompile returned null, so its own refusal "
                                   "counters and names are the authority. NOT drawn "
                                   "on the fallback: that PSO has no geometry stage "
                                   "and no guest layout.");
                            break;
                        }
                        if (pipeHasGeomStage) {
                            s_pipePsoCarriesGeomStage.fetch_add(1,
                                                                std::memory_order_relaxed);
                        }
                    }
                }
            }

            // F-648: desc.topology, ASSIGNED. F-637 added the field to
            // DynamicMeshDesc (src/d3d12_backend.h:101) and F-650 added the
            // backend's UNDEFINED refusal that named this file as the cause
            // (src/d3d12_backend.cpp:2596-2619, citing render_thread.cpp:1253),
            // but nothing here ever assigned it: the `desc = {}` zero-initialises
            // it, and a D3D_PRIMITIVE_TOPOLOGY of 0 is UNDEFINED. So every
            // captured draw reached the backend as "the producer never set a
            // topology" and the guest's real prim_type was discarded - exactly
            // what this call fixes.
            //
            // MapXenosPrimType is the architected map, written out per code
            // against xenos::PrimitiveType (xenos.h:44-59) rather than as an
            // offset into an array (src/d3d12_backend.cpp:265-319). It refuses
            // every prim_type D3D12 has no equivalent for and counts each one
            // per prim_type, so calling it is what MAKES the refusal counter
            // able to see the guest's primitive type at all.
            //
            // F-716: the THIRD ARGUMENT IS THE CARRIED GEOMETRY-STAGE FACT, and
            // this call is the only reason it exists. `pipeHasGeomStage` came out
            // of GetOrCompile (pipeline_cache.h), which can only set it on a cache
            // hit whose key named the expansion stage -- so it means "the PSO this
            // draw is about to use HAS the stage bound". Passing
            // `GeometryStageSupported()` here instead would be true on every
            // draw, because the device IS capable (0xB000/11.0, F-653), and would
            // map every rectangle list to TRIANGLELIST including the ones about to
            // be drawn against the GS-less cache fallback: half a quad per
            // rectangle with nothing in the log saying so. That is the F-609 fake
            // this call is built to make impossible, and it is why the flag is
            // CARRIED per-draw rather than read from a device-wide property.
            if (!D3D12Backend::MapXenosPrimType(dc.primitiveTopology,
                                                 desc.topology,
                                                 pipeHasGeomStage)) {
                // F-648: 0x08 kRectangleList is the case that matters here, so it
                // gets its own counter instead of hiding in the fallthrough.
                //
                // THE DECISION IS A REFUSAL, not an expansion, and F-652 re-
                // examined all three prerequisites this comment used to list as
                // undecoded. Two are DECODED and one is still BLOCKING. Recording
                // that here rather than in a session note, because "we tried" is
                // not evidence and the next stream must not re-derive it.
                //
                // (a) PIXEL-CENTRE CONVENTION - DECODED: there is no host-side
                //     pixel-centre offset in the expansion AT ALL. The complete
                //     rectangle rule is the D3D12 geometry-shader fallback,
                //     .research/xenia/src/xenia/gpu/d3d12/pipeline_cache.cc:2550-
                //     2694, and every arithmetic term in it (:2579-2595 edge
                //     squares, :2669-2674 the fourth corner) is a plain float
                //     add of vertex positions with no 0.5 and no PA_SU_VTX_CNTL
                //     term. `grep half_pixel` over primitive_processor.cc and the
                //     rectangle-list paths in both pipeline caches returns hits
                //     only in the EDRAM-resolve code (draw_util.cc:344, :842-849,
                //     :1098-1103, the resolve.xesli shaders), which is a
                //     different feature. The half-pixel offset the old comment
                //     cited is xenos.h:934-939 describing what the GUEST's OWN
                //     vertex shader applies ("with the half-pixel offset ...
                //     pre-applied to the vertices"), not something the emulator
                //     adds. So this prerequisite is settled and it is settled
                //     AGAINST adding an offset.
                //
                // (b) VERTEX-FETCH ENDIANNESS - DECODED, CARRIED AND NOW
                //     APPLIED. The slot's `endian` is `xe_gpu_vertex_fetch_t`'s
                //     2-bit field (xenos.h:1122), read by this file's own working
                //     decode at src/gpu_cp.cpp:1705 (and :1735, the by-index
                //     reader). 2026-10-04: this cited :1056, which is inside
                //     CpRegPoke and carries no `s.endian =`; re-measured, the two
                //     lines above are the only ones. The index-side byte-order
                //     model is the same shape (render_thread.cpp
                //     XenosIndexElement / TranscodeXenosIndices, :363-398), and
                //     the vertex side now matches it: F-751 added
                //     CpVertexElement::endianness to src/render_queue.h and the
                //     DRAW_CAPTURED path now applies xenos::GpuSwap to every
                //     dword of the stream it reads.
                //
                //     THE "IT IS MOOT" SENTENCE THAT STOOD HERE WAS WRONG, AND
                //     IT WAS WRONG IN A MEASURABLE WAY. It read "It is moot for
                //     the corner rule anyway, for the reason in (c): the
                //     positions are not vertex-buffer bytes." The second clause
                //     is false: the positions ARE vertex-buffer bytes on this
                //     path. The backend's own probe reads the float lanes
                //     straight out of the stream this file hands it -
                //     `memcpy(&f, vp + l * 4u, 4)` at src/d3d12_backend.cpp:2975,
                //     over `desc.vertexBytes`, which is the very buffer
                //     `ReadBytes` filled above - and MEASURED in build/w708.log
                //     it printed v0lane0Bits=0x000000BF,0x000000BF where the
                //     architected reading is 0xBF000000 = -0.5. So (c)'s own
                //     premise is what (b) was reasoning from, and (c) is about
                //     WHICH LANE is position and whether it is PRE- or POST- the
                //     vertex shader - a different question from what byte order
                //     the lanes arrive in. Leaving (b) unresolved did not make
                //     it moot; it left a real transform unmade on the path that
                //     reaches the rasterizer.
                //
                // (c) WHICH ELEMENT IS POSITION - STILL BLOCKING, and it is not
                //     a gap in the vertex fetch. The reference computes the
                //     fourth corner from the POST-VERTEX-SHADER position:
                //     d3d12/pipeline_cache.cc:2579-2582 reads
                //     `V2D(2, input_register_position, ...)` and :2636-2637
                //     emits `O(output_register_position)` from
                //     `V2D(input_vertex_index, input_register_position)` - i.e.
                //     a GEOMETRY-SHADER input, the guest VS's own output. The
                //     longest-edge test (:2597-2622) is on those transformed
                //     values too, precisely so the expansion stays correct under
                //     an arbitrary VS transform (the same concern the triangle-
                //     fan comment at primitive_processor.h:536-543 raises).
                //     Producing them on the CPU means EXECUTING the guest vertex
                //     shader, and this is a static recompiler - there is no
                //     interpreter, and the alternative (folding the rule into the
                //     translated shader) is src/renderer/**, which another stream
                //     owns and is mid-edit.
                //     The reference agrees this is unimplemented: its own SPIR-V
                //     translator carries the TODO at
                //     spirv_shader_translator.cc:1322-1323 ("For
                //     HostVertexShaderType::kRectangeListAsTriangleStrip, start
                //     the vertex loop, and load the index there"), and
                //     dxbc_shader_translator.cc:630-634 takes the whole type to
                //     assert_unhandled_case. Only the D3D12 GS fallback above
                //     implements it.
                //
                // So it is refused by name, with the blocker named, rather than
                // half-implemented: a CPU expansion that computed v1+v2-v0 over
                // UNTRANSFORMED vertex bytes would produce parallelograms for
                // every rectangle whose VS moves a corner, which is sheared
                // quads - strictly worse than the blank below. WHAT THE GAME
                // EXPERIENCES: these draws produce NO pixels, where before they
                // produced half of every quad with nothing in the log saying so.
                // prim-rect-list= on DRAW-CP-CENSUS and rectList(expanded=0
                // refused=N) on PC-DERIVE are both non-zero, so the gate is
                // visible and countable rather than inferred.
                if (dc.primitiveTopology == 0x08u) {
                    refuse("prim-rect-list", s_cpRefusePrimRect,
                           "- xenos::PrimitiveType::kRectangleList (xenos.h:53): 3 "
                             "vertices per rectangle, expanded by the reference to a "
                             "two-triangle strip IN THE VERTEX SHADER "
                             "(primitive_processor.cc:392-398, :449-457). NOT "
                             "substituted with a triangle list, which would draw one "
                             "of the rectangle's two triangles.");
                } else {
                    refuse("prim-unmappable", s_cpRefusePrimOther,
                           "- D3D12 has no topology for this Xenos prim_type; see "
                             "MapXenosPrimType (src/d3d12_backend.cpp:265-319).");
                }
                break;
            }
            s_cpTopologyAssigned.fetch_add(1, std::memory_order_relaxed);

            // B4 (T41.4b), same fix as DRAW_INDEXED: DrawDynamicMesh already
            // closes, executes, presents and advances the frame index
            // (src/d3d12_backend.cpp:1487-1504). The ClearAndPresent() that
            // used to follow was a SECOND present of the same frame whose first
            // act is ClearRenderTargetView — it erased the draw that had just
            // rendered. One present per drawn frame, owned by the draw path.
            // 2026-10-02: WHAT THIS DRAW ACTUALLY DID, as a row of its own.
            //
            // HISTORY OF THE SENTENCE BELOW, because it described the defect
            // rather than the fix and would now be false: "`DRAW-CP-DRAWN`
            // counts commands that REACHED this site. It does not count draws,
            // and the difference is the whole measurement problem." That was
            // TRUE of the tree this file was last compiled against and is NO
            // LONGER TRUE of it. `DRAW-CP-DRAWN` is now gated on the draw call
            // actually being recorded (the backend's own m_stats.drawsIssued
            // advancing across the call), and the commands-that-reached-the-
            // site count it used to carry has moved to its own row,
            // DRAW-CP-DRAWN-SKIPPED, on its own counter. The measurement
            // problem this paragraph was written about is the one the next
            // paragraph's evidence is for, and it is kept below as the record
            // of what was wrong.
            //
            // MEASURED on build/w696.log (sha256 3D21DE0E..7F1893,
            // 55,669 lines), which carries `DRAW-CP-DRAWN #1` at 03:30:04.948 and
            // `#2` at 03:30:04.961, and also carries:
            //   - `FRAME-OWNER owner=draw` ZERO times, so
            //     PresentOwnedFrame(FrameOwner::Draw) never ran;
            //   - `D3D12Backend: draw #N issued through a cache-produced PSO` ZERO
            //     times, so the body of DrawDynamicMeshWithPipeline never reached
            //     SetPipelineState;
            //   - the BACKEND's `CONST-BANK #n` ZERO times (the two
            //     CONST-BANK rows in that log are `CONST-BANK-PRODUCE`, the
            //     producer side -- a different marker, and matching its prefix
            //     would have been a false positive);
            //   - `DRAW-CP-PIPE` ZERO times. NOTE: the parenthetical claim that
            //     used to sit here -- "pipeStop reaches `drawn` and pipeRow() is
            //     called for it at the end of this case" -- was FALSE and is
            //     retracted. `pipeStop` is set to "drawn" only inside the
            //     `else if (pipePso)` arm, which is reached only when
            //     `beganFrame` is true, and the call at the end of this case is
            //     `if (std::strcmp(pipeStop, "drawn") == 0) pipeRow();`. So a
            //     BeginFrame refusal sets pipeStop to "begin-frame-false",
            //     pipeRow() is NOT called, and DRAW-CP-PIPE=0 is the CORRECT
            //     and EXPECTED consequence of a closed gate -- it is not
            //     independent evidence of a second fault.
            // Two readings of the rest are consistent with every line above, and
            // they are different faults: BeginFrame() returning false is a
            // completely different problem from a refusal inside the draw body.
            // As of 2026-10-02 this is no longer a choice between them on the
            // evidence: the backend names all five of its own exits
            // (D3D12-BEGINFRAME-REFUSE, one row per gate) and names every
            // abandoned frame (D3D12-FRAME-ABANDONED), so the next soak says
            // which one fired instead of leaving the two to be told apart by
            // absence. This row reports the outcome plus the draw's own return
            // value, which the call below used to DISCARD -- a draw that
            // returned false and a draw that rendered were the same two lines.
            // 2026-10-02: hoisted out of the block below so that DRAW-CP-DRAWN,
            // which sits ~80 lines further down and outside that block, can gate
            // on the same fact instead of on a second, weaker guess. Declared
            // here and assigned inside; both are single-threaded with respect to
            // the backend (this is the render thread, the only consumer).
            uint64_t cpDrawCallsBefore = backend_.Stats().drawsIssued;
            bool cpIssuedDrawCall = false;
            {
                const bool beganFrame = backend_.BeginFrame();
                // 2026-10-02: `drew` is the backend's own return value, and it
                // is NOT the same fact as "a draw call was issued". The backend
                // increments m_stats.drawsIssued at exactly one place -- right
                // after DrawIndexedInstanced/DrawInstanced -- so reading it
                // across this call measures whether the draw call was RECORDED,
                // independently of whether the present at the end of the frame
                // then succeeded. Both are reported: `drew` is what the caller
                // got, `cpIssuedDrawCall` is what the GPU was handed.
                const bool drew =
                    beganFrame
                        ? backend_.DrawDynamicMeshWithPipeline(desc, pipePso.Get())
                        : false;
                cpIssuedDrawCall =
                    beganFrame && (backend_.Stats().drawsIssued != cpDrawCallsBefore);
                if (!beganFrame) {
                    // Named, not defaulted. The backend's own row for this is
                    // D3D12-BEGINFRAME-REFUSE, which now says WHICH of its five
                    // exits fired; this is the producer-side half.
                    pipeStop = "begin-frame-false";
                } else if (cpIssuedDrawCall) {
                    // "drawn" is now gated on the draw call having been issued,
                    // not merely on the gate being open. Before this it was set
                    // whenever `beganFrame && pipePso`, so it too could report a
                    // frame as drawn that recorded no draw call -- the same lie
                    // as DRAW-CP-DRAWN, one level up, and it is what made
                    // DRAW-CP-PIPE reachable at all on a closed gate.
                    pipeStop = "drawn";
                } else {
                    // Reached when the gate opened but the draw body refused
                    // before the draw call: D3D12-DRAW-RETURN names which gate.
                    pipeStop = pipePso ? "draw-refused" : "no-pso-at-draw";
                    pipeRow();
                }
                // The new marker. `colorFormatCode` is the guest's own
                // RB_COLOR_INFO colour_format and `colorFormatDxgi` is what it
                // mapped to -- which is exactly what the PSO's RTVFormats[0] and
                // NumRenderTargets were computed from
                // (renderer/pipeline_cache.cpp:1921-1945). It is printed here
                // because the value is otherwise consumed and discarded inside
                // the derivation; this is the only site that can put it next to
                // D3D12-RTV-FORMAT, the format of the render target really bound.
                // 0xFFFFFFFF = RB_COLOR_INFO was never presented. Code 0 is
                // k_8_8_8_8, which is PRESENT and legal, not an absence.
                const uint32_t in = s_cpIssuedLogged.fetch_add(
                                        1, std::memory_order_relaxed) + 1u;
                if (in <= 8u || (in % 200u) == 0u) {
                    MCLA_LOG_WARN(
                        "DRAW-CP-ISSUED #{} draw={} beginFrame={} drawCall={} "
                        "returned={} pso={} | colorFormatCode={} "
                        "colorFormatDxgi={} rsPresent={:08X} -- "
                        "colorFormatDxgi is what the PSO's RTVFormats[0] was "
                        "built from; compare it with D3D12-RTV-FORMAT, the "
                        "format of the render target actually bound. A "
                        "disagreement rasterizes nothing without an error.",
                        in, n, beganFrame ? 1 : 0,
                        (beganFrame && pipePso) ? 1 : 0, drew ? 1 : 0,
                        pipePso ? 1u : 0u, pipeColorFormatCode,
                        pipeColorFormatDxgi, pipeRsPresent);
                }
                // 2026-10-02: THE COMPARISON, IN ONE ROW. P5 could not be
                // satisfied by D3D12-RTV-FORMAT alone and the reason is
                // structural, not an oversight: a D3D12 pipeline state does not
                // report its own RTVFormats[] -- there is no reflection getter
                // for it -- so the PSO side is knowable ONLY here, where the
                // guest's colour_format was mapped, and the bound side is
                // knowable ONLY in the backend, which read it off the bound
                // resource's D3D12_RESOURCE_DESC. Two rows in two translation
                // units, never adjacent. This row is that comparison, and it is
                // NEW: it appends to nothing and renames nothing, because
                // DRAW-CP-ISSUED's format is one of the 244 tracked and
                // changing it is forbidden.
                //
                // `bound=0` means the backend has not bound a render target yet,
                // which on a closed gate is the expected reading and not a
                // format: the bind site is downstream of BeginFrame(). `agree`
                // is therefore only claimed when BOTH numbers are real, and a
                // disagreement is printed as a disagreement rather than left for
                // a reader to subtract two numbers from two different rows.
                const uint32_t boundRtvDxgi = backend_.BoundRtvFormat();
                if (in <= 8u || (in % 200u) == 0u) {
                    MCLA_LOG_WARN(
                        "CP-COLORFMT-VSRTV #{} draw={} psoRtvDxgi={} boundRtvDxgi={} "
                        "agree={} boundSet={} colorFormatCode={} | psoRtvDxgi is "
                        "MapXenosColorFormatToDxgi(colorFormatCode) -- the value "
                        "renderer/pipeline_cache.cpp put in RTVFormats[0]; "
                        "boundRtvDxgi is the backend's D3D12-RTV-FORMAT value, "
                        "read off the bound back buffer's own descriptor. "
                        "boundSet=0 means no render target has been bound yet, so "
                        "no comparison is possible and agree is reported 0, NOT as "
                        "a match. psoRtvDxgi=28 is R8G8B8A8_UNORM.",
                        in, n, pipeColorFormatDxgi, boundRtvDxgi,
                        (boundRtvDxgi != 0 && boundRtvDxgi == pipeColorFormatDxgi)
                            ? 1 : 0,
                        (boundRtvDxgi != 0) ? 1u : 0u, pipeColorFormatCode);
                }
            }
            // ------------------------------------------------------------------
            // HISTORY OF THE BLOCK THAT JUST MOVED ABOVE, kept whole because two
            // of its claims were wrong and cost a previous stream a re-do of
            // F-653. It is COMMENT ONLY: the `if (backend_.BeginFrame())` that
            // wrapped it is gone, because the call it guarded now happens once,
            // above, with its result kept. Nothing below this line executes.
            //
            // THE OLD SHAPE was
            //     if (backend_.BeginFrame()) {
            //         if (pipePso) { backend_.DrawDynamicMeshWithPipeline(desc,
            //                                            pipePso.Get());
            //                        pipeStop = "drawn"; }
            //         else { pipeStop = "no-pso-at-draw"; pipeRow(); }
            //     }
            //     const uint32_t dn = s_cpDrawn.fetch_add(1) + 1;
            // i.e. `DRAW-CP-DRAWN` was incremented and logged whether or not the
            // body ran. That is the defect measured in build/w696.log: the row
            // reads as a closed draw chain and no row anywhere says a draw call
            // was made.
            //
            // THE HISTORY, because the previous version of this comment was
                // wrong and would have misled the next agent into re-doing F-653.
                // It claimed that `DrawDynamicMesh` hard-passed the test PSO, that
                // the hard pass was the `m_testPipeline.Get()` argument, and that
                // the second fallback at d3d12_backend.cpp:2801 still had to be
                // deleted. All three were already false in the tree this file was
                // last compiled against: F-653 rewrote that entry point so it
                // REFUSES instead of forwarding (d3d12_backend.cpp:2622-2634) and
                // deleted the `pipeline ? pipeline : m_testPipeline.Get()` line
                // (it survives only as history at d3d12_backend.cpp:2920-2922;
                // :2801 is now `if (desc.indexed && !desc.cachedIndexGpu)`). The
                // 28-byte stride gate this comment cited at :2554-2557 also moved
                // to :2674-2698, where it fires only for a test PSO the caller
                // passed deliberately.
                //
                // So the backend is no longer what protects this line - the gate
                // is. `no-translated-pso` above ends the draw with a `break`, and
                // that is the only thing standing between a derived rasteriser
                // with no PSO and a draw call. It was measured, not assumed: in
                // build/w682.log that gate did NOT break, fell through to the
                // primitive mapper, and on any prim_type other than 0x08 it would
                // have carried on to this call.
                //
                // F-716: WHAT IS STILL MISSING IS NOT IN THIS FILE, AND IT IS NOW
                // NAMED BY A MEASUREMENT INSTEAD OF A HOPE. The old text here said
                // "wiring this call site to DrawDynamicMeshWithPipeline(desc,
                // realPso.Get()) needs translated HLSL plus an input layout from
                // the guest's own program, which is src/renderer/** - owned
                // elsewhere". That was half right and half wrong: the HLSL needs no
                // ownership change at all (TranslateShaderPinned is already in the
                // tree and is called from the chain above), and the input layout is
                // NOT an src/renderer/** problem. It is that an EMBEDDED program
                // carries no vertex-element table -- the reference does not keep
                // one either, taking vertex elements from the vertex-FETCH hardware
                // and the interpolant set from SQ_INTERPOLATOR_CNTL
                // (d3d12/pipeline_cache.cc:882, :915) -- so with
                // `vertexElements` empty every semantic ReferencedVertexInputs can
                // return is its own POSITION fallback (shader_translator.cpp:68-78).
                // The blockers are therefore two CAPTURES, in files this stream
                // does not own: the vfetch `dst_reg` (which would give the element
                // address to match, and gpu_cp.cpp:1352 states its omission as
                // deliberate) and the vf->DXGI table for elements past the first
                // (inline in gpu_cp.cpp as F-632, not exported). Neither is in the
                // renderer, and neither is a translation problem.
                //
            // The call is the WithPipeline overload, on the PSO the chain
            // above actually obtained. The no-pipeline `DrawDynamicMesh` is
            // NEVER called from here again: it refuses by design (F-653,
            // d3d12_backend.cpp:2622-2634), and leaving it as the tail would
            // make this a counted absence rather than a drawn frame.
            //
            // END OF HISTORY. The live call is the block above this comment.
            // ------------------------------------------------------------------
            // 2026-10-02: THIS MARKER WAS A LIE AND NO LONGER IS.
            //
            // `s_cpDrawn` was incremented UNCONDITIONALLY here, outside the
            // BeginFrame gate, so it counted commands that REACHED this site
            // rather than draws that happened. MEASURED on build/w698.log: two
            // DRAW-CP-DRAWN rows and zero PC-PSO-BOUND, zero
            // D3D12-DRAW-RETURN, zero `D3D12Backend: draw #N issued through a
            // cache-produced PSO` and zero `FRAME-OWNER owner=draw` -- i.e. two
            // rows reading as a closed draw chain for two frames in which no
            // draw call was recorded. The same counter is what
            // DRAW-CP-CENSUS prints as `drawn=`, so that field was lying too,
            // with the same mechanism and the same fix.
            //
            // WHY THIS AND NOT A RENAME. Two options were available: move the
            // increment inside the gate, or rename/retarget the row. Renaming
            // is not available -- `DRAW-CP-DRAWN` is one of the 244 markers
            // tools/soak_census.py tracks, and its format literal
            // ("DRAW-CP-DRAWN #{} prim={} ...") may not be changed, and the
            // marker name IS part of that literal. So the row keeps its name and
            // its format and becomes TRUE instead: the gate is
            // `cpIssuedDrawCall`, which is the backend's own
            // m_stats.drawsIssued having advanced across the draw call, i.e. the
            // draw call was recorded into the command list. A weaker gate
            // (`beganFrame`) was rejected for the same reason the old
            // unconditional increment was: it would still report "drawn" for a
            // frame whose body refused at D3D12-DRAW-RETURN before
            // DrawInstanced.
            //
            // NOTHING BECOMES ABSENT. The count this used to carry -- commands
            // that reached this site and did NOT become a draw call -- is now
            // its own row, DRAW-CP-DRAWN-SKIPPED below, on its own counter, so
            // "the draw was refused" and "the draw was never attempted" stay
            // two different numbers and neither is lost.
            if (cpIssuedDrawCall) {
                const uint32_t dn =
                    s_cpDrawn.fetch_add(1, std::memory_order_relaxed) + 1;
                if (dn <= 8 || (dn % 200) == 0)
                    // F-633: tc.count / tc.maxIndex are the static transcode
                    // buffer's previous contents on a non-indexed draw - nothing
                    // wrote them - so they are reported as the guest's own
                    // numbers instead of a stale value from an earlier kDMA draw.
                    MCLA_LOG_INFO("DRAW-CP-DRAWN #{} prim={} topo={} vertices={} "
                                  "indexed={} indices={} maxIndex={} fmt=vf{}:dxgi{}:{}B "
                                  "stride={} descs={}/{}",
                                  dn, dc.primitiveTopology,
                                  static_cast<uint32_t>(desc.topology), vertexCount,
                                  indexed ? 1u : 0u, indexed ? tc.count : 0u,
                                  indexed ? tc.maxIndex : 0u, dc.vbFormat.xenos,
                                  dc.vbFormat.dxgi, dc.vbFormat.bytes, dc.vbStride,
                                  dc.vbFullCount, dc.vbDescCount);
            } else {
                // The new row. `pipeStop` is the reason, taken from the same
                // string DRAW-CP-PIPE prints, so the two can be read together
                // without a lookup table. begin-frame-false means the gate never
                // opened -- the backend's D3D12-BEGINFRAME-REFUSE row names
                // which of its five exits -- and draw-refused means the gate
                // opened and the draw body refused, which
                // D3D12-DRAW-RETURN names.
                const uint32_t sk =
                    s_cpDrawnSkipped.fetch_add(1, std::memory_order_relaxed) + 1;
                if (sk <= 8 || (sk % 200) == 0) {
                    MCLA_LOG_WARN(
                        "DRAW-CP-DRAWN-SKIPPED #{} draw={} stop={} beganFrame={} "
                        "issuedDrawCall=0 pso={} drawnTotal={} | this command "
                        "reached the draw site and NO draw call was recorded, so "
                        "it is deliberately NOT counted in DRAW-CP-DRAWN and NOT "
                        "in DRAW-CP-CENSUS drawn=. stop=begin-frame-false is the "
                        "backend gate (D3D12-BEGINFRAME-REFUSE names which exit); "
                        "stop=draw-refused is inside the draw body "
                        "(D3D12-DRAW-RETURN names which gate); "
                        "stop=no-pso-at-draw means there was no PSO to draw with.",
                        sk, n, pipeStop, cpIssuedDrawCall ? 1 : 0,
                        pipePso ? 1u : 0u,
                        s_cpDrawn.load(std::memory_order_relaxed));
                }
            }
            if (std::strcmp(pipeStop, "drawn") == 0) pipeRow();
            // ------------------------------------------------------------------
            // F-725: THE POST-DRAW PIXEL SAMPLE. This is where a framebuffer
            // sample belongs, and it is not inside RenderCommand::PRESENT.
            //
            // MEASURED on build/w699.log: both `PRESENT-FB sample` rows are
            // timestamped 05:28:28.187 and .188, the two `DRAW-CP-DRAWN` rows
            // are .209 and .221. Every sample in that log predates every draw,
            // by 21 ms and 33 ms. It is not a sampling accident: PRESENT-FB is
            // emitted from inside `case RenderCommand::PRESENT` and only when
            // blitVA != 0, and it reads the GUEST's linear surface
            // (va=B96EF2C0) -- a buffer the host's draw never writes. So the
            // sample is in the wrong place in the pipeline (a present, not a
            // draw) AND on the wrong surface (guest memory, not the back
            // buffer), and both had to change before the measurement could mean
            // anything. PRESENT-FB is left exactly where it is: it measures the
            // guest's own framebuffer, which is a different and still-useful
            // fact, and moving it would change the format of a tracked marker.
            //
            // What this row adds is a sample of the surface the draw actually
            // wrote, timed AFTER the DRAW-CP-DRAWN row above. The values come
            // from the backend's own readback (D3D12-DRAW-PIXEL), which copies
            // the back buffer into a D3D12_HEAP_TYPE_READBACK heap buffer and
            // Maps it -- a READBACK heap resource is mappable by definition,
            // which is the one property every other heap type refuses.
            //
            // NEW ROW NAME. `DRAW-CP-PIXEL` occurs 0 times in this file's MCLA_LOG
            // literals and 0 times in build/w699.log, so nothing is appended to
            // and nothing is renamed. The gate is the backend's own
            // RenderThreadPixelsValid(), which is false until a readback has
            // completed: a caller that reaches here before the first readback
            // prints nothing rather than a default-initialised zero.
            if (backend_.RenderThreadPixelsValid()) {
                static std::atomic<uint32_t> pixelRow{0};
                const uint32_t prn = pixelRow.fetch_add(1, std::memory_order_relaxed) + 1u;
                if (prn <= 8u || (prn % 200u) == 0u) {
                    MCLA_LOG_WARN(
                        "DRAW-CP-PIXEL #{} draw={} rgba=({},{},{},{}) at ({},{}) "
                        "rowPitch={} | nonBlack={}/{} ({:.4f}%) maxChannel={} "
                        "meanChannel={:.4f} readbacks={} -- a sample of the "
                        "surface THIS draw wrote, timestamped after DRAW-CP-DRAWN. "
                        "PRESENT-FB samples the guest's linear surface at present "
                        "time and, in build/w699.log, every one of its rows "
                        "predated every draw; this one cannot. Read the value, not "
                        "the presence of the row: rgba is a single probe at the "
                        "viewport centre, and rgb=0,0,0 with alpha=255 is a real "
                        "black frame, not a missing sample. Pair with "
                        "D3D12-DRAW-PIXEL, which is the same measurement one layer "
                        "down where the copy and the Map happen.",
                        prn, n, backend_.RenderThreadPixelR(), backend_.RenderThreadPixelG(),
                        backend_.RenderThreadPixelB(), backend_.RenderThreadPixelA(),
                        backend_.RenderThreadPixelX(), backend_.RenderThreadPixelY(),
                        backend_.RenderThreadPixelRowPitch(),
                        backend_.RenderThreadNonBlackPixels(),
                        backend_.RenderPixelCensusTotal(),
                        backend_.RenderPixelCensusTotal()
                            ? (100.0 * static_cast<double>(backend_.RenderThreadNonBlackPixels()) /
                               static_cast<double>(backend_.RenderPixelCensusTotal()))
                            : 0.0,
                        backend_.RenderThreadMaxChannel(),
                        backend_.RenderThreadMeanChannel(),
                        backend_.DrawReadbackCompletions());
                }
            }
            break;
        }
        case RenderCommand::DRAW_MARKER: {
            if (!d3d12Initialized_) break;
            const auto& mk = std::get<DrawMarkerCommand>(cmd.data);
            static std::atomic<uint32_t> markerCount{0};
            const uint32_t n = markerCount.fetch_add(1) + 1;
            if (n <= 10 || (n % 500) == 0)
                MCLA_LOG_INFO("RenderThread: DRAW-MARKER #{} seq={} prim={} numIdx={}",
                              n, mk.seq, mk.prim, mk.numIdx);

            // Synthetic quad on a 40x23 grid, ~2% cells, hue by seq. Test
            // layout (POS float3 + COL float4, stride 28) so the test PSO
            // accepts it. No clear after (T41.8 defect class); no guest
            // memory touched - SYNTHETIC pipe proof, see DrawMarkerCommand.
            struct MarkerVertex { float pos[3]; float color[4]; };
            const float gx = static_cast<float>(mk.seq % 40u) / 40.0f * 2.0f - 1.0f;
            const float gy = static_cast<float>((mk.seq / 40u) % 23u) / 23.0f * 2.0f - 1.0f;
            const float s = 0.018f;
            const float h = static_cast<float>(mk.seq % 7u) / 7.0f;
            const MarkerVertex verts[4] = {
                { { gx - s, gy - s, 0.0f }, { h, 1.0f - h, 0.35f, 1.0f } },
                { { gx + s, gy - s, 0.0f }, { 1.0f - h, h, 0.35f, 1.0f } },
                { { gx + s, gy + s, 0.0f }, { 0.35f, h, 1.0f - h, 1.0f } },
                { { gx - s, gy + s, 0.0f }, { h, 0.35f, 1.0f - h, 1.0f } },
            };
            static const uint16_t quadIdx[6] = { 0, 1, 2, 0, 2, 3 };

            D3D12Backend::DynamicMeshDesc desc = {};
            desc.vertexBytes = verts;
            desc.vertexBytesSize = sizeof(verts);
            desc.vertexStride = sizeof(MarkerVertex);
            desc.vertexCount = 4;
            desc.indexed = true;
            desc.indexBytes = quadIdx;
            desc.indexBytesSize = sizeof(quadIdx);
            desc.indexFormat = DXGI_FORMAT_R16_UINT;
            desc.indexCount = 6;

            // F-725: this BeginFrame() and AbandonFrame() pair is REMOVED, and the
            // measurement for removing them is that neither call has an effect
            // this path can use.
            //
            // DrawDynamicMesh (d3d12_backend.cpp:2704, F-653) REFUSES every
            // call: its whole body is `(void)desc; ++m_noPipelineBypassRefusals;
            // ... return false;`. It touches no frame state at all -- not
            // m_inFrame, not m_frameIndex, not m_stats, not the command list.
            // So BeginFrame() opened a frame that DrawDynamicMesh had no use
            // for, and AbandonFrame() closed it again. That pair is what
            // produced `owner=draw-marker` on 8 printed
            // D3D12-FRAME-ABANDONED rows in build/w699.log, with
            // `beganFrame` climbing one per marker and `presented` unchanged.
            //
            // The refusal itself is KEPT and is still counted, which is the
            // whole point of DRAW-MARKER: `RenderThread: DRAW-MARKER #{}` above
            // still reports every marker that arrives, and
            // `D3D12Backend: DrawDynamicMesh refused #{}` still counts them.
            // What is gone is the frame bookkeeping around a call that cannot
            // use it.
            //
            // MEASURED consequence of keeping it: on w699.log the first
            // draw-marker abandon is #1 at 05:28:27.398 and the refusal of the
            // NEXT BeginFrame on `already-in-frame` is a real gate this path can
            // trip. See the abandon-loop census below for the numbers.
            backend_.DrawDynamicMesh(desc);
            break;
        }
        case RenderCommand::RESIZE: {
            if (!d3d12Initialized_) break;
            const auto& r = std::get<ResizeCommand>(cmd.data);
            MCLA_LOG_INFO("RenderThread: RESIZE {}x{}", r.width, r.height);
            backend_.Resize(r.width, r.height);
            break;
        }
        case RenderCommand::SET_VERTEX_BUFFERS:
        case RenderCommand::SET_INDEX_BUFFER:
        case RenderCommand::NOOP:
            break;
    }
}

} // namespace mcla::native
