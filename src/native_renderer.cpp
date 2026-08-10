#include "native_renderer.h"
#include "gpu_mmio.h"
#include "renderer_hook_dispatch.h"
#include "renderer_mode.h"
#include "capture_hooks.h"
#include "frame_trace.h"
#include "d3d12_backend.h"
#include "patches.h"
#include <rex/logging.h>
#include <rex/ui/window.h>
#include <cmath>
#include <rex/runtime.h>
#include <rex/graphics/graphics_system.h>
#include <rex/graphics/register_file.h>
#include <rex/graphics/command_processor.h>
#include "generated/default/mcla_init.h"
#include <rex/graphics/xenos.h>
#include "renderer/shader_translator.h"
#include "renderer/pipeline_cache.h"
#include "renderer/xenos_shader_ir.h"
#include "renderer/vertex_decode.h"
#include "renderer/grc_fvf_decode.h"

#include <cassert>
#include <chrono>
#include <filesystem>
#include <thread>
#include <unordered_set>
#include <vector>

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

// Host-side frame trace driver.  The game renders through the host GPU plugin
// (rexgpu-xenos.dll) on the command-processor worker thread, not through the
// guest PPC draw functions we hook, so the only complete record of real draws
// is the CommandProcessor's built-in TraceWriter (Xenia .xtr stream format).
//
// BeginTracing/EndTracing are virtual, dispatched through the vtable to the
// plugin's D3D12CommandProcessor, so they need no exported symbol on our side.
// They only set trace state and open/close the backing file; packet bytes are
// written on the CP worker thread itself while it drains the ring buffer.  A
// detached host thread waits a warm-up delay for the scene to settle, opens the
// trace for a capture window, then closes it, leaving <root>/{title:08X}_stream.xtr.
static constexpr std::chrono::milliseconds kHostTraceWarmup{3000};
static constexpr std::chrono::milliseconds kHostTraceWindow{1500};

void StartHostFrameTrace() {
    auto* cp = GetCommandProcessor();
    if (!cp) {
        REXLOG_WARN("StartHostFrameTrace: no command processor available");
        return;
    }

    auto* runtime = rex::Runtime::instance();
    std::filesystem::path root =
        (runtime && !runtime->cache_root().empty()) ? runtime->cache_root()
                                                    : std::filesystem::current_path();

    REXLOG_INFO("StartHostFrameTrace: scheduling Xenos .xtr capture under '{}'",
                root.string());

    // Must not block the caller; run the warm-up + Begin/End on a detached host
    // thread.  These are virtual (vtable dispatch), so they are safe to call
    // from any thread and require no exported SDK symbol.
    std::thread([cp, root]() {
        std::this_thread::sleep_for(kHostTraceWarmup);

        cp->BeginTracing(root);
        REXLOG_INFO("StartHostFrameTrace: BeginTracing under '{}'", root.string());

        // Let the CP keep draining the ring buffer and writing trace packets
        // for the capture window before closing the stream.
        std::this_thread::sleep_for(kHostTraceWindow);

        cp->EndTracing();
        REXLOG_INFO("StartHostFrameTrace: EndTracing complete");
    }).detach();
}

// reIssueDraw is a protected in CommandProcessor.  This shim exposes it as
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

namespace {

// Cap on a single consumed vertex range. Non-indexed MCLA city geometry is a
// few KB per stream; anything larger is treated as a bad capture rather than
// staging a multi-MB upload.
constexpr uint32_t kMaxConsumeBytes = 1u << 20;

// Read a raw .fxc shader container from guest memory at `guestAddr`. Returns
// true on success, filling `out` with the container bytes. Container geometry
// comes from the header (flags magic 0x102A1100, vsize at +4, psize at +8);
// the caller owns `out` and must have already validated the guest range.
static bool ReadShaderContainerFromGuest(GuestMemoryView& memView, uint32_t guestAddr,
                                         std::vector<uint8_t>& out) {
    uint32_t header[9] = {};
    if (!memView.IsValidRange(guestAddr, 36) ||
        !memView.ReadBytes(guestAddr, header, 36)) {
        return false;
    }

    uint32_t flags = renderer::AssembleBE32(reinterpret_cast<const uint8_t*>(header));
    if ((flags & 0xFFFFFF00) != 0x102A1100) {
        return false;
    }

    uint32_t vsize = renderer::AssembleBE32(reinterpret_cast<const uint8_t*>(&header[1]));
    uint32_t psize = renderer::AssembleBE32(reinterpret_cast<const uint8_t*>(header + 2));
    // Guard against 32-bit wrap on a malformed guest container; the parser
    // below bounds-checks against the actual container size.
    if (vsize + psize < vsize || vsize + psize < psize) {
        return false;
    }
    uint32_t containerSize = vsize + psize;
    // Reject implausibly large containers before allocating, and validate the
    // guest range before any allocation, so a malformed header cannot force a
    // giant buffer on the draw path.
    if (containerSize > 16 * 1024 * 1024) {
        return false;
    }
    if (!memView.IsValidRange(guestAddr, containerSize)) {
        return false;
    }

    out.resize(containerSize);
    if (!memView.ReadBytes(guestAddr, out.data(), containerSize)) {
        out.clear();
        return false;
    }
    return true;
}

// Extract vertex input layout from a parsed vertex shader program. Semantic
// name/index come from ReferencedVertexInputs — the exact entry-signature the
// translated HLSL declares, in first-fetch order — so the layout always agrees
// with the generated VS. Format resolution: a concrete Xenos vf code maps to
// its DXGI format; MCLA VFETCH embeds vf=0 so the format/stride live in a
// guest fetch-constant descriptor (Phase 3 capture evidence gap). Those
// elements fall back to the fixture layout (POSITION float3 @0 then COLOR
// float4 @12 = 28 bytes) that TryConsumeCapturedGeometry's stride==28 gate
// admits, matching the only VB the pipeline consumes today.
static std::vector<D3D12_INPUT_ELEMENT_DESC>
BuildInputLayoutFromVS(const mcla::renderer::ShaderProgram& vsProg) {
    std::vector<D3D12_INPUT_ELEMENT_DESC> layout;
    const auto refs = mcla::renderer::ReferencedVertexInputs(vsProg);
    layout.reserve(refs.size());

    uint32_t fixtureOffset = 0;
    for (const auto& ref : refs) {
        D3D12_INPUT_ELEMENT_DESC desc = {};
        desc.SemanticName = mcla::renderer::VertexUsageSemanticName(ref.usage);
        desc.SemanticIndex = ref.usageIndex;
        desc.InputSlot = 0;
        desc.InputSlotClass = D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA;
        desc.InstanceDataStepRate = 0;

        const VertexFormatDesc fd = DecodeVertexFormat(ref.vertexFormat);
        if (fd.valid && fd.dxgiFormat != 0) {
            desc.Format = static_cast<DXGI_FORMAT>(fd.dxgiFormat);
            desc.AlignedByteOffset = ref.offset;
        } else {
            // Unresolvable vf (MCLA vf=0): use the fixture VB layout the
            // consume gate requires. No invented format/stride.
            desc.Format = ref.usage == 0 ? DXGI_FORMAT_R32G32B32_FLOAT
                                         : DXGI_FORMAT_R32G32B32A32_FLOAT;
            desc.AlignedByteOffset = fixtureOffset;
            fixtureOffset += ref.usage == 0 ? 12 : 16;
        }
        layout.push_back(desc);
    }
    return layout;
}

// Hash the vertex declaration referenced by a VS (vf + usage + usageIndex
// triples). Returns 0 when any element is unresolved (MCLA vf=0), which is the
// documented Phase 3 evidence gap; a 0 vertexDeclHash keeps such keys distinct
// from any resolvable declaration.
static uint64_t HashVsVertexDeclaration(const mcla::renderer::ShaderProgram& vsProg) {
    const auto refs = mcla::renderer::ReferencedVertexInputs(vsProg);
    std::vector<uint32_t> vf;
    std::vector<uint8_t> usage, usageIndex;
    vf.reserve(refs.size());
    usage.reserve(refs.size());
    usageIndex.reserve(refs.size());
    for (const auto& r : refs) {
        vf.push_back(r.vertexFormat);
        usage.push_back(static_cast<uint8_t>(r.usage));
        usageIndex.push_back(static_cast<uint8_t>(r.usageIndex));
    }
    return HashVertexDeclaration(vf.data(), usage.data(), usageIndex.data(),
                                 static_cast<uint32_t>(vf.size()));
}

// Resolve the captured RAGE drawable vertex declaration (grcFvf) when the
// packet carries one. Fills `layout` (D3D12 input elements) and `declHash`
// (PipelineKey vertexDeclHash) from the decoded declaration and returns true.
//
// Cross-check: every vertex input the VS references must resolve to a decoded
// channel. The drawable may declare more channels than the current VS uses
// (extra channels stay in the stride and are included in the input layout),
// but a referenced-but-absent element is refused, never defaulted (Golden
// Rule 5).
//
// When the packet has no captured grcFvf (live drawable pointer chain still
// unproven - no game draw reached a hook yet), falls back to the documented
// Phase-3 stopgap: the fixture layout from the VS referenced inputs plus
// HashVsVertexDeclaration (which yields 0 for MCLA vf=0). A one-time
// deduplicated diagnostic keeps the evidence gap loud without frame spam.
static bool ResolveCapturedVertexLayout(
    const DrawPacket& packet, const mcla::renderer::ShaderProgram& vsProg,
    std::vector<D3D12_INPUT_ELEMENT_DESC>& layout, uint64_t& declHash) {
    static std::unordered_set<std::string> s_emittedReasons;

    auto refuse = [&](const char* reason) {
        std::string key(reason);
        if (s_emittedReasons.insert(key).second) {
            REXLOG_WARN("Native render: captured grcFvf layout refused ({})", reason);
        }
        layout.clear();
        declHash = 0;
        return false;
    };

    if (!packet.hasGrcFvf) {
        if (s_emittedReasons.insert("no captured grcFvf (live drawable pointer chain unproven)").second) {
            REXLOG_WARN("Native render: packet has no captured grcFvf (live drawable "
                        "pointer chain unproven); using fixture layout stopgap, stride==28 gate");
        }
        layout = BuildInputLayoutFromVS(vsProg);
        declHash = HashVsVertexDeclaration(vsProg);
        return !layout.empty();
    }

    const mcla::native::GrcFvfDeclaration decl = mcla::native::DecodeGrcFvf(packet.grcFvf);
    if (!decl.valid) {
        return refuse(decl.unknownChannel
                          ? "captured grcFvf has an unknown channel type"
                          : "captured grcFvf empty/invalid");
    }
    if (decl.sizeMismatch) {
        return refuse("captured grcFvf stride inconsistency (fvfSize != channel sum)");
    }

    mcla::native::GrcFvfLayoutEntry entries[mcla::native::kGrcFvfChannelCount];
    uint32_t entryCount = 0;
    if (!mcla::native::BuildGrcFvfLayout(decl, entries, entryCount) || entryCount == 0) {
        return refuse("captured grcFvf produced no usable layout");
    }

    const auto refs = mcla::renderer::ReferencedVertexInputs(vsProg);
    for (const auto& r : refs) {
        bool found = false;
        for (uint32_t i = 0; i < entryCount; ++i) {
            if (entries[i].usage == r.usage && entries[i].usageIndex == r.usageIndex) {
                found = true;
                break;
            }
        }
        if (!found) {
            REXLOG_WARN("Native render: VS references (usage={},idx={}) missing from "
                        "captured grcFvf; refusing",
                        (int)r.usage, (int)r.usageIndex);
            return refuse("VS input missing from captured grcFvf");
        }
    }

    std::vector<D3D12_INPUT_ELEMENT_DESC> out;
    out.reserve(entryCount);
    for (uint32_t i = 0; i < entryCount; ++i) {
        D3D12_INPUT_ELEMENT_DESC desc = {};
        desc.SemanticName = mcla::renderer::VertexUsageSemanticName(entries[i].usage);
        desc.SemanticIndex = entries[i].usageIndex;
        desc.InputSlot = 0;
        desc.InputSlotClass = D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA;
        desc.InstanceDataStepRate = 0;
        desc.Format = static_cast<DXGI_FORMAT>(entries[i].dxgiFormat);
        desc.AlignedByteOffset = entries[i].byteOffset;
        out.push_back(desc);
    }

    layout = std::move(out);
    declHash = mcla::native::HashGrcFvfDeclaration(decl);
    return true;
}

// Xenos/XenosRecomp-researched surface format mappings.
// RB_COLOR_INFO: bits 16-19 = ColorRenderTargetFormat (4 bits)
// RB_DEPTH_INFO: bit 16 = DepthRenderTargetFormat (1 bit)
//
// ColorRenderTargetFormat enum (Xenia xenos.h):
//   0  k_8_8_8_8
//   1  k_8_8_8_8_GAMMA
//   2  k_2_10_10_10
//   3  k_2_10_10_10_FLOAT  (7e3 float)
//   4  k_16_16
//   5  k_16_16_16_16
//   6  k_16_16_FLOAT
//   7  k_16_16_16_16_FLOAT
//   10 k_2_10_10_10_AS_10_10_10_10
//   12 k_2_10_10_10_FLOAT_AS_16_16_16_16
//   14 k_32_FLOAT
//   15 k_32_32_FLOAT
//
// DepthRenderTargetFormat enum:
//   0  kD24S8
//   1  kD24FS8  (float depth, 20e4)

static DXGI_FORMAT DecodeColorTargetFormat(uint32_t colorInfo) {
    // Extract color_format from bits 16-19
    const uint32_t format = (colorInfo >> 16) & 0xF;
    switch (format) {
        case 0:  return DXGI_FORMAT_R8G8B8A8_UNORM;              // k_8_8_8_8
        case 1:  return DXGI_FORMAT_R8G8B8A8_UNORM_SRGB;         // k_8_8_8_8_GAMMA
        case 2:  return DXGI_FORMAT_R10G10B10A2_UNORM;           // k_2_10_10_10
        case 3:  return DXGI_FORMAT_R10G10B10A2_UNORM;           // k_2_10_10_10_FLOAT (7e3) - same storage
        case 4:  return DXGI_FORMAT_R16G16_UNORM;                // k_16_16
        case 5:  return DXGI_FORMAT_R16G16B16A16_UNORM;          // k_16_16_16_16
        case 6:  return DXGI_FORMAT_R16G16_FLOAT;                // k_16_16_FLOAT
        case 7:  return DXGI_FORMAT_R16G16B16A16_FLOAT;          // k_16_16_16_16_FLOAT
        case 10: return DXGI_FORMAT_R10G10B10A2_UNORM;           // k_2_10_10_10_AS_10_10_10_10
        case 12: return DXGI_FORMAT_R16G16B16A16_FLOAT;          // k_2_10_10_10_FLOAT_AS_16_16_16_16
        case 14: return DXGI_FORMAT_R32_FLOAT;                   // k_32_FLOAT
        case 15: return DXGI_FORMAT_R32G32_FLOAT;                // k_32_32_FLOAT
        default:
            REXLOG_WARN("Native render: unknown color target format {} (raw=0x{:08X})",
                        format, colorInfo);
            return DXGI_FORMAT_R8G8B8A8_UNORM;
    }
}

static DXGI_FORMAT DecodeDepthTargetFormat(uint32_t depthInfo) {
    // Extract depth_format from bit 16
    const uint32_t format = (depthInfo >> 16) & 0x1;
    switch (format) {
        case 0: return DXGI_FORMAT_D24_UNORM_S8_UINT;            // kD24S8
        case 1: return DXGI_FORMAT_D24_UNORM_S8_UINT;            // kD24FS8 (float depth, 20e4) - same storage
        default:
            REXLOG_WARN("Native render: unknown depth target format {} (raw=0x{:08X})",
                        format, depthInfo);
            return DXGI_FORMAT_D24_UNORM_S8_UINT;
    }
}

// Build a PipelineState from a DrawPacket's captured render state.
static mcla::renderer::PipelineState
BuildPipelineStateFromPacket(const DrawPacket& packet) {
    mcla::renderer::PipelineState state = {};

    // Render target formats from Xenos RB_COLOR_INFO / RB_DEPTH_INFO registers.
    for (uint32_t i = 0; i < 4; ++i) {
        if (packet.colorTargets[i] != 0) {
            state.targetFormats[i] = DecodeColorTargetFormat(packet.colorTargets[i]);
        }
    }
    if (packet.depthTarget != 0) {
        state.depthStencilFormat = DecodeDepthTargetFormat(packet.depthTarget);
    }

    // Rasterizer state from PA registers
    state.rasterState = packet.paClipCntl | (packet.paSuScModeCntl << 16);

    // Primitive topology
    switch (packet.primType) {
        case 0: state.topology = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE; break;
        case 1: state.topology = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE; break;
        case 2: state.topology = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE; break;
        case 3: state.topology = D3D12_PRIMITIVE_TOPOLOGY_TYPE_LINE; break;
        case 4: state.topology = D3D12_PRIMITIVE_TOPOLOGY_TYPE_POINT; break;
        default: state.topology = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE; break;
    }
    state.sampleCount = 1;

    return state;
}

// Try to get or compile a PSO for the captured draw packet.
// Returns the PSO to use (fallback test PSO if compilation in progress).
static Microsoft::WRL::ComPtr<ID3D12PipelineState>
GetPipelineForPacket(D3D12Backend* backend, const DrawPacket& packet) {
    if (!packet.sqVsProgram || !packet.sqPsProgram) {
        return nullptr;
    }

    // Get the memory view from the accumulator
    GuestMemoryView& memView = GetDrawAccumulator()->GetMemoryView();

    // Read the raw guest VS/PS containers; they feed both the translator
    // (real HLSL) and the IR parse (guest vertex input layout).
    std::vector<uint8_t> vsContainer, psContainer;
    if (!ReadShaderContainerFromGuest(memView, packet.sqVsProgram, vsContainer)) {
        REXLOG_WARN("Failed to read VS container at 0x{:08X}", packet.sqVsProgram);
        return nullptr;
    }
    if (!ReadShaderContainerFromGuest(memView, packet.sqPsProgram, psContainer)) {
        REXLOG_WARN("Failed to read PS container at 0x{:08X}", packet.sqPsProgram);
        return nullptr;
    }

    // Translate the captured guest microcode to HLSL (real shaders, not the
    // test fixtures). The offline corpus gate validates every generated HLSL
    // with dxc.exe, so non-empty HLSL here is compilable on the worker.
    mcla::renderer::TranslatedShader vsOut, psOut;
    if (!mcla::renderer::TranslateShader(vsContainer.data(), vsContainer.size(), {}, vsOut) ||
        vsOut.hlsl.empty()) {
        REXLOG_WARN("Failed to translate VS at 0x{:08X}: {}", packet.sqVsProgram, vsOut.error);
        return nullptr;
    }
    if (!mcla::renderer::TranslateShader(psContainer.data(), psContainer.size(), {}, psOut) ||
        psOut.hlsl.empty()) {
        REXLOG_WARN("Failed to translate PS at 0x{:08X}: {}", packet.sqPsProgram, psOut.error);
        return nullptr;
    }

    // Parse the VS into the IR for the guest input layout.
    mcla::renderer::ShaderProgram vsProg;
    if (!ParseShaderProgram(vsContainer.data(), vsContainer.size(), vsProg)) {
        REXLOG_WARN("Failed to parse VS IR at 0x{:08X}", packet.sqVsProgram);
        return nullptr;
    }

    // Build pipeline key from the translated program hashes + guest vertex
    // declaration. GetOrCompile compiles HLSL in the background and returns
    // the fallback PSO immediately, so the draw never stalls.
    mcla::renderer::PipelineState state = BuildPipelineStateFromPacket(packet);
    uint64_t vertexDeclHash = 0;
    std::vector<D3D12_INPUT_ELEMENT_DESC> inputLayout;
    if (!ResolveCapturedVertexLayout(packet, vsProg, inputLayout, vertexDeclHash)) {
        return nullptr;
    }
    mcla::renderer::PipelineKey key = mcla::renderer::ComputePipelineKey(
        vsOut.programHash, psOut.programHash, vertexDeclHash, state);

    auto& cache = backend->GetPipelineCache();
    return cache.GetOrCompile(key, vsOut.hlsl, psOut.hlsl, inputLayout);
}

// Attempt to consume the most recently captured DrawPacket as native
// geometry. Returns true when the packet passes the layout gate AND the draw
// was submitted; false otherwise (caller falls back to the fixture quad).
// Refusals are emitted once per reason (deduplicated) so a non-matching
// capture stays quiet after the first frame.
bool TryConsumeCapturedGeometry(D3D12Backend* backend, const DrawPacket* packet) {
    static std::unordered_set<std::string> s_emittedReasons;

    auto refuse = [&](const char* reason) {
        std::string key(reason);
        if (s_emittedReasons.insert(key).second) {
            REXLOG_WARN("Native render: captured draw not consumable ({}) \u2014 falling back to fixture quad",
                        reason);
        }
        return false;
    };

    if (!backend) return false;
    if (!packet || !packet->isValid) return refuse("packet not valid");
    if (packet->primType != 0) return refuse("primType != TriList(0)");
    // The test PSO input layout is non-indexed-only; consuming an indexed draw
    // would require proving the captured index buffer layout, which no capture
    // evidence supports yet.
    if (packet->indexType != 2) return refuse("indexType != non-indexed(2)");
    if (packet->vertexStreamCount != 1) return refuse("vertexStreamCount != 1");
    // Expected stride: from the captured grcFvf declaration when present
    // (Phase 8 item 1), otherwise the fixture (test) input layout's 28 bytes.
    uint32_t expectedStride = 28;
    if (packet->hasGrcFvf) {
        const mcla::native::GrcFvfDeclaration decl = mcla::native::DecodeGrcFvf(packet->grcFvf);
        if (!decl.valid || decl.unknownChannel || decl.sizeMismatch) {
            return refuse("captured grcFvf not usable for stride gate");
        }
        expectedStride = decl.computedStride;
    }
    const uint32_t stride = packet->vertexStreams[0].stride;
    if (stride != expectedStride) return refuse("vertex stride != declared grcFvf stride");
    if (packet->indexCount == 0) return refuse("indexCount == 0");

    const VertexStreamDesc& vs = packet->vertexStreams[0];
    const uint64_t bytesNeeded = static_cast<uint64_t>(packet->indexCount) * stride;
    if (bytesNeeded > kMaxConsumeBytes) return refuse("vertex range exceeds 1 MiB cap");
    if (bytesNeeded == 0) return refuse("vertex range empty");

    std::vector<uint8_t> vb(static_cast<size_t>(bytesNeeded));
    if (!GetDrawAccumulator()->ReadGuestRange(vs.guestAddress + vs.offset,
                                              static_cast<uint32_t>(bytesNeeded),
                                              vb.data())) {
        return refuse("guest vertex range not fully mapped");
    }

    D3D12Backend::DynamicMeshDesc desc = {};
    desc.vertexBytes = vb.data();
    desc.vertexBytesSize = static_cast<uint32_t>(bytesNeeded);
    desc.vertexStride = stride;
    desc.vertexCount = packet->indexCount;  // non-indexed: indexCount is vertex count
    desc.indexed = false;

    // Get the PSO for this packet from the pipeline cache. On a cache miss
    // GetOrCompile returns the fallback (test) PSO immediately and queues the
    // real PSO for background compilation, so the draw never stalls.
    Microsoft::WRL::ComPtr<ID3D12PipelineState> pipeline = GetPipelineForPacket(backend, *packet);
    if (!pipeline) {
        return refuse("no pipeline available");
    }

    return backend->DrawDynamicMeshWithPipeline(desc, pipeline.Get());
}

REX_FUNC(Hooked_VdSwap) {
    uint32_t obj        = ctx.r3.u32;   // swap chain object + 4
    uint32_t swap_info  = ctx.r4.u32;   // swap info struct

    static int swapCount = 0;
    swapCount++;
    if (swapCount <= 5) {
        REXLOG_INFO("VdSwap[{}] obj=0x{:08X} swap_info=0x{:08X} mode={}",
                    swapCount, obj, swap_info,
                    mcla::renderer::RendererModeName(mcla::renderer::GetRendererMode()));
    }

    // Snapshot the last validated packet BEFORE OnFrameEnd clears it; the
    // accumulator zeroes m_lastPacket at frame end, so reading it afterwards
    // would always fail and the consumption path would stay dead forever.
    DrawPacket capturedSnapshot{};
    bool haveCaptured = false;
    {
        const DrawPacket* captured = nullptr;
        if (GetDrawAccumulator()->LastPacket(captured)) {
            capturedSnapshot = *captured;
            haveCaptured = true;
        }
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

            // Build and execute the render graph for this frame
            auto graph = d3dBackend->CreateRenderGraph();

            // Pass 1: Geometry consumption (if captured packet available)
            bool consumed = false;
            if (haveCaptured) {
                graph.AddPass(L"ConsumeCapturedGeometry",
                    {
                        // No specific resources tracked yet - we'll track them better once live captures work
                    },
                    [&](ID3D12GraphicsCommandList* cmdList) {
                        auto* backend = GetD3D12Backend();
                        if (TryConsumeCapturedGeometry(backend, &capturedSnapshot)) {
                            // Mark as consumed - the actual draw happens inside TryConsumeCapturedGeometry
                        }
                    });
            }

            // Pass 2: Fallback test triangle (always runs if geometry not consumed)
            // This pass writes to the back buffer RTV
            graph.AddPass(L"DrawTestTriangle",
                {},
                [&](ID3D12GraphicsCommandList* cmdList) {
                    auto* backend = GetD3D12Backend();
                    static uint64_t s_nativeFrameCount = 0;
                    s_nativeFrameCount++;
                    backend->DrawTestMeshedTriangle(static_cast<uint32_t>(s_nativeFrameCount));
                });

            // Execute the render graph
            if (graph.Build()) {
                graph.Execute();
            }
            graph.Reset();

            // Low-noise aggregate: one structured line per 120th frame.
            static uint64_t s_nativeReportFrame = 0;
            if (static_cast<uint64_t>(s_nativeFrameCount) % 120 == 0) {
                const auto& stats = d3dBackend->Stats();
                REXLOG_INFO("Native render frame={} draws={} uploaded_bytes_total={} cache_hits={} cache_misses={}",
                            s_nativeFrameCount, stats.drawsIssued, stats.uploadsBytes,
                            stats.cacheHits, stats.cacheMisses);
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

} // namespace

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

        // Also drive the runtime's own built-in frame trace (.xtr).  The real
        // draws execute on the host GPU-plugin CP thread, which the guest PPC
        // hooks never see; this is the only complete record of them.  Runs in
        // parallel on a detached thread, so the app keeps booting normally.
        StartHostFrameTrace();
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

    // Hook VdSwap (swap/flip — chains to original SDK implementation).
    // The generated recompiled code calls __imp__VdSwap via a DIRECT
    // relative call to the import-library JMP thunk, which bypasses
    // FunctionDispatcher::SetFunction (indirect/dispatcher calls only).
    // Detour the thunk itself so ALL call paths (direct, dispatcher, JIT)
    // hit our hook; keep the dispatcher entry set for indirect routing.
    dispatcher->SetFunction(0x827BD6E4, Hooked_VdSwap);
    orig_VdSwap = mcla_DetourImportThunk(
        reinterpret_cast<uint8_t*>(reinterpret_cast<void*>(&__imp__VdSwap)),
        Hooked_VdSwap);
    if (orig_VdSwap) {
        REXLOG_INFO("Native renderer: VdSwap import thunk detoured (passthrough)");
    } else {
        REXLOG_WARN("Native renderer: VdSwap import thunk detour failed; "
                    "falling back to dispatcher entry only");
    }
}

} // namespace mcla::native
