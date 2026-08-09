// Standalone capture + guestmem dump validator.
//
// Usage:
//   capture_dump_validator.exe <trace.mclatrace> [guestmem-dir]
//   capture_dump_validator.exe <capture-root>      (directory containing
//       *.mclatrace plus a guestmem/ subfolder; scans all traces)
//   capture_dump_validator.exe                     (built-in self-test)
//
// Cross-checks the captured DrawPacket stream against the raw guest memory
// dumps written by capture_hooks (vb_<addr>_<size>.bin / ib_<addr>_<size>.bin):
//
//   1. Trace header integrity (magic/version/packetSize).
//   2. Per-packet sanity: primitive type, stream count, stride/address,
//      vertex-format decodability, index-buffer population.
//   3. Dump coverage: every captured VB stream has a matching dump of exactly
//      stride*indexCount bytes (capped at 0x10000 like the capture).
//   4. Aggregated layout evidence: which vertex-format codes and strides the
//      corpus actually uses, and how many packets carry an index buffer.
//
// Exit code 0 = clean, 1 = errors found. This is the offline evidence gate
// for Phase 3 guest-vertex wiring.

#include "frame_trace.h"
#include "vertex_decode.h"

#include <cstdarg>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <map>
#include <set>
#include <string>
#include <vector>

namespace fs = std::filesystem;
using namespace mcla::native;

static int g_errors = 0;
static int g_warnings = 0;

static void Diag(bool ok, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    std::printf(ok ? "  [OK] " : "  [!!] ");
    std::vprintf(fmt, args);
    std::printf("\n");
    va_end(args);
    if (!ok) g_errors++;
}

// Expected dump size a capture would produce for one vertex stream.
// When layout is resolved (stride != 0) the capture writes stride*count bytes
// (capped like the capture). When stride == 0 the layout is UNRESOLVED (Rev 03:
// format/stride live in the captured drawable's grcFvf, not the shader or the
// fetch-constant descriptor) -- we must NOT guess a default stride (that would
// be invented draw data per Golden Rule 5). Return 0 to signal "cannot state an
// expected dump size yet"; the caller reports it as a layout gap.
static uint32_t ExpectedStreamDumpBytes(const VertexStreamDesc& s, uint32_t indexCount) {
    if (s.stride == 0) return 0;  // layout unresolved -- no invented stride
    const uint32_t elements = indexCount > 0 ? indexCount : 1;
    const uint32_t maxBytes = s.stride * elements;
    return maxBytes > 0x10000u ? 0x10000u : maxBytes;
}

// Parse "tag_<addr>_<size>.bin" -> (ok, addr, size).
static bool ParseDumpName(const fs::path& p, uint32_t& addr, uint32_t& size) {
    std::string stem = p.stem().string();
    auto lastUnd = stem.find_last_of('_');
    if (lastUnd == std::string::npos) return false;
    auto firstUnd = stem.find_first_of('_');
    if (firstUnd == std::string::npos || firstUnd == lastUnd) return false;
    try {
        addr = static_cast<uint32_t>(std::stoul(stem.substr(firstUnd + 1, lastUnd - firstUnd - 1), nullptr, 16));
        size = static_cast<uint32_t>(std::stoul(stem.substr(lastUnd + 1), nullptr, 16));
    } catch (...) {
        return false;
    }
    return true;
}

struct LayoutEvidence {
    std::map<uint32_t, uint64_t> formatCount;      // vfCode -> draws
    std::map<std::pair<uint32_t, uint32_t>, uint64_t> strideFormatCount; // (vf,stride)->draws
    uint64_t packetsWithIndexBuffer = 0;
    uint64_t packetsNonIndexed = 0;
    uint64_t packetsInvalid = 0;
    uint64_t packetsTotal = 0;
    uint64_t streamsLayoutUnresolved = 0;
};

// Analyze one trace file against a guestmem dir (may be empty).
static void AnalyzeTrace(const fs::path& tracePath, const fs::path& memDir, LayoutEvidence& agg) {
    std::printf("== Trace: %s\n", tracePath.filename().string().c_str());

    FILE* f = std::fopen(tracePath.string().c_str(), "rb");
    if (!f) {
        Diag(false, "cannot open trace %s", tracePath.string().c_str());
        return;
    }

    TraceHeader h{};
    if (std::fread(&h, 1, sizeof(h), f) != sizeof(h)) {
        std::fclose(f);
        Diag(false, "truncated trace header");
        return;
    }
    Diag(h.magic == kTraceMagic, "magic 0x%08X (expected 0x%08X)", h.magic, kTraceMagic);
    Diag(h.version == kTraceVersion, "version %u (expected %u)", h.version, kTraceVersion);
    Diag(h.packetSize == sizeof(DrawPacket), "packetSize %u (expected %zu)",
         h.packetSize, sizeof(DrawPacket));
    if (h.magic != kTraceMagic || h.version != kTraceVersion ||
        h.packetSize != sizeof(DrawPacket)) {
        std::fclose(f);
        return;
    }

    std::vector<DrawPacket> packets(h.packetCount);
    if (h.packetCount > 0) {
        if (std::fread(packets.data(), sizeof(DrawPacket), h.packetCount, f) != h.packetCount) {
            std::fclose(f);
            Diag(false, "truncated packet stream");
            return;
        }
    }
    std::fclose(f);

    Diag(true, "loaded %u packets (build 0x%016llX)", h.packetCount,
         static_cast<unsigned long long>(h.buildHash));

    // Index dumps by (addr,size) for coverage lookup.
    std::set<std::pair<uint32_t, uint32_t>> dumps;
    if (!memDir.empty()) {
        for (auto& e : fs::directory_iterator(memDir)) {
            uint32_t a = 0, s = 0;
            if (e.is_regular_file() && ParseDumpName(e.path(), a, s)) {
                dumps.insert({ a, s });
            }
        }
        std::printf("  guestmem: %zu dump file(s) in %s\n", dumps.size(), memDir.string().c_str());
    }

    uint64_t streamCovered = 0, streamTotal = 0;
    for (size_t i = 0; i < packets.size(); ++i) {
        const DrawPacket& p = packets[i];
        agg.packetsTotal++;

        if (!p.isValid) {
            agg.packetsInvalid++;
            Diag(false, "packet %zu: isValid=0 (guest refs rejected at capture)", i);
            continue;
        }

        // Primitive / draw sanity.
        if (p.primType > 3) Diag(false, "packet %zu: unusual primType %u", i, p.primType);
        if (p.indexCount > 1u << 24) Diag(false, "packet %zu: indexCount %u implausible", i, p.indexCount);
        if (p.vertexStreamCount > 16) Diag(false, "packet %zu: streamCount %u > 16", i, p.vertexStreamCount);

        // Index buffer population (the known Phase 3 gap).
        if (p.indexBufferAddress != 0 || p.indexBufferSize != 0) {
            agg.packetsWithIndexBuffer++;
            if (p.indexBufferAddress == 0 || p.indexBufferSize == 0) {
                Diag(false, "packet %zu: partial index buffer (addr=%08X size=%X)", i,
                     p.indexBufferAddress, p.indexBufferSize);
            }
        } else {
            agg.packetsNonIndexed++;
        }

        for (uint32_t s = 0; s < p.vertexStreamCount && s < 16; ++s) {
            const VertexStreamDesc& vs = p.vertexStreams[s];
            if (vs.guestAddress == 0) {
                Diag(false, "packet %zu: stream %u guestAddress==0", i, s);
                continue;
            }
            if (vs.stride == 0) {
                // Layout unresolved (Rev 03: format/stride live in the captured
                // drawable's grcFvf, not the shader or fetch-constant). One
                // diagnostic per stream; do NOT guess a stride or claim dump
                // coverage (Golden Rule 5). Excluded from the coverage ratio.
                agg.streamsLayoutUnresolved++;
                Diag(false, "packet %zu: stream %u layout unresolved (stride==0) -- "
                     "cannot state expected VB dump; needs captured grcFvf layout", i, s);
                continue;
            }

            VertexFormatDesc d = DecodeVertexFetch(vs.format, vs.format);
            if (!d.valid && vs.format != 0) {
                Diag(false, "packet %zu: stream %u vf=%u undecodable", i, s, vs.format);
            }
            agg.formatCount[vs.format]++;
            agg.strideFormatCount[{ vs.format, vs.stride }]++;

            streamTotal++;
            const uint32_t want = ExpectedStreamDumpBytes(vs, p.indexCount);
            if (dumps.count({ vs.guestAddress, want })) {
                streamCovered++;
            } else {
                Diag(false, "packet %zu: stream %u missing dump vb_%08X_%06X.bin (expected %u bytes)",
                     i, s, vs.guestAddress, want, want);
            }
        }
    }

    if (streamTotal > 0) {
        Diag(streamCovered == streamTotal,
             "vertex-stream dump coverage %llu/%llu (%.0f%%)",
             static_cast<unsigned long long>(streamCovered),
             static_cast<unsigned long long>(streamTotal),
             100.0 * double(streamCovered) / double(streamTotal));
    }
}

static void PrintEvidence(const LayoutEvidence& agg) {
    std::printf("\n== Aggregated layout evidence\n");
    std::printf("  packets total:   %llu\n", static_cast<unsigned long long>(agg.packetsTotal));
    std::printf("  invalid packets: %llu\n", static_cast<unsigned long long>(agg.packetsInvalid));
    std::printf("  with index buf:  %llu\n", static_cast<unsigned long long>(agg.packetsWithIndexBuffer));
    std::printf("  non-indexed:     %llu\n", static_cast<unsigned long long>(agg.packetsNonIndexed));
    std::printf("  streams layout unresolved: %llu\n",
                static_cast<unsigned long long>(agg.streamsLayoutUnresolved));
    if (!agg.formatCount.empty()) {
        std::printf("  vertex-format codes:\n");
        for (auto& [vf, n] : agg.formatCount) {
            std::printf("    vf=%-3u  %-24s x%llu\n", vf, VertexFormatName(vf),
                        static_cast<unsigned long long>(n));
        }
    }
    if (!agg.strideFormatCount.empty()) {
        std::printf("  (format,stride) pairs:\n");
        for (auto& [kv, n] : agg.strideFormatCount) {
            std::printf("    vf=%-3u stride=%-4u x%llu\n", kv.first, kv.second,
                        static_cast<unsigned long long>(n));
        }
    }
    if (agg.packetsTotal > 0 && agg.packetsWithIndexBuffer == 0) {
        std::printf("  NOTE: no packets carry an index buffer -- the capture hook\n"
                    "        does not populate indexBufferAddress/Size yet (Phase 3 gap).\n");
    }
}

// Self-test: synthesize a trace + matching dumps, then analyze it.
static bool RunSelfTest() {
    std::printf("== Self-test: synthetic capture + guestmem\n");
    fs::path dir = fs::temp_directory_path() / "mcla_dump_selftest";
    std::error_code ec;
    fs::remove_all(dir, ec);
    fs::create_directories(dir / "guestmem", ec);

    // Write a minimal valid trace (replicated writer logic; header patched after).
    fs::path tracePath = dir / "selftest.mclatrace";
    FILE* f = std::fopen(tracePath.string().c_str(), "wb");
    if (!f) return false;

    std::vector<DrawPacket> packets(2);
    packets[0].frameIndex = 1;
    packets[0].drawInFrame = 0;
    packets[0].primType = 0;
    packets[0].indexType = 0;
    packets[0].indexCount = 36;
    packets[0].vertexStreamCount = 1;
    packets[0].vertexStreams[0] = { 0x1000, 12, 0, 17 }; // Float32x3-ish, stride 12
    packets[0].indexBufferAddress = 0;                    // non-indexed
    packets[0].isValid = 1;
    packets[0].stateHash = 0xAAAAAAAAAAAAAAAAULL;

    packets[1].frameIndex = 1;
    packets[1].drawInFrame = 1;
    packets[1].primType = 0;
    packets[1].indexType = 1;
    packets[1].indexCount = 120;
    packets[1].vertexStreamCount = 2;
    packets[1].vertexStreams[0] = { 0x2000, 16, 0, 33 }; // Float32x4-ish
    packets[1].vertexStreams[1] = { 0x3000, 4, 0, 16 };  // Unorm8x4
    packets[1].indexBufferAddress = 0x5000;
    packets[1].indexBufferSize = 240;
    packets[1].isValid = 1;
    packets[1].stateHash = 0xBBBBBBBBBBBBBBBBULL;

    TraceHeader h{};
    h.magic = kTraceMagic;
    h.version = kTraceVersion;
    h.headerSize = sizeof(TraceHeader);
    h.packetSize = sizeof(DrawPacket);
    h.packetCount = static_cast<uint32_t>(packets.size());
    h.buildHash = 0x1122334455667788ULL;
    h.startTimestamp = 1;

    std::fwrite(&h, 1, sizeof(h), f);
    std::fwrite(packets.data(), sizeof(DrawPacket), packets.size(), f);
    std::fclose(f);

    // Write matching dumps with correct sizes.
    auto writeDump = [&](const char* name, uint32_t size) {
        fs::path p = dir / "guestmem" / name;
        FILE* d = std::fopen(p.string().c_str(), "wb");
        if (!d) return;
        std::vector<uint8_t> buf(size, 0xAB);
        std::fwrite(buf.data(), 1, size, d);
        std::fclose(d);
    };
    // packet0 stream: stride 12 * 36 = 432
    writeDump("vb_00001000_0001B0.bin", 432);
    // packet1 stream0: stride 16 * 120 = 1920 (0x780)
    writeDump("vb_00002000_000780.bin", 1920);
    // packet1 stream1: stride 4 * 120 = 480 (0x1E0)
    writeDump("vb_00003000_0001E0.bin", 480);
    // packet1 index buffer: 240 (0xF0)
    writeDump("ib_00005000_0000F0.bin", 240);

    LayoutEvidence agg;
    AnalyzeTrace(tracePath, dir / "guestmem", agg);
    PrintEvidence(agg);

    bool ok = (g_errors == 0);
    Diag(ok, "self-test %s", ok ? "PASSED" : "FAILED");
    fs::remove_all(dir, ec);
    return ok;
}

int main(int argc, char** argv) {
    std::printf("MCLA capture + guestmem dump validator\n");

    if (argc < 2) {
        return RunSelfTest() ? 0 : 1;
    }

    fs::path target = argv[1];
    LayoutEvidence agg;

    if (fs::is_directory(target)) {
        // Directory mode: scan *.mclatrace, each with a guestmem/ subfolder.
        std::vector<fs::path> traces;
        for (auto& e : fs::directory_iterator(target)) {
            if (e.is_regular_file() && e.path().extension() == ".mclatrace") {
                traces.push_back(e.path());
            }
        }
        std::printf("found %zu trace file(s) in %s\n", traces.size(), target.string().c_str());
        if (traces.empty()) {
            std::printf("no *.mclatrace found under %s\n", target.string().c_str());
            return 0;
        }
        for (auto& t : traces) {
            fs::path memDir = t.parent_path() / "guestmem";
            if (!fs::is_directory(memDir)) memDir.clear();
            AnalyzeTrace(t, memDir, agg);
        }
    } else {
        fs::path memDir = argc >= 3 ? fs::path(argv[2]) : (target.parent_path() / "guestmem");
        if (!fs::is_directory(memDir)) memDir.clear();
        AnalyzeTrace(target, memDir, agg);
    }

    PrintEvidence(agg);

    if (g_errors == 0) {
        std::printf("\nRESULT: CLEAN (0 errors)\n");
        return 0;
    }
    std::printf("\nRESULT: %d error(s), %d warning(s)\n", g_errors, g_warnings);
    return 1;
}
