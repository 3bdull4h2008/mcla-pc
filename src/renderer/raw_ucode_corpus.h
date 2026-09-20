#pragma once

// Shared raw-ucode corpus input handling for the offline shader validators
// (shader_pipeline_validator / phase3_validator dir scans).
//
// Mirrors the proven classification + endian approach of
// xenos_decode_validator.cpp (G-XENOS-DECODE-CLEAN baseline, binary rollup
// 806/806):
//   - Xenia ucode binary dumps (*.ucode.bin.*) store HOST-endian dwords
//     (Shader::DumpUcode writes the host-endian array verbatim,
//     .research/xenia/src/xenia/gpu/shader.cc:142-145) and must be
//     byte-reversed back to guest big-endian before any BE decode.
//   - ASCII text disasm companions (*.ucode.<vert|frag>, no ".bin.") are not
//     microcode; feeding them to the decoder measures ASCII, not decoder gaps,
//     so they are classified and skipped (counted, not errors).
//   - Compiled *.d3d12.bin.* dump companions are neither microcode nor
//     containers and are ignored.
//   - Files carrying the Rockstar .fxc container magic route to the existing
//     container pipelines; everything else microcode-shaped routes to a raw
//     guest-BE decode.
//
// Header-only on purpose: no CMake/target changes, and xenos_decode_validator
// keeps its own copy (outside this task's modification scope).

#include "xenos_shader_ir.h"

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace mcla::renderer::corpus {

// Substring test on a path (corpus file names encode their provenance).
inline bool PathContains(const std::string& path, const char* needle) {
    return path.find(needle) != std::string::npos;
}

// Vertex-stage dump name suffix (Xenia dumps use ".vert"/".frag").
[[nodiscard]] inline bool IsVertexDumpName(const std::string& path) {
    return PathContains(path, ".vert");
}

// Byte-reversal per dword: LE-stored dump -> guest-BE stream, in place.
// Explicit per-dword swap - no reinterpret_cast on file data.
inline void RestoreGuestEndianDwords(std::vector<uint8_t>& data) {
    for (size_t i = 0; i + 4 <= data.size(); i += 4) {
        uint8_t t = data[i];
        data[i] = data[i + 3];
        data[i + 3] = t;
        t = data[i + 1];
        data[i + 1] = data[i + 2];
        data[i + 2] = t;
    }
}

// >=90% printable bytes in the first 64 => text (disassembly companion).
[[nodiscard]] inline bool LooksLikeText(const uint8_t* data, size_t size) {
    const size_t n = size < 64 ? size : 64;
    if (n == 0) return false;
    size_t printable = 0;
    for (size_t i = 0; i < n; ++i) {
        const uint8_t c = data[i];
        if ((c >= 0x20 && c < 0x7F) || c == '\r' || c == '\n' || c == '\t') {
            ++printable;
        }
    }
    return printable * 100 >= n * 90;
}

// True when the Rockstar .fxc container magic sits anywhere in the stream
// (containers live at variable offsets behind a name string; same predicate
// as VisitShaderContainers / xenos_decode_validator).
[[nodiscard]] inline bool HasFxcContainerMagic(const uint8_t* data, size_t size) {
    for (size_t i = 0; i + 36 <= size; i += 4) {
        const uint32_t flags = (uint32_t(data[i]) << 24) | (uint32_t(data[i + 1]) << 16) |
                               (uint32_t(data[i + 2]) << 8) | uint32_t(data[i + 3]);
        if ((flags & 0xFFFFFF00u) == 0x102A1100u) return true;
    }
    return false;
}

enum class InputClass {
    FxcContainer,  // Rockstar container magic present -> container pipeline
    RawMicrocode,  // binary microcode dump (guest-BE after endian restore)
    TextDisasm,    // ASCII disassembly companion -> skip gracefully (counted)
    Ignore,        // unrelated dump companion (.d3d12.bin.*, metadata, ...)
};

// Dual-path input classification for one corpus file. Callers must have
// restored endian on ".ucode.bin." files BEFORE classifying so binary dumps
// are never mistaken for text.
[[nodiscard]] inline InputClass ClassifyCorpusFile(const std::string& path,
                                                   const uint8_t* data, size_t size) {
    if (HasFxcContainerMagic(data, size)) return InputClass::FxcContainer;
    if (PathContains(path, ".ucode.")) {
        if (LooksLikeText(data, size)) return InputClass::TextDisasm;
        return InputClass::RawMicrocode;
    }
    return InputClass::Ignore;
}

// Decode-quality counters for one raw microcode blob.
struct RawDecodeStats {
    uint64_t oobExecs = 0;      // exec target beyond buffer end
    uint64_t unknownInstrs = 0; // instructions with no decoder table entry
};

// Decode a raw guest-BE microcode blob into prog.instructions using the exact
// CF/exec walk of ParseShaderProgram (container metadata stages stay
// defaulted - they are unavailable for raw dumps). Never fails: quality is
// reported via RawDecodeStats so callers decide policy.
inline RawDecodeStats DecodeRawMicrocode(const uint8_t* code, size_t size, ShaderProgram& out) {
    RawDecodeStats st{};
    out.instructions.clear();
    const size_t cfBound = ComputeControlFlowByteBound(code, size);
    const size_t nBlocks = cfBound / 12;
    for (size_t b = 0; b < nBlocks; ++b) {
        const uint8_t* blk = code + b * 12;
        const uint32_t w0 = AssembleBE32(blk);
        const uint32_t w1 = AssembleBE32(blk + 4);
        const uint32_t w2 = AssembleBE32(blk + 8);
        for (int slot = 0; slot < 2; ++slot) {
            const uint32_t cfw0 = slot == 0 ? w0 : ((w1 >> 16) | (w2 << 16));
            const uint16_t cfw1 = slot == 0 ? static_cast<uint16_t>(w1 & 0xFFFF)
                                            : static_cast<uint16_t>(w2 >> 16);
            const ControlFlowInstruction cf = DecodeControlFlow(cfw0, cfw1);
            if (!cf.IsExec()) continue;
            const size_t instrBase = size_t(cf.address) * 12;
            if (cf.count > 0 && instrBase + size_t(cf.count) * 12 > size) {
                ++st.oobExecs;
                continue;
            }
            for (uint32_t i = 0; i < cf.count; ++i) {
                if (instrBase + size_t(i) * 12 + 12 > size) break;
                const uint8_t* ip = code + instrBase + size_t(i) * 12;
                const bool isFetch = ((cf.sequence >> (2 * i)) & 1) != 0;
                IrInstruction ir;
                ir.address = uint32_t(cf.address + i);
                ir.isFetch = isFetch;
                ir.decoded = DecodeInstruction(AssembleBE32(ip), AssembleBE32(ip + 4),
                                               AssembleBE32(ip + 8), isFetch);
                if (ir.decoded.unknown) ++st.unknownInstrs;
                out.instructions.push_back(ir);
            }
        }
    }
    return st;
}

}  // namespace mcla::renderer::corpus
