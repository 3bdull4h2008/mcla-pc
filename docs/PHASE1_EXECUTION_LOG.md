# PHASE 1 EXECUTION LOG — IO/streaming stall (corrected)

**Started:** 2026-09-13
**Executor:** this session
**Prerequisite:** PHASE0 rules §1/§8 still in force. Ledger starts at F-030
(F-024..F-029 already used in PHASE0/earlier).

---

## T1: Decode the wait at lr=8242FC1C / 8242FCB0

### Correction to §0 ground truth (IMPORTANT)

The PHASE1 task's §0 table is **partly wrong**. Runtime evidence in
`build/boot_stdout_p0d1.log` overturns the "IO slot never completes" reading:

| Task claim | Actual evidence |
|---|---|
| 471 waits until timeout kill, completion never arrives | WAKE[KWFSO] status=00000000 (SUCCESS) fires constantly; only some waits are STATUS_TIMEOUT (0x102). The poller is ALIVE. |
| rptrWB=0000 means IO producer never wrote | `rptrWB`/`put` in WAIT lines are **GPU CP metrics** logged on every KWFSO (put=gpuCtx+10908, rptrWB=0xC701C4BC). They are NOT fields of the waited object. |
| Object 0x40004D7C is an IO queue slot | It is the long-known **tick/dispatcher object**. Guest `sub_8242FB88` waits on `r26+32` (r26=0x40004D5C → obj=0x40004D7C), reason=3, 30 ms. On success it `KeResetEvent`s the same address. Host `SignalSchedulerTick` Releases a Semaphore wrapper there every VSYNC (`TICK-PROBE path=release`). |
| Stall = 471× same wait | The 471 waits span the whole late boot (TOC76 interleaves with WAIT/WAKE). The **terminal stall** is different — see below. |

### The real terminal stall

Log ends at:

```
TOC76 #21 ... path='resources/ui/policecam/policecam.xsf' lr=821CCED0
TOC76-RET #21 ret=A008F950
WAIT #00472 tid=000063E8 obj@40004D7C ...
TOC76 #22 ... path='resources/ui/policecam/policecam.xsf' lr=821CC44C
WAKE #00471 tid=000063E8 status=00000000 lr=8242FC1C
<EOF — no TOC76-RET #22>
```

**PROVEN:** `sub_821CBFC0` (TOC76) entry #22 is logged; the post-call RET is not.
The GPU worker thread (tid=000063E8) continues cycling after that — so this is
NOT a global deadlock. A *different* thread is stuck inside TOC76 #22 (or a
callee that never returns).

Baseline `build/boot_stdout_78.log` **completes** the identical call:

```
TOC76 #22 obj=A007D810 inner=A0088000 path='resources/ui/policecam/policecam.xsf' lr=821CC44C
GETDEV #15 path='a:/archive/resources/ui/policecam/policecam.xsf'
TOC76 #23..#27
GETDEV #16 credits.xsf
... then star_glow fatal
```

So policecam TOC76 #22 is **not inherently un-runnable**. p0d1 (post-hydration)
hangs there; baseline does not. Hydration (`HydrateShaderHashTable` → writes
0x82839F70) is the only host semantic delta between those boots.

### Decode of the waited object / worker (PROVEN from generated code)

Function `sub_8242FB88` (mcla_recomp.26.cpp:56340):

```
r26 = r3                          // worker object
loop:
  r25 = [r26+0]
  timeout = -300000 (100ns) = 30ms   // lis/ori 0xFFFB6C20
  if [r26+4] != [r25+376]: timeout = NULL (infinite)
  if [r26+60] != [r26+56]: skip wait
  r28 = r26+32                  // dispatcher object @ 0x40004D7C
  KeWaitForSingleObject(r28, reason=3, timeout)   // lr 8242FC1C / 8242FCB0
  if r3 == 258:                 // STATUS_TIMEOUT
      enter CS @ [0x82000864→obj]+14944
      if bit1 of [obj+10942]: sub_82419E90 / sub_82419E98
      leave CS; loop
  else:                         // SUCCESS
      KeResetEvent(r26+32)
      if [r25+4]==0: return
      sub_8242F870(r26); loop
```

TYPE-CENSUS: obj=40004D7C **type=00**. Wait path prefers Semaphore if already
in WrapperIdentityMap, else Event (imports.cpp:2141-2157). Release path
(`SignalSchedulerTick`) does `QueryKernelObject<Semaphore>` + `Release(1)`.
WAKE SUCCESS proves that pair is currently wired.

### Decode of TOC76 #22 caller

`lr=821CC44C` is inside `sub_821CC418` (mcla_recomp.5.cpp:16751):

```
r4 = r30 + [r31+36]
bctrl  vtable+144   // → sub_821CBFC0, LR=0x821CC44C
if r3==0: return -1
if [r31+1128]==0: return 1
else: sub_82130000(fmt, path); return 1
```

`sub_821CBFC0` itself (mcla_recomp.5.cpp:16119): if `[obj+8]==0` return 0;
else binary-search the packfile TOC by path components (hash via
`sub_821C9790`, string compare). **No kernel waits, no file IO** in the
function body. An infinite hang here means either a bounds bug on corrupt TOC
words, or a callee that never returns.

Object: obj=A007D810, inner=`[obj+8]=A0088000` (same for #19–#22).

### T1 result

**The 0x40004D7C wait loop is a red herring.** The boot-terminating stall is
TOC76 #22 (`sub_821CBFC0` via `sub_821CC418`) never returning on the loading
thread, while the GPU tick worker keeps running.

---

## T2 (started): Why does #22 hang when #20 and baseline #22 return?

Facts to build on:
1. #19 (lr=821CCED0) and #20 (lr=821CC44C) — same path, same obj, **RET**.
2. GETDEV #14 (read-only lookup) between the pairs.
3. #21 (ED0) RET; #22 (44C) no RET.
4. Baseline completes #22. Hydration is the only host semantic change.
5. TOC76 has no waits; hang must be spin/corrupt-bounds or a missing callee.

Next: instrument TOC76 to dump search bounds + elapsed time, and check whether
hydration can alias or race anything the TOC path touches. Runtime census
before any fix (T3 gate).

---

## T2/T3 (boot p1b): THE p0d1 "TOC76 #22 HANG" WAS FLAKY — REAL FATAL IS star_glow

Boot `build/boot_stdout_p1b.log` (current tree, TOC76 hang census added):

### TOC76 #22 is fine

```
TOC76-RET #22 ret=A008F950 dt=0ms lr=821CC44C
```

Then boot continues through #23–#80 (credits, legals, meshtextures, preload
lists) and hits:

```
[error] Fatal error dispatcher invoked - terminating game
[error]   fatal message: 'Unable to load shader '%s', it probably wasn't preloaded properly.'
[error]   fatal aux r4: 'star_glow'
```

**p0d1 hung early (TOC76 #22 never returned) and therefore never reached
star_glow.** Hydration "fixed" star_glow only by coincidence of the hang —
it does NOT prevent the fatal when boot actually proceeds. Baseline 78 has
the same star_glow fatal after policecam. p1b matches baseline frontier.

### Hydration DID run and is insufficient

```
TEXDICT-CALLER #10 reached — triggering hash table hydration
DICT-HYDRATE slot=0..9 entry=A0110280..A0110440
DICT-HYDRATE done: 10/10 entries -> hash table @0x82839F70
```

Those 10 factory names (draw, Copy, BlitTransparentEdgeBlur, …) are NOT
star_glow. star_glow is a game shader that must load via the INSERT /
embedded-device path. Hydration only lets the factory entries skip INSERT.

### star_glow load cascade (p1b, PROVEN)

```
GETDEV #38 path='embedded:/dcl/star_glow.dcl'          → E0 archive only
GETDEV #39 path='embedded:/star_glow.dcl'
GETDEV #40 path='embedded:/fxl_final/star_glow.fxc'
GETDEV #41 path='a:/archive/star_glow/dcl/star_glow/dcl/star_glow.dcl'  (mangled)
GETDEV #42 path='a:/archive/dcl/star_glow.dcl'
GETDEV #43 path='a:/archive/fxl_final/star_glow.fxc'
FATAL star_glow
```

GETDEV-E1 every time: `hold=A0084028 dcnt=0000 dcap=0001 d0=CDCDCDCD` —
the embedded/memory device holder is **allocated but empty**.

MOUNT76 still **2** (both `a:/archive/`). EMB76 **0**. INFLATE #1–#15 fire.

### Post-inflate callback is NOT a memory mount (handoff theory overturned)

PRELOAD-CTX #1: `streamCnt=7 inflSize=12 cbPtr=821BC548 arcDev=C98B9800
bufPtr=A47FD000`. POST-EXEC streamCnt=0 (streams drained).

`sub_821BC548` is a one-instruction tail-call to `sub_821C9108`:

```
// sub_821C9108: if (r3==0) return; sub_8244ED10(r3,1,0); return r3!=0;
```

It **ignores r4=bufPtr and r5=inflSize**. Runtime:

```
RELSEMA sub_821C9108 #40 h=C98B9800 lr=821BC538
```

That is a semaphore release on the archive device object — **not**
`fiDevice::Mount` and not a memory: device registration.

**GATE (bold):** **`star_glow` cannot load because the inflated preload
dictionaries are never registered as a `memory:`/`embedded:` device — GETDEV
for `embedded:/...` finds only the empty E1 holder (dcnt=0/CDCDCDCD), so
INSERT falls through to archive paths that do not contain star_glow, and the
guest's own fatal fires.** The post-inflate callback at `[r26+1548]`
(`sub_821BC548`→`sub_821C9108`→`sub_8244ED10`) only releases a semaphore on
the archive device; it is not the missing mount.

### Mount call sites in the binary (static)

`bl sub_821CB9D8` appears in only 3 places:

| Site | Enclosing | Runtime |
|---|---|---|
| `sub_821CBF28` lr=821CBF54 | archive Mount wrapper | **Fires 2×** (both `a:/archive/`) |
| `0x82139B58` | string-copy then Mount(path,dev,1) | **Never in any boot log** |
| `0x82139EF4` | string-copy then Mount(path,dev,1) | **Never in any boot log** |

T2 next: identify the enclosing functions of 82139B58 / 82139EF4, their
callers, and why they never run (or run and take a different branch).

### Mount call sites (static, raw-verified)

Raw bytes at `guest-0x82000000` in `build/cache/mcla_pe.bin` confirm real
function prologues (`7d8802a6` = mfspr r12,LR):

| Guest | Role | Runtime |
|---|---|---|
| `sub_821CBF28` @821CBF28 | Archive Mount wrapper → `bl Mount` lr=821CBF54 | **Fires 2×** |
| `sub_821399E0` @821399E0 | Builds path on stack, `bl Mount` @82139B58 | **0 callers in ppc_xenon**; never runs |
| `sub_82139BE0` @82139BE0 | Builds path on stack, `bl Mount` @82139EF4 | Called only from `sub_82135E48` |

`sub_82135E48` itself is called from `sub_82144C88` region only when
`[r30+4]==0` AND `sub_8213AB78` returns true. Neither address appears in any
boot log — this chain never executes.

### Status before next step

- T1 done (wait decoded; red herring).
- T2/T3 gate **proven with runtime + static evidence** (above).
- T4 (fix) **not started** — do not compensate host-side until we know whether
  Xbox actually runs `sub_82139BE0` on this path, or mounts via a surface we
  do not emulate (escalate path §2).
- No commit (T5 not reached).

### Recommended next actions (for whoever picks this up)

1. Census `sub_82135E48` / `sub_8213AB78` / `sub_82144C88` to see how close
   the executed path gets to the Mount chain.
2. Decode what `[r30+4]` is (nonzero skips the Mount).
3. If the guest truly never mounts on our emu surface, implement a faithful
   host-side `memory:` device that serves the inflated buffers — same struct
   layout as the archive device (vt=82012BDC), same GETDEV registration into
   the E1 holder — **after** proving which buffer holds star_glow.
4. Two verification boots, then commit.
