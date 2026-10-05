# SUPERVISOR REVIEW — 2026-10-01 (evening)

> Produced read-only, in a lane deliberately disjoint from the concurrent session
> (which is editing `xenos_microcode.cpp` / `shader_translator.cpp` / `xenos_shader_ir.cpp` /
> `render_thread.cpp` — the draw-bridge/vertex frontier). Nothing here touches those files.
> Metrics: 467 soaks dated by in-content timestamps (xz re-stamps mtimes — do not date by mtime),
> 461 dated ledger findings (F-077..F-729; F-001..F-056 are pre-`###` compacted, 09-20's volume
> fault makes that day artificially sparse), 420 commits.

## The acts, rated

| Act | Window | F / S / C | What it was | Grade | Why |
|---|---|---|---|---|---|
| I — Prototype | 08-06..08-14 | – / – / 16 | Phase 0-3 scaffolding committed | **B** | The capture/decode/backend foundation still carries everything; no evidence trail existed yet |
| II — Build-out | 08-21..09-19 | – / – / 137 | Heavy build days (peak 26 commits/day); texture decode, shader pipeline, D3D12 | **B-** | High output, zero documentation — the era we cannot audit |
| III — Institution born | 09-20..09-23 | sparse / – / 21 | First census era; **volume fault zeroed the ledger**; §1 rules 1-19 + do-not list born | **C+ / A-** | C+ on output (fault, sparse records); A- on institutional learning — the rule corpus is this act's product |
| IV — Campaign core | 09-24..09-27 | **353 / 412 / 246** | The soak-and-kill machine at full speed; Path A to 100%; both loop root-causes | **A-** | Peak velocity (135 findings on 09-27); contains the biggest win AND the biggest waste — the price of the learning curve |
| V — Meta-correction | 09-28..10-01 | 108 / 54 / **0** | RULE 0 born; 11 false claims killed; comment-licence class found (F-681..F-692); ledger reconstructed (F-720..F-728); docs compressed | **A- / D** | A- on self-correction — the project audited itself successfully. **D on durability: four days, 156 findings, zero commits** |

## Measured pattern verdicts

**Most cost-effective behavior:** single-bug, single-build root-causing with counter-field
evidence. F-640 (phys allocator): 1 build, 2 soaks, `oom=101,700→0`, permanent. F-643 (31-bit
mask): collisions 2,426→0. F-645 (double-inflate): 1 build. These are the fixes that never needed
touching again.

**Most wasteful behavior:** multi-day soak chains run against an un-measured *framing premise*.
- The enqueue-gap odyssey (F-186→F-519): 3+ days, ~40+ findings, dozens of soaks → the closing
  verdict was "the pacing lever is the title's." The frame was wrong; decompression was necessary
  but never sufficient.
- The descent (F-594→F-628): 7 build+soak cycles + an 8-round descent, refuted wholesale —
  and the refutation found the corroborating instrument itself was stale ("lying instruments", w654).
- F-650's read-mode lever: acting on a real-but-unvetted predicate produced the first-ever guest
  fatal and a revert that "restored throughput, not correctness."
Common root: a premise would have died to one falsifying build if asked for *before* the chain,
not after. F-632's ten-minute-review rule now exists precisely for this — it must gate the NEXT
chain too, not just the last one.

**Cross-act ledger-grade note:** 09-28 onward has 156 findings and zero commits. Every other
metric in this review is provisional against the risk that the working tree — now the only copy of
Acts IV-V — is lost. **Commit is still the highest-value remaining action.**

## The concurrent session (measured, not guessed)

Editing `renderer/xenos_microcode.cpp` (19:17), `shader_translator.cpp` + `xenos_shader_ir.cpp`
(18:51), `render_thread.cpp` (19:19) — the vertex/draw-bridge lane. No boots since 09:15 (w686);
next soak will be w690+. Live frontier it owns: the UIXSF-DIVERGE regression
(144,864→22,145 good bytes), the `chevy` fatal chain, and the `DRAW-CP-REFUSE no-translated-pso`
refusals — 8 draws attempted, 0 pixels as of w685.

**Two supervisor cautions for that lane** (from this review, not from its code):
1. The UIXSF-DIVERGE regression must be explained *with* the vertex work — measuring vertex gains
   on a moving container baseline invalidates the comparison (the w406/w408 lesson: same code,
   589,824 vs 917,504 bytes).
2. Vertex/microcode translation is dense in exactly the classes that produced the worst wastes:
   rotate-immediate masks (F-647: read the raw word), "never fires" claims (compare sets, not
   counts), and decompler-trust. One falsifying build per premise, before any chain.

## Supervisor's overall grade for the project to date

**B+.** World-class evidence discipline that demonstrably self-corrects (a ledger where ~82% of
findings are measured negatives is a feature); genuine engineering wins at the allocator, VFS, and
loop-root-cause layers; the boot now reaches the game's own logic (truthful guest fatal) rather
than crashing. Held below A by: four days uncommitted, the enqueue-gap/descent class of waste
(now rule-guarded but not yet tool-gated), and a doc layer that until today fought its own agents.
The remaining distance to "playable" is one named frontier — pixels — and the concurrent session
is pointed exactly at it.
