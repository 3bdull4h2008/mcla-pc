// Standalone MCLA shader pipeline-key validator (Phase 5 groundwork).
//
// Usage: shader_pipeline_validator.exe <shader-dir> [--dump <out-dir>]
//
// Scans every regular file in <shader-dir>, walks Rockstar .fxc containers via
// VisitShaderContainers, and for each container:
//   - parses it through ParseShaderContainer into the normalized IR;
//   - verifies hash determinism (HashShaderContainer returns the same
//     programHash on two independent parses of the same bytes);
//   - reports stage split (VS vs PS);
//   - translates to HLSL (Phase 5 gate: no unknown/unsupported opcodes, non
//     empty output); with --dump, writes each generated HLSL to <out-dir> so
//     the samples can be compiled with the SDK dxc.exe.
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
#include <fstream>
#include <string>
#include <vector>
#include <wrl/client.h>

// Simple mock COM object for testing PipelineCache without a real D3D12 device.
// Implements IUnknown and ID3D12PipelineState (which is an empty marker interface).
class MockPipelineState : public ID3D12PipelineState {
public:
    MockPipelineState() : refCount_(1) {}
    
    // IUnknown
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppv) override {
        if (riid == __uuidof(IUnknown) || riid == __uuidof(ID3D12PipelineState)) {
            *ppv = static_cast<ID3D12PipelineState*>(this);
            AddRef();
            return S_OK;
        }
        *ppv = nullptr;
        return E_NOINTERFACE;
    }
    
    ULONG STDMETHODCALLTYPE AddRef() override {
        return ++refCount_;
    }
    
    ULONG STDMETHODCALLTYPE Release() override {
        ULONG count = --refCount_;
        if (count == 0) delete this;
        return count;
    }
    
    // ID3D12Object
    HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID, UINT*, void*) override { return E_NOTIMPL; }
    HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID, UINT, const void*) override { return E_NOTIMPL; }
    HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(REFGUID, const IUnknown*) override { return E_NOTIMPL; }
    HRESULT STDMETHODCALLTYPE SetName(LPCWSTR) override { return E_NOTIMPL; }
    HRESULT STDMETHODCALLTYPE GetDevice(REFIID, void**) override { return E_NOTIMPL; }
    
    // ID3D12PipelineState
    HRESULT STDMETHODCALLTYPE GetCachedBlob(ID3DBlob**) override { return E_NOTIMPL; }
    
private:
    virtual ~MockPipelineState() = default;
    std::atomic<ULONG> refCount_;
};

// Helper to create a mock pipeline state
inline Microsoft::WRL::ComPtr<ID3D12PipelineState> MakeMockPipeline(uint64_t) {
    return Microsoft::WRL::ComPtr<ID3D12PipelineState>(new MockPipelineState());
}

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
    uint64_t translationErrors = 0;
    uint64_t emptyHlsl = 0;
    uint64_t emptyProgram = 0;
    uint64_t unknownOpcodes = 0;
    uint64_t unsupportedOpcodes = 0;
};

static std::vector<uint8_t> ReadFile(const fs::path& path, bool& ok) {
    std::vector<uint8_t> data;
    ok = false;
    std::error_code ec;
    const uintmax_t sz = fs::file_size(path, ec);
    if (ec) return data;
    FILE* f = std::fopen(path.string().c_str(), "rb");
    if (!f) return data;
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

// Parse + double-hash a single container slice, then run the Phase 5
// translation gates: the HLSL output must be non-empty and every decoded
// instruction must have a known opcode and a lowering. Returns false on error
// (any failed gate flips the global RESULT to ISSUES FOUND).
// When `dumpDir` is set, the generated HLSL is written to
// `<dumpDir>/<stem>_<idx>_<vs|ps>.hlsl` (see main) for offline dxc validation.
static bool ProcessContainer(const uint8_t* data, size_t size, Stats& stats,
                             const fs::path& dumpDir, const fs::path& stem,
                             size_t idx) {
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

    // Phase 5 gate: translate to HLSL and require a complete, clean lowering.
    bool ok = true;
    if (!TranslateShader(data, size, {}, out)) {
        stats.translationErrors++;
        ok = false;
    }
    if (out.instructionCount == 0) {
        stats.emptyProgram++;
        ok = false;
    }
    if (out.hlsl.empty()) {
        stats.emptyHlsl++;
        ok = false;
    }
    if (out.unknownOpcodeCount != 0) {
        stats.unknownOpcodes += out.unknownOpcodeCount;
        ok = false;
    }
    if (out.unsupportedOpcodeCount != 0) {
        stats.unsupportedOpcodes += out.unsupportedOpcodeCount;
        ok = false;
    }

    if (!dumpDir.empty() && !out.hlsl.empty()) {
        const std::string stage = out.isVertex ? "vs" : "ps";
        const fs::path outPath = dumpDir /
                (stem.string() + "_" + std::to_string(idx) + "_" + stage + ".hlsl");
        std::ofstream ofs(outPath, std::ios::binary | std::ios::trunc);
        if (ofs) {
            ofs.write(out.hlsl.data(), std::streamsize(out.hlsl.size()));
            ofs.close();
        } else {
            std::printf("  !! cannot write %s\n", outPath.string().c_str());
            ok = false;
        }
    }

    return ok;
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
    cache.Insert(k1, MakeMockPipeline(1));
    cache.Insert(k3, MakeMockPipeline(2));
    PipelineKey k4 = ComputePipelineKey(1, 2, 3, s1);
    PipelineKey k5 = ComputePipelineKey(4, 5, 6, s1);
    cache.Insert(k4, MakeMockPipeline(3));
    cache.Insert(k5, MakeMockPipeline(4)); // evicts k1

    Microsoft::WRL::ComPtr<ID3D12PipelineState> handle;
    if (cache.Find(k1, handle)) { std::printf("  !! evicted key still present\n"); ok = false; }
    if (!cache.Find(k3, handle)) { std::printf("  !! k3 lookup failed\n"); ok = false; }
    if (!cache.Find(k4, handle)) { std::printf("  !! k4 lookup failed\n"); ok = false; }
    if (!cache.Find(k5, handle)) { std::printf("  !! k5 lookup failed\n"); ok = false; }
    if (cache.Size() != 3) { std::printf("  !! cache size %zu != 3\n", cache.Size()); ok = false; }

    // Update existing key handle.
    cache.Insert(k3, MakeMockPipeline(99));
    if (!cache.Find(k3, handle)) { std::printf("  !! insert-update failed\n"); ok = false; }

    return ok;
}

int main(int argc, char** argv) {
    std::setvbuf(stdout, nullptr, _IONBF, 0);
    if (argc < 2) {
        std::printf("Usage: %s <shader-dir> [--dump <out-dir>]\n", argv[0]);
        return 2;
    }
    const fs::path root = argv[1];

    // Optional --dump <dir>: write every generated HLSL to <dir> (created on
    // demand) so the samples can be compiled with the SDK dxc.exe.
    fs::path dumpDir;
    for (int i = 2; i + 1 < argc; i++) {
        if (std::strcmp(argv[i], "--dump") == 0) dumpDir = argv[i + 1];
    }

    if (!fs::is_directory(root)) {
        std::printf("not a directory: %s\n", root.string().c_str());
        return 2;
    }
    if (!dumpDir.empty()) {
        std::error_code ec;
        if (!fs::create_directories(dumpDir, ec) && ec) {
            std::printf("cannot create dump dir: %s\n", dumpDir.string().c_str());
            return 2;
        }
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
        const fs::path stem = entry.path().stem();
        VisitShaderContainers(data.data(), data.size(), [&](size_t off) {
            const size_t vsize = AssembleBE32(data.data() + off + 4);
            const size_t psize = AssembleBE32(data.data() + off + 8);
            if (!ProcessContainer(data.data() + off, vsize + psize, stats,
                                  dumpDir, stem, containers))
                fileClean = false;
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
    std::printf("phase5_gates: empty_hlsl=%llu empty_program=%llu unknown_opcodes=%llu unsupported_opcodes=%llu translation_errors=%llu\n",
                (unsigned long long)stats.emptyHlsl,
                (unsigned long long)stats.emptyProgram,
                (unsigned long long)stats.unknownOpcodes,
                (unsigned long long)stats.unsupportedOpcodes,
                (unsigned long long)stats.translationErrors);
    std::printf("pipeline_key_test=%s\n", keyOk ? "ok" : "FAIL");
    std::printf("RESULT: %s\n", allOk ? "CLEAN" : "ISSUES FOUND");
    return allOk ? 0 : 1;
}
