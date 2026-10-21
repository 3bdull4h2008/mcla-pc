#include "native_renderer.h"
#include "renderer_hook_dispatch.h"
#include "renderer_mode.h"
#include "capture_hooks.h"
#include "frame_trace.h"
#include "d3d12_backend.h"
#include "patches.h"
#include "app.h"
#include "logging.h"
#include "guest_memory.h"
#include "kernel/memory.h"
#include "kernel/heap_arena.h"  // F-640: the pool's own bounds, to tell the 4 MiB overlap from a miss
#include "boot_host.h"          // F-640: TranslatePhysViewToPoolVa / RegisterPhysAliasWriter / LogPhysAliasRow
#include "gpu_mmio.h"
#include "gpu_device.h"
#include "gpu_cp.h"          // F-XXX: CpGuestRenderTargetInfo (RB_COPY_DEST_BASE) + CpEmitXeSwap
#include "render_queue.h"
#include "render_thread.h"
#include "generated/ppc_xenon/ppc_recomp_shared.h"
#include "renderer/shader_translator.h"
#include "renderer/pipeline_cache.h"
#include "renderer/xenos_shader_ir.h"
#include "renderer/vertex_decode.h"
#include "renderer/grc_fvf_decode.h"

#include <atomic>
#include <cassert>
#include <chrono>
#include <filesystem>
#include <string>
#include <thread>
#include <unordered_set>
#include <vector>

// w31: deep child census hook (defined in gpu_device.cpp).
void MclaW31OnPresent();

namespace mcla::native {

// Internal state
// (2026-09-09 S1–S3 consolidation: the old Hooked_GfxCmdBufSubmit /
// Hooked_Sub82420BA8 dual-owner hooks were removed. gpu_device.cpp's
// strong-alias overrides are now the SINGLE owner of 0x8241BD08 / 0x82420BA8
// and carry the RecordSubmit/RecordDrawBuild + submit-observer + trace-feed
// duties. Golden rule 1 restored.)
static PPCFunc* orig_Sub8241ABB8     = nullptr;

// Host-side frame trace driver - dead stub: no callers, constants below unused
static constexpr std::chrono::milliseconds kHostTraceWarmup{3000};
static constexpr std::chrono::milliseconds kHostTraceWindow{1500};

void StartHostFrameTrace() {
    MCLA_LOG_WARN("StartHostFrameTrace: not available in standalone mode (no legacy command processor)");
}

// Register file sync - no-ops (the live Xenos register file is gpu_cp.cpp's)
void WriteGpuContextToRegisterFile(::MclaGpuContext* gpuCtx) {
    (void)gpuCtx;
    // No register file lives here: gpu_cp.cpp owns the live one (g_xenosReg,
    // F-090). Sole caller patches.cpp:992 logs "seeded" - nothing is seeded.
}

void RestoreRegisterFileToContext(::MclaGpuContext* gpuCtx) {
    (void)gpuCtx;
    // No-op in standalone mode
}

void ForwardRegisterToBackend(uint32_t regIndex, uint32_t value) {
    (void)regIndex;
    (void)value;
    // No-op in standalone mode
}

// Hook: sub_8241ABB8 - SetViewport / SetRenderTargets state setup
PPC_FUNC_IMPL(Hooked_Sub8241ABB8) {
    mcla::renderer::RecordStateSetup();
    uint32_t ctx_guest   = ctx.r3.u32;
    uint32_t src_state   = ctx.r4.u32;

    if (ctx_guest && src_state) {
        GuestMemoryView& memView = GetDrawAccumulator()->GetMemoryView();
        if (!memView.IsValidRange(src_state, 128)) return;

        ::MclaGpuContext* gpuCtx = reinterpret_cast<::MclaGpuContext*>(base + ctx_guest);

        gpuCtx->rbSurfaceInfoP0 = PPC_LOAD_U32(src_state + 108);
        gpuCtx->rbSurfaceInfoP1 = PPC_LOAD_U32(src_state + 112);
        gpuCtx->rbSurfaceInfoP2 = PPC_LOAD_U32(src_state + 116);
        gpuCtx->rbSurfaceInfoP3 = PPC_LOAD_U32(src_state + 120);
        gpuCtx->rbSurfaceInfoP4 = PPC_LOAD_U32(src_state + 124);
        gpuCtx->rbSurfaceInfoP5 = PPC_LOAD_U32(src_state + 128);

        GetDrawAccumulator()->OnStateSetup(gpuCtx, src_state);
    }

    if (orig_Sub8241ABB8) {
        orig_Sub8241ABB8(ctx, base);
    }
}

// Native draw dispatch - dead stub (no callers); draws go via g_commandQueue
void IssueNativeDraw(::MclaGpuContext* gpuCtx) {
    (void)gpuCtx;
    MCLA_LOG_WARN("IssueNativeDraw: legacy command processor path not available in standalone mode");
}

// ---------------------------------------------------------------------------
// F-612 SURFACE-RESOLVER AUDIT (consumer side).
//
// The resolver lives in gpu_device.cpp:4002-4093 and picks the present surface
// by SCORING candidates (ScoreSurfacePixels, :4016) - it is a guess by
// construction, and gpu_device.cpp:4075 only logs when the WINNER CHANGES, so
// w654.log carries just 5 "PRESENT-SURF" lines for 4140+ presents and never
// says which candidate won. What those 5 lines do say is damning:
//
//   PRESENT-SURF resolved va=004E0D30 score=1  (was 5115184)
//   PRESENT-SURF resolved va=CB189B80 score=7  (was 3407387520)
//   PRESENT-SURF resolved va=CB18A300 score=12 (was 3407389440)
//
// score=1 is the CLAMP FLOOR (gpu_device.cpp:4039: `if (score == 0) score = 1`)
// and 0x004E0D30 is the VdSwap swap_info this file registers at :169 UNTRANSFORMED
// - a PHYSICAL address (gpu_cp.h:22-24 and PhysToKernelVA, gpu_cp.cpp:669, both
// say a value below 0x20000000 is physical and is published as pa|0xC0000000).
// So the first frame ever resolved a present surface to a physical address
// carrying the least possible information, purely because it was the only
// candidate present at that moment.
//
// This block does NOT replace the scorer. It re-derives the SAME metric on the
// consumer side, where the resolved value and the guest's own flip arguments
// are both in hand, and prints all of them side by side on the house cadence.
// The first real frame then says whether the score-based guess was right (the
// resolved VA scores high and its pixels vary) or wrong (it scores 0/1 while
// the kernel-VA form of the guest's own swap_info scores high). Same 16x16 grid
// and same arithmetic as gpu_device.cpp:4023-4041, so the numbers compare.
// ---------------------------------------------------------------------------
static uint32_t PresentSurfaceScore(uint32_t va, uint32_t w, uint32_t h) {
    if (va == 0 || w == 0 || h == 0) return 0;
    auto& mem = ::mcla::kernel::GuestMemoryHeap::Instance();
    constexpr uint32_t kGrid = 16;
    uint8_t pix[4];
    uint32_t distinct = 0, nonzero = 0, lastRGB = 0xFFFFFFFFu;
    for (uint32_t gy = 0; gy < kGrid; ++gy) {
        for (uint32_t gx = 0; gx < kGrid; ++gx) {
            const uint32_t sx = (gx * w) / kGrid;
            const uint32_t sy = (gy * h) / kGrid;
            const uint32_t off = (sy * w + sx) * 4;
            if (!mem.ReadBytes(va + off, pix, 4)) return 0;
            const uint32_t rgb = (uint32_t(pix[0]) << 16) | (uint32_t(pix[1]) << 8) | pix[2];
            if (rgb != 0) ++nonzero;
            if (rgb != lastRGB) { ++distinct; lastRGB = rgb; }
        }
    }
    if (nonzero == 0) return 0;
    uint32_t score = distinct * nonzero / (kGrid * kGrid);
    if (score == 0) score = 1;
    if (score > 1000) score = 1000;
    return score;
}

// The guest's own VdSwap arguments, kept so a PresentKick-initiated present can
// be compared against the flip the guest actually issued. Written by
// Hooked_VdSwap below; read only by the audit.
//
// F-XXX (2026-10-21): r4 IS NOT A SURFACE ADDRESS. It is a POINTER to the
// guest's 24-byte texture fetch constant on its own stack (the guest's bytes:
// 0x82419EB4 `addi r3,r1,128` / 0x82419EBC `li r5,24` / 0x82419EC8
// `bl 0x823DA950`; and at the call 0x82419A0DC `addi r4,r1,128`). So
// `g_lastVdSwapInfo` now holds the FETCH HEADER's address, and the front
// buffer's own identity lives in the two atomics below.
static std::atomic<uint32_t> g_lastVdSwapObj{0};      // r3: the ring block pointer
static std::atomic<uint32_t> g_lastVdSwapInfo{0};    // r4: the FETCH HEADER pointer
// F-XXX: the console's PHYSICAL address of the front buffer, and this tree's
// byte for it (0xA0000000 + pa). Both are published by Hooked_VdSwap.
static std::atomic<uint32_t> g_lastVdSwapFbPa{0};
static std::atomic<uint32_t> g_lastVdSwapFbPool{0};
static std::atomic<uint32_t> g_vdSwapCalls{0};
static std::atomic<uint32_t> g_nativePresents{0};

// ---------------------------------------------------------------------------
// F-640: THIS FILE'S VIEW-TRANSLATION SITE (the present-surface resolve).
//
// WHAT THE ADDRESS IS. `Hooked_VdSwap`'s r4 (`swap_info`) is a PHYSICAL address.
// Measured today, build/w664.log:6612 -- `VdSwap[1] obj=0xC65D931C
// swap_info=0x004E0D30 kva=0xC04E0D30` -- and w664.log:6631 --
// `PRESENT-SURF-AUDIT ... vdInfo=004E0D30 vdKva=C04E0D30 | resolved=004E0D30
// score=1 | phys=004E0D30 score=1 | kva=C04E0D30 score=0`. So the resolver has
// been binding the present to 0x004E0D30 and the audit scores the `pa|0xC0000000`
// form at 0. Neither address was ever written.
//
// WHY. The console reaches one physical byte through THREE page-size views --
// .research/xenia/src/xenia/memory.cc:173-180, all three handed `&heaps_.physical`
// -- so `0xA0000000 + pa` and `0xC0000000 + pa` are THE SAME BYTES, a hardware
// guarantee. This tree has one flat 4 GiB window and `Translate` is
// `m_base + guestAddr` (src/kernel/memory.cpp:285-297), so `pa | 0xC0000000` is
// exactly 0x20000000 ABOVE the pool byte the console means. For pa = 0x004E0D30
// the console's byte is 0xA04E0D30 and the old `mcla_gpu_AddSurfaceCandidate(swap_info
// | 0xC0000000u, ...)` produced 0xC04E0D30 -- which is not even inside the pool,
// because the pool ends at 0xC0400000. The present resolve was scoring flat memory
// nothing wrote, every frame, and publishing that as the surface.
//
// The mechanism and every counter live in boot_host.cpp (`F640MapViewToPool` /
// `TranslatePhysViewToPoolVa`, F640-CVIEW-TRANSLATE / -DROPPED / F640-PHYSALIAS-SUM).
// This is only the call site, and it is the one F640-PHYSALIAS phase=init names at
// `adopt=native_renderer.cpp:294(present)`.
//
// THE 4 MiB OVERLAP, AND WHY THIS SITE REFUSES RATHER THAN FALLING BACK. The pool
// is [0xA0400000, 0xC0400000) and the C window is [0xC0000000, 0xE0000000), so they
// OVERLAP by [0xC0000000, 0xC0400000) = 4 MiB. F-640/B2 (2026-10-21): a C-view access
// for pa < 0x400000 now DOES have a byte -- the console's LOW REGION at
// [0xA0000000, 0xA0400000) (src/boot_host.h, kPhysLowRegionVa) -- but the UNTRANSLATED
// address for it is still not that byte: in this flat window 0xC0000000 + pa is the
// POOL'S OWN TAIL, live pool-managed memory holding physical 0x20400000..0x207FFFFF,
// which the console does not have. So there is still nothing to fall back to that is not
// either wrong or destructive: registering the view address would hand the resolver a
// score over 4 MiB of live allocator memory and could bind a present to it, and a
// writer would corrupt the pool with no error anywhere. THEREFORE: NO FALLBACK. A
// refusal touches no memory, so it cannot be an access violation -- it is the same
// shape as every other refusal in this project, named and counted and loud:
// boot_host's `F640-CVIEW-DROPPED` (which carries the attempt index) plus this site's
// own `F640-CVIEW-REFUSED` with `reason=CVIEW-OVERLAPS-POOL-TAIL`. The pool bounds in
// that test come from `kPhysArenaBeginVa`/`kPhysArenaEndVa`, not from a restated 4 MiB
// literal, so the two cannot drift.
//
// MEASURED, so the refusal arm is a measurement and not a hope. Every VdSwap physical
// address in w852.log is 0x004E0AF0 -- EIGHT rows, ONE distinct value, and all of them
// ABOVE the 4 MiB floor. So `refused_overlap=0` means "the guest has not asked for that
// window", not "the guard is dead" -- the guard has a counter and a row either way.
//
// F-640/B2 (2026-10-21), AND A CORRECTION TO WHAT THE OLD PARAGRAPH SAID. The text this
// replaces claimed that "every VdSwap physical address in w664.log is 0x004E0D30, above
// the 4 MiB floor" and that the tree's other F-640 write site "carries raw=0x075D8CBC
// (w664.log:1200), also above it". The SECOND half of that was FALSE, and the fleet
// repeated it: the low physical addresses that were dropped in w852 -- view_va=C0000000
// (physical 0) x1262, view_va=C01FE0FC (physical 0x1FE0FC) x1264 and view_va=C003E01C
// (physical 0x3E01C) x3, 2529 `F640-CVIEW-DROPPED` rows in all -- did NOT come from this
// site. They came from the VERTEX FETCH CONSTANT decode: every printed refusal row in
// w852 says `site=FETCHVB-CONSTANTS` (2503 rows: pa=001FE0FC x1250, pa=00000000 x1249,
// pa=0003E01C x4), and the guest's own fetch constants name physical 0 (528 bytes) and
// physical 0x1FE0FC (11,013,392 bytes) -- `CP-FETCHVB-DECODE #249200 ... slot=1
// physBase=001FE0FC sizeWords=2753348` and `slot=2 physBase=00000000 sizeWords=132`.
// `F640-CVIEW-REFUSED` (this site) was 0 in w852, exactly as the guard predicts.
//
// WHAT CHANGED: the console's low 4 MiB now HAS BYTES. The pool used to present
// physical [0x400000, 0x20400000) because F-391 moved its base by +0x400000, so physical
// [0, 0x400000) had no byte at all -- and on the console it does
// (.research/xenia/src/xenia/memory.cc:171-175: one 512 MiB physical heap at physical 0,
// aliased into the 0xA/0xC/0xE views). The 4 MiB BELOW the pool is now the LOW REGION
// (src/boot_host.h, kPhysLowRegionVa) and carries console physical [0, 0x400000), so the
// view->pool rule is the console's own identity `0xA0000000 + pa` for the whole window.
// The refusal arm below is therefore STILL the right shape -- a physical address outside
// the console's 512 MiB window has no byte anywhere -- but it is no longer reachable for
// a low physical address.
// ---------------------------------------------------------------------------
namespace {
// F-640: this site's own census, so `dropped=0` is READ as a measurement rather than
// as "nothing was ever routed here" (F-057(6: a tracked marker whose producer is
// dead reports zero and means nothing). `adopted` is registered with boot_host on the
// first attempt, which is what puts this site in `F640-PHYSALIAS-SUM adopted_sites=`.
struct F640VdSwapSite
{
    std::atomic<uint64_t> attempts{0};
    std::atomic<uint64_t> mapped{0};         // resolved onto a pool byte
    std::atomic<uint64_t> refusedOverlap{0}; // pa < 4 MiB: the C view IS the pool's tail
    std::atomic<uint64_t> refusedNoPool{0};  // in a view, past the pool's window
    // pool byte and the pa it came from, packed into ONE atomic: a reader can never
    // pair a fresh pa with a stale pool byte, and the audit re-checks `pa == vsInfo`
    // before it trusts the value.
    std::atomic<uint64_t> poolPacked{0};
    std::atomic<bool> announced{false};
};
F640VdSwapSite g_f640VdSwap;
constexpr const char* kF640SiteVdSwap = "native_renderer.cpp:Hooked_VdSwap";
} // namespace

// F-640: one VdSwap physical address -> the pool byte the console means. Returns 0 and
// COUNTS a refusal when this tree has no pool byte for it. It never falls back to the
// untranslated view address (see the overlap note above) and never asserts on the guest
// value -- a physical address with no pool byte is a MISS, not a fault.
//
// F-XXX (2026-10-21): the second parameter. The ADDRESS this site is handed is now the
// front buffer's PHYSICAL address, derived from the guest's own texture fetch
// constant (see the ABI block at Hooked_VdSwap). When the caller has ALREADY resolved
// that physical address to a pool byte -- which it has to do, because the address in
// the fetch constant is a CONSOLE VIEW address and the physical address is the
// view-relative offset (xboxkrnl_video.cc:375-385) -- the resolved pool address is
// passed in so that ONE translation, not two, is counted by the F-640 census. The
// identity `not_a_view + translated + dropped == calls` in F640-PHYSALIAS-SUM is
// therefore unchanged: a caller that resolves it itself contributes exactly one
// TranslatePhysViewToPoolVa call, which it makes.
static uint32_t F640VdSwapPoolVa(uint32_t pa, uint32_t poolVaIn = 0u) {
    const uint64_t n = g_f640VdSwap.attempts.fetch_add(1, std::memory_order_relaxed) + 1;
    if (!g_f640VdSwap.announced.exchange(true, std::memory_order_relaxed))
        mcla::boot::RegisterPhysAliasWriter(kF640SiteVdSwap);

    const uint32_t viewVa = pa | 0xC0000000u;  // the console's own published form (PhysToKernelVA)
    uint32_t poolVa = poolVaIn;
    mcla::boot::PhysViewResult r = mcla::boot::PhysViewResult::kMapped;
    if (poolVa == 0u) {
        r = mcla::boot::TranslatePhysViewToPoolVa(viewVa, &poolVa);
    }

    if (r == mcla::boot::PhysViewResult::kMapped) {
        g_f640VdSwap.mapped.fetch_add(1, std::memory_order_relaxed);
        g_f640VdSwap.poolPacked.store(((uint64_t)poolVa << 32) | (uint64_t)pa,
                                     std::memory_order_relaxed);
    } else {
        // The view address is inside our own pool => this is the 4 MiB overlap, and the
        // address the tree would otherwise have used holds LIVE pool memory.
        const bool overlapsPool = viewVa >= mcla::kernel::kPhysArenaBeginVa &&
                                  viewVa < mcla::kernel::kPhysArenaEndVa;
        (overlapsPool ? g_f640VdSwap.refusedOverlap : g_f640VdSwap.refusedNoPool)
            .fetch_add(1, std::memory_order_relaxed);
        g_f640VdSwap.poolPacked.store((uint64_t)pa, std::memory_order_relaxed);  // pool byte 0
        if (n <= 8 || (n % 200) == 0) {
            MCLA_LOG_ERROR(
                "F640-CVIEW-REFUSED #{} site={} pa={:08X} view_va={:08X} pool_va=NONE "
                "reason={} nothing_read_nothing_written site_attempts={} mapped={} "
                "refused_overlap={} refused_no_pool={}",
                n, kF640SiteVdSwap, pa, viewVa,
                overlapsPool
                    ? "CVIEW-OVERLAPS-POOL-TAIL(4MiB;_[C0000000..C0400000)_IS_our_pool)"
                    : "NO_POOL_BYTE(outside_the_pool_window)",
                n, g_f640VdSwap.mapped.load(std::memory_order_relaxed),
                g_f640VdSwap.refusedOverlap.load(std::memory_order_relaxed),
                g_f640VdSwap.refusedNoPool.load(std::memory_order_relaxed));
        }
    }

    // Publish the house summary row on the site cadence, so `F640-PHYSALIAS-SUM` is
    // printed WITH this site's numbers in it: `adopted_sites >= 1` and the identity
    // `not_a_view + translated + dropped == calls` becomes checkable while it runs,
    // rather than after the fact. Nothing else in the tree calls LogPhysAliasRow.
    if (n <= 4 || (n % 200) == 0)
        mcla::boot::LogPhysAliasRow("vdSwap-present-site");
    return (r == mcla::boot::PhysViewResult::kMapped) ? poolVa : 0u;
}

// R1 (2026-09-10): native present is owned by PresentKick (sub_824294E0).
// VdSwap is a kernel import UR also stubs; here MCLA logs it + feeds W7 only.
void EnqueueNativePresent(uint32_t frameNumber, uint32_t obj, uint32_t fbAddr) {
    if (mcla::renderer::GetRendererMode() != mcla::renderer::RendererMode::Native) {
        return;
    }
    mcla::native::RenderCommand cmd;
    cmd.type = mcla::native::RenderCommand::PRESENT;
    auto& present = cmd.data.emplace<mcla::native::PresentCommand>();
    present.frameNumber = frameNumber;
    present.obj = obj;
    present.swapInfo = fbAddr;
    // W7: resolve surface VA when swapInfo is a swap-table slot.
    present.surfaceVA = mcla::gpu::ResolvedPresentSurfaceVA();
    // F-C census (LONG_TODO_MASTER T37.5): dump the present "swap OBJ" plus a
    // one-hop pointer scan. The spec's observed set C61D8818/C61D8928/C625894C
    // never printed: obj is PresentKick r3, constant 40002080 (the device) in
    // all 2223 rows; only fb cycles slots C71D82C0..CC. First 6 + every 500th.
    {
        static std::atomic<uint32_t> s_objCensus{0};
        const uint32_t on = s_objCensus.fetch_add(1) + 1;
        if (obj != 0 && (on <= 6 || (on % 500) == 0)) {
            auto& mem = ::mcla::kernel::GuestMemoryHeap::Instance();
            auto dumpWords = [&](uint32_t addr, uint32_t words, const char* tag) {
                if (addr == 0 || !mem.IsValid(addr, words * 4)) return;
                std::string out;
                out.reserve(words * 9);
                for (uint32_t k = 0; k < words; ++k) {
                    uint32_t v = 0;
                    (void)mem.ReadU32BE(addr + k * 4, &v);
                    out += fmt::format("{:08X} ", v);
                }
                MCLA_LOG_INFO("OBJ-CENSUS {} @{:08X}: {}", tag, addr, out);
            };
            MCLA_LOG_INFO("OBJ-CENSUS #{} obj={:08X} fb={:08X} surf={:08X}",
                          on, obj, fbAddr, present.surfaceVA);
            dumpWords(obj, 24, "SWAPOBJ");
            // Follow one hop for every plausible pointer word in the first 24.
            for (uint32_t k = 0; k < 24; ++k) {
                uint32_t v = 0;
                (void)mem.ReadU32BE(obj + k * 4, &v);
                if (v >= 0x40000000u && v < 0xE0000000u && mem.IsValid(v, 8))
                    dumpWords(v, 8, "SWAPOBJ-PTR");
            }
        }
    }
    mcla::native::g_commandQueue.push(cmd);
    const uint32_t nPresents = g_nativePresents.fetch_add(1, std::memory_order_relaxed) + 1;
    if (frameNumber <= 8 || (frameNumber % 120) == 0) {
        MCLA_LOG_INFO("NATIVE-PRESENT #{} obj={:08X} fb={:08X} surf={:08X} q={}",
                      frameNumber, obj, fbAddr, present.surfaceVA,
                      mcla::native::g_commandQueue.size());

        // F-612: score the surface the resolver actually chose, and the two
        // forms of the guest's own VdSwap flip argument, with the resolver's
        // own metric. Bounded: 3 x 256 x 4 B of guest reads per printed
        // present, and only on the cadence above - no per-frame cost, no
        // allocation. A resolved score of 0/1 while the kva score is high is
        // the scorer being wrong, stated by the log instead of assumed.
        //
        // F-640: the `kva` column is LEFT EXACTLY AS IT WAS -- it is the address
        // this tree used to hand the resolver, so the F-612 comparison survives
        // verbatim and stays falsifiable. The `pool` column beside it is the
        // TRANSLATED byte (F640VdSwapPoolVa), which is the one the console means,
        // and it is the column that decides the verdict first: if `pool` scores high
        // while `resolved` scores 1, the resolver was reading the wrong address and
        // the translation is the fix. Read `pool` only when its packed `pa` still
        // matches `vdInfo`; otherwise it belongs to an older flip and is not scored.
        //
        // F-XXX (2026-10-21): `vdInfo` IS NOT A SURFACE ANY MORE -- it is the guest's
        // TEXTURE FETCH HEADER pointer (a stack address). The surface the console
        // means is the FRONT BUFFER, and its pool byte is the `pool` column, whose
        // packed `pa` is now compared against the front buffer's own physical
        // address (`vsPa`) rather than against `vdInfo`. The `phys` and `kva`
        // columns are LEFT ALONE on purpose: they score the STACK ADDRESS the old
        // code was resolving, and that score (1 = the clamp floor, w664.log:6631)
        // is the evidence that the old resolution was wrong. It stays printable.
        const uint32_t vsInfo = g_lastVdSwapInfo.load(std::memory_order_relaxed);
        const uint32_t vsObj  = g_lastVdSwapObj.load(std::memory_order_relaxed);
        const uint32_t vsPa   = g_lastVdSwapFbPa.load(std::memory_order_relaxed);
        const uint32_t kva    = (vsInfo != 0 && vsInfo < 0x20000000u)
                                ? (vsInfo | 0xC0000000u) : 0u;
        const uint64_t packed = g_f640VdSwap.poolPacked.load(std::memory_order_relaxed);
        const uint32_t vsPoolPa = (uint32_t)(packed & 0xFFFFFFFFull);
        const uint32_t vsPool   = (vsPoolPa == vsPa && vsPa != 0)
                                    ? (uint32_t)(packed >> 32) : 0u;
        const uint32_t sRes   = PresentSurfaceScore(present.surfaceVA, 1280, 720);
        const uint32_t sPhys  = PresentSurfaceScore(vsInfo, 1280, 720);
        const uint32_t sKva   = PresentSurfaceScore(kva, 1280, 720);
        const uint32_t sPool  = (vsPool != 0) ? PresentSurfaceScore(vsPool, 1280, 720) : 0u;
        const char* verdict =
            (present.surfaceVA == 0)      ? "NO-SURFACE-bound" :
            (sRes >= 100)                 ? "resolved-looks-like-an-image" :
            (sRes <= 1 && sPool > sRes)   ? "SCORE-GUESS-WRONG-pool-scored-higher(F-640-translated)" :
            (sRes <= 1 && sKva > sRes)    ? "SCORE-GUESS-WRONG-kva-scored-higher" :
            (sRes <= 1)                   ? "resolved-is-flat-or-unreadable" :
                                            "resolved-partially-varied";
        MCLA_LOG_WARN("PRESENT-SURF-AUDIT frame={} presents={} vdSwapCalls={} "
                      "routeRatio={} vdObj={:08X} vdInfo={:08X} vdKva={:08X} | "
                      "resolved={:08X} score={} | phys={:08X} score={} | "
                      "kva={:08X} score={} | pool={:08X} score={} => {}",
                      frameNumber, nPresents,
                      g_vdSwapCalls.load(std::memory_order_relaxed),
                      g_vdSwapCalls.load(std::memory_order_relaxed) ? "live" : "dead",
                      vsObj, vsInfo, kva, present.surfaceVA, sRes, vsInfo, sPhys,
                      kva, sKva, vsPool, sPool, verdict);
    }
    // w31: periodic deep child census + bind (first 6, then every 30th).
    MclaW31OnPresent();
}

// VdSwap import hook — the console's KERNEL export (xenia
// src/xenia/kernel/xboxkrnl/xboxkrnl_video.cc:352-434). It still does NOT
// produce a PRESENT (R1): the present is owned by PresentKick, and a second
// present would double-present. What it DOES do now is the console's own
// swap: it derives the front buffer's identity from the guest's own texture
// fetch constant and writes the console's PM4_XE_SWAP packet into the ring
// block the guest reserved.
//
// Guest frame-end reaches VdSwap only from sub_82419E98 @0x8241A0E4
// (ppc_recomp.77.cpp:11782-11784, the sole `bl 0x827bd6e4`; tools/ppc_xrefs.py
// fn 8241A0E4 confirms 1 call site).
//
// F-612, MEASURED: the route is LIVE, not vestigial. w654.log holds
// "VdSwap[200]", "[400]" and "[600]", so the guest issued >=600 flips inside a
// single 120 s boot, one per frame-end, alongside PresentKick. Making it
// produce a second PRESENT would therefore double-present, so R1's inertness is
// correct - but it means ONE of the two guest flip routes contributes nothing
// and the frame rate is set entirely by PresentKick. The route census below
// keeps that measurable instead of assumed.
//
// ---------------------------------------------------------------------------
// F-XXX (2026-10-21): THE CONSOLE'S VdSwap ABI, FROM THE GUEST'S OWN BYTES.
//
// WHAT THE OLD CODE BELIEVED, AND WHY IT WAS WRONG. The hook read r4
// (`swap_info`) as a CONSOLE PHYSICAL ADDRESS, handed it to
// F640VdSwapPoolVa, and published the result as "the VdSwap surface". r4 is a
// POINTER TO A STACK STRUCT. Every number derived from it was a stack
// address: the measured value in build/w854.log was `swap_info=0x004E0AF0`
// with `pool=0xA04E0AF0`, and 0x004E0AF0 is the guest's STACK (the fetch
// header is at r1+128, so the frame's r1 was 0x004E0A70).
//
// THE GUEST'S OWN CALL SITE (build/cache/mcla_pe.bin, VA = offset +
// 0x82000000; the frame-end function sub_82419E98):
//     0x82419EB0  addi r4,r28,28     ; the source of the 24-byte copy
//     0x82419EB4  addi r3,r1,128     ; the destination: the guest's STACK
//     0x82419EBC  li   r5,24         ; 24 bytes = 6 dwords
//     0x82419EC8  bl   0x823DA950    ; memcpy (the guest's memcpy)
//     0x82419ED0  lwz  r29,132(r1)   ; r29 = the copy's dword_1
//     0x82419F4C  rlwinm r6,r29,0,0,19 ; r6 = r29 & 0xFFFFF000
//     0x82419F60  stw  r6,108(r1)    ; -> the word at r1+108
//     0x82419F54  rlwinm r5,r29,0,26,31 ; r5 = r29 & 0x3F
//     0x82419F68  stw  r5,112(r1)    ; -> the word at r1+112
//     0x82419A0C4  addi r10,r1,104   ; r10 = the color space pointer
//     0x82419A0C8  addi r9,r1,112    ; r9 = the TEXTURE FORMAT pointer
//     0x82419A0D0  addi r8,r1,108    ; r8 = the FRONT BUFFER ADDRESS pointer
//     0x82419A0DC  addi r4,r1,128    ; r4 = the FETCH HEADER
//     0x82419A0E0  addi r3,r30+4     ; r3 = the primary ring buffer block
//     0x82419A0E4  bl   0x827BD6E4
//     0x82419A0E8  addi r11,r30,256 ; the guest advances its own ring by
//     0x82419A0EC  stw  r11,48(r31)  ; 256 bytes = 64 words, AFTER the call
// (the mask semantics above are the tree's own: `rlwinm`'s mb/me count from
// the MSB, so mb=0,me=19 is r29 & 0xFFFFF000 and mb=26,me=31 is r29 & 0x3F.
//
// THE REGISTER MEANINGS ARE THE REFERENCE'S, NOT A GUESS
// (xboxkrnl_video.cc:352-360):
//     r3 buffer_ptr       "ptr into primary ringbuffer"
//     r4 fetch_ptr        "frontbuffer Direct3D 9 texture header fetch"
//     r5 unk2  r6 unk3  r7 unk4
//     r8 frontbuffer_ptr  "lpdword_t frontbuffer_ptr, ptr to frontbuffer address"
//     r9 texture_format_ptr   r10 color_space_ptr
//
// WHICH FIELD OF THE HEADER CARRIES THE SURFACE'S ADDRESS. The header is a
// XENOS TEXTURE FETCH CONSTANT (xenia xenos.h:1184-1284,
// `xe_gpu_texture_fetch_t`, six dwords):
//     dword_0: type:2 sign_x/y/z/w:2 clamp_x/y/z:3 pad:3 pitch:9 tiled:1
//     dword_1: format:6 endianness:2 request_size:2 stacked:1
//              nearest_clamp_policy:1 base_address:20      <-- THE ADDRESS
//     dword_2: size_2d { width:13 height:13 stack_depth:6 }
// and the guest's own code agrees, field for field:
//     r29 & 0xFFFFF000  ==  base_address << 12   (the address)
//     r29 & 0x3F        ==  format               (the texture format)
// The reference reads the same two fields: `gpu_fetch.base_address << 12` is
// the front buffer's address and `*frontbuffer_ptr` must equal it
// (xboxkrnl_video.cc:382-384), and the format is `*texture_format_ptr`.
//
// AND THE GUEST'S OWN FORMAT REMAP PROVES THE FIELD MAP (the guest rewrites
// the copy's format field before the call, 0x82419ED4-0x82419EF4 -- the
// rlwimi at :11717-11718 of the recompiled function):
//     (dword_1 & 0x3F) == 50 (k_8_8_8_8_AS_16_16_16_16) -> 6  (k_8_8_8_8)
//     (dword_1 & 0x3F) ==  7 (k_2_10_10_10)              -> 54 (k_2_10_10_10_AS_16_16_16_16)
// and 6 and 54 are EXACTLY the two formats the reference asserts for VdSwap
// (xboxkrnl_video.cc:389-392; xenos.h:457 and :530). The field map is
// confirmed from the guest's bytes, not inferred.
//
// WHAT THE ADDRESS IS: the reference says the fetch constant "contains the
// address in one of the virtual mappings of the physical memory rather than
// the physical address itself" (xboxkrnl_video.cc:375-380) and converts it
// with GetPhysicalAddress (:385). So the header carries a CONSOLE VIEW address
// and the physical address is the view-relative offset. This tree's ONE rule
// for that is src/boot_host.cpp:312-328 (F640MapViewToPool): `poolVa =
// 0xA0000000 + pa`, so `pa = poolVa - 0xA0000000`. A header that already
// carries a physical address (< 0x20000000) is taken as one. BOTH forms are
// printed by the VDSWAP-ABI row, so the next soak says which one the guest
// actually used.
// ---------------------------------------------------------------------------
namespace {
// F-XXX: the console's VdSwap arguments, decoded out of the guest's own memory.
struct VdSwapFrontBuffer {
    bool        headerOk = false;   // the 24-byte fetch constant was readable
    uint32_t    fetch[6] = {0, 0, 0, 0, 0, 0};
    uint32_t    baseAddress = 0;    // fetch[1] >> 12     (20 bits)
    uint32_t    headerAddr = 0;     // baseAddress << 12 (== fetch[1] & 0xFFFFF000)
    uint32_t    format = 0;         // fetch[1] & 0x3F
    uint32_t    width = 0;          // fetch[2] size_2d.width  + 1
    uint32_t    height = 0;         // fetch[2] size_2d.height + 1
    uint32_t    fbWord = 0;         // *r8 : the guest's own copy of the address
    bool        fbWordOk = false;
    uint32_t    fmtWord = 0;        // *r9 : the guest's own copy of the format
    bool        fmtWordOk = false;
    uint32_t    pa = 0;             // the console PHYSICAL address
    uint32_t    poolVa = 0;         // this tree's byte for that physical address
    const char* addrForm = "none";  // how `pa` was derived
    const char* why = "";           // why it was not derived, when it was not
};
} // namespace

// F-XXX: read the console's VdSwap arguments out of the guest's own memory and
// derive the front buffer's PHYSICAL address. Touches no memory it did not
// read, and asserts nothing about the guest's values.
static VdSwapFrontBuffer VdSwapReadFrontBuffer(uint32_t fetchPtr, uint32_t fbWordPtr,
                                                uint32_t fmtWordPtr) {
    VdSwapFrontBuffer fb;
    auto &mem = ::mcla::kernel::GuestMemoryHeap::Instance();
    if (fetchPtr == 0 || !mem.IsValid(fetchPtr, 24u)) {
        fb.why = "fetch-header-unreadable";
        return fb;
    }
    for (uint32_t i = 0; i < 6u; ++i) {
        if (!mem.ReadU32BE(fetchPtr + i * 4u, &fb.fetch[i])) {
            fb.why = "fetch-header-unreadable";
            return fb;
        }
    }
    fb.headerOk = true;
    fb.baseAddress = fb.fetch[1] >> 12;
    fb.headerAddr = fb.baseAddress << 12;   // == fetch[1] & 0xFFFFF000
    fb.format = fb.fetch[1] & 0x3Fu;
    fb.width = (fb.fetch[2] & 0x1FFFu) + 1u;
    fb.height = ((fb.fetch[2] >> 13) & 0x1FFFu) + 1u;
    if (fbWordPtr != 0) {
        fb.fbWordOk = mem.ReadU32BE(fbWordPtr, &fb.fbWord);
    }
    if (fmtWordPtr != 0) {
        fb.fmtWordOk = mem.ReadU32BE(fmtWordPtr, &fb.fmtWord);
    }

    // The PHYSICAL address, through the tree's ONE rule
    // (src/boot_host.cpp:312-328, F640MapViewToPool): the pool address is
    // 0xA0000000 + pa, so the physical address is the pool address minus
    // 0xA0000000. The view bases are NOT restated here.
    if (fb.headerAddr >= mcla::boot::kPhysLowRegionVa) {
        // A console VIEW address: ask the one mechanism for its pool byte.
        uint32_t poolVa = 0;
        const mcla::boot::PhysViewResult r =
            mcla::boot::TranslatePhysViewToPoolVa(fb.headerAddr, &poolVa);
        if (r == mcla::boot::PhysViewResult::kMapped) {
            fb.poolVa = poolVa;
            fb.pa = poolVa - mcla::boot::kPhysLowRegionVa;
            fb.addrForm = "console-view";
        } else {
            fb.why = (r == mcla::boot::PhysViewResult::kNotAView)
                         ? "header-address-not-a-view"
                         : "header-address-has-no-pool-byte";
        }
    } else if (fb.headerAddr < mcla::kernel::kConsolePhysicalBytes) {
        // Already a PHYSICAL address.
        fb.pa = fb.headerAddr;
        fb.addrForm = "console-physical";
    } else {
        fb.why = "header-address-outside-the-console-physical-window";
    }
    return fb;
}

PPC_FUNC_IMPL(Hooked_VdSwap) {
    // The console's argument registers (xboxkrnl_video.cc:352-360).
    const uint32_t bufferPtr  = ctx.r3.u32;  // ptr into the primary ringbuffer
    const uint32_t fetchPtr   = ctx.r4.u32;  // the 24-byte texture fetch constant
    const uint32_t fbWordPtr  = ctx.r8.u32;  // ptr to the front buffer's address
    const uint32_t fmtWordPtr = ctx.r9.u32;  // ptr to the texture format

    g_lastVdSwapObj.store(bufferPtr, std::memory_order_relaxed);
    g_lastVdSwapInfo.store(fetchPtr, std::memory_order_relaxed);
    const uint32_t nSwap = g_vdSwapCalls.fetch_add(1, std::memory_order_relaxed) + 1;

    // F-XXX: the console's front buffer, from the guest's own fetch constant.
    const VdSwapFrontBuffer fb =
        VdSwapReadFrontBuffer(fetchPtr, fbWordPtr, fmtWordPtr);

    // F-XXX: this tree's byte for the front buffer's PHYSICAL address. This is
    // the ONE translation site (F640VdSwapPoolVa -> boot_host.cpp:312-328), and
    // it is now handed the front buffer's address rather than a stack pointer.
    uint32_t poolVaForSwap = 0;
    if (fb.pa != 0) {
        poolVaForSwap = F640VdSwapPoolVa(fb.pa, fb.poolVa);
        g_lastVdSwapFbPa.store(fb.pa, std::memory_order_relaxed);
        g_lastVdSwapFbPool.store(poolVaForSwap, std::memory_order_relaxed);
    } else {
        g_lastVdSwapFbPa.store(0, std::memory_order_relaxed);
        g_lastVdSwapFbPool.store(0, std::memory_order_relaxed);
    }

    // F-XXX: the surface candidate is now the console's FRONT BUFFER. The old
    // candidate was the stack pointer (r4) itself, which is what bound every
    // present to a stack struct (w654.log:6631 `resolved=004E0D30 score=1`).
    // The pool form only needs to ENTER the candidate table once: AddSurface
    // Candidate updates the existing entry for a known VA
    // (gpu_device.cpp:4048-4053) and RefreshResolvedSurface re-scores every
    // slot on each call, so registering it on the first four flips costs 4
    // extra refreshes for the whole boot instead of one per frame, and cannot
    // change behaviour after those four.
    if (poolVaForSwap != 0) {
        const uint32_t w = (fb.width != 0) ? fb.width : 1280u;
        const uint32_t h = (fb.height != 0) ? fb.height : 720u;
        if (nSwap <= 4) {
            mcla_gpu_AddSurfaceCandidate(poolVaForSwap, w, h, "vdswap-frontbuffer");
        }
    }

    // F-XXX: THE CONSOLE'S SWAP PACKET. The console's kernel export writes TWO
    // PM4 packets into the ring block the caller reserved
    // (xboxkrnl_video.cc:404-434) and the display engine acts on them when the
    // ring is submitted. This host never emitted them: build/w854.log carries
    // 0 `CP: XE_SWAP` rows, and the CP's own decoder could not have reached one
    // (the packet had no case in DrainPacketAt and fell into its `default:`
    // arm). The packets are written into the GUEST'S OWN stream, at the point
    // the console writes them -- after the frame's kCopy draw, before the flip.
    bool emitted = false;
    if (fb.headerOk && fb.pa != 0 && bufferPtr != 0) {
        emitted = mcla::gpu::CpEmitXeSwap(bufferPtr, fb.fetch, fb.pa, fb.width,
                                          fb.height);
    }

    // F-XXX: THE CENSUS ROW (falsifier 1). The derived physical address and the
    // header field it came from are printed SIDE BY SIDE, together with the
    // guest's own copy of the address (*r8) and the console's own answer to
    // "which surface is displayed" (RB_COPY_DEST_BASE, 0x2319), so the
    // agreement is checkable in the log and not asserted in prose.
    {
        const mcla::gpu::CpGuestRenderTarget rt = mcla::gpu::CpGuestRenderTargetInfo();
        const uint32_t rbPitch = rt.copyDestPitch & 0x3FFFu;
        const uint32_t rbHeight = (rt.copyDestPitch >> 16) & 0x3FFFu;
        const uint32_t matchHeader =
            (fb.fbWordOk && fb.fbWord == fb.headerAddr) ? 1u : 0u;
        const uint32_t matchFormat =
            (fb.fmtWordOk && fb.fmtWord == fb.format) ? 1u : 0u;
        const uint32_t matchRbCopy = (fb.pa != 0 && fb.pa == rt.copyDestBase) ? 1u : 0u;
        const uint32_t matchGeom =
            (fb.width == rbPitch && fb.height == rbHeight) ? 1u : 0u;
        static std::atomic<uint32_t> s_abiRows{0};
        const uint32_t on = s_abiRows.fetch_add(1, std::memory_order_relaxed) + 1u;
        if (on <= 8u || (on % 200u) == 0u) {
            MCLA_LOG_WARN(
                "VDSWAP-ABI #{} fetchPtr={:08X} dword1={:08X} baseAddr={:08X} "
                "headerAddr={:08X} fbWord={:08X} fbWordOk={} fmt={} fmtWord={:08X} "
                "fmtWordOk={} wh={}x{} pa={:08X} pool={:08X} addrForm={} "
                "rbCopyDestBase={:08X} rbPitch={} rbHeight={} "
                "matchHeader={} matchFormat={} matchRbCopy={} matchGeom={} "
                "emit={} why={}",
                on, fetchPtr, fb.fetch[1], fb.baseAddress, fb.headerAddr,
                fb.fbWord, fb.fbWordOk ? 1 : 0, fb.format, fb.fmtWord,
                fb.fmtWordOk ? 1 : 0, fb.width, fb.height, fb.pa, poolVaForSwap,
                fb.addrForm, rt.copyDestBase, rbPitch, rbHeight, matchHeader,
                matchFormat, matchRbCopy, matchGeom, emitted ? 1 : 0, fb.why);
        }
    }

    static int swapCount = 0;
    swapCount++;
    if (swapCount <= 8 || (swapCount % 200) == 0) {
        const uint32_t presents = g_nativePresents.load(std::memory_order_relaxed);
        MCLA_LOG_INFO("VdSwap[{}] obj=0x{:08X} swap_info=0x{:08X} kva=0x{:08X} "
                      "pool=0x{:08X} pool_n={} fbPa=0x{:08X} emit={} "
                      "(INERT — present owned by PresentKick 0x824294E0; "
                      "presents={} vdswap={} ratio=1:{})",
                    swapCount, bufferPtr, fetchPtr,
                    (fetchPtr != 0 && fetchPtr < 0x20000000u)
                        ? (fetchPtr | 0xC0000000u) : fetchPtr,
                    poolVaForSwap,
                    g_f640VdSwap.mapped.load(std::memory_order_relaxed),
                    fb.pa, emitted ? 1 : 0,
                    presents, nSwap,
                    presents ? (nSwap / presents) : 0u);
    }
    // Do NOT enqueue PRESENT here and do NOT RecordFramePresented —
    // double-present if both VdSwap and PresentKick fire from the same
    // guest frame-end (verified in ppc_recomp.77.cpp sub_82419E98).
}

void InstallNativeRenderer(mcla::App::FunctionDispatcher* dispatcher) {
    if (!dispatcher) {
        MCLA_LOG_WARN("Native renderer: null dispatcher, skipping install");
        return;
    }

    const std::string_view mode = MCLA_CVAR_GET_STRING(renderer_mode);
    if (mode == "compat") {
        MCLA_LOG_WARN("Native renderer: COMPAT mode - no hooks installed "
                    "(backup 2026-07-16 parity)");
        return;
    }

    if (!BisectGroupEnabled("native")) {
        MCLA_LOG_WARN("Native renderer: mcla_patch_groups excludes 'native' - "
                    "no hooks installed");
        return;
    }

    if (!VerifyTraceFileForTests()) {
        MCLA_LOG_ERROR("Native renderer: Phase 1 trace validation self-test FAILED");
    } else {
        MCLA_LOG_INFO("Native renderer: Phase 1 trace validation self-test PASSED");
    }

    if (!VerifyGuestMemoryViewForTests()) {
        MCLA_LOG_ERROR("Native renderer: guest memory view self-test FAILED");
    } else {
        MCLA_LOG_INFO("Native renderer: guest memory view self-test PASSED");
    }

    GetDrawAccumulator()->Initialize(nullptr);

    if (mcla::renderer::GetRendererMode() == mcla::renderer::RendererMode::Capture &&
        mcla::renderer::GetTraceMode() != mcla::renderer::TraceMode::Off) {
        std::filesystem::path tracePath = "mcla_capture.mclatrace";
        auto* app = mcla::GetApp();
        if (app && !app->GetCacheRoot().empty()) {
            tracePath = app->GetCacheRoot() / "mcla_capture.mclatrace";
        }
        GetDrawAccumulator()->SetCaptureEnabled(true, tracePath);
        MCLA_LOG_INFO("Native renderer: Phase 1 DrawPacket capture ENABLED (trace={}, path={})",
                    mcla::renderer::TraceModeName(mcla::renderer::GetTraceMode()),
                    tracePath.string());
    } else {
        GetDrawAccumulator()->SetCaptureEnabled(false);
        MCLA_LOG_INFO("Native renderer: Phase 1 DrawPacket capture disabled (mode={}, trace={})",
                    mcla::renderer::RendererModeName(mcla::renderer::GetRendererMode()),
                    mcla::renderer::TraceModeName(mcla::renderer::GetTraceMode()));
    }

    // S1–S3 consolidation: 0x8241BD08 / 0x82420BA8 are owned by gpu_device.cpp's
    // strong-alias overrides (single hook per guest address). Only the submit
    // observers still register here; gpu_device dispatches them via
    // DispatchBeforeSubmit from the single-owner hook.
    if (!mcla::renderer::hooks::AddBeforeSubmitObserver(mcla::gpu::NotifyGpuSubmit)) {
        MCLA_LOG_ERROR("Native renderer: failed to register GPU submit observer");
    }
#ifndef NDEBUG
    assert(mcla::renderer::hooks::VerifySubmitObserverOrderingForTests());
#endif

    orig_Sub8241ABB8 = dispatcher->GetFunction(0x8241ABB8);
    if (orig_Sub8241ABB8) {
        dispatcher->SetFunction(0x8241ABB8, Hooked_Sub8241ABB8);
        MCLA_LOG_INFO("Native renderer: sub_8241ABB8 (state setup) hooked");
    } else {
        MCLA_LOG_WARN("Native renderer: sub_8241ABB8 not found");
    }

    dispatcher->SetFunction(0x827BD6E4, Hooked_VdSwap);
    MCLA_LOG_INFO("Native renderer: VdSwap registered INERT (present owned by "
                  "PresentKick sub_824294E0 / frame-end sub_82419E90)");

    // F-612 REPORT (not fixed here - src/patches.cpp is not this file's):
    // tools/addr_owners.py --check 0x827BD6E4 exits 1. Three sites claim this
    // guest function: SetFunction Hooked_VdSwap at native_renderer.cpp:295
    // (this file), SetFunction hk_vdswap_observer at src/patches.cpp:568, and a
    // named-import host body VdSwap at src/kernel/imports.cpp:4633. The
    // addr_owners VIOLATION text is explicit that no file states which owner
    // wins. Empirically THIS hook is the one that ran in w654.log - the
    // "VdSwap[1] obj=0x... (INERT - present owned by PresentKick)" line is this
    // file's format string and it prints - so the collision is currently
    // benign, but that is an accident of install order, not a stated fact.
}

} // namespace mcla::native

