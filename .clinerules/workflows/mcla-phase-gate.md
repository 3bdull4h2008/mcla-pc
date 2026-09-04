# MCLA Phase Gate — MCLA Native PC GPU

(Ported from `.opencode/skills/mcla-phase-gate.md`)

## Purpose
Enforce phase discipline from `MCLA_REBUILD_PLAN.md`. Never advance a phase until its gate criteria pass.

## Phase Gates Reference
| Phase | Name | Gate Criteria |
|-------|------|---------------|
| 0 | Bootstrap | Build passes, legacy mode runs, hooks register |
| 1 | Hook Discovery | All draw calls captured, guest structs documented |
| 2 | Shader Translation | Xenos microcode → IR → HLSL/DXIL validated |
| 3 | Native Draw | Translated draws execute on D3D12, visual parity |
| 4 | Resource Management | Textures/buffers/shadows native, no leaks |
| 5 | Performance | Frame time ≤ legacy, GPU utilization > 80% |
| 6 | Compatibility | All game content renders, no regressions |

## Pre-Phase Checklist
- [ ] Read `MCLA_REBUILD_PLAN.md` for current phase requirements
- [ ] Query handoffs/memory for prior phase decisions/assumptions
- [ ] List strategies (first-principles, hypothesis-driven, adversarial, search)
- [ ] Step-by-step plan with validation gates
- [ ] Route design through the architect role for design review

## Post-Phase Checklist
- [ ] All gate criteria verified (automated + manual)
- [ ] Code review pass on all changes
- [ ] Security-audit pass on guest-memory changes
- [ ] Update `docs/ARCHITECTURE.md`
- [ ] Write handoff markdown to `docs/handoffs/`
- [ ] Run `build/mcla.exe --validate-shaders --headless`

## Anti-Patterns
- ❌ Starting implementation before design review
- ❌ Claiming phase complete without gate verification
- ❌ Advancing phase with known validation warnings
- ❌ Skipping handoff documentation

## Invocation
Run this skill before starting any task tagged with a phase in `MCLA_REBUILD_PLAN.md`.
