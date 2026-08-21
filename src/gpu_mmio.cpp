#include "gpu_mmio.h"
#include "native_renderer.h"
#include "logging.h"
#include <unordered_map>

namespace mcla::gpu {

static std::unordered_map<uint32_t, uint64_t> g_mmioWriteCounts;
static GpuHooks g_hooks;

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
        MCLA_LOG_INFO("GPU MMIO: 0x7FC8%04X (%s) = 0x%08X [%llu]",
            offset, regName, value, count);
    }
}

static int g_bitstreamWriteCount = 0;

PPC_FUNC_IMPL(gpu_MmioWriteHook) {
    g_bitstreamWriteCount++;

    if (g_bitstreamWriteCount <= 5 || (g_bitstreamWriteCount % 1000 == 0)) {
        uint32_t mgr       = ctx.r3.u32;
        uint32_t writePtr  = ctx.r4.u32;
        uint32_t bitstream = ctx.r5.u32;
        uint32_t bsSize    = ctx.r6.u32;

        MCLA_LOG_INFO("sub_824238E0[%d] mgr=0x%08X wptr=0x%08X bs=0x%08X sz=%u",
                    g_bitstreamWriteCount, mgr, writePtr, bitstream, bsSize);
    }

    if (g_hooks.onGpuKick)
        g_hooks.onGpuKick(ctx);

    if (orig_sub_824238E0) orig_sub_824238E0(ctx, base);
}

PPC_FUNC_IMPL(gpu_MmioWriteHelperHook) {
    if (g_hooks.onGpuKick) g_hooks.onGpuKick(ctx);
    if (orig_sub_82422EF8) orig_sub_82422EF8(ctx, base);
}

PPC_FUNC_IMPL(gpu_Sub82411180Hook) {
    if (g_hooks.onDrawCall) g_hooks.onDrawCall(ctx);
    if (orig_sub_82411180) orig_sub_82411180(ctx, base);
}

void NotifyGpuSubmit(PPCContext& ctx, uint8_t*) {
    if (g_hooks.onDrawCall) g_hooks.onDrawCall(ctx);
}

PPC_FUNC_IMPL(gpu_Sub82411618Hook) {
    if (g_hooks.onSetupVertexFetch) g_hooks.onSetupVertexFetch(ctx);
    if (orig_sub_82411618) orig_sub_82411618(ctx, base);
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
    orig_sub_82411180 = dispatcher->GetFunction(0x82411180);
    orig_sub_82411618 = dispatcher->GetFunction(0x82411618);

    dispatcher->SetFunction(0x824238E0, gpu_MmioWriteHook);
    dispatcher->SetFunction(0x82422EF8, gpu_MmioWriteHelperHook);
    dispatcher->SetFunction(0x82411180, gpu_Sub82411180Hook);
    dispatcher->SetFunction(0x82411618, gpu_Sub82411618Hook);

    MCLA_LOG_INFO("GPU hooks installed: 4 intercept+passthrough; submit is renderer-owned");
}

} // namespace mcla::gpu

