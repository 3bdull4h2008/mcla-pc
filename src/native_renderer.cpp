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

#include <cassert>
#include <chrono>
#include <filesystem>
#include <thread>
#include <unordered_set>
#include <vector>

namespace mcla::native {

// Internal state
// (2026-09-09 S1–S3 consolidation: the old Hooked_GfxCmdBufSubmit /
// Hooked_Sub82420BA8 dual-owner hooks were removed. gpu_device.cpp's
// strong-alias overrides are now the SINGLE owner of 0x8241BD08 / 0x82420BA8
// and carry the RecordSubmit/RecordDrawBuild + submit-observer + trace-feed
// duties. Golden rule 1 restored.)
static PPCFunc* orig_Sub8241ABB8     = nullptr;

// Host-side frame trace driver (stubbed - no legacy command processor)
static constexpr std::chrono::milliseconds kHostTraceWarmup{3000};
static constexpr std::chrono::milliseconds kHostTraceWindow{1500};

void StartHostFrameTrace() {
    MCLA_LOG_WARN("StartHostFrameTrace: not available in standalone mode (no legacy command processor)");
}

// Register file sync - stubbed (no legacy register file in standalone mode)
void WriteGpuContextToRegisterFile(::MclaGpuContext* gpuCtx) {
    (void)gpuCtx;
    // In standalone mode, we don't have a legacy register file.
    // Draw state is captured directly from guest context via hooks.
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

// Native draw dispatch - now uses D3D12Backend directly
void IssueNativeDraw(::MclaGpuContext* gpuCtx) {
    (void)gpuCtx;
    MCLA_LOG_WARN("IssueNativeDraw: legacy command processor path not available in standalone mode");
    // Native draws are now issued through the VdSwap hook -> D3D12Backend render graph
}

// VdSwap hook - native present path


PPC_FUNC_IMPL(Hooked_VdSwap) {
    uint32_t obj        = ctx.r3.u32;
    uint32_t swap_info  = ctx.r4.u32;

    static int swapCount = 0;
    swapCount++;
    if (swapCount <= 5) {
        MCLA_LOG_INFO("VdSwap[{}] obj=0x{:08X} swap_info=0x{:08X} mode={}",
                    swapCount, obj, swap_info,
                    mcla::renderer::RendererModeName(mcla::renderer::GetRendererMode()));
    }

    GetDrawAccumulator()->OnFrameEnd();

    if (mcla::renderer::GetRendererMode() == mcla::renderer::RendererMode::Native) {
        static uint64_t s_nativeFrameCount = 0;
        s_nativeFrameCount++;

        mcla::native::RenderCommand cmd;
        cmd.type = mcla::native::RenderCommand::PRESENT;
        auto& present = cmd.data.emplace<mcla::native::PresentCommand>();
        present.frameNumber = static_cast<uint32_t>(s_nativeFrameCount);
        present.obj = obj;
        present.swapInfo = swap_info;
        mcla::native::g_commandQueue.push(cmd);

        if (s_nativeFrameCount % 120 == 0) {
            MCLA_LOG_INFO("VdSwap[{}] enqueued PRESENT #{} (queue size: {})",
                        swapCount, s_nativeFrameCount, mcla::native::g_commandQueue.size());
        }
    } else {
        // Legacy / Capture mode - chain to original if needed for game logic
        // In standalone mode, there's no original SDK VdSwap to chain to
        // The game's VSync/swap logic runs in the PPC thread
    }

    mcla::renderer::RecordFramePresented();
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
    MCLA_LOG_INFO("Native renderer: VdSwap hooked");
}

} // namespace mcla::native

