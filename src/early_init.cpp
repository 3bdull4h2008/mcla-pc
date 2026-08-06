#include <cstdlib>
#include <cstdio>
#include <signal.h>
#include <windows.h>

static LONG WINAPI EarlyVeh(EXCEPTION_POINTERS* ep) {
    FILE* f = nullptr;
    fopen_s(&f, "crash_log_early.txt", "w");
    if (f) {
        fprintf(f, "VEH exception: code=0x%08X addr=0x%p\n",
                ep->ExceptionRecord->ExceptionCode,
                ep->ExceptionRecord->ExceptionAddress);
        for (ULONG i = 0; i < ep->ExceptionRecord->NumberParameters && i < 15; i++) {
            fprintf(f, "  param[%lu] = 0x%llX\n", i, ep->ExceptionRecord->ExceptionInformation[i]);
        }
        if (ep->ContextRecord) {
            fprintf(f, "RIP=0x%llX RSP=0x%llX\n", ep->ContextRecord->Rip, ep->ContextRecord->Rsp);
        }
        fflush(f);
        fclose(f);
    }
    return EXCEPTION_CONTINUE_SEARCH;
}

static void EarlyInvalidParam(const wchar_t*, const wchar_t*, const wchar_t*, unsigned int, uintptr_t) {
}

static void EarlyAbortSignal(int) {
}

#pragma init_seg(lib)
struct EarlyCrashInit {
    EarlyCrashInit() {
        _set_abort_behavior(0, _CALL_REPORTFAULT);
        _set_invalid_parameter_handler(EarlyInvalidParam);
        signal(SIGABRT, EarlyAbortSignal);
        AddVectoredExceptionHandler(1, EarlyVeh);
    }
} g_earlyCrashInit;
