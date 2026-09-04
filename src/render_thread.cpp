#include "render_thread.h"
#include "logging.h"

namespace mcla::native {

RenderThread g_renderThread;
CommandQueue g_commandQueue;

RenderThread::RenderThread() : running_(false), shouldStop_(false) {}

RenderThread::~RenderThread() {
    stop();
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

    running_ = false;
    MCLA_LOG_INFO("RenderThread: stopped");
}

void RenderThread::threadMain() {
    MCLA_LOG_INFO("RenderThread: entering command loop");

    while (!shouldStop_) {
        RenderCommand cmd;
        if (!g_commandQueue.pop(cmd)) {
            break;
        }
        processCommand(cmd);
    }

    MCLA_LOG_INFO("RenderThread: exiting command loop");
}

void RenderThread::processCommand(const RenderCommand& cmd) {
    switch (cmd.type) {
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
            const auto& p = std::get<PresentCommand>(cmd.data);
            MCLA_LOG_DEBUG("RenderThread: Present frame={}", p.frameNumber);
            break;
        }
        case RenderCommand::SET_VERTEX_BUFFERS:
        case RenderCommand::SET_INDEX_BUFFER:
        case RenderCommand::NOOP:
            break;
    }
}

} // namespace mcla::native