---
name: second-brain
description: Durable project memory for decisions, assumptions, handoffs, context budget
---

# Second Brain — MCLA Native PC GPU

## Purpose
Persistent memory layer for decisions, assumptions, phase gates, golden rules, and agent routing. Survives session compaction (which is disabled but discipline remains).

## Memory Store (file ledger — CANONICAL)
> ⚠️ The `second_brain_*` MCP tools are **opencode-only and unattached in
> Cline** — the file ledger below is the store. `.opencode/memory/` is a stale
> duplicate; do not write there.
| Operation | How (Cline) |
|------|-------------|
| store | Append a tagged entry (subject:/tags:/confidence:/source:/content:) to `.clinerules/memory/memories-*.md` |
| recall | Read `.clinerules/memory/memories-*.md` + `docs/handoffs/` for the subject |
| search | Grep `.clinerules/memory/` and `docs/handoffs/` |
| list subjects | List `.clinerules/memory/memories-*.md` |

## Memory Schema
```json
{
  "subject": "hook:draw_indexed",
  "tags": ["phase-1", "hook", "guest-address:0x80123456"],
  "content": "Hook at 0x80123456 captures draw indexed state. Struct: u32 index_count, u32 start_index, u32 base_vertex. Verified via Ghidra + security-auditor.",
  "confidence": "high",
  "source": "reverser + ghidra_analyze"
}
```

## Core Subjects to Maintain
| Subject Prefix | Examples |
|----------------|----------|
| `phase:` | `phase-1:hook-discovery`, `phase-2:shader-translation` |
| `hook:` | `hook:draw_indexed`, `hook:set_render_target` |
| `struct:` | `struct:XenosDrawCall`, `struct:VertexBufferBinding` |
| `register:` | `register:XREG_VS_CONFIG`, `register:XREG_TEX_SAMPLER` |
| `decision:` | `decision:legacy-default-mode`, `decision:pipeline-key-fields` |
| `assumption:` | `assumption:guest-ram-512mb`, `assumption:d3d12-fl11_0` |
| `open-question:` | `open-question:vertex-fetch-format`, `open-question:hi-z` |

## Handoff Protocol
Before session end or task switch:
1. `second_brain_store` all new decisions, assumptions, addresses, evidence (file-ledger: append to `.clinerules/memory/`)
2. Tag with current phase and agent
3. Write lossless handoff markdown to `docs/handoffs/`

## Context Budget Advisor
- Grep the ledger + `docs/handoffs/` BEFORE grep-spamming the tree
- Estimate tokens needed for task; if >50k, delegate to a subagent
- Never keep investigation state only in conversation
- Playbook: `docs/AI_PROMPT_PLAYBOOK.md` (templates T1–T6)