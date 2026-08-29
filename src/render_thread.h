#pragma once

#include <thread>
#include <atomic>
#include "render_queue.h"

namespace mcla::native {

class RenderThread {
public:
    RenderThread();
    ~RenderThread();
    
    void start();
    void stop();
    
    bool isRunning() const { return running_; }
    
private:
    void threadMain();
    void processCommand(const RenderCommand& cmd);
    void executeDrawIndexed(const DrawIndexedCommand& cmd);
    void executeSetPipelineState(const SetPipelineStateCommand& cmd);
    void executePresent(const PresentCommand& cmd);
    
    std::thread thread_;
    std::atomic<bool> running_;
    std::atomic<bool> shouldStop_;
};

extern RenderThread g_renderThread;

} // namespace mcla::native