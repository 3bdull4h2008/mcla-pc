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

// F-609: a real per-guest-thread identity block, for host threads the guest
// believes are threads but which were NOT created by ExCreateThread -- the boot
// worker, the vsync ISR, the audio thread, and the ~20 synthesized contexts in
// gpu_device.cpp. Every one of those hard-aliases r13 = 0x8F200000
// (SetupInitialContext's ThreadBlock, boot_host.cpp:731; kernel/imports.cpp:1735-1737;
// apu/audio.cpp:73; gpu_device.cpp:20270,20285,20392 per its own comment), so the
// owner key in
// RtlEnterCriticalSection -- g_ppcContext->r13 (kernel/imports.cpp:1390, not r3
// as the audit said) -- is the SAME value on all of them: spin-lock holders,
// the TLS table at 0x8F201000 and cs->OwningThread all alias. That alias is
// why the 5s CS-TIMEOUT force-steal (imports.cpp:1422-1431, which breaks
// mutual exclusion by design) and KFSPIN-RECOVERY (imports.cpp:1525-1535)
// exist at all; removing the steal is a separate job blocked on this one.
//
// Layout is GuestThreadContext's, copied from kernel/guest_thread.cpp:11-17 and
// :40-48 rather than re-derived: two different block layouts is precisely the
// split-brain this exists to remove. Blocks come from g_userHeap, the same
// o1heap the real guest threads use (guest_thread.cpp:23), so a synthetic block
// is indistinguishable from a real one to anything that walks r13.
struct GuestThreadBlock
{
    uint8_t* pcr = nullptr;   // host base; MapVirtual(pcrVa) == pcr
    uint32_t pcrVa = 0;       // guest VA -- this is what r13 must be
    uint32_t tlsVa = 0;       // *(pcr + 0x000)
    uint32_t tebVa = 0;       // *(pcr + 0x100)
    uint32_t stackTopVa = 0;  // r1, top of the 0x40000 stack
    const char* tag = nullptr;// static string naming the owning host thread
    uint32_t cpuNumber = 0;   // *(pcr + 0x10C)
    // False on an honest OOM (the F-370 path). A caller must not publish the
    // VA in that case -- a half-built block is exactly the 0x8F200000 wipe
    // that gpu_device.cpp:20559 already had to work around.
    [[nodiscard]] bool valid() const { return pcr != nullptr; }
};

// Allocates and initialises one block, or nullptr on OOM. Never silent: the
// nullptr path logs the F370-THREAD-CTX-NULL-shaped reason and count, because
// guest_thread.cpp:26-37 showed what the unnamed version costs (memset(0) and a
// silently dead thread). Log-only budget: first 16 and every 100th, so an OOM
// storm cannot itself become the flood.
GuestThreadBlock* AllocateGuestThreadBlock(const char* tag, uint32_t cpuNumber = 0);

// Returns the payload to g_userHeap, erases the tag, and frees the descriptor.
// Safe on nullptr. Does NOT free the stack -- the stack is inside the payload.
void ReleaseGuestThreadBlock(GuestThreadBlock* block);

// Attribution: the tag registered for a block's pcr VA, or nullptr if that VA
// is not a live F-609 block. Lets a CS-TIMEOUT / spin-recovery line name WHICH
// host thread holds or steals a lock instead of printing a bare 0x8F200000.
// Read-only; a miss here can never change guest behaviour.
const char* LookupGuestThreadBlockTag(uint32_t pcrVa);

// Log bridge for the SEH-bearing boot TU. boot_host.cpp contains __try/__except
// and cannot instantiate spdlog/fmt templates in the same TU (clang 19.1.7
// ICEs in the X86 assembler); these forward to spdlog from a separate TU.
void BootReportInfo(const char* line);
void BootReportError(const char* line);

// ===================== F-640: PHYSICAL-VIEW TRANSLATION =====================
// The console maps physical memory through THREE page-size views that alias ONE
// 512 MiB pool -- 0xA0000000 (64 KiB pages), 0xC0000000 (16 MiB pages, the GPU
// write-back window) and 0xE0000000 (4 KiB pages), each declared with the full
// 0x20000000 and passed the same parent heap
// (.research/xenia/src/xenia/memory.cc:171-180). So `0xC0000000 + pa` and
// `0xA0000000 + pa` are the same bytes, and that is what PhysToKernelVA's
// `pa | 0xC0000000` (src/gpu_cp.cpp:1755-1756) converts a physical address into.
//
// THIS TREE HAS ONE FLAT 4 GiB WINDOW (a single VirtualAlloc, boot_host.cpp:677)
// and `Translate` is `m_base + guestAddr` (src/kernel/memory.cpp:285-297), so a
// view address is just more flat memory and NO view aliases the pool. Mapping the
// views is not possible here -- two views of one host range need a section object,
// the pool's bytes are a sub-range of a private allocation, and the view addresses
// are inside an already-committed reservation; the reasoning is in full at the F-640
// block at the top of boot_host.cpp. The mechanism is therefore translation, and
// these are its entry points: a call site that holds a console-view address calls
// TranslatePhysViewToPoolVa and gets the pool address, or an honest refusal.
//
//   kMapped      -- *outPoolVa is the pool address; use it.
//   kNoPoolByte  -- the byte has no pool address in this tree (past the console's
//                   512 MiB physical window). The access CANNOT be honoured; it must be
//                   dropped and counted, never silently redirected elsewhere.
//   kNotAView    -- not a view address; the caller's model was wrong, not the memory.
//
// F-640/B2 (2026-10-21): THE CONSOLE'S LOW PHYSICAL REGION -- CONSOLE PHYSICAL 0 IS A
// REAL BYTE. Before this change the tree's physical pool presented physical
// [0x400000, 0x20400000) and had NO byte at all for physical [0, 0x400000): the +0x400000
// skew F-391 introduced when it moved the pool off the title's XTL slab region. The
// console has no such hole -- `.research/xenia/src/xenia/memory.cc:171-172` declares ONE
// physical heap of 0x20000000 bytes at physical 0, and memory.cc:173-180 hands that SAME
// parent to the three views, so `0xA0000000 + pa` is the physical heap's byte for `pa`
// for EVERY pa in [0, 0x20000000) -- the A view's base IS the physical heap's base.
//
// THE LOW REGION IS WHERE CONSOLE PHYSICAL [0, 0x400000) NOW LIVES: guest VA
// [0xA0000000, 0xA0400000), i.e. the 4 MiB BELOW the allocator's pool. It is inside the
// flat 4 GiB window (src/kernel/memory.cpp:399, one MEM_COMMIT|MEM_RESERVE allocation),
// it is inside the region the tree itself calls the unowned gap
// (src/boot_host.cpp:3309 "the unowned gap 0xA0030000..0xA0400000"), and the allocator
// CANNOT hand it out: the pool's o1heap arena starts at kPhysArenaBeginVa
// (src/kernel/heap.cpp:2766-2788). So the low region is real, mapped, writable memory
// that no allocator owns -- exactly the console's physical page 0.
inline constexpr uint32_t kPhysLowRegionVa = 0xA0000000u;      // console physical 0
inline constexpr uint32_t kPhysLowRegionBytes = 0x00400000u;   // 4 MiB
inline constexpr uint32_t kPhysLowRegionEndVa = kPhysLowRegionVa + kPhysLowRegionBytes;
//
// Both counters are published, attempts and outcomes separately, and every drop gets
// its own `F640-CVIEW-DROPPED` line carrying its attempt index -- a bare `dropped=0`
// with no adopted writer beside it is not a measurement, which is why
// RegisterPhysAliasWriter exists and why `F640-PHYSALIAS-SUM` prints
// `zero_is_measured=`.
// =====================
enum class PhysViewResult : uint8_t { kNotAView = 0, kMapped = 1, kNoPoolByte = 2 };

PhysViewResult TranslatePhysViewToPoolVa(uint32_t viewVa, uint32_t* outPoolVa);

// "A64K" / "C16M" / "E4K" for a view address, "-" for anything else. Classification only.
const char* PhysViewName(uint32_t viewVa);

// A call site that routes its accesses through the translation registers itself, so
// the rows can say how many there are and a zero drop count can be read as a
// measurement rather than as "nothing was ever routed here". Idempotent per name.
void RegisterPhysAliasWriter(const char* site);

// The one-line summary: calls / not_a_view / translated / dropped / adopted_sites /
// zero_is_measured / sum_ok (the three outcomes must add up to calls) / low_region_hits
// (how many of the translated accesses landed in the console's LOW physical region,
// i.e. console physical [0, 4 MiB) -- the census that says the guest really does
// address the console's low memory, and that the bytes it lands on are real).
void LogPhysAliasRow(const char* reason);

} // namespace mcla::boot