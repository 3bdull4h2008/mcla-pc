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
#include <vector>

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

    if (heartbeat_.joinable()) {
        heartbeat_.join();
    }
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
            // Vibe: show a visible clear immediately so the window is not black
            // while waiting for the first guest PresentKick.
            if (backend_.BeginFrame()) {
                backend_.ClearAndPresent(0.06f, 0.10f, 0.22f, 1.0f);
                MCLA_LOG_INFO("RenderThread: initial clear+present (dark blue)");
            }
            // W6 one-shot: prove PresentBgra (upload + CopyResource + Present)
            // with a synthetic gradient so the blit path is verified even if
            // the guest never fires NATIVE-PRESENT during a short soak.
            {
                const uint32_t w = 1280, h = 720;
                std::vector<uint8_t> grad(static_cast<size_t>(w) * h * 4u);
                for (uint32_t y = 0; y < h; ++y) {
                    for (uint32_t x = 0; x < w; ++x) {
                        uint8_t* p = &grad[(static_cast<size_t>(y) * w + x) * 4u];
                        p[0] = static_cast<uint8_t>((x * 255u) / (w - 1)); // R
                        p[1] = static_cast<uint8_t>((y * 255u) / (h - 1)); // G
                        p[2] = 64;                                         // B
                        p[3] = 255;
                    }
                }
                if (backend_.PresentBgra(w, h, grad.data())) {
                    MCLA_LOG_INFO("PRESENT-BLIT-SYNTH ok {}x{} (gradient)", w, h);
                } else {
                    MCLA_LOG_WARN("PRESENT-BLIT-SYNTH fail {}x{}", w, h);
                }
            }
            // Heartbeat: ALWAYS enqueue a clear present. Do not skip when the
            // guest queue is busy — SET_RENDER_STATE traffic otherwise starves
            // presents and the window flashes once then dies visually.
            heartbeat_ = std::thread([this]() {
                using namespace std::chrono_literals;
                while (!shouldStop_) {
                    std::this_thread::sleep_for(33ms);
                    if (shouldStop_ || !d3d12Initialized_) continue;
                    RenderCommand cmd;
                    cmd.type = RenderCommand::PRESENT;
                    auto& p = cmd.data.emplace<PresentCommand>();
                    p.frameNumber = 0;
                    p.obj = 0;
                    p.swapInfo = 0;
                    g_commandQueue.push(std::move(cmd));
                }
            });
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
            desc.vertexCount = (d.vbStride > 0) ? (d.vbSize / d.vbStride) : 0;
            desc.indexed = true;
            desc.indexBytes = ib.data();
            desc.indexBytesSize = d.ibSize;
            desc.indexFormat = (d.ibFormat & 1) ? DXGI_FORMAT_R32_UINT : DXGI_FORMAT_R16_UINT;
            desc.indexCount = d.indexCount;

            // B4 (T41.4b): one present per drawn frame. DrawDynamicMesh* already
            // closes, executes, presents and advances the frame index, so the
            // old ClearAndPresent() here was a SECOND present of the same frame
            // whose first act is ClearRenderTargetView — it erased whatever the
            // draw had just rendered. The present belongs to the draw path until
            // the backend grows a real EndFrame.
            if (backend_.BeginFrame()) {
                if (pipeline) {
                    backend_.DrawDynamicMeshWithPipeline(desc, pipeline);
                } else {
                    backend_.DrawDynamicMesh(desc);
                }
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
            // B4 (T41.4b): the 33 ms heartbeat enqueues exactly
            // {frameNumber=0, obj=0, swapInfo=0}, so it can be told apart from a
            // guest PresentKick without guessing. Counting them as PRESENT made
            // the marker measure our own timer, not the guest (w102: 60 PRESENT
            // lines, all heartbeat). The heartbeat line deliberately avoids the
            // substring "PRESENT" because soak_census counts matching LINES
            // (F-054 discipline): a guest-driven PRESENT count is now real.
            const bool heartbeat =
                p.frameNumber == 0 && p.obj == 0 && p.swapInfo == 0;
            if (n <= 10 || (n % 120) == 0)
                MCLA_LOG_INFO(
                    "RenderThread: {} #{} frame={} obj={:08X} fb={:08X} "
                    "surf={:08X}",
                    heartbeat ? "HB-FLICKER" : "PRESENT", n, p.frameNumber,
                    p.obj, p.swapInfo, p.surfaceVA);

            // Frame pacing
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

            // W5: sample average color for logs. W6: full-viewport blit of
            // the guest framebuffer when swapInfo is a high guest VA.
            // W7: if swapInfo is a swap-table slot (C71D81xx family or
            // samples as near-zero), use the resolved surface VA instead.
            float cr = 0.06f, cg = 0.10f, cb = 0.22f;
            bool blitOk = false;

            // Determine which VA to blit from.
            // Heartbeat (swapInfo=0): don't blit, just clear.
            // Guest present with swap-table swapInfo: use resolved surface.
            // Guest present with real surface swapInfo: use swapInfo directly.
            uint32_t blitVA = 0;
            if (p.swapInfo >= 0x80000000u && p.swapInfo < 0x100000000u) {
                // Heuristic: swap-table slots are in the C71D81xx family
                // (table at C71D8180, slots at +0x40..+0x5C).
                const bool isSwapTable =
                    (p.swapInfo >= 0xC71D8180u && p.swapInfo < 0xC71D81E0u);
                if (isSwapTable) {
                    // Swap-table slot — use resolved surface if available.
                    blitVA = p.surfaceVA;
                } else {
                    // Might be a real surface — try it directly.
                    blitVA = p.swapInfo;
                }
            }
            // Note: swapInfo=0 (heartbeat) leaves blitVA=0 → clear-only.

            if (blitVA != 0) {
                auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
                // Prefer full 1280x720 linear 32bpp; fall back to 640x360 if
                // the larger ReadBytes is not valid (page still uncommitted).
                static std::vector<uint8_t> fbBuf;
                constexpr uint32_t kFullW = 1280, kFullH = 720;
                constexpr uint32_t kHalfW = 640, kHalfH = 360;
                constexpr uint32_t kFullBytes = kFullW * kFullH * 4;
                constexpr uint32_t kHalfBytes = kHalfW * kHalfH * 4;
                if (fbBuf.size() < kFullBytes) fbBuf.resize(kFullBytes);

                uint32_t fbW = 0, fbH = 0;
                if (mem.ReadBytes(blitVA, fbBuf.data(), kFullBytes)) {
                    fbW = kFullW;
                    fbH = kFullH;
                } else if (mem.ReadBytes(blitVA, fbBuf.data(), kHalfBytes)) {
                    fbW = kHalfW;
                    fbH = kHalfH;
                }

                if (fbW != 0) {
                    uint64_t sumR = 0, sumG = 0, sumB = 0;
                    const uint32_t sampleCount = 16 * 16;
                    for (uint32_t y = 0; y < 16; ++y) {
                        for (uint32_t x = 0; x < 16; ++x) {
                            const uint32_t sx = x * (fbW / 16);
                            const uint32_t sy = y * (fbH / 16);
                            const uint32_t off = (sy * fbW + sx) * 4;
                            // LE 32bpp in guest memory: treat as RGBA bytes.
                            sumR += fbBuf[off + 0];
                            sumG += fbBuf[off + 1];
                            sumB += fbBuf[off + 2];
                        }
                    }
                    cr = static_cast<float>(sumR / sampleCount) / 255.0f;
                    cg = static_cast<float>(sumG / sampleCount) / 255.0f;
                    cb = static_cast<float>(sumB / sampleCount) / 255.0f;
                    if (cr + cg + cb < 0.02f) {
                        cr = 0.06f;
                        cg = 0.10f;
                        cb = 0.22f;
                    }
                    static std::atomic<uint32_t> presentFbCount{0};
                    const uint32_t pfn = presentFbCount.fetch_add(1) + 1;
                    if (pfn <= 16 || (pfn % 60) == 0)
                        MCLA_LOG_INFO("PRESENT-FB sample rgb=({:.2f},{:.2f},{:.2f}) va={:08X} (fb={:08X}) wh={}x{}",
                                      cr, cg, cb, blitVA, p.swapInfo, fbW, fbH);

                    if (!backend_.PresentBgra(fbW, fbH, fbBuf.data())) {
                        static std::atomic<uint32_t> blitFail{0};
                        const uint32_t fn = blitFail.fetch_add(1) + 1;
                        if (fn <= 5 || (fn % 120) == 0)
                            MCLA_LOG_WARN("PRESENT-BLIT fail #{} va={:08X} wh={}x{}",
                                          fn, blitVA, fbW, fbH);
                    } else {
                        blitOk = true;
                        static std::atomic<uint32_t> blitCount{0};
                        const uint32_t bn = blitCount.fetch_add(1) + 1;
                        if (bn <= 10 || (bn % 60) == 0)
                            MCLA_LOG_INFO("PRESENT-BLIT #{} {}x{} va={:08X} (fb={:08X})",
                                          bn, fbW, fbH, blitVA, p.swapInfo);
                    }
                } else if (n <= 8 || (n % 240) == 0) {
                    MCLA_LOG_WARN("PRESENT-FB read failed va={:08X} (fb={:08X})",
                                  blitVA, p.swapInfo);
                }
            }

            if (!blitOk) {
                if (backend_.BeginFrame()) {
                    backend_.ClearAndPresent(cr, cg, cb, 1.0f);
                }
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
            desc.vertexCount = (dc.vbStride > 0) ? (dc.vbSize / dc.vbStride) : 0;
            desc.indexed = true;
            desc.indexBytes = ib.data();
            desc.indexBytesSize = dc.ibSize;
            desc.indexFormat = DXGI_FORMAT_R16_UINT;
            // FIXME: Assumes 16-bit indices; DRAW_CAPTURED doesn't carry ibFmt
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
