#pragma once

#include <cstdint>
#include <string>
#include <vector>

// Global-scope forward declaration (the real type is defined in src/ppc_context.h).
// Declaring it inside mcla::boot would create a DIFFERENT incomplete type and break
// every PPCContext use in this namespace.
struct PPCContext;

namespace mcla::boot {

// T38.2b (F-046): the VEH crash dump prints ONE PPCContext per thread. Guest code
// that runs on a *synthetic* context (the forced boot gate, the GFx ctor call) must
// publish it here or the dump silently reports an unrelated frame's registers — which
// is exactly how four sessions misread the 0x7E780000 fault. Diagnostic only: this
// changes no execution, only whose registers get printed.
class FaultContextScope
{
public:
    FaultContextScope(const PPCContext* ctx, const char* tag);
    ~FaultContextScope();
    FaultContextScope(const FaultContextScope&) = delete;
    FaultContextScope& operator=(const FaultContextScope&) = delete;

private:
    const PPCContext* prevCtx_;
    const char* prevTag_;
};

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

// B1 discriminator (F-094): arm this thread's DR0/DR1 watchpoints on the
// globaltex.list member pages. Called from BootThreadProc and every guest
// thread start; log-only, budgeted, self-disarming.
void B1ArmGuestThread();

// B1 guard-page watchpoint (F-100 rule 19): make the page holding a guest buffer
// inaccessible, prove the watch fires with a self-test read, then leave it live
// for one real accessor. Log-only; the accessor re-executes after the page is
// restored. Called from the RD-BUF read census.
void B1GuardArm(uint32_t guestVa);

const BootReport& GetReport();

// W36b: peek at the boot worker thread's live PPCContext (g_faultCtx).
// Returns register value rN (0-31). Returns 0 if context unavailable.
uint32_t GetBootWorkerReg(unsigned regIndex);

// Log bridge for the SEH-bearing boot TU. boot_host.cpp contains __try/__except
// and cannot instantiate spdlog/fmt templates in the same TU (clang 19.1.7
// ICEs in the X86 assembler); these forward to spdlog from a separate TU.
void BootReportInfo(const char* line);
void BootReportError(const char* line);

} // namespace mcla::boot