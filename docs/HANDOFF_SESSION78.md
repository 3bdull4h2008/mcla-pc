# NOTE — 2026-09-20b (duplicate-work correction). Short file; read the real queue instead.

**The authoritative entry point is `docs/LONG_TODO_MASTER.md` §0 + §2 → work T37.0.**
Then `docs/HANDOFF_NEXT_AGENT.md` "LIVE" block. This file exists only to correct a
bad claim an agent (me) wrote earlier today, and to record two small real findings.

## 1. CORRECTION — the "broken stub" work was already finished; I re-derived it

Earlier today I wrote a long handoff asserting that the 30 residual broken-stub
targets were still open, that I had newly root-caused them, and that a `JTS-TAILCALL`
tool patch I had just authored was landed-but-uncompiled. **All of that was wrong.**
Verified against the tree, not against my recollection:

| Check | Result |
|---|---|
| `grep -hoE 'ERROR:? *0?x?[0-9A-Fa-f]{8}' generated/ppc_xenon/ppc_recomp.*.cpp \| wc -l` | **0** — zero broken stubs, not 91 |
| `git log --oneline -1 75ed486` | `session78: broken stubs 91 -> 0 (last 30 targets: parent+self spans, JTS-TAILCALL tool patch, dispatch guard as hook)` |
| `grep -c JTS-TAILCALL` in `XenonRecomp.exe` | **present** — the patch was already compiled in |

So `JTS-TAILCALL` is **not** my finding; a session on **2026-09-12** landed it, together
with the parent+self spans and the dispatch guard as a config hook. Both docs already
say so: `PROGRAM_GUIDE.md` §5 ("a session-78 tool patch that makes out-of-span
switch-case labels emit tail calls"; "**0 broken stubs** (was 1719)") and the
`HANDOFF_NEXT_AGENT.md` session ledger row for session 78.

**There is also a session-numbering collision.** The ledger's "session 78" is dated
09-12 and is the stub fix. The filename `HANDOFF_SESSION78.md` was, until this
rewrite, a *different*, later "session 78" written 09-20. Do not read the two as the
same session.

**The lesson is the one already in `PROGRAM_GUIDE.md` §11 rule 3 / rule 13:** census
the tree before claiming a defect is open. I asserted a `file:line` root cause from
reasoning alone and never re-ran the stub census against the live tree before writing
it down. Re-derive from `git log` + the censuses, never from a summary.

## 2. REAL FINDING — the recompiler cannot currently be rebuilt

`ninja XenonRecomp` in `.research/XenonRecomp/build-clang` **fails**:

```
yvals_core.h(917): error: static assertion failed:
  STL1000: Unexpected compiler version, expected Clang 20 or newer.
```

Cause: the MSVC STL was upgraded to **14.51.36231** (VS `18/BuildTools`, now the only
installed toolset) while LLVM is still **clang 19**. The stale PCH that had been
masking this (baked under `msvc19.44.35228`) was deleted during diagnosis, so
regenerating it now hits the gate.

**This does not affect the game build.** `build/mcla.exe` linked at 16:41 today and the
main build uses no PCH. It blocks *only* future recompiler-tool changes (Route B in
`PLAN_VMX128.md` §4 — the 94 type-5 `vupkd3d128` unpack sites, if the boot ever reaches
`0x822Fxxxx`).

Remedies, cheapest first: (1) install LLVM/Clang ≥ 20 and reconfigure; (2) reconfigure
`build-clang` for MSVC `cl.exe` instead of `clang-cl`; (3) install an older 14.44.x
toolset side-by-side and pin `-T`.

**Do not delete any more PCH artifacts** — the working `XenonRecomp.exe` predates the
VS upgrade and is currently the only build that contains the landed patch. It was not
overwritten (the compile failed before linking), so the tool on disk is still correct.

## 3. REAL, SMALL WIN — the tool patch is now preserved in a tracked file

`PROGRAM_GUIDE.md` §5 and `PLAN_VMX128.md` §6 R2 both warn that `.research/` and
`generated/` are gitignored, so **any tool patch must be committed as a `.patch` file
or it is lost on the next clone**. No such file existed. Now:

- **`tools/xenonrecomp_local.patch`** — source-only diff of the vendored tool
  (`git -C .research/XenonRecomp diff -- XenonRecomp/ XenonUtils/ XenonAnalyse/`,
  141 insertions / 2 deletions in `recompiler.cpp`; contains `JTS-TAILCALL`). Build
  artifacts deliberately excluded.

Regenerate it after any future tool edit; do not hand-write it.

Also fixed by the same edit: `XenonRecomp/recompiler.cpp` in the working copy had
drifted *out* of sync with its own compiled binary — the source lacked the
`JTS-TAILCALL` block that the shipped exe contains. It now carries it again, so source
and exe agree. This is why reading the source alone would have made the patch look
"missing"; it was only missing from the source.

## 4. THE LEAD — an undocumented VEH short-circuit machine is probably *causing* the park

Found while checking the two open signals. Verify independently before acting; every
claim below is file:line or grep-citable.

### 4.1 The park is one fault site, hit 703 times

`build/smoke_long2.log` (09-20 16:49, 9560 lines) has **703** `VEH boot-worker AV`
lines and **all 703 report the same guest lr**:

```
grep -oE 'VEH boot-worker AV #[0-9]+ in lr=[0-9A-Fa-f]+' build/smoke_long2.log |
  grep -oE 'lr=[0-9A-Fa-f]+$' | sort | uniq -c | sort -rn
      703 lr=822FBC28
```

One deterministic site, not a scatter — so this is a loop being recovered on every
iteration, not incidental noise.

### 4.2 What the recovery actually does (`src/boot_host.cpp:1010-1039`)

Per distinct guest `lr`, tracked in `s_faultCounts`:

| Fault # | Action |
|---|---|
| 1 | `ContextRecord->Rip += 16` (`:1016`) |
| 2 | `ContextRecord->Rip += 64` (`:1020`) |
| 3+ | read `[Rsp]`, set `Rip = *Rsp`, `Rsp += 8`, **`Rax = 0`** (`:1026-1033`) — i.e. **fabricate a function return whose result register is zero** |
| 3+, if that slot reads 0 | `Rip += 4096` (`:1036`) |

Adding 16 / 64 / 4096 to a **host** RIP does not skip a guest instruction — it lands
mid-function in compiled x64 whose layout the recompiler never intended to re-enter.
And faking a return with `r3 = 0` hands the caller a null/failure value the guest would
never have produced.

Immediately adjacent, same handler, same cluster — `boot_host.cpp:975-1002`:

- if `lr == 0x822F44E0`: write **`0xC3` (RET) over the host entry of `sub_822FA958`**
  at runtime (`:982-990`), i.e. void the recompiled guest function in place;
- if `s_inUILoad`: **"Nuclear advance: 256MB"** — `Rip += 256 MB` "to skip entire
  caller chain" (`:999-1002`);
- otherwise: `for(;;) Sleep(1000)` — park the boot worker forever (`:1005-1007`).

### 4.3 Why this is probably the real blocker

The symptom on record is "guest stuck at loading screen, CP frozen, `rptr` never
advances" (newest soak: `put=11` but `rptrWB=0000`). If the thread that would advance
the CP is repeatedly taking an AV and being handed a **fabricated return with `r3=0`**,
then it never performs the submission — and the "guest logic is stuck" framing is an
artifact of our own recovery path.

That matters for the queue: `LONG_TODO_MASTER.md` **T37.3** forks on
*(a) UI/GFx progressing / (b) GPU-starved / (c) new crash family*. **That fork may be
false** — all three readings are downstream of a handler that rewrites control flow
whenever the guest misbehaves. Fixing or measuring around it comes first.

### 4.4 Rule violations to raise with the user

- **Not in the §7 short-circuit table.** `PROGRAM_GUIDE.md` §7 lists 14 known
  short-circuits; none is this VEH path. It is acknowledged only as "VEH recovery" in
  commit `b6528ad`. §12's own anti-cheat question — *"did any change make the guest do
  something the PPC binary doesn't say?"* — is answered **yes**, unambiguously.
- **`PLAN_VMX128.md` R5** forbids exactly this: *"do not 'fix' a trap by skipping the
  instruction … it looks like progress."*
- **`LONG_TODO_MASTER.md` rule 1 / do-not 9**: census before fix, no stacked
  short-circuits without root cause.

### 4.5 The honest next experiment

**Neutralize the recovery and re-soak** — make the handler report and *not* continue
(let it crash cleanly, or park without faking state), then boot into a NEW log
(`w37a`, per rule 5). Either outcome is decisive:

- boot **advances** → the 703 fake-returns were the park; the guest was fine;
- boot **crashes earlier** → the crash is the true first divergence, with a real
  `lr`/`r3`/address instead of `RAX=0` fiction.

Downside is honest and must be stated: **this can make the boot look worse** (an
earlier clean fatal instead of a live-but-zombie process). That is why it needs a
decision, not a silent edit. Rule 7 is satisfied either way — no build breakage, one
handler's behaviour.

### 4.6 Likely connection to the open VMX128 work

`0x822FBC28` and `0x822F44E0`/`sub_822FA958` sit in the **`0x822Fxxxx` cluster**, which
`PLAN_VMX128.md` §3 identifies as the home of the **94 unimplemented
`vupkd3d128` UIMM=20 (type-5 FLOAT16_4) unpack sites**. The tree still emits
**101 `__builtin_debugtrap()`** calls
(`grep -hc __builtin_debugtrap generated/ppc_xenon/ppc_recomp.*.cpp` summed). So the
most coherent story is: boot has now *reached* the type-5 cluster, and instead of a
clean trap we get an AV that our own handler launders into 703 silent fake returns.

If that holds, **the `LONG_TODO_MASTER` "Route A is enough" position ends here**: the
plan itself says 94 sites "would not be maintainable → that is **Route B** territory"
(`PLAN_VMX128.md` §4), and **Route B needs the recompiler rebuild that §2 above says is
currently broken.** So the toolchain fix is likely on the critical path, not optional
tooling hygiene.

Note `loc_822FBC28` is *not* a label in `generated/` and no `PPC_FUNC(sub_822F….
)` exists — `lr` is a **return address**, so the faulting callee is invoked from
~`0x822FBC24`. Per `PROGRAM_GUIDE.md` §8 Misc, LR attribution is only void after
memset/leaf calls; this is a real return address, but pin the owner with xrefs + arg
registers rather than assuming.

