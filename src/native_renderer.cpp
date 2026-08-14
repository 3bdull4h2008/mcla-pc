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
#include "generated/default/mcla_init.h"
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
static PPCFunc* orig_GfxCmdBufSubmit = nullptr;
static PPCFunc* orig_Sub82420BA8     = nullptr;
static PPCFunc* orig_Sub8241ABB8     = nullptr;
static PPCFunc* orig_VdSwap          = nullptr;
static DrawCaptureCallback g_drawCaptureCb = nullptr;

// Host-side frame trace driver (stubbed - no ReXGlue command processor)
static constexpr std::chrono::milliseconds kHostTraceWarmup{3000};
static constexpr std::chrono::milliseconds kHostTraceWindow{1500};

void StartHostFrameTrace() {
    REXLOG_WARN("StartHostFrameTrace: not available in standalone mode (no ReXGlue command processor)");
}

// Draw-capture callback
void SetDrawCaptureCallback(DrawCaptureCallback cb) {
    g_drawCaptureCb = cb;
}

// Draw type / flags from latest sub_82420BA8 call
static uint32_t s_lastDrawType = 0;
static uint32_t s_lastDrawFlags = 0;

uint32_t GetLastDrawType()  { return s_lastDrawType; }
uint32_t GetLastDrawFlags() { return s_lastDrawFlags; }

// Register file sync - stubbed (no ReXGlue register file in standalone mode)
void WriteGpuContextToRegisterFile(::MclaGpuContext* gpuCtx) {
    (void)gpuCtx;
    // In standalone mode, we don't have a ReXGlue register file.
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

// Hook: sub_8241BD08 - GfxCmdBufSubmit
REX_FUNC(Hooked_GfxCmdBufSubmit) {
    mcla::renderer::RecordSubmit();
    mcla::renderer::hooks::DispatchBeforeSubmit(ctx, base);

    uint32_t ctx_guest = ctx.r3.u32;

    if (ctx_guest) {
        ::MclaGpuContext* gpuCtx = reinterpret_cast<::MclaGpuContext*>(base + ctx_guest);

        static int drawCount = 0;
        drawCount++;
        if (drawCount <= 5 || (drawCount % 100 == 0)) {
            REXLOG_INFO("GfxCmdBufSubmit[{}] ctx=0x%08X r4=0x%08X "
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

// Hook: sub_82420BA8 - Draw-call builder
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
        REXLOG_INFO("Sub82420BA8[{}] ctx=0x%08X flags=0x%08X type=%u "
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

// Hook: sub_8241ABB8 - SetViewport / SetRenderTargets state setup
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

// Native draw dispatch - now uses D3D12Backend directly
void IssueNativeDraw(::MclaGpuContext* gpuCtx) {
    (void)gpuCtx;
    REXLOG_WARN("IssueNativeDraw: legacy ReXGlue command processor path not available in standalone mode");
    // Native draws are now issued through the VdSwap hook -> D3D12Backend render graph
}

// VdSwap hook - native present path
namespace {

constexpr uint32_t kMaxConsumeBytes = 1u << 20;

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
    if (vsize + psize < vsize || vsize + psize < psize) {
        return false;
    }
    uint32_t containerSize = vsize + psize;
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
            desc.Format = ref.usage == 0 ? DXGI_FORMAT_R32G32B32_FLOAT
                                         : DXGI_FORMAT_R32G32B32A32_FLOAT;
            desc.AlignedByteOffset = fixtureOffset;
            fixtureOffset += ref.usage == 0 ? 12 : 16;
        }
        layout.push_back(desc);
    }
    return layout;
}

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

static DXGI_FORMAT DecodeColorTargetFormat(uint32_t colorInfo) {
    const uint32_t format = (colorInfo >> 16) & 0xF;
    switch (format) {
        case 0:  return DXGI_FORMAT_R8G8B8A8_UNORM;
        case 1:  return DXGI_FORMAT_R8G8B8A8_UNORM_SRGB;
        case 2:  return DXGI_FORMAT_R10G10B10A2_UNORM;
        case 3:  return DXGI_FORMAT_R10G10B10A2_UNORM;
        case 4:  return DXGI_FORMAT_R16G16_UNORM;
        case 5:  return DXGI_FORMAT_R16G16B16A16_UNORM;
        case 6:  return DXGI_FORMAT_R16G16_FLOAT;
        case 7:  return DXGI_FORMAT_R16G16B16A16_FLOAT;
        case 10: return DXGI_FORMAT_R10G10B10A2_UNORM;
        case 12: return DXGI_FORMAT_R16G16B16A16_FLOAT;
        case 14: return DXGI_FORMAT_R32_FLOAT;
        case 15: return DXGI_FORMAT_R32G32_FLOAT;
        default:
            REXLOG_WARN("Native render: unknown color target format {} (raw=0x{:08X})",
                        format, colorInfo);
            return DXGI_FORMAT_R8G8B8A8_UNORM;
    }
}

static DXGI_FORMAT DecodeDepthTargetFormat(uint32_t depthInfo) {
    const uint32_t format = (depthInfo >> 16) & 0x1;
    switch (format) {
        case 0: return DXGI_FORMAT_D24_UNORM_S8_UINT;
        case 1: return DXGI_FORMAT_D24_UNORM_S8_UINT;
        default:
            REXLOG_WARN("Native render: unknown depth target format {} (raw=0x{:08X})",
                        format, depthInfo);
            return DXGI_FORMAT_D24_UNORM_S8_UINT;
    }
}

static mcla::renderer::PipelineState
BuildPipelineStateFromPacket(const DrawPacket& packet) {
    mcla::renderer::PipelineState state = {};

    for (uint32_t i = 0; i < 4; ++i) {
        if (packet.colorTargets[i] != 0) {
            state.targetFormats[i] = DecodeColorTargetFormat(packet.colorTargets[i]);
        }
    }
    if (packet.depthTarget != 0) {
        state.depthStencilFormat = DecodeDepthTargetFormat(packet.depthTarget);
    }

    state.rasterState = packet.paClipCntl | (packet.paSuScModeCntl << 16);

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

static Microsoft::WRL::ComPtr<ID3D12PipelineState>
GetPipelineForPacket(D3D12Backend* backend, const DrawPacket& packet) {
    if (!packet.sqVsProgram || !packet.sqPsProgram) {
        return nullptr;
    }

    GuestMemoryView& memView = GetDrawAccumulator()->GetMemoryView();

    std::vector<uint8_t> vsContainer, psContainer;
    if (!ReadShaderContainerFromGuest(memView, packet.sqVsProgram, vsContainer)) {
        REXLOG_WARN("Failed to read VS container at 0x{:08X}", packet.sqVsProgram);
        return nullptr;
    }
    if (!ReadShaderContainerFromGuest(memView, packet.sqPsProgram, psContainer)) {
        REXLOG_WARN("Failed to read PS container at 0x{:08X}", packet.sqPsProgram);
        return nullptr;
    }

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

    mcla::renderer::ShaderProgram vsProg;
    if (!ParseShaderProgram(vsContainer.data(), vsContainer.size(), vsProg)) {
        REXLOG_WARN("Failed to parse VS IR at 0x{:08X}", packet.sqVsProgram);
        return nullptr;
    }

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
    if (packet->indexType != 2) return refuse("indexType != non-indexed(2)");
    if (packet->vertexStreamCount != 1) return refuse("vertexStreamCount != 1");

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
    desc.vertexCount = packet->indexCount;
    desc.indexed = false;

    Microsoft::WRL::ComPtr<ID3D12PipelineState> pipeline = GetPipelineForPacket(backend, *packet);
    if (!pipeline) {
        return refuse("no pipeline available");
    }

    return backend->DrawDynamicMeshWithPipeline(desc, pipeline.Get());
}

} // namespace

REX_FUNC(Hooked_VdSwap) {
    uint32_t obj        = ctx.r3.u32;
    uint32_t swap_info  = ctx.r4.u32;

    static int swapCount = 0;
    swapCount++;
    if (swapCount <= 5) {
        REXLOG_INFO("VdSwap[{}] obj=0x{:08X} swap_info=0x{:08X} mode={}",
                    swapCount, obj, swap_info,
                    mcla::renderer::RendererModeName(mcla::renderer::GetRendererMode()));
    }

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
        auto* d3dBackend = GetD3D12Backend();
        if (!d3dBackend->IsInitialized()) {
            auto* app = mcla::GetApp();
            if (app && app->GetHwnd()) {
                d3dBackend->Initialize(app->GetHwnd(), app->GetWidth(), app->GetHeight());
            }
        }

        if (d3dBackend->IsInitialized()) {
            static uint64_t s_nativeFrameCount = 0;
            s_nativeFrameCount++;

            auto graph = d3dBackend->CreateRenderGraph();

            bool consumed = false;
            if (haveCaptured) {
                graph.AddPass(L"ConsumeCapturedGeometry",
                    {},
                    [&](ID3D12GraphicsCommandList* cmdList) {
                        auto* backend = GetD3D12Backend();
                        if (TryConsumeCapturedGeometry(backend, &capturedSnapshot)) {
                        }
                    });
            }

            graph.AddPass(L"DrawTestTriangle",
                {},
                [&](ID3D12GraphicsCommandList* cmdList) {
                    auto* backend = GetD3D12Backend();
                    static uint64_t s_nativeFrameCount = 0;
                    s_nativeFrameCount++;
                    backend->DrawTestMeshedTriangle(static_cast<uint32_t>(s_nativeFrameCount));
                });

            if (graph.Build()) {
                graph.Execute();
            }
            graph.Reset();

            static uint64_t s_nativeReportFrame = 0;
            if (static_cast<uint64_t>(s_nativeFrameCount) % 120 == 0) {
                const auto& stats = d3dBackend->Stats();
                REXLOG_INFO("Native render frame={} draws={} uploaded_bytes_total={} cache_hits={} cache_misses={}",
                            s_nativeFrameCount, stats.drawsIssued, stats.uploadsBytes,
                            stats.cacheHits, stats.cacheMisses);
            }
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
        REXLOG_WARN("Native renderer: null dispatcher, skipping install");
        return;
    }

    const std::string_view mode = REXCVAR_GET(renderer_mode);
    if (mode == "compat") {
        REXLOG_WARN("Native renderer: COMPAT mode - no hooks installed "
                    "(backup 2026-07-16 parity)");
        return;
    }

    if (!BisectGroupEnabled("native")) {
        REXLOG_WARN("Native renderer: mcla_patch_groups excludes 'native' - "
                    "no hooks installed");
        return;
    }

    if (!VerifyTraceFileForTests()) {
        REXLOG_ERROR("Native renderer: Phase 1 trace validation self-test FAILED");
    } else {
        REXLOG_INFO("Native renderer: Phase 1 trace validation self-test PASSED");
    }

    if (!VerifyGuestMemoryViewForTests()) {
        REXLOG_ERROR("Native renderer: guest memory view self-test FAILED");
    } else {
        REXLOG_INFO("Native renderer: guest memory view self-test PASSED");
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
        REXLOG_INFO("Native renderer: Phase 1 DrawPacket capture ENABLED (trace={}, path={})",
                    mcla::renderer::TraceModeName(mcla::renderer::GetTraceMode()),
                    tracePath.string());
    } else {
        GetDrawAccumulator()->SetCaptureEnabled(false);
        REXLOG_INFO("Native renderer: Phase 1 DrawPacket capture disabled (mode={}, trace={})",
                    mcla::renderer::RendererModeName(mcla::renderer::GetRendererMode()),
                    mcla::renderer::TraceModeName(mcla::renderer::GetTraceMode()));
    }

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

    orig_Sub82420BA8 = dispatcher->GetFunction(0x82420BA8);
    if (orig_Sub82420BA8) {
        dispatcher->SetFunction(0x82420BA8, Hooked_Sub82420BA8);
        REXLOG_INFO("Native renderer: sub_82420BA8 (draw builder) hooked - passthrough");
    } else {
        REXLOG_WARN("Native renderer: sub_82420BA8 not found");
    }

    orig_Sub8241ABB8 = dispatcher->GetFunction(0x8241ABB8);
    if (orig_Sub8241ABB8) {
        dispatcher->SetFunction(0x8241ABB8, Hooked_Sub8241ABB8);
        REXLOG_INFO("Native renderer: sub_8241ABB8 (state setup) hooked");
    } else {
        REXLOG_WARN("Native renderer: sub_8241ABB8 not found");
    }

    dispatcher->SetFunction(0x827BD6E4, Hooked_VdSwap);
    REXLOG_INFO("Native renderer: VdSwap hooked");
}

} // namespace mcla::native