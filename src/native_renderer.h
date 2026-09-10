#pragma once

#include <cstddef>
#include <cstdint>
#include "app.h"

struct MclaGpuContext;

namespace mcla::native {

void InstallNativeRenderer(mcla::App::FunctionDispatcher* dispatcher);

// R1 (2026-09-10): native present is driven by the game's PresentKick
// (sub_824294E0), not the kernel VdSwap import. Call from the single-owner
// PresentKick hook when renderer_mode=native.
void EnqueueNativePresent(uint32_t frameNumber, uint32_t obj, uint32_t fbAddr);

// (GetLastDrawType/GetLastDrawFlags/SetDrawCaptureCallback removed 2026-09-09:
// zero callers — dead API deleted with the S1–S3 dual-owner hook sweep.)

void WriteGpuContextToRegisterFile(::MclaGpuContext* gpuCtx);
void RestoreRegisterFileToContext(::MclaGpuContext* gpuCtx);
void ForwardRegisterToBackend(uint32_t regIndex, uint32_t value);

void IssueNativeDraw(::MclaGpuContext* gpuCtx);
void StartHostFrameTrace();

D3D12Backend* GetD3D12Backend();

} // namespace mcla::native

struct MclaGpuContext {
    uint32_t vtable;
    uint32_t pad04[9];
    uint64_t flagsBitmask;
    uint32_t cmdBufWritePos;
    uint32_t cmdBufNextPos;
    uint32_t cmdBufAvailPos;

    uint8_t _pad03C[0x5D8 - 0x3C];

    uint32_t cmdEntries[32][5];

    uint32_t cmdEntryCount;
    uint32_t cmdWriteIndex;
    uint32_t cmdRemaining;

    uint8_t _pad864[0x3098 - 0x864];

    uint32_t rbSurfaceInfoP0;
    uint32_t rbSurfaceInfoP1;
    uint32_t rbSurfaceInfoP2;
    uint32_t rbSurfaceInfoP3;
    uint32_t rbSurfaceInfoP4;
    uint32_t rbSurfaceInfoP5;

    uint8_t _pad30B0[0x317C - 0x30B0];

    uint32_t sqVsConst;
    uint32_t sqPsConst;
    uint32_t sqVsProgram;
    uint32_t sqPsProgram;

    uint8_t _pad318C[0x31AC - 0x318C];

    uint32_t drawFenceID;
    uint32_t drawStateVersion;
    uint32_t paClipCntl;
    uint32_t paSuScModeCntl;
    uint32_t paClVteCntl;
    uint32_t vgtDrawStateCount;
    uint32_t rsaMirror[5];
    uint32_t drawVertexCount;

    uint8_t _pad31E0[0x3200 - 0x31E0];
};

static_assert(offsetof(MclaGpuContext, flagsBitmask) == 0x28);
static_assert(offsetof(MclaGpuContext, cmdEntries) == 0x5D8);
static_assert(offsetof(MclaGpuContext, rbSurfaceInfoP0) == 0x3098);
static_assert(offsetof(MclaGpuContext, sqVsConst) == 0x317C);
static_assert(offsetof(MclaGpuContext, drawVertexCount) == 0x31D8);
static_assert(sizeof(MclaGpuContext) == 0x3200);