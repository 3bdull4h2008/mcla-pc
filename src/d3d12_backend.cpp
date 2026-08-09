#include "d3d12_backend.h"
#include "renderer/test_shaders.h"
#include "renderer/vertex_decode.h"
#include <rex/logging.h>

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
        REXLOG_ERROR("D3D12Backend: Null HWND passed to Initialize");
        return false;
    }

    m_hwnd = hwnd;
    m_width = (width > 0) ? width : 1280;
    m_height = (height > 0) ? height : 720;

    REXLOG_INFO("D3D12Backend: Initializing backend for HWND 0x{:X} ({}x{})",
                reinterpret_cast<uintptr_t>(hwnd), m_width, m_height);
    DWORD winThread = GetWindowThreadProcessId(hwnd, nullptr);
    DWORD curThread = GetCurrentThreadId();
    REXLOG_INFO("D3D12Backend: window owner thread={} calling thread={} {}",
                winThread, curThread, winThread == curThread ? "(MATCH)" : "(MISMATCH)");
    {
        char cls[256] = {};
        GetClassNameA(hwnd, cls, 256);
        REXLOG_INFO("D3D12Backend: window class='{}' visible={}",
                    cls, IsWindowVisible(hwnd) ? 1 : 0);
    }

    if (!CreateDevice()) return false;
    if (!CreateCommandObjects()) return false;
    if (!CreateSwapChain(hwnd, m_width, m_height)) return false;
    if (!CreateRenderTargets()) return false;
    if (!CreateSyncObjects()) return false;
    if (!CreateUploadHeap()) return false;
    if (!CreateTestRootSignature()) return false;
    if (!CreateTestPipeline()) return false;
    if (!CreateStaticIndexBuffer()) return false;
    if (!CreateSrvHeap()) return false;

    m_initialized = true;
    REXLOG_INFO("D3D12Backend: Successfully initialized D3D12 native renderer skeleton + Phase 3 test pipeline");
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
            REXLOG_INFO("D3D12Backend: Direct3D 12 Debug Layer enabled");
        }
    }
#endif

    HRESULT hr = CreateDXGIFactory2(dxgiFactoryFlags, IID_PPV_ARGS(&m_factory));
    if (FAILED(hr)) {
        REXLOG_ERROR("D3D12Backend: CreateDXGIFactory2 failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
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
            REXLOG_INFO("D3D12Backend: Selected GPU adapter: {}", descBuf);
            adapterSelected = true;
            break;
        }
    }

    if (!adapterSelected) {
        // Loop always leaves hardwareAdapter non-null after the first iteration,
        // so clear it explicitly before the WARP fallback.
        REXLOG_WARN("D3D12Backend: No hardware D3D12 adapter found, attempting WARP software adapter");
        hardwareAdapter = nullptr;
        m_factory->EnumWarpAdapter(IID_PPV_ARGS(&hardwareAdapter));
    }

    if (!hardwareAdapter) {
        REXLOG_ERROR("D3D12Backend: No D3D12-capable adapter (hardware or WARP) available");
        return false;
    }

    hr = D3D12CreateDevice(hardwareAdapter.Get(), D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&m_device));
    if (FAILED(hr)) {
        REXLOG_ERROR("D3D12Backend: D3D12CreateDevice failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
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
        REXLOG_ERROR("D3D12Backend: CreateCommandQueue failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    for (uint32_t i = 0; i < kBufferCount; ++i) {
        hr = m_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&m_commandAllocators[i]));
        if (FAILED(hr)) {
            REXLOG_ERROR("D3D12Backend: CreateCommandAllocator[{}] failed with hr=0x{:08X}", i, static_cast<uint32_t>(hr));
            return false;
        }
    }

    hr = m_device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, m_commandAllocators[0].Get(), nullptr, IID_PPV_ARGS(&m_commandList));
    if (FAILED(hr)) {
        REXLOG_ERROR("D3D12Backend: CreateCommandList failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    m_commandList->Close();
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
        REXLOG_ERROR("D3D12Backend: CreateSwapChainForHwnd failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    m_factory->MakeWindowAssociation(hwnd, DXGI_MWA_NO_ALT_ENTER);
    hr = swapChain.As(&m_swapChain);
    if (FAILED(hr)) {
        REXLOG_ERROR("D3D12Backend: Query IDXGISwapChain3 interface failed");
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
        REXLOG_ERROR("D3D12Backend: CreateDescriptorHeap (RTV) failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    m_rtvDescriptorSize = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);

    D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_rtvHeap->GetCPUDescriptorHandleForHeapStart());

    for (uint32_t i = 0; i < kBufferCount; ++i) {
        hr = m_swapChain->GetBuffer(i, IID_PPV_ARGS(&m_renderTargets[i]));
        if (FAILED(hr)) {
            REXLOG_ERROR("D3D12Backend: GetBuffer[{}] failed with hr=0x{:08X}", i, static_cast<uint32_t>(hr));
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
        REXLOG_ERROR("D3D12Backend: CreateFence failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
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
        REXLOG_ERROR("D3D12Backend: CreateEvent failed");
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
        REXLOG_ERROR("D3D12Backend: CreateCommittedResource(upload) failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    m_uploadCapacity = kUploadSize;
    m_uploadRegionSize = kUploadSize / kBufferCount;
    m_uploadOffset = 0;
    m_uploadMap = nullptr;
    hr = m_uploadHeap->Map(0, nullptr, reinterpret_cast<void**>(&m_uploadMap));
    if (FAILED(hr) || !m_uploadMap) {
        REXLOG_ERROR("D3D12Backend: upload heap Map failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    REXLOG_INFO("D3D12Backend: created {} MiB upload arena", kUploadSize / (1024 * 1024));
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
        REXLOG_ERROR("D3D12Backend: CreateCommittedResource(static ib) failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    void* mapped = nullptr;
    hr = m_staticIndexBuffer->Map(0, nullptr, &mapped);
    if (FAILED(hr) || !mapped) {
        REXLOG_ERROR("D3D12Backend: static index buffer Map failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }
    std::memcpy(mapped, indices, kIndexBytes);
    m_staticIndexBuffer->Unmap(0, nullptr);

    const uint64_t ibGpu = m_staticIndexBuffer->GetGPUVirtualAddress();
    const ResourceKey ibKey = { ResourceKind::Buffer, 0 /*synthetic test addr*/,
                                kIndexBytes, DXGI_FORMAT_R16_UINT, 1 };
    m_resourceCache.Insert(ibKey, ResourceEntry{ ibGpu, 1, false });
    m_stats.cacheMisses++;

    REXLOG_INFO("D3D12Backend: static index buffer cached ({} bytes, gpu=0x{:X})", kIndexBytes, ibGpu);
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
        REXLOG_WARN("D3D12Backend: upload arena region exhausted (need {} bytes, {} free); frame draw dropped",
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
        REXLOG_ERROR("D3D12Backend: CreateDescriptorHeap (CBV/SRV/UAV) failed with hr=0x{:08X}",
                     static_cast<uint32_t>(hr));
        return false;
    }
    m_srvDescriptorSize = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
    return true;
}

// Phase 4 data-independent slice: upload host-linear decoded pixels into a
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
            REXLOG_ERROR("D3D12Backend: CreateDecodedTexture unsupported dxgi format {}", dxgiFormat);
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
        REXLOG_ERROR("D3D12Backend: CreateDecodedTexture CreateCommittedResource failed with hr=0x{:08X}",
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
        REXLOG_ERROR("D3D12Backend: CreateDecodedTexture staging failed with hr=0x{:08X}",
                     static_cast<uint32_t>(hr));
        return false;
    }

    void* mapped = nullptr;
    hr = staging->Map(0, nullptr, &mapped);
    if (FAILED(hr) || !mapped) {
        REXLOG_ERROR("D3D12Backend: CreateDecodedTexture staging Map failed with hr=0x{:08X}",
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

    REXLOG_INFO("D3D12Backend: decoded texture created ({}x{}, format {}) + SRV t0",
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
        REXLOG_ERROR("D3D12Backend: D3D12SerializeRootSignature failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }

    hr = m_device->CreateRootSignature(0, signatureBlob->GetBufferPointer(),
                                       signatureBlob->GetBufferSize(),
                                       IID_PPV_ARGS(&m_rootSignature));
    if (FAILED(hr)) {
        REXLOG_ERROR("D3D12Backend: CreateRootSignature failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
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
        REXLOG_ERROR("D3D12Backend: CreateGraphicsPipelineState(test) failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
        return false;
    }
    REXLOG_INFO("D3D12Backend: Phase 3 test pipeline created (DXIL {} vs / {} ps bytes)",
                GetTestVsBlobSize(), GetTestPsBlobSize());
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
        REXLOG_INFO("D3D12Backend: DrawTestMeshedTriangle frame={} present_hr=0x{:08X}",
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
        REXLOG_WARN("D3D12Backend: DrawDynamicMesh refused vertex stride {} (test layout is {})",
                    desc.vertexStride, kLayoutStride);
        return false;
    }
    if (desc.indexed && !desc.cachedIndexGpu &&
        (!desc.indexBytes || desc.indexBytesSize == 0)) {
        return false;
    }
    if (desc.indexed && desc.cachedIndexGpu && desc.cachedIndexBytesSize == 0) {
        REXLOG_WARN("D3D12Backend: DrawDynamicMesh refused cached IB with size 0");
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
    m_commandList->SetPipelineState(m_testPipeline.Get());
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

bool D3D12Backend::Resize(uint32_t width, uint32_t height) {
    std::lock_guard<std::recursive_mutex> lock(m_mutex);
    if (!m_initialized || !m_swapChain) return false;
    if (width == 0 || height == 0) return false;

    REXLOG_INFO("D3D12Backend: Resizing swap chain to {}x{}", width, height);

    WaitForGpu();

    for (uint32_t i = 0; i < kBufferCount; ++i) {
        m_renderTargets[i].Reset();
        m_fenceValues[i] = m_fenceValues[m_frameIndex];
    }

    HRESULT hr = m_swapChain->ResizeBuffers(kBufferCount, width, height, DXGI_FORMAT_R8G8B8A8_UNORM, 0);
    if (FAILED(hr)) {
        REXLOG_ERROR("D3D12Backend: ResizeBuffers failed with hr=0x{:08X}", static_cast<uint32_t>(hr));
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

    if (m_fenceEvent) {
        CloseHandle(m_fenceEvent);
        m_fenceEvent = nullptr;
    }

    m_fence.Reset();
    for (uint32_t i = 0; i < kBufferCount; ++i) {
        m_renderTargets[i].Reset();
        m_commandAllocators[i].Reset();
    }
    m_rtvHeap.Reset();
    m_commandList.Reset();
    m_commandQueue.Reset();
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
    REXLOG_INFO("D3D12Backend: Shutdown complete");
}

} // namespace mcla::native
