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
};

// Parse + hash a shader container. Fills `prog` with the normalized IR and
// `out` with the stage + program hash. Returns false if the container header is
// malformed. This is what feeds the pipeline key.
bool ParseShaderContainer(const uint8_t* data, size_t size,
                          ShaderProgram& prog, TranslatedShader& out);

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
