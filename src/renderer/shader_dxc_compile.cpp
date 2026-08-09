#include "shader_translator.h"
#include "dxc_runtime.h"
#include "xenos_shader_ir.h"

namespace mcla::renderer {

bool CompileShaderToDxil(const uint8_t* container, size_t size,
                         const DxcRuntime& dxc, TranslatedShader& out) {
    // Parse the container to get the IR and HLSL source
    ShaderProgram prog;
    if (!ParseShaderContainer(container, size, prog, out)) {
        out.error = "ParseShaderContainer failed";
        return false;
    }

    if (out.hlsl.empty()) {
        out.error = "Generated HLSL is empty";
        return false;
    }

    // Determine profile from shader stage
    const std::string_view profile = out.isVertex ? "vs_6_0" : "ps_6_0";

    // Compile via runtime DXC
    std::string error;
    std::vector<uint8_t> dxil;
    if (!dxc.Compile(out.hlsl, "main", profile, dxil, error)) {
        out.error = "DXC compile failed: " + error;
        return false;
    }

    out.dxil = std::move(dxil);
    out.dxilOk = true;
    return true;
}

} // namespace mcla::renderer