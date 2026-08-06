#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif

#include <windows.h>
#include <d3d12.h>
#include <dxgi1_4.h>
#include <wrl/client.h>

#include <cstdint>
#include <filesystem>
#include <mutex>

#include "renderer/resource_cache.h"

namespace mcla::native {

class D3D12Backend {
public:
    static constexpr uint32_t kBufferCount = 3;

    D3D12Backend();
    ~D3D12Backend();

    // Initialize D3D12 device, command queue, swap chain, descriptor heaps
    bool Initialize(HWND hwnd, uint32_t width, uint32_t height);
    void Shutdown();

    bool IsInitialized() const { return m_initialized; }

    // Resize swap chain buffers
    bool Resize(uint32_t width, uint32_t height);

    // Frame lifecycle
    bool BeginFrame();
    bool ClearAndPresent(float r, float g, float b, float a);

    // Phase 3 native draw slice: submit a test indexed triangle through the
    // upload arena + test PSO. Proves buffer, index, viewport, topology, and
    // RTV handling end-to-end on the native (non-Xenos) path.
    bool DrawTestMeshedTriangle(uint32_t frame);

    // Counters for the Phase 3 debug overlay / structured log.
    struct DrawStats {
        uint64_t drawsIssued = 0;
        uint64_t uploadsBytes = 0;
        uint64_t bytesThisFrame = 0;
        uint64_t cacheHits = 0;
        uint64_t cacheMisses = 0;
    };
    const DrawStats& Stats() const { return m_stats; }

    void EndFrame();

    // Accessors
    ID3D12Device* GetDevice() const { return m_device.Get(); }
    ID3D12GraphicsCommandList* GetCommandList() const { return m_commandList.Get(); }
    ID3D12CommandQueue* GetCommandQueue() const { return m_commandQueue.Get(); }
    uint32_t GetCurrentFrameIndex() const { return m_frameIndex; }
    uint32_t GetWidth() const { return m_width; }
    uint32_t GetHeight() const { return m_height; }

    // Wait for all GPU work to complete
    void WaitForGpu();

    // Phase 3 draw-path resources
    bool CreateUploadHeap();
    bool CreateTestRootSignature();
    bool CreateTestPipeline();
    uint8_t* MapUpload(size_t size, size_t alignment, D3D12_GPU_VIRTUAL_ADDRESS& gpu);

    // Per-frame upload arena lives in an upload heap and records into
    // vertex/index buffers. Grows once on Initialize. The arena is split into
    // kBufferCount regions, one per back buffer, so a frame only writes the
    // region whose completion is guaranteed by BeginFrame's fence wait.
    Microsoft::WRL::ComPtr<ID3D12Resource> m_uploadHeap;
    size_t m_uploadCapacity = 0;
    size_t m_uploadRegionSize = 0;
    size_t m_uploadOffset = 0;
    uint8_t* m_uploadMap = nullptr;

    Microsoft::WRL::ComPtr<ID3D12RootSignature> m_rootSignature;
    Microsoft::WRL::ComPtr<ID3D12PipelineState> m_testPipeline;

    // Static index buffer for the deterministic triangle, uploaded once and
    // cached by ResourceCache so later frames do not re-upload it.
    bool CreateStaticIndexBuffer();
    Microsoft::WRL::ComPtr<ID3D12Resource> m_staticIndexBuffer;
    ResourceCache m_resourceCache;

    DrawStats m_stats;

private:
    bool CreateDevice();
    bool CreateSwapChain(HWND hwnd, uint32_t width, uint32_t height);
    bool CreateRenderTargets();
    bool CreateCommandObjects();
    bool CreateSyncObjects();

    bool m_initialized = false;
    HWND m_hwnd = nullptr;
    uint32_t m_width = 1280;
    uint32_t m_height = 720;

    Microsoft::WRL::ComPtr<IDXGIFactory4> m_factory;
    Microsoft::WRL::ComPtr<ID3D12Device> m_device;
    Microsoft::WRL::ComPtr<ID3D12CommandQueue> m_commandQueue;
    Microsoft::WRL::ComPtr<IDXGISwapChain3> m_swapChain;

    Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> m_rtvHeap;
    uint32_t m_rtvDescriptorSize = 0;
    Microsoft::WRL::ComPtr<ID3D12Resource> m_renderTargets[kBufferCount];

    Microsoft::WRL::ComPtr<ID3D12CommandAllocator> m_commandAllocators[kBufferCount];
    Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> m_commandList;

    // CPU-GPU sync
    Microsoft::WRL::ComPtr<ID3D12Fence> m_fence;
    HANDLE m_fenceEvent = nullptr;
    uint64_t m_fenceValues[kBufferCount] = {};
    uint64_t m_currentFenceValue = 0;
    uint32_t m_frameIndex = 0;

    bool m_inFrame = false;
    std::recursive_mutex m_mutex;
};

D3D12Backend* GetD3D12Backend();

} // namespace mcla::native
