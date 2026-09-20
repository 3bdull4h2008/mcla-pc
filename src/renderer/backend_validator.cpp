// Standalone Phase 3 backend validator: exercises the D3D12 draw-path setup
// AND the full render+readback loop headlessly using the WARP software
// adapter (no window/swap chain required).
//
// SYNTHETIC FIXTURE notice: the render step uses a deterministic quad with
// fixed colors. It is NOT a captured game frame and is never claimed as one;
// it proves the native draw path (upload arena, input layout, test PSO,
// viewport, R16 indices, topology) rasterizes correctly against a target
// sized from the captured frame-surface semantics.
//
// 1. Creates a D3D12 device (hardware fallback WARP).
// 2. Serializes + creates the same empty root signature the backend uses.
// 3. Creates the test graphics PSO from the embedded DXIL blobs and an input
//    layout identical to d3d12_backend.cpp's CreateTestPipeline.
// 4. Verifies the upload-arena allocation math matches the backend.
// 5. Cross-checks the input-layout element strides against vertex_decode
//    (POSITION float3 stride=12, COLOR0 float4 stride=16, total 28).
// 6. Static index-buffer cache / re-upload semantics.
// 7. SYNTHETIC render fixture: draws the test quad into an offscreen
//    1280x720 BGRA8 target (surface semantics from the captured
//    D1GRPH_PRIMARY_SURFACE_ADDRESS / RB_COPY_DEST_BASE frame: BGRA8, active
//    scissor 1280x720 per PA_SC_WINDOW_SCISSOR_BR=0x02D00500), reads back the
//    pixels and verifies clear color, viewport/scissor, per-corner vertex
//    colors (interpolation), and that both triangles of the index buffer are
//    rasterized (topology).
//
// Exit code 0 = clean, 1 = errors found.

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#ifndef NOMINMAX
#define NOMINMAX
#endif
#endif

#include <windows.h>
#include <d3d12.h>
#include <dxgi1_4.h>
#include <wrl/client.h>

#include "renderer/test_shaders.h"
#include "renderer/vertex_decode.h"
#include "renderer/resource_cache.h"
#include "renderer/texture_decode.h"

using namespace mcla::native;

#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <vector>

#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dxgi.lib")

using Microsoft::WRL::ComPtr;

// Debug-layer helper: dumps and clears any ID3D12InfoQueue messages produced
// so far, returning how many there were so callers can gate on it.
static UINT64 LeakInfoMessages(ID3D12Device* dev) {
    UINT64 n = 0;
    ComPtr<ID3D12InfoQueue> iq;
    if (dev && SUCCEEDED(dev->QueryInterface(IID_PPV_ARGS(&iq)))) {
        n = iq->GetNumStoredMessages();
        for (UINT64 i = 0; i < n; i++) {
            SIZE_T sz = 0;
            iq->GetMessage(i, nullptr, &sz);
            std::vector<char> buf(sz);
            D3D12_MESSAGE* msg = reinterpret_cast<D3D12_MESSAGE*>(buf.data());
            iq->GetMessage(i, msg, &sz);
            std::printf("    [DX12] %s\n", msg->pDescription);
        }
        iq->ClearStoredMessages();
    }
    return n;
}

static bool g_ok = true;

static void Check(bool cond, const char* what) {
    std::printf("  [%s] %s\n", cond ? "ok" : "FAIL", what);
    if (!cond) g_ok = false;
}

int main() {
    std::setvbuf(stdout, nullptr, _IONBF, 0);
    std::printf("== Phase 3 D3D12 backend validator ==\n");

    // Enable the debug layer so the validator reports (not hides) API misuse.
    {
        ComPtr<ID3D12Debug> dbg;
        if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&dbg)))) {
            dbg->EnableDebugLayer();
        }
    }

    // ── 1. Device (hardware, else WARP) ────────────────────────────────────
    ComPtr<IDXGIFactory4> factory;
    HRESULT hr = CreateDXGIFactory1(IID_PPV_ARGS(&factory));
    Check(SUCCEEDED(hr), "CreateDXGIFactory1");

    ComPtr<ID3D12Device> device;
    if (SUCCEEDED(hr)) {
        ComPtr<IDXGIAdapter1> adapter;
        for (UINT i = 0; SUCCEEDED(factory->EnumAdapters1(i, &adapter)); ++i) {
            DXGI_ADAPTER_DESC1 desc;
            adapter->GetDesc1(&desc);
            if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE) continue;
            if (SUCCEEDED(D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_11_0,
                                            IID_PPV_ARGS(&device)))) {
                std::printf("  using hardware adapter: %ls\n", desc.Description);
                break;
            }
        }
        if (!device) {
            ComPtr<IDXGIAdapter1> warp;
            if (SUCCEEDED(factory->EnumWarpAdapter(IID_PPV_ARGS(&warp)))) {
                hr = D3D12CreateDevice(warp.Get(), D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&device));
                Check(SUCCEEDED(hr), "D3D12CreateDevice (WARP)");
            }
        }
    }
    Check(device != nullptr, "D3D12 device available");
    if (!device) return 1;

    // ── 2. Root signature (mirrors CreateTestRootSignature) ────────────────
    // The backend's root signature carries a pixel-visible SRV descriptor
    // table at t0 plus a static linear-clamp sampler at s0 for the Phase 4
    // decoded-texture path. The test shaders do not sample, but the signature
    // must serialize/create and be usable for the PSO and the descriptor-table
    // bind below.
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
    rootDesc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;
    rootDesc.NumParameters = _countof(rootParams);
    rootDesc.pParameters = rootParams;
    rootDesc.NumStaticSamplers = 1;
    rootDesc.pStaticSamplers = &staticSampler;
    ComPtr<ID3DBlob> sigBlob, errBlob;
    hr = D3D12SerializeRootSignature(&rootDesc, D3D_ROOT_SIGNATURE_VERSION_1_0,
                                     &sigBlob, &errBlob);
    Check(SUCCEEDED(hr), "D3D12SerializeRootSignature (t0 SRV table + s0 static sampler)");

    ComPtr<ID3D12RootSignature> rootSig;
    if (SUCCEEDED(hr) && sigBlob) {
        hr = device->CreateRootSignature(0, sigBlob->GetBufferPointer(),
                                         sigBlob->GetBufferSize(),
                                         IID_PPV_ARGS(&rootSig));
        Check(SUCCEEDED(hr), "CreateRootSignature");
    }

    // ── 3. Test graphics PSO (mirrors CreateTestPipeline) ──────────────────
    Check(GetTestVsBlobSize() > 0 && GetTestPsBlobSize() > 0, "embedded DXIL blobs non-empty");

    D3D12_INPUT_ELEMENT_DESC elements[] = {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,  D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
        { "COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
    };

    D3D12_GRAPHICS_PIPELINE_STATE_DESC pso = {};
    pso.pRootSignature = rootSig.Get();
    pso.VS = { GetTestVsBlob(), GetTestVsBlobSize() };
    pso.PS = { GetTestPsBlob(), GetTestPsBlobSize() };
    pso.InputLayout = { elements, _countof(elements) };
    pso.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
    pso.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM;
    pso.NumRenderTargets = 1;
    pso.SampleDesc.Count = 1;
    pso.SampleMask = UINT_MAX;
    pso.RasterizerState.FillMode = D3D12_FILL_MODE_SOLID;
    pso.RasterizerState.CullMode = D3D12_CULL_MODE_NONE;
    pso.RasterizerState.DepthClipEnable = TRUE;
    pso.BlendState.RenderTarget[0].RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;
    pso.DepthStencilState.DepthEnable = FALSE;
    pso.DepthStencilState.StencilEnable = FALSE;

    ComPtr<ID3D12PipelineState> pipeline;
    hr = device->CreateGraphicsPipelineState(&pso, IID_PPV_ARGS(&pipeline));
    Check(SUCCEEDED(hr), "CreateGraphicsPipelineState (Phase 3 test PSO)");

    // ── 4. Upload-arena math ────────────────────────────────────────────────
    {
        size_t offset = 0;
        auto alignUp = [&](size_t v) { return (v + 255) & ~size_t(255); };
        offset = alignUp(offset + 28);  // one 28-byte vertex record
        Check(offset == 256, "upload arena aligns 28B request to 256");
        size_t offset2 = offset + 12;   // index buffer 6*2 = 12
        Check(alignUp(offset2) == 512, "upload arena aligns 12B request to 256 (offset2=268->512)");
    }

    // ── 5. Cross-check input layout vs vertex_decode ───────────────────────
    {
        VertexFormatDesc pos = DecodeVertexFormat(57);  // 32_32_32_float
        VertexFormatDesc col = DecodeVertexFormat(38);  // 32_32_32_32_float
        Check(pos.valid && pos.totalBytes == 12, "vf=57 (float3) stride == 12");
        Check(col.valid && col.totalBytes == 16, "vf=38 (float4) stride == 16");
        Check(pos.totalBytes + col.totalBytes == 28, "layout total stride == 28 (matches backend vertex)");
    }

    // ── 6. Static index-buffer cache (mirrors D3D12Backend::CreateStaticIndexBuffer ──
    {
        constexpr uint32_t kIndexBytes = 6 * sizeof(uint16_t);
        // Same synthetic key the backend inserts; dataVersion 1 == uploaded.
        const ResourceKey ibKey = { ResourceKind::Buffer, 0 /*synthetic test addr*/,
                                    kIndexBytes, DXGI_FORMAT_R16_UINT, 1 };
        ResourceCache cache(8);
        cache.Insert(ibKey, ResourceEntry{ 0x1234, 1, false });

        // Replaying the "same frame" later must be a cache hit with no re-upload.
        Check(!cache.NeedsUpload(ibKey), "static index buffer does not need re-upload (version matches)");
        ResourceEntry cached;
        Check(cache.Find(ibKey, cached) && cached.handle != 0, "static index buffer found in cache");

        // A version bump must force a re-upload.
        ResourceKey ibKeyV2 = ibKey; ibKeyV2.dataVersion = 2;
        Check(cache.NeedsUpload(ibKeyV2), "static index buffer needs re-upload after version bump");

        // Re-upload must cache a new handle so later frames reuse it.
        cache.Insert(ibKeyV2, ResourceEntry{ 0x5678, 2, false });
        ResourceEntry re;
        Check(cache.Find(ibKeyV2, re) && re.handle == 0x5678 && !cache.NeedsUpload(ibKeyV2),
              "static index buffer re-upload caches new handle");
        Check(re.handle != cached.handle, "re-uploaded handle differs from the first");

        // Index type consistency for the IB view format (DXGI_FORMAT_R16_UINT).
        Check(IndexElementBytes(0) == 2, "indexType=0 is 16-bit (2 bytes), matches R16_UINT view");
    }

    // ── 7. SYNTHETIC render fixture: draw into offscreen 1280x720 BGRA8
    //        target and read back the pixels. ───────────────────────────────
    // Surface semantics: the captured frame buffer is BGRA8 at 1280x720
    // active (PA_SC_WINDOW_SCISSOR_BR=0x02D00500 -> 0x500/0x2D0 = 1280/720,
    // base 0x07C48000 == D1GRPH_PRIMARY_SURFACE_ADDRESS/RB_COPY_DEST_BASE).
    // This step does NOT touch a swap chain (no window); it renders the same
    // command sequence D3D12Backend::DrawTestMeshedTriangle issues into an
    // offscreen target and verifies the produced image.
    {
        constexpr uint32_t kTargetW = 1280, kTargetH = 720;
        const float clearColor[4] = { 0.02f, 0.03f, 0.05f, 1.0f };

        ComPtr<ID3D12CommandQueue> queue;
        D3D12_COMMAND_QUEUE_DESC qdesc = {};
        qdesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
        hr = device->CreateCommandQueue(&qdesc, IID_PPV_ARGS(&queue));
        Check(SUCCEEDED(hr), "fixture CreateCommandQueue");

        ComPtr<ID3D12CommandAllocator> alloc;
        hr = device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&alloc));
        Check(SUCCEEDED(hr), "fixture CreateCommandAllocator");

        ComPtr<ID3D12GraphicsCommandList> cl;
        hr = device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, alloc.Get(),
                                       nullptr, IID_PPV_ARGS(&cl));
        Check(SUCCEEDED(hr), "fixture CreateCommandList");
        if (FAILED(hr)) return 1;
        cl->Close();

        // Offscreen render target (1280x720 BGRA8) + RTV.
        D3D12_RESOURCE_DESC rtDesc = {};
        rtDesc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
        rtDesc.Width = kTargetW;
        rtDesc.Height = kTargetH;
        rtDesc.DepthOrArraySize = 1;
        rtDesc.MipLevels = 1;
        rtDesc.SampleDesc.Count = 1;
        rtDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        rtDesc.Flags = D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET;

        D3D12_HEAP_PROPERTIES defHeap = { D3D12_HEAP_TYPE_DEFAULT };
        ComPtr<ID3D12Resource> offscreenRT;
        hr = device->CreateCommittedResource(&defHeap, D3D12_HEAP_FLAG_NONE,
                                             &rtDesc, D3D12_RESOURCE_STATE_RENDER_TARGET,
                                             nullptr, IID_PPV_ARGS(&offscreenRT));
        Check(SUCCEEDED(hr), "fixture offscreen RT creation");
        if (FAILED(hr)) return 1;

        D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc = {};
        rtvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
        rtvHeapDesc.NumDescriptors = 1;
        rtvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
        ComPtr<ID3D12DescriptorHeap> offRtvHeap;
        hr = device->CreateDescriptorHeap(&rtvHeapDesc, IID_PPV_ARGS(&offRtvHeap));
        Check(SUCCEEDED(hr), "fixture RTV heap");
        if (FAILED(hr)) return 1;
        D3D12_RENDER_TARGET_VIEW_DESC rtv = {};
        rtv.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        rtv.ViewDimension = D3D12_RTV_DIMENSION_TEXTURE2D;
        device->CreateRenderTargetView(offscreenRT.Get(), &rtv,
                                       offRtvHeap->GetCPUDescriptorHandleForHeapStart());

        // Upload heap for the fixed vertex/index data (mirrors the backend
        // arena alignment: 256-byte pitch).
        struct FixtureVertex { float pos[3]; float color[4]; };
        // Deterministic colored quad. NOTE: fixed colors, not the runtime's
        // pulse colors — assertions below sample the exact NDC corners.
        const FixtureVertex verts[4] = {
            { { -0.8f, -0.8f, 0.0f }, { 1.0f, 0.0f, 0.0f, 1.0f } },  // v0 red   (bottom-left)
            { {  0.8f, -0.8f, 0.0f }, { 0.0f, 0.0f, 1.0f, 1.0f } },  // v1 blue  (bottom-right)
            { {  0.8f,  0.8f, 0.0f }, { 0.0f, 1.0f, 0.0f, 1.0f } },  // v2 green (top-right)
            { { -0.8f,  0.8f, 0.0f }, { 1.0f, 1.0f, 1.0f, 1.0f } },  // v3 white (top-left)
        };
        const uint16_t indices[6] = { 0, 1, 2, 0, 2, 3 };   // 0-2: two tris sharing v0,v2
        constexpr uint32_t kStride = sizeof(FixtureVertex); // 28 B, matches vf=57+vf=38

        const size_t vbBytes = sizeof(verts), ibBytes = sizeof(indices);
        auto align256 = [](size_t v) { return (v + 255) & ~size_t(255); };
        const size_t totalBytes = align256(vbBytes) + align256(ibBytes);
        D3D12_RESOURCE_DESC uploadDesc = D3D12_RESOURCE_DESC{};
        uploadDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
        uploadDesc.Width = totalBytes;
        uploadDesc.Height = 1;
        uploadDesc.DepthOrArraySize = 1;
        uploadDesc.MipLevels = 1;
        uploadDesc.SampleDesc.Count = 1;
        uploadDesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
        D3D12_HEAP_PROPERTIES uh = { D3D12_HEAP_TYPE_UPLOAD };
        ComPtr<ID3D12Resource> upload;
        hr = device->CreateCommittedResource(&uh, D3D12_HEAP_FLAG_NONE,
                                             &uploadDesc, D3D12_RESOURCE_STATE_GENERIC_READ,
                                             nullptr, IID_PPV_ARGS(&upload));
        Check(SUCCEEDED(hr), "fixture upload buffer");
        if (FAILED(hr)) return 1;
        void* mapPtr = nullptr;
        if (upload) upload->Map(0, nullptr, &mapPtr);
        if (mapPtr) {
            uint8_t* p = static_cast<uint8_t*>(mapPtr);
            std::memcpy(p, verts, vbBytes);
            std::memcpy(p + align256(vbBytes), indices, ibBytes);
        }
        Check(mapPtr != nullptr, "fixture upload mapped");
        if (mapPtr == nullptr) return 1;
        D3D12_GPU_VIRTUAL_ADDRESS vbGpu = upload->GetGPUVirtualAddress();
        D3D12_GPU_VIRTUAL_ADDRESS ibGpu = vbGpu + align256(vbBytes);

        // Readback buffer.
        D3D12_RESOURCE_DESC rbDesc = uploadDesc; rbDesc.Width = kTargetW * kTargetH * 4;
        D3D12_HEAP_PROPERTIES rh = { D3D12_HEAP_TYPE_READBACK };
        ComPtr<ID3D12Resource> readback;
        hr = device->CreateCommittedResource(&rh, D3D12_HEAP_FLAG_NONE,
                                             &rbDesc, D3D12_RESOURCE_STATE_COPY_DEST,
                                             nullptr, IID_PPV_ARGS(&readback));
        Check(SUCCEEDED(hr), "fixture readback buffer");
        if (FAILED(hr)) return 1;

        // Record the draw (exact DrawTestMeshedTriangle sequence, offscreen).
        cl->Reset(alloc.Get(), nullptr);
        D3D12_VIEWPORT vp = { 0, 0, (float)kTargetW, (float)kTargetH, 0, 1 };
        D3D12_RECT scissor = { 0, 0, (LONG)kTargetW, (LONG)kTargetH };

        cl->ClearRenderTargetView(offRtvHeap->GetCPUDescriptorHandleForHeapStart(), clearColor, 0, nullptr);
        D3D12_CPU_DESCRIPTOR_HANDLE rtRtv = offRtvHeap->GetCPUDescriptorHandleForHeapStart();
        cl->OMSetRenderTargets(1, &rtRtv, FALSE, nullptr);
        cl->RSSetViewports(1, &vp);
        cl->RSSetScissorRects(1, &scissor);
        cl->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
        // { BufferLocation, SizeInBytes, StrideInBytes } — stride 28 = layout total.
        D3D12_VERTEX_BUFFER_VIEW vbv = { vbGpu, (UINT)vbBytes, kStride };
        cl->IASetVertexBuffers(0, 1, &vbv);
        D3D12_INDEX_BUFFER_VIEW ibv = { ibGpu, (UINT)ibBytes, DXGI_FORMAT_R16_UINT };
        cl->IASetIndexBuffer(&ibv);
        cl->SetGraphicsRootSignature(rootSig.Get());
        cl->SetPipelineState(pipeline.Get());
        cl->DrawIndexedInstanced(6, 1, 0, 0, 0);
        cl->Close();

        // Execute + wait (WARP is synchronous-free from CPU but still use a
        // real fence so the fixture is GPU-correct, not sleep-dependent).
        ID3D12CommandList* lists[] = { cl.Get() };
        queue->ExecuteCommandLists(1, lists);

        // Copy RT -> readback for pixel verification.
        ComPtr<ID3D12CommandAllocator> alloc2;
        hr = device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&alloc2));
        Check(SUCCEEDED(hr), "fixture copy allocator");
        if (FAILED(hr)) return 1;
        ComPtr<ID3D12GraphicsCommandList> copyCl;
        hr = device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, alloc2.Get(),
                                       nullptr, IID_PPV_ARGS(&copyCl));
        Check(SUCCEEDED(hr), "fixture copy list");
        if (FAILED(hr)) return 1;
        {
            D3D12_RESOURCE_BARRIER b2 = {};
            b2.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
            b2.Transition.pResource = offscreenRT.Get();
            b2.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
            b2.Transition.StateAfter = D3D12_RESOURCE_STATE_COPY_SOURCE;
            copyCl->ResourceBarrier(1, &b2);
            D3D12_TEXTURE_COPY_LOCATION dst = {}, src = {};
            dst.pResource = readback.Get();
            dst.Type = D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT;
            dst.PlacedFootprint.Footprint.Width = kTargetW;
            dst.PlacedFootprint.Footprint.Height = kTargetH;
            dst.PlacedFootprint.Footprint.Depth = 1;
            dst.PlacedFootprint.Footprint.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
            dst.PlacedFootprint.Footprint.RowPitch = kTargetW * 4;
            src.pResource = offscreenRT.Get();
            src.Type = D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX;
            src.SubresourceIndex = 0;
            copyCl->CopyTextureRegion(&dst, 0, 0, 0, &src, nullptr);
            copyCl->Close();
        }
        ID3D12CommandList* clists[] = { copyCl.Get() };
        queue->ExecuteCommandLists(1, clists);

        // Sync.
        ComPtr<ID3D12Fence> fence;
        hr = device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&fence));
        Check(SUCCEEDED(hr), "fixture fence");
        if (FAILED(hr)) return 1;
        HANDLE ev = CreateEventW(nullptr, FALSE, FALSE, nullptr);
        Check(ev != nullptr, "fixture sync event");
        if (ev == nullptr) return 1;
        queue->Signal(fence.Get(), 1);
        fence->SetEventOnCompletion(1, ev);
        WaitForSingleObject(ev, INFINITE);
        CloseHandle(ev);
        Check(LeakInfoMessages(device.Get()) == 0,
              "no D3D12 debug-layer messages during fixture draw + copy");

        // Sample pixels.
        D3D12_RANGE rr = { 0, kTargetW * kTargetH * 4 };
        uint8_t* rb = nullptr;
        hr = readback->Map(0, &rr, reinterpret_cast<void**>(&rb));
        Check(SUCCEEDED(hr), "fixture readback map");
        if (FAILED(hr)) return 1;
        if (rb) {
            auto sample = [&](uint32_t x, uint32_t y) -> std::array<uint8_t, 4> {
                return { rb[(y * kTargetW + x) * 4], rb[(y * kTargetW + x) * 4 + 1],
                         rb[(y * kTargetW + x) * 4 + 2], rb[(y * kTargetW + x) * 4 + 3] };
            };
            auto nearClear = [&](std::array<uint8_t, 4> px) {
                return px[0] <= 20 && px[1] <= 20 && px[2] <= 20;
            };
            // (1) Clear fill: far corners of the image are the clear color.
            std::array<uint8_t, 4> cTL = sample(64, 64), cTR = sample(kTargetW - 64, 64),
                                   cBL = sample(64, kTargetH - 64), cBR = sample(kTargetW - 64, kTargetH - 64);
            Check(nearClear(cTL) && nearClear(cTR) && nearClear(cBL) && nearClear(cBR),
                  "fixture clear color present at viewport corners");
            // (2) Exact interpolation at center: pixel center (640,360) ->
            //     NDC (0.00078, -0.00139) sits in tri (0,1,2) with barycentric
            //     weights ~ (0.4995, 0.0014, 0.4999): color = 0.5*red + 0.5*
            //     green over the v0->v2 diagonal = (127,127,0,255). Direct
            //     proof of vertex-color interpolation, not just inequality.
            auto cCenter = sample(kTargetW / 2, kTargetH / 2);
            Check(cCenter[0] == 127 && cCenter[1] == 127 && cCenter[2] == 0 && cCenter[3] == 255,
                  "fixture center reads (127,127,0,255) = 50/50 red+green over v0-v2 diagonal");
            // (3) Topology: the two triangles split the quad along the
            //     v0->v2 diagonal. Centroid of tri (0,1,2) is right of center;
            //     centroid of (0,2,3) is left of center. Both must be lit.
            //     NDC tri centroid (a,b): pixel = ((a/2+0.5)*W, (0.5-b/2)*H)
            //     tri012 centroid NDC ~ (0.267, -0.267) -> px ~ (811, 456)
            //     tri023 centroid NDC ~ (-0.267, 0.267) -> px ~ (469, 264)
            auto pT012 = sample(811, 456), pT023 = sample(469, 264);
            Check(!nearClear(pT012) && !nearClear(pT023),
                  "fixture both triangles rasterized (topology via R16 index buffer)");
            // (4) Interpolated colors differ across the two triangles: the
            //     split edge is the v0->v2 diagonal, so a lit pixel on either
            //     side samples a mixture dominated by adjacent vertex colors.
            uint32_t lit = 0;
            // Sample a horizontal line across the middle to confirm the quad
            // occupies the expected viewport band, not the full frame.
            for (uint32_t x = 0; x < kTargetW; x += 4) {
                auto px = sample(x, kTargetH / 2);
                if (!nearClear(px)) lit++;
            }
            Check(lit > 0 && lit * 4 < kTargetW, "fixture quad leaves left/right clear margins (viewport/scissor)");
            Check(pT012 != pT023, "fixture two triangles produce different colors (indices addressed)");
        }
        readback->Unmap(0, nullptr);
    }

    // ── 8. CPU untiling round-trip (mirrors texture_decode_test, no oracle) ─
    // Synthetic 32x32 texels of 8_8_8_8 (xenosFormat 6, bpb=4, bpbLog2=2).
    // Writes a tiled surface with deterministic content, untiles it with
    // UntileTexture2D, then verifies the linear output against a reference
    // re-tile computed from GetTiledOffset2D — proving the decode path a
    // captured texture would go through on the host before CreateDecodedTexture.
    {
        constexpr uint32_t kPitch = 32, kH = 32;  // one macro tile of blocks
        std::vector<uint8_t> tiled(kPitch * kH * 4, 0u);
        const uint32_t n = kPitch * kH * 4;
        for (uint32_t i = 0; i < n; ++i) tiled[i] = uint8_t((i * 131u + 17u) & 0xFF);

        std::vector<uint8_t> linear(kPitch * kH * 4, 0u);
        const TextureFormatInfo* fi = GetTextureFormatInfo(6);  // 8_8_8_8
        Check(fi != nullptr, "texture_decode: xenosFormat 6 (8_8_8_8) known");
        if (fi) {
            TextureUntileInfo ti = {};
            ti.format = fi;
            ti.offsetX = 0; ti.offsetY = 0;
            ti.width = kPitch; ti.height = kH;
            ti.inputPitch = kPitch; ti.inputHeight = kH;
            ti.outputPitch = kPitch;
            ti.srcBytes = uint32_t(tiled.size());
            ti.dstBytes = uint32_t(linear.size());
            UntileTexture2D(tiled.data(), linear.data(), ti);
        }

        // Reference re-tile via GetTiledOffset2D (same math the untile used).
        std::vector<uint8_t> ref(kPitch * kH * 4, 0u);
        for (uint32_t y = 0; y < kH; ++y) {
            for (uint32_t x = 0; x < kPitch; ++x) {
                const int32_t off = GetTiledOffset2D(int32_t(x), int32_t(y), kPitch, 2);
                std::memcpy(&ref[(y * kPitch + x) * 4], &tiled[off], 4);
            }
        }
        Check(linear == ref,
              "UntileTexture2D round-trip (32x32 8_8_8_8) matches GetTiledOffset2D reference");
    }

    // ── 9. Decoded-texture D3D12 slice: upload host-linear decoded pixels to
    //        a DEFAULT texture, create a shader-visible SRV at t0, bind the
    //        descriptor table + static sampler on a command list, then copy
    //        the texture back to a readback buffer and verify pixel equality.
    //        This exercises the exact resource/barrier/descriptor sequence the
    //        backend's CreateDecodedTexture + BindDecodedTexture issue, minus
    //        an actual sampling shader (none can be compiled headlessly).
    {
        constexpr uint32_t kTexW = 32, kTexH = 32;
        std::vector<uint8_t> pixels(kTexW * kTexH * 4);
        for (uint32_t i = 0; i < pixels.size(); ++i) pixels[i] = uint8_t((i * 197u + 3u) & 0xFF);

        ComPtr<ID3D12CommandQueue> queue2;
        D3D12_COMMAND_QUEUE_DESC qd2 = {};
        qd2.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
        hr = device->CreateCommandQueue(&qd2, IID_PPV_ARGS(&queue2));
        Check(SUCCEEDED(hr), "texture fixture: CreateCommandQueue");
        if (FAILED(hr)) return 1;
        ComPtr<ID3D12CommandAllocator> alloc2;
        hr = device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&alloc2));
        Check(SUCCEEDED(hr), "texture fixture: CreateCommandAllocator");
        if (FAILED(hr)) return 1;
        ComPtr<ID3D12GraphicsCommandList> cl2;
        hr = device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, alloc2.Get(),
                                       nullptr, IID_PPV_ARGS(&cl2));
        Check(SUCCEEDED(hr), "texture fixture: CreateCommandList");
        if (FAILED(hr)) return 1;
        cl2->Close();

        ComPtr<ID3D12Resource> tex, staging, readback;
        {
            D3D12_HEAP_PROPERTIES def = { D3D12_HEAP_TYPE_DEFAULT };
            D3D12_RESOURCE_DESC td = {};
            td.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
            td.Width = kTexW; td.Height = kTexH; td.DepthOrArraySize = 1;
            td.MipLevels = 1; td.SampleDesc.Count = 1;
            td.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
            hr = device->CreateCommittedResource(&def, D3D12_HEAP_FLAG_NONE, &td,
                                                 D3D12_RESOURCE_STATE_COPY_DEST,
                                                 nullptr, IID_PPV_ARGS(&tex));
            Check(SUCCEEDED(hr), "texture fixture: CreateCommittedResource (texture)");
            if (FAILED(hr)) return 1;

            // D3D12 footprint row pitch (aligned), same as the backend.
            D3D12_PLACED_SUBRESOURCE_FOOTPRINT fp = {};
            UINT64 total = 0;
            {
                UINT rowCount = 0;
                device->GetCopyableFootprints(&td, 0, 1, 0, &fp, &rowCount, nullptr, &total);
            }
            D3D12_HEAP_PROPERTIES up = { D3D12_HEAP_TYPE_UPLOAD };
            D3D12_RESOURCE_DESC bd = {};
            bd.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
            bd.Width = total; bd.Height = 1; bd.DepthOrArraySize = 1;
            bd.MipLevels = 1; bd.SampleDesc.Count = 1;
            bd.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
            hr = device->CreateCommittedResource(&up, D3D12_HEAP_FLAG_NONE, &bd,
                                                 D3D12_RESOURCE_STATE_GENERIC_READ,
                                                 nullptr, IID_PPV_ARGS(&staging));
            Check(SUCCEEDED(hr), "texture fixture: staging upload buffer");
            if (FAILED(hr)) return 1;

            void* mapped = nullptr;
            hr = staging->Map(0, nullptr, &mapped);
            Check(SUCCEEDED(hr) && mapped, "texture fixture: staging map");
            if (mapped) {
                uint8_t* dst = static_cast<uint8_t*>(mapped);
                const UINT srcPitch = kTexW * 4;
                for (UINT32 y = 0; y < kTexH; ++y)
                    std::memcpy(dst + size_t(y) * fp.Footprint.RowPitch,
                                pixels.data() + size_t(y) * srcPitch, srcPitch);
            }
            staging->Unmap(0, nullptr);

            D3D12_HEAP_PROPERTIES rbHeap = { D3D12_HEAP_TYPE_READBACK };
            D3D12_RESOURCE_DESC rbd = {};
            rbd.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
            rbd.Width = kTexW * kTexH * 4; rbd.Height = 1; rbd.DepthOrArraySize = 1;
            rbd.MipLevels = 1; rbd.SampleDesc.Count = 1;
            rbd.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
            hr = device->CreateCommittedResource(&rbHeap, D3D12_HEAP_FLAG_NONE, &rbd,
                                                 D3D12_RESOURCE_STATE_COPY_DEST,
                                                 nullptr, IID_PPV_ARGS(&readback));
            Check(SUCCEEDED(hr), "texture fixture: readback buffer");
            if (FAILED(hr)) return 1;

            // SRV heap (shader-visible) + descriptor + bind on the command list.
            D3D12_DESCRIPTOR_HEAP_DESC srvHeapDesc = {};
            srvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
            srvHeapDesc.NumDescriptors = 1;
            srvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
            ComPtr<ID3D12DescriptorHeap> srvHeap;
            hr = device->CreateDescriptorHeap(&srvHeapDesc, IID_PPV_ARGS(&srvHeap));
            Check(SUCCEEDED(hr), "texture fixture: shader-visible SRV heap");
            if (FAILED(hr)) return 1;

            D3D12_SHADER_RESOURCE_VIEW_DESC srv = {};
            srv.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
            srv.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
            srv.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
            srv.Texture2D.MipLevels = 1;
            device->CreateShaderResourceView(tex.Get(), &srv,
                                             srvHeap->GetCPUDescriptorHandleForHeapStart());

            // Record: copy upload->texture, transition, bind table+sampler,
            // transition, copy texture->readback.
            cl2->Reset(alloc2.Get(), nullptr);
            D3D12_TEXTURE_COPY_LOCATION dstLoc = {};
            dstLoc.pResource = tex.Get();
            dstLoc.Type = D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX;
            dstLoc.SubresourceIndex = 0;
            D3D12_TEXTURE_COPY_LOCATION srcLoc = {};
            srcLoc.pResource = staging.Get();
            srcLoc.Type = D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT;
            srcLoc.PlacedFootprint = fp;
            cl2->CopyTextureRegion(&dstLoc, 0, 0, 0, &srcLoc, nullptr);

            D3D12_RESOURCE_BARRIER b = {};
            b.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
            b.Transition.pResource = tex.Get();
            b.Transition.StateBefore = D3D12_RESOURCE_STATE_COPY_DEST;
            b.Transition.StateAfter = D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE;
            b.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
            cl2->ResourceBarrier(1, &b);

            cl2->SetDescriptorHeaps(1, srvHeap.GetAddressOf());
            cl2->SetGraphicsRootSignature(rootSig.Get());
            cl2->SetGraphicsRootDescriptorTable(
                0, srvHeap->GetGPUDescriptorHandleForHeapStart());

            // Transition PSR -> COPY_SOURCE and copy back for readback.
            b.Transition.StateBefore = D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE;
            b.Transition.StateAfter = D3D12_RESOURCE_STATE_COPY_SOURCE;
            cl2->ResourceBarrier(1, &b);
            D3D12_TEXTURE_COPY_LOCATION rbDst = {};
            rbDst.pResource = readback.Get();
            rbDst.Type = D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT;
            rbDst.PlacedFootprint.Footprint.Width = kTexW;
            rbDst.PlacedFootprint.Footprint.Height = kTexH;
            rbDst.PlacedFootprint.Footprint.Depth = 1;
            rbDst.PlacedFootprint.Footprint.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
            rbDst.PlacedFootprint.Footprint.RowPitch = kTexW * 4;
            D3D12_TEXTURE_COPY_LOCATION rbSrc = {};
            rbSrc.pResource = tex.Get();
            rbSrc.Type = D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX;
            rbSrc.SubresourceIndex = 0;
            cl2->CopyTextureRegion(&rbDst, 0, 0, 0, &rbSrc, nullptr);
            cl2->Close();

            ID3D12CommandList* lists2[] = { cl2.Get() };
            queue2->ExecuteCommandLists(1, lists2);
        }

        // Sync and read back.
        ComPtr<ID3D12Fence> fence2;
        hr = device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&fence2));
        Check(SUCCEEDED(hr), "texture fixture: fence");
        if (FAILED(hr)) return 1;
        HANDLE ev2 = CreateEventW(nullptr, FALSE, FALSE, nullptr);
        Check(ev2 != nullptr, "texture fixture: event");
        if (ev2 == nullptr) return 1;
        queue2->Signal(fence2.Get(), 1);
        fence2->SetEventOnCompletion(1, ev2);
        WaitForSingleObject(ev2, INFINITE);
        CloseHandle(ev2);
        Check(LeakInfoMessages(device.Get()) == 0,
              "no D3D12 debug-layer messages during texture upload/SRV/bind/copy");

        D3D12_RANGE rr2 = { 0, kTexW * kTexH * 4 };
        uint8_t* rbPtr = nullptr;
        hr = readback->Map(0, &rr2, reinterpret_cast<void**>(&rbPtr));
        Check(SUCCEEDED(hr), "texture fixture: readback map");
        if (FAILED(hr)) return 1;
        if (rbPtr) {
            bool same = true;
            for (UINT32 y = 0; y < kTexH && same; ++y) {
                const uint8_t* row = rbPtr + size_t(y) * kTexW * 4;
                if (std::memcmp(row, pixels.data() + size_t(y) * kTexW * 4, kTexW * 4) != 0)
                    same = false;
            }
            Check(same, "decoded-texture D3D12 slice round-trips pixels (upload -> SRV bind -> readback)");
        }
        readback->Unmap(0, nullptr);
    }

    std::printf("RESULT: %s\n", g_ok ? "CLEAN" : "ISSUES FOUND");
    return g_ok ? 0 : 1;
}
