# The Fool — MCLA Native PC GPU

(Ported from `.opencode/skills/the-fool.md`)

## Purpose
Adversarial review of architectural decisions, phase plans, and implementation approaches. Prevents overconfidence and catches blind spots.

## When to Invoke
- Before starting a new phase in `MCLA_REBUILD_PLAN.md`
- After completing a phase gate, before claiming success
- When making ownership decisions (hook addresses, resource lifetimes)
- When choosing between translation strategies (inline vs offline)

## Review Checklist

### Architecture
- [ ] Does this advance the phase gate or add incidental complexity?
- [ ] Is the legacy path truly isolated from native path?
- [ ] Are guest pointers fully contained in `GuestMemory`?
- [ ] Can this be tested offline without running the game?

### Hook Design
- [ ] Single owner per guest address enforced?
- [ ] Hook captures only state — zero D3D12 calls?
- [ ] All guest reads bounds-checked and endian-explicit?
- [ ] Unknown capture fields researched, not invented?

### Translation
- [ ] Xenos microcode → IR → HLSL pipeline validated?
- [ ] Shader corpus regression test passes?
- [ ] Pipeline key includes all relevant state (VS/PS/RS/DS/BS/IB/VB)?

### Performance
- [ ] Barriers batched per frame?
- [ ] Descriptor heap updates minimized?
- [ ] Upload heap usage tracked?
- [ ] Tracy zones on all GPU submission?

## Pre-Mortem Questions
1. What happens if the guest struct layout changes between game versions?
2. What if the Xenos microcode has undocumented instructions?
3. What if D3D12 feature level 11_0 is not available?
4. What if the recompiler emits different hook addresses?
5. What if the native path is slower than legacy?

## Output
Write findings to handoff notes in `docs/handoffs/` with:
- Decision record
- Assumptions made
- Open questions
- Risk mitigation
