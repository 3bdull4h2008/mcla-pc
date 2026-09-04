# AI Prompt Playbook — MCLA-PC

Researched 2026-09-03 from primary sources; analyzed against our stack
(Xbox 360 static recompilation, PPC/RE, D3D12, agent-driven development).
Every template in Part C is tailored to this repo's agents, gates, and ledger.

**Sources (all fetched & analyzed 2026-09-03):**
- S-A: Anthropic, "Best practices for Claude Code" (agentic coding patterns)
- S-B: Anthropic, "Writing effective tools for agents" (tool/MCP design)
- S-C: OpenAI, "Prompt engineering" guide (agentic tasks, reasoning models)
- S-D: x1xhlol, "system-prompts-and-models-of-ai-tools" (143k★; real system
  prompts of Cursor/Devin/Windsurf/VSCode Agent — structural conventions)
- E: `.research/UnleashedRecomp` + vendor docs for domain specifics

---

## Part A — What the sources teach (distilled)

**From S-A (agentic coding):**
1. **Give the agent a way to verify its work** — a runnable check beats any
   amount of prose instruction. If you can't verify it, don't ship it.
2. **Explore first, then plan, then code** — never let the implementer read
   and write in the same pass.
3. **Adversarial review with anti-over-engineering clause** — a reviewer told
   to "find gaps" will invent some; instruct it to flag ONLY gaps affecting
   correctness or stated requirements, treat the rest as optional.
4. **Named failure patterns**: kitchen-sink session (unrelated topics share
   context), correcting-loop (2 failed corrections → clear + rewrite prompt
   with what was learned), over-specified rules file (ignored in the noise),
   trust-then-verify gap, infinite unscoped exploration.
5. **Subagents for investigation** — keep exploration out of the main context;
   distilled findings return, raw dumps stay in the subagent.

**From S-B (tools for agents):**
6. Tools are a contract with a NON-deterministic caller — write descriptions
   for the agent, not for a developer. Name tools by task outcome, namespace
   them, return meaningful context (not raw dumps), optimize token cost of
   responses, and parameter names should match agent vocabulary.
7. Evaluation-driven tool improvement: small description refinements produced
   measurable SWE-bench gains — treat MCP tool text as code, review it.

**From S-C (OpenAI):**
8. **Agentic persistence instruction**: "keep going until the query is fully
   resolved; decompose into sub-requests; reflect after each tool call; only
   terminate when done."
9. **Preambles**: explain WHY a tool is called, but only at notable steps
   (transparency without noise).
10. **Rubric/TODO tracking** to enforce structured planning — no missed steps.
11. **Reasoning vs non-reasoning framing**: reasoning models are "senior
    coworkers" (give goals, not steps); non-reasoning models are "junior
    coworkers" (give explicit steps). Pick instruction density per model.
12. Code tasks: principles → structure → components → agent instructions;
    state assumptions explicitly and test states.

**From S-D (real agent system prompts):**
13. Cross-vendor conventions worth copying: a short identity/role block; an
    explicit tool-use policy (when NOT to call); output-contract sections;
    "you MUST/NEVER" for hard rules vs soft prose for guidance; memory/state
    files updated at defined moments (not ad hoc).

**Already ours (Loop Discipline in this plan) matches the best of S-A/S-C:**
verification ladder = (1); run receipts + terminal states = (10); caps on
failed hypotheses = the correcting-loop fix; maker/checker = (3). What we
LACKED until this playbook: ready-made prompt bodies per agent, the
anti-over-engineering clause for reviewers, persistence/preamble language,
and a census-design workflow.

---

## Part B — Pattern → project mapping

| # | Pattern (source) | Where it lands here |
|---|------------------|---------------------|
| P1 | Verify-your-work loop (S-A) | Every template in Part C ends with a runnable gate (`phase0_validator`, gate runner, census log signature) |
| P2 | Explore→plan→code (S-A) | gpu-engineer template T5 (plan slice BEFORE touching src) |
| P3 | Anti-over-engineering reviewer clause (S-A) | code-reviewer upgrade — see `.clinerules/custom-modes.json` note + T6 |
| P4 | Failure-pattern avoidance (S-A) | Playbook Part D; one-session-one-front rule already in plan §Loop Discipline |
| P5 | Persistence + reflect-after-tool (S-C) | census-design workflow (new, `.clinerules/workflows/census-design.md`) |
| P6 | Preambles at notable steps (S-C) | census workflow + T2 |
| P7 | TODO/rubric tracking (S-C) | T5 step table = the rubric |
| P8 | Senior/junior instruction density (S-C) | gate-cracker/reverser = senior style (goals + contracts); gpu-engineer = junior style (explicit steps) |
| P9 | Output contracts + MUST/NEVER markup (S-D) | gate-cracker exit-condition table (already), T1 formalizes |
| P10 | Tool-text-as-code, eval-driven (S-B) | applies to our ghidra/ida/renderdoc/pix MCP prompts — review tool descriptions when RE output quality drops; see Part E |

---

## Part C — Ready-to-use prompt templates

Copy the block, fill the `<>` slots, paste to the named agent/mode.

### T1 · RE decode request → `reverser` / `gate-cracker` (senior style, S-C P8 + S-D P9)

```text
TARGET: <guest address / symbol, e.g. sub_8242FC1C>
QUESTION: <"who writes/advances X on hardware" | "what makes this wait exit">

Deliverable (exact contract):
1. Disassembly → pseudo-C for the target, every claim cited file:line from
   generated/ppc_xenon/*.cpp. No folklore, no guessed field names.
2. Exit-condition table: | # | condition (pseudo-C) | effect | r3 on exit | evidence |
3. Ranked emulation points for OUR host: each = mechanism, data source
   (derived-from-what), risk, and what would DISPROVE it.
4. If a rate/magnitude is unknowable statically: say so and design a runtime
   probe instead of guessing.
Rules: decode semantics not syntax (subf r10,r11,r30 = r30-r11). Max 2 decode
attempts per ambiguity, then present both readings + discriminating probe.
Freeze line respected: propose kernel-role fixes only, no PM4, no seeding.
```

### T2 · Census design → `gpu-engineer` (P1+P5+P6)

```text
GOAL: <e.g. "classify sub_821DE9D8 return-0 paths: refill vs no-refill">
Plan the census BEFORE touching src:
1. State the verifiable prediction: "if <hypothesis>, log signature <X> appears
   within <N>s of boot; if <alternative>, signature <Y> instead."
2. Plan the smallest override that answers ONLY that question
   (PPC_FUNC weak-alias, checked reads only, no D3D12, log throttled).
3. List every guest field you will read with its provenance (which TU proves
   that offset) — assert every offset; wrong offsets fail SILENTLY.
4. State the cleanup: what gets deleted when the census is answered.
Then implement, build, and end with a RUN receipt:
RUN n: trigger=<change> | expect=<prediction> | observed=<signature> |
state=<SUCCESS|NO-OP|BLOCKED|STALLED|EXHAUSTED> | next=<one action>
Persist the receipt to the ledger (.clinerules/memory/) — do not end the turn
before it is written.
```

### T3 · Crash triage → `debugger` (S-A failure-pattern aware)

```text
SYMPTOM: <fault addr / regs / log signature>
KNOWN: <what previous sessions proved — cite ledger/handoff sections>
Constraints: max 3 failed hypotheses on one theory, then mandatory bisection
to last known-good. Two consecutive regressions = revert + record proven-negative.
Method: 1) reproduce + capture full evidence (host stack, guest LR, regs,
PPC_LOOKUP_FUNC slot). 2) Map to decoded sites in the plan's Investigation
Record BEFORE theorizing. 3) Name the terminal state you expect.
Verify with: <exact command, e.g. build\mcla.exe 60s soak + log grep>.
```

### T4 · Security audit → `security-auditor` (S-A P3 anti-over-engineering)

```text
SCOPE: <diff / files, e.g. patches.cpp census overrides>
Audit ONLY for gaps affecting CORRECTNESS or MEMORY SAFETY: guest-VA-as-host
pointer, unchecked Translate+reinterpret_cast, offset provenance, bounds
(OOB), endianness, TOCTOU on translated pointers.
Do NOT report style preferences, abstraction opportunities, or defensive code
for impossible states — out of scope by directive.
Output: | finding | file:line | rule violated | concrete failure scenario | fix direction |
Every finding must name a realistic guest-control path or be marked THEORETICAL.
```

### T5 · Implementation slice → `gpu-engineer` (P2+P7 explore→plan→code)

```text
TASK: <one phase-gate slice, e.g. "P4.6′ dirty tracking for GuestTexture">
Do a plan pass FIRST — no edits:
1. Read only: the owning files + the plan section + relevant ledger entries.
2. Produce a step table (rubric): | step | files | verification command |
   expected evidence |. No step without a runnable check.
3. List assumptions explicitly; route unknown guest fields to reverser.
Then implement step-by-step; after EACH step run its verification command and
state pass/fail before moving on. Build stays green (Ninja+clang-cl,
RelWithDebInfo) after every focused change. End with the gate run:
build\phase0_validator.exe (13/13 required) + <slice-specific validator>.
```

### T6 · Adversarial review → `code-reviewer` (P3 — anti-over-engineering clause)

```text
Review <diff> against: docs/AGENTS.md golden rules, .clinerules/coding-standards.md,
docs/MCLA_REBUILD_PLAN.md (current phase + SOURCE-vs-PLAN AUDIT S1–S9).
Flag ONLY: correctness gaps, golden-rule violations, hook-ownership conflicts,
regressions vs the last known-good run. Everything else = optional note.
Maker/checker rule: you did not write this diff; grade output, not path — a fix
that passes the validator via a different mechanism than predicted still counts.
End with: APPROVE | REQUEST-CHANGES <numbered, blocking only>.
```

---

## Part D — Failure patterns → our context (S-A, adapted)

| Failure | Our local form | Countermeasure |
|---|---|---|
| Kitchen-sink session | blocker debugging + doc editing + config fiddling in one context | one front per session; ledger already externalizes state |
| Correcting-loop | agent "fixes" a census twice, still wrong | cap is formalized: 3 failed hypotheses → bisect; 2 regressions → revert |
| Over-specified rules file | .clinerules bloat | rules stay lean; playbooks live in docs/, loaded on demand |
| Trust-then-verify gap | "should boot now" claims | rung ≥2 evidence law + RUN receipts (already Loop Discipline) |
| Infinite exploration | grepping all 179 TUs in main context | subagent routing (reverser/gate-cracker) + targeted slices |

## Part E — MCP tool-prompting lessons (S-B) for ghidra/ida/renderdoc/pix

- Tool text is CODE: when RE output quality drops, review the MCP tool
  descriptions before blaming the model — describe task outcomes, not RPC
  mechanics; return distilled context (addresses + types), not raw dumps.
- Parameter names should match the vocabulary agents already use
  (`guest_address`, not `addrIn`).
- Our "two sources per address claim" rule is S-B's evaluation-driven mindset
  applied to decode trust.

---
*Adoption note: T1–T6 are additive — they bind to existing agents and Loop
Discipline; no golden rule was weakened. Re-review this playbook when the
sources above publish newer agent guidance.*

