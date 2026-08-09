#pragma once

// Phase 5 runtime DXC (HLSL -> DXIL) compiler.
//
// DXC is NOT linked into mcla.exe; this module loads dxcompiler.dll +
// dxil.dll dynamically at runtime (LoadLibrary) so a DXIL blob can be produced
// at pipeline-key time without a compile-time dependency on the shader
// compiler. The DLL pair is resolved from, in priority order: an explicit
// directory, the MCLA_DXC_DIR environment variable, the vendored
// `.research/XenosRecomp/thirdparty/dxc-bin/bin/x64` tree, then the
// executable's directory.
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
    DxcRuntime();
    ~DxcRuntime();
    DxcRuntime(const DxcRuntime&) = delete;
    DxcRuntime& operator=(const DxcRuntime&) = delete;
    DxcRuntime(DxcRuntime&&) = delete;
    DxcRuntime& operator=(DxcRuntime&&) = delete;

    // Loads dxil.dll + dxcompiler.dll and resolves DxcCreateInstance.
    // `dllDir` may be empty to use the default search order. On success fills
    // `usedDir` with the directory that provided the DLLs. Returns false and
    // fills `error` when the DLLs or the API are unavailable.
    bool Load(std::string_view dllDir, std::string& usedDir, std::string& error);

    // Compiles complete HLSL source into a DXIL blob. `entry` defaults to
    // "main"; `profile` is "vs_6_0" or "ps_6_0". True on success; on failure
    // `error` holds the first DXC diagnostic and `dxil` stays empty.
    bool Compile(std::string_view hlsl, std::string_view entry,
                 std::string_view profile, std::vector<uint8_t>& dxil,
                 std::string& error) const;

    explicit operator bool() const { return impl_ != nullptr && loaded_; }

private:
    struct Impl;
    Impl* impl_ = nullptr;
    bool loaded_ = false;
};

}
