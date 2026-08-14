#pragma once

#include <SDL3/SDL.h>
#include <string>
#include <memory>
#include <functional>
#include <filesystem>
#include <optional>
#include <cstdint>

#include "d3d12_backend.h"
#include "renderer_mode.h"
#include "native_renderer.h"
#include "guest_memory.h"
#include "cvar.h"

namespace mcla {

// PPC Context structure matching ReXGlue's PPCContext
struct PPCContext {
    // General purpose registers r0-r31
    union { uint32_t u32; uint64_t u64; float f32; double f64; } r[32];
    // Floating point registers f0-f31 (aliased with r)
    union { uint32_t u32; uint64_t u64; float f32; double f64; } f[32];

    // Special registers
    uint64_t lr;      // Link register
    uint64_t ctr;     // Count register
    uint64_t xer;     // Fixed-point exception register
    uint64_t cr;      // Condition register
    uint32_t pc;      // Program counter (guest address)

    // FPSCR
    uint32_t fpscr;

    // Vector/scalar registers (VSX) - 128-bit each
    struct VSXReg { uint64_t lo, hi; } vsr[64];

    // Default constructor
    PPCContext() = default;
};

namespace native {
using PPCContext = mcla::PPCContext;
}

class App {
public:
    App(const char* name = "MCLA");
    ~App();

    bool Initialize();
    void Run();
    void Shutdown();

    // Window management
    SDL_Window* GetWindow() const { return m_window; }
    HWND GetHwnd() const { return m_hwnd; }
    uint32_t GetWidth() const { return m_width; }
    uint32_t GetHeight() const { return m_height; }

    // D3D12 backend access
    native::D3D12Backend* GetD3D12Backend() { return native::GetD3D12Backend(); }

    // Guest memory access
    native::GuestMemoryView& GetGuestMemoryView() { return m_guestMemoryView; }

    // Function dispatcher for PPC hooks
    class FunctionDispatcher;
    FunctionDispatcher* GetFunctionDispatcher() { return m_dispatcher.get(); }

    // PPC context base address
    uint8_t* GetPPCBase() const { return m_ppcBase; }
    void SetPPCBase(uint8_t* base) { m_ppcBase = base; }

    // Game data paths
    const std::filesystem::path& GetGameDataRoot() const { return m_gameDataRoot; }
    const std::filesystem::path& GetCacheRoot() const { return m_cacheRoot; }

    // Frame callback
    using FrameCallback = std::function<void()>;
    void SetFrameCallback(FrameCallback cb) { m_frameCallback = std::move(cb); }

private:
    bool InitSDL();
    bool InitPaths();
    bool CreateWindow();
    bool InitD3D12();
    void MainLoop();
    void HandleEvents();
    void OnResize(uint32_t width, uint32_t height);

    std::string m_name;
    SDL_Window* m_window = nullptr;
    HWND m_hwnd = nullptr;
    uint32_t m_width = 1280;
    uint32_t m_height = 720;
    bool m_running = false;

    std::filesystem::path m_gameDataRoot;
    std::filesystem::path m_cacheRoot;

    native::GuestMemoryView m_guestMemoryView;
    std::unique_ptr<FunctionDispatcher> m_dispatcher;
    uint8_t* m_ppcBase = nullptr;

    FrameCallback m_frameCallback;
};

// Function dispatcher for PPC hook management
class App::FunctionDispatcher {
public:
    using PPCFunc = void(*)(PPCContext&, uint8_t*);

    FunctionDispatcher() = default;
    ~FunctionDispatcher() = default;

    PPCFunc GetFunction(uint32_t addr) const;
    void SetFunction(uint32_t addr, PPCFunc func);
    uint32_t AllocateThunk(PPCFunc func, uint32_t originalAddr);

private:
    struct ThunkEntry {
        PPCFunc func;
        uint32_t originalAddr;
    };
    std::unordered_map<uint32_t, PPCFunc> m_functions;
    std::unordered_map<uint32_t, ThunkEntry> m_thunks;
    uint32_t m_nextThunkAddr = 0x83000000;
    mutable std::mutex m_mutex;
};

// Global app instance accessor
App* GetApp();

} // namespace mcla