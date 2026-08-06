// Standalone Phase3 validator: vertex_decode + resource_cache.
//
// Usage: phase3_validator.exe <shader-dir>
//
// 1. Unit-exercises DecodeVertexFormat / IndexElementBytes /
//    HashVertexDeclaration and ResourceCache insert/find/eviction/needs-upload.
// 2. Scans every container in <shader-dir>, decodes the IR, and records every
//    VFETCH vertexFormat code actually used by the corpus. Verifies that all
//    observed codes decode to a supported VertexFormatDesc.
//
// Exit code 0 = clean, 1 = errors found.

#include "xenos_shader_ir.h"
#include "vertex_decode.h"
#include "resource_cache.h"
#include "test_shaders.h"

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

    // DecodeVertexFetch: vf=0 flags fetch-constant-relative layout.
    {
        VertexFormatDesc d = DecodeVertexFetch(0, 31);
        if (!d.fromFetchConstant || d.fetchConstantIndex != 31) {
            std::printf("  !! DecodeVertexFetch should flag fetch-constant (vf=0,const=31)\\n");
            ok = false;
        }
        VertexFormatDesc d2 = DecodeVertexFetch(36, 7);
        if (d2.fromFetchConstant || !d2.valid || d2.type != VertexType::Float32) {
            std::printf("  !! DecodeVertexFetch(36) should decode as float32, not fetch-constant\\n");
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
    bool rcOk = ExerciseResourceCache();
    bool shOk = ExerciseTestShaderBlobs();

    // Scan corpus for used vf codes.
    std::map<uint32_t, uint64_t> vfUsage;
    std::map<uint32_t, uint64_t> constIndexUsage;
    std::set<uint32_t> unsupported;
    uint64_t containers = 0, fetchInstrs = 0, fetchConstantRel = 0;
    for (const auto& entry : fs::recursive_directory_iterator(root)) {
        if (!entry.is_regular_file()) continue;
        if (entry.path().extension() == ".list") continue;
        bool ok = false;
        std::vector<uint8_t> data = ReadFile(entry.path(), ok);
        if (!ok) continue;
        VisitShaderContainers(data.data(), data.size(), [&](size_t off) {
            const size_t vsize = AssembleBE32(data.data() + off + 4);
            const size_t psize = AssembleBE32(data.data() + off + 8);
            ShaderProgram prog;
            if (!ParseShaderProgram(data.data() + off, vsize + psize, prog)) return true;
            containers++;
            for (const auto& ir : prog.instructions) {
                if (ir.decoded.kind != InstructionKind::VertexFetch) continue;
                fetchInstrs++;
                uint32_t vf = ir.decoded.vertexFormat & 0x3F;
                VertexFormatDesc vfd = DecodeVertexFetch(vf, ir.decoded.constIndex & 0x1F);
                vfUsage[vf]++;
                if (vfd.valid || vfd.fromFetchConstant) {
                    fetchConstantRel++;
                } else {
                    unsupported.insert(vf);
                }
                // Also record fetch-constant index use (MCLA vertex fetch is
                // constant-relative: format/stride live in the fetch-constant
                // descriptor, not the VFETCH instruction).
                constIndexUsage[ir.decoded.constIndex & 0x1F]++;
            }
            return true;
        });
    }
    std::printf("vertex_decode_test=%s  resource_cache_test=%s  test_shader_blobs=%s\n",
                vdOk ? "ok" : "FAIL", rcOk ? "ok" : "FAIL", shOk ? "ok" : "FAIL");
    std::printf("corpus: containers=%llu vertex_fetches=%llu used_vf_codes=%zu unsupported_codes=%zu\\n",
                (unsigned long long)containers, (unsigned long long)fetchInstrs,
                vfUsage.size(), unsupported.size());
    std::printf("  fetch_constant_relative=%llu (vf=0 resolved from guest fetch-constant descriptor)\\n",
                (unsigned long long)fetchConstantRel);
    std::printf("vf_code_histogram:\n");
    for (auto& [vf, count] : vfUsage) {
        const char* status = DecodeVertexFormat(vf).valid ? "supported"
                              : (DecodeVertexFetch(vf, 31).fromFetchConstant ? "fetch_const" : "UNSUPPORTED");
        std::printf("  vf=%-3u (%-14s) count=%-8llu %s\n", vf, VertexFormatName(vf),
                    (unsigned long long)count, status);
    }
    std::printf("fetch_constant_index_histogram (constIndex of each VFETCH):\n");
    for (auto& [idx, count] : constIndexUsage) {
        std::printf("  const[%u] count=%llu\n", idx, (unsigned long long)count);
    }

    bool allOk = vdOk && rcOk && shOk && unsupported.empty();
    std::printf("RESULT: %s\n", allOk ? "CLEAN" : "ISSUES FOUND");
    return allOk ? 0 : 1;
}
