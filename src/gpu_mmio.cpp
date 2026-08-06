#include "gpu_mmio.h"
#include "native_renderer.h"
#include <rex/logging.h>
#include <unordered_map>

namespace mcla::gpu {

static std::unordered_map<uint32_t, uint64_t> g_mmioWriteCounts;
static GpuHooks g_hooks;

// Saved original function pointers
static PPCFunc* orig_sub_824238E0 = nullptr;
static PPCFunc* orig_sub_82422EF8 = nullptr;
static PPCFunc* orig_sub_82411180 = nullptr;
static PPCFunc* orig_sub_82411618 = nullptr;

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
        REXLOG_INFO("GPU MMIO: 0x7FC8%04X (%s) = 0x%08X [%llu]",
            offset, regName, value, count);
    }
}

// ── Ring-buffer bitstream writer (sub_824238E0) ──────────────────────────
//
// The game calls this function to encode register-offset+value pairs into
// the command ring buffer as PM4 packets.  The parameters are:
//   r3 = ring-buffer manager object
//   r4 = write pointer (destination offset into ring)
//   r5 = source bitstream (packed (offset,value) pairs)
//   r6 = bitstream size in bytes
//
// We DO NOT attempt to decode the bitstream here — that would duplicate
// the PM4 encoder logic.  Instead we just track the call rate and chain
// to the original, which populates the ring buffer normally.
//
// NOTE: the earlier hook interpreted ctx.r6/r7 as (offset,value), which is
// incorrect — r6 is the bitstream byte size, r7 is a local variable set
// inside the callee.  That interpretation is removed.

static int g_bitstreamWriteCount = 0;

REX_FUNC(gpu_MmioWriteHook) {
    g_bitstreamWriteCount++;

    if (g_bitstreamWriteCount <= 5 || (g_bitstreamWriteCount % 1000 == 0)) {
        uint32_t mgr       = ctx.r3.u32;
        uint32_t writePtr  = ctx.r4.u32;
        uint32_t bitstream = ctx.r5.u32;
        uint32_t bsSize    = ctx.r6.u32;

        REXLOG_INFO("sub_824238E0[%d] mgr=0x%08X wptr=0x%08X bs=0x%08X sz=%u",
                    g_bitstreamWriteCount, mgr, writePtr, bitstream, bsSize);
    }

    if (g_hooks.onGpuKick)
        g_hooks.onGpuKick(ctx);

    if (orig_sub_824238E0) orig_sub_824238E0(ctx, base);
}

// Hook: sub_82422EF8 - Ring buffer flush helper
REX_FUNC(gpu_MmioWriteHelperHook) {
    if (g_hooks.onGpuKick) g_hooks.onGpuKick(ctx);
    if (orig_sub_82422EF8) orig_sub_82422EF8(ctx, base);
}

// Hook: sub_82411180 - Ring buffer alignment/sync
REX_FUNC(gpu_Sub82411180Hook) {
    if (g_hooks.onDrawCall) g_hooks.onDrawCall(ctx);
    if (orig_sub_82411180) orig_sub_82411180(ctx, base);
}

void NotifyGpuSubmit(PPCContext& ctx, uint8_t*) {
    if (g_hooks.onDrawCall) g_hooks.onDrawCall(ctx);
}

// Hook: sub_82411618 - Vertex fetch setup
REX_FUNC(gpu_Sub82411618Hook) {
    if (g_hooks.onSetupVertexFetch) g_hooks.onSetupVertexFetch(ctx);
    if (orig_sub_82411618) orig_sub_82411618(ctx, base);
}

void DefaultGpuKickHook(PPCContext& ctx) {
    REXLOG_INFO("GPU KICK: CP_RB_WPTR signal");
}

void DefaultSetupVertexFetchHook(PPCContext& ctx) {
    REXLOG_INFO("GPU VERTEX FETCH SETUP");
}

void DefaultDrawCallHook(PPCContext& ctx) {
    REXLOG_INFO("GPU DRAW CALL");
}

void InstallGpuHooks(rex::runtime::FunctionDispatcher* dispatcher, const GpuHooks& hooks) {
    g_hooks = hooks;

    orig_sub_824238E0 = dispatcher->GetFunction(0x824238E0);
    orig_sub_82422EF8 = dispatcher->GetFunction(0x82422EF8);
    orig_sub_82411180 = dispatcher->GetFunction(0x82411180);
    orig_sub_82411618 = dispatcher->GetFunction(0x82411618);

    dispatcher->SetFunction(0x824238E0, gpu_MmioWriteHook);
    dispatcher->SetFunction(0x82422EF8, gpu_MmioWriteHelperHook);
    dispatcher->SetFunction(0x82411180, gpu_Sub82411180Hook);
    dispatcher->SetFunction(0x82411618, gpu_Sub82411618Hook);

    REXLOG_INFO("GPU hooks installed: 4 intercept+passthrough; submit is renderer-owned");
}

} // namespace mcla::gpu
