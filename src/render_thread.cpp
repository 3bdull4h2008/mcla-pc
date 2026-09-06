#include "render_thread.h"
#include "logging.h"
#include "generated/ppc_xenon/ppc_recomp_shared.h"
#include "kernel/memory.h"
#include "renderer/shader_translator.h"
#include "renderer/pipeline_cache.h"
#include "renderer/xenos_shader_ir.h"
#include "renderer/grc_fvf_decode.h"
#include "d3d12_backend.h"
#include <chrono>
#include <unordered_map>

namespace mcla::native {

// Frame pacing: target 30fps (33.33ms per frame)
static constexpr double kTargetFrameSeconds = 1.0 / 30.0;
// Queue depth warning threshold
static constexpr uint32_t kQueueDepthWarning = 30;
// Queue depth drop threshold: if queue is this deep, skip non-critical commands
static constexpr uint32_t kQueueDepthDrop = 60;

RenderThread g_renderThread;
CommandQueue g_commandQueue;

RenderThread::RenderThread() : running_(false), shouldStop_(false) {}

RenderThread::~RenderThread() {
    stop();
}

void RenderThread::SetWindowParams(void* hwnd, uint32_t width, uint32_t height) {
    pendingHwnd_ = hwnd;
    pendingWidth_ = width;
    pendingHeight_ = height;
}

void RenderThread::start() {
    if (running_) return;

    running_ = true;
    shouldStop_ = false;
    MCLA_LOG_INFO("RenderThread: started");
    thread_ = std::thread(&RenderThread::threadMain, this);
}

void RenderThread::stop() {
    if (!running_) return;

    shouldStop_ = true;
    g_commandQueue.shutdown();

    if (thread_.joinable()) {
        thread_.join();
    }

    if (d3d12Initialized_) {
        backend_.GetPipelineCache().StopWorker();
        backend_.Shutdown();
        d3d12Initialized_ = false;
    }

    running_ = false;
    MCLA_LOG_INFO("RenderThread: stopped");
}

void RenderThread::threadMain() {
    MCLA_LOG_INFO("RenderThread: entering command loop");

    if (pendingHwnd_ && !d3d12Initialized_) {
        if (backend_.Initialize(static_cast<HWND>(pendingHwnd_), pendingWidth_, pendingHeight_)) {
            d3d12Initialized_ = true;
            MCLA_LOG_INFO("RenderThread: D3D12 initialized on thread start ({}x{})",
                          pendingWidth_, pendingHeight_);
            // Start the pipeline cache async compilation worker
            backend_.GetPipelineCache().StartWorker(
                backend_.GetDevice(), backend_.GetRootSignature());
            MCLA_LOG_INFO("RenderThread: PipelineCache worker started");
        } else {
            MCLA_LOG_ERROR("RenderThread: D3D12 initialization failed on thread start");
        }
    }

    while (!shouldStop_) {
        RenderCommand cmd;
        if (!g_commandQueue.pop(cmd)) {
            break;
        }

        // Queue depth monitoring
        const size_t qDepth = g_commandQueue.size();
        if (qDepth >= kQueueDepthDrop) {
            // Queue dangerously deep — skip non-critical commands
            if (cmd.type == RenderCommand::SET_RENDER_STATE ||
                cmd.type == RenderCommand::SET_PIPELINE_STATE ||
                cmd.type == RenderCommand::SET_VERTEX_BUFFERS ||
                cmd.type == RenderCommand::SET_INDEX_BUFFER ||
                cmd.type == RenderCommand::DRAW_INDEXED ||
                cmd.type == RenderCommand::NOOP) {
                static std::atomic<uint32_t> dropCount{0};
                const uint32_t n = dropCount.fetch_add(1) + 1;
                if (n <= 5 || (n % 100) == 0)
                    MCLA_LOG_WARN("RenderThread: DROPPED cmd type={} queueDepth={} (total dropped={})",
                                  static_cast<int>(cmd.type), qDepth, n);
                continue;
            }
        } else if (qDepth >= kQueueDepthWarning) {
            static std::atomic<uint32_t> warnCount{0};
            const uint32_t n = warnCount.fetch_add(1) + 1;
            if (n <= 5 || (n % 100) == 0)
                MCLA_LOG_WARN("RenderThread: queue depth {} (warning threshold={})",
                              qDepth, kQueueDepthWarning);
        }

        processCommand(cmd);
    }

    if (d3d12Initialized_) {
        backend_.WaitForGpu();
    }

    MCLA_LOG_INFO("RenderThread: exiting command loop");
}

// ---------------------------------------------------------------------------
// Shader container reader: reads a Xenos .fxc container from guest memory.
// Returns the raw container bytes. Returns empty on failure.
// ---------------------------------------------------------------------------
static std::vector<uint8_t> ReadShaderContainer(mcla::kernel::GuestMemoryHeap& mem,
                                                 uint32_t guestAddr) {
    if (guestAddr == 0) return {};

    uint32_t header[9] = {};
    if (!mem.IsValid(guestAddr, 36) ||
        !mem.ReadBytes(guestAddr, header, 36)) {
        return {};
    }

    // Validate container header: flags field must have (flags & 0xFFFFFF00) == 0x102A1100
    const uint32_t flags = mcla::renderer::AssembleBE32(
        reinterpret_cast<const uint8_t*>(header));
    if ((flags & 0xFFFFFF00) != 0x102A1100) {
        return {};
    }

    const uint32_t vsize = mcla::renderer::AssembleBE32(
        reinterpret_cast<const uint8_t*>(&header[1]));
    const uint32_t psize = mcla::renderer::AssembleBE32(
        reinterpret_cast<const uint8_t*>(header + 2));
    if (vsize + psize < vsize || vsize + psize < psize) {
        return {};
    }

    const uint32_t totalSize = 36 + vsize + psize;  // header(36) + virtual + physical
    std::vector<uint8_t> container(totalSize);
    // Copy the already-read header
    std::memcpy(container.data(), header, 36);
    // Read the rest
    if (!mem.ReadBytes(guestAddr + 36, container.data() + 36, totalSize - 36)) {
        return {};
    }

    return container;
}

// ---------------------------------------------------------------------------
// PSO lookup stats
// ---------------------------------------------------------------------------
static std::atomic<uint32_t> s_psoCacheHits{0};
static std::atomic<uint32_t> s_psoCacheMisses{0};
static std::atomic<uint32_t> s_psoTranslateFailures{0};

void RenderThread::processCommand(const RenderCommand& cmd) {
    switch (cmd.type) {
        case RenderCommand::INIT_D3D12: {
            const auto& init = std::get<InitD3D12Command>(cmd.data);
            if (!d3d12Initialized_) {
                if (backend_.Initialize(static_cast<HWND>(init.hwnd), init.width, init.height)) {
                    d3d12Initialized_ = true;
                    MCLA_LOG_INFO("RenderThread: D3D12 initialized ({}x{})", init.width, init.height);
                } else {
                    MCLA_LOG_ERROR("RenderThread: D3D12 initialization failed");
                }
            }
            break;
        }
        case RenderCommand::DRAW_INDEXED: {
            if (!d3d12Initialized_) break;
            const auto& d = std::get<DrawIndexedCommand>(cmd.data);
            static std::atomic<uint32_t> drawCount{0};
            const uint32_t n = drawCount.fetch_add(1) + 1;
            if (n <= 20 || (n % 1000) == 0)
                MCLA_LOG_INFO("RenderThread: DRAW_INDEXED #{} prim={} vb={:08X} ib={:08X} "
                              "count={} stride={} vbSize={} ibSize={} vs={:08X} ps={:08X}",
                              n, d.primitiveTopology, d.vbAddr, d.ibAddr,
                              d.indexCount, d.vbStride, d.vbSize, d.ibSize,
                              d.vsProgram, d.psProgram);

            if (d.vbAddr == 0 || d.vbSize == 0 || d.ibAddr == 0 || d.ibSize == 0 || d.indexCount == 0) break;

            auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
            std::vector<uint8_t> vb(d.vbSize);
            std::vector<uint8_t> ib(d.ibSize);
            if (!mem.ReadBytes(d.vbAddr, vb.data(), d.vbSize)) break;
            if (!mem.ReadBytes(d.ibAddr, ib.data(), d.ibSize)) break;

            // Attempt PSO lookup from shader programs
            ID3D12PipelineState* pipeline = nullptr;
            Microsoft::WRL::ComPtr<ID3D12PipelineState> cachedPso;

            if (d.vsProgram != 0 && d.psProgram != 0) {
                // Read shader containers from guest memory
                auto vsContainer = ReadShaderContainer(mem, d.vsProgram);
                auto psContainer = ReadShaderContainer(mem, d.psProgram);

                if (!vsContainer.empty() && !psContainer.empty()) {
                    // Translate shaders to HLSL
                    mcla::renderer::TranslatedShader vsOut, psOut;
                    bool vsOk = mcla::renderer::TranslateShader(
                        vsContainer.data(), vsContainer.size(), {}, vsOut);
                    bool psOk = mcla::renderer::TranslateShader(
                        psContainer.data(), psContainer.size(), {}, psOut);

                    if (vsOk && psOk && !vsOut.hlsl.empty() && !psOut.hlsl.empty()) {
                        // Parse VS IR for vertex input layout
                        mcla::renderer::ShaderProgram vsProg;
                        if (mcla::renderer::ParseShaderProgram(
                                vsContainer.data(), vsContainer.size(), vsProg)) {

                            // Build input layout: prefer grcFvf if available,
                            // otherwise fall back to VS reflection
                            std::vector<D3D12_INPUT_ELEMENT_DESC> inputLayout;
                            uint64_t vertexDeclHash = 0;

                            if (d.hasGrcFvf && d.fvfMask != 0 && d.fvfSize != 0) {
                                // Build from grcFvf
                                GrcFvfDesc fvf{};
                                fvf.fvfMask = d.fvfMask;
                                fvf.fvfSize = d.fvfSize;
                                fvf.flags = d.fvfFlags;
                                fvf.dynamicOrder = d.fvfDynamicOrder;
                                fvf.channelCount = d.fvfChannelCount;
                                fvf.types = d.fvfTypes;
                                inputLayout = backend_.BuildInputLayoutFromGrcFvf(fvf);
                                if (!inputLayout.empty()) {
                                    vertexDeclHash = mcla::native::HashGrcFvfDeclaration(
                                        mcla::native::DecodeGrcFvf(fvf));
                                }
                            }

                            // Fallback: build from VS reflection
                            if (inputLayout.empty()) {
                                const auto refs = mcla::renderer::ReferencedVertexInputs(vsProg);
                                for (const auto& r : refs) {
                                    D3D12_INPUT_ELEMENT_DESC desc = {};
                                    desc.SemanticName = mcla::renderer::VertexUsageSemanticName(r.usage);
                                    desc.SemanticIndex = r.usageIndex;
                                    desc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
                                    desc.InputSlot = 0;
                                    desc.InputSlotClass = D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA;
                                    desc.AlignedByteOffset = D3D12_APPEND_ALIGNED_ELEMENT;
                                    inputLayout.push_back(desc);
                                }
                                // Hash from VS vertex declaration
                                std::vector<uint32_t> vf;
                                std::vector<uint8_t> usage, usageIndex;
                                for (const auto& r : refs) {
                                    vf.push_back(r.vertexFormat);
                                    usage.push_back(static_cast<uint8_t>(r.usage));
                                    usageIndex.push_back(static_cast<uint8_t>(r.usageIndex));
                                }
                                if (!vf.empty()) {
                                    vertexDeclHash = mcla::renderer::HashShaderBytecode(
                                        std::vector<uint8_t>(
                                            reinterpret_cast<const uint8_t*>(vf.data()),
                                            reinterpret_cast<const uint8_t*>(vf.data() + vf.size())));
                                }
                            }

                            if (!inputLayout.empty()) {
                                // Build pipeline state
                                mcla::renderer::PipelineState state = {};
                                state.targetFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM;
                                state.depthStencilFormat = DXGI_FORMAT_D24_UNORM_S8_UINT;
                                state.blendState = 0;
                                state.rasterState = 0;
                                state.depthStencilState = 0;
                                state.topology = 0; // triangle
                                state.sampleCount = 1;

                                // Compute pipeline key
                                mcla::renderer::PipelineKey key = mcla::renderer::ComputePipelineKey(
                                    vsOut.programHash, psOut.programHash,
                                    vertexDeclHash, state);

                                // Look up or compile PSO
                                auto& cache = backend_.GetPipelineCache();
                                cachedPso = cache.GetOrCompile(
                                    key, vsOut.hlsl, psOut.hlsl, inputLayout);
                                if (cachedPso) {
                                    pipeline = cachedPso.Get();
                                    s_psoCacheHits.fetch_add(1, std::memory_order_relaxed);
                                    if (n <= 5 || (n % 500) == 0)
                                        MCLA_LOG_INFO("RenderThread: PSO HIT #{} vs={:016X} ps={:016X}",
                                                      n, vsOut.programHash, psOut.programHash);
                                } else {
                                    s_psoCacheMisses.fetch_add(1, std::memory_order_relaxed);
                                    if (n <= 5 || (n % 500) == 0)
                                        MCLA_LOG_INFO("RenderThread: PSO MISS #{} (async compile in progress)",
                                                      n);
                                }
                            }
                        }
                    } else {
                        s_psoTranslateFailures.fetch_add(1, std::memory_order_relaxed);
                        if (n <= 3 || (n % 1000) == 0)
                            MCLA_LOG_WARN("RenderThread: shader translate failed #{} vs={} ps={}",
                                          n, d.vsProgram, d.psProgram);
                    }
                } else {
                    if (n <= 3 || (n % 1000) == 0)
                        MCLA_LOG_WARN("RenderThread: shader container read failed #{} vs={} ps={}",
                                      n, d.vsProgram, d.psProgram);
                }
            }

            // Stats logging
            if (n == 1 || (n % 2000) == 0) {
                MCLA_LOG_INFO("RenderThread: PSO stats — hits={} misses={} translate_fails={}",
                              s_psoCacheHits.load(), s_psoCacheMisses.load(),
                              s_psoTranslateFailures.load());
            }

            D3D12Backend::DynamicMeshDesc desc = {};
            desc.vertexBytes = vb.data();
            desc.vertexBytesSize = d.vbSize;
            desc.vertexStride = d.vbStride;
            desc.vertexCount = d.vbSize / d.vbStride;
            desc.indexed = true;
            desc.indexBytes = ib.data();
            desc.indexBytesSize = d.ibSize;
            desc.indexFormat = (d.ibFormat & 1) ? DXGI_FORMAT_R32_UINT : DXGI_FORMAT_R16_UINT;
            desc.indexCount = d.indexCount;

            if (backend_.BeginFrame()) {
                if (pipeline) {
                    backend_.DrawDynamicMeshWithPipeline(desc, pipeline);
                } else {
                    backend_.DrawDynamicMesh(desc);
                }
                backend_.ClearAndPresent(0.0f, 0.0f, 0.02f, 1.0f);
            }
            break;
        }
        case RenderCommand::SET_PIPELINE_STATE: {
            const auto& p = std::get<SetPipelineStateCommand>(cmd.data);
            MCLA_LOG_DEBUG("RenderThread: SetPipelineState hash={:016X}", p.psoHash);
            break;
        }
        case RenderCommand::SET_RENDER_STATE: {
            const auto& rs = std::get<SetRenderStateCommand>(cmd.data);
            static std::atomic<uint32_t> rsCount{0};
            const uint32_t n = rsCount.fetch_add(1) + 1;
            if (n <= 20 || (n % 1000) == 0)
                MCLA_LOG_INFO("RenderThread: SET_RENDER_STATE #{} dev={:08X} value={:08X}",
                              n, rs.deviceAddr, rs.value);
            break;
        }
        case RenderCommand::PRESENT: {
            if (!d3d12Initialized_) break;
            const auto& p = std::get<PresentCommand>(cmd.data);
            static std::atomic<uint32_t> presentCount{0};
            const uint32_t n = presentCount.fetch_add(1) + 1;
            if (n <= 10 || (n % 120) == 0)
                MCLA_LOG_INFO("RenderThread: PRESENT #{} frame={} obj={:08X}",
                              n, p.frameNumber, p.obj);

            // Frame pacing: wait until target frame interval elapsed
            using Clock = std::chrono::steady_clock;
            static auto lastPresentTime = Clock::now();
            {
                auto now = Clock::now();
                double elapsed = std::chrono::duration<double>(now - lastPresentTime).count();
                if (elapsed < kTargetFrameSeconds) {
                    double sleepMs = (kTargetFrameSeconds - elapsed) * 1000.0;
                    if (sleepMs > 1.0) {
                        Sleep(static_cast<DWORD>(sleepMs));
                    }
                }
                lastPresentTime = Clock::now();
            }

            if (backend_.BeginFrame()) {
                backend_.ClearAndPresent(0.0f, 0.0f, 0.02f, 1.0f);
            }
            break;
        }
        case RenderCommand::DRAW_CAPTURED: {
            if (!d3d12Initialized_) break;
            const auto& dc = std::get<DrawCapturedCommand>(cmd.data);
            static std::atomic<uint32_t> drawCount{0};
            const uint32_t n = drawCount.fetch_add(1) + 1;
            if (n <= 10 || (n % 500) == 0)
                MCLA_LOG_INFO("RenderThread: DRAW_CAPTURED #{} vb={:08X} ib={:08X} "
                              "vbSize={} ibSize={} stride={}",
                              n, dc.vbBase, dc.ibBase, dc.vbSize, dc.ibSize, dc.vbStride);

            if (dc.vbBase == 0 || dc.vbSize == 0 || dc.ibBase == 0 || dc.ibSize == 0) break;

            auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
            std::vector<uint8_t> vb(dc.vbSize);
            std::vector<uint8_t> ib(dc.ibSize);
            if (!mem.ReadBytes(dc.vbBase, vb.data(), dc.vbSize)) break;
            if (!mem.ReadBytes(dc.ibBase, ib.data(), dc.ibSize)) break;

            D3D12Backend::DynamicMeshDesc desc = {};
            desc.vertexBytes = vb.data();
            desc.vertexBytesSize = dc.vbSize;
            desc.vertexStride = dc.vbStride;
            desc.vertexCount = dc.vbSize / dc.vbStride;
            desc.indexed = true;
            desc.indexBytes = ib.data();
            desc.indexBytesSize = dc.ibSize;
            desc.indexFormat = DXGI_FORMAT_R16_UINT;
            desc.indexCount = dc.ibSize / 2;

            if (backend_.BeginFrame()) {
                backend_.DrawDynamicMesh(desc);
                backend_.ClearAndPresent(0.0f, 0.0f, 0.02f, 1.0f);
            }
            break;
        }
        case RenderCommand::RESIZE: {
            if (!d3d12Initialized_) break;
            const auto& r = std::get<ResizeCommand>(cmd.data);
            MCLA_LOG_INFO("RenderThread: RESIZE {}x{}", r.width, r.height);
            backend_.Resize(r.width, r.height);
            break;
        }
        case RenderCommand::SET_VERTEX_BUFFERS:
        case RenderCommand::SET_INDEX_BUFFER:
        case RenderCommand::NOOP:
            break;
    }
}

} // namespace mcla::native
