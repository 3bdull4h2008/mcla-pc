// Guest boot host: allocates the 4 GiB guest window, loads default.xex,
// installs the 46k-function lookup table, seeds the pre-boot slots and runs
// the guest entry under SEH. Ported from the proven smoke host
// (tools/xenon_smoke, commit 8fc8842) with MCLA logging and the App's active
// GuestMemoryView / PPC base wiring. Phase 5 of BOOT_REBUILD_PLAN.md.

#include "ppc_config.h"
#include "ppc_context.h"
#include <cpu/ppc_context.h>
#include "ppc_recomp_shared.h"

#include "app.h"
#include "guest_memory.h"
#include "logging.h"
#include "boot_host.h"
#include "kernel/heap.h"
#include "kernel/memory.h"
#include <image.h>

// P4 vtable-word scan (defined in task_dispatch_trace.cpp)
namespace mcla::trace {
void ScanForDispatchVtableWords(uint32_t imageBase, uint32_t imageSize);
}

// Forward declare Xex2LoadImage from XenonRecomp (Image is defined in image.h)
Image Xex2LoadImage(const uint8_t* data, size_t dataSize);

#include <windows.h>
#include <dbghelp.h>
#include <unordered_map>

// Skip flag for generated code (defined in generated/ppc_xenon/ppc_recomp.49.cpp)

// UILOAD thread tracking
std::atomic<DWORD> s_uiLoadThreadId{0};
std::atomic<bool> s_inUILoad{false};

#pragma comment(lib, "dbghelp.lib")

// Guest main-thread id (defined in kernel imports.cpp, declared in xdm.h).
extern std::atomic<uint32_t> g_mainGuestThreadId;

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <mutex>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

// Global-scope redeclarations of the kernel-stub XTL alloc/free (defined in
// kernel_stubs.cpp at global namespace; C++ linkage). Referenced via the r13
// thread-block function block so indirect calls resolve in the guest table.
PPC_EXTERN_FUNC(__xtl_alloc);
PPC_EXTERN_FUNC(__xtl_free);

namespace mcla::boot {

namespace
{
    uint8_t* g_base = nullptr;

    constexpr size_t GuestMemorySize = 0x100000000ull; // 4 GiB, matches PPC_MEMORY_SIZE
    constexpr uintptr_t GuestMemoryBase = 0x100000000ull;

    std::mutex g_reportMutex;
    BootReport g_report;
    std::atomic<bool> g_bootDone{false};
    // Per-thread, because the VEH handler runs on the faulting thread: a process-wide
    // pointer here printed the BOOT THREAD'S context for a fault on any other thread
    // (F-046). The tag names which context so a dump can never be mistaken again.
    thread_local const PPCContext* g_faultCtx = nullptr;
    thread_local const char* g_faultCtxTag = "none";
    uintptr_t g_moduleBase = 0;
    static DWORD s_bootWorkerThreadId = 0;

    // B1 discriminator (F-094 open bit): hardware watchpoints on the two
    // globaltex.list member-page heads (stable VAs across w47-w50). A hit whose
    // host RIP is NOT our NtReadFile fill path means a real consumer touched the
    // member bytes; hits only from the fill path = the prototype tolerates the
    // raw opaque window as-is. Log-only, budgeted, self-disarming.
    constexpr uint32_t kB1WatchVas[2] = {0xC6157B80u, 0xC6167C00u};
    std::atomic<uint32_t> g_b1Hit[2]{};
    std::atomic<uint32_t> g_b1Logged{0};

    bool B1HandleSingleStep(PEXCEPTION_POINTERS ei) {
        CONTEXT* c = ei->ContextRecord;
        if (c == nullptr) return false;
        int slot = -1;
        if (c->Dr6 & 1ULL) slot = 0;
        else if (c->Dr6 & 2ULL) slot = 1;
        if (slot < 0) return false;  // not ours: let the rest of the VEH see it
        const uint32_t n = g_b1Hit[slot].fetch_add(1) + 1;
        const uint32_t ln = g_b1Logged.fetch_add(1) + 1;
        uint32_t glr = 0;
        if (const PPCContext* pc = GetPPCContext()) glr = (uint32_t)pc->lr;
        const uintptr_t rip = (uintptr_t)c->Rip;
        const uintptr_t rv = (g_moduleBase != 0 && rip >= g_moduleBase) ? rip - g_moduleBase : rip;
        if (ln <= 48) {
            MCLA_LOG_WARN("B1-WATCH slot={} va={:08X} hits={} tid={} hostRIP=0x{:X} guestLR={:08X}",
                          slot, kB1WatchVas[slot], n, GetCurrentThreadId(), rv, glr);
        } else {
            c->Dr7 &= ~(1ULL << 0 | 1ULL << 2);  // budget spent: disarm
        }
        c->Dr6 = 0;
        return true;  // ours: continue execution, no park/crash-dump
    }

    void B1ArmCurrentThreadImpl() {
        if (g_base == nullptr) {
            MCLA_LOG_WARN("B1-ARM tid={} SKIP base=null", GetCurrentThreadId());
            return;
        }
        CONTEXT ctx{};
        ctx.ContextFlags = CONTEXT_DEBUG_REGISTERS;
        HANDLE self = GetCurrentThread();
        if (!GetThreadContext(self, &ctx)) {
            MCLA_LOG_WARN("B1-ARM tid={} FAIL getcontext err={}", GetCurrentThreadId(), GetLastError());
            return;
        }
        ctx.Dr0 = (DWORD64)(uintptr_t)(g_base + kB1WatchVas[0]);
        ctx.Dr1 = (DWORD64)(uintptr_t)(g_base + kB1WatchVas[1]);
        ctx.Dr6 = 0;
        ctx.Dr7 = (1ULL << 0) | (2ULL << 16) | (3ULL << 18)   // L0 RW len8
                | (1ULL << 2) | (2ULL << 20) | (3ULL << 22);  // L1 RW len8
        const bool ok = SetThreadContext(self, &ctx) != 0;
        MCLA_LOG_WARN("B1-ARM tid={} ok={} dr0={:X} dr1={:X}", GetCurrentThreadId(), ok,
                      (uintptr_t)ctx.Dr0, (uintptr_t)ctx.Dr1);
    }

    // B1 redo (rule 19 / F-100). Debug registers cannot be programmed from a
    // running thread, so the page-cache windows are watched with a guard page
    // instead: thread-agnostic, and its EFFECT is provable, because every arm is
    // followed by a deliberate one-byte read that must fault and log tag=SELFTEST
    // before the watch is left live. One trip per arm; the handler restores
    // PAGE_READWRITE and lets the accessor re-execute untouched, so the guest
    // sees no behavioural change beyond the log line.
    namespace {
        uintptr_t g_b1gHost = 0;
        SIZE_T g_b1gLen = 0;
        std::atomic<bool> g_b1gArmed{false};
        std::atomic<bool> g_b1gSelfTest{false};
        std::atomic<uint32_t> g_b1gTrips{0};
        std::atomic<uint32_t> g_b1gSelfTests{0};
        std::atomic<uint32_t> g_b1gLogged{0};
        // Every page this instrument has ever made inaccessible. A fault on any
        // of them is ours no matter what the protection looks like at handler
        // time: w62/w63 showed that claiming only the first trip let a second
        // thread's in-window fault reach the park machinery and parked a live
        // guest thread, which moved the frontier (GETDEV 168->116, fatal lost).
        constexpr int kB1gPages = 32;
        std::atomic<uintptr_t> g_b1gPages[kB1gPages];
        std::atomic<int> g_b1gPageN{0};

        bool B1GuardOwns(uintptr_t page) {
            const int n = g_b1gPageN.load(std::memory_order_acquire);
            for (int i = 0; i < n; ++i) {
                if (g_b1gPages[i].load(std::memory_order_relaxed) == page) return true;
            }
            return false;
        }

        void B1GuardClaim(uintptr_t page) {
            const int n = g_b1gPageN.load(std::memory_order_relaxed);
            if (n >= kB1gPages) return;
            g_b1gPages[n].store(page, std::memory_order_relaxed);
            g_b1gPageN.store(n + 1, std::memory_order_release);
        }
    }  // namespace

    bool B1GuardHandle(PEXCEPTION_POINTERS ei) {
        const EXCEPTION_RECORD* rec = ei->ExceptionRecord;
        if (rec == nullptr || rec->ExceptionCode != 0xC0000005L ||
            rec->NumberParameters < 2) {
            return false;
        }
        const uintptr_t fa = (uintptr_t)rec->ExceptionInformation[1];
        constexpr uintptr_t kPage = 0xFFFull;
        if (!B1GuardOwns(fa & ~kPage)) return false;
        const uint32_t n = g_b1gTrips.fetch_add(1) + 1;
        const bool wantWrite = (rec->ExceptionInformation[0] == 1);
        const bool wasWatched = g_b1gArmed.load(std::memory_order_acquire);
        DWORD old = 0;
        const uintptr_t page = fa & ~kPage;
        VirtualProtect((void*)page, 4096, PAGE_READWRITE, &old);
        g_b1gArmed.store(false, std::memory_order_release);  // one watch per arm
        if (g_b1gSelfTest.load()) {
            g_b1gSelfTests.fetch_add(1);
            MCLA_LOG_WARN("B1-GUARD tag=SELFTEST trip={} addr={:X} want={} tid={}", n, fa,
                          wantWrite ? "W" : "R", GetCurrentThreadId());
            return true;  // the read instruction re-executes on restored RW
        }
        if (g_b1gLogged.fetch_add(1) < 48) {
            const uintptr_t rip = (uintptr_t)ei->ContextRecord->Rip;
            const uintptr_t rv =
                (g_moduleBase != 0 && rip >= g_moduleBase) ? rip - g_moduleBase : rip;
            uint32_t glr = 0;
            if (const PPCContext* pc = GetPPCContext()) glr = (uint32_t)pc->lr;
            MCLA_LOG_WARN("B1-GUARD tag={} trip={} addr={:X} want={} hostRIP=0x{:X} "
                          "guestLR={:08X} tid={}",
                          wasWatched ? "ACCESS" : "LATE", n, fa, wantWrite ? "W" : "R",
                          rv, glr, GetCurrentThreadId());
        }
        return true;
    }

    void B1GuardArmImpl(uint32_t guestVa) {
        if (g_base == nullptr || guestVa == 0) return;
        constexpr SIZE_T kLen = 4096;
        const uintptr_t host = (uintptr_t)(g_base + guestVa) & ~(uintptr_t)0xFFF;
        DWORD old = 0;
        g_b1gHost = host;
        g_b1gLen = kLen;
        if (!VirtualProtect((void*)host, kLen, PAGE_NOACCESS, &old)) {
            MCLA_LOG_WARN("B1-GUARD arm-FAIL va={:08X} host={:X} err={}", guestVa, host,
                          GetLastError());
            return;
        }
        B1GuardClaim(host);
        g_b1gArmed.store(true, std::memory_order_release);
        g_b1gSelfTest.store(true, std::memory_order_release);
        volatile uint32_t sink = 0;
        sink = *reinterpret_cast<volatile uint32_t*>(host);  // must trip: proves the watch lives
        (void)sink;
        g_b1gSelfTest.store(false, std::memory_order_release);
        const bool rearmed =
            VirtualProtect((void*)host, kLen, PAGE_NOACCESS, &old) != 0;
        if (rearmed) g_b1gArmed.store(true, std::memory_order_release);
        MCLA_LOG_WARN("B1-GUARD armed va={:08X} host={:X} live={} selftests={} trips={}",
                      guestVa, host, rearmed ? 1 : 0, g_b1gSelfTests.load(),
                      g_b1gTrips.load());
    }

    // Reverse map: host function entry -> guest address, for fault triage.
    std::unordered_map<uintptr_t, uint32_t> g_hostToGuest;
    void InsertFunction(uint32_t guest, PPCFunc* host)
    {
        PPC_LOOKUP_FUNC(g_base, guest) = host;
    }

    // Re-write one function-table slot from the canonical mapping. Used when
    // guest allocs (CDCD-FILL @0x8Cxxxxxx) zero entries inside the table
    // region that lives at guest VA 0x8B9E0000+.
    void RemapFunctionSlot(uint32_t guest)
    {
        if (g_base == nullptr)
            return;
        for (size_t i = 0; PPCFuncMappings[i].host != nullptr; i++)
        {
            if ((uint32_t)PPCFuncMappings[i].guest == guest)
            {
                InsertFunction(guest, PPCFuncMappings[i].host);
                return;
            }
        }
    }

    static uint32_t ReadU32BE(uint8_t* base, uint32_t guestAddr)
    {
        return __builtin_bswap32(*(volatile uint32_t*)(base + guestAddr));
    }

    static void WriteU32BE(uint8_t* base, uint32_t guestAddr, uint32_t value)
    {
        *(volatile uint32_t*)(base + guestAddr) = __builtin_bswap32(value);
    }

    bool AllocateGuestMemory()
    {
        // Share the window Memory::Memory() reserved at static-init so every
        // translation frontend (g_memory, GuestMemoryHeap, GuestMemoryView)
        // sees identical host addresses for a given guest address. Skipping
        // this forked the address space: g_memory stayed on its own window
        // while the boot host allocated a second one at a random base.
        if (mcla::kernel::g_memory.base != nullptr && mcla::kernel::g_memory.size >= GuestMemorySize)
        {
            g_base = mcla::kernel::g_memory.base;
            return true;
        }

        g_base = (uint8_t*)VirtualAlloc((void*)GuestMemoryBase, GuestMemorySize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
        if (g_base == nullptr)
        {
            // Fallback: any 32-byte-aligned region works (recomp code requires base % 0x20 == 0).
            g_base = (uint8_t*)VirtualAlloc(nullptr, GuestMemorySize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
        }
        if (g_base == nullptr)
        {
            return false;
        }

        // Keep g_memory in sync with whichever window we actually got.
        mcla::kernel::g_memory.base = g_base;
        mcla::kernel::g_memory.size = GuestMemorySize;

        // First-page NOACCESS guard (UnleashedRecomp canonical): trap null derefs
        DWORD oldProtect;
        VirtualProtect(g_base, 4096, PAGE_NOACCESS, &oldProtect);
        return true;
    }

    void InstallGuestImage(const Image& image)
    {
        std::memcpy(g_base + image.base, image.data.get(), image.size);
    }

    __attribute__((noinline)) void DumpImageRegion(uint32_t guestAddr, uint32_t words)
    {
        char lbuf[512];
        size_t o = 0;
        o += std::snprintf(lbuf + o, sizeof(lbuf) - o, "[boot] region-dump 0x%08X:", guestAddr);
        for (uint32_t i = 0; i < words; i++)
        {
            uint32_t v = ReadU32BE(g_base, guestAddr + i * 4);
            o += std::snprintf(lbuf + o, sizeof(lbuf) - o, " %08X", v);
        }
        BootReportInfo(lbuf);
    }

    size_t InstallFunctionTable()
    {
        size_t inserted = 0;
        g_hostToGuest.clear();
        for (size_t i = 0; PPCFuncMappings[i].host != nullptr; i++)
        {
            const uint32_t guest = (uint32_t)PPCFuncMappings[i].guest;
            PPCFunc* host = PPCFuncMappings[i].host;
            InsertFunction(guest, host);
            g_hostToGuest.emplace((uintptr_t)host, guest);
            inserted++;
        }
        // Runtime holes: 8C760 bctrls to vtable+88 = 0x821A5CC0 and AVs
        // when the table slot is null. Force-map the no-op stub.
        for (size_t i = 0; PPCFuncMappings[i].host != nullptr; i++)
        {
            if ((uint32_t)PPCFuncMappings[i].guest == 0x821A5CC0u)
            {
                InsertFunction(0x821A5CC0u, PPCFuncMappings[i].host);
                char lbuf[128];
                std::snprintf(lbuf, sizeof(lbuf),
                              "[boot] force-map 821A5CC0 -> %p",
                              (void*)PPCFuncMappings[i].host);
                BootReportInfo(lbuf);
                break;
            }
        }
        return inserted;
    }

    // Nearest guest function whose start address is <= `guest` (a return address).
    const char* GuestFunctionName(uint32_t guest)
    {
        static thread_local char buf[128];
        uint32_t best = 0;
        for (size_t i = 0; PPCFuncMappings[i].host != nullptr; i++)
        {
            if (PPCFuncMappings[i].guest <= guest && PPCFuncMappings[i].guest > best)
                best = (uint32_t)PPCFuncMappings[i].guest;
        }
        if (best != 0)
        {
            std::snprintf(buf, sizeof(buf), "0x%08x", best);
            return buf;
        }
        std::snprintf(buf, sizeof(buf), "0x%08x (unmapped)", guest);
        return buf;
    }

    void SetupInitialContext(PPCContext& ctx)
    {
        std::memset(&ctx, 0, sizeof(ctx));

        // Seed the FPSCR cache from the real host MXCSR. The recompiled code
        // only toggles rounding + flush bits via ctx.fpscr; if the cache starts
        // at zero, the first enableFlushMode() writes MXCSR = 0x8040, clearing
        // the exception-mask bits (0x1F80) and unmasking host FPU exceptions
        // (0xC000008F STATUS_FLOAT_MULTIPLE_FAULTS) in float-heavy guest code.
        // The mask bits are ORed in defensively (guest FP never faults on 360).
        ctx.fpscr.csr = ctx.fpscr.getcsr() | 0x1F80;

        // 2 MiB guest stack, clear of the image (image ends around 0x829E0000).
        constexpr uint32_t StackTop = 0x8F000000u;
        constexpr uint32_t StackSize = 0x200000u;
        std::memset(g_base + StackTop - StackSize, 0, StackSize);

        ctx.r1.u32 = StackTop; // r1 = stack pointer (grows down)
        ctx.msr = 0x200A000;   // FP/VMX bits, matches PPCContext default

        // Xbox 360 entry point (_xstart) expects:
        // r3 = module handle (image base)
        // r4 = reason (DLL_PROCESS_ATTACH = 1)
        // r5 = reserved (0)
        ctx.r3.u32 = 0x82000000; // image base
        ctx.r4.u32 = 1;          // DLL_PROCESS_ATTACH
        ctx.r5.u32 = 0;

        // Guest r13 thread block + XTL import dispatch chain.
        //
        // The generated thunks sub_82130528/550/588 (XTL allocation import)
        // resolve through r13:
        //   r11 = *(r13); r3 = *(r11 + 28); r9 = *r3; fn = *(r9 + 8|12); call fn
        // so slot 7 (offset 28) of the table at *(r13) must point at a
        // descriptor whose first word points at a function block holding the
        // alloc/free guest addresses at +8/+12. The resolved address is looked
        // up in the function table (PPC_CALL_INDIRECT_FUNC), so those guest
        // addresses must be registered via InsertFunction.
        //
        // The same block also serves the other r13 consumers found in the game:
        //   r13+0x100 (256): TEB pointer (last error stored at TEB+0x160)
        //   r13+0x10C (268): cpu number (byte)
        //   r13+0x150 (336): "program doesn't want errors" flag
        constexpr uint32_t ThreadBlock = 0x8F200000u; // clear of stack (0x8F000000) and image
        constexpr uint32_t TableBase = ThreadBlock + 0x1000;
        constexpr uint32_t Descriptor = ThreadBlock + 0x2000;
        constexpr uint32_t FuncBlock = ThreadBlock + 0x3000;
        constexpr uint32_t AllocFnGuest = ThreadBlock + 0x4000;
        constexpr uint32_t FreeFnGuest = ThreadBlock + 0x4010;
        constexpr uint32_t Teb = ThreadBlock + 0x5000;

        const auto storeU32 = [](uint32_t guestAddr, uint32_t value) {
            *(volatile uint32_t*)(g_base + guestAddr) = __builtin_bswap32(value);
        };

        std::memset(g_base + ThreadBlock, 0, 0x10000);

        ctx.r13.u32 = ThreadBlock;
        storeU32(ThreadBlock + 0x000, TableBase);
        storeU32(ThreadBlock + 0x100, Teb);
        *(volatile uint8_t*)(g_base + ThreadBlock + 0x10C) = 0; // cpu number
        storeU32(ThreadBlock + 0x150, 0);                       // "want errors" flag

        storeU32(TableBase + 28, Descriptor);
        storeU32(Descriptor + 0, FuncBlock);
        storeU32(FuncBlock + 8, AllocFnGuest);
        storeU32(FuncBlock + 12, FreeFnGuest);

        InsertFunction(AllocFnGuest, &__xtl_alloc);
        InsertFunction(FreeFnGuest, &__xtl_free);
    }

    // T4-final: faithful replay of the dead memory-device ctor / Mount("memory:")
    // special path. GETDEV("memory:"/"embedded:/") returns the static Device*
    // 0x827D838C (sub_821CB488: lis r11,-32130; addi r3,r11,-31860). The CRT
    // initializer sub_827B8B38 only installs the BASE vtable 0x8201206C whose
    // +16 slot is the no-op stub 0x82762480, so EMB76 (open = 0x821CB070 on
    // vtable 0x82012918+16) never fires. Replay the stores the dead chain
    // should have produced, before CRT overwrites and before shader preload.
    //
    // Field cites (guest store instructions, identity map VA-0x82000000):
    //   [0x827D838C] = 0x82012918   // vtable: CRT sub_827B8B38 stw r11,-31860(r10)
    //                                 //   but r11 must be the MEMORY table
    //                                 //   (scan of .rdata: 82012918 holds
    //                                 //    AE50/AFB8/CB070/CB400), not base
    //                                 //   0x8201206C (addi r11,r11,8300).
    //   [0x827D8380] = 0x827D838C   // fallback Device*: Mount sub_821CB9D8
    //                                 //   stw r26,-31872(r11) for path=="memory:"
    //   name "memory:" @ image       // Mount/GETDEV prefix, string 0x820127D8
    //   276-byte handler link        // Mount general path: sub_821CB760 inits
    //                                 //   entry+268/272/274; name at +0, flag
    //                                 //   +262, nameLen +264. GETDEV prefix
    //                                 //   path does not scan this table, so
    //                                 //   the link is installed for the
    //                                 //   fallback/no-prefix path only.
    // Seed the embedded:/ name list with static .data blobs that the CRT
    // .CRT$XCU inits would have registered via sub_821D22E8. Our boot host
    // jumps at the game entry and those inits never run — AFB76 therefore
    // sees an empty list. Nodes live in image .data (no heap Alloc).
    // Triples decoded from every `bl 0x821d22e8` under 0x827A/0x827B
    // (recompiled bodies confirm signed addi).
    // Format matches D22E8: {name*, buf, size, next} pushed at 0x82860AF8.
    static void SeedEmbeddedNameList()
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        constexpr uint32_t kListHead = 0x82860AF8;

        struct Seed {
            uint32_t node, name, buf, size;
        };
        // node addresses are the CRT-provided static storage (r3 of D22E8).
        const Seed seeds[] = {
            {0x828395B8u, 0x820093D4u, 0x827D2DD0u, 5258u},   // rage_im
            {0x82839D7Cu, 0x8200A06Cu, 0x827D4458u, 5406u},   // fastmipmap
            {0x8288B8E0u, 0x820418B0u, 0x827E2CB0u, 10331u},  // spotlightfog
            {0x828D47A4u, 0x8206ABDCu, 0x827F3C48u, 3187u},   // rage_bink
            {0x828D4D2Cu, 0x8206DD30u, 0x827F5380u, 3612u},   // rmptfx_default
            {0x828D4D60u, 0x8206DD50u, 0x827F61A0u, 8133u},   // rmptfx_litsprite
            {0x828D4D3Cu, 0x8206DD70u, 0x827F8168u, 138u},    // dcl rmptfx_default
            {0x828D4D1Cu, 0x8206DD88u, 0x827F81F8u, 138u},    // dcl rmptfx_litsprite
            {0x828D5054u, 0x8206FD38u, 0x827F9CE8u, 32280u},  // atmoscatt_clouds
            {0x828D5044u, 0x8206FD5Cu, 0x82801B00u, 5713u},   // perlinnoise
            {0x828D5074u, 0x820700A0u, 0x82803540u, 4564u},   // rmptfx_collision
            {0x829019ECu, 0x82086280u, 0x82813908u, 5112u},   // shadowcollector
            {0x829019FCu, 0x820862A4u, 0x82814D00u, 4347u},   // shadowdepth
            {0x82901A1Cu, 0x82086678u, 0x82815E48u, 18323u},  // blendshadows
            {0x829054C0u, 0x82089394u, 0x8281BB00u, 48u},     // rage_postfx
        };

        uint32_t head = 0;
        mem.ReadU32BE(kListHead, &head);
        int n = 0;
        for (const Seed& s : seeds)
        {
            mem.WriteU32BE(s.node + 0, s.name);
            mem.WriteU32BE(s.node + 4, s.buf);
            mem.WriteU32BE(s.node + 8, s.size);
            mem.WriteU32BE(s.node + 12, head);
            head = s.node;
            ++n;
        }
        mem.WriteU32BE(kListHead, head);
        char lbuf[128];
        std::snprintf(lbuf, sizeof(lbuf),
                      "[boot] embed-seed %d CRT triples, listHead=%08X", n,
                      head);
        BootReportInfo(lbuf);
    }

    static void ReplayDeadMemoryDeviceCtor()
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        constexpr uint32_t kMemDeviceObj = 0x827D838C; // GETDEV prefix return
        constexpr uint32_t kFallbackPtr = 0x827D8380;  // Mount("memory:") slot
        constexpr uint32_t kMemVtable = 0x82012918;    // AE50/AFB8/B070/B400

        // Only image .data stores. Do NOT write guest heap scratch (0xA00xxxxx)
        // here — that landed in o1heap fragments and produced
        // sysMemMultiAllocator::Free "Not owned by any known heap".
        // [0x827D838C+0] = memory vtable (override CRT's 0x8201206C).
        mem.WriteU32BE(kMemDeviceObj + 0, kMemVtable);
        // [0x827D8380] = Device* fallback = the static object itself.
        mem.WriteU32BE(kFallbackPtr, kMemDeviceObj);

        SeedEmbeddedNameList();

        uint32_t vt = 0, fb = 0, head = 0;
        mem.ReadU32BE(kMemDeviceObj, &vt);
        mem.ReadU32BE(kFallbackPtr, &fb);
        mem.ReadU32BE(0x82860AF8u, &head);
        char lbuf[192];
        std::snprintf(lbuf, sizeof(lbuf),
                      "[boot] dead-ctor replay: vt@%08X=%08X fallback@%08X=%08X "
                      "listHead=%08X",
                      kMemDeviceObj, vt, kFallbackPtr, fb, head);
        BootReportInfo(lbuf);
    }

    void SeedPreBootSlots()
    {
        ReplayDeadMemoryDeviceCtor();

        // The fatal-error dispatcher (Function_821BD618) reads slot 0x8285FEA0
        // and calls it when non-zero. Leave it ZERO so the dispatcher
        // branches straight to its infinite loop (b .) instead of calling
        // a handler that might return and trigger the debugtrap in the loop.
        constexpr uint32_t SlotAddr = 0x8285FEA0;
        uint32_t slotValue = 0;
        std::memcpy(&slotValue, g_base + SlotAddr, sizeof(slotValue));
        const uint32_t slotBE = __builtin_bswap32(slotValue);
        if (slotBE != 0)
        {
            char lbuf[192];
            std::snprintf(lbuf, sizeof(lbuf), "[boot] pre-boot init: slot @0x%08X already 0x%08X; leaving as-is",
                          SlotAddr, slotBE);
            BootReportInfo(lbuf);
        }
        else
        {
            BootReportInfo("[boot] pre-boot init: slot @0x8285FEA0 left zero (dispatcher will loop)");
        }

        // Global table pointer at 0x8288E5AC read by sub_82388598. Point it at
        // a valid guest scratch table region so the load succeeds.
        constexpr uint32_t TablePtrAddr = 0x8288E5AC;
        constexpr uint32_t ScratchTable = 0x8F207000;
        uint32_t tablePtrVal = 0;
        std::memcpy(&tablePtrVal, g_base + TablePtrAddr, sizeof(tablePtrVal));
        if (__builtin_bswap32(tablePtrVal) == 0)
        {
            const uint32_t scratchBE = __builtin_bswap32(ScratchTable);
            std::memcpy(g_base + TablePtrAddr, &scratchBE, sizeof(scratchBE));
            char lbuf[192];
            std::snprintf(lbuf, sizeof(lbuf), "[boot] pre-boot init: table ptr @0x%08X populated with scratch table 0x%08X",
                          TablePtrAddr, ScratchTable);
            BootReportInfo(lbuf);
        }
    }

} // namespace boot internals (keep NearestFunctionName below in same ns)

// CRT .CRT$XCU initializer that would install the BASE vtable 0x8201206C into
// the static memory-device object at 0x827D838C. Override so the object keeps
// the real memory-family vtable 0x82012918 (EMB76 / open = sub_821CB070).
// Guest stores, cited:
//   stw r11,-31860(r10)  @0x827B8B38+0x0C  -> [0x827D838C] = vtable
//   (r11 was addi r11,r11,8300 = 0x8201206C; we write 0x82012918)
PPC_FUNC_IMPL(__imp__sub_827B8B38);
PPC_FUNC(sub_827B8B38) {
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
    constexpr uint32_t kMemDeviceObj = 0x827D838C;
    constexpr uint32_t kMemVtable = 0x82012918;
    mem.WriteU32BE(kMemDeviceObj + 0, kMemVtable);
    // Mount("memory:") special path: stw r26,-31872(r11) -> [0x827D8380]=dev*
    mem.WriteU32BE(0x827D8380, kMemDeviceObj);
}

// Sibling CRT init writes the same base vtable into 0x827D8388. Keep it in
// sync so neighboring statics stay consistent if anything aliases them.
PPC_FUNC_IMPL(__imp__sub_827B8B20);
PPC_FUNC(sub_827B8B20) {
    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
    mem.WriteU32BE(0x827D8388, 0x82012918);
}

namespace { // resume file-local helpers

    const char* NearestFunctionName(uint64_t hostAddr)
    {
        static thread_local char buf[160];
        const uintptr_t pc = (uintptr_t)hostAddr;

        // Walk unwind metadata to get the real containing host function start.
        DWORD64 imageBase = 0;
        const PRUNTIME_FUNCTION fn = RtlLookupFunctionEntry(pc, &imageBase, nullptr);
        if (fn != nullptr)
        {
            const uintptr_t start = imageBase + fn->BeginAddress;
            auto it = g_hostToGuest.find(start);
            if (it != g_hostToGuest.end())
            {
                std::snprintf(buf, sizeof(buf), "0x%08x", it->second);
                return buf;
            }
        }

        // Host-only code (kernel imports, our C++): ask the PDB via dbghelp.
        {
            static std::once_flag symOnce;
            std::call_once(symOnce, []() {
                SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS);
                SymInitialize(GetCurrentProcess(), nullptr, TRUE);
            });
            SYMBOL_INFO* si = (SYMBOL_INFO*)buf;
            // Use a scratch buffer: SYMBOL_INFO must precede the name.
            alignas(8) char scratch[sizeof(SYMBOL_INFO) + 96];
            si = (SYMBOL_INFO*)scratch;
            si->SizeOfStruct = sizeof(SYMBOL_INFO);
            si->MaxNameLen = 95;
            DWORD64 disp = 0;
            if (SymFromAddr(GetCurrentProcess(), pc, &disp, si))
            {
                std::snprintf(buf, sizeof(buf), "%s+0x%llx", si->Name,
                              (unsigned long long)disp);
                return buf;
            }
        }

        // Fallback: the PC may sit in a merged/leaf-thunk region with no unwind
        // entry of its own (identical-code folding splits chunks). Scan the full
        // mapping table for the function whose host start is the closest one <= PC.
        PPCFunc* closest = nullptr;
        for (size_t i = 0; PPCFuncMappings[i].host != nullptr; i++)
        {
            PPCFunc* h = PPCFuncMappings[i].host;
            if ((uintptr_t)h <= pc && (closest == nullptr || (uintptr_t)h > (uintptr_t)closest))
                closest = h;
        }
        if (closest != nullptr)
        {
            const uintptr_t start = (uintptr_t)closest;
            std::snprintf(buf, sizeof(buf), "0x%08x (+0x%llx)", g_hostToGuest[start],
                          (unsigned long long)(pc - start));
            return buf;
        }

        std::snprintf(buf, sizeof(buf), "host 0x%llx", (unsigned long long)hostAddr);
        return buf;
    }

    // T38.2b (F-046): "which translated guest function contains the faulting host RIP"
    // is answerable WITHOUT the context registers, so it survives the wrong-frame problem.
    // Allocation- and lock-free on purpose (unwind metadata + the static mapping table):
    // this runs inside the VEH handler, where NearestFunctionName's dbghelp path does not.
    const char* GuestFnAtHostAddr(uint64_t hostAddr)
    {
        static thread_local char buf[80];
        DWORD64 imageBase = 0;
        const PRUNTIME_FUNCTION fn = RtlLookupFunctionEntry((DWORD64)hostAddr, &imageBase, nullptr);
        if (fn == nullptr)
        {
            std::snprintf(buf, sizeof(buf), "no unwind entry");
            return buf;
        }
        const uintptr_t start = (uintptr_t)(imageBase + fn->BeginAddress);
        for (size_t i = 0; PPCFuncMappings[i].host != nullptr; i++)
        {
            if ((uintptr_t)PPCFuncMappings[i].host == start)
            {
                // The offset is HOST code bytes from the translated function's entry, not a guest PC
                // displacement — 0x82304348 + 0x144 decoded as guest is a block that never ran (F-050).
                std::snprintf(buf, sizeof(buf), "guest 0x%08zX (host+0x%llX)", PPCFuncMappings[i].guest,
                              (unsigned long long)(hostAddr - start));
                return buf;
            }
        }
        std::snprintf(buf, sizeof(buf), "host 0x%llx, not a mapped guest fn",
                      (unsigned long long)start);
        return buf;
    }

    static void CaptureFaultInfo(EXCEPTION_POINTERS* info, BootReport& report, bool captureStack)
    {
        const uintptr_t pc = (uintptr_t)info->ContextRecord->Rip;

        if (captureStack)
        {
            void* frames[24] = {};
            const WORD n = RtlCaptureStackBackTrace(0, 24, frames, nullptr);
            report.faultStack.clear();
            for (WORD i = 0; i < n; i++)
            {
                const uintptr_t fa = (uintptr_t)frames[i];
                char buf[128];
                std::snprintf(buf, sizeof(buf), "0x%016zx %s", (size_t)fa, NearestFunctionName(fa));
                report.faultStack.emplace_back(buf);
            }
        }

        DWORD64 imageBase = 0;
        const PRUNTIME_FUNCTION fn = RtlLookupFunctionEntry(pc, &imageBase, nullptr);
        if (fn != nullptr)
        {
            report.faultOwnerStart = imageBase + fn->BeginAddress;
            report.faultOwnerOffset = pc - report.faultOwnerStart;
        }
        report.faultInfo = NearestFunctionName(pc);
        report.faultHost = pc;
        report.faultRva = pc - g_moduleBase;
        report.faultCode = info->ExceptionRecord->ExceptionCode;
        report.faultAddr = (uintptr_t)info->ExceptionRecord->ExceptionInformation[1];
        report.readFault = info->ExceptionRecord->ExceptionInformation[0] == 0;

        report.faultRax = info->ContextRecord->Rax;
        report.faultRbx = info->ContextRecord->Rbx;
        report.faultRcx = info->ContextRecord->Rcx;
        report.faultRdx = info->ContextRecord->Rdx;
        report.faultRsi = info->ContextRecord->Rsi;
        report.faultRdi = info->ContextRecord->Rdi;
        report.faultR1 = g_faultCtx ? g_faultCtx->r1.u32 : 0;
        report.faultR3 = g_faultCtx ? g_faultCtx->r3.u32 : 0;
        report.faultR13 = g_faultCtx ? g_faultCtx->r13.u32 : 0;
        report.faultLR = g_faultCtx ? (uint32_t)g_faultCtx->lr : 0;
        if (g_faultCtx != nullptr)
        {
            std::memset(report.faultGpr, 0, sizeof(report.faultGpr));
            report.faultGpr[1] = g_faultCtx->r1.u32;
            report.faultGpr[3] = g_faultCtx->r3.u32;
            report.faultGpr[4] = g_faultCtx->r4.u32;
            report.faultGpr[5] = g_faultCtx->r5.u32;
            report.faultGpr[6] = g_faultCtx->r6.u32;
            report.faultGpr[7] = g_faultCtx->r7.u32;
            report.faultGpr[8] = g_faultCtx->r8.u32;
            report.faultGpr[9] = g_faultCtx->r9.u32;
            report.faultGpr[10] = g_faultCtx->r10.u32;
            report.faultGpr[13] = g_faultCtx->r13.u32;
        }

        std::memset(report.faultBytes, 0, sizeof(report.faultBytes));
        if (pc >= g_moduleBase)
            std::memcpy(report.faultBytes, (const void*)pc, sizeof(report.faultBytes));

        if (g_base != nullptr)
        {
            for (int i = 0; i < 16; i++)
                report.faultTable[i] = ReadU32BE(g_base, 0x827EB900u + (uint32_t)i * 4);
        }

        if (report.faultR1 != 0 && g_base != nullptr)
        {
            uint32_t callerLR = 0;
            std::memcpy(&callerLR, g_base + report.faultR1 + 88, sizeof(callerLR));
            report.faultCallerLR = callerLR;
        }
    }

    int FilterCapture(EXCEPTION_POINTERS* info)
    {
        CaptureFaultInfo(info, g_report, true);
        return EXCEPTION_EXECUTE_HANDLER;
    }

    void LogReport()
    {
        std::scoped_lock lock(g_reportMutex);
        char lbuf[256];
        std::snprintf(lbuf, sizeof(lbuf), "[boot] entry=0x%08X returned=%d",
                      g_report.entryGuest, g_report.returned ? 1 : 0);
        BootReportInfo(lbuf);
        if (g_report.returned)
            return;
        std::snprintf(lbuf, sizeof(lbuf), "[boot] fault: code=0x%08X read=%d addr=0x%016zX host=0x%016zX rva=0x%zX in %s",
                      g_report.faultCode, g_report.readFault ? 1 : 0, (size_t)g_report.faultAddr,
                      (size_t)g_report.faultHost, (size_t)g_report.faultRva, g_report.faultInfo.c_str());
        BootReportError(lbuf);
        if (g_report.faultOwnerStart != 0)
        {
            std::snprintf(lbuf, sizeof(lbuf), "[boot] fault owner host=0x%016zX +0x%zX",
                          (size_t)g_report.faultOwnerStart, (size_t)g_report.faultOwnerOffset);
            BootReportError(lbuf);
        }
        std::snprintf(lbuf, sizeof(lbuf), "[boot] r1=0x%08X r3=0x%08X r13=0x%08X lr=0x%08X callerLR=0x%08X",
                      g_report.faultR1, g_report.faultR3, g_report.faultR13,
                      g_report.faultLR, g_report.faultCallerLR);
        BootReportError(lbuf);
        {
            char tbuf[256];
            int o = std::snprintf(tbuf, sizeof(tbuf), "[boot] fault-table 0x827EB900:");
            for (int i = 0; i < 16; i++)
                o += std::snprintf(tbuf + o, sizeof(tbuf) - (size_t)o, " %08X", g_report.faultTable[i]);
            BootReportInfo(tbuf);
        }
        // Reverse-lookup the fault owner host address to a guest address
        if (g_report.faultOwnerStart != 0)
        {
            auto it = g_hostToGuest.find(g_report.faultOwnerStart);
            if (it != g_hostToGuest.end())
            {
                std::snprintf(lbuf, sizeof(lbuf), "[boot] fault guest=0x%08X (+0x%zX)",
                              it->second, (size_t)g_report.faultOwnerOffset);
                BootReportError(lbuf);
            }
        }
        for (const auto& line : g_report.faultStack)
        {
            std::snprintf(lbuf, sizeof(lbuf), "[boot]   stack %s", line.c_str());
            BootReportInfo(lbuf);
        }
    }

    // Use SetUnhandledExceptionFilter instead of VEH+SEH for fault handling
// This avoids SEH which causes clang-cl ICE and CRT linkage issues with MSVC

static LONG WINAPI UnhandledExceptionFilter(PEXCEPTION_POINTERS info)
{
    if (g_faultCtx == nullptr)
        return EXCEPTION_CONTINUE_SEARCH;

    CaptureFaultInfo(info, g_report, false);
    // W0: do not let the process die. Park this thread so the window survives.
    spdlog::default_logger()->flush();
    for (;;)
        Sleep(1000);
    return EXCEPTION_EXECUTE_HANDLER; // unreachable
}

// SEH-safe stack-slot read: C-style free function with no C++ objects that
// require unwinding. clang-cl ICEs compiling __try inside the VEH lambda
// below (same ICE class as kernel/heap.cpp SehO1Allocate and the note at
// line 653: SEH + unwinding objects in one function). Callers pass POD only.
#if defined(_MSC_VER)
static uint64_t SehReadStackSlot(const uint64_t *p)
{
    uint64_t v = 0;
    __try { v = *p; } __except (EXCEPTION_EXECUTE_HANDLER) { v = 0; }
    return v;
}
#endif

void BootWorker(uint32_t entryGuest)
{
    // Publish this host thread as the guest "main thread" for park probes.
    g_mainGuestThreadId.store(GetCurrentThreadId());

    PPCFunc* entryFunc = PPC_LOOKUP_FUNC(g_base, entryGuest);
    if (entryFunc == nullptr)
    {
        std::scoped_lock lock(g_reportMutex);
        g_report.faultInfo = "entry point not present in function table";
        g_bootDone.store(true);
        return;
    }

    PPCContext ctx;
    SetupInitialContext(ctx);
    ctx.lr = 0x00FFFFFF;

    // Publish this thread's context: hand-written kernel imports read
    // registers via the thread-local g_ppcContext (generated code gets ctx as
    // a parameter). Without this the first such import AV'd reading
    // g_ppcContext->r13 at offsetof 0x48 on a null pointer.
    SetPPCContext(ctx);

    g_faultCtx = &ctx;
    g_faultCtxTag = "boot-root";

// Install vectored exception handler for early crash detection
    PVOID vehHandle = AddVectoredExceptionHandler(1, [](PEXCEPTION_POINTERS ExceptionInfo) -> LONG {
        DWORD code = ExceptionInfo->ExceptionRecord->ExceptionCode;
        PVOID addr = ExceptionInfo->ExceptionRecord->ExceptionAddress;
        DWORD flags = ExceptionInfo->ExceptionRecord->ExceptionFlags;
        ULONG_PTR* info = ExceptionInfo->ExceptionRecord->ExceptionInformation;
        DWORD nInfo = ExceptionInfo->ExceptionRecord->NumberParameters;
        const uintptr_t pc = (uintptr_t)addr;
        const uintptr_t rva = (g_moduleBase != 0 && pc >= g_moduleBase) ? pc - g_moduleBase : pc;

        // B1: DR watchpoint single-steps are ours — log and continue BEFORE any
        // of the census/park machinery below sees them (they would eat the
        // fullDump budget and could park a healthy consumer thread).
        if (code == 0x80000004L && B1HandleSingleStep(ExceptionInfo)) {
            return EXCEPTION_CONTINUE_EXECUTION;
        }

        // B1 guard-page watchpoint (F-100 rule 19): same reason — must be
        // resolved before the census/park machinery, which would otherwise spend
        // the fullDump budget and park a thread that is merely the consumer.
        if (code == 0xC0000005L && B1GuardHandle(ExceptionInfo)) {
            return EXCEPTION_CONTINUE_EXECUTION;
        }

        // W0 flood cap: full dump only for the first few exceptions. Later
        // faults on other threads get a one-liner and still get parked.
        static std::atomic<uint32_t> s_vehCount{0};
        const uint32_t vehN = s_vehCount.fetch_add(1, std::memory_order_relaxed);
        const bool fullDump = (vehN < 3);

        // Write crash dump to file immediately (in case log doesn't flush)
        if (fullDump) {
        FILE* crashFile = nullptr;
        fopen_s(&crashFile, "crash_dump.txt", "w");
        if (crashFile) {
            fprintf(crashFile, "Exception: code=0x%08X addr=0x%p rva=0x%X flags=0x%X nParams=%u thread=%lu\n",
                    code, addr, rva, flags, nInfo, GetCurrentThreadId());
            for (DWORD i = 0; i < nInfo; ++i) {
                fprintf(crashFile, "  Param[%u]=0x%p\n", i, (PVOID)info[i]);
            }
            
            // Register-independent attribution (survives a stale/wrong-context dump).
            fprintf(crashFile, "  rip owner=%s\n", GuestFnAtHostAddr(pc));

            // PPC context
            if (const PPCContext* fc = g_faultCtx) {
                fprintf(crashFile, "  ppc ctx=%p tag=%s tid=%lu (registers below belong to THIS context)\n",
                        (const void*)fc, g_faultCtxTag, GetCurrentThreadId());
                fprintf(crashFile, "  ppc r1=%08X lr=%08X r3=%08X r4=%08X r5=%08X r6=%08X r7=%08X r8=%08X r9=%08X r10=%08X r13=%08X\n",
                        fc->r1.u32, (uint32_t)fc->lr, fc->r3.u32, fc->r4.u32, fc->r5.u32,
                        fc->r6.u32, fc->r7.u32, fc->r8.u32, fc->r9.u32, fc->r10.u32, fc->r13.u32);
                // T38.2 (revised at build time): PPCContext has NO ctr/xer/r11/r30
                // members — ppc_config.h makes them host locals
                // (PPC_CONFIG_CTR_AS_LOCAL / _NON_ARGUMENT_AS_LOCAL / _NON_VOLATILE_AS_LOCAL),
                // so they can never be dumped. What CAN settle the 0x7E780000 family is
                // identity-testing the fault address against the function-table probe
                // PPC_LOOKUP_FUNC(base,y) for the candidate targets, because the generated
                // code does `ctr.u64 = ctx.rN.u64` straight before the call.
                const uint64_t b = (uint64_t)(uintptr_t)g_base;
                fprintf(crashFile, "  g_base=0x%llX table=0x%llX\n",
                        (unsigned long long)b,
                        (unsigned long long)(b + PPC_IMAGE_BASE + PPC_IMAGE_SIZE));
                for (const uint32_t cand :
                     { (uint32_t)0u, fc->r8.u32, fc->r9.u32, fc->r3.u32, (uint32_t)fc->lr }) {
                    const uint64_t s64 = (uint64_t)PPC_IMAGE_BASE + PPC_IMAGE_SIZE +
                                         (uint64_t(uint32_t(cand) - PPC_CODE_BASE) * 2);
                    const bool hit = code == 0xC0000005 && nInfo >= 2 &&
                            (uint32_t)(uintptr_t)info[1] == (uint32_t)s64;
                    fprintf(crashFile, "  probe y=%08X -> off32=0x%08X%s\n", cand,
                            (uint32_t)s64, hit ? " == Param[1] (base contributed 0)" : "");
                }
            } else {
                fprintf(crashFile, "  ppc ctx=nil tag=%s tid=%lu — nothing published on the faulting thread;"
                                   " any GPR read from this dump would be another frame's (F-046)\n",
                        g_faultCtxTag, GetCurrentThreadId());
            }
            
            // Host registers
            if (code == 0xC0000005 && ExceptionInfo->ContextRecord) {
                const CONTEXT* c = ExceptionInfo->ContextRecord;
                fprintf(crashFile, "  host regs rip=%p rax=%p rbx=%p rcx=%p rdx=%p rsi=%p rdi=%p r8=%p r9=%p r10=%p r11=%p rsp=%p\n",
                        (PVOID)c->Rip, (PVOID)c->Rax, (PVOID)c->Rbx, (PVOID)c->Rcx, (PVOID)c->Rdx,
                        (PVOID)c->Rsi, (PVOID)c->Rdi, (PVOID)c->R8, (PVOID)c->R9,
                        (PVOID)c->R10, (PVOID)c->R11, (PVOID)c->Rsp);
            }

            // Session 76b: locate the faulting value in guest memory —
            // find which structure carries the garbage pointer.
            if (code == 0xC0000005 && nInfo >= 2) {
                const uint32_t needle = (uint32_t)(uintptr_t)info[1];
                if (needle != 0) {
                    uint8_t pat[4] = {(uint8_t)(needle >> 24),
                                      (uint8_t)(needle >> 16),
                                      (uint8_t)(needle >> 8),
                                      (uint8_t)needle};
                    struct Range { uint32_t lo, hi; const char* name; };
                    const Range ranges[] = {
                        {0x00600000, 0x00800000, "stacks"},
                        {0x50000000, 0x60000000, "inflate-out"},
                        {0xA0000000, 0xB0000000, "phys-heap"},
                        {0x82000000, 0x82AD3000, "image+bss"},
                    };
                    uint8_t* guestBase = (uint8_t*)mcla::kernel::g_memory.base;
                    int hits = 0;
                    for (const auto& r : ranges) {
                        uint8_t* p = guestBase + r.lo;
                        const size_t len = r.hi - r.lo;
                        for (size_t i = 0; i + 4 <= len && hits < 8; ++i) {
                            if (p[i] == pat[0] && p[i+1] == pat[1] &&
                                p[i+2] == pat[2] && p[i+3] == pat[3]) {
                                const uint32_t va = r.lo + (uint32_t)i;
                                fprintf(crashFile,
                                        "  needle %08X @ guest %08X (%s): ",
                                        needle, va, r.name);
                                for (int k = -16; k < 16; k += 4) {
                                    if ((int)i + k >= 0) {
                                        uint32_t w;
                                        memcpy(&w, p + i + k, 4);
                                        fprintf(crashFile, "%08X ", w);
                                    }
                                }
                                fprintf(crashFile, "\n");
                                ++hits;
                                i += 4;
                            }
                        }
                        if (hits >= 8) break;
                    }
                    if (hits == 0)
                        fprintf(crashFile, "  needle %08X: no occurrences in scanned regions\n", needle);
                }
            }

            // Session 76g: dump the device-list neighborhood around the
            // faulting ppc r6 (the device object whose name ptr = garbage).
            if (code == 0xC0000005 && g_faultCtx) {
                const uint32_t r6v = g_faultCtx->r6.u32;
                if (r6v >= 0xA0000000u && r6v < 0xB0000000u) {
                    uint8_t* guestBase = (uint8_t*)mcla::kernel::g_memory.base;
                    uint8_t* p = guestBase + (r6v & ~0xFu) - 0x40;
                    fprintf(crashFile, "  device dump around r6=%08X:\n", r6v);
                    for (int row = 0; row < 12; ++row) {
                        fprintf(crashFile, "   %08X:", (r6v & ~0xFu) - 0x40 + row*16);
                        for (int w = 0; w < 4; ++w) {
                            uint32_t v;
                            memcpy(&v, p + row*16 + w*4, 4);
                            fprintf(crashFile, " %08X", v);
                        }
                        fprintf(crashFile, "\n");
                    }
                }
            }
            
            // Stack trace
            if (code == 0xC0000005 || code == 0x80000003 || code == 0xE06D7363) {
                static std::once_flag symOnce;
                std::call_once(symOnce, [] {
                    SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS);
                    SymInitialize(GetCurrentProcess(), nullptr, TRUE);
                });
                void* frames[32] = {};
                const USHORT nFrames = CaptureStackBackTrace(0, 32, frames, nullptr);
                fprintf(crashFile, "Stack trace (%hu frames):\n", nFrames);
                char symBuf[sizeof(SYMBOL_INFO) + 160] = {};
                auto* sym = reinterpret_cast<SYMBOL_INFO*>(symBuf);
                sym->SizeOfStruct = sizeof(SYMBOL_INFO);
                sym->MaxNameLen = 159;
                SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS);
                SymInitialize(GetCurrentProcess(), nullptr, TRUE);
                for (USHORT i = 0; i < 32 && i < (USHORT)nFrames; ++i) {
                    DWORD64 disp = 0;
                    char symBuf2[sizeof(SYMBOL_INFO) + 160] = {};
                    auto* sym = reinterpret_cast<SYMBOL_INFO*>(symBuf2);
                    sym->SizeOfStruct = sizeof(SYMBOL_INFO);
                    sym->MaxNameLen = 159;
                    if (SymFromAddr(GetCurrentProcess(), reinterpret_cast<DWORD64>(frames[i]), nullptr, sym)) {
                        fprintf(crashFile, "  [%02u] %s\n", i, sym->Name);
                    } else {
                        fprintf(crashFile, "  [%02u] ??? 0x%p\n", i, frames[i]);
                    }
                }
            }
            fflush(crashFile);
            fclose(crashFile);
        }
        } // fullDump

        if (!fullDump) {
            MCLA_LOG_ERROR("VEH[{}] (capped) code=0x{:08X} addr=0x{:p} nParams={} thread={}",
                           vehN, code, addr, nInfo, GetCurrentThreadId());
        } else {
        MCLA_LOG_ERROR("Vectored exception: code=0x{:08X} addr=0x{:p} rva=0x{:X} flags=0x{:X} nParams={} thread={}",
                       code, addr, rva, flags, nInfo, GetCurrentThreadId());
        for (DWORD i = 0; i < nInfo; ++i) {
            MCLA_LOG_ERROR("  Param[{}]=0x{:p}", i, (PVOID)info[i]);
        }
        // Register-independent attribution: the translated guest function that
        // contains the faulting host instruction.
        MCLA_LOG_ERROR("  rip owner={}", GuestFnAtHostAddr(pc));
        if (const PPCContext* fc = g_faultCtx)
        {
            MCLA_LOG_ERROR("  ppc ctx={:p} tag={} tid={} (registers below belong to THIS context)",
                           (const void*)fc, g_faultCtxTag, GetCurrentThreadId());
            MCLA_LOG_ERROR("  ppc r1={:08X} lr={:08X} r3={:08X} r4={:08X} r5={:08X} r6={:08X} "
                           "r7={:08X} r8={:08X} r9={:08X} r10={:08X} r13={:08X}",
                           fc->r1.u32, (uint32_t)fc->lr, fc->r3.u32, fc->r4.u32, fc->r5.u32,
                           fc->r6.u32, fc->r7.u32, fc->r8.u32, fc->r9.u32, fc->r10.u32, fc->r13.u32);
            // T38.2 (revised at build time): ctr/xer/r11/r30 are NOT PPCContext members
            // (ppc_config.h PPC_CONFIG_CTR_AS_LOCAL / _NON_ARGUMENT_AS_LOCAL /
            // _NON_VOLATILE_AS_LOCAL make them host locals), so the dump can never carry
            // them. Identity-test the fault address against the function-table probe
            // instead — the generated code copies a ctx register into ctr immediately
            // before PPC_CALL_INDIRECT_FUNC, so one of these candidates must match.
            const uint64_t b = (uint64_t)(uintptr_t)g_base;
            MCLA_LOG_ERROR("  g_base=0x{:X} table=0x{:X}", b,
                           b + PPC_IMAGE_BASE + PPC_IMAGE_SIZE);
            for (const uint32_t cand :
                 { (uint32_t)0u, fc->r8.u32, fc->r9.u32, fc->r3.u32, (uint32_t)fc->lr })
            {
                const uint64_t s64 = (uint64_t)PPC_IMAGE_BASE + PPC_IMAGE_SIZE +
                                     (uint64_t(uint32_t(cand) - PPC_CODE_BASE) * 2);
                MCLA_LOG_ERROR("  probe y={:08X} -> off32=0x{:08X}{}", cand, (uint32_t)s64,
                               code == 0xC0000005 && nInfo >= 2 &&
                                       (uint32_t)(uintptr_t)info[1] == (uint32_t)s64
                                   ? " == Param[1] (base contributed 0)"
                                   : "");
            }
        }
        else
        {
            MCLA_LOG_ERROR("  ppc ctx=nil tag={} tid={} — nothing published on the faulting thread;"
                           " any GPR read from this dump would be another frame's (F-046)",
                           g_faultCtxTag, GetCurrentThreadId());
        }

        // Host GP registers - session 17: pin which pointer is the bad raw
        // host address (e.g. 0x7E780000) at indirect-dispatch fault sites.
        if (code == 0xC0000005 && ExceptionInfo->ContextRecord)
        {
            const CONTEXT* c = ExceptionInfo->ContextRecord;
            MCLA_LOG_ERROR("  host regs rip={:p} rax={:p} rbx={:p} rcx={:p} rdx={:p} rsi={:p} rdi={:p} "
                           "r8={:p} r9={:p} r10={:p} r11={:p} rsp={:p}",
                           (PVOID)c->Rip, (PVOID)c->Rax, (PVOID)c->Rbx, (PVOID)c->Rcx, (PVOID)c->Rdx,
                           (PVOID)c->Rsi, (PVOID)c->Rdi, (PVOID)c->R8, (PVOID)c->R9,
                           (PVOID)c->R10, (PVOID)c->R11, (PVOID)c->Rsp);
        }

        // resolve host symbols from the PDB so crashes name themselves
        if (code == 0xC0000005 || code == 0x80000003 || code == 0xE06D7363)
        {
            static std::once_flag symOnce;
            std::call_once(symOnce, [] {
                SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS);
                SymInitialize(GetCurrentProcess(), nullptr, TRUE);
            });
            void* frames[24] = {};
            const USHORT nFrames = CaptureStackBackTrace(0, 24, frames, nullptr);
            char symBuf[sizeof(SYMBOL_INFO) + 160] = {};
            auto* sym = reinterpret_cast<SYMBOL_INFO*>(symBuf);
            sym->SizeOfStruct = sizeof(SYMBOL_INFO);
            sym->MaxNameLen = 159;
            MCLA_LOG_ERROR("  host stack (deepest first):");
            for (USHORT i = 0; i < nFrames && i < 14; ++i) {
                DWORD64 disp = 0;
                if (SymFromAddr(GetCurrentProcess(), reinterpret_cast<DWORD64>(frames[i]), &disp, sym)) {
                    MCLA_LOG_ERROR("   [{:2}] {} +0x{:X}", i, sym->Name, disp);
                } else {
                    MCLA_LOG_ERROR("   [{:2}] ??? 0x{:p}", i, frames[i]);
                }
            }
        }
        } // fullDump log
        spdlog::default_logger()->flush();

        // W0: park guest (and any recoverable) AVs instead of letting Windows
        // kill the thread/process via EXCEPTION_CONTINUE_SEARCH.
        // 0x7E78xxxx = PPC_LOOKUP_FUNC(guest 0) wild-pointer family.
        // Guest lr set while g_faultCtx is live = fault inside recompiled code.
        bool wildParam = false;
        if (code == 0xC0000005 && nInfo >= 2) {
            const uint32_t p1 = (uint32_t)(uintptr_t)info[1];
            if (p1 >= 0x7E000000u && p1 < 0x7F000000u)
                wildParam = true;
        }
        const uint32_t glr = g_faultCtx ? (uint32_t)g_faultCtx->lr : 0u;
        const bool guestLrSet = (g_faultCtx != nullptr) && glr != 0u && glr != 0x00FFFFFFu;
        const bool guestAv = wildParam || guestLrSet || (g_faultCtx != nullptr && code == 0xC0000005);
        const bool isBootWorker = (GetCurrentThreadId() == s_bootWorkerThreadId);
        const bool isUILoadThread = (GetCurrentThreadId() == s_uiLoadThreadId.load()) || s_inUILoad.load();

        // W36f: boot worker / UILOAD thread special handling.
        //
        // T38.3 (2026-09-20): the three recovery paths that used to live inside this block are
        // DELETED, not tuned. They were (a) float-div-0 → clear MXCSR + zero XMM0 + re-execute,
        // plus a 0xC3 (RET) code patch over sub_823D91F8's host entry and an infinite park at
        // lr=0x82133440; (b) illegal-instruction → Rip += 256MB; (c) the "known crash site"
        // lr=0x822F44E0/0x82133440 branch → set s_skipSub822FA958, patch sub_822FA958's host
        // entry with 0xC3 and Rip += 256MB. F-051 measured 0 firings across two honest soaks and
        // called them dead; build/w38e.log disproved that the moment the gate driver reached
        // UILOAD — (c) fired 616,824 times, each 256MB advance re-faulting 0x10000000 higher,
        // turning ONE guest write to 0xE0 into a 1.86M-line log. All three fabricated execution
        // (PLAN_VMX128 risk R5) and hid the real fault. A guest AV now takes the VEH-NEUTRAL
        // decline below, and then the generic park at the end of the handler.
        if (isBootWorker || isUILoadThread) {
            if (code == 0xC0000005) { // STATUS_ACCESS_VIOLATION
                if (ExceptionInfo->ContextRecord) {
                    // EXPERIMENT (session 79, user-approved): the recovery removed here
                    // advanced the host RIP by 16/64/4096 bytes and fabricated returns
                    // with RAX=0, so the guest executed control flow the PPC binary does
                    // not describe -- exactly what PLAN_VMX128 risk R5 forbids. It fired
                    // 703 times at one lr in build/smoke_long2.log. Report the real fault
                    // and decline instead, so the first divergence is observable.
                    const ULONG_PTR accessType =
                        ExceptionInfo->ExceptionRecord->ExceptionInformation[0];
                    const void* faultAddr = reinterpret_cast<const void*>(
                        ExceptionInfo->ExceptionRecord->ExceptionInformation[1]);
                    MCLA_LOG_WARN(
                        "VEH-NEUTRAL guest AV: lr={:08X} {} host addr {:p} (hostRip={:p}) "
                        "-- recovery disabled, declining",
                        glr,
                        accessType == 0 ? "read of"
                                        : (accessType == 1 ? "write to" : "exec of"),
                        faultAddr, (void*)ExceptionInfo->ContextRecord->Rip);
                    return EXCEPTION_CONTINUE_SEARCH;
                }
            }
        }

        // Park this thread forever for AVs / illegal insn / fp-div0. Never
        // return to the faulting code. Other threads (window, render,
        // workers) keep running so the process and HWND stay alive.
        // W36: also park 0xC000008E (STATUS_FLOAT_DIVIDE_BY_ZERO) which
        // the atArray allocator chain triggers when the TLS chain is broken.
        if (code == 0xC0000005 || code == 0xC000001D || code == 0xC000012A ||
            code == 0xC000008E) {
            MCLA_LOG_ERROR("VEH W0: parking thread {} code=0x{:08X} guest={} wild={} lr={:08X} "
                           "— process stays alive",
                           GetCurrentThreadId(), code, guestAv ? 1 : 0, wildParam ? 1 : 0, glr);
            spdlog::default_logger()->flush();
            for (;;)
                Sleep(1000);
        }
        return EXCEPTION_CONTINUE_SEARCH;
    });

    // Install unhandled exception filter
    LPTOP_LEVEL_EXCEPTION_FILTER prevFilter = SetUnhandledExceptionFilter(UnhandledExceptionFilter);

    bool returned = false;
    MCLA_LOG_INFO("BootWorker: calling entry point 0x{:08X}", entryGuest);
    s_bootWorkerThreadId = GetCurrentThreadId();
    spdlog::default_logger()->flush();
    entryFunc(ctx, g_base);
    returned = true;
    MCLA_LOG_INFO("BootWorker: entry point returned! r3=0x{:08X} lr=0x{:08X} r1=0x{:08X} r13=0x{:08X}",
                  ctx.r3.u32, (uint32_t)ctx.lr, ctx.r1.u32, ctx.r13.u32);
    spdlog::default_logger()->flush();

    SetUnhandledExceptionFilter(prevFilter);

    {
        std::scoped_lock lock(g_reportMutex);
        g_report.returned = returned;
    }
    g_faultCtx = nullptr;
    g_bootDone.store(true);
}

    DWORD WINAPI BootThreadProc(LPVOID param)
    {
        const uint32_t entryGuest = (uint32_t)(uintptr_t)param;
        B1ArmCurrentThreadImpl();
        BootWorker(entryGuest);
        return 0;
    }
} // namespace

    // B1 cross-TU arming entry: guest_thread.cpp calls this at every guest
    // thread's start so the watchpoints follow the workers, not just the root.
    void B1ArmGuestThread() { B1ArmCurrentThreadImpl(); }

    void B1GuardArm(uint32_t guestVa) { B1GuardArmImpl(guestVa); }

    // Publishes the context the current thread is running guest code ON, so a VEH dump
    // taken inside the scope names the faulting frame instead of the boot thread's root
    // context (F-046). Restores the previous pairing on scope exit.
    FaultContextScope::FaultContextScope(const PPCContext* ctx, const char* tag)
        : prevCtx_(g_faultCtx), prevTag_(g_faultCtxTag)
    {
        g_faultCtx = ctx;
        g_faultCtxTag = tag;
    }

    FaultContextScope::~FaultContextScope()
    {
        g_faultCtx = prevCtx_;
        g_faultCtxTag = prevTag_;
    }

bool LoadAndPrepare(const std::string& xexPath, uint32_t& entryGuest)
{
    g_moduleBase = (uintptr_t)GetModuleHandle(nullptr);
    if (!AllocateGuestMemory())
    {
        char lbuf[256];
        std::snprintf(lbuf, sizeof(lbuf), "[boot] failed to allocate %llu GiB guest window",
                      (unsigned long long)(GuestMemorySize >> 30));
        BootReportError(lbuf);
        return false;
    }

    mcla::App* app = mcla::GetApp();
    if (app == nullptr)
    {
        BootReportError("[boot] no App instance; cannot wire guest memory");
        return false;
    }
    app->GetGuestMemoryView().SetMemoryBase(g_base, GuestMemorySize);
    app->SetPPCBase(g_base);
    mcla::kernel::GuestMemoryHeap::Instance().Adopt(g_base, GuestMemorySize);
    // Function table lives at guest VA 0x8B9E0000 (g_base + IMAGE_BASE +
    // IMAGE_SIZE). Guest o1heap/XTL allocs were landing at 0x8Cxxxxxx and
    // zeroing table slots (A5CC0 → null bctrl AV). Reserve that range.
    {
        auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
        constexpr uint32_t kFTableGuest = 0x829E0000u;
        constexpr uint32_t kFTableSize = 0x800000u; // 8 MiB covers ~45k slots
        bool wasCommitted = false;
        if (!mem.AllocVirtualFixed(kFTableGuest, kFTableSize, true, false,
                                   &wasCommitted))
        {
            char lbuf[160];
            std::snprintf(lbuf, sizeof(lbuf),
                          "[boot] WARN: could not reserve func-table "
                          "0x%08X+0x%X (wasCommitted=%d)",
                          kFTableGuest, kFTableSize, (int)wasCommitted);
            BootReportInfo(lbuf);
        }
        else
        {
            BootReportInfo("[boot] reserved func-table guest 0x8B9E0000 +8MB");
        }
    }

    // TU83 spawn pointer scanner (Lead 1) — runs once after guest memory is adopted
    mcla::native::kernel::ScanGuestMemoryForTU83SpawnPointers();

    // Session 72/73: physical o1heap lives at guest 0xA0000000. The instance
    // is 576 bytes (64 bins x8 + mask + diagnostics) then fragments follow.
    // Guest stores here are the heap-corruption vector — the session-72
    // 0x200 window saw nothing, but that run never reached the load stage
    // where the corruption fires. Watch the instance + first fragments.
    mcla::native::RegisterGuestWatchRange(0xA0000000u, 0xA0000800u);

    // Session 73: attribute every 0xCDCDCDCD store. Static decode: the guest
    // fills tiny-slab elements with 0xCD on alloc (sub_821DE9D8 tail) — the
    // watch confirms the fill source and catches any OTHER fill site live.
    mcla::native::RegisterGuestWatchValue(0xCDCDCDCDu);

    // Session 73 probe: poison-param regions (see gpu_cp.cpp PARAM-STORE).
    mcla::native::RegisterGuestWatchRange(0xA0106000u, 0xA0107000u);
    mcla::native::RegisterGuestWatchRange(0xA0197E00u, 0xA0197F00u);

    // Session 76f: watch the "ui" preload-list global (0x827D7770, 32 bytes)
    // — the boot init reads it before anything fills it (BOOTPATH crash).
    mcla::native::RegisterGuestWatchRange(0x827D7770u, 0x827D7790u);

    // Session 76i: watch the device-registry header (0x82860844: array ptr
    // + count) — catch WHO registers devices and when.
    mcla::native::RegisterGuestWatchRange(0x82860844u, 0x82860850u);

    // Session 76j: entry0's device-vector fields (arr+268..276: holder ptr,
    // device count/cap) and the holder array contents themselves. The crash
    // reads holder[i] = FF00FF00 at the match call; catch the writer live.
    mcla::native::RegisterGuestWatchRange(0xA008261Cu, 0xA0082624u);
    mcla::native::RegisterGuestWatchRange(0xA0018028u, 0xA0018030u);

    // Kernel heaps must exist before any guest import allocates. Skipping this
    // left heap==physicalHeap==nullptr and the first allocation crashed inside
    // o1heapAllocate reading handle->diagnostics.capacity at instance+0x208.
    g_userHeap.Init();
    {
        const auto mainDiag = o1heapGetDiagnostics(g_userHeap.heap);
        const auto physDiag = o1heapGetDiagnostics(g_userHeap.physicalHeap);
        MCLA_LOG_INFO("[boot] kernel heaps: main capacity={} physical capacity={}",
                      mainDiag.capacity, physDiag.capacity);
    }

    std::vector<uint8_t> bytes;
    FILE* f = nullptr;
    if (fopen_s(&f, xexPath.c_str(), "rb") != 0 || f == nullptr)
    {
        char lbuf[1024];
        std::snprintf(lbuf, sizeof(lbuf), "[boot] cannot open XEX: %s", xexPath.c_str());
        BootReportError(lbuf);
        return false;
    }
    fseek(f, 0, SEEK_END);
    const long len = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (len <= 0)
    {
        fclose(f);
        char lbuf[1024];
        std::snprintf(lbuf, sizeof(lbuf), "[boot] empty XEX: %s", xexPath.c_str());
        BootReportError(lbuf);
        return false;
    }
    bytes.resize((size_t)len);
    if (fread(bytes.data(), 1, (size_t)len, f) != (size_t)len)
    {
        fclose(f);
        char lbuf[1024];
        std::snprintf(lbuf, sizeof(lbuf), "[boot] short read from %s", xexPath.c_str());
        BootReportError(lbuf);
        return false;
    }
    fclose(f);

    Image image = Xex2LoadImage(bytes.data(), bytes.size());
    if (image.data == nullptr || image.size == 0)
    {
        char lbuf[1024];
        std::snprintf(lbuf, sizeof(lbuf), "[boot] Xex2LoadImage failed for %s", xexPath.c_str());
        BootReportError(lbuf);
        return false;
    }
    {
        char lbuf[256];
        std::snprintf(lbuf, sizeof(lbuf), "[boot] image base 0x%08X size 0x%X entry 0x%08X",
                      (uint32_t)image.base, image.size, (uint32_t)image.entry_point);
        BootReportInfo(lbuf);
    }

    InstallGuestImage(image);
    // One-time cache dump of the decompressed linear image (identity map:
    // file offset = VA - 0x82000000) so IDA/Ghidra raw-byte lookups work
    // without a live boot. Skip when already present.
    {
        std::error_code ec;
        const std::filesystem::path pe = "build/cache/mcla_pe.bin";
        if (!std::filesystem::exists(pe, ec) && image.data != nullptr)
        {
            std::FILE* f = std::fopen(pe.string().c_str(), "wb");
            if (f)
            {
                const size_t n = std::fwrite(image.data.get(), 1, image.size, f);
                std::fclose(f);
                char lbuf[192];
                std::snprintf(lbuf, sizeof(lbuf),
                              "[boot] dumped %zu bytes to build/cache/mcla_pe.bin", n);
                BootReportInfo(lbuf);
            }
        }
    }
    DumpImageRegion(0x827EB900u, 32);
    mcla::trace::ScanForDispatchVtableWords((uint32_t)image.base, image.size);
    const size_t mapped = InstallFunctionTable();
    {
        char lbuf[256];
        std::snprintf(lbuf, sizeof(lbuf), "[boot] installed %zu function-table entries", mapped);
        BootReportInfo(lbuf);
    }

    SeedPreBootSlots();

    // NOTE: the old self-patching blocks here (jmp->ret on the fatal dispatcher
    // and NOP'ing a "bl" in sub_821305B8) scanned HOST x86 code as if it were
    // PPC and wrote into .text. After any relayout they false-positive and
    // corrupt live functions - the kernel-side override of sub_821BD618 in
    // imports.cpp handles the dispatcher correctly now. Do not reintroduce.

    entryGuest = (uint32_t)image.entry_point;
    return true;
}

void Start(uint32_t entryGuest)
{
    {
        std::scoped_lock lock(g_reportMutex);
        g_report = BootReport{};
        g_report.entryGuest = entryGuest;
    }
    g_bootDone.store(false);

    {
        char lbuf[256];
        std::snprintf(lbuf, sizeof(lbuf), "[boot] starting guest worker thread, entry @0x%08X", entryGuest);
        BootReportInfo(lbuf);
    }

    // Plain CreateThread proc (no std::thread/std::invoke wrapper): clang
    // 19.1.7 ICEs in the X86 assembler for the std::invoke lambda wrapper of a
    // function that contains __try/__except under /EHa. spdlog/fmt calls also
    // must not appear in the SEH TU at all (same ICE) — logging goes through
    // BootReportInfo/BootReportError in boot_log.cpp.
    // Increase worker thread stack size to 8MB to accommodate recompiled PPC functions
    constexpr size_t WorkerStackSize = 8 * 1024 * 1024; // 8MB
    const HANDLE workerHandle = CreateThread(nullptr, WorkerStackSize, BootThreadProc, (LPVOID)(uintptr_t)entryGuest, 0, nullptr);

    // Park sampler (diagnostic): periodically suspend the guest worker, log
    // its host RIP + top stack return addresses resolved to guest VAs.
    // Evidence for boot-progression blockers (ring put frozen post-init,
    // 2026-08-23). Capture-only; stops after ~60s or when boot completes.
    if (workerHandle != nullptr)
    {
        std::thread([workerHandle]() {
            {
                char lbuf[128];
                std::snprintf(lbuf, sizeof(lbuf), "PARK-SAMPLE base=%llx",
                              (unsigned long long)(uintptr_t)GetModuleHandle(nullptr));
                BootReportInfo(lbuf);
            }
            uint64_t lastRip = 0;
            // Per-PC dwell histogram over 0x10-byte host-RVA buckets
            // (session-5: sampled PCs were our own guest_memory accessors —
            // the histogram quantifies which accessor dominates).
            std::unordered_map<uint32_t, uint32_t> hist;
            uint32_t samples = 0;
            for (int i = 0; i < 120 && !g_bootDone.load(); ++i)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                CONTEXT tc;
                std::memset(&tc, 0, sizeof(tc));
                tc.ContextFlags = CONTEXT_CONTROL | CONTEXT_INTEGER;
                if (SuspendThread(workerHandle) == (DWORD)-1)
                    break;
                const bool ok = GetThreadContext(workerHandle, &tc) != 0;
                uint64_t rets[3] = {0, 0, 0};
                if (ok)
                {
                    for (size_t k = 0; k < 3; ++k)
                    {
                        const void* sp = (const void*)(tc.Rsp + 8 * (k + 1));
                        if (!IsBadReadPtr(sp, sizeof(uint64_t)))
                            rets[k] = *(const uint64_t*)sp;
                    }
                    ++samples;
                    if (g_moduleBase != 0 && tc.Rip >= g_moduleBase)
                        ++hist[uint32_t((tc.Rip - g_moduleBase) >> 4)];
                }
                ResumeThread(workerHandle);
                if (!ok || tc.Rip == lastRip)
                    continue;
                lastRip = tc.Rip;
                // Guest driver state via the pinned device chain
                // **(u32**)0x82000864 (gpu_device.cpp overrides use it), plus
                // VdSetGraphicsInterruptCallback userData object. The old
                // pollerCtx/D0 probe (0x82839254) read a DIFFERENT object —
                // retired per session-5.
                uint32_t dev = 0, slot = 0, cursor = 0, vbl = 0, flg = 0, ud = 0, ud1 = 0, ud8 = 0;
                {
                    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
                    if (mem.ReadU32BE(0x82000864, &slot) && slot != 0)
                        (void)mem.ReadU32BE(slot, &dev);
                    if (dev != 0)
                    {
                        (void)mem.ReadU32BE(dev + 0x30, &cursor);
                        (void)mem.ReadU32BE(dev + 21648, &vbl);
                        (void)mem.ReadU32BE(dev + 10942, &flg);
                    }
                    // VdSetGraphicsInterruptCallback userData: probe BOTH the
                    // uncached alias (guest-chosen 0xA0003080) and its
                    // would-be cached slot (0x80003080). System-wide A/C
                    // convergence was reverted (e9c9445: title needs >512 MB
                    // physical; identity-safe capacity insufficient), so
                    // alias resolution stays per-probe until evidence
                    // justifies more.
                    (void)mem.ReadU32BE(0xA0003080, &ud);
                    if (ud != 0)
                        (void)mem.ReadU32BE(ud, &ud1);
                    (void)mem.ReadU32BE(0x80003080, &ud8);
                }
                // Live guest state of the parked main thread: g_faultCtx points
                // at BootWorker's PPCContext while it runs guest code. Context
                // carries arg/TLS regs only (PPC_CONFIG_NON_VOLATILE_AS_LOCAL);
                // callee-saved r30/r31 + lr sit in the guest frame per the
                // generated prologue convention (stw lr,-8(r1); std
                // r30,-24(r1); std r31,-16(r1)) — read as raw slots.
                uint32_t gr3 = 0, gr4 = 0, gr13 = 0, glr = 0;
                uint32_t swM8 = 0, swM16 = 0, swM24 = 0, tls0 = 0;
                if (g_faultCtx != nullptr)
                {
                    gr3 = g_faultCtx->r3.u32;
                    gr4 = g_faultCtx->r4.u32;
                    gr13 = g_faultCtx->r13.u32; // TLS/PCR base
                    glr = (uint32_t)g_faultCtx->lr;
                    auto& mem = mcla::kernel::GuestMemoryHeap::Instance();
                    if (gr13 != 0)
                        (void)mem.ReadU32BE(gr13 + 0x0, &tls0);
                    const uint32_t sp = g_faultCtx->r1.u32;
                    if (sp != 0)
                    {
                        (void)mem.ReadU32BE(sp - 8, &swM8);   // saved lr slot
                        (void)mem.ReadU32BE(sp - 16, &swM16); // saved r31 slot
                        (void)mem.ReadU32BE(sp - 24, &swM24); // saved r30 slot
                    }
                }
                char rbuf[3][64];
                char lbuf[1024];
                std::snprintf(lbuf, sizeof(lbuf),
                              "PARK-SAMPLE rawrip=%llx nf=%s s0=%s s1=%s s2=%s dev=%08X cur=%08X vbl=%u flg=%u ud=%08X ud1=%08X ud8=%08X"
                              " | r3=%08X r4=%08X lr=%08X r13=%08X tls0=%08X [r1-8]=%08X [r1-16]=%08X [r1-24]=%08X",
                              (unsigned long long)tc.Rip,
                              NearestFunctionName(tc.Rip),
                              (std::snprintf(rbuf[0], sizeof(rbuf[0]), "%s", NearestFunctionName(rets[0])), rbuf[0]),
                              (std::snprintf(rbuf[1], sizeof(rbuf[1]), "%s", NearestFunctionName(rets[1])), rbuf[1]),
                              (std::snprintf(rbuf[2], sizeof(rbuf[2]), "%s", NearestFunctionName(rets[2])), rbuf[2]),
                              dev, cursor, vbl, flg, ud, ud1, ud8,
                              gr3, gr4, glr, gr13, tls0, swM8, swM16, swM24);
                BootReportInfo(lbuf);
            }
            {
                char lbuf[2048];
                size_t off = (size_t)std::snprintf(lbuf, sizeof(lbuf), "PARK-HIST samples=%u buckets=%zu top:", samples, hist.size());
                std::vector<std::pair<uint32_t, uint32_t>> top(hist.begin(), hist.end());
                std::sort(top.begin(), top.end(), [](auto& a, auto& b) { return a.second > b.second; });
                for (size_t k = 0; k < top.size() && k < 16 && off < sizeof(lbuf); ++k)
                {
                    const int w = std::snprintf(lbuf + off, sizeof(lbuf) - off, " %06x=%u",
                                                (unsigned)(top[k].first * 16), top[k].second);
                    if (w < 0)
                        break;
                    off += (size_t)w;
                }
                BootReportInfo(lbuf);
            }
        }).detach();
    }

    constexpr int WatchdogMs = 300000; // 5 minutes
    for (int i = 0; i < WatchdogMs && !g_bootDone.load(); i += 100)
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    if (!g_bootDone.load())
    {
        char lbuf[256];
        std::snprintf(lbuf, sizeof(lbuf), "[boot] watchdog fired after %d ms; boot still running (parked in main loop is expected)",
                      WatchdogMs);
        BootReportInfo(lbuf);
        CONTEXT tc;
        std::memset(&tc, 0, sizeof(tc));
        tc.ContextFlags = CONTEXT_CONTROL;
        if (workerHandle != nullptr && SuspendThread(workerHandle) != (DWORD)-1)
        {
            if (GetThreadContext(workerHandle, &tc))
            {
                const uintptr_t rip = (uintptr_t)tc.Rip;
                std::snprintf(lbuf, sizeof(lbuf), "[boot] worker suspended; RIP=0x%llX in %s",
                              (unsigned long long)rip, NearestFunctionName(rip));
                BootReportInfo(lbuf);
            }
            // Try to seed GPU context state field (ctx+0xd0 = 1) so Function_824E37E0 proceeds.
            const uint32_t gpuCtxPtrAddr = 0x82839254;
            const uint32_t gpuCtxPtr = ReadU32BE(g_base, gpuCtxPtrAddr);
            if (gpuCtxPtr != 0 && gpuCtxPtr < 0x90000000)
            {
                const uint32_t stateAddr = gpuCtxPtr + 0xD0;
                WriteU32BE(g_base, stateAddr, 1);
                std::snprintf(lbuf, sizeof(lbuf), "[boot] seeded GPU context state @0x%08X+0xD0 = 1", gpuCtxPtr);
                BootReportInfo(lbuf);
            }
            ResumeThread(workerHandle);
        }
    }
    else if (workerHandle != nullptr)
    {
        WaitForSingleObject(workerHandle, INFINITE);
        CloseHandle(workerHandle);
        LogReport();
    }
    else
    {
        LogReport();
    }
}

const BootReport& GetReport()
{
    return g_report;
}

uint32_t GetBootWorkerReg(unsigned regIndex)
{
    if (!g_faultCtx) return 0;
    // Only registers guaranteed to exist in PPCContext are returned
    // directly. Non-volatile registers (r14-r31) may be compiled out
    // when PPC_CONFIG_NON_VOLATILE_AS_LOCAL is set.
    switch (regIndex) {
    case 1:  return g_faultCtx->r1.u32;
    case 3:  return g_faultCtx->r3.u32;
    case 4:  return g_faultCtx->r4.u32;
    case 5:  return g_faultCtx->r5.u32;
    case 6:  return g_faultCtx->r6.u32;
    case 7:  return g_faultCtx->r7.u32;
    case 8:  return g_faultCtx->r8.u32;
    case 9:  return g_faultCtx->r9.u32;
    case 10: return g_faultCtx->r10.u32;
    case 13: return g_faultCtx->r13.u32;
    default: return 0;
    }
}

} // namespace mcla::boot