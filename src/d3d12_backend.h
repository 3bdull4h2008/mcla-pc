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
#include "renderer/pipeline_cache.h"

namespace rex {
class Runtime;
namespace ui {
class Presenter;
}
} // namespace rex

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

    // Host-side geometry for DrawDynamicMesh. Data is already validated by the
    // caller; the backend never interprets guest layouts — it only uploads and
    // draws with the input layout the PSO declares. `cachedIndexGpu` is set by
    // the caller to reuse a previously cached static index buffer (0 = none).
    struct DynamicMeshDesc {
        const void* vertexBytes = nullptr;  // host vertex data
        uint32_t vertexBytesSize = 0;
        uint32_t vertexStride = 0;          // must match the test input layout (28)
        uint32_t vertexCount = 0;           // non-indexed draw count

        bool indexed = false;
        const void* indexBytes = nullptr;   // uploaded this frame (indexed case)
        uint32_t indexBytesSize = 0;
        DXGI_FORMAT indexFormat = DXGI_FORMAT_R16_UINT;
        D3D12_GPU_VIRTUAL_ADDRESS cachedIndexGpu = 0;  // cached static IB, or 0
        uint32_t cachedIndexBytesSize = 0;  // byte size of cachedIndexGpu (required when set)
        uint32_t indexCount = 0;            // indexed draw count
    };

    // Phase 3 native draw slice: submit a test indexed triangle through the
    // upload arena + test PSO. Proves buffer, index, viewport, topology, and
    // RTV handling end-to-end on the native (non-Xenos) path.
    bool DrawTestMeshedTriangle(uint32_t frame);

    // Generic dynamic-geometry draw: uploads the caller's vertex/index bytes
    // through the per-frame upload arena and issues one draw (indexed or not).
    // This is the consumption target for a captured DrawPacket whose layout
    // provably matches the test PSO input layout.
    bool DrawDynamicMesh(const DynamicMeshDesc& desc);

    // Overload that accepts a specific PSO to use instead of the default test pipeline.
    bool DrawDynamicMeshWithPipeline(const DynamicMeshDesc& desc,
                                     ID3D12PipelineState* pipeline);

    // Pipeline cache access for Phase 5 shader integration.
    renderer::PipelineCache& GetPipelineCache() { return m_pipelineCache; }

    // Counters for the Phase 3 debug overlay / structured log.
    struct DrawStats {
        uint64_t drawsIssued = 0;
        uint64_t uploadsBytes = 0;
        uint64_t bytesThisFrame = 0;
        uint64_t cacheHits = 0;
        uint64_t cacheMisses = 0;
    };
    const DrawStats& Stats() const { return m_stats; }

    // Phase 4 texture path (data-independent slice). Uploads host-linear
    // decoded pixel bytes (already untiled by texture_decode) into a
    // DEFAULT-heap texture and creates a shader-visible SRV at t0. Returns
    // false on any D3D12 failure; a failed create leaves the previous texture
    // untouched.
    bool CreateDecodedTexture(const uint8_t* linearPixels, uint32_t width,
                              uint32_t height, uint32_t dxgiFormat);
    // Bind the SRV descriptor table (+ static sampler s0) for the current draw.
    // No-op when no decoded texture has been created.
    void BindDecodedTexture();

    // Phase 5 live DXIL PSO creation: build a graphics pipeline state from
    // runtime-compiled VS/PS DXIL blobs and the provided render state.
    // Returns false on any D3D12 failure.
    bool CreatePipelineFromDxil(const std::vector<uint8_t>& vsDxil,
                                const std::vector<uint8_t>& psDxil,
                                const std::vector<D3D12_INPUT_ELEMENT_DESC>& inputLayout,
                                const renderer::PipelineState& state,
                                Microsoft::WRL::ComPtr<ID3D12PipelineState>& outPso);

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

    // Wait until the GPU is done with the current back buffer's prior frame.
    // Must precede writes into this frame's upload arena region.
    bool WaitForCurrentFrameGpu();

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

    // Phase 4 texture resources (decoded host-linear pixels -> texture + SRV).
    bool CreateSrvHeap();
    Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> m_srvHeap;
    uint32_t m_srvDescriptorSize = 0;
    Microsoft::WRL::ComPtr<ID3D12Resource> m_decodedTexture;
    Microsoft::WRL::ComPtr<ID3D12Resource> m_decodedTextureUpload;
    D3D12_GPU_DESCRIPTOR_HANDLE m_decodedTextureSrvGpu = {};
    HRESULT m_lastPresentHr = S_OK;

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

    // Phase 5 pipeline cache for live shader compilation
    renderer::PipelineCache m_pipelineCache;
};

D3D12Backend* GetD3D12Backend();

} // namespace mcla::native
