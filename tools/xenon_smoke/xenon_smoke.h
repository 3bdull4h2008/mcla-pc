#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "ppc_recomp_shared.h"

// Kernel import stubs call this to log progress. Thread-safe.
void s_StubCalled(const char* name);

// XTL dispatch chain targets (slot 7 allocation import). Registered in the
// function table by SetupInitialContext so the indirect call resolves.
void __xtl_alloc(PPCContext& __restrict ctx, uint8_t* base);
void __xtl_free(PPCContext& __restrict ctx, uint8_t* base);

// Guest memory base: guest address `g` maps to `g_base + g`.
extern uint8_t* g_base;

// Map a host PC (faulting instruction) to the owning guest function name.
// Scans the installed function table for the host entry containing `hostAddr`.
const char* NearestFunctionName(uint64_t hostAddr);

// Small registry of what the smoke boot observed.
struct BootReport
{
    uint32_t entryGuest = 0;
    uint64_t distinctStubCache = 0;
    std::vector<std::string> stubOrder;
    bool returned = false;
    std::string faultInfo;
    uint64_t faultHost = 0;
    uint32_t faultR1 = 0;
    uint32_t faultR3 = 0;
    uint32_t faultR13 = 0;
    uint32_t faultLR = 0;
    uint32_t faultGpr[32] = {};
    unsigned char faultBytes[16] = {};
    uint32_t faultCallerLR = 0;
    std::vector<std::string> traceLog;
    uintptr_t faultAddr = 0;
    uintptr_t faultOwnerStart = 0;
    uintptr_t faultOwnerOffset = 0;
    uintptr_t faultRva = 0;
    bool readFault = true;
    uint32_t faultCode = 0;
    std::vector<std::string> faultStack;
    uintptr_t faultRax = 0;
    uintptr_t faultRbx = 0;
    uintptr_t faultRcx = 0;
    uintptr_t faultRdx = 0;
    uintptr_t faultRsi = 0;
    uintptr_t faultRdi = 0;
};

// Runs the entry point on a worker thread with a watchdog. Owned by the host.
void RunBoot(BootReport& report, uint32_t entryGuest);