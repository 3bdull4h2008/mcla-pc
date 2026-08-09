#pragma once

// Normalized, pipeline-keyable shader program model for the MCLA native
// renderer (Phase 5). Builds on xenos_microcode.h:
//   - Parses a Rockstar .fxc shader container into stable metadata
//     (constant table, definition table, interpolators, vertex elements,
//     pixel outputs).
//   - Decodes the microcode into a flat, program-relative IR instruction
//     list (CF-bounded, see ComputeControlFlowByteBound).
//   - Produces a deterministic 64-bit program hash usable as a component of a
//     pipeline key.
//
// All multi-byte guest fields are big-endian; reads go through explicit BE
// assembly only.

#include "xenos_microcode.h"

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>

namespace mcla::renderer {

// D3DXREGISTER_SET (see D3DXSHADER_CONSTANTINFO).
enum class RegisterSet : uint16_t {
    Bool = 0,
    Int4 = 1,
    Float4 = 2,
    Sampler = 3,
};

const char* RegisterSetName(RegisterSet set);

// One D3DXSHADER_CONSTANTINFO from the constant table.
struct ConstantInfo {
    uint32_t nameOffset = 0;      // byte offset of name within the constant table
    RegisterSet registerSet = RegisterSet::Float4;
    uint16_t registerIndex = 0;
    uint16_t registerCount = 0;
    uint16_t reserved = 0;
    uint32_t typeInfo = 0;        // byte offset of D3DXSHADER_TYPEINFO
    uint32_t defaultValue = 0;
};

// D3DXSHADER_TYPEINFO.
struct ConstantTypeInfo {
    uint16_t parameterClass = 0;  // D3DXPARAMETER_CLASS
    uint16_t parameterType = 0;   // D3DXPARAMETER_TYPE
    uint16_t rows = 0;
    uint16_t columns = 0;
    uint16_t elements = 0;
    uint16_t structMembers = 0;
    uint32_t structMemberInfo = 0;
};

constexpr size_t kTypeInfoSize = 24;  // 4+4+2+2+2+2+4 (D3DXSHADER_TYPEINFO)
constexpr size_t kStructMemberInfoSize = 8;

// A constant plus its resolved name and type info.
struct ConstantEntry {
    std::string name;
    ConstantInfo info;
    ConstantTypeInfo type;
};

// Vertex-stream / interpolator surfaces (decl usage + index).
struct VertexInput {
    uint16_t usage = 0;      // DeclUsage
    uint16_t usageIndex = 0;
    uint16_t address = 0;    // placement in the vertex stream (VS)
    uint16_t reg = 0;        // guest register target (PS interpolators)
};

// Pixel shader render-target outputs.
struct PixelOutputs {
    bool color0 = false, color1 = false, color2 = false, color3 = false;
    bool depth = false;
};

// A decoded instruction in program order. `address` is the instruction index
// within the microcode program (cf.address + i), in 12-byte instruction units.
struct IrInstruction {
    uint32_t address = 0;
    bool isFetch = false;       // from the exec sequence bit (vs ALU)
    DecodedInstruction decoded;
};

// The whole normalized program: metadata + decoded instruction stream.
struct ShaderProgram {
    bool isVertex = false;

    // Container geometry.
    uint32_t flags = 0;
    uint32_t virtualSize = 0;
    uint32_t physicalSize = 0;

    // shader header
    uint32_t physicalOffset = 0;
    uint32_t shaderSize = 0;    // microcode size (bytes)
    uint32_t fieldC = 0;        // (fieldC >> 8) & 0xFF == svPos register
    uint32_t field10 = 0;
    uint32_t interpolatorInfo = 0; // (interpolatorInfo >> 5) & 0x1F == interpolator count

    // constants (constant table) and float4/int4 default values (definition
    // table). definition values are kept raw; the translator will interpret.
    std::vector<ConstantEntry> constants;
    std::vector<VertexInput> vertexElements;   // VS
    std::vector<VertexInput> interpolators;    // PS
    PixelOutputs pixelOutputs;                 // PS
    std::vector<uint32_t> float4DefaultValues; // raw BE-assembled dwords
    std::vector<uint32_t> int4DefaultValues;   // raw BE-assembled dwords

    // decoded IR in program order
    std::vector<IrInstruction> instructions;

    uint32_t interpolatorCount() const { return (interpolatorInfo >> 5) & 0x1F; }
    uint32_t svPosRegister() const { return (fieldC >> 8) & 0xFF; }
};

// Parse one container located at `data` (must point at a valid .fxc container
// header). Returns false if the container header is malformed.
bool ParseShaderProgram(const uint8_t* data, size_t size, ShaderProgram& out);

// Walk a stream of containers (as in a .fxc file, whose containers can sit at
// variable offsets) and invoke `cb` for each valid container with the container
// start. cb returns false to stop. Returns the number of containers visited.
template <typename Fn>
size_t VisitShaderContainers(const uint8_t* data, size_t size, Fn&& cb) {
    size_t i = 0;
    size_t count = 0;
    while (i + 36 <= size) {
        uint32_t flags = AssembleBE32(data + i);
        uint32_t vsize = AssembleBE32(data + i + 4);
        uint32_t psize = AssembleBE32(data + i + 8);
        uint32_t field1C = AssembleBE32(data + i + 28);
        uint32_t field20 = AssembleBE32(data + i + 32);
        if ((flags & 0xFFFFFF00) == 0x102A1100 && field1C == 0 && field20 == 0 &&
            size_t(vsize) + size_t(psize) <= size - i) {
            if (!cb(i)) break;
            ++count;
            i += size_t(vsize) + size_t(psize);
        } else {
            i += 4;
        }
    }
    return count;
}

// Deterministic 64-bit hash of the normalized program + metadata. Stable
// across runs; changes when any decode/parser change alters the IR
// (intentionally sensitive so pipeline keys stay correct).
uint64_t ComputeShaderProgramHash(const ShaderProgram& prog);

}
