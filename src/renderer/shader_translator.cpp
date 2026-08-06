#include "shader_translator.h"

#include <cstring>

namespace mcla::renderer {

bool ParseShaderContainer(const uint8_t* data, size_t size,
                          ShaderProgram& prog, TranslatedShader& out) {
    if (!ParseShaderProgram(data, size, prog))
        return false;
    out.isVertex = prog.isVertex;
    out.programHash = ComputeShaderProgramHash(prog);
    return true;
}

bool HashShaderContainer(const uint8_t* data, size_t size, bool& isVertex, uint64_t& programHash) {
    ShaderProgram prog;
    if (!ParseShaderProgram(data, size, prog))
        return false;
    isVertex = prog.isVertex;
    programHash = ComputeShaderProgramHash(prog);
    return true;
}

// Translation of HLSL/DXIL is intentionally delegated to the offline tool in
// this stage: mcla.exe does not link the recompiler or DXC. The parse+hash half
// above is what the runtime pipeline key needs. This seam returns the parsed
// metadata and leaves dxil empty (dxilOk=false) until a backend is wired.
bool TranslateShader(const uint8_t* container, size_t size,
                     std::string_view /*commonHeader*/, TranslatedShader& out) {
    ShaderProgram prog;
    if (!ParseShaderContainer(container, size, prog, out))
        return false;
    out.error.clear();
    return true;
}

} // namespace mcla::renderer
