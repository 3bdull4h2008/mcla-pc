# PHASE 1 EXECUTION TASK — IO completion gap (the "working game" tranche)

**Prerequisite reading:** `docs/PHASE0_EXECUTION_TASK.md` §1 (rules/allowlist —
all still in force) + §8 (anti-cheat). Ledger = ROOT_CAUSE_VALIDATION_FINDINGS.md
(append F-025+). Log = `docs/PHASE1_EXECUTION_LOG.md` (create now).
**Goal in one line:** kill the 471-iteration IO wait stall so resource loading
(streaming) actually completes — that is the road to a running game.

## §0 GROUND TRUTH (raw/log-verified; build on it)

Stall signature (build/boot_stdout_p0d1.log, after TOC76 #22
path='resources/ui/policecam/policecam.xsf' inner=A0088000 lr=821CC44C):

| Fact | Value |
|---|---|
| Wait loop | **471×** `WAIT[KWFSO] obj@40004D7C reason=3 to=30ms` — ~14 s of 30 ms polls until timeout kill |
| Thread | tid=000063E8 only |
| Pollers | lr=**8242FC1C** (451×), lr=8242FCB0 (20×); pc=005A0E10 |
| Dead give | `rptrWB=0000 put=7` — the slot's write-back pointer NEVER moves |
| Object | 0x40004D7C — physical/IO window, NOT a normal heap ptr |

Interpretation (INFERENCE, verify): a streaming thread polls an IO queue slot
for completion that is never signaled. `rptrWB=0000` = producer side never
wrote. This matches the handoff §75w finding exactly: NtReadFile completes
synchronously with evt=0/apc=0; the pending-slot contract is "dormant"; the
prior **SLOT-READY** hook (write 2 to [slot+12] when it reads 1) is what broke
the weeks-long loading-screen stall — same disease, new site.

Prior art in tree: `SLOT-READY` hook in src/gpu_device.cpp (session 75w),
`s_hMnt` MOUNT76 wrapper hooks **sub_821CB9D8 = fiDevice::Mount** and WORKS
(2 archive mounts) — mount machinery is fine; INFLATE caller loop already
decoded at 0x821BC2D4..0x821BC4CC (ppc_recomp.15.cpp, session 73 notes in
gpu_device.cpp).

Secondary open item (do AFTER the stall, only if time): the preload parser
inflates dictionaries but never mounts a `memory:` device (MOUNT76 = 2, both
archive). Whether that still matters post-hydration is unknown.

## §1 TASKS

T1 — Decode the wait: raw-disassemble around lr=8242FC1C and 8242FCB0
(function starts via prologue scan). Identify: what object layout it polls
(offset of rptrWB / put / status fields at 0x40004D7C), what value transition
releases the wait, and which import wraps the 30 ms wait (NtWaitForSingle-
ObjectEx? KeWait? — find the host impl in src/kernel/imports.cpp).
T2 — Decode the producer: who is SUPPOSED to write rptrWB/put for this queue?
Scan the binary for stores to the same field offsets with the object base in
the 0x40000000 window (raw scan: lis 0x4000/addis pairs + stw to the field
offsets). Identify the completing function(s) — likely the NtReadFile/AIO
completion path or a DMA/interrupt emulation site.
T3 — Prove the miss at runtime: add a TEMPORARY census on the host side of
the completing import (args + return + whether it touches the slot), build,
boot ×1 → `build/boot_stdout_p1b.log`. Expected: the producer import either
never runs for this request, or runs and skips the slot write (fake-success).
Gate sentence (bold, one line): "The slot never completes because ____."
T4 — Implement the real fix host-side: make completion semantics match Xbox
(signal event / advance rptrWB / SLOT-READY-style flip — whichever T1–T3
prove). NOT a sleep/poll hack. Reference the guest addresses of the contract
in comments.
T5 — Verify: boot ×2 (`_p1d1`, `_p1d2` — BOTH required this time). Acceptance:
- policecam.xsf load advances (TOC76 counter climbs past #22, wait loop gone
  or bounded)
- Boot reaches a NEW frontier (menu? more resources? document it precisely)
- No new `[error]` classes vs p0d1; fatal count still 0; EMB76/mount censuses
  unchanged unless your fix legitimately changes them (explain if so)
- Baseline counters within sane range (TSLAB-ALLOC ~2125+, EVENT-CREATE ~256+)
T6 — Write up: log + handoff top block + ledger F-025+ + one commit
`phase1: IO completion for <queue> — boot advances to <frontier>`.

## §2 ESCALATE (stop + log) if
- The producer turns out to be GUEST code that runs but computes wrong
  (codegen reopen — stop, do not compensate host-side).
- The wait is actually a deadlock between two guest threads (different fix
  shape — log the scheduler evidence first).
- T2 scan can't find any producer within ~30 min (then the queue may be fed
  by a hardware/emulated-DMA surface that doesn't exist host-side — that's
  the finding, log it, escalate for design).
