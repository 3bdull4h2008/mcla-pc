---
name: mcla-phase-gate
description: Enforces MCLA phase discipline before starting any NATIVE_GPU_REBUILD_PLAN.md task. Use when beginning a renderer phase, modifying hook ownership, or checking whether a change is phase-authorized.
---

# MCLA Phase Gate

This project moves through ordered phases in `NATIVE_GPU_REBUILD_PLAN.md`.
Run this gate before starting a task so you do real, authorized work that
leaves the tree building and the default `legacy` mode intact.

## Gate checks (do these in order)

1. **Phase authorization.** Determine the phase named in the task and confirm
   the change is allowed by it. If the step belongs to a later phase, stop and
   report the prerequisite. Do **not** skip ahead.
2. **Hook ownership.** The target guest address must have exactly one hook
   owner. If another file registers it (e.g. both `gpu_mmio.cpp` and
   `native_renderer.cpp` on `0x8241BD08`), consolidate via the dispatcher
   before proceeding.
3. **Generated code.** No edits under `generated/`. It is input.
4. **No invented data.** Unknown capture structs/fields are researched, not
   defaulted. Fields in `MclaGpuContext` must be proven before use.
5. **Build.** Configure with Ninja + clang-cl + RelWithDebInfo; build and
   confirm zero errors before claiming done.

## Output

Report: phase name, authorized?, hook owners checked, generated code
untouched, build command + result.