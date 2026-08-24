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

// Forward declare Xex2LoadImage from XenonRecomp (Image is defined in image.h)
Image Xex2LoadImage(const uint8_t* data, size_t dataSize);

#include <windows.h>
#include <dbghelp.h>

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
    const PPCContext* g_faultCtx = nullptr;
    uintptr_t g_moduleBase = 0;

    // Reverse map: host function entry -> guest address, for fault triage.
    std::unordered_map<uintptr_t, uint32_t> g_hostToGuest;

    void InsertFunction(uint32_t guest, PPCFunc* host)
    {
        PPC_LOOKUP_FUNC(g_base, guest) = host;
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

    void SeedPreBootSlots()
    {
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

    int FilterCapture(EXCEPTION_POINTERS* info)
    {
        {
            const uintptr_t pc = (uintptr_t)info->ContextRecord->Rip;

            void* frames[24] = {};
            const WORD n = RtlCaptureStackBackTrace(0, 24, frames, nullptr);
            g_report.faultStack.clear();
            for (WORD i = 0; i < n; i++)
            {
                const uintptr_t fa = (uintptr_t)frames[i];
                char buf[128];
                std::snprintf(buf, sizeof(buf), "0x%016zx %s", (size_t)fa, NearestFunctionName(fa));
                g_report.faultStack.emplace_back(buf);
            }

            DWORD64 imageBase = 0;
            const PRUNTIME_FUNCTION fn = RtlLookupFunctionEntry(pc, &imageBase, nullptr);
            if (fn != nullptr)
            {
                g_report.faultOwnerStart = imageBase + fn->BeginAddress;
                g_report.faultOwnerOffset = pc - g_report.faultOwnerStart;
            }
            g_report.faultInfo = NearestFunctionName(pc);
            g_report.faultHost = pc;
            g_report.faultRva = pc - g_moduleBase;
            g_report.faultCode = info->ExceptionRecord->ExceptionCode;
            g_report.faultAddr = (uintptr_t)info->ExceptionRecord->ExceptionInformation[1];
            g_report.readFault = info->ExceptionRecord->ExceptionInformation[0] == 0;

            g_report.faultRax = info->ContextRecord->Rax;
            g_report.faultRbx = info->ContextRecord->Rbx;
            g_report.faultRcx = info->ContextRecord->Rcx;
            g_report.faultRdx = info->ContextRecord->Rdx;
            g_report.faultRsi = info->ContextRecord->Rsi;
            g_report.faultRdi = info->ContextRecord->Rdi;
            g_report.faultR1 = g_faultCtx ? g_faultCtx->r1.u32 : 0;
            g_report.faultR3 = g_faultCtx ? g_faultCtx->r3.u32 : 0;
            g_report.faultR13 = g_faultCtx ? g_faultCtx->r13.u32 : 0;
            g_report.faultLR = g_faultCtx ? (uint32_t)g_faultCtx->lr : 0;
            if (g_faultCtx != nullptr)
            {
                std::memset(g_report.faultGpr, 0, sizeof(g_report.faultGpr));
                g_report.faultGpr[1] = g_faultCtx->r1.u32;
                g_report.faultGpr[3] = g_faultCtx->r3.u32;
                g_report.faultGpr[4] = g_faultCtx->r4.u32;
                g_report.faultGpr[5] = g_faultCtx->r5.u32;
                g_report.faultGpr[6] = g_faultCtx->r6.u32;
                g_report.faultGpr[7] = g_faultCtx->r7.u32;
                g_report.faultGpr[8] = g_faultCtx->r8.u32;
                g_report.faultGpr[9] = g_faultCtx->r9.u32;
                g_report.faultGpr[10] = g_faultCtx->r10.u32;
                g_report.faultGpr[13] = g_faultCtx->r13.u32;
            }

            std::memset(g_report.faultBytes, 0, sizeof(g_report.faultBytes));
            if (pc >= g_moduleBase)
                std::memcpy(g_report.faultBytes, (const void*)pc, sizeof(g_report.faultBytes));

            if (g_base != nullptr)
            {
                for (int i = 0; i < 16; i++)
                    g_report.faultTable[i] = ReadU32BE(g_base, 0x827EB900u + (uint32_t)i * 4);
            }

            if (g_report.faultR1 != 0 && g_base != nullptr)
            {
                uint32_t callerLR = 0;
                std::memcpy(&callerLR, g_base + g_report.faultR1 + 88, sizeof(callerLR));
                g_report.faultCallerLR = callerLR;
            }
        }
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

    // Capture fault info similar to the VEH handler
    const uintptr_t pc = (uintptr_t)info->ContextRecord->Rip;
    const PRUNTIME_FUNCTION fn = RtlLookupFunctionEntry(pc, nullptr, nullptr);
    if (fn != nullptr)
    {
        g_report.faultOwnerStart = (uintptr_t)fn->BeginAddress;
        g_report.faultOwnerOffset = pc - g_report.faultOwnerStart;
    }
    g_report.faultInfo = NearestFunctionName(pc);
    g_report.faultHost = pc;
    g_report.faultRva = pc - g_moduleBase;
    g_report.faultCode = info->ExceptionRecord->ExceptionCode;
    g_report.faultAddr = (uintptr_t)info->ExceptionRecord->ExceptionInformation[1];
    g_report.readFault = info->ExceptionRecord->ExceptionInformation[0] == 0;

    // Capture register state
    g_report.faultRax = info->ContextRecord->Rax;
    g_report.faultRbx = info->ContextRecord->Rbx;
    g_report.faultRcx = info->ContextRecord->Rcx;
    g_report.faultRdx = info->ContextRecord->Rdx;
    g_report.faultRsi = info->ContextRecord->Rsi;
    g_report.faultRdi = info->ContextRecord->Rdi;
    g_report.faultR1 = g_faultCtx ? g_faultCtx->r1.u32 : 0;
    g_report.faultR3 = g_faultCtx ? g_faultCtx->r3.u32 : 0;
    g_report.faultR13 = g_faultCtx ? g_faultCtx->r13.u32 : 0;
    g_report.faultLR = g_faultCtx ? (uint32_t)g_faultCtx->lr : 0;
    if (g_faultCtx != nullptr)
    {
        g_report.faultGpr[1] = g_faultCtx->r1.u32;
        g_report.faultGpr[3] = g_faultCtx->r3.u32;
        g_report.faultGpr[4] = g_faultCtx->r4.u32;
        g_report.faultGpr[5] = g_faultCtx->r5.u32;
        g_report.faultGpr[6] = g_faultCtx->r6.u32;
        g_report.faultGpr[7] = g_faultCtx->r7.u32;
        g_report.faultGpr[8] = g_faultCtx->r8.u32;
        g_report.faultGpr[9] = g_faultCtx->r9.u32;
        g_report.faultGpr[10] = g_faultCtx->r10.u32;
        g_report.faultGpr[13] = g_faultCtx->r13.u32;
    }

    // Capture fault bytes
    if (pc >= g_moduleBase)
        std::memcpy(g_report.faultBytes, (const void*)pc, sizeof(g_report.faultBytes));

    if (g_base != nullptr)
    {
        for (int i = 0; i < 16; i++)
            g_report.faultTable[i] = ReadU32BE(g_base, 0x827EB900u + (uint32_t)i * 4);
    }

    if (g_report.faultR1 != 0 && g_base != nullptr)
    {
        uint32_t callerLR = 0;
        std::memcpy(&callerLR, g_base + g_report.faultR1 + 88, sizeof(callerLR));
        g_report.faultCallerLR = callerLR;
    }

    // Store exception info for reporting
    g_report.faultInfo = NearestFunctionName(pc);

    return EXCEPTION_EXECUTE_HANDLER;
}

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

// Install vectored exception handler for early crash detection
    PVOID vehHandle = AddVectoredExceptionHandler(1, [](PEXCEPTION_POINTERS ExceptionInfo) -> LONG {
        DWORD code = ExceptionInfo->ExceptionRecord->ExceptionCode;
        PVOID addr = ExceptionInfo->ExceptionRecord->ExceptionAddress;
        DWORD flags = ExceptionInfo->ExceptionRecord->ExceptionFlags;
        ULONG_PTR* info = ExceptionInfo->ExceptionRecord->ExceptionInformation;
        DWORD nInfo = ExceptionInfo->ExceptionRecord->NumberParameters;
        const uintptr_t pc = (uintptr_t)addr;
        const uintptr_t rva = (g_moduleBase != 0 && pc >= g_moduleBase) ? pc - g_moduleBase : pc;
        MCLA_LOG_ERROR("Vectored exception: code=0x{:08X} addr=0x{:p} rva=0x{:X} flags=0x{:X} nParams={} thread={}",
                       code, addr, rva, flags, nInfo, GetCurrentThreadId());
        for (DWORD i = 0; i < nInfo; ++i) {
            MCLA_LOG_ERROR("  Param[{}]=0x{:p}", i, (PVOID)info[i]);
        }
        if (const PPCContext* fc = g_faultCtx)
        {
            MCLA_LOG_ERROR("  ppc r1={:08X} lr={:08X} r3={:08X} r4={:08X} r5={:08X} r6={:08X} "
                           "r7={:08X} r8={:08X} r9={:08X} r10={:08X} r13={:08X}",
                           fc->r1.u32, (uint32_t)fc->lr, fc->r3.u32, fc->r4.u32, fc->r5.u32,
                           fc->r6.u32, fc->r7.u32, fc->r8.u32, fc->r9.u32, fc->r10.u32, fc->r13.u32);
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
        spdlog::default_logger()->flush();
        return EXCEPTION_CONTINUE_SEARCH;
    });

    // Install unhandled exception filter
    LPTOP_LEVEL_EXCEPTION_FILTER prevFilter = SetUnhandledExceptionFilter(UnhandledExceptionFilter);

    bool returned = false;
    MCLA_LOG_INFO("BootWorker: calling entry point 0x{:08X}", entryGuest);
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
        BootWorker(entryGuest);
        return 0;
    }
} // namespace

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
    DumpImageRegion(0x827EB900u, 32);
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

} // namespace mcla::boot