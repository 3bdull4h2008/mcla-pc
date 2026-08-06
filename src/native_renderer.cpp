#include "native_renderer.h"
#include "gpu_mmio.h"
#include "renderer_hook_dispatch.h"
#include "renderer_mode.h"
#include "capture_hooks.h"
#include "frame_trace.h"
#include "d3d12_backend.h"
#include <rex/logging.h>
#include <rex/ui/window.h>
#include <cmath>
#include <rex/runtime.h>
#include <rex/graphics/graphics_system.h>
#include <rex/graphics/register_file.h>
#include <rex/graphics/command_processor.h>
#include "generated/default/mcla_init.h"
#include <rex/graphics/xenos.h>

#include <cassert>
#include <filesystem>

namespace mcla::native {

// â”€â”€ Internal state â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€

static PPCFunc* orig_GfxCmdBufSubmit = nullptr;
static PPCFunc* orig_Sub82420BA8     = nullptr;
static PPCFunc* orig_Sub8241ABB8     = nullptr;
static DrawCaptureCallback g_drawCaptureCb = nullptr;

// â”€â”€ Helper: access the backend register file â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€

static rex::graphics::RegisterFile* GetRegisterFile() {
    auto* runtime = rex::Runtime::instance();
    if (!runtime) return nullptr;
    auto* gs = static_cast<rex::graphics::GraphicsSystem*>(runtime->graphics_system());
    if (!gs) return nullptr;
    return gs->register_file();
}

// â”€â”€ Helper: access the backend command processor â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€

static rex::graphics::CommandProcessor* GetCommandProcessor() {
    auto* runtime = rex::Runtime::instance();
    if (!runtime) return nullptr;
    auto* gs = static_cast<rex::graphics::GraphicsSystem*>(runtime->graphics_system());
    if (!gs) return nullptr;
    return gs->command_processor();
}

// IssueDraw is protected in CommandProcessor.  This shim exposes it as
// a public static so we can call it from the hook without modifying the SDK.

struct CommandProcessorAccess : rex::graphics::CommandProcessor {
    static bool CallIssueDraw(rex::graphics::CommandProcessor* cp,
                              rex::graphics::xenos::PrimitiveType prim_type,
                              uint32_t index_count,
                              bool major_mode_explicit) {
        return static_cast<CommandProcessorAccess*>(cp)->IssueDraw(
            prim_type, index_count, nullptr, major_mode_explicit);
    }
};

// â”€â”€ Seed critical registers from guest context â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€
//
// Instead of trying to replicate the complex rldicr-based ring-buffer write
// logic (which overflows source arrays when all bitmask bits are set during
// initialization), we directly read the source data arrays and match each
// entry to its intended register using the same address calculation that
// sub_82423548 uses.
//
// Each "group" = one call to sub_82423548 inside sub_82420BA8, defined by:
//   - srcOffset: where the register values live in the context
//   - baseReg:   starting register address (dword index)
//   - rldicrShift / rldicrMaskStart:  how to extract the relevant bitmask
//
// The register address for the n-th source entry (within one run of
// consecutive 1-bits) is:
//   reg = baseReg + leadingZeros + entryIndexInRun

static void ProcessRingBufferGroup(rex::graphics::RegisterFile* rf,
                                   uint8_t* contextBase,
                                   uint32_t srcOffset,
                                   uint32_t baseReg,
                                   uint64_t ctxMask,
                                   int rldicrShift,
                                   int rldicrMaskStart,
                                   uint32_t maxEntries,
                                   const char* name) {
    // Apply rldicr to extract the relevant bits
    uint64_t shifted = (ctxMask << rldicrShift) | (ctxMask >> (64 - rldicrShift));
    uint32_t bitsKept = static_cast<uint32_t>(rldicrMaskStart) + 1;
    uint64_t bitmask = shifted & ((~0ULL) << (64 - bitsKept));

    if (!bitmask) return;

    uint32_t* srcData = reinterpret_cast<uint32_t*>(contextBase + srcOffset);
    uint32_t srcIdx = 0;

    while (bitmask && srcIdx < maxEntries) {
        // Find MSB set bit
        int lz = __builtin_clzll(bitmask);
        // Shift past leading zeros
        bitmask <<= lz;
        // Count consecutive 1s
        int runLen = __builtin_clzll(~bitmask);
        // Clamp to max entries
        if (runLen > static_cast<int>(maxEntries - srcIdx)) {
            runLen = static_cast<int>(maxEntries - srcIdx);
        }
        // Starting register address
        uint32_t regAddr = baseReg + lz;
        for (int i = 0; i < runLen; i++) {
            if (regAddr + i < rex::graphics::RegisterFile::kRegisterCount) {
                rf->values[regAddr + i] = srcData[srcIdx + i];
            }
        }
        srcIdx += runLen;
        bitmask <<= runLen;
    }

    if (srcIdx > 0) {
        REXLOG_INFO("  Seeded {} regs from {} base=0x{:04X} (max={})",
                    srcIdx, name, baseReg, maxEntries);
    }
}

// Max source entries per group.
// Source offsets (ascending): 10368(RB), 10444(SQcfg1), 10528(SQcfg2),
// 10548(SQprog), 10596(SQconst1), 10680(SQconst2).
// Each group's max = (next_offset - this_offset) / 4.
static constexpr uint32_t kGroupMax[6] = {
    12,  // [0] SQprog   (10548â†’10596 = 48/4 = 12)
     5,  // [1] SQcfg2   (10528â†’10548 = 20/4 =  5)
    19,  // [2] RB       (10368â†’10444 = 76/4 = 19)
    21,  // [3] SQcfg1   (10444â†’10528 = 84/4 = 21)
    21,  // [4] SQconst1 (10596â†’10680 = 84/4 = 21)
    UINT32_MAX  // [5] SQconst2 (last, unbounded)
};

static void SeedAllRegistersFromContext(::MclaGpuContext* gpuCtx) {
    auto* rf = GetRegisterFile();
    if (!rf) return;

    uint8_t* ctx = reinterpret_cast<uint8_t*>(gpuCtx);
    uint64_t ctx16 = *reinterpret_cast<uint64_t*>(ctx + 16);
    uint64_t ctx24 = *reinterpret_cast<uint64_t*>(ctx + 24);
    uint64_t ctx32 = *reinterpret_cast<uint64_t*>(ctx + 32);

    // Each call to sub_82423548:
    //   Group  (cache)  srcOffset   base  rldicr(shift, maskStart)  maxEntries
    //   â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€
    //   0(SQprog)   ctx+10548  0x2200  (52, 11)   12
    //   1(SQcfg2)   ctx+10528  0x2180  (47, 4)     5
    //   2(RB)       ctx+10368  0x2000  (6, 15)     19
    //   3(SQcfg1)   ctx+10444  0x2100  (22, 20)    21
    //   4(SQconst1) ctx+10596  0x2280  (9, 20)     21   (uses ctx24)
    //   5(SQconst2) ctx+10680  0x2300  (26, 37)   inf    (uses ctx32)
    //
    // NOTE: Groups 0-3 use MODIFIED copies of ctx16 (bits cleared after each).
    // Since game hasn't called sub_8241ABB8 yet for initial draws, these
    // source arrays may contain stale/uninitialized values.  Critical
    // render-state registers (RB_SURFACE_INFO, RB_MODECONTROL etc.) are
    // overridden in WriteGpuContextToRegisterFile after this call.

    ProcessRingBufferGroup(rf, ctx, 10548, 0x2200, ctx16, 52, 11, kGroupMax[0], "SQprog");
    ProcessRingBufferGroup(rf, ctx, 10528, 0x2180, ctx16, 47,  4, kGroupMax[1], "SQcfg2");
    ProcessRingBufferGroup(rf, ctx, 10368, 0x2000, ctx16,  6, 15, kGroupMax[2], "RB");
    ProcessRingBufferGroup(rf, ctx, 10444, 0x2100, ctx16, 22, 20, kGroupMax[3], "SQcfg1");
    ProcessRingBufferGroup(rf, ctx, 10596, 0x2280, ctx24,  9, 20, kGroupMax[4], "SQconst1");
    ProcessRingBufferGroup(rf, ctx, 10680, 0x2300, ctx32, 26, 37, kGroupMax[5], "SQconst2");

    REXLOG_INFO("SeedAllRegistersFromContext: ctx16=0x{:016X} ctx24=0x{:016X} ctx32=0x{:016X}",
                (unsigned long long)ctx16, (unsigned long long)ctx24, (unsigned long long)ctx32);
}

// â”€â”€ Full guest-context â†” register-file sync â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€
//
// Every render-state value that the game stores in the GpuContext struct is
// written into the backend register file so the backend sees correct state
// regardless of PM4 ring-buffer timing.

void WriteGpuContextToRegisterFile(::MclaGpuContext* gpuCtx) {
    auto* rf = GetRegisterFile();
    if (!rf) return;

    using namespace rex::graphics;

    // â”€â”€ Step 1: Bulk seed from context source-data arrays â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€
    //
    // Processes the 6 register groups that sub_82420BA8 would normally
    // write as PM4 packets.  Each group is capped at its valid source-
    // data entry count to avoid reading garbage into the register file.
    //
    // During initialization the bitmasks are all-1s (all dirty), so many
    // register addresses within the rldicr-mapped range get written with
    // whatever is in the context arrays â€” potentially stale values.
    // Critical overrides follow in steps 2-3.

    SeedAllRegistersFromContext(gpuCtx);

    // â”€â”€ Step 2: Override with known reliable context fields â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€
    //
    // These come from the game's explicit struct fields (set during
    // sub_8241ABB8 state-setup or the save/load reinit path) and are
    // more trustworthy than the source-data arrays, which may contain
    // stale values if the bitmask in ctx16/24/32 didn't cause them to
    // be re-emitted.

    // Render-target surface / depth info
    if (gpuCtx->rbSurfaceInfoP0) {
        rf->values[XE_GPU_REG_RB_SURFACE_INFO] = gpuCtx->rbSurfaceInfoP0;
    }
    if (gpuCtx->rbSurfaceInfoP1) {
        rf->values[XE_GPU_REG_RB_DEPTH_INFO]   = gpuCtx->rbSurfaceInfoP1;
    }

    // Window scissor â€” packed TL/BR pair
    if (gpuCtx->rbSurfaceInfoP2) {
        rf->values[XE_GPU_REG_PA_SC_WINDOW_SCISSOR_TL] = gpuCtx->rbSurfaceInfoP2;
    }

    // Viewport transform â€” X-scale
    if (gpuCtx->rbSurfaceInfoP3) {
        rf->values[XE_GPU_REG_PA_CL_VPORT_XSCALE]  = gpuCtx->rbSurfaceInfoP3;
    }

    // Screen scissor â€” TL corner
    if (gpuCtx->rbSurfaceInfoP4) {
        rf->values[XE_GPU_REG_PA_SC_SCREEN_SCISSOR_TL] = gpuCtx->rbSurfaceInfoP4;
    }

    // Shader-program constants / program pointers
    rf->values[XE_GPU_REG_SQ_VS_CONST]   = gpuCtx->sqVsConst;
    rf->values[XE_GPU_REG_SQ_PS_CONST]   = gpuCtx->sqPsConst;
    rf->values[XE_GPU_REG_SQ_VS_PROGRAM] = gpuCtx->sqVsProgram;
    rf->values[XE_GPU_REG_SQ_PS_PROGRAM] = gpuCtx->sqPsProgram;

    // Rasteriser / primitive-assembly state
    rf->values[XE_GPU_REG_PA_CL_CLIP_CNTL]    = gpuCtx->paClipCntl;
    rf->values[XE_GPU_REG_PA_SU_SC_MODE_CNTL] = gpuCtx->paSuScModeCntl;
    rf->values[XE_GPU_REG_PA_CL_VTE_CNTL]     = gpuCtx->paClVteCntl;

    // VGT draw state
    rf->values[XE_GPU_REG_VGT_MAX_VTX_INDX] = gpuCtx->drawVertexCount;

    // â”€â”€ Step 3: Force-seed critical render-state registers â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€

    // RB_MODECONTROL must use kColorDepth (4) for normal draws.
    // The source arrays may have seeded garbage (e.g. edram_mode=6=kCopy).
    rf->values[XE_GPU_REG_RB_MODECONTROL] = 4;  // kColorDepth

    // VGT_DRAW_INITIATOR (0x21FC) â€” outside all 6 group ranges.
    // Layout: prim_type[0:5] | source_select[6:7] | major_mode[8:9] |
    //         pad_10 | index_size[11] | not_eop[12] | pad_13[13:15] |
    //         num_indices[16:31]
    {
        uint32_t drawType  = GetLastDrawType();
        uint32_t indexCnt  = gpuCtx->drawVertexCount;
        if (indexCnt == 0) indexCnt = 64;

        // source_select = 0 (auto), major_mode = 1 (explicit),
        // index_size = 0 (16-bit), not_eop = 1
        uint32_t vgt_di = (drawType & 0x3F)           // prim_type
                        | (0 << 6)                    // source_select
                        | (1 << 8)                    // major_mode = EXPLICIT
                        | (0 << 11)                   // index_size = 16bit
                        | (1 << 12)                   // not_eop
                        | ((indexCnt & 0xFFFF) << 16);
        rf->values[XE_GPU_REG_VGT_DRAW_INITIATOR] = vgt_di;
    }
}

void RestoreRegisterFileToContext(::MclaGpuContext* gpuCtx) {
    auto* rf = GetRegisterFile();
    if (!rf) return;
    using namespace rex::graphics;

    gpuCtx->rbSurfaceInfoP0  = rf->values[XE_GPU_REG_RB_SURFACE_INFO];
    gpuCtx->rbSurfaceInfoP1  = rf->values[XE_GPU_REG_RB_DEPTH_INFO];
    gpuCtx->rbSurfaceInfoP2  = rf->values[XE_GPU_REG_PA_SC_WINDOW_SCISSOR_TL];
    gpuCtx->rbSurfaceInfoP3  = rf->values[XE_GPU_REG_PA_CL_VPORT_XSCALE];
    gpuCtx->rbSurfaceInfoP4  = rf->values[XE_GPU_REG_PA_SC_SCREEN_SCISSOR_TL];
    gpuCtx->paClipCntl       = rf->values[XE_GPU_REG_PA_CL_CLIP_CNTL];
    gpuCtx->paSuScModeCntl   = rf->values[XE_GPU_REG_PA_SU_SC_MODE_CNTL];
    gpuCtx->paClVteCntl      = rf->values[XE_GPU_REG_PA_CL_VTE_CNTL];
    gpuCtx->sqVsConst        = rf->values[XE_GPU_REG_SQ_VS_CONST];
    gpuCtx->sqPsConst        = rf->values[XE_GPU_REG_SQ_PS_CONST];
    gpuCtx->sqVsProgram      = rf->values[XE_GPU_REG_SQ_VS_PROGRAM];
    gpuCtx->sqPsProgram      = rf->values[XE_GPU_REG_SQ_PS_PROGRAM];
}

// â”€â”€ Register forwarder (called from MMIO hook path) â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€

void ForwardRegisterToBackend(uint32_t regIndex, uint32_t value) {
    auto* rf = GetRegisterFile();
    if (!rf) return;
    if (regIndex < rex::graphics::RegisterFile::kRegisterCount) {
        rf->values[regIndex] = value;
    }
}

// â”€â”€ Draw-capture callback â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€

void SetDrawCaptureCallback(DrawCaptureCallback cb) {
    g_drawCaptureCb = cb;
}

// â”€â”€ Draw type / flags from latest sub_82420BA8 call â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€

static uint32_t s_lastDrawType = 0;
static uint32_t s_lastDrawFlags = 0;

uint32_t GetLastDrawType()  { return s_lastDrawType; }
uint32_t GetLastDrawFlags() { return s_lastDrawFlags; }

// â”€â”€ Native draw dispatch â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€
//
// Called at GfxCmdBufSubmit time after the register file has been seeded
// from the guest context.  Issues the draw directly to the backend command
// processor via IssueDraw(), bypassing the PM4 ring-buffer path.

void IssueNativeDraw(::MclaGpuContext* gpuCtx) {
    auto* cp = GetCommandProcessor();
    if (!cp) {
        REXLOG_WARN("Native draw: no command processor available");
        return;
    }

    auto* rf = GetRegisterFile();

    // Dump critical register state just before draw
    using namespace rex::graphics;
    uint32_t vgt_di = rf ? rf->values[XE_GPU_REG_VGT_DRAW_INITIATOR] : 0;
    uint32_t rb_mc  = rf ? rf->values[XE_GPU_REG_RB_MODECONTROL] : 0;
    uint32_t rb_si  = rf ? rf->values[XE_GPU_REG_RB_SURFACE_INFO] : 0;

    using namespace rex::graphics::xenos;
    PrimitiveType primType = PrimitiveType::kTriangleList;

    uint32_t drawType = s_lastDrawType & 7;
    switch (drawType) {
        case 0: primType = PrimitiveType::kTriangleList;   break;
        case 1: primType = PrimitiveType::kTriangleStrip;  break;
        case 2: primType = PrimitiveType::kTriangleFan;    break;
        case 3: primType = PrimitiveType::kLineList;       break;
        case 4: primType = PrimitiveType::kPointList;      break;
        case 5: primType = PrimitiveType::kRectangleList;  break;
        default: break;
    }

    uint32_t indexCount = gpuCtx->drawVertexCount;
    if (indexCount == 0) indexCount = 64;

    REXLOG_INFO("NATIVE DRAW: type={} idx={} vgt_di=0x{:08X} rb_mc=0x{:08X} rb_si=0x{:08X}",
                (int)primType, indexCount, vgt_di, rb_mc, rb_si);

    CommandProcessorAccess::CallIssueDraw(cp, primType, indexCount, true);
}

// â”€â”€ Hook: sub_8241BD08 â€” GfxCmdBufSubmit â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€

REX_FUNC(Hooked_GfxCmdBufSubmit) {
    mcla::renderer::RecordSubmit();
    mcla::renderer::hooks::DispatchBeforeSubmit(ctx, base);

    uint32_t ctx_guest = ctx.r3.u32;

    if (ctx_guest) {
        ::MclaGpuContext* gpuCtx = reinterpret_cast<::MclaGpuContext*>(base + ctx_guest);

        static int drawCount = 0;
        drawCount++;
        if (drawCount <= 5 || (drawCount % 100 == 0)) {
            REXLOG_INFO("GfxCmdBufSubmit[%d] ctx=0x%08X r4=0x%08X "
                        "surf0=0x%08X surf1=0x%08X "
                        "vsProg=0x%08X psProg=0x%08X",
                        drawCount, ctx_guest, ctx.r4.u32,
                        gpuCtx->rbSurfaceInfoP0, gpuCtx->rbSurfaceInfoP1,
                        gpuCtx->sqVsProgram, gpuCtx->sqPsProgram);
        }

        // Notify the draw-capture callback (if set)
        if (g_drawCaptureCb) {
            g_drawCaptureCb(gpuCtx, ctx.r4.u32, 0);
        }

        // Phase 1: Accumulate DrawPacket on submit
        GetDrawAccumulator()->OnSubmit(gpuCtx, ctx.r4.u32);
    }

    // Phase 0 preserves the generated submission path. It is called exactly
    // once; observers above may record state but cannot replace this chain.
    if (orig_GfxCmdBufSubmit) {
        orig_GfxCmdBufSubmit(ctx, base);
    }
}

// â”€â”€ Hook: sub_82420BA8 â€” Draw-call builder â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€

REX_FUNC(Hooked_Sub82420BA8) {
    mcla::renderer::RecordDrawBuild();
    uint32_t drawFlags = ctx.r4.u32;
    uint32_t drawType  = drawFlags & 7;

    s_lastDrawType  = drawType;
    s_lastDrawFlags = drawFlags;

    uint32_t ctx_guest = ctx.r3.u32;
    if (ctx_guest) {
        ::MclaGpuContext* gpuCtx = reinterpret_cast<::MclaGpuContext*>(base + ctx_guest);
        GetDrawAccumulator()->OnDrawBuild(gpuCtx, ctx);
    }

    static int ba8Count = 0;
    ba8Count++;
    if (ba8Count <= 5 || (ba8Count % 100 == 0)) {
        REXLOG_INFO("Sub82420BA8[%d] ctx=0x%08X flags=0x%08X type=%u "
                    "r6=0x%08X r7=0x%08X f1=%f  [{}]",
                    ba8Count, ctx.r3.u32, drawFlags, drawType,
                    ctx.r6.u32, ctx.r7.u32,
                    *reinterpret_cast<const float*>(&ctx.f1.u32),
                    mcla::renderer::GetRendererMode() == mcla::renderer::RendererMode::Native ? "NATIVE - bypassing PM4" : "LEGACY/CAPTURE");
    }

    // In Native mode, bypass PM4 draw emission entirely.
    if (mcla::renderer::GetRendererMode() != mcla::renderer::RendererMode::Native) {
        if (orig_Sub82420BA8) {
            orig_Sub82420BA8(ctx, base);
        }
    }
}

// â”€â”€ Hook: sub_8241ABB8 â€” SetViewport / SetRenderTargets state setup â”€â”€â”€â”€â”€â”€â”€

REX_FUNC(Hooked_Sub8241ABB8) {
    mcla::renderer::RecordStateSetup();
    uint32_t ctx_guest   = ctx.r3.u32;
    uint32_t src_state   = ctx.r4.u32;

    if (ctx_guest && src_state) {
        ::MclaGpuContext* gpuCtx = reinterpret_cast<::MclaGpuContext*>(base + ctx_guest);

        gpuCtx->rbSurfaceInfoP0 = REX_LOAD_U32(src_state + 108);
        gpuCtx->rbSurfaceInfoP1 = REX_LOAD_U32(src_state + 112);
        gpuCtx->rbSurfaceInfoP2 = REX_LOAD_U32(src_state + 116);
        gpuCtx->rbSurfaceInfoP3 = REX_LOAD_U32(src_state + 120);
        gpuCtx->rbSurfaceInfoP4 = REX_LOAD_U32(src_state + 124);

        GetDrawAccumulator()->OnStateSetup(gpuCtx, src_state);
    }

    if (orig_Sub8241ABB8) {
        orig_Sub8241ABB8(ctx, base);
    }
}

// â”€â”€ Hook: VdSwap â€” swap/flip â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€

static PPCFunc* orig_VdSwap = nullptr;

REX_FUNC(Hooked_VdSwap) {
    uint32_t obj        = ctx.r3.u32;   // swap chain object + 4
    uint32_t swap_info  = ctx.r4.u32;   // swap info struct

    static int swapCount = 0;
    swapCount++;
    if (swapCount <= 5) {
        REXLOG_INFO("VdSwap[%d] obj=0x%08X swap_info=0x%08X mode={}",
                    swapCount, obj, swap_info,
                    mcla::renderer::RendererModeName(mcla::renderer::GetRendererMode()));
    }

    GetDrawAccumulator()->OnFrameEnd();

    if (mcla::renderer::GetRendererMode() == mcla::renderer::RendererMode::Native) {
        // Native mode D3D12 clear & present
        auto* d3dBackend = GetD3D12Backend();
        if (!d3dBackend->IsInitialized()) {
            auto* runtime = rex::Runtime::instance();
            if (runtime && runtime->display_window()) {
                auto* win = runtime->display_window();
                HWND hwnd = reinterpret_cast<HWND>(win->GetNativeWindowHandle());
                if (hwnd) {
                    d3dBackend->Initialize(hwnd, win->GetActualPhysicalWidth(), win->GetActualPhysicalHeight());
                }
            }
        }

        if (d3dBackend->IsInitialized()) {
            static uint64_t s_nativeFrameCount = 0;
            s_nativeFrameCount++;
            // Phase 3: draw a meshed indexed triangle on the native path.
            // This proves buffer/upload, index, viewport, topology, and RTV
            // handling end-to-end without the Xenos command processor.
            d3dBackend->DrawTestMeshedTriangle(static_cast<uint32_t>(s_nativeFrameCount));

            // Low-noise aggregate: one structured line per 120th frame.
            const auto& stats = d3dBackend->Stats();
            static uint64_t s_nativeReportFrame = 0;
            if (s_nativeFrameCount % 120 == 0) {
                REXLOG_INFO("Native render phase3 frame={} draws={} uploaded_bytes_total={} cache_hits={} cache_misses={}",
                            s_nativeFrameCount, stats.drawsIssued, stats.uploadsBytes,
                            stats.cacheHits, stats.cacheMisses);
                (void)s_nativeReportFrame;
            }
        }
    } else {
        // Legacy / Capture mode chains to original SDK VdSwap
        if (orig_VdSwap) {
            orig_VdSwap(ctx, base);
        }
    }

    mcla::renderer::RecordFramePresented();
}

// â”€â”€ Install â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€

void InstallNativeRenderer(rex::runtime::FunctionDispatcher* dispatcher) {
    if (!dispatcher) {
        REXLOG_WARN("Native renderer: null dispatcher, skipping install");
        return;
    }

    // Run trace validation self-test
    if (!VerifyTraceFileForTests()) {
        REXLOG_ERROR("Native renderer: Phase 1 trace validation self-test FAILED");
    } else {
        REXLOG_INFO("Native renderer: Phase 1 trace validation self-test PASSED");
    }

    // Run guest-memory bounds self-test
    if (!VerifyGuestMemoryViewForTests()) {
        REXLOG_ERROR("Native renderer: guest memory view self-test FAILED");
    } else {
        REXLOG_INFO("Native renderer: guest memory view self-test PASSED");
    }

    // Initialize DrawPacket accumulator
    GetDrawAccumulator()->Initialize(nullptr);

    // Capture tracing only runs when the renderer mode is capture and the
    // native_renderer_trace CVar is not "off". The binary trace and its JSON
    // manifest are written into the cache directory when available.
    if (mcla::renderer::GetRendererMode() == mcla::renderer::RendererMode::Capture &&
        mcla::renderer::GetTraceMode() != mcla::renderer::TraceMode::Off) {
        std::filesystem::path tracePath = "mcla_capture.mclatrace";
        auto* runtime = rex::Runtime::instance();
        if (runtime && !runtime->cache_root().empty()) {
            tracePath = runtime->cache_root() / "mcla_capture.mclatrace";
        }
        GetDrawAccumulator()->SetCaptureEnabled(true, tracePath);
        REXLOG_INFO("Native renderer: Phase 1 DrawPacket capture ENABLED (trace={}, path={})",
                    mcla::renderer::TraceModeName(mcla::renderer::GetTraceMode()),
                    tracePath.string());
    } else {
        GetDrawAccumulator()->SetCaptureEnabled(false);
        REXLOG_INFO("Native renderer: Phase 1 DrawPacket capture disabled (mode={}, trace={})",
                    mcla::renderer::RendererModeName(mcla::renderer::GetRendererMode()),
                    mcla::renderer::TraceModeName(mcla::renderer::GetTraceMode()));
    }

    // Hook GfxCmdBufSubmit
    orig_GfxCmdBufSubmit = dispatcher->GetFunction(0x8241BD08);
    if (orig_GfxCmdBufSubmit) {
        dispatcher->SetFunction(0x8241BD08, Hooked_GfxCmdBufSubmit);
        if (!mcla::renderer::hooks::AddBeforeSubmitObserver(mcla::gpu::NotifyGpuSubmit)) {
            REXLOG_ERROR("Native renderer: failed to register GPU submit observer");
        }
#ifndef NDEBUG
        assert(mcla::renderer::hooks::VerifySubmitObserverOrderingForTests());
#endif
        REXLOG_INFO("Native renderer: GfxCmdBufSubmit hooked (single owner, {} observer(s))",
                    mcla::renderer::hooks::BeforeSubmitObserverCount());
    } else {
        REXLOG_WARN("Native renderer: GfxCmdBufSubmit not found");
    }

    // Hook sub_82420BA8
    orig_Sub82420BA8 = dispatcher->GetFunction(0x82420BA8);
    if (orig_Sub82420BA8) {
        dispatcher->SetFunction(0x82420BA8, Hooked_Sub82420BA8);
        REXLOG_INFO("Native renderer: sub_82420BA8 (draw builder) hooked - passthrough");
    } else {
        REXLOG_WARN("Native renderer: sub_82420BA8 not found");
    }

    // Hook sub_8241ABB8 (SetViewport / SetRenderTargets â€” captures state early)
    orig_Sub8241ABB8 = dispatcher->GetFunction(0x8241ABB8);
    if (orig_Sub8241ABB8) {
        dispatcher->SetFunction(0x8241ABB8, Hooked_Sub8241ABB8);
        REXLOG_INFO("Native renderer: sub_8241ABB8 (state setup) hooked");
    } else {
        REXLOG_WARN("Native renderer: sub_8241ABB8 not found");
    }

    // Hook VdSwap (swap/flip â€” chains to original SDK implementation)
    orig_VdSwap = dispatcher->GetFunction(0x827BD6E4);
    if (orig_VdSwap) {
        dispatcher->SetFunction(0x827BD6E4, Hooked_VdSwap);
        REXLOG_INFO("Native renderer: VdSwap hooked (passthrough)");
    } else {
        REXLOG_WARN("Native renderer: VdSwap not found");
    }
}

} // namespace mcla::native
