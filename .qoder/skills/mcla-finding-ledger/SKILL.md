---
name: mcla-finding-ledger
description: Record a verified finding, fix or mitigation in docs/ROOT_CAUSE_VALIDATION.md Part 3 using the F-### ledger format, and keep the HANDOFF/plan docs consistent with it. Use whenever a claim is about to be written down, committed, or reported as progress.
---

# Findings ledger discipline

The project's memory is three append-only files. Writing in the wrong place, or without evidence,
is how the 2026-09-20 false handoff happened (three confident claims, all already obsolete).

## Before writing: check for duplicates

🔴 **`docs/ROOT_CAUSE_VALIDATION.md` contains 1 NUL byte, so plain `grep` classifies it as binary and
silently returns 74 of 625 headings plus "Binary file matches".** Every grep below therefore carries
`-a`. Measured 2026-10-06: an agent ran the un-`-a` form, read `F-543` as the ledger top, and nearly
allocated a duplicate ID. **A backtick also breaks a pattern**: searching `agents.md rule 12` returns 0
while the file holds `` `agents.md` rule 12 `` at `:8581` — quote the words, not the markup.

```bash
cd "E:/mcla pc"
grep -an "F-04[0-9]" docs/ROOT_CAUSE_VALIDATION.md | tail -8
grep -ain "<your address or marker>" docs/*.md | head
# next free ID — never trust a number quoted in any doc, including this one:
grep -aoE "^### F-[0-9]+" docs/ROOT_CAUSE_VALIDATION.md | tail -1
ls -l --time-style=+%m-%d_%H:%M docs/            # another session may have moved it
```

If a doc changed since you read it, **re-read it**. If it already carries your finding, link the
existing ID instead of adding a second entry. Concurrent sessions are normal here — add dated
superseding blocks, never rewrite another session's text (append-only), and never renumber.

## Entry format (Part 3 of `docs/ROOT_CAUSE_VALIDATION.md`)

🔴 **Never take the next ID from this file — it is a snapshot and it rots.** This paragraph used to say
"ledger is at **F-089**, so the next ID is **F-090**", citing `:1799`; both the number and the anchor are
long dead. **Run the command instead:**

```bash
grep -aoE "^### F-[0-9]+" docs/ROOT_CAUSE_VALIDATION.md | tail -1   # -a is mandatory, see above
```

Measured 2026-10-06: **625** headings, top **`### F-773`**. Both heading punctuations are live and
neither is wrong — **425** entries use an em-dash (`### F-745 — …`), **206** use a plain hyphen
(`### F-773 - …`). Match whichever the neighbouring entries use. The five field lines below are
**optional in practice**: only **8 of the last 20** entries carry them. Use them for a FIX or anything
that will be re-tested; a short FACT/REFUTED entry with a bold provenance line and a body is equally
correct and is what the recent tail looks like. The old `**F-0NN — …** FACT | …` one-liner form is NOT
what is in the file — grep `^### F-` for real entries; `**F-0` hits are inline references inside other
entries. **Known ID voids, do not renumber or reuse:** F-056…F-076 (that week survives only as
unnumbered prose), F-412…F-429 (never allocated — F-773), and F-629 (reconstructed as F-635).

```
### F-0NN — <the claim, as one sentence>

- Task:        T## (and the wave log, e.g. `build/w43a.log`)
- Type:        FACT | INFERENCE | FIX
- Class:       A..I
- Priority:    P0..P4
- Evidence:    <log file:line · raw words from build/cache/mcla_pe.bin · src file:line>
<body — one bold lead per item>
```

**If a marker's printer is counter-capped (`n <= 40`, `(n % 250) == 0`), say so and say what the cap
hides** — a zero from a capped printer is not a negative result (F-089 §6 lost a whole conclusion this
way: `TOC76` stopped at #80, 1 ms before the lookups that mattered).

Classification: A = recompiler/codegen, B = generated code computes wrong, C = guest ABI/pointer/
endianness, D = kernel/runtime implementation, E = filesystem/device, F = GPU/shader translation,
G = the game's own coded behavior, H = instrumentation artifact, I = insufficient evidence.

**Numbering hole to know about (F-090 audit, 2026-09-23):** the live ledger has **no numbered entries
between F-056 and F-077** — that week survives only as unnumbered prose at
`ROOT_CAUSE_VALIDATION.md:1071-1166` (identical to `LEDGER-ADDENDUM.md` in the emergency backup), and
seven F-numbers are cited *from `src/`* with no entry to resolve to (F-057 `gpu_cp.h:30`,
F-058 `gpu_cp.cpp:828`, F-063 `gpu_device.cpp:11397`, F-066/067 `:11047`, F-073 `fs/vfs_rpf.h:18`,
F-076 `vfs_rpf.h:20`). So **grepping for a cited F-number and finding nothing does NOT mean it was
invented** — check that prose block and `C:\mcla-emergency-20260921-0112\` before calling a citation
bogus, and never re-use an ID in the gap.

Rules that make or break the entry:

- **No soak-log line / raw word / `file:line` → no entry.** Report it as unverified prose instead.
- A commit-only claim must be marked `UNVERIFIED` until a soak reproduces it (rule 13).
- A mitigation must be **named as a mitigation** and must cite the `file:line` that implements it.
  Silent short-circuits are the single biggest historical cost (do-not #9: never stack them).
- Prefer superseding to correcting: if an older F-### is now known wrong, add a new entry that
  states "supersedes F-0NN" rather than editing history.

## Keeping the other docs honest

| Doc | Update when |
|---|---|
| `docs/LONG_TODO_MASTER.md` §0 + §2 | the frontier or task order changes; state = dated "verified <HH:MM>" block |
| `docs/HANDOFF_NEXT_AGENT.md` | a session ends — one ledger row + the live block |
| `docs/PROGRAM_GUIDE.md` §7 / §9 | a new host short-circuit or log marker exists (they must appear in the tables or the next session cannot see them) |
| `docs/EXECUTION_PHASES.md` | a phase closes |

`docs/` must be added explicitly if it is ever re-ignored — check with
`git check-ignore -v docs/<file>` before assuming a doc is tracked, then `git add -f`.
