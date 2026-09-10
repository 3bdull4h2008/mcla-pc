# HANDOFF — next agent, read this first

**Date:** 2026-09-10 (session 73 addendum)  
**Goal:** Midnight Club LA native D3D12 renderer — working game with visible frames.  
**Repo:** `E:\mcla pc` (do not delete; overlay notes in `audit-clean/`).

---

## SESSION 73 — ROOT CAUSE OF `0xCDCDCDCD` FOUND (handoff item 1 CLOSED)

The "corruptor" does not exist. The 0xCD is **guest-native fill-on-alloc**,
compiled into the shipped image:

1. **Fill mechanism (static + runtime proven).** The tiny-slab allocator
   `sub_821DE9D8` memsets every returned element before handing it out:
   common tail at `loc_821DEAFC` (ppc_recomp.20.cpp): `li r4,205; lhz
   r5,4(classHead)  # elemsize; mr r3,node; bl memset(0x823D9890)` — on the
   freelist-pop path AND the fresh-slab refill path. Runtime watch
   (`CDCD-FILL ... lr=821DEB0C`) confirms it live. Two startup fills of the
   1352-byte global at `0x8283C5E0` exist too (`sub_8218C9A8` body, memset
   returns `0x8218C9D4`/`0x8218CCCC`; re-armed at runtime by `sub_8217A068`).
   The heap also free-fills with `0xDD` (seen in POISON-DUMP).
2. **Same fill runs on retail HW** (it is in the shipped XEX). So a
   `CDCDCDCD` field read at a use-site = **a field its owner never
   initialized** — i.e. an initializer/loader that runs on HW but not in our
   emu. Stop hunting a writer; hunt the skipped init step.
3. **Poisoned object family A — texture objects (meshtextures fatal).**
   `sub_82185368`/`sub_82185410` are find-or-create-by-name: on lookup miss
   they `sub_82130528(64)` (RAGE small-alloc → 64-byte element, 0xCD-filled)
   and init via `sub_82184F58` (compares name to "none"/"nonresident",
   builds a 32×32 fallback texture, stores handle at obj+32) — **never
   writes obj+4**, the resource-id field later rebased by
   `sub_821B5A60` (consumer `sub_821D2970`, lr `821D29A0`). Producer LRs
   captured in soak: `821853AC`/`8218542C`.
4. **Poisoned object family B — 112-byte resource objects (A0106xxx
   params).** POISON-DUMP shows records `vtable=0x820131A4 @+0, body +4..+5F
   all CDCD, trailing 0xDD free fill`. The vtable sits next to the string
   `Resource '%s': %s (ptr=%p)` (0x82013167). Ctor writes only the vtable;
   the loader that fills the body never runs in our emu.
5. **Conclusion:** killing CDCDCDCD = making the **loaders run** (real
   XCompress inflate, real texture creation/registration) — NOT more
   zeroing at use-sites. The existing REBASE-POISON / P10-PRE zeroing stays
   as boot life-support until then.

### New instrumentation left in tree (all census-only, no behavior change)
- `TSLAB-ALLOC` / `TSLAB-OWNER` (patches.cpp, `sub_821DE9D8` +
  `sub_821C29A0` wrappers): element → (caller LR, elemsize) rings;
  `mcla_SlimTslabFind` (patches.h) resolves producer at use-sites.
- `CDCD-FILL` value watch (`RegisterGuestWatchValue(0xCDCDCDCD)` in
  boot_host.cpp; census in gpu_cp.cpp `PageWatchOnWrite`). `WriteU8`/`WriteU16BE`
  now route byte/halfword 0xCD stores into the watch for registered ranges.
- `PARAM-STORE` probe ranges (A0106000-A0107000, A0197E00-A0197F00) +
  `POISON-DUMP` record dump on first 3 REBASE-POISON hits.

---

## What worked before (session 72 baseline, unchanged this session)

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

## Next steps (priority order — updated session 73)

### 1. Heap AV storm / physical-arena corruption (THE remaining blocker)
The present-handshake fix pushed the run far past the old ceilings — and it
now dies in the o1heap corruption sooner (~1.4s of frame loop instead of
~75s), because the load advances much faster. Signature: o1heapAllocate
AVs on corrupted bins, `SehO1Allocate` converts to null; arena shows
`allocated=720MB cap=1.6GB oomCount=0` (NOT a genuine OOM — a free-list
walk AVs). AV rvas seen: 0xF4B58 / 0xF3868 / 0xF0A98 / 0xEF328.
Unifier hypothesis: uninitialized resource ids (CDCD story) → loader
computes wild addresses → wild writes corrupt o1heap fragment headers /
bins. Fix order: (a) catch the guest write that lands on o1heap headers —
value watch + `IsLiveAllocation` probes over the arena; the poison
producers named above are the likely source of the bad pointers;
(b) the guest AVs on failed allocs without null-checks (lr=821325D4
`MmAllocatePhysicalMemoryEx: FAILED` then AV) — the faithful fix is making
the allocations succeed, i.e. (a).

### 2. Real draws (P5')
- `SUBMIT-census sub_82420BA8` has `r5=0` (VB/IB empty). Find who fills
  `r5`/`r6` in the device-boundary path. `DRAW_INDEXED` must go >0.
- Then pixel-hash validator (`phase3_validator`).

### 3. Continuous presents — mechanically closed, blocked by (1)
- Root cause decoded and fixed this session (commit `079f94a`): the
  6-present wall was the swap-table handshake — dev+21624/21628 counters,
  2 slots reserved per kick (guest writes ZERO, HW fills timestamps LE),
  completion processor `sub_824286A0` advances only when slot
  `(completed+1&7)+16` is non-zero, gated by rlwinm-bit26 of
  `sub_82458030` (kernel-populated status chain our emu never wrote).
  Both emulation points live in gpu_device.cpp (`SWAP-STATUS` /
  `SWAP-FILL` / `SWAP-COMP` log lines).
- Presents now continue while the load runs; the run dies in (1) before a
  long soak is possible. Re-verify continuous presents after (1).

### 4. Poison family B (lower priority, now understood)
- The 112-byte vtable objects (`vtable 0x820131A4`) get their body from a
  loader that never runs. Use `TSLAB-OWNER`/`PARAM-STORE` in a soak to find
  who allocates them (owner LR) once the inflate path is fixed; the
  initializer is probably upstream of the same data dependency.

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
| `boot_stdout_cdcd74.log` | REBASE-POISON prod=Y prodLr=821853AC/8218542C; CDCD-FILL LR census |
| `boot_stdout_cdcd75.log` | PARAM-STORE probe: A0106xxx written with real param data (lr=821CB1C8) |
| `boot_stdout_cdcd76.log` | POISON-DUMP records (vtable 0x820131A4, body CDCD, 0xDD free fill); INFLATE-EMPTY ×1663; AV rva 0xF3868 |
| `boot_stdout_texsc2.log` | depth fatal 0; AV storm (session 72) |
| `boot_stdout_rootcd.log` | watch armed; INFLATE-EMPTY; no A000 write (session 72) |
| `docs/BOOT_HANDOFF.md` | full session trail |
| `audit-clean/HONEST_ASSESSMENT.md` | why the tree looks messy |

## Task board
Check `task` list: ~~T39 (CDCDCDCD root)~~ root-caused this session; T40
(heap watch → AV storm), T36 (long soak DRAW_INDEXED), T28 (pool16/UAF —
superseded by the fill-on-alloc finding), T9/T18 (optional IDA dual-source).
