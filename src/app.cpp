#include "app.h"
#include "logging.h"
#include "patches.h"
#include "native_renderer.h"
#include "renderer_mode.h"
#include "generated/default/mcla_init.h"
#include "vfs_rpf.h"

#include <fmt/format.h>
#include <algorithm>
#include <thread>
#include <chrono>

namespace mcla {

static App* g_appInstance = nullptr;

App::App(const char* name) : m_name(name) {
    g_appInstance = this;
}

App::~App() {
    Shutdown();
    g_appInstance = nullptr;
}

App* GetApp() {
    return g_appInstance;
}

bool App::Initialize() {
    MCLA_LOG_INFO("Initializing {}...", m_name);

    if (!InitSDL()) return false;
    if (!InitPaths()) return false;
    if (!CreateWindow()) return false;
    if (!InitD3D12()) return false;

    // Initialize logging first so patches can log
    mcla::cvar::CVarSystem::Instance().LoadConfig(m_cacheRoot / "mcla.toml");
    mcla::log::Initialize(m_name.c_str(), mcla::log::Level::Info,
                          (m_cacheRoot / "mcla.log").string().c_str());

    MCLA_LOG_INFO("Game data root: {}", m_gameDataRoot.string());
    MCLA_LOG_INFO("Cache root: {}", m_cacheRoot.string());

    // Apply patches (installs PPC hooks)
    if (m_dispatcher) {
        mcla_ApplyPatches(m_dispatcher.get());
    }

    // Initialize VFS for city art
    mcla::vfs::RpfVirtualFileSystem& vfs = mcla::vfs::RpfVirtualFileSystem::Instance();
    std::filesystem::path extractedRoot = m_gameDataRoot / "mcla extracted cache";
    if (std::filesystem::exists(extractedRoot)) {
        if (vfs.Initialize(extractedRoot.string())) {
            vfs.Mount();
            MCLA_LOG_INFO("VFS initialized and mounted");
        }
    }

    m_running = true;
    return true;
}

void App::Run() {
    MainLoop();
}

void App::Shutdown() {
    if (!m_running && m_window == nullptr) return;

    m_running = false;

    // Save config
    mcla::cvar::CVarSystem::Instance().SaveConfig(m_cacheRoot / "mcla.toml");

    // Unmount VFS
    mcla::vfs::RpfVirtualFileSystem::Instance().Unmount();

    // Shutdown D3D12 backend
    if (auto* backend = native::GetD3D12Backend()) {
        backend->Shutdown();
    }

    // Destroy window
    if (m_window) {
        SDL_DestroyWindow(m_window);
        m_window = nullptr;
        m_hwnd = nullptr;
    }

    SDL_Quit();
    mcla::log::Shutdown();

    MCLA_LOG_INFO("Shutdown complete");
}

bool App::InitSDL() {
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD | SDL_INIT_EVENTS)) {
        MCLA_LOG_ERROR("SDL_Init failed: {}", SDL_GetError());
        return false;
    }
    MCLA_LOG_INFO("SDL initialized");
    return true;
}

bool App::InitPaths() {
    // Get executable directory
    char exePath[MAX_PATH];
    GetModuleFileNameA(nullptr, exePath, MAX_PATH);
    std::filesystem::path exeDir = std::filesystem::path(exePath).parent_path();

    // Game data root: check cvar, then fallback to exe_dir/game_data
    std::string gameDataCvar = MCLA_CVAR_GET_STRING(game_data_root);
    if (!gameDataCvar.empty()) {
        m_gameDataRoot = gameDataCvar;
    } else {
        m_gameDataRoot = exeDir / "game_data";
        if (!std::filesystem::exists(m_gameDataRoot)) {
            m_gameDataRoot = "game_data";
        }
    }

    // Cache root: check cvar, then fallback to exe_dir/cache
    std::string cacheCvar = MCLA_CVAR_GET_STRING(cache_root);
    if (!cacheCvar.empty()) {
        m_cacheRoot = cacheCvar;
    } else {
        m_cacheRoot = exeDir / "cache";
    }

    std::error_code ec;
    std::filesystem::create_directories(m_cacheRoot, ec);

    return true;
}

bool App::CreateWindow() {
    Uint32 flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN | SDL_WINDOW_HIGH_PIXEL_DENSITY;

    // Check for fullscreen cvar
    if (MCLA_CVAR_GET_BOOL(fullscreen)) {
        flags |= SDL_WINDOW_FULLSCREEN;
    }

    m_window = SDL_CreateWindow(m_name.c_str(), m_width, m_height, flags);
    if (!m_window) {
        MCLA_LOG_ERROR("SDL_CreateWindow failed: {}", SDL_GetError());
        return false;
    }

    // Get HWND for D3D12
    SDL_PropertiesID props = SDL_GetWindowProperties(m_window);
    m_hwnd = (HWND)SDL_GetPointerProperty(props, SDL_PROP_WINDOW_WIN32_HWND_POINTER, nullptr);
    if (!m_hwnd) {
        MCLA_LOG_ERROR("Failed to get HWND from SDL window");
        return false;
    }

    // Get actual drawable size
    int w, h;
    SDL_GetWindowSizeInPixels(m_window, &w, &h);
    m_width = static_cast<uint32_t>(w);
    m_height = static_cast<uint32_t>(h);

    SDL_ShowWindow(m_window);
    MCLA_LOG_INFO("Window created: {}x{} HWND=0x{:X}", m_width, m_height, reinterpret_cast<uintptr_t>(m_hwnd));
    return true;
}

bool App::InitD3D12() {
    // Only initialize D3D12 in native renderer mode
    if (mcla::renderer::GetRendererMode() == mcla::renderer::RendererMode::Native) {
        if (!native::GetD3D12Backend()->Initialize(m_hwnd, m_width, m_height)) {
            MCLA_LOG_ERROR("Failed to initialize D3D12 backend");
            return false;
        }
        MCLA_LOG_INFO("D3D12 backend initialized in native mode");
    } else {
        MCLA_LOG_INFO("Renderer mode is legacy/capture; D3D12 backend will initialize lazily");
    }
    return true;
}

void App::MainLoop() {
    MCLA_LOG_INFO("Entering main loop");

    while (m_running) {
        HandleEvents();

        if (!m_running) break;

        // Frame callback (for PPC execution, etc.)
        if (m_frameCallback) {
            m_frameCallback();
        }

        // Small sleep to prevent 100% CPU when idle
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    MCLA_LOG_INFO("Main loop exited");
}

void App::HandleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_EVENT_QUIT:
                m_running = false;
                break;

            case SDL_EVENT_WINDOW_RESIZED:
            case SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED:
                OnResize(static_cast<uint32_t>(event.window.data1),
                         static_cast<uint32_t>(event.window.data2));
                break;

            case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
                m_running = false;
                break;

            default:
                break;
        }
    }
}

void App::OnResize(uint32_t width, uint32_t height) {
    if (width == 0 || height == 0) return;

    m_width = width;
    m_height = height;

    if (auto* backend = native::GetD3D12Backend()) {
        if (backend->IsInitialized()) {
            backend->Resize(width, height);
        }
    }

    MCLA_LOG_INFO("Window resized to {}x{}", width, height);
}

// FunctionDispatcher implementation
App::FunctionDispatcher::PPCFunc App::FunctionDispatcher::GetFunction(uint32_t addr) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_functions.find(addr);
    return (it != m_functions.end()) ? it->second : nullptr;
}

void App::FunctionDispatcher::SetFunction(uint32_t addr, PPCFunc func) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_functions[addr] = func;
}

uint32_t App::FunctionDispatcher::AllocateThunk(PPCFunc func, uint32_t originalAddr) {
    std::lock_guard<std::mutex> lock(m_mutex);
    uint32_t thunkAddr = m_nextThunkAddr++;
    m_thunks[thunkAddr] = {func, originalAddr};
    m_functions[thunkAddr] = func;
    return thunkAddr;
}

} // namespace mcla