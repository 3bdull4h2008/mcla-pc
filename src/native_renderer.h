#pragma once

#include <cstddef>
#include <cstdint>
#include <rex/system/function_dispatcher.h>

struct MclaGpuContext;

namespace mcla::native {

void InstallNativeRenderer(rex::runtime::FunctionDispatcher* dispatcher);

// Register a callback invoked at every draw boundary with the full GPU
// context and any captured draw parameters.
using DrawCaptureCallback = void(*)(::MclaGpuContext* gpuCtx,
                                    uint32_t drawType,
                                    uint32_t drawFlags);

void SetDrawCaptureCallback(DrawCaptureCallback cb);

// Sync the guest GPU context struct fields to the backend register file.
// Called from both the GfxCmdBufSubmit hook and the save/load reinit path.
void WriteGpuContextToRegisterFile(::MclaGpuContext* gpuCtx);

// Restore the guest context from the backend register file (save/load path).
void RestoreRegisterFileToContext(::MclaGpuContext* gpuCtx);

// Forward a guest GPU register value directly to the backend register file.
// Called from the MMIO hook path to ensure the backend has up-to-date state
// even before the ring buffer is processed.
void ForwardRegisterToBackend(uint32_t regIndex, uint32_t value);

// Access the last captured draw type/flags (from sub_82420BA8 hook).
uint32_t GetLastDrawType();
uint32_t GetLastDrawFlags();

// Issue a native draw directly to the backend command processor, bypassing
// the PM4 ring-buffer processing path.  Captured state from
// sub_82420BA8 + sub_8241ABB8 is combined with the register file to fill in
// all renderer requirements before the call.
void IssueNativeDraw(::MclaGpuContext* gpuCtx);

// Drive the runtime's own frame trace (Xenia .xtr stream).  The game renders
// through the host GPU plugin (rexgpu-xenos.dll) on the "GPU Commands" thread,
// not through the guest PPC draw functions we hook, so the only complete
// record of real draws is the CommandProcessor's built-in TraceWriter.
// StartHostFrameTrace spawns a host thread that, after a warm-up delay,
// calls CommandProcessor::BeginTracing(root) and then EndTracing() after a
// capture window, leaving <root>/{title_id:08X}_stream.xtr on disk.
void StartHostFrameTrace();

}

// GPU context struct from reverse engineering of the game's render-state
// arrays.  Passed as r31 to all GfxCmdBuf*/CommandBuffer* functions.
// Layout verified across recomp files.
struct MclaGpuContext {
    uint32_t vtable;              // +0x00
    uint32_t pad04[9];            // +0x04–+0x27
    uint64_t flagsBitmask;        // +0x28
    uint32_t cmdBufWritePos;      // +0x30
    uint32_t cmdBufNextPos;       // +0x34
    uint32_t cmdBufAvailPos;      // +0x38

    uint8_t _pad03C[0x5D8 - 0x3C];

    // Command-buffer entry array (32 × 5 = 160 uint32s)
    uint32_t cmdEntries[32][5];   // +0x5D8

    uint32_t cmdEntryCount;       // +0x858
    uint32_t cmdWriteIndex;       // +0x85C
    uint32_t cmdRemaining;        // +0x860

    uint8_t _pad864[0x3098 - 0x864];

    // ── Render-target / depth surface-info source-of-truth ────────────────
    // Each 4-byte value is the surface-info pointer/value the game intends
    // to load into the GPU register of the same number for the next draw.
    // (sub_8241ABB8 copies these to the "mirror" at +0x31C4-0x31DC before
    //  the draw is committed, comparing them to decide whether to re-emit
    //  state packets — we hook both for redundant seeding into the
    //  backend register file.)

    uint32_t rbSurfaceInfoP0;     // +0x3098 = RB_SURFACE_INFO source (RT0)
    uint32_t rbSurfaceInfoP1;     // +0x309C = RB_SURFACE_INFO source (RT1)
    uint32_t rbSurfaceInfoP2;     // +0x30A0 = RB_SURFACE_INFO source (RT2)
    uint32_t rbSurfaceInfoP3;     // +0x30A4 = RB_SURFACE_INFO source (RT3 / depth often)
    uint32_t rbSurfaceInfoP4;     // +0x30A8 = RB_SURFACE_INFO source (default)

    uint8_t _pad30D0[0x317C - 0x30AC];

    // ── Shader-program state ──────────────────────────────────────────────

    uint32_t sqVsConst;           // +0x317C = SQ_VS_CONST    (reg 0x2307)
    uint32_t sqPsConst;           // +0x3180 = SQ_PS_CONST    (reg 0x2308)
    uint32_t sqVsProgram;         // +0x3184 = SQ_VS_PROGRAM  (reg 0x21F7)
    uint32_t sqPsProgram;         // +0x3188 = SQ_PS_PROGRAM  (reg 0x21F6)

    uint8_t _pad318C[0x31AC - 0x318C];

    // ── VGT draw state mirror ─────────────────────────────────────────────
    // This is what sub_8241ABB8 copies FROM the surface-info source
    // (above), and is what sub_82420BA8 finally emits as PM4 register-write
    // packets in the ring buffer.

    uint32_t drawFenceID;         // +0x31AC = pending-op ID (-1 = active)
    uint32_t drawStateVersion;    // +0x31B0 = state-version hash counter
    uint32_t paClipCntl;          // +0x31B4 = PA_CL_CLIP_CNTL
    uint32_t paSuScModeCntl;      // +0x31B8 = PA_SU_SC_MODE_CNTL
    uint32_t paClVteCntl;         // +0x31BC = PA_CL_VTE_CNTL
    uint32_t vgtDrawStateCount;   // +0x31C0 = VGT state-list entry count
    uint32_t rsaMirror[5];        // +0x31C4–+0x31D4 (mirrors of Group A above)
    uint32_t drawVertexCount;     // +0x31D8 = number of vertices / entries

    uint8_t _pad31E0[0x3200 - 0x31E0];
};

static_assert(offsetof(MclaGpuContext, flagsBitmask) == 0x28);
static_assert(offsetof(MclaGpuContext, cmdEntries) == 0x5D8);
static_assert(offsetof(MclaGpuContext, rbSurfaceInfoP0) == 0x3098);
static_assert(offsetof(MclaGpuContext, sqVsConst) == 0x317C);
static_assert(offsetof(MclaGpuContext, drawVertexCount) == 0x31D8);
static_assert(sizeof(MclaGpuContext) == 0x3200);
