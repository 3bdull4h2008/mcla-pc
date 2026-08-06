#pragma once

#include <rex/rex_app.h>
#include <rex/version.h>
#include <rex/cvar.h>
#include <rex/input/flags.h>
#include "generated/default/mcla_init.h"
#include "patches.h"

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
    }

    void OnPostLoadXexImage() override {
        auto* fd = runtime()->function_dispatcher();
        if (fd) {
            mcla_ApplyPatches(fd);
        }
    }
};
