---
name: mcla-trail-writer
description: Write project findings down in the right place with the right voice: ledger F-entries, TASK/INDEX pointer updates, and vibe-language user summaries. Use whenever a session ends, a campaign closes, or the user asks what happened.
---

# Trail-writer discipline

You are the project's writing agent. Three destinations, three voices. Never mix them.

## 1. Ledger (`docs/ROOT_CAUSE_VALIDATION.md` Part 3) — evidence voice

Append-only. New `### F-NNN` entry at the tail, never a rewrite, never a renumber.
Format and ID rules live in `mcla-finding-ledger` — follow that skill exactly.
Extra writer rules:

- **Re-verify every claim before writing it.** Re-run the count, re-read the
  cited lines. A finding verified two soaks ago is re-checked today or it
  ships marked UNVERIFIED with its falsifier.
- **Corrections are entries, not edits.** A wrong number in an old entry gets
  a new entry citing the old heading (`### F-NNN`), never a silent fix.
  Withdrawn claims keep their heading with cause (see F-639: heading as
  clearance).
- **Voids are load-bearing:** F-056…F-076 (hole), F-412…F-429 (never
  allocated), F-629 (reconstructed as F-635). Allocate with
  `grep -aoE "^### F-[0-9]+"` (the `-a` is mandatory — 1 NUL byte makes
  plain grep return 74 of 625+ headings).

## 2. Working docs (`TASK_*.md`, `COMPACT_*.md`, `INDEX_COMPACT.md`) — pointer voice

- Add dated blocks and new files only. Never rewrite another session's text.
- Before writing: check mtime; if it moved under you, re-read first.
- Prefer pointers over prose: `file:line` + log line + one sentence. Numbers
  rot (median drift measured in thousands of lines) — symbols over lines.
- `LONG_TODO_MASTER.md`, `HANDOFF_NEXT_AGENT.md`, `PROGRAM_GUIDE.md`,
  `ROOT_CAUSE_VALIDATION.md` get superseding blocks or nothing. They are
  other sessions' live documents.

## 3. Chat summaries — vibe voice

- Plain words first, numbers second. Every term translated on first use.
- Lead with what changed for the goal (boot → menu → playable), not with
  mechanism. Mechanism follows, short.
- Own your misses before reporting wins: withdrawn claims up top, with cause.
- Never state an unmeasured thing as fact. Predictions carry falsifiers.
- End with choices for the user (A/B/C with tradeoffs), never an open hole.
- Short. If it needs scrolling, it needs cutting.
