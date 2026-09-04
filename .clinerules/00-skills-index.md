# MCLA Skill & MCP Index (ported from .opencode)

This file is always loaded by Cline. It routes to project skills (invocable
as Cline workflows via `/name` from `.clinerules/workflows/`) and documents
the MCP servers ported from `opencode.json`.

## Skills → use the matching workflow when...

| Workflow | Use when |
|---|---|
| `/debugging-wizard` | Crash/stack-trace analysis, D3D12 validation errors, device removal |
| `/mcla-phase-gate` | Starting/finishing any `MCLA_REBUILD_PLAN.md` phase task (invoke BEFORE starting) |
| `/second-brain` | Persisting/recalling decisions, assumptions, handoffs, context budget |
| `ai-prompt-playbook` | Ready-made prompt templates T1–T6 for all agents (`docs/AI_PROMPT_PLAYBOOK.md`) — consult before dispatching subagent tasks |
| `/spec-miner` | Reverse-engineering undocumented Xenos GPU code, guest structs, microcode |
| `/the-fool` | Design review / pre-mortem / devil's advocate before major decisions |
| `/mcla-stall-forensics` | Guest parks/spins/stalls in a driver wait (PARK-SAMPLE, E98, ring waiters) |
| `/census-design` | Adding/retiring PPC_FUNC census overrides; runtime path-classification questions |

## MCP servers (Cline MCP panel)

- `ghidra` — bridge-mcp-ghidra.exe (listing, function, program, xref, analysis, documentation)
- `ida` — ida-pro-mcp.exe from idamcp-venv (supersedes old `ida-pro-mcp` entry, now disabled)
- `renderdoc` — renderdoc-mcp.exe from rdmcp-venv
- `pix` — pix-mcp.exe with PIXTOOL_PATH=C:\Program Files\Microsoft PIX\2603.25\pixtool.exe
- `davinci-resolve` — ported disabled from config.json (enable in Cline MCP panel if needed)

Note: the `second-brain` skill references `second_brain_*` MCP tools, but no
such MCP server is defined in config.json — it was plugin-based in opencode
and has no Cline equivalent. Maintain that memory as markdown handoffs in
`docs/handoffs/` instead.

## Custom modes (ported from opencode agents in config.json/opencode.json)

Switch modes from the Cline mode selector (or via `new_task` to delegate a
subtask in a specific mode — Cline's equivalent of opencode subagents):

| Mode (slug) | Role / when to use | Tool access |
|---|---|---|
| `gpu-engineer` | Native renderer / D3D12 / C++ implementation. Default mode | full; edits denied under `generated/` |
| `architect` | System design, phase planning, ownership decisions | read + MCP (ghidra/ida) |
| `reverser` | PPC/recomp analysis, guest struct discovery, hook forensics | read + MCP (ghidra/ida) |
| `shader-translator` | Xenos microcode decode, IR, HLSL/DXIL codegen | read/edit + MCP (renderdoc) |
| `perf-engineer` | GPU/CPU perf, upload/cache tuning, frame pacing | full |
| `debugger` | Crash/assert/validation-warning triage | full |
| `code-reviewer` | Read-only PR/diff review, conventions + hook ownership | read only |
| `security-auditor` | Read-only memory-safety audit (OOB, bounds, endianness) | read only |
| `build-specialist` | CMake/toolchain/link/ABI issues | read/edit/command |
| `test-engineer` | Offline validators, smoke gates, corpus regression | read/edit/command |
| `docs-writer` | Plan docs, handoff notes, phase reports | read/edit |
| `research-scout` | External reference research (Xenia, XenosRecomp, ...) | read only |
| `node-tooling` | Manifest/database and node tooling | read/edit/command |
| `gate-cracker` | GPU progress-gate decode: wait-primitive exit conditions, emulation-point ranking | read + MCP (ghidra/ida) |

Routing: implementation → `gpu-engineer`; shader work → `shader-translator`;
perf → `perf-engineer`; failures → `debugger`; builds → `build-specialist`;
design/RE → `architect`/`reverser`. Always finish with `code-reviewer`, plus
`security-auditor` for any guest-memory change.

## Rules (always loaded by Cline)

`coding-standards.md`, `workflow.md`, `context-management.md`, `ghidra-mcp.md`,
`ida-mcp.md`, `gpu-tooling-mcp.md` — the same instruction set, now in `.clinerules/`.
