# COMPACT_PROGRAM_GUIDE (2026-10-12, from docs/PROGRAM_GUIDE.md)

> 13 sections. Line numbers below are rotted on sight (drift 800-2,300
> measured) — use symbol/literal + grep recipe, never a bare number.

## Map

§1 what it is (XenonRecomp PPC→C++ + D3D12, guest `default.xex` is data);
§2 layout; §3 build/run; §4 image (`0x82000000`, section table lies);
§5 regen gate (never edit `generated/`); §6 runtime/threads/CP; §7
short-circuit registry + F-091 addendum + label-drift repoint table;
§8 cheat-sheet (poison values); §9 marker inventory + `soak_census.py`
parse rules; §10 RE tooling; §11 rules 1-11 + forbidden lists; §12 battery.

## Build/run (§3)

`ninja_build.bat`, clang-cl, `taskkill /F /IM mcla.exe` before link and
after soak, one new `build/w*.log` per run, `timeout 120`, verify mcla.exe
mtime moved, newest `build/*.log` <2 min = live peer session → docs only.

## Registry (§7) — keep direction labels

Knobs: KDELAY/FENCE/TASKJOIN/REBASE-POISON/P10-PRE/INFLATE-SKIP/TEXCREATE/
SEH-o1heap/align/semaphore/BLIT-OOB/SLOT-READY/DISCCHK/DICT-HYDRATE/
F432-GROW-SKIP/F434-SPIN-BREAK. Retired (F-609, do not restore):
`dispatchBootGateOnce`, GFX-BLOCK. Log-only (NOT short-circuits):
`MCLA_T43_FORCE_INV_GATE`, T4311-LEN-GUARD (`gpu_device.cpp:26065`),
T4312-UNDELIVERED, READAT-DROP, T43.14 clamp arm (`arFull||arClamp`,
guest return unchanged). Repoint table: DISCCHK→`kDiscChkForcedAck`,
F432-SC→`F432-GROW-SKIP`, F434-SC→`F434-SPIN-BREAK` (symbols live, e.g.
`kPathBHostFullDecode` at `gpu_device.cpp:1265`, `kUiXsfChunkFeed` at
`:1391`, F432 gate `:25530` — all re-measured 2026-10-12).

## Census (§9)

`markers_from_guide()`: literal heading, `|`-first-cell, backticked tokens,
no `file:line` in first cell, case-insensitive substring. Flood vs
progress + known-broken (`nGfx`="not counted" F-437, UILOLD/`Fatal`/PRESENT
substrings, deleted SYNTH/GRADIENT).

## Forbidden (§11 rule 7)

Modifiable: `patches.cpp`, `gpu_device.cpp`, `kernel/*`, CMakeLists for new
files, docs. Forbidden: `generated/**`, `config/mcla_xenonrecomp.toml`,
`src/ppc_context.h`, `src/ppc_config.h`, `.research/**`,
`src/dispatch_guard.cpp`. One owner per guest addr; one log per experiment;
one commit per fix; claims A–I/P0–P4 go to the ledger.
