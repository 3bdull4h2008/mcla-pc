#include "app.h"
#include "logging.h"

#include <thread>
#include <chrono>

int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    mcla::App app("MCLA Native");

    if (!app.Initialize()) {
        // W0: park instead of exiting — but Initialize only fails before the HWND
        // exists (app.cpp:43/54; the D3D12 render thread starts at app.cpp:110).
        MCLA_LOG_ERROR("Initialize failed — keeping process alive if window exists");
        while (true) {
            std::this_thread::sleep_for(std::chrono::hours(24));
        }
    }

    app.Run();

    // W0: after MainLoop, do not exit immediately — keep window until killed.
    while (true) {
        std::this_thread::sleep_for(std::chrono::hours(24));
    }
    return 0;
}
