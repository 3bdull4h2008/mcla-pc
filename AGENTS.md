# MCLA PC — agent rules (auto-loaded; keep this file short — it costs tokens every session)

Xbox 360 (Xenon) → PC emulator: XenonRecomp static PPC→C++ recompiler + D3D12 backend, guest
`default.xex` (Midnight Club LA prototype). Goal: boot → menu → playable. Not a general game project:
**the guest binary is data, the raw bytes are the source of truth, the docs only about _intent_.** Any
doc sentence asserting a guest fact — address, layout, count, "never fires" — is a hypothesis until
re-measured. Cite the measurement, not the doc (F-458, F-463, F-446).

## ⛔ RULE 0 — NO GUESSING. MEASURE OR DECOMPILE. (added 2026-09-30; its own record re-audited 2026-10-01)

**Every statement about the guest binary, or about a log, is a hypothesis until a tool prints it.**
Reasoning about what the game "must want" is banned.

**On 09-30 the orchestrator asserted 11 things and agents killed them. The tiers matter more than the
anecdotes — a constitution citing a measurement that does not exist teaches readers citations are optional.**

- **LEDGERED — the heading is the only clearance.** A deleted exception that never existed (F-639:
  "REFUTES the widely-repeated claim … cite this heading instead"); "1,267 skipped constructors" is
  **withdrawn** (F-686) though 1,267 is a real count and the guest enters all of them (F-638); the
  brief's `101,600` allocation failures — cumulative `oom=` is **101,700**, and 1,025 is the
  *printed-row* count (F-651); "3 of 4 phantom markers" — `CP: RING A DRAIN` lives in the census skill,
  `CP-REG-TN` is the one genuine phantom (F-651).
- **LEDGERED, GLOSS NOT.** The `DISCCHK` 779→41 collapse is real; F-650 attributes it to the read-mode
  predicate `(w3&3)==2`. The "*log-print filter*" reading is **not** in F-650 — UNVERIFIED.
- **RECORDED OUTSIDE THE LEDGER — name the file, it is not an F-ID.** 299.5 MB vs 354 MB:
  `src/kernel/heap.cpp:950-951` ("299.5 MiB … `n=3 req=354.0MB`"). The 437 "real register writes" that
  were pure zeros: `docs/PROGRAM_GUIDE.md:727` — which credits the kill to "F-637", and F-637 is the
  *compaction census* (`ROOT_CAUSE_VALIDATION.md:14085`), not a kill record.
- **NO RECORD — do not quote as kills.** "a fix resting on n=3", "'six shaders' (57)", "'517 shaders
  compile'": **zero** ledger mentions each. What survives the third is not the anecdote but PROGRAM_GUIDE
  §9's `PC-TRANSLATE` rule — "an offline validator result is not a boot fact" (its ok-arm hardcodes `failed=0`).
- **WITHDRAWN AS INCORRECT — two of RULE 0's own glosses, kept so nobody re-imports them.**
  (a) The `0xC0000000` "placeholder payload that is really `0xC0006200` = `PM4_SET_BIN_SELECT_LO`":
  **no ledger entry contains `0xC0006200` or `BIN_SELECT`**, and F-653 records `v9[1] = 0xC0000000` —
  "Meaning unknown. Recorded, not interpreted." The reinterpretation is dead.
  (b) `walked == 2*t0` as "the signature of an empty buffer" is repudiated verbatim by **F-685**: "NOT
  'the signature of an empty buffer' … It holds 8/8, including on a 1,038,134-dword (4 MB) window, so it
  is a **TYPE degeneracy, not a size one**." A zero dword scores TYPE-0 because `hdr>>30==0`, so
  `walked == 2*t0` is what an all-zero buffer *must* produce. Load-bearing evidence is the raw
  `CP: INDIRECT_BUFFER` dump: 16 zero dwords where `PKT-CAP` read real bytes `0x20000000` lower — a
  *pointer-base* disagreement.

**The authority for a guest fact is `build/cache/mcla_pe.bin` (offset = VA − `0x82000000`), then IDA
decompilation. Never inference. Never a doc. Never a remembered number from an earlier session.**
Decompiler output is still a model. **Any mask claim is invalid until the raw word is read** — that part
was always right and it is the whole lesson. **But F-647's gloss is INVERTED and must not be followed.**

> **F-647 as previously recorded was WRONG, and acting on it corrupts the build.** It claimed "all three
> decompilers render PPC rotate-immediate masks backwards", citing raw `55 6A 00 42` = MB=1, ME=1 =
> "bit 1". **MB=1, ME=1 gives bit 30 → `0x40000000`** — which is exactly what the ISA gives, what
> `ComputeMask` (`recompiler.cpp:5-11`, called as `:1546`) gives, and what IDA *and*
> `generated/ppc_xenon/ppc_recomp.17.cpp` print. **The emitters were right; the record's gloss numbered
> MB from the LSB.** "bit 1" is MB=30, ME=30 — **never (1,1)**.
>
> **Settled 2026-10-05 by three independent implementations against the Xenia oracle: ISA 28/31,
> `ComputeMask` 28/31 — identical 28, identical 3 (all `MB>ME` wrap cases a 32-bit harness cannot
> model).** Both historically disputed words now agree: `MB=1,ME=1 → 0x40000000`;
> `MB=24,ME=31 → 0x000000FF` (`clrlwi` = *clear left*, retaining the low `32−n` bits).
> **The correct record is F-765, not F-647.** Populations reproduce exactly: 72,297 rotate-immediate
> words, 16,709 with MB=24/ME=31, 16,708 `& 0xFF;` sites, **0 non-rotate** — 100% rotate-family.
>
> ⚠️ **"Fixing" `generated/**` to `0xFF000000` inverts 16,709 sites across 176 translation units and
> makes the boot strictly worse.** Do not. `generated/**` is forbidden anyway (rule 2).

**Field notes, all measured, so you do not rediscover them the hard way:**
- ⚠️ **CORRECTED 2026-10-22 (F-857): `ori`'s destination is `b20:16`, NOT `b25:21`.** This note was wrong
  twice — first it said the opposite, then a "correction" made it wrong again. The LLVM citation it
  leaned on (`class DForm_base`, `let Inst{6...10} = RST; let Inst{11...15} = RA;`) **cannot** settle
  it, because the *field slots* are identical and only the *naming* differs between the two families.
  **MEASURED, three independent ways:**
  (a) **The guest's own `lis`+`ori` idiom.** `lis r9,0x0004` (`3D200004`) then `ori r30,r9,0xAE00`
  (`613EAE00`) must build ONE constant `0x4AE00 = 306,688` in r30 — and `306,688 << 10 = 0x12B80000`
  is exactly the size the boot asks the physical pool for. Under `b25:21` the instruction would instead
  clobber the `lis` result and OR in an unrelated register, i.e. the idiom would be meaningless.
  (b) **The tiebreaker.** `generated/ppc_xenon/ppc_recomp.0.cpp:3143-3144` decodes the SAME word
  `0x613EAE00` as `ori r30,r9,44544` and emits `r30.u64 = ctx.r9.u64 | 44544;` — destination r30 at
  `b20:16`, source r9 at `b25:21`. **`generated/**` is right; do not touch it.**
  (c) **Two re-encode controls, byte-for-byte:** `ori r8,r9,0x6772` → `0x61286772` and
  `ori r9,r8,0x6772` → `0x61096772`. (The earlier note had these two byte values with the MNEMONICS
  SWAPPED — the byte values were real, the assignment to mnemonics was not.)
  The arithmetic controls in the old note (`addi r4,r1,80`=`38810050`, `li r5,256`=`38A00100`,
  `lwz r7,80(r1)`=`80E10050`, `lis r9,0x6178`=`3D206178`) still stand, and they are the OTHER family.
- **The asymmetry is the trap, and it is what produced an hour of wasted work.** The TRUE split is by
  FORM, not by "logical vs arithmetic": the **D-form arithmetic and load/store family**
  (`addi`/`addis`/`addic`/`mulli`/`subfic`/`lwz`/`stw`/`stwu`) keeps the **destination at `b25:21`**,
  while **everything else** puts the destination at **`b20:16`** — the D-form logical-immediate family
  (`ori`/`oris`/`xori`/`xoris`), the X-form logical family (`or`/`and`/`xor`/`mr`/`cmp`; `0x7FC8F378` =
  `or r8,r30,r30`, destination r8 at `b20:16`), and the X-form arithmetic family (`add`/`subf`, whose
  destination is the third field at `b15:11`). Both conventions are right — **for different opcodes.**
  Never generalise one from the other. **Extract nibble by nibble; shift-and-mask arithmetic has
  produced four wrong answers in this project.** ⚠️ `tools/ppc_disasm.py` had this same defect for the
  WHOLE `ori`/`oris`/`xori`/`xoris` family (one `d`/`a` pair computed and reused for both families, so
  every one of them printed its two registers swapped). **Fixed in F-857** with three new
  `--selftest` controls (28/28 now pass; it was 25/25). Re-read this note before trusting any
  `ori`/`xori` disassembly, and re-run `--selftest` after touching that tool.
- ✅ **REFUTED 2026-10-22 (F-857): `generated/ppc_xenon/` does NOT mis-emit `ori` immediate-form.**
  The old note here claimed a "real defect in generated code" at two sites (`0x8218C848` →
  `ppc_recomp.9.cpp:18434-18435`; `0x8213DC98` → `ppc_recomp.1.cpp:16207-16208`) and told you to route
  it through `.qoder/skills/mcla-recompiler-regen`. **That "proof" was made with
  `tools/ppc_disasm.py`, which had the whole `ori`/`oris`/`xori`/`xoris` family swapped (see the note
  above) — so the tool and the generated code were compared in the WRONG direction.** MEASURED at both
  cited sites, byte-for-byte, against the raw guest words:
  * `0x8218C848` = `0x61286772`; the generated code says `// ori r8,r9,26482` and emits
    `ctx.r8.u64 = ctx.r9.u64 | 26482;` — destination r8 at `b20:16`, source r9 at `b25:21`. CORRECT.
  * `0x8213DC98` = `0x612860B7`; the generated code says `// ori r8,r9,24759` and emits
    `ctx.r8.u64 = ctx.r9.u64 | 24759;`. CORRECT.
  * The fixed `tools/ppc_disasm.py` now prints `ori r8,r9,6772` and `ori r8,r9,60B7` for those two
    words — the same registers and the same immediates as the generated code.
  **There is nothing to regen.** Do not touch `generated/**` for `ori`; its 6,447 `ori` emissions are
  consistent. If the old reading is wanted back, fix `tools/ppc_disasm.py`, not the recompiler.
- **`ori rA,r0,imm` round-trips as a no-op store to `r0` in Capstone 5.0.7** — a real defect in its
  or-immediate arm. Do not use it to settle operand order.
- ⚠️ **`op18` (I-form branch) IS resolvable; a circulated "bits 2..27" encoding is REFUTED — do not
  re-import it.** PPC bit numbers run from the MSB (bit *k* = `1<<(31-k)`): **LI = bits 6..29** =
  `& 0x03FFFFFC`, sign-extended from 26 bits, already ×4; **AA = bit 30**; **LK = bit 31**; target =
  `VA + sext(LI)`, else `sext(LI)` when AA=1. Over all 147,363 op18 words that gives **144,170
  in-image targets, 123,273 on a function in `ppc_func_mapping.cpp`, and 143,827/143,827 = 100% of
  code-range words**; the 2,910 residual are all outside the code range and are ASCII/data, not
  branches (`49440000`=`"ID"`, `4B45524E`=`"KERN"`). Bits 2..27 is *structurally* impossible, not
  merely unfit: bits 0..5 **are** the primary opcode, so bit 1 is set in **147,363 of 147,363** words
  and bit 0 in **0** — that reading would make every op18 branch absolute *and* non-linking, when
  really LK(bit 31) is set in **107,153** words and AA(bit 30) in **1,469** (`ppc_xrefs.py`'s own
  docstring agrees). Control: **13,548** `bl` sites whose target the recompiler itself already
  resolved (26 TUs of `generated/ppc_xenon/ppc_recomp.*.cpp`) — signed bits 6..29
  **13,548/13,548**; bits 2..27, bits 2..25 and bits 6..31-unsigned **0** each. Both oracles
  (`tools/ppc_disasm.py`, Capstone 5.0.7) print the textbook target at all six hand-checked sites,
  e.g. `0x8218C83C` raw `48031ED5` → `0x821BE710` (bits 2..27 → `0x84198FF0`). **`ppc_disasm.py` does
  NOT read op18 "unsigned-and-outside"** — the bullet this replaces was wrong about the tool as well
  as the encoding; its real defects are two bullets below.
- **`tools/ppc_xrefs.py calls` USED to under-report, and the note about it was itself wrong.** The
  previous text here said it "reported 20 callers of `0x821BE250` where a raw scan finds **0** direct
  call sites (vtable dispatch)". **Both numbers were false.** Measured 2026-10-06 against
  `build/cache/mcla_pe.bin`: a raw whole-image op-18 scan finds **80** direct `bl` sites to
  `0x821BE250` (0 tail `b`), and the tool listed **61** of them with **zero false positives** — the
  defect was a silent output cap (`if n > 60: break` at `:299-300`, then `{n} call site(s)` at `:301`),
  so the number it printed was the *listing cap*, not the count. The 19 it dropped were the highest
  addresses, i.e. exactly the callers you are most likely looking for. **Fixed** (F-775): it now scans
  everything, lists at most 60, and prints `80 call site(s) -- only the first 60 listed above; 20 more
  exist`, which reproduces the raw scan exactly. Scale of what the cap was hiding: `0x823DA950` (the
  guest memcpy) has **597** call sites, not 61. Its `->` column does name the *enclosing* function
  (`sub_8218B0C8 +0x1f4` = an offset into it), and it still cannot see the **15,392** register-indirect
  `bctrl`/`bctr` sites (op 19), which have no static target (`:284-286`).
- 🔴 **`tools/ppc_disasm.py` does NOT invert `mr` — that claim (F-112) was re-measured FALSE on
  2026-10-06 and acting on it would have broken a correct decoder.** `decode(0x7C9D2378)` →
  `mr r29,r4` ✓; `decode(0x7FC8F378)` → `mr r8,r30` ✓ (rS==rB, so the alias is right — AGENTS.md's
  own control `0x7FC8F378 = or r8,r30,r30` is the *same instruction* in long form);
  `decode(0x7C8B5214)` → `add r4,r11,r10` ✓ matching Capstone. Both operand conventions in this file
  are honoured correctly: X-form logical (`or`/`mr`, XO 444) prints `r(a),r(d),r(b)` because the
  destination is the bits-11:15 field, while X-form arithmetic (`add`, XO 266) prints
  `r(d),r(a),r(b)` because there the destination is bits-6:10. **Do not "fix" either arm.**
- **`tools/ppc_disasm.py` still cannot decode opcode-30** (`rldicl`/`rldicr`) — and that gap is
  bigger than the old note implied: **5,884** op-30 words in `mcla_pe.bin` (of 2,588,672 dwords;
  for scale, op-31 = 271,675, op-18 = 147,363, op-16 = 146,177, op-21 = 64,033). It also bails on
  op-4 (`float/ps`), op-19 unknown XOs, `op31:<XO>` and `op58sub`/`op62sub`. **Fixed (F-776):** every
  fallback now appends `NOT-DECODED(use generated/ppc_xenon/*.cpp)`, so an undecoded word can no
  longer pass for an answer — previously `rldic-family 78A30004` looked like output and carried zero
  operands. Control: `--selftest` is still 25/25 after the change. Use `generated/ppc_xenon/*.cpp`
  as the tiebreaker for those opcodes.
- **Do not trust operand ordering in `generated/ppc_recomp.*.cpp` comments** — four sources disagreed
  and the emitted code was the tiebreaker, not the comment.
- **A control with `MB=0` is symmetric under the MB↔ME swap and therefore has *some* power but not
  none** — measured: it discriminates five candidate wrong-models; only `ME=0` and `ME=31` are blind.
  A widely-circulated claim that it is *powerless* was itself false. **Establish the discriminating
  power of any control you rely on.**

**How to stop guessing — use these, not your memory:**
| need | tool |
|---|---|
| decompile guest functions | `python tools/ida_dump.py <dir> 0x821378B8 0x…` (bridge on :8745) |
| whole image as files, with raw bytes | `python tools/ida_bulk_export.py <dir>` |
| raw instruction truth | `tools/ppc_disasm.py` (offset = VA − `0x82000000`; **prints mnemonics** — F-633 added them, so the old "prints raw fields, not mnemonics" note was stale — plus raw fields and the rotate mask. Undecodable opcodes now say `NOT-DECODED`, F-776. Run `--selftest` after touching it.) |
| xrefs (use `calls`/`fn`, **not** `xref`) | `python tools/ppc_xrefs.py calls 0x824112C8` |
| who owns a guest address | `python tools/addr_owners.py --check 0x…` — hex **or** `sub_<VA>` both work |
| exact log counts | `open(f,'rb').read().lower().count(b'…')` — **not** `findstr` alone |

**Traps that have each produced a false reading:** `CALLERS (none)` is an IDA carving artifact, not
evidence. A marker absent from `src/` has a zero that means nothing — **prove the literal exists before
interpreting its count**. An offline validator result is **not** a boot fact (one `submitted=1` on
`PC-TRANSLATE` is the whole shader frontier and is **not** evidence a shader compiles).
`shlex(posix=False)` splits `/I"E:\mcla pc\src"` and invents 35 errors. `-c` is a substring of `-clang:-std=c++23`.

**When you must state something you have not measured, label it a prediction and say what would
falsify it.** Never state it as a fact. Per rule 14 a brief is not authority — and as of 09-30 that
includes this orchestrator's briefs.

## Read in this order (never skip step 1)

1. `docs/LONG_TODO_MASTER.md` — §0 dated state, §1 rules, §2 task queue, §4 do-not list.
2. `docs/HANDOFF_NEXT_AGENT.md` — live block + session ledger (what the last session actually saw).
3. `docs/PROGRAM_GUIDE.md` on demand — §3 build/run gotchas, §4 guest image, §5 recompiler pipeline, §7 host short-circuit table, §9 log-marker inventory, §10 RE tooling, §11 forbidden paths.
4. `docs/ROOT_CAUSE_VALIDATION.md` Part 3 — the append-only evidence ledger. **Never trust an ID range quoted anywhere, including here**: the top moves hourly (last heading `### F-773`, **625** headings, measured 2026-10-06). 🔴 **The file contains 1 NUL byte, so plain `grep` treats it as binary and silently returns 74 of 625 headings plus "Binary file matches"** — an agent this session read `F-543` as the ledger top from exactly that. **Always `grep -a`.** Two commands that never rot: next free ID = `grep -aoE "^### F-[0-9]+" docs/ROOT_CAUSE_VALIDATION.md | tail -1`; a duplicate check = `grep -ain "<address or marker>" docs/ROOT_CAUSE_VALIDATION.md`. Note a **backtick breaks a grep pattern**: searching `agents.md rule 12` returns 0 while the file holds `` `agents.md` rule 12 `` at `:8581`. **F-056…F-076 is a documented hole** (`:2098`; that week survives only as unnumbered prose at `:1071-1166`), so **F-057/F-058 resolve to nothing** and a grep that finds nothing does *not* prove a citation was fabricated. **F-412…F-429 were never allocated** (F-773). **F-629 has no `###` heading** (17 textual mentions, all references to the void); it was reconstructed as **F-635** — do not renumber or reuse it.

Older status text anywhere else = trail, not truth. Pre-compression doc text: `git show 8f07a39:docs/<file>`.

**Before asserting anything about the tree, re-census it** (`grep`, `ls -l`, `git log`). Three claims in one handoff were false purely because they were remembered from a compaction summary, not re-measured. That is rule 13 in practice: **cite a tool-printed log line or a `file:line`; a commit hash alone marks the claim UNVERIFIED until a soak reproduces it.**

## The 7 rules that keep costing sessions

**Rule numbers are namespaced — never expand a bare "rule N" without naming the file.** This file:
1–6, 14, 19. `LONG_TODO_MASTER` §1 ("Rules", `:552-573`, rules 1–19 — what a bare "rule 11/13" means):
5 = one new log per experiment (`:558`), 6 = timeout every boot + kill `mcla.exe`, 7 = tree must always
compile, 8 = retail content only, 9 = no framework rewrites while not booting, **10 = write the trail as
you go**, 11 = two-session coordination (`:564`), **12 = the stale-exe trap** (`:565`), **19 = a zero from
an instrument is not a result until that instrument is shown firing on a known event** (`:572`).
`PROGRAM_GUIDE` §11 ("Rules that govern all work", `:796-830`, rules 1–11) — **6/7/8/9/10 collide with
`LONG_TODO_MASTER` §1**, its 5 = do-not-stack-short-circuits (`:808`). So **"rule 5" is triple-valued**
(this file's concurrency rule, `LONG_TODO_MASTER.md:558`, `PROGRAM_GUIDE.md:808`) — write the file.
⚠️ **Prefer the section name to the line range: anchors in this project rot faster than the prose**
(F-764 measured the scale). The five line numbers in this paragraph were all wrong before 2026-10-06 and
are re-measured as of it — expect them to drift again, and re-run `grep -n "^## " <file>` rather than
trusting any range, including these. One live miscite proves the cost: `ROOT_CAUSE_VALIDATION.md:8581`
says "`agents.md` rule 12" — **this file has no rule 12**, its list is 1–6, 14, 19; that rule is
`LONG_TODO_MASTER` §1's stale-exe trap. (A second miscite once cited here, `HANDOFF_NEXT_AGENT.md:528`
"AGENTS.md rule 5/6", is **gone**: 0 hits in the live HANDOFF, 0 in `docs/archive/trail-handoff-2026-10.md`,
0 in `HEAD`'s blob. It was corrected, and this sentence is the only trace.)

1. **Census before fix.** No short-circuit without a root cause; never stack short-circuits (do-not #1/#9). A mitigation must be labelled and cited at its `file:line`.
   **1a (bisect attribution).** A `src/` change may not be named as a fault's cause unless the only build differing from the last known-good is that change, or a single-variable revert is shown; otherwise write "N-way" and name the other files still in the build. **A citation is not attribution.** *Check:* `git diff --name-only <last-good>..HEAD` ∩ `src/` = 1 file.
   **1b (new-symbol taint).** Any new `static`/`extern` host function or global in the working tree must be listed in the same claim; attribution stays provisional until a revert excludes or confirms it. *Check:* `git diff <last-good>..HEAD -- src/ | grep -E '^\+.*\b(static|extern)\b'`.
2. **Never edit `generated/**`, `.research/**`, `config/mcla_xenonrecomp.toml`, `src/ppc_context.h`, `src/ppc_config.h`, `src/dispatch_guard.cpp`** — full forbidden + default-modifiable lists: PROGRAM_GUIDE §11 rule 7 (`:813-817`). Tool changes go through `.qoder/skills/mcla-recompiler-regen`.
3. **Raw-byte rule (F-023).** `build/cache/mcla_pe.bin`, offset = VA − 0x82000000, words big-endian; the PE section table lies; IDA is a hypothesis until the bytes agree.
4. **One owner per guest address.** `python tools/addr_owners.py --check <addr\|symbol>` before adding any hook (it reads `PPC_FUNC`/`GUEST_FUNCTION_HOOK`/`SetFunction`/`GetFunction`; **exit 1 = duplicate owners**, 2 = unresolvable symbol). grep is the fallback, not the check.
5. **Concurrent sessions are normal.** Before building/booting: `tasklist | grep -iE "mcla|ninja"` and the newest `build/*.log` >2 min old (= `LONG_TODO_MASTER` §1 **rule 11**). Before writing a doc: check its mtime and add a dated superseding block rather than editing someone else's.
6. **E: is primary again (merged 2026-09-23; pre-merge state = commit `35912f0`).** `C:\mcla-pc` is a retired **read-only** archive; provenance snapshot `E:\mcla-c-snapshot-20260923`. Verified then: the merged tree **built clean on E: (`build_on_e.bat`, 11/11, 0 errors) and `w46.log` reproduced `w45b`**. Do not start building on C: again; `diff -q` against the snapshot before trusting either side.
14. **Premises must be cited.** Every factual assertion in a task brief or a finding carries a `file:line` or a log line. No citation means verify before acting, not after. A brief is not authority; a measurement is. Briefing from this project's own records is a defect, not a shortcut.
19. **A zero is not a result until the instrument is shown firing on an event you know happened** (`LONG_TODO_MASTER` §1 rule 19, `:572`; F-100 voids F-095). Six harnesses in this project reported *pass* while blind — they never failed on anything. Before believing any 0: make it fail once on a known-positive fixture and show the line. Corollaries that each cost a session: **a marker absent from `src/` has a zero that means nothing** (prove the printer literal exists first — `tools/soak_census.py` prints `MARKER NOT IN SRC` for this); **a capped printer's count is a cadence, not a total** (`UIXSF-GOLDEN-REVERIFY` fires only at n∈[1000,9000] ∧ n%1000==0, so "25 rows" says nothing about how many verified); **and a second printer can emit your token** — naive `pct=100` counts 65 in `w737` where `UIXSF-GOLDEN-REVERIFY` accounts for 30 and `PHYS-FREE-SUM`'s `honoured_pct=100.0000` for 35 (F-772). **Count a marker only on lines where it follows the `] [` level tag, i.e. where it is the message's own label.**

## Project skills (`.qoder/skills/`) — use them, don't rediscover the gotchas

| Skill | When |
|---|---|
| `mcla-boot-cycle` | any src change to compile+boot (MSYS guards, kill-before-build, stale-exe trap, new log per run) |
| `mcla-guest-raw-decode` | attributing a fault `lr`, naming a vtable slot, checking an IDA address (`lis` sign-extension trap) |
| `mcla-log-census` | reading/comparing soaks or claiming a gate (case-insensitive counts vs named baseline) |
| `mcla-finding-ledger` | writing any conclusion down |
| `mcla-recompiler-regen` | VMX128 ops, stubs, jump tables, `midasm_hook` work |

## Project tools (`tools/*.py`) — the executable form of those skills, run them instead of re-deriving

| Tool | When | Exit code |
|---|---|---|
| `tools/soak_census.py <new.log> <baseline.log>` | reading or comparing any soak. Every tracked marker counted as matching **lines**, case-insensitive (= `grep -ic`); fault-line vs all-line `lr=` split; a **CP truth** line (`drains`/`last_rptr`/`pub` vs `put` — the only honest pipeline signal; a waiter's `rptrWB=` is not, F-057(1)/F-058, both in the ledger hole); and **LOG QUALITY**, which WITHHELDS the whole marker table when one mitigation shape owns a log (F-054: `w38e.log`, 616,824 firings = 33% of 1,860,449 lines, `soak_census.py:65-66`). Prints **MARKER NOT IN SRC** for any tracked marker whose literal is in neither `src/` nor `generated/` — its zero means nothing (F-057(6)). Reconcile a hand count with it before claiming it. | 0 |
| `tools/addr_owners.py` | rule 4, before adding **any** hook — guest address → `file:line` → hook name, plus which sites actually *claim* it. `--check <addr\|symbol>` for one site; `--gates <addr>` prints each claim's enclosing-function conditions **verbatim, uninterpreted**, so a conflict is resolved by reading the soak for the *installer's* own log line, never by guessing which registration wins (F-053). **`--check` takes hex OR `sub_<VA>`: the three-tier resolver documented at `tools/addr_owners.py:53-76` tries `hex`, `sub_`, then the generated table, prints which tier answered, and exits 2 rather than 0 when it cannot resolve. Measured 2026-10-01: `--check sub_821CA540` = 2 sites, exit 0 — the old "symbol form is broken, use hex" warning described a real bug that is now fixed; its history is the tool's own docstring at `:72-75`.** | **1 = duplicate owners**; 2 = unresolvable |
| `tools/mitigation_audit.py` | do-not #9 — diffs the PROGRAM_GUIDE §7 registry against the mitigation-shaped labels really in `src/`. Re-measured **2026-10-01**: **§7 = 92 registered, 4 stale; `src/` = 105 mitigation-shaped of 1,330 label tokens; 86 undocumented** (the old "13" was the F-047 reading). `--tiers`, `--label X`. | **1 = unregistered/stale** |
| `tools/ppc_xrefs.py` | static xrefs without IDA: `find-str <text>`, `xref <hexVA>` (`lis`=`addis rT,0,imm`! sliding per-register state), `calls`, `fn`. One-site messages are load-bearing attributions (F-102 named the whole preload chain this way). | 0 |
| `tools/rpf_offline.py` | archive forensics without a soak: `header` (RPF3 TOC length/endianness), `names <toc_dump>`, `find <path> [archive\|dump]`, `member <off> <len>`, `islands`. Raw-archive `find` returns 0 **by design** — the on-disk TOC is AES, the in-guest copy is a hash-sorted cleartext table (F-099). | 0 |
| `tools/host_rva_resolve.py build/mcla.map [--base <runtime image base>] <rva\|absolute>…` | names a **host** address from the VEH/PARK dumps (`rip owner=host …`, `rawrip=…`, the host stack lines) using the `/MAP` every link already writes (`CMakeLists.txt:577`; the old `§410` pointed at the `ppc_recomp.82..85` list) — this turned F-370's `C0000005` from "some host thread" into `memset ← GuestThreadContext ctor`, and on 2026-10-06 named the writer of **both** zeroed o1heap instances from `F374-HEAPSTORE`'s `caller_rva` — 16 distinct sites `+0x2df … +0x699` inside `__imp__sub_823DA950`, an identical set for the user instance (`0x20000`) and the physical one (`0xA0400000`); see **F-778**, which also resolves a full 20-frame `F379-HEAPSTORE-BT` chain that reaches `sub_8218B0C8`. Control: a known symbol must resolve at `+0x0`, using the map from the SAME build as the log. ⚠️ **If you verify this tool by hand, read the map's THIRD column (`Rva+Base`), not the first, and subtract with a computer.** The publics table is `Address(section:offset) | Publics by Value | Rva+Base | Lib:Object`; the first column is section-relative, so a hand parse of it lands exactly **0x1000** off and will make a *correct* resolution look wrong (this happened, and nearly discarded a true result). Worked example, measured not remembered: `__imp__sub_823DA950` is sec:off **`0001:016ff230`**, `Rva+Base` **`0x141700230`** ⇒ RVA **`0x1700230`**, next symbol at `0x1701160`, extent **`0xF30`**. An earlier revision of this line gave `016ff170`/`0x1700170` — **both wrong**, produced by hand-computing `0x170050f − 0x2df`; the true answer is `0x1700230`, and **`sec:off 0001:016ff170` does not exist in the map at all** (RVA `0x1700170` is inside `__imp__sub_823DA748`, base RVA `0x16ffbc0`, at `+0x5b0`). A wrong base silently re-attributes every offset computed from it, so `python -c "print(hex(0x170050f-0x2df))"`, never mental arithmetic. Also check the offset lands *inside* the symbol's extent (next symbol minus this one) before believing it — `+0x2df` into a `0xF30`-byte function is fine; `+0x2df` past a 16-byte symbol is a nearest-preceding-symbol artifact. | 0 |
| `build/soak_parallel.py` | **REFUSES to run more than one mcla** ("Single-instance bounded soak runner", docstring `:1`). The old N-affinity-pinned mode and its `time.sleep(5)` stagger (`:3-5`) were unsound: one window, one D3D12 device, one audio endpoint, one VFS cache, so a collision is a **synchronisation** bug pinning cannot fix (F-572). **Soaks run through `build/soak_run.py`** (`:41-43`). | 0 ran / **2 refused** |

## Project MCP servers — both `opencode.json` (gitignored, different schema) and the committed `.qoder/settings.json` declare the same **three** (first load shows a trust prompt; run `/mcp reload`)

| Server | What it is | Constraint |
|---|---|---|
| `ida-pro` | `python ~/.local/share/mcp/ida-bridge.py` → idalib on `build/game_data/default.xex`, RPC :8745 | it `taskkill`s `idalib-mcp.exe` on start — **never** launch it while another session's IDA session is open. If `tasklist` shows `idalib-mcp.exe`, **attach to `http://127.0.0.1:8745/mcp` instead** (POST, `Accept: application/json, text/event-stream`, keep `Mcp-Session-Id`) — verified working 09-20 22:2x: 47 tools, `get_metadata`, `decompile_function`, `get_xrefs_to` (PROGRAM_GUIDE §10) |
| `renderdoc` | `python -m renderdoc_mcp` + `C:\Program Files\RenderDoc` | for capture analysis only (W34/W35 GPU work); hooks must stay log-only, no RenderDoc in the boot path |
| `x64dbg` | headless x64dbg (`x64dbg_run` / `x64dbg_attach`) | launch-under-debugger only; never in the boot path |

Built-ins worth using: `node-repl` (the manifest TOMLs must be edited via node tooling, never by hand — PROGRAM_GUIDE §11), `browser-use`/`WebSearch` (Xenia/XenonRecomp upstream semantics — cite the file:line into `.research/xenia/` too, a local checkout). `qoder-qmind`/`sites`/`canvas` are irrelevant; don't spend turns on them.

## Known conflicts / hazards in this directory (full register: `LONG_TODO_MASTER` §8)

- **Two agent configs, same three servers, different schema** — keep them semantically identical and note which one you changed. `.gitignore` ignores `.mcp.json`, which **Qoder does not read**: don't create it.
- **`.qoder/` is NOT gitignored**, so `settings.json` and the skills are committed. They carry absolute machine paths (`C:\Users\abdul\...`) — fine for this single-user repo, but never add a secret/token here; use `.qoder/settings.local.json` for per-machine overrides.
- **NOT a duplicate — a prior "delete the root one" instruction here was WRONG (corrected 2026-09-28).** Root `CODE_OPTIMIZATION_PLAN.md` is the live **coding policy (Ponytail+)** + MCLA guardrails, "still in force" (`:1-8`); `docs/CODE_OPTIMIZATION_PLAN.md` is the 2026-09-20 **compressed task-status** list, "Subordinate to `docs/LONG_TODO_MASTER.md`" (`:1-4`), which cites the root file for the guardrails (`:22-23`). Complementary: docs/ wins on *task status*, root on *policy*. The VOID warning still stands as a rule: **never follow any Phase 0 that edits `generated/`.**
- **Two task queues.** `LONG_TODO_MASTER.md` §2 is the durable queue; the agent `TaskCreate` list is per-session scratch. Never let a queue item live in only one of them.
- **Root junk is mostly discharged, and `git add -A` is unsafe here** — stage named paths only. Two deliberate root residents: **`mcla_jts_regen.toml`** (the live jump-table regen config, read as `BASE_CONFIG` by `tools/fix_stubs_iter.py:20`) and `CODE_OPTIMIZATION_PLAN.md` above.
- **`docs/` is tracked since 09-20** (`.gitignore:9-12` says so; `git check-ignore docs/…` exits 1) — plain `git add` a new doc. Never re-ignore it.

## Non-negotiable project constraints

Retail content only (`xarchive_cache.rpf` + audio/music; never `mc4/art`). Guest pointers are 32-bit
guest VAs read through the checked helper with explicit endianness (`ReadU16BE`/`ReadU32BE`/`ReadF32BE`)
— no `reinterpret_cast` on guest data. Census hooks capture state only: no D3D12 calls, no
`RegisterFile` dependencies, no invented draw data. No ReXGlue SDK dependency — from
LARecomp/BadassBaboon take guest *facts* only (addresses, timings, quirks), never their architecture or
`rex::` runtime. Do not pop stash `session33-audlo-forensics-gpu-device-capture-hardening` (it regresses
boot). Commit only when asked.