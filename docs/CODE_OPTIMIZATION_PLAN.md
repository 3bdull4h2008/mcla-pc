# CODE OPTIMIZATION PLAN — MCLA PC (2026-09-20, compressed)

> Subordinate to `docs/LONG_TODO_MASTER.md` (its rule 9: no optimization while
> the game isn't booting). Supersedes both earlier versions of this plan.

## Planned vs actual

| Planned | Actual (09-20) |
|---|---|
| Split gpu_device.cpp (8k) into 7 | Not done — grew to ~11.5k; **split in flight by live session into `src/hooks/`** (alloc_census.cpp ~94 KB+, mid-move) |
| Kill validators/debug cruft | Changed: validators moved intact to `tools/validators/` (phase gates — keep) |
| Kernel 12→5, renderer 30→3 | Superseded by real reorg (common/cpu/fs/rage/hooks extracted; patches.cpp = registry only) |
| PCH, unity build, pools | Not started; baseline 19 s build / 1.6 GB / 200 s boot / 23.6 s logging — re-measure first |

## Remaining (priority order; gates at bottom)

1. Finish gpu_device split into `src/hooks/*.cpp` (pattern exists) — one move
   per commit, never mixed with behavior changes; smoke-boot gate each move.
2. PCH for the stdafx.h chain. **Never unity-batch `generated/` TUs** (input
   only; CMake regrouping is the only allowed touch).
3. Log flood → throttled counters (KWFSO/PKT-CAP/PARK-SAMPLE; Wave G).
4. Guardrails/keep-patterns: see root `CODE_OPTIMIZATION_PLAN.md` §MCLA
   guardrails — all in force.

## Gates per landed change

Build clean → 60 s smoke: no new `[error]` classes, frontier markers unchanged
(or advanced if that wave landed too) → `opt:` commit → HANDOFF trail note.
