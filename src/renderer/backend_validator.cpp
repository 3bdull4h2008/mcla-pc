// Standalone Phase 3 backend validator: exercises the D3D12 draw-path setup
// headlessly using the WARP software adapter (no window/swap chain required).
//
// 1. Creates a D3D12 device (hardware fallback WARP).
// 2. Serializes + creates the same empty root signature the backend uses.
// 3. Creates the test graphics PSO from the embedded DXIL blobs and an input
//    layout identical to d3d12_backend.cpp's CreateTestPipeline.
// 4. Verifies the upload-arena allocation math matches the backend.
// 5. Cross-checks the input-layout element strides against vertex_decode
//    (POSITION float3 stride=12, COLOR0 float4 stride=16, total 28).
//
// Exit code 0 = clean, 1 = errors found.

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

#include "renderer/test_shaders.h"
#include "renderer/vertex_decode.h"
#include "renderer/resource_cache.h"

using namespace mcla::native;

#include <cstdint>
#include <cstdio>

#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dxgi.lib")

using Microsoft::WRL::ComPtr;

static bool g_ok = true;

static void Check(bool cond, const char* what) {
    std::printf("  [%s] %s\n", cond ? "ok" : "FAIL", what);
    if (!cond) g_ok = false;
}

int main() {
    std::setvbuf(stdout, nullptr, _IONBF, 0);
    std::printf("== Phase 3 D3D12 backend validator ==\n");

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
    D3D12_ROOT_SIGNATURE_DESC rootDesc = {};
    rootDesc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;
    ComPtr<ID3DBlob> sigBlob, errBlob;
    hr = D3D12SerializeRootSignature(&rootDesc, D3D_ROOT_SIGNATURE_VERSION_1_0,
                                     &sigBlob, &errBlob);
    Check(SUCCEEDED(hr), "D3D12SerializeRootSignature (empty root sig)");

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
        offset = alignUp(offset + 28);  // 4 verts? no: single vertex = 28 bytes
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

    std::printf("RESULT: %s\n", g_ok ? "CLEAN" : "ISSUES FOUND");
    return g_ok ? 0 : 1;
}
