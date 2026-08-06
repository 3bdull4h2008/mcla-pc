# MCLA Workflow & Phase Discipline

Follow this before, during, and after any change to the renderer. The phase
plan is `NATIVE_GPU_REBUILD_PLAN.md`; the designated skill is
`mcla-phase-gate`.

## Before editing

1. Read `NATIVE_GPU_REBUILD_PLAN.md` and the immediately preceding phase.
2. `rg` the target guest function address; confirm it has exactly **one hook
   owner** (see Golden Rule 1).
3. Confirm the change is authorized by the current phase. Do not skip ahead:
   no D3D12-native work in Phase 0, no PM4 bypass before Phase 2, etc.

## During work

- Keep **generated/** unchanged. Validate before trusting any struct field.
- One vertical slice at a time. Leave the existing renderer mode functional so
  the tree always builds and boots.
- Guest reads go through the checked memory helper with explicit endian reads.
- Build after every focused change; never leave the tree non-building.

## Validation evidence

Record, per change:

- files changed and why;
- build command + result (expect zero errors);
- the validation gate you targeted and its outcome;
- any unresolved guest-structure assumptions (name the field + the evidence
  gap).
- `renderer_mode` stays `legacy` by default until the gate says otherwise.

## Offline / headless verification

- Shader corpus validators and IR dumps live under `build/`
  (`shader_ir`, `shader_ir_v2`, `shader_recompiled`).
- Run the shader decoder/validator over the corpus and confirm
  `0 unknown, 0 OOB` before claiming a decoder fix.
- `test-engineer` owns the smoke gates; do not hand-wave them.

## Handoff checklist (every continuation)

- [ ] Single hook owner per address confirmed
- [ ] Generated code untouched
- [ ] `legacy` still the default; prior mode still functional
- [ ] Built cleanly; build command + result recorded
- [ ] Validation evidence and assumptions written down
- [ ] Never claimed "native" while calling the Xenos command processor / PM4 /
  guessed draw data

## Phase-gate skill

Invoke the `mcla-phase-gate` skill (`.opencode/skills/mcla-phase-gate`) before
starting any task named in `NATIVE_GPU_REBUILD_PLAN.md`. It enforces the
ordering above.