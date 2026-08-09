#include "dxc_runtime.h"

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <unknwn.h>  // IUnknown for DXC COM interfaces
#include <dxc/dxcapi.h>
#include <wrl/client.h>

#include <cstdlib>
#include <vector>

namespace mcla::renderer {

namespace {

template <typename T>
using ComPtr = Microsoft::WRL::ComPtr<T>;

std::wstring ToWide(std::string_view s) {
    if (s.empty()) return {};
    const int n = MultiByteToWideChar(CP_UTF8, 0, s.data(), static_cast<int>(s.size()),
                                      nullptr, 0);
    std::wstring w(static_cast<size_t>(n), L'\0');
    MultiByteToWideChar(CP_UTF8, 0, s.data(), static_cast<int>(s.size()), w.data(), n);
    return w;
}

std::string WinErrorText(DWORD code) {
    char buf[512] = {};
    FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                   nullptr, code, 0, buf, static_cast<DWORD>(sizeof(buf)), nullptr);
    std::string s(buf);
    while (!s.empty() && (s.back() == '\n' || s.back() == '\r')) s.pop_back();
    return s;
}

std::string HexHr(HRESULT hr) {
    char buf[32] = {};
    std::snprintf(buf, sizeof(buf), "0x%08lX", static_cast<unsigned long>(hr));
    return buf;
}

}  // namespace

struct DxcRuntime::Impl {
    HMODULE dxil = nullptr;
    HMODULE dxcompiler = nullptr;
    DxcCreateInstanceProc createInstance = nullptr;
    ComPtr<IDxcUtils> utils;
    ComPtr<IDxcCompiler3> compiler;
};

DxcRuntime::DxcRuntime() : impl_(new Impl{}) {}

DxcRuntime::~DxcRuntime() {
    if (!impl_) return;
    impl_->utils.Reset();
    impl_->compiler.Reset();
    if (impl_->dxcompiler) FreeLibrary(impl_->dxcompiler);
    if (impl_->dxil) FreeLibrary(impl_->dxil);
    delete impl_;
    impl_ = nullptr;
}

bool DxcRuntime::Load(std::string_view dllDir, std::string& usedDir, std::string& error) {
    usedDir.clear();
    error.clear();
    if (loaded_) {
        usedDir = "";  // already loaded; caller should not need the dir
        return true;
    }
    if (!impl_) return false;

    // Candidate directories for the DXC DLL pair, in priority order.
    std::vector<std::string> dirs;
    if (!dllDir.empty()) dirs.push_back(std::string(dllDir));
    if (const char* env = std::getenv("MCLA_DXC_DIR"); env && *env)
        dirs.push_back(env);
    dirs.push_back(".research/XenosRecomp/thirdparty/dxc-bin/bin/x64");
    {
        char exe[1024] = {};
        const DWORD n = GetModuleFileNameA(nullptr, exe, sizeof(exe));
        if (n > 0 && n < sizeof(exe)) {
            std::string exePath(exe, n);
            const size_t sep = exePath.find_last_of("/\\");
            if (sep != std::string::npos) dirs.push_back(exePath.substr(0, sep));
        }
    }

    std::string dir;
    for (const auto& c : dirs) {
        if (c.empty()) continue;
        const std::string sep =
            (!c.empty() && (c.back() == '/' || c.back() == '\\')) ? "" : "\\";
        if (GetFileAttributesA((c + sep + "dxcompiler.dll").c_str()) !=
            INVALID_FILE_ATTRIBUTES) {
            dir = c + sep;
            break;
        }
    }
    if (dir.empty()) {
        error = "DXC DLLs not found (tried explicit dir, MCLA_DXC_DIR, "
                ".research/XenosRecomp/thirdparty/dxc-bin/bin/x64, exe dir)";
        return false;
    }

    // Pre-load dxil.dll by full path so dxcompiler.dll's dependency resolves
    // from the same directory regardless of the process search path.
    impl_->dxil = LoadLibraryA((dir + "dxil.dll").c_str());
    if (!impl_->dxil) {
        error = "LoadLibrary(dxil.dll) failed: " + WinErrorText(GetLastError());
        return false;
    }
    impl_->dxcompiler =
        LoadLibraryExA((dir + "dxcompiler.dll").c_str(), nullptr,
                       LOAD_LIBRARY_SEARCH_DLL_LOAD_DIR |
                           LOAD_LIBRARY_SEARCH_DEFAULT_DIRS);
    if (!impl_->dxcompiler) {
        error = "LoadLibrary(dxcompiler.dll) failed: " + WinErrorText(GetLastError());
        return false;
    }
    impl_->createInstance = reinterpret_cast<DxcCreateInstanceProc>(
        GetProcAddress(impl_->dxcompiler, "DxcCreateInstance"));
    if (!impl_->createInstance) {
        error = "DxcCreateInstance export not found in dxcompiler.dll";
        return false;
    }

    HRESULT hr = impl_->createInstance(
        CLSID_DxcCompiler, __uuidof(IDxcCompiler3),
        reinterpret_cast<void**>(impl_->compiler.GetAddressOf()));
    if (FAILED(hr)) {
        error = "DxcCreateInstance(CLSID_DxcCompiler) failed " + HexHr(hr);
        return false;
    }
    hr = impl_->createInstance(CLSID_DxcUtils, __uuidof(IDxcUtils),
                               reinterpret_cast<void**>(impl_->utils.GetAddressOf()));
    if (FAILED(hr)) {
        error = "DxcCreateInstance(CLSID_DxcUtils) failed " + HexHr(hr);
        return false;
    }

    usedDir = dir;
    loaded_ = true;
    return true;
}

bool DxcRuntime::Compile(std::string_view hlsl, std::string_view entry,
                         std::string_view profile, std::vector<uint8_t>& dxil,
                         std::string& error) const {
    dxil.clear();
    error.clear();
    if (!impl_ || !impl_->compiler || !impl_->utils || !loaded_) {
        error = "DxcRuntime not loaded";
        return false;
    }

    ComPtr<IDxcBlobEncoding> sourceBlob;
    HRESULT hr = impl_->utils->CreateBlobFromPinned(
        hlsl.data(), static_cast<uint32_t>(hlsl.size()), DXC_CP_UTF8,
        sourceBlob.GetAddressOf());
    if (FAILED(hr) || !sourceBlob) {
        error = "IDxcUtils::CreateBlobFromPinned failed " + HexHr(hr);
        return false;
    }

    DxcBuffer source{};
    source.Ptr = sourceBlob->GetBufferPointer();
    source.Size = sourceBlob->GetBufferSize();

    // Mirror the reference invocation in
    // .research/XenosRecomp/XenosRecomp/dxc_compiler.cpp: same profiles,
    // HLSL 2021, all-resources-bound, and stripped debug/reflect containers.
    const std::wstring wEntry = ToWide(entry.empty() ? "main" : entry);
    const std::wstring wProfile = ToWide(profile);
    std::vector<const wchar_t*> args;
    args.push_back(L"-E");
    args.push_back(wEntry.c_str());
    args.push_back(L"-T");
    args.push_back(wProfile.c_str());
    args.push_back(L"-HV");
    args.push_back(L"2021");
    args.push_back(L"-all-resources-bound");
    args.push_back(L"-Wno-ignored-attributes");
    args.push_back(L"-Qstrip_reflect");
    args.push_back(L"-Qstrip_debug");

    ComPtr<IDxcResult> result;
    hr = impl_->compiler->Compile(&source, args.data(), static_cast<uint32_t>(args.size()),
                                  nullptr, __uuidof(IDxcResult),
                                  reinterpret_cast<void**>(result.GetAddressOf()));
    if (FAILED(hr) || !result) {
        error = "IDxcCompiler3::Compile failed " + HexHr(hr);
        return false;
    }

    HRESULT status = E_FAIL;
    result->GetStatus(&status);
    if (FAILED(status)) {
        ComPtr<IDxcBlobEncoding> errBlob;
        if (SUCCEEDED(result->GetOutput(DXC_OUT_ERRORS, __uuidof(IDxcBlobEncoding),
                                        reinterpret_cast<void**>(errBlob.GetAddressOf()),
                                        nullptr)) &&
            errBlob && errBlob->GetBufferSize() > 0) {
            error.assign(static_cast<const char*>(errBlob->GetBufferPointer()),
                         errBlob->GetBufferSize());
        }
        if (error.empty()) error = "DXC compile failed (no diagnostics)";
        return false;
    }

    ComPtr<IDxcBlob> obj;
    hr = result->GetOutput(DXC_OUT_OBJECT, __uuidof(IDxcBlob),
                           reinterpret_cast<void**>(obj.GetAddressOf()), nullptr);
    if (FAILED(hr) || !obj || obj->GetBufferSize() == 0) {
        error = "no DXIL object produced by DXC";
        return false;
    }
    const auto* p = static_cast<const uint8_t*>(obj->GetBufferPointer());
    dxil.assign(p, p + obj->GetBufferSize());
    return true;
}

}  // namespace mcla::renderer
