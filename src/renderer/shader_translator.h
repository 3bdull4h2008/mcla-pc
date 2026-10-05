#pragma once

// Phase 5 runtime-facing shader translation seam.
//
// TranslateShader translates a captured guest .fxc container into HLSL at
// runtime (guest container parse -> xenos_shader_ir decode -> HLSL emitter),
// and the resulting HLSL is compiled to DXIL by the background pipeline
// worker (DxcRuntime) in pipeline_cache.cpp. The offline corpus gate
// (shader_pipeline_validator) guarantees every generated HLSL compiles under
// dxc.exe, so non-empty runtime HLSL is worker-compilable. This module also
// parses containers into the normalized IR for stable program hashes,
// vertex-input layout, and shader-stage info.

#include "xenos_shader_ir.h"

#include <cstdint>
#include <string>
#include <string_view>
#include <vector>

namespace mcla::renderer {

// Result of translating one .fxc shader container to HLSL (+ optional DXIL).
struct TranslatedShader {
    bool isVertex = false;
    uint64_t programHash = 0;      // stable hash of the parsed IR
    std::string hlsl;              // generated HLSL source (empty unless translated)
    std::vector<uint8_t> dxil;     // compiled DXIL (empty unless compiled)
    bool dxilOk = false;
    std::string error;             // last translation/compile error
    uint64_t instructionCount = 0; // decoded instructions processed
    uint64_t unknownOpcodeCount = 0;   // instructions with no decoder table entry
    uint64_t unsupportedOpcodeCount = 0; // instructions with no lowering (never dropped)

    // Did this translation's vertex epilogue actually carry the clip_disable
    // rescale? FALSE means it was emitted as the IDENTITY because no viewport
    // extent had been published yet, i.e. SetClipDisableViewportExtent had not
    // been called when this program was translated.
    //
    // It is set from what AppendEpilogue DID, not from a re-read of the global,
    // so it cannot disagree with the HLSL in `hlsl`. Only meaningful when
    // `isVertex` is true: a pixel program writes no position and nothing is
    // withheld, so it reads true.
    //
    // WHY IT IS HERE. The identity is a defensible choice -- it asserts no
    // number nobody measured -- but it is UNDETECTABLE from the outside: the
    // only trace was a comment inside the generated HLSL, which no caller reads
    // and no census counts. A caller that keys a pipeline on this HLSL would
    // cache a geometry-less vertex program with nothing to show for it. This
    // field is the seam that lets the owner of the call ORDER see it.
    //
    // MEASURED (build/w707.log, 2026-10-04): the one extent publication in that
    // soak, d3d12_backend.cpp:3157 inside the first draw, happened at 06:57:37.295
    // -- AFTER that draw's vertex program was translated at 06:57:37.262
    // (timestamped by the unwritten-register row this very call emits two lines
    // above AppendEpilogue, shader_translator.cpp:586). So the first draw's
    // program carries this field false and the second draw's carries it true,
    // and the two are byte-identical guest programs as far as AppendEpilogue is
    // concerned. Ordering harness: %TEMP%\opencode\clipgate\run1.txt.
    bool clipRescaleBaked = true;
};

// Parse + hash a shader container. Fills `prog` with the normalized IR and
// `out` with the stage + program hash. Returns false if the container header is
// malformed. This is what feeds the pipeline key.
//
// `psNumReg` is SQ_PROGRAM_CNTL.ps_num_reg, threaded to the pixel interpolant
// derivation; see ShaderProgram::psNumReg. Defaulted, and 0 is the initialiser
// rather than a guest value.
bool ParseShaderContainer(const uint8_t* data, size_t size,
                          ShaderProgram& prog, TranslatedShader& out,
                          uint32_t psNumReg = 0u);

// Convenience wrapper: parse + hash without keeping the full IR.
bool HashShaderContainer(const uint8_t* data, size_t size, bool& isVertex, uint64_t& programHash);

// Runtime translation contract. The heavy half (HLSL/DXIL generation) is
// provided by the offline translation tool today. Returns true if the container
// parsed successfully; `out.dxilOk` reports whether a compiled blob was produced.
bool TranslateShader(const uint8_t* container, size_t size,
                     std::string_view commonHeader, TranslatedShader& out);

// Reflected vertex input for pipeline input-layout creation: the exact
// (usage, usageIndex) pair the generated VS entry signature consumes, plus the
// format/stride/offset of the first vertex fetch that resolves to it.
struct VertexInputRef {
    uint32_t usage = 0;        // DeclUsage (see the kUsageVariables table)
    uint32_t usageIndex = 0;
    uint32_t vertexFormat = 0; // Xenos 6-bit vf code (0 when unresolved)
    uint32_t stride = 0;
    int32_t offset = 0;
};

// HLSL semantic name for a DeclUsage value (POSITION, TEXCOORD, ...).
// Out-of-range usages clamp to the first entry (POSITION), matching the
// translator's vertex-input fallback.
const char* VertexUsageSemanticName(uint32_t usage);

// One authoritative vertex-input semantic, in the order the D3D12 input layout
// presents it (BuildGrcFvfInputLayout emits ascending byteOffset). `usage` and
// `usageIndex` are the same DeclUsage numbering VertexUsageSemanticName and
// grc_fvf_decode's lane table use, so a semantic computed here and a lane
// decoded there name the same thing.
struct VertexInputSemantic {
    uint32_t usage = 0;
    uint32_t usageIndex = 0;
};

// The VERTEX shader a pixel shader is being paired with, plus the one piece of
// register state the reference's interpolator count reads.
//
// WHY A CALLER HAS TO SUPPLY IT. The reference's GPR seed is a PER-DRAW value: it
// is `VS.writes_interpolators() & PS.GetInterpolatorInputMask(SQ_PROGRAM_CNTL,...)`
// (vulkan_command_processor.cc:2206-2211,
// d3d12/d3d12_command_processor.cc:2081-2086), and the one resulting mask is
// handed to BOTH stages (:2088, :2093). A container therefore cannot carry it --
// the same pixel shader paired with two vertex shaders takes two different seeds --
// so it has to reach the translator out of band. TranslateShaderPinned receives
// CONTAINER BYTES, so this struct is the only channel, and it is why a defaulted
// trailing parameter was added rather than a second entry point:
// TranslateShaderPinned stays the single translation entry point this file needs.
//
// A null `pairing` (the default, and every call site with no VS) means NO PAIRING
// IS KNOWN, and the mask is then 0 -- the reference's own mask-0 behaviour, which
// seeds every unwritten GPR with zero. It is NOT a fallback that keeps the pixel
// shader's own candidates: an unpaired PS must not claim an interpolant nothing
// supplied (see ApplyInterpolatorIntersection).
struct PixelShaderPairing {
    // The paired vertex shader's container bytes, exactly as they will be given to
    // ParseShaderProgram. Null (or a zero size) means "no known VS".
    const uint8_t* vsContainer = nullptr;
    size_t vsContainerSize = 0;
    // SQ_PROGRAM_CNTL.ps_num_reg, the raw "count minus 1" field
    // (.research/xenia/src/xenia/gpu/registers.h:136). 0 is the INITIALISER, not a
    // guest value; see ShaderProgram::psNumReg. It reaches the interpolator count
    // only for a program using register dynamic addressing
    // (.research/xenia/src/xenia/gpu/shader.h:938-945).
    uint32_t psNumReg = 0;
};

// Translate with the VS entry signature PINNED to an authoritative input
// layout, so the semantics the PSO is created against are the ones the input
// assembler actually supplies.
//
// Why this exists (F-609 item 4): the fetch-resolution path derives a semantic
// per vertex FETCH (matching a fetch IR address against a program
// vertexElement address, else falling back to vertexElements[0]), and the
// input layout was built from the draw's grcFvf lanes by a DIFFERENT mapping.
// Two different namings for the same buffer produce either a PSO-create failure
// or a shader fed garbage. Pinning removes the second naming: the signature can
// only use semantics the layout supplies.
//
// Matching rule, in order, and refusing when none applies:
//   1. exact (usage, usageIndex);
//   2. the layout's single element with the same `usage` (only when exactly one
//      such element exists, so an ambiguous layout cannot be resolved by luck);
//   3. otherwise UNBOUND -> false.
//
// Returns false and fills `error` when the container fails to parse, translation
// produced no HLSL, the program is not a vertex shader while a layout was given,
// or any resolved input is UNBOUND. `out` is left reset on failure.
//
// `pairing` is the paired VERTEX shader for a pixel-shader translation; see
// PixelShaderPairing. It is ignored for a vertex program, which is what the
// reference's own asymmetry requires: writes_interpolators() is a vertex-shader
// property (a pixel shader has no kInterpolator result target,
// .research/xenia/src/xenia/gpu/shader_translator.cc:1319-1339).
bool TranslateShaderPinned(const uint8_t* container, size_t size,
                          const VertexInputSemantic* layout, size_t layoutCount,
                          TranslatedShader& out, std::string& error,
                          const PixelShaderPairing* pairing = nullptr);

// Publishes the render-target extent (in pixels) that the vertex-shader
// clip_disable rescale is built from, so the generated HLSL's constants and the
// backend's D3D12 viewport cannot disagree.
//
// WHY IT EXISTS. The guest runs with PA_CL_CLIP_CNTL bit 16 (clip_disable) set
// and all six PA_CL_VTE_CNTL vport_*_ena clear -- MEASURED, build/w706.log:
//1676-1678 prints r2204=00010000 and r2206=00000300 for every draw. With no
// clip volume and no VTE viewport transform, the vertex shader's POSITION output
// is in guest pixels, and the reference converts those to host clip space inside
// the vertex shader rather than with a host viewport
// (.research/xenia/src/xenia/gpu/draw_util.cc:362-386, applied at
// spirv_shader_translator.cc:1612-1624; that checkout has no .git and 0 files in
// HEAD, so the citations are trail, not authority).
//
// `extentX`/`extentY` are the RENDER TARGET size, not the viewport rectangle.
// The reference's extent is min(8192, RT extent), so a 1280x720 target uses
// 1280x720. Returns false if either extent is zero, leaving the previous value
// in place.
//
// Call this before translating any vertex shader, and again whenever the render
// target is resized. Not atomic with respect to an in-flight translation; see
// the definition in shader_translator.cpp.
bool SetClipDisableViewportExtent(uint32_t extentX, uint32_t extentY);

// The clip_disable rescale currently baked into vertex-shader output, read back
// so a diagnostic in the backend reports the SAME numbers the shader uses rather
// than recomputing them (two copies of this arithmetic would eventually disagree,
// and the disagreement would be invisible).
struct ClipDisableRescaleConstants {
    float scaleX = 0.0f, scaleY = 0.0f, scaleZ = 1.0f;
    float offsetX = 0.0f, offsetY = 0.0f, offsetZ = 0.0f;
    bool valid = false;   // false until SetClipDisableViewportExtent has accepted one
};

// Fills `out` with the constants described above. Returns false (leaving `out`
// reset) when no extent has been accepted yet.
bool QueryClipDisableRescale(ClipDisableRescaleConstants* out);

// One-shot note explaining that the rescale's GATE (whether a given draw has
// clip_disable set with the vport enables clear) is a MEASURED constant rather
// than a per-draw register read, and citing where it was measured. Logged once
// per process by the backend. Names no tracked marker on purpose.
extern const char* const kClipDisableRescaleGateNote;

// Vertex inputs the VS entry signature must declare, resolved exactly the way
// the generator resolves a vertex fetch (vertex element by slot address, else
// the first element). The translator uses this for the entry signature; offline
// PSO smoke tests use it to build the input layout. Empty for pixel shaders.
std::vector<VertexInputRef> ReferencedVertexInputs(const ShaderProgram& prog);

// DXC is only linked into offline validator targets; mcla.exe never links it.
class DxcRuntime;

// Compile the translated HLSL for `container` to DXIL via `dxc`. Sets
// out.dxil / out.dxilOk / out.error. Returns false on any failure.
// Implemented in shader_dxc_compile.cpp, which the mcla target does not build.
bool CompileShaderToDxil(const uint8_t* container, size_t size,
                         const DxcRuntime& dxc, TranslatedShader& out);

}
