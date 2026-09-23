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
| `put=` / `rptrWB=` on `WAIT[KWFSO]` | ~~`rptrWB=0000` = no consumer~~ **VOID — see the 21:30 correction below**; use `CP: RING A DRAIN` + `CP: GUEST-PUB` instead | put=11, rptrWB=0000 | put=11, rptrWB=0000 | put=11, rptrWB=0000 |
| `Fatal error` | guest fatal dispatcher | 0 | **1** (`swfCMD::Fixup`, F-042) | 1 |
| short-circuit lines | host mitigations firing — never a fix | 784 | 166 | 172 |

**21:30 correction (F-057) — two fields in this table lie, and both were cited as "starvation":**
- `rptrWB=0000` is a **wrong-address poll**: `src/kernel/imports.cpp:2117` reads hard-coded
  `0xC71D81BC` while the CP publishes to `C71D82BC` (`src/gpu_cp.cpp:951`). It can only ever print 0.
  The honest CP signals are `CP: RING A DRAIN … rptr XXXX->YYYY … published=true` and
  `CP: GUEST-PUB #n … pub A->B put=B` — in `w38g.log` the ring drained 8× to `rptr=001F` with
  `pub==put==11`, i.e. the consumer was keeping up, while `DRAW_INDEXED` stayed 0 for a different
  reason (`src/gpu_cp.cpp:664-666`, raw phys `listPtr`).
- `PRESENT-FB sample rgb=(0.06,0.10,0.22)` is **not** a guest-pixel reading. `src/render_thread.cpp`
  substitutes that exact triple whenever the sampled framebuffer sums below 0.02, so the line means
  "the guest framebuffer is black"; the on-screen dark blue is the same host constant
  (`:85`, `:444`, `:505-507`). Never count it as "UI visible" and never treat a `PRESENT` heartbeat as
  a guest present — check `fb=` on the `RenderThread: PRESENT` line (`fb=00000000` = heartbeat).

**23:32 correction (F-063 / do-not #22) — a bare hex code is not an event.** `80000003` counted **+1**
in `w38m.log` and was read as "a new VMX `debugtrap`", i.e. Route B back on the critical path. Its one
occurrence was a PM4 argument dword: `CP-T3-CENSUS op=0x58 … args=80000003 071D82C0 DEADBEEF`
(`w38m.log:3054`), and `debugtrap`/`illegal instruction` were both 0 there. `tools/soak_census.py` now
counts `C0000005`/`C0000003`/`C000001D`/`C000008E`/`80000003`/`406D1388` only inside a `code=0x…`
context (every real fault line prints that — measured), and it still reproduces F-040's `703 → 1`.
Generalise it yourself whenever a marker is a value rather than a word: check what the matching LINE
actually is before reporting a count.

**New vocabulary since then (`w38n`…`w38s`)** — all log-only, all chained, defined in
`PROGRAM_GUIDE` §9: `MSGCHAIN`/`MSGBISECT` (the boot-init chain, incl.
`MSGBISECT 5-822FBAF8 RETURN` = the `star_glow` init completed), `GATE-STACK`/`GATE-WAIT` (the forced
gate's own thread + `[0x8287E26C]`), and `D3070-RUN` next to `D3070-SKIP` (F-063: SKIP now means a
dead object, not a caller flag). A count that goes DOWN after a fix is only a regression if the lines
were guest-produced — enumerate which tool emitted them (F-051's test; `GFx 9 → 1` at 23:25 was eight
host `GFX-*`/`W34-*` stand-in prints, not guest output).

`VEH` alone is not enough: count the *named* recovery paths (`advancing RIP`, `Nuclear advance`,
`permanently disabled`, `patched sub_82`, `parking boot worker`, `fallback advance`,
`cleared MXCSR`) — all zero in `w37a`/`w38b`, and 692 + 2 in the laundered baseline (F-051). A soak
whose only VEH line is `VEH-NEUTRAL … declining` is honest; one with a `VEH` total in the hundreds is
not, whatever its `C0000005` says.

**21:30 correction (F-057(6)) — that list is dead text.** All 7 names above now measure **0 in `src/`**
and 0 in `w38g.log`: the paths were deleted in T38.3(a) and the list was never regenerated, so "all
zero" from it is vacuous, not reassuring. The live VEH signals to count instead are
`VEH-NEUTRAL` (the handler declined — honest) and `VEH W0: parking thread`
(`src/boot_host.cpp:1064`, the generic park). `tools/soak_census.py` has the same rot: 8 of its 9
`VEH_PATHS` entries are gone from `src/` and it omits `parking thread` — fix it (T40.4) before
trusting its recovery column, and re-derive the list from the source rather than from this file.

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
