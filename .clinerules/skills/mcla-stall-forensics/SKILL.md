---
name: mcla-stall-forensics
description: Use when the recompiled MCLA guest parks, spins, or stalls in a driver wait (PARK-SAMPLE, RW/E98 census lines, ring waiters, sub_82411xxx family) - encodes the proven decode-emulate-verify loop for guest GPU wait stalls. Trigger words: park, stall, spin, waiter, census, doorbell, rptr, progress counter.
---

# MCLA Stall Forensics Loop

Proven method that cracked three stall layers on 2026-08-23 (dead dispatcher,
rptr publish, progress counter). Run it verbatim, one layer at a time.

## The loop

1. **Census** - add/extend a log-only `PPC_FUNC` override at the parked
   function's entry (+ return counter). Log predicate INPUTS only:
   device VA, compared words, this-thread TLS block. Throttle
   `n<=16 || n%500==0`. NEVER log inside hot loops.
2. **Soak** - single `build\mcla.exe --headless` run (ONE instance only -
   shared `build\cache\mcla.log`). 90-150 s. Grep E98/RW/PARK-SAMPLE lines.
3. **Decode** - read the generated TU body (`generated/ppc_xenon/
   ppc_recomp.NN.cpp`) of the parked function. Write the exit table: every
   early-out, loop predicate, trap. Cite line numbers. Check whether the
   function is an EMPTY padding stub first (`PPC_FUNC_PROLOGUE(); // .long
   0x0` only) - the real body may be the sibling address.
4. **Attribute** - who SHOULD advance each polled word on HW? Xenia analogs:
   rptr write-back = BE dword index via CP_RB_RPTR_ADDR; scratch write-back;
   system-cmdbuf identifier (VdSetSystemCommandBufferGpuIdentifierAddress,
   advanced ONLY at swap); vblank liveness. No external writer = kernel-role
   emulation point.
5. **Emulate minimally** - derive values from consumed/captured data, never
   invent. Label any rate-based bump EXPERIMENT in code + handoff ledger.
6. **Verify** - rerun soak: census must show the waiter returning and traffic
   advancing past the previous watermark. Update gates/handoff.

## Known predicate map (as of 2026-08-23)

| Function | Polls | Exits when |
|---|---|---|
| sub_82411218 | subctx[+60] (ring RB rptr) | free-space wrap OK |
| sub_82411188 | subctx[+4] | cursor advances |
| sub_82412F98 | *(r13+256)+88 delta>=5000 vs ctx[12] snapshot | kill bit dev[+10941]&2, or pump E3 |
| sub_82411E98 | needed(r4) > *(*(dev+10896)+0) | published catches needed |
| sub_82411180 | barrier variant | space |

sub_82411E94 is an EMPTY padding stub - real body is sub_82411E98.

## Gotchas

- Overrides MUST be global scope (`PPC_FUNC(sub_X)` at namespace level);
  namespaced symbols never bind to the weak alias.
- Snapshot volatile regs BEFORE passthrough (r8 clobber class).
- Throttles hide post-settle traffic - before assuming deadlock, check
  whether counters still increment (n%throttle lines appearing).
- GuestDevice VAs live in A-segment (A0003080 primary, A0009100 second).
  All probes read via checked ReadU32BE; A-segment aliases above 512 MB view
  return OOB sentinel 0xFFFFFFFF - not a real value.
- Symbolize host RIPs: `llvm-symbolizer --obj=build\mcla.exe <addr>`
  (DIA/PDB plugins broken; guest_memory.cpp accessor churn between every
  guest insn is EXPECTED in samples, not a park).
- mcla.exe held open by running game = link permission denied - kill the PTY
  before rebuild.
