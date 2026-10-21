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
static std::atomic<uint32_t> g_lastVdSwapObj{0};
static std::atomic<uint32_t> g_lastVdSwapInfo{0};
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
static uint32_t F640VdSwapPoolVa(uint32_t pa) {
    const uint64_t n = g_f640VdSwap.attempts.fetch_add(1, std::memory_order_relaxed) + 1;
    if (!g_f640VdSwap.announced.exchange(true, std::memory_order_relaxed))
        mcla::boot::RegisterPhysAliasWriter(kF640SiteVdSwap);

    const uint32_t viewVa = pa | 0xC0000000u;  // the console's own published form (PhysToKernelVA)
    uint32_t poolVa = 0;
    const mcla::boot::PhysViewResult r =
        mcla::boot::TranslatePhysViewToPoolVa(viewVa, &poolVa);

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
        const uint32_t vsInfo = g_lastVdSwapInfo.load(std::memory_order_relaxed);
        const uint32_t vsObj  = g_lastVdSwapObj.load(std::memory_order_relaxed);
        const uint32_t kva    = (vsInfo != 0 && vsInfo < 0x20000000u)
                                ? (vsInfo | 0xC0000000u) : 0u;
        const uint64_t packed = g_f640VdSwap.poolPacked.load(std::memory_order_relaxed);
        const uint32_t vsPoolPa = (uint32_t)(packed & 0xFFFFFFFFull);
        const uint32_t vsPool   = (vsPoolPa == vsInfo && vsInfo != 0)
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

// VdSwap import hook — INERT for frame production (R1).
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
PPC_FUNC_IMPL(Hooked_VdSwap) {
    uint32_t obj       = ctx.r3.u32;
    uint32_t swap_info = ctx.r4.u32;

    g_lastVdSwapObj.store(obj, std::memory_order_relaxed);
    g_lastVdSwapInfo.store(swap_info, std::memory_order_relaxed);
    const uint32_t nSwap = g_vdSwapCalls.fetch_add(1, std::memory_order_relaxed) + 1;

    // W7: VdSwap swap_info is a physical-ish address (seen as 0x004E0D30).
    // Add it as a surface candidate — it may be the real framebuffer.
    //
    // F-612: that value is PHYSICAL, and it was being handed to the resolver as
    // if it were a guest VA. Proof from w654.log: the very first
    // "PRESENT-SURF resolved va=004E0D30 score=1" - the resolver bound a present
    // to a physical address below the 0x20000000 window, scoring the clamp floor
    // (gpu_device.cpp:4039). The repo's own convention for exactly this value is
    // PhysToKernelVA (gpu_cp.cpp:669), published through pa|0xC0000000 (see
    // gpu_cp.h:22-24, which states it for the rptr write-back).
    // The phys form is KEPT so the existing candidate set is unchanged, and the
    // kernel-VA form is ADDED beside it: scoring only ever promotes a better
    // candidate, never demotes one, and PRESENT-SURF-AUDIT prints all three
    // scores so the promotion is falsifiable from the next soak.
    //
    // F-640 (2026-09-30): "the kernel-VA form" was `swap_info | 0xC0000000u`, and
    // that IS the C view address -- which in this tree is 0x20000000 ABOVE the pool
    // byte the console means and, for pa = 0x004E0D30, not even inside the pool. So
    // the promoted candidate was flat memory nothing wrote (w664.log:6631 scores
    // `kva=C04E0D30 score=0` while `phys=004E0D30 score=1`). It is now TRANSLATED
    // through the one mechanism (boot_host's TranslatePhysViewToPoolVa), the src
    // label is `vdswap-pool` because the address is no longer the kva form, and a
    // refusal registers NOTHING -- see the F-640 block above for why there is
    // deliberately no fallback. The raw-`swap_info` candidate above is untouched, so
    // the F-612 evidence (`resolved=004E0D30 score=1`) stays reproducible.
    uint32_t poolVaForSwap = 0;
    if (swap_info != 0 && swap_info < 0xF0000000u) {
        mcla_gpu_AddSurfaceCandidate(swap_info, 1280, 720, "vdswap");
        // The pool form only needs to ENTER the candidate table once:
        // AddSurfaceCandidate updates the existing entry for a known VA
        // (gpu_device.cpp:4048-4053) and RefreshResolvedSurface re-scores every
        // slot on each call - including the one PresentKick makes at
        // gpu_device.cpp:4145, once per frame. Registering it on the first four
        // flips therefore costs 4 extra refreshes for the whole boot instead of
        // one per frame, and cannot change behaviour after those four.
        //
        // The TRANSLATION, by contrast, is attempted on every flip: it is pure
        // arithmetic plus the boot_host counters, it is what makes `translated=` /
        // `dropped=` real numbers instead of a four-sample anecdote, and it is what
        // keeps `poolPacked` current for the audit above.
        if (swap_info < 0x20000000u) {
            poolVaForSwap = F640VdSwapPoolVa(swap_info);
            if (poolVaForSwap != 0 && nSwap <= 4) {
                mcla_gpu_AddSurfaceCandidate(poolVaForSwap, 1280, 720, "vdswap-pool");
            }
        }
    }

    static int swapCount = 0;
    swapCount++;
    if (swapCount <= 8 || (swapCount % 200) == 0) {
        const uint32_t presents = g_nativePresents.load(std::memory_order_relaxed);
        MCLA_LOG_INFO("VdSwap[{}] obj=0x{:08X} swap_info=0x{:08X} kva=0x{:08X} "
                      "pool=0x{:08X} pool_n={} "
                      "(INERT — present owned by PresentKick 0x824294E0; "
                      "presents={} vdswap={} ratio=1:{})",
                    swapCount, obj, swap_info,
                    (swap_info != 0 && swap_info < 0x20000000u)
                        ? (swap_info | 0xC0000000u) : swap_info,
                    poolVaForSwap,
                    g_f640VdSwap.mapped.load(std::memory_order_relaxed),
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

