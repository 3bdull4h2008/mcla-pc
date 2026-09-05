#include "render_thread.h"
#include "logging.h"
#include "generated/ppc_xenon/ppc_recomp_shared.h"
#include "kernel/memory.h"
#include <chrono>

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
            const auto& d = std::get<DrawIndexedCommand>(cmd.data);
            static std::atomic<uint32_t> drawCount{0};
            const uint32_t n = drawCount.fetch_add(1) + 1;
            if (n <= 20 || (n % 1000) == 0)
                MCLA_LOG_INFO("RenderThread: DRAW_INDEXED #{} prim={} vb={:08X} ib={:08X} "
                              "count={} stride={} ibFmt={}",
                              n, d.primitiveTopology, d.vbAddr, d.ibAddr,
                              d.indexCount, d.vbStride, d.ibFormat);
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
