# Census Design — MCLA Native PC GPU

Trigger: adding/retiring any PPC_FUNC census override (OOM-CENSUS-class work),
or answering a "which code path does X" question at runtime.
Prompt doctrine: docs/AI_PROMPT_PLAYBOOK.md T2 (patterns S-A P1, S-C P5/P6).

## Loop contract (per census)

- **Trigger:** a hypothesis that a static decode cannot settle.
- **Plan first, no edits:** state the verifiable prediction ("if <hyp>, log
  signature <X> within <N>s; if <alternative>, <Y> instead").
- **Smallest override:** PPC_FUNC weak-alias, checked reads only, no D3D12,
  throttled logging. One question per census.
- **Offset provenance:** every guest field read cites the TU that proves the
  offset; assert every offset — wrong offsets fail SILENTLY.
- **Cleanup declared upfront:** what gets deleted when answered (censuses are
  scaffolding, not features).

## Verification & receipt

- Build green (Ninja + clang-cl, RelWithDebInfo) before boot.
- Boot soak with log capture; grep the exact signature.
- Append RUN receipt to the ledger (`.clinerules/memory/`) — trigger | expect |
  observed | state | next. Do not end the session before it is written.
- Stall-forensics gotcha: instrumentation shifts timing — re-run 2–3x before
  declaring an intermittent behavior fixed/gone.

## Caps & terminal states

Per `docs/MCLA_REBUILD_PLAN.md` §Loop Discipline: 3 failed hypotheses → bisect;
2 regressions → revert + proven-negative. End in exactly one named state
(SUCCESS / NO-OP / BLOCKED / STALLED / EXHAUSTED). Freeze line: censuses are
kernel-role diagnostics — no PM4, no seeding, no opcode expansion.