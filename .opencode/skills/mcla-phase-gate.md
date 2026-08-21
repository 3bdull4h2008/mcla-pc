---
name: mcla-phase-gate
description: Enforces MCLA_REBUILD_PLAN.md phase discipline and handoff checklist
---

# MCLA Phase Gate — MCLA Native PC GPU

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
- [ ] Query `second_brain` for prior phase decisions/assumptions
- [ ] List strategies (first-principles, hypothesis-driven, adversarial, search)
- [ ] Step-by-step plan with validation gates
- [ ] Route through `architect` for design review

## Post-Phase Checklist
- [ ] All gate criteria verified (automated + manual)
- [ ] `code-reviewer` pass on all changes
- [ ] `security-auditor` pass on guest-memory changes
- [ ] Update `.opencode/docs/architecture.md`
- [ ] Write handoff via `memory-steward` / `second_brain_store`
- [ ] Run `build/mcla.exe --validate-shaders --headless`

## Anti-Patterns
- ❌ Starting implementation before `architect` review
- ❌ Claiming phase complete without gate verification
- ❌ Advancing phase with known validation warnings
- ❌ Skipping handoff documentation

## Invocation
Run this skill before starting any task tagged with a phase in `MCLA_REBUILD_PLAN.md`.