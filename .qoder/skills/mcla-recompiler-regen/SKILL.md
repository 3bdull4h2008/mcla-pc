---
name: mcla-recompiler-regen
description: Safely regenerate or hook generated/ppc_xenon for the MCLA PC project - reproducibility gate, scratch-tree rule, TU-count invariant, the ppc_recomp.10.cpp hand patch, and the currently broken tool build. Use when a recompiler stub, VMX128 op, jump table or midasm hook is being changed, or when Route B comes back on the critical path.
---

# Recompiler regen (Route A/B/C)

`generated/**` and `.research/**` are **forbidden edit paths** (`docs/PROGRAM_GUIDE.md` §11) and
both are gitignored. Nothing may be regenerated straight into the project tree.

## 0. Current blocker (verified 2026-09-20)

The tool cannot be rebuilt: MSVC STL 14.51 demands Clang ≥ 20, LLVM here is 19 →
`yvals_core.h(917): STL1000`. **Do not delete anything under
`.research/XenonRecomp/build-clang/`** — the existing `XenonRecomp.exe` predates the VS upgrade and
is the *only* binary carrying the landed `JTS-TAILCALL` patch. Remedies if Route B is ever needed:
install Clang ≥ 20, or reconfigure `build-clang` for `cl.exe`, or pin the 14.44 toolset.
As of 2026-09-20 Route B is **off the critical path** — the type-5 `vupkd3d128` cluster is not
reached (`LONG_TODO_MASTER.md` §0), so do not spend a session on LLVM.

## 1. Prefer Route A (hook in the tracked TOML)

`config/mcla_xenonrecomp.toml` is tracked; a `[[midasm_hook]]` + a host function in
`src/cpu/vmx128_pack.cpp` keeps the change in version control and leaves the vendored tool
untouched. Four type-2 pack sites are landed this way. Route A does not scale past a handful of
sites (94 would be unmaintainable → that is Route B).

## 2. If the tool source must change

Save the diff **outside** `.research/` immediately:

```bash
cd "E:/mcla pc" && git -C .research/XenonRecomp diff -- XenonRecomp/ XenonUtils/ XenonAnalyse/ > tools/xenonrecomp_local.patch
grep -c "JTS-TAILCALL" tools/xenonrecomp_local.patch    # must be >= 1
```

`tools/xenonrecomp_local.patch` is the tracked copy of the tool patch — if it is missing or does not
match `git -C .research/XenonRecomp diff`, the source has drifted from the binary. Fix that before
any regen work.

## 3. Reproducibility gate (hard, run before touching the tool)

1. Regen **unmodified** into scratch: `build/xr_baseline` via
   `config/mcla_xenonrecomp_baseline.toml` (identical to the live config except `out_directory_path`).
2. `diff -r build/xr_baseline generated/ppc_xenon` — session 75 got 181/183 byte-identical
   (`ppc_context.h` trailing newline; `ppc_recomp.10.cpp` carries a **hand safety patch** inside
   `sub_8218CC70` — indirect-branch `targetFn`/`basePtr` validation — that the tool cannot emit).
   **Never full-replace `ppc_recomp.10.cpp`** or the session-38 null-dispatch AV returns.
3. If a fresh regen is not byte-for-byte clean → **STOP**, fall back to Route A/C.

## 4. Invocation gotchas that fail silently

- The config path must be a **bare filename** run from the repo root; a separator makes
  `recompiler_config.cpp:5` derive `directoryPath` wrong and the run exits 127 with no useful error.
- Header round-trip: `tail -n +4 generated/ppc_xenon/ppc_context.h > src/ppc_context.h`
  (the generated file prepends `#pragma once` + `#include "ppc_config.h"` + blank; `cmp`-clean).
- **TU count must stay 176** — `CMakeLists.txt` hardcodes `ppc_recomp.0..175.cpp`. A regen that
  changes the count breaks the build.
- Never unity-batch or regroup `generated/` TUs (input only; CMake regrouping is the sole allowed
  touch, per `docs/CODE_OPTIMIZATION_PLAN.md`).

## 5. VMX128 work in flight

Semantics and site census are settled in `docs/PLAN_VMX128.md` — **do not re-derive**. Open items:
type-2 unpack (§2.3, 1 site `0x821B43D8`), type-5 unpack (§2.2, 94 sites, Route B), `vcmpbfp128`
(§2.4, `0x825CEA2C`). Risk R5 is a project rule: never "fix" a trap by skipping the instruction.
The `VMX128-PACK` counter has never fired, so Route A is **not runtime-validated** — say so.
