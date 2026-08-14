#include "app.h"
#include "logging.h"

int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    mcla::App app("MCLA Native");

    if (!app.Initialize()) {
        return 1;
    }

    app.Run();

    return 0;
}