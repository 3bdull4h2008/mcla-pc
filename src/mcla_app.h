#pragma once

#include <filesystem>
#include <fstream>

#include <rex/rex_app.h>
#include <rex/version.h>
#include <rex/cvar.h>
#include <rex/input/flags.h>
#include "generated/default/mcla_init.h"
#include "patches.h"
#include "d3d12_backend.h"

// Pre-create empty .loc stubs for t:\mc4\art\city\*.loc BEFORE the runtime
// mounts the VFS.  The RAGE city-art loader opens these RPF3 archives that
// live inside xarchive_cache.rpf on the disc; the host game_data tree has no
// mc4\art\city at all.  The VFS entry tree is populated at mount time, so
// stubs created later are never resolved (STATUS_NO_SUCH_FILE / 0xc000000f).
// Creating them under update_data_root (which the t: symlink resolves to)
// before Runtime::Setup() runs means the mount sees real empty files and the
// loader gets real empty-stream handles (NtReadFile → EOF).  This is a
// legacy game-data accommodation, not native-GPU work.
inline void MclaPrecreateArtCityStubs(const std::filesystem::path& update_root) {
    if (update_root.empty()) return;
    static constexpr const char* kStubs[] = {
        "test_dt_railyard.loc",
        "test_sc_exposition_park.loc",
    };
    std::error_code ec;
    std::filesystem::path city_dir = update_root / "mc4" / "art" / "city";
    std::filesystem::create_directories(city_dir, ec);
    for (const char* name : kStubs) {
        std::filesystem::path stub = city_dir / name;
        if (std::filesystem::exists(stub, ec)) continue;
        std::ofstream ofs(stub, std::ios::binary | std::ios::trunc);
        ofs.close();
    }
}

class MCLAApp : public rex::ReXApp {
public:
    using rex::ReXApp::ReXApp;

    static std::unique_ptr<rex::ui::WindowedApp> Create(rex::ui::WindowedAppContext& ctx) {
        return std::unique_ptr<MCLAApp>(new MCLAApp(ctx, "mcla", PPCImageConfig));
    }

    void OnConfigurePaths(rex::PathConfig& paths) override {
        if (paths.game_data_root.empty())
            paths.game_data_root = "game_data";
        if (paths.update_data_root.empty())
            paths.update_data_root = paths.game_data_root;

        // Materialize the t:\mc4\art\city\*.loc stubs on the host FS before
        // the runtime mounts the VFS, so the mount's entry-tree population
        // sees them.  (Files created after mount are invisible to the cached
        // entry tree → 0xc000000f on open.)
        MclaPrecreateArtCityStubs(paths.update_data_root);
    }

    void OnPreSetup(rex::RuntimeConfig& config) override {
        config.gpu_plugin = "xenos";
    }

    void OnPostSetup() override {
        rex::cvar::SetFlagByName("vsync", "true");
        rex::cvar::SetFlagByName("async_shader_compilation", "true");

        rex::cvar::SetFlagByName("gpu_allow_invalid_fetch_constants", "true");
        rex::cvar::SetFlagByName("native_2x_msaa", "true");
        rex::cvar::SetFlagByName("native_stencil_value_output", "true");
        rex::cvar::SetFlagByName("direct_host_resolve", "true");
        rex::cvar::SetFlagByName("gamma_render_target_as_unorm16", "true");
        rex::cvar::SetFlagByName("anisotropic_override", "4");
        rex::cvar::SetFlagByName("occlusion_query_enable", "true");
        rex::cvar::SetFlagByName("d3d12_allow_variable_refresh_rate_and_tearing", "true");
        rex::cvar::SetFlagByName("d3d12_bindless", "true");
        rex::cvar::SetFlagByName("d3d12_pipeline_creation_threads", "4");
        rex::cvar::SetFlagByName("texture_cache_memory_limit_soft", "1024");
        rex::cvar::SetFlagByName("texture_cache_memory_limit_hard", "2048");
        rex::cvar::SetFlagByName("texture_cache_memory_limit_render_to_texture", "256");
        rex::cvar::SetFlagByName("guide_button", "true");

        // Register VFS symlink so t:\ resolves to the update: device
        auto* vfs = runtime()->file_system();
        if (vfs) {
            vfs->RegisterSymbolicLink("t:", "update:");
        }

        // Initialize the native D3D12 backend on the MAIN thread.  D3D12
        // flip-model swap chains require CreateSwapChainForHwnd to run on the
        // thread that owns the window (E_ACCESSDENIED otherwise).  The VdSwap
        // hook fires on a guest game thread, so lazy init from there always
        // fails; do it here where the window thread is guaranteed.
        auto* win = runtime()->display_window();
        if (win) {
            HWND hwnd = reinterpret_cast<HWND>(win->GetNativeWindowHandle());
            if (hwnd) {
                mcla::native::GetD3D12Backend()->Initialize(
                    hwnd, win->GetActualPhysicalWidth(), win->GetActualPhysicalHeight());
            } else {
                REXLOG_WARN("MCLAApp: display window has no native handle; "
                            "native backend will init lazily from VdSwap (may fail)");
            }
        }
    }

    void OnPostLoadXexImage() override {
        auto* fd = runtime()->function_dispatcher();
        if (fd) {
            mcla_ApplyPatches(fd);
        }
    }
};
