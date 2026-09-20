# CODE OPTIMIZATION PLAN — coding policy (Ponytail+)

> **Policy file — still in force.** The *task* side of this plan is superseded by
> `docs/LONG_TODO_MASTER.md` (ordered queue) and `docs/CODE_OPTIMIZATION_PLAN.md` (status +
> remaining work). What stays here is the coding ladder and the guardrails.
> **VOID: the old Phase 0 "patch crash sites in generated code"** — `generated/**` is input-only,
> never edited. The old Phase-1 deletions were superseded by the real reorg (validators are
> gate exes in `tools/validators/`; hooks live in `src/hooks/`).

## The ladder (stop at first rung that holds; read the code first)

1. Does this need to exist? Speculative = skip (YAGNI).
2. Already in codebase? Reuse.
3. Stdlib does it? Use it.
4. Native platform covers it? Prefer it.
5. Installed dep solves it? Use it; never add one for what few lines do.
6. Can it be one line? One line.
7. Only then: minimum code that works.

**Never cut:** trust-boundary validation · data-loss error handling · security ·
accessibility basics · anything explicitly requested.
Deliberate shortcuts get `// ponytail: <ceiling>; <upgrade path>`.
Intensity: `lite` for boot/GPU census areas, `full` default, `ultra` greenfield only.

## MCLA guardrails (override everything above)

**Don't simplify ever:** guest-memory bounds checks · VEH boot-worker recovery ·
TLS allocator chain init · `shader_pipeline_validator.cpp` · present ordering ·
`PPC_FUNC`/`PPC_FUNC_IMPL` macros · `MCLA_LOG_*` structured logging (only
observability) · `GuestMemoryHeap::Instance()` singleton · `static std::atomic`
one-time init · `gpu_cp/gpu_mmio` register mapping · `src/kernel/imports.cpp`
stubs (deleting breaks the game) · `pipeline_cache`/`resource_cache` (perf-critical).

**Anti-patterns still true:** comments explaining "what" (use types) ·
single-impl interfaces/factories · shared_ptr by default · optimize before
profiling · dead code "just in case" (git remembers) · config for constants ·
fix symptom in one caller instead of root · measure success by LOC instead of
defects/review time. Net-code-size metric: writing 50 lines that delete 200 = win.

## Execution gates (every optimization)

Build clean → 60 s smoke boot with no new `[error]` classes and unchanged
frontier markers → one `opt:`-prefixed commit per move → trail updated.
Optimization never blocks the playable-loop waves (LONG_TODO rule 9).
