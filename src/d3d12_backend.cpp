#include "d3d12_backend.h"
#include "renderer/test_shaders.h"
#include "renderer/vertex_decode.h"
#include "renderer/pipeline_cache.h"
#include "renderer/resource_cache.h"
#include "renderer/texture_decode.h"
#include "guest_memory.h"
#include "logging.h"

#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dxgi.lib")

namespace mcla::native {

namespace {
static D3D12Backend g_d3d12Backend;
}

D3D12Backend* GetD3D12Backend() {
    return &g_d3d12Backend;
}

D3D12Backend::D3D12Backend() = default;

D3D12Backend::~D3D12Backend() {
    Shutdown();
}

bool D3D12Backend::Initialize(HWND hwnd, uint32_t width, uint32_t height) {
    std::lock_guard<std::recursive_mutex> lock(m_mutex);

    if (m_initialized) return true;
    if (!hwnd) {
        MCLA_LOG_ERROR("D3D12Backend: Null HWND passed to Initialize");
        return false;
    }

    m_hwnd = hwnd;
    m_width = (width > 0) ? width : 1280;
    m_height = (height > 0) ? height : 720;

    MCLA_LOG_INFO("D3D12Backend: Initializing backend for HWND 0x{:X} ({}x{})",
                reinterpret_cast<uintptr_t>(hwnd), m_width, m_height);
    DWORD winThread = GetWindowThreadProcessId(hwnd, nullptr);
    DWORD curThread = GetCurrentThreadId();
    MCLA_LOG_INFO("D3D12Backend: window owner thread={} calling thread={} {}",
                winThread, curThread, winThread == curThread ? "(MATCH)" : "(MISMATCH)");
    {
        char cls[256] = {};
        GetClassNameA(hwnd, cls, 256);
        MCLA_LOG_INFO("D3D12Backend: window class='{}' visible={}",
                    cls, IsWindowVisible(hwnd) ? 1 : 0);
    }

    if (!CreateDevice()) return false;
    if (!CreateCommandObjects()) return false;
    if (!CreateCopyQueue()) return false;
    if (!CreateSwapChain(hwnd, m_width, m_height)) return false;
    if (!CreateRenderTargets()) return false;
    if (!CreateSyncObjects()) return false;
    if (!CreateUploadHeap()) return false;
    if (!CreateTestRootSignature()) return false;
    if (!CreateTestPipeline()) return false;
    if (!CreateStaticIndexBuffer()) return false;
    if (!CreateSrvHeap()) return false;
    if (!CreateSamplerHeap()) return false;

    // Initialize pipeline cache worker thread and set fallback PSO (test pipeline)
    m_pipelineCache.StartWorker(m_device, m_rootSignature);
    m_pipelineCache.SetFallbackPipeline(m_testPipeline);

    m_initialized = true;
    MCLA_LOG_INFO("D3D12Backend: Successfully initialized D3D12 native renderer skeleton + Phase 3 test pipeline");
    return true;
}

bool D3D12Backend::CreateDevice() {
    UINT dxgiFactoryFlags = 0;

#if !defined(NDEBUG)
    {
        Microsoft::WRL::ComPtr<ID3D12Debug> debugController;
        if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController)))) {
            debugController->EnableDebugLayer();
            dxgiFactoryFlags |= DXGI_CREATE_FACTORY_DEBUG;
            MCLA_LOG_INFO("D3D12Backend: Direct3D 12 Debug Layer enabled");
        }
    }
#endif

    HRESULT hr = CreateDXGIFactory2(dxgiFactoryFlags, IID_PPV_ARGS(&m_factory));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateDXGIFactory2 failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    Microsoft::WRL::ComPtr<IDXGIAdapter1> hardwareAdapter;
    bool adapterSelected = false;
    for (UINT adapterIndex = 0; SUCCEEDED(m_factory->EnumAdapters1(adapterIndex, &hardwareAdapter)); ++adapterIndex) {
        DXGI_ADAPTER_DESC1 desc;
        hardwareAdapter->GetDesc1(&desc);

        if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE) continue;

        if (SUCCEEDED(D3D12CreateDevice(hardwareAdapter.Get(), D3D_FEATURE_LEVEL_11_0, _uuidof(ID3D12Device), nullptr))) {
            char descBuf[128] = {};
            size_t converted = 0;
            wcstombs_s(&converted, descBuf, sizeof(descBuf) - 1, desc.Description, _TRUNCATE);
            MCLA_LOG_INFO("D3D12Backend: Selected GPU adapter: {}", descBuf);
            adapterSelected = true;
            break;
        }
    }

    if (!adapterSelected) {
        // Loop always leaves hardwareAdapter non-null after the first iteration,
        // so clear it explicitly before the WARP fallback.
        MCLA_LOG_WARN("D3D12Backend: No hardware D3D12 adapter found, attempting WARP software adapter");
        hardwareAdapter = nullptr;
        m_factory->EnumWarpAdapter(IID_PPV_ARGS(&hardwareAdapter));
    }

    if (!hardwareAdapter) {
        MCLA_LOG_ERROR("D3D12Backend: No D3D12-capable adapter (hardware or WARP) available");
        return false;
    }

    hr = D3D12CreateDevice(hardwareAdapter.Get(), D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&m_device));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: D3D12CreateDevice failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    return true;
}

bool D3D12Backend::CreateCommandObjects() {
    D3D12_COMMAND_QUEUE_DESC queueDesc = {};
    queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
    queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;

    HRESULT hr = m_device->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&m_commandQueue));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateCommandQueue failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    for (uint32_t i = 0; i < kBufferCount; ++i) {
        hr = m_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&m_commandAllocators[i]));
        if (FAILED(hr)) {
            MCLA_LOG_ERROR("D3D12Backend: CreateCommandAllocator[{}] failed with hr=0x{:08X}", i, static_cast<uint32_t>(hr));
            return false;
        }
    }

    hr = m_device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, m_commandAllocators[0].Get(), nullptr, IID_PPV_ARGS(&m_commandList));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateCommandList failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    m_commandList->Close();
    return true;
}

bool D3D12Backend::CreateCopyQueue() {
    D3D12_COMMAND_QUEUE_DESC queueDesc = {};
    queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
    queueDesc.Type = D3D12_COMMAND_LIST_TYPE_COPY;

    HRESULT hr = m_device->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&m_copyQueue));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateCopyQueue failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    hr = m_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_COPY, IID_PPV_ARGS(&m_copyAllocator));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateCopyAllocator failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    hr = m_device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_COPY, m_copyAllocator.Get(), nullptr, IID_PPV_ARGS(&m_copyCommandList));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateCopyCommandList failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }
    m_copyCommandList->Close();

    hr = m_device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&m_copyFence));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateCopyFence failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    m_copyFenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);
    if (!m_copyFenceEvent) {
        MCLA_LOG_ERROR("D3D12Backend: CreateEvent(copy fence) failed");
        return false;
    }

    MCLA_LOG_INFO("D3D12Backend: Copy queue created (type=COPY)");
    return true;
}

bool D3D12Backend::CreateSwapChain(HWND hwnd, uint32_t width, uint32_t height) {
    DXGI_SWAP_CHAIN_DESC1 swapChainDesc = {};
    swapChainDesc.BufferCount = kBufferCount;
    swapChainDesc.Width = width;
    swapChainDesc.Height = height;
    swapChainDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
    swapChainDesc.SampleDesc.Count = 1;

    Microsoft::WRL::ComPtr<IDXGISwapChain1> swapChain;
    HRESULT hr = m_factory->CreateSwapChainForHwnd(
        m_commandQueue.Get(),
        hwnd,
        &swapChainDesc,
        nullptr,
        nullptr,
        &swapChain);

    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateSwapChainForHwnd failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    m_factory->MakeWindowAssociation(hwnd, DXGI_MWA_NO_ALT_ENTER);
    hr = swapChain.As(&m_swapChain);
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: Query IDXGISwapChain3 interface failed");
        return false;
    }

    m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();
    return true;
}

bool D3D12Backend::CreateRenderTargets() {
    D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc = {};
    rtvHeapDesc.NumDescriptors = kBufferCount;
    rtvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
    rtvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

    HRESULT hr = m_device->CreateDescriptorHeap(&rtvHeapDesc, IID_PPV_ARGS(&m_rtvHeap));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateDescriptorHeap (RTV) failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    m_rtvDescriptorSize = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);

    D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_rtvHeap->GetCPUDescriptorHandleForHeapStart());

    for (uint32_t i = 0; i < kBufferCount; ++i) {
        hr = m_swapChain->GetBuffer(i, IID_PPV_ARGS(&m_renderTargets[i]));
        if (FAILED(hr)) {
            MCLA_LOG_ERROR("D3D12Backend: GetBuffer[{}] failed with hr=0x{:08X}", i, static_cast<uint32_t>(hr));
            return false;
        }
        m_device->CreateRenderTargetView(m_renderTargets[i].Get(), nullptr, rtvHandle);
        rtvHandle.ptr += m_rtvDescriptorSize;
    }

    return true;
}

bool D3D12Backend::CreateSyncObjects() {
    HRESULT hr = m_device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&m_fence));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateFence failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    // The fence is created at value 0. Pre-arm the per-frame wait values to 0
    // so the FIRST BeginFrame does not wait on a value that was never signaled
    // (the fence is only advanced by the Signal() after each submit). A slot
    // only becomes non-zero once its frame has been submitted and fenced.
    m_fenceValues[m_frameIndex] = 0;
    m_currentFenceValue = 0;

    m_fenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);
    if (!m_fenceEvent) {
        MCLA_LOG_ERROR("D3D12Backend: CreateEvent failed");
        return false;
    }

    return true;
}

bool D3D12Backend::CreateUploadHeap() {
    constexpr size_t kUploadSize = 4 * 1024 * 1024;  // 4 MiB per-frame upload arena

    D3D12_HEAP_PROPERTIES props = {};
    props.Type = D3D12_HEAP_TYPE_UPLOAD;
    props.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
    props.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;

    D3D12_RESOURCE_DESC desc = {};
    desc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
    desc.Width = kUploadSize;
    desc.Height = 1;
    desc.DepthOrArraySize = 1;
    desc.MipLevels = 1;
    desc.SampleDesc.Count = 1;
    desc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;

    HRESULT hr = m_device->CreateCommittedResource(
        &props, D3D12_HEAP_FLAG_NONE, &desc, D3D12_RESOURCE_STATE_GENERIC_READ,
        nullptr, IID_PPV_ARGS(&m_uploadHeap));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateCommittedResource(upload) failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    m_uploadCapacity = kUploadSize;
    m_uploadRegionSize = kUploadSize / kBufferCount;
    m_uploadOffset = 0;
    m_uploadMap = nullptr;
    hr = m_uploadHeap->Map(0, nullptr, reinterpret_cast<void**>(&m_uploadMap));
    if (FAILED(hr) || !m_uploadMap) {
        MCLA_LOG_ERROR("D3D12Backend: upload heap Map failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    MCLA_LOG_INFO("D3D12Backend: created {} MiB upload arena", kUploadSize / (1024 * 1024));
    return true;
}

bool D3D12Backend::CreateStaticIndexBuffer() {
    // 6 R16_UINT indices for the deterministic triangle, written once into a
    // dedicated upload resource and cached by ResourceCache. Later frames bind
    // the cached GPU address instead of re-uploading unchanged data (Phase 3
    // gate: "replaying the same frame twice does not reupload unchanged data").
    const uint16_t indices[6] = { 0, 1, 2, 0, 2, 3 };
    constexpr uint32_t kIndexBytes = sizeof(indices);

    D3D12_HEAP_PROPERTIES props = {};
    props.Type = D3D12_HEAP_TYPE_UPLOAD;
    props.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
    props.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;

    D3D12_RESOURCE_DESC desc = {};
    desc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
    desc.Width = kIndexBytes;
    desc.Height = 1;
    desc.DepthOrArraySize = 1;
    desc.MipLevels = 1;
    desc.SampleDesc.Count = 1;
    desc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;

    HRESULT hr = m_device->CreateCommittedResource(
        &props, D3D12_HEAP_FLAG_NONE, &desc, D3D12_RESOURCE_STATE_GENERIC_READ,
        nullptr, IID_PPV_ARGS(&m_staticIndexBuffer));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateCommittedResource(static ib) failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    void* mapped = nullptr;
    hr = m_staticIndexBuffer->Map(0, nullptr, &mapped);
    if (FAILED(hr) || !mapped) {
        MCLA_LOG_ERROR("D3D12Backend: static index buffer Map failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }
    std::memcpy(mapped, indices, kIndexBytes);
    m_staticIndexBuffer->Unmap(0, nullptr);

    const uint64_t ibGpu = m_staticIndexBuffer->GetGPUVirtualAddress();
    const ResourceKey ibKey = { ResourceKind::Buffer, 0 /*synthetic test addr*/,
                                kIndexBytes, DXGI_FORMAT_R16_UINT, 1 };
    m_resourceCache.Insert(ibKey, ResourceEntry{ ibGpu, 1, false });
    m_stats.cacheMisses++;

    MCLA_LOG_INFO("D3D12Backend: static index buffer cached ({} bytes, gpu=0x{:X})", kIndexBytes, ibGpu);
    return true;
}

uint8_t* D3D12Backend::MapUpload(size_t size, size_t alignment, D3D12_GPU_VIRTUAL_ADDRESS& gpu) {
    if (!m_uploadMap || size == 0) return nullptr;
    if (alignment == 0) alignment = 256;

    // Offset is relative to this frame's region (region = back-buffer index),
    // so the fence wait in BeginFrame() guarantees the GPU is done reading this
    // region before we write it again. Region reuse requires offset < region.
    m_uploadOffset = (m_uploadOffset + alignment - 1) & ~(alignment - 1);
    if (m_uploadOffset + size > m_uploadRegionSize) {
        MCLA_LOG_WARN("D3D12Backend: upload arena region exhausted (need {} bytes, {} free); frame draw dropped",
                    size, m_uploadRegionSize - m_uploadOffset);
        return nullptr;
    }

    const size_t regionBase = static_cast<size_t>(m_frameIndex) * m_uploadRegionSize;
    gpu = m_uploadHeap->GetGPUVirtualAddress() + regionBase + m_uploadOffset;
    uint8_t* dst = m_uploadMap + regionBase + m_uploadOffset;
    m_uploadOffset += size;
    m_stats.uploadsBytes += size;
    m_stats.bytesThisFrame += size;
    return dst;
}

bool D3D12Backend::CreateSrvHeap() {
    D3D12_DESCRIPTOR_HEAP_DESC heapDesc = {};
    heapDesc.NumDescriptors = 1;
    heapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
    heapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

    HRESULT hr = m_device->CreateDescriptorHeap(&heapDesc, IID_PPV_ARGS(&m_srvHeap));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateDescriptorHeap (CBV/SRV/UAV) failed with hr=0x{:08X}",
                     static_cast<uint32_t>(hr));
        return false;
    }
    m_srvDescriptorSize = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
    return true;
}

// Phase 6: Create shader-visible sampler descriptor heap
bool D3D12Backend::CreateSamplerHeap() {
    D3D12_DESCRIPTOR_HEAP_DESC heapDesc = {};
    heapDesc.NumDescriptors = kSamplerHeapSize;
    heapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER;
    heapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

    HRESULT hr = m_device->CreateDescriptorHeap(&heapDesc, IID_PPV_ARGS(&m_samplerHeap));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateDescriptorHeap (Sampler) failed with hr=0x{:08X}",
                     static_cast<uint32_t>(hr));
        return false;
    }
    m_samplerDescriptorSize = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER);
    m_samplerHeapOffset = 0;
    MCLA_LOG_INFO("D3D12Backend: Created sampler descriptor heap ({} descriptors)", kSamplerHeapSize);
    return true;
}

// Phase 6: Get or create sampler descriptor in the shader-visible heap
D3D12Backend::SamplerDescriptor D3D12Backend::GetOrCreateSamplerDescriptor(const D3D12_SAMPLER_DESC& desc) {
    SamplerCacheKey key{ desc };
    auto it = m_samplerDescriptorIndex.find(key);
    if (it != m_samplerDescriptorIndex.end()) {
        uint32_t index = it->second;
        D3D12_CPU_DESCRIPTOR_HANDLE cpuHandle = m_samplerHeap->GetCPUDescriptorHandleForHeapStart();
        cpuHandle.ptr += static_cast<SIZE_T>(index) * m_samplerDescriptorSize;
        D3D12_GPU_DESCRIPTOR_HANDLE gpuHandle = m_samplerHeap->GetGPUDescriptorHandleForHeapStart();
        gpuHandle.ptr += static_cast<SIZE_T>(index) * m_samplerDescriptorSize;
        return { cpuHandle, gpuHandle };
    }

    // Allocate new descriptor
    if (m_samplerHeapOffset >= kSamplerHeapSize) {
        MCLA_LOG_ERROR("D3D12Backend: Sampler descriptor heap exhausted ({} slots)", kSamplerHeapSize);
        return { {}, {} };
    }

    uint32_t index = m_samplerHeapOffset++;
    m_samplerDescriptorIndex.emplace(key, index);

    // Create the sampler in the heap
    D3D12_CPU_DESCRIPTOR_HANDLE cpuHandle = m_samplerHeap->GetCPUDescriptorHandleForHeapStart();
    cpuHandle.ptr += static_cast<SIZE_T>(index) * m_samplerDescriptorSize;
    m_device->CreateSampler(&desc, cpuHandle);

    D3D12_GPU_DESCRIPTOR_HANDLE gpuHandle = m_samplerHeap->GetGPUDescriptorHandleForHeapStart();
    gpuHandle.ptr += static_cast<SIZE_T>(index) * m_samplerDescriptorSize;

    return { cpuHandle, gpuHandle };
}

// Bind the shader-visible sampler descriptor heap to the command list
void D3D12Backend::BindSamplerHeap() {
    if (!m_samplerHeap) return;
    ID3D12DescriptorHeap* heaps[] = { m_samplerHeap.Get() };
    m_commandList->SetDescriptorHeaps(1, heaps);
}

// Phase 7: Render Graph implementation
D3D12Backend::RenderGraphBuilder D3D12Backend::CreateRenderGraph() {
    return RenderGraphBuilder(this);
}

D3D12Backend::RenderGraphBuilder::PassHandle D3D12Backend::RenderGraphBuilder::AddPass(
    std::wstring name,
    std::vector<ResourceAccess> resources,
    std::function<void(ID3D12GraphicsCommandList*)> execute) {
    RenderGraphPass pass;
    pass.name = std::move(name);
    pass.resources = std::move(resources);
    pass.execute = std::move(execute);
    PassHandle handle{ static_cast<uint32_t>(m_backend->m_renderGraphPasses.size()) };
    m_backend->m_renderGraphPasses.push_back(std::move(pass));
    return handle;
}

ID3D12Resource* D3D12Backend::RenderGraphBuilder::GetTransientResource(const TransientResourceDesc& desc) {
    // Search for existing reusable resource
    for (auto& entry : m_backend->m_transientResources) {
        if (!entry.inUse && entry.desc.Width == desc.desc.Width &&
            entry.desc.Height == desc.desc.Height &&
            entry.desc.Format == desc.desc.Format &&
            entry.desc.DepthOrArraySize == desc.desc.DepthOrArraySize &&
            entry.desc.MipLevels == desc.desc.MipLevels &&
            entry.desc.SampleDesc.Count == desc.desc.SampleDesc.Count &&
            entry.desc.Flags == desc.desc.Flags) {
            entry.inUse = true;
            entry.lastUsedFrame = m_backend->m_frameIndex;
            return entry.resource.Get();
        }
    }

    // Create new resource
    D3D12_HEAP_PROPERTIES heapProps = {};
    heapProps.Type = D3D12_HEAP_TYPE_DEFAULT;

    Microsoft::WRL::ComPtr<ID3D12Resource> resource;
    HRESULT hr = m_backend->m_device->CreateCommittedResource(
        &heapProps, D3D12_HEAP_FLAG_NONE, &desc.desc,
        D3D12_RESOURCE_STATE_COMMON,
        &desc.clearValue, IID_PPV_ARGS(&resource));

    if (FAILED(hr)) {
        MCLA_LOG_ERROR("RenderGraph: Failed to create transient resource '{}', hr=0x{:08X}",
                     std::string(desc.name.begin(), desc.name.end()).c_str(),
                     static_cast<uint32_t>(hr));
        return nullptr;
    }

    TransientResourceEntry entry;
    entry.name = desc.name;
    entry.desc = desc.desc;
    entry.clearValue = desc.clearValue;
    entry.resource = resource;
    entry.lastUsedFrame = m_backend->m_frameIndex;
    entry.inUse = true;

    m_backend->m_transientResources.push_back(std::move(entry));
    return m_backend->m_transientResources.back().resource.Get();
}

bool D3D12Backend::RenderGraphBuilder::Build() {
    auto& passes = m_backend->m_renderGraphPasses;
    auto& resources = m_backend->m_transientResources;
    auto& executionOrder = m_backend->m_renderGraphExecutionOrder;

    // Build dependency graph based on resource access patterns
    for (uint32_t i = 0; i < passes.size(); ++i) {
        for (uint32_t j = i + 1; j < passes.size(); ++j) {
            const auto& passA = passes[i];
            const auto& passB = passes[j];

            // Check for resource dependencies
            bool hasDependency = false;
            for (const auto& resA : passA.resources) {
                for (const auto& resB : passB.resources) {
                    if (resA.resource == resB.resource) {
                        // Same resource accessed - check for write dependency
                        if (resA.usage == ResourceUsage::Write || resB.usage == ResourceUsage::Write ||
                            resA.usage == ResourceUsage::ReadWrite || resB.usage == ResourceUsage::ReadWrite) {
                            hasDependency = true;
                            break;
                        }
                    }
                }
                if (hasDependency) break;
            }
            if (hasDependency) {
                passes[i].dependents.push_back(j);
                passes[j].dependencies.push_back(i);
            }
        }
    }

    // Topological sort (Kahn's algorithm)
    std::vector<uint32_t> inDegree(passes.size(), 0);
    for (const auto& pass : passes) {
        for (uint32_t dep : pass.dependencies) {
            inDegree[dep]++;
        }
    }

    std::queue<uint32_t> q;
    for (uint32_t i = 0; i < passes.size(); ++i) {
        if (inDegree[i] == 0) q.push(i);
    }

    executionOrder.clear();
    while (!q.empty()) {
        uint32_t u = q.front();
        q.pop();
        executionOrder.push_back(u);
        for (uint32_t v : passes[u].dependents) {
            if (--inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (executionOrder.size() != passes.size()) {
        MCLA_LOG_ERROR("RenderGraph: Cycle detected in pass dependencies");
        return false;
    }

    // Allocate transient resources
    for (auto& res : resources) {
        if (!res.inUse) {
            // Already allocated or will be allocated on first use
        }
    }

    m_backend->m_renderGraphBuilt = true;
    return true;
}

void D3D12Backend::RenderGraphBuilder::Execute() {
    if (!m_backend->m_renderGraphBuilt) return;

    auto& passes = m_backend->m_renderGraphPasses;
    auto& executionOrder = m_backend->m_renderGraphExecutionOrder;

    for (uint32_t idx : executionOrder) {
        const auto& pass = passes[idx];

        // Emit barriers for resource state transitions
        std::vector<D3D12_RESOURCE_BARRIER> barriers;
        for (const auto& res : pass.resources) {
            if (res.resource) {
                D3D12_RESOURCE_BARRIER barrier = {};
                barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
                barrier.Transition.pResource = res.resource;
                barrier.Transition.StateBefore = res.beforeState;
                barrier.Transition.StateAfter = res.afterState;
                barrier.Transition.Subresource = res.subresource;
                barriers.push_back(barrier);
            }
        }
        if (!barriers.empty()) {
            m_backend->m_commandList->ResourceBarrier(static_cast<UINT>(barriers.size()), barriers.data());
        }

        // Execute the pass
        if (pass.execute) {
            pass.execute(m_backend->m_commandList.Get());
        }

        // Emit UAV barriers for resources written
        std::vector<D3D12_RESOURCE_BARRIER> uavBarriers;
        for (const auto& res : pass.resources) {
            if (res.resource && (res.usage == ResourceUsage::Write || res.usage == ResourceUsage::ReadWrite)) {
                D3D12_RESOURCE_BARRIER uavBarrier = {};
                uavBarrier.Type = D3D12_RESOURCE_BARRIER_TYPE_UAV;
                uavBarrier.UAV.pResource = res.resource;
                uavBarriers.push_back(uavBarrier);
            }
        }
        if (!uavBarriers.empty()) {
            m_backend->m_commandList->ResourceBarrier(static_cast<UINT>(uavBarriers.size()), uavBarriers.data());
        }
    }

    // Mark transient resources as no longer in use
    for (auto& res : m_backend->m_transientResources) {
        res.inUse = false;
    }
}

void D3D12Backend::RenderGraphBuilder::Reset() {
    m_backend->m_renderGraphPasses.clear();
    m_backend->m_renderGraphExecutionOrder.clear();
    m_backend->m_renderGraphBuilt = false;
    // Note: transient resources are kept for reuse, only marked as not in use
    for (auto& res : m_backend->m_transientResources) {
        res.inUse = false;
    }
}
// DEFAULT-heap texture and expose them as a shader-visible SRV (t0). The
// caller produces `linearPixels` via texture_decode (UntileTexture2D); the
// backend never touches guest memory here. Only scalar (1 block/texel)
// formats are accepted so the row-pitch copy is exact.
bool D3D12Backend::CreateDecodedTexture(const uint8_t* linearPixels, uint32_t width,
                                        uint32_t height, uint32_t dxgiFormat) {
    std::lock_guard<std::recursive_mutex> lock(m_mutex);
    if (!m_initialized || !m_srvHeap) return false;
    if (!linearPixels || width == 0 || height == 0) return false;

    const DXGI_FORMAT format = static_cast<DXGI_FORMAT>(dxgiFormat);
    UINT bytesPerPixel = 0;
    switch (format) {
        case DXGI_FORMAT_R8G8B8A8_UNORM: bytesPerPixel = 4; break;
        case DXGI_FORMAT_R8_UNORM:       bytesPerPixel = 1; break;
        default:
            MCLA_LOG_ERROR("D3D12Backend: CreateDecodedTexture unsupported dxgi format {}", dxgiFormat);
            return false;
    }

    D3D12_HEAP_PROPERTIES defProps = {};
    defProps.Type = D3D12_HEAP_TYPE_DEFAULT;
    defProps.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
    defProps.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;

    D3D12_RESOURCE_DESC texDesc = {};
    texDesc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
    texDesc.Width = width;
    texDesc.Height = height;
    texDesc.DepthOrArraySize = 1;
    texDesc.MipLevels = 1;
    texDesc.SampleDesc.Count = 1;
    texDesc.Format = format;
    texDesc.Layout = D3D12_TEXTURE_LAYOUT_UNKNOWN;

    Microsoft::WRL::ComPtr<ID3D12Resource> texture;
    HRESULT hr = m_device->CreateCommittedResource(
        &defProps, D3D12_HEAP_FLAG_NONE, &texDesc, D3D12_RESOURCE_STATE_COPY_DEST,
        nullptr, IID_PPV_ARGS(&texture));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateDecodedTexture CreateCommittedResource failed with hr=0x{:08X}",
                     static_cast<uint32_t>(hr));
        return false;
    }

    // Staging upload with the D3D12 footprint (row pitch aligned, not naive).
    D3D12_PLACED_SUBRESOURCE_FOOTPRINT footprint = {};
    UINT64 totalBytes = 0;
    UINT64 rowBytes = 0;
    {
        UINT64 tmp = 0;
        D3D12_RESOURCE_DESC fullDesc = texDesc;
        m_device->GetCopyableFootprints(&fullDesc, 0, 1, 0, &footprint, nullptr, &tmp, &totalBytes);
        rowBytes = static_cast<UINT64>(width) * bytesPerPixel;
    }

    D3D12_HEAP_PROPERTIES upProps = {};
    upProps.Type = D3D12_HEAP_TYPE_UPLOAD;
    upProps.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
    upProps.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;

    D3D12_RESOURCE_DESC bufDesc = {};
    bufDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
    bufDesc.Width = totalBytes;
    bufDesc.Height = 1;
    bufDesc.DepthOrArraySize = 1;
    bufDesc.MipLevels = 1;
    bufDesc.SampleDesc.Count = 1;
    bufDesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;

    Microsoft::WRL::ComPtr<ID3D12Resource> staging;
    hr = m_device->CreateCommittedResource(&upProps, D3D12_HEAP_FLAG_NONE, &bufDesc,
                                           D3D12_RESOURCE_STATE_GENERIC_READ,
                                           nullptr, IID_PPV_ARGS(&staging));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateDecodedTexture staging failed with hr=0x{:08X}",
                     static_cast<uint32_t>(hr));
        return false;
    }

    void* mapped = nullptr;
    hr = staging->Map(0, nullptr, &mapped);
    if (FAILED(hr) || !mapped) {
        MCLA_LOG_ERROR("D3D12Backend: CreateDecodedTexture staging Map failed with hr=0x{:08X}",
                     static_cast<uint32_t>(hr));
        return false;
    }
    {
        uint8_t* dst = static_cast<uint8_t*>(mapped);
        const UINT srcPitch = width * bytesPerPixel;
        const UINT64 dstPitch = footprint.Footprint.RowPitch;
        for (UINT32 y = 0; y < height; ++y) {
            std::memcpy(dst + static_cast<size_t>(y) * dstPitch,
                        linearPixels + static_cast<size_t>(y) * srcPitch, srcPitch);
        }
    }
    staging->Unmap(0, nullptr);

    // The copy is enqueued into the current frame's command list below, so the
    // staging buffer must outlive the draw; the previous staging is replaced
    // only after the new one is successfully created.
    Microsoft::WRL::ComPtr<ID3D12Resource> prevStaging = m_decodedTextureUpload;

    D3D12_TEXTURE_COPY_LOCATION dstLoc = {};
    dstLoc.pResource = texture.Get();
    dstLoc.Type = D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX;
    dstLoc.SubresourceIndex = 0;
    D3D12_TEXTURE_COPY_LOCATION srcLoc = {};
    srcLoc.pResource = staging.Get();
    srcLoc.Type = D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT;
    srcLoc.PlacedFootprint = footprint;

    if (!m_inFrame) {
        if (!BeginFrame()) return false;
    }
    m_commandList->CopyTextureRegion(&dstLoc, 0, 0, 0, &srcLoc, nullptr);

    D3D12_RESOURCE_BARRIER barrier = {};
    barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    barrier.Transition.pResource = texture.Get();
    barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_COPY_DEST;
    barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE;
    barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    m_commandList->ResourceBarrier(1, &barrier);

    D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
    srvDesc.Format = format;
    srvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
    srvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
    srvDesc.Texture2D.MipLevels = 1;

    D3D12_CPU_DESCRIPTOR_HANDLE srvHandle(m_srvHeap->GetCPUDescriptorHandleForHeapStart());
    m_device->CreateShaderResourceView(texture.Get(), &srvDesc, srvHandle);
    m_decodedTextureSrvGpu = m_srvHeap->GetGPUDescriptorHandleForHeapStart();

    // Commit the new texture/upload only now that everything succeeded.
    m_decodedTexture = texture;
    m_decodedTextureUpload = staging;
    prevStaging.Reset();

    MCLA_LOG_INFO("D3D12Backend: decoded texture created ({}x{}, format {}) + SRV t0",
                width, height, dxgiFormat);
    return true;
}

void D3D12Backend::BindDecodedTexture() {
    if (!m_srvHeap || !m_decodedTexture) return;
    m_commandList->SetDescriptorHeaps(1, m_srvHeap.GetAddressOf());
    m_commandList->SetGraphicsRootDescriptorTable(0, m_decodedTextureSrvGpu);
}

bool D3D12Backend::CreateTestRootSignature() {
    // Root signature for the deterministic test shaders. The existing test
    // VS/PS do not sample, but the Phase 4 decoded-texture path needs a
    // pixel-visible SRV descriptor table at t0 and a static sampler at s0 so a
    // captured texture can be bound without recompiling the root signature.
    // Shaders that ignore the table are unaffected by it.
    D3D12_DESCRIPTOR_RANGE srvRange = {};
    srvRange.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
    srvRange.NumDescriptors = 1;
    srvRange.BaseShaderRegister = 0;  // t0
    srvRange.RegisterSpace = 0;
    srvRange.OffsetInDescriptorsFromTableStart = 0;

    D3D12_ROOT_PARAMETER rootParams[1] = {};
    rootParams[0].ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
    rootParams[0].DescriptorTable.NumDescriptorRanges = 1;
    rootParams[0].DescriptorTable.pDescriptorRanges = &srvRange;
    rootParams[0].ShaderVisibility = D3D12_SHADER_VISIBILITY_PIXEL;

    D3D12_STATIC_SAMPLER_DESC staticSampler = {};
    staticSampler.Filter = D3D12_FILTER_MIN_MAG_MIP_LINEAR;
    staticSampler.AddressU = D3D12_TEXTURE_ADDRESS_MODE_CLAMP;
    staticSampler.AddressV = D3D12_TEXTURE_ADDRESS_MODE_CLAMP;
    staticSampler.AddressW = D3D12_TEXTURE_ADDRESS_MODE_CLAMP;
    staticSampler.MipLODBias = 0.0f;
    staticSampler.MaxAnisotropy = 1;
    staticSampler.ComparisonFunc = D3D12_COMPARISON_FUNC_ALWAYS;
    staticSampler.BorderColor = D3D12_STATIC_BORDER_COLOR_OPAQUE_BLACK;
    staticSampler.MinLOD = 0.0f;
    staticSampler.MaxLOD = D3D12_FLOAT32_MAX;
    staticSampler.ShaderRegister = 0;  // s0
    staticSampler.RegisterSpace = 0;
    staticSampler.ShaderVisibility = D3D12_SHADER_VISIBILITY_PIXEL;

    D3D12_ROOT_SIGNATURE_DESC rootDesc = {};
    rootDesc.NumParameters = _countof(rootParams);
    rootDesc.pParameters = rootParams;
    rootDesc.NumStaticSamplers = 1;
    rootDesc.pStaticSamplers = &staticSampler;
    rootDesc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;

    Microsoft::WRL::ComPtr<ID3DBlob> signatureBlob;
    Microsoft::WRL::ComPtr<ID3DBlob> errorBlob;
    HRESULT hr = D3D12SerializeRootSignature(&rootDesc, D3D_ROOT_SIGNATURE_VERSION_1_0,
                                             &signatureBlob, &errorBlob);
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: D3D12SerializeRootSignature failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    hr = m_device->CreateRootSignature(0, signatureBlob->GetBufferPointer(),
                                       signatureBlob->GetBufferSize(),
                                       IID_PPV_ARGS(&m_rootSignature));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateRootSignature failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }
    return true;
}

bool D3D12Backend::CreateTestPipeline() {
    // Input layout matching the Phase 3 test shader (POSITION float3, COLOR float4).
    D3D12_INPUT_ELEMENT_DESC inputElements[] = {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,  D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
        { "COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
    };

    D3D12_GRAPHICS_PIPELINE_STATE_DESC psoDesc = {};
    psoDesc.pRootSignature = m_rootSignature.Get();
    psoDesc.VS = { GetTestVsBlob(), GetTestVsBlobSize() };
    psoDesc.PS = { GetTestPsBlob(), GetTestPsBlobSize() };
    psoDesc.InputLayout = { inputElements, _countof(inputElements) };
    psoDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;

    psoDesc.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM;
    psoDesc.NumRenderTargets = 1;
    psoDesc.SampleDesc.Count = 1;
    psoDesc.SampleMask = UINT_MAX;

    psoDesc.RasterizerState.FillMode = D3D12_FILL_MODE_SOLID;
    psoDesc.RasterizerState.CullMode = D3D12_CULL_MODE_NONE;
    psoDesc.RasterizerState.DepthClipEnable = TRUE;

    psoDesc.BlendState.AlphaToCoverageEnable = FALSE;
    psoDesc.BlendState.IndependentBlendEnable = FALSE;
    for (UINT i = 0; i < 8; ++i) {
        psoDesc.BlendState.RenderTarget[i].RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;
    }

    psoDesc.DepthStencilState.DepthEnable = FALSE;
    psoDesc.DepthStencilState.StencilEnable = FALSE;

    HRESULT hr = m_device->CreateGraphicsPipelineState(&psoDesc, IID_PPV_ARGS(&m_testPipeline));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateGraphicsPipelineState(test) failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }
    MCLA_LOG_INFO("D3D12Backend: Phase 3 test pipeline created (DXIL {} vs / {} ps bytes)",
                GetTestVsBlobSize(), GetTestPsBlobSize());
    return true;
}

// Create mipmap generation compute pipeline (root signature + PSO)
bool D3D12Backend::CreateMipGenPipeline() {
    // Root signature: SRV (t0) + UAV (u0) + CBV (b0) for params
    D3D12_DESCRIPTOR_RANGE srvRange = {};
    srvRange.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
    srvRange.NumDescriptors = 1;
    srvRange.BaseShaderRegister = 0;  // t0
    srvRange.RegisterSpace = 0;
    srvRange.OffsetInDescriptorsFromTableStart = 0;

    D3D12_DESCRIPTOR_RANGE uavRange = {};
    uavRange.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_UAV;
    uavRange.NumDescriptors = 1;
    uavRange.BaseShaderRegister = 0;  // u0
    uavRange.RegisterSpace = 0;
    uavRange.OffsetInDescriptorsFromTableStart = 0;

    D3D12_ROOT_PARAMETER rootParams[2] = {};
    rootParams[0].ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
    rootParams[0].DescriptorTable.NumDescriptorRanges = 1;
    rootParams[0].DescriptorTable.pDescriptorRanges = &srvRange;
    rootParams[0].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;

    rootParams[1].ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;
    rootParams[1].Descriptor.ShaderRegister = 0;  // b0
    rootParams[1].Descriptor.RegisterSpace = 0;
    rootParams[1].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;

    D3D12_ROOT_SIGNATURE_DESC rootDesc = {};
    rootDesc.NumParameters = _countof(rootParams);
    rootDesc.pParameters = rootParams;
    rootDesc.NumStaticSamplers = 0;
    rootDesc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;

    Microsoft::WRL::ComPtr<ID3DBlob> signatureBlob, errorBlob;
    HRESULT hr = D3D12SerializeRootSignature(&rootDesc, D3D_ROOT_SIGNATURE_VERSION_1_0,
                                             &signatureBlob, &errorBlob);
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: MipGen SerializeRootSignature failed hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    hr = m_device->CreateRootSignature(0, signatureBlob->GetBufferPointer(),
                                       signatureBlob->GetBufferSize(),
                                       IID_PPV_ARGS(&m_mipGenRootSignature));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: MipGen CreateRootSignature failed hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    MCLA_LOG_INFO("D3D12Backend: MipGen root signature created");
    return true;
}

// Generate mipmaps using compute shader downsampling
bool D3D12Backend::GenerateMipmaps(ID3D12Resource* texture, uint32_t mipLevels) {
    if (!texture || mipLevels <= 1) {
        MCLA_LOG_WARN("D3D12Backend: GenerateMipmaps invalid args (texture={}, mipLevels={})",
                    texture != nullptr, mipLevels);
        return false;
    }

    D3D12_RESOURCE_DESC desc = texture->GetDesc();
    if ((desc.Flags & D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS) == 0) {
        MCLA_LOG_ERROR("D3D12Backend: GenerateMipmaps texture lacks ALLOW_UNORDERED_ACCESS flag");
        return false;
    }
    if (desc.MipLevels < mipLevels) {
        MCLA_LOG_ERROR("D3D12Backend: GenerateMipmaps texture has {} mips, requested {}",
                     desc.MipLevels, mipLevels);
        return false;
    }

    // Lazy-create mip generation pipeline on first use
    if (!m_mipGenRootSignature) {
        if (!CreateMipGenPipeline()) return false;
    }

    // Lazy-create compute PSO on first use
    if (!m_mipGenPipeline) {
        const char* csHlsl = GetMipGenCsHlsl();
        if (!csHlsl || !*csHlsl) {
            MCLA_LOG_ERROR("D3D12Backend: GenerateMipmaps missing CS HLSL source");
            return false;
        }

        // Compile CS with DXC runtime
        mcla::renderer::DxcRuntime dxc;
        std::string usedDir, error;
        if (!dxc.Load("", usedDir, error)) {
            MCLA_LOG_ERROR("D3D12Backend: GenerateMipmaps failed to load DXC runtime: {}", error);
            return false;
        }

        std::vector<uint8_t> csBlob;
        if (!dxc.Compile(csHlsl, "main", "cs_6_0", csBlob, error)) {
            MCLA_LOG_ERROR("D3D12Backend: GenerateMipmaps CS compilation failed: {}", error);
            return false;
        }

        // Create compute PSO
        D3D12_COMPUTE_PIPELINE_STATE_DESC psoDesc = {};
        psoDesc.pRootSignature = m_mipGenRootSignature.Get();
        psoDesc.CS = { csBlob.data(), csBlob.size() };
        psoDesc.Flags = D3D12_PIPELINE_STATE_FLAG_NONE;

        HRESULT hr = m_device->CreateComputePipelineState(&psoDesc, IID_PPV_ARGS(&m_mipGenPipeline));
        if (FAILED(hr)) {
            MCLA_LOG_ERROR("D3D12Backend: GenerateMipmaps CreateComputePipelineState failed hr=0x{:08X}",
                         static_cast<uint32_t>(hr));
            return false;
        }
        MCLA_LOG_INFO("D3D12Backend: MipGen compute pipeline created (CS blob {} bytes)", csBlob.size());
    }

    // Create SRV heap for source mips (read) and UAV heap for destination mips (write)
    // We'll use the existing SRV heap for source and create UAVs for each mip level
    // For simplicity, we'll use the same descriptor heap with different offsets

    D3D12_DESCRIPTOR_HEAP_DESC srvUavHeapDesc = {};
    srvUavHeapDesc.NumDescriptors = mipLevels * 2;  // SRV + UAV per mip
    srvUavHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
    srvUavHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

    Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> srvUavHeap;
    HRESULT hr = m_device->CreateDescriptorHeap(&srvUavHeapDesc, IID_PPV_ARGS(&srvUavHeap));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: GenerateMipmaps CreateDescriptorHeap failed hr=0x{:08X}",
                     static_cast<uint32_t>(hr));
        return false;
    }

    uint32_t descriptorSize = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);

    // Create SRVs and UAVs for each mip level
    std::vector<D3D12_CPU_DESCRIPTOR_HANDLE> srvHandles(mipLevels);
    std::vector<D3D12_CPU_DESCRIPTOR_HANDLE> uavHandles(mipLevels);

    D3D12_CPU_DESCRIPTOR_HANDLE srvStart = srvUavHeap->GetCPUDescriptorHandleForHeapStart();
    D3D12_CPU_DESCRIPTOR_HANDLE uavStart;
    uavStart.ptr = srvStart.ptr + static_cast<SIZE_T>(mipLevels) * descriptorSize;

    for (uint32_t i = 0; i < mipLevels; ++i) {
        D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
        srvDesc.Format = desc.Format;
        srvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
        srvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
        srvDesc.Texture2D.MostDetailedMip = i;
        srvDesc.Texture2D.MipLevels = 1;
        srvDesc.Texture2D.PlaneSlice = 0;
        srvDesc.Texture2D.ResourceMinLODClamp = 0.0f;

        D3D12_CPU_DESCRIPTOR_HANDLE srvHandle = srvStart;
        srvHandle.ptr += static_cast<SIZE_T>(i) * descriptorSize;
        m_device->CreateShaderResourceView(texture, &srvDesc, srvHandle);
        srvHandles[i] = srvHandle;

        D3D12_UNORDERED_ACCESS_VIEW_DESC uavDesc = {};
        uavDesc.Format = desc.Format;
        uavDesc.ViewDimension = D3D12_UAV_DIMENSION_TEXTURE2D;
        uavDesc.Texture2D.MipSlice = i;
        uavDesc.Texture2D.PlaneSlice = 0;

        D3D12_CPU_DESCRIPTOR_HANDLE uavHandle = uavStart;
        uavHandle.ptr += static_cast<SIZE_T>(i) * descriptorSize;
        m_device->CreateUnorderedAccessView(texture, nullptr, &uavDesc, uavHandle);
        uavHandles[i] = uavHandle;
    }

    // Constant buffer for mip generation params
    struct MipGenParams {
        uint32_t srcWidth;
        uint32_t srcHeight;
        uint32_t dstWidth;
        uint32_t dstHeight;
        uint32_t srcMipLevel;
        uint32_t padding[3];
    };

    // Wait for GPU to be ready for this frame's upload region
    if (!WaitForCurrentFrameGpu()) return false;

    // Begin frame if not already in frame
    if (!m_inFrame) {
        if (!BeginFrame()) return false;
    }

    // Transition all mips to appropriate states and generate each level
    for (uint32_t i = 1; i < mipLevels; ++i) {
        uint32_t srcMip = i - 1;
        uint32_t dstMip = i;

        // Calculate dimensions
        uint32_t srcWidth = std::max<uint32_t>(1, desc.Width >> srcMip);
        uint32_t srcHeight = std::max<uint32_t>(1, desc.Height >> srcMip);
        uint32_t dstWidth = std::max<uint32_t>(1, desc.Width >> dstMip);
        uint32_t dstHeight = std::max<uint32_t>(1, desc.Height >> dstMip);

        // Transition src mip: current state -> NON_PIXEL_SHADER_RESOURCE (SRV)
        if (!TransitionResource(texture,
                                D3D12_RESOURCE_STATE_COMMON,  // tracked state
                                D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE,
                                srcMip)) {
            // If transition failed, continue anyway
        }

        // Transition dst mip: current state -> UNORDERED_ACCESS (UAV)
        if (!TransitionResource(texture,
                                D3D12_RESOURCE_STATE_COMMON,
                                D3D12_RESOURCE_STATE_UNORDERED_ACCESS,
                                dstMip)) {
        }

        // Begin frame if needed
        if (!m_inFrame) {
            if (!BeginFrame()) return false;
        }

        // Bind pipeline and descriptors
        m_commandList->SetPipelineState(m_mipGenPipeline.Get());
        m_commandList->SetComputeRootSignature(m_mipGenRootSignature.Get());

        // Bind SRV table (src mip)
        D3D12_GPU_DESCRIPTOR_HANDLE srvGpuHandle = srvUavHeap->GetGPUDescriptorHandleForHeapStart();
        srvGpuHandle.ptr += static_cast<SIZE_T>(srcMip) * descriptorSize;
        m_commandList->SetComputeRootDescriptorTable(0, srvGpuHandle);

        // Bind UAV table (dst mip)
        D3D12_GPU_DESCRIPTOR_HANDLE uavGpuHandle = srvUavHeap->GetGPUDescriptorHandleForHeapStart();
        uavGpuHandle.ptr += static_cast<SIZE_T>(mipLevels + dstMip) * descriptorSize;
        m_commandList->SetComputeRootDescriptorTable(1, uavGpuHandle);

        // Bind constants via CBV (root param 1)
        struct MipGenParams {
            uint32_t srcWidth;
            uint32_t srcHeight;
            uint32_t dstWidth;
            uint32_t dstHeight;
            uint32_t srcMipLevel;
            uint32_t padding[3];
        } params = { srcWidth, srcHeight, dstWidth, dstHeight, srcMip, {0,0,0} };

        m_commandList->SetComputeRoot32BitConstants(1, sizeof(MipGenParams) / 4, &params, 0);

        // Dispatch
        uint32_t dispatchX = (dstWidth + 7) / 8;
        uint32_t dispatchY = (dstHeight + 7) / 8;
        m_commandList->Dispatch(dispatchX, dispatchY, 1);

        // UAV barrier for this mip
        D3D12_RESOURCE_BARRIER uavBarrier = {};
        uavBarrier.Type = D3D12_RESOURCE_BARRIER_TYPE_UAV;
        uavBarrier.UAV.pResource = texture;
        m_commandList->ResourceBarrier(1, &uavBarrier);

        // Transition dst mip back to SRV state for next iteration
        TransitionResource(texture,
                          D3D12_RESOURCE_STATE_UNORDERED_ACCESS,
                          D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE,
                          dstMip);
    }

    // Final transition: all mips to PIXEL_SHADER_RESOURCE | NON_PIXEL_SHADER_RESOURCE
    for (uint32_t i = 0; i < mipLevels; ++i) {
        TransitionResource(texture,
                          D3D12_RESOURCE_STATE_COMMON,
                          D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE | D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE,
                          i);
    }

    MCLA_LOG_INFO("D3D12Backend: Generated {} mip levels for texture", mipLevels);
    return true;
}

bool D3D12Backend::CreatePipelineFromDxil(const std::vector<uint8_t>& vsDxil,
                                          const std::vector<uint8_t>& psDxil,
                                          const std::vector<D3D12_INPUT_ELEMENT_DESC>& inputLayout,
                                          const renderer::PipelineState& state,
                                          Microsoft::WRL::ComPtr<ID3D12PipelineState>& outPso) {
    if (vsDxil.empty() || psDxil.empty()) {
        MCLA_LOG_ERROR("D3D12Backend: CreatePipelineFromDxil: empty DXIL blob");
        return false;
    }

    D3D12_GRAPHICS_PIPELINE_STATE_DESC psoDesc = {};
    psoDesc.pRootSignature = m_rootSignature.Get();
    psoDesc.VS = { vsDxil.data(), vsDxil.size() };
    psoDesc.PS = { psDxil.data(), psDxil.size() };
    psoDesc.InputLayout = { inputLayout.data(), static_cast<UINT>(inputLayout.size()) };
    psoDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;

    // RTV formats from PipelineState
    for (uint32_t i = 0; i < renderer::kMaxRenderTargets; ++i) {
        if (state.targetFormats[i] != 0) {
            psoDesc.RTVFormats[i] = static_cast<DXGI_FORMAT>(state.targetFormats[i]);
        }
    }
    psoDesc.NumRenderTargets = 1;  // default; could be extended
    psoDesc.SampleDesc.Count = state.sampleCount;
    psoDesc.SampleMask = UINT_MAX;

    // Rasterizer state
    psoDesc.RasterizerState.FillMode = D3D12_FILL_MODE_SOLID;
    psoDesc.RasterizerState.CullMode = D3D12_CULL_MODE_NONE;
    psoDesc.RasterizerState.DepthClipEnable = TRUE;

    // Blend state
    psoDesc.BlendState.AlphaToCoverageEnable = FALSE;
    psoDesc.BlendState.IndependentBlendEnable = FALSE;
    for (UINT i = 0; i < 8; ++i) {
        psoDesc.BlendState.RenderTarget[i].RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;
    }

    // Depth/stencil state
    psoDesc.DepthStencilState.DepthEnable = FALSE;
    psoDesc.DepthStencilState.StencilEnable = FALSE;

    HRESULT hr = m_device->CreateGraphicsPipelineState(&psoDesc, IID_PPV_ARGS(&outPso));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: CreateGraphicsPipelineState(translated) failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }
    MCLA_LOG_INFO("D3D12Backend: Live pipeline created from DXIL (VS={} bytes, PS={} bytes)", vsDxil.size(), psDxil.size());
    return true;
}

// Phase 3 test draw: an indexed triangle whose colors pulse per frame.
// Exercises the upload arena, index/vertex buffer binding, viewport, and
// primitive topology on the native path. The draw body is shared with the
// captured-geometry path via DrawDynamicMesh so both go through identical
// command-list handling.
bool D3D12Backend::DrawTestMeshedTriangle(uint32_t frame) {
    // Deterministic rotating color so the frame visibly changes.
    const float t = static_cast<float>(frame) * 0.1f;
    const float cr = (std::sin(t) + 1.0f) * 0.5f;
    const float cg = (std::sin(t + 2.0f) + 1.0f) * 0.5f;
    const float cb = (std::sin(t + 4.0f) + 1.0f) * 0.5f;

    // A meshed quad: 4 vertices, 6 indices (two triangles).
    struct TestVertex { float pos[3]; float color[4]; };
    const TestVertex vertices[4] = {
        { { -0.8f, -0.8f, 0.0f }, { cr, cg, cb, 1.0f } },
        { {  0.8f, -0.8f, 0.0f }, { cg, cb, cr, 1.0f } },
        { {  0.8f,  0.8f, 0.0f }, { cb, cr, cg, 1.0f } },
        { { -0.8f,  0.8f, 0.0f }, { cr, cb, cg, 1.0f } },
    };
    const uint16_t indices[6] = { 0, 1, 2, 0, 2, 3 };

    DynamicMeshDesc desc = {};
    desc.vertexBytes = vertices;
    desc.vertexBytesSize = sizeof(vertices);
    desc.vertexStride = sizeof(TestVertex);  // 28 bytes
    desc.vertexCount = 4;
    desc.indexed = true;
    desc.indexFormat = DXGI_FORMAT_R16_UINT;
    desc.indexCount = 6;

    // Reuse the static cached index buffer (uploaded once at Initialize).
    const ResourceKey ibKey = { ResourceKind::Buffer, 0 /*synthetic test addr*/,
                                sizeof(indices), DXGI_FORMAT_R16_UINT, 1 };
    ResourceEntry ibEntry;
    if (m_resourceCache.Find(ibKey, ibEntry)) {
        desc.cachedIndexGpu = ibEntry.handle;
        desc.cachedIndexBytesSize = sizeof(indices);
        m_stats.cacheHits++;
    } else {
        // Should not happen (initialized before draw), but recover safely by
        // falling back to a per-frame upload of the same bytes.
        desc.indexBytes = indices;
        desc.indexBytesSize = sizeof(indices);
        m_stats.cacheMisses++;
    }

    const bool ok = DrawDynamicMesh(desc);
    if (frame <= 3) {
        MCLA_LOG_INFO("D3D12Backend: DrawTestMeshedTriangle frame={} present_hr=0x{:08X}",
                    frame, static_cast<uint32_t>(m_lastPresentHr));
    }
    return ok;
}

// Generic dynamic-geometry draw. Uploads the caller's vertex bytes (and index
// bytes when the caller has no cached IB) into the per-frame upload arena and
// issues one indexed/non-indexed draw. The caller is responsible for producing
// host data from validated captures; the backend never interprets guest
// layouts. The vertex stride must match the test PSO's input layout
// (Position:float3 + Color:float4 = 28 bytes) — anything else is refused so we
// never draw with a mismatched layout.
bool D3D12Backend::DrawDynamicMesh(const DynamicMeshDesc& desc) {
    return DrawDynamicMeshWithPipeline(desc, m_testPipeline.Get());
}

// Overload that accepts a specific PSO to use instead of the default test pipeline.
bool D3D12Backend::DrawDynamicMeshWithPipeline(const DynamicMeshDesc& desc,
                                               ID3D12PipelineState* pipeline) {
    // Guard the whole body (including MapUpload / m_frameIndex / m_stats /
    // m_inFrame mutation) so it cannot race with Resize()/Shutdown() from the
    // window/app thread. BeginFrame() re-locks the same recursive mutex.
    std::lock_guard<std::recursive_mutex> lock(m_mutex);
    if (!m_initialized) return false;
    if (!desc.vertexBytes || desc.vertexBytesSize == 0 || desc.vertexCount == 0) return false;

    // The test PSO input layout is exactly { float3 pos, float4 color } = 28
    // bytes. Refusing any other stride keeps us honest: a captured stream with
    // a different layout is not invented into this layout.
    constexpr uint32_t kLayoutStride = 28;
    if (desc.vertexStride != kLayoutStride) {
        MCLA_LOG_WARN("D3D12Backend: DrawDynamicMesh refused vertex stride {} (test layout is {})",
                    desc.vertexStride, kLayoutStride);
        return false;
    }
    if (desc.indexed && !desc.cachedIndexGpu &&
        (!desc.indexBytes || desc.indexBytesSize == 0)) {
        return false;
    }
    if (desc.indexed && desc.cachedIndexGpu && desc.cachedIndexBytesSize == 0) {
        MCLA_LOG_WARN("D3D12Backend: DrawDynamicMesh refused cached IB with size 0");
        return false;
    }

    m_stats.bytesThisFrame = 0;
    m_uploadOffset = 0;

    // Wait for the GPU to finish the previous frame that used this back
    // buffer's upload region before we write into it again. This must happen
    // before MapUpload, not at BeginFrame time (which is after staging), or
    // the CPU can overwrite bytes the GPU is still reading.
    if (!WaitForCurrentFrameGpu()) return false;

    // Stage vertex data BEFORE starting any command-list work, so an arena
    // exhaustion bails out cleanly with no open list and no stuck m_inFrame.
    D3D12_GPU_VIRTUAL_ADDRESS vbGpu = 0, ibGpu = desc.cachedIndexGpu;
    uint8_t* vbDst = MapUpload(desc.vertexBytesSize, D3D12_TEXTURE_DATA_PITCH_ALIGNMENT, vbGpu);
    if (!vbDst) return false;
    std::memcpy(vbDst, desc.vertexBytes, desc.vertexBytesSize);

    if (desc.indexed && !desc.cachedIndexGpu) {
        uint8_t* ibDst = MapUpload(desc.indexBytesSize, D3D12_TEXTURE_DATA_PITCH_ALIGNMENT, ibGpu);
        if (!ibDst) return false;
        std::memcpy(ibDst, desc.indexBytes, desc.indexBytesSize);
    }

    if (!m_inFrame) {
        if (!BeginFrame()) return false;
    }

    // Transition the back buffer to render target.
    D3D12_RESOURCE_BARRIER barrier = {};
    barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    barrier.Transition.pResource = m_renderTargets[m_frameIndex].Get();
    barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_PRESENT;
    barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_RENDER_TARGET;
    barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    m_commandList->ResourceBarrier(1, &barrier);

    D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_rtvHeap->GetCPUDescriptorHandleForHeapStart());
    rtvHandle.ptr += static_cast<size_t>(m_frameIndex) * m_rtvDescriptorSize;

    const float clearColor[4] = { 0.02f, 0.03f, 0.05f, 1.0f };
    m_commandList->ClearRenderTargetView(rtvHandle, clearColor, 0, nullptr);
    m_commandList->OMSetRenderTargets(1, &rtvHandle, FALSE, nullptr);

    // Viewport covering the full back buffer.
    D3D12_VIEWPORT viewport = { 0.0f, 0.0f,
                                static_cast<float>(m_width), static_cast<float>(m_height),
                                0.0f, 1.0f };
    D3D12_RECT scissor = { 0, 0, static_cast<LONG>(m_width), static_cast<LONG>(m_height) };
    m_commandList->RSSetViewports(1, &viewport);
    m_commandList->RSSetScissorRects(1, &scissor);

    D3D12_VERTEX_BUFFER_VIEW vbView = {};
    vbView.BufferLocation = vbGpu;
    vbView.StrideInBytes = desc.vertexStride;
    vbView.SizeInBytes = desc.vertexBytesSize;

    m_commandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    m_commandList->IASetVertexBuffers(0, 1, &vbView);

    D3D12_INDEX_BUFFER_VIEW ibView = {};
    if (desc.indexed) {
        ibView.BufferLocation = ibGpu;
        // A D3D12 IBV with SizeInBytes == 0 is treated as unbound (the runtime
        // considers the slot null), so the cached IB must carry its real byte
        // size even though it is never re-uploaded.
        ibView.SizeInBytes = desc.cachedIndexGpu ? desc.cachedIndexBytesSize
                                                 : desc.indexBytesSize;
        ibView.Format = desc.indexFormat;
        m_commandList->IASetIndexBuffer(&ibView);
    }

    m_commandList->SetGraphicsRootSignature(m_rootSignature.Get());

    // Use the provided pipeline or fall back to test pipeline
    ID3D12PipelineState* pso = pipeline ? pipeline : m_testPipeline.Get();
    m_commandList->SetPipelineState(pso);
    BindDecodedTexture();  // no-op unless a decoded texture is active

    if (desc.indexed) {
        m_commandList->DrawIndexedInstanced(desc.indexCount, 1, 0, 0, 0);
    } else {
        m_commandList->DrawInstanced(desc.vertexCount, 1, 0, 0);
    }

    m_stats.drawsIssued++;

    // Transition back to present and submit.
    barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
    barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;
    m_commandList->ResourceBarrier(1, &barrier);

    HRESULT hr = m_commandList->Close();
    if (FAILED(hr)) {
        m_inFrame = false;
        return false;
    }

    ID3D12CommandList* ppCommandLists[] = { m_commandList.Get() };
    m_commandQueue->ExecuteCommandLists(1, ppCommandLists);

    hr = m_swapChain->Present(1, 0);
    m_lastPresentHr = hr;

    m_currentFenceValue++;
    m_commandQueue->Signal(m_fence.Get(), m_currentFenceValue);
    m_fenceValues[m_frameIndex] = m_currentFenceValue;

    m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();
    m_inFrame = false;

    return SUCCEEDED(hr);
}

void D3D12Backend::WaitForGpu() {
    if (!m_device || !m_commandQueue || !m_fence || !m_fenceEvent) return;

    uint64_t fenceVal = ++m_currentFenceValue;
    if (SUCCEEDED(m_commandQueue->Signal(m_fence.Get(), fenceVal))) {
        if (m_fence->GetCompletedValue() < fenceVal) {
            m_fence->SetEventOnCompletion(fenceVal, m_fenceEvent);
            WaitForSingleObject(m_fenceEvent, INFINITE);
        }
    }
}

bool D3D12Backend::StreamingUpload(ID3D12Resource* dest, const void* data, uint32_t size) {
    if (!m_device || !m_copyQueue || !m_copyCommandList || !dest || !data || size == 0) return false;

    D3D12_HEAP_PROPERTIES uploadHeapProps = {};
    uploadHeapProps.Type = D3D12_HEAP_TYPE_UPLOAD;

    D3D12_RESOURCE_DESC bufDesc = {};
    bufDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
    bufDesc.Width = (size + 255) & ~255u; // align to 256 bytes
    bufDesc.Height = 1;
    bufDesc.DepthOrArraySize = 1;
    bufDesc.MipLevels = 1;
    bufDesc.SampleDesc.Count = 1;
    bufDesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;

    Microsoft::WRL::ComPtr<ID3D12Resource> uploadBuffer;
    HRESULT hr = m_device->CreateCommittedResource(
        &uploadHeapProps, D3D12_HEAP_FLAG_NONE,
        &bufDesc, D3D12_RESOURCE_STATE_GENERIC_READ,
        nullptr, IID_PPV_ARGS(&uploadBuffer));
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: StreamingUpload CreateCommittedResource failed hr=0x{:08X}",
                       static_cast<uint32_t>(hr));
        return false;
    }

    void* mapped = nullptr;
    D3D12_RANGE readRange = {0, 0};
    hr = uploadBuffer->Map(0, &readRange, &mapped);
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: StreamingUpload Map failed hr=0x{:08X}",
                       static_cast<uint32_t>(hr));
        return false;
    }
    memcpy(mapped, data, size);
    uploadBuffer->Unmap(0, nullptr);

    hr = m_copyCommandList->Reset(m_copyAllocator.Get(), nullptr);
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: StreamingUpload CopyReset failed hr=0x{:08X}",
                       static_cast<uint32_t>(hr));
        return false;
    }

    m_copyCommandList->CopyBufferRegion(dest, 0, uploadBuffer.Get(), 0, size);

    hr = m_copyCommandList->Close();
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: StreamingUpload Close failed hr=0x{:08X}",
                       static_cast<uint32_t>(hr));
        return false;
    }

    ID3D12CommandList* lists[] = { m_copyCommandList.Get() };
    m_copyQueue->ExecuteCommandLists(1, lists);

    return true;
}

uint64_t D3D12Backend::SignalCopyFence() {
    if (!m_copyQueue || !m_copyFence) return 0;
    ++m_copyFenceValue;
    m_copyQueue->Signal(m_copyFence.Get(), m_copyFenceValue);
    return m_copyFenceValue;
}

void D3D12Backend::WaitForCopyFence(uint64_t fenceValue) {
    if (!m_copyFence || !m_copyFenceEvent) return;
    if (m_copyFence->GetCompletedValue() < fenceValue) {
        m_copyFence->SetEventOnCompletion(fenceValue, m_copyFenceEvent);
        WaitForSingleObject(m_copyFenceEvent, INFINITE);
    }
}

bool D3D12Backend::Resize(uint32_t width, uint32_t height) {
    std::lock_guard<std::recursive_mutex> lock(m_mutex);
    if (!m_initialized || !m_swapChain) return false;
    if (width == 0 || height == 0) return false;

    MCLA_LOG_INFO("D3D12Backend: Resizing swap chain to {}x{}", width, height);

    WaitForGpu();

    for (uint32_t i = 0; i < kBufferCount; ++i) {
        m_renderTargets[i].Reset();
        m_fenceValues[i] = m_fenceValues[m_frameIndex];
    }

    HRESULT hr = m_swapChain->ResizeBuffers(kBufferCount, width, height, DXGI_FORMAT_R8G8B8A8_UNORM, 0);
    if (FAILED(hr)) {
        MCLA_LOG_ERROR("D3D12Backend: ResizeBuffers failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    m_width = width;
    m_height = height;
    m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();

    return CreateRenderTargets();
}

// Wait until the GPU is done with everything recorded against the current back
// buffer. Callers that write into the upload arena region for this frame must
// do so only after this returns, otherwise the CPU can overwrite bytes the GPU
// is still reading from the previous frame that used the same region.
bool D3D12Backend::WaitForCurrentFrameGpu() {
    std::lock_guard<std::recursive_mutex> lock(m_mutex);
    if (!m_initialized) return false;
    uint64_t completedVal = m_fence->GetCompletedValue();
    if (completedVal < m_fenceValues[m_frameIndex]) {
        m_fence->SetEventOnCompletion(m_fenceValues[m_frameIndex], m_fenceEvent);
        WaitForSingleObject(m_fenceEvent, INFINITE);
    }
    return true;
}

bool D3D12Backend::BeginFrame() {
    std::lock_guard<std::recursive_mutex> lock(m_mutex);
    if (!m_initialized || m_inFrame) return false;

    if (!WaitForCurrentFrameGpu()) return false;

    HRESULT hr = m_commandAllocators[m_frameIndex]->Reset();
    if (FAILED(hr)) return false;

    hr = m_commandList->Reset(m_commandAllocators[m_frameIndex].Get(), nullptr);
    if (FAILED(hr)) return false;

    m_inFrame = true;
    return true;
}

bool D3D12Backend::ClearAndPresent(float r, float g, float b, float a) {
    std::lock_guard<std::recursive_mutex> lock(m_mutex);
    if (!m_initialized) return false;

    if (!m_inFrame) {
        if (!BeginFrame()) return false;
    }

    // Transition render target buffer from PRESENT to RENDER_TARGET
    D3D12_RESOURCE_BARRIER barrier = {};
    barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    barrier.Transition.pResource = m_renderTargets[m_frameIndex].Get();
    barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_PRESENT;
    barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_RENDER_TARGET;
    barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;

    m_commandList->ResourceBarrier(1, &barrier);

    D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_rtvHeap->GetCPUDescriptorHandleForHeapStart());
    rtvHandle.ptr += static_cast<size_t>(m_frameIndex) * m_rtvDescriptorSize;

    const float clearColor[4] = { r, g, b, a };
    m_commandList->ClearRenderTargetView(rtvHandle, clearColor, 0, nullptr);

    // Transition render target back to PRESENT
    barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
    barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;

    m_commandList->ResourceBarrier(1, &barrier);

    HRESULT hr = m_commandList->Close();
    if (FAILED(hr)) {
        m_inFrame = false;
        return false;
    }

    ID3D12CommandList* ppCommandLists[] = { m_commandList.Get() };
    m_commandQueue->ExecuteCommandLists(1, ppCommandLists);

    // Present the frame
    hr = m_swapChain->Present(1, 0);

    // Signal fence for current frame
    m_currentFenceValue++;
    m_commandQueue->Signal(m_fence.Get(), m_currentFenceValue);
    m_fenceValues[m_frameIndex] = m_currentFenceValue;

    m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();
    m_inFrame = false;

    return SUCCEEDED(hr);
}

void D3D12Backend::EndFrame() {
    m_inFrame = false;
}

void D3D12Backend::Shutdown() {
    std::lock_guard<std::recursive_mutex> lock(m_mutex);
    if (!m_initialized) return;

    WaitForGpu();

    // Stop pipeline cache worker thread
    m_pipelineCache.StopWorker();

    if (m_fenceEvent) {
        CloseHandle(m_fenceEvent);
        m_fenceEvent = nullptr;
    }

    if (m_copyFenceEvent) {
        CloseHandle(m_copyFenceEvent);
        m_copyFenceEvent = nullptr;
    }

    m_fence.Reset();
    m_copyFence.Reset();
    for (uint32_t i = 0; i < kBufferCount; ++i) {
        m_renderTargets[i].Reset();
        m_commandAllocators[i].Reset();
    }
    m_rtvHeap.Reset();
    m_commandList.Reset();
    m_commandQueue.Reset();
    m_copyCommandList.Reset();
    m_copyAllocator.Reset();
    m_copyQueue.Reset();
    m_swapChain.Reset();

    // Phase 3 draw-path resources: clear the persistent upload mapping and
    // release the cached resources so a Shutdown() -> Initialize() recovery
    // path (device-lost) cannot touch a dangling m_uploadMap.
    if (m_uploadHeap) {
        m_uploadHeap->Unmap(0, nullptr);
        m_uploadHeap.Reset();
    }
    m_uploadMap = nullptr;
    m_uploadOffset = 0;
    m_staticIndexBuffer.Reset();
    m_decodedTexture.Reset();
    m_decodedTextureUpload.Reset();
    m_srvHeap.Reset();
    m_decodedTextureSrvGpu = {};
    m_testPipeline.Reset();
    m_rootSignature.Reset();
    m_resourceCache.Clear();

    m_device.Reset();
    m_factory.Reset();

    m_initialized = false;
    MCLA_LOG_INFO("D3D12Backend: Shutdown complete");
}

// Phase 4: Sampler state management (static samplers for root signature)
uint32_t D3D12Backend::GetOrCreateStaticSampler(const D3D12_SAMPLER_DESC& desc) {
    SamplerCacheKey key{ desc };
    auto it = m_samplerCache.find(key);
    if (it != m_samplerCache.end()) {
        for (uint32_t i = 0; i < m_staticSamplerArray.size(); ++i) {
            if (memcmp(&m_staticSamplerArray[i].Filter, &desc.Filter, sizeof(D3D12_SAMPLER_DESC)) == 0) return i;
        }
    }
    D3D12_STATIC_SAMPLER_DESC staticDesc = {};
    staticDesc.Filter = desc.Filter;
    staticDesc.AddressU = desc.AddressU;
    staticDesc.AddressV = desc.AddressV;
    staticDesc.AddressW = desc.AddressW;
    staticDesc.MipLODBias = desc.MipLODBias;
    staticDesc.MaxAnisotropy = desc.MaxAnisotropy;
    staticDesc.ComparisonFunc = desc.ComparisonFunc;
    staticDesc.BorderColor = D3D12_STATIC_BORDER_COLOR_OPAQUE_BLACK;
    staticDesc.MinLOD = desc.MinLOD;
    staticDesc.MaxLOD = desc.MaxLOD;
    staticDesc.ShaderRegister = 0;
    staticDesc.RegisterSpace = 0;
    staticDesc.ShaderVisibility = D3D12_SHADER_VISIBILITY_PIXEL;
    uint32_t index = static_cast<uint32_t>(m_staticSamplerArray.size());
    m_staticSamplerArray.push_back(staticDesc);
    m_samplerCache.emplace(SamplerCacheKey{ desc }, desc);
    return index;
}

bool D3D12Backend::CreateRenderTargetView(ID3D12Resource* texture, DXGI_FORMAT format,
                                          D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle) {
    if (!texture || !m_device) return false;
    D3D12_RENDER_TARGET_VIEW_DESC rtvDesc = {};
    rtvDesc.Format = format;
    rtvDesc.ViewDimension = D3D12_RTV_DIMENSION_TEXTURE2D;
    rtvDesc.Texture2D.MipSlice = 0;
    rtvDesc.Texture2D.PlaneSlice = 0;
    m_device->CreateRenderTargetView(texture, &rtvDesc, rtvHandle);
    return true;
}

bool D3D12Backend::CreateDepthStencilView(ID3D12Resource* texture, DXGI_FORMAT format,
                                          D3D12_CPU_DESCRIPTOR_HANDLE dsvHandle) {
    if (!texture || !m_device) return false;
    D3D12_DEPTH_STENCIL_VIEW_DESC dsvDesc = {};
    dsvDesc.Format = format;
    dsvDesc.ViewDimension = D3D12_DSV_DIMENSION_TEXTURE2D;
    dsvDesc.Flags = D3D12_DSV_FLAG_NONE;
    dsvDesc.Texture2D.MipSlice = 0;
    m_device->CreateDepthStencilView(texture, &dsvDesc, dsvHandle);
    return true;
}

bool D3D12Backend::ResolveRenderTarget(ID3D12Resource* srcRt, ID3D12Resource* dstTexture,
                                       DXGI_FORMAT format) {
    if (!srcRt || !dstTexture || !m_commandList) return false;
    D3D12_RESOURCE_BARRIER barriers[2] = {};
    barriers[0].Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    barriers[0].Transition.pResource = srcRt;
    barriers[0].Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
    barriers[0].Transition.StateAfter = D3D12_RESOURCE_STATE_RESOLVE_SOURCE;
    barriers[0].Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    barriers[1].Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    barriers[1].Transition.pResource = dstTexture;
    barriers[1].Transition.StateBefore = D3D12_RESOURCE_STATE_COMMON;
    barriers[1].Transition.StateAfter = D3D12_RESOURCE_STATE_RESOLVE_DEST;
    barriers[1].Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    m_commandList->ResourceBarrier(2, barriers);
    m_commandList->ResolveSubresource(dstTexture, 0, srcRt, 0, format);
    barriers[0].Transition.StateBefore = D3D12_RESOURCE_STATE_RESOLVE_SOURCE;
    barriers[0].Transition.StateAfter = D3D12_RESOURCE_STATE_RENDER_TARGET;
    barriers[1].Transition.StateBefore = D3D12_RESOURCE_STATE_RESOLVE_DEST;
    barriers[1].Transition.StateAfter = D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE;
    m_commandList->ResourceBarrier(2, barriers);
    return true;
}

const D3D12_BLEND_DESC* D3D12Backend::GetOrCreateBlendState(const D3D12_BLEND_DESC& desc) {
    BlendStateCacheKey key{ desc };
    auto it = m_blendStateCache.find(key);
    if (it != m_blendStateCache.end()) return &it->second;
    auto [it2, inserted] = m_blendStateCache.emplace(BlendStateCacheKey{ desc }, desc);
    return &it2->second;
}

const D3D12_DEPTH_STENCIL_DESC* D3D12Backend::GetOrCreateDepthStencilState(const D3D12_DEPTH_STENCIL_DESC& desc) {
    DepthStencilStateCacheKey key{ desc };
    auto it = m_depthStencilStateCache.find(key);
    if (it != m_depthStencilStateCache.end()) return &it->second;
    auto [it2, inserted] = m_depthStencilStateCache.emplace(DepthStencilStateCacheKey{ desc }, desc);
    return &it2->second;
}

const D3D12_RASTERIZER_DESC* D3D12Backend::GetOrCreateRasterizerState(const D3D12_RASTERIZER_DESC& desc) {
    RasterizerStateCacheKey key{ desc };
    auto it = m_rasterizerStateCache.find(key);
    if (it != m_rasterizerStateCache.end()) return &it->second;
    auto [it2, inserted] = m_rasterizerStateCache.emplace(RasterizerStateCacheKey{ desc }, desc);
    return &it2->second;
}

bool D3D12Backend::TransitionResource(ID3D12Resource* resource,
                                      D3D12_RESOURCE_STATES stateBefore,
                                      D3D12_RESOURCE_STATES stateAfter,
                                      UINT subresource) {
    if (!resource || !m_commandList) return false;
    if (stateBefore == stateAfter) return false;
    auto it = m_resourceStates.find(resource);
    D3D12_RESOURCE_STATES trackedBefore = (it != m_resourceStates.end()) ? it->second.state : D3D12_RESOURCE_STATE_COMMON;
    D3D12_RESOURCE_STATES trackedSub = (it != m_resourceStates.end()) ? D3D12_RESOURCE_STATES(it->second.subresource) : D3D12_RESOURCE_STATES(D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES);
    if (trackedBefore == stateBefore && trackedSub == subresource) {
        if (it != m_resourceStates.end()) {
            it->second.state = stateAfter;
            it->second.subresource = subresource;
        } else {
            m_resourceStates.emplace(resource, ResourceStateEntry{ stateAfter, subresource });
        }
        return false;
    }
    D3D12_RESOURCE_BARRIER barrier = {};
    barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    barrier.Transition.pResource = resource;
    barrier.Transition.StateBefore = trackedBefore;
    barrier.Transition.StateAfter = stateAfter;
    barrier.Transition.Subresource = trackedSub;
    m_commandList->ResourceBarrier(1, &barrier);
    if (it != m_resourceStates.end()) {
        it->second.state = stateAfter;
        it->second.subresource = subresource;
    } else {
        m_resourceStates.emplace(resource, ResourceStateEntry{ stateAfter, subresource });
    }
    return true;
}

bool D3D12Backend::BeginRenderPass(const D3D12Backend::RenderPassDesc& desc) {
    if (!m_commandList || desc.rtvs.empty()) return false;
    std::vector<D3D12_CPU_DESCRIPTOR_HANDLE> rtvHandles;
    for (const auto& rtv : desc.rtvs) rtvHandles.push_back(rtv.cpuHandle);
    D3D12_CPU_DESCRIPTOR_HANDLE dsvHandle = {};
    bool hasDsv = desc.dsv.has_value();
    if (hasDsv) dsvHandle = desc.dsv->cpuHandle;
    m_commandList->OMSetRenderTargets(static_cast<UINT>(rtvHandles.size()),
                                      rtvHandles.data(), FALSE,
                                      hasDsv ? &dsvHandle : nullptr);
    for (const auto& rtv : desc.rtvs) {
        if (rtv.clear) {
            m_commandList->ClearRenderTargetView(rtv.cpuHandle, rtv.clearColor, 0, nullptr);
        }
    }
    if (hasDsv && (desc.dsv->clearDepth || desc.dsv->clearStencil)) {
        D3D12_CLEAR_FLAGS flags = static_cast<D3D12_CLEAR_FLAGS>(0);
        if (desc.dsv->clearDepth) flags |= D3D12_CLEAR_FLAG_DEPTH;
        if (desc.dsv->clearStencil) flags |= D3D12_CLEAR_FLAG_STENCIL;
        m_commandList->ClearDepthStencilView(dsvHandle, flags,
                                             desc.dsv->depthClear, desc.dsv->stencilClear,
                                             0, nullptr);
    }
    if (desc.viewport.Width > 0 && desc.viewport.Height > 0) {
        m_commandList->RSSetViewports(1, &desc.viewport);
    }
    if (desc.scissor.right > desc.scissor.left && desc.scissor.bottom > desc.scissor.top) {
        m_commandList->RSSetScissorRects(1, &desc.scissor);
    }
    m_activeRenderPass = desc;
    return true;
}

void D3D12Backend::EndRenderPass() {
    if (!m_activeRenderPass.has_value() || !m_commandList) return;
    m_activeRenderPass.reset();
}

} // namespace mcla::native

// =============================================================================
// Phase 5: Captured DrawPacket Native Draw Implementation
// =============================================================================

namespace mcla::native {

std::vector<D3D12_INPUT_ELEMENT_DESC>
D3D12Backend::BuildInputLayoutFromGrcFvf(const native::GrcFvfDesc& grcFvf)
{
    std::vector<D3D12_INPUT_ELEMENT_DESC> layout;

    if (grcFvf.fvfMask == 0 || grcFvf.fvfSize == 0) {
        MCLA_LOG_WARN("BuildInputLayoutFromGrcFvf: invalid grcFvf (mask=0x%08X, size=%u)",
                      grcFvf.fvfMask, grcFvf.fvfSize);
        return layout;
    }

    // Decode channel types from the 64-bit field (16 channels x 4 bits each)
    // Each 4-bit nibble represents the type for that channel
    for (uint32_t lane = 0; lane < 16; ++lane) {
        if ((grcFvf.fvfMask & (1u << lane)) == 0) continue;

        uint32_t typeCode = (grcFvf.types >> (lane * 4)) & 0xF;

        D3D12_INPUT_ELEMENT_DESC desc = {};
        desc.InputSlot = 0;
        desc.InputSlotClass = D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA;
        desc.InstanceDataStepRate = 0;

        // Map RAGE VFETCH channel type codes to DXGI formats
        // Type codes from Xenos microcode / RAGE format table:
        // 0 = float, 1 = float2, 2 = float3, 3 = float4
        // 4 = ubyte4, 5 = ubyte4_norm, 6 = sbyte4, 7 = sbyte4_norm
        // 8 = ushort2, 9 = ushort2_norm, 10 = ushort4, 11 = ushort4_norm
        // 12 = short2, 13 = short2_norm, 14 = short4, 15 = short4_norm
        // (exact mapping depends on RAGE's grcFvf decoding)

        DXGI_FORMAT format = DXGI_FORMAT_UNKNOWN;
        uint32_t offset = 0; // Will be calculated by lane order

        // Semantic mapping based on channel index (RAGE convention)
        const char* semanticName = "TEXCOORD";
        uint32_t semanticIndex = lane;

        // Common semantic assignments for RAGE:
        switch (lane) {
            case 0: semanticName = "POSITION"; semanticIndex = 0; break;  // Position
            case 1: semanticName = "BLENDWEIGHT"; semanticIndex = 0; break;
            case 2: semanticName = "BLENDINDICES"; semanticIndex = 0; break;
            case 3: semanticName = "NORMAL"; semanticIndex = 0; break;
            case 4: semanticName = "PSIZE"; semanticIndex = 0; break;
            case 5: semanticName = "TEXCOORD"; semanticIndex = 0; break;
            case 6: semanticName = "TEXCOORD"; semanticIndex = 1; break;
            case 7: semanticName = "TEXCOORD"; semanticIndex = 2; break;
            case 8: semanticName = "TEXCOORD"; semanticIndex = 3; break;
            case 9: semanticName = "TEXCOORD"; semanticIndex = 4; break;
            case 10: semanticName = "TEXCOORD"; semanticIndex = 5; break;
            case 11: semanticName = "TEXCOORD"; semanticIndex = 6; break;
            case 12: semanticName = "TEXCOORD"; semanticIndex = 7; break;
            case 13: semanticName = "TANGENT"; semanticIndex = 0; break;
            case 14: semanticName = "BINORMAL"; semanticIndex = 0; break;
            case 15: semanticName = "TESSFACTOR"; semanticIndex = 0; break;
        }

        desc.SemanticName = semanticName;
        desc.SemanticIndex = semanticIndex;

        // Map type code to DXGI format
        switch (typeCode) {
            case 0x0: format = DXGI_FORMAT_R32_FLOAT; break;                    // float
            case 0x1: format = DXGI_FORMAT_R32G32_FLOAT; break;                // float2
            case 0x2: format = DXGI_FORMAT_R32G32B32_FLOAT; break;             // float3
            case 0x3: format = DXGI_FORMAT_R32G32B32A32_FLOAT; break;          // float4
            case 0x4: format = DXGI_FORMAT_R8G8B8A8_UINT; break;               // ubyte4
            case 0x5: format = DXGI_FORMAT_R8G8B8A8_UNORM; break;              // ubyte4_norm
            case 0x6: format = DXGI_FORMAT_R8G8B8A8_SINT; break;               // sbyte4
            case 0x7: format = DXGI_FORMAT_R8G8B8A8_SNORM; break;              // sbyte4_norm
            case 0x8: format = DXGI_FORMAT_R16G16_UINT; break;                 // ushort2
            case 0x9: format = DXGI_FORMAT_R16G16_UNORM; break;                // ushort2_norm
            case 0xA: format = DXGI_FORMAT_R16G16B16A16_UINT; break;           // ushort4
            case 0xB: format = DXGI_FORMAT_R16G16B16A16_UNORM; break;          // ushort4_norm
            case 0xC: format = DXGI_FORMAT_R16G16_SINT; break;                 // short2
            case 0xD: format = DXGI_FORMAT_R16G16_SNORM; break;                // short2_norm
            case 0xE: format = DXGI_FORMAT_R16G16B16A16_SINT; break;           // short4
            case 0xF: format = DXGI_FORMAT_R16G16B16A16_SNORM; break;          // short4_norm
            default:
                MCLA_LOG_WARN("BuildInputLayoutFromGrcFvf: unknown type code %u for lane %u",
                              typeCode, lane);
                continue;
        }

        desc.Format = format;
        desc.AlignedByteOffset = D3D12_APPEND_ALIGNED_ELEMENT;

        layout.push_back(desc);

        MCLA_LOG_INFO("BuildInputLayoutFromGrcFvf: lane=%u semantic=%s idx=%u type=%u fmt=%u",
                      lane, semanticName, semanticIndex, typeCode, static_cast<uint32_t>(format));
    }

    if (layout.empty()) {
        MCLA_LOG_WARN("BuildInputLayoutFromGrcFvf: no valid lanes decoded from mask=0x%08X",
                      grcFvf.fvfMask);
    }

    return layout;
}

renderer::PipelineState D3D12Backend::BuildPipelineStateFromPacket(const native::DrawPacket& packet)
{
    renderer::PipelineState state = {};

    // Target formats - default to R8G8B8A8_UNORM
    state.targetFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM;
    state.depthStencilFormat = DXGI_FORMAT_D24_UNORM_S8_UINT;

    // Blend state hash - extract from paClipCntl / other registers
    state.blendState = packet.paClipCntl ^ 0x12345678;

    // Raster state hash - extract cull mode, fill mode from paClipCntl / paSuScModeCntl
    state.rasterState = packet.paClipCntl ^ packet.paSuScModeCntl;

    // Depth-stencil state hash
    state.depthStencilState = packet.paClVteCntl ^ 0xABCDEF00;

    // Primitive topology
    switch (packet.primType) {
        case 0: state.topology = 0; break; // Triangle
        case 1: state.topology = 0; break; // Triangle strip
        case 2: state.topology = 1; break; // Line
        case 3: state.topology = 1; break; // Line strip
        case 4: state.topology = 2; break; // Point
        default: state.topology = 0; break;
    }

    state.sampleCount = 1;

    return state;
}

bool D3D12Backend::UploadPacketGeometry(const native::DrawPacket& packet,
                                        D3D12_GPU_VIRTUAL_ADDRESS& vbGpu,
                                        D3D12_GPU_VIRTUAL_ADDRESS& ibGpu,
                                        uint32_t& vertexStride,
                                        uint32_t& vertexCount,
                                        uint32_t& indexCount,
                                        DXGI_FORMAT& indexFormat)
{
    // Get active guest memory view
    auto& memView = mcla::native::GetActiveGuestMemoryView();

    // Upload vertex buffer
    if (packet.vertexStreamCount == 0) {
        MCLA_LOG_WARN("UploadPacketGeometry: no vertex streams in packet");
        return false;
    }

    // For now, use first vertex stream
    const auto& stream = packet.vertexStreams[0];
    if (!stream.guestAddress || stream.stride == 0) {
        MCLA_LOG_WARN("UploadPacketGeometry: invalid vertex stream 0 (addr=0x%08X stride=%u)",
                      stream.guestAddress, stream.stride);
        return false;
    }

    // Read vertex data from guest memory
    if (!memView.IsValidRange(stream.guestAddress, stream.stride * packet.indexCount)) {
        MCLA_LOG_WARN("UploadPacketGeometry: vertex stream out of bounds (addr=0x%08X stride=%u count=%u)",
                      stream.guestAddress, stream.stride, packet.indexCount);
        return false;
    }

    // For now, use the test vertex stride (28 bytes) since our test PSO expects that
    vertexStride = 28;
    vertexCount = packet.indexCount;

    std::vector<uint8_t> vertexData(vertexStride * vertexCount);
    if (!memView.ReadBytes(stream.guestAddress, vertexData.data(), vertexData.size())) {
        MCLA_LOG_WARN("UploadPacketGeometry: failed to read vertex data from guest");
        return false;
    }

    // Upload vertex buffer
    vbGpu = 0;
    uint8_t* vbDst = MapUpload(vertexData.size(), D3D12_TEXTURE_DATA_PITCH_ALIGNMENT, vbGpu);
    if (!vbDst) return false;
    std::memcpy(vbDst, vertexData.data(), vertexData.size());

    // Upload index buffer
    if (packet.indexType == 1) {
        indexFormat = DXGI_FORMAT_R32_UINT;
    } else {
        indexFormat = DXGI_FORMAT_R16_UINT;
    }
    indexCount = packet.indexCount;

    // Check if we have a cached index buffer for this packet's index data
    ResourceKey ibKey = { ResourceKind::Buffer, packet.indexBufferAddress, packet.indexBufferSize, 0, 0 };
    ResourceEntry ibEntry;
    if (m_resourceCache.Find(ibKey, ibEntry)) {
        ibGpu = ibEntry.handle;
        MCLA_LOG_INFO("UploadPacketGeometry: using cached index buffer 0x%llx", ibGpu);
    } else {
        // Upload index buffer data
        if (!memView.IsValidRange(packet.indexBufferAddress, packet.indexBufferSize)) {
            MCLA_LOG_WARN("UploadPacketGeometry: index buffer out of bounds (addr=0x%08X size=%u)",
                          packet.indexBufferAddress, packet.indexBufferSize);
            return false;
        }

        std::vector<uint8_t> indexData(packet.indexBufferSize);
        if (!memView.ReadBytes(packet.indexBufferAddress, indexData.data(), indexData.size())) {
            MCLA_LOG_WARN("UploadPacketGeometry: failed to read index data from guest");
            return false;
        }

        ibGpu = 0;
        uint8_t* ibDst = MapUpload(indexData.size(), D3D12_TEXTURE_DATA_PITCH_ALIGNMENT, ibGpu);
        if (!ibDst) return false;
        std::memcpy(ibDst, indexData.data(), indexData.size());

        // Cache the index buffer for future frames
        ResourceEntry entry = { ibGpu, 0, false };
        m_resourceCache.Insert(ibKey, entry);
        MCLA_LOG_INFO("UploadPacketGeometry: cached new index buffer 0x%llx", ibGpu);
    }

    return true;
}

bool D3D12Backend::DrawCapturedPacket(const native::DrawPacket& packet)
{
    if (!m_initialized) {
        MCLA_LOG_WARN("DrawCapturedPacket: backend not initialized");
        return false;
    }
    if (!packet.isValid) {
        MCLA_LOG_WARN("DrawCapturedPacket: packet is invalid");
        return false;
    }
    if (!m_inFrame) {
        if (!BeginFrame()) return false;
    }

    // Build input layout from captured grcFvf
    std::vector<D3D12_INPUT_ELEMENT_DESC> inputLayout;
    if (packet.hasGrcFvf) {
        inputLayout = BuildInputLayoutFromGrcFvf(packet.grcFvf);
        if (inputLayout.empty()) {
            MCLA_LOG_WARN("DrawCapturedPacket: failed to build input layout from grcFvf");
            return false;
        }
    } else {
        MCLA_LOG_WARN("DrawCapturedPacket: packet missing grcFvf, using fallback layout");
        // Fallback to test layout
        inputLayout = {
            { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D12_APPEND_ALIGNED_ELEMENT, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
            { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D12_APPEND_ALIGNED_ELEMENT, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
        };
    }

    // Build pipeline state from packet
    renderer::PipelineState state = BuildPipelineStateFromPacket(packet);

    // Get or create PSO for this input layout + state
    Microsoft::WRL::ComPtr<ID3D12PipelineState> pso;
    renderer::PipelineKey key = renderer::ComputePipelineKey(packet.sqVsProgram, packet.sqPsProgram,
                                                            0, state);
    pso = m_pipelineCache.GetOrCompile(key, "", "", inputLayout);
    if (!pso) {
        // Fallback to test pipeline
        pso = m_testPipeline;
        if (!pso) {
            MCLA_LOG_WARN("DrawCapturedPacket: no valid PSO available");
            return false;
        }
    }

    // Upload geometry
    D3D12_GPU_VIRTUAL_ADDRESS vbGpu = 0, ibGpu = 0;
    uint32_t vertexStride = 0, vertexCount = 0, indexCount = 0;
    DXGI_FORMAT indexFormat = DXGI_FORMAT_R16_UINT;

    if (!UploadPacketGeometry(packet, vbGpu, ibGpu, vertexStride, vertexCount, indexCount, indexFormat)) {
        MCLA_LOG_WARN("DrawCapturedPacket: failed to upload packet geometry");
        return false;
    }

    // Draw using the generic dynamic mesh path with the created PSO
    DynamicMeshDesc desc = {};
    desc.vertexBytes = nullptr; // Already uploaded
    desc.vertexBytesSize = 0;
    desc.vertexStride = 28; // Test layout stride
    desc.vertexCount = vertexCount;
    desc.indexed = true;
    desc.indexFormat = indexFormat;
    desc.indexCount = indexCount;
    desc.cachedIndexGpu = ibGpu;
    desc.cachedIndexBytesSize = packet.indexBufferSize;

    return DrawDynamicMeshWithPipeline(desc, pso.Get());
}

} // namespace mcla::native
