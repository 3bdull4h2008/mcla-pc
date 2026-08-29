#include "render_thread.h"
#include "d3d12_backend.h"
#include "logging.h"
#include "native_renderer.h"

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
    MCLA_LOG_ERROR(">>> RenderThread::start() called <<<");
    thread_ = std::thread(&RenderThread::threadMain, this);
    MCLA_LOG_ERROR(">>> Render thread started (P4.5') <<<");
}

void RenderThread::stop() {
    if (!running_) return;
    
    shouldStop_ = true;
    g_commandQueue.shutdown();
    
    if (thread_.joinable()) {
        thread_.join();
    }
    
    running_ = false;
    MCLA_LOG_INFO("Render thread stopped");
}

void RenderThread::threadMain() {
    MCLA_LOG_INFO("Render thread main loop starting");
    
    while (!shouldStop_) {
        RenderCommand cmd;
        if (!g_commandQueue.pop(cmd)) {
            break; // Queue shutdown
        }
        
        processCommand(cmd);
    }
    
    MCLA_LOG_INFO("Render thread main loop exiting");
}

void RenderThread::processCommand(const RenderCommand& cmd) {
    switch (cmd.type) {
        case RenderCommand::DRAW_INDEXED:
            executeDrawIndexed(std::get<DrawIndexedCommand>(cmd.data));
            break;
            
        case RenderCommand::SET_PIPELINE_STATE:
            executeSetPipelineState(std::get<SetPipelineStateCommand>(cmd.data));
            break;
            
        case RenderCommand::PRESENT:
            executePresent(std::get<PresentCommand>(cmd.data));
            break;
            
        case RenderCommand::SET_VERTEX_BUFFERS:
        case RenderCommand::SET_INDEX_BUFFER:
        case RenderCommand::NOOP:
            // Not implemented yet
            break;
    }
}

void RenderThread::executeDrawIndexed(const DrawIndexedCommand& cmd) {
    // Move the actual D3D12 call here from TryConsumeDeviceBoundaryDraw
    // This is where all D3D12 API calls happen now
    
    MCLA_LOG_DEBUG("Render thread: DrawIndexed vb={:08X} ib={:08X} count={}", 
                   cmd.vbAddr, cmd.ibAddr, cmd.indexCount);
    
    D3D12Backend* backend = GetD3D12Backend();
    if (!backend || !backend->IsInitialized()) {
        return;
    }
    
    D3D12Backend::DynamicMeshDesc desc = {};
    desc.vertexBytes = nullptr; // Will be filled from guest memory
    desc.vertexBytesSize = 0;
    desc.vertexStride = cmd.vbStride;
    desc.vertexCount = cmd.indexCount;
    desc.indexed = true;
    desc.indexBytes = nullptr;
    desc.indexBytesSize = 0;
    desc.indexFormat = static_cast<DXGI_FORMAT>(cmd.ibFormat);
    
    // We need to read vertex/index data from guest memory
    // For now, just log that we're executing
    MCLA_LOG_INFO("Render thread: executing DrawIndexed (stub - need guest memory read)");
}

void RenderThread::executeSetPipelineState(const SetPipelineStateCommand& cmd) {
    MCLA_LOG_DEBUG("Render thread: SetPipelineState hash={:016X}", cmd.psoHash);
    // TODO: Set PSO
}

void RenderThread::executePresent(const PresentCommand& cmd) {
    MCLA_LOG_DEBUG("Render thread: Present frame={}", cmd.frameNumber);
    // TODO: Call swap chain present
}

} // namespace mcla::native