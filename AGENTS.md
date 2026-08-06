# MCLA Native PC GPU

Project rules and agent routing for the Midnight Club native-PC renderer.
This file is loaded into every session. Detailed standards live in
`.opencode/rules/` (referenced automatically via `instructions`).

## Purpose

Replace the Xenos command-processor rendering path in the recompiled Xbox 360
game with a native Direct3D 12 renderer. Recompiled PPC code keeps running; its
rendering intent is captured at the high-level draw boundary and executed as
native D3D12 work. The default renderer mode must remain `legacy` until the
phase gates in `NATIVE_GPU_REBUILD_PLAN.md` pass.

## Stack

- C++23, CMake 3.25+, **Ninja + clang-cl** (MSVC `/utf-8`, `NOMINMAX`)
- D3D12, SDL3, ReXGlue SDK (Xenos GPU plugin), spdlog/fmt, Tracy
- Xbox 360 Xenos microcode -> IR -> HLSL/DXIL shader translation
- Node.js + better-sqlite3 for offline manifest/database tooling

## Build & verify

```text
configure:  cmake -S . -B build -G Ninja -DCMAKE_CXX_COMPILER=clang-cl -DCMAKE_BUILD_TYPE=RelWithDebInfo
build:      cmake --build build
run:        build/mcla.exe
offline:    shader corpus validators and IR dumps under build/ (see workflow.md)
```

Build after every focused change. Never leave the tree in a non-building state.

## Repo map

| Path | Role |
| --- | --- |
| `src/` | Application, hooks, D3D12 backend, guest-memory view |
| `src/renderer/` | Xenos decode/IR, shader translation, caches, validators |
| `generated/` | Recompilation output — **treat as input, never patch** |
| `rexglue-sdk/` | Vendored SDK (headers/libs/cmake). Do not edit |
| `.research/` | Reference recomp projects (XenosRecomp, Xenia cache, etc.) |
| `build/` | Build outputs, trace dumps, shader IR dumps |
| `mcla_manifest*.toml` | Game manifest; edited via node tooling, not by hand |

## Golden rules

1. **One hook owner per guest address.** Use the composable dispatcher; never
   register the same address in two places.
2. **Hooks only capture state.** They must not call D3D12 or depend on
   `rex::graphics::RegisterFile`.
3. **Guest pointers are 32-bit guest addresses with bounds**, never raw host
   pointers; reads go through the checked guest-memory helper.
4. **Endianness is explicit** (`ReadU16BE`, `ReadU32BE`, `ReadF32BE`). No
   `reinterpret_cast` for guest data.
5. **No invented draw data.** Unknown capture data must be researched, not
   defaulted.
6. **Do not claim a path is native while it calls the Xenos command
   processor, submits PM4, or relies on guessed draw data.**
7. Keep generated code unchanged; validate before you trust a struct field.

Full standards: `.opencode/rules/coding-standards.md` · workflow:
`.opencode/rules/workflow.md` · phase plan: `NATIVE_GPU_REBUILD_PLAN.md`.

## Agent catalog

Cycle primaries with **Tab**; invoke subagents with `@name`.

| Agent | Mode | Model | Role / when to use |
| --- | --- | --- | --- |
| `architect` | primary | `omniroute/gh/claude-opus-4.7` | System design, phase planning, ownership decisions. Start here for design work |
| `gpu-engineer` | primary (default) | `omniroute/auto/coding` | Native renderer / D3D12 / C++ implementation. Default agent |
| `reverser` | primary | `omniroute/gh/claude-opus-4.7` | PPC/recomp analysis, guest struct discovery, hook-chain forensics |
| `perf-engineer` | primary | `omniroute/auto/coding:pro` | GPU/CPU perf, Tracy, upload/cache tuning, frame pacing |
| `shader-translator` | subagent | `omniroute/gh/claude-opus-4.7` | Xenos microcode decode, IR, HLSL/DXIL codegen |
| `debugger` | subagent | `omniroute/gh/claude-sonnet-4.6` | Crash/assert/validation-warning triage |
| `code-reviewer` | subagent | `omniroute/gh/claude-sonnet-4.6` | Read-only PR/diff review, convention + hook-ownership checks |
| `security-auditor` | subagent | `omniroute/gh/claude-sonnet-4.6` | Read-only memory-safety audit (OOB, bounds, endianness) |
| `build-specialist` | subagent | `omniroute/auto/coding:fast` | CMake/toolchain/link/ABI issues |
| `test-engineer` | subagent | `omniroute/auto/coding:cheap` | Offline validators, smoke gates, corpus regression checks |
| `docs-writer` | subagent | `omniroute/gh/claude-sonnet-4.6` | Plan docs, handoff notes, phase reports |
| `research-scout` | subagent | `omniroute/auto/best-reasoning` | External reference research (Xenia, XenosRecomp, UnleashedRecomp) |
| `node-tooling` | subagent | `omniroute/auto/coding` | Manifest/database and node tooling side |

## Routing

- Design/reverse-engineering questions -> `architect` / `reverser`.
- Implementation -> `gpu-engineer`; shader work -> `shader-translator`.
- Perf -> `perf-engineer`; failures -> `debugger`; builds -> `build-specialist`.
- Always route through a code review (`code-reviewer`) and, for guest-memory /
  pointer-touching changes, a `security-auditor` pass before claiming done.
- Offline/headless verification -> `test-engineer`; external lookups ->
  `research-scout`; docs/notes -> `docs-writer`.

## Skills

Relevant installed skills are auto-discovered. Prefer the specialized ones over
generic approaches:

| Task | Skill |
| --- | --- |
| C++23 implementation | `cpp-pro` |
| Crash/stack-trace analysis | `debugging-wizard` |
| Code review | `code-reviewer` |
| Security/memory audit | `security-reviewer` / `secure-code-guardian` |
| Testing/validation | `test-master` |
| Docs | `code-documenter` |
| Game/graphics systems | `game-developer` |
| Reverse-engineering legacy code | `spec-miner` |
| Architecture decisions | `architecture-designer` |

The project-specific `mcla-phase-gate` skill enforces the phase discipline and
handoff checklist; invoke it before starting any `NATIVE_GPU_REBUILD_PLAN.md`
task.
