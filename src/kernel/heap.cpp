#include <stdafx.h>
#include "heap.h"
#include "memory.h"
#include "function.h"
#include "ppc_config.h"  // T43.1c (F-791): PPC_IMAGE_BASE/PPC_IMAGE_SIZE for the PHYS-LIVE region
                         // table below. Read-only use; the header itself is rule-2 do-not-edit.
#include "logging.h"
#include <boot_host.h>  // F-374: header guard arm/disarm around each operation
#include <atomic>
#include <unordered_set>
#include <windows.h>
#include <intrin.h>  // F-370: _ReturnAddress() for the heap caller census
#include <cstdio>    // F-373: snprintf for the raw header dump
#include <cstdlib>   // T43.1: std::getenv for the forced-invariant-gate control
#include <dbghelp.h>

// F-806b: RAII open/close of the F-374/F-388 header-guard window. MOVED UP from below (it used to
// be defined just above Heap::Alloc): the reporter rows at ~1482/~1556 run on their own thread,
// outside any allocator window, and `HeapDiag` reads the instance -- `capacity` at instance+0x208
// -- which since F-806 is a genuine out-of-window access on the guarded page. MEASURED in w801 as
// `F388-PHYSGUARD trip=3/4/5 off=0X208 want=R hostRVA=0x2e4dd3` = `o1heapGetDiagnostics+0x3`.
// Every existing user keeps the same two calls in the same order; do not move this back down.
namespace {
    struct HeapGuardWindow
    {
        HeapGuardWindow() { mcla::boot::HeapGuardDisarm(); }
        ~HeapGuardWindow() { mcla::boot::HeapGuardArm(); }
    };
} // namespace

// F-784 phase 3: the T44 wipe-watch COVERAGE line, defined in gpu_cp.cpp beside
// T44WipeSelfTest. NotePhysBinProbe prints it once per probe so a run whose card pages produced
// no T44-WIPE-STORE row reports its counts instead of leaving the reader to argue from absence --
// w747's "0 rows in the card window" was uninterpretable precisely because no such count existed
// (LT rule 19: a zero is not a result until the instrument is shown firing).
namespace mcla::gpu { void T44WipeTotalsLine(uint32_t probeN); }

// F-412: dead -- zero code references in src/; the same value lives on as kUserHeapArenaEnd
// (heap_arena.h:24). Kept only because heap_arena.h:25 still names it in prose.
constexpr size_t RESERVED_BEGIN = 0x7FEA0000;

// Session 76j: exact-allocation registry for the physical arena. The guest
// frees sub-blocks carved from ITS OWN pools via RtlFreeHeap/XFreeMem; a raw
// o1heapFree on such a pointer releases a region that still contains live
// data (observed: the device-registry holder shared bytes with a live guest
// slab element â†’ the texture ctor scribbled FF00FF00 over it â†’ GetDevice
// called a poisoned Device* â†’ AV at the first uncommitted page). Only
// pointers this allocator actually returned may be freed.
static std::unordered_set<void *> &LivePhysAllocs()
{
    static std::unordered_set<void *> set;
    return set;
}

// The host-image-relative return address of a caller frame. MOVED here (unchanged body) so the SEH
// wrappers below can publish it: it used to live in the anonymous namespace at the FragHeaderProbe
// block, which is BELOW them, and the name is used by the same internal function at every old site.
static uintptr_t CallerRva(void *ra)
{
    const uintptr_t base = reinterpret_cast<uintptr_t>(GetModuleHandleA(nullptr));
    return base ? reinterpret_cast<uintptr_t>(ra) - base : 0;
}

// ---- F-640: in-process host-symbol resolution ------------------------------------------------
//
// A CHEAP MECHANISM ALREADY EXISTS IN THIS FILE, which is the only reason this block is here at
// all rather than a report that symbol resolution is too expensive to do in-process: `SymInitialize`
// + `SymFromAddr` behind a `std::once_flag`, in the BOGUSFREE stack walk further down
// (`Heap::Free`'s non-exact-free probe). That code is factored out here, UNCHANGED in behaviour,
// so the leak census can print the symbol its own `caller_rva` names instead of leaving every rank
// row as a bare hex rva that only an offline /MAP pass can turn into a name.
//
// WHY IT IS BOUNDED, since the task brief allows declining this. `SYMOPT_DEFERRED_LOADS` makes
// `SymFromAddr` a walk of the loaded module list plus the symbol table the loader already has --
// no symbol server, no disk read, and nothing on the allocation hot path. It is called ONLY from
// the summary cadence (`kAcctSummaryEvery` = 20000 events, which is 4 emits per arena in a
// w661/w662-shaped run) and at most `kCallerSlots` = 64 times per emit: <= 256 lookups for an
// entire run. The offline form remains the authority and is still what the gate should use, because
// in-process resolution returns whatever symbols the RUNNING image exposes, which is a different set
// from the linker's /MAP file:
//     python tools/host_rva_resolve.py build/mcla.map 0x<rva>
// and it must be the map from the SAME build (a control for that requirement is in the report).
namespace
{
    std::once_flag g_symOnce;

    void EnsureSymInit()
    {
        std::call_once(g_symOnce, []() {
            SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS);
            SymInitialize(GetCurrentProcess(), nullptr, TRUE);
        });
    }

    // rva -> "<symbol>+0x<disp>" into a caller-supplied buffer, in the F-373 house style
    // (snprintf, no allocation, no exception, cannot fault building its own string). Returns `out`
    // on every path, always NUL-terminated when outSize > 0, so a caller can print it directly.
    const char *HostSymbol(uint32_t rva, char *out, size_t outSize)
    {
        if (outSize == 0)
            return out;
        out[0] = 0;
        const uintptr_t base = reinterpret_cast<uintptr_t>(GetModuleHandleA(nullptr));
        if (base == 0)
        {
            std::snprintf(out, outSize, "no-image");
            return out;
        }
        if (rva == 0)
        {
            std::snprintf(out, outSize, "no-host-frame");
            return out;
        }
        EnsureSymInit();
        alignas(8) char scratch[sizeof(SYMBOL_INFO) + 256];
        SYMBOL_INFO *si = (SYMBOL_INFO *)scratch;
        si->SizeOfStruct = sizeof(SYMBOL_INFO);
        si->MaxNameLen = 255;
        DWORD64 disp = 0;
        if (SymFromAddr(GetCurrentProcess(), (DWORD64)(base + (uintptr_t)rva), &disp, si) &&
            si->Name[0] != 0)
        {
            std::snprintf(out, outSize, "%s+0x%llx", si->Name, (unsigned long long)disp);
            return out;
        }
        // Deliberately NOT silent: an unresolvable rva must be visible as such, because the whole
        // point of the field is that a reader never has to guess whether a blank meant "no symbol".
        std::snprintf(out, outSize, "unresolved-0x%x", rva);
        return out;
    }
}  // namespace

// ---- attribution state for the SEH net and the leak census (read-only) ----------------------
//
// WHY THIS EXISTS. SehO1Allocate/SehO1Free turn an AV inside o1heap into a logged null return.
// That net is what keeps the process alive (the comment at the refusal check below: 293,212
// `o1heap AV fault-addr=` rows in w578, and the guest keeps running), but the row it prints names
// the FAULTING ADDRESS and nothing else. Not which allocation was in flight, not who asked for
// it, not the last requests the arena served. A poisoned free-list link is therefore unnamed: the
// only thing a soak can say is "o1heap walked a bad pointer again". The two structures below are
// what turn that row into an attribution, and both are fixed-size PODs -- no allocation, no free,
// no behaviour change anywhere.
namespace
{
    constexpr uint32_t kArenaUser = 0;  // guest 0x20000..0x7FEA0000, heap_arena.h:23-25
    constexpr uint32_t kArenaPhys = 1;  // guest 0xA0400000..0xFFFFFFFF, heap_arena.h:40

    // The last kSiteSlots requests each arena served. A ring, not a histogram: a leaking caller
    // is named by the rva/guest-lr of the request in flight when its arena dies, and 8 deep is
    // enough to separate "one host loop" from "the XTL path" (memory.cpp:339). A ring is also the
    // only shape that can be read from an SEH filter without allocating.
    struct HeapSite
    {
        uint32_t seq;   // ring sequence that wrote this slot; 0 = never written
        uint32_t arena; // kArenaUser / kArenaPhys
        uint32_t rva;   // CallerRva(_ReturnAddress()) of the host frame that asked
        uint32_t glr;   // guest lr, 0 outside a guest context
        uint32_t size;  // bytes that caller asked for
    };
    constexpr uint32_t kSiteSlots = 8;
    struct SiteRing
    {
        std::atomic<uint32_t> seq{0};
        HeapSite slot[kSiteSlots];
    };
    SiteRing g_sites[2];

    void RecordSite(uint32_t arena, uint32_t size, void *ra)
    {
        SiteRing &r = g_sites[arena];
        const uint32_t n = r.seq.fetch_add(1, std::memory_order_relaxed) + 1;
        HeapSite &s = r.slot[(n - 1) % kSiteSlots];
        s.size = size;
        s.rva = (uint32_t)CallerRva(ra);
        s.glr = 0;
        if (const PPCContext *c = GetPPCContext())
            s.glr = (uint32_t)c->lr;
        s.arena = arena;
        s.seq = n;  // written last, so the newest slots are the likeliest to be complete
    }

    const HeapSite *NewestSite(uint32_t arena)
    {
        const SiteRing &r = g_sites[arena];
        const uint32_t n = r.seq.load(std::memory_order_relaxed);
        if (n == 0)
            return nullptr;
        return &r.slot[(n - 1) % kSiteSlots];
    }

    // One fixed-size line describing the last kSiteSlots requests `arena` served. snprintf into a
    // caller-supplied buffer (F-373's house style for text built next to the filter) so the filter
    // itself formats without allocating and cannot fault on its own string building.
    // `[[maybe_unused]]`: its only caller is the SEH filter, which does not exist on the no-SEH
    // path (`MCLA_O1_ALLOC` -> `o1heapAllocate` directly), where this would be dead code.
    [[maybe_unused]] void FormatSites(uint32_t arena, char *out, size_t outSize)
    {
        const SiteRing &r = g_sites[arena];
        const uint32_t n = r.seq.load(std::memory_order_relaxed);
        if (n == 0)
        {
            std::snprintf(out, outSize, "none");
            return;
        }
        const uint32_t first = n > kSiteSlots ? n - kSiteSlots : 0;
        size_t used = 0;
        out[0] = 0;
        for (uint32_t i = first; i < n && used + 1 < outSize; ++i)
        {
            const HeapSite &s = r.slot[i % kSiteSlots];
            const int w = std::snprintf(out + used, outSize - used, "%srva:%#x lr:%08X sz:%#x",
                                        (i != first) ? " | " : "", s.rva, s.glr, s.size);
            if (w <= 0)
                break;
            used += (size_t)w;
        }
    }

    // What an o1heap call is serving right now is declared in the `_MSC_VER` block below, with the
    // net that consumes it: on the no-SEH path (`MCLA_O1_ALLOC` -> `o1heapAllocate` directly)
    // nothing would ever read it.
}  // namespace

// SEH-safe o1heap allocate: must be a C-style function with no C++ objects
// that require unwinding â€” clang-cl crashes compiling __try in a C++ method
// that holds std::lock_guard.
#if defined(_MSC_VER)
    namespace
    {
    // What an o1heap call is serving right now, published by the wrappers below so the filter can
    // print it instead of guessing. thread_local ON PURPOSE: an AV is caught by the thread that
    // faulted, so the filter always reads its own thread's request, and the cross-thread mixture
    // (request A's size with request B's op) that a plain global would produce under concurrent
    // allocs cannot appear. Trivially destructible, so no TLS teardown can run inside a filter.
    enum : uint32_t
    {
        kO1Idle = 0,
        kO1AllocUser,
        kO1AllocPhys,
        kO1FreeUser,
        kO1FreePhys,
    };
    struct O1InFlight
    {
        uintptr_t inst;   // o1heap instance being served
        uintptr_t ptr;    // raw (alloc) or user (free) pointer
        uint64_t amount;  // bytes asked of o1heap (alloc) or 0 (free)
        uint32_t op;      // one of the kO1* values
        uint32_t rva;     // CallerRva of the host frame that asked
        uint32_t glr;     // guest lr at that moment
        // 2026-09-30 (F-641), ADDED FIELD, appended last so the offsets above are untouched: 1 when
        // the request in flight went to o1heapAllocateGranular (the fixed-granularity large path)
        // rather than to o1heapAllocate. It only reaches a log line when the net catches an AV, and
        // its whole job is to say WHICH of the two allocators was walking the list at the time --
        // the large path is the only one that walks, so without this a poisoned-link AV would be
        // indistinguishable between the two.
        uint32_t granular;  // 0 = binned path, 1 = granular path
    };
    thread_local O1InFlight t_o1InFlight{};

    const char *O1OpName(uint32_t op)
    {
        switch (op)
        {
            case kO1AllocUser: return "user-alloc";
            case kO1AllocPhys: return "phys-alloc";
            case kO1FreeUser: return "user-free";
            case kO1FreePhys: return "phys-free";
            default: return "idle";
        }
    }

    uint32_t O1ArenaOf(uint32_t op)
    {
        return (op == kO1AllocPhys || op == kO1FreePhys) ? kArenaPhys : kArenaUser;
    }

    // Namespace-scope, not a function-local static: an AV filter must not touch an initialisation
    // guard. Counts AVs so the site dump below can be throttled independently of the AV row.
    std::atomic<uint32_t> g_o1AvSites{0};
    }  // namespace

    // Session 73: capture the faulting address so the corrupted o1heap
    // fragment can be identified. The filter runs while the exception
    // context is live; keep it C-style (no unwinding objects).
    static long SehO1Filter(EXCEPTION_POINTERS *info)
    {
        if (info && info->ExceptionRecord &&
            info->ExceptionRecord->ExceptionCode == 0xC0000005 &&
            info->ExceptionRecord->NumberParameters >= 2)
        {
            const void *faultAddr =
                (const void *)info->ExceptionRecord->ExceptionInformation[1];
            // The attribution half: the request being served when the net went up. Before this the
            // row said only "AV at X"; now it says which allocation was in flight, out of which
            // arena, and which host/guest frame asked for it -- which is the difference between
            // "o1heap walked a bad pointer" and a nameable writer.
            const O1InFlight &f = t_o1InFlight;
            MCLA_LOG_ERROR("o1heap AV fault-addr={:p} (op={} ) arena={} req={:#x} inst={:p} "
                           "ptr={:p} site_rva={:#x} site_lr={:08X} gran={}",
                           faultAddr,
                           (unsigned long long)
                               info->ExceptionRecord->ExceptionInformation[0],
                           O1OpName(f.op), (uint64_t)f.amount, (void *)f.inst, (void *)f.ptr,
                           f.rva, f.glr, (unsigned)f.granular);
            // The last requests this arena served, so a future finding can name the writer from a
            // soak. THROTTLED ON PURPOSE, separately from the row above: that row is unbounded
            // (293,212 of them in w578) and one extra line per AV would double the volume of the
            // single marker the log-quality checks count (F-054's POISONED rule).
            {
                const uint32_t sn = g_o1AvSites.fetch_add(1, std::memory_order_relaxed) + 1;
                if (sn <= 4 || (sn % 1000) == 0)
                {
                    char sites[512] = {};
                    FormatSites(O1ArenaOf(f.op), sites, sizeof(sites));
                    MCLA_LOG_ERROR("o1heap AV #{} last_sites[{}]: {}", sn, (unsigned)kSiteSlots,
                                   sites);
                }
            }
            const uint8_t *gbase =
                static_cast<const uint8_t *>(
                    mcla::kernel::g_memory.Translate(0));
            const uintptr_t fault = (uintptr_t)faultAddr;
            const uintptr_t lo = (uintptr_t)gbase;
            // Unsigned offset test â€” `fault + 64 < lo + 4GB` wraps and passes
            // for wild pointers like 0xFFFFFFFFFFFFFFFF, and the dump below
            // then faulted *inside* this filter (2 cascading AVs per real one).
            const uintptr_t off = fault - lo;
            if (gbase != nullptr && fault >= lo && off < 0x100000000ull)
            {
                MCLA_LOG_ERROR("o1heap AV guest-addr={:08X}",
                               static_cast<uint32_t>(off));
                if (off >= 32 && off + 40 <= 0x100000000ull)
                {
                    const uint64_t *p = (const uint64_t *)(fault & ~7ull);
                    MCLA_LOG_ERROR("  [fa-32]={:016X}:{:016X} [fa-16]={:016X}:{:016X}",
                                   p[-4], p[-3], p[-2], p[-1]);
                    MCLA_LOG_ERROR("  [fa+00]={:016X} [fa+08]={:016X}", p[0], p[1]);
                    MCLA_LOG_ERROR("  [fa+16]={:016X} [fa+24]={:016X}", p[2], p[3]);
                }
            }
        }
        return EXCEPTION_EXECUTE_HANDLER;
    }

    void* SehO1Allocate(O1HeapInstance* heap, size_t amount)
    {
        void* ptr = nullptr;
        // Publish the request BEFORE the call, clear it after: an AV inside o1heap is caught by
        // this frame, so the filter below always finds this thread's descriptor filled in. The
        // arena is named by comparing the instance against the two heaps g_userHeap holds, which
        // is what makes the filter's `arena=` field mean something.
        O1InFlight& f = t_o1InFlight;
        f.inst = reinterpret_cast<uintptr_t>(heap);
        f.ptr = 0;
        f.amount = amount;
        f.op = (heap != nullptr && heap == g_userHeap.physicalHeap) ? kO1AllocPhys : kO1AllocUser;
        f.rva = (uint32_t)CallerRva(_ReturnAddress());
        f.glr = 0;
        f.granular = 0;
        if (const PPCContext* c = GetPPCContext())
            f.glr = static_cast<uint32_t>(c->lr);
        __try
        {
            ptr = o1heapAllocate(heap, amount);
        }
        __except (SehO1Filter(GetExceptionInformation()))
        {
            ptr = nullptr;
        }
        f.op = kO1Idle;
        return ptr;
    }
    // F-641: the SAME net for the fixed-granularity large path, because that path is the only code in
    // o1heap.c that walks a free list, so it is the only new place an AV can come from. It is a copy
    // of SehO1Allocate with one line changed -- the call -- on purpose: sharing the body would mean a
    // function parameter on a frame that must stay C-style, and the descriptor fields that make an AV
    // row actionable (arena, request, site, guest lr) are set identically in both. If the two ever
    // drift, the `gran=` field on the AV row is what says so.
    void* SehO1AllocateGranular(O1HeapInstance* heap, size_t amount, size_t granularity)
    {
        void* ptr = nullptr;
        O1InFlight& f = t_o1InFlight;
        f.inst = reinterpret_cast<uintptr_t>(heap);
        f.ptr = 0;
        f.amount = amount;
        f.op = (heap != nullptr && heap == g_userHeap.physicalHeap) ? kO1AllocPhys : kO1AllocUser;
        f.rva = (uint32_t)CallerRva(_ReturnAddress());
        f.glr = 0;
        f.granular = 1;
        if (const PPCContext* c = GetPPCContext())
            f.glr = static_cast<uint32_t>(c->lr);
        __try
        {
            ptr = o1heapAllocateGranular(heap, amount, granularity);
        }
        __except (SehO1Filter(GetExceptionInformation()))
        {
            ptr = nullptr;
        }
        f.op = kO1Idle;
        return ptr;
    }
    // T43.2: THE SAME NET FOR THE PROBE, for the reason F-641 gives above -- `o1heapProbeGranular`
    // walks `next_free`, which is the one dereference a corrupt free list makes unsafe, so the
    // instrument that exists to find the corruption must not become a second fault on the same path.
    // On a catch the result is marked `probe_av`, and that is an ANSWER rather than a lost row: it
    // says the list the allocator was walking holds a pointer that is not readable, which is a
    // stronger statement than any size word in the census could make. Deliberately not routed through
    // `SehO1Filter`: that filter prints an AV row attributed to an ALLOCATION IN FLIGHT via
    // `t_o1InFlight`, and no allocation is in flight here -- the request already failed and returned.
    // Attributing a probe fault to it would name the wrong operation, which is exactly the error
    // F-641's `gran=` field was added to prevent.
    void SehO1ProbeGranular(const O1HeapInstance* heap, size_t amount, size_t granularity,
                            O1HeapProbeResult* out)
    {
        if (out == nullptr)
            return;
        __try
        {
            o1heapProbeGranular(heap, amount, granularity, out);
        }
        __except (EXCEPTION_EXECUTE_HANDLER)
        {
            out->probe_av = 1u;
            out->found_bin = -1;
        }
    }
    void SehO1Free(O1HeapInstance* heap, void* ptr)
    {
        // Same publication for the free half, so an AV inside o1heapFree names the block being
        // released rather than only its faulting address.
        O1InFlight& f = t_o1InFlight;
        f.inst = reinterpret_cast<uintptr_t>(heap);
        f.ptr = reinterpret_cast<uintptr_t>(ptr);
        f.amount = 0;
        f.op = (heap != nullptr && heap == g_userHeap.physicalHeap) ? kO1FreePhys : kO1FreeUser;
        f.rva = (uint32_t)CallerRva(_ReturnAddress());
        f.glr = 0;
        if (const PPCContext* c = GetPPCContext())
            f.glr = static_cast<uint32_t>(c->lr);
        __try
        {
            o1heapFree(heap, ptr);
        }
        __except (EXCEPTION_EXECUTE_HANDLER)
        {
            static std::atomic<uint32_t> s_freeSeh{0};
            const uint32_t n = s_freeSeh.fetch_add(1) + 1;
            if (n <= 8 || (n % 100) == 0)
                MCLA_LOG_ERROR("o1heapFree SEH catch #{} ptr={:p} arena={} site_rva={:#x} "
                               "site_lr={:08X}",
                               n, ptr, O1OpName(f.op), f.rva, f.glr);
        }
        f.op = kO1Idle;
    }
#define MCLA_O1_ALLOC(heap, amount) SehO1Allocate((heap), (amount))
#define MCLA_O1_ALLOC_GRANULAR(heap, amount, gran) SehO1AllocateGranular((heap), (amount), (gran))
#define MCLA_O1_FREE(heap, ptr) SehO1Free((heap), (ptr))
#else
#define MCLA_O1_ALLOC(heap, amount) o1heapAllocate((heap), (amount))
#define MCLA_O1_ALLOC_GRANULAR(heap, amount, gran) o1heapAllocateGranular((heap), (amount), (gran))
#define MCLA_O1_FREE(heap, ptr) o1heapFree((heap), (ptr))
#endif

// Mirrors o1heap.c FragmentHeader layout (private there): next@0, prev@8,
// size@16, used@24. O1HEAP_ALIGNMENT=32, FRAGMENT_SIZE_MIN=64.
namespace
{
    struct FragHeaderProbe
    {
        void* next;
        void* prev;
        size_t size;
        bool used;
    };
    constexpr size_t kO1HeapAlignment = sizeof(void*) * 4; // 32
    constexpr size_t kFragmentSizeMin = kO1HeapAlignment * 2; // 64
}

// F-370: the guest user heap keeps its own o1heap header at guest VA 0x20000 (Heap::Init binds the
// arena there). In w374/w375/w376 (and again in w378, F-372 Â§1) those words turn to garbage between
// two consecutive Heap calls -- `F370-HEAP-BIG #15` healthy, `#16` garbage one line later --
// after which Heap::Alloc refuses everything (`Alloc: o1heap invariants FAIL`) and the 16th guest
// thread is never created (src/kernel/guest_thread.cpp:23 takes the null and used to AV in memset,
// F-370 Â§1). `w373` is the pre-instrument soak: there the same dead header shows only as that AV
// plus its one `invariants FAIL` row, and F-370 Â§3 scanned 40 soaks and found zero hits before it.
// The boot worker then keeps looping with its work capped by the dead allocator: it
// does NOT park forever on counting semaphore C501FC00 -- F-370 Â§4 measured 6 WAIT + 6 RETURNED
// pairs there and retired F-369 Â§5's "INFINITE wait" wording. `capacity` is constant, so an
// O(1) compare against the value captured at Init brackets the corruption to one heap operation
// without walking the allocator's tree.
namespace
{
    size_t g_hdrGoldenCap = 0;
    uint8_t *g_hdrArena = nullptr;

    inline O1HeapDiagnostics HeapDiag(O1HeapInstance *h)
    {
        O1HeapDiagnostics d{};
        if (h != nullptr)
            d = o1heapGetDiagnostics(h);
        return d;
    }

    // F-631: o1heap's private `nonempty_bin_mask` sits immediately after the 64 bin heads --
    // `O1HeapInstance{bins[NUM_BINS_MAX=64], mask, diagnostics}` (o1heap.c:133-139) -- so it is
    // instance+0x200 on x64, and `diagnostics.capacity` is +0x208 (F-375 §2, corroborated by
    // boot_host.cpp:1991-1992 "64 bins x8 + mask + diagnostics, instance is 0x230 bytes padded to
    // 0x240"). This ONE word is what separates an honest full pool from a destroyed one, and the
    // distinction is not observable any other way:
    //   * `o1heapDoInvariantsHold` NEVER dereferences a fragment and never walks a list
    //     (o1heap.c:452-490: bin-mask/bins consistency plus the diagnostics words). It therefore
    //     returns TRUE with every bin head zeroed and every fragment marked used.
    //   * `o1heapAllocate` with `nonempty_bin_mask == 0` computes `suitable_bins == 0`, skips the
    //     whole allocation body and returns NULL (o1heap.c:321-323,376-379) -- for EVERY size,
    //     including 1 byte.
    //   So a refusal row carrying `mask` names which of the two happened, from the same row, with
    //     no new instrument. That is F-630's method note ("a refusal of an absurdly small size is a
    //     corrupt-allocator signal, not a capacity signal") turned into a printed field instead of
    //     an argument: mask=0 with cap intact IS exhaustion; mask!=0 with capacity intact is
    //     corruption; capacity==0 is a destroyed header.
    constexpr size_t kO1BinMaskOffset = 0x200;
    uint64_t O1BinMask(const O1HeapInstance *h)
    {
        if (h == nullptr)
            return 0;
        return *reinterpret_cast<const uint64_t *>(reinterpret_cast<const uint8_t *>(h) +
                                                  kO1BinMaskOffset);
    }

    // F-631: the size class o1heap would look in, and whether that class is reachable at all.
    // `o1heapAllocate` rounds `amount + 32` up to a power of two, indexes `bins[]` by
    // `log2Ceil(fragment_size / 64)` and masks `nonempty_bin_mask` with `candidate_bin_mask`
    // (o1heap.c:310-321). Reproducing those four lines here turns a bare "returned null" into
    // "asked for bin N, the mask admits bins >= N, lowest set bit is M" -- the whole difference
    // between a full pool (M == 0, no bit set) and a destroyed one (capacity == 0, or a fragment
    // header overwritten so the walk finds no exact-size match while the mask still promises one).
    inline size_t O1Log2Pow2(size_t v)  // v is a power of two and >= 1
    {
        unsigned long idx = 0;
        _BitScanReverse64(&idx, (unsigned __int64)v);
        return (size_t)idx;
    }

    inline size_t O1RoundUpPow2(size_t v)
    {
        size_t p = kFragmentSizeMin;
        while (p < v && p < ((size_t)1 << 62))
            p <<= 1;
        return p;
    }

    // F-638: the size class o1heap will look in, in ONE place, so the periodic row and the
    // verdict can never disagree about what class was asked for. This mirrors o1heap's own
    // arithmetic: `roundUpToPowerOf2(amount + O1HEAP_ALIGNMENT)` (o1heap.c:310) then
    // `log2Ceil(fragment_size / FRAGMENT_SIZE_MIN)` (o1heap.c:316), and with
    // FRAGMENT_SIZE_MIN = 2*O1HEAP_ALIGNMENT = 64 (o1heap.c:98) the bin index is log2(frag) - 6.
    struct PhysClassReq
    {
        size_t frag;   // 64 << opt: the footprint this request will consume if it is served
        uint32_t opt;  // the bin index it asks for; cand admits bins >= opt (o1heap.c:318)
    };

    inline PhysClassReq O1ClassOf(size_t amount)
    {
        const size_t frag = O1RoundUpPow2(amount + kO1HeapAlignment);
        return {frag, (frag >= kFragmentSizeMin) ? (uint32_t)(O1Log2Pow2(frag) - 6u) : 0u};
    }

    // =====================================================================================
    // F-641: THE THRESHOLD FOR THE FIXED-GRANULARITY LARGE PATH, AND WHY IT IS NOT A CONSTANT.
    //
    // WHAT THE CONSOLE'S KERNEL DOES WITH THE SAME CALL. `MmAllocatePhysicalMemoryEx` rounds the
    // region to a PAGE size and scans a per-page table; there is no size class anywhere in the chain:
    //   * `page_size` = 4 KiB by default, 64 KiB under X_MEM_LARGE_PAGES, 16 MiB under
    //     X_MEM_16MB_PAGES, and `adjusted_size = xe::round_up(region_size, page_size)` --
    //     .research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_memory.cc:356-364, with
    //     `adjusted_alignment = xe::round_up(alignment, page_size)` at :365 -- then
    //     `PhysicalHeap::AllocRange` at :383.
    //   * `PhysicalHeap::AllocRange` re-rounds and delegates
    //     (.research/xenia/src/xenia/memory.cc:1466, size at :1473, delegation at :1484).
    //   * `BaseHeap::AllocRange` reduces the size to a PAGE COUNT
    //     (`get_page_count(size, page_size_)`, memory.cc:924) and the ONLY size precondition in the
    //     whole chain is `page_count > (high_page_number - low_page_number)` (memory.cc:934); the
    //     search itself is a linear top-down scan of `page_table_` -- a `std::vector<PageEntry>`,
    //     one entry per page (memory.h:210) -- for that many consecutive free pages
    //     (memory.cc:949-988).
    //   * The servable pool is 0x20000000 = 512 MiB (`heaps_.physical.Initialize(..., 0x00000000,
    //     0x20000000, 4096)`, memory.cc:171-172) less the top 64 KiB it reserves as NOACCESS
    //     (`heaps_.physical.AllocFixed(0x1FFF0000, 0x10000, 0x10000, ...)`,
    //     memory.cc:188-189) = 0x1FFF0000 = 511.9 MiB.
    // SO POWER-OF-TWO BINNING IS NOT FAITHFUL FOR THE CONSOLE'S PHYSICAL POOL. It is faithful for
    // the title's own user heap, which is o1dev's allocator and whose classes are its contract; it is
    // a foreign rule for a kernel export that charges `round_up(region_size, 4096)`.
    //
    // 2026-09-30 (F-642, SUPERSEDES the F-641 threshold; the citation block above is unchanged
    // because the reference's behaviour is unchanged -- what changed is what WE do about it).
    //
    // THE F-641 THRESHOLD WAS TOO NARROW, AND MEASURED SO. It was `O1RoundUpPow2(amount + 32) >
    // capacity`, i.e. exactly the requests the binned path CANNOT SERVE. build/w672.log is the
    // counter-example and it is one row: the fatal there was a 0x40000 (256 KiB) request refused at
    // `live=0x1ffb0880 cap=0x1ffffdc0 oom=1` (w672.log:44586) whose power-of-two class is 0x80000
    // = 512 KiB against 0x4f540 = 324,928 bytes free (w672.log:44587, `PHYS-STATE #1`). The pool was
    // 99.94% full of the console's whole 512 MiB, and the request was refused because its charge was
    // DOUBLE the payload, not because the bytes were absent: the page-rounded charge of the same
    // request is 0x42000 = 270,336 B, which is 54,592 bytes LESS than the free bytes already in the
    // pool. `rounded_over_pool=0` on that row because its condition also requires `o1_frag >
    // capacity`, and 0x80000 is not > 0x1ffffdc0 -- so the counter written to name this defect does
    // not fire on it, which is itself the finding: "the set of requests o1heap cannot serve" is a
    // subset of "the set of requests whose charge is wasteful", and only the second one costs the
    // pool its RAM.
    //
    // THE SPACE COST OF EACH POLICY, MEASURED (not modelled). Both charges are computed here from
    // one expression each -- `O1RoundUpPow2(amount + 32)` and `O1GranularCharge(amount)`, the same
    // two the allocator uses -- over the 32 request sizes that build/w672.log actually records
    // (`PHYS-CENSUS` rows 1..32, w672.log:208..3489, the only rows in that log that name a size on
    // this path; `HEAPLEAK-SUM`'s 20,000-allocation cadence never fired because the run made 6,691):
    //     payload                      105,364,272 B   (100.48 MiB)
    //     power-of-two charge          159,607,872 B   (152.21 MiB)   ratio to payload 1.5148
    //     page charge                  105,492,480 B   (100.61 MiB)   ratio to payload 1.0012
    //     pow2 / page                            1.5130        recovered 54,115,392 B (51.61 MiB)
    // and adding the one row only the page policy can serve at all (0x12b80000 -> pow2 class
    // 0x20000000, unservable; page charge 0x12b81000), pow2 needs 664.21 MiB to hold 400.11 MiB of
    // payload and the page rule needs 400.11 MiB. THE ANSWER TO "HOW MUCH DOES ROUNDING COST" IS
    // "UP TO HALF THE POOL", and it is not a worst case here: it is the measured ratio of a real run.
    // The page rule's own waste is bounded by granule-1 = 4,095 B per request, i.e. 27.4 MB over
    // 6,691 requests -- and see (2) below for why even that is not all of it.
    //
    // THE ONE PLACE THE PAGE RULE IS WORSE, AND IT IS MEASURED, NOT ASSUMED: a request whose
    // `amount + 32` is below one page is charged a whole 4096 by the page rule and only
    // `roundUpToPowerOf2(amount + 32)` (>= 64) by the binned one -- 13 of the 32 measured requests
    // (41%: sizes 32..364 B) fall here. The console charges those a full page too
    // (`adjusted_size = xe::round_up(region_size, page_size)`, xboxkrnl_memory.cc:364), so charging a
    // page is the FAITHFUL answer and not a concession; and the cost is bounded anyway, because a
    // sub-page request's power-of-two charge is at most 2,048 B, so all 6,691 of them together could
    // only add 6,691 * 4,095 = 27,397,245 B = 26.1 MiB, against 222,492,800 B of non-row3 power-of-two
    // charge in the same run (536,545,408 live - 314,052,608 for row3, w672.log:44586) -- of which
    // at most 6,691 * 2,048 = 13,701,248 B could come from sub-page requests, so at least
    // 208,791,552 B is provably charged by requests the page rule never charges more for.
    //
    // THE TIME COST OF THE GRANULAR PATH, MEASURED (this is the number the decision needed and it is
    // not a guess). The concern is real: `o1heapAllocateGranular` is the only function in o1heap.c
    // that WALKS a free list instead of taking a bin head, so it is not O(1) -- that is the whole
    // reason the F-641 header told callers to use it only on a refusal path. Measured on this
    // machine, replaying w672's own request shape (the 32 measured sizes plus a 6,660-request tail,
    // 512 MiB arena, best of 7 repetitions, frequency hoisted out of the timed region):
    //     alloc-only   pow2 898.2 ns/alloc   granular 923.1 ns/alloc   +24.9 ns  (+2.77%)
    //     free-every-3rd pow2  16.6 ns/alloc granular  20.8 ns/alloc   + 4.2 ns  (+25.3%)
    // i.e. between 15 us and 167 us of extra time across the whole run's 6,691 allocations, against
    // a 180-second soak. And the scan's own worst case did not occur: instrumenting a SEPARATE COPY
    // of o1heap.c in a temp directory (the repo file is never modified) to count the `hops` the scan
    // loop skips gave hops = 0 on all 13,386 granular calls across both workloads, with
    // `granular_walk_capped = 0` throughout. The reason is structural rather than lucky: the scan
    // starts at the charge's own bin and walks UP, `rebin` bins every split leftover by its OWN size
    // (o1heap.c:236, `log2Floor`), and a leftover is always strictly smaller than the class that
    // produced it, and `o1heapFree` coalesces every free run it touches (o1heap.c:644-676). Free space
    // therefore migrates DOWN the ladder and out of the charge's own bin, which is the one place the
    // scan would have to skip a node. A synthetic pool fragmented into 4,000 free runs also measured
    // hops = 0, because the same coalescing removes the shape the skip path exists for.
    //
    // THE POLICY, THEREFORE, IS: ALWAYS PAGE-GRANULAR, AND THE THRESHOLD DISSOLVES. Not because the
    // cost is zero -- it is +2.8% and 167 us -- but because it buys a measured 1.5130x reduction in
    // charged bytes and the reference applies no size class to this pool at all
    // (memory.cc:924/934/949-988, quoted above). A threshold would only be justified if the two
    // policies charged the same bytes somewhere and one were cheaper in time; they do not -- for
    // every request whose charge is a whole number of pages the page rule is never worse by more than
    // 4,095 B and is usually strictly better, and where the two charges are EQUAL the page rule is
    // also correct, so no size class buys anything back. Two consequences that are properties of the
    // code and not of a run: the routing needs no capacity comparison, so it cannot be wrong the way
    // `> capacity` was when the arena is rebound (`AttachPhysicalArena`); and it needs no fitted
    // constant, so it cannot be mis-attributed to whatever else the next build changes (rule 1a).
    // WHAT THIS DOES NOT TOUCH: the USER arena. `Heap::Alloc` calls `MCLA_O1_ALLOC` (the binned
    // `o1heapAllocate`) and never the granular macro -- grep `O1NeedsGranular`/`MCLA_O1_ALLOC_GRANULAR`
    // for the proof -- so the title's own heap keeps the power-of-two classes three streams measured
    // 181 rows against, and the exception-safety net in SehO1Allocate is still the code that runs for
    // every user allocation.
    constexpr size_t kO1PageGranule = 4096;  // the reference's default page_size, xboxkrnl_memory.cc:356

    // The charge the granular path will ask for, computed the same way the small path's class is
    // computed above: the same `amount + O1HEAP_ALIGNMENT` term, then rounded to the granule instead
    // of to a power of two. Kept here so the row below and the allocator can never disagree about it.
    inline size_t O1GranularCharge(size_t amount)
    {
        return (size_t)((((amount + kO1HeapAlignment) + kO1PageGranule - 1u) / kO1PageGranule) *
                        kO1PageGranule);
    }

    // F-644: WHAT THE CONSOLE CHARGES FOR THE SAME REQUEST. This is the comparator, and it is
    // deliberately NOT `O1GranularCharge` above: the two differ by exactly the terms the console
    // does not have, which is the entire question. The host charges
    //     round_up(guestSize + alignment + O1HEAP_ALIGNMENT + O1HEAP_ALIGNMENT, 4096)
    // -- the `o1Amount` local in `Heap::AllocPhysical` (quoted by symbol; it is
    // `size + alignment + O1HEAP_ALIGNMENT`) plus the `amount + O1HEAP_ALIGNMENT` inside
    // `o1heapAllocateGranular`'s charge -- and the console charges
    //     round_up(region_size, page_size)                                    [xboxkrnl_memory.cc:364]
    // of the guest's `region_size` alone. So the console's charge is this function, and
    // `O1GranularCharge(o1Amount) - O1ConsoleCharge(size)` is the whole of the residual:
    //   * the caller's alignment term, which on every measured request is 16 (the title's alloc
    //     thunk hardcodes `li r5,16`, `82130538`, quoted at imports.cpp:94);
    //   * 32 bytes for the pre-alignment bookkeeping words written at `aligned-8` and `aligned-16`;
    //   * 32 bytes for o1heap's own fragment header (o1heap.c:103-131, below the user pointer).
    // The first two are avoidable in principle and the third is not, because o1heap's fragment
    // header IS how `o1heapFree` and `Heap::IsLiveAllocation` find the block. Note also that BOTH
    // charges round to the same granule, so the only way this function can exceed `size` by a whole
    // page rather than by a few bytes is the page rounding itself -- which the console charges too.
    inline size_t O1ConsoleCharge(size_t guestSize)
    {
        const size_t s = (guestSize > 0) ? guestSize : 1;  // AllocPhysical's own `max(1, size)`
        return (size_t)((((s + kO1PageGranule) - 1u) / kO1PageGranule) * kO1PageGranule);
    }

    // F-642: THE ROUTING PREDICATE. It is the whole policy in one line, and it is `true`.
    //
    // It USED to be `O1RoundUpPow2(amount + kO1HeapAlignment) > capacity` -- "the requests o1heap
    // cannot serve" -- which is true and far too narrow, for the reason the block above measures: a
    // request can be perfectly servable and still charge twice what it needs, and on a 512 MiB pool
    // with 6,691 such requests that is the difference between 100 MiB of payload living and 350 MiB
    // of it living (build/w672.log:44586, `live=0x1ffb0880` of `cap=0x1ffffdc0`). The predicate is
    // KEPT under its old name for one caller only -- `NotePhysLarge`'s `class_over_cap` field, which
    // is a DIAGNOSTIC about the power-of-two class, not a decision -- so no existing reader changes
    // what a number means.
    inline bool O1NeedsGranular(size_t amount, size_t capacity)
    {
        // `O1RoundUpPow2` starts at FRAGMENT_SIZE_MIN, so this reproduces
        // `roundUpToPowerOf2(amount + O1HEAP_ALIGNMENT)` for every amount it can be given.
        return O1RoundUpPow2(amount + kO1HeapAlignment) > capacity;
    }

    // F-642: THE POLICY IN FORCE for the physical pool, as a predicate so the call site still reads
    // as a decision and not as a constant, and so the one place that could ever want to put a
    // threshold back has a name to put it in. `capacity` is deliberately NOT a parameter: under this
    // policy no capacity comparison decides anything, which is what makes the routing independent of
    // which arena is bound.
    //
    // T43.19 (2026-10-13): the SUB-PAGE LEVER, cvar-gated, DEFAULT OFF, one purpose.
    // w769 measured 46,992 served requests at 634.5 MiB charged for 459.1 MiB of payload, of which
    // >= 33,217 requests were a single 4 KiB page each with a 6-112 byte payload (F-642's own bound
    // was 6,691 requests = 26.1 MiB; this run exceeds it 7x, so the term is now the pool's dominant
    // consumer). The smallest refused request needed a 256 KiB run against 68 KiB free -- a 4.3x
    // shortfall that the provable single-page population alone covers ~125x.
    // `mcla_phys_subpage=1` routes ONLY amounts whose full page charge has a sub-page remainder
    // (amount + alignment + 32 <= page; larger requests keep the console-faithful page charge), to
    // the power-of-two class O1RoundUpPow2(amount + alignment + 32) (<= 2,048 B) -- the same class
    // the reference's binned path uses (memory.cc:924: `round_up(alignment, page_size)` then
    // o1heapAllocate) and the same `pow2_would_be` this file already prints on every PHYS-ACCT row.
    // FAITHFULNESS, STATED: xboxkrnl_memory.cc:364 charges the console a full page for sub-page
    // MmAllocatePhysicalMemoryEx requests, so this lever gives the guest MORE memory than the
    // console would have -- a divergence with downstream risk. It stays off until (a) the guest's
    // OWN rounding is read from mcla_pe.bin (rule 0: the guest's bytes outrank Xenia's model) and
    // (b) a soak shows it changes the wall. Every routed allocation is counted and printed
    // (SUB-PAGE-ROUTED, first 8 then every 4096th) so a soak reads the take rate, not a guess.
    inline bool O1SubPageRouting()
    {
        static const bool kEnabled = [] {
            const char* e = std::getenv("mcla_phys_subpage");
            return e != nullptr && e[0] == '1';
        }();
        return kEnabled;
    }
    inline bool O1UsesGranularPolicy(size_t amount, size_t /*capacity*/)
    {
        // The lever only speaks for amounts the page rule OVERCHARGES by more than it saves:
        // `amount` here is o1Amount (size + alignment + O1HEAP_ALIGNMENT), so a sub-page request
        // is one whose amount still fits inside one page. Anything else takes the old path.
        if (O1SubPageRouting() && amount <= kO1PageGranule)
            return false;
        return true;
    }

    // F-638: FOUR classes, and each one is decidable from the fields that exist. The old test
    // ended in `else healthy`, and that third arm is the defect: a pool can be 99.995% full and
    // still carry a non-zero bin mask, so "mask != 0" was read as health. w658's own row proves
    // it -- `bin_mask=0x400 ... free=0x129c0 suitable=0x0` -- and the verdict column said
    // `healthy`. The `else` also made the fragmentation reading in `AcctSummary`'s `HEAPLEAK-SUM`
    // row (the "`bin_mask=0` with `o1_free>0` is the signature of a pool whose every free block
    // is too SMALL" sentence, by that symbol) unreachable dead code: no reading can produce it.
    //
    // THE ONE DERIVED FACT ALL FOUR REST ON -- from the allocator, not from a run.
    //   * `capacity` is the sum of ALL fragment footprints, written once at init (o1heap.c:287);
    //     `allocated` is the running sum of the USED ones: `+= fragment_size` on a successful
    //     take (o1heap.c:356), `-= frag->header.size` on a free (o1heap.c:409). Every byte of
    //     the arena belongs to exactly one fragment, so
    //         free = capacity - allocated  ==  SUM OF THE FREE FRAGMENT SIZES.
    //   * `rebin`/`unbin` are the ONLY writers of `nonempty_bin_mask` (`|= pow2(idx)`,
    //     o1heap.c:210; `&= ~pow2(idx)`, o1heap.c:230), and each runs exactly when a free
    //     fragment enters/leaves its bin, so
    //         free == 0   <=>   bin_mask == 0.
    // Two consequences, and the second is why the old test could not say "exhausted":
    //   1. `bin_mask == 0` is NOT an independent signal -- it is the SAME reading as `free == 0`.
    //      The old `bin_mask == 0 -> exhausted` arm therefore added nothing the free/capacity
    //      words did not already carry.
    //   2. A pool is never healthy on a non-zero mask. "Healthy" means a bin at or above the
    //      class being requested is non-empty, i.e. `suitable != 0` (o1heap.c:321) -- under any
    //      other definition the word carries no information.
    //
    // WHY THERE IS NO free/capacity PERCENTAGE THRESHOLD HERE, although one was asked for: a
    // percentage cannot decide "usable room", and the allocator says why, not the log. A
    // successful allocation SPLITS the fragment it takes and bins the leftover, whose class is
    // strictly BELOW the class taken (`leftover = frag->size - fragment_size < fragment_size`,
    // o1heap.c:339-351), while a free COALESCES adjacent runs (o1heap.c:418-447). So under an
    // alloc-only workload free space only ever migrates DOWN the ladder, `suitable == 0` is an
    // ABSORBING state, and no fraction of capacity bounds how much usable room is left. A
    // free/capacity percentage is therefore REPORTED (`free_ppm` on both rows) and never used as
    // a threshold; build/verify_gate.py B-3 reads the same ratio and says so in its own row.
    //
    // THE ONE THRESHOLD THAT IS THE ALLOCATOR'S OWN: `free < 64 << opt`, the size of ONE
    // fragment of the class being requested. o1heap needs a run of at least
    // `roundUpToPowerOf2(amount + 32)` bytes (o1heap.c:310); if the total free is below that,
    // then every free run is below it, and no coalescing of any subset can produce a serving
    // run either. So the partition below is EXACT, with no fudge factor and nothing fitted to
    // a single run:
    //     free <  64<<opt                  -> EXHAUSTED for this class (free==0 is the
    //                                          special case free < 64<<0 = 64, so it is inside)
    //     free >= 64<<opt, suitable == 0   -> OVER-FRAGMENTED: the bytes exist, the layout does not
    //     free >= 64<<opt, suitable != 0   -> HEALTHY: the class is servable
    enum class PhysVerdict
    {
        Healthy = 0,
        OverFragmented = 1,
        Exhausted = 2,
        DestroyedHeader = 3,
    };

    struct PhysVerdictRow
    {
        PhysVerdict cls = PhysVerdict::Exhausted;
        const char *why = "unclassified";  // the deciding field, printed verbatim
        uint64_t freeBytes = 0;
        uint64_t suitable = 0;
        uint64_t reqFrag = 0;
        unsigned long long freePpm = 0;
        // false when two classes SHARE this reading and the row cannot say which -- printed as
        // `split=collapsed`, never silently resolved. See the opt==0 note in ClassifyPhysPool.
        bool splitExact = true;
    };

    PhysVerdictRow ClassifyPhysPool(const O1HeapDiagnostics &d, uint64_t binMask,
                                    const PhysClassReq &req)
    {
        PhysVerdictRow v;
        v.reqFrag = req.frag;
        // HEADER FIRST, and this ordering is load-bearing: a destroyed instance normally reads
        // `allocated == 0` too, so a `free == 0` test run first would name a destroyed header
        // "exhausted". `destroyed-header` and `exhausted` share the free reading; `capacity` is
        // the only word that separates them, so it is asked first and alone.
        //
        // `capacity == 0` IS NOT PROOF OF A WRITER, and the row must not let a reader assume it.
        // o1heapInit returns false WITHOUT writing the diagnostics words when the base is NULL
        // or the arena is smaller than INSTANCE_SIZE_PADDED + FRAGMENT_SIZE_MIN
        // (o1heap.c:248-249), so the words keep whatever the memory held -- zero on fresh pages,
        // ARBITRARY on a reused arena. Three other producers of the same reading, all named
        // here so a zero is not silently accepted: (i) an external writer zeroing instance+0x208
        // (F-630's mechanism, measured on the USER arena -- for the physical pool it remains a
        // hypothesis, not a measurement); (ii) a STALE instance pointer, i.e. the mapping behind
        // the pool moved and the read landed on a different page (F-373's `moved=`/`retrans=`
        // disambiguation, already printed by CheckHeapHeader); (iii) an Init that was
        // interrupted after the instance was placed but before o1heapInit finished.
        // The integrity test is o1heap's OWN: `capacity >= FRAGMENT_SIZE_MIN &&
        // (capacity % FRAGMENT_SIZE_MIN) == 0` (o1heap.c:469-470), not "is it zero".
        if (d.capacity < kFragmentSizeMin || (d.capacity % kFragmentSizeMin) != 0)
        {
            v.cls = PhysVerdict::DestroyedHeader;
            v.why = (d.capacity == 0) ? "capacity_zero" : "capacity_not_a_whole_class_multiple";
            v.splitExact = false;   // capacity says BROKEN, never says WHICH of the four above
            return v;
        }
        if (d.allocated > d.capacity)
        {
            v.cls = PhysVerdict::DestroyedHeader;
            v.why = "allocated_exceeds_capacity";  // o1heap.c:357 asserts this cannot happen
            v.splitExact = false;
            return v;
        }
        v.freeBytes = d.capacity - d.allocated;
        v.freePpm = (d.capacity != 0)
                        ? (unsigned long long)((v.freeBytes * 1000000ull) / d.capacity)
                        : 0ull;
        const uint64_t cand = (req.opt < 64u) ? (~uint64_t(0) << req.opt) : 0ull;
        v.suitable = binMask & cand;
        if (v.freeBytes < req.frag)
            v.why = (v.freeBytes == 0) ? "no_free_fragment" : "free_below_one_request_class";
        else if (v.suitable == 0)
            v.why = "free_but_no_suitable_class";
        else
            v.why = "suitable_class_present";
        v.cls = PhysVerdict::Exhausted;
        if (v.freeBytes >= req.frag)
            v.cls = (v.suitable == 0) ? PhysVerdict::OverFragmented : PhysVerdict::Healthy;
        // SHARED READING, said in the row rather than papered over. For opt == 0 the candidate
        // mask is all-ones (`~(pow2(0) - 1)`, o1heap.c:318), so `suitable == bin_mask` and
        // `suitable == 0 <=> free == 0`: OVER-FRAGMENTED IS UNREACHABLE at that class and the
        // verdict collapses onto `exhausted`. `split=collapsed` is what the row prints then, so
        // nobody reads the collapse as a measurement. REACHABILITY, derived rather than
        // assumed: the alloc path hands o1heap `o1Amount = size + alignment + 32` with
        // `size >= 1` and `alignment >= 1`, so `o1Amount >= 34` and `frag >= roundUpPow2(66) =
        // 128`, i.e. `opt >= 1` on EVERY refusal row. opt == 0 is therefore reachable only from
        // the FREE path's "nothing has ever been refused" fallback below, and a collapsed
        // `split=` on a refusal row would mean this arithmetic had been broken.
        if (req.opt == 0)
            v.splitExact = false;
        return v;
    }

    const char *PhysVerdictName(int v)
    {
        switch (v)
        {
        case (int)PhysVerdict::Healthy:          return "healthy";
        case (int)PhysVerdict::OverFragmented:  return "over-fragmented";
        case (int)PhysVerdict::Exhausted:       return "exhausted";
        case (int)PhysVerdict::DestroyedHeader: return "destroyed-header";
        default:                                 return "none";
        }
    }

    // One line of real allocator state for the physical instance, on demand. F-631 exists because
    // `w654` answered the question that mattered with the wrong instrument: its refusal row carried
    // only `size=` and `align=` -- that exe predates the current heap.cpp, whose refusal row prints
    // capacity/peak/caller_rva/glr and appears in NO log on record -- so a 120 s soak produced 8,700
    // refusals and not one byte of evidence about WHY. This is that evidence, and it reads the same
    // words `g_hdrGoldenCap` already trusts (`diagnostics.capacity` is what the F-370 guard
    // compares against, F-375 section 2: capacity is the constant at instance+0x208).
    //
    // `class_ok` is the one-word verdict F-630's method note asks for, and it is the field that
    // made w658's single row unreadable. Its old three-way reading, quoted here because it is the
    // defect this row's `verdict=` column replaces:
    //   class_ok=0 and bin_mask=0  -> EXHAUSTED: every fragment is marked used. Not corruption.
    //   class_ok=0 and bin_mask!=0 -> a fragment header was overwritten: the walk matched no
    //                                  exact-size fragment although the mask claims one exists.
    //   capacity=0                 -> DESTROYED header.
    // The SECOND arm is what the measurement refuted: w658's row is `bin_mask=0x400
    // suitable=0x0` with the header INTACT (`capacity=0x5fbffdc0` equals the golden value) and
    // the pool 99.995% full -- one 64 KB bin against a 463,296 B request is an ordinary full
    // pool, not a header overwrite, and a reader applying the old sentence would have gone
    // looking for a corrupter that does not exist. The four decidable classes, and the one
    // threshold that is the allocator's own, are in ClassifyPhysPool above; `class_ok` is kept
    // because F-630's method note names it, and `verdict=` is now the answer to read.
    // `size` is the AMOUNT handed to o1heap (payload + alignment + 32: the `o1Amount` local in
    // `Heap::AllocPhysical`, quoted by symbol because a bare line number has been measured wrong
    // on 68 % of the citations in this repo), so the class arithmetic below is o1heap's own, not
    // an approximation: o1heap rounds `amount + O1HEAP_ALIGNMENT` (o1heap.c:310) and the caller
    // has already added its own 32, so the +32 below is o1heap's and must not be counted twice.
    void PhysStateRow(size_t size, size_t align, uint64_t seq, void *callerRa)
    {
        O1HeapInstance *const h = g_userHeap.physicalHeap;
        const O1HeapDiagnostics d = HeapDiag(h);
        const uint64_t binMask = O1BinMask(h);
        const PhysClassReq req = O1ClassOf(size);
        const uint64_t cand = (req.opt < 64u) ? (~uint64_t(0) << req.opt) : 0ull;
        const uint64_t suitable = binMask & cand;
        const uint64_t smallest = suitable & ~(suitable - 1u);
        const uint32_t glr = GetPPCContext() ? static_cast<uint32_t>(GetPPCContext()->lr) : 0u;
        const bool classOk = (size > 0) && (d.capacity >= kO1HeapAlignment) &&
                             (size <= d.capacity - kO1HeapAlignment) && (smallest != 0);
        // F-638: the row now carries the CLASS and the free/capacity RATIO, not just the free
        // bytes, so a reader never has to divide two hex words by hand to learn that 0x129c0 out
        // of 0x5fbffdc0 is 4.7 ppm. `class_ok=0` alone is what made w658's single row unreadable:
        // it says the request was not served, and nothing about whether that was the pool's
        // fault. `verdict=` is the same four-class answer NotePhysVerdict prints, computed by
        // the same ClassifyPhysPool, so the two rows cannot disagree.
        const PhysVerdictRow v = ClassifyPhysPool(d, binMask, req);
        MCLA_LOG_ERROR("PHYS-STATE #{} size={:#x} align={:#x} o1_frag={:#x} class_ok={} "
                       "opt_bin={} cand_mask={:#x} suitable={:#x} smallest={:#x} bin_mask={:#x} "
                       "allocated={:#x} peak_allocated={:#x} capacity={:#x} free={:#x} "
                       "free_ppm={} verdict={} why={} split={} "
                       "pfrag={:#x} page_fits={} pow2_fits={} "
                       "peak_req={:#x} oom={} caller_rva={:#x} glr={:08X} tid={}",
                       (unsigned long long)seq, size, align, req.frag, classOk ? 1 : 0,
                       (unsigned)req.opt, cand, suitable, smallest, binMask, (uint64_t)d.allocated,
                       (uint64_t)d.peak_allocated, (uint64_t)d.capacity, v.freeBytes, v.freePpm,
                       PhysVerdictName((int)v.cls), v.why, v.splitExact ? "exact" : "collapsed",
                       // F-642: the charge the allocator ACTUALLY asked for under the page-granular
                       // policy, and both fit tests, side by side. `o1_frag` above is untouched: it is
                       // the power-of-two class and `verdict=`/`why=`/`opt_bin=` still classify against
                       // it, so build/verify_gate.py's B-3 and every other reader keep their meaning
                       // unchanged. These three fields ADD the comparison the defect is made of, and
                       // they are what makes w672's row readable as the defect it was:
                       //   o1_frag=0x80000 pfrag=0x42000 free=0x4f540 -> page_fits=1 pow2_fits=0.
                       (uint64_t)O1GranularCharge(size),
                       (v.freeBytes >= (uint64_t)O1GranularCharge(size)) ? 1u : 0u,
                       (v.freeBytes >= (uint64_t)req.frag) ? 1u : 0u,
                       (uint64_t)d.peak_request_size, (unsigned long long)d.oom_count,
                       CallerRva(callerRa), glr, GetCurrentThreadId());
    }

    // ==========================================================================================
    // T43.2: PHYS-BINPROBE -- THE SIZE WORDS THE SEARCH ACTUALLY COMPARED AGAINST.
    //
    // THE CONTRADICTION THIS EXISTS TO CLOSE, every term of it measured. `build/w743.log:30954`
    // refuses a 413-byte guest request (`size=0x19d align=0x4000 o1_amount=0x41bd`) on a pool
    // reporting `free=0x22f8000` = 34.97 MiB, and `:30955` reports `bin_mask=0x801c0`
    // `suitable=0x80000 verdict=healthy why=suitable_class_present capped_walks=0`. Those readings
    // cannot all be true of one refused allocation:
    //   * the charge is 0x5000 (`pfrag=0x5000`, `gran=4096`), so the granular search starts at
    //     log2Floor(0x5000/64) = bin 8;
    //   * `o1heapDoInvariantsHold` had just passed on this same instance (`invariants FAIL` = 0 in
    //     w743, and the gate is proven to fire -- `build/w742ctl.log:210-215`), and what it tests is
    //     exactly `(mask bit i set) == (bins[i] != NULL)` for all 64 bins (`o1heap.c:812-819`), so
    //     bit 19 set means `bins[19]` was non-NULL;
    //   * a fragment linked into bin 19 was binned there by `log2Floor(header.size / 64)`
    //     (`o1heap.c:236`), so its size is in [2^25, 2^26) = [32 MiB, 64 MiB), which satisfies a
    //     20 KiB charge outright;
    //   * `capped_walks=0` reads `d.granular_walk_capped` (`:1580`), the field the search's own
    //     post-loop check bumps (`o1heap.c:675-676`), so the hop cap did not null a found fragment;
    //   * and `free` is `d.capacity - d.allocated` (`:796`), 34.97 MiB against a 20 KiB charge.
    // The search therefore had to reach bin 19 and serve the request, and `oom=1..4` proves instead
    // that it ran to its own out-path and returned NULL (`oom_count` is bumped only there, and only
    // by the allocator that was called -- which is also what proves these rows describe the SAME
    // instance that refused, not a second healthier one).
    //
    // EVERY TERM ABOVE IS READ FROM SOURCE OR PRINTED BY THE HOST except one: the search decides on
    // `fragment->header.size`, and nothing in this tree reports a fragment's size. `allocated` is a
    // sum, `bin_mask` is a presence bitmap, and the invariant check never dereferences a fragment.
    // So `verdict=healthy` is not a wrong answer -- it is an answer to a different question. The
    // classifier models BIN PRESENCE and the granular allocator decides on SIZE WITHIN THE BIN, and
    // the gap between those two is exactly where this refusal lives. This row reads the size words.
    //
    // THREE OUTCOMES, so the row is decidable by whoever reads it and not by whoever wrote it:
    //   found_bin >= 0             -> the replay WOULD serve it from the state as it now stands, so
    //                                 the state moved between the call and the reading. Look for a
    //                                 second writer, not for a fragment defect.
    //   found_bin < 0, head_null=1 -> the mask promises a bin the array does not hold, i.e. the
    //                                 invariant gate is not running on this instance after all.
    //   found_bin < 0, every max_size < charge -> a fragment sits in a bin its own size does not
    //                                 belong to: a header that no longer matches the list it is
    //                                 linked from. `head_used=1` on the same row names the stronger
    //                                 form -- a LIVE fragment linked into a free list.
    //   probe_av=1                 -> the walk itself faulted, so the list holds an unreadable
    //                                 pointer. Stronger than any size word.
    //
    // COST AND CADENCE. Called only from the refusal printer's own `n <= 8 || (n % 100) == 0` gate
    // and with its `n`, so the two rows always pair and the cadence is the refusal cadence that is
    // already on disk -- 4 rows in w743's 300 s. The walk is bounded twice over: the replay by
    // O1HEAP_GRANULAR_MAX_HOPS (4096 links total across all bins, `o1heap.c:130`) and each census
    // bin by O1HEAP_PROBE_MAX_LINKS, so the worst case touches ~4096 fragment headers = 256 KiB.
    // It runs under `physicalMutex` like everything else on this path, which is why the bound is
    // stated rather than assumed. Allocates nothing, writes nothing to guest or arena memory, makes
    // no D3D12 call and reads no RegisterFile.
    void NotePhysBinProbe(O1HeapInstance* heap, size_t o1Amount, uint32_t n, void* callerRa,
                          const void* arenaBase, uint32_t arenaGuestBase)
    {
        O1HeapProbeResult pr{};
        pr.found_bin = -1;
        SehO1ProbeGranular(heap, o1Amount, kO1PageGranule, &pr);
        char bins[1536] = {};
        size_t off = 0;
        for (uint32_t i = 0; (i < pr.n_bins) && (i < O1HEAP_PROBE_MAX_BINS) && (off + 1 < sizeof(bins));
             ++i)
        {
            const O1HeapProbeBin& b = pr.bins[i];
            // `gva`/`aoff` are the fragment's guest VA and its offset from the arena base, which is
            // the whole point of printing the address: w744 measured head_size == 0 in both set bins
            // and a size cannot say where. F-778's guest memcpy zeroed [A0400000, A04004C0), so
            // `aoff` inside that range names the writer without a guess.
            const size_t aoff = (arenaBase != nullptr && b.head_addr >= (size_t)arenaBase)
                                    ? (b.head_addr - (size_t)arenaBase)
                                    : ~(size_t)0;
            const uint32_t gva = (aoff == ~(size_t)0) ? 0u : (uint32_t)(arenaGuestBase + aoff);
            const int w = snprintf(bins + off, sizeof(bins) - off,
                                   " b%u=[bin=%u null=%u used=%u len=%u trunc=%u n_ge=%u head=%#llx "
                                   "min=%#llx max=%#llx gva=%08X aoff=%#llx prev=%#llx next=%#llx]",
                                   i, b.bin, b.head_null, b.head_used, b.list_len, b.truncated,
                                   b.n_ge_charge, (unsigned long long)b.head_size,
                                   (unsigned long long)b.min_size, (unsigned long long)b.max_size,
                                   gva, (unsigned long long)aoff,
                                   (unsigned long long)b.head_prev,
                                   (unsigned long long)b.head_next);
            if (w <= 0 || (size_t)w >= sizeof(bins) - off)
                break;
            off += (size_t)w;
        }
        // F-784 phase 3: state the watch's counts at the same instant the damage is read, so this
        // row and the T44 arm can be checked against each other (a band that took 0 hits on a run
        // whose selftest fired is a coverage statement, not a finding).
        mcla::gpu::T44WipeTotalsLine(n);
        MCLA_LOG_ERROR("PHYS-BINPROBE #{} charge={:#x} valid={} gran_ok={} charge_ok={} start_bin={} "
                       "bits_ge_start={} hops={} cap_would_fire={} found_bin={} found_size={:#x} "
                       "probe_av={} n_bins={}{} caller_rva={:#x}",
                       n, pr.charge, pr.valid, pr.granularity_ok, pr.charge_ok, pr.start_bin,
                       pr.bits_at_or_above_start, pr.hops, pr.cap_would_fire, pr.found_bin,
                       pr.found_size, pr.probe_av, pr.n_bins, bins, CallerRva(callerRa));
    }

    // F-638: the periodic PHYS-STATE row. The old period was 10,000 refusals, and w658 refused
    // ~7,500 times in 79 s (oom=1 at 19:42:35.040 -> 7,500 at the end of the run) and printed
    // EXACTLY ONE row -- a period longer than a run's total event count is a hope, not a period.
    // The damage was not cosmetic: the last `HEAPLEAK-SUM arena=phys` row is 19:42:05.741 and
    // the first refusal is 19:42:35.040, so at the moment the pool actually filled, the most
    // recent state reading on disk was 30 s stale, and a `full -> destroyed-header` transition
    // after that point would have left NO row at all. NotePhysVerdict below covers the
    // transition EDGE; this covers the STATE HISTORY between two transitions, which is the half
    // a verdict-change-only instrument cannot see by construction.
    //
    // N = 1,000, justified from the measured rate rather than from taste:
    //   * 95 refusals/s (7,500 / 79 s) -> one row per ~10.5 s, so any 120 s soak yields 1 + 7
    //     rows at worst and the fill is bracketed to one interval -- 3x finer than the 30 s
    //     HEAPLEAK-SUM gap above (that cadence is `kAcctSummaryEvery = 20000` ALLOCATIONS, so it
    //     is not tunable from the refusal path without changing the leak summary's own meaning).
    //   * volume: 8 extra rows in w658's 1,001,196-line log is 0.0008 %, against F-054's
    //     POISONED ceiling of 66 % of a log being one repeating shape.
    //   * the head count is the house `n <= K` half of `n <= K || (n % M) == 0`: a run that
    //     dies on its 9th refusal still has 8 rows on disk, and the first refusal is the row
    //     that decides the question (unchanged contract).
    constexpr uint64_t kPhysStateEvery = 1000;
    constexpr uint64_t kPhysStateHead = 8;
    std::atomic<uint64_t> g_physStateSeq{0};

    // F-644: defined immediately below this block; declared here because `EmitPhysState` calls it
    // and the definitions are long enough that a reader arriving at the call site needs the anchor.
    void NotePhysLive(uint64_t stateSeq);

    void EmitPhysState(size_t size, size_t align, void *callerRa)
    {
        const uint64_t seq = g_physStateSeq.fetch_add(1, std::memory_order_relaxed) + 1;
        if (seq <= kPhysStateHead || (seq % kPhysStateEvery) == 0)
            PhysStateRow(size, align, seq, callerRa);
        NotePhysLive(seq);
    }

    // ==========================================================================================
    // F-644: PHYS-LIVE -- IS THE BIGGEST BLOCK STILL HELD? The question build/w675.log cannot
    // answer, stated here in the terms it would take to answer it.
    //
    // THE MEASUREMENT THAT EXISTS. `PHYS-LARGE` on every row of w675 prints
    //     max_req=0x12b80030 max_frag=0x12b81000
    // i.e. one served allocation of 314,060,592 bytes whose measured footprint was 314,060,800 =
    // 299.5 MiB = 58.5 % of the console's whole 512 MiB pool, and it was PHYS-ACCT #3 of 10,044
    // (w675.log:243, `n=3 req=354.0MB`, glr=821325D4 caller_rva=0x2a60c8, 09:18:21.901). No row in
    // the whole 1,004,592-line log carries its ADDRESS, and no row counts what references it. So
    // the block's size is known, its footprint is known, that it was never freed by the pool is
    // known -- and whether the GAME still needs it is unknowable, which is why the pool question
    // has stayed open. `page_fits=0 free=0xdc0` on `PHYS-POOL-FULL #1` is arithmetic about the
    // pool, not about the guest.
    //
    // WHAT "STILL HELD" HAS TO MEAN, and why one number decides it. A live reservation and a leak
    // are indistinguishable from inside the allocator: both are a fragment with `used == true` and
    // an `allocated` that never came back, and this tree never had a free path that ran (w675 has
    // eight `PHYS-FREE` arrivals and no ninth, all before the storm). They differ in exactly one
    // observable: WHETHER ANY 32-BIT GUEST-VISIBLE WORD STILL NAMES THE BLOCK'S GUEST ADDRESS. The
    // guest is 32-bit and this pool is identity-mapped into its flat window (`MapVirtual` inverts
    // `Translate`, so a physical pointer the guest holds IS a guest VA -- the `guest=` field on
    // PHYS-FREE prints 0xB7321280, inside this pool's own extent, as a matter of course). So the
    // guest's own structures hold the address, and counting them is the same technique used on the
    // title's 256-slot dictionary: read guest memory, do not ask the host.
    //
    //     guest_refs == 0  and  freed == 0   ->  a LEAK: nothing in the guest names it and nothing
    //                                            ever released it. The bytes are unrecoverable and
    //                                            the pool is short by this block's size.
    //     guest_refs >= 1                    ->  LIVE: the game still holds the address, and the
    //                                            pool's occupancy is the price of the game running.
    //     freed == 1                         ->  RELEASED: o1heapFree ran on it, so `allocated` moved
    //                                            and the block is not what is filling the pool.
    //
    // `pool_refs` is separated from `guest_refs` for a reason that is a false-positive trap, not a
    // nicety: the pool's own 299.5 MiB of PAYLOAD is guest data (a texture, a mesh, an audio bed),
    // and a 32-bit word in 299 MiB of unstructured data hits any given value by chance roughly
    // 299e6/2^32 = 0.07 times -- small, but a single hit would make a leak look live. A hit FOUND
    // INSIDE the pool is a physical-to-physical reference, which is not evidence that the guest owns
    // the block, so it is counted separately and never counted into the decision. Note the direction
    // of that test: it is the hit's own address, never the target's -- the target is a physical
    // address and is inside the pool by construction, so testing the target would classify every hit
    // as pool-internal and hold `guest_refs` at zero for the whole run.
    //
    // WHY IT IS A SWEEP AND NOT A LOOKUP. Nothing in this tree knows where the guest keeps its
    // pointers -- that is the question -- so a pass still covers the whole 4 GiB window, for the
    // exact 32-bit value, 8 bytes at a time (low and high dword of each aligned 64-bit word, which
    // finds every 4-byte-aligned word once instead of twice). T43.1c (F-791) REORDERED the visit so
    // the regions where a holder can live are scanned first -- image, boot stack, pool, user heap,
    // then the remaining gaps, table beside `kPhysLiveRegions` -- a pass's coverage unchanged, only
    // its order; and corrected the word read to BIG-ENDIAN (`be` below: `memory.cpp:221-222` loads
    // raw then Swap32's), without which the compare ran against the byte-REVERSED value -- 276 rows
    // across 10 logs, every one zero, none of them a statement about the block. `sweep_ppm` on the
    // row is the fraction of the window covered in the CURRENT pass and `complete=` says whether the
    // answer is final; a partial row is explicitly not an answer and says so in its own field.
    //
    // COST, STATED SO IT IS NOT DISCOVERED (re-measured by T43.1c, F-791: the old numbers here
    // described a cadence and a stop the code never had). The emission is PER REFUSAL -- the
    // cadence gate in `EmitPhysState` guards `PhysStateRow` only; `NotePhysLive` is called
    // unconditionally, so w755's 256 refusals produced 256 rows -- and it runs while
    // `Heap::AllocPhysical` holds `std::lock_guard lock(physicalMutex)` to its return. Measured
    // (F-783 §7): 256 MiB per emission = ~41 ms at ~6.2 GB/s = 166 ms injected across four refusals
    // in w743, 10.9 s across w755's whole refusal era -- the instrument was perturbing the thing it
    // measures. T43.1c drops the budget to 16 MiB (`kPhysLiveBudget`, quoted by symbol) = ~2.6 ms
    // per emission, and 256 rows x 16 MiB = exactly one 4 GiB pass. The sweep does NOT stop when a
    // pass completes (w755 ran 16 of them), and `ctl=` is the rule-19 positive control (dwords
    // quoted beside `kPhysLiveCtlOri`): image memory that never yields one is an instrument fault.
    // Nothing here allocates, frees, writes to the guest, or changes a return value.

    // F-638: the verdict-change edge, on the refusal path AND the free path. This is the row
    // that would have caught F-630's own misreading live -- the verdict column is what says
    // "exhausted" instead of "destroyed" -- and it costs one diagnostics copy on those paths
    // only. It is now request-aware, because `over-fragmented` and `healthy` are only decidable
    // against a size class: with no class in hand there is nothing for `suitable` to be 0 with.
    //
    // THE CALLER THAT LIES IS NAMED IN ITS OWN COMMENT. heap.cpp's free path passes amount==0
    // and its verdict can only be a POOL-level one; w658's single row for the whole run came
    // from exactly there (caller_rva=0x253313, `DestroyKernelObject+0x133`, 19:41:16.087,
    // refusals=0) -- 79 s BEFORE the first refusal, on a pool that was not full yet. A verdict
    // printed once, from the free path, with no request class, is not evidence about the pool
    // the refusals happened on. Hence the class fallback below and the periodic row above.
    std::atomic<int> g_physVerdict{-1};  // -1 = no verdict printed yet
    std::atomic<uint32_t> g_physLastOpt{0};      // class of the last REFUSED request

    void NotePhysVerdict(size_t amount, void *callerRa)
    {
        O1HeapInstance *const h = g_userHeap.physicalHeap;
        if (h == nullptr)
            return;
        const O1HeapDiagnostics d = HeapDiag(h);
        const uint64_t binMask = O1BinMask(h);
        // amount == 0 is the free path's "no request of its own": fall back to the class of the
        // last refusal, the only class the pool has been asked to serve and failed. 0 (nothing
        // ever refused) means class 0, and the split is then reported `collapsed`.
        PhysClassReq req;
        if (amount != 0)
        {
            req = O1ClassOf(amount);
            g_physLastOpt.store(req.opt, std::memory_order_relaxed);
        }
        else
        {
            req = {kFragmentSizeMin, g_physLastOpt.load(std::memory_order_relaxed)};
        }
        const PhysVerdictRow v = ClassifyPhysPool(d, binMask, req);
        const int verdict = (int)v.cls;
        const int prev = g_physVerdict.exchange(verdict, std::memory_order_relaxed);
        if (verdict == prev)
            return;
        MCLA_LOG_ERROR("PHYS-VERDICT-CHANGE {} -> {} why={} split={} refusals={} req_amt={:#x} "
                       "req_class={} req_frag={:#x} bin_mask={:#x} suitable={:#x} free={:#x} "
                       "free_ppm={} allocated={:#x} peak_allocated={:#x} capacity={:#x} "
                       "oom={} caller_rva={:#x}",
                       prev < 0 ? "none" : PhysVerdictName(prev), PhysVerdictName(verdict), v.why,
                       v.splitExact ? "exact" : "collapsed",
                       (unsigned long long)g_physStateSeq.load(std::memory_order_relaxed), amount,
                       (unsigned)req.opt, v.reqFrag, binMask, v.suitable, v.freeBytes, v.freePpm,
                       (uint64_t)d.allocated, (uint64_t)d.peak_allocated, (uint64_t)d.capacity,
                       (unsigned long long)d.oom_count, CallerRva(callerRa));
    }

    // =====================================================================================
    // F-640: IS THE CONSOLE'S POOL IN FORCE, AND WHAT DID IT COST? The refusal path already knows
    // everything this needs -- `PHYS-STATE` classifies the pool, `PHYS-VERDICT-CHANGE` catches the
    // edge, `AllocPhysical: o1heapAllocate returned null` prints a sample -- and none of them can
    // answer the question the 512 MiB cap actually raises: with the pool 2.992x smaller, a refusal
    // is no longer only a signal about a guest leak, it is also THE CONSOLE'S OWN ANSWER. So
    // refusals have to be countable separately from the accidents, and counted by SIZE, because
    // "the pool is full" and "this request could never have fit in 512 MiB of RAM" are different
    // claims with different consequences.
    //
    // FOUR CLASSES, and the split is DERIVED, not fitted. `ClassifyPhysPool` (quoted by symbol, not
    // by line) already partitions every refusal into four using only the allocator's own
    // arithmetic, and this adds ONE predicate on top, pure arithmetic over the constant:
    //   over_cap   req.frag > pool capacity. The request's OWN power-of-two fragment is larger than
    //              all of the console's RAM, so it is unservable under ANY state on ANY host and
    //              the console returns 0. This is the refusal that was impossible to observe before
    //              and is the whole point: `peak_req=0x12b80030` (measured, w662 PHYS-STATE) rounds
    //              to a 0x20000000 fragment = 512.0 MiB = THE ENTIRE POOL for one allocation, and
    //              under the old 1,532 MiB pool it silently succeeded. A SUBSET of `exhausted`,
    //              reported as a breakdown of it, never as a fifth class.
    //   exhausted  free < one request class (heap.cpp's own threshold, free < 64<<opt). The pool is
    //              out of room. THE CONSOLE'S REFUSAL. The one that gets the size buckets.
    //   over_frag  free bytes exist but no run of the class does (`free_but_no_suitable_class`).
    //              Counted separately and NOT bucketed: the console would refuse this too, but for
    //              a different reason, and lumping the two would make a 512 MiB cap look like a
    //              fragmentation regression when it is not.
    //   destroyed  capacity unusable. A FAULT, not a refusal of the console's pool. Counted, never
    //              bucketed, never presented as exhaustion.
    //   class_present  (F-643) the pool still had a bin at or above the requested class when it
    //              refused, so the refusal came from the page-granular SCAN, not from capacity. The
    //              reference charges a whole page for these too (xboxkrnl_memory.cc:364), so this is
    //              the console's own refusal and NOT a fault. Counted separately, never bucketed,
    //              and -- until F-643 -- silently filed under `destroyed`, which is how 96 % of one
    //              run's refusals were reported as a corrupted arena that never existed.
    //
    // ATTEMPTS AND OUTCOMES ARE SEPARATE COUNTERS, because the ratio between them is the only
    // honest denominator: a pool that refuses 400 of 40,000 attempts is 1 % refused, and a pool
    // that refuses 400 of 400 is dead. One number cannot say which.
    //
    // CADENCE: `seq <= kPhysPoolHead || (seq % kPhysPoolEvery) == 0`, K=8, M=200 -- the house
    // pattern. (F-638 derived 1,000 for PHYS-STATE from a measured 95 refusals/s; this row is 5x
    // coarser because a 512 MiB pool refuses far less often than a 1.5 GiB one.) Every row is the
    // whole CUMULATIVE tally, not a delta, so the last row before a crash carries the full account.
    constexpr uint64_t kPhysPoolHead = 8;
    constexpr uint64_t kPhysPoolEvery = 200;
    // Size buckets on the REQUEST, by the same power-of-two ladder o1heap bins by, with the top
    // bucket deliberately open-ended: b4 is "bigger than 32 MiB", i.e. the class of requests that on
    // the console can only be a whole-RAM reservation or an outright impossibility.
    constexpr size_t kPhysPoolBucketEdges[5] = {0x10000u,   0x80000u, 0x400000u,
                                                0x2000000u, (size_t)-1};
    constexpr const char* kPhysPoolBucketNames[5] = {"le64K", "le512K", "le4M", "le32M", "gt32M"};
    static_assert(kPhysPoolBucketEdges[4] == (size_t)-1, "the top bucket must be open-ended");

    struct PhysPoolCounters
    {
        std::atomic<uint64_t> attempts{0};  // requests handed to o1heap for the physical pool
        std::atomic<uint64_t> served{0};    // outcomes: non-null
        std::atomic<uint64_t> refused{0};   // outcomes: null
        std::atomic<uint64_t> overCap{0};   // frag > capacity: unservable at any state
        std::atomic<uint64_t> exhausted{0};  // free < one request class: the console's refusal
        std::atomic<uint64_t> overFrag{0};   // free bytes, but no suitable run
        std::atomic<uint64_t> destroyed{0};  // capacity unusable: a fault, not a refusal
        // F-643: `destroyed` counted the WRONG CLASS for a whole run, and the name was innocent.
        // The switch in NotePhysPoolFull had no `case PhysVerdict::Healthy`, and `Healthy` is the
        // enum's ZERO value, so every refusal the classifier called "healthy" fell into `default:`
        // -- the arm commented "DestroyedHeader: a fault" -- and incremented `destroyed`. Measured
        // on build/w675.log: 97,446 of 101,600 refusals landed there, while the string
        // "verdict=destroyed-header" occurs ZERO times in 1,004,592 lines, `F370-HEAP-HDR` occurs
        // ZERO times, and PHYS-POOL-FULL #1 reads `destroyed=1 ... verdict=healthy` on ONE row.
        // `destroyed` was a per-refusal tally of the healthiest possible reading.
        // THIS COUNTER IS THE POPULATION IT WAS COUNTING, correctly named: a refusal taken while
        // the pool still had a bin at or above the requested power-of-two class (`suitable != 0`),
        // i.e. the refusal came from the page-granular SCAN and not from the pool's capacity. Under
        // F-642's page policy that is the expected refusal, not a fault: a bin of 2048 B is present
        // while the request's page charge is 0x1000, and the reference charges a whole page too
        // (xboxkrnl_memory.cc:364). It was 96 % of w675's refusals and had no name at all.
        std::atomic<uint64_t> classPresent{0};
        std::atomic<uint64_t> bucket[5]{};   // `exhausted` by request-size bucket
        std::atomic<uint64_t> maxReq{0};     // largest single request REFUSED
        std::atomic<uint64_t> maxFrag{0};    // the fragment that request would have consumed
        // F-641: the mirror of the two above, for SUCCESSES. `max_refused` alone cannot answer "was
        // a legal request served", which is the question a boot gate asks, and the two are read
        // together: a run whose `max_served` never approaches `max_refused` is a run where the pool
        // is refusing everything large, whatever the verdict column says.
        std::atomic<uint64_t> maxServedReq{0};   // largest single request SERVED
        std::atomic<uint64_t> maxServedFrag{0};  // the fragment it MEASUREDLY occupied
        // F-641: THE NAMED COUNTER FOR THE EXACT DEFECT. `roundedOverPool` counts requests refused
        // because the power-of-two charge exceeded the whole pool (`o1_frag > capacity`) AT A MOMENT
        // WHEN THE FREE BYTES WERE SUFFICIENT (`capacity - allocated >= amount`). That conjunction is
        // the bug to the byte -- a legal request refused while the pool held it -- so it gets its own
        // name instead of being inferable from `over_cap` plus `free_ppm` on two different rows. After
        // the large path exists it must read 0; a non-zero value on a soak is the whole defect back.
        std::atomic<uint64_t> roundedOverPool{0};
        // F-641: the fixed-granularity large path, counted on its own so the inflation is a MEASURED
        // number instead of an inference from the allocator's source. `largeReq`/`largeCharged` are
        // cumulative bytes so `large_ppm` is a ratio over every large request the run served, and
        // `largeMaxReq`/`largeMaxFrag` are the largest single one and what it actually cost -- the
        // pair a reader needs to check "the console would have charged 299.5 MiB" against.
        std::atomic<uint64_t> largeServed{0};
        std::atomic<uint64_t> largeRefused{0};
        std::atomic<uint64_t> largeReq{0};
        std::atomic<uint64_t> largeCharged{0};
        std::atomic<uint64_t> largeMaxReq{0};
        std::atomic<uint64_t> largeMaxFrag{0};
        std::atomic<uint64_t> seq{0};
        // F-642: THE COUNTER FOR "A REQUEST WAS REFUSED WHILE A PAGE-ROUNDED BLOCK WOULD HAVE FIT".
        // This is the gate field, and it is NOT `roundedOverPool`: that counter requires
        // `o1_frag > capacity`, and build/w672.log's fatal request had `o1_frag = 0x80000` against
        // `cap_o1 = 0x1ffffdc0`, so `over_cap = 0` and `rounded_over_pool = 0` on the one row that
        // IS the defect (w672.log:44589). The defect's real shape is a RELATIVE one -- the power-of-two
        // charge exceeded the FREE BYTES while the page charge did not -- and that is what this
        // counts: refused && pageCharge <= free && pow2Class > free. Under F-642's policy this can no
        // longer happen (every such request is routed to the page path), so a non-zero value on a
        // soak means the routing did not take effect. When the page charge does NOT fit either, the
        // pool genuinely has no room and the refusal is the console's own, so the two cases stay
        // separable on the same row: `granfit_missed` counts the first, `full`/`over_frag` the second.
        std::atomic<uint64_t> granfitMissed{0};
        // F-642: THE CORRECTED ACCOUNTING, cumulative over every SERVED physical allocation, so the
        // question "what would these requests have cost under the reference's own rounding?" is
        // answered by a number in the log instead of by an extrapolation from a 32-row sample.
        // `pageReq` is the sum of the o1heap amounts and `pageCharge` the sum of the charges actually
        // taken out of the fragment headers, so `page_over_req_ppm` is the inflation as a RATIO and
        // `pageCharge` is the footprint itself -- the two numbers the soak gate reads. `pageN` is the
        // count, so `pageCharge / pageN` is the mean charge and a reader never has to divide by the
        // `served` counter (which counts BOTH policies and would double-count under a mixed policy).
        std::atomic<uint64_t> pageN{0};
        std::atomic<uint64_t> pageReq{0};
        std::atomic<uint64_t> pageCharge{0};
        std::atomic<uint64_t> pagePow2{0};
        // F-644: WHAT THE CONSOLE WOULD HAVE CHARGED FOR THE SAME REQUESTS, and the residue
        // between the two. Nothing in the tree could produce this before, which is why the question
        // "is any charge left that the console would not make?" had to be answered by reading four
        // files instead of by reading a number. The comparator is the reference's own rule and
        // nothing else: `MmAllocatePhysicalMemoryEx_entry` computes
        // `adjusted_size = xe::round_up(region_size, page_size)` with page_size = 4 KiB
        // (.research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_memory.cc:364, default page_size at
        // :356), `PhysicalHeap::AllocRange` re-rounds to the same granule
        // (.research/xenia/src/xenia/memory.cc:1466, size at :1473) and `BaseHeap::AllocRange`
        // reduces it to a PAGE COUNT (memory.cc:924) whose only size precondition is that enough
        // pages exist (memory.cc:934). No size class, no per-request header, no alignment term.
        // `conCharge` is therefore `round_up(guestSize, 4096)` summed over the same requests, and
        // `resid = charge - conCharge` is EVERY byte this pool charges that the console would not.
        // It is expected to be small and positive (the host pays `alignment + 2*O1HEAP_ALIGNMENT`
        // per request -- see the `o1Amount` local in `Heap::AllocPhysical`, quoted by symbol) and
        // its per-million form `over_console_ppm` is the number that settles the accounting.
        std::atomic<uint64_t> conCharge{0};      // sum of round_up(guestSize, kO1PageGranule)
        std::atomic<uint64_t> conSize{0};        // sum of the guest's own `size` argument
        std::atomic<uint64_t> alignBytes{0};     // host-only: the caller's alignment term
        std::atomic<uint64_t> hdrBytes{0};       // host-only: the two O1HEAP_ALIGNMENT terms
        // F-644: BYTES THE POOL ACTUALLY GAVE BACK. Measured on build/w675.log:
        // `page_charge` 545,484,800 minus `allocated` 0x1FFFF000 = 536,866,816 is 8,617,984 =
        // 8.22 MiB that o1heapFree returned, while `PHYS-FREE` printed 8 rows and NO row carries a
        // byte total (its own comment says so: "No size field on purpose ... The byte accounting is
        // `HEAPLEAK-SUM nfree/freed`", and `HEAPLEAK-SUM` fires every 20,000 events so it printed
        // twice, at nalloc=1 and nalloc=2). So on the one run where the question mattered, 8.22 MiB
        // of releases existed and were unattributable. This counter closes that gap and costs one
        // relaxed add on the free path.
        std::atomic<uint64_t> physFreedBytes{0};
        // F-644: THE BIGGEST BLOCK THE POOL EVER SERVED, by GUEST ADDRESS. `maxServedReq` and
        // `maxServedFrag` (both above) already record its size; neither records WHERE it is, and
        // without an address no liveness question about it can be posed -- which is the whole of
        // F-644's Task 1. Set once, on the served path, under the same lock that already bumps the
        // two maxima.
        std::atomic<uint64_t> bigGuest{0};   // guest VA of the aligned user pointer
        std::atomic<uint64_t> bigFrag{0};    // its MEASURED footprint (FragFootprint of the raw ptr)
        std::atomic<uint64_t> bigSize{0};    // the guest's own request size
        std::atomic<uint64_t> bigSeq{0};     // which PHYS-ACCT allocation number it was
        std::atomic<uint32_t> bigGlr{0};     // the guest lr that asked for it
        std::atomic<uint64_t> bigRva{0};     // the host caller_rva that asked for it
        std::atomic<uint64_t> bigFreed{0};   // 1 once o1heapFree ran on THAT fragment
        // F-642: the emission counter for `PHYS-ACCT`. Separate from `seq` (which is the refusal
        // snapshot's) because the accounting must be reportable on a run with ZERO refusals, which is
        // exactly the run this change is trying to produce.
        std::atomic<uint64_t> acctSeq{0};
    };
    PhysPoolCounters g_physPool;

    // The maximum is a CAS loop on its own field, not a load-then-store: two guest threads refusing
    // a large request at once must not let the smaller one win and hide the 299.5 MiB case.
    void PhysPoolBumpMax(std::atomic<uint64_t>& slot, uint64_t v)
    {
        uint64_t cur = slot.load(std::memory_order_relaxed);
        while (v > cur && !slot.compare_exchange_weak(cur, v, std::memory_order_relaxed))
        {
        }
    }

    // ATTEMPT, on the way IN, before o1heap is asked, so `attempts` is a true denominator and
    // cannot be skewed by the refusal path's own sampling cadence.
    inline void NotePhysAttempt()
    {
        g_physPool.attempts.fetch_add(1, std::memory_order_relaxed);
    }

    inline void NotePhysServed()
    {
        g_physPool.served.fetch_add(1, std::memory_order_relaxed);
    }

    // F-642: PHYS-ACCT -- the CORRECTED ACCOUNTING, on the success path, so it is reportable on a run
    // with no refusals at all. Every row the refusal path prints is a snapshot of a pool that
    // FAILED; this row reports what a run actually cost, and it is the row a soak gate reads for
    // "the served allocations' corrected footprint".
    //
    // WHY A NEW ROW AND NOT A FIELD ON HEAPLEAK-SUM. That row's cadence is 20,000 ALLOCATIONS
    // (kAcctSummaryEvery, quoted by symbol in the EmitPhysState comment above) and w672 made 6,691
    // physical allocations in total, so it printed TWICE for this arena -- which is exactly why only
    // 32 of the run's 6,691 request sizes are anywhere in the log, and why the arithmetic in the
    // F-642 policy block had to be extrapolated from a 32-row sample. A cadence that cannot fire
    // inside the run it describes cannot instrument this question. `PHYS-POOL-FULL` is no better: it
    // prints only when the pool refuses, and a run that works has none.
    //
    // CADENCE: the house `n <= K || (n % M) == 0` shape, K = 4 and M = 2000. w672's 6,691
    // allocations give 4 + 3 = 7 rows (~0.0007% of its 956,623 lines, against F-054's POISONED
    // ceiling of 66%) and a longer run stays at the same ratio. K = 4 because the first four
    // allocations are where `over_req_ppm` first shows whether the granule is being applied at all:
    // a routing that silently failed reads ~1.5 there, which is the whole point of printing it early.
    //
    // THE FIELDS. `req` is the cumulative sum of o1heap amounts; `charge` the cumulative sum of the
    // fragment footprints MEASURED back out of the headers (never the predicted value -- the rule
    // `NotePhysLarge` and `PhysPoolBumpMax(maxServedFrag)` already follow). `pow2_would_be` is what
    // those same requests would have charged under the rule this change replaced, from the same two
    // expressions the allocator uses, so the row states its own counterfactual instead of leaving a
    // reader to reconstruct it; `recovered` is the difference, and it is the number the finding turns
    // on. `pow2_would_be` is a MODEL of the replaced rule and is labelled `would_be` for that reason:
    // the only measured charge on this row is `charge`.
    void NotePhysAcct(size_t amount, size_t measuredFrag, size_t guestSize, size_t alignment,
                      void *callerRa)
    {
        const uint64_t seq = g_physPool.acctSeq.fetch_add(1, std::memory_order_relaxed) + 1;
        const uint64_t n = g_physPool.pageN.fetch_add(1, std::memory_order_relaxed) + 1;
        const uint64_t pow2 = O1RoundUpPow2(amount + kO1HeapAlignment);
        const uint64_t sreq = g_physPool.pageReq.fetch_add(amount, std::memory_order_relaxed) + amount;
        const uint64_t schg =
            g_physPool.pageCharge.fetch_add(measuredFrag, std::memory_order_relaxed) + measuredFrag;
        const uint64_t spow =
            g_physPool.pagePow2.fetch_add(pow2, std::memory_order_relaxed) + pow2;
        // F-644: THE CONSOLE'S OWN CHARGE FOR THIS REQUEST, and the residue. `O1ConsoleCharge`
        // (quoted by symbol, defined beside `kO1PageGranule`) is the reference's rule and nothing
        // else, so `resid = measuredFrag - con` is every byte this pool charged that the console's
        // allocator would not have, for THIS request -- not on average, and not estimated.
        const uint64_t con = O1ConsoleCharge(guestSize);
        const uint64_t scon = g_physPool.conCharge.fetch_add(con, std::memory_order_relaxed) + con;
        g_physPool.conSize.fetch_add(guestSize, std::memory_order_relaxed);
        g_physPool.alignBytes.fetch_add(alignment, std::memory_order_relaxed);
        // TWO O1HEAP_ALIGNMENT terms, and both are named: the `+ O1HEAP_ALIGNMENT` inside the
        // `o1Amount` local in `Heap::AllocPhysical` (the room for the two bookkeeping words written
        // at `aligned-8` and `aligned-16`) and the `amount + O1HEAP_ALIGNMENT` inside
        // `o1heapAllocateGranular`'s charge (o1heap.c:547). Counted as a formula, not a literal,
        // so it cannot drift if either site changes.
        g_physPool.hdrBytes.fetch_add(2u * (uint64_t)kO1HeapAlignment, std::memory_order_relaxed);
        const uint64_t resid = (measuredFrag > con) ? (uint64_t)(measuredFrag - con) : 0ull;
        if (seq > 4 && (seq % 2000) != 0)
            return;
        // F-806b, CORRECTED: a `HeapGuardWindow` was briefly added here on the theory that this
        // reporter was the F-388 reader. It is not -- `Heap::AllocPhysical` opens its own window at
        // :3340 (function scope), so this read was already covered and the added guard was pure
        // nesting depth. The real reader is `MmAllocatePhysicalMemoryEx`'s failure path,
        // `imports.cpp:4973`, which runs AFTER that window closes. Reverted here on purpose.
        const O1HeapDiagnostics d = HeapDiag(g_userHeap.physicalHeap);
        const uint64_t free = (d.capacity > d.allocated) ? (d.capacity - d.allocated) : 0ull;
        MCLA_LOG_WARN("PHYS-ACCT #{} policy=page granule={:#x} n={} req={:.1f}MB charge={:.1f}MB "
                      "pow2_would_be={:.1f}MB recovered={:.1f}MB over_req_ppm={} "
                      "live={:.1f}MB cap={:.1f}MB free={:.1f}MB used_ppm={} "
                      "oom={} capped_walks={} refusals={} glr={:08X} caller_rva={:#x} "
                      "con_charge={:.1f}MB over_console_ppm={} resid={}B "
                      "align_bytes={} hdr_bytes={} freed_bytes={} big_guest={:08X} big_frag={:#x}",
                      (unsigned long long)seq, (uint64_t)kO1PageGranule, (unsigned long long)n,
                      (double)sreq / 1048576.0, (double)schg / 1048576.0, (double)spow / 1048576.0,
                      (double)(spow - schg) / 1048576.0,
                      (sreq != 0) ? (unsigned long long)((schg * 1000000ull) / sreq) : 0ull,
                      (double)d.allocated / 1048576.0, (double)d.capacity / 1048576.0,
                      (double)free / 1048576.0,
                      (d.capacity != 0)
                          ? (unsigned long long)((d.allocated * 1000000ull) / (uint64_t)d.capacity)
                          : 0ull,
                      (unsigned long long)d.oom_count, (unsigned long long)d.granular_walk_capped,
                      (unsigned long long)g_physPool.refused.load(std::memory_order_relaxed),
                      GetPPCContext() ? static_cast<uint32_t>(GetPPCContext()->lr) : 0u,
                      CallerRva(callerRa),
                      // F-644: THE TASK-2 NUMBER. `over_console_ppm` = charge / con_charge per
                      // million, so 1,000,000 means this pool charges exactly what the reference's
                      // page rounding charges, and every 1,000 above it is a byte the console would
                      // not have asked for. `resid` is that same excess on the LAST request alone
                      // (it is 0 for every request whose size is already a whole number of pages,
                      // which is why the cumulative figure is the one to read).
                      (double)scon / 1048576.0,
                      (scon != 0) ? (unsigned long long)((schg * 1000000ull) / scon) : 0ull,
                      (unsigned long long)resid,
                      g_physPool.alignBytes.load(std::memory_order_relaxed),
                      g_physPool.hdrBytes.load(std::memory_order_relaxed),
                      g_physPool.physFreedBytes.load(std::memory_order_relaxed),
                      g_physPool.bigGuest.load(std::memory_order_relaxed),
                      g_physPool.bigFrag.load(std::memory_order_relaxed));
    }

    // F-641: THE GRANULAR-PATH TALLY. Called with the o1heap `amount` and the CHARGE the granular
    // path rounded it to, plus the fragment footprint MEASURED back out of the header the allocator
    // just wrote (never the predicted value) once the request was served. `fragOverReqPpm` is the
    // inflation the power-of-two rule used to impose, expressed per million: for w665's 0x12B80030
    // request it was 1,709,072 ppm and it is 1,000,203 ppm after the fix, which is the whole
    // difference between the pool that could not answer and the console that could.
    struct LargeRow
    {
        uint64_t req = 0;     // the o1heap amount, i.e. what PHYS-STATE prints as `size`
        uint64_t charge = 0;  // roundUp(amount + 32, 4096): what the large path asks the arena for
        uint64_t frag = 0;    // MEASURED from the returned fragment header (0 on a refusal)
        bool served = false;
    };

    void NotePhysLarge(const LargeRow &r, void *callerRa)
    {
        const uint64_t seq = g_physPool.largeServed.load(std::memory_order_relaxed) +
                             g_physPool.largeRefused.load(std::memory_order_relaxed) + 1;
        if (r.served)
        {
            g_physPool.largeServed.fetch_add(1, std::memory_order_relaxed);
            g_physPool.largeReq.fetch_add(r.req, std::memory_order_relaxed);
            g_physPool.largeCharged.fetch_add(r.charge, std::memory_order_relaxed);
            PhysPoolBumpMax(g_physPool.largeMaxReq, r.req);
            PhysPoolBumpMax(g_physPool.largeMaxFrag, r.frag);
        }
        else
        {
            g_physPool.largeRefused.fetch_add(1, std::memory_order_relaxed);
        }
        // House cadence: the first 4 (this path fires a handful of times per boot, and each one is a
        // decision the reader wants to see), then every 64th. A soak that never reaches the large
        // path prints no row, which is itself the answer.
        if (seq > 4 && (seq % 64) != 0)
            return;
        const uint64_t sumReq = g_physPool.largeReq.load(std::memory_order_relaxed);
        const uint64_t sumChg = g_physPool.largeCharged.load(std::memory_order_relaxed);
        // F-806b, CORRECTED: a guard here was redundant for the same reason as at :1502 -- see
        // the note there. The instance read is already inside `Heap::AllocPhysical`'s window.
        const O1HeapDiagnostics d = HeapDiag(g_userHeap.physicalHeap);
        const uint64_t free = (d.capacity > d.allocated) ? (d.capacity - d.allocated) : 0ull;
        MCLA_LOG_WARN("PHYS-LARGE #{} path=granular granule={:#x} outcome={} req={:#x} charge={:#x} "
                      "frag={:#x} req_over_frag_ppm={} cum_req={} cum_charge={} cum_over_ppm={} "
                      "served={} refused={} max_req={:#x} max_frag={:#x} "
                      "pow2_class={:#x} class_over_cap={} free={:#x} cap={:#x} alloc={:#x} "
                      "capped_walks={} glr={:08X} caller_rva={:#x}",
                      (unsigned long long)seq, (uint64_t)kO1PageGranule,
                      r.served ? "served" : "refused", r.req, r.charge, r.frag,
                      (r.req != 0 && r.frag != 0)
                          ? (unsigned long long)((r.req * 1000000ull) / r.frag)
                          : 0ull,
                      (unsigned long long)sumReq, (unsigned long long)sumChg,
                      (sumReq != 0) ? (unsigned long long)((sumChg * 1000000ull) / sumReq) : 0ull,
                      (unsigned long long)g_physPool.largeServed.load(std::memory_order_relaxed),
                      (unsigned long long)g_physPool.largeRefused.load(std::memory_order_relaxed),
                      g_physPool.largeMaxReq.load(std::memory_order_relaxed),
                      g_physPool.largeMaxFrag.load(std::memory_order_relaxed),
                      O1RoundUpPow2(r.req + kO1HeapAlignment),
                      (d.capacity != 0 && O1RoundUpPow2(r.req + kO1HeapAlignment) > (size_t)d.capacity)
                          ? 1u
                          : 0u,
                      free, (uint64_t)d.capacity, (uint64_t)d.allocated,
                      (unsigned long long)d.granular_walk_capped,
                      GetPPCContext() ? static_cast<uint32_t>(GetPPCContext()->lr) : 0u,
                      CallerRva(callerRa));
    }

    // F-641: `CheckGranularBlock` is defined below, next to `ProbeReasonName` and `FragFootprint`
    // (it calls both) and immediately before `Heap::IsLiveAllocation` (it calls that too). It is
    // declared here only so this namespace reads top-down; the definition carries the reasoning.
    void CheckGranularBlock(const char *phase, size_t amount, size_t charge, void *rawPtr,
                            uint8_t *arenaBase, size_t arenaSize, O1HeapInstance *heap, void *callerRa);
    std::atomic<uint32_t> g_granBad{0};

    // F-640: the refusal snapshot. `amount` is the `o1Amount` -- the same value PHYS-STATE and
    // PHYS-VERDICT-CHANGE are handed -- so all three rows classify one request identically and no
    // reader has to reconcile them. The capacity on the row is the LIVE o1heap one, not
    // `PhysArenaSizeBytes()`, because the question a census asks of this row is what the pool
    // ACTUALLY had; the two differ by o1heap's 0x240 of header, so `model=cap_model` sits beside
    // it and the constant is on every row.
    void NotePhysPoolFull(size_t amount, void* callerRa)
    {
        O1HeapInstance *const h = g_userHeap.physicalHeap;
        const O1HeapDiagnostics d = HeapDiag(h);
        const PhysClassReq req = O1ClassOf(amount);
        const PhysVerdictRow v = ClassifyPhysPool(d, O1BinMask(h), req);
        const bool overCap = (d.capacity != 0) && (req.frag > (size_t)d.capacity);
        // F-641: THE NAMED COUNTER, decided here because both facts are in hand at one place: the
        // power-of-two class is larger than the WHOLE pool, AND the bytes for the request itself were
        // free. `amount` is the o1heap amount (payload + alignment + 32) -- the same quantity the
        // allocator was asked for -- so the free-space test is against that and not against the
        // inflated class, which is the whole point: a refusal satisfying this conjunction is the
        // defect to the byte, not a tight pool. It is a subset of `overCap`, never a fifth class, and
        // it must read 0 on any soak that gets past this.
        if (overCap && (d.capacity > d.allocated) &&
            (v.freeBytes >= (uint64_t)(amount + kO1HeapAlignment)))
        {
            g_physPool.roundedOverPool.fetch_add(1, std::memory_order_relaxed);
        }
        // F-642: THE COUNTER THAT ACTUALLY FIRES ON w672's FATAL, and the reason `roundedOverPool`
        // did not. That counter needs `o1_frag > capacity`; w672's refused request had
        // `o1_frag = 0x80000` against `cap_o1 = 0x1ffffdc0` (w672.log:44589), so it read 0 on the one
        // row that IS the defect. The defect is not "the class exceeds the whole pool" -- it is "the
        // power-of-two charge exceeded the FREE BYTES while the page charge, which is what the
        // reference would have asked for, did not". Both facts are already in hand here, so the test
        // is two charges compared against `v.freeBytes` and nothing else:
        //     page charge 0x42000 = 270,336 <= free 0x4f540 = 324,928  -> the pool HAD the room
        //     pow2  class 0x80000 = 524,288  >  free 0x4f540 = 324,928  -> and was told it did not
        // `pfrag`/`page_fits` are printed so that conjunction is checkable by hand from the row, which
        // is what turns "the counter says 0" into "and here is the arithmetic that says why".
        const size_t pfrag = O1GranularCharge(amount);
        const bool pageFits = (v.freeBytes >= (uint64_t)pfrag);
        if (pageFits && (v.freeBytes < (uint64_t)req.frag))
        {
            g_physPool.granfitMissed.fetch_add(1, std::memory_order_relaxed);
        }

        g_physPool.refused.fetch_add(1, std::memory_order_relaxed);
        switch (v.cls)
        {
            case PhysVerdict::Exhausted:
                g_physPool.exhausted.fetch_add(1, std::memory_order_relaxed);
                if (overCap)
                    g_physPool.overCap.fetch_add(1, std::memory_order_relaxed);
                for (unsigned b = 0; b < 5; ++b)
                {
                    if (amount <= kPhysPoolBucketEdges[b])
                    {
                        g_physPool.bucket[b].fetch_add(1, std::memory_order_relaxed);
                        break;
                    }
                }
                PhysPoolBumpMax(g_physPool.maxReq, amount);
                PhysPoolBumpMax(g_physPool.maxFrag, req.frag);
                break;
            case PhysVerdict::OverFragmented:
                g_physPool.overFrag.fetch_add(1, std::memory_order_relaxed);
                break;
            // F-643: THE MISSING ARM, and it was the largest population in the run. `Healthy` is the
            // enum's ZERO value and this switch had no case for it, so it took `default:` -- the arm
            // whose comment says "DestroyedHeader: a fault" -- and `destroyed` counted a pool whose
            // capacity word reads CORRECTLY and whose class is SERVABLE. build/w675.log measures the
            // cost of that: `destroyed=97446` against `refused=101600` and `verdict=destroyed-header`
            // 0 occurrences in the whole log, on the same row as `verdict=healthy` (PHYS-POOL-FULL #1).
            // A counter whose name asserts a fault that is not occurring is the defect; the name
            // `destroyed` stays CORRECT for the fault, and this arm is what makes it mean that again.
            // It is deliberately NOT bucketed: these refusals are the granular scan's, and their size
            // profile is the console's page rounding, not a property of the pool's exhaustion.
            case PhysVerdict::Healthy:
                g_physPool.classPresent.fetch_add(1, std::memory_order_relaxed);
                break;
            // Unreachable while the enum has four values and all four are named above. It stays, and
            // it stays a FAULT bucket, so an unclassified reading is never silently dropped (F-054's
            // lesson: a counter that quietly stops counting looks exactly like a counter at zero).
            default:  // DestroyedHeader: a fault. Counted, never presented as a refusal of RAM.
                g_physPool.destroyed.fetch_add(1, std::memory_order_relaxed);
                break;
        }

        const uint64_t seq = g_physPool.seq.fetch_add(1, std::memory_order_relaxed) + 1;
        if (seq > kPhysPoolHead && (seq % kPhysPoolEvery) != 0)
            return;
        const uint64_t mreq = g_physPool.maxReq.load(std::memory_order_relaxed);
        const uint64_t mfrag = g_physPool.maxFrag.load(std::memory_order_relaxed);
        // F-641: THE TWO NEW FIELD GROUPS, both appended, both BEFORE `req_class=` so that the
        // `verdict= glr= caller_rva=` tail of the row is byte-identical to every row on record -- any
        // reader anchoring on that tail keeps working, and no existing field or value changes.
        //   rounded_over_pool  the named counter above. THE GATE FIELD: a non-zero value is this
        //                      defect, by name, in one field.
        //   max_served/_frag   the largest request this pool actually served, and what it cost. Before
        //                      the large path these two are unreachable for anything near the pool
        //                      size, which is exactly why a run could not distinguish "refused
        //                      because it is big" from "refused because the rule cannot say big".
        //   large_*            the fixed-granularity path's own tally, with the inflation as
        //                      `large_over_req_ppm` (cumulative charge/request, per million) so the
        //                      1.709x that the power-of-two rule charged is a number in the log.
        const uint64_t sumLgReq = g_physPool.largeReq.load(std::memory_order_relaxed);
        const uint64_t sumLgChg = g_physPool.largeCharged.load(std::memory_order_relaxed);
        MCLA_LOG_ERROR("PHYS-POOL-FULL #{} model=console-512MiB cap_model={:#x} cap_o1={:#x} "
                       "attempts={} served={} refused={} full={} over_cap={} over_frag={} "
                       "destroyed={} class_present={} "
                       "buckets=[{}={} {}={} {}={} {}={} {}={}] max_refused={:#x} "
                       "max_refused_frag={:#x} frag_of_cap_ppm={} rounded_over_pool={} "
                       "max_served={:#x} max_served_frag={:#x} gran={} large_served={} "
                       "large_refused={} large_req={} large_charge={} large_over_req_ppm={} "
                       "large_max_req={:#x} large_max_frag={:#x} gran_bad={} capped_walks={} "
                       "granfit_missed={} pfrag={:#x} page_fits={} "
                       "page_n={} page_req={:.1f}MB page_charge={:.1f}MB "
                       "page_pow2_would_be={:.1f}MB page_over_req_ppm={} "
                       "con_charge={:.1f}MB over_console_ppm={} resid={}B "
                       "align_bytes={} hdr_bytes={} freed_bytes={} big_guest={:08X} big_frag={:#x} "
                       "big_freed={} big_seq={} "
                       "req_class={} free={:#x} "
                       "verdict={} glr={:08X} caller_rva={:#x}",
                       (unsigned long long)seq, (uint64_t)mcla::kernel::kConsolePhysicalBytes,
                       (uint64_t)d.capacity,
                       g_physPool.attempts.load(std::memory_order_relaxed),
                       g_physPool.served.load(std::memory_order_relaxed),
                       g_physPool.refused.load(std::memory_order_relaxed),
                       g_physPool.exhausted.load(std::memory_order_relaxed),
                       g_physPool.overCap.load(std::memory_order_relaxed),
                       g_physPool.overFrag.load(std::memory_order_relaxed),
                       g_physPool.destroyed.load(std::memory_order_relaxed),
                       // F-643: the population the missing `case Healthy` used to file under
                       // `destroyed=`. Placed beside it, and before `req_class=`, so the
                       // `verdict= glr= caller_rva=` tail stays byte-identical to every row on record.
                       g_physPool.classPresent.load(std::memory_order_relaxed),
                       kPhysPoolBucketNames[0],
                       g_physPool.bucket[0].load(std::memory_order_relaxed),
                       kPhysPoolBucketNames[1],
                       g_physPool.bucket[1].load(std::memory_order_relaxed),
                       kPhysPoolBucketNames[2],
                       g_physPool.bucket[2].load(std::memory_order_relaxed),
                       kPhysPoolBucketNames[3],
                       g_physPool.bucket[3].load(std::memory_order_relaxed),
                       kPhysPoolBucketNames[4],
                       g_physPool.bucket[4].load(std::memory_order_relaxed), mreq, mfrag,
                       (d.capacity != 0)
                           ? (unsigned long long)((mfrag * 1000000ull) / (uint64_t)d.capacity)
                           : 0ull,
                       g_physPool.roundedOverPool.load(std::memory_order_relaxed),
                       g_physPool.maxServedReq.load(std::memory_order_relaxed),
                       g_physPool.maxServedFrag.load(std::memory_order_relaxed),
                       (uint64_t)kO1PageGranule,
                       (unsigned long long)g_physPool.largeServed.load(std::memory_order_relaxed),
                       (unsigned long long)g_physPool.largeRefused.load(std::memory_order_relaxed),
                       (unsigned long long)sumLgReq, (unsigned long long)sumLgChg,
                       (sumLgReq != 0)
                           ? (unsigned long long)((sumLgChg * 1000000ull) / sumLgReq)
                           : 0ull,
                       g_physPool.largeMaxReq.load(std::memory_order_relaxed),
                       g_physPool.largeMaxFrag.load(std::memory_order_relaxed),
                       (unsigned)g_granBad.load(std::memory_order_relaxed),
                       (unsigned long long)d.granular_walk_capped,
                       // F-642: the counter that fires on w672's fatal, and the two numbers that
                       // produce it. `page_*` are the same cumulative accounting PHYS-ACCT prints,
                       // repeated here because a reader who has reached a refusal row should not
                       // have to hunt for a second row to learn what the run cost.
                       (unsigned long long)g_physPool.granfitMissed.load(std::memory_order_relaxed),
                       (uint64_t)pfrag, pageFits ? 1u : 0u,
                       (unsigned long long)g_physPool.pageN.load(std::memory_order_relaxed),
                       (double)g_physPool.pageReq.load(std::memory_order_relaxed) / 1048576.0,
                       (double)g_physPool.pageCharge.load(std::memory_order_relaxed) / 1048576.0,
                       (double)g_physPool.pagePow2.load(std::memory_order_relaxed) / 1048576.0,
                       (g_physPool.pageReq.load(std::memory_order_relaxed) != 0)
                           ? (unsigned long long)((g_physPool.pageCharge.load(std::memory_order_relaxed) *
                                                   1000000ull) /
                                                  g_physPool.pageReq.load(std::memory_order_relaxed))
                           : 0ull,
                       // F-644: THE TASK-2 NUMBERS ON THE REFUSAL ROW TOO, so a reader who reaches a
                       // refusal does not have to find a PHYS-ACCT row to learn what this pool charges
                       // against what the console charges -- `over_console_ppm` is that ratio and
                       // `resid` is the excess in bytes. `big_guest`/`big_frag`/`big_freed` are the
                       // address and the fate of the largest served block, which is the one PHYS-LIVE
                       // sweeps the guest window for.
                       (double)g_physPool.conCharge.load(std::memory_order_relaxed) / 1048576.0,
                       (g_physPool.conCharge.load(std::memory_order_relaxed) != 0)
                           ? (unsigned long long)((g_physPool.pageCharge.load(std::memory_order_relaxed) *
                                                   1000000ull) /
                                                  g_physPool.conCharge.load(std::memory_order_relaxed))
                           : 0ull,
                       (g_physPool.pageCharge.load(std::memory_order_relaxed) >
                        g_physPool.conCharge.load(std::memory_order_relaxed))
                           ? (unsigned long long)(g_physPool.pageCharge.load(std::memory_order_relaxed) -
                                                  g_physPool.conCharge.load(std::memory_order_relaxed))
                           : 0ull,
                       g_physPool.alignBytes.load(std::memory_order_relaxed),
                       g_physPool.hdrBytes.load(std::memory_order_relaxed),
                       g_physPool.physFreedBytes.load(std::memory_order_relaxed),
                       g_physPool.bigGuest.load(std::memory_order_relaxed),
                       g_physPool.bigFrag.load(std::memory_order_relaxed),
                       g_physPool.bigFreed.load(std::memory_order_relaxed),
                       (unsigned long long)g_physPool.bigSeq.load(std::memory_order_relaxed),
                       (unsigned)req.opt, (uint64_t)v.freeBytes, PhysVerdictName((int)v.cls),
                       GetPPCContext() ? static_cast<uint32_t>(GetPPCContext()->lr) : 0u,
                       CallerRva(callerRa));
    }

    constexpr uint32_t kPhysLiveHits = 8;
    constexpr uint64_t kPhysLiveChunk = 1ull << 20;    // 1 MiB scratch, one memcpy per step
    // T43.1c (F-791): 16 MiB per row, was 256 MiB. F-783 §7 measured the 256 MiB emission at
    // ~41 ms under `physicalMutex` (w743: four refusals = 166 ms of guest-blocked time; w755:
    // 256 emissions = 10.9 s of its refusal era), i.e. the instrument was perturbing the thing it
    // measures. 16 MiB at that same measured 6.2 GB/s is ~2.6 ms per emission, and 256 rows x
    // 16 MiB = exactly one 4 GiB pass, so a w755-class refusal count still completes a pass.
    constexpr uint64_t kPhysLiveBudget = 16ull << 20; // 16 MiB of window per PHYS-LIVE row
    // T43.1c (F-791): POSITIVE CONTROL (LONG_TODO §1 rule 19 -- a zero is not a result until the
    // instrument is shown firing on an event you know happened). Two dwords measured in
    // `build/cache/mcla_pe.bin` (offset = VA - 0x82000000, rule 3): the DOS `MZ` word at image
    // base, and `ori r9,r8,0x6772` = raw `61 28 67 72` at offset 0x18C848 = VA 0x8218C848 -- the
    // raw bytes re-read for this change, and UNIQUE in the whole image file (one occurrence), so
    // `ctl` counts exactly the controls plus chance (299 MiB/2^32 ~ 0.07 expected). Both sit in
    // region 0 of the visit order, which fits inside emission #1's 16 MiB budget, so from row #1
    // onward `ctl == 0` means the sweep cannot see image memory -- a property of the instrument,
    // not of the block. Before this control existed the sweep had never once been seen positive.
    constexpr uint32_t kPhysLiveCtlMz = 0x4D5A9000u;   // mcla_pe.bin[0x0:0x4] = 4D 5A 90 00
    constexpr uint32_t kPhysLiveCtlOri = 0x61286772u;  // mcla_pe.bin[0x18C848] = 61 28 67 72
    // F-782: THE SWEEP'S FIRST BYTE, and the reason this constant exists. Guest VA 0 is a
    // deliberate PAGE_NOACCESS null guard (`kNullGuardBytes`, armed in memory.cpp), and this sweep
    // reads the window with a raw `base + pos` instead of through `Translate`/`IsValid`, so a
    // cursor starting at 0 faulted on the very first 1 MiB chunk -- in every boot, deterministically.
    // Measured cost: `PHYS-LIVE` printed 0 rows in all 313 logs on disk, `NotePhysVerdict` and
    // `NotePhysPoolFull` were unreachable on the alloc-refusal path because `EmitPhysState` threw
    // inside `NotePhysLive` before returning, and one of the five C0000005s per boot was ours while
    // the VEH labelled it `guest AV` off a sticky lr. Skipping the guard loses no signal: nothing
    // can legitimately live at a guest VA the guard exists to make unreadable.
    constexpr uint64_t kPhysLiveStart = mcla::kernel::kNullGuardBytes;
    // T43.1c (F-791): THE VISIT ORDER. The nine regions are disjoint and their union is exactly
    // [kPhysLiveStart, 4 GiB), so a pass still covers the whole window once -- only the ORDER
    // changed: where a holder of the block's address can plausibly live is scanned first, the dead
    // space after it. Region 0 is the image (globals + both control dwords, inside emission #1);
    // region 1 is the boot worker's execution stack (boot_host.cpp:1041-1043: StackTop 0x8F000000,
    // StackSize 0x200000 -> [0x8E000000, 0x8F000000), plus ThreadBlock 0x8F200000 at :1071 --
    // restated here because those are function-local constants; w755's dominant sp cluster
    // 0x8EFFFFxx proves this stack is live); region 2 is the pool itself -> `pool_refs`; region 3
    // is the user heap -> guest thread stacks / PCR / TLS blocks (w755's second sp cluster
    // 0x006Dxxxx sits in it; guest thread blocks are g_userHeap allocations, boot_host.cpp:1876);
    // regions 4-8 are the remaining gaps in ascending order for completeness. The T43.1c row
    // proposed scanning [0x80000000, 0xC0400000) first -- regions 0-2 plus gaps 5-7 cover it -- but
    // that window alone would EXCLUDE the user heap the live thread stacks sit in, so the heap is
    // added as region 3 rather than left to the gaps.
    struct PhysLiveRegion
    {
        uint64_t lo, hi;
    };
    static constexpr PhysLiveRegion kPhysLiveRegions[] = {
        { PPC_IMAGE_BASE, PPC_IMAGE_BASE + PPC_IMAGE_SIZE },                     // image: globals + ctl dwords
        { 0x8E000000ull, 0x8F400000ull },                                       // boot stack + thread block
        { mcla::kernel::kPhysArenaBeginVa, mcla::kernel::kPhysArenaEndVa },     // the pool -> pool_refs
        { mcla::kernel::kUserHeapArenaVa, mcla::kernel::kUserHeapArenaEnd },    // guest stacks/PCR/TLS -> guest_refs
        { kPhysLiveStart, mcla::kernel::kUserHeapArenaVa },                     // gap: guard .. user heap
        { mcla::kernel::kUserHeapArenaEnd, PPC_IMAGE_BASE },                    // gap: user heap .. image
        { PPC_IMAGE_BASE + PPC_IMAGE_SIZE, 0x8E000000ull },                     // gap: image .. boot stack (incl. func table)
        { 0x8F400000ull, mcla::kernel::kPhysArenaBeginVa },                     // gap: boot statics .. pool
        { mcla::kernel::kPhysArenaEndVa, 0x100000000ull },                      // gap: pool .. top of window
    };
    std::atomic<uint64_t> g_physLiveRefs{0};
    std::atomic<uint64_t> g_physLivePoolRefs{0};
    std::atomic<uint64_t> g_physLiveCtl{0};  // T43.1c (F-791): pass accumulator for the control dwords
    std::atomic<uint64_t> g_physLivePass{0};
    std::atomic<uint64_t> g_physLiveHits[kPhysLiveHits]{};
    std::atomic<uint32_t> g_physLiveNHits{0};

    void NotePhysLive(uint64_t stateSeq)
    {
        const uint64_t g = g_physPool.bigGuest.load(std::memory_order_relaxed);
        if (g == 0 || g > 0xFFFFFFFFull)
            return;  // nothing large has been served yet, or the address is not a guest VA
        const uint32_t target = (uint32_t)g;
        const uint8_t *const base = mcla::kernel::GuestMemoryHeap::Instance().Base();
        const uint64_t winSz = mcla::kernel::GuestMemoryHeap::Instance().Size();
        if (base == nullptr || winSz < 8)
            return;

        // THE REGISTRY ANSWER, which is free and needs no sweep: the host's own set of live
        // physical pointers (`LivePhysAllocs`, the set `Heap::Free` erases from) still holding an
        // entry inside this block means the host has never released it, and 0 means it has --
        // independently of o1heap's own `used` bit, which survives across a free by construction
        // (o1heap.c:626-628 sets it, `o1heapFree` clears it, but `Heap::Free`'s validate-before-free
        // can return without ever reaching o1heap, and this set is what that path touches).
        // Read under `physicalMutex`, which the caller (`Heap::AllocPhysical`) already holds and
        // which is the only writer's lock, so the iteration needs no lock of its own.
        const uint64_t frag = g_physPool.bigFrag.load(std::memory_order_relaxed);
        uint64_t regHit = 0, regTotal = 0;
        for (const void *p : LivePhysAllocs())
        {
            regTotal++;
            // T43.1c (F-791): the set stores HOST pointers -- `aligned` in `Heap::AllocPhysical`
            // (uintptr_t arithmetic on the o1heap return, inserted by `LivePhysAllocs().insert`)
            // -- and the old code compared that raw 64-bit host address against the guest-VA
            // target: a range check no in-window host pointer can enter unless the window's host
            // base is pathologically low, so `reg_hit=0` was STRUCTURAL, not a reading (w755's
            // `reg_hit=0 reg_total=4949` said nothing about release).
            // `MapVirtual` is the bounds-checked host->guest inverse: memory.cpp:492-497 returns 0
            // for anything outside the window, and 0 can never fall inside
            // [target, target+frag).
            const uint64_t pv = mcla::kernel::g_memory.MapVirtual(p);
            if (pv >= target && pv < (target + (frag != 0 ? frag : 1ull)))
                regHit++;
        }

        static std::atomic<uint64_t> cursor{kPhysLiveRegions[0].lo};  // position inside the CURRENT region
        static std::atomic<uint32_t> cursorRgn{0};  // index into kPhysLiveRegions the cursor belongs to
        static std::atomic<uint64_t> sweptFor{0};  // which block the cursor's coverage belongs to
        static std::atomic<uint64_t> passScanned{0};  // bytes covered in the CURRENT pass (sweep_ppm's numerator)
        constexpr uint32_t kRgnN = (uint32_t)(sizeof(kPhysLiveRegions) / sizeof(kPhysLiveRegions[0]));
        if (sweptFor.load(std::memory_order_relaxed) != g)
        {
            // A NEW BIGGEST BLOCK. Coverage and tallies measured for the previous block are not
            // coverage of this one, so they are discarded rather than carried -- a partial sweep of
            // the wrong block presented as a partial sweep of the right one would make a leak look
            // like a block nobody had scanned yet, which is the failure this whole row exists to
            // avoid.
            cursorRgn.store(0, std::memory_order_relaxed);
            cursor.store(kPhysLiveRegions[0].lo, std::memory_order_relaxed);
            sweptFor.store(g, std::memory_order_relaxed);
            g_physLiveRefs.store(0, std::memory_order_relaxed);
            g_physLivePoolRefs.store(0, std::memory_order_relaxed);
            g_physLiveCtl.store(0, std::memory_order_relaxed);
            g_physLivePass.store(0, std::memory_order_relaxed);
            g_physLiveNHits.store(0, std::memory_order_relaxed);
            passScanned.store(0, std::memory_order_relaxed);
        }
        uint32_t rgn = cursorRgn.load(std::memory_order_relaxed);
        uint64_t pos = cursor.load(std::memory_order_relaxed);
        uint64_t scanned = 0, refs = 0, poolRefs = 0, ctl = 0;
        uint64_t hits[kPhysLiveHits];
        uint32_t nHits = 0;
        static uint8_t chunk[kPhysLiveChunk];
        const uint64_t poolLo = mcla::kernel::kPhysArenaBeginVa;
        const uint64_t poolHi = mcla::kernel::kPhysArenaEndVa;
        bool complete = false;
        // T43.1c (F-791): BIG-ENDIAN, or the sweep sees nothing. Guest words in the window are
        // stored big-endian -- `ReadU32BE` (memory.cpp:221-222) host-loads raw and Swap32's, same
        // formula inlined here because `GuestMemoryHeap::Swap32` is private -- so the old raw host
        // load compared against the byte-REVERSED numeric target and could never match a real
        // pointer: 276 PHYS-LIVE rows across 10 logs, all zero, before this line existed.
        const auto be = [](uint32_t v) {
            return ((v & 0xFFu) << 24) | ((v & 0xFF00u) << 8) | ((v >> 8) & 0xFF00u) | (v >> 24);
        };

        while (scanned < kPhysLiveBudget)
        {
            const PhysLiveRegion &R = kPhysLiveRegions[rgn];
            const uint64_t hi = (R.hi < winSz) ? R.hi : winSz;
            if (pos < R.lo)
                pos = R.lo;  // defensive snap; the cursor is initialised at a region base
            if ((pos + 8) > hi)
            {
                // Region boundary: advance, exactly as the old code stepped from the window end
                // back to kPhysLiveStart (F-782: never at 0 -- that is the null guard).
                rgn++;
                if (rgn == kRgnN)
                {
                    rgn = 0;
                    pos = kPhysLiveRegions[0].lo;
                    complete = true;
                    break;
                }
                pos = kPhysLiveRegions[rgn].lo;
                continue;
            }
            const uint64_t room = hi - pos;
            const uint64_t n = (room < kPhysLiveChunk) ? room : kPhysLiveChunk;
            std::memcpy(chunk, base + pos, (size_t)n);
            for (uint64_t off = 0; (off + 8) <= n; off += 8)
            {
                uint64_t w;
                std::memcpy(&w, chunk + off, sizeof(w));
                const uint32_t d[2] = {be((uint32_t)w), be((uint32_t)(w >> 32))};
                for (unsigned k = 0; k < 2; ++k)
                {
                    if (d[k] == target)
                    {
                        refs++;
                        // CLASSIFIED BY WHERE THE REFERENCE WAS FOUND, not by what it points at. The
                        // target is always inside the pool -- it is a physical address -- so testing the
                        // target here would file every hit under `pool_refs` and leave `guest_refs`
                        // permanently zero, which is exactly the "a counter that quietly stops counting
                        // looks like a counter at zero" failure. A hit whose OWN address lies in the
                        // pool is a physical-to-physical reference and is not evidence the guest owns
                        // the block; a hit anywhere else is the guest's own structure naming it.
                        const uint64_t at = pos + off + (uint64_t)k * 4u;
                        if (at >= poolLo && at < poolHi)
                            poolRefs++;
                        if (nHits < kPhysLiveHits)
                            hits[nHits++] = at;
                    }
                    else if (d[k] == kPhysLiveCtlMz || d[k] == kPhysLiveCtlOri)
                        ctl++;  // T43.1c (F-791): the positive control, counted wherever scanned
                }
            }
            pos += n;
            scanned += n;
        }
        // A budget exhausted exactly on a region boundary advances now, so the wrap (and any
        // region change) is reported on the ROW THAT CAUSED IT rather than one row late.
        if (!complete)
        {
            const PhysLiveRegion &R = kPhysLiveRegions[rgn];
            const uint64_t hi = (R.hi < winSz) ? R.hi : winSz;
            if ((pos + 8) > hi)
            {
                rgn++;
                if (rgn == kRgnN)
                {
                    rgn = 0;
                    pos = kPhysLiveRegions[0].lo;
                    complete = true;
                }
                else
                    pos = kPhysLiveRegions[rgn].lo;
            }
        }
        // WRAP, AND REPORT THE WRAP. A pass that reaches the end of the LAST region starts again
        // at region 0 (F-782: never at 0 -- that is the null guard; region 0 is the image) and
        // counts a new pass, so `sweep_ppm` below is always "coverage of the CURRENT pass" and
        // a reader never mistakes pass 2's first 10 % for a completed answer. (`complete` itself
        // was decided by the loop and the boundary advance above.)
        uint64_t pass = g_physLivePass.load(std::memory_order_relaxed);
        uint64_t showRefs, showPoolRefs, showCtl;
        if (complete)
        {
            pass++;
            g_physLivePass.store(pass, std::memory_order_relaxed);
            // A completed pass is the ANSWER, so its tallies are the tallies that matter. Publish
            // the FINISHED pass (accumulated so far, plus this emission) on the wrap row, then
            // zero the running ones: the next pass measures the same question again and a
            // cumulative total across passes would double-count every word in the window. T43.1c
            // (F-791): the old code stored THIS emission's `refs` alone here, silently discarding
            // the pass -- invisible before F-791 only because every count was zero for the
            // byte-order reason above.
            showRefs = g_physLiveRefs.load(std::memory_order_relaxed) + refs;
            showPoolRefs = g_physLivePoolRefs.load(std::memory_order_relaxed) + poolRefs;
            showCtl = g_physLiveCtl.load(std::memory_order_relaxed) + ctl;
            g_physLiveRefs.store(0, std::memory_order_relaxed);
            g_physLivePoolRefs.store(0, std::memory_order_relaxed);
            g_physLiveCtl.store(0, std::memory_order_relaxed);
            passScanned.store(0, std::memory_order_relaxed);
        }
        else
        {
            g_physLiveRefs.fetch_add(refs, std::memory_order_relaxed);
            g_physLivePoolRefs.fetch_add(poolRefs, std::memory_order_relaxed);
            g_physLiveCtl.fetch_add(ctl, std::memory_order_relaxed);
            passScanned.fetch_add(scanned, std::memory_order_relaxed);
            showRefs = g_physLiveRefs.load(std::memory_order_relaxed);
            showPoolRefs = g_physLivePoolRefs.load(std::memory_order_relaxed);
            showCtl = g_physLiveCtl.load(std::memory_order_relaxed);
        }
        cursorRgn.store(rgn, std::memory_order_relaxed);
        cursor.store(pos, std::memory_order_relaxed);

        uint32_t n = g_physLiveNHits.load(std::memory_order_relaxed);
        for (uint32_t i = 0; i < nHits && n < kPhysLiveHits; ++i)
            g_physLiveHits[n++].store(hits[i], std::memory_order_relaxed);
        g_physLiveNHits.store(n, std::memory_order_relaxed);

        MCLA_LOG_ERROR("PHYS-LIVE #{} state_seq={} block_guest={:08X} frag={:#x} size={:#x} "
                       "alloc_seq={} caller_rva={:#x} glr={:08X} freed={} reg_hit={} reg_total={} "
                       "guest_refs={} pool_refs={} ctl={} scanned={:.1f}MB sweep_ppm={} complete={} pass={} "
                       "hits={} hit0={:08X} hit1={:08X} hit2={:08X}",
                       (unsigned long long)stateSeq, (unsigned long long)stateSeq, target, frag,
                       g_physPool.bigSize.load(std::memory_order_relaxed),
                       (unsigned long long)g_physPool.bigSeq.load(std::memory_order_relaxed),
                       g_physPool.bigRva.load(std::memory_order_relaxed),
                       g_physPool.bigGlr.load(std::memory_order_relaxed),
                       g_physPool.bigFreed.load(std::memory_order_relaxed),
                       (unsigned long long)regHit, (unsigned long long)regTotal,
                       (unsigned long long)showRefs,
                       (unsigned long long)showPoolRefs,
                       (unsigned long long)showCtl,
                       (double)scanned / 1048576.0,
                       (winSz != 0)
                           ? (unsigned long long)((passScanned.load(std::memory_order_relaxed) * 1000000ull) /
                                                  winSz)
                           : 0ull,
                       complete ? 1u : 0u, (unsigned long long)pass,
                       g_physLiveNHits.load(std::memory_order_relaxed),
                       g_physLiveHits[0].load(std::memory_order_relaxed),
                       g_physLiveHits[1].load(std::memory_order_relaxed),
                       g_physLiveHits[2].load(std::memory_order_relaxed));
    }

    // `CallerRva` used to be defined here and was MOVED above the SEH block, unchanged, so the
    // o1heap wrappers could publish it (it sits below them in the file). Every call site in this
    // namespace resolves to that one internal function.

    void CheckHeapHeader(const char *phase, size_t reqSize, O1HeapInstance *h, void *callerRa)
    {
        if (h == nullptr || g_hdrGoldenCap == 0)
            return;
        // O1HeapInstance is opaque in the public header, so the fields come through the
        // diagnostics copy. Which memory that is matters: `capacity` sits at instance+0x208
        // (F-375 Â§2), so this is NOT the first-40-bytes window the raw dump below reads --
        // those 40 bytes are the free-bin pointers `bins[0..4]`.
        const O1HeapDiagnostics d = HeapDiag(h);
        if (d.capacity == g_hdrGoldenCap && d.allocated <= g_hdrGoldenCap &&
            d.peak_allocated <= g_hdrGoldenCap)
            return;
        static std::atomic<uint32_t> s_hdrBad{0};
        const uint32_t n = s_hdrBad.fetch_add(1) + 1;
        if (n <= 8 || (n % 500) == 0)
        {
            uint32_t glr = 0;
            if (const PPCContext *c = GetPPCContext())
                glr = static_cast<uint32_t>(c->lr);
            MCLA_LOG_ERROR("F370-HEAP-HDR #{} phase={} subj={:#x} cap={:#x} want_cap={:#x} "
                           "used={:#x} peak={:#x} oom={} hdr_off={:#x} glr={:08X} caller_rva={:#x}",
                           n, phase, reqSize, d.capacity, g_hdrGoldenCap, d.allocated,
                           d.peak_allocated, static_cast<unsigned long long>(d.oom_count),
                           g_hdrArena ? static_cast<unsigned>(reinterpret_cast<uint8_t *>(h) -
                                                                   g_hdrArena)
                                      : 0u,
                           glr, CallerRva(callerRa));
            // F-373: "the header is garbage" has two very different causes, and the fix is
            // opposite: (i) somebody wrote over guest 0x20000, or (ii) the host pointer we
            // captured at Init is stale because the mapping behind 0x20000 moved, so we are
            // reading a page that is no longer the heap. Re-Translate and read the instance's
            // first 40 bytes through the checked path: if the mapping moved, `retrans` says so
            // directly. NOTE (F-375 Â§2, which retired F-373's own conclusion): those 40 bytes are
            // `bins[0..4]`, NOT the `capacity`/`used`/`peak` words the test above compared, which
            // sit at instance +0x208 -- so `hex=` and `cap=` never describe the same fields and a
            // disagreement between them is not a broken reader.
            // The physical-arena compare is a free needle test -- if the two headers match, the
            // "corruption" is a copy of the other heap and the writer names itself.
            auto &gm = mcla::kernel::GuestMemoryHeap::Instance();
            void *re = gm.Translate(mcla::kernel::kUserHeapArenaVa);
            uint8_t raw[40] = {};
            const bool got = gm.ReadBytes(mcla::kernel::kUserHeapArenaVa, raw, static_cast<uint32_t>(sizeof(raw)));
            uint8_t phys[40] = {};
            const bool gotPhys =
                gm.ReadBytes(mcla::kernel::kPhysArenaBeginVa, phys, static_cast<uint32_t>(sizeof(phys)));
            char hex[sizeof(raw) * 2 + 1] = {};
            char asc[sizeof(raw) + 1] = {};
            for (size_t k = 0; k < sizeof(raw); ++k)
            {
                std::snprintf(&hex[k * 2], 3, "%02x", raw[k]);
                asc[k] = (raw[k] >= 32 && raw[k] < 127) ? static_cast<char>(raw[k]) : '.';
            }
            asc[sizeof(raw)] = 0;
            MCLA_LOG_ERROR("F373-HEAP-RAW #{} phase={} base={:p} retrans={:p} moved={} "
                           "read_ok={} phys_read_ok={} phys_same={} hex={} ascii='{}'",
                           n, phase, (void *)g_hdrArena, re, re != (void *)g_hdrArena, got,
                           gotPhys, got && gotPhys && std::memcmp(raw, phys, sizeof(raw)) == 0,
                           hex, asc);
        }
    }
} // namespace

// ---- leak census (READ-ONLY) ----------------------------------------------------------------
// WHY: `__xtl_free` (src/kernel/imports.cpp:61) is a deliberate no-op that returns 1, so EVERY
// guest XTL allocation is un-reclaimable and the physical arena can only grow. `w654` (2026-09-28
// 18:14) measured the consequence: `AllocPhysical: o1heapAllocate returned null` reaches #8700
// (the row prints every 100th, so 8700+ refusals) against a 0x5FC00000 = 1.494 GiB arena, while
// the ONLY consumer that was being counted -- PHYS-CENSUS, src/kernel/imports.cpp:2056-2070 --
// accounts for 46 MB. The gap is the two consumers nobody measured: `__xtl_alloc` ->
// GuestMemoryHeap::Alloc (src/kernel/memory.cpp:334-344) and the host xdm.h:53 object path. So the
// leak rate is not merely unmeasured, the arena is demonstrably full and the refill question has
// no answer in any log to date.
//
// WHAT IS COUNTED, AND IN WHICH UNIT. All byte sums are the o1heap FRAGMENT FOOTPRINT, read from
// the fragment header on the alloc side and from the same header via the live probe on the free
// side, so the two sides subtract exactly (o1heap rounds every fragment to a power of two,
// src/kernel/o1heap.c:310 -- requested bytes and footprint are different units and must never be
// subtracted from each other). Requested bytes are kept as a separate, never-subtracted column so
// the rounding blowup stays visible. Nothing here allocates, frees, or changes a decision.
namespace
{
    struct ArenaAcct
    {
        std::atomic<uint64_t> events{0};     // alloc+free operations; drives the summary row
        std::atomic<uint64_t> nAlloc{0};
        std::atomic<uint64_t> nFree{0};
        std::atomic<uint64_t> reqBytes{0};   // cumulative bytes the callers asked for
        std::atomic<uint64_t> fragBytes{0};  // cumulative footprint handed out
        std::atomic<uint64_t> freeBytes{0};  // cumulative footprint handed back
        std::atomic<uint64_t> liveBytes{0};  // handed out minus handed back: the leak
        std::atomic<uint64_t> peakLive{0};
        std::atomic<uint64_t> nullAlloc{0};  // honest OOM refusals
        std::atomic<uint64_t> rejFree{0};    // frees refused by validate-before-free
    };
    ArenaAcct g_acct[2];

    // House style for a probe cadence: the first rows always, then a bounded repeat (the
    // `n <= K || n % M` convention every probe in this file already uses).
    constexpr uint64_t kAcctSummaryEvery = 20000;

    inline double AcctMb(uint64_t b)
    {
        return static_cast<double>(b) / (1024.0 * 1024.0);
    }

    // The bytes a live pointer occupies in its arena: the `size` field of the o1heap fragment
    // header 32 bytes below the pointer o1heap returned (FragHeaderProbe, above). Valid only while
    // the fragment is live, which is exactly when the census reads it.
    size_t FragFootprint(const void *livePtr)
    {
        const auto *hdr = reinterpret_cast<const FragHeaderProbe *>(
            static_cast<const uint8_t *>(livePtr) - kO1HeapAlignment);
        return hdr->size;
    }

    // ---- F-639: per-caller ALLOCATION census (READ-ONLY) -------------------------------------
    //
    // THE QUESTION THIS EXISTS TO ANSWER, and why the two existing instruments could not answer it.
    // `w661.log` (2026-09-29 07:34:57, 789,867 lines, 0 crashes) ends the physical arena at
    // nalloc=79,782 nfree=219, and the brief for F-639 asked which allocation path has no matching
    // free. The two instruments already in this file both fail to answer that, for DIFFERENT and
    // individually fatal reasons, and both reasons are visible in w661 with nothing added:
    //
    //   1. `HEAPLEAK-SUM` is a per-ARENA total. It counts 79,782 allocations and 219 frees and
    //      says nothing about which of the callers produced either number. A ratio of two
    //      arena-wide totals cannot name a caller, and the ratio's own sign is uninterpretable
    //      while the pool is nearly full (verify_gate.py B-8 says this in its own row).
    //   2. `RecordSite`/`HeapSite` is a RING of the LAST kSiteSlots=8 requests (quoted by symbol
    //      above). It is an attribution-of-last-resort for the moment an arena dies; a ring has no
    //      counts, so 8 slots cannot answer a question about 79,782 events.
    //   3. AND THE ONE THAT INVALIDATES THE OBVIOUS FIX: the caller_rva already in every refusal
    //      row and in `HEAPLEAK-SUM last_site_rva` CANNOT separate the XTL path from anything
    //      else on the physical arena, and this is measurable, not suspected. `RecordSite` is
    //      called with `_ReturnAddress()` from INSIDE `Heap::AllocPhysical`, so `caller_rva` is the
    //      return address of `AllocPhysical`'s own caller. Resolved against the map from THIS
    //      build (`build/mcla.map`, written 07:34:49, eight seconds before the run started at
    //      07:34:57 -- the same-build requirement in the task brief):
    //          0x24c84a -> GuestMemoryHeap::Alloc+0x1a
    //      and w661's own PHYS-STATE rows carry `caller_rva=0x24c84a` on all 23 of them, at
    //      oom=1 through oom=15,000, sizes 0x31 through 0x87960. Two hosts -- `GuestMemoryHeap::Alloc`
    //      (the XTL/import path, memory.cpp:339) and `MmAllocatePhysicalMemoryEx` (rva 0x276888,
    //      `MmAllocatePhysicalMemoryEx+0x38`, the path PHYS-CENSUS measures) -- and the refusal
    //      rows happen to name only the first. So "the refusals are the XTL path" is true, but
    //      "the other 79,000 allocations are not" does NOT follow from the same field: a reader
    //      who grepped `caller_rva` would have seen one rva on every row and concluded
    //      everything is XTL, which is an artefact of where `_ReturnAddress()` is called, not a
    //      property of the guest.
    //
    // SO THE KEY IS (rva, glr), NOT rva. The guest `lr` is the field that actually distinguishes
    // callers -- two return addresses in w661's own refusal rows, 0x82137904 (145 rows) and
    // 0x821C667C (36 rows), and both are the instruction after a `bl 0x82130528`, the game's own
    // allocation thunk, while PHYS-CENSUS's 32 rows all carry lr=0x821325D4. That is a real
    // three-way split and no host-only key can produce it. Keying on both also means the split
    // does not depend on this file knowing the guest's allocator: the table reports the buckets
    // and a reader groups them, rather than the census asserting which bucket is "XTL".
    //
    // SHAPE, and why it is this shape. Fixed-size POD, 64 buckets, open addressing by linear
    // probe, a 64-bit key so the (rva, glr) pair is claimed with ONE compare-exchange and can
    // never be observed torn. No allocation, no lock, no behaviour change, nothing freed -- the
    // same constraints as the site ring above, and for the same reason: this runs on the
    // allocation hot path. Overflow is COUNTED, never dropped, so `n=` still equals the arena's
    // `nalloc` and a reader can tell a busy table from a saturated one instead of discovering it
    // as a silent undercount. `req` and `frag` are the census's own two units, never subtracted
    // from each other (the note above AcctMb's comment block: o1heap rounds every fragment to a
    // power of two, src/kernel/o1heap.c:310), and their RATIO is the footprint inflation, which
    // is the number that decides whether this arena is a leak or a rounding bill.
    struct CallerBucket
    {
        std::atomic<uint64_t> key{0};  // (rva << 32) | glr; 0 = unclaimed slot
        std::atomic<uint64_t> n{0};    // allocations
        std::atomic<uint64_t> req{0};  // bytes asked for
        std::atomic<uint64_t> frag{0}; // fragment footprint handed out
    };
    constexpr uint32_t kCallerSlots = 64;
    // F-640: `kCallerTop` is KEPT as the name of the OLD bound, not deleted, so the change is
    // visible at the declaration where a reader looking for "where did 8 come from" will find it.
    // It is no longer a bound on anything: the top-N is derived from the census capacity
    // (`kCallerSlots`) and every claimed slot is printed. The static_assert is the statement of
    // that, in a form the compiler checks rather than a comment it can drift from.
    constexpr uint32_t kCallerTop = 8;
    static_assert(kCallerSlots >= kCallerTop,
                  "F-640: the printed top-N is kCallerSlots (all claimed slots), not kCallerTop; "
                  "this assert exists only to keep the old constant referenced and self-describing");
    struct CallerCensus
    {
        std::atomic<uint64_t> n{0};        // every allocation this arena served
        std::atomic<uint64_t> distinct{0}; // buckets claimed
        std::atomic<uint64_t> overflow{0}; // events no slot could hold (still counted in n)
        CallerBucket slot[kCallerSlots];
    };
    CallerCensus g_callers[2];
    // F-639: the `alignment == 0 ? 0x1000` default in `Heap::AllocPhysical` is the one policy in
    // this file that can inflate a small request by 4 KB. w661 measured the SIZE of the total
    // inflation (req=763.2MB against frag=1169.1MB at nalloc=79,781, i.e. 405.9MB / 34.7% of live)
    // but not its DISTRIBUTION, so these counters are the measurement that decides whether that
    // default is the defect.
    //
    // THE CLAIM w661's OWN ROWS REFUTE, corrected here rather than left standing: "a 0x31-byte
    // request becomes 49 + 4096 + 32, rounded up to 8 KB". All 181 physical-arena rows in w661
    // that carry an alignment carry `align=0x10` -- 158 `AllocPhysical: o1heapAllocate returned
    // null` rows (132 of them `size=0x1 align=0x10 o1_amt=0x31`) and all 23 `PHYS-STATE` rows
    // (`oom=`1..15000). `o1_amount = size + 0x10 + 0x20`, so the default never fired on this path,
    // and the fragment the 49-byte request actually costs is `PHYS-STATE #1000`'s own
    // `o1_frag=0x80` = 128 B, not 8 KB. And a REFUSED request costs nothing at all:
    // `diagnostics.allocated += fragment_size` runs only on the success path (o1heap.c:356), so
    // the 15,000 refusals consumed 0 bytes and are a symptom of a full pool, not a cost.
    // The 405.9 MB is therefore not shown to be alignment; w661 also bounds the default's share:
    // between `HEAPLEAK-SUM #40000` and `#60000`, 20,000 allocations grew `req` by 0.4 MB and
    // `frag` by 2.9 MB, and 20,000 allocations that each took the default would have grown `frag`
    // by >= 20,000 * 8192 = 163.8 MB -- so at most ~1.8% of that window could have.
    //
    // THE DECISION RULE, so the next reader applies one test and not a preference. Read the
    // `defalign_*` fields on `HEAPLEAK-TOP arena=phys SUM` and take `defalign_frag / defalign_n`,
    // which is the MEAN FOOTPRINT of the allocations that were charged the default:
    //   * ~8192 -- the default fired and each such allocation really did cost a full page
    //     fragment. Then `defalign_n * 8192` is the recovery ceiling and it competes with the
    //     405.9 MB directly: if `defalign_n` is of order 10^4 it dominates, if of order 10^2 it
    //     is noise. SAY WHICH, with the number.
    //   * ~128 -- the default never fired. 128 B is what a 16-aligned request of any size <= 96
    //     already costs (`roundUpPow2(size + 48 + 32)`), so this reading says the whole 405.9 MB
    //     is o1heap's power-of-two rounding, in a file this one does not own, and NO change here
    //     moves the 1.53x. That is the reading w661 predicts.
    //   * between -- report the ratio and the count; do not round it to an argument.
    // `defalign_req` is the same subset's REQUESTED bytes, so `defalign_frag - defalign_req` is
    // the inflation attributable to this subset alone, with nothing else folded in. It is the
    // ceiling on what removing the default can return, and it is why the counter needs a third
    // field: `defalign_frag/defalign_n` alone cannot say whether the loss is recoverable.
    //
    // PER ARENA, not global. The user arena has no alignment parameter (`Heap::Alloc(size_t)`,
    // heap.h:30) and never feeds the sentinel, so a single global pair printed on BOTH SUM rows
    // would put the physical arena's numbers on the `arena=user` row with nothing to say so. The
    // gate reads `arena=phys`; this makes the row mean what it says either way.
    //
    // `kDefAlignSentinel`, not the alignment itself: the caller-census key is `(rva, glr)` and the
    // alignment arrives as a separate argument, so the default is marked by a value no alignment
    // can take rather than by equality with 0x1000 (a guest may legitimately ask for a page, and
    // that allocation is NOT the default's cost). Unreachable as an alignment because the pow2
    // rounding in AllocPhysical has already bounded every real argument at 2^31.
    constexpr uint32_t kDefAlignSentinel = 0xFFFFFFFFu;
    struct DefAlignAcct
    {
        std::atomic<uint64_t> n{0};     // allocations charged the zero-alignment default
        std::atomic<uint64_t> frag{0};  // their cumulative fragment FOOTPRINT (bytes charged)
        std::atomic<uint64_t> req{0};   // their cumulative REQUESTED bytes
    };
    DefAlignAcct g_defAlign[2];

    // F-640: IDENTITY for the zero-alignment subset. `defalign_n/frag/req` on the SUM row are three
    // aggregates over a subset that w662 measured as SIX requests carrying 648.0 MB of footprint
    // against 391.0 MB requested -- the largest single identifiable consumer in that run -- and
    // three numbers cannot say WHICH six. This ring is the identity.
    //
    // WHY THE AGGREGATE ALONE WAS NOT ENOUGH, measured rather than assumed. Two candidate sources
    // of per-request rows for this path exist and NEITHER can answer it in w662:
    //   * `PHYS-CENSUS` (imports.cpp, the `MmAllocatePhysicalMemoryEx` success row) is a SAMPLE,
    //     not a census: it prints the first 32 allocations and then every 2000th, and it RESETS its
    //     byte counter once past 200 MB. w662 has 32 such rows for a run that served 79,780
    //     physical allocations, so it is silent about 99.96 % of them.
    //   * `MmAllocatePhysicalMemoryEx`'s own `LOGF_UTILITY(...)` row, which is the only place the
    //     alignment ARGUMENT is printed per call, is COMPILED OUT (`imports.cpp` says so in a
    //     comment next to its only other user). Zero rows of it exist in w662, which was verified by
    //     grepping the log, not assumed.
    // So no row in w662 pairs a physical allocation with the alignment it was handed, and the six
    // are not nameable from that log. This ring is what makes them nameable next run.
    //
    // BOUNDED RING, UNBOUNDED COUNTERS -- the house rule, kept deliberately. The ring stores at most
    // kDefAlignSlots identities; `g_defAlign[].n/frag/req` are NOT bounded and are the census. The
    // SUM row prints `defalign_rows=` next to `defalign_n=` so the difference between what was
    // measured and what could be named is itself a printed number rather than a silent truncation.
    struct DefAlignSite
    {
        uint64_t req;   // bytes that request asked for
        uint64_t frag;  // fragment footprint it was charged
        uint32_t rva;   // host return address of the frame that asked
        uint32_t glr;   // guest lr at that moment
    };
    constexpr uint32_t kDefAlignSlots = 8;      // w662's whole subset is 6; the ring holds 8
    struct DefAlignRing
    {
        std::atomic<uint32_t> n{0};    // every request charged the default, unbounded
        std::atomic<uint32_t> shown{0};// identities actually stored in `slot` (<= kDefAlignSlots)
        DefAlignSite slot[kDefAlignSlots];
    };
    DefAlignRing g_defAlignRing[2];

    void CensusAlloc(uint32_t arena, void *ra, uint64_t req, uint64_t frag, uint32_t alignment)
    {
        CallerCensus &t = g_callers[arena];
        const uint32_t rva = (uint32_t)CallerRva(ra);
        const uint32_t glr = GetPPCContext() ? (uint32_t)GetPPCContext()->lr : 0u;
        t.n.fetch_add(1, std::memory_order_relaxed);
        if (alignment == kDefAlignSentinel)
        {
            // SUCCESS ONLY, and that is the right condition rather than a shortcut: an allocation
            // o1heap refused never entered `diagnostics.allocated` (o1heap.c:356 is the only
            // writer and it is on the success path), so a refused request has no footprint to
            // count and including it would inflate `defalign_frag/defalign_n` toward 8192 for
            // requests that cost nothing. Same condition as `AcctAlloc` above, so the two sum.
            DefAlignAcct &da = g_defAlign[arena];
            da.n.fetch_add(1, std::memory_order_relaxed);
            da.frag.fetch_add(frag, std::memory_order_relaxed);
            da.req.fetch_add(req, std::memory_order_relaxed);
            // F-640: name it. Same subset, same condition, but now each of the first
            // kDefAlignSlots requests keeps its own size, footprint and caller pair, so the SUM row
            // can print WHICH six and not only how many. `n` is bumped unconditionally and `shown`
            // only when a slot was actually stored, so "measured 40, named 8" is two numbers a
            // reader can see rather than a silent loss.
            DefAlignRing &dr = g_defAlignRing[arena];
            const uint32_t dn = dr.n.fetch_add(1, std::memory_order_relaxed) + 1;
            if (dn <= kDefAlignSlots)
            {
                DefAlignSite &ds = dr.slot[dn - 1];
                ds.req = req;
                ds.frag = frag;
                ds.rva = (uint32_t)CallerRva(ra);
                ds.glr = glr;
                dr.shown.store(dn, std::memory_order_relaxed);
            }
        }
        const uint64_t key = (static_cast<uint64_t>(rva) << 32) | glr;
        if (key == 0)
        {
            // No host frame and no guest context: unnameable. Counted, flagged as overflow, never
            // silently attributed to bucket zero.
            t.overflow.fetch_add(1, std::memory_order_relaxed);
            return;
        }
        for (uint32_t i = 0; i < kCallerSlots; ++i)
        {
            CallerBucket &b = t.slot[i];
            uint64_t k = b.key.load(std::memory_order_relaxed);
            if (k == key)
            {
                b.n.fetch_add(1, std::memory_order_relaxed);
                b.req.fetch_add(req, std::memory_order_relaxed);
                b.frag.fetch_add(frag, std::memory_order_relaxed);
                return;
            }
            if (k == 0)
            {
                uint64_t expect = 0;
                if (b.key.compare_exchange_strong(expect, key, std::memory_order_relaxed,
                                                  std::memory_order_relaxed))
                {
                    t.distinct.fetch_add(1, std::memory_order_relaxed);
                    b.n.fetch_add(1, std::memory_order_relaxed);
                    b.req.fetch_add(req, std::memory_order_relaxed);
                    b.frag.fetch_add(frag, std::memory_order_relaxed);
                    return;
                }
                // Lost the race for this slot: re-read, and if it is now ours, count into it.
                if (b.key.load(std::memory_order_relaxed) == key)
                {
                    b.n.fetch_add(1, std::memory_order_relaxed);
                    b.req.fetch_add(req, std::memory_order_relaxed);
                    b.frag.fetch_add(frag, std::memory_order_relaxed);
                    return;
                }
            }
        }
        t.overflow.fetch_add(1, std::memory_order_relaxed);
    }

    // F-640: the identity of ONE emitted census block, printed on the SUM row and on every row
    // beneath it. THIS IS THE FIX FOR THE SECOND HALF OF THE DEFECT. w662's rank rows carried no
    // block id beyond the bare word `arena=`, so a reader grepping them could pair a rank row with
    // the wrong SUM, and two agents did exactly that and drew OPPOSITE conclusions from one table
    // -- one reading "the selection is broken" from all-zero rows, the other reading the same rows
    // as healthy. A monotonic `block=` on the SUM and on each of its rows makes the pairing
    // impossible to get wrong by grep.
    std::atomic<uint32_t> g_censusBlock{0};

    // The top-N, emitted beside HEAPLEAK-SUM at the SAME cadence, so it is a series a census can
    // count rather than a one-shot print. Every line carries the literal `HEAPLEAK-TOP` so a soak
    // counts occurrences, not a substring that might also appear in prose.
    //
    // F-640, THE SELECTION. The old code sized its index array with `kCallerTop` and bounded its
    // inner scan with the SAME constant, so it ranked slots 0..7 of 64: a bucket at slot index >= 8
    // could never be selected no matter how many allocations it held. The emitted table was
    // "top-8 of the FIRST 8 SLOTS EVER CLAIMED", not "top-8 overall", and the difference is not
    // cosmetic. From w662's own final `HEAPLEAK-TOP arena=phys SUM` block (00:44:31.927):
    //     n=79780 distinct=64 overflow=4691 top1_ppm=3534
    //     rank 1..8 n = 282, 38, 5, 1, 1, 1, 1, 1        -> 330 allocations, 0.41 % of n
    // `distinct=64` against `kCallerSlots=64` means the table was SATURATED: every slot was
    // claimed, so the 56 unprinted slots and the 4,691 overflow events together held 99.59 % of the
    // run and not one of them was printable. The leak was in the un-printed part by construction.
    //
    // N IS DERIVED, NOT PICKED: the census is a fixed table of `kCallerSlots` buckets, so the
    // faithful top-N over all claimed slots is ALL of them, and that is what is printed. 64 rows x
    // 4 emits x 2 arenas = 512 lines for a whole run against w662's ~790,000, i.e. 0.06 %, and
    // nowhere near F-054's POISONED ceiling (66 % of a log being one repeating shape). The
    // selection is a 64-element partial selection sort on the SUMMARY cadence, not on the
    // allocation path, and it only reads, so it cannot fault. `kCallerTop` is kept as the name of
    // the old bound and is now only the head-count a reader may cite; nothing is truncated by it.
    //
    // IT TOLERATES A CONCURRENT INCREMENT between selecting and printing: the printed count is a
    // lower bound for that bucket at that instant, and `attributed`/`n` are read at their own
    // instants, so `acct_ok=` is a consistency CHECK rather than an equality that must hold.
    void CensusTop(uint32_t arena)
    {
        CallerCensus &t = g_callers[arena];
        // F-640: one scratch buffer for the whole emit, declared LOCAL and not static: CensusTop
        // runs on the alloc/free path (AcctSummary calls it), so a file-scope buffer would be a
        // data race between two threads' symbol strings. 288 B is enough for the longest undemangled
        // name this tree produces (the D3D12Backend `??$_Try_emplace@...` template) plus the
        // "+0x<disp>" tail, and HostSymbol truncates rather than overflowing.
        char symBuf[288];
        const uint64_t n = t.n.load(std::memory_order_relaxed);
        const uint64_t overflow = t.overflow.load(std::memory_order_relaxed);
        const uint32_t block = g_censusBlock.fetch_add(1, std::memory_order_relaxed) + 1;
        const char *arenaName = (arena == kArenaPhys) ? "phys" : "user";
        // Rank ALL kCallerSlots slots, claimed or not, by `n` descending.
        uint32_t idx[kCallerSlots];
        for (uint32_t i = 0; i < kCallerSlots; ++i)
            idx[i] = i;
        for (uint32_t i = 0; i < kCallerSlots; ++i)
        {
            uint32_t best = i;
            for (uint32_t j = i + 1; j < kCallerSlots; ++j)
            {
                const uint64_t a = t.slot[idx[j]].n.load(std::memory_order_relaxed);
                const uint64_t b = t.slot[idx[best]].n.load(std::memory_order_relaxed);
                if (a > b)
                    best = j;
            }
            const uint32_t tmp = idx[i];
            idx[i] = idx[best];
            idx[best] = tmp;
        }
        // F-640: how much of the run the printed rows actually account for. `attributed` is the sum
        // of every CLAIMED bucket, `unattributed` is `overflow`, and `acct_ok` reports whether they
        // add up to `n`. This is what makes `overflow=4691` actionable: a reader can now see that
        // 4,691 allocations in this arena have NO caller at all, rather than having to guess whether
        // the number is a table-health warning or a hole in the accounting.
        uint64_t attributed = 0;
        uint32_t claimed = 0;
        for (uint32_t i = 0; i < kCallerSlots; ++i)
        {
            if (t.slot[i].key.load(std::memory_order_relaxed) == 0)
                continue;
            ++claimed;
            attributed += t.slot[i].n.load(std::memory_order_relaxed);
        }
        // The head line carries the SPLIT, so the split is countable without summing 64 lines: the
        // top bucket's share of every allocation this arena served, in ppm, plus the table's own
        // health (distinct buckets, overflow, saturation).
        const CallerBucket &b0 = t.slot[idx[0]];
        const uint64_t top1 = b0.n.load(std::memory_order_relaxed);
        const uint64_t top1key = b0.key.load(std::memory_order_relaxed);
        // `defalign_mean` is `defalign_frag/defalign_n` IN BYTES, which is the whole decision:
        // ~8192 says the zero-alignment default fired and cost a page fragment each time, ~128
        // says it never fired and the inflation is o1heap's pow2 rounding instead (the reading
        // rule is spelled out at `g_defAlign`). Printed rather than computed in a reader so the
        // three fields cannot be read from different instants of the run. 0 when nothing took the
        // default, and the guard keeps the division out of it.
        const DefAlignAcct &da = g_defAlign[arena];
        const uint64_t dan = da.n.load(std::memory_order_relaxed);
        const uint32_t daShown = g_defAlignRing[arena].shown.load(std::memory_order_relaxed);
        MCLA_LOG_WARN("HEAPLEAK-TOP arena={} block={} SUM n={} distinct={} overflow={} top1_ppm={} "
                      "top1_rva={:#x} top1_glr={:08X} rows={}/{} attributed={} unattributed={} "
                      "attributed_ppm={} acct_ok={} saturated={} "
                      "defalign_n={} defalign_frag={:.1f}MB defalign_req={:.1f}MB "
                      "defalign_mean={}B defalign_rows={}/{}",
                      arenaName, block, n,
                      (unsigned long long)t.distinct.load(std::memory_order_relaxed),
                      (unsigned long long)overflow,
                      n ? (unsigned long long)((top1 * 1000000ull) / n) : 0ull,
                      (unsigned)(top1key >> 32), (unsigned)(top1key & 0xFFFFFFFFu), claimed,
                      (unsigned)kCallerSlots, (unsigned long long)attributed,
                      (unsigned long long)overflow,
                      n ? (unsigned long long)((attributed * 1000000ull) / n) : 0ull,
                      (attributed + overflow >= n) ? 1 : 0,
                      (claimed >= kCallerSlots) ? 1 : 0,
                      (unsigned long long)dan,
                      AcctMb(da.frag.load(std::memory_order_relaxed)),
                      AcctMb(da.req.load(std::memory_order_relaxed)),
                      dan ? (unsigned long long)(da.frag.load(std::memory_order_relaxed) / dan) : 0ull,
                      (unsigned)daShown, (unsigned long long)dan);
        // F-640: the zero-alignment subset, NAMED. Three aggregates cannot say which requests they
        // came from, and in w662 they were six requests carrying 648.0 MB of footprint against
        // 391.0 MB requested -- the single largest identifiable consumer in the run. These rows
        // carry the same fields as a rank row, so the reader needs no second instrument to read
        // them. `defalign_rows` on the SUM above says how many of the `defalign_n` measured
        // requests could be named; the difference is the truncation, printed rather than implied.
        if (dan != 0)
        {
            for (uint32_t i = 0; i < kDefAlignSlots; ++i)
            {
                if (i >= daShown)
                    break;
                const DefAlignSite &ds = g_defAlignRing[arena].slot[i];
                const char *sym = HostSymbol(ds.rva, symBuf, sizeof(symBuf));
                MCLA_LOG_WARN("HEAPLEAK-TOP arena={} block={} DEFLIGN i={} rva={:#x} glr={:08X} "
                              "sym={} n=1 req={:.1f}MB frag={:.1f}MB infl={:.3f} of_n={}",
                              arenaName, block, i + 1, ds.rva, ds.glr, sym, AcctMb(ds.req),
                              AcctMb(ds.frag),
                              ds.req ? static_cast<double>(ds.frag) / (double)ds.req : 0.0,
                              (unsigned long long)dan);
            }
        }
        // F-640: EVERY RANK ROW IS SELF-IDENTIFYING. `arena=` and `block=` pair it to exactly one
        // SUM; `slot=` is the table index it was found at, so a reader can tell a bucket the census
        // actually holds from padding; `rva=`+`sym=` name the HOST frame (the symbol is resolved
        // in-process by the mechanism already in this file -- see HostSymbol above); `glr=` names
        // the GUEST frame, which is the half of the key that does the real work (F-639 measured
        // six distinct guest return addresses behind ONE host rva in w662, so a host-only key
        // cannot produce that split); `n/req/frag/infl` are the census's own two units and their
        // ratio, never subtracted from each other; and `unattributed=` repeats the overflow count
        // at the instant of the print, so no rank row can be read as if it covered the whole run.
        // UNCLAIMED SLOTS ARE NOT PRINTED: the old shape emitted an all-zero row for each one,
        // indistinguishable from a claimed bucket that happens to be zero, which is the other half
        // of why this table was misread. `rows=` on the SUM says how many rows to expect.
        uint32_t rank = 0;
        for (uint32_t i = 0; i < kCallerSlots; ++i)
        {
            const uint32_t slot = idx[i];
            const CallerBucket &b = t.slot[slot];
            const uint64_t k = b.key.load(std::memory_order_relaxed);
            if (k == 0)
                continue;  // unclaimed: no key was ever CAS'd into this slot
            ++rank;
            const uint64_t bn = b.n.load(std::memory_order_relaxed);
            const uint64_t bq = b.req.load(std::memory_order_relaxed);
            const uint64_t bf = b.frag.load(std::memory_order_relaxed);
            const uint32_t brva = (uint32_t)(k >> 32);
            const uint32_t bglr = (uint32_t)(k & 0xFFFFFFFFu);
            const char *sym = HostSymbol(brva, symBuf, sizeof(symBuf));
            MCLA_LOG_WARN("HEAPLEAK-TOP arena={} block={} rank={} slot={} rva={:#x} glr={:08X} "
                          "sym={} n={} req={:.1f}MB frag={:.1f}MB infl={:.3f} "
                          "arena_n={} unattributed={}",
                          arenaName, block, rank, slot, brva, bglr, sym,
                          (unsigned long long)bn, AcctMb(bq), AcctMb(bf),
                          bq ? static_cast<double>(bf) / (double)bq : 0.0, (unsigned long long)n,
                          (unsigned long long)overflow);
        }
    }

    // The periodic summary. `live` is the honest leak number for this arena; `o1_alloc` is o1heap's
    // own view of the same quantity, and the two must agree -- if `live` and `o1_alloc` drift, the
    // drift IS a free the SEH net swallowed (SehO1Free, heap.cpp:273) that the census counted as
    // returned. Printing both is what keeps the census from becoming the thing it is measuring.
    void AcctSummary(ArenaAcct &a, uint32_t arena, O1HeapInstance *inst)
    {
        const uint64_t e = a.events.fetch_add(1, std::memory_order_relaxed) + 1;
        if (e > 2 && (e % kAcctSummaryEvery) != 0)
            return;
        const O1HeapDiagnostics d = HeapDiag(inst);
        const HeapSite *s = NewestSite(arena);
        // F-631: `o1_free` and `bin_mask` are the two fields that make this row self-interpreting.
        // `o1_free = cap - allocated` is the honest free space -- F-630's "1.45 GB free" came from
        // reading `cap` as free, and `PHYS-CENSUS total=` is a cumulative requested-bytes counter
        // that RESETS above 200 MB (imports.cpp:2985-2999), not occupancy, so nothing on record ever
        // printed occupancy for this arena. `bin_mask=0` with `o1_free>0` is the signature of a pool
        // whose every free block is too SMALL to serve the request -- fragmentation, a third reading
        // that neither "full" nor "destroyed" covers and that the refusal rows could not separate.
        // F-638: a request of o1_amount <= 32 B has opt==0, for which `cand` is all-ones and
        // `suitable == bin_mask`, so `bin_mask=0 with o1_free>0` is NOT reachable at that class
        // -- but the alloc path's own `o1Amount = size + alignment + 32` with size>=1 and
        // alignment>=1 puts every refusal at opt>=1, so this row and the verdict agree. The
        // verdict says so with `split=collapsed` rather than guessing.
        MCLA_LOG_WARN("HEAPLEAK-SUM arena={} #{} nalloc={} nfree={} req={:.1f}MB "
                      "frag={:.1f}MB freed={:.1f}MB live={:.1f}MB peak={:.1f}MB null={} "
                      "rej_free={} o1_alloc={:.1f}MB o1_peak={:.1f}MB cap={:.1f}MB "
                      "o1_free={:.1f}MB bin_mask={:#x} oom={} "
                      "last_site_rva={:#x} last_site_lr={:08X} last_site_sz={:#x}",
                      arena == kArenaPhys ? "phys" : "user", e,
                      a.nAlloc.load(std::memory_order_relaxed),
                      a.nFree.load(std::memory_order_relaxed),
                      AcctMb(a.reqBytes.load(std::memory_order_relaxed)),
                      AcctMb(a.fragBytes.load(std::memory_order_relaxed)),
                      AcctMb(a.freeBytes.load(std::memory_order_relaxed)),
                      AcctMb(a.liveBytes.load(std::memory_order_relaxed)),
                      AcctMb(a.peakLive.load(std::memory_order_relaxed)),
                      a.nullAlloc.load(std::memory_order_relaxed),
                      a.rejFree.load(std::memory_order_relaxed), AcctMb(d.allocated),
                      AcctMb(d.peak_allocated), AcctMb(d.capacity),
                      AcctMb(d.capacity > d.allocated ? d.capacity - d.allocated : 0),
                      O1BinMask(inst), (unsigned long long)d.oom_count, s ? s->rva : 0u,
                      s ? s->glr : 0u, s ? s->size : 0u);
        // F-639: the per-caller split, on the same cadence and the same gate as the row above, so
        // the two can never be read from different runs. Arena-wide `nalloc`/`nfree` above says the
        // arena is unbalanced; only this says WHICH caller made it unbalanced.
        CensusTop(arena);
    }

    void AcctAlloc(uint32_t arena, O1HeapInstance *inst, uint64_t req, size_t frag)
    {
        ArenaAcct &a = g_acct[arena];
        a.nAlloc.fetch_add(1, std::memory_order_relaxed);
        a.reqBytes.fetch_add(req, std::memory_order_relaxed);
        a.fragBytes.fetch_add(frag, std::memory_order_relaxed);
        const uint64_t live = a.liveBytes.fetch_add(frag, std::memory_order_relaxed) + frag;
        uint64_t peak = a.peakLive.load(std::memory_order_relaxed);
        while (live > peak &&
               !a.peakLive.compare_exchange_weak(peak, live, std::memory_order_relaxed))
        {
        }
        AcctSummary(a, arena, inst);
    }

    void AcctFree(uint32_t arena, O1HeapInstance *inst, size_t frag)
    {
        ArenaAcct &a = g_acct[arena];
        a.nFree.fetch_add(1, std::memory_order_relaxed);
        a.freeBytes.fetch_add(frag, std::memory_order_relaxed);
        a.liveBytes.fetch_sub(frag, std::memory_order_relaxed);
        AcctSummary(a, arena, inst);
    }
} // namespace


// F-779: host memory for the two DETACHED o1heap instances. Deliberately process-lifetime and never
// freed, exactly like the arenas themselves. VirtualAlloc rather than _aligned_malloc because
// <windows.h> is already included here and its 64 KiB granularity trivially satisfies
// O1HEAP_ALIGNMENT (32), so no alignment arithmetic is needed and no new include is added.
//
// WHY THEY MUST NOT BE IN THE GUEST WINDOW. o1heapInit places the instance AT the arena base, so the
// first 0x240 bytes of a guest-addressable arena are our control blocks. F-778 measured what that
// costs: the title handed 0xA0400000 -- the physical instance's own first byte -- to its memcpy as a
// copy destination and zeroed 128 bytes there, i.e. bin heads 0..15. With the bin heads and
// `nonempty_bin_mask` zeroed, o1heapAllocate computes `suitable_bins == 0` and returns NULL for EVERY
// size including 1 byte, while o1heapDoInvariantsHold -- which never dereferences a fragment -- still
// returns true. That is precisely the `w740` signature: `o1heap invariants fail` alongside
// `xtl-alloc-refused`, a pool that looks healthy and refuses everything.
//
// Detaching makes the arena's first byte an ordinary allocatable fragment, so a guest write to a guest
// physical address can only ever land on guest data. NOTHING ABOUT THE ARENA BASE CHANGES: the title is
// still handed 0x20000 and 0xA0400000 (F-384's measurement stands, and relocating the base was already
// tried in `w395` and reverted), we simply no longer keep our books there.
static uint8_t *g_userInstMem = nullptr;
static uint8_t *g_physInstMem = nullptr;

static uint8_t *AllocDetachedInstanceMem()
{
    void *const p = VirtualAlloc(nullptr, o1heapInstanceSize(), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    return static_cast<uint8_t *>(p);
}

// F-806: readers for the two detached instance blocks, so the write-watchers can follow the header
// off the arena. Read-only accessors over statics that already existed; see heap.h for the taint list.
uint8_t *UserHeapInstanceMem(void) { return g_userInstMem; }
uint8_t *PhysHeapInstanceMem(void) { return g_physInstMem; }

void Heap::Init()
{
    // F-384: this line used to hardcode 0x20000 (XenonRecomp's baseline); the address is unchanged but
    // it now comes from `kUserHeapArenaVa`, and so do the four probes that watch this page. The
    // relocation to 0x20000000 was tried and measured in `w395` and REVERTED: the writer followed the
    // base (`guest=20000000 val=20000004` from the same `sub_82397060` chain), so the title is being
    // HANDED our arena base -- that hand-off is T41.67, not a relocation.
    // F-779: the arena base is still that same guest address; only the INSTANCE moved out of it.
    heapArenaBase = (uint8_t*)mcla::kernel::g_memory.Translate(mcla::kernel::kUserHeapArenaVa);
    heapArenaSize = mcla::kernel::kUserHeapArenaEnd - mcla::kernel::kUserHeapArenaVa;
    g_userInstMem = AllocDetachedInstanceMem();
    heap = g_userInstMem ? o1heapInitSeparate(g_userInstMem, heapArenaBase, heapArenaSize)
                         : o1heapInit(heapArenaBase, heapArenaSize);
    g_hdrArena = heapArenaBase;
    if (heap != nullptr)
        g_hdrGoldenCap = o1heapGetDiagnostics(heap).capacity;  // F-370: constant from here on

    physArenaBase = (uint8_t*)mcla::kernel::g_memory.Translate(mcla::kernel::kPhysArenaBeginVa);
    // F-640/B2: THE ALLOCATOR MUST NOT REACH THE LOW REGION. The low region
    // [0xA0000000, 0xA0400000) carries the console's physical [0, 0x400000); the
    // allocator's arena starts at kPhysArenaBeginVa, which IS the low region's end.
    // The two are therefore disjoint BY CONSTRUCTION and o1heap can never hand a
    // low-region byte to the guest -- which is what makes the low region a faithful
    // "console physical page 0" rather than a second allocator arena. Stated at
    // compile time so a future base move cannot quietly overlap them.
    static_assert(mcla::kernel::kPhysArenaBeginVa >= mcla::boot::kPhysLowRegionEndVa,
                  "F-640/B2: the physical allocator's arena must start at or above the "
                  "console's LOW REGION end (0xA0400000), or it would hand out bytes "
                  "that are also the console's physical page 0.");
    // F-640: THE CAPACITY IS NOW THE CONSOLE'S, DERIVED, NOT INVENTED. This line used to read
    // `0x100000000 - kPhysArenaBeginVa` = 0x5FC00000 = 1,532.0 MiB -- "everything above the base,
    // to the top of the window". That expression had no source: it encoded F-391's choice of BASE,
    // and a reason to move a base is not a reason for a size (heap_arena.h:39-51 gives the base a
    // reason; nothing ever gave the magnitude one). It is replaced by `PhysArenaSizeBytes()`, which
    // is `kConsolePhysicalBytes` = 0x20000000 = 512 MiB, the reference's own
    // `heaps_.physical.Initialize(..., 0x00000000, 0x20000000, 4096)`
    // (.research/xenia/src/xenia/memory.cc:171-172). Ratio corrected: 2.992x. See heap_arena.h for
    // the four corroborations in the same file, for why the 0xA/0xC/0xE regions are three VIEWS of
    // this one pool rather than a split, and for the five in-tree sites that already tell the guest
    // a physical address is below 0x20000000 (gpu_cp.cpp:1756, gpu_cp.cpp:2328, gpu_mmio.cpp:83,
    // gpu_mmio.cpp:74, native_renderer.cpp:120) -- which is why backing 512 MiB with 1,532 MiB
    // was a lie with a number attached, and why 512 MiB is the faithful value and not a budget.
    // `AttachPhysicalArena` can still rebind the size (it is not called anywhere in this tree); the
    // init row below is emitted from whichever binding is live, so the two cannot disagree.
    // F-779: it still rebinds to an ATTACHED instance (`o1heapInit`), i.e. to the old layout. It is
    // dead code in this tree; if it is ever wired up it must be detached too, or the collision F-778
    // measured comes back with it.
    physArenaSize = mcla::kernel::PhysArenaSizeBytes();
    g_physInstMem = AllocDetachedInstanceMem();
    physicalHeap = g_physInstMem ? o1heapInitSeparate(g_physInstMem, physArenaBase, physArenaSize)
                                 : o1heapInit(physArenaBase, physArenaSize);
    const uint64_t o1Cap =
        physicalHeap ? (uint64_t)o1heapGetDiagnostics(physicalHeap).capacity : 0ull;
    // F-640: the model-in-force row. Emitted ONCE, at Init, on the same terms as every other row in
    // this file: the modelled capacity straight from the constant, the guest extent it implies, the
    // value it replaces, and the o1heap capacity the allocator actually took.
    // F-779 CORRECTS THE PARENTHETICAL THAT USED TO BE HERE: it said the allocator took
    // "arenaSize - 0x240, o1heap's own header padding". That was true of `o1heapInit` and is FALSE of
    // `o1heapInitSeparate` -- a detached instance is not in the arena, so capacity is the whole
    // `arenaSize` (still clamped to FRAGMENT_SIZE_MAX and rounded down to FRAGMENT_SIZE_MIN, neither
    // of which binds at 0x20000000). `o1_cap_delta` is that difference printed explicitly: it is
    // +0x240 when the instance is detached and 0 when it is not, so a census can tell which layout
    // the running exe actually used WITHOUT trusting this comment. `inst_detached`, `inst_host` and
    // `frag0_guest` are the same fact from the other side: the instance lives at a host address that
    // is not in the guest window, and the first allocatable fragment is now the arena's own first
    // byte rather than base+0x240.
    const uint64_t o1CapAttachedModel =
        (physArenaSize > o1heapInstanceSize()) ? (uint64_t)(physArenaSize - o1heapInstanceSize()) : 0ull;
    MCLA_LOG_WARN("PHYS-POOL phase=init cap_bytes={:#x} cap_mb={:.1f} model=console-512MiB "
                  "replaced_mb=1532.0 ratio=2.992x guest=[{:08X}..{:08X}) o1_capacity={:#x} "
                  "o1_capacity_mb={:.1f} hdr={:p} inst_detached={} inst_host={:p} "
                  "frag0_guest={:08X} o1_cap_delta={:#x} user_inst_detached={} user_inst_host={:p}"
                  " | low_region=[{:08X}..{:08X}) low_bytes={:#x} low_in_allocator=0 "
                  "low_region_owner=console-physical-0(F-640/B2)",
                  (uint64_t)physArenaSize,
                  static_cast<double>(physArenaSize) / (1024.0 * 1024.0),
                  mcla::kernel::kPhysArenaBeginVa,
                  mcla::kernel::kPhysArenaBeginVa + (uint32_t)physArenaSize,
                  (uint64_t)o1Cap,
                  physicalHeap ? static_cast<double>(o1Cap) / (1024.0 * 1024.0) : 0.0,
                  (void*)physArenaBase,
                  (g_physInstMem != nullptr) ? 1 : 0,
                  (void*)g_physInstMem,
                  mcla::kernel::kPhysArenaBeginVa,
                  (uint64_t)(o1Cap - o1CapAttachedModel),
                  (g_userInstMem != nullptr) ? 1 : 0,
                  (void*)g_userInstMem,
                  mcla::boot::kPhysLowRegionVa, mcla::boot::kPhysLowRegionEndVa,
                  (uint64_t)mcla::boot::kPhysLowRegionBytes);
}

void Heap::AttachPhysicalArena(void* base, size_t size)
{
    physArenaBase = (uint8_t*)base;
    physArenaSize = size;
    physicalHeap = o1heapInit(base, size);
}

namespace
{
    const char* ProbeReasonName(Heap::LiveProbe::Reason reason)
    {
        switch (reason)
        {
            case Heap::LiveProbe::Reason::Ok: return "ok";
            case Heap::LiveProbe::Reason::Null: return "null";
            case Heap::LiveProbe::Reason::OutOfArena: return "out-of-arena";
            case Heap::LiveProbe::Reason::Misaligned: return "misaligned";
            case Heap::LiveProbe::Reason::BadSize: return "bad-size";
            case Heap::LiveProbe::Reason::NotUsed: return "not-used";
            case Heap::LiveProbe::Reason::BadPointers: return "bad-pointers";
        }
        return "unknown";
    }

    // F-641: THE CHECK THAT ACTUALLY RUNS ON A GRANULAR BLOCK, and the reason it lives out here.
    // Every O1HEAP_ASSERT in o1heap.c is COMPILED OUT on the mcla target -- `-DNDEBUG` is in the
    // o1heap.c compile line in build/compile_commands.json -- so the power-of-two check, the
    // double-free check and the leftover-alignment check do not exist at run time, and re-enabling
    // them is out of bounds. `o1heapDoInvariantsHold` is the only run-time check inside o1heap.c and
    // it never dereferences a fragment (F-631 depends on that: it is what lets it survive a poisoned
    // list), so it cannot see any of this. Therefore the properties the large path must preserve are
    // checked HERE, from outside, against the header the allocator has just written -- and each
    // property is the SAME predicate the rest of the tree already reads, not a restatement of it:
    //   * `FragFootprint` reads the header 32 bytes below the raw pointer, which is o1heap's own
    //     `out = ((char*)frag) + O1HEAP_ALIGNMENT`. The footprint must equal the charge, or the
    //     arena was not asked for what was accounted.
    //   * `Heap::IsLiveAllocation` -- the very predicate `Heap::Free` calls before it will hand the
    //     block back to o1heapFree -- must accept it. That predicate requires O1HEAP_ALIGNMENT
    //     alignment, in-arena, a size that is a MULTIPLE of FRAGMENT_SIZE_MIN, `used == true`, and
    //     both header links NULL or in-arena. Note what it does NOT require: a power of two. Its own
    //     comment says so ("o1heap sizes fragments by `roundUpToPowerOf2`, so a live size is always a
    //     power of two -- but the test below only enforces the multiple"), which is why a
    //     page-granular size is legal here and needed no change to that predicate.
    //   * `o1heapDoInvariantsHold` must still hold afterwards.
    // A failure is COUNTED in `g_granBad` and printed on the house cadence. It does NOT refuse: a
    // diagnostic check must not convert a served request into a refusal, because then the instrument
    // would be changing the thing it measures, and `PHYS-POOL-FULL`'s `gran_bad` field exists so the
    // number is on the tally row a soak reads rather than only in an error line.
    void CheckGranularBlock(const char *phase, size_t amount, size_t charge, void *rawPtr,
                            uint8_t *arenaBase, size_t arenaSize, O1HeapInstance *heap, void *callerRa)
    {
        if (rawPtr == nullptr)
            return;  // A refusal has no block to check; the refusal path owns that case.
        const uintptr_t p = reinterpret_cast<uintptr_t>(rawPtr);
        const size_t measured = FragFootprint(rawPtr);
        Heap::LiveProbe probe;
        const bool live = g_userHeap.IsLiveAllocation(arenaBase, arenaSize, rawPtr, &probe);
        const bool aligned = (p % kO1HeapAlignment) == 0;
        const bool gridOk = (measured >= kFragmentSizeMin) && ((measured % kFragmentSizeMin) == 0);
        if (live && aligned && gridOk && (measured == charge))
            return;
        const uint32_t n = g_granBad.fetch_add(1, std::memory_order_relaxed) + 1;
        if (n <= 8 || (n % 100) == 0)
        {
            const O1HeapDiagnostics d = HeapDiag(heap);
            MCLA_LOG_ERROR("PHYS-LARGE-BAD #{} phase={} amount={:#x} charge={:#x} raw={:p} "
                           "measured={:#x} ptr_align_ok={} grid_ok={} live={} why={} next={:p} "
                           "prev={:p} used={} invariants={} capped_walks={} oom={} "
                           "glr={:08X} caller_rva={:#x}",
                           n, phase, amount, charge, rawPtr, measured, aligned ? 1 : 0,
                           gridOk ? 1 : 0, live ? 1 : 0, ProbeReasonName(probe.reason), probe.next,
                           probe.prev, probe.used ? 1 : 0,
                           (heap != nullptr && o1heapDoInvariantsHold(heap)) ? 1 : 0,
                           (unsigned long long)d.granular_walk_capped,
                           (unsigned long long)d.oom_count,
                           GetPPCContext() ? static_cast<uint32_t>(GetPPCContext()->lr) : 0u,
                           CallerRva(callerRa));
        }
    }
}

namespace
{
    // F-645: THE FRAGMENT PREDICATE, EXTRACTED VERBATIM from Heap::IsLiveAllocation so that
    // IsLiveAllocation can run the SAME checks a second time on a different pointer -- the raw o1heap
    // fragment recovered from the bookkeeping word below a guest-visible user pointer. Every
    // predicate, every order, every field written into `probe` (including the header fields, which are
    // read BEFORE the size/used tests so a caller that gets `bad-size` still sees them) is
    // unchanged: this is an extraction, not a new rule, and the refusal reasons it produces are the
    // same strings the log already carries.
    bool ProbeO1Fragment(const uint8_t* arenaBase, size_t arenaSize, void* ptr, Heap::LiveProbe& probe)
    {
        const uintptr_t base = (uintptr_t)arenaBase;
        const uintptr_t p = (uintptr_t)ptr;

        // Must be inside the arena (with room for a header below it) and 32-byte
        // aligned (o1heap returns aligned ptrs).
        if (p < base + kO1HeapAlignment || p >= base + arenaSize)
        {
            probe.reason = Heap::LiveProbe::Reason::OutOfArena;
            return false;
        }
        if ((p % kO1HeapAlignment) != 0)
        {
            probe.reason = Heap::LiveProbe::Reason::Misaligned;
            return false;
        }

        // Probe the fragment header just below the user pointer.
        const FragHeaderProbe* hdr = (const FragHeaderProbe*)(p - kO1HeapAlignment);
        probe.next = hdr->next;
        probe.prev = hdr->prev;
        probe.size = hdr->size;
        probe.used = hdr->used;

        // Size must be a multiple of FRAGMENT_SIZE_MIN and fit the arena (o1heap sizes fragments by
        // `roundUpToPowerOf2`, o1heap.c:310, so a live size is always a power of two -- but the test
        // below only enforces the multiple, not the power of two).
        if (probe.size < kFragmentSizeMin || (probe.size % kFragmentSizeMin) != 0 || probe.size > arenaSize)
        {
            probe.reason = Heap::LiveProbe::Reason::BadSize;
            return false;
        }

        // Live allocations have used=true; free fragments are in bins.
        if (!probe.used)
        {
            probe.reason = Heap::LiveProbe::Reason::NotUsed;
            return false;
        }

        // Header pointers must either be NULL or inside the same arena.
        const auto inArena = [base, arenaSize](void* q) {
            return (uintptr_t)q >= base && (uintptr_t)q < base + arenaSize;
        };
        if ((hdr->prev != nullptr && !inArena(hdr->prev)) || (hdr->next != nullptr && !inArena(hdr->next)))
        {
            probe.reason = Heap::LiveProbe::Reason::BadPointers;
            return false;
        }

        probe.reason = Heap::LiveProbe::Reason::Ok;
        return true;
    }
} // namespace

// F-645: WHY THIS FUNCTION NOW ACCEPTS TWO POINTERS, AND WHAT THAT IS NOT.
//
// MEASURED, on build/w675.log (READ ONLY), and this is the whole finding. `XTL-FREE` refused every
// free it saw with `reason=out-of-arena`, and the addresses it printed are INSIDE the pool:
// `B7328280`, `B732B280`, `B73C7280`, `BE84B280` are all in [A0400000, C0400000). So the printed
// reason cannot be the physical probe's: `__xtl_free` (src/kernel/imports.cpp, the `IsLiveAllocation`
// call pair) probes the PHYSICAL arena first and, when that fails, probes the USER arena with the SAME
// `probe` object, which OVERWRITES the physical reason. The user arena is [0x20000, 0x7FEA0000), so
// every physical address is `out-of-arena` there and that string is printed for every physical
// refusal regardless of what the physical probe said. The row has been reporting the second probe.
//
// The physical probe's own reason, recovered without editing imports.cpp: `Heap::AllocPhysical`
// returns `aligned`, not o1heap's raw pointer, and writes the raw pointer to `*((void**)aligned - 1)`
// (both quoted by symbol, the `aligned` local and the two `*((void**)aligned - N) =` stores). With the
// guest's hardcoded 16-byte alignment (`82130538 li r5,16`, and the `std::max<size_t>(16, alignment)`
// floor), `aligned` is deterministically `raw + 0x20`, so `aligned - 0x20` is the PAYLOAD START, not a
// fragment header -- and the header fields read there are the first 32 bytes the guest wrote. Four
// independent checks agree that these are `raw + 0x20` pointers and not raw fragments:
//   * every refused address is `== 0 (mod 64)` (`0x…280`, four for four), which is `frag + 0x40`;
//   * `Heap::Free` frees the SAME pointer form successfully -- `PHYS-FREE #1..#8` print guest
//     `B7321280`, `B7323280`, `B733C280`, `B9342280`, `B9344280`, `B934C280`, all `== 0 (mod 64)`, all
//     `== 0 (mod 64)` addresses the allocator itself handed out -- because `Heap::Free` resolves
//     `rawPtr = *((void**)ptr - 1)` BEFORE it probes (the `void* rawPtr = *((void**)ptr - 1)` local in
//     `Heap::Free`) and then hands o1heap that;
//   * `PHYS-FREE`'s counter is incremented for EVERY free that reaches `Heap::Free`, and it printed
//     8 rows on a cadence of "first 8, then every 4096th", so fewer than 4096 frees reached
//     `Heap::Free` in the whole run against 10,044 allocations;
//   * `imports.cpp`'s own `LivePhysAllocs().erase(ptr)` -- keyed on the ALIGNED pointer, exactly as
//     `AllocPhysical` inserts it -- is what the 8 honoured frees cleared.
// So the registry, the bookkeeping word and the allocator all agree; only the PREDICATE was being
// asked about the wrong representation. This is bookkeeping (b), not a guest bug (a), and the
// mechanism is ours.
//
// WHAT THIS IS NOT, so a future reader cannot widen it by accident:
//   * The extra accept is reachable ONLY when the first fragment probe already FAILED, and only for
//     the PHYSICAL arena. `Heap::Alloc` (the user arena) returns o1heap's raw pointer unmodified
//     (the `return ptr` at the end of `Heap::Alloc`), so the user arena has one representation and
//     the user-arena call sites are byte-for-byte unaffected.
//   * It is not a weakening: the recovered raw fragment must pass `ProbeO1Fragment` UNCHANGED, in
//     full, and the pointer must lie strictly inside that fragment's own extent and within
//     `kPhysUserPointerSlackBytes` of it -- a bound derived from the callers, not chosen. A garbage
//     or double-freed pointer has to pass all of that by luck.
//   * It does NOT relax the exact-allocation contract. `Heap::Free` still refuses anything absent from
//     `LivePhysAllocs()` (the `if (LivePhysAllocs().erase(ptr) == 0)` guard), so a sub-block or
//     interior free is still refused there, now with an accurate row instead of a mislabelled one.
bool Heap::IsLiveAllocation(uint8_t* arenaBase, size_t arenaSize, void* ptr, LiveProbe* out) const
{
    LiveProbe local;
    LiveProbe& probe = out != nullptr ? *out : local;
    probe = {};

    if (arenaBase == nullptr || ptr == nullptr)
    {
        probe.reason = LiveProbe::Reason::Null;
        return false;
    }

    if (ProbeO1Fragment(arenaBase, arenaSize, ptr, probe))
        return true;

    // F-645: the second representation. Physical only, and only inside the arena -- `p - 8` is
    // inside the arena exactly when the predicate above already proved `p >= base + 0x20`.
    const uintptr_t base = (uintptr_t)arenaBase;
    const uintptr_t p = (uintptr_t)ptr;
    if (arenaBase != physArenaBase || p < base + kO1HeapAlignment || p >= base + arenaSize)
        return false;

    void* raw = nullptr;
    std::memcpy(&raw, (const void*)(p - sizeof(void*)), sizeof(raw));  // *((void**)aligned - 1)

    LiveProbe rp;
    rp = {};
    const bool rawOk = (raw != nullptr) && ProbeO1Fragment(arenaBase, arenaSize, raw, rp);
    const uintptr_t r = (uintptr_t)raw;
    const uintptr_t delta = (rawOk && p > r) ? (p - r) : 0;  // never a wrapped subtraction
    const bool inside =
        rawOk && p >= r + kO1HeapAlignment && delta <= (uintptr_t)mcla::kernel::kPhysUserPointerSlackBytes &&
        delta < (uintptr_t)rp.size;

    // THE DISTINGUISHING MEASUREMENT, as a row, because the run that decides it cannot be edited
    // into printing it: `raw_ok=1 inside=1` is bookkeeping (b) -- our bookkeeping lost the
    // representation -- and `raw_ok=0` is (a), a pointer this allocator never produced. The old row
    // answered neither, because its `reason` belonged to the other arena's probe.
    {
        static std::atomic<uint64_t> s_probe{0};
        static std::atomic<uint64_t> s_probeRecovered{0};
        const uint64_t n = s_probe.fetch_add(1, std::memory_order_relaxed) + 1;
        if (inside)
            s_probeRecovered.fetch_add(1, std::memory_order_relaxed);
        if (n <= 8 || (n % 4096) == 0)
        {
            MCLA_LOG_WARN(
                "PHYS-PROBE #{} ptr={:p} guest={:08X} arena=[{:08X},{:08X}) off={:#x} of={:#x} "
                "why={} raw_below={:p} raw_off={:#x} raw_ok={} raw_why={} frag={:#x} delta={:#x} "
                "inside={} seen={} recovered={} glr={:08X}",
                (unsigned long long)n, (void*)ptr, mcla::kernel::g_memory.MapVirtual(ptr),
                mcla::kernel::kPhysArenaBeginVa, mcla::kernel::kPhysArenaEndVa,
                (uint64_t)(p - base), (uint64_t)arenaSize, ProbeReasonName(probe.reason), raw,
                rawOk ? (uint64_t)(r - base) : 0ull, rawOk ? 1 : 0,
                rawOk ? ProbeReasonName(rp.reason) : "null", (uint64_t)rp.size, (uint64_t)delta,
                inside ? 1 : 0, (unsigned long long)n,
                (unsigned long long)s_probeRecovered.load(std::memory_order_relaxed),
                GetPPCContext() ? static_cast<uint32_t>(GetPPCContext()->lr) : 0u);
        }
    }

    if (!inside)
        return false;

    probe = rp;
    probe.reason = LiveProbe::Reason::Ok;
    return true;
}

namespace
{
    // F-374 / F-412: RAII window for the header guard. F-412 replaced the old bool arms with ONE
    // nesting depth over BOTH guard pages (g_hgDepth under g_hgMtx, boot_host.cpp:323-324, with
    // the Disarm/Arm pair at :462-484): a page goes back to NOACCESS only when the LAST open
    // window across ALL threads closes (only HeapGuardArmImpl re-arms, and only at depth 0 --
    // :477; the guard-trip handlers themselves never re-arm, boot_host.cpp:384, because re-arming
    // under the faulting instruction was the w380 storm. F-412's one exception: the VEH W0 PARK
    // branch drains its own thread's windows through HeapGuardArmImpl, boot_host.cpp:1596). The
    // old rule -- "declare this immediately after the function's std::lock_guard so it
    // destructs before the mutex is released" -- was an attempt at the same guarantee:
    // Heap::Alloc follows it, Heap::Free does NOT -- it opens its window before any lock,
    // because CheckHeapHeader("pre-free") reads the guarded instance page and must run
    // disarmed. That is harmless now (depth, not ordering) and must stay so: every instance
    // read belongs in a window -- moving this below the lock trips F374-HEAPGUARD per free.
    // F-806b: `HeapGuardWindow` was defined HERE, i.e. AFTER the reporter rows at ~1482/~1556 that
    // now need it. It was moved up, next to this comment, so those reporters can open a window
    // before reading the instance. Behaviour is unchanged for every existing user: same two calls,
    // same order, same one-window-per-operation pairing. Do not move it back below the reporters.
    struct HeapGuardWindowForwardDeclIsNotEnough;  // no-op marker removed below
} // namespace

void* Heap::Alloc(size_t size)
{
    std::lock_guard lock(mutex);
    HeapGuardWindow hg;

    if (heap == nullptr)
        return nullptr;

    // F-370: is the header already broken before this call? Paired with the post-alloc check
    // below, a bad "pre" with a good "post" on the previous call means the corrupter was NOT a
    // heap operation at all (an external writer into guest 0x20000..). That writer is no longer
    // unnamed: F-375 Â§1 traced it to the title's own `memcpy`, reached by a vtable dispatch
    // through a stream-object field that holds the SIZE 0x20000 instead of a pointer.
    CheckHeapHeader("pre-alloc", size, heap, _ReturnAddress());

    // F-370 census: who takes a >=256 KiB slice of the guest's own user heap. The host Path A
    // fill and the guest's thread contexts (0x40e90 each) share this arena.
    if (size >= 0x40000)
    {
        static std::atomic<uint32_t> s_big{0};
        const uint32_t n = s_big.fetch_add(1) + 1;
        if (n <= 40 || (n % 200) == 0)
        {
            const O1HeapDiagnostics d = HeapDiag(heap);
            MCLA_LOG_WARN("F370-HEAP-BIG #{} size={:#x} used={:#x} peak={:#x} cap={:#x} oom={} "
                          "caller_rva={:#x}",
                          n, size, d.allocated, d.peak_allocated, d.capacity,
                          static_cast<unsigned long long>(d.oom_count),
                          CallerRva(_ReturnAddress()));
            if (n == 1)
            {
                // F-100 rule: a probe that only ever fires on failure cannot tell "the header
                // broke" from "my reader is broken". Dump the same 40 bytes while the header is
                // provably healthy (this is the first of 15 successful thread-context allocs), so
                // the later F373-HEAP-RAW line has a golden reference and a working reader.
                auto &gm = mcla::kernel::GuestMemoryHeap::Instance();
                uint8_t raw[40] = {};
                const bool got =
                    gm.ReadBytes(mcla::kernel::kUserHeapArenaVa, raw, static_cast<uint32_t>(sizeof(raw)));
                char hex[sizeof(raw) * 2 + 1] = {};
                for (size_t k = 0; k < sizeof(raw); ++k)
                    std::snprintf(&hex[k * 2], 3, "%02x", raw[k]);
                MCLA_LOG_WARN("F373-HEAP-GOLDEN #{} base={:p} read_ok={} cap={:#x} hex={}", n,
                              (void *)g_hdrArena, got, d.capacity, hex);
            }
        }
    }

    if (!o1heapDoInvariantsHold(heap))
    {
        static std::atomic<uint32_t> s_badMain{0};
        const uint32_t n = s_badMain.fetch_add(1) + 1;
        if (n <= 8 || (n % 200) == 0)
        {
            const O1HeapDiagnostics d = HeapDiag(heap);
            MCLA_LOG_ERROR("Alloc: o1heap invariants FAIL #{} size={:#x} cap={:#x} used={:#x} "
                           "peak={:#x} oom={} caller_rva={:#x}",
                           n, size, d.capacity, d.allocated, d.peak_allocated,
                           static_cast<unsigned long long>(d.oom_count),
                           CallerRva(_ReturnAddress()));
        }
        return nullptr;
    }
    void* ptr = MCLA_O1_ALLOC(heap, std::max<size_t>(1, size));
    if (ptr == nullptr)
    {
        static std::atomic<uint32_t> s_nullMain{0};
        const uint32_t n = s_nullMain.fetch_add(1) + 1;
        g_acct[kArenaUser].nullAlloc.fetch_add(1, std::memory_order_relaxed);
        if (n <= 8 || (n % 100) == 0)
        {
            const O1HeapDiagnostics d = HeapDiag(heap);
            MCLA_LOG_ERROR("Alloc: o1heapAllocate returned null #{} size={:#x} cap={:#x} "
                           "used={:#x} peak={:#x} oom={} caller_rva={:#x}",
                           n, size, d.capacity, d.allocated, d.peak_allocated,
                           static_cast<unsigned long long>(d.oom_count),
                           CallerRva(_ReturnAddress()));
        }
    }
    // HEAPLEAK: the USER arena's share of the census, recorded on both outcomes so a refusal is
    // counted as a refusal and not silently absorbed. Read-only; the footprint comes from the
    // header o1heap just wrote, which is the same unit Heap::Free's live probe hands back.
    RecordSite(kArenaUser, (uint32_t)size, _ReturnAddress());
    if (ptr != nullptr)
    {
        // F-639: the per-caller allocation census, same success-only condition and same footprint
        // unit as the row above, so `HEAPLEAK-TOP`'s n/req/frag subtract cleanly from
        // `HEAPLEAK-SUM`'s. The user arena has no alignment parameter (`Heap::Alloc(size_t)`,
        // heap.h:30), so the defalign counter is not fed here.
        const size_t frag = FragFootprint(ptr);
        AcctAlloc(kArenaUser, heap, size, frag);
        CensusAlloc(kArenaUser, _ReturnAddress(), size, frag, 0);
    }
    CheckHeapHeader("post-alloc", size, heap, _ReturnAddress());
    return ptr;
}

void* Heap::AllocPhysical(size_t size, size_t alignment)
{
    // F-639: remember whether the caller passed 0 alignment BEFORE the default below overwrites
    // it. The `defalign_n` counter is the measurement of the 4 KB default's real cost, and it can
    // only be exact if "asked for nothing" is captured here: by the time the allocation succeeds
    // the two are indistinguishable (a guest that asked for 0x1000 and a guest that asked for
    // nothing and was charged 0x1000 look identical), and a counter that cannot tell them apart
    // would measure the wrong thing. This is a local read of the argument; it changes no decision.
    const bool askedNoAlign = (alignment == 0);
    size = std::max<size_t>(1, size);
    // F-639: `alignment == 0 ? 0x1000 :` DELETED, so a zero argument now falls through to the
    // floor this function has always enforced -- `std::max<size_t>(16, alignment)`, unchanged and
    // in the same expression, so the smallest correct form is one deleted clause and no new
    // policy. The default was inherited verbatim from the reference
    // (.research/UnleashedRecomp/UnleashedRecomp/kernel/heap.cpp:25) and had no stated
    // justification anywhere; it is 256x the floor and 128x o1heap's own guarantee
    // (o1heap.h:34,90 "the returned pointer is guaranteed to be aligned at O1HEAP_ALIGNMENT" =
    // 32; o1heap.c:367 returns `frag + O1HEAP_ALIGNMENT`).
    //
    // THE CONTRACT FOR ZERO, from both references and from the guest's own sizes:
    //   * Xenia keeps a zero alignment at zero -- `xe::round_up(alignment, page_size)`
    //     (.research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_memory.cc:365) maps 0 to 0 -- and
    //     its own primary physical export passes 0 explicitly:
    //     `MmAllocatePhysicalMemory_entry` -> `..., 0, 0xFFFFFFFFu, 0` (same file:399). So 0 is an
    //     ORDINARY value meaning "no alignment requirement", not "unspecified, pick a page". Only
    //     the first reading justifies inventing 4 KB, and it is the one the other reference uses.
    //     Xenia gets its page granularity from the SIZE instead (`round_up(region_size, page_size)`,
    //     same file:364) -- a size policy that lives in imports.cpp:4417, not in this file.
    //   * The guest never asks for a page. Its XTL alloc thunk hardcodes the alignment:
    //     `82130538 li r5,16` (quoted at imports.cpp:94, read off
    //     build/cache/mcla_pe.bin at VA-0x82000000 per F-023), and `__xtl_alloc` clamps anything
    //     below 16 up to 16 (imports.cpp:68). So the game's own allocator asks for 16 and has
    //     never asked for 0x1000 in any soak on record.
    //   * The only in-tree path that can DELIVER 0 is `MmAllocatePhysicalMemoryEx`
    //     (imports.cpp:4417), which forwards the guest's Alignment argument. Every other caller
    //     cannot produce one: `AllocPhysical<T>` passes `alignof(T)` (heap.h:88), `XAllocMem`
    //     passes `1ull << ((flags>>24)&0xF)` in [1,32768] (this file, XAllocMem), and
    //     `GuestMemoryHeap::Alloc`'s own default is 16 (memory.h:54).
    //   * 16 is PROVABLY sufficient here, not merely the observed value. The bookkeeping guard
    //     below (`if (aligned < ptr + O1HEAP_ALIGNMENT) aligned += alignment`) puts the aligned
    //     user pointer at >= ptr+32 for every alignment >= 1, so `*((void**)aligned - 1)` and
    //     `*((size_t*)aligned - 2)` land at >= ptr+16 and can never touch the 32-byte o1heap
    //     fragment header at ptr-32..ptr-1 (o1heap.c:115-131). The floor is 16, and the extra
    //     `+ O1HEAP_ALIGNMENT` on `o1Amount` below is what pays for the two words -- an
    //     improvement over the reference, which omits it (UnleashedRecomp heap.cpp:29) and
    //     therefore writes them over the payload. w661 is the empirical check on the 16 floor:
    //     19,958 allocations served at `align=0x10` before the first refusal, `capacity` constant
    //     on all 23 PHYS-STATE rows, 0 `F370-HEAP-HDR` rows.
    //   * REFUTED, 2026-10-06, and the refutation is the reason for the 16 KB floor below. This
    //     bullet used to read "Nothing consumes a page-aligned physical pointer. `MapVirtual` is
    //     pure identity arithmetic on the arena window (memory.cpp:300-309), so no host page, no
    //     aliasing and no page-table step depends on an individual fragment's alignment, and 4 KB
    //     bought nothing." Every host-side half of that is still true and is irrelevant: the
    //     consumer of a physical pointer's alignment is THE GUEST'S OWN SLAB ARITHMETIC, which no
    //     host-side survey can see. `sub_821C2840` (the guest heap init) masks the pointer we hand
    //     it down to a slab base and builds its header there:
    //         821C2884  54880022  rlwinm r8,r4,0,0,17   ; r8 = r4 & 0xFFFFC000  (~0x3FFF, 16 KB)
    //         821C2890  911F00F8  stw    r8,248(r31)    ; heap+248 = the masked base
    //     Raw words read at VA-0x82000000 per F-023; the emitted C++ agrees
    //     (`generated/ppc_xenon/ppc_recomp.15.cpp`, `ctx.r8.u64 = ... & 0xFFFFC000;`). Closure
    //     against the log: `HEAP76 ... +4=A0400290 +248=A0400000` (build/w736.log:941) -- both
    //     fields are satisfied by exactly r4 in [A0400261, A0400280], and A0400280 is the lowest VA
    //     this function can return (`:3176-3178`; corroborated `w736.log:245 big_guest=A0400280`).
    //     A0400280 & ~0x3FFF = A0400000 = OUR o1heap INSTANCE HEADER, which o1heapInit places at the
    //     arena base and which spans [A0400000, A0400240) (`o1heap.c:166` INSTANCE_SIZE_PADDED =
    //     0x240, `:312` first fragment at base+0x240, `heap.cpp:2413` init site). The guest then
    //     zero-sweeps it: `HEAPHDR-STORE` (`gpu_cp.cpp:7434-7458`) fired its 200-row cap covering
    //     183 distinct addresses in [A0400000, A04004C0), 164 of them storing 00000000, the
    //     dominant run being 137 contiguous stride-4 zeros from A0400000 (a memcpy whose dst is
    //     caller-supplied, `lr=821BE3BC` = `sub_821BE250+0x16c`, `821BE3B8 bl 0x823DA950`).
    //     `diagnostics.capacity` lives at instance+0x208, inside that sweep, which is why it reads
    //     0: `AllocPhysical: o1heap invariants FAIL #1 size=0x19d align=0x10 cap=0 peak=0`
    //     (w736.log:33535) followed 1:1 in the same millisecond by `XTL-ALLOC-REFUSED #1 size=413
    //     align=16 -> returned 0` (imports.cpp:184) x4 -- and the guest never tests r3 there, so the
    //     null propagates into an unconstructed object and a zero vtable slot.
    //   * WHY 16 KB AND NOT 4 KB -- a page floor is not a cheaper fix, it is a non-fix. The mask is
    //     ~0x3FFF, so on a 4 KB-aligned pointer `ptr & ~0x3FFF` is still up to 0x3000 BELOW ptr and
    //     still lands in the header. Only a granule >= the guest's own makes mask-down the identity,
    //     so the slab base equals the pointer we returned and the guest writes only inside memory it
    //     was given. In-tree precedent for the same mask, measured earlier and independently:
    //     `alloc_census.cpp:346`, `slab = elem & ~0x3FFF` = A0400000 from elem = A0401020.
    //   * COST, measured not estimated: `o1Amount` at `:3040` is `size + alignment + 32` and the
    //     granular charge rounds that up to 4 KB, so the floor adds <= 16 KB per allocation. w736
    //     served 3,776 physical allocations (~59 MB extra) with peak live 373.6 MB
    //     (`used_ppm=729615`) and minimum free 138.4 MB, leaving ~79 MB. Larger requested
    //     alignments survive (`XAllocMem`'s up to 0x8000, `MmAllocatePhysicalMemoryEx`'s forwarded
    //     argument) because this is a floor, not an assignment. The w661 evidence the 16 floor used
    //     to cite (19,958 allocations at align=0x10) predates the guest ever reaching its heap init
    //     and does not bound this cost; if a future boot multiplies the allocation count enough to
    //     exhaust the arena, `PHYS-POOL-FULL` / `returned null` will name it.
    constexpr size_t kPhysSlabGranule = 0x4000;  // the guest's own slab mask, ~0x3FFF, measured above
    // T43.16 (2026-10-12): SCOPE the slab floor to slab-scale requests.
    // The floor has exactly ONE consumer: sub_821C2840 masks the pointer with
    // ~0x3FFF and builds its header at the masked base (proof :3200-3236).
    // A request smaller than the granule can never be a slab the guest
    // heap-inits -- the guest heap-init runs on arena-scale regions -- so
    // charging every 14-byte XTL string-dup 16 KB is pure overcharge
    // (~125 MiB over 8,000 asks, F-792 S2, the T43.2 exhaustion driver).
    // Slab-scale requests keep the EXACT old behavior (floor + pow2 below
    // unchanged); small requests keep max(16, pow2) which the :3185-3194
    // bookkeeping proof already shows sufficient. Explicit large alignments
    // (XAllocMem up to 0x8000, MmAllocatePhysicalMemoryEx forwards) survive
    // on both arms via max(). Falsifier: HEAP76 census (:3207) naming a
    // slab-init on a sub-granule block -- revert this scope if it fires.
    // Counters, throttled rows (first 8 + every 4096th): ~10 rows per boot,
    // nowhere near F-054 scale.
    static std::atomic<uint64_t> s_slabFloorKept{0};
    static std::atomic<uint64_t> s_slabFloorRelaxed{0};
    if (size >= kPhysSlabGranule) {
        alignment = std::max<size_t>(kPhysSlabGranule, alignment);
        const uint64_t n = s_slabFloorKept.fetch_add(1, std::memory_order_relaxed) + 1;
        if (n <= 8 || (n % 4096u) == 0u) {
            MCLA_LOG_WARN("SLAB-FLOOR kept #{} size={:#x} align={:#x} (slab-scale, old behavior)",
                          n, size, alignment);
        }
    } else {
        alignment = std::max<size_t>(16, alignment);
        const uint64_t n = s_slabFloorRelaxed.fetch_add(1, std::memory_order_relaxed) + 1;
        if (n <= 8 || (n % 4096u) == 0u) {
            MCLA_LOG_WARN("SLAB-FLOOR relaxed #{} size={:#x} align={:#x} kept={} (T43.16 scope)",
                          n, size, alignment,
                          s_slabFloorKept.load(std::memory_order_relaxed));
        }
    }
    // Session 72: guest can pass non-pow2 (observed 0x404). The
    // `& ~(alignment-1)` mask is only valid for pow2 â€” a non-pow2 alignment
    // produced a misaligned user pointer and the bookkeeping words written
    // below it corrupted o1heap fragment headers (AV in o1heapAllocate).
    {
        size_t p2 = 16;
        while (p2 < alignment)
            p2 <<= 1;
        alignment = p2;
    }

    std::lock_guard lock(physicalMutex);
    HeapGuardWindow hg;  // F-388: both header guards off while an allocator is in flight

    if (physicalHeap == nullptr)
        return nullptr;

    // F-386 census (READ-ONLY, no behaviour change): the invariants check below PASSES in every boot
    // that still AVs inside `o1heapAllocate` -- w394/w395/w396/w397 each log exactly one
    // `code=0xC0000005 rva=0x206C_8 = o1heapAllocate+0x98`, Param[0]=1 (a WRITE) to 0xE49125FC with
    // rcx=0xE49125D4. That address is a GUEST VA in the physical band being used as a host pointer,
    // and +0x28 is the `prev_free` field of `struct Fragment` (src/kernel/o1heap.c:123-131), so the
    // walk was following a poisoned free-list link that `o1heapDoInvariantsHold` never dereferences.
    // Validate what the allocator is actually about to chase: the 64 bin heads (the first 512 bytes of
    // the instance -- `O1HeapInstance{bins[], mask, diagnostics}`, o1heap.c:133-138, F-375's
    // correction) and then the links themselves. A bad value is reported with the physical-allocation
    // registry's own answer for "is this number a buffer we handed the guest, and who asked for it".
    if (physArenaBase != nullptr)
    {
        static std::atomic<uint32_t> s_binBad{0};
        static std::atomic<uint32_t> s_physCalls{0};
        const uint32_t call = s_physCalls.fetch_add(1) + 1;
        const uintptr_t lo = (uintptr_t)physArenaBase;
        const uintptr_t hi = lo + physArenaSize;
        uint32_t bad = 0;
        int badSlot = -1;
        uintptr_t badVal = 0;
        uintptr_t bins[64] = {};
        std::memcpy(bins, (const void *)physArenaBase, sizeof(bins));
        for (int i = 0; i < 64; ++i)
        {
            const uintptr_t v = bins[i];
            if (v != 0 && (v < lo || v >= hi))
            {
                ++bad;
                if (badSlot < 0)
                {
                    badSlot = i;
                    badVal = v;
                }
            }
        }
        // The links are where the poison actually lives if the bin heads look sane: follow each
        // non-empty bin for a bounded number of hops and check every pointer.
        // F-386 (second revision -- F-387 itself left no source change): the first version checked
        // only the 64 bin heads on every call, and `w398` measured that as blind exactly when it
        // mattered (`F386-PHYSFREE` printed 0 rows there while the AV still fired; same in `w399`
        // with heads + sampler, so the poison is either created after the check or deeper in a
        // list than the sample reached). Now a round-robin SAMPLER: 8 nodes per call, advancing
        // globally, so a poison that persists in a list is found within a handful of calls while the
        // per-call cost stays negligible. The value it is looking for has an exact signature in the
        // fault dump: node = 0xE49125D4 with rdi = r8 = 0x1A0000000 (the arena's host base), i.e. a
        // host pointer to physical memory (Translate(0xE49125D4) = 0x1E49125D4) that lost its high
        // dword -- a 32-bit GUEST pointer written into a 64-bit host link field.
        int linkHop = -1;
        uintptr_t linkVal = 0;
        if (bad == 0)
        {
            static std::atomic<uint32_t> s_walkCursor{0};
            uint32_t cur = s_walkCursor.fetch_add(8) % 64;
            for (int k = 0; k < 8 && linkHop < 0; ++k)
            {
                const int b = (int)((cur + (uint32_t)k) % 64u);
                uintptr_t p = bins[b];
                for (int hop = 0; p != 0 && hop < 8; ++hop)
                {
                    if (p < lo || p >= hi)
                    {
                        linkVal = p;
                        linkHop = hop;
                        bad = 1;
                        badSlot = b;
                        break;
                    }
                    uintptr_t nxt = 0;
                    // Fragment = { header{next@0,prev@8,size@16,used@24}, next_free@32, prev_free@40 }
                    // (src/kernel/o1heap.c:115-131; O1HEAP_ALIGNMENT is 32, so the header is 32 bytes).
                    // The AV writes node+0x28 = prev_free, i.e. an unlink through a poisoned link.
                    std::memcpy(&nxt, (const void *)(p + 32), sizeof(nxt));  // Fragment::next_free
                    p = nxt;
                }
            }
        }
        if (bad != 0)
        {
            const uint32_t n = s_binBad.fetch_add(1) + 1;
            if (n <= 4)
            {
                const uintptr_t gv = bad ? (badVal ? badVal : linkVal) : 0;
                const uint32_t bogus = (uint32_t)(gv & 0xFFFFFFFFu);
                uint32_t ab = 0, asz = 0, alr = 0;
                bool exact = false;
                const bool known =
                    mcla::kernel::MclaPhysAllocInfo(bogus, &ab, &asz, &alr, &exact);
                uint32_t nb = 0, nsz = 0;
                const bool below =
                    mcla::kernel::MclaPhysNearestAllocBelow(bogus, &nb, &nsz);
                uint32_t glr = 0;
                if (const PPCContext *c = GetPPCContext())
                    glr = (uint32_t)c->lr;
                MCLA_LOG_ERROR("F386-PHYSFREE #{} call={} kind={} bin={} hop={} value={:X} "
                               "high4zero={} plusWindowInArena={} asGuestVa={:08X} allocInfo={} "
                               "base={:08X} size={:X} reqLr={:08X} exact={} nearestBelow={} "
                               "below={:08X}+{:X} guestLr={:08X} tid={}",
                               n, call, (badVal != 0) ? "binhead" : "link", badSlot, linkHop,
                               (unsigned long long)gv, gv < 0x100000000ull ? 1 : 0,
                               (gv < 0x100000000ull && (lo + 0x0000000100000000ull) >= lo &&
                                (gv + 0x0000000100000000ull) >= lo &&
                                (gv + 0x0000000100000000ull) < hi)
                                   ? 1
                                   : 0,
                               bogus,
                               known ? 1 : 0, ab, asz, alr, exact ? 1 : 0, below ? 1 : 0, nb, nsz,
                               glr, GetCurrentThreadId());
            }
        }
    }

    // Session 72: post-present AV inside o1heapAllocate walking a corrupted
    // free list (CDCDCDCD class). Refuse the alloc here when the invariants
    // are already broken, so the guest takes its own OOM path. Scope, per
    // F-386: this check does NOT catch the boot AV -- `o1heapDoInvariantsHold`
    // returns TRUE in every soak that still faults (`invariants FAIL` count 0
    // while `o1heapAllocate+0x98` AVs once per boot), because a poisoned free
    // list link is exactly what the check never dereferences (0 `invariants FAIL` and 0
    // `returned null` rows in w394..w398, which still AV once each). What turns the fault into a
    // null is the SEH wrapper: MCLA_O1_ALLOC -> SehO1Allocate catches it, so w578 shows
    // 293,212 `o1heap AV fault-addr=` rows against 2,940 printed `AllocPhysical: o1heapAllocate
    // returned null` rows (that row is capped to the first 8 + every 100th, so the printed count
    // is not the refusal count) -- that refusal, not this one, is what keeps the process alive.
    //
    // T43.1: `o1Amount` and the F-640 attempt counter are computed HERE, above this gate, because
    // the gate's refusal path now emits the same three rows the allocation-refusal path below does.
    // Both are pure functions of the two parameters and `alignment` was already finalised by the
    // slab floor and the pow2 round-up above the lock, so the value is IDENTICAL to the one this
    // line used to produce after the gate -- the hoist moves a declaration, it changes no number.
    // Hoisting the attempt is what keeps `attempts == served + refused` true once an invariant
    // refusal increments `refused` (F-640's own rationale is quoted at its former site below).
    const size_t o1Amount = size + alignment + O1HEAP_ALIGNMENT;  // F-631: named so the rows report
                                                                  // the size o1heap actually classified
    NotePhysAttempt();

    // T43.1 CONTROL -- A FAULT INJECTOR, NOT A MITIGATION, and the direction is the safe one.
    // Setting MCLA_T43_FORCE_INV_GATE=1 makes this gate fire on a HEALTHY heap, so the three rows
    // below can be SHOWN firing rather than argued about (LONG_TODO §1 rule 19: a zero is not a
    // result until the instrument is seen on an event you know happened). It exists because
    // post-F-779 the guest no longer zeroes our instance header, so `invariants FAIL` measures
    // **4 rows in each of w736..w740 and 0 in both w741 and w741b** -- a normal soak of the fixed
    // tree CANNOT reach this path, and without the control the fix would ship on a prediction.
    // Read once into a function-local static, defaults off, and when on it refuses EVERY physical
    // allocation so the boot fails loudly and immediately. That is the opposite of the failure mode
    // this project keeps getting burned by (`kBe710MagicWrite` suppressed 57 fatals and made a
    // broken boot look healthy for as long as it lived): an injector that makes things visibly
    // worse cannot masquerade as a fix.
    //
    // IT STAYS (F-781 §7). The control run is on disk -- `build/w742ctl.log:210-215`, which is the
    // only place in 313 logs where `PHYS-POOL-FULL` has ever printed -- but deleting the injector
    // would make this path unfalsifiable again for exactly as long as F-779's fix holds, which is
    // the situation that produced the defect in the first place. Default-off, one getenv read per
    // process, and it is registered in PROGRAM_GUIDE §7/§9 so an unregistered control is never
    // mistaken for a silent short-circuit (do-not #9).
    static const bool kT43ForceInvGate = [] {
        const char *e = std::getenv("MCLA_T43_FORCE_INV_GATE");
        return e != nullptr && e[0] == '1';
    }();
    if (kT43ForceInvGate || !o1heapDoInvariantsHold(physicalHeap))
    {
        static std::atomic<uint32_t> s_badHeap{0};
        const uint32_t n = s_badHeap.fetch_add(1) + 1;
        if (n <= 8 || (n % 200) == 0)
        {
            const auto d = o1heapGetDiagnostics(physicalHeap);
            MCLA_LOG_ERROR("AllocPhysical: o1heap invariants FAIL #{} size={:#x} "
                           "align={:#x} cap={} peak={}",
                           n, size, alignment, d.capacity, d.peak_allocated);
        }
        // First failure: dump a few fragment headers so we can see what
        // overwrote the free list (CDCDCDCD / wild next ptr).
        if (n == 1 && physArenaBase != nullptr)
        {
            const uint8_t* p = physArenaBase;
            // O1HeapInstance is at arena start; fragment headers follow.
            // Dump first 8 qwords of the instance + first fragment area.
            uint64_t words[16] = {};
            std::memcpy(words, p, sizeof(words));
            MCLA_LOG_ERROR("o1heap arena[0..127]: {:016X} {:016X} {:016X} {:016X}",
                           words[0], words[1], words[2], words[3]);
            MCLA_LOG_ERROR("o1heap arena[32..]: {:016X} {:016X} {:016X} {:016X}",
                           words[4], words[5], words[6], words[7]);
        }
        // T43.1: THE ORDERING FIX. This `return nullptr` used to be the last word the pool got. It
        // executed BEFORE `EmitPhysState` / `NotePhysVerdict` / `NotePhysPoolFull`, which all live in
        // the `ptr == nullptr` block below that this path never reaches -- and `NotePhysAttempt()`
        // sat below it too, so F-640's counters missed these refusals entirely. Measured cost, from
        // the four logs where this gate actually fired: `w736` holds four
        // `AllocPhysical: o1heap invariants FAIL #1..#4 size=0x19d align=0x10 cap=0 peak=0` rows at
        // `:33535/:33540/:33543/:33546`, and its ONE `PHYS-VERDICT-CHANGE` row is `:910`
        // (`none -> healthy why=suitable_class_present refusals=0 req_amt=0x0`, 14:50:17 -- from the
        // FREE path, `req_amt=0x0`, 2 m 16 s earlier), with **`PHYS-STATE` 0 rows and
        // `PHYS-POOL-FULL` 0 rows in the whole log**. So the last thing that run said about a pool
        // that was refusing every request was "healthy". Same defect class as the stale
        // `PARK-SAMPLE` mirror (F-627/F-628 Correction 2): the row mirrors the last time the code
        // REACHED it, not the present state.
        //
        // These are the same three calls with the same arguments the block below makes, so one
        // request cannot be classified differently by the two refusal paths, and `_ReturnAddress()`
        // is this function's own return address from either site, so `caller_rva` is unchanged.
        // NO NEW FIELD IS NEEDED to tell the paths apart: `ClassifyPhysPool` maps `d.capacity == 0`
        // to `destroyed-header why=capacity_zero` (`:781-787`), and `cap=0` on this path is already
        // measured in those same four logs, so the row names its own origin. The switch in
        // `NotePhysPoolFull` has an explicit `default:` arm for `DestroyedHeader` that increments
        // `destroyed` (`:1500-1502`), i.e. the bucket lands honestly rather than in `exhausted`.
        // Cost: `EmitPhysState` also drives the incremental 4 GiB PHYS-LIVE sweep while
        // `physicalMutex` is held -- ONE EMISSION PER REFUSAL (no cadence gate reaches
        // `NotePhysLive`; w755 printed 256 rows for 256 refusals), 16 MiB each since T43.1c/F-791
        // (~2.6 ms at the measured 6.2 GB/s; was 256 MiB ~41 ms). The old claim here -- 16 rows
        // then a stop when the pass completes -- described neither: w755 completed 16 passes
        // without stopping. Changes no decision and no return value.
        EmitPhysState(o1Amount, alignment, _ReturnAddress());
        NotePhysVerdict(o1Amount, _ReturnAddress());
        NotePhysPoolFull(o1Amount, _ReturnAddress());
        return nullptr;
    }

    // Extra head-room guarantees the aligned user pointer sits at least one
    // O1HEAP_ALIGNMENT above the raw o1heap user pointer, so the two
    // bookkeeping words written below it can never overlap the o1heap
    // fragment header (next@-32, prev@-24, size@-16, used@-8). Overlapping it
    // destroyed the pow2-size/used invariants IsLiveAllocation checks.
    // (That head-room is exactly what the `+ O1HEAP_ALIGNMENT` term in the HOISTED `o1Amount`
    // above the invariant gate pays for; the declaration itself moved there for T43.1.)
    //
    // F-640: ATTEMPTS AND OUTCOMES, counted on the way in and on the way out, so the refusal tally
    // has a denominator that the refusal path's own sampling cadence cannot bias. One relaxed
    // increment on a path that already takes a lock and walks a buddy allocator's bins; it changes
    // no decision and no return value. **T43.1 moved the `NotePhysAttempt()` call itself above the
    // invariant gate** so that an invariant refusal is counted as an attempt as well as a refusal,
    // which is what keeps `attempts == served + refused` arithmetically true now that
    // `NotePhysPoolFull` runs on that path too. The increment, its cost and its meaning are
    // unchanged; only its position moved.
    // F-641/F-642: ROUTE, AND THE ROUTING IS THE FIX. `o1heapAllocate` charges
    // `roundUpToPowerOf2(amount + O1HEAP_ALIGNMENT)`. F-641 first used that as a defect only when the
    // class exceeded the whole arena (build/w665.log: o1_amount=0x12b80030 -> class 0x20000000 against
    // capacity 0x1FFFFDC0, one 431.9 MiB run present and unreachable, then `'ExternalAllocator - Out
    // of virtual memory'`). build/w672.log then showed the narrower threshold was wrong: a 0x40000
    // request was refused at `free=0x4f540` because its class 0x80000 was DOUBLE the payload while
    // the page charge 0x42000 fitted in the bytes already free (w672.log:44586-44589), after 6,691
    // requests had charged 536,545,408 of the console's 536,870,336 bytes. The console rounds to a
    // PAGE and scans a per-page table, with no size class anywhere in the chain
    // (.research/xenia/src/xenia/kernel/xboxkrnl/xboxkrnl_memory.cc:364 -> memory.cc:924,934,949-988),
    // so EVERY request on this pool goes to `o1heapAllocateGranular`, which charges
    // `roundUp(amount + 32, 4096)`.
    //
    // F-642: THE THRESHOLD IS GONE, and `O1UsesGranularPolicy` is `true`. The space and time costs
    // that replace it are measured in the F-642 block beside `kO1PageGranule` (quoted by symbol):
    // 1.5130x fewer charged bytes on w672's own measured requests, for +2.77% of allocation time
    // (+24.9 ns, 167 us across the whole run) and 0 skipped hops in 13,386 granular calls. A threshold
    // would only pay if the two policies charged the SAME bytes somewhere and one were cheaper in
    // time; they never do, because the page rule is <= the power-of-two rule for every charge that is
    // a whole number of pages and the console has no class to prefer.
    //
    // `capBefore` is still read HERE, inside physicalMutex, and still names the same diagnostics copy
    // the refusal path below reads, so nothing on this path can disagree with the rows. Under this
    // policy it decides nothing -- which is the point: the routing no longer depends on which arena
    // is bound (`AttachPhysicalArena` can rebind it) or on how full the pool is.
    const size_t capBefore = HeapDiag(physicalHeap).capacity;
    const bool granular = O1UsesGranularPolicy(o1Amount, capBefore);
    if (!granular)
    {
        // T43.19: the sub-page lever took this request. Counted and printed (throttled) so a soak
        // measures the take rate; the accounting below is unchanged and still measures the header.
        static std::atomic<uint64_t> s_subPageRouted{0};
        const uint64_t n = s_subPageRouted.fetch_add(1, std::memory_order_relaxed) + 1;
        if (n <= 8 || (n % 4096u) == 0u)
            MCLA_LOG_WARN("SUB-PAGE-ROUTED #{} amount={:#x} pow2_would_be={:#x} "
                          "page_saved={:#x} (T43.19: mcla_phys_subpage=1; divergence vs console "
                          "page charging is DELIBERATE and cvar-gated)",
                          n, o1Amount, O1RoundUpPow2(o1Amount + kO1HeapAlignment),
                          O1GranularCharge(o1Amount) -
                              O1RoundUpPow2(o1Amount + kO1HeapAlignment));
    }
    void* ptr = granular ? MCLA_O1_ALLOC_GRANULAR(physicalHeap, o1Amount, kO1PageGranule)
                         : MCLA_O1_ALLOC(physicalHeap, o1Amount);
    if (ptr != nullptr)
    {
        NotePhysServed();
        // F-641: the largest request SERVED and what it actually cost, measured out of the header the
        // allocator wrote rather than predicted. Recorded on BOTH paths, not just the large one:
        // `max_served` is the field that answers "did this pool ever serve something big", and it has
        // to cover the binned path too or the two are not comparable.
        PhysPoolBumpMax(g_physPool.maxServedReq, o1Amount);
        PhysPoolBumpMax(g_physPool.maxServedFrag, FragFootprint(ptr));
        // F-642: THE CORRECTED ACCOUNTING, on every success, before anything that can print a row.
        // `FragFootprint` reads the header the allocator just wrote, so `charge` here is a MEASUREMENT
        // and not the predicted `O1GranularCharge`, and the two are cross-checkable on every
        // `PHYS-LARGE` row by anyone who wants to confirm the allocator charged what this file says
        // it charges. Placed outside the `granular` arm on purpose: it is the accounting for the POOL,
        // not for one of the two allocators, so it must cover every served request whatever routed it.
        NotePhysAcct(o1Amount, FragFootprint(ptr), size, alignment, _ReturnAddress());
        if (granular)
        {
            // F-641: the large path's own row, then the check that runs in place of the asserts the
            // -DNDEBUG build removed. `raw` is the o1heap pointer the guest bookkeeping words point
            // at, which is what `FragFootprint` and the free path both use.
            const size_t charge = O1GranularCharge(o1Amount);
            LargeRow lr;
            lr.req = o1Amount;
            lr.charge = charge;
            lr.frag = FragFootprint(ptr);
            lr.served = true;
            CheckGranularBlock("post-alloc", o1Amount, charge, ptr, physArenaBase, physArenaSize,
                               physicalHeap, _ReturnAddress());
            // F-642: under the page-granular policy `granular` is true for EVERY physical request, so
            // this row's cadence now describes the whole pool rather than a rare large path. The
            // cadence itself is UNCHANGED (first 4, then every 64th), which on w672's 6,691
            // allocations is 108 rows -- 0.011% of its 956,623 lines, against F-054's POISONED
            // ceiling. The fields are unchanged too, so every reader of this row keeps its meaning;
            // `path=granular` is simply no longer a distinguishing value.
            NotePhysLarge(lr, _ReturnAddress());
            // T43.2 POSITIVE CONTROL (LONG_TODO rule 19: a zero is not a result until the instrument
            // is shown firing on an event you know happened). w744's four rows all read
            // `head=0 min=0 max=0`, and an instrument that has never been seen printing a NONZERO
            // cannot distinguish "the arena's headers are zeroed" from "the probe reads the wrong
            // offset". One row is emitted on the FIRST served allocation, where the arena is
            // demonstrably working because the allocation succeeded, so a nonzero head_size there
            // proves the offset and makes the zeros at refusal the arena's state. `#0` is the row.
            static std::atomic<uint32_t> s_physProbeOkOnce{0};
            if (s_physProbeOkOnce.fetch_add(1u, std::memory_order_relaxed) == 0u)
                NotePhysBinProbe(physicalHeap, o1Amount, 0, _ReturnAddress(), physArenaBase,
                                 mcla::kernel::kPhysArenaBeginVa);
        }
    }
    if (ptr == nullptr && granular)
    {
        // F-641: a large-path REFUSAL is its own row, because a refusal here is a different event
        // from a binned refusal: the binned path can refuse for lack of room, but the large path
        // refuses only when no run in the whole arena is as long as the request, so the reason is
        // always a layout fact and never a rounding fact. `capped_walks` on the row separates the
        // third possibility -- a free list that could not be walked, i.e. corruption.
        LargeRow lr;
        lr.req = o1Amount;
        lr.charge = O1GranularCharge(o1Amount);
        lr.frag = 0;
        lr.served = false;
        NotePhysLarge(lr, _ReturnAddress());
    }
    if (ptr == nullptr)
    {
        static std::atomic<uint32_t> s_nullPtr{0};
        const uint32_t n = s_nullPtr.fetch_add(1) + 1;
        g_acct[kArenaPhys].nullAlloc.fetch_add(1, std::memory_order_relaxed);
        // F-631: the refusal is the row that matters, so it now carries the allocator's real state.
        // `w654` refused 8,700 times with `size=` and `align=` and nothing else -- that exe's
        // heap.cpp predates this row -- so the run produced a number nobody could interpret and
        // F-630 read it as a destroyed allocator when the leading hypothesis is an ordinary full
        // pool. `o1_amount` is the payload+align+32 handed to o1heap, `live`/`cap` are the real
        // o1heap words (NOT `PHYS-CENSUS total=`, which is a cumulative requested-bytes counter
        // reset above 200 MB, imports.cpp:2985-2999), and PHYS-STATE/NotePhysVerdict below add the
        // bin mask that separates "full" from "destroyed" outright.
        // Capped at the first 8 + every 100th exactly as before: 8,700 refusals in 53 s is past the
        // point where more lines add anything (F-054's POISONED rule), and PHYS-STATE owns the
        // unbounded-history question instead. F-638 cut that cadence 10x, to every 1,000th
        // refusal -- the old 10,000 was longer than w658's ENTIRE run (7,500 refusals), so a
        // period that long is a hope, not a period. See EmitPhysState for the derivation of 1,000.
        if (n <= 8 || (n % 100) == 0)
        {
            const O1HeapDiagnostics d = HeapDiag(physicalHeap);
            MCLA_LOG_ERROR("AllocPhysical: o1heapAllocate returned null #{} "
                           "size={:#x} align={:#x} o1_amount={:#x} live={:#x} cap={:#x} peak={:#x} "
                           "oom={} caller_rva={:#x} glr={:08X}",
                           n, size, alignment, o1Amount, d.allocated, d.capacity, d.peak_allocated,
                           (unsigned long long)d.oom_count,
                           CallerRva(_ReturnAddress()),
                           GetPPCContext() ? static_cast<uint32_t>(GetPPCContext()->lr) : 0u);
            // T43.2: the row above reports BIN PRESENCE (`live`/`cap`) and the PHYS-STATE row below
            // reports `bin_mask`; neither can answer why the granular scan returned NULL when a set
            // mask bit promised a fragment big enough. This replays that scan read-only and prints
            // the size words the allocator actually compared against the charge. `n` and
            // `_ReturnAddress()` come from the CALL SITE so the row pairs with the refusal above and
            // `caller_rva` stays AllocPhysical's caller, not AllocPhysical itself.
            NotePhysBinProbe(physicalHeap, o1Amount, n, _ReturnAddress(), physArenaBase,
                             mcla::kernel::kPhysArenaBeginVa);
        }
        // F-638: the periodic state row -- first 8 refusals, then every 1,000th, so the pool's
        // STATE HISTORY between two verdict transitions is on disk and not reconstructed from a
        // 30 s-stale HEAPLEAK-SUM row. The head count is the `n <= K` half of the house pattern
        // `n <= K || (n % M) == 0`: the first refusal is the only one that decides the question,
        // and it is the row w654 could not produce. NotePhysVerdict below adds the edge row.
        EmitPhysState(o1Amount, alignment, _ReturnAddress());
        // F-638: the amount goes in because `over-fragmented` and `healthy` are only decidable
        // against a size class -- with no class, `suitable` has nothing to be 0 with.
        NotePhysVerdict(o1Amount, _ReturnAddress());
        // F-640: the COUNTED refusal. Placed after PHYS-STATE and PHYS-VERDICT-CHANGE so those
        // two keep priority in the log ordering a reader already knows, and given the same
        // `o1Amount` so the three rows cannot classify one request differently. This is the row
        // that makes the console's own refusal visible: under the old 1,532 MiB pool a request
        // needing a 512.0 MiB fragment was served silently, so `over_cap=0` was not evidence of
        // health -- it was evidence the pool was too big to have an opinion.
        NotePhysPoolFull(o1Amount, _ReturnAddress());
        return nullptr;
    }

    uintptr_t aligned = ((uintptr_t)ptr + alignment) & ~(alignment - 1);
    if (aligned < (uintptr_t)ptr + O1HEAP_ALIGNMENT)
        aligned += alignment;

    // F-644: the guest-visible form of the aligned pointer, taken ONCE here. It was already being
    // computed further down for the WIN76 reachability window (quoted by marker) on the same path,
    // so this is a hoist of an existing pure call, not a new translation.
    const uintptr_t g = mcla::kernel::g_memory.MapVirtual((void*)aligned);

    *((void**)aligned - 1) = ptr;
    *((size_t*)aligned - 2) = size + O1HEAP_ALIGNMENT;

    // F-644: REMEMBER THE BIGGEST BLOCK'S GUEST ADDRESS, because nothing else in the tree records
    // one and without it the liveness question cannot even be posed (see the `PHYS-LIVE` block,
    // quoted by marker). Monotonic on `bigFrag`, and published size-FIRST so a concurrent reader
    // can pair a new size with a stale address but never a new address with a stale size -- a wrong
    // size is a wrong answer, a wrong address is a skipped row. `MapVirtual` is the inverse of
    // `Translate` and this pool is identity-mapped into the flat guest window, so the aligned host
    // pointer's guest form IS the address the guest holds, which is what makes the sweep in PHYS-LIVE
    // a search for something the guest genuinely stores. Recorded here, AFTER the aligned pointer
    // exists, because it is the ALIGNED pointer the guest is given, not the raw fragment.
    {
        const uint64_t frag = FragFootprint(ptr);
        if (frag > g_physPool.bigFrag.load(std::memory_order_relaxed))
        {
            g_physPool.bigFrag.store(frag, std::memory_order_relaxed);
            g_physPool.bigGuest.store(g, std::memory_order_relaxed);
            g_physPool.bigSize.store(size, std::memory_order_relaxed);
            g_physPool.bigSeq.store(g_physPool.pageN.load(std::memory_order_relaxed),
                                    std::memory_order_relaxed);
            g_physPool.bigGlr.store(GetPPCContext() ? static_cast<uint32_t>(GetPPCContext()->lr) : 0u,
                                    std::memory_order_relaxed);
            g_physPool.bigRva.store(CallerRva(_ReturnAddress()), std::memory_order_relaxed);
        }
    }

    LivePhysAllocs().insert((void*)aligned);

    // HEAPLEAK: the PHYSICAL arena's share of the census. The footprint counted is the RAW
    // fragment's, not the aligned user pointer's, because the raw fragment is what goes back to
    // o1heap in Heap::Free and what its live probe measures -- counting the aligned pointer's own
    // length here would sum two different units against one free.
    RecordSite(kArenaPhys, (uint32_t)size, _ReturnAddress());
    {
        // F-639: the physical arena's per-caller census. `defAlign` is 0xFFFFFFFF -- a value no
        // alignment can take, since the pow2 rounding above has already reduced every real
        // argument to 16..2^31 -- and means "the caller passed 0", i.e. the request that took the
        // zero-alignment default. Passing the EFFECTIVE alignment instead would count guests that
        // deliberately asked for a page, which is the opposite of what the counter is for. After
        // F-639's change the effective alignment for that subset is the 16 floor, so the subset is
        // identified by the ARGUMENT (captured as `askedNoAlign` at the top of this function,
        // before the default clause consumed it), not by the value o1heap saw.
        const size_t frag = FragFootprint(*((void**)aligned - 1));
        AcctAlloc(kArenaPhys, physicalHeap, size, frag);
        CensusAlloc(kArenaPhys, _ReturnAddress(), size, frag,
                     askedNoAlign ? kDefAlignSentinel : (uint32_t)alignment);
    }

    // Session 76j: full ownership history of the overlap window (the holder
    // vs guest-slab-element collision). Log every alloc landing here.
    // REACHABILITY (F-391): the pool now starts at kPhysArenaBeginVa = 0xA0400000
    // (src/kernel/heap_arena.h:40), so a physical user pointer maps to a guest VA >= that and can
    // never fall in 0xA0017FE0..0xA0018060 -- 0 rows in every soak since F-391 (w403..w579). The
    // window is kept as the record of the collision F-391 removed: 0xA0017FE0 is inside the
    // title's own XTL heap (0xA0001000..0xA002FFC0), which is why we moved.
    {
        if (g >= 0xA0017FE0u && g < 0xA0018060u)
        {
            static std::atomic<uint32_t> s_winAlloc{0};
            const uint32_t n = s_winAlloc.fetch_add(1) + 1;
            uint32_t lr = 0;
            if (const PPCContext *c = GetPPCContext())
                lr = static_cast<uint32_t>(c->lr);
            MCLA_LOG_WARN("WIN76-ALLOC #{} guest={:08X} size={:#x} align={:#x} "
                          "lr={:08X}",
                          n, g, size, alignment, lr);
        }
    }
    return (void*)aligned;
}

namespace
{
    // F-646: PHYS-FREE's running census, the same three fields XTL-FREE-SUM
    // carries (src/kernel/imports.cpp, anchored on the literal "XTL-FREE-SUM"),
    // because build/w677.log (READ ONLY) shows the same defect one level down:
    // the marker is gated at `first 8, then every 4096th` and it printed
    // `total=` 8 in a 180 s run. Eight rows cannot support a claim about a pool
    // whose allocation side logged 10,052 PHYS-ACCT events. Density is NOT
    // raised here by cadence -- this site only ever sees the eight frees that
    // survive `__xtl_free`'s own gate, so a 1-in-N gate on 8 events can only
    // ever print 8 -- but the RUNNING TALLY rides on every row it does print,
    // and PHYS-FREE-SUM below adds an every-16th row for a build where this
    // site is hot. The refusal split is the point: `non-exact` is
    // `LivePhysAllocs().erase(ptr) == 0` and `non-live` is the failed
    // `IsLiveAllocation`, and those are the two answers a reader needs to tell a
    // bookkeeping refusal (b) from a pointer this allocator never produced (a).
    std::atomic<uint64_t> s_physFreeOk{0};
    std::atomic<uint64_t> s_physFreeRejNotExact{0};
    std::atomic<uint64_t> s_physFreeRejNotLive{0};
    constexpr uint32_t kPhysFreeSumEvery = 16u;
} // namespace

void Heap::Free(void* ptr)
{
    if (ptr == nullptr)
        return;

    HeapGuardWindow hg;  // F-374: no header guard while we are inside the allocator

    CheckHeapHeader("pre-free", 0, heap, _ReturnAddress());  // F-370

    // F-631: the free path ROUTES BY ARENA BOUNDS, not by "is this host address at or above the
    // physical instance". `ptr >= physicalHeap` compares against the INSTANCE address, which is a
    // host pointer into the guest window and therefore moves with `GuestMemoryHeap::m_base`
    // (memory.cpp:204/211/227 -- an arbitrary VirtualAlloc when the 4 GiB fixed request fails), and
    // `AttachPhysicalArena` can rebind it to any base at all. `Heap::IsPhysicalArenaPtr`
    // (heap.h:63-67) is the same test written against the arena's real bounds, which is what the two
    // branches below actually assume: the physical branch reads `*(ptr-8)` as an o1heap raw pointer
    // and the user branch hands `ptr` to `o1heapFree(heap, ptr)` with no translation at all. Today
    // the two happen to agree for every in-window pointer (the user arena at 0x20000 is below the
    // physical one at 0xA0400000, so the comparison is accidentally right), which is exactly why a
    // wrong threshold here would have survived every soak on record: it is a mis-attribution hazard,
    // not a corruption one, and both branches end in a refusal. F-631 fixes it because the refusal
    // ROWS are now load-bearing evidence for the exhaustion question and must not be filed against
    // the wrong arena.
    if (IsPhysicalArenaPtr(ptr))
    {
        // Physical allocs carry custom bookkeeping just below the returned
        // pointer: *(ptr-8)=raw o1heap frag ptr, *(ptr-16)=size+32. Validate
        // the RAW pointer before touching o1heap bins.
        std::lock_guard lock(physicalMutex);

        // F-631: PHYS-FREE, the census `w654` could not have produced. That run has ZERO free rows of
        // any kind -- no `PHYS-FREE`, no `WIN76-FREE`, no `HEAPLEAK-SUM` (its exe predates the
        // accounting) -- and zero frees are the entire other half of the exhaustion reading: 512 KB
        // per request against a 1.4949 GiB pool is ~3,061 successful allocations to fill it, and
        // nothing gives any of it back. It also has to be here rather than in the accounting because
        // the accounting is only reached on the path that actually releases the fragment, so a
        // census placed after the live probe would print nothing about a REJECTED free, and a
        // rejected free is precisely the case where a caller believes it returned memory.
        // Counted in three buckets so the row answers "did frees happen, and were they honoured":
        // exact-and-live (the o1heapFree below runs), exact-but-not-live (refused, bytes kept), and
        // not-in-the-registry (refused before the arena was even consulted). Every free reaching
        // this function increments the total, so "no PHYS-FREE rows at all" is now a fact about the
        // title and not about the log.
        {
            static std::atomic<uint64_t> s_freeSeen{0};
            const uint64_t fs = s_freeSeen.fetch_add(1, std::memory_order_relaxed) + 1;
            const uint32_t glr = GetPPCContext() ? static_cast<uint32_t>(GetPPCContext()->lr) : 0u;
            // House cadence: the first 8 (the shape of a real free pattern), then every 4096th.
            if (fs <= 8 || (fs % 4096) == 0)
            {
                const O1HeapDiagnostics d = HeapDiag(physicalHeap);
                // No size field on purpose: the bookkeeping word that carries it lives at
                // `*(size_t*)ptr - 2` and reading it HERE would be an unguarded dereference of a
                // pointer that has not passed the live probe yet (a `__try` here would be the
                // clang-cl-in-a-locked-method crash the SEH wrappers exist to avoid,
                // heap.cpp:131-133). The byte accounting is `HEAPLEAK-SUM nfree/freed`, which is
                // taken after the probe; this row's only job is to prove a free ARRIVED and say
                // whether the pool was full at the time.
                MCLA_LOG_WARN("PHYS-FREE #{} total={} ptr={:p} guest={:08X} "
                              "o1_allocated={:#x} o1_capacity={:#x} o1_free={:#x} "
                              "caller_rva={:#x} glr={:08X} attempted={} honoured={} "
                              "refused={} rej_notexact={} rej_notlive={}",
                              (unsigned long long)fs, (unsigned long long)fs, (void *)ptr,
                              mcla::kernel::g_memory.MapVirtual(ptr), (uint64_t)d.allocated,
                              (uint64_t)d.capacity,
                              (uint64_t)(d.capacity > d.allocated ? d.capacity - d.allocated : 0),
                              CallerRva(_ReturnAddress()), glr,
                              (unsigned long long)fs,
                              (unsigned long long)s_physFreeOk.load(std::memory_order_relaxed),
                              (unsigned long long)(s_physFreeRejNotExact.load(std::memory_order_relaxed) +
                                                   s_physFreeRejNotLive.load(std::memory_order_relaxed)),
                              (unsigned long long)s_physFreeRejNotExact.load(std::memory_order_relaxed),
                              (unsigned long long)s_physFreeRejNotLive.load(std::memory_order_relaxed));
            }

            // F-646: PHYS-FREE-SUM -- the every-16th row. `unaccounted` is
            // `attempted - honoured - refused` and MUST read 0: this block sits
            // at the top of the physical branch and the only two returns below
            // it are the two refusal buckets it names, so a non-zero value would
            // mean an exit path this census does not classify.
            if ((fs % kPhysFreeSumEvery) == 0u)
            {
                const uint64_t ok = s_physFreeOk.load(std::memory_order_relaxed);
                const uint64_t ne = s_physFreeRejNotExact.load(std::memory_order_relaxed);
                const uint64_t nl = s_physFreeRejNotLive.load(std::memory_order_relaxed);
                const uint64_t rej = ne + nl;
                const O1HeapDiagnostics ds = HeapDiag(physicalHeap);
                MCLA_LOG_WARN("PHYS-FREE-SUM attempted={} honoured={} refused={} "
                              "unaccounted={} honoured_pct={:.4f} rej[non-exact]={} "
                              "rej[non-live]={} o1_allocated={:#x} o1_capacity={:#x} "
                              "o1_free={:#x} phys_freed_bytes={} caller_rva={:#x} glr={:08X}",
                              (unsigned long long)fs, (unsigned long long)ok, (unsigned long long)rej,
                              (unsigned long long)(fs >= ok + rej ? fs - ok - rej : 0ull),
                              // T43.17 (2026-10-13): pct is over ATTEMPTED, not
                              // accounted. The old denominator (ok+rej) excluded
                              // the 1 in-flight free, so every row printed
                              // 100.0000 while attempted = honoured+1. Same
                              // flaw class as XTL-FREE-SUM before its fix.
                              fs ? (static_cast<double>(ok) * 100.0 /
                                     static_cast<double>(fs))
                                 : 0.0,
                              (unsigned long long)ne, (unsigned long long)nl,
                              (uint64_t)ds.allocated, (uint64_t)ds.capacity,
                              (uint64_t)(ds.capacity > ds.allocated ? ds.capacity - ds.allocated : 0),
                              (unsigned long long)g_physPool.physFreedBytes.load(std::memory_order_relaxed),
                              CallerRva(_ReturnAddress()), glr);
            }
        }

        // Session 76j: enforce the exact-allocation contract first. Guest
        // sub-block frees must not reach o1heap even when the bytes below
        // them happen to look like a valid fragment header.
        if (LivePhysAllocs().erase(ptr) == 0)
        {
            static std::atomic<uint32_t> s_bogusFree{0};
            const uint32_t n = s_bogusFree.fetch_add(1) + 1;
            g_acct[kArenaPhys].rejFree.fetch_add(1, std::memory_order_relaxed);
            // F-646: UNGATED, because the whole point is that a refusal is
            // counted even when its row is not printed. The per-event row above
            // this one still gates at 8/4096, so on build/w677.log's numbers
            // (8 physical frees in 180 s) five of six refusals would have been
            // invisible; here they are on PHYS-FREE-SUM as rej[non-exact].
            s_physFreeRejNotExact.fetch_add(1, std::memory_order_relaxed);
            if (n <= 16)
            {
                uint32_t guestLr = 0;
                if (const PPCContext *c = GetPPCContext())
                    guestLr = static_cast<uint32_t>(c->lr);
                MCLA_LOG_WARN("Heap::Free: rejected NON-EXACT physical free "
                              "#{} ptr={:p} guest={:08X} in_arena={} lr={:08X}",
                              n, ptr, mcla::kernel::g_memory.MapVirtual(ptr), 1, guestLr);
                if (n == 1)
                {
                    // F-640: the same one-time symbol init, factored into EnsureSymInit() above so
                    // SymInitialize/ SymSetOptions are called from exactly ONE place no matter which
                    // of the two callers runs first. Identical options, identical arguments, one
                    // call site: this is an extraction, not a change.
                    EnsureSymInit();
                    void *frames[16] = {};
                    const USHORT nCap =
                        CaptureStackBackTrace(0, 16, frames, nullptr);
                    for (USHORT fi = 0; fi < nCap; ++fi)
                    {
                        alignas(8) char scratch[sizeof(SYMBOL_INFO) + 160];
                        SYMBOL_INFO *si = (SYMBOL_INFO *)scratch;
                        si->SizeOfStruct = sizeof(SYMBOL_INFO);
                        si->MaxNameLen = 159;
                        DWORD64 disp = 0;
                        char nameBuf[200];
                        const char *name = "???";
                        if (SymFromAddr(GetCurrentProcess(),
                                        (DWORD64)frames[fi], &disp, si))
                        {
                            snprintf(nameBuf, sizeof(nameBuf), "%s+0x%llx",
                                     si->Name, (unsigned long long)disp);
                            name = nameBuf;
                        }
                        MCLA_LOG_WARN("BOGUSFREE frame {:02d} {} {}", fi,
                                      (void *)frames[fi], name);
                    }
                }
            }
            return;
        }

        void* rawPtr = *((void**)ptr - 1);

        LiveProbe probe;
        if (!IsLiveAllocation(physArenaBase, physArenaSize, rawPtr, &probe))
        {
            g_acct[kArenaPhys].rejFree.fetch_add(1, std::memory_order_relaxed);
            s_physFreeRejNotLive.fetch_add(1, std::memory_order_relaxed);
            MCLA_LOG_WARN("Heap::Free: rejected non-live physical pointer {:p} "
                          "(raw={:p} reason={} hdr next={} prev={} size=0x{:X} used={} arena=[{:p},{:p}))",
                          ptr, rawPtr, ProbeReasonName(probe.reason), probe.next, probe.prev,
                          probe.size, probe.used, (void*)physArenaBase,
                          (void*)(physArenaBase + physArenaSize));
            return;
        }
        // HEAPLEAK: the bytes really go back to o1heap here, so this is where the arena's live
        // total falls. `probe.size` is the raw fragment's footprint -- the exact unit the alloc
        // side added. An SEH-absorbed free (SehO1Free) is still counted as returned, which is
        // the one known way `live` can over-report: HEAPLEAK-SUM's `live` vs `o1_alloc` pair is
        // what exposes that drift instead of hiding it.
        AcctFree(kArenaPhys, physicalHeap, probe.size);
        // Session 76j: log frees releasing any part of the overlap window. Same reachability as
        // the WIN76-ALLOC probe above: 0xA0017FE0..0xA0018060 is below kPhysArenaBeginVa since
        // F-391, so a live physical free can no longer report here either (0 rows w403..w579).
        {
            const uintptr_t g = mcla::kernel::g_memory.MapVirtual(ptr);
            const uintptr_t gsz = *((size_t*)ptr - 2);
            if (g + gsz >= 0xA0017FE0u && g < 0xA0018060u)
            {
                static std::atomic<uint32_t> s_winFree{0};
                const uint32_t n = s_winFree.fetch_add(1) + 1;
                uint32_t lr = 0;
                if (const PPCContext *c = GetPPCContext())
                    lr = static_cast<uint32_t>(c->lr);
                MCLA_LOG_WARN("WIN76-FREE #{} guest={:08X} size={:#x} lr={:08X}",
                              n, g, gsz, lr);
            }
        }
        MCLA_O1_FREE(physicalHeap, rawPtr);
        // F-644: THE BYTES THAT WENT BACK, as a number no row on record carried. `PHYS-FREE` prints
        // no size on purpose (its own comment: "No size field on purpose ... The byte accounting is
        // `HEAPLEAK-SUM nfree/freed`"), and `HEAPLEAK-SUM` fires every 20,000 events, so on
        // build/w675.log -- 10,052 events -- it printed twice and the two counters it would have
        // reconciled (`page_charge` 545,484,800 against `allocated` 0x1FFFF000 = 536,866,816) are
        // 8,617,984 = 8.22 MiB apart with nothing in the log able to say what closed the gap. This
        // closes it, from `probe.size`, which is the fragment's own header field -- the same unit the
        // alloc side charged -- so `page_charge - physFreedBytes - allocated` is now identically zero
        // on any run, and a reader can attribute every byte.
        g_physPool.physFreedBytes.fetch_add(probe.size, std::memory_order_relaxed);
        // F-646: PHYS-FREE's `honoured`, incremented HERE and not at the call so
        // that `honoured` and `phys_freed_bytes` cannot disagree: this is the
        // one place that knows the fragment's bytes were declared returned. It
        // also inherits the drift this file's comment above already names -- an
        // SEH-absorbed `o1heapFree` is counted as returned by both -- so the two
        // fields are wrong together rather than in opposite directions, and
        // HEAPLEAK-SUM's live-vs-o1_alloc pair still exposes it.
        s_physFreeOk.fetch_add(1, std::memory_order_relaxed);
        // F-644: AND WHETHER *THIS* FREE RELEASED THE BIGGEST BLOCK. The single field that turns
        // PHYS-LIVE's `freed=` from an inference into a measurement, and the one place in the tree
        // that can know: only `o1heapFree` on that exact fragment reduces `allocated`, and this is
        // the call. Latched, not counted -- a block cannot be freed twice.
        {
            const uint64_t bg = g_physPool.bigGuest.load(std::memory_order_relaxed);
            if (bg != 0 && (uint64_t)(uintptr_t)ptr == bg)
            {
                g_physPool.bigFreed.store(1, std::memory_order_relaxed);
            }
        }
        // F-631: the only path by which the pool can become healthy again, so it is the only place
        // the full->healthy edge can be observed. `w654` never reached it (zero free rows of any
        // kind), which is what left exhaustion unproven: nothing in that run ever returned a byte.
        // F-638: amount==0 says "no request of its own", so the class falls back to the last
        // REFUSED class. THIS IS THE CALL SITE THAT PRODUCED w658's ONLY VERDICT ROW FOR THE
        // WHOLE 120 s RUN: 19:41:16.087, caller_rva=0x253313, `refusals=0` -- 79 s before the
        // first refusal, on a pool that was not full yet. A pool-level verdict printed from
        // here with no request class is not evidence about the pool the refusals happened on,
        // which is why the refusal path now carries a class and the periodic PHYS-STATE row
        // exists at all.
        NotePhysVerdict(0, _ReturnAddress());
    }
    else
    {
        std::lock_guard lock(mutex);
        LiveProbe probe;
        if (!IsLiveAllocation(heapArenaBase, heapArenaSize, ptr, &probe))
        {
            g_acct[kArenaUser].rejFree.fetch_add(1, std::memory_order_relaxed);
            MCLA_LOG_WARN("Heap::Free: rejected non-live pointer {:p} "
                          "(reason={} hdr next={} prev={} size=0x{:X} used={} arena=[{:p},{:p}))",
                          ptr, ProbeReasonName(probe.reason), probe.next, probe.prev,
                          probe.size, probe.used, (void*)heapArenaBase,
                          (void*)(heapArenaBase + heapArenaSize));
            return;
        }
        // HEAPLEAK: same pairing as the physical branch above -- counted only on the path that
        // actually releases the fragment, and in the same footprint unit the alloc side used.
        AcctFree(kArenaUser, heap, probe.size);
        MCLA_O1_FREE(heap, ptr);
        // F-370: a free of a pointer that was live but whose neighbour bookkeeping was wrong
        // coalesces straight over the allocator's own header. If the header goes bad here rather
        // than at an alloc, this line names the freeing caller.
        CheckHeapHeader("post-free", reinterpret_cast<size_t>(ptr), heap, _ReturnAddress());
    }
}

size_t Heap::Size(void* ptr)
{
    if (!ptr) return 0;
    // Only read header if ptr was allocated from this heap
    LiveProbe probe;
    if (IsLiveAllocation(heapArenaBase, heapArenaSize, ptr, &probe))
        return *((size_t*)ptr - 2) - O1HEAP_ALIGNMENT;
    if (physicalHeap != nullptr && IsLiveAllocation(physArenaBase, physArenaSize, ptr, &probe))
        return *((size_t*)ptr - 2) - O1HEAP_ALIGNMENT;
    return 0;
}

uint32_t RtlAllocateHeap(uint32_t heapHandle, uint32_t flags, uint32_t size)
{
    void* ptr = g_userHeap.Alloc(size);
    if (!ptr) return 0;
    if ((flags & 0x8) != 0)
        memset(ptr, 0, size);

    assert(ptr);
    return mcla::kernel::g_memory.MapVirtual(ptr);
}

uint32_t RtlReAllocateHeap(uint32_t heapHandle, uint32_t flags, uint32_t memoryPointer, uint32_t size)
{
    void* ptr = g_userHeap.Alloc(size);
    if (!ptr) return 0;
    if ((flags & 0x8) != 0)
        memset(ptr, 0, size);

    if (memoryPointer != 0)
    {
        void* oldPtr = mcla::kernel::g_memory.Translate(memoryPointer);
        memcpy(ptr, oldPtr, std::min<size_t>(size, g_userHeap.Size(oldPtr)));
        g_userHeap.Free(oldPtr);
    }

    assert(ptr);
    return mcla::kernel::g_memory.MapVirtual(ptr);
}

uint32_t RtlFreeHeap(uint32_t heapHandle, uint32_t flags, uint32_t memoryPointer)
{
    if (memoryPointer != NULL)
        g_userHeap.Free(mcla::kernel::g_memory.Translate(memoryPointer));

    return true;
}

uint32_t RtlSizeHeap(uint32_t heapHandle, uint32_t flags, uint32_t memoryPointer)
{
    if (memoryPointer != NULL)
        return (uint32_t)g_userHeap.Size(mcla::kernel::g_memory.Translate(memoryPointer));

    return 0;
}

uint32_t XAllocMem(uint32_t size, uint32_t flags)
{
    // F-133 census (read-only; at most 40 lines per boot). The frontier's last
    // deterministic guest event is a physical allocation of 0xFFFFFFFF that
    // fails - once per boot, identical in w138/w140/w141 (w138:12555) - and the
    // guest then memcpy's that same length (r5=0xFFFFFFFF at the store site,
    // w142) for ~321 MB. MmAllocatePhysicalMemoryEx is ruled out as the caller
    // (its own FAILED line never prints), so name this import's caller: lr, the
    // flags bits (bit30 is the ones that would memset a null ptr below) and the
    // caller's stack words.
    // ANSWERED, and this probe is the negative half of it: F-134 Â§1 ran this census on w143 and
    // it printed 0 lines, so XAllocMem is NOT that caller -- the -1 came from the guest's own
    // `GetSize` error return (`sub_821BE8D8` -> `__xtl_alloc` -> `GuestMemoryHeap::Alloc`,
    // src/kernel/memory.cpp:334-344), and F-135's slot-recycle fix removed the request itself
    // (0 `size=0xffffffff` rows in w578/w579). Kept as the guard: a non-zero here now means that
    // shape came back through THIS import.
    if (size >= 0x04000000u)
    {
        static std::atomic<uint32_t> s_hugeAlloc{0};
        const uint32_t n = s_hugeAlloc.fetch_add(1) + 1;
        if (n <= 40)
        {
            uint32_t lr = 0, sp = 0, a3 = 0, a4 = 0, a5 = 0;
            uint32_t s[8] = {};
            if (const PPCContext *c = GetPPCContext())
            {
                lr = static_cast<uint32_t>(c->lr);
                sp = c->r1.u32;
                a3 = c->r3.u32;
                a4 = c->r4.u32;
                a5 = c->r5.u32;
                for (int k = 0; k < 8; ++k)
                    (void)mcla::kernel::GuestMemoryHeap::Instance().ReadU32BE(
                        sp + k * 4u, &s[k]);
            }
            MCLA_LOG_WARN("XALLOC-HUGE #{} size={:#x} flags={:08X} lr={:08X} "
                          "r3={:08X} r4={:08X} r5={:08X} sp={:08X} "
                          "stk=[{:08X} {:08X} {:08X} {:08X} {:08X} {:08X} "
                          "{:08X} {:08X}]",
                          n, size, flags, lr, a3, a4, a5, sp, s[0], s[1], s[2],
                          s[3], s[4], s[5], s[6], s[7]);
        }
    }
    void* ptr = (flags & 0x80000000) != 0 ?
        g_userHeap.AllocPhysical(size, (1ull << ((flags >> 24) & 0xF))) :
        g_userHeap.Alloc(size);

    // F-390b house style (cf. Heap::Alloc<T> heap.h:75-93, RtlAllocateHeap :796-797):
    // honest OOM returns null; zero-init must not memset(null). Same shape as the
    // fixed guest_thread.cpp:21-38 bug.
    if (ptr == nullptr)
        return 0;

    if ((flags & 0x40000000) != 0)
        memset(ptr, 0, size);

    assert(ptr);
    return mcla::kernel::g_memory.MapVirtual(ptr);
}

void XFreeMem(uint32_t baseAddress, uint32_t flags)
{
    if (baseAddress != NULL)
        g_userHeap.Free(mcla::kernel::g_memory.Translate(baseAddress));
}

GUEST_FUNCTION_STUB(sub_82BD7788); // HeapCreate
GUEST_FUNCTION_STUB(sub_82BD9250); // HeapDestroy

GUEST_FUNCTION_HOOK(sub_82BD7D30, RtlAllocateHeap);
GUEST_FUNCTION_HOOK(sub_82BD8600, RtlFreeHeap);
GUEST_FUNCTION_HOOK(sub_82BD88F0, RtlReAllocateHeap);
GUEST_FUNCTION_HOOK(sub_82BD6FD0, RtlSizeHeap);

GUEST_FUNCTION_HOOK(sub_831CC9C8, XAllocMem);
GUEST_FUNCTION_HOOK(sub_831CCA60, XFreeMem);
