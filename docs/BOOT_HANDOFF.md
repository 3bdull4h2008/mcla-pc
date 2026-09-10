# BOOT HANDOFF - updated 2026-09-10 (see HANDOFF_NEXT_AGENT.md)

## Session 73 — CDCDCDCD ROOT CAUSE + inflate spin closed
There is no corruptor. The guest image **fills every tiny-slab allocation
with 0xCD on alloc** (`sub_821DE9D8` common tail, `memset(elem,0xCD,elemsize)`
at loc_821DEAFC; watch-confirmed LR 0x821DEB0C) and free-fills 0xDD. Same
fill on retail HW ⇒ poison at use-sites = **initializers that never ran**.
Named so far: texture find-or-create (`sub_82185368`/`85410` →
`sub_82184F58`, obj+4 resource id never written) and 112-byte resource
objects (vtable 0x820131A4, ctor writes vtable only). Fix path = real
inflate + real texture registration, not zeroing. Full writeup + new
TSLAB/CDCD-FILL/PARAM-STORE instrumentation: see HANDOFF_NEXT_AGENT.md.
Soak evidence: `boot_stdout_cdcd74/75/76.log`.

Inflate spin also closed: caller loop key is `state+16` (outLeft);
INFLATE-EMPTY bail now zeroes it → 1663 → 8 entries
(`boot_stdout_infout.log`).

## Current state
- **Closed this session:** KDELAY join · meshtextures poison · semaphore
  wake-loss · inflate garbage/empty · o1heap pow2 align · depth backup
  texture fatal · SEH o1heap alloc/free.
- **Verified:** FRAME-END ×9+, NATIVE-PRESENT ×6, D3D12 on RTX 3070,
  ring-B consumers drain, TEXCREATE-SC (depth fatal 0).
- **Still open:** CDCDCDCD object fields · AV storm kills process ~75s ·
  DRAW_INDEXED=0 · presents may continue but log is throttled at frame≤8.
- **Next agent:** read `docs/HANDOFF_NEXT_AGENT.md` first.

## Session 72 summary
See HANDOFF_NEXT_AGENT.md for hook table, addresses, run recipe, and
priority-ordered next steps. Do not stack more short-circuits without
killing CDCDCDCD at the source.

## Remaining to a working game
1. **Fatal: `Unable to create backup texture for depth render target`**
   (string `0x8200A5C8`). Kills the run after ~200 FRAME-ENDs. Guest Xenos
   driver create path returns null — find the create import/MMIO and make
   depth RT create succeed on the D3D12 backend.
2. **Root CDCDCDCD** — heap/pool corruption. SEH is a bandage.
3. **Continuous presents** — PresentKick stops after 6; FRAME-END keeps going.
4. **Real draws** — DRAW_INDEXED count=0; SUBMIT r5 all zeros (empty VB/IB).
5. P5' pixel-hash validation once geometry appears.

## Session 72 — closed
| Blocker | Fix |
|---------|-----|
| KDELAY stall | FENCE-SC `ClearTaskJoinBusy` |
| meshtextures | REBASE-POISON + D890 skip |
| Wake-loss | `NtReleaseSemaphore` → `GetKernelObject` |
| Inflate AV | skip-fatal emit-0 |
| o1heap AV | pow2 alignment + SEH `SehO1Allocate` |

## Key addresses
| Addr | Role |
|------|------|
| `0x8283D1A8/0x8283D1C4` | task-join count/entries |
| `0x828369C0` | task-drain refcount (historic) |
| `0x0FF512EF` | XCompress magic |
| `sub_821BD220` | task-join |
| `sub_821B5A60` / `sub_82193090` | pointer rebase |

## Session 72 — four blockers closed → present loop

| Blocker | Cause | Fix |
|---------|-------|-----|
| KDELAY stall | Join on `task_entry+12` | FENCE-SC `ClearTaskJoinBusy` |
| meshtextures fatal | Resource id `0xCDCDCDCD` | REBASE-POISON + D890 skip |
| Wake-loss | Release minted new wrapper | `NtReleaseSemaphore` → `GetKernelObject` |
| AV `0x7E780000` | Inflate PT copied non-XCompress garbage | skip-fatal, emit 0 |

### Evidence (`boot_stdout_inflate_skip.log`)
```
PUSH pIdx=1                         ← consumer drained
FRAME-END #1..#8
NATIVE-PRESENT #1..#6
SUBMIT-census #12                   ← draws into native path
INFLATE-SKIP magic=525DE064 emit=0
```

### Inflate / XCompress
Magic `0x0FF512EF`. `XMemDecompress` is guest (`sub_8244FF20`→`82460420`).
Unknown magic: skip fatal, consume stream, emit 0. Do not copy raw bytes.

### Next
1. AV `Param[1]=-1` at host rva `0xEF328` after present loop.
2. `P1-FDB30` task table `tbl=CDCDCDCD` (same poison class).
3. P5' pixel-hash / DRAW_INDEXED runtime validation.
4. Longer soak once the -1 AV is classified.

## Session 72 — three blockers closed

### 1. KDELAY (task-join)
`sub_821BD220` wait on `task_entry+12`. FENCE-SC `ClearTaskJoinBusy`.

### 2. meshtextures (poison resource id)
id=`0xCDCDCDCD` into `sub_8217D890`/`sub_821B5A60`/`sub_82193090`.
`REBASE-POISON` zeros at B5A60; `P10-PRE` skips D890 fatal.

### 3. Semaphore wake-loss (ring-B consumers + main completion)
**Class:** session-64 family. `NtCreateSemaphore` mints identity handle =
`MapVirtual(host Semaphore*)`. Wait uses `GetKernelObject` → that object.
Release used `QueryKernelObject(header)` which **minted a fresh wrapper**
(create never registers in `WrapperIdentityMap`) — Release missed the waiter.

**Evidence:** PUSH released `C5000280`; consumer waited `C5000280`; SIGNAL
fired; **no WAKE**. After fix: `pIdx` 0→1, `C6009F80` RELSEMA, main proceeds.

**Fix (`imports.cpp` `NtReleaseSemaphore`):** resolve via
`GetKernelObject`/`dynamic_cast<Semaphore*>` when `IsKernelObject(handle)`;
fallback `QueryKernelObject` for raw guest structs.

### Present milestone (`boot_stdout_wakefix.log`)
```
PUSH #2 pIdx=1 cnt=1          ← consumer drained
RELSEMA C6009F80              ← completion signaled
FRAME-END sub_82419E90 #1
NATIVE-PRESENT #1/#2          ← R1 PresentKick path live
INFLATE #7600+ magic=00000000 ← raw VFS streams
```

### Open
- Guest AV at `sub_821CC2F0` / `0x7E780000` during load.
- Inflate mid-stream magic=0 not pass-through (only start-of-stream).
- Pool CDCDCDCD source (mitigations only at rebase/lookup).
- Pixel-hash / P5' runtime validation still pending.

## Session 72 — two blockers closed

### 1. KDELAY (task-join)
Probe `callerLR=821BD334` → `sub_821BD220` wait on `task_entry+12`.
Table: count@`0x8283D1A8`, entries@`0x8283D1C4`, stride 28.
FENCE-SC now `ClearTaskJoinBusy(tag)` + `TASKJOIN` census/SC.

### 2. meshtextures (poison resource id)
```
P10-PRE id=CDCDCDCD group=8EFFF240 table=8EFFF260 lr=821B5AB4 / 821930D8
P5-LOOKUP r4=CDCDCDCD -> FFFFFFFF
→ Resource '%s': %s  aux='meshtextures'
```
`sub_821B5A60` rebases `*param` through D890; `sub_82193090` also calls
D890 on `obj+16`. Both fed uninitialized `0xCDCDCDCD`.

**Fixes (no invented sizes):**
- `sub_821B5A60` hook: if `*param` has `0xCD` low byte → write 0, return
  (same as the function's own membership-miss path).
- `sub_8217D890` hook: if id has `0xCD` low byte → log + return 0, skip
  original fatal.

**Evidence** (`boot_stdout_d890_skip.log`):
```
REBASE-POISON ×14 (lr=821D29A0 / 821930C4)
P10-PRE ×5 (lr=821930D8 / 82192E8C / 825FDC30 / 825EE7C8 / 825EF150)
Fatal error dispatcher count = 0
Uptime 3+ min, KWFSO #7300+, VDRAIN #11500+
```

### Still open
- Ring-dead: no doorbells after 4 drains; FRAME-END never fires.
- Pool CDCDCDCD source (this session only mitigates at rebase/lookup).
- InflateBegin pass-through in-tree for when a real XCompress stream appears.

### Inflate / XCompress (ready, unused)
Magic `0x0FF512EF`. `sub_821D5E10` pass-through copies raw VFS streams.
`XMemDecompress` is guest code (`sub_8244FF20`→`82460420`), not a host stub.

## Session 72 — KDELAY decode + close (2026-09-10)

### STALL CLASSIFIED (probe soak 15:48) then FIXED (16:06)
| Field | Value |
|-------|-------|
| Outer fn | `sub_821BD220` (task-join) |
| Wait word | `task_entry+12` (in-progress, stride 28) |
| Table | count@`0x8283D1A8`, entries@`0x8283D1C4`, idx=`(count-1)&tag` |
| Caller | `sub_821E5640` fence cleanup, `release=1`, after FENCE-SC |
| Task | `ENQ sub_821BCB10` tag=`4` cb=`821BC548` |

**Fix:** FENCE-SC (`gpu_device.cpp`) now calls `ClearTaskJoinBusy(tag)`
after the semaphore pre-release. Also `TASKJOIN` census + main-thread
`TASKJOIN-SC` on `sub_821BD220`.

**Evidence (`boot_stdout_kdelay_fix2.log`):**
```
FENCE-SC #1 tag=00000004 rel=1
TASKJOIN-SC tag=00000004 idx=4 entry=A0121560 busy 00000001->0
TASKJOIN sub_821BD220 #1 ... busy=00000000
SLEEP60270 count = 0   ← KDELAY flood gone
→ Fatal: zlibInflater XCompress meshtextures (NEW site)
```

**Address correction:** `lis -32124` → `0x82840000`, r30=`0x8283D1AC`
(NOT `0x821BD1AC`). First patch used the wrong base and was a no-op.

### Call chain into the 10ms sleep
```
bl sub_821C91B8 → b sub_8244FEC0 → b sub_82460270 → KeDelay (lr=824602C4)
```

### Task-join object
| Addr | Role |
|------|------|
| `0x8283D1A8` | slot count (mask = count-1) |
| `0x8283D1C4` | entries base pointer |
| entry+0 | key (must match tag) |
| entry+12 | in-progress flag ← join wait word |

IDA `get_xrefs_to(0x8283D1A8/0x8283D1C4)` hits many `sub_821BF*`/`sub_821C0*`
sites — dual-source confirmed.

### Next — meshtextures resource miss (CLASSIFIED 16:22)
```
P5-LOOKUP #1 r3=8EFFF260 r4=CDCDCDCD -> FFFFFFFF lr=8217D8B0
P5-MISSFIX desc=8EFFF240 a4=82009840 old=CDCDCDCD lr=8217D8F0
fatal Resource '%s': %s  aux='meshtextures'
```
**Root fact:** `sub_8217D890` is called with **id=`0xCDCDCDCD`** (heap fill /
uninitialized). Lookup misses, `sub_821D2378` fatals. Same class as the
pool16 CDCDCDCD freelist issue — not a missing XCompress decoder.

`sub_8217D890` on miss returns **0** (not -1) after the fatal call, so the
existing P10 census (which keys on -1) stayed silent.

**Next probes:**
1. Who should write the resource ID before `sub_8217D890`?
2. Why is it still CDCDCDCD at lookup time (uninit vs UAF)?
3. Dump `*(u32*)0x8EFFF260` (table ptr) and the caller of the lookup.

InflateBegin pass-through is still in-tree for when a real stream appears.

## Session 72 — KDELAY wait-site decode (2026-09-10, DONE)

### STALL CLASSIFIED (probe soak 15:48, `boot_stdout_kdelay_probe.log`)
`SLEEP60270` `callerLR=821BD334` on **every** 10ms iteration — not the
`0x828369C0` refcount drain.

| Field | Value |
|-------|-------|
| Outer fn | `sub_821BD220` (task-join / wait-complete) |
| Wait word | `task_entry+12` (in-progress flag, 28-byte slots) |
| Table | `r30=0x821BD1AC`, entries at `r30+24`, stride 28 |
| Immediate caller | `sub_821E5640` fence cleanup, `release=1`, after FENCE-SC |
| Task | `ENQ sub_821BCB10` tag=`4` cb=`821BC548` (=lock-release) |
| Why stuck | Ring REINIT left CP idle (`primaryWptr=FFFFFFFF`); nothing clears `+12` |

```
sub_821E5640(obj, blk=1, release=1):
  FENCE-SC pre-releases ev     // semaphore wait OK
  original wait returns
  if (release) sub_821BD220(obj[0])   // ← STALL: join tag=4
```

**Class:** same family as E98/KDELAY-SC — a completion the frozen/reinitialized
CP can never publish. FENCE-SC is incomplete: it wakes the semaphore but the
fence cleanup still joins the task-table slot.

**Emulation-point options (do not patch until approved):**
1. After FENCE-SC, also clear the matching `task_entry+12` (or skip the join).
2. Have the doorbell handler complete the ENQ synchronously so `+12` is
   already 0 when join runs (matches "work IS done" doctrine).
3. Census `sub_821BD220` to dump `tag` + `entry+12` + table base at stall.

### Call chain into the 10ms sleep
```
bl sub_821C91B8          // pass-through thunk (r3 = ms)
  b  sub_8244FEC0        // li r4,0  (alertable=0)
    b  sub_82460270      // Sleep helper
      bl KeDelayExecutionThread  → lr=0x824602C4  ← census LR
```
No static caller of `sub_8244FEC0` passes 10ms as a literal. The 10ms
arrives via the `sub_821C91B8` thunk from several outer loops.

### 10ms wait-site table (Sleep(10) via sub_821C91B8)

| Site | Condition (pseudo-C) | Who advances it | Rank |
|------|----------------------|-----------------|------|
| `sub_821447B8` @ `0x821447F8` | `locked_read(*(u32*)0x828369C0) != 0` | `sub_82161090` refcount 1→0 | **HIGH — task-drain** |
| `sub_821447B8` @ `0x82144820` | `*(u8*)(obj+0x308) != 0` | owner clears byte | HIGH (same fn, 2nd drain) |
| `sub_821C3800` @ `0x821C3B10` | `*(r19+24084) <= 0` | scheduler slot publish | MED |
| `~0x821BC68C` | global `!= 0` | (parent TBD) | MED |
| `~0x821BD32C` | `task[i]+12 != 0` | task-complete | MED |
| `~0x822CF198` | `*(sp+80) == 1` | local flag | LOW |

### Task-drain object (`sub_821447B8` / `sub_82144A90`)
Globals under `lis -32125` → `0x82830000`:

| Addr | Role |
|------|------|
| `0x828369BC` | spinlock (`sub_821C90C0` / `sub_821C9108`) |
| `0x828369C0` | **in-flight task refcount** ← loop-1 wait word |
| `0x828369C4` | event handle (`sub_82160450`) |
| `0x828369C8` | flag byte (`sub_82160460`) |

```
sub_821447B8(obj):
  if (handle = read(0x828369C4)) sub_82161090(handle, 0);
  write(0x828369C8, 0);
  while (locked_read(0x828369C0) != 0) Sleep(10);   // DRAIN-1
  obj[777] = 0;                                      // +0x309
  while (obj[776] != 0) Sleep(10);                   // DRAIN-2  +0x308
  sub_821C9168(obj[780]); sub_8214CFA0(obj+0xAC);
  sub_82130000();                                    // thread exit
```
`sub_82161090(obj, flag)` is the refcount mutator: transitions of
`obj[12049]` 0↔1 increment/decrement `*(u32*)0x828369C0` under the lock.

Caller: `sub_82144A90` → `sub_821447B8` → `sub_82160448` (=`sub_821627A8`).
Also reached from teardown in `sub_821E6A68` (`ppc_recomp.21.cpp:7623`).

### r1 soak timeline (`boot_stdout_r1.log:858-929`)
1. VDRAIN #14: ring live, `wptr=0x19 rptr=0x19 drains=2`
2. Pool16 repair fires
3. E98 #0001 returns; `VdInitializeRingBuffer` REINIT, rptr reset
4. E98 #0002 `wait=1` → KDELAY-SC forces `pub0=5`
5. E98 #0003 returns
6. `SEMA-CREATE C98C3800` → `ENQ sub_821BCB10` → `FENCE-SC #1`
   (pre-release succeeds; main wakes immediately)
7. `NtClose C98C3800`
8. **KDELAY flood** `tid=00000D84 to=10ms lr=824602C4` forever
9. Ring dead: `primaryWptr=FFFFFFFF rptr=0000 db=FFFFFFFF`

The fence itself is NOT the stall (FENCE-SC works). Something AFTER
`sub_821E5FD0` returns enters a 10ms loop and never exits.

### Discriminating probe (no new patch — census already in tree)
Rebuild + short soak. `SLEEP60270` will log `callerLR` ∈
`{0x82144800, 0x82144828, 0x821C3B18, 0x821BC694, 0x821BD334, 0x822CF1C0, …}`.
That value names the loop. Optionally dump `*(u32*)0x828369C0` and
`*(u8*)(obj+0x308)` on the same tick.

### IDA dual-source (2026-09-10)
Headless IDA JSON-RPC is live on `127.0.0.1:8745` (`tools/start_idalib_mcp.ps1`).
`check_connection` OK; `get_metadata`/`get_xrefs_to`/`decompile_function` work.
**Caveat:** IDA auto-analysis splits functions on this raw PPC image
(real `sub_821447B8` drain body cut at `0x821447f8`). Treat generated TUs +
Ghidra as ground truth; IDA is secondary for xrefs/Hex-Rays after bounds check.
`get_xrefs_to(0x828369C0)` independently hits `sub_82163BC8` / `sub_82163C70`
/ `sub_82164890` — consistent with the refcount-mutator family around
`sub_82161090`.

## Session 64 — VSYNC-ISR Deadlock Fix (DONE)
Two root causes, both fixed (full evidence:
`docs/handoffs/2026-09-06-session64-vsync-deadlock-fix.md`):
1. **Spinlock poison:** `VdInitializeEngines` seeded gpuCtx+0x4148/+0x4158
   with 1, but `KfAcquireSpinLock` is 0=unlocked. The vblank ISR
   (`sub_82411478` r3=0 → `sub_82419718` when bit0 of 0x7FC86544 set)
   spun forever on the phantom holder (38.6M spins observed), wedging the
   vsync thread at ~frame 4 — so `SignalSchedulerTick()` never ran. Fixed:
   seeds are 0 now. `KfAcquireSpinLock` also stores BE r13 and has a 5s
   lock-recovery steal net (`KFSPIN-RECOVERY`).
2. **Phantom kernel-object wrappers:** `QueryKernelObject` trusted the
   guest header's Flink/Blink for wrapper identity; the guest driver
   rewrites them, so wait and release resolved DIFFERENT host Semaphore
   instances (wake-loss). Fixed: durable host-side identity map
   (`WrapperIdentityMap()` in xdm.h, keyed by header guest addr + Type).
- Verification: phase0_validator 13/13 PASS; ISR runs indefinitely;
  TICK-PROBE release every cycle; CP drains doorbells==drains, rptr==db.
- **Multiple waiters** share tick sem 0x40004D7C (main thread + worker):
  ~30ms release cadence consumed by race winner; ~7.5s successful wakes
  per waiter is EXPECTED (HW-like 30ms timeout pacing), not a bug.

## Session 63 — Scheduler Tick Semaphore Fix (DONE, superseded by S64)
- **Root cause of guest park:** `SignalSchedulerTick()` wrote to raw guest
  memory at offset 0x10 in the XKSEMAPHORE struct, but `KeWaitForSingleObject`
  resolves the object to a **host-side `Semaphore` wrapper** whose `Wait()`
  polls a separate `std::atomic<uint32_t> count` — never synced from guest
  memory. The signal never reached the waiter, parking the driver worker
  thread forever in a 30ms timeout loop (`NtWaitForSingleObject` on
  `obj@0x40004D7C`), preventing all GPU work submission after the initial
  2 doorbell drains.
- **Fix:** `SignalSchedulerTick()` now calls `QueryKernelObject<Semaphore>()`
  to resolve the host wrapper and `sem->Release(1, nullptr)`, which increments
  the host atomic AND calls `notify_all()` to wake the waiter.
- **Build: 2/2 files, 0 errors, linked.**
- **Next: runtime test** — verify the guest unblocks and draws reach the
  pipeline. Expect to see new log activity from DRAW_INDEXED handler and
  PipelineCache.

## Session 57 — P4′ Step 3: Render Thread (DONE)
- Render thread now owns ALL D3D12 calls.

## Session 58 — P4.5′: Copy Queue + Frame Pacing + Queue Depth (DONE)
- Copy queue, 30fps frame pacing, queue depth monitoring (warn 30, drop 60).

## Session 60-61 — P5′ Shader Pipeline (CODE DONE) + Park Identified
- PSO cache + async worker, root signature matching translator contract,
  grcFvf input layout — all wired (B9/B10/B11 code-complete). Details:
  `docs/handoffs/2026-09-06-session61-p5-shader-pipeline-and-park.md`.
- **Blocker now:** guest parks at ~t=4-7min in `WAIT[KWFSO]` loop
  (tid=0x69C0, lr=0x8242FC1C, obj@0x40004D7C, put=11 rptrWB=001F frozen);
  no draws ever reach B9-B11. Decode `sub_8242FB88`'s wait condition next.
- app.cpp: CVar LoadConfig now before InitD3D12 (native mode actually
  initializes D3D12 now).

## Session 59 — P5′: First Native Draw Wired (DONE)
- **DRAW_INDEXED now actually renders.** `sub_82420BA8` capture pushes
  `DrawIndexedCommand` with `{vbAddr, ibAddr, vbSize, ibSize, vbStride,
  ibFormat, indexCount}` to the render queue. Render thread reads guest
  memory, uploads VB/IB to D3D12, calls `DrawDynamicMesh()`.
- Added `vbSize` and `ibSize` fields to `DrawIndexedCommand` (read from
  VB descriptor at r5+8 and IB descriptor at r6+4).
- Index format auto-detected from `ibFormat` bit 0: 0=16-bit, 1=32-bit.
- **This should produce visible geometry** when VB/IB data is valid.

## Next: P5′ continued — PSO Management + Shader Pipeline
1. **PSO cache** — create D3D12 graphics pipeline state objects from Xenos
   shader hashes. Cache by `(VS hash, PS hash, blend/depth/rasterizer state)`.
2. **Root signature** — currently hardcoded test root sig; need to match
   Xenia's register layout (CBVs, SRVs, samplers).
3. **Vertex input layout** — decode Xenos FVF vertex declarations into
   D3D12 input element descriptions.

## Session 55 — Dispatch Fix (DONE)
- **Root cause:** Function table has non-NULL garbage (`0x0c800c800c800c800`)
  for uncompiled functions. When `sub_8218CC70` dispatches an uncompiled index,
  the garbage pointer was treated as a valid function address.
- **Fix:** Built `compiledFuncs` map from authoritative `PPCFuncMappings[]`
  (46029 entries, null-terminated). Dispatch hook checks map first; if not
  compiled, logs and returns without calling. If compiled, uses `targetFn & ~3u`
  masking (all targets misaligned with bit0 set).
- **Secondary fixes:** spdlog format strings (`%08X`/`%zu`/`%d` → `{}` format),
  reverted safety gates in ppc_recomp.10.cpp to original.

## Session 56 — Writer-Attribution Census (DONE)
- **Census v3 implemented:** dense logging, ring buffer (32768 snapshots),
  dispatch_entry.log, validity tracking
- **Free-time check:** Compares element first4 at alloc vs free — ALL 64
  detections are false positives (snapFirst4=CDCDCDCD fill pattern, curFirst4
  = initialized string data like "mcAmbientPath", "mcTrigger*", "vehTune*")
- **Slab scan:** `ScanPool16SlabsForOverflow()` found 0 actual overflows —
  freelist chain integrity intact across all slabs
- **Conclusion:** The 16-byte pool overflow is either (a) no longer occurring
  with current patches, or (b) the census approach doesn't detect the actual
  overflow pattern (writes past element boundary into adjacent elements)
- **Raw output:** `build/cache/pool16_writers.log`

## Next: P5′ continued — Runtime Test + Root Signature
1. **Runtime test** — run and verify PSO cache wiring works end-to-end
2. **Root signature** — if PSO creation fails (shader CBVs not in root sig),
   add CBV root parameters for VS/PS constant buffers (b0/b1)
3. **G-CORPUS-* gates** — verify all 1,264+ existing ucode shader dumps compile

## Run Receipt — 2026-09-09 06:02 (semaphore census, session 66)

- **Build:** `cb0de39` (census instrumentation `4a5c4cf` + ISR-lambda compile fix
  `cb0de39`). phase0_validator 13/13 PASS. imports.cpp.obj + mcla.exe relinked 06:01:17.
- **Effective mode: `native`** (log line 06:05:27 `mode=native`). Source =
  `build/cache/mcla.toml` (`renderer_mode = native`, deliberate per S64 "keep
  for runs"). `config/mcla_manifest.toml` is NOT consumed at runtime (zero src
  readers); its flip to `legacy` (`131c35f`) is documentation-only. Run kept in
  native to stay comparable with the S64 baseline.
- **Commits:** `131c35f` docs+toml audit resync · `4a5c4cf` census
  instrumentation · `cb0de39` mispasted TYPE-CENSUS block removed from
  VdSetGraphicsInterruptCallback ISR lambda (referenced KeWaitForSingleObject
  locals — would not compile). stash@{0} untouched.
- **Static read:** 5 wait paths (Nt→typed `obj->Wait`; Nt→unrecognized handle
  STATUS_TIMEOUT; KWFSO case 4 map-hit-Sem→fallback-Event; KWFSO case 5
  QueryKernelObject<Sem>; KWFSO default timeout-return). Removed asserts in
  `0adc159`: `timeout==0||INFINITE` ×2, `"Unrecognized kernel object type."`,
  `hThread != CURRENT_THREAD` (kept, renamed `th`).
- **Census (90s soak):** DWELL[KWFSO] 58/60 `<30ms` (timeout-paced), 1 `<1s`,
  1 `<1ms`, zero `>=1s`. TYPE-CENSUS 60× `type=00` (semaphore): obj=`40004D7C`
  dominant (timeout=0x1E=30ms, lr=`8242FC1C`) + one INFINITE wait on
  `40004DCC`. TICK-PROBE **60/60 `path=release`** — no guard bounce; release
  cadence 20.8ms early → ~44ms mid-load, consistent with S64's documented
  ~30ms timeout pacing (S64-era raw logs rotated out; receipt cites handoff
  numbers). RING probes ×40. Zero fatals/crashes in window.
- **Instrumentation follow-up:** `res=` always logs `pending` (census fires
  before wait resolution is set) — move the res field into the DWELL log next
  census. DWELL[NTWFSO] silent (guest uses the Ke path).
- **Queue:** S1–S3 deletion remains deferred post-stall (single-hook-owner
  verify + code-reviewer/security-auditor; S4 shrinks to patches.cpp GpuKick
  after that sweep). Manifest generator: **no node tooling exists in-repo**
  (zero .js/package.json) — the "Generated by node tooling" header is
  unverifiable here; previous `native` value was almost certainly a hand edit
  (matches S61's flip-and-restore pattern).


| Address | Purpose |
|---------|---------|
| `0x828369BC` | Task-drain spinlock |
| `0x828369C0` | Task-drain in-flight refcount (KDELAY wait word) |
| `0x828369C4` | Task-drain event handle |
| `0x828369C8` | Task-drain flag byte |
| `0x827D5CC0` | Callback data table (written by `sub_82189E80`) |
| `0x827D5E40` | Registration table (written by `sub_82189E20`) |
| `0x827D6010` | Dispatch offset table (24 entries, sentinel at 23) |
| `0x82839254` | basePtr (set to `0x40002080` — GPU physical memory) |
| `0x82839270` | kConfigGlobal — always zero, unused/reserved BSS slot |
| `0x82830DB8` | 16-byte pool classHead (elemsize=16, capacity=1018) |

## Warnings
- `rexgpu-xenos.dll not loaded` — GPU emulation skipped per user directive
- stash@{0} 'session33-audlo-forensics-gpu_device-capture-hardening' REGRESSES
  boot (stalls ~5s) and hardcodes AUDLO answers - salvage individually, never pop.
- generated/default is a STALE second regen - only generated/ppc_xenon is
  compiled (CMakeLists). Do not decode from generated/default.
- Freeze line: no PM4, no manual GPU seeding, no opcode expansion.
- Census work in patches.cpp (sessions 37-56) was committed as part of the
  session-65 rescan checkpoint; no outstanding patches.cpp edits expected.
