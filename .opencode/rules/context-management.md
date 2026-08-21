# Context Management — MCLA Native PC GPU

## Context Budget
The active model has a 220k window and **auto-compaction/pruning are disabled** in this project (`compaction: { auto: false, prune: false }` in `opencode.json`) so long conversations are never silently summarized. That makes context discipline mandatory, not optional.

## Mandatory Practices

### 1. Delegate Broad Operations to Subagents
- Use `reverser` for PPC/recomp analysis and guest struct discovery
- Use `research-scout` for external reference research (Xenia, XenosRecomp, UnleashedRecomp)
- Use `debugger` for crash/assert/validation triage
- Use `code-reviewer` for read-only PR/diff review
- Use `security-auditor` for memory-safety audits
- Use `test-engineer` for offline validators and corpus regression

### 2. Query Knowledge Graph Before Grep
- Use `memory-steward` / `second-brain` to query `codebase_memory_*` graph
- Query `@architecture` reference for component navigation
- Only grep when graph/reference don't have the answer

### 3. Read Targeted Slices
- Use `Read` with `offset`/`limit` for large files
- Output is capped at 500 lines / 24 KiB per tool call
- Avoid tiny repeated slices (30 line chunks)

### 4. Externalize Exact State
- Write handoff files before context pressure
- Record: addresses, offsets, evidence, open questions
- Never rely on summarization — auto-compaction is disabled

## Handoff Protocol
Before ending a session or switching tasks:
1. Run `memory-steward` to persist decisions, assumptions, open questions
2. Write lossless handoff notes with exact state
3. Update `.opencode/docs/architecture.md` if phase landed

## Anti-Patterns to Avoid
- ❌ Reading entire large files "just to see"
- ❌ Grep-spamming without checking graph first
- ❌ Keeping investigation state only in conversation history
- ❌ Assuming context will be preserved automatically