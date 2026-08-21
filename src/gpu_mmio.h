#pragma once

#include <cstdint>
#include "app.h"

namespace mcla::gpu {

enum XenosRegister : uint32_t {
    CP_RB_WPTR            = 0x01C4,
    CP_RB_RPTR            = 0x01C8,
    CP_RB_BASE            = 0x01C0,
    CP_RB_CNTL            = 0x01CC,
    VGT_PRIMITIVE_TYPE    = 0x21F8,
    VGT_NUM_INDICES       = 0x21FC,
    VGT_DRAW_INITIATOR    = 0x21F0,
    SQ_ALU_CONST_CACHE    = 0x2440,
    CB_COLOR0_BASE        = 0x2000,
    CB_DEPTH_BASE         = 0x2002,
    SQ_PGM_START_VS       = 0x21F4,
    SQ_PGM_START_PS       = 0x21F6,
    SQ_PGM_RESOURCES_VS   = 0x2300,
    SQ_PGM_RESOURCES_PS   = 0x2301,
};

struct GpuHooks {
    void (*onGpuKick)(mcla::native::PPCContext&) = nullptr;
    void (*onDrawCall)(mcla::native::PPCContext&) = nullptr;
    void (*onSetupVertexFetch)(mcla::native::PPCContext&) = nullptr;
};

void LogMmioWrite(uint32_t offset, uint32_t value);

void NotifyGpuSubmit(mcla::native::PPCContext& ctx, uint8_t* base);

void DefaultGpuKickHook(mcla::native::PPCContext& ctx);
void DefaultSetupVertexFetchHook(mcla::native::PPCContext& ctx);
void DefaultDrawCallHook(mcla::native::PPCContext& ctx);

void InstallGpuHooks(mcla::App::FunctionDispatcher* dispatcher, const GpuHooks& hooks);

} // namespace mcla::gpu