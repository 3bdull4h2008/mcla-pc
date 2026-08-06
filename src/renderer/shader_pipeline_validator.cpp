// Standalone MCLA shader pipeline-key validator (Phase 5 groundwork).
//
// Usage: shader_pipeline_validator.exe <shader-dir>
//
// Scans every regular file in <shader-dir>, walks Rockstar .fxc containers via
// VisitShaderContainers, and for each container:
//   - parses it through ParseShaderContainer into the normalized IR;
//   - verifies hash determinism (HashShaderContainer returns the same
//     programHash on two independent parses of the same bytes);
//   - reports stage split (VS vs PS).
// Then exercises the pipeline-key machinery headlessly:
//   - ComputePipelineKey / HashPipelineKey sanity (distinct keys distinct);
//   - PipelineCache insert/find + bounded FIFO eviction.
// Exit code 0 = clean, 1 = errors found.

#include "shader_translator.h"
#include "pipeline_cache.h"

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;
using namespace mcla::renderer;

struct Stats {
    uint64_t files = 0;
    uint64_t containers = 0;
    uint64_t parsed = 0;
    uint64_t vertex = 0;
    uint64_t pixel = 0;
    uint64_t hashMismatches = 0;
    uint64_t parseErrors = 0;
};

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

// Parse + double-hash a single container slice. Returns false on error.
static bool ProcessContainer(const uint8_t* data, size_t size, Stats& stats) {
    stats.containers++;

    TranslatedShader out;
    ShaderProgram prog;
    if (!ParseShaderContainer(data, size, prog, out)) {
        stats.parseErrors++;
        return false;
    }
    stats.parsed++;
    if (out.isVertex) stats.vertex++; else stats.pixel++;

    // Determinism: independent parse/hash of the same bytes must match.
    bool isVertex2 = false;
    uint64_t hash2 = 0;
    if (!HashShaderContainer(data, size, isVertex2, hash2) || hash2 != out.programHash) {
        stats.hashMismatches++;
        return false;
    }
    return true;
}

// Exercise the pipeline-key + cache machinery with synthetic data.
static bool ExercisePipelineKeys() {
    bool ok = true;

    PipelineState s1;
    s1.targetFormats[0] = 0x00162; // R8G8B8A8_UNORM
    s1.depthStencilFormat = 0;
    s1.blendState = 0x1234;
    s1.rasterState = 0x5678;
    s1.depthStencilState = 0x9abc;
    s1.topology = 3; // triangle list
    s1.sampleCount = 1;

    PipelineKey k1 = ComputePipelineKey(0xA, 0xB, 0xC, s1);
    PipelineKey k2 = ComputePipelineKey(0xA, 0xB, 0xC, s1); // same
    PipelineKey k3 = ComputePipelineKey(0xD, 0xE, 0xF, s1); // different shaders

    if (!(k1 == k2)) { std::printf("  !! equal keys compare unequal\n"); ok = false; }
    if (k1 == k3)     { std::printf("  !! distinct keys compare equal\n"); ok = false; }
    if (HashPipelineKey(k1) != HashPipelineKey(k2)) { std::printf("  !! equal keys hash differently\n"); ok = false; }
    if (HashPipelineKey(k1) == HashPipelineKey(k3)) { std::printf("  !! distinct keys hash collision\n"); ok = false; }

    // Bounded FIFO eviction.
    PipelineCache cache(3);
    cache.Insert(k1, 1);
    cache.Insert(k3, 2);
    PipelineKey k4 = ComputePipelineKey(1, 2, 3, s1);
    PipelineKey k5 = ComputePipelineKey(4, 5, 6, s1);
    cache.Insert(k4, 3);
    cache.Insert(k5, 4); // evicts k1

    uint64_t handle = 0;
    if (cache.Find(k1, handle)) { std::printf("  !! evicted key still present\n"); ok = false; }
    if (!cache.Find(k3, handle) || handle != 2) { std::printf("  !! k3 lookup failed\n"); ok = false; }
    if (!cache.Find(k4, handle) || handle != 3) { std::printf("  !! k4 lookup failed\n"); ok = false; }
    if (!cache.Find(k5, handle) || handle != 4) { std::printf("  !! k5 lookup failed\n"); ok = false; }
    if (cache.Size() != 3) { std::printf("  !! cache size %zu != 3\n", cache.Size()); ok = false; }

    // Update existing key handle.
    cache.Insert(k3, 99);
    if (!cache.Find(k3, handle) || handle != 99) { std::printf("  !! insert-update failed\n"); ok = false; }

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

    Stats stats;
    bool allOk = true;

    for (const auto& entry : fs::recursive_directory_iterator(root)) {
        if (!entry.is_regular_file()) continue;
        // Skip metadata/list files.
        const std::string ext = entry.path().extension().string();
        if (ext == ".list") continue;

        bool ok = false;
        std::vector<uint8_t> data = ReadFile(entry.path(), ok);
        if (!ok) continue;
        stats.files++;

        // Walk containers at variable offsets (XenosRecomp-style scan).
        bool fileClean = true;
        size_t containers = 0;
        VisitShaderContainers(data.data(), data.size(), [&](size_t off) {
            const size_t vsize = AssembleBE32(data.data() + off + 4);
            const size_t psize = AssembleBE32(data.data() + off + 8);
            if (!ProcessContainer(data.data() + off, vsize + psize, stats)) fileClean = false;
            containers++;
            return true;
        });
        if (containers == 0) {
            // Extensionless/unknown file with no container header is ignored.
            stats.files--;
            continue;
        }
        if (!fileClean) allOk = false;
    }

    bool keyOk = ExercisePipelineKeys();
    if (!keyOk) allOk = false;

    std::printf("files=%llu containers=%llu parsed=%llu vs=%llu ps=%llu parse_errors=%llu hash_mismatches=%llu\n",
                (unsigned long long)stats.files,
                (unsigned long long)stats.containers,
                (unsigned long long)stats.parsed,
                (unsigned long long)stats.vertex,
                (unsigned long long)stats.pixel,
                (unsigned long long)stats.parseErrors,
                (unsigned long long)stats.hashMismatches);
    std::printf("pipeline_key_test=%s\n", keyOk ? "ok" : "FAIL");
    std::printf("RESULT: %s\n", allOk ? "CLEAN" : "ISSUES FOUND");
    return allOk ? 0 : 1;
}
