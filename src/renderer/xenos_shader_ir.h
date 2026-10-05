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
    // VertexFetch WORD 1 bits 30-31, packed bit0 = is_mini_fetch, bit1 =
    // is_predicated. VertexFetch word 1 reads, in order and to 32 bits exactly:
    // dst_swizzle:12(0-11), format_comp_all:1(12), num_format_all:1(13),
    // signed_rf_mode_all:1(14), is_index_rounded:1(15), format:6(16-21),
    // reserved2:2(22-23), exp_adjust:6(24-29), is_mini_fetch:1(30),
    // is_predicated:1(31) -- .research/xenia/src/xenia/gpu/ucode.h:761-771,
    // spelled out again at xenos_microcode.cpp:147-155.
    //
    // THE POSITION IS VERTEXFETCH-WORD-1-ONLY, and the difference matters:
    // tfetch word 1 is_predicated is ALSO bit 31 (ucode.h:866,
    // xenos_microcode.cpp:185), but ALU word 1 is_predicated is bit 28
    // (ucode.h:2076, xenos_microcode.cpp:231). One position, three layouts --
    // so "bit 28" is a true statement about an ALU instruction and a false one
    // about a vertex fetch, and a reader must not carry it across.
    //
    // WHY 30/31 -- MEASURED, NOT READ OFF THE DOC, because a reference
    // implementation is a hypothesis until the raw words agree. The live draw-1
    // pair discriminates it (build/w686.log, CP-SHADER-BODY #3 against
    // CP-FETCHVB-DESC #1; the same bodies and lines recur in w685):
    //   FULL fetch word1 = 0x00393A88 -> strideDwords=7, miniFetch=0
    //   MINI fetch word1 = 0x40263688 -> strideDwords=0, miniFetch=1
    // The second line's dstSwizzle=688 is exactly that word's low 12 bits, so
    // the log line and the raw word are the same instruction and not two
    // look-alikes. The guest set exactly one mini fetch and it is the bit-30
    // word: bit 30 is 0 on the full and 1 on the mini, while bit 28 is 0 on
    // BOTH and therefore cannot be the flag. What makes a fetch a mini is
    // measured too -- stride 0 in its own word2, inheriting the previous full
    // fetch's stride (.research/xenia/src/xenia/gpu/shader_translator.cc
    // :1022-1023 and :1045; the rule this project's stride inheritance applies,
    // in shader_translator.cpp's ReferencedVertexInputs).
    //
    // Second, structural, argument. Bits 22-23 are reserved2 and read 0 on every
    // vfetch word1 reachable from this tree: 4 unique values over 15 instruction
    // instances -- 0x00393A88 (n=4), 0x40263688 (n=4), 0x00253B48 (n=5) from
    // CP-SHADER-BODY #3/#5/#6/#8/#200 across build/w685.log and build/w686.log,
    // and 0x00008800 (n=2) from the 166-file .fxc corpus (164 files under
    // build/assets plus build/tq_vs.fxc and build/tq_ps.fxc).
    // A reserved field is not arbitrary, so bits 22-23 cannot be the head of
    // exp_adjust:6; exp_adjust therefore starts at 24 and the two flags land on
    // 30 and 31, which is also the only split that fills the word to 32.
    // Provenance, stated because it is NOT re-derivable from this tree: a wider
    // census of 70 unique vfetch word1 values from 25 validated microcode
    // containers reports bits 22-23 = 0 on 70/70. That number was handed to
    // this comment by the agent that fixed xenos_microcode.cpp; no corpus on
    // this machine yields 70 values, so treat the 4-value census above as the
    // reproducible half and the 70/70 as reported, not re-measured here.
    //
    // DecodeInstruction reads the same two bits today (xenos_microcode.cpp
    // :167-168), and so does the CP-side decoder (src/gpu_cp.cpp:1295-1296), so
    // this packed copy is redundant rather than corrective. It is kept because
    // the derivation below must not depend on which layout a fetch uses, and it
    // is the site to fix if the two ever diverge again.
    //
    // HISTORY, kept because the wrong version was nearly as plausible: this
    // comment used to claim DecodedInstruction reads bits 28-29
    // (xenos_microcode.cpp:168-169) and that 0x40263688's "bit 28 = 0" is "what
    // DecodedInstruction reports". Both were false -- 168-169 is not even the
    // isMiniFetch read -- and the same false pair had already propagated into
    // shader_translator.cpp and xenos_shader_ir.cpp.
    //
    // UNFIXED SIBLING DEFECT, deliberately not corrected here (that file is not
    // this comment's to edit): xenos_microcode.cpp:165 reads expAdjust as
    // (word1 >> 22) & 0x3F where the layout above puts exp_adjust at 24-29 --
    // the same two-bit skew. Its START BIT is corroborated by the reserved2
    // argument above; its VALUE is UNVERIFIED, because (word1>>24)&0x3F and
    // (word1>>22)&0x3F both read 0 on all 4 unique vfetch word1 values above,
    // so no live sample distinguishes them. Do not "fix" it on the strength of
    // this paragraph alone; measure a word where the two readings differ first.
    uint8_t fetchFlagBits = 0;
    DecodedInstruction decoded;

    bool isMiniFetch() const { return (fetchFlagBits & 0x1) != 0; }
    bool isPredicatedFetch() const { return (fetchFlagBits & 0x2) != 0; }
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
    // Provenance of the two tables above. FALSE means the container's own
    // declaration tables produced them (the .fxc header path in
    // xenos_shader_ir.cpp). TRUE means the container declared no table and the
    // entries were derived from the program's OWN INSTRUCTION STREAM -- every
    // field traced back to a guest word, the semantic NAME being the only
    // conventional part (see DeriveVertexElementsFromInstructionStream).
    // Hashed by ComputeShaderProgramHash because it changes the emitted HLSL.
    bool vertexElementsDerived = false;
    bool interpolatorsDerived = false;
    PixelOutputs pixelOutputs;                 // PS
    std::vector<uint32_t> float4DefaultValues; // raw BE-assembled dwords
    std::vector<uint32_t> int4DefaultValues;   // raw BE-assembled dwords

    // decoded IR in program order
    std::vector<IrInstruction> instructions;

    uint32_t interpolatorCount() const { return (interpolatorInfo >> 5) & 0x1F; }
    uint32_t svPosRegister() const { return (fieldC >> 8) & 0xFF; }

    // ---- register state, NOT container bytes -------------------------------
    //
    // These four are SQ_PROGRAM_CNTL fields or analysis results rather than
    // anything the guest's container declares, so they are NOT read out of `data`
    // and NOT written into the host envelope. Saying so here is the point: the
    // envelope adapter (BuildProgramEnvelope, render_thread.cpp) exists to hand
    // ParseShaderProgram the guest's own bytes, and register state that reached it
    // through a container field would be indistinguishable from a guest
    // declaration -- which is the fabrication F-609 forbids.

    // SQ_PROGRAM_CNTL.ps_num_reg -- the raw FIELD, i.e. "GPR count minus 1"
    // (.research/xenia/src/xenia/gpu/registers.h:136), supplied by the caller.
    // DEFAULT 0 IS NOT A GUEST VALUE: it is the initialiser, and it means "no
    // capture reached this translation". Its only consequence is one term of
    // DynamicAddressableRegisterCount() (below); no code path reads it as "the
    // guest said zero", and a caller holding the register states so by passing
    // ParseShaderProgram's psNumReg argument.
    uint32_t psNumReg = 0;

    // Shader::writes_interpolators() (.research/xenia/src/xenia/gpu/shader.h:957):
    // which VS interpolants this program EXPORTS. VS only; 0 for a pixel program,
    // because a pixel shader has no kInterpolator result target
    // (.research/xenia/src/xenia/gpu/shader_translator.cc:1319-1339). Derived from
    // this program's own instruction stream -- see
    // DeriveVertexInterpolatorExports in xenos_shader_ir.cpp. A pure function of
    // the hashed instruction stream, so it needs no hash term of its own.
    uint32_t writesInterpolators = 0;
    bool writesInterpolator(uint32_t reg) const {
        return reg < 32u && (writesInterpolators & (1u << reg)) != 0u;
    }

    // register_static_address_bound(), GetDynamicAddressableRegisterCount() and the
    // dynamic-addressing flag they derive from
    // (.research/xenia/src/xenia/gpu/shader.h:938-945,
    //  shader_translator.cc:336-354, :532-543, :581-599), as measured by the pixel
    // interpolant derivation and kept so ApplyInterpolatorIntersection can report
    // the arithmetic without recomputing it. PS only. Pure functions of the hashed
    // stream plus psNumReg, and psNumReg carries its own hash term.
    uint32_t registerStaticBound = 0;
    uint32_t dynamicAddressableRegCount = 0;
    bool usesRegisterDynamicAddressing = false;
};

// Parse one container located at `data` (must point at a valid .fxc container
// header). Returns false if the container header is malformed.
//
// `psNumReg` is SQ_PROGRAM_CNTL.ps_num_reg (the raw "count minus 1" field), threaded
// to the pixel interpolant derivation because the reference's interpolator count
// needs it. It defaults to 0, which is the INITIALISER and not a guest value: see
// ShaderProgram::psNumReg. A container declares no such field, so there is
// deliberately no way to read it out of `data`.
bool ParseShaderProgram(const uint8_t* data, size_t size, ShaderProgram& out,
                        uint32_t psNumReg = 0u);

// The reference's PER-DRAW interpolator set, and the GPR seeding it decides.
//
// THE RULE, in the reference's own arithmetic:
//   .research/xenia/src/xenia/gpu/vulkan/vulkan_command_processor.cc:2206-2211
//       interpolator_mask = vertex_shader->writes_interpolators() &
//                           pixel_shader->GetInterpolatorInputMask(...)
//   .research/xenia/src/xenia/gpu/d3d12/d3d12_command_processor.cc:2081-2090
//       the same expression, and the ONE mask is handed to BOTH stages, which is
//       the equality asserted at d3d12/pipeline_cache.cc:1703-1704.
//   spirv_shader_translator.cc:2052-2070 (pixel) and :1300-1309 (vertex) -- and the
//   DXBC path this project's backend follows, dxbc_shader_translator.cc:685-701 --
//   read that same mask when seeding a GPR: interpolant `i` when
//   `i < kMaxInterpolators && (mask & (1 << i))`, else `const_float4_0_` /
//   `dxbc::Src::LF(0.0f)`.
//
//   GetInterpolatorInputMask is a PREFIX, not a read set
//   (.research/xenia/src/xenia/gpu/shader_translator.cc:336-354):
//       count = min(kMaxInterpolators,
//                   max(register_static_address_bound(),
//                       GetDynamicAddressableRegisterCount(ps_num_reg)))
//       mask  = (1 << count) - 1
//   and GetDynamicAddressableRegisterCount returns 0 unless the program uses
//   register dynamic addressing (.research/xenia/src/xenia/gpu/shader.h:938-945),
//   so ps_num_reg contributes ONLY to a dynamically-addressed program. Both facts
//   are load-bearing and both were got wrong here once; see
//   DerivePixelInterpolatorsFromInstructionStream.
//
// `vs == nullptr` means NO PAIRING IS KNOWN, and the mask is then 0 -- the
// reference's own mask-0 behaviour, which seeds every unwritten GPR with zero. It
// is deliberately NOT a fallback to "keep the PS's own candidates": an unpaired PS
// must not claim an interpolant nothing supplied.
struct InterpolatorIntersection {
    bool vsKnown = false;
    uint32_t vsWritesInterpolators = 0;  // VS.writes_interpolators()
    uint32_t psInputMask = 0;           // PS.GetInterpolatorInputMask()
    uint32_t psNumReg = 0;              // SQ_PROGRAM_CNTL.ps_num_reg, as supplied
    uint32_t staticBound = 0;           // register_static_address_bound()
    uint32_t dynamicRegCount = 0;       // GetDynamicAddressableRegisterCount()
    uint32_t interpolatorCount = 0;     // min(16, max(staticBound, dynamicRegCount))
    uint32_t intersected = 0;           // vsWritesInterpolators & psInputMask
    size_t candidatesBefore = 0;        // ps.interpolators before the intersection
    size_t kept = 0;                    // after
};

// Applies `intersected` to `ps` IN PLACE: an entry of `ps.interpolators` whose
// register bit is absent from the mask is dropped, because the reference declares
// no such PS input for it (dxbc_shader_translator.cc:2824-2853 builds the PS input
// signature from the mask alone) and so seeds the corresponding GPR with zero
// (dxbc_shader_translator.cc:689-700). `vs` may be null -- see the struct comment.
// Returns what it did, for the seed marker.
//
// NEVER ADDS an entry. The PS's candidate set comes from its own instruction stream
// (DerivePixelInterpolatorsFromInstructionStream) and this function can only remove
// from it. That is what makes an invented interpolant impossible here.
InterpolatorIntersection ApplyInterpolatorIntersection(ShaderProgram& ps,
                                                      const ShaderProgram* vs);

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
