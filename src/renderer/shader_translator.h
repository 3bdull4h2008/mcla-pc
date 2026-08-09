#pragma once

// Phase 5 runtime-facing shader translation seam.
//
// Full HLSL->DXIL translation is performed by the offline pipeline (see
// .research/SHADER_TRANSLATION_PIPELINE.md and XenosRecompValidate); mcla.exe
// does not link the recompiler or DXC. This module owns the parts the runtime
// needs at pipeline-key time: parse a .fxc container into the normalized IR
// (xenos_shader_ir) and derive a stable program hash / shader-stage info.
//
// The TranslateShader contract below is the integration point a runtime
// backend calls once it wires the recompiler backend in; today its heavy half
// is satisfied by the offline tool.

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

}
