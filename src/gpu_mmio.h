#pragma once

#include <cstdint>
#include <functional>
#include <rex/ppc/context.h>
#include <rex/system/function_dispatcher.h>

namespace mcla::gpu {

using PPCContext = ::PPCContext;

// MMIO write hook: called when game writes to GPU MMIO register
using GpuMmioWriteHook = void(*)(PPCContext& ctx, uint32_t offset, uint32_t value);

// MMIO read hook: called when game reads from GPU MMIO register
using GpuMmioReadHook = uint32_t(*)(PPCContext& ctx, uint32_t offset);

// High-level GPU event callbacks
struct GpuHooks {
    void (*onGpuKick)(PPCContext& ctx) = nullptr;
    void (*onSetupVertexFetch)(PPCContext& ctx) = nullptr;
    void (*onDrawCall)(PPCContext& ctx) = nullptr;
};

// Xenos GPU MMIO register offsets (from 0x7FC80000 base)
namespace XenosRegister {
    constexpr uint32_t CP_RB_WPTR      = 0x0714;
    constexpr uint32_t CP_RB_RPTR      = 0x0718;
    constexpr uint32_t CP_RB_BASE      = 0x0700;
    constexpr uint32_t CP_RB_CNTL      = 0x0704;
    constexpr uint32_t CP_IB_BASE      = 0x0720;
    constexpr uint32_t CP_IB_BUFSZ     = 0x0724;
    constexpr uint32_t VGT_PRIMITIVE_TYPE    = 0x3000;
    constexpr uint32_t VGT_NUM_INDICES       = 0x3004;
    constexpr uint32_t VGT_DRAW_INITIATOR    = 0x3008;
    constexpr uint32_t VGT_VERTEX_BUFFER     = 0x3100;
    constexpr uint32_t VGT_INDEX_BASE        = 0x3200;
    constexpr uint32_t VGT_INDEX_TYPE        = 0x3204;
    constexpr uint32_t SQ_VTX_CONSTANT_WORD0_0 = 0x4000;
    constexpr uint32_t SQ_ALU_CONST_CACHE     = 0x4800;
    constexpr uint32_t SQ_TEX_SAMPLER_WORD0_0 = 0x6000;
    constexpr uint32_t SQ_TEX_RESOURCE_WORD0_0 = 0x6100;
    constexpr uint32_t CB_COLOR0_BASE       = 0x7000;
    constexpr uint32_t CB_COLOR0_PITCH      = 0x7004;
    constexpr uint32_t CB_DEPTH_BASE        = 0x7100;
    constexpr uint32_t CB_DEPTH_PITCH       = 0x7104;
    constexpr uint32_t SQ_PGM_START_VS      = 0x8000;
    constexpr uint32_t SQ_PGM_START_PS      = 0x8004;
    constexpr uint32_t SQ_PGM_RESOURCES_VS  = 0x8010;
    constexpr uint32_t SQ_PGM_RESOURCES_PS  = 0x8014;
    constexpr uint32_t SQ_PGM_EXPORTS_VS    = 0x8018;
    constexpr uint32_t SQ_PGM_EXPORTS_PS    = 0x801C;
    constexpr uint32_t CP_RB_RPTR_R        = 0x071C;
    constexpr uint32_t CP_STAT             = 0x07F0;
    constexpr uint32_t CP_INT_CNTL         = 0x07F4;
    constexpr uint32_t CP_INT_STATUS       = 0x07F8;
}

constexpr uint32_t GPU_NORTHBRIDGE_BASE = 0x7FE90000;
constexpr uint32_t GPU_CORE_BASE        = 0x7FC80000;

inline bool IsGpuMmio(uint32_t addr) {
    return (addr >= GPU_NORTHBRIDGE_BASE && addr < GPU_NORTHBRIDGE_BASE + 0x10000) ||
           (addr >= GPU_CORE_BASE && addr < GPU_CORE_BASE + 0x10000);
}

inline uint32_t GetGpuRegisterOffset(uint32_t addr) {
    if (addr >= GPU_CORE_BASE && addr < GPU_CORE_BASE + 0x10000) {
        return addr - GPU_CORE_BASE;
    }
    if (addr >= GPU_NORTHBRIDGE_BASE && addr < GPU_NORTHBRIDGE_BASE + 0x10000) {
        return (addr - GPU_NORTHBRIDGE_BASE) | 0x10000;
    }
    return 0xFFFFFFFF;
}

void InstallGpuHooks(rex::runtime::FunctionDispatcher* dispatcher, const GpuHooks& hooks = {});

// Called by the single renderer-owned GfxCmdBufSubmit hook. GPU diagnostics
// remain an observer and never replace the generated submit function.
void NotifyGpuSubmit(PPCContext& ctx, uint8_t* base);

void DefaultGpuKickHook(PPCContext& ctx);
void DefaultSetupVertexFetchHook(PPCContext& ctx);
void DefaultDrawCallHook(PPCContext& ctx);

} // namespace mcla::gpu
