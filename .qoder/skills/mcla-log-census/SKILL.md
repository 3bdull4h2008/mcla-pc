---
name: mcla-log-census
description: Count and compare boot-log markers in build/*.log case-insensitively to decide whether a change advanced the guest. Use when reading a soak, comparing two soaks, claiming a gate, or hunting why a counter is zero — i.e. before any statement about boot progress.
---

# Log census (rule 13's evidence machine)

Every "it advanced / it didn't / zero occurrences" statement in this project must come from a
counted log line. Four census mistakes are on record:

- **Case-sensitivity false negative (2026-09-20):** `grep -c c0000005` = **0** while the log held
  **703** `code=0xC0000005` lines. Always use `-i`. This is still live in the frontier table below:
  `GFx` reads **0** case-sensitively and **7** case-insensitively in the same baseline.
- **The shell has GNU grep 3.0** (`/usr/bin/grep`); `ugrep` is *not* installed — an earlier revision
  of this skill claimed otherwise and that was wrong. `grep -ic` behaves normally. Still: never infer
  absence from one empty result — repeat with a second pattern form.
- **Benign pollers dominate any naive `lr=` census (2026-09-20):** `lr=8242FC1C` appears **5,728**
  times in `w37a.log` and is the 30 ms KWFSO/GPU poller, not a fault. Count `lr=` only over lines
  that report a fault (an exception code, `AV`, `VEH`, `parking`, `Fatal error`).
- **Mitigation lines are not fault lines (2026-09-20):** `P5-PHYS … skip fatal (caller takes
  delta-0 path)` matches any filter containing the word "fatal". Those 17 `lr=825EF1DC` events are a
  host short-circuit *absorbing* a guest failure. Including them invented a second fault cluster.

## Marker battery

`tools/soak_census.py` is the executable form of this skill. Its counts are matching **lines**,
case-insensitive, so every number it prints is reconcilable with `grep -ic`. It derives its marker
list from `PROGRAM_GUIDE` §9 plus a frontier battery, and adds the fault-lr census, the CP-ring
watermarks and the mitigation-firing count.

```bash
cd "E:/mcla pc"
python tools/soak_census.py build/w38a.log build/smoke_long2.log   # new vs named baseline
python tools/soak_census.py build/w38a.log --unchanged             # only what moved
python tools/soak_census.py build/w38a.log --markers GFx,UILOAD,C0000005
```

By hand, when the tool is unavailable:

```bash
for m in "UILOAD" "GFx" "FACTORY" "SUBMIT" "DRAW_INDEXED" "DRAWDISP" "NATIVE-PRESENT" \
         "FRAME-END" "PRESENT-FB" "INFLATE" "TOC76" "PARK-SAMPLE" "C0000005" "C0000003" \
         "80000003" "Fatal error" "assert" "PHYS-OVERRUN" "BLIT-OOB-GUARD" "MmAllocatePhysicalMemoryEx"; do
  printf "%-32s %s %s\n" "$m" "$(grep -ic "$m" build/w38a.log)" "$(grep -ic "$m" build/smoke_long2.log)"
done
```

Two columns, always: **new log vs named baseline**. A single number means nothing without the
baseline it moved from, and the baseline name must be written into the claim.

## Frontier markers (what "progress" means here)

All values case-insensitive, measured by `tools/soak_census.py` on 2026-09-20.

| Signal | Meaning | `smoke_long2` (120 s, pre-VEH-fix) | `w37a` (post-VEH-fix) | `w38b` (19:20 soak) |
|---|---|---|---|---|
| `C0000005` | guest access violations — must be **≤ 3** and each root-caused | 703 (laundered by a VEH mitigation, F-040) | **1** | **1** |
| fault-line `lr=` | distinct guest return addresses on fault lines | 703 events, **1** distinct (`822FBC28`) | 1 event, `822FBC28` | 1 event, `822FBC28` |
| `VEH-NEUTRAL` | the handler **declined** — an honest dump | 0 | 1 | 1 |
| `80000003` | host `int3` from an unimplemented VMX128 op | 0 (Route A landed) | 0 | 0 |
| `GFx` / `UILOAD` | UI layer reached | 7 / 2 | 9 / 1 | 9 / 1 |
| `DRAW_INDEXED` / `DRAWDISP` | real draws — **the actual goal** | 0 / 0 | **0 / 0** | **0 / 0** |
| `put=` / `rptrWB=` on `WAIT[KWFSO]` | CP ring producer/consumer; `rptrWB=0000` = no consumer | put=11, rptrWB=0000 | put=11, rptrWB=0000 | put=11, rptrWB=0000 |
| `Fatal error` | guest fatal dispatcher | 0 | **1** (`swfCMD::Fixup`, F-042) | 1 |
| short-circuit lines | host mitigations firing — never a fix | 784 | 166 | 172 |

`VEH` alone is not enough: count the *named* recovery paths (`advancing RIP`, `Nuclear advance`,
`permanently disabled`, `patched sub_82`, `parking boot worker`, `fallback advance`,
`cleared MXCSR`) — all zero in `w37a`/`w38b`, and 692 + 2 in the laundered baseline (F-051). A soak
whose only VEH line is `VEH-NEUTRAL … declining` is honest; one with a `VEH` total in the hundreds is
not, whatever its `C0000005` says.

## Reading discipline

- `lr=` in a marker line is a **guest** return address, often sticky after a `memset`/leaf call
  (do-not #14). Attribute with xrefs + argument registers, or the FFBT trace.
- `0xCDCDCDCD` in a dump = never-initialized guest memory, not corruption.
- `crash_dump.txt` / `crash_log_early.txt` at the repo root are stale artifacts unless their
  mtime matches the soak you just ran.
- The presence of a `FATAL-SOFT`, `VEH`, `skip fatal`, `delta-0` or `-GATE` line means a **host
  short-circuit intercepted** — report it as a mitigation, never as a fix, and name the file:line
  of that mitigation (evidence-discipline rule from project memory).
- To find those file:lines without grepping by hand: `python tools/mitigation_audit.py` diffs the
  `PROGRAM_GUIDE` §7 registry against `src/` and cites every label at its `file:line`.
- **Check a soak's shape before believing its counts.** One repeating host message can be the whole
  log: `w38e.log` was 175 MB / 1,860,449 lines of one VEH recovery firing **616,824** times in 31.7 s
  (66% of the file, `C0000005` = 616,825 against **1** in `w38c.log`), so read naively it looked like a
  boot 616,824 exceptions further along (F-054). `tools/soak_census.py` prints a `LOG QUALITY` line per
  dominant repeated shape and a **POISONED** verdict when one mitigation/VEH shape is ≥2% of the log —
  if you see that verdict, the log is evidence of a host loop, not of the guest, and must not be named
  as a baseline.
- **A zero is only evidence if the pattern is known to match something.** The battery used to carry
  `parking thread`, which no soak has ever emitted (the real message is `parking boot worker thread`),
  so the row read 0 in every column and looked like "the park path never fires" (F-051). Validate a
  marker by seeing it fire once in a log that contains it — `grep -ic` the literal string against all
  three soaks — and derive markers from the `MCLA_LOG_*` format strings in `src/`, never from a doc's
  paraphrase of them.

## After the census

Write the counts into `docs/` (HANDOFF session ledger or an F-### entry via `mcla-finding-ledger`),
with the log filename and the baseline filename.
