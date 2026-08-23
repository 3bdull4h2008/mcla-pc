// Standalone Phase3 validator: vertex_decode + resource_cache.
//
// Usage: phase3_validator.exe <shader-dir>
//
// 1. Unit-exercises DecodeVertexFormat / IndexElementBytes /
//    HashVertexDeclaration and ResourceCache insert/find/eviction/needs-upload.
// 2. Scans every container in <shader-dir> (dual-path input classification
//    per raw_ucode_corpus.h: Rockstar .fxc containers, plus raw Xenia ucode
//    dumps decoded after host->guest endian restore; ASCII disasm companions
//    are skipped and counted), decodes the IR, and records every
//    VFETCH vertexFormat code actually used by the corpus. Verifies that all
//    observed codes decode to a supported VertexFormatDesc.
//
// Exit code 0 = clean, 1 = errors found.

#include "xenos_shader_ir.h"
#include "vertex_decode.h"
#include "resource_cache.h"
#include "test_shaders.h"
#include "grc_fvf_decode.h"
#include "raw_ucode_corpus.h"

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <map>
#include <set>
#include <string>
#include <vector>

namespace fs = std::filesystem;
using namespace mcla::renderer;
using namespace mcla::native;

static std::vector<uint8_t> ReadFile(const fs::path& path, bool& ok) {
    std::vector<uint8_t> data;
    ok = false;
    FILE* f = std::fopen(path.string().c_str(), "rb");
    if (!f) return data;
    std::fseek(f, 0, SEEK_END);
    long sz = std::ftell(f);
    std::fseek(f, 0, SEEK_SET);
    if (sz > 0) {
        data.resize(size_t(sz));
        if (std::fread(data.data(), 1, size_t(sz), f) != size_t(sz)) {
            std::fclose(f);
            data.clear();
            return data;
        }
    }
    std::fclose(f);
    ok = true;
    return data;
}

static bool ExerciseVertexFetchConstant() {
    bool ok = true;
    // zero entry -> isZero, not valid.
    {
        uint8_t p[8] = {0, 0, 0, 0, 0, 0, 0, 0};
        VertexFetchConstant fc = DecodeVertexFetchConstant(p);
        if (!fc.isZero || fc.valid) { std::printf("  !! zero slot must be isZero\n"); ok = false; }
    }
    // w0 address=0x1000 dwords (0x4000 bytes), word1 endian=2, size=0x20 words
    {
        uint32_t addrDwords = 0x1000;      // 4096 dwords = 16384 bytes
        uint8_t p[8];
        uint32_t w0 = (0u << 30) | (addrDwords & 0x3FFFFFFF);
        uint32_t w1 = (2u << 30) | (0x20u << 6);   // endian=2, size=32 words
        p[0] = uint8_t(w0 >> 24); p[1] = uint8_t(w0 >> 16);
        p[2] = uint8_t(w0 >> 8);  p[3] = uint8_t(w0);
        p[4] = uint8_t(w1 >> 24); p[5] = uint8_t(w1 >> 16);
        p[6] = uint8_t(w1 >> 8);  p[7] = uint8_t(w1);
        VertexFetchConstant fc = DecodeVertexFetchConstant(p);
        if (!fc.valid) { std::printf("  !! non-zero entry must decode valid\n"); ok = false; }
        if (fc.addressBytes != 0x4000) { std::printf("  !! addressBytes=%u != 16384\n", fc.addressBytes); ok = false; }
        if (fc.addressType != 0) { std::printf("  !! addressType=%u != 0\n", fc.addressType); ok = false; }
        if (fc.endian != 2) { std::printf("  !! endian=%u != 2\n", fc.endian); ok = false; }
        if (fc.sizeWords != 0x20) { std::printf("  !! sizeWords=%u != 0x20\n", fc.sizeWords); ok = false; }
    }
    // size=0 but address set -> not valid (0-size stream).
    {
        uint8_t p[8] = {0, 0, 0x10, 0, 0, 0, 0, 0};
        VertexFetchConstant fc = DecodeVertexFetchConstant(p);
        if (fc.valid) { std::printf("  !! zero-size stream must not be valid\n"); ok = false; }
    }
    // Ensure decoding is big-endian independent of host endianness.
    {
        uint8_t p[8] = {0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00}; // addr 0x1000 dwords
        VertexFetchConstant fc = DecodeVertexFetchConstant(p);
        if (fc.addressBytes != 0x4000) { std::printf("  !! BE decode host-independent mismatch\n"); ok = false; }
    }
    return ok;
}

static bool ExerciseVertexDecode() {
    bool ok = true;

    // Known-good formats: total byte sizes must be sane and non-zero.
    static const uint32_t kGood[] = {6, 7, 16, 17, 25, 26, 31, 32, 33, 34, 35, 36, 37, 38, 57};
    for (uint32_t vf : kGood) {
        VertexFormatDesc d = DecodeVertexFormat(vf);
        if (!d.valid || d.totalBytes == 0 || d.componentCount == 0) {
            std::printf("  !! vf=%u not decoded\n", vf);
            ok = false;
        }
        if (d.dxgiFormat == 0) {
            std::printf("  !! vf=%u missing DXGI format\n", vf);
            ok = false;
        }
    }

    // Unknown / unsupported codes must be rejected.
    for (uint32_t vf : {0u, 1u, 3u, 63u, 100u}) {
        if (DecodeVertexFormat(vf).valid) {
            std::printf("  !! vf=%u should be unsupported\n", vf);
            ok = false;
        }
    }

    // Index byte sizes.
    if (IndexElementBytes(0) != 2 || IndexElementBytes(1) != 4 || IndexElementBytes(2) != 0) {
        std::printf("  !! IndexElementBytes wrong\n");
        ok = false;
    }

    // DecodeVertexFetch: vf=0 flags fetch-constant-relative layout. The
    // hardware descriptor slot for const_index=31, const_index_select=2 is
    // 31*3+2 = 95 (fetch-constant block of 96 two-dword entries).
    {
        VertexFormatDesc d = DecodeVertexFetch(0, 31, 2);
        if (!d.fromFetchConstant || d.fetchConstantIndex != 95 || d.fetchConstantSelect != 2) {
            std::printf("  !! DecodeVertexFetch should resolve (vf=0,const=31,sel=2) to slot 95\n");
            ok = false;
        }
        VertexFormatDesc d1 = DecodeVertexFetch(0, 31);  // sel unknown => slot 93
        if (!d1.fromFetchConstant || d1.fetchConstantIndex != 93) {
            std::printf("  !! DecodeVertexFetch default sel should give slot 93\n");
            ok = false;
        }
        VertexFormatDesc d2 = DecodeVertexFetch(36, 7);
        if (d2.fromFetchConstant || !d2.valid || d2.type != VertexType::Float32) {
            std::printf("  !! DecodeVertexFetch(36) should decode as float32, not fetch-constant\n");
            ok = false;
        }
    }
    // Declaration hash: deterministic, and unsupported element => 0.
    uint32_t vf[3] = {36, 37, 32};  // position float3, texcoord float2, color byte4
    uint8_t usage[3] = {0, 3, 4};   // POSITION, TEXCOORD, COLOR
    uint8_t idx[3] = {0, 0, 0};
    uint64_t h1 = HashVertexDeclaration(vf, usage, idx, 3);
    uint64_t h2 = HashVertexDeclaration(vf, usage, idx, 3);
    if (h1 == 0 || h1 != h2) { std::printf("  !! vertex decl hash nondeterministic/zero\n"); ok = false; }
    if (HashVertexDeclaration(vf, usage, idx, 3) == HashVertexDeclaration(vf, usage, idx, 2)) {
        std::printf("  !! vertex decl hash ignores element count\n");
        ok = false;
    }
    uint32_t bad[1] = {63};
    if (HashVertexDeclaration(bad, usage, idx, 1) != 0) {
        std::printf("  !! unsupported element should hash to 0\n");
        ok = false;
    }

    return ok;
}

static bool ExerciseGrcFvfDecode() {
    bool ok = true;
    auto fail = [&ok](const char* what) {
        std::printf("  !! %s\n", what);
        ok = false;
    };

    // ---- Fixture 1: MCLA1-style 16-channel declaration.
    // types = 0xAA1111111199A996 stored big-endian (bytes AA 11 11 11 11 99
    // A9 96); lanes 0-15 bound. Type codes (4-bit, LSB-first over the BE
    // u64): ch0 Float3(6), ch1/2/4/5 Colour(9), ch3/14/15 Dec3N(A),
    // ch6..13 Half2(1). Sizes 12+4+4+4+4+4 + 8*4 + 4 + 4 = 72 -> fvfSize 72.
    {
        GrcFvfDesc desc{};
        desc.fvfMask = 0x0000FFFF;
        desc.fvfSize = 72;
        desc.flags = 0;
        desc.dynamicOrder = 0;
        desc.channelCount = 16;
        const uint8_t t[8] = {0xAA, 0x11, 0x11, 0x11, 0x11, 0x99, 0xA9, 0x96};
        desc.types = 0;
        for (int i = 0; i < 8; ++i) desc.types |= uint64_t(t[i]) << (56 - 8 * i);

        GrcFvfDeclaration d = DecodeGrcFvf(desc);
        if (!d.valid || d.unknownChannel) fail("fixture1 must decode valid");
        if (d.computedStride != 72 || d.sizeMismatch) fail("fixture1 stride mismatch");
        if (d.countMismatch || d.channelCount != 16) fail("fixture1 count mismatch");

        // Semantic/type/offset per lane (offsets: ch0@0, ch1@12, ch2@16,
        // ch3@20, ch4@24, ch5@28, ch6..13@32..60, ch14@64, ch15@68).
        if (d.channels[0].type != 6 || d.channels[0].dxgiFormat != 6 /*R32G32B32_FLOAT*/
            || d.channels[0].byteOffset != 0 || d.channels[0].usage != 0 || d.channels[0].usageIndex != 0)
            fail("fixture1 ch0 Position/Float3");
        if (d.channels[3].type != 10 /*Dec3N*/ || d.channels[3].dxgiFormat != 24
            || d.channels[3].byteOffset != 20 || d.channels[3].usage != 3)
            fail("fixture1 ch3 Normal/Dec3N");
        if (d.channels[4].usage != 10 || d.channels[4].usageIndex != 0
            || d.channels[4].dxgiFormat != 28 || d.channels[4].byteOffset != 24)
            fail("fixture1 ch4 Colour0");
        if (d.channels[5].usageIndex != 1) fail("fixture1 ch5 Colour1");
        if (d.channels[6].usage != 5 || d.channels[6].usageIndex != 0
            || d.channels[6].dxgiFormat != 34 || d.channels[6].byteOffset != 32)
            fail("fixture1 ch6 TexCoord0/Half2");
        if (d.channels[14].usage != 6 || d.channels[14].usageIndex != 0
            || d.channels[14].dxgiFormat != 24 || d.channels[14].byteOffset != 64)
            fail("fixture1 ch14 Tangent0/Dec3N");
        if (d.channels[15].usageIndex != 1 || d.channels[15].byteOffset != 68)
            fail("fixture1 ch15 Tangent1");
        if (d.channels[17].present) fail("fixture1 lane17 must not be present");

        GrcFvfLayoutEntry layout[18];
        uint32_t n = 0;
        if (!BuildGrcFvfLayout(d, layout, n) || n != 16) fail("fixture1 layout count");
        if (layout[0].usage != 0 || layout[0].byteOffset != 0 || layout[0].dxgiFormat != 6)
            fail("fixture1 layout[0]");
        if (layout[15].usage != 6 || layout[15].usageIndex != 1 || layout[15].byteOffset != 68)
            fail("fixture1 layout[15]");
        // Layout must be ascending by byte offset.
        for (uint32_t i = 1; i < n; ++i)
            if (layout[i].byteOffset <= layout[i - 1].byteOffset) fail("fixture1 layout not ascending");
    }

    // ---- Fixture 2: PNCT-ish declaration, mask 0x40C9 (lanes 0,3,6,7,14):
    // ch0 Float3(6), ch3 Dec3N(A), ch6/7 Half2(1), ch14 Float4(7).
    // t[0]=0x07 -> lane14 Float4 (low nibble), t[4]=0x11 -> lanes 6/7 Half2,
    // t[6]=0xA0 -> lane3 Dec3N (high nibble), t[7]=0x06 -> lane0 Float3.
    // Sizes 12+4+4+4+16 = 40 -> fvfSize 40.
    {
        GrcFvfDesc desc{};
        desc.fvfMask = 0x40C9;  // bits 0,3,6,7,14
        desc.fvfSize = 40;
        desc.channelCount = 5;
        const uint8_t t[8] = {0x07, 0x00, 0x00, 0x00, 0x11, 0x00, 0xA0, 0x06};
        desc.types = 0;
        for (int i = 0; i < 8; ++i) desc.types |= uint64_t(t[i]) << (56 - 8 * i);

        GrcFvfDeclaration d = DecodeGrcFvf(desc);
        if (!d.valid || d.unknownChannel || d.countMismatch) fail("fixture2 must decode valid");
        if (d.channelCount != 5 || d.computedStride != 40 || d.sizeMismatch)
            fail("fixture2 count/stride mismatch");
        if (d.channels[0].byteOffset != 0 || d.channels[3].byteOffset != 12)
            fail("fixture2 offsets");
        if (d.channels[14].type != 7 || d.channels[14].dxgiFormat != 2 /*R32G32B32A32_FLOAT*/
            || d.channels[14].byteOffset != 24 || d.channels[14].usage != 6)
            fail("fixture2 ch14 Tangent/Float4");
    }

    // ---- Fixture 3: bound lane with an unverified type code (4 FloatUnk)
    // must decode unknown and be refused for layout building.
    {
        GrcFvfDesc desc{};
        desc.fvfMask = 0x1;
        desc.fvfSize = 4;
        desc.channelCount = 1;
        desc.types = 0x4;  // nibble0 = FloatUnk
        GrcFvfDeclaration d = DecodeGrcFvf(desc);
        if (d.valid || !d.unknownChannel) fail("fixture3 unknown type must be refused");
        GrcFvfLayoutEntry layout[18];
        uint32_t n = 99;
        if (BuildGrcFvfLayout(d, layout, n)) fail("fixture3 layout must not build");
        if (n != 0) fail("fixture3 layout count must stay 0");
    }

    // ---- Fixture 4: stored channelCount inconsistent with the mask is an
    // informational mismatch, not a validity failure.
    {
        GrcFvfDesc desc{};
        desc.fvfMask = 0x1;
        desc.fvfSize = 12;
        desc.channelCount = 3;  // wrong; popcount is 1
        desc.types = 0x6;       // nibble0 = Float3
        GrcFvfDeclaration d = DecodeGrcFvf(desc);
        if (!d.valid || !d.countMismatch) fail("fixture4 count mismatch must be informational");
        if (d.channelCount != 1) fail("fixture4 canonical count must be popcount");
    }

    // ---- Fixture 5: hash determinism, distinctness, sensitivity.
    {
        GrcFvfDesc desc{};
        desc.fvfMask = 0x0000FFFF;
        desc.fvfSize = 72;
        desc.channelCount = 16;
        const uint8_t t[8] = {0xAA, 0x11, 0x11, 0x11, 0x11, 0x99, 0xA9, 0x96};
        desc.types = 0;
        for (int i = 0; i < 8; ++i) desc.types |= uint64_t(t[i]) << (56 - 8 * i);

        GrcFvfDeclaration a = DecodeGrcFvf(desc);
        GrcFvfDeclaration b = DecodeGrcFvf(desc);
        uint64_t h1 = HashGrcFvfDeclaration(a);
        if (h1 == 0 || h1 != HashGrcFvfDeclaration(b)) fail("fixture5 hash nondeterministic/zero");
        GrcFvfDesc desc2 = desc;
        desc2.types ^= 0x1;  // flip ch0's LSB type bit
        GrcFvfDeclaration c = DecodeGrcFvf(desc2);
        if (HashGrcFvfDeclaration(c) == h1) fail("fixture5 hash insensitive to types");
        if (c.channels[0].type == a.channels[0].type) fail("fixture5 types bit not decoded");
    }

    // ---- Fixture 6: presence is mask-gated; a type code on an unbound lane
    // is ignored. mask 0x11 (lanes 0,4), ch3 type 6 but lane 3 not bound.
    {
        GrcFvfDesc desc{};
        desc.fvfMask = 0x11;
        desc.fvfSize = 16;
        desc.channelCount = 2;
        desc.types = 0x96006;  // nibble0=6, nibble3=6, nibble4=9
        GrcFvfDeclaration d = DecodeGrcFvf(desc);
        if (!d.valid || d.unknownChannel || d.countMismatch) fail("fixture6 must decode valid");
        if (!d.channels[0].present || d.channels[0].type != 6) fail("fixture6 ch0 present");
        if (d.channels[3].present) fail("fixture6 unbound lane3 must be absent");
        if (!d.channels[4].present || d.channels[4].type != 9
            || d.channels[4].byteOffset != 12 || d.channels[4].usage != 10)
            fail("fixture6 ch4 Colour@12");
        if (d.computedStride != 16 || d.sizeMismatch) fail("fixture6 stride");
    }

    // ---- Fixture 7: bound Binormal lane (16) has no type bits in the u64
    // and must be refused (no UB, no invented format). mask 0x10000, lane 16.
    {
        GrcFvfDesc desc{};
        desc.fvfMask = 0x10000;  // bit 16
        desc.fvfSize = 4;
        desc.channelCount = 1;
        desc.types = 0;
        GrcFvfDeclaration d = DecodeGrcFvf(desc);
        if (d.valid || !d.unknownChannel) fail("fixture7 lane16 must refuse");
        if (!d.channels[16].present) fail("fixture7 lane16 marked present");
        if (d.channels[16].usage != 7 || d.channels[16].usageIndex != 0)
            fail("fixture7 lane16 Binormal0 semantic");
        if (d.sizeMismatch) fail("fixture7 lane16 must not size-mismatch (0 bytes)");
        GrcFvfLayoutEntry layout[18];
        uint32_t n = 99;
        if (BuildGrcFvfLayout(d, layout, n)) fail("fixture7 layout must not build");
        if (n != 0) fail("fixture7 layout count must stay 0");
    }

    // ---- Fixture 8: bound lane with type Nothing (code 0) is refused: the
    // u64 nibble exists but the type corroborates no size/format, so an
    // invented layout would violate Golden Rule 5.
    {
        GrcFvfDesc desc{};
        desc.fvfMask = 0x1;     // lane 0
        desc.fvfSize = 12;
        desc.channelCount = 1;
        desc.types = 0x0;       // nibble0 = 0 (Nothing)
        GrcFvfDeclaration d = DecodeGrcFvf(desc);
        if (d.valid || !d.unknownChannel) fail("fixture8 code-0 lane must refuse");
        if (!d.channels[0].present) fail("fixture8 lane0 present");
        if (d.sizeMismatch || d.countMismatch) fail("fixture8 must not flag size/count");
        if (d.channelCount != 1) fail("fixture8 canonical count must be popcount");
    }

    // ---- Fixture 9: bound lane with each unverified code (2, 4, 11-15) is
    // refused. Coverage uses one mask bit (lane 0) and toggles the nibble
    // across all six codes.
    {
        const uint8_t unkCodes[] = {2, 4, 11, 12, 13, 14, 15};
        for (uint8_t code : unkCodes) {
            GrcFvfDesc desc{};
            desc.fvfMask = 0x1;
            desc.fvfSize = 4;
            desc.channelCount = 1;
            desc.types = static_cast<uint64_t>(code);
            GrcFvfDeclaration d = DecodeGrcFvf(desc);
            if (d.valid || !d.unknownChannel)
                fail("fixture9 unverified code must refuse");
            if (d.channels[0].type != code) fail("fixture9 type bit echoed");
        }
    }

    return ok;
}

static bool ExerciseTestShaderBlobs() {
    bool ok = true;

    // DXBC magic: 'DXBC' little-endian = 0x43425844.
    constexpr uint32_t kDxbcMagic = 0x43425844;
    const auto* vs = static_cast<const uint8_t*>(GetTestVsBlob());
    const auto* ps = static_cast<const uint8_t*>(GetTestPsBlob());

    if (GetTestVsBlobSize() < 4 || *reinterpret_cast<const uint32_t*>(vs) != kDxbcMagic) {
        std::printf("  !! VS blob is not a valid DXBC/DXIL container\n");
        ok = false;
    }
    if (GetTestPsBlobSize() < 4 || *reinterpret_cast<const uint32_t*>(ps) != kDxbcMagic) {
        std::printf("  !! PS blob is not a valid DXBC/DXIL container\n");
        ok = false;
    }
    // Deterministic size across the embedded arrays.
    if (GetTestVsBlobSize() != sizeof(kTestVsBlob) ||
        GetTestPsBlobSize() != sizeof(kTestPsBlob)) {
        std::printf("  !! blob size accessors disagree with array size\n");
        ok = false;
    }

    // The backend's test draw uses IndexElementBytes(0) == 2 (R16_UINT) for the
    // index buffer; verify vertex_decode reports the same so the two never
    // diverge silently.
    if (IndexElementBytes(0) != 2) {
        std::printf("  !! indexType=0 must be 16-bit (2 bytes) to match test PSO R16_UINT\n");
        ok = false;
    }

    // Upload-arena alignment math mirrors D3D12_TEXTURE_DATA_PITCH_ALIGNMENT.
    {
        size_t offset = 0;
        auto alignUp = [&](size_t v) { return (v + 255) & ~size_t(255); };
        (void)alignUp;
        offset = alignUp(offset + static_cast<size_t>(3 * sizeof(float) + 4 * sizeof(float)));  // 28 -> 256
        if (offset != 256) { std::printf("  !! upload arena alignment mismatch (%zu)\n", offset); ok = false; }
    }

    return ok;
}

static bool ExerciseResourceCache() {
    bool ok = true;
    ResourceCache cache(3);

    ResourceKey k1{ResourceKind::Buffer, 0x1000, 1024, 0, 1};
    ResourceKey k1v2 = k1; k1v2.dataVersion = 2;
    ResourceKey k2{ResourceKind::Texture, 0x2000, 4096, 79, 1};
    ResourceKey k3{ResourceKind::RenderTarget, 0x3000, 0, 2, 0};

    cache.Insert(k1, ResourceEntry{10, 1, false});
    cache.Insert(k2, ResourceEntry{20, 1, false});
    cache.Insert(k3, ResourceEntry{30, 0, true});
    cache.Insert(ResourceKey{ResourceKind::Buffer, 0x4000, 64, 0, 1}, ResourceEntry{40, 1, false}); // evicts k1

    ResourceEntry e;
    if (cache.Find(k1, e)) { std::printf("  !! evicted key still present\n"); ok = false; }
    if (!cache.Find(k2, e) || e.handle != 20) { std::printf("  !! k2 lookup failed\n"); ok = false; }
    if (!cache.Find(k3, e) || !e.isRenderTarget) { std::printf("  !! k3 lookup failed\n"); ok = false; }
    if (cache.Size() != 3) { std::printf("  !! cache size %zu != 3\n", cache.Size()); ok = false; }

    // needs-upload semantics.
    if (!cache.NeedsUpload(k1v2)) { std::printf("  !! should need upload after version bump\n"); ok = false; }
    if (cache.NeedsUpload(k2)) { std::printf("  !! k2 should not need upload\n"); ok = false; }

    // Update-in-place.
    cache.Insert(k2, ResourceEntry{99, 1, false});
    if (!cache.Find(k2, e) || e.handle != 99) { std::printf("  !! insert-update failed\n"); ok = false; }

    // Different format/layout -> different key even if same address.
    ResourceKey k1b = k1; k1b.formatLayout = 5;
    cache.Insert(k1b, ResourceEntry{55, 1, false});
    if (!cache.Find(k1b, e) || e.handle != 55) { std::printf("  !! format-distinct key collision\n"); ok = false; }

    return ok;
}

int main(int argc, char** argv) {
    std::setvbuf(stdout, nullptr, _IONBF, 0);
    if (argc < 2) {
        std::printf("Usage: %s <shader-dir>\n", argv[0]);
        return 2;
    }
    const fs::path root = argv[1];
    if (!fs::is_directory(root)) {
        std::printf("not a directory: %s\n", root.string().c_str());
        return 2;
    }

    bool vdOk = ExerciseVertexDecode();
    bool fOk = ExerciseVertexFetchConstant();
    bool rcOk = ExerciseResourceCache();
    bool shOk = ExerciseTestShaderBlobs();
    bool gfOk = ExerciseGrcFvfDecode();

    // Scan corpus for used vf codes.
    std::map<uint32_t, uint64_t> vfUsage;
    std::map<uint32_t, uint64_t> constIndexUsage;
    std::map<uint32_t, uint64_t> strideUsage;
    std::map<bool, uint64_t> miniUsage;
    std::set<uint32_t> unsupported;
    uint64_t containers = 0, fetchInstrs = 0, fetchConstantRel = 0;
    // Raw-ucode corpus path (Xenia dumps; no container metadata).
    uint64_t rawPrograms = 0, rawOobExecs = 0, rawUnknownInstrs = 0;
    uint64_t textDisasmSkipped = 0;
    // Container-proven vs raw-observed stream-binding evidence (Rev 04): the
    // fetch-constant DESCRIPTORS backing vf=0 slots live in guest memory and
    // are absent from raw microcode dumps, so stream-binding proof is only
    // possible for container-parsed programs (they carry the guest tables).
    std::map<uint32_t, uint64_t> containerFetchSlotUsage;
    std::map<uint32_t, uint64_t> rawFetchSlotUsage;
    uint64_t containerFetchInstrs = 0, containerFetchConstRel = 0;
    uint64_t containerMiniFetches = 0;

    // Stream-binding classification (Rev 03): the offline corpus can only prove
    // HOW MANY vertex streams and WHICH fetch-constant slot the shaders bind; it
    // cannot recover format/stride (that lives in the captured drawable grcFvf).
    // Assert the corpus is single-stream so the capture path knows a VB layout
    // for every draw must come from the guest declaration, never from here.
    std::map<uint32_t, uint64_t> fetchConstantSlotUsage;

    // VFETCH usage recording, shared by the .fxc-container path and the
    // raw-microcode path (identical IR shape: prog.instructions).
    auto recordFetches = [&](const ShaderProgram& prog, bool fromContainer) {
        for (const auto& ir : prog.instructions) {
            if (ir.decoded.kind != InstructionKind::VertexFetch) continue;
            fetchInstrs++;
            uint32_t vf = ir.decoded.vertexFormat & 0x3F;
            VertexFormatDesc vfd = DecodeVertexFetch(vf, ir.decoded.constIndex,
                                                     ir.decoded.constIndexSelect);
            vfUsage[vf]++;
            strideUsage[ir.decoded.stride]++;
            miniUsage[ir.decoded.isMiniFetch]++;
            if (vfd.valid || vfd.fromFetchConstant) {
                fetchConstantRel++;
            } else {
                unsupported.insert(vf);
            }
            // Also record fetch-constant slot use (MCLA vertex fetch is
            // constant-relative: format/stride live in the fetch-constant
            // descriptor, not the VFETCH instruction).
            const uint32_t slot = vfd.fromFetchConstant
                                      ? vfd.fetchConstantIndex
                                      : (ir.decoded.constIndex & 0x1F);
            constIndexUsage[slot]++;
            fetchConstantSlotUsage[slot]++;
            if (fromContainer) {
                ++containerFetchInstrs;
                if (vfd.valid || vfd.fromFetchConstant) ++containerFetchConstRel;
                ++containerFetchSlotUsage[slot];
                if (ir.decoded.isMiniFetch) ++containerMiniFetches;
            } else {
                ++rawFetchSlotUsage[slot];
            }
        }
    };

    // Stream-binding classification (Rev 03): the offline corpus can only prove
    // HOW MANY vertex streams and WHICH fetch-constant slot the shaders bind; it
    // cannot recover format/stride (that lives in the captured drawable grcFvf).
    // Assert the corpus is single-stream so the capture path knows a VB layout
    // for every draw must come from the guest declaration, never from here.
    for (const auto& entry : fs::recursive_directory_iterator(root)) {
        if (!entry.is_regular_file()) continue;
        if (entry.path().extension() == ".list") continue;
        bool ok = false;
        std::vector<uint8_t> data = ReadFile(entry.path(), ok);
        if (!ok) continue;
        const std::string pathStr = entry.path().string();
        // Xenia ucode binary dumps hold host-endian dwords (Shader::DumpUcode
        // writes them verbatim); restore guest-BE before classification/decode.
        if (corpus::PathContains(pathStr, ".ucode.bin.")) {
            corpus::RestoreGuestEndianDwords(data);
        }
        // Dual-path input classification: .fxc containers -> container parse;
        // raw microcode dumps -> shared raw decode; text disasms -> counted
        // skip; compiled .d3d12.bin.* companions -> ignored.
        const corpus::InputClass cls =
            corpus::ClassifyCorpusFile(pathStr, data.data(), data.size());
        if (cls == corpus::InputClass::Ignore) continue;
        if (cls == corpus::InputClass::TextDisasm) {
            textDisasmSkipped++;
            continue;
        }
        if (cls == corpus::InputClass::RawMicrocode) {
            ShaderProgram prog;
            prog.isVertex = corpus::IsVertexDumpName(pathStr);
            const corpus::RawDecodeStats st =
                corpus::DecodeRawMicrocode(data.data(), data.size(), prog);
            rawPrograms++;
            rawOobExecs += st.oobExecs;
            rawUnknownInstrs += st.unknownInstrs;
            recordFetches(prog, false);
            continue;
        }
        VisitShaderContainers(data.data(), data.size(), [&](size_t off) {
            const size_t vsize = AssembleBE32(data.data() + off + 4);
            const size_t psize = AssembleBE32(data.data() + off + 8);
            ShaderProgram prog;
            if (!ParseShaderProgram(data.data() + off, vsize + psize, prog)) return true;
            containers++;
            recordFetches(prog, true);
            return true;
        });
    }
    std::printf("vertex_decode_test=%s  fetch_constant_test=%s  resource_cache_test=%s  test_shader_blobs=%s  grc_fvf_decode_test=%s\n",
                vdOk ? "ok" : "FAIL", fOk ? "ok" : "FAIL", rcOk ? "ok" : "FAIL", shOk ? "ok" : "FAIL", gfOk ? "ok" : "FAIL");
    std::printf("corpus: containers=%llu vertex_fetches=%llu used_vf_codes=%zu unsupported_codes=%zu\\n",
                (unsigned long long)containers, (unsigned long long)fetchInstrs,
                vfUsage.size(), unsupported.size());
    std::printf("  fetch_constant_relative=%llu (vf=0 resolved from guest fetch-constant descriptor)\\n",
                (unsigned long long)fetchConstantRel);
    std::printf("raw_ucode: programs=%llu oob=%llu unknown=%llu text_skipped=%llu\\n",
                (unsigned long long)rawPrograms, (unsigned long long)rawOobExecs,
                (unsigned long long)rawUnknownInstrs, (unsigned long long)textDisasmSkipped);
    std::printf("vf_code_histogram:\n");
    for (auto& [vf, count] : vfUsage) {
        const char* status = DecodeVertexFormat(vf).valid ? "supported"
                              : (DecodeVertexFetch(vf, 31).fromFetchConstant ? "fetch_const" : "UNSUPPORTED");
        std::printf("  vf=%-3u (%-14s) count=%-8llu %s\n", vf, VertexFormatName(vf),
                    (unsigned long long)count, status);
    }
    std::printf("fetch_constant_index_histogram (merged descriptor slot const*3+sel of each VFETCH):\n");
    for (auto& [idx, count] : constIndexUsage) {
        std::printf("  const[%u] count=%llu\n", idx, (unsigned long long)count);
    }
    std::printf("stride_histogram (VFETCH instruction stride field):\n");
    for (auto& [s, count] : strideUsage) {
        std::printf("  stride[%u] count=%llu\n", s, (unsigned long long)count);
    }
    std::printf("mini_fetch_histogram:\n");
    for (auto& [mini, count] : miniUsage) {
        std::printf("  %s count=%llu\n", mini ? "mini" : "full", (unsigned long long)count);
    }

    // Rev 03 stream-binding classification: every vertex fetch in the corpus
    // must resolve to exactly one fetch-constant slot bound to stream input.
    // If that holds, each captured draw needs a VB layout that can ONLY come
    // from the guest drawable's run-time vertex declaration (grcFvf); the
    // shader/descriptor supplies address+size only. Any multi-slot or non-fetch
    //-constant fetch would mean a different (offline-recoverable) layout and
    // must be reported, not assumed.
    // Rev 04 (raw-ucode corpus): the descriptors backing vf=0 slots are guest
    // memory, not part of microcode dumps, so the single-stream PROOF is only
    // possible for container-parsed programs. The hard assertion therefore
    // applies to the container sub-corpus only (identical semantics when a
    // container corpus is scanned); raw-dump slot observations are reported
    // below as evidence - recorded, never invented, never asserted.
    const uint64_t distinctSlots = fetchConstantSlotUsage.size();
    const bool containerBindingProven = containerFetchInstrs > 0;
    bool singleStream = !containerBindingProven ||
                        (containerFetchSlotUsage.size() == 1 &&
                         containerMiniFetches == 0);
    // Gating: only slots that are provably fetch-constant-relative count as a
    // single bound stream. vf=0 => fetchConstantRel==fetchInstrs.
    bool allFetchConstant = !containerBindingProven ||
                            (containerFetchConstRel == containerFetchInstrs);
    std::printf("stream_binding_classification:\n");
    std::printf("  distinct_fetch_constant_slots=%llu  vertex_fetches=%llu  fetch_constant_relative=%llu\n",
                (unsigned long long)distinctSlots, (unsigned long long)fetchInstrs,
                (unsigned long long)fetchConstantRel);
    if (containerBindingProven) {
        std::printf("  container_fetches=%llu fetch_constant_relative=%llu distinct_container_slots=%llu\n",
                    (unsigned long long)containerFetchInstrs,
                    (unsigned long long)containerFetchConstRel,
                    (unsigned long long)containerFetchSlotUsage.size());
        std::printf("  single_stream=%s  (all fetches resolve to one slot, full-rate, layout must come from guest grcFvf)\n",
                    (singleStream && allFetchConstant) ? "TRUE" : "FALSE");
    } else {
        std::printf("  container_proven=false (no .fxc containers in scan dir; "
                    "single-stream assertion N/A without guest descriptors)\n");
    }
    if (!rawFetchSlotUsage.empty()) {
        std::printf("raw_stream_binding_observation (informational; descriptors unavailable):\n");
        for (auto& [slot, count] : rawFetchSlotUsage) {
            std::printf("  slot[%u] count=%llu\n", slot, (unsigned long long)count);
        }
    }

    bool allOk = vdOk && fOk && rcOk && shOk && gfOk && unsupported.empty() &&
                 singleStream && allFetchConstant;
    std::printf("RESULT: %s\n", allOk ? "CLEAN" : "ISSUES FOUND");
    return allOk ? 0 : 1;
}
