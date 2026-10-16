# TASK_OPTIMIZE — PARKED per rule 9 (one doc, no split)

> Rule 9 (LONG_TODO_MASTER §1; PROGRAM_GUIDE §11): NO framework rewrites
> while not booting. Everything below is PARKED. Do not start it. Each item
> lists its trigger — work begins only when the trigger soak exists.

## Parked items (DO NOT START)

1. **VMX128 Route B** — vector-pack rewrite in `src/cpu/vmx128_pack.cpp`.
   Trigger: a soak at menu profiles vector ops as the top cost AND the frame
   path is byte-honest (`DRAW-CP-DRAWN` > 0 with `FATAL-SOFT=0`).
2. **`gpu_device.cpp` split** — file is ~27,000 lines; split into TUs.
   Trigger: link/edit cycle time blocks a menu-gated fix (show the timing),
   not aesthetics. Registry knobs to preserve: `kPathBHostFullDecode`
   (`src/gpu_device.cpp:1265`), `FDBF8-ARR-RESTORE` (`:16818`),
   `arFull||arClamp` (`:20203-20230`).
3. **PCH (precompiled headers)** — `src/stdafx.h` exists; wiring a PCH is a
   build-system change. Trigger: measured full-build time regression vs the
   435-commit baseline, with numbers from two clean builds.
4. **Log throttling** — caps like `if (k <= 16 || (k % 4096) == 0)` already
   exist (example `src/gpu_device.cpp:26064`; `RAGE-ASSET-REFUSE` pattern
   `src/rage/rage_asset_pipeline.cpp:509`). Generalising them is parked.
   Trigger: a soak log exceeds the size budget AND a census shows one marker
   owning the log (`tools/soak_census.py` LOG QUALITY withholds — that is the
   signal, e.g. F-054 shape).

## Also parked (menu-gate)

XMA bitstream, native RAGE upload (`GetTextureData` honest-`false`,
`src/rage/rage_asset_pipeline.cpp:499-516`), exotic prims / t4+ descriptors /
depth-resolve variants. Removal trigger for every refusal
(`src/rage/rage_ideal_flow.h:60-61`): a soak reaching menu with that refusal
at zero.

## Standing rules while parked

Never edit `generated/**`; one new `build/w*.log` per experiment; always
compile (`ninja_build.bat`); cite `file:line` or a log line for every claim.

## FPS recipe (parked until menu — recorded 2026-10-13 from LARecomp
docs + r/midnightclub progress-thread snippets; Reddit bodies are
fetch-walled, so thread text is snippet-grade and repo docs are primary)

Their 100 FPS is real gameplay frames on strong hardware, not a trick —
and not raw power either (a Threadripper+2080 owner reports choppiness;
settings dominate). Pieces, each with a home in our tree for later:
- Decouple game speed from frame rate ("scales with any FPS", progress
  #2) — else uncapped = 2x speed (their two-timestep-overwrite finding).
- 60 Hz present-interval patch (`li r11,2`→1 in the interval builder;
  LARecomp sub_824199B0 area) + monotonic host clock
  (`--clock_no_scaling`, kills the vblank catch-up spiral that collapsed
  long sessions to <10 FPS irreversibly).
- Windows timer granularity (`timeBeginPeriod(1)`) + vsync-off together;
  fence busy-wait throttled with yield (render-thread load 98.8→82.2%).
- Async shader precompile folded into loading (no present-path DXC).
- Frame-gen/vsync settings are optional garnish (45 bearable, 30 bad).
None of this moves until menu (MENU-GATE); our wall is task order at
second 12, theirs was pacing at 60+. Different race stage.

## Taken 2026-10-13 (host-only, no guest behavior change, no emulation)

- Monotonic guest timebase: max-latch in `QueryGuestTimebase`
  (`src/guest_memory.cpp:1089`) + throttled `TIMEBASE-CLAMP` row. Identity
  on a healthy clock; backward steps can never rewind guest time silently.
- 1 ms process timer granularity (`timeBeginPeriod` in
  `src/early_init.cpp`, winmm already linked) for the semaphore/vsync
  sleep slices.
- Deliberately NOT taken: `Present(1,0)` stays (vsync-on is correct while
  presents are heartbeat-paced; flipping it changes nothing guest-visible
  and buys tearing); no guest present-interval/timer patch (guest behavior
  change — post-menu work with its own gate); async shader compile is
  already at load (`StartWorker` in `Initialize`, `d3d12_backend.cpp:650`).
