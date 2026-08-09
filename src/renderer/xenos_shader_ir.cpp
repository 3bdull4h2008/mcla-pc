#include "xenos_shader_ir.h"

#include <algorithm>
#include <cstring>
#include <cstdio>

namespace mcla::renderer {

static uint32_t ReadBE32(const uint8_t* p) {
    return (uint32_t(p[0]) << 24) | (uint32_t(p[1]) << 16) |
           (uint32_t(p[2]) << 8) | uint32_t(p[3]);
}
static uint16_t ReadBE16(const uint8_t* p) {
    return uint16_t((uint16_t(p[0]) << 8) | uint16_t(p[1]));
}

const char* RegisterSetName(RegisterSet set) {
    switch (set) {
        case RegisterSet::Bool:    return "Bool";
        case RegisterSet::Int4:    return "Int4";
        case RegisterSet::Float4:  return "Float4";
        case RegisterSet::Sampler: return "Sampler";
    }
    return "Unknown";
}

static constexpr size_t kContainerHeaderSize = 36;
static constexpr size_t kShaderHeaderSize = 24;

bool ParseShaderProgram(const uint8_t* data, size_t size, ShaderProgram& out) {
    if (size < kContainerHeaderSize) return false;

    out.flags       = ReadBE32(data + 0);
    out.virtualSize = ReadBE32(data + 4);
    out.physicalSize= ReadBE32(data + 8);

    if ((out.flags & 0xFFFFFF00) != 0x102A1100) return false;
    uint32_t f1C = ReadBE32(data + 28);
    uint32_t f20 = ReadBE32(data + 32);
    if (f1C != 0 || f20 != 0) return false;
    if (size_t(out.virtualSize) + size_t(out.physicalSize) > size) return false;

    uint32_t so = ReadBE32(data + 24);
    out.isVertex  = (out.flags & 0x1) != 0;

    // Shader header
    if (so + kShaderHeaderSize > out.virtualSize) return false;    const uint8_t* sp = data + so;
    out.physicalOffset   = ReadBE32(sp + 0);
    out.shaderSize       = ReadBE32(sp + 4);
    out.fieldC           = ReadBE32(sp + 12);
    out.field10          = ReadBE32(sp + 16);
    out.interpolatorInfo = ReadBE32(sp + 20);

    const size_t codeStart = size_t(out.virtualSize) + out.physicalOffset;
    if (codeStart + out.shaderSize > size) return false;

    // Decode microcode into IR
    const uint8_t* code = data + codeStart;
    const size_t cfBound = ComputeControlFlowByteBound(code, out.shaderSize);
    const size_t nBlocks = cfBound / 12;

    out.instructions.clear();
    for (size_t b = 0; b < nBlocks; ++b) {
        const uint8_t* blk = code + b * 12;
        uint32_t w0 = ReadBE32(blk);
        uint32_t w1 = ReadBE32(blk + 4);
        uint32_t w2 = ReadBE32(blk + 8);
        for (int slot = 0; slot < 2; ++slot) {
            uint32_t cfw0 = slot == 0 ? w0 : ((w1 >> 16) | (w2 << 16));
            uint16_t cfw1 = slot == 0 ? static_cast<uint16_t>(w1 & 0xFFFF)
                                      : static_cast<uint16_t>(w2 >> 16);
            ControlFlowInstruction cf = DecodeControlFlow(cfw0, cfw1);
            if (!cf.IsExec()) continue;

            const size_t instrBase = size_t(cf.address) * 12;
            for (uint32_t i = 0; i < cf.count; ++i) {
                if (instrBase + size_t(i) * 12 + 12 > out.shaderSize) break;
                const uint8_t* ip = code + instrBase + i * 12;
                uint32_t iw0 = ReadBE32(ip);
                uint32_t iw1 = ReadBE32(ip + 4);
                uint32_t iw2 = ReadBE32(ip + 8);
                bool isFetch = ((cf.sequence >> (2 * i)) & 1) != 0;
                IrInstruction ir;
                ir.address  = uint32_t(cf.address + i);
                ir.isFetch  = isFetch;
                ir.decoded  = DecodeInstruction(iw0, iw1, iw2, isFetch);
                out.instructions.push_back(ir);
            }
        }
    }

    // Constant table
    out.constants.clear();
    uint32_t cto = ReadBE32(data + 16);
    // Promote to size_t before adding: cto/ctSize are 32-bit guest fields and
    // can wrap past the buffer when summed in uint32_t (a crafted container
    // with cto near 0xFFFFFFFF would pass the guard and read ~4 GB OOB).
    if (cto != 0 && size_t(cto) + 24 <= out.virtualSize) {
        const uint8_t* ctd = data + cto;
        uint32_t ctSize      = ReadBE32(ctd + 0);
        uint32_t ctConstants = ReadBE32(ctd + 12);
        uint32_t ctInfoOff   = ReadBE32(ctd + 16);
        if (size_t(cto) + ctSize <= out.virtualSize) {
            // Cap iterations to the validated table region; ctConstants is
            // unvalidated and could otherwise loop ~4 G times (CPU DoS).
            const uint32_t maxConstants =
                uint32_t(std::min<size_t>(ctSize / 16, uint32_t(-1)));
            uint32_t capped = std::min(ctConstants, maxConstants);
            for (uint32_t ci = 0; ci < capped; ++ci) {
                const size_t off = size_t(ctInfoOff) + size_t(ci) * 16;
                if (off + 16 > ctSize) break;
                const uint8_t* ciPtr = ctd + off;
                ConstantEntry entry;
                entry.info.nameOffset    = ReadBE32(ciPtr + 0);
                entry.info.registerSet   = static_cast<RegisterSet>(ReadBE16(ciPtr + 4));
                entry.info.registerIndex = ReadBE16(ciPtr + 6);
                entry.info.registerCount = ReadBE16(ciPtr + 8);
                entry.info.reserved      = ReadBE16(ciPtr + 10);
                entry.info.typeInfo      = ReadBE32(ciPtr + 12);
                entry.info.defaultValue  = ReadBE32(ciPtr + 16);
                // Bounds-check the constant name before reading it. The
                // nameOffset is relative to the constant table and may point
                // outside it (or past ctSize) in some MCLA containers.
                {
                    const size_t nameOff = size_t(entry.info.nameOffset);
                    if (nameOff < ctSize) {
                        const uint8_t* ns = ctd + nameOff;
                        size_t remain = ctSize - nameOff;
                        size_t len = 0;
                        while (len < remain && ns[len] != 0) ++len;
                        entry.name.assign(ns, ns + len);
                    }
                }
                if (entry.info.typeInfo != 0 && entry.info.typeInfo + kTypeInfoSize <= ctSize) {
                    const uint8_t* tp = ctd + entry.info.typeInfo;
                    entry.type.parameterClass = ReadBE16(tp + 0);
                    entry.type.parameterType  = ReadBE16(tp + 2);
                    entry.type.rows           = ReadBE16(tp + 4);
                    entry.type.columns        = ReadBE16(tp + 6);
                    entry.type.elements       = ReadBE16(tp + 8);
                    entry.type.structMembers  = ReadBE16(tp + 10);
                    entry.type.structMemberInfo = ReadBE32(tp + 12);
                }
                out.constants.push_back(entry);
            }
        }
    }

    // Vertex elements (VS) / interpolators (PS)
    out.vertexElements.clear();
    out.interpolators.clear();
    out.pixelOutputs = PixelOutputs{};
    if (out.isVertex) {
        // VS header: field18 (sp+24) is an entry index into the
        // vertexElementsAndInterpolators[] array that begins at sp+36.
        // Vertex element i sits at array index field18 + i; interpolator i at
        // field18 + vertexElementCount + i. Each entry packs
        // VertexElement { address:12, usage:4, usageIndex:4 }.
        uint32_t veStart = ReadBE32(sp + 24);
        uint32_t veCount = ReadBE32(sp + 28);
        // Promote to size_t before multiplying: (veStart+veCount+32)*4 can
        // wrap in uint32_t, letting the guard pass while the element read
        // wraps ~4 GB OOB (crafted container with veStart near 0xFFFFFFFF).
        if (veCount <= 32 &&
            size_t(so) + 36 + (size_t(veStart) + veCount + 32) * 4 <= out.virtualSize) {
            for (uint32_t ve = 0; ve < veCount; ++ve) {
                uint32_t val = ReadBE32(sp + 36 + (size_t(veStart) + ve) * 4);
                VertexInput vi;
                vi.address    = val & 0xFFF;
                vi.usage      = (val >> 12) & 0xF;
                vi.usageIndex = (val >> 16) & 0xF;
                out.vertexElements.push_back(vi);
            }
            // VS interpolators: emitted outputs, stored right after the vertex
            // elements in the same array.
            const uint32_t interpCount = out.interpolatorCount();
            if (interpCount <= 32 && size_t(so) + 36 +
                                         (size_t(veStart) + veCount + interpCount) * 4 <=
                                     out.virtualSize) {
                for (uint32_t i = 0; i < interpCount; ++i) {
                    uint32_t word = ReadBE32(sp + 36 + (size_t(veStart) + veCount + i) * 4);
                    VertexInput in;
                    in.usageIndex = (word >> 0) & 0xF;
                    in.usage      = (word >> 4) & 0xF;
                    in.reg        = (word >> 8) & 0xF;
                    out.interpolators.push_back(in);
                }
            }
        }
    } else {
        // PS: field18 (sp+24), outputs (sp+28), interpolators (sp+32...)
        uint32_t psOutputs = ReadBE32(sp + 28);
        out.pixelOutputs.color0 = (psOutputs & 0x01) != 0;
        out.pixelOutputs.color1 = (psOutputs & 0x02) != 0;
        out.pixelOutputs.color2 = (psOutputs & 0x04) != 0;
        out.pixelOutputs.color3 = (psOutputs & 0x08) != 0;
        out.pixelOutputs.depth  = (psOutputs & 0x10) != 0;

        // Interpolator table follows the outputs field. Each entry is
        // Interpolator { usageIndex:4, usage:4, reg:4, pad:20 }.
        const uint32_t interpCount = out.interpolatorCount();
        if (interpCount <= 32 && size_t(so) + 32 + size_t(interpCount) * 4 <= out.virtualSize) {
            for (uint32_t i = 0; i < interpCount; ++i) {
                uint32_t word = ReadBE32(sp + 32 + i * 4);
                VertexInput in;
                in.usageIndex = (word >> 0) & 0xF;
                in.usage      = (word >> 4) & 0xF;
                in.reg        = (word >> 8) & 0xF;
                out.interpolators.push_back(in);
            }
        }
    }

    return true;
}


// FNV-1a 64-bit
static constexpr uint64_t kFNV1aOffset = 14695981039346656037ULL;
static constexpr uint64_t kFNV1aPrime  = 1099511628211ULL;
static void Hash(uint64_t& h, const void* data, size_t len) {
    const uint8_t* p = static_cast<const uint8_t*>(data);
    for (size_t i = 0; i < len; ++i) {
        h ^= uint64_t(p[i]);
        h *= kFNV1aPrime;
    }
}
template<typename T> static void HashVal(uint64_t& h, const T& v) {
    Hash(h, &v, sizeof(v));
}
template<typename T> static void HashBE32(uint64_t& h, T v) {
    uint32_t be = uint32_t(v);
    // hash in big-endian to match guest representation
    uint8_t b[4] = {uint8_t(be>>24), uint8_t(be>>16), uint8_t(be>>8), uint8_t(be)};
    Hash(h, b, 4);
}

uint64_t ComputeShaderProgramHash(const ShaderProgram& prog) {
    uint64_t h = kFNV1aOffset;

    HashVal(h, prog.isVertex);
    HashBE32(h, prog.flags);
    HashBE32(h, prog.virtualSize);
    HashBE32(h, prog.physicalSize);
    HashBE32(h, prog.physicalOffset);
    HashBE32(h, prog.shaderSize);
    HashBE32(h, prog.fieldC);
    HashBE32(h, prog.field10);
    HashBE32(h, prog.interpolatorInfo);

    uint32_t icount = uint32_t(prog.instructions.size());
    HashVal(h, icount);
    for (const auto& ir : prog.instructions) {
        HashBE32(h, ir.address);
        HashVal(h, ir.isFetch);
        HashVal(h, ir.decoded.kind);
        // hash the first two dwords of the decoded instruction
        // (opcode + dest + src fields) as a stable fingerprint
        HashBE32(h, ir.decoded.fetchOpcode);
        HashBE32(h, ir.decoded.dstRegister);
        HashBE32(h, ir.decoded.srcRegister);
        HashBE32(h, ir.decoded.constIndex);
        HashVal(h, ir.decoded.unknown);
    }

    return h;
}

}  // namespace mcla::renderer
