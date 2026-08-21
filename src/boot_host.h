#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace mcla::boot {

// What the boot observed, for fault triage and gate evidence. Mirrors the
// proven smoke-host BootReport (tools/xenon_smoke, commit 8fc8842).
struct BootReport
{
    uint32_t entryGuest = 0;
    bool returned = false;
    std::string faultInfo;
    uint64_t faultHost = 0;
    uint32_t faultR1 = 0;
    uint32_t faultR3 = 0;
    uint32_t faultR13 = 0;
    uint32_t faultLR = 0;
    uintptr_t faultAddr = 0;
    uintptr_t faultOwnerStart = 0;
    uintptr_t faultOwnerOffset = 0;
    uintptr_t faultRva = 0;
    uintptr_t faultRax = 0;
    uintptr_t faultRbx = 0;
    uintptr_t faultRcx = 0;
    uintptr_t faultRdx = 0;
    uintptr_t faultRsi = 0;
    uintptr_t faultRdi = 0;
    bool readFault = true;
    uint32_t faultCode = 0;
    unsigned char faultBytes[16] = {};
    uint32_t faultGpr[32] = {};
    std::vector<std::string> faultStack;
    uint32_t faultCallerLR = 0;
    uint32_t faultTable[16] = {};
};

// Allocates the 4 GiB guest window, wires it into the App's active
// GuestMemoryView + PPC base, loads default.xex, installs the 46k-function
// lookup table and the pre-boot slot seeds. Returns the XEX entry point.
// Must run on the main thread before any PPC code executes.
bool LoadAndPrepare(const std::string& xexPath, uint32_t& entryGuest);

// Spawns the boot worker thread (SEH-guarded). Returns immediately; the
// outcome (fault report or parked-in-main-loop) is logged by a monitor.
void Start(uint32_t entryGuest);

const BootReport& GetReport();

// Log bridge for the SEH-bearing boot TU. boot_host.cpp contains __try/__except
// and cannot instantiate spdlog/fmt templates in the same TU (clang 19.1.7
// ICEs in the X86 assembler); these forward to spdlog from a separate TU.
void BootReportInfo(const char* line);
void BootReportError(const char* line);

} // namespace mcla::boot