# Workflow — MCLA Native PC GPU

## Phase Discipline
All work follows `MCLA_REBUILD_PLAN.md` phase gates. Never advance a phase until its gate criteria pass.

## Before Starting Any Task
1. **Search First** — grep/glob the codebase, check `.research/`, query the knowledge graph (`memory-steward` / `second-brain`)
2. **List Strategies** — Write down your thinking/acting strategies (first-principles, hypothesis-driven, adversarial self-critique, search strategy)
3. **Step-by-Step Plan** — Define precise implementation steps and validation gates
4. **Get Review** — For implementation tasks, route through `code-reviewer`; for guest-memory changes, also `security-auditor`

## Development Loop
```
configure:  cmake -S . -B build -G Ninja -DCMAKE_CXX_COMPILER=clang-cl -DCMAKE_BUILD_TYPE=RelWithDebInfo
build:      cmake --build build
run:        build/mcla.exe
validate:   build/mcla.exe --validate-shaders --headless
```
**Build after every focused change. Never leave the tree in a non-building state.**

## Hook Development
1. Discover guest address/struct via `reverser` (Ghidra, recomp output)
2. Add hook to `src/hooks/registry.cpp` using composable dispatcher
3. Hook captures **only** state — no D3D12, no side effects
4. Verify with `security-auditor` (bounds, endianness, OOB)
5. Register in dispatcher; one owner per address

## Shader Translation
1. Extract Xenos microcode → IR via `shader-translator` subagent
2. Validate IR dumps under `build/`
3. Generate HLSL/DXIL via offline tooling
4. Corpus regression check via `test-engineer`

## Perf Work
- Profile with Tracy + PIX/RenderDoc
- Use `perf-engineer` for upload/cache tuning, frame pacing
- Document findings in handoff notes

## Documentation & Handoffs
- Update `.opencode/docs/architecture.md` after phase lands
- Write lossless handoff via `memory-steward` / `docs-writer` before long sessions end
- Record decisions, assumptions, open questions in durable memory (`second-brain`)

## Context Discipline
- Auto-compaction **disabled** — manage context manually
- Delegate broad reads/search to subagents
- Query `codebase_memory_*` graph and `@architecture` before grep-spamming
- Read targeted slices (`Read` with `offset`/`limit`)
- Externalize exact state to handoff files before context pressure