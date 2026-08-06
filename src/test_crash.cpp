#include <cstdio>
#include <rex/cvar.h>

int main() {
    printf("Hello from test_crash\n");
    fflush(stdout);
    
    auto& reg = rex::cvar::GetRegistry();
    printf("Registry size: %zu\n", reg.size());
    fflush(stdout);
    
    return 0;
}
