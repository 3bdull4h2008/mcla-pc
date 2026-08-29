#include "render_command_queue.h"

#include "d3d12_backend.h"
#include "guest_memory.h"
#include "logging.h"
#include "renderer_mode.h"

#include <thread>
#include <chrono>

namespace mcla::gpu {

RenderCommandQueue::~RenderCommandQueue() {
    Shutdown();
}

void RenderCommandQueue::Enqueue(RenderCommand&& cmd) {
    std::scoped_lock lock(m_mutex);
    if (m_shutdown.load(std::memory_order_relaxed)) return;
    cmd.sequence = m_sequence.fetch_add(1, std::memory_order_relaxed);
    m_queue.push_back(std::move(cmd));
    m_cv.notify_one();
}

std::optional<RenderCommand> RenderCommandQueue::Dequeue() {
    std::unique_lock lock(m_mutex);
    m_cv.wait(lock, [this] {
        return !m_queue.empty() || m_shutdown.load(std::memory_order_relaxed);
    });
    if (m_shutdown.load(std::memory_order_relaxed) && m_queue.empty()) {
        return std::nullopt;
    }
    RenderCommand cmd = std::move(m_queue.front());
    m_queue.erase(m_queue.begin());
    return cmd;
}

void RenderCommandQueue::Wake() {
    std::scoped_lock lock(m_mutex);
    m_cv.notify_all();
}

void RenderCommandQueue::Shutdown() {
    m_shutdown.store(true, std::memory_order_relaxed);
    m_cv.notify_all();
}

size_t RenderCommandQueue::PendingCount() const {
    std::scoped_lock lock(m_mutex);
    return m_queue.size();
}

bool RenderCommandQueue::IsShutdown() const {
    return m_shutdown.load(std::memory_order_relaxed);
}

RenderThread::RenderThread() = default;

RenderThread::~RenderThread() {
    Stop();
}

bool RenderThread::Start(void* hwnd, uint32_t width, uint32_t height) {
    if (m_running.exchange(true)) return false;
    m_thread = std::thread(&RenderThread::ThreadMain, this, hwnd, width, height);
    return true;
}

void RenderThread::Stop() {
    if (!m_running.exchange(false)) return;
    m_queue.Shutdown();
    if (m_thread.joinable()) {
        m_thread.join();
    }
}

void RenderThread::EnqueueCommand(RenderCommand&& cmd) {
    m_queue.Enqueue(std::move(cmd));
}

RenderThread& RenderThread::Instance() {
    static RenderThread instance;
    return instance;
}

void RenderThread::ThreadMain(void* hwnd, uint32_t width, uint32_t height) {
    mcla::native::D3D12Backend backend;
    if (!backend.Initialize(static_cast<HWND>(hwnd), width, height)) {
        MCLA_LOG_ERROR("RenderThread: D3D12Backend initialization failed");
        m_running.store(false);
        return;
    }

    MCLA_LOG_INFO("RenderThread: started, entering command loop");

    while (m_running.load(std::memory_order_relaxed)) {
        auto cmdOpt = m_queue.Dequeue();
        if (!cmdOpt) break;

        RenderCommand& cmd = *cmdOpt;

        switch (cmd.type) {
            case RenderCommand::Type::Draw: {
                const auto& d = cmd.draw;
                MCLA_LOG_INFO("RenderThread: Draw seq={} dev={:08X} prim={:08X} ibBase={:08X} ibCnt={:08X}",
                              cmd.sequence, cmd.deviceVA, d.primTypeFlags, d.ibBase, d.ibCounts);

                mcla::native::D3D12Backend::DynamicMeshDesc desc = {};
                desc.vertexStride = d.vbDesc[0][1];
                desc.vertexCount = d.ibCounts & 0xFFFF;
                desc.indexed = false;

                if (!backend.BeginFrame()) {
                    MCLA_LOG_WARN("RenderThread: BeginFrame failed");
                    continue;
                }

                bool ok = backend.DrawDynamicMesh(desc);
                if (!ok) {
                    MCLA_LOG_WARN("RenderThread: DrawDynamicMesh failed");
                }

                if (!backend.ClearAndPresent(0.0f, 0.0f, 0.2f, 1.0f)) {
                    MCLA_LOG_WARN("RenderThread: ClearAndPresent failed");
                }
                break;
            }
            case RenderCommand::Type::Present: {
                const auto& p = cmd.present;
                MCLA_LOG_INFO("RenderThread: Present seq={} dev={:08X} fb={:08X} bbIdx={} bbCount={} bbBase={:08X}",
                              cmd.sequence, cmd.deviceVA, p.fbAddr, p.bbIdx, p.bbCount, p.bbBase);

                if (!backend.BeginFrame()) {
                    MCLA_LOG_WARN("RenderThread: BeginFrame failed");
                    continue;
                }

                if (!backend.ClearAndPresent(0.0f, 0.0f, 0.2f, 1.0f)) {
                    MCLA_LOG_WARN("RenderThread: ClearAndPresent failed");
                }
                break;
            }
            case RenderCommand::Type::StateSetup: {
                const auto& s = cmd.stateSetup;
                MCLA_LOG_INFO("RenderThread: StateSetup seq={} dev={:08X} srcState={:08X}",
                              cmd.sequence, cmd.deviceVA, s.srcStateVA);
                break;
            }
        }
    }

    backend.Shutdown();
    MCLA_LOG_INFO("RenderThread: stopped");
}

} // namespace mcla::gpu