# Handoff — MCLA Native PC (E:\mcla pc) — 2026-08-22 (session 2)

**Base:** HEAD = `11a8e97` (ring probe commit). **Worktree: 4 files modified, UNCOMMITTED.**
Chain of evidence below; superseded details from `.opencode/handoffs/2026-08-22-phase3-gate.md` still valid.

## LANDED (uncommitted, in worktree)

1. **Blocker 1 — probe strip.** `function.h`: import-trace fprintf block + `<atomic>`/`<cstdio>`
   includes removed from `HostToGuestFunction`. Verified healthy alone AND in combination.
2. **Blocker 3 — query consolidation.** `imports.cpp`: static `NtQueryVolumeInformationFileImpl`
   / `NtQueryDirectoryFileImpl` + their manual `PPC_FUNC(__imp__X)` wrappers deleted; the typed
   impls (~line 860/880) are now hooked via `GUEST_FUNCTION_HOOK` at ~2586. One owner per import
   (grep-verified). NOTE: neither import is called during boot (0 log hits across all runs).
3. **Blocker 4 — xenia query statuses.** `NtQueryInformationFileImpl` fallback no longer returns
   SUCCESS+zeros: unknown class → `STATUS_INVALID_INFO_CLASS`, known class w/o usable handle/buffer
   → `STATUS_INFO_LENGTH_MISMATCH`. Constants added to `xbox.h` (`#ifndef`-guarded).
   Game queries class=26 twice during boot, tolerates the new error (proceeds to GPU init fine).
4. **BUGFIX (pre-existing, blocks validator): finite-wait infinite park.**
   `kernel_objects.h` `Event::Wait`/`Semaphore::Wait` FINITE branches used `std::atomic::wait()`
   which has NO timed form → deadline check unreachable when nobody signals → infinite park.
   Introduced in `9cf5a4f` ("fix finite-timeout waits"). Replaced with bounded 1ms poll honoring
   deadline. phase0_validator was HANGING at Semaphore test since that commit; now truly passes.

## DROPPED (proven-negative this session)

**Blocker 2 — VSync log demotion (INFO→DEBUG).** Runtime-inert by inspection (lambda never runs
pre-stall), yet correlationally lethal: with demotion 3/4 boots STALL at the engines-init →
VdSetGraphicsInterruptCallback boundary (silent total log freeze, process alive); without it 0/5
stalls (incl. 10+ HEAD runs). Hypothesis: code-layout shift exposes latent race between boot
worker and GpuContextPoller/init path. OPEN QUESTION for debugger/architect — do NOT re-land
demotion until race is understood. Keep per-frame INFO logs for now.

## EVIDENCE (loop-discipline receipts)

RUN (HEAD control): trigger=baseline after stash | observed=vsync up, RING ticking | state=SUCCESS
RUN (fixes-only, clean objs): vsync=True ring=ok, class26 error tolerated | state=SUCCESS
RUN (fixes+consolidation, clean objs): vsync=True ring=ok | state=SUCCESS
RUN (full diff incl. demotion): 1×SUCCESS, 3×STALL@engines-init | state=STALLED → demotion reverted
RUN (landing state ×2, clean objs): vsync=True ring_ticks=34 both | state=SUCCESS
phase0_validator: 13/13 PASS ×3 on final code. Build clean (clang-cl RelWithDebInfo, zero errors,
5 pre-existing warnings: discarded nodiscard returns in ring probe @imports.cpp:1323-1327;
pointer-to-int casts @1597,2377).

## METHOD NOTES (context discipline)

- Incremental builds after header edits proved untrustworthy mid-session (bisect confusion);
  ALWAYS delete `build/CMakeFiles/mcla.dir/src/kernel/*.obj` before gate builds touching headers.
- PowerShell quoting: `'stash@{0}'` needs single quotes. `git checkout 'stash@{0}' -- <file>`.
- build/cache/mcla.log APPENDS across runs — filter runs by last "kernel heaps" line number.

## NEXT (Phase 4 front line — unchanged priority)

1. Commit landing set (4 files) — pending user approval.
2. CP emulation per recon gap table: doorbell MMIO trap phys 0x7FC80000 reg 0x01C5 → drain ring
   put≠read → BE-store rptr to writeback addr 0x072344BC (ring base 0xC6224480, sizeLog2=12,
   32KB). Minimal packet set: SET_CONSTANT / IM_LOAD(_IMM) / DRAW_INDX_2 / XE_SWAP(0x64).
   Live evidence: game puts advance (C62345CC→C62346BC), rptr static at head C0114800 000003FF.
3. Ship-blocker #5 (MED security): identity-handle ABA/generation counter before adding handle types.
