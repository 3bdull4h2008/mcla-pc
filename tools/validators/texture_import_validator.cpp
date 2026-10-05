// tools/validators/texture_import_validator.cpp
//
// External proof that a decoded host image can be imported into MCLA's own D3D12
// layer and sampled on screen. Not part of the emulator exe, and it touches nothing
// in the boot path: nothing here can move CP-DRAW / DRAW_INDEXED, and a pass says
// nothing about guest boot progress.
//
// It drives the real backend through its public API only:
//   D3D12Backend::Initialize                   device + swapchain on this window
//   D3D12Backend::CreateDecodedTexture         the import entry point (had zero callers)
//   D3D12Backend::BindDecodedTexture           SRV descriptor table + static sampler
//   D3D12Backend::CreatePipelineFromDxil       our textured VS/PS, their root signature
//   D3D12Backend::DrawDynamicMeshWithPipeline  backbuffer draw + Present
//
// Each case renders from one decoded upload twice: into an offscreen RT at the
// texture's native size (read back on the GPU, compared byte-for-byte) and onto the
// swapchain so it is genuinely visible. Three controls keep the compare from being
// vacuous: a baseline case with nothing imported, an offscreen clear colour that
// appears in no chart, and a second chart differing from the first everywhere.
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif

#include <windows.h>
#include <wingdi.h>
#include <d3d12.h>
#include <d3d12sdklayers.h>
#include <dxgi1_4.h>
#include <wrl/client.h>

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <unordered_set>
#include <vector>

#include "d3d12_backend.h"
#include "texture_quad_shaders_gen.h"

using Microsoft::WRL::ComPtr;
using mcla::native::D3D12Backend;

namespace {

int g_pass = 0;
int g_fail = 0;

void Check(bool ok, const std::string& what) {
    std::printf("  %s %s\n", ok ? "[ ok ]" : "[FAIL ]", what.c_str());
    std::fflush(stdout);
    if (ok) ++g_pass; else ++g_fail;
}

void Note(const std::string& what) {
    std::printf("        %s\n", what.c_str());
    std::fflush(stdout);
}

// The backend turns on the D3D12 debug layer, so the info queue is the fastest way to
// learn WHY a call failed instead of guessing at it.
void DrainInfoQueue(ID3D12Device* dev, const char* where) {
    if (!dev) return;
    ComPtr<ID3D12InfoQueue> iq;
    if (FAILED(dev->QueryInterface(IID_PPV_ARGS(&iq)))) {
        Note(std::string(where) + ": no info queue (debug layer off?)");
        return;
    }
    const UINT64 n = iq->GetNumStoredMessages();
    if (n == 0) {
        Note(std::string(where) + ": info queue empty");
        return;
    }
    for (UINT64 i = 0; i < n && i < 12; ++i) {
        SIZE_T sz = 0;
        if (FAILED(iq->GetMessage(i, nullptr, &sz)) || sz == 0) continue;
        std::vector<uint8_t> buf(sz, 0u);
        auto* msg = reinterpret_cast<D3D12_MESSAGE*>(buf.data());
        if (FAILED(iq->GetMessage(i, msg, &sz))) continue;
        std::printf("        [%s] %s\n", where, msg->pDescription ? msg->pDescription : "");
    }
    std::fflush(stdout);
    iq->ClearStoredMessages();
}

struct Image {
    uint32_t w = 0;
    uint32_t h = 0;
    std::vector<uint8_t> rgba;  // row-major, packed R,G,B,A
};

// Written to the offscreen RT before the draw. Present in neither chart, so "the
// clear survived" is distinguishable from "an imported texel landed".
const float kClearColor[4] = {0.0f, 1.0f, 0.0f, 1.0f};
const uint8_t kClearRgb[3] = {0, 255, 0};

// Deterministic chart: asymmetric on both axes with single-channel-only corner
// markers, so a vertical flip, a horizontal flip and an R/B swap each produce a
// different image instead of passing by symmetry.
Image MakeChart(uint32_t w, uint32_t h, uint32_t variant) {
    Image im;
    im.w = w;
    im.h = h;
    im.rgba.resize(size_t(w) * h * 4);
    const uint32_t ring = w / 16;
    const uint32_t iw = w - 2 * ring, ih = h - 2 * ring;
    for (uint32_t y = 0; y < h; ++y) {
        for (uint32_t x = 0; x < w; ++x) {
            uint8_t* p = &im.rgba[(size_t(y) * w + x) * 4];
            p[3] = 255;
            if (x < ring || y < ring || x + ring >= w || y + ring >= h) {
                if (variant == 1) { p[0] = 255; p[1] = 255; p[2] = 0; }  // yellow
                else { p[0] = 255; p[1] = 0; p[2] = 255; }               // magenta
                continue;
            }
            const uint32_t u = x - ring, v = y - ring;
            p[0] = uint8_t(u * 255 / (iw - 1));
            p[1] = uint8_t(v * 255 / (ih - 1));
            p[2] = (((x >> 6) ^ (y >> 6)) & 1u) ? 255 : 0;
            if (variant == 1) {
                p[0] = uint8_t(255 - u * 255 / (iw - 1));
                p[2] = (((x >> 5) ^ (y >> 6)) & 1u) ? 255 : 0;
            }
            if (u < 24 && v < 24) { p[0] = 255; p[1] = 0; p[2] = 0; }              // red TL
            if (u + 24 >= iw && v + 24 >= ih) { p[0] = 0; p[1] = 0; p[2] = 255; }  // blue BR
        }
    }
    return im;
}

bool ExactMatch(const Image& a, const Image& b) {
    return a.rgba == b.rgba;
}

bool Upload(ID3D12Device* dev, const void* src, size_t bytes, ComPtr<ID3D12Resource>& out) {
    D3D12_HEAP_PROPERTIES hp = {};
    hp.Type = D3D12_HEAP_TYPE_UPLOAD;
    D3D12_RESOURCE_DESC rd = {};
    rd.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
    rd.Width = UINT(bytes);
    rd.Height = 1;
    rd.DepthOrArraySize = 1;
    rd.MipLevels = 1;
    rd.SampleDesc.Count = 1;
    rd.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
    if (FAILED(dev->CreateCommittedResource(&hp, D3D12_HEAP_FLAG_NONE, &rd,
                                            D3D12_RESOURCE_STATE_GENERIC_READ, nullptr,
                                            IID_PPV_ARGS(&out))))
        return false;
    if (src && bytes) {
        void* mapped = nullptr;
        if (FAILED(out->Map(0, nullptr, &mapped))) return false;
        std::memcpy(mapped, src, bytes);
        out->Unmap(0, nullptr);
    }
    return true;
}

// ---- real-asset side: DDS container + BC1/BC3 block decode -------------------
//
// The retail members reached offline by tools/extract_rpf_member.py are plain DDS
// containers holding DXT1/DXT5 with a full linear mip chain (a 256x256 DXT1 mip=9
// file is 128 + 32768 + 8192 + ... == 43832 bytes, exactly what the archive
// declares), so no untile is required for these; texture_decode's tiled path is
// covered separately by backend_validator section 8. CreateDecodedTexture only
// accepts scalar formats ("1 block/texel so the row-pitch copy is exact"), so the
// compressed blocks are expanded to RGBA8 here before the import.

uint32_t ReadU32LE(const uint8_t* p) {
    return uint32_t(p[0]) | (uint32_t(p[1]) << 8) | (uint32_t(p[2]) << 16) |
           (uint32_t(p[3]) << 24);
}

uint8_t Unpack5To8(uint8_t v) { return uint8_t((v << 3) | (v >> 2)); }

void DecodeBc1Block(const uint8_t* blk, uint8_t out[16 * 4]) {
    const uint32_t c0 = ReadU32LE(blk) & 0xFFFF;
    const uint32_t c1 = (ReadU32LE(blk) >> 16) & 0xFFFF;
    uint8_t pal[4][4];
    auto unpack = [&](uint32_t c, uint8_t* d) {
        d[0] = Unpack5To8(uint8_t(c >> 11) & 0x1F);
        d[1] = Unpack5To8(uint8_t(c >> 5) & 0x3F);
        d[2] = Unpack5To8(uint8_t(c) & 0x1F);
        d[3] = 255;
    };
    unpack(c0, pal[0]);
    unpack(c1, pal[1]);
    if (c0 > c1) {  // four opaque colours
        for (int i = 0; i < 3; ++i) {
            pal[2][i] = uint8_t((2 * pal[0][i] + pal[1][i]) / 3);
            pal[3][i] = uint8_t((2 * pal[1][i] + pal[0][i]) / 3);
        }
        pal[2][3] = pal[3][3] = 255;
    } else {  // three colours plus the 1-bit-alpha index-3 entry
        for (int i = 0; i < 3; ++i) {
            pal[2][i] = uint8_t((pal[0][i] + pal[1][i]) / 2);
            pal[3][i] = 0;
        }
        pal[2][3] = 255;
        pal[3][3] = 0;
    }
    const uint32_t idx = ReadU32LE(blk + 8);
    for (int i = 0; i < 16; ++i) {
        const uint8_t sel = uint8_t((idx >> (i * 2)) & 3u);
        std::memcpy(&out[i * 4], pal[sel], 4);
    }
}

void DecodeBc3Block(const uint8_t* blk, uint8_t out[16 * 4]) {
    uint8_t alpha[8];
    alpha[0] = blk[0];
    alpha[1] = blk[1];
    if (alpha[0] > alpha[1]) {
        for (int i = 2; i < 8; ++i)
            alpha[i] = uint8_t(((8 - i) * alpha[0] + (i - 1) * alpha[1]) / 7);
    } else {
        for (int i = 2; i < 6; ++i)
            alpha[i] = uint8_t(((6 - i) * alpha[0] + (i - 1) * alpha[1]) / 5);
        alpha[6] = 0;
        alpha[7] = 255;
    }
    uint64_t bits = 0;
    for (int i = 0; i < 6; ++i) bits |= uint64_t(blk[2 + i]) << (i * 8);
    uint8_t colour[16 * 4];
    DecodeBc1Block(blk + 8, colour);
    for (int i = 0; i < 16; ++i) {
        std::memcpy(&out[i * 4], &colour[i * 4], 3);
        out[i * 4 + 3] = alpha[uint8_t((bits >> (i * 3)) & 7u)];
    }
}

bool LoadDdsMip0AsRgba(const std::string& path, Image& out, std::string& why) {
    FILE* f = std::fopen(path.c_str(), "rb");
    if (!f) { why = "cannot open"; return false; }
    std::vector<uint8_t> d;
    fseek(f, 0, SEEK_END);
    const long n = ftell(f);
    fseek(f, 0, SEEK_SET);
    d.resize(size_t(n));
    const size_t got = std::fread(d.data(), 1, d.size(), f);
    std::fclose(f);
    if (got < 128 || std::memcmp(d.data(), "DDS ", 4) != 0) { why = "not a DDS"; return false; }
    const uint32_t h = ReadU32LE(&d[12]);
    const uint32_t w = ReadU32LE(&d[16]);
    const uint32_t mipCount = ReadU32LE(&d[28]);
    char fourcc[5] = {0, 0, 0, 0, 0};
    std::memcpy(fourcc, &d[84], 4);
    const bool bc1 = std::strcmp(fourcc, "DXT1") == 0;
    const bool bc3 = std::strcmp(fourcc, "DXT5") == 0 || std::strcmp(fourcc, "BC3") == 0;
    if (!bc1 && !bc3) {
        why = std::string("fourCC '") + fourcc + "' is not BC1/BC3";
        return false;
    }
    if (w == 0 || h == 0 || w % 4 || h % 4) { why = "not a whole number of blocks"; return false; }
    const size_t bytesPerBlock = bc1 ? 8 : 16;
    const size_t mip0 = size_t(w / 4) * (h / 4) * bytesPerBlock;
    if (d.size() < 128 + mip0) {
        why = "truncated: need " + std::to_string(128 + mip0) + " have " + std::to_string(d.size());
        return false;
    }
    out.w = w;
    out.h = h;
    out.rgba.resize(size_t(w) * h * 4);
    const uint8_t* src = d.data() + 128;
    for (uint32_t by = 0; by < h / 4; ++by) {
        for (uint32_t bx = 0; bx < w / 4; ++bx) {
            uint8_t px[16 * 4];
            const uint8_t* blk = src + (size_t(by) * (w / 4) + bx) * bytesPerBlock;
            if (bc1) DecodeBc1Block(blk, px); else DecodeBc3Block(blk, px);
            for (int sy = 0; sy < 4; ++sy) {
                std::memcpy(&out.rgba[(size_t(by * 4 + sy) * w + bx * 4) * 4],
                            &px[sy * 16], 16);
            }
        }
    }
    Note(std::string("dds ") + std::to_string(w) + "x" + std::to_string(h) + " fourCC=" + fourcc +
         " mipCount=" + std::to_string(mipCount) + " -> mip0 " + std::to_string(mip0) +
         " B decoded to " + std::to_string(out.rgba.size()) + " B RGBA");
    return true;
}

bool AllocateReadback(ID3D12Device* dev, size_t bytes, ComPtr<ID3D12Resource>& out) {
    // A CopyTextureRegion DESTINATION must sit on a READBACK heap; the UPLOAD heap
    // the backend uses for its own staging is only valid as a copy SOURCE.
    D3D12_HEAP_PROPERTIES hp = {};
    hp.Type = D3D12_HEAP_TYPE_READBACK;
    D3D12_RESOURCE_DESC rd = {};
    rd.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
    rd.Width = UINT(bytes);
    rd.Height = 1;
    rd.DepthOrArraySize = 1;
    rd.MipLevels = 1;
    rd.SampleDesc.Count = 1;
    rd.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
    return SUCCEEDED(dev->CreateCommittedResource(&hp, D3D12_HEAP_FLAG_NONE, &rd,
                                                  D3D12_RESOURCE_STATE_COPY_DEST, nullptr,
                                                  IID_PPV_ARGS(&out)));
}

struct Quad {
    float verts[18];
    ComPtr<ID3D12Resource> vb;
    D3D12_VERTEX_BUFFER_VIEW view = {};
};

bool MakeQuad(ID3D12Device* dev, Quad& q) {
    // Two triangles covering clip space; the VS derives uv from position.
    const float v[18] = {
        -1.0f, -1.0f, 0.0f, +1.0f, -1.0f, 0.0f, +1.0f, +1.0f, 0.0f,
        -1.0f, -1.0f, 0.0f, +1.0f, +1.0f, 0.0f, -1.0f, +1.0f, 0.0f,
    };
    std::memcpy(q.verts, v, sizeof(v));
    if (!Upload(dev, q.verts, sizeof(q.verts), q.vb)) return false;
    q.view.BufferLocation = q.vb->GetGPUVirtualAddress();
    q.view.StrideInBytes = 12;
    q.view.SizeInBytes = UINT(sizeof(q.verts));
    return true;
}

struct Offscreen {
    ComPtr<ID3D12Resource> rt;
    ComPtr<ID3D12Resource> staging;
    ComPtr<ID3D12DescriptorHeap> rtvHeap;
    D3D12_PLACED_SUBRESOURCE_FOOTPRINT fp = {};
    UINT64 totalBytes = 0;
    Image packed;  // last readback, unpacked RGBA
};

bool PrepareOffscreen(ID3D12Device* dev, uint32_t w, uint32_t h, Offscreen& o) {
    D3D12_RESOURCE_DESC rtd = {};
    rtd.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
    rtd.Width = w;
    rtd.Height = h;
    rtd.DepthOrArraySize = 1;
    rtd.MipLevels = 1;
    rtd.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    rtd.SampleDesc.Count = 1;
    rtd.Flags = D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET;
    D3D12_CLEAR_VALUE cv = {};
    cv.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    for (int i = 0; i < 4; ++i) cv.Color[i] = kClearColor[i];

    D3D12_HEAP_PROPERTIES dp = {};
    dp.Type = D3D12_HEAP_TYPE_DEFAULT;
    if (FAILED(dev->CreateCommittedResource(&dp, D3D12_HEAP_FLAG_NONE, &rtd,
                                            D3D12_RESOURCE_STATE_RENDER_TARGET, &cv,
                                            IID_PPV_ARGS(&o.rt))))
        return false;

    D3D12_DESCRIPTOR_HEAP_DESC dh = {};
    dh.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
    dh.NumDescriptors = 1;
    if (FAILED(dev->CreateDescriptorHeap(&dh, IID_PPV_ARGS(&o.rtvHeap)))) return false;
    D3D12_RENDER_TARGET_VIEW_DESC rtvd = {};
    rtvd.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    rtvd.ViewDimension = D3D12_RTV_DIMENSION_TEXTURE2D;
    rtvd.Texture2D.MipSlice = 0;
    dev->CreateRenderTargetView(o.rt.Get(), &rtvd,
                                o.rtvHeap->GetCPUDescriptorHandleForHeapStart());

    UINT rowCount = 0;
    UINT64 rowSizeInBytes = 0;
    dev->GetCopyableFootprints(&rtd, 0, 1, 0, &o.fp, &rowCount, &rowSizeInBytes,
                               &o.totalBytes);
    return AllocateReadback(dev, size_t(o.totalBytes), o.staging);
}

// Record the offscreen sample + copy-out, then let the backend draw the same decoded
// texture to the swapchain (that call closes, submits and Presents the list).
bool RunCase(D3D12Backend& be, const Image& img, ID3D12PipelineState* pso, const Quad& quad,
             Offscreen& o, bool uploadTexture) {
    o.packed.rgba.clear();
    if (!be.BeginFrame()) { Note("BeginFrame failed"); return false; }
    if (uploadTexture &&
        !be.CreateDecodedTexture(img.rgba.data(), img.w, img.h,
                                 DXGI_FORMAT_R8G8B8A8_UNORM)) {
        Note("CreateDecodedTexture failed");
        return false;
    }
    ID3D12GraphicsCommandList* cl = be.GetCommandList();
    if (!cl) { Note("no command list"); return false; }

    const D3D12_CPU_DESCRIPTOR_HANDLE rtv =
        o.rtvHeap->GetCPUDescriptorHandleForHeapStart();
    cl->OMSetRenderTargets(1, &rtv, FALSE, nullptr);
    cl->ClearRenderTargetView(rtv, kClearColor, 0, nullptr);
    const D3D12_VIEWPORT vp = {0.0f, 0.0f, float(img.w), float(img.h), 0.0f, 1.0f};
    const D3D12_RECT sc = {0, 0, LONG(img.w), LONG(img.h)};
    cl->RSSetViewports(1, &vp);
    cl->RSSetScissorRects(1, &sc);
    cl->SetGraphicsRootSignature(be.GetRootSignature());
    cl->SetPipelineState(pso);
    cl->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    cl->IASetVertexBuffers(0, 1, &quad.view);
    be.BindDecodedTexture();
    cl->DrawInstanced(6, 1, 0, 0);

    D3D12_RESOURCE_BARRIER toCopy = {};
    toCopy.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    toCopy.Transition.pResource = o.rt.Get();
    toCopy.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
    toCopy.Transition.StateAfter = D3D12_RESOURCE_STATE_COPY_SOURCE;
    cl->ResourceBarrier(1, &toCopy);

    D3D12_TEXTURE_COPY_LOCATION dst = {};
    dst.pResource = o.staging.Get();
    dst.Type = D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT;
    dst.PlacedFootprint = o.fp;
    D3D12_TEXTURE_COPY_LOCATION src = {};
    src.pResource = o.rt.Get();
    src.Type = D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX;
    src.SubresourceIndex = 0;
    cl->CopyTextureRegion(&dst, 0, 0, 0, &src, nullptr);

    D3D12Backend::DynamicMeshDesc desc;
    desc.vertexBytes = quad.verts;
    desc.vertexBytesSize = UINT(sizeof(quad.verts));
    desc.vertexStride = 12;
    desc.vertexCount = 6;
    desc.indexed = false;
    if (!be.DrawDynamicMeshWithPipeline(desc, pso)) {
        Note("DrawDynamicMeshWithPipeline/Present failed");
        DrainInfoQueue(be.GetDevice(), "draw");
        return false;
    }
    be.WaitForGpu();

    uint8_t* mapped = nullptr;
    if (FAILED(o.staging->Map(0, nullptr, reinterpret_cast<void**>(&mapped)))) {
        Note("staging Map failed");
        return false;
    }
    o.packed.w = img.w;
    o.packed.h = img.h;
    o.packed.rgba.resize(size_t(img.w) * img.h * 4);
    const uint32_t srcPitch = o.fp.Footprint.RowPitch;
    for (uint32_t y = 0; y < img.h; ++y) {
        std::memcpy(&o.packed.rgba[size_t(y) * img.w * 4], mapped + size_t(y) * srcPitch,
                    size_t(img.w) * 4);
    }
    o.staging->Unmap(0, nullptr);
    return true;
}

struct Stats {
    uint32_t uniqueColors = 0;
    uint32_t nonBlack = 0;
    uint32_t clearLeft = 0;
};

Stats Measure(const Image& im) {
    std::unordered_set<uint32_t> seen;
    Stats s;
    for (size_t i = 0; i + 3 < im.rgba.size(); i += 4) {
        if (im.rgba[i] || im.rgba[i + 1] || im.rgba[i + 2]) ++s.nonBlack;
        if (im.rgba[i] == kClearRgb[0] && im.rgba[i + 1] == kClearRgb[1] &&
            im.rgba[i + 2] == kClearRgb[2])
            ++s.clearLeft;
        seen.insert((uint32_t(im.rgba[i]) << 24) | (uint32_t(im.rgba[i + 1]) << 16) |
                    (uint32_t(im.rgba[i + 2]) << 8) | im.rgba[i + 3]);
    }
    s.uniqueColors = uint32_t(seen.size());
    return s;
}

// Self-diagnosing exact compare: on mismatch, test the hypotheses that would each
// explain it, so the run says what broke rather than just "it differs".
bool VerifyExact(const Image& got, const Image& exp, const std::string& what) {
    if (got.w != exp.w || got.h != exp.h) {
        Check(false, what + ": geometry mismatch");
        return false;
    }
    const uint32_t w = exp.w, h = exp.h;
    size_t bad = 0;
    size_t firstBad = SIZE_MAX;
    size_t clearHits = 0, rbSwapHits = 0, vflipHits = 0, hflipHits = 0;
    for (uint32_t y = 0; y < h; ++y) {
        for (uint32_t x = 0; x < w; ++x) {
            const size_t i = (size_t(y) * w + x) * 4;
            const uint8_t* g = &got.rgba[i];
            const uint8_t* e = &exp.rgba[i];
            if (!std::memcmp(g, e, 4)) continue;
            if (!bad) firstBad = i;
            ++bad;
            if (g[0] == kClearRgb[0] && g[1] == kClearRgb[1] && g[2] == kClearRgb[2])
                ++clearHits;
            if (g[0] == e[2] && g[1] == e[1] && g[2] == e[0]) ++rbSwapHits;
            const uint8_t* ev = &exp.rgba[(size_t(h - 1 - y) * w + x) * 4];
            const uint8_t* eh = &exp.rgba[(size_t(y) * w + (w - 1 - x)) * 4];
            if (!std::memcmp(g, ev, 3)) ++vflipHits;
            if (!std::memcmp(g, eh, 3)) ++hflipHits;
        }
    }
    const size_t total = size_t(w) * h;
    Check(bad == 0, what + " (" + std::to_string(total - bad) + "/" +
                         std::to_string(total) + " texels exact)");
    if (bad) {
        const uint8_t* g = &got.rgba[firstBad];
        const uint8_t* e = &exp.rgba[firstBad];
        const uint32_t x = uint32_t(firstBad / 4 % w), y = uint32_t(firstBad / 4 / w);
        Note("first mismatch (" + std::to_string(x) + "," + std::to_string(y) + ") got " +
             std::to_string(g[0]) + "," + std::to_string(g[1]) + "," + std::to_string(g[2]) +
             " want " + std::to_string(e[0]) + "," + std::to_string(e[1]) + "," +
             std::to_string(e[2]));
        char buf[192];
        std::snprintf(buf, sizeof(buf),
                      "hypotheses over %zu mismatches: clear-survived %zu, R/B-swapped %zu, "
                      "v-flipped %zu, h-flipped %zu", bad, clearHits, rbSwapHits, vflipHits,
                      hflipHits);
        Note(buf);
    }
    return bad == 0;
}

bool WriteBmp(const std::string& path, const Image& im) {
    const uint32_t rowBytes = ((im.w * 3 + 3) / 4) * 4;
    const uint32_t pixSize = rowBytes * im.h;
    BITMAPFILEHEADER fh = {};
    BITMAPINFOHEADER ih = {};
    ih.biSize = DWORD(sizeof(ih));
    ih.biWidth = LONG(im.w);
    ih.biHeight = LONG(im.h);  // positive == bottom-up
    ih.biPlanes = 1;
    ih.biBitCount = 24;
    ih.biCompression = BI_RGB;
    fh.bfType = WORD(0x4D42);
    fh.bfOffBits = DWORD(sizeof(fh) + sizeof(ih));
    fh.bfSize = fh.bfOffBits + pixSize;
    std::vector<uint8_t> rows(size_t(pixSize), 0u);
    for (uint32_t y = 0; y < im.h; ++y) {
        uint8_t* dst = &rows[size_t(im.h - 1 - y) * rowBytes];
        for (uint32_t x = 0; x < im.w; ++x) {
            const uint8_t* s = &im.rgba[(size_t(y) * im.w + x) * 4];
            dst[size_t(x) * 3 + 0] = s[2];
            dst[size_t(x) * 3 + 1] = s[1];
            dst[size_t(x) * 3 + 2] = s[0];
        }
    }
    FILE* f = std::fopen(path.c_str(), "wb");
    if (!f) return false;
    std::fwrite(&fh, sizeof(fh), 1, f);
    std::fwrite(&ih, sizeof(ih), 1, f);
    std::fwrite(rows.data(), pixSize, 1, f);
    std::fclose(f);
    return true;
}

bool WriteRaw(const std::string& path, const Image& im) {
    FILE* f = std::fopen(path.c_str(), "wb");
    if (!f) return false;
    std::fwrite(im.rgba.data(), im.rgba.size(), 1, f);
    std::fclose(f);
    return true;
}

LRESULT CALLBACK WndProc(HWND h, UINT m, WPARAM w, LPARAM l) {
    if (m == WM_DESTROY) { PostQuitMessage(0); return 0; }
    return DefWindowProcA(h, m, w, l);
}

// Keep the window pumping so the presented frame is actually composited and visible.
void PumpFor(DWORD ms) {
    const DWORD end = GetTickCount() + ms;
    while (GetTickCount() < end) {
        MSG msg;
        while (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) return;
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }
        Sleep(5);
    }
}

}  // namespace

int main(int argc, char** argv) {
    std::printf("== texture import validator (external; host D3D12 layer) ==\n");
    std::fflush(stdout);

    uint32_t side = 512;
    std::string assetPath;
    for (int i = 1; i < argc; ++i) {
        if (!std::strcmp(argv[i], "--size") && i + 1 < argc)
            side = uint32_t(std::atoi(argv[++i]));
        else if (!std::strcmp(argv[i], "--dds") && i + 1 < argc)
            assetPath = argv[++i];
    }

    HINSTANCE inst = GetModuleHandleA(nullptr);
    WNDCLASSEXA wc = {};
    wc.cbSize = sizeof(wc);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.hInstance = inst;
    wc.hCursor = LoadCursorA(nullptr, IDC_ARROW);
    wc.lpszClassName = "MclaTextureImportValidator";
    RegisterClassExA(&wc);

    RECT r = {0, 0, LONG(side), LONG(side)};
    AdjustWindowRect(&r, WS_OVERLAPPEDWINDOW, FALSE);
    HWND hwnd = CreateWindowExA(WS_EX_APPWINDOW, wc.lpszClassName,
                                "MCLA texture import (external test)", WS_OVERLAPPEDWINDOW,
                                80, 40, r.right - r.left, r.bottom - r.top, nullptr, nullptr,
                                inst, nullptr);
    if (!hwnd) {
        std::printf("CreateWindowExA failed (%lu)\n", GetLastError());
        return 2;
    }
    ShowWindow(hwnd, SW_SHOWNORMAL);

    D3D12Backend be;
    if (!be.Initialize(hwnd, side, side)) {
        std::printf("D3D12Backend::Initialize failed\n");
        return 2;
    }
    ID3D12Device* dev = be.GetDevice();
    Check(dev != nullptr, "backend exposes its device");

    Quad quad;
    Check(MakeQuad(dev, quad), "clip-space quad vertex buffer uploaded");

    const std::vector<uint8_t> vs(kTextureQuadVs, kTextureQuadVs + sizeof(kTextureQuadVs));
    const std::vector<uint8_t> ps(kTextureQuadPs, kTextureQuadPs + sizeof(kTextureQuadPs));
    const std::vector<D3D12_INPUT_ELEMENT_DESC> layout = {
        {"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,
         D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0},
    };
    mcla::renderer::PipelineState state = {};
    state.targetFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM;
    state.sampleCount = 1;
    ComPtr<ID3D12PipelineState> pso;
    const bool madePso = be.CreatePipelineFromDxil(vs, ps, layout, state, pso);
    Check(madePso, "textured PSO built from DXIL against the backend root signature");
    if (!madePso) return 2;

    const Image chartA = MakeChart(side, side, 0);
    const Image chartB = MakeChart(side, side, 1);
    Offscreen off;
    Check(PrepareOffscreen(dev, side, side, off),
          "offscreen render target + staging buffer prepared");

    std::printf("- case 0: baseline, nothing imported (t1 holds a null SRV)\n");
    if (RunCase(be, chartA, pso.Get(), quad, off, false)) {
        const Stats s = Measure(off.packed);
        Note(std::to_string(s.uniqueColors) + " unique colours, " +
             std::to_string(s.nonBlack) + " non-black, " + std::to_string(s.clearLeft) +
             " still the clear colour");
        Check(!ExactMatch(off.packed, chartA),
              "baseline does NOT reproduce the chart, so the compare can really fail");
    } else {
        Check(false, "baseline case ran");
    }

    std::printf("- case 1: chart A through CreateDecodedTexture\n");
    if (RunCase(be, chartA, pso.Get(), quad, off, true)) {
        VerifyExact(off.packed, chartA, "chart A sampled == chart A imported");
        WriteBmp("build/texture_import_chartA.bmp", off.packed);
        WriteRaw("build/texture_import_chartA.rgba", off.packed);
    } else {
        Check(false, "case 1 ran");
    }

    std::printf("- case 2: chart B over the same slot (stale-texture guard)\n");
    if (RunCase(be, chartB, pso.Get(), quad, off, true)) {
        VerifyExact(off.packed, chartB, "chart B sampled == chart B imported");
        Check(!ExactMatch(off.packed, chartA), "case 2 readback differs from case 1");
        WriteBmp("build/texture_import_chartB.bmp", off.packed);
        WriteRaw("build/texture_import_chartB.rgba", off.packed);
    } else {
        Check(false, "case 2 ran");
    }

    if (!assetPath.empty()) {
        std::printf("- case 3: real retail asset %s\n", assetPath.c_str());
        Image asset;
        std::string why;
        if (!LoadDdsMip0AsRgba(assetPath, asset, why)) {
            Check(false, "asset decodes: " + why);
        } else {
            Offscreen ao;
            if (PrepareOffscreen(dev, asset.w, asset.h, ao) &&
                RunCase(be, asset, pso.Get(), quad, ao, true)) {
                VerifyExact(ao.packed, asset,
                            "asset sampled == asset decoded (byte-exact import round trip)");
                const Stats s = Measure(ao.packed);
                Note(std::to_string(s.uniqueColors) + " unique colours, " +
                     std::to_string(s.nonBlack) + "/" +
                     std::to_string(asset.w * asset.h) + " non-black");
                Check(s.uniqueColors > 16 && s.nonBlack > asset.w,
                      "asset readback is non-blank");
                WriteBmp("build/texture_import_asset.bmp", ao.packed);
                WriteRaw("build/texture_import_asset.rgba", ao.packed);
            } else {
                Check(false, "asset case ran");
            }
        }
    }

    std::printf("- window is showing the last imported texture at %ux%u\n", side, side);
    std::fflush(stdout);
    PumpFor(2500);
    be.Shutdown();
    DestroyWindow(hwnd);

    std::printf("== %d passed, %d failed ==\n", g_pass, g_fail);
    std::fflush(stdout);
    return g_fail ? 1 : 0;
}
