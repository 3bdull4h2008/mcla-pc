# Honest assessment — 2026-09-10

## Is this "bad previous agent work" or normal pain?

**Both, in different layers.** Not a single dumb mistake.

### What is normal for this class of project
Xbox 360 → native PC D3D12 recompilation is genuinely hard:
- 46k+ recompiled guest functions, incomplete kernel surface
- Xenos GPU semantics vs real D3D12
- No reference that "just works" (UnleashedRecomp/Xenia took large teams years)
- Every real milestone (boot → load → present → draws) surfaces the next layer

The KDELAY join, XCompress streams, resource ID tables, task-join slots —
those are real guest protocols. Discovering them takes RE time. That part
is normal.

### What is accumulated debt (prior sessions)
The tree is heavy on **mitigations stacked without root cause**:

| Pattern | Examples |
|---------|----------|
| Short-circuit hooks | KDELAY-SC, FENCE-SC, TASKJOIN-SC, REBASE-POISON, INFLATE-SKIP, TEXCREATE-SC, F98-SKIP |
| Census sprawl | dozens of log-only hooks in gpu_device/patches/task_dispatch_trace |
| Poison band-aids | zero `0xCDCDCDCD` at use-sites instead of fixing the allocator/UAF |
| SEH containment | o1heap AV → return null instead of fixing heap corruption |

That is not "stupid" — it is how you keep a boot alive while RE'ing. But
it **hides the root**: physical-heap / pool corruption (`0xCDCDCDCD`) that
reappears in every new subsystem.

### Bugs we actually fixed this session (host-side, real)
1. **Semaphore wake-loss** — `NtCreateSemaphore` mints identity handle;
   Wait used `GetKernelObject`; Release used `QueryKernelObject` and minted
   a *second* wrapper. Classic wake-loss. Fixed.
2. **o1heap alignment** — guest passed `0x404` (not pow2); align mask
   corrupted fragment headers. Fixed (round up to pow2).
3. **Inflate raw copy** — non-XCompress bytes fed to guest parser → wild
   ptr `0x7E780000`. Changed to skip-fatal, emit 0.
4. **Depth backup texture fatal** — `sub_82177EB0` returned `0x8007000E`
   (E_OUTOFMEMORY); callers fatal. Short-circuit in native mode (D3D12
   owns RTs). **Depth fatal count is now 0.**

### Current truth (latest soak `boot_stdout_texsc2.log`)
- FRAME-END ×9, NATIVE-PRESENT ×6 (presents still stop after ~6)
- TEXCREATE-SC ×1, depth fatal **0**
- 0xC0000005 ×35 — process dies under heap AV storm (same rva `0xF0A98`)
- DRAW_INDEXED **0** — SUBMIT r5 all zeros (no real VB/IB yet)
- CDCDCDCD still the root of heap/task tables

### Verdict
Do **not** throw the tree away. The recompiled image + kernel + D3D12
skeleton are real. The problem is **mitigation debt + one root corruption**.
Redoing from zero would lose weeks of guest decode for no gain.

**Correct move:** keep this tree, stop stacking SCs, and root-cause
`0xCDCDCDCD` (who writes freed pool16 / physical heap), then make presents
continuous and draws real.

## Goal remaining (working native game)
1. Root-cause CDCDCDCD (stop SEH-as-design)
2. Continuous PresentKick (not 6 then stop)
3. Real DRAW_INDEXED (VB/IB non-zero)
4. P5' pixel-hash once geometry exists
