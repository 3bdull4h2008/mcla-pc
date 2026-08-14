#include "xenon_smoke.h"

#include <windows.h>
#include <psapi.h>

#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstring>
#include <mutex>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

#include "image.h"
#include "xex.h"

uint8_t* g_base = nullptr;

// The MSVC CRT does not provide C23 roundevenf (referenced by simde's math
// fallback inside the recompiled TUs). Provide a host implementation.
extern "C" __declspec(noinline) float roundevenf(float value)
{
    return value >= 0.0f ? float((int)(value + 0.5f)) : float((int)(value - 0.5f));
}

// ---------------------------------------------------------------------------
// Kernel import stubs
// ---------------------------------------------------------------------------

namespace
{
    std::mutex stubMutex;
    BootReport* g_report = nullptr;
} // namespace

void s_StubCalled(const char* name)
{
    std::scoped_lock lock(stubMutex);
    if (g_report != nullptr)
    {
        for (const auto& seen : g_report->stubOrder)
        {
            if (seen == name)
                return;
        }
        g_report->stubOrder.emplace_back(name);
        g_report->distinctStubCache++;
    }
}

// ---------------------------------------------------------------------------
// Function table
// ---------------------------------------------------------------------------

static void InsertFunction(uint32_t guest, PPCFunc* host)
{
    PPC_LOOKUP_FUNC(g_base, guest) = host;
}

namespace
{
    // Reverse map: host function entry -> guest address, for fault triage.
    std::unordered_map<uintptr_t, uint32_t> g_hostToGuest;
} // namespace

const char* NearestFunctionName(uint64_t hostAddr)
{
    static thread_local char buf[128];
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

    // Fallback: the PC may sit in a merged/leaf-thunk region with no unwind
    // entry of its own (identical-code folding splits chunks). Scan the full
    // mapping table for the function whose host start is the closest one <= PC.
    const PPCFunc* closest = nullptr;
    for (size_t i = 0; PPCFuncMappings[i].host != nullptr; i++)
    {
        const PPCFunc* h = PPCFuncMappings[i].host;
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

// ---------------------------------------------------------------------------
// Guest memory + XEX image
// ---------------------------------------------------------------------------

namespace
{
    constexpr size_t GuestMemorySize = 0x100000000ull; // 4 GiB, matches PPC_MEMORY_SIZE
    constexpr uintptr_t GuestMemoryBase = 0x100000000ull;

    bool AllocateGuestMemory()
    {
        g_base = (uint8_t*)VirtualAlloc((void*)GuestMemoryBase, GuestMemorySize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
        if (g_base == nullptr)
        {
            // Fallback: any 32-byte-aligned region works (recomp code requires base % 0x20 == 0).
            g_base = (uint8_t*)VirtualAlloc(nullptr, GuestMemorySize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
        }
        return g_base != nullptr;
    }

    void InstallGuestImage(const Image& image)
    {
        std::memcpy(g_base + image.base, image.data.get(), image.size);
        std::printf("[smoke] image base 0x%08zx size 0x%zx entry 0x%08x\n",
                    image.base, image.size, (uint32_t)image.entry_point);
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

    void SetupInitialContext(PPCContext& ctx)
    {
        std::memset(&ctx, 0, sizeof(ctx));

        // Seed the FPSCR cache from the real host MXCSR. The recompiled code
        // only toggles rounding + flush bits via ctx.fpscr; if the cache starts
        // at zero, the first enableFlushMode() writes MXCSR = 0x8040, clearing
        // the exception-mask bits (0x1F80) and unmasking host FPU exceptions
        // (0xC000008F STATUS_FLOAT_MULTIPLE_FAULTS) in float-heavy guest code.
        ctx.fpscr.csr = ctx.fpscr.getcsr();

        // 2 MiB guest stack, clear of the image (image ends around 0x829E0000).
        constexpr uint32_t StackTop = 0x8F000000u;
        constexpr uint32_t StackSize = 0x200000u;
        std::memset(g_base + StackTop - StackSize, 0, StackSize);

        ctx.r1.u32 = StackTop; // r1 = stack pointer (grows down)
        ctx.msr = 0x200A000;   // FP/VMX bits, matches PPCContext default

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
        // This mirrors the UnleashedRecomp thread-block layout (guest_thread.cpp).
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

        InsertFunction(AllocFnGuest, __xtl_alloc);
        InsertFunction(FreeFnGuest, __xtl_free);

        std::printf("[smoke] r13 thread block @0x%08x, XTL alloc->0x%08x free->0x%08x\n",
                    ThreadBlock, AllocFnGuest, FreeFnGuest);
    }
} // namespace

// ---------------------------------------------------------------------------
// Boot with watchdog
// ---------------------------------------------------------------------------

namespace
{
    // Exception filter: capture fault PC (host) + owning guest function.
    BootReport* g_bootReport = nullptr;
    const PPCContext* g_faultCtx = nullptr;
    uintptr_t g_moduleBase = 0;

    int FilterCapture(EXCEPTION_POINTERS* info)
    {
        if (g_bootReport != nullptr)
        {
            const uintptr_t pc = (uintptr_t)info->ContextRecord->Rip;
            // Host stack backtrace of the faulting thread: each recompiled
            // function is a real host frame, so the return addresses resolve
            // through RtlLookupFunctionEntry + g_hostToGuest into guest code.
            // This is far more reliable than the unwind+g_hostToGuest of the
            // raw RIP (identical-code folding can misattribute the RIP owner).
            void* frames[24] = {};
            const WORD n = RtlCaptureStackBackTrace(0, 24, frames, nullptr);
            g_bootReport->faultStack.clear();
            for (WORD i = 0; i < n; i++)
            {
                const uintptr_t fa = (uintptr_t)frames[i];
                const char* name = NearestFunctionName(fa);
                char buf[128];
                std::snprintf(buf, sizeof(buf), "0x%016zx %s", (size_t)fa, name);
                g_bootReport->faultStack.emplace_back(buf);
            }
            // The host offset within the owning compiled function. For a
            // recompiled function the unwind chunk is whole-function, so this
            // tells us which guest instruction faulted instead of relying on
            // stack-frame heuristics.
            DWORD64 imageBase = 0;
            const PRUNTIME_FUNCTION fn = RtlLookupFunctionEntry(pc, &imageBase, nullptr);
            if (fn != nullptr)
            {
                g_bootReport->faultOwnerStart = imageBase + fn->BeginAddress;
                g_bootReport->faultOwnerOffset = pc - g_bootReport->faultOwnerStart;
            }
            g_bootReport->faultInfo = NearestFunctionName(pc);
            g_bootReport->faultHost = pc;
            g_bootReport->faultRva = pc - g_moduleBase;
            g_bootReport->faultCode = info->ExceptionRecord->ExceptionCode;
            g_bootReport->faultAddr = (uintptr_t)info->ExceptionRecord->ExceptionInformation[1];
            g_bootReport->readFault = info->ExceptionRecord->ExceptionInformation[0] == 0;
            // Host register values at the faulting instruction. For the
            // generated load/store helpers these are: Rdx = guest base,
            // Rcx/R8-R11 = guest offset(s) into base. Rbx often carries the
            // walking pointer in list-traversal code (e.g. sub_82133438).
            g_bootReport->faultRax = info->ContextRecord->Rax;
            g_bootReport->faultRbx = info->ContextRecord->Rbx;
            g_bootReport->faultRcx = info->ContextRecord->Rcx;
            g_bootReport->faultRdx = info->ContextRecord->Rdx;
            g_bootReport->faultRsi = info->ContextRecord->Rsi;
            g_bootReport->faultRdi = info->ContextRecord->Rdi;
            g_bootReport->faultR1 = g_faultCtx ? g_faultCtx->r1.u32 : 0;
            g_bootReport->faultR3 = g_faultCtx ? g_faultCtx->r3.u32 : 0;
            g_bootReport->faultR13 = g_faultCtx ? g_faultCtx->r13.u32 : 0;
            g_bootReport->faultLR = g_faultCtx ? (uint32_t)g_faultCtx->lr : 0;
            if (g_faultCtx != nullptr)
            {
                // PPCContext is compiled with PPC_CONFIG_NON_ARGUMENT_AS_LOCAL
                // and PPC_CONFIG_NON_VOLATILE_AS_LOCAL, so only r1, r3..r10 and
                // r13 are host-visible; the rest are locals of the generated
                // functions and cannot be recovered from the guest context.
                std::memset(g_bootReport->faultGpr, 0, sizeof(g_bootReport->faultGpr));
                g_bootReport->faultGpr[1] = g_faultCtx->r1.u32;
                g_bootReport->faultGpr[3] = g_faultCtx->r3.u32;
                g_bootReport->faultGpr[4] = g_faultCtx->r4.u32;
                g_bootReport->faultGpr[5] = g_faultCtx->r5.u32;
                g_bootReport->faultGpr[6] = g_faultCtx->r6.u32;
                g_bootReport->faultGpr[7] = g_faultCtx->r7.u32;
                g_bootReport->faultGpr[8] = g_faultCtx->r8.u32;
                g_bootReport->faultGpr[9] = g_faultCtx->r9.u32;
                g_bootReport->faultGpr[10] = g_faultCtx->r10.u32;
                g_bootReport->faultGpr[13] = g_faultCtx->r13.u32;
            }
            std::memset(g_bootReport->faultBytes, 0, sizeof(g_bootReport->faultBytes));
            if (pc >= g_moduleBase)
                std::memcpy(g_bootReport->faultBytes, (const void*)pc, sizeof(g_bootReport->faultBytes));
            // The faulting function (sub_821BD618) saved its caller's LR at
            // [r1]+88 when it grew its stack frame (stw r12,-8(r1); stwu r1,-96).
            // Walking one frame tells us who actually called through the slot.
            if (g_bootReport->faultR1 != 0 && g_base != nullptr)
            {
                uint32_t callerLR = 0;
                std::memcpy(&callerLR, g_base + g_bootReport->faultR1 + 88, sizeof(callerLR));
                g_bootReport->faultCallerLR = callerLR;
            }
        }
        return EXCEPTION_EXECUTE_HANDLER;
    }

    std::atomic<bool> g_bootDone{false};

    // --- trampoline tracer -------------------------------------------------
    // Wrap guest function entries reached via PPC_CALL_INDIRECT_FUNC with a
    // logging wrapper: records the guest return address (ctx.lr at entry) and
    // optional slot contents, then delegates. Each (guest, slot) combination
    // gets its own wrapper instance via template, appending to a shared log.
    std::vector<std::string> g_traceLog;

    template<uint32_t Guest, uint32_t SlotAddr>
    struct TraceHolder
    {
        static PPCFunc* original;
    };
    template<uint32_t Guest, uint32_t SlotAddr>
    PPCFunc* TraceHolder<Guest, SlotAddr>::original = nullptr;

    template<uint32_t Guest, uint32_t SlotAddr>
    static void TraceWrapper(struct PPCContext& ctx, uint8_t* base)
    {
        char buf[192];
        if (SlotAddr != 0)
            std::snprintf(buf, sizeof(buf), "tramp 0x%08x entered from guest 0x%08x (slot@0x%08x = 0x%08x)",
                          Guest, (uint32_t)ctx.lr, SlotAddr,
                          (unsigned)(*(uint32_t*)(g_base + SlotAddr)));
        else
            std::snprintf(buf, sizeof(buf), "tramp 0x%08x entered from guest 0x%08x",
                          Guest, (uint32_t)ctx.lr);
        {
            std::scoped_lock lock(stubMutex);
            if (g_traceLog.size() < 64)
                g_traceLog.push_back(buf);
        }
        TraceHolder<Guest, SlotAddr>::original(ctx, base);
    }

    template<uint32_t Guest, uint32_t SlotAddr>
    void PatchTrampolineTrace()
    {
        PPCFunc* original = PPC_LOOKUP_FUNC(g_base, Guest);
        if (original == nullptr)
            return;
        TraceHolder<Guest, SlotAddr>::original = original;
        PPC_LOOKUP_FUNC(g_base, Guest) = TraceWrapper<Guest, SlotAddr>;
    }

    // Entry probe for sub_82133438 (buffer-pool allocator). The large-bucket
    // free-list walk faults on an uninitialized list head, so capture the pool
    // object (r3), request descriptor (r4) and size (r5) plus the free-list
    // head at pool+384 and the allocation cursor at pool+48 on every call.
    static PPCFunc* g_poolAllocOriginal = nullptr;
    static void PoolAllocProbe(struct PPCContext& ctx, uint8_t* base)
    {
        char buf[256];
        uint32_t head = 0, cursor = 0, field44 = 0;
        if (ctx.r3.u32 < GuestMemorySize)
        {
            std::memcpy(&head, base + ctx.r3.u32 + 384, 4);
            head = __builtin_bswap32(head);
            std::memcpy(&cursor, base + ctx.r3.u32 + 48, 4);
            cursor = __builtin_bswap32(cursor);
            std::memcpy(&field44, base + ctx.r3.u32 + 44, 4);
            field44 = __builtin_bswap32(field44);
        }
        std::snprintf(buf, sizeof(buf),
                      "poolalloc pool=0x%08x desc=0x%08x size=0x%x head=0x%08x cursor=0x%08x f44=0x%08x from=0x%08x",
                      ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, head, cursor, field44, (uint32_t)ctx.lr);
        {
            std::scoped_lock lock(stubMutex);
            if (g_traceLog.size() < 256)
                g_traceLog.push_back(buf);
        }
        g_poolAllocOriginal(ctx, base);
    }

    void BootWorker(BootReport& report, uint32_t entryGuest)
    {
        PPCFunc* entryFunc = PPC_LOOKUP_FUNC(g_base, entryGuest);
        if (entryFunc == nullptr)
        {
            report.faultInfo = "entry point not present in function table";
            g_bootDone.store(true);
            return;
        }

        PPCContext ctx;
        SetupInitialContext(ctx);
        ctx.lr = 0x00FFFFFF; // if the function blr's, we can detect the return site below

        g_faultCtx = &ctx;

        std::printf("[smoke] booting guest function @0x%08x\n", entryGuest);
        __try
        {
            entryFunc(ctx, g_base);
            report.returned = true;
        }
        __except (FilterCapture(GetExceptionInformation()))
        {
        }
        g_faultCtx = nullptr;
        g_bootDone.store(true);
    }
} // namespace

void RunBoot(BootReport& report, uint32_t entryGuest, bool traceTramps)
{
    report.entryGuest = entryGuest;
    g_bootReport = &report;
    g_report = &report;
    g_bootDone.store(false);
    {
        std::scoped_lock lock(stubMutex);
        g_traceLog.clear();
    }

    // Pre-boot static initialization pass for slot 0x8285FEA0 and table pointer 0x8288E5AC.
    constexpr uint32_t SlotAddr = 0x8285FEA0;
    constexpr uint32_t Landing = 0x82130678;
    const PPCFunc* landingEntry = PPC_LOOKUP_FUNC(g_base, Landing);
    std::printf("[smoke] pre-boot PPC_LOOKUP_FUNC(0x%08x) = %p%s\n",
                Landing, (void*)landingEntry,
                landingEntry == nullptr ? " <-- NULL ENTRY" : " (installed)");
    uint32_t slotValue = 0;
    std::memcpy(&slotValue, g_base + SlotAddr, sizeof(slotValue));
    const uint32_t slotBE = __builtin_bswap32(slotValue);
    std::printf("[smoke] pre-boot slot @0x%08x = 0x%08x\n", SlotAddr, slotBE);
    if (slotBE == 0)
    {
        const uint32_t landingBE = __builtin_bswap32(Landing);
        std::memcpy(g_base + SlotAddr, &landingBE, sizeof(landingBE));
        std::printf("[smoke] pre-boot init: slot @0x%08x populated with 0x%08x\n", SlotAddr, Landing);
    }
    else
    {
        std::printf("[smoke] pre-boot init: slot already populated; skipping\n");
    }

    // Pre-initialize global table pointer at 0x8288E5AC read by sub_82388598.
    // Point it to a valid guest scratch table region (e.g. 0x8F207000) so the load succeeds.
    constexpr uint32_t TablePtrAddr = 0x8288E5AC;
    constexpr uint32_t ScratchTable = 0x8F207000;
    uint32_t tablePtrVal = 0;
    std::memcpy(&tablePtrVal, g_base + TablePtrAddr, sizeof(tablePtrVal));
    if (__builtin_bswap32(tablePtrVal) == 0)
    {
        const uint32_t scratchBE = __builtin_bswap32(ScratchTable);
        std::memcpy(g_base + TablePtrAddr, &scratchBE, sizeof(scratchBE));
        std::printf("[smoke] pre-boot init: table ptr @0x%08x populated with scratch table 0x%08x\n", TablePtrAddr, ScratchTable);
    }

    // Arm the trampoline tracer (if requested) before the worker starts:
    // sub_821305B8 is the indirect-called trampoline that calls sub_821BD618;
    // sub_82131790 is the slot writer (0x82130678 -> 0x8285FEA0).
    if (traceTramps)
    {
        PatchTrampolineTrace<0x821305B8, 0x8285FEA0>();
        PatchTrampolineTrace<0x82131790, 0>();
    }

    // Always probe the buffer-pool allocator while diagnosing its uninitialized
    // large-bucket free-list (the current boot fault).
    {
        PPCFunc* original = PPC_LOOKUP_FUNC(g_base, 0x82133438);
        if (original != nullptr)
        {
            g_poolAllocOriginal = original;
            PPC_LOOKUP_FUNC(g_base, 0x82133438) = PoolAllocProbe;
            std::printf("[smoke] pool-alloc probe armed for 0x82133438\n");
        }
    }

    // Dump a marker so determinism is measurable across runs.
    std::printf("[smoke] ---- boot ----\n");
    std::thread worker([&]() { BootWorker(report, entryGuest); });
    const HANDLE workerHandle = worker.native_handle();

    // Wait up to the watchdog budget, checking completion (a plain join()
    // cannot time out, and joinable() is true even after the function ends).
    constexpr int WatchdogMs = 8000;
    for (int i = 0; i < WatchdogMs && !g_bootDone.load(); i += 100)
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    if (!g_bootDone.load())
    {
        std::printf("[smoke] watchdog fired after %d ms; boot still running\n", WatchdogMs);
        // Sample the worker's host RIP and map it back to a guest function so a
        // hang in recompiled code can be located without a fault.
        CONTEXT tc;
        std::memset(&tc, 0, sizeof(tc));
        tc.ContextFlags = CONTEXT_CONTROL;
        if (workerHandle != nullptr && SuspendThread(workerHandle) != (DWORD)-1)
        {
            if (GetThreadContext(workerHandle, &tc))
            {
                const uintptr_t rip = (uintptr_t)tc.Rip;
                const char* where = NearestFunctionName(rip);
                std::printf("[smoke] worker suspended; RIP=0x%llx in %s\n",
                            (unsigned long long)rip, where);
            }
            ResumeThread(workerHandle);
        }
        worker.detach();
    }
    else
    {
        worker.join();
    }

    {
        std::scoped_lock lock(stubMutex);
        report.traceLog = g_traceLog;
    }
}

int main(int argc, char** argv)
{
    std::setvbuf(stdout, nullptr, _IONBF, 0);
    g_moduleBase = reinterpret_cast<uintptr_t>(GetModuleHandleW(nullptr));
    const char* xexPath = "build/game_data/default.xex";
    const char* funcArg = nullptr;
    bool dumpImports = false;
    bool dumpImage = false;
    bool dumpPointers = false;
    bool traceTramps = false;
    const char* hexdumpArg = nullptr;

    for (int i = 1; i < argc; i++)
    {
        if (std::strncmp(argv[i], "--function=", 11) == 0)
            funcArg = argv[i] + 11;
        else if (std::strncmp(argv[i], "--xex=", 6) == 0)
            xexPath = argv[i] + 6;
        else if (std::strcmp(argv[i], "--dump-imports") == 0)
            dumpImports = true;
        else if (std::strcmp(argv[i], "--dump-image") == 0)
            dumpImage = true;
        else if (std::strcmp(argv[i], "--dump-pointers") == 0)
            dumpPointers = true;
        else if (std::strcmp(argv[i], "--trace-tramps") == 0)
            traceTramps = true;
        else if (std::strncmp(argv[i], "--hexdump=", 10) == 0)
            hexdumpArg = argv[i] + 10;
        else
            xexPath = argv[i];
    }

    // -------------------------------------------------------------------
    // Image inspection: decompress the XEX once, then report section layout
    // and every big-endian 4-byte word matching the requested guest address.
    // -------------------------------------------------------------------
    std::vector<uint8_t> imageBytes;
    Image loadedImage;
    if (dumpImage || dumpPointers || hexdumpArg != nullptr)
    {
        std::FILE* f = std::fopen(xexPath, "rb");
        if (f == nullptr)
        {
            std::fprintf(stderr, "[smoke] cannot open %s\n", xexPath);
            return 1;
        }
        std::fseek(f, 0, SEEK_END);
        const long len = std::ftell(f);
        std::fseek(f, 0, SEEK_SET);
        imageBytes.resize((size_t)len);
        const size_t got = std::fread(imageBytes.data(), 1, (size_t)len, f);
        std::fclose(f);
        if (got != (size_t)len)
            return 1;

        loadedImage = Xex2LoadImage(imageBytes.data(), imageBytes.size());
        if (loadedImage.data == nullptr)
        {
            std::fprintf(stderr, "[smoke] Xex2LoadImage failed\n");
            return 1;
        }

        if (dumpImage)
        {
            std::printf("[smoke] image base 0x%08zx size 0x%zx entry 0x%08x\n",
                        loadedImage.base, loadedImage.size, (uint32_t)loadedImage.entry_point);
            std::printf("[smoke] sections:\n");
            for (const auto& sec : loadedImage.sections)
            {
                std::printf("  %-12s base 0x%08zx size 0x%06x flags %s\n",
                            sec.name.c_str(), sec.base, sec.size,
                            sec.flags & SectionFlags_Code ? "code" : (sec.flags & SectionFlags_Data ? "data" : "raw"));
            }
        }

        if (dumpPointers)
        {
            const uint32_t targets[] = { 0x821305B8u, 0x821BD618u, 0x821BD7C0u, 0x82131790u, 0x82130678u, 0x821322B8u, 0x821BD648u, 0x821D5F68u, 0x821C06F0u, 0x82130000u, 0x821C45D8u, 0x821C4C10u, 0x821D5F70u };
            for (uint32_t t : targets)
            {
                uint32_t matches = 0;
                std::printf("[smoke] pointers to 0x%08x:\n", t);
                const size_t size = loadedImage.size;
                const uint8_t* d = loadedImage.data.get();
                for (size_t off = 0; off + 4 <= size; off += 4)
                {
                    const uint32_t be = ((uint32_t)d[off] << 24) | ((uint32_t)d[off + 1] << 16) | ((uint32_t)d[off + 2] << 8) | d[off + 3];
                    if (be == t)
                    {
                        std::printf("    +0x%06zx (guest 0x%08zx)\n", off, loadedImage.base + off);
                        if (++matches >= 12)
                        {
                            std::printf("    ...\n");
                            break;
                        }
                    }
                }
                if (matches == 0)
                    std::printf("    (none)\n");
            }
        }

        if (hexdumpArg != nullptr)
        {
            // --hexdump=<guestVA>,<words> : dump BE words of the decompressed image.
            uint32_t va = 0;
            uint32_t words = 64;
            if (std::sscanf(hexdumpArg, "%x,%x", &va, &words) >= 1)
            {
                const size_t start = va - (size_t)loadedImage.base;
                for (uint32_t w = 0; w < words && start + w * 4 + 4 <= loadedImage.size; w++)
                {
                    const uint8_t* p = loadedImage.data.get() + start + w * 4;
                    const uint32_t be = ((uint32_t)p[0] << 24) | ((uint32_t)p[1] << 16) | ((uint32_t)p[2] << 8) | p[3];
                    std::printf("  0x%08zx  %08x\n", loadedImage.base + start + w * 4, be);
                }
            }
        }
        return 0;
    }

    if (dumpImports)
    {
        std::FILE* f = std::fopen(xexPath, "rb");
        if (f == nullptr)
        {
            std::fprintf(stderr, "[smoke] cannot open %s\n", xexPath);
            return 1;
        }
        std::fseek(f, 0, SEEK_END);
        const long len = std::ftell(f);
        std::fseek(f, 0, SEEK_SET);
        std::vector<uint8_t> xexData((size_t)len);
        const size_t got = std::fread(xexData.data(), 1, (size_t)len, f);
        std::fclose(f);
        if (got != (size_t)len)
            return 1;

        Image image = Xex2LoadImage(xexData.data(), xexData.size());
        if (image.data == nullptr)
        {
            std::fprintf(stderr, "[smoke] Xex2LoadImage failed\n");
            return 1;
        }

        // Imports parsed by Xex2LoadImage land in image.symbols as
        // { export-name, firstThunk VA }. Dump them all.
        std::printf("[smoke] import symbols parsed: %zu\n", image.symbols.size());
        for (const auto& s : image.symbols)
        {
            std::printf("  0x%08zx  %s\n", s.address, s.name.c_str());
        }

        // Also walk the raw import descriptor tables to list every firstThunk
        // slot (patched or not) so we can see un-named / un-patched slots.
        const auto* imports =
            reinterpret_cast<const Xex2ImportHeader*>(getOptHeaderPtr(xexData.data(), XEX_HEADER_IMPORT_LIBRARIES));
        if (imports != nullptr)
        {
            const char* pStrTable = reinterpret_cast<const char*>(imports + 1);
            std::vector<std::string_view> libNames;
            size_t padded = 0;
            for (size_t i = 0; i < imports->numImports; i++)
            {
                libNames.emplace_back(pStrTable + padded);
                padded += ((libNames.back().length() + 1) + 3) & ~3;
            }
            auto* library = (Xex2ImportLibrary*)(((char*)imports) + sizeof(Xex2ImportHeader) + imports->sizeOfStringTable);
            for (size_t i = 0; i < libNames.size(); i++)
            {
                auto* descriptors = (Xex2ImportDescriptor*)(library + 1);
                std::printf("[smoke] library %s: %u imports\n", std::string(libNames[i]).c_str(), (unsigned)library->numberOfImports);
                for (size_t im = 0; im < library->numberOfImports; im++)
                {
                    const uint32_t va = (uint32_t)descriptors[im].firstThunk;
                    const void* t = image.Find(va);
                    uint32_t raw = 0;
                    if (t != nullptr)
                        std::memcpy(&raw, t, sizeof(raw));
                    const uint32_t thunkData = ByteSwap(raw);
                    std::printf("    slot 0x%08x  thunkData 0x%08x\n", va, thunkData);
                }
                library = (Xex2ImportLibrary*)((char*)(library + 1) + library->numberOfImports * sizeof(Xex2ImportDescriptor));
            }
        }
        return 0;
    }

    if (funcArg != nullptr)
    {
        // Direct function call (no XEX boot): proves a TU executes and returns.
        if (!AllocateGuestMemory())
        {
            std::fprintf(stderr, "[smoke] VirtualAlloc(4 GiB) failed\n");
            return 1;
        }
        std::printf("[smoke] guest memory base 0x%llx\n", (unsigned long long)(uintptr_t)g_base);

        const size_t mapped = InstallFunctionTable();
        std::printf("[smoke] PPCFuncMappings installed: %zu functions\n", mapped);

        const uint32_t guest = (uint32_t)std::strtoul(funcArg, nullptr, 0);
        BootReport report;
        RunBoot(report, guest, traceTramps);
        std::printf("[smoke] direct call outcome:\n");
        std::printf("  target     : 0x%08x\n", guest);
        std::printf("  returned   : %s\n", report.returned ? "yes" : "no");
        std::printf("  kernel imports hit: %zu distinct\n", report.stubOrder.size());
        if (!report.traceLog.empty())
        {
            for (const auto& l : report.traceLog)
                std::printf("  %s\n", l.c_str());
        }
        if (!report.faultInfo.empty())
            std::printf("  fault      : guest function %s\n", report.faultInfo.c_str());
        return report.returned ? 0 : 2;
    }

    std::FILE* f = std::fopen(xexPath, "rb");
    if (f == nullptr)
    {
        std::fprintf(stderr, "[smoke] cannot open %s\n", xexPath);
        return 1;
    }
    std::fseek(f, 0, SEEK_END);
    const long len = std::ftell(f);
    std::fseek(f, 0, SEEK_SET);
    std::vector<uint8_t> xexData((size_t)len);
    const size_t got = std::fread(xexData.data(), 1, (size_t)len, f);
    std::fclose(f);
    if (got != (size_t)len)
    {
        std::fprintf(stderr, "[smoke] short read\n");
        return 1;
    }

    Image image = Xex2LoadImage(xexData.data(), xexData.size());
    if (image.data == nullptr)
    {
        std::fprintf(stderr, "[smoke] Xex2LoadImage failed\n");
        return 1;
    }

    if (!AllocateGuestMemory())
    {
        std::fprintf(stderr, "[smoke] VirtualAlloc(4 GiB) failed\n");
        return 1;
    }
    std::printf("[smoke] guest memory base 0x%llx\n", (unsigned long long)(uintptr_t)g_base);

    InstallGuestImage(image);

    const size_t mapped = InstallFunctionTable();
    std::printf("[smoke] PPCFuncMappings installed: %zu functions\n", mapped);

    BootReport report;
    RunBoot(report, (uint32_t)image.entry_point, traceTramps);

    std::printf("[smoke] boot outcome:\n");
    std::printf("  entry        : 0x%08x\n", report.entryGuest);
    std::printf("  returned     : %s\n", report.returned ? "yes" : "no");
    std::printf("  kernel imports hit: %llu distinct\n", (unsigned long long)report.distinctStubCache);
    if (!report.traceLog.empty())
    {
        std::printf("  trampoline trace:\n");
        for (const auto& l : report.traceLog)
            std::printf("    %s\n", l.c_str());
    }
    if (!report.stubOrder.empty())
    {
        std::printf("  stub order (first-seen):\n");
        for (size_t i = 0; i < report.stubOrder.size() && i < 40; i++)
            std::printf("    %s\n", report.stubOrder[i].c_str());
        if (report.stubOrder.size() > 40)
            std::printf("    ... and %zu more\n", report.stubOrder.size() - 40);
    }
    {
        // Default game heap global (sub_82135D28 reads it from 0x8294A5A0).
        // Printed on every outcome so a watchdog hang still verifies the
        // NtAllocateVirtualMemory stubs created the boot heap.
        uint32_t heap = 0;
        if (0x8294A5A0u + 4 <= GuestMemorySize)
        {
            std::memcpy(&heap, g_base + 0x8294A5A0u, 4);
            heap = __builtin_bswap32(heap);
        }
        std::printf("  heap global  : [0x8294A5A0]=0x%08x\n", heap);
    }
    if (!report.faultInfo.empty())
    {
        std::printf("  fault        : guest function %s\n", report.faultInfo.c_str());
        std::printf("  fault host PC: 0x%llx", (unsigned long long)report.faultHost);
        if (report.faultOwnerStart != 0)
            std::printf(" (+0x%llx in owner 0x%llx, RVA 0x%llx)",
                        (unsigned long long)report.faultOwnerOffset, (unsigned long long)report.faultOwnerStart,
                        (unsigned long long)report.faultRva);
        std::printf("\n");
        std::printf("  fault regs   : r1=0x%08x r3=0x%08x r13=0x%08x lr=0x%08x\n",
                    report.faultR1, report.faultR3, report.faultR13, report.faultLR);
        if (report.faultRdx != 0 || report.faultRcx != 0 || report.faultRbx != 0)
            std::printf("  host regs    : rax=0x%llx rbx=0x%llx rcx=0x%llx rdx=0x%llx rsi=0x%llx rdi=0x%llx\n",
                        (unsigned long long)report.faultRax, (unsigned long long)report.faultRbx,
                        (unsigned long long)report.faultRcx, (unsigned long long)report.faultRdx,
                        (unsigned long long)report.faultRsi, (unsigned long long)report.faultRdi);
        if (report.faultGpr[4] != 0 || report.faultGpr[5] != 0 || report.faultGpr[11] != 0 ||
            report.faultGpr[28] != 0 || report.faultGpr[29] != 0 || report.faultGpr[30] != 0 ||
            report.faultGpr[31] != 0)
        {
            std::printf("  gpr         : r4=0x%08x r5=0x%08x r6=0x%08x r7=0x%08x r8=0x%08x r9=0x%08x r10=0x%08x\n",
                        report.faultGpr[4], report.faultGpr[5], report.faultGpr[6], report.faultGpr[7],
                        report.faultGpr[8], report.faultGpr[9], report.faultGpr[10]);
            std::printf("  gpr         : r11=0x%08x r12=0x%08x r14=0x%08x r28=0x%08x r29=0x%08x r30=0x%08x r31=0x%08x\n",
                        report.faultGpr[11], report.faultGpr[12], report.faultGpr[14], report.faultGpr[28],
                        report.faultGpr[29], report.faultGpr[30], report.faultGpr[31]);
        }
        {
            // Runtime probes: file-system singletons + device table + chunk-cache flag.
            const uint32_t probes[] = {
                0x827D8388u, 0x827D838Cu, 0x827D8390u, 0x827D8394u,
                0x82860844u, 0x82860848u, 0x82855E0Cu, 0x828748B0u,
                0x8294A5A0u, // default game heap pointer (sub_82135D28: lis -32107 = 0x82950000)
            };
            std::printf("  probes       :");
            for (uint32_t va : probes)
            {
                if (va < GuestMemorySize)
                {
                    uint32_t w = 0;
                    std::memcpy(&w, g_base + va, 4);
                    w = __builtin_bswap32(w);
                    std::printf(" [0x%08x]=0x%08x", va, w);
                }
            }
            std::printf("\n");
            for (uint32_t va : probes)
            {
                if (va < GuestMemorySize)
                {
                    uint32_t w = 0;
                    std::memcpy(&w, g_base + va, 4);
                    w = __builtin_bswap32(w);
                    if (w >= 0x82000000u && w < 0x83000000u && GuestFunctionName(w)[0] == 's')
                    {
                        std::printf("  vtable?      : [0x%08x]=0x%08x is %s\n", va, w, GuestFunctionName(w));
                        for (int s = 0; s < 8; s++)
                        {
                            uint32_t slot = 0;
                            if (w + 4u * (uint32_t)s < GuestMemorySize)
                            {
                                std::memcpy(&slot, g_base + w + 4u * (uint32_t)s, 4);
                                slot = __builtin_bswap32(slot);
                                std::printf("    [v+%d] = 0x%08x (%s)\n", s * 4, slot, GuestFunctionName(slot));
                            }
                        }
                    }
                }
            }
            {
                // Default game heap (sub_82135D28 reads it from 0x8294A5A0).
                // Dump the fields the allocators (sub_82133438/sub_82134860)
                // use: +20 flags, +28 block count, +44 large list, +48 cursor,
                // +384 large free-list head, +1408 critical section.
                uint32_t heap = 0;
                std::memcpy(&heap, g_base + 0x8294A5A0u, 4);
                heap = __builtin_bswap32(heap);
                std::printf("  heap         : [0x8294A5A0]=0x%08x\n", heap);
                if (heap != 0 && heap < GuestMemorySize)
                {
                    const uint32_t offs[] = {20, 28, 40, 44, 48, 88, 248, 384, 1408};
                    for (uint32_t o : offs)
                    {
                        if (heap + o + 4 <= GuestMemorySize)
                        {
                            uint32_t w = 0;
                            std::memcpy(&w, g_base + heap + o, 4);
                            w = __builtin_bswap32(w);
                            std::printf("    heap+%-5u = 0x%08x\n", o, w);
                        }
                    }
                }
                {
                    // Low guest memory reads the allocator would hit with a
                    // NULL heap (sub_82133438 indexes [pool+384] etc.).
                    const uint32_t low[] = {0, 4, 8, 24, 28, 40, 44, 48, 384, 1024, 1408};
                    std::printf("  low mem     :");
                    for (uint32_t va : low)
                    {
                        uint32_t w = 0;
                        std::memcpy(&w, g_base + va, 4);
                        w = __builtin_bswap32(w);
                        std::printf(" [%u]=0x%08x", va, w);
                    }
                    std::printf("\n");
                }
                {
                    // The request descriptor sub_82133438 was called with.
                    const uint32_t desc = report.faultGpr[4];
                    if (desc != 0 && desc + 16 <= GuestMemorySize)
                    {
                        std::printf("  desc         : 0x%08x\n", desc);
                        for (uint32_t o = 0; o < 16; o += 4)
                        {
                            uint32_t w = 0;
                            std::memcpy(&w, g_base + desc + o, 4);
                            w = __builtin_bswap32(w);
                            std::printf("    desc+%-3u = 0x%08x\n", o, w);
                        }
                    }
                    // Large free-list walk (fault path): pool=0, so the list
                    // head is guest[384]; nodes are u16 size at -8, u32 next
                    // at +0, u32 prev at +4. Sentinel is the head addr (384).
                    {
                        const uint32_t head = 384;
                        uint32_t node = 0;
                        std::memcpy(&node, g_base + head, 4);
                        node = __builtin_bswap32(node);
                        std::printf("  free-list    : head guest[%u]=0x%08x\n", head, node);
                        for (int hop = 0; hop < 24; hop++)
                        {
                            if (node == head) break;
                            if (node >= 0x82000000u && node + 12 <= GuestMemorySize)
                            {
                                uint16_t sz = 0;
                                uint32_t nx = 0, pv = 0;
                                std::memcpy(&sz, g_base + node - 8, 2);
                                sz = __builtin_bswap16(sz);
                                std::memcpy(&nx, g_base + node, 4);
                                nx = __builtin_bswap32(nx);
                                std::memcpy(&pv, g_base + node + 4, 4);
                                pv = __builtin_bswap32(pv);
                                std::printf("    [0x%08x] sz=%5u next=0x%08x prev=0x%08x\n", node, sz, nx, pv);
                                node = nx;
                            }
                            else
                            {
                                std::printf("    [0x%08x] OUT OF RANGE (next read faults)\n", node);
                                break;
                            }
                        }
                    }
                }
            }
            {
                // Indirect NT dispatch table used by the game's file layer:
                // [0x827F39D0] holds a static vtable; +12 = create, +16 = read,
                // +24 = query-directory, +32 = query-information.
                const uint32_t ftable = 0x827F39D0u;
                uint32_t table = 0;
                std::memcpy(&table, g_base + ftable, 4);
                table = __builtin_bswap32(table);
                std::printf("  nt table     : [0x%08x]=0x%08x\n", ftable, table);
                if (table != 0 && table < GuestMemorySize)
                {
                    for (int s = 0; s <= 28; s += 4)
                    {
                        uint32_t slot = 0;
                        std::memcpy(&slot, g_base + table + (uint32_t)s, 4);
                        slot = __builtin_bswap32(slot);
                        std::printf("    [t+%d] = 0x%08x (%s)\n", s, slot, GuestFunctionName(slot));
                    }
                }
            }
        }
        {
            // PPC prologue convention: mflr r12; stw r12,-8(r1); stwu r1,-N(r1)
            // places the return address (guest caller of the faulting function)
            // at entry_r1-8 == current_r1 + N - 8. For sub_821BD618, N=96.
            const uint64_t sp = report.faultR1;
            const uint64_t savedLrSlot = sp + 96 - 8;
            if (savedLrSlot < GuestMemorySize)
            {
                uint32_t savedLr = 0;
                std::memcpy(&savedLr, g_base + savedLrSlot, sizeof(savedLr));
                savedLr = __builtin_bswap32(savedLr);
                std::printf("  saved LR     : 0x%08x at guest [r1+88] (caller of faulting fn, in %s)\n",
                            savedLr, GuestFunctionName(savedLr));
            }
        }
        {
            // Walk the guest backchain: [r1] holds the previous SP; print each
            // frame's [+88] and [+8] words (candidate saved-LR slots).
            std::printf("  guest stack  :\n");
            uint32_t sp = report.faultR1;
            for (int depth = 0; depth < 10 && sp >= 0x1000 && sp + 96 < GuestMemorySize; depth++)
            {
                uint32_t backchain = 0, w88 = 0, w8 = 0;
                std::memcpy(&backchain, g_base + sp, 4);
                std::memcpy(&w88, g_base + sp + 88, 4);
                std::memcpy(&w8, g_base + sp + 8, 4);
                backchain = __builtin_bswap32(backchain);
                w88 = __builtin_bswap32(w88);
                w8 = __builtin_bswap32(w8);
                std::printf("    r1=0x%08x backchain=0x%08x [+88]=0x%08x (%s) [+8]=0x%08x\n",
                            sp, backchain, w88, GuestFunctionName(w88), w8);
                {
                    // sub_822C4630 keeps its token list at [r1+144] with the
                    // count at [r1+176]; dump the first token string if set.
                    uint32_t tokList = 0, tokCount = 0;
                    std::memcpy(&tokList, g_base + sp + 144, 4);
                    std::memcpy(&tokCount, g_base + sp + 176, 4);
                    tokList = __builtin_bswap32(tokList);
                    tokCount = __builtin_bswap32(tokCount);
                    if (tokList != 0 && tokList < GuestMemorySize && tokCount > 0)
                    {
                        std::printf("      [tokens] count=%u first=0x%08x \"", tokCount, tokList);
                        uint32_t tokPtr = tokList;
                        for (int i = 0; i < 64; i++)
                        {
                            uint8_t c = 0;
                            std::memcpy(&c, g_base + tokPtr + i, 1);
                            if (c == 0)
                                break;
                            std::printf("%c", (c >= 32 && c < 127) ? c : '?');
                        }
                        std::printf("\"\n");
                    }
                }
                if (backchain <= sp)
                    break;
                sp = backchain;
            }
        }
        if (report.faultBytes[0] != 0)
        {
            std::printf("  fault bytes  :");
            for (int i = 0; i < 16; i++)
                std::printf(" %02x", report.faultBytes[i]);
            std::printf("\n");
        }
        if (report.faultCallerLR != 0)
            std::printf("  caller LR    : 0x%08x (guest caller of the indirect call, in %s)\n",
                        report.faultCallerLR, GuestFunctionName(report.faultCallerLR));
        std::printf("  fault mem    : %s @0x%llx%s",
                    report.faultCode == EXCEPTION_ACCESS_VIOLATION ? (report.readFault ? "READ" : "WRITE") : "N/A",
                    (unsigned long long)report.faultAddr,
                    report.faultAddr == 0 ? " (NULL)" : "");
        if (report.faultCode == EXCEPTION_ACCESS_VIOLATION && report.faultAddr >= (uintptr_t)g_base && report.faultAddr < (uintptr_t)g_base + GuestMemorySize)
            std::printf(" (guest 0x%llx)", (unsigned long long)(report.faultAddr - (uintptr_t)g_base));
        std::printf(" [code 0x%08x%s]\n", report.faultCode,
                    report.faultCode == EXCEPTION_ACCESS_VIOLATION ? " AV" :
                    report.faultCode == EXCEPTION_BREAKPOINT ? " BPT" :
                    report.faultCode == EXCEPTION_INT_DIVIDE_BY_ZERO ? " DIV0" :
                    report.faultCode == 0xC000008F ? " FP-FAULT" : "");
        constexpr uint32_t TriageSlot = 0x8285FEA0;
        uint32_t slotRaw = 0;
        std::memcpy(&slotRaw, g_base + TriageSlot, sizeof(slotRaw));
        const uint32_t slotBE = __builtin_bswap32(slotRaw);
        std::printf("  slot @0x%08x = 0x%08x (BE 0x%08x)\n", TriageSlot, slotBE, slotBE);
        if (slotBE != 0)
        {
            // Dispatch table entry for the slot target, as sub_821BD618 resolves
            // it: *(PPCFunc**)(base + PPC_IMAGE_BASE + PPC_IMAGE_SIZE +
            // (target - PPC_CODE_BASE) * 2). Prints the computed table address
            // and its content so we can tell a NULL entry (faulting table read)
            // from a non-NULL entry (fault inside the callee).
            const uintptr_t tableAddr =
                uintptr_t(g_base) + PPC_IMAGE_BASE + PPC_IMAGE_SIZE +
                (uint64_t(uint32_t(slotBE) - PPC_CODE_BASE) * 2);
            PPCFunc* entry = PPC_LOOKUP_FUNC(g_base, slotBE);
            std::printf("  dispatch table@0x%08zx -> PPC_LOOKUP_FUNC(0x%08x) = %p%s\n",
                        (size_t)tableAddr, slotBE, (void*)entry,
                        entry == nullptr ? " <-- NULL ENTRY" : " (installed)");
        }
        if (!report.faultStack.empty())
        {
            std::printf("  host stack   : (innermost first)\n");
            for (const auto& s : report.faultStack)
                std::printf("    %s\n", s.c_str());
        }
    }

    return 0;
}