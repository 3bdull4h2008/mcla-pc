# MCLA Native PC GPU

Project rules and agent routing for the Midnight Club native-PC renderer.
This file is loaded into every session. Detailed standards live in
`.opencode/rules/` (referenced automatically via `instructions`).

## Mandatory Core Mandates

1. **Search Before Acting:** You are not smarter than the internet or the codebase. Always perform searches (`websearch`, `grep`, `glob`, `ghidra`, `renderdoc`) to gather authoritative evidence, documentation, API specs, and existing patterns *before* acting or writing code. Never guess.
2. **List Strategies & Plan Before Execution:** Before executing any non-trivial task, explicitly list:
   - **Thinking & Acting Strategies:** First-principles decomposition, hypothesis-driven verification, adversarial self-critique (pre-mortem), and search strategy.
   - **Step-by-Step Plan & Validation Gates:** The precise sequence of implementation steps and how they will be verified.

## Purpose

Replace the Xenos command-processor rendering path in the recompiled Xbox 360
game with a native Direct3D 12 renderer. Recompiled PPC code keeps running; its
rendering intent is captured at the high-level draw boundary and executed as
native D3D12 work. The default renderer mode must remain `legacy` until the
phase gates in `MCLA_REBUILD_PLAN.md` pass.

## Stack

- C++23, CMake 3.25+, **Ninja + clang-cl** (MSVC `/utf-8`, `NOMINMAX`)
- D3D12, SDL3, spdlog/fmt, XenonRecomp + UnleashedRecomp kernel framework
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
| `third_party/` | Vendored third-party deps (SDL3, fmt, spdlog, toml++, DXC). No rexglue |
| `.research/` | Reference recomp projects (XenosRecomp, Xenia cache, etc.) |
| `build/` | Build outputs, trace dumps, shader IR dumps |
| `mcla_manifest*.toml` | Game manifest; edited via node tooling, not by hand |

## Golden rules

1. **One hook owner per guest address.** Use the composable dispatcher; never
   register the same address in two places.
2. **Hooks only capture state.** They must not call D3D12 or depend on
   `mcla::native::RegisterFile`.
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
`.opencode/rules/workflow.md` · phase plan: `MCLA_REBUILD_PLAN.md`.

## Agent catalog

Cycle primaries with **Tab**; invoke subagents with `@name`. Agent models
inherit the session default (global `model` in `~/.config/opencode/opencode.json`);
override per agent via the `model:` key in its frontmatter.

| Agent | Mode | Role / when to use |
| --- | --- | --- |
| `architect` | primary | System design, phase planning, ownership decisions. Start here for design work |
| `gpu-engineer` | primary (default) | Native renderer / D3D12 / C++ implementation. Default agent |
| `reverser` | primary | PPC/recomp analysis, guest struct discovery, hook-chain forensics |
| `perf-engineer` | primary | GPU/CPU perf, upload/cache tuning, frame pacing |
| `shader-translator` | subagent | Xenos microcode decode, IR, HLSL/DXIL codegen |
| `debugger` | subagent | Crash/assert/validation-warning triage |
| `code-reviewer` | subagent | Read-only PR/diff review, convention + hook-ownership checks |
| `security-auditor` | subagent | Read-only memory-safety audit (OOB, bounds, endianness) |
| `build-specialist` | subagent | CMake/toolchain/link/ABI issues |
| `test-engineer` | subagent | Offline validators, smoke gates, corpus regression checks |
| `docs-writer` | subagent | Plan docs, handoff notes, phase reports |
| `research-scout` | subagent | External reference research (Xenia, XenosRecomp, UnleashedRecomp) |
| `node-tooling` | subagent | Manifest/database and node tooling side |
| `memory-steward` | subagent | Persistent memory: codebase graph, architecture brainmap, lossless handoffs, context-budget advisor |

## Routing

- Design/reverse-engineering questions -> `architect` / `reverser`.
- Implementation -> `gpu-engineer`; shader work -> `shader-translator`.
- Perf -> `perf-engineer`; failures -> `debugger`; builds -> `build-specialist`.
- Always route through a code review (`code-reviewer`) and, for guest-memory /
  pointer-touching changes, a `security-auditor` pass before claiming done.
- Offline/headless verification -> `test-engineer`; external lookups ->
  `research-scout`; docs/notes -> `docs-writer`.
- Memory/graph/context -> `memory-steward`: refresh the knowledge graph or
  architecture brainmap after a phase lands, write lossless handoffs before
  long sessions end, and get context-budget advice when the window is tight.
  - **Second Brain MCP** (`second-brain_*`): query durable project memory for
    decisions, assumptions, phase gates, golden rules, agent routing, repo map.
    Use `brain_search`/`brain_recall_subject` instead of re-reading docs.

## Context budget

The active model has a 220k window and **auto-compaction/pruning are disabled**
in this project (`compaction: { auto: false, prune: false }` in
`opencode.json`) so long conversations are never silently summarized. That makes
context discipline mandatory, not optional:

- Delegate broad reads/search/decode/audit to subagents; keep only distilled
  findings in the main session.
- Query the `codebase_memory_*` graph and the `@architecture` reference before
  grep-spamming the tree.
- Read targeted slices (`Read` with `offset`/`limit`); output is capped at
  500 lines / 24 KiB.
- Externalize exact state (addresses, offsets, evidence, open questions) to
  handoff files before context pressure — never rely on summarization.

Full rules: `.opencode/rules/context-management.md`.

## Skills

Relevant installed skills are auto-discovered. Prefer the specialized ones over
generic approaches:

| Task | Skill |
| --- | --- |
| Crash/stack-trace analysis | `debugging-wizard` |
| Reverse-engineering legacy/undocumented code | `spec-miner` |
| Design review / pre-mortem / devil's advocate | `the-fool` |
| Durable project memory (decisions, assumptions, handoffs) | `second-brain` |

The project-specific `mcla-phase-gate` skill enforces the phase discipline and
handoff checklist; invoke it before starting any `MCLA_REBUILD_PLAN.md`
task. (The global catalog was deliberately slimmed from ~75 skills to the 3
above — see `.opencode/rules/gpu-tooling-mcp.md`.)
