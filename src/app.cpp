#include "app.h"
#include "logging.h"
#include "patches.h"
#include "boot_host.h"
#include "native_renderer.h"
#include "renderer_mode.h"
#include "render_thread.h"
#include "generated/ppc_xenon/ppc_recomp_shared.h"
#include "fs/vfs_rpf.h"
#include "kernel/memory.h"
#include "kernel/xam.h"
#include "apu/audio.h"

// Forward declaration for GPU context poller (Phase 4)
void StartGpuContextPoller();

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
    // Initialize logging first so all subsequent log calls have a sink.
    // InitPaths() must run first to compute m_cacheRoot for the log file path.
    // Lines emitted before this point (InitSDL logs; InitPaths does not) are not
    // dropped: spdlog's default logger is a stdout sink -> they miss mcla.log.
    if (!InitSDL()) return false;
    if (!InitPaths()) return false;

    mcla::log::Initialize(m_name.c_str(), mcla::log::Level::Info,
                      (m_cacheRoot / "mcla.log").string().c_str());

    MCLA_LOG_INFO("Initializing {}...", m_name);

    // The PPC ABI load/store macros route through the checked guest-memory view.
    SetActiveGuestMemoryView(&m_guestMemoryView);

    if (!CreateSDLWindow()) return false;
    // Load CVars before InitD3D12: the renderer_mode gate reads the CVar.
    mcla::cvar::CVarSystem::Instance().LoadConfig(m_cacheRoot / "mcla.toml");

    if (!InitD3D12()) return false;

    MCLA_LOG_INFO("Game data root: {}", m_gameDataRoot.string());
    MCLA_LOG_INFO("Cache root: {}", m_cacheRoot.string());

    // M5: open the SDL3 audio stream (48 kHz stereo s16). Failure is non-fatal
    // — the game must keep booting even with no output device.
    apu::Init();

    // F-609: open whatever controllers are already attached and take the
    // first sample BEFORE the guest boot worker is started below. SDL_Init
    // queued SDL_EVENT_GAMEPAD_ADDED for anything already plugged in, but
    // those events are not processed until MainLoop runs - and the guest
    // thread would otherwise poll XamInputGetState against a snapshot that
    // had never been filled, getting DEVICE_NOT_CONNECTED for port 0 during
    // exactly the window in which a title decides whether it has a pad.
    XamInputInit();

    // Phase 5 (BOOT_REBUILD_PLAN.md - retired, cf. src/boot_host.cpp:5): load
    // the game image into the 4 GiB guest window and prepare the boot context.
    // Must run after logging + paths (boot diagnostics need a sink) and before
    // mcla_ApplyPatches (guest-memory hooks need a live window).
    const std::filesystem::path xexPath = m_gameDataRoot / "default.xex";
    if (std::filesystem::exists(xexPath) && boot::LoadAndPrepare(xexPath.string(), m_bootEntry)) {
        MCLA_LOG_INFO("Guest image loaded; entry @0x{:08X}", m_bootEntry);
    } else {
        MCLA_LOG_WARN("Boot host not started: {} missing or load failed", xexPath.string());
    }

    // Apply patches (installs PPC hooks). The dispatcher was never
    // instantiated before 2026-08-23 - mcla_ApplyPatches silently no-op'd on
    // every boot, leaving CP MMIO routing (doorbell consumer) and the whole
    // patch layer dead. Found via doorbell-never-drains trace.
    m_dispatcher = std::make_unique<FunctionDispatcher>();
    if (m_dispatcher) {
        mcla_ApplyPatches(m_dispatcher.get());
        // renderer_mode comes solely from the CVar system: the previous hard-coded
        // SetString("renderer_mode","native") is gone - the only writer left is the
        // LoadConfig() above. Compiled default is "native" (src/renderer_mode.cpp:8);
        // config/mcla_manifest.toml:16's "legacy" is inert - no src/ reader (F-053).
        mcla::native::InstallNativeRenderer(m_dispatcher.get());
    }

    // Initialize the RPF VFS: back-end for guest file IO (Nt*File hooks, RSC tab)
    mcla::vfs::RpfVirtualFileSystem& vfs = mcla::vfs::RpfVirtualFileSystem::Instance();
    std::filesystem::path extractedRoot = m_gameDataRoot / "mcla extracted cache";
    if (std::filesystem::exists(extractedRoot)) {
        if (vfs.Initialize(extractedRoot.string())) {
            vfs.Mount();
            MCLA_LOG_INFO("VFS initialized and mounted");
        }
    }

m_running = true;

    // Start GPU context poller (Phase 4) - waits for game to allocate GPU context
    StartGpuContextPoller();

    // P4.5': Start the dedicated render thread before boot::Start() (which blocks
    // in its 5-min watchdog loop; W0 below runs it on a detached thread). It
    // inits D3D12 on entry, then pops - kept awake by its own 33 ms heartbeat.
    mcla::native::g_renderThread.start();

    // Start the guest boot worker once the host services it will touch (VFS,
    // kernel stubs, logging) are up. The worker parks in the game main loop;
    // its outcome is reported in mcla.log by the boot watchdog.
    // NOTE: boot::Start blocks (watchdog loop) — render thread must already be up.
    // W0: do not block Initialize on the boot watchdog — the SDL main loop
    // must keep pumping events so the window stays visible even if the guest
    // hits a fatal and parks.
    if (m_bootEntry != 0) {
        std::thread([entry = m_bootEntry]() {
            boot::Start(entry);
        }).detach();
    }

    return true;
}

void App::Run() {
    MainLoop();
}

void App::Shutdown() {
    if (!m_running && m_window == nullptr) return;

    m_running = false;

    // Close audio before tearing down SDL so the stream/device goes away
    // cleanly and does not race SDL_Quit.
    apu::Shutdown();

    // P4.5': Stop the render thread before tearing down D3D12/window.
    // The render thread owns D3D12 and shuts it down in stop().
    mcla::native::g_renderThread.stop();

    // Save config
    mcla::cvar::CVarSystem::Instance().SaveConfig(m_cacheRoot / "mcla.toml");

    // Unmount VFS
    mcla::vfs::RpfVirtualFileSystem::Instance().Unmount();

    // F-609: stop the motors and release every SDL_Gamepad* before SDL_Quit -
    // SDL_CloseGamepad must run while the joystick subsystem is still alive.
    XamInputShutdown();

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

    // Game data root: cvar undeclared in src/ (reads "") -> exe_dir/game_data
    std::string gameDataCvar(MCLA_CVAR_GET_STRING(game_data_root));
    if (!gameDataCvar.empty()) {
        m_gameDataRoot = gameDataCvar;
    } else {
        m_gameDataRoot = exeDir / "game_data";
        if (!std::filesystem::exists(m_gameDataRoot)) {
            m_gameDataRoot = "game_data";
        }
    }

    // Cache root: cvar undeclared in src/ (reads "") -> exe_dir/cache
    std::string cacheCvar(MCLA_CVAR_GET_STRING(cache_root));
    if (!cacheCvar.empty()) {
        m_cacheRoot = cacheCvar;
    } else {
        m_cacheRoot = exeDir / "cache";
    }

    std::error_code ec;
    std::filesystem::create_directories(m_cacheRoot, ec);

    return true;
}

bool App::CreateSDLWindow() {
    Uint32 flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN | SDL_WINDOW_HIGH_PIXEL_DENSITY;

    // Fullscreen cvar: undeclared in src/, so GetBool() is always false here
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
    // D3D12 initialization is deferred to the render thread (P4′ Step 3).
    // The render thread owns all D3D12 calls. We just store the window params
    // and the render thread will initialize D3D12 when it starts.
    if (mcla::renderer::GetRendererMode() == mcla::renderer::RendererMode::Native) {
        mcla::native::g_renderThread.SetWindowParams(m_hwnd, m_width, m_height);
        MCLA_LOG_INFO("D3D12 deferred to render thread (HWND=0x{:X} {}x{})",
                      reinterpret_cast<uintptr_t>(m_hwnd), m_width, m_height);
    } else {
        MCLA_LOG_INFO("Renderer mode is legacy/capture; D3D12 not needed");
    }
    return true;
}

void App::MainLoop() {
    MCLA_LOG_INFO("Entering main loop");

    while (m_running) {
        HandleEvents();

        if (!m_running) break;

        // Optional frame callback: never set today (no SetFrameCallback caller)
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

            // F-609: hot-plug. SDL_Init(SDL_INIT_GAMEPAD) is set at
            // src/app.cpp:179 but nothing ever opened a controller, so pads
            // that were attached at launch and pads attached later were both
            // invisible to the guest. The main thread owns every SDL_Gamepad*
            // and does all of the sampling (see the threading model in
            // kernel/xam.cpp).
            case SDL_EVENT_GAMEPAD_ADDED:
                XamInputGamepadAdded(event.gdevice.which);
                break;

            case SDL_EVENT_GAMEPAD_REMOVED:
                XamInputGamepadRemoved(event.gdevice.which);
                break;

            default:
                break;
        }
    }

    // Sample the input snapshot only AFTER the drain: SDL_PollEvent is what
    // runs SDL_UpdateGamepads, so anything read before it is a frame behind.
    // The guest thread copies this snapshot under a lock and never calls SDL.
    XamInputPoll();
}

void App::OnResize(uint32_t width, uint32_t height) {
    if (width == 0 || height == 0) return;

    m_width = width;
    m_height = height;

    if (mcla::renderer::GetRendererMode() == mcla::renderer::RendererMode::Native) {
        mcla::native::RenderCommand cmd;
        cmd.type = mcla::native::RenderCommand::RESIZE;
        auto& resize = cmd.data.emplace<mcla::native::ResizeCommand>();
        resize.width = width;
        resize.height = height;
        mcla::native::g_commandQueue.push(cmd);
    }

    MCLA_LOG_INFO("Window resized to {}x{}", width, height);
}

// FunctionDispatcher implementation
//
// DESIGN NOTE: the recompiled guest dispatch table lives in
// Memory::InsertFunction / PPC_LOOKUP_FUNC (src/kernel/memory.h:170-176).
// The dispatcher map (m_functions) is written by SetFunction and AllocateThunk
// but read only by GetFunction – never at dispatch time, so SetFunction was
// dead code on its own.  This fix also writes the real dispatch table so that
// hooks installed via the dispatcher actually intercept guest calls.
// GetFunction falls back to the dispatch table so the original can be
// retrieved before the hook overwrites it.

App::FunctionDispatcher::PPCFunc App::FunctionDispatcher::GetFunction(uint32_t addr) const {
    // 1. Check the override map first (SetFunction registrations).
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        auto it = m_functions.find(addr);
        if (it != m_functions.end())
            return it->second;
    }
    // 2. Fall back to the real dispatch table so the original generated
    //    function can be retrieved before we overwrite it with a hook.
    return kernel::g_memory.FindFunction(addr);
}

void App::FunctionDispatcher::SetFunction(uint32_t addr, PPCFunc func) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_functions[addr] = func;
    // Also install in the real dispatch table so guest calls actually
    // reach the hook (or replacement) at runtime.
    kernel::g_memory.InsertFunction(addr, func);
}

uint32_t App::FunctionDispatcher::AllocateThunk(PPCFunc func, uint32_t originalAddr) {
    std::lock_guard<std::mutex> lock(m_mutex);
    uint32_t thunkAddr = m_nextThunkAddr++;
    m_thunks[thunkAddr] = {func, originalAddr};
    m_functions[thunkAddr] = func;
    return thunkAddr;
}

} // namespace mcla

