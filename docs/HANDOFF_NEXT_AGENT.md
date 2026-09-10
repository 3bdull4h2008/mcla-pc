# HANDOFF — next agent, read this first

**Date:** 2026-09-10  
**Goal:** Midnight Club LA native D3D12 renderer — working game with visible frames.  
**Repo:** `E:\mcla pc` (do not delete; overlay notes in `audit-clean/`).

---

## What works now (verified this session)

| Milestone | Evidence |
|-----------|----------|
| Boot past KDELAY stall | `SLEEP60270` count 0 |
| Past meshtextures fatal | `REBASE-POISON` + D890 skip |
| Ring-B consumers drain | `PUSH pIdx` 0→1 |
| D3D12 backend up | RTX 3070, 1280×720, test pipeline |
| **Native present** | `FRAME-END` ×9+, `NATIVE-PRESENT` ×6 |
| Depth backup fatal gone | `TEXCREATE-SC` ×1, fatal count 0 |

**Not working:** process dies (~75s) under AV storm; presents log-stop at 6
(likely log throttle at frame≤8); `DRAW_INDEXED` = 0 (empty VB/IB);
`CDCDCDCD` still poisons object fields.

---

## Architecture (read before changing hooks)

- Guest PPC runs from `generated/ppc_xenon/` (never edit). Image loaded
  from `build/cache/mcla_pe.bin`.
- Host hooks: one owner per guest address (Golden Rule 1). Check
  `PPC_FUNC` / `GUEST_FUNCTION_HOOK` / `SetFunction` before adding another.
- Guest memory: `mcla::kernel::GuestMemoryHeap` (checked BE accessors).
  `WriteGuestU32` → `GuestMemoryView` (page-watch).
- Physical o1heap arena: guest VA **`0xA0000000`**–`0xFFFFFFFF` (1.6GB).
  Pool16 slabs live inside it (`A0014xxx`).
- Task-join table: count @ `0x8283D1A8`, entries @ `0x8283D1C4`, stride 28,
  idx = `(count-1) & tag`. Wait word = `entry+12`.
- XCompress magic: `0x0FF512EF`. Unknown magic → skip-fatal, emit 0.

---

## Short-circuits in tree (do not stack more without root cause)

| Hook | File | What it does |
|------|------|----------------|
| KDELAY-SC | `gpu_device.cpp` E98 | force `pub0` when wait would spin |
| FENCE-SC + ClearTaskJoinBusy | `gpu_device.cpp` | pre-release ev + clear `entry+12` |
| TASKJOIN-SC | `gpu_device.cpp` `sub_821BD220` | main-thread force busy=0 |
| REBASE-POISON | `task_dispatch_trace.cpp` `sub_821B5A60` | zero `*param` if `0xCD` byte |
| P10-PRE | `task_dispatch_trace.cpp` D890 | skip fatal on poison id, return 0 |
| INFLATE-SKIP / EMPTY | `gpu_device.cpp` `sub_821D5E10` | no XCompress → emit 0 / bail |
| TEXCREATE-SC | `patches.cpp` `sub_82177EB0` | r3<0 → 0 (legacy RT unused) |
| SEH o1heap | `heap.cpp` `SehO1Allocate/Free` | AV → null / no-op |
| pow2 align | `heap.cpp` AllocPhysical | round alignment up |
| NtReleaseSemaphore | `imports.cpp` | `GetKernelObject` like Wait |

**Wake-loss fix is a real bugfix** (create/wait/release wrapper mismatch).
The rest are boot-life support until `CDCDCDCD` is killed.

---

## Next steps (priority order)

### 1. Root-cause `0xCDCDCDCD` (T39/T40)
- Pattern: pool16 free-fill; allocated objects keep CD in uninit fields;
  those fields are then used as IDs/pointers (resource id, task table).
- Guest never stores the literal `CDCDCDCD` in generated code — runtime fill.
- PAGEWATCH on `0xA0000000` header: **no guest writes** this run (not the
  o1heap-header corruptor). Watch armed; hit count 0 on that range.
- Next: watch a **live pool16 slab** (e.g. `A0014000`+32) for stores of
  `0xCDCDCDCD` / overflows; enable a **lightweight** pool16 alloc/free log
  (`kPool16CensusEnabled` is `false` in `patches.cpp` — do not turn on the
  full census; add a slim hook).
- IDA is live (`tools/start_idalib_mcp.ps1`, port 8745) for xrefs.

### 2. Inflate caller loop (T-carry)
- `INFLATE-EMPTY` fires 900+ times on `st=006D8F20` with `in=0
  consumed=0xFFFFFFF4`. Hook now zeroes in/consumed/expected.
- If spin continues, decode caller `sub_821BC380` (`ppc_recomp.15.cpp`) —
  what field makes it re-enter? May need to set a "done" bit in the
  object, not just the inflate state.

### 3. Continuous presents
- `EnqueueNativePresent` logs only `frameNumber<=8` or `%120==0`. Count
  FRAME-END vs actual enqueue (add a raw counter). Flip queue / render
  queue depth at present #6.

### 4. Real draws (P5')
- `SUBMIT-census sub_82420BA8` has `r5=0` (VB/IB empty). Find who fills
  `r5`/`r6` in the device-boundary path. `DRAW_INDEXED` must go >0.
- Then pixel-hash validator (`phase3_validator`).

### 5. Heap AV storm
- rva `0xF0A98` / `0xEF328` in o1heap, ~1/sec after ~20s. SEH converts
  some to null; process still dies. Dump first-fail arena words (already
  logged on invariants FAIL — that path is **not** firing; AV is inside
  o1heap after invariants pass). Consider a canary at
  `physArenaBase+0x200` and a periodic walk.

---

## How to run

```bat
cd /d "E:\mcla pc"
ninja_build.bat
build\mcla.exe
```

Logs: `boot_stdout_*.log` in repo root. Kill leftover `mcla.exe` before
relink (handoff rule).

**IDA MCP:** `powershell -File tools\start_idalib_mcp.ps1` then
`check_connection`. Do not use SSE `idalib_server.py` with the proxy.

**Ghidra:** already connected (`mcla_pe.bin`). Prefer generated TUs as
ground truth; IDA function starts on this raw bin are unreliable.

---

## Do not

- Do not pop stash `session33-audlo-forensics-...` (regresses boot).
- Do not edit `generated/`.
- Do not add a second hook on an address that already has `PPC_FUNC`.
- Do not copy raw non-XCompress bytes into inflate output (causes
  `0x7E780000` AV).
- Do not claim a gate without a soak log line.

---

## Evidence files

| File | What it shows |
|------|----------------|
| `boot_stdout_texsc2.log` | depth fatal 0; AV storm |
| `boot_stdout_seh.log` | FRAME-END #200, SEH heap |
| `boot_stdout_inflate_skip.log` | first NATIVE-PRESENT ×6 |
| `boot_stdout_rootcd.log` | watch armed; INFLATE-EMPTY; no A000 write |
| `docs/BOOT_HANDOFF.md` | full session 72 trail |
| `audit-clean/HONEST_ASSESSMENT.md` | why the tree looks messy |

## Task board
Check `task` list: T39 (CDCDCDCD root), T40 (heap watch), T36 (long soak
DRAW_INDEXED), T28 (pool16/UAF), T9/T18 (optional IDA dual-source).
