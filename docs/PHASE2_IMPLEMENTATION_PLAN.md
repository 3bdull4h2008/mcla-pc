# Phase 2 Implementation Plan: Canonical Kernel Framework Rewrite

> **✅ STATUS: COMPLETED (2026-08-21/22).** Historical document — kept for the
> violation audit trail and loop-protocol methodology. Phase 2 gate: 13/13
> phase0_validator tests pass (re-verified 2026-09-03). Current work follows
> `MCLA_REBUILD_PLAN.md` (P4′ ladder) and `docs/BOOT_HANDOFF.md`.

## Executive Summary

MCLA's kernel layer currently violates the canonical UnleashedRecomp framework in several critical ways. This plan details the exact steps to rewrite the kernel framework to match `.research/UnleashedRecomp/kernel/` exactly, enabling Phase 3 (critical imports) to proceed on the correct foundation.

---

## Current Violations (from MCLA_REBUILD_PLAN.md §359-435)

| # | Violation | Current MCLA | Canonical Framework |
|---|-----------|--------------|---------------------|
| 1 | **Handle model** | Host-heap index handles (`handle & 0x80000000`) | Identity handles: `handle = guest VA`, `GetKernelObject = Translate` |
| 2 | **Import signatures** | Manual `ctx.rN` reads in many imports | Typed-arg `GUEST_FUNCTION_HOOK` one-liners only |
| 3 | **Competing implementations** | `kernel_stubs.cpp` + `kernel_stubs_body.inc` (two per import) | Single implementation per import in `imports.cpp` |
| 4 | **Critical section layout** | `OwningThread@0x10` (Windows-style, 24 bytes) | `OwningThread@0x18` (Xbox 360, 28 bytes) |
| 5 | **NOACCESS guard** | **PARTIAL** - implemented in `memory.cpp:16` but not validated | First page of 4GB `VirtualAlloc` = `PAGE_NOACCESS` |
| 6 | **Vd imports** | Partial impl with manual seeding | Full Xenia semantics, no manual seeding |
| 7 | **`ObReferenceObjectByHandle`** | **CORRECT** - already returns handle as pointer | `*object = handle; return 0;` |
| 8 | **`g_keSetEventGeneration`** | **PARTIAL** - exists but only for Event, not Semaphore | Full counter for `KeWaitForMultipleObjects` WAIT_ANY |
| 9 | **GuestThread pattern** | **PARTIAL** - exists but `GuestThreadHandle` not fully integrated | `GuestThread::Start` allocates PCR+TLS+TEB+Stack per thread |

---

## Step-by-Step Implementation Plan

### Step 2.1: Guest Physical Heap — Verify NOACCESS Guard + Round-trip ✅ MOSTLY DONE
**File:** `src/kernel/memory.cpp`, `src/kernel/memory.h`

**Actions:**
1. Confirm `VirtualProtect(base, 4096, PAGE_NOACCESS, &oldProtect)` on Windows (already line 16)
2. Confirm `mprotect(base, 4096, PROT_NONE)` on Linux (already line 26)
3. Ensure `GuestMemoryHeap::Adopt()` is wired from `boot::LoadAndPrepare` (P0-FixB done)
4. Add unit test assertion in `phase0_validator.cpp` for guard page (Test 1 already does this)

**Validation Gate:** `phase0_validator.exe` Test 1 passes (NOACCESS guard verified, round-trip works)

---

### Step 2.2: PPCContext Struct Layout ✅ DONE
**Status:** Already matches XenonRecomp layout. `ppc_context.h` has static_assert guards. No action needed.

---

### Step 2.3: `GUEST_FUNCTION_HOOK` + `HostToGuestFunction` / `ArgTranslator` Machinery
**File:** `src/kernel/function.h`

**Status:** MCLA's `function.h` is **identical** to UnleashedRecomp's `function.h` (verified line-by-line). The machinery exists but is **not applied consistently** in `imports.cpp`.

**Actions:**
1. No code changes to `function.h` needed
2. Audit ALL imports in `imports.cpp` — convert any remaining manual `ctx.rN` reads to typed signatures + `GUEST_FUNCTION_HOOK` one-liner
3. Delete `kernel_stubs.cpp` and `kernel_stubs_body.inc` (they contain the competing implementations)

**Validation Gate:** Zero manual `ctx.rN` reads in `imports.cpp`; `grep -n "ctx\." src/kernel/imports.cpp` returns only in `GuestThread` context, not in import implementations

---

### Step 2.4: `KernelObject` Hierarchy — Fix `Wait` Signature
**File:** `src/kernel/xdm.h`, `src/kernel/imports.cpp`

**Current MCLA:** `virtual uint32_t Wait(uint32_t timeout)` ✅ **Already correct** (single param)

**But:** Import wrappers must handle alertability, not pass to `Wait()`:
- `KeWaitForSingleObject` takes `Alertable` param → decides `STATUS_USER_APC` before calling `Wait()`
- `NtWaitForSingleObjectEx` takes `Alertable` param → decides `STATUS_USER_APC` before calling `Wait()`
- `KeWaitForMultipleObjects` takes `Alertable` → handles in wrapper

**Actions:**
1. Verify all `Wait()` calls in imports pass ONLY `timeout` (no `alertable`)
2. Verify alertability logic lives in import wrapper functions

**Validation Gate:** `grep -n "\.Wait(" src/kernel/imports.cpp` shows only single-arg calls

---

### Step 2.5: Identity Handles + `QueryKernelObject` Lazy-Wrap
**Files:** `src/kernel/xdm.h`, `src/kernel/xdm.cpp`, `src/kernel/imports.cpp`

**Critical Changes Required:**

#### 2.5.1 Fix `IsKernelObject` in `xdm.cpp`
```cpp
// CURRENT (WRONG - host-heap index model):
bool IsKernelObject(uint32_t handle) { return (handle & 0x80000000) != 0; }

// CANONICAL (identity handle model):
bool IsKernelObject(uint32_t handle) {
    // Kernel objects live in guest physical heap (high addresses)
    // Valid if handle != INVALID and Translate succeeds
    return handle != GUEST_INVALID_HANDLE_VALUE && g_memory.Translate(handle) != nullptr;
}
```

#### 2.5.2 Fix `GetKernelHandle` / `GetKernelObject` round-trip
- `GetKernelHandle(obj)` = `g_memory.MapVirtual(obj)` (guest VA of object)
- `GetKernelObject(handle)` = `reinterpret_cast<T*>(g_memory.Translate(handle))`
- **Identity:** `GetKernelObject(GetKernelHandle(obj)) == obj`

#### 2.5.3 `QueryKernelObject` Lazy-Wrap (already correct in `xdm.h:130-143`)
- Checks `header.WaitListHead.Flink != 'XBOX'`
- Creates host wrapper via `CreateKernelObject<T>(guest_header_ptr)`
- Caches wrapper's guest VA in `header.WaitListHead.Blink`
- Returns cached wrapper on subsequent calls

#### 2.5.4 Update ALL imports to use identity handles
- `NtCreateEvent` → `*handle = GetKernelHandle(CreateKernelObject<Event>(...))` ✅ Already correct
- `ObReferenceObjectByHandle` → `*object = handle; return 0;` ✅ Already correct
- `NtClose` → `DestroyKernelObject(handle)` (handle IS guest VA) ✅ Already correct
- `KeSetEvent` → takes `XKEVENT*` (guest VA), calls `QueryKernelObject<Event>(*pEvent)` ✅ Already correct

**Validation Gate:** `phase0_validator.exe` Tests 3, 4 pass (identity handles, lazy-wrap)

---

### Step 2.6: TLS/PCR Emulation — `GuestThread::Start` Pattern
**Files:** `src/kernel/guest_thread.h`, `src/kernel/guest_thread.cpp`

**Status:** MCLA implementation **matches** UnleashedRecomp exactly (verified line-by-line). PCR_SIZE=0xAB0, TLS_SIZE=0x100, TEB_SIZE=0x2E0, STACK_SIZE=0x40000.

**Actions:**
1. Verify `ExCreateThread` in `imports.cpp` uses `GuestThread::Start(params, &threadId)` pattern ✅ Line 1538-1551
2. Ensure `r13` = PCR base, `r1` = stack top per guest thread ✅ `GuestThreadContext` constructor

**Validation Gate:** `phase0_validator.exe` Test 8 passes

---

### Step 2.7: **DELETE `kernel_stubs_body.inc` and MCLA's `HandleTable`/`KernelObject`** — Replace ALL Imports
**Files to DELETE:**
- `src/kernel_stubs.cpp` (competing implementation layer)
- `src/kernel_stubs_body.inc` (hand-written stubs, 37+ dead/shadowed functions)

**Files to MODIFY:**
- `src/kernel/imports.cpp` → **Single source of truth** for ALL imports
- `src/kernel/xdm.h/cpp` → Identity handle helpers only
- `src/kernel/function.h` → Typed-arg machinery (unchanged)

**Import Migration Strategy:**
For each import in `kernel_stubs_body.inc`:
1. If already in `imports.cpp` with correct typed signature → **keep `imports.cpp` version, delete stub**
2. If only in `kernel_stubs_body.inc` as stub → **implement properly in `imports.cpp` with typed args**
3. If stub returns garbage `r3` → fix per 360 semantics (UnleashedRecomp + Xenia reference)

**Critical Imports to Implement/Verify (from Phase 3 table):**
| Import | Status | Action |
|--------|--------|--------|
| `NtCreateEvent` | ✅ Typed | Verify arg order (r5=eventType, r6=initialState) |
| `KeSetEvent` | ✅ Typed | Takes `XKEVENT*`, uses `QueryKernelObject` |
| `ObReferenceObjectByHandle` | ✅ Typed | Identity: `*object = handle` |
| `RtlEnterCriticalSection` / `RtlLeaveCriticalSection` | ✅ Typed | Fix critical section layout first |
| `KeDelayExecutionThread` | ✅ Typed | Alertable → `STATUS_USER_APC` |
| `MmAllocatePhysicalMemoryEx` | ✅ Typed | r3=flags, r4=size, return guest VA (no byteswap) |
| `VdGetSystemCommandBuffer` | ✅ Typed | Write `0xBEEF0000@p0`, `0xBEEF0001@p1` |
| `HalReturnToFirmware` | ✅ Typed | No-op return (not `std::exit`) |
| `MmQueryAllocationSize` | ✅ Typed | Real size tracking (not hardcoded 0x1000) |
| `ExCreateThread` | ✅ Typed | `GuestThread::Start` pattern |
| `KeWaitForMultipleObjects` | ✅ Typed | Generation counter for WAIT_ANY |
| `VdInitializeRingBuffer` | ✅ Typed | Xenia: zero ring, size=1<<(log2+3) |
| `VdEnableRingBufferRPtrWriteBack` | ✅ Typed | CP_RB_RPTR_ADDR 0x70C |
| `VdInitializeEngines` | ⚠️ Partial | Full GPU context init (spinlocks, cmd buffer, present cb) |
| `VdSetGraphicsInterruptCallback` | ⚠️ Partial | VSync thread, no manual seeding |
| `VdQueryVideoMode` | ✅ Typed | 1280×720, non-interlaced, widescreen, hi_def, 60Hz |
| `VdQueryVideoFlags` | ✅ Typed | widescreen?1 \| width≥1280?2 \| width≥1920?4 |

**Validation Gate:** 
- `cmake --build build` succeeds (zero errors)
- `phase0_validator.exe` 9/9 tests pass
- Zero `reinterpret_cast` on guest data in `imports.cpp`
- Zero manual `ctx.rN` reads in `imports.cpp`
- `kernel_stubs.cpp` and `kernel_stubs_body.inc` deleted

---

### Step 2.8: `g_keSetEventGeneration` Counter for `KeWaitForMultipleObjects`
**Files:** `src/kernel/imports.cpp`

**Current MCLA:** Has `g_keSetEventGeneration` (line 95) but `KeWaitForMultipleObjects` implementation (line 1628-1697) only handles Event type, not Semaphore. UnleashedRecomp version (line 1502-1539) also only handles Event.

**Required:** Full implementation handling both Event (type 0/1) and Semaphore (type 5) with generation counter.

**Actions:**
1. Update `KeWaitForMultipleObjects` to match UnleashedRecomp but add Semaphore support:
   - `WaitType == 0` (WaitAll): wait on all objects sequentially
   - `WaitType == 1` (WaitAny): use `g_keSetEventGeneration` to avoid polling
2. Ensure `KeSetEvent` increments counter and `notify_all()` (already line 1088-1089)
3. Ensure `KeReleaseSemaphore` also increments counter and `notify_all()`

**Validation Gate:** `phase0_validator.exe` Test 10 passes (generation increments on KeSetEvent)

---

## Critical Section Layout Fix (Prerequisite for Step 2.7)

**File:** `src/kernel/xbox.h` (need to create or find) / wherever `XRTL_CRITICAL_SECTION` is defined

**Current MCLA (WRONG - Windows layout):**
```cpp
// 24 bytes: Header(16) + LockCount@0x10 + RecursionCount@0x14 + OwningThread@0x10? (overlaps!)
```

**Canonical (Xbox 360 - 28 bytes):**
```cpp
struct XDISPATCHER_HEADER {
    uint8_t Type;
    uint8_t Absolute;
    uint8_t Size;
    uint8_t Inserted;
    be<uint32_t> SignalState;
    LIST_ENTRY WaitListHead; // 8 bytes (Flink, Blink)
}; // 16 bytes

struct XRTL_CRITICAL_SECTION {
    XDISPATCHER_HEADER Header; // 0x00-0x0F
    int32_t LockCount;         // 0x10
    int32_t RecursionCount;    // 0x14
    uint32_t OwningThread;     // 0x18
}; // 28 bytes total
```

**Actions:**
1. Define `XRTL_CRITICAL_SECTION` with correct 28-byte layout in `xdm.h` or `xbox.h`
2. Verify `RtlInitializeCriticalSection`, `RtlEnterCriticalSection`, `RtlLeaveCriticalSection` use correct offsets
3. MCLA's imports.cpp line 692, 695, 744-751, 1287-1311, 1305-1311 already use `cs->OwningThread` — just needs struct definition fix

**Validation Gate:** `phase0_validator.exe` Test 7 passes (28 bytes, OwningThread@0x18)

---

## File Deletion / Cleanup Checklist

| File | Action | Reason |
|------|--------|--------|
| `src/kernel_stubs.cpp` | **DELETE** | Competing implementation layer |
| `src/kernel_stubs_body.inc` | **DELETE** | 37+ dead/shadowed stubs |
| `src/kernel/handle.h` | **DELETE** if exists | Host-heap handle table (non-framework) |
| `src/kernel/tls.h` | **DELETE** if exists | Superseded by `KeTls*` in imports.cpp |

---

## Validation Gates Summary

| Gate | Command | Expected Result |
|------|---------|-----------------|
| **Build** | `cmake --build build` | Zero errors, zero warnings (RelWithDebInfo, clang-cl) |
| **Phase 0 Unit Tests** | `build/phase0_validator.exe` | 12/12 tests PASS (added Test 10-12) |
| **No Manual Reads** | `grep -n "ctx\." src/kernel/imports.cpp` | Only in `GuestThread` context |
| **No Reinterpret Cast** | `grep -n "reinterpret_cast" src/kernel/imports.cpp` | Zero matches on guest data |
| **Identity Handles** | `phase0_validator.exe` Test 3,4 | PASS |
| **Lazy-Wrap** | `phase0_validator.exe` Test 4 | PASS |
| **Critical Section** | `phase0_validator.exe` Test 7 | PASS (28 bytes, OwningThread@0x18) |
| **Generation Counter** | `phase0_validator.exe` Test 10 | PASS |
| **No Dead Stubs** | `ls src/kernel_stubs*` | Files not found |

---

## Strategies Applied

### 1. First-Principles Decomposition
- Decomposed "kernel framework rewrite" into 8 atomic steps matching Phase 2 plan
- Each step addresses one canonical framework rule (identity handles, typed args, lazy-wrap, etc.)
- No step assumes prior MCLA patterns — all verified against UnleashedRecomp source

### 2. Hypothesis-Driven Verification
- **Hypothesis:** "MCLA's `function.h` already matches framework" → **Verified** (identical to UnleashedRecomp)
- **Hypothesis:** "NOACCESS guard already implemented" → **Verified** (memory.cpp:16,26)
- **Hypothesis:** "`ObReferenceObjectByHandle` already correct" → **Verified** (imports.cpp:649-653)
- Each hypothesis tested by direct source comparison

### 3. Adversarial Self-Critique (Pre-Mortem)
- **Risk:** Deleting `kernel_stubs.cpp` breaks boot because some imports only exist there
  - **Mitigation:** Audit every stub in `kernel_stubs_body.inc` before deletion; port to `imports.cpp` with typed args
- **Risk:** `IsKernelObject` change breaks existing handle checks
  - **Mitigation:** Identity handles are superset — all valid guest VAs in heap pass; update `phase0_validator` Test 3
- **Risk:** Critical section layout change breaks guest code expecting Windows layout
  - **Mitigation:** Xbox 360 uses 28-byte layout; validated by `phase0_validator` Test 7; guest code uses `RtlEnterCriticalSection` which we control
- **Risk:** Vd imports need full GPU context init (Phase 4) but Phase 2 only requires framework
  - **Mitigation:** Implement stubs with correct signatures now; full GPU init in Phase 4

### 4. Search Strategy
- **Primary:** Direct file reads of MCLA vs UnleashedRecomp kernel directories
- **Secondary:** `grep` for patterns (`ctx\.`, `reinterpret_cast`, `IsKernelObject`, `OwningThread`)
- **Tertiary:** `phase0_validator.cpp` as executable specification of framework behavior
- **Reference:** UnleashedRecomp source as ground truth (vendored in `.research/`)

---

## Execution Order

```
1. Fix XRTL_CRITICAL_SECTION layout (xdm.h or new xbox.h)
2. Fix IsKernelObject in xdm.cpp (identity handle model)
3. Audit imports.cpp: convert ALL to typed-arg GUEST_FUNCTION_HOOK one-liners
4. Implement missing critical imports in imports.cpp (VdInitializeEngines, VdSetGraphicsInterruptCallback, etc.)
5. Update KeWaitForMultipleObjects for Semaphore + generation counter
6. DELETE kernel_stubs.cpp and kernel_stubs_body.inc
7. Update CMakeLists.txt to remove kernel_stubs.cpp from build
8. Run build + phase0_validator
9. If any test fails, iterate on that specific component
```

---

## Loop Protocol (per step, 2026-08-21)

Each numbered step above runs as a bounded loop, not an open-ended session
(see `MCLA_REBUILD_PLAN.md` §Loop Discipline):

- **Trigger:** step start · **Goal:** that step's validation gate (listed per step).
- **Cap:** 3 failed attempts on one fix hypothesis → stop, bisect against
  `.research/UnleashedRecomp` reference, record STALLED/BLOCKED.
- **Terminal states:** SUCCESS (gate PASS) · BLOCKED (toolchain/link — name it)
  · EXHAUSTED (cap hit). Record the state next to the step result.
- **Checker:** after steps 3–6 land, a `code-reviewer` pass on the diff before
  declaring Phase 2 complete (maker/checker split).
- **Memory:** one run-receipt line per attempt appended to the status table
  above — zero dependence on session recall.

---

## Handoff Notes for Next Agent

- **Start with:** Critical section layout fix (prerequisite for Rtl*CriticalSection imports)
- **Then:** `IsKernelObject` identity handle fix in `xdm.cpp`
- **Then:** Import audit in `imports.cpp` — systematic conversion
- **Reference files:** 
  - Canonical: `.research/UnleashedRecomp/UnleashedRecomp/kernel/imports.cpp`
  - Validator spec: `src/kernel/phase0_validator.cpp`
  - Current MCLA: `src/kernel/imports.cpp`, `src/kernel/xdm.h/cpp`
- **Do NOT modify:** `function.h` (already canonical), `guest_thread.cpp` (already canonical), `memory.cpp` (NOACCESS already there)
- **Build command:** `cmake --build build` (from repo root, after `vcvars64.bat`)