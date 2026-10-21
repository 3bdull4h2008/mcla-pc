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
    std::thread heartbeat_;
    std::atomic<bool> running_;
    std::atomic<bool> shouldStop_;
    std::atomic<bool> d3d12Initialized_{false};
    D3D12Backend backend_;

    void* pendingHwnd_{nullptr};
    uint32_t pendingWidth_{0};
    uint32_t pendingHeight_{0};
};

extern RenderThread g_renderThread;

// F-XXX: THE HOST'S SINGLE XENOS->DXGI COLOUR-FORMAT MAP.
//
// DEFINED in src/render_thread.cpp (it is the render thread's own, and it
// cites Xenia's d3d12_render_target_cache.cc:1685-1686 for every entry).
// DECLARED HERE so that a second consumer -- the D3D12 backend, which needs
// the GUEST's colour format for the guest's render target -- uses THAT table
// and not a copy of it. A copy would be a second thing to drift, and the
// drift would be silent: the guest render target's format and the PSO's
// RTVFormats[0] would disagree, which rasterises nothing and reports no
// error (the D3D12-RTV-FORMAT row says exactly that).
//
// 0 = DXGI_FORMAT_UNKNOWN is returned for every code with no mapping, and
// the consumer must refuse such a code rather than default it.
uint32_t MapXenosColorFormatToDxgi(uint32_t colorFormat);

} // namespace mcla::native