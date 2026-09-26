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

// F-370: registry of semaphore handles created with a NON-ZERO initial count. Those are
// job/concurrency limiters (permits), so "a thread waits on one and never returns" means work
// was handed out and never completed - the census that names it needs the handle set, which
// only exists at create time (imports.cpp::NtCreateSemaphore records into it; the wait/release
// hooks in gpu_device.cpp ask it). Log-only, bounded, no behaviour change.
// F-374: guard-page watch over the user heap's o1heap header (guest 0x20000). The guest writes
// through `base[va]`, which never passes a checked accessor, and DR registers cannot be set on a
// running thread (F-100), so a page guard is the only thing that can name the writer of the
// corruption in F-370. Heap::Alloc/Heap::Free call these around each operation: the page is
// writable while the allocator itself is writing its header, guarded the rest of the time. The
// first arm proves the watch lives with a deliberate self-test read (F374-HEAPGUARD SELFTEST).
void HeapGuardArm();
void HeapGuardDisarm();

void RegisterCountingSema(uint32_t handle, uint32_t initCount);
bool IsCountingSema(uint32_t handle, uint32_t *initOut = nullptr);
// Per-handle print budget: one busy limiter (C6137A00) must not starve a quiet one out of a
// shared cap, which is exactly how C501FC00's own WAIT row got lost in w374. Bumps the handle's
// counter and says whether this row should be printed.
bool CountingSemaAllow(uint32_t handle);

// Log bridge for the SEH-bearing boot TU. boot_host.cpp contains __try/__except
// and cannot instantiate spdlog/fmt templates in the same TU (clang 19.1.7
// ICEs in the X86 assembler); these forward to spdlog from a separate TU.
void BootReportInfo(const char* line);
void BootReportError(const char* line);

} // namespace mcla::boot