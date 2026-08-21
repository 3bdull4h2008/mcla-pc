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
#include <optional>

#include "renderer/resource_cache.h"
#include "renderer/pipeline_cache.h"
#include "native_types.h"

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

    // Phase 5: Draw a captured DrawPacket using its native vertex/index data,
    // shaders, and state. Builds input layout from grcFvf, creates/selects PSO
    // from PipelineCache, uploads guest vertex/index buffers, and issues the draw.
    bool DrawCapturedPacket(const native::DrawPacket& packet);

    // Helper: Build D3D12 input layout from captured grcFvf vertex declaration.
    // Returns empty vector on failure (unsupported format).
    std::vector<D3D12_INPUT_ELEMENT_DESC>
    BuildInputLayoutFromGrcFvf(const native::GrcFvfDesc& grcFvf);

    // Helper: Build render state from captured DrawPacket state.
    renderer::PipelineState BuildPipelineStateFromPacket(const native::DrawPacket& packet);

    // Helper: Upload guest vertex/index data from captured packet to upload arena.
    // Returns false if upload fails or data is invalid.
    bool UploadPacketGeometry(const native::DrawPacket& packet,
                              D3D12_GPU_VIRTUAL_ADDRESS& vbGpu,
                              D3D12_GPU_VIRTUAL_ADDRESS& ibGpu,
                              uint32_t& vertexStride,
                              uint32_t& vertexCount,
                              uint32_t& indexCount,
                              DXGI_FORMAT& indexFormat);

    // Phase 4: Sampler state management
    // Creates or retrieves a cached sampler state from the provided descriptor.
    // Returns the D3D12_STATIC_SAMPLER_DESC index for root signature binding,
    // or UINT32_MAX on failure.
    uint32_t GetOrCreateStaticSampler(const D3D12_SAMPLER_DESC& desc);

    // Phase 4: Render target view for a texture (allows texture to be used as RT)
    // Creates an RTV for the given texture resource with the specified format.
    // Returns false on failure.
    bool CreateRenderTargetView(ID3D12Resource* texture, DXGI_FORMAT format,
                                D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle);

    // Phase 4: Depth-stencil view for a texture
    bool CreateDepthStencilView(ID3D12Resource* texture, DXGI_FORMAT format,
                                D3D12_CPU_DESCRIPTOR_HANDLE dsvHandle);

    // Phase 4: Generate mipmaps for a texture (requires SRV + UAV)
    // Source texture must have D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS.
    bool GenerateMipmaps(ID3D12Resource* texture, uint32_t mipLevels);

    // Phase 5: Create mipmap generation compute pipeline (root signature + PSO)
    bool CreateMipGenPipeline();

    // Phase 6: Create shader-visible sampler descriptor heap
    bool CreateSamplerHeap();

    // Phase 6: Dynamic sampler descriptor heap management
    // Returns CPU/GPU descriptor handles for a sampler state; creates and caches if new.
    // The GPU handle is valid for binding to a root signature descriptor table slot.
    struct SamplerDescriptor {
        D3D12_CPU_DESCRIPTOR_HANDLE cpuHandle;
        D3D12_GPU_DESCRIPTOR_HANDLE gpuHandle;
    };
    SamplerDescriptor GetOrCreateSamplerDescriptor(const D3D12_SAMPLER_DESC& desc);

    // Binds the shader-visible sampler descriptor heap to the command list.
    // Call after BeginRenderPass or before drawing when sampler tables are needed.
    void BindSamplerHeap();

    // Phase 4: Resolve a render target to a texture (for MSAA or format conversion)
    bool ResolveRenderTarget(ID3D12Resource* srcRt, ID3D12Resource* dstTexture,
                             DXGI_FORMAT format);

    // Phase 4: Full render state objects (cached by descriptor)
    // Blend state
    const D3D12_BLEND_DESC* GetOrCreateBlendState(const D3D12_BLEND_DESC& desc);
    // Depth-stencil state
    const D3D12_DEPTH_STENCIL_DESC* GetOrCreateDepthStencilState(const D3D12_DEPTH_STENCIL_DESC& desc);
    // Rasterizer state
    const D3D12_RASTERIZER_DESC* GetOrCreateRasterizerState(const D3D12_RASTERIZER_DESC& desc);

    // Phase 4: Resource state tracking and automatic barrier insertion
    // Call before accessing a resource to ensure correct state transition.
    // Returns true if a barrier was emitted.
    bool TransitionResource(ID3D12Resource* resource,
                            D3D12_RESOURCE_STATES stateBefore,
                            D3D12_RESOURCE_STATES stateAfter,
                            UINT subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES);

    // Phase 4: Frame graph / render pass support
    // Begin a render pass: sets RTs/DSV, emits necessary barriers, clears if requested.
    // Passes an array of render target descriptors (format, clear color, load/store ops).
    struct RenderPassDesc {
        struct RTV {
            D3D12_CPU_DESCRIPTOR_HANDLE cpuHandle;
            DXGI_FORMAT format;
            float clearColor[4] = {0, 0, 0, 0};
            bool clear = false;
            D3D12_RESOURCE_STATES initialState = D3D12_RESOURCE_STATE_RENDER_TARGET;
            D3D12_RESOURCE_STATES finalState = D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE;
        };
        struct DSV {
            D3D12_CPU_DESCRIPTOR_HANDLE cpuHandle;
            DXGI_FORMAT format;
            float depthClear = 1.0f;
            UINT8 stencilClear = 0;
            bool clearDepth = false;
            bool clearStencil = false;
            D3D12_RESOURCE_STATES initialState = D3D12_RESOURCE_STATE_DEPTH_WRITE;
            D3D12_RESOURCE_STATES finalState = D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE;
        };
        std::vector<RTV> rtvs;
        std::optional<DSV> dsv;
        D3D12_VIEWPORT viewport = {};
        D3D12_RECT scissor = {};
    };
    bool BeginRenderPass(const RenderPassDesc& desc);
    void EndRenderPass();

    // Phase 7: Render Graph / Frame Graph Architecture
    // Declarative render graph builder for automatic barrier management and transient resource allocation.
    struct RenderGraphPass;
    class RenderGraphBuilder {
    public:
        // Opaque handle to a pass in the graph
        struct PassHandle { uint32_t index; };
        // Resource usage in a pass
        enum class ResourceUsage {
            Read,       // SRV
            Write,      // RTV/DSV/UAV
            ReadWrite   // UAV read+write
        };
        // Resource access info for a pass
        struct ResourceAccess {
            ID3D12Resource* resource = nullptr;
            ResourceUsage usage = ResourceUsage::Read;
            D3D12_RESOURCE_STATES beforeState = D3D12_RESOURCE_STATE_COMMON;
            D3D12_RESOURCE_STATES afterState = D3D12_RESOURCE_STATE_COMMON;
            UINT subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
        };
        // Transient resource description for allocation
        struct TransientResourceDesc {
            std::wstring name;
            D3D12_RESOURCE_DESC desc;
            D3D12_CLEAR_VALUE clearValue = {};
        };

        RenderGraphBuilder() = default;
        explicit RenderGraphBuilder(D3D12Backend* backend) : m_backend(backend) {}

        // Add a pass to the graph. `execute` is called during graph execution.
        // `resources` lists all resources accessed by this pass with their usage and state transitions.
        // Returns a handle to the pass for later reference.
        PassHandle AddPass(std::wstring name,
                           std::vector<ResourceAccess> resources,
                           std::function<void(ID3D12GraphicsCommandList*)> execute);

        // Request a transient resource. The graph will allocate/recycle based on lifetime.
        ID3D12Resource* GetTransientResource(const TransientResourceDesc& desc);

        // Build the graph: validates dependencies, performs topological sort, allocates transients.
        bool Build();

        // Execute the built graph on the current command list.
        void Execute();

        // Clear the graph for the next frame.
        void Reset();

    private:
        D3D12Backend* m_backend = nullptr;
        friend class D3D12Backend;
    };

    // Create a RenderGraphBuilder for the current frame.
    RenderGraphBuilder CreateRenderGraph();

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

    // Phase 5: Mipmap generation compute pipeline
    Microsoft::WRL::ComPtr<ID3D12RootSignature> m_mipGenRootSignature;
    Microsoft::WRL::ComPtr<ID3D12PipelineState> m_mipGenPipeline;

    // Static index buffer for the deterministic triangle, uploaded once and
    // cached by ResourceCache so later frames do not re-upload it.
    bool CreateStaticIndexBuffer();
    Microsoft::WRL::ComPtr<ID3D12Resource> m_staticIndexBuffer;
    ResourceCache m_resourceCache;

    // Phase 4 texture resources (decoded host-linear pixels -> texture + SRV).
    bool CreateSrvHeap();
    Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> m_srvHeap;
    uint32_t m_srvDescriptorSize = 0;
    Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> m_samplerHeap;
    uint32_t m_samplerDescriptorSize = 0;
    uint32_t m_samplerHeapOffset = 0;
    Microsoft::WRL::ComPtr<ID3D12Resource> m_decodedTexture;
    Microsoft::WRL::ComPtr<ID3D12Resource> m_decodedTextureUpload;
    D3D12_GPU_DESCRIPTOR_HANDLE m_decodedTextureSrvGpu = {};
    HRESULT m_lastPresentHr = S_OK;

DrawStats m_stats;

    // Phase 6: Dynamic sampler descriptor heap
    static constexpr uint32_t kSamplerHeapSize = 2048;
    // SamplerCacheKey and hash must be defined before the map that uses them
    struct SamplerCacheKey {
        D3D12_SAMPLER_DESC desc;
        bool operator==(const SamplerCacheKey& other) const {
            return memcmp(&desc, &other.desc, sizeof(D3D12_SAMPLER_DESC)) == 0;
        }
    };
    struct SamplerCacheKeyHash {
        size_t operator()(const SamplerCacheKey& k) const noexcept {
            const uint8_t* p = reinterpret_cast<const uint8_t*>(&k.desc);
            size_t h = 14695981039346656037ULL;
            for (size_t i = 0; i < sizeof(D3D12_SAMPLER_DESC); ++i) {
                h ^= p[i]; h *= 1099511628211ULL;
            }
            return h;
        }
    };
std::unordered_map<SamplerCacheKey, D3D12_SAMPLER_DESC, SamplerCacheKeyHash> m_samplerCache;
    std::vector<D3D12_STATIC_SAMPLER_DESC> m_staticSamplerArray;  // for root signature
    std::unordered_map<SamplerCacheKey, uint32_t, SamplerCacheKeyHash> m_samplerDescriptorIndex;  // desc -> heap index

    // Phase 4: Cached state objects
    // Samplers in D3D12 are either static (root signature) or descriptor heap entries.
    // We cache the descriptor descriptors for reuse.

    // For Blend/DepthStencil/Rasterizer states, D3D12 bakes them into PSOs.
    // We cache the descriptors for reuse when creating PSOs.
    struct BlendStateCacheKey {
        D3D12_BLEND_DESC desc;
        bool operator==(const BlendStateCacheKey& other) const {
            return memcmp(&desc, &other.desc, sizeof(D3D12_BLEND_DESC)) == 0;
        }
    };
    struct BlendStateCacheKeyHash {
        size_t operator()(const BlendStateCacheKey& k) const noexcept {
            const uint8_t* p = reinterpret_cast<const uint8_t*>(&k.desc);
            size_t h = 14695981039346656037ULL;
            for (size_t i = 0; i < sizeof(D3D12_BLEND_DESC); ++i) {
                h ^= p[i]; h *= 1099511628211ULL;
            }
            return h;
        }
    };
    std::unordered_map<BlendStateCacheKey, D3D12_BLEND_DESC, BlendStateCacheKeyHash> m_blendStateCache;

    struct DepthStencilStateCacheKey {
        D3D12_DEPTH_STENCIL_DESC desc;
        bool operator==(const DepthStencilStateCacheKey& other) const {
            return memcmp(&desc, &other.desc, sizeof(D3D12_DEPTH_STENCIL_DESC)) == 0;
        }
    };
    struct DepthStencilStateCacheKeyHash {
        size_t operator()(const DepthStencilStateCacheKey& k) const noexcept {
            const uint8_t* p = reinterpret_cast<const uint8_t*>(&k.desc);
            size_t h = 14695981039346656037ULL;
            for (size_t i = 0; i < sizeof(D3D12_DEPTH_STENCIL_DESC); ++i) {
                h ^= p[i]; h *= 1099511628211ULL;
            }
            return h;
        }
    };
    std::unordered_map<DepthStencilStateCacheKey, D3D12_DEPTH_STENCIL_DESC, DepthStencilStateCacheKeyHash> m_depthStencilStateCache;

    struct RasterizerStateCacheKey {
        D3D12_RASTERIZER_DESC desc;
        bool operator==(const RasterizerStateCacheKey& other) const {
            return memcmp(&desc, &other.desc, sizeof(D3D12_RASTERIZER_DESC)) == 0;
        }
    };
    struct RasterizerStateCacheKeyHash {
        size_t operator()(const RasterizerStateCacheKey& k) const noexcept {
            const uint8_t* p = reinterpret_cast<const uint8_t*>(&k.desc);
            size_t h = 14695981039346656037ULL;
            for (size_t i = 0; i < sizeof(D3D12_RASTERIZER_DESC); ++i) {
                h ^= p[i]; h *= 1099511628211ULL;
            }
            return h;
        }
    };
    std::unordered_map<RasterizerStateCacheKey, D3D12_RASTERIZER_DESC, RasterizerStateCacheKeyHash> m_rasterizerStateCache;

    // Resource state tracking for automatic barrier insertion
    struct ResourceStateEntry {
        D3D12_RESOURCE_STATES state = D3D12_RESOURCE_STATE_COMMON;
        UINT subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    };
    std::unordered_map<ID3D12Resource*, ResourceStateEntry> m_resourceStates;

    // Current render pass state
    std::optional<RenderPassDesc> m_activeRenderPass;

    // Phase 7: Render Graph state
    struct RenderGraphPass {
        std::wstring name;
        std::vector<RenderGraphBuilder::ResourceAccess> resources;
        std::function<void(ID3D12GraphicsCommandList*)> execute;
        std::vector<uint32_t> dependencies;  // indices of passes this depends on
        std::vector<uint32_t> dependents;    // indices of passes that depend on this
    };
    struct TransientResourceEntry {
        std::wstring name;
        D3D12_RESOURCE_DESC desc;
        D3D12_CLEAR_VALUE clearValue;
        Microsoft::WRL::ComPtr<ID3D12Resource> resource;
        uint64_t lastUsedFrame = 0;
        bool inUse = false;
    };
    std::vector<RenderGraphPass> m_renderGraphPasses;
    std::vector<TransientResourceEntry> m_transientResources;
    std::vector<uint32_t> m_renderGraphExecutionOrder;
    bool m_renderGraphBuilt = false;

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
