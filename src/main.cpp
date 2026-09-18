#include "app.h"
#include "logging.h"

#include <thread>
#include <chrono>

int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    mcla::App app("MCLA Native");

    if (!app.Initialize()) {
        // W0: never drop a live window. If init failed after the HWND exists,
        // park the process so the user still sees D3D12 output.
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
