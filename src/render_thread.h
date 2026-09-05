#pragma once

#include <thread>
#include <atomic>
#include "render_queue.h"
#include "d3d12_backend.h"

namespace mcla::native {

class RenderThread {
public:
    RenderThread();
    ~RenderThread();

    void start();
    void stop();

    bool isRunning() const { return running_; }
    bool isD3D12Initialized() const { return d3d12Initialized_; }

    D3D12Backend* GetBackend() { return &backend_; }

    void SetWindowParams(void* hwnd, uint32_t width, uint32_t height);

private:
    void threadMain();
    void processCommand(const RenderCommand& cmd);

    std::thread thread_;
    std::atomic<bool> running_;
    std::atomic<bool> shouldStop_;
    std::atomic<bool> d3d12Initialized_{false};
    D3D12Backend backend_;

    void* pendingHwnd_{nullptr};
    uint32_t pendingWidth_{0};
    uint32_t pendingHeight_{0};
};

extern RenderThread g_renderThread;

} // namespace mcla::native