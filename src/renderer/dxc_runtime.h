#pragma once

// Phase 5 runtime DXC (HLSL -> DXIL) compiler.
//
// REQUIREMENT (F-609): mcla.exe does not link DXC. Every real (non-test)
// pipeline needs dxil.dll + dxcompiler.dll at RUN TIME, and a missing pair is
// not a degradation -- it means no real PSO exists for the life of the process
// and every draw stays on the test PSO. The deploy requirement is therefore
// explicit and reported, not an environment accident:
//
//   * Set MCLA_DXC_DIR to a directory containing BOTH dxil.dll and
//     dxcompiler.dll, or
//   * place that pair beside mcla.exe, or
//   * ship them in third_party/dxc/bin/x64 next to the executable.
//
// `third_party/dxc` in this repository ships `inc/` (headers) only -- there is
// no `bin/` -- so that candidate cannot satisfy the requirement from the repo
// alone; only the read-only local XenosRecomp checkout under
// .research/XenosRecomp/thirdparty/dxc-bin/bin/x64 has a pair today. Both
// in-tree callers pass an empty `dllDir`, so MCLA_DXC_DIR (or DLLs beside the
// exe) is the supported route. Load() enumerates every candidate it tried, with
// the reason each was rejected, and the pipeline worker prints one FATAL line
// naming the fix -- a silent fallback to the test PSO is the failure mode this
// header exists to prevent.
//
// Threading: DXC COM compiler objects are not thread-safe. Create one
// DxcRuntime per thread that compiles; the DLLs stay loaded for the process
// lifetime.

#include <cstdint>
#include <string>
#include <string_view>
#include <vector>

namespace mcla::renderer {

class DxcRuntime {
public:
    // Shader models. The translator emits a complete `main()` for a 6.0
    // graphics shader, and the generated HLSL uses only SM6.0-legal features
    // (cbuffer, Texture*, SamplerState, SV_*). The worker and every offline
    // validator use these names so the target is stated in exactly one place:
    // promoting to 6.x is a one-line change here plus a corpus re-run.
    static constexpr const char* kVertexProfile = "vs_6_0";
    static constexpr const char* kPixelProfile = "ps_6_0";

    // D3D_SIT_* values, restated because d3dcommon.h is not in this header's
    // include set. Numbers are from the Windows SDK d3dcommon.h and are stable.
    static constexpr uint32_t kSitCbuffer = 6;
    static constexpr uint32_t kSitTexture = 2;
    static constexpr uint32_t kSitSampler = 5;
    static constexpr uint32_t kSitStructuredBuffer = 14;
    static constexpr uint32_t kSitByteAddressBuffer = 26;

    DxcRuntime();
    ~DxcRuntime();
    DxcRuntime(const DxcRuntime&) = delete;
    DxcRuntime& operator=(const DxcRuntime&) = delete;
    DxcRuntime(DxcRuntime&&) = delete;
    DxcRuntime& operator=(DxcRuntime&&) = delete;

    // Loads dxil.dll + dxcompiler.dll and resolves DxcCreateInstance.
    // `dllDir` may be empty to use the default search order (see the deploy
    // requirement above). On success fills `usedDir` with the directory that
    // provided the DLLs. Returns false and fills `error` when the DLLs or the
    // API are unavailable; `error` lists every candidate directory that was
    // tried and why each was rejected, so the log names the fix instead of
    // just "not found".
    bool Load(std::string_view dllDir, std::string& usedDir, std::string& error);

    // Compiles complete HLSL source into a DXIL blob. `entry` defaults to
    // "main"; `profile` is normally kVertexProfile / kPixelProfile. True on
    // success; on failure `error` receives the ENTIRE DXC_OUT_ERRORS buffer --
    // every diagnostic line verbatim, not just the first one -- or the fixed
    // text "DXC compile failed (no diagnostics)" when that buffer is
    // absent/empty. `dxil` is cleared on entry, so it stays empty either way.
    // If `keepReflection` is true, the output DXIL will contain reflection data
    // suitable for ID3D12ShaderReflection.
    bool Compile(std::string_view hlsl, std::string_view entry,
                 std::string_view profile, std::vector<uint8_t>& dxil,
                 std::string& error, bool keepReflection = false) const;

    // One reflected shader-visible binding.
    struct ResourceBinding {
        uint32_t type = 0;                   // D3D_SIT_* (see the kSit* above)
        uint32_t register_ = 0;             // shader register (t/s/b/u)
        uint32_t space_ = 0;                // register space
        uint32_t byteSize = 0;              // CBV size in bytes (0 otherwise)
        uint32_t firstVariableRegister = 0; // first c#/t#/s# the CBV covers
    };

    // Reflects a compiled DXIL blob: every CBV (with the byte size the draw
    // path's upload needs) and every SRV/sampler, so the caller can REFUSE a
    // shader that binds a register the shared root signature does not declare
    // instead of creating a PSO that reads a descriptor table slot that does not
    // exist.
    bool ReflectBindings(const std::vector<uint8_t>& dxil,
                         std::vector<ResourceBinding>& out,
                         std::string& error) const;

    // Reflects a compiled DXIL blob to extract CBV register bindings. Thin
    // wrapper over ReflectBindings.
    struct CbvBinding {
        uint32_t register_ = 0;
        uint32_t space_ = 0;
        uint32_t byteSize = 0;
        uint32_t firstVariableRegister = 0;
    };
    bool ReflectCbvBindings(const std::vector<uint8_t>& dxil,
                            std::vector<CbvBinding>& outCbvs,
                            std::string& error) const;

    // The directory the loaded DLLs came from (empty when not loaded).
    const std::string& UsedDir() const;

    explicit operator bool() const { return impl_ != nullptr && loaded_; }

private:
    struct Impl;
    Impl* impl_ = nullptr;
    bool loaded_ = false;
    std::string usedDir_;
};

} // namespace mcla::renderer
