#include "gpu_mmio.h"
#include "native_renderer.h"
#include "logging.h"
#include <unordered_map>

// F-612 CENSUS, measured 2026-09-28 on build/w654.log + build/w653.log
// (both 120 s soaks, 21.5 MB each): THIS FILE IS NOT THE MMIO APERTURE.
//
// The aperture the task brief describes - "the game writes registers by storing
// to a physical window and this code turns those stores into CP traffic" - does
// not live here. It lives on the checked guest-accessor path:
//
//   guest_memory.cpp:341  GuestMemoryView::WriteU32BE gates (addr & 0xFFFF0000)
//   guest_memory.cpp:257  ...ReadU32BE, same gate
//       == 0x7FC80000  ->  GetGpuMmioWriteHandler()/ReadHandler()
//   gpu_cp.cpp:2677-2679  CpInstallMmioRouting installs CpMmioWrite/CpMmioRead
//   gpu_cp.cpp:2206-2209  CpMmioWrite RE-gates on the same CACHED window
//
// Measured consequences, both from w654.log:
//   * 0 occurrences of "GPU MMIO:"   -> LogMmioWrite (below) has NO caller
//     anywhere in src/ or generated/ (grep: only its own definition at
//     gpu_mmio.cpp:16 and its declaration at gpu_mmio.h:31). Dead.
//   * 0 occurrences of "sub_824238E0" and 0 of "sub_82422EF8" -> the two MMIO
//     hooks installed at :103-104 are never reached by the guest. The live
//     doorbell reaches CpMmioWrite directly through the accessor gate.
// So nothing here is on the MMIO boundary; the hooks below are passive
// passthroughs that only ever observe a guest function the title does not call.
// Kept installed (they forward to orig_* and change no behaviour) so the census
// in InstallGpuHooks keeps stating the measured truth instead of implying
// coverage this file does not have.

namespace mcla::gpu {

static std::unordered_map<uint32_t, uint64_t> g_mmioWriteCounts;
static GpuHooks g_hooks;

static PPCFunc* orig_sub_824238E0 = nullptr;
static PPCFunc* orig_sub_82422EF8 = nullptr;
// orig_sub_82411180 / orig_sub_82411618 removed 2026-09-28 (F-609 one-owner
// sweep) with the two registrations in InstallGpuHooks that were their only
// reader; see the note there.

void LogMmioWrite(uint32_t offset, uint32_t value) {
    g_mmioWriteCounts[offset]++;
    auto count = g_mmioWriteCounts[offset];

    if (count <= 5 || (count % 1000 == 0)) {
        const char* regName = "UNKNOWN";
        switch (offset) {
            case XenosRegister::CP_RB_WPTR: regName = "CP_RB_WPTR (KICK)"; break;
            case XenosRegister::CP_RB_RPTR: regName = "CP_RB_RPTR"; break;
            case XenosRegister::CP_RB_BASE: regName = "CP_RB_BASE"; break;
            case XenosRegister::CP_RB_CNTL: regName = "CP_RB_CNTL"; break;
            case XenosRegister::VGT_PRIMITIVE_TYPE: regName = "VGT_PRIMITIVE_TYPE"; break;
            case XenosRegister::VGT_NUM_INDICES: regName = "VGT_NUM_INDICES"; break;
            case XenosRegister::VGT_DRAW_INITIATOR: regName = "VGT_DRAW_INITIATOR"; break;
            case XenosRegister::SQ_ALU_CONST_CACHE: regName = "SQ_ALU_CONST_CACHE"; break;
            case XenosRegister::CB_COLOR0_BASE: regName = "CB_COLOR0_BASE"; break;
            case XenosRegister::CB_DEPTH_BASE: regName = "CB_DEPTH_BASE"; break;
            case XenosRegister::SQ_PGM_START_VS: regName = "SQ_PGM_START_VS"; break;
            case XenosRegister::SQ_PGM_START_PS: regName = "SQ_PGM_START_PS"; break;
            case XenosRegister::SQ_PGM_RESOURCES_VS: regName = "SQ_PGM_RESOURCES_VS"; break;
            case XenosRegister::SQ_PGM_RESOURCES_PS: regName = "SQ_PGM_RESOURCES_PS"; break;
        }
        MCLA_LOG_INFO("GPU MMIO: 0x7FC8%04X (%s) = 0x%08X [%llu]",
            offset, regName, value, count);
    }
}

static int g_bitstreamWriteCount = 0;

// F-612: the address-space convention of the pointers the MMIO producer hands
// out. The CP drains the same buffer through PhysToKernelVA (gpu_cp.cpp:1765-1767,
// `pa < 0x20000000 ? pa|0xC0000000 : pa`, applied at :3092/:3434 for the
// indirect-buffer list pointer and :3852 for the rptr writeback) but NOT to
// the ring body - gpu_cp.cpp:915-931 already says so and leaves it as an open
// question with a one-shot warning. This is the producer-side half of that
// measurement: it names which convention the value arriving here is in, so the
// day the hook fires the two halves can be compared instead of one being
// assumed. Zero cost while the hook is dead (see the file header).
//
// F-640 (2026-09-30), AND THIS FUNCTION IS DELIBERATELY NOT CHANGED. It is on the
// `F640-PHYSALIAS phase=init` `adopt=` list, and the answer is that it must not
// adopt: `a | 0xC0000000u` at :83 is the C VIEW address, which in this flat-window
// tree is 0x20000000 above the pool byte the console means (boot_host.cpp's
// F640MapViewToPool block), so translating it here would be the fix at the wrong
// layer. But this function's entire OUTPUT is two things: the label string, and a
// `physForm` word that is consumed by exactly one caller and goes only into the
// `MCLA_LOG_INFO` at :107-111. It reads no memory and writes no memory -- the only
// two things it computes are a name and a number to print. A label function that
// translated would be WRONG, because its purpose is to report the convention the
// value arriving here is in so it can be compared against the convention the CP
// applies; a "corrected" label would silently agree with the thing it exists to
// disagree with, and the comparison F-612 asked for would be destroyed.
//
// So the F-640 defect is REPORTED from this file, not patched here, and the
// translation is not attempted from here either: a call into
// `TranslatePhysViewToPoolVa` from a labeler would inflate boot_host's
// `calls`/`translated` with diagnostic traffic while this file registers no
// adopted writer, which is precisely how a zero stops being a measurement
// (F-057(6)). InstallGpuHooks says so out loud, one line, so a reader can tell a
// labeler from a writer without reading this comment. The hook is also dead as
// measured (w664.log holds 0 "sub_824238E0"), so the row below is dormant
// instrumentation, not a live path.
static const char* MmioAddrSpace(uint32_t a, uint32_t* physForm) {
    if (a == 0) { *physForm = 0; return "null"; }
    if (a < 0x20000000u)          { *physForm = a | 0xC0000000u; return "PHYS"; }
    if (a >= 0xC0000000u)         { *physForm = a & ~0xC0000000u; return "KERNEL-VA"; }
    if ((a & 0xFFFF0000u) == 0x7FC80000u ||
        (a & 0xFFFF0000u) == 0xFFC80000u) { *physForm = a; return "MMIO"; }
    *physForm = a;
    return "CACHED";
}

PPC_FUNC_IMPL(gpu_MmioWriteHook) {
    g_bitstreamWriteCount++;

    if (g_bitstreamWriteCount <= 5 || (g_bitstreamWriteCount % 1000 == 0)) {
        uint32_t mgr       = ctx.r3.u32;
        uint32_t writePtr  = ctx.r4.u32;
        uint32_t bitstream = ctx.r5.u32;
        uint32_t bsSize    = ctx.r6.u32;

        // F-612: report the convention of mgr and of the bitstream pointer,
        // plus the physical form the CP's PhysToKernelVA would produce, so a
        // live call proves which side of the gpu_cp.cpp:915 divergence we are on.
        uint32_t mgrPhys = 0, bsPhys = 0;
        const char* mgrSpace = MmioAddrSpace(mgr, &mgrPhys);
        const char* bsSpace  = MmioAddrSpace(bitstream, &bsPhys);

        MCLA_LOG_INFO("sub_824238E0[%d] mgr=0x%08X(%s,phys=0x%08X) wptr=0x%08X "
                      "bs=0x%08X(%s,phys=0x%08X) sz=%u lr=0x%08X",
                    g_bitstreamWriteCount, mgr, mgrSpace, mgrPhys, writePtr,
                    bitstream, bsSpace, bsPhys, bsSize,
                    static_cast<uint32_t>(ctx.lr));
    }

    if (g_hooks.onGpuKick)
        g_hooks.onGpuKick(ctx);

    if (orig_sub_824238E0) orig_sub_824238E0(ctx, base);
}

PPC_FUNC_IMPL(gpu_MmioWriteHelperHook) {
    if (g_hooks.onGpuKick) g_hooks.onGpuKick(ctx);
    if (orig_sub_82422EF8) orig_sub_82422EF8(ctx, base);
}

// gpu_Sub82411180Hook / gpu_Sub82411618Hook removed 2026-09-28 (F-609 one-owner
// sweep). Both reduced to their orig_* chain because src/patches.cpp:500 passes
// an empty GpuHooks, and both were unreachable through the dispatch table, so
// they were shadowed by the compile-time owners in src/gpu_device.cpp:2614 /
// :2637. Draw observation is served by NotifyGpuSubmit below, which is
// renderer-owned and is not a guest-function binding, so it is unaffected.

void NotifyGpuSubmit(PPCContext& ctx, uint8_t*) {
    if (g_hooks.onDrawCall) g_hooks.onDrawCall(ctx);
}

void DefaultGpuKickHook(PPCContext& ctx) {
    MCLA_LOG_INFO("GPU KICK: CP_RB_WPTR signal");
}

void DefaultSetupVertexFetchHook(PPCContext& ctx) {
    MCLA_LOG_INFO("GPU VERTEX FETCH SETUP");
}

void DefaultDrawCallHook(PPCContext& ctx) {
    MCLA_LOG_INFO("GPU DRAW CALL");
}

void InstallGpuHooks(mcla::App::FunctionDispatcher* dispatcher, const GpuHooks& hooks) {
    g_hooks = hooks;

    orig_sub_824238E0 = dispatcher->GetFunction(0x824238E0);
    orig_sub_82422EF8 = dispatcher->GetFunction(0x82422EF8);

    dispatcher->SetFunction(0x824238E0, gpu_MmioWriteHook);
    dispatcher->SetFunction(0x82422EF8, gpu_MmioWriteHelperHook);

    // DELETED 2026-09-28 (F-609 one-owner sweep): the 0x82411180 /
    // 0x82411618 registrations, and with them the two passthrough wrappers
    // gpu_Sub82411180Hook / gpu_Sub82411618Hook and the orig_* statics they
    // saved. Both addresses are already owned by a compile-time PPC_FUNC body
    // in src/gpu_device.cpp:2614 and :2637, so each of these was a second
    // binding mechanism on one guest function, and the two answers differed per
    // call site. The wrappers were the dead side of that fork:
    //  * g_hooks is empty. src/patches.cpp:500 is the only InstallGpuHooks
    //    caller and it passes `GpuHooks{}`, so onDrawCall and
    //    onSetupVertexFetch are both null and each wrapper reduced to
    //    `orig(addr)(ctx, base)` -- the override body, verbatim.
    //  * no table-indirect caller exists. ppc_xrefs.py calls reports 2 direct
    //    edges to 0x82411180 (ppc_recomp.75.cpp:14483, :14612) and 3 to
    //    0x82411618 (:19546, ppc_recomp.77.cpp:15167, ppc_recomp.78.cpp:3892),
    //    each a link-time `sub_82411180(ctx, base);`; `rg
    //    "PPC_CALL_INDIRECT_FUNC\(0x82411180\|0x82411618\)"` in generated/ = 0
    //    of 14,832, and ppc_xrefs.py xref materialises neither address.
    //    So nothing ever entered the table slot these wrappers occupied.
    //  * the owner is measured live and the wrapper was not. build/w654.log and
    //    w653.log each hold 21 "HELPER-thunk sub_82411180 hit" and 2
    //    "HELPER-thunk sub_82411618 hit" -- the gpu_device.cpp:2625/:2640
    //    markers -- and 0 of any marker this file could have produced.
    // NotifyGpuSubmit is the live draw observer and is renderer-owned; it is
    // untouched. src/gpu_device.cpp:2614 / :2637 need no edit.

    // F-612: state the measured coverage of this file rather than letting the
    // install line imply it owns the MMIO aperture. w654.log/w653.log hold 0
    // "sub_824238E0" and 0 "sub_82422EF8" lines, so both MMIO hooks are dead;
    // the real aperture is the checked-accessor gate (guest_memory.cpp:257/342)
    // into CpMmioWrite (gpu_cp.cpp:2206). One-shot: a later soak that does
    // produce those markers is self-announcing, so this line is not noise.
    MCLA_LOG_WARN("GPU hooks installed: 4 intercept+passthrough; submit is "
                  "renderer-owned. F-612: the live MMIO aperture is NOT these "
                  "hooks - it is guest_memory.cpp:342 -> CpMmioWrite "
                  "(gpu_cp.cpp:2206); a 'sub_824238E0' line here means the "
                  "producer finally fired and the F-612 alias census starts.");

    // F-640: SAY OUT LOUD THAT THIS FILE ADOPTS NOTHING, so `F640-PHYSALIAS-SUM
    // adopted_sites` is not silently short one reader. `MmioAddrSpace` (:83) is
    // named in F640-PHYSALIAS phase=init's `adopt=` list and does NOT call
    // TranslatePhysViewToPoolVa, deliberately: it is a label function whose
    // `physForm` word goes only into the log row at :107-111 (see the block
    // above). So this file contributes 0 attempts and 0 adopted sites by
    // construction, and the two writer sites are elsewhere: native_renderer.cpp
    // Hooked_VdSwap (present surface, registered via RegisterPhysAliasWriter)
    // and gpu_cp.cpp's rptr write-back at :3852, which is STILL UNTRANSLATED
    // and is a WRITE, not a read -- reported to the owning stream, not patched
    // from here. A zero in this file is a decision with a reason, not a gap.
    MCLA_LOG_WARN("F640-PHYSALIAS phase=gpu_mmio site=gpu_mmio.cpp:83(MmioAddrSpace) "
                  "adopted=0 attempts=0 role=LABEL-ONLY reads_no_memory "
                  "physForm=pa|0xC0000000_is_the_C_VIEW_address_0x20000000_above_the_pool_byte "
                  "NOT_translated_here_writers_are_elsewhere");

    // F-612 / F-609: the 0x82411180 and 0x82411618 conflicts against the
    // strong-alias owners at src/gpu_device.cpp:2614 / :2637 are RESOLVED, and
    // they resolve in the orchestrator's favour: those two SetFunction lines are
    // gone from the block above, so addr_owners.py --check on either address now
    // reports the single `override` in gpu_device.cpp and exits 0.
}

} // namespace mcla::gpu

