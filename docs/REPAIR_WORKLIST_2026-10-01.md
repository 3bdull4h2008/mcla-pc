# REPAIR WORKLIST — 2026-10-01 audit campaign (for the editing AI)

> Produced by a ~70-agent read-only audit of the rules/docs layer on 2026-10-01.
> **Entry point.** Every claim below was verified by an agent against the tree THIS DATE; items
> marked [CORRECTED] supersede an earlier draft of this worklist (adversarial re-verification pass).
> The tree is being edited concurrently — **re-measure any file:line before editing it** (F-692's law).
> Line numbers below were measured 2026-10-01 ~07:00-16:00 JST and may already have drifted.

## 0. Rules of engagement for this worklist

**Companion deliverable (2026-10-01 evening): `docs/SUPERVISOR_REVIEW_2026-10-01.md`** — the
per-act retrospective (Acts I-V rated on measured metrics: 467 soaks, 461 findings, 420 commits),
the top wins/wastes rankings, and supervisor cautions for the concurrent vertex session. Read it
for "how did we do"; read this file for "what still needs fixing".

- Read-only audit; nothing here was edited by the auditor except this file (progress save) and the
  de-bloat actions listed in §8 (junk deletion + log compression, explicitly requested by the user).
- Convention: every item cites file:line as measured on 2026-10-01. If the line moved, re-grep the
  symbol; do not trust the number (F-692).
- Ledger IDs F-693/F-694/F-696 are CITED in src/ but have no entries; the editor's new HANDOFF block
  designates **F-697** as next free — see §3 item 1 before allocating IDs.

## 1. Constitution-level defects (AGENTS.md / RULE 0)

1. **RULE 0's historical record is partially uncited.** [CORRECTED: it is 3 of 11 kills with no
   record, not 5] — (a) "a fix resting on n=3" (AGENTS.md:21), (b) "0xC0006200 =
   PM4_SET_BIN_SELECT_LO" (AGENTS.md:19) — **and this one is CONTRADICTED by ledger F-653**
   (ROOT_CAUSE_VALIDATION.md:14428-14430 records the payload as `0xC0000000`, "Meaning unknown.
   Recorded, not interpreted."), (c) "'517 shaders compile' never measured" (AGENTS.md:41).
   Two more are killed only in src/doc comments, not the ledger: 299.5→354 kill lives at
   src/kernel/heap.cpp:950-951; 437-zeros kill lives at docs/PROGRAM_GUIDE.md:727. AND a second
   contradiction: RULE 0's "the signature of an empty buffer" gloss (AGENTS.md:17-18) is repudiated
   verbatim by F-685 (ROOT_CAUSE_VALIDATION.md:14708: "NOT 'the signature of an empty buffer'... a
   TYPE degeneracy, not a size one"). **Fix: either ledger the missing kills as new F-IDs or reword
   RULE 0 to cite only recorded kills; resolve both contradictions explicitly.**
2. **AGENTS.md defaced heading**: the RULE 0 heading wraps so its second line begins `##`,
   creating a spurious heading (AGENTS.md:9-10). Fix: rejoin the heading or demote the wrap.
3. **"The 6 rules that keep costing sessions" has 7 items** (1,2,3,4,5,6,14) — AGENTS.md:66.
   Fix: retitle to "7 rules" or fold 14 into the numbering note.
4. **Brevity constraint breached**: AGENTS.md grew 109→180 lines (+65%) against its own header
   "keep this file short — it costs tokens every session" (AGENTS.md:1). Fix: compress the tool
   table and conflict list; move worked examples into the skills they summarize.
5. **Two wrong cites in AGENTS.md** [CORRECTED by K-audit]: `/MAP` flag is at CMakeLists.txt:577
   (not :563); soak_parallel's stagger doc is at build/soak_parallel.py:4 (not :49).
6. **Tool table row WRONG (not just stale)**: addr_owners.py symbol form WORKS now (three-tier
   resolver, tools/addr_owners.py:53-73; `--check sub_821CA540` = 2 sites, exit 0, verified
   2026-10-01). AGENTS.md:35 and :117 still tell readers it is broken and cite :240 as the reason —
   that line now holds unrelated macro-extraction comments. Also the same stale claim appears in the
   row's "USE HEX" warning.
7. **Tool table row OBSOLETE**: build/soak_parallel.py now REFUSES multi-instance ("Single-instance
   bounded soak runner. REFUSES to run more than one mcla", docstring line 1; lines 4-9, 43-44 point
   to build/soak_run.py). AGENTS.md:122 still describes N-pinned-instances + 5 s stagger.
8. **RULE 0 vs rule 13 evidence bars**: AGENTS.md:64 bridges them but silently drops rule 13's
   commit-hash clause. Fix (worklist of record): make rule 13 read "cite a tool-printed log line or
   file:line; a commit hash alone marks the claim UNVERIFIED until a soak reproduces it."
9. **Rule-number namespace**: AGENTS.md:68 covers only 1-6/14 + 11/13. Bare "rule 5" is
   triple-valued (AGENTS.md:87 concurrency vs LONG_TODO:976 new-log vs PROGRAM_GUIDE:797
   no-stacking); 6/7/8/9/10 collide LONG_TODO §1 vs PROGRAM_GUIDE §11. Two live miscites found:
   ROOT_CAUSE_VALIDATION.md:8581 "agents.md rule 12" (AGENTS has no rule 12) and
   HANDOFF_NEXT_AGENT.md:226 "AGENTS.md rule 5/6" (rule 6 is the E:-primary rule, irrelevant).
   Fix: extend AGENTS.md:68 to assign 7-10/12 explicitly, correct the two miscites.

## 2. HANDOFF_NEXT_AGENT.md

1. **[FIXED BY EDITOR TODAY]** 2026-10-01 SUPERSEDING block added (ledger through F-692); §5 kills
   the "Next free ID: F-654" footer; §7 retires the 09-28 "tree is RED" verdict with evidence.
   Remaining defect in that new block (K-audit, 6 items):
   - Line 5: fatal cited at w685.log "line 25,091" — actual 25092 (25091 is an F442-SECTION row).
   - "Chevy occurs 8 times" vs "'Chevvy' x8" later in the same chain — one spelling is wrong.
   - `sub_823964C0` claimed "0 hits" in ledger — grep finds 1.
   - "549 `### F-NNN` headings" — actual 552.
   - "prepended only" is false: 3 lines were appended at EOF (old 2601 → new 3317-3319) without a
     date header.
   - Pre-edit "2,545 lines" is impossible (HEAD=2601, 0 deletions, +718 ⇒ 3014).
2. Older bookkeeping lines now wrong (fix when convenient): :103 "last commit d7125d1" (HEAD is
   8385925); :102-104 "~194 KB uncommitted ledger work" (now ~2.0 MB added / 1.4 MB deleted).
3. Monotonicity: the F-383/391/384 cluster (:725/:734/:742) is out of order (documented insert
   artifact — low priority).

## 3. Ledger (ROOT_CAUSE_VALIDATION.md)

1. **Orphan F-IDs cited in src/ with no entry** — final census [CORRECTED: 4 true orphans, 12 weak]:
   TRUE (zero ledger mentions): F-150 (gpu_device.cpp:22698,22711,23509), F-266 (gpu_device.cpp:4885),
   F-694 (gpu_cp.cpp:424,3181,3214,3828; render_queue.h:185,308,317), F-696 (vfs_rpf.cpp:2038,2329,2373).
   WEAK (no own entry; referenced in passing or as "Next ID" pointers): F-056 (reconstruction cited
   at ROOT_CAUSE_VALIDATION.md:1848 to an EXTERNAL file C:\mcla-emergency-20260921-0112\LEDGER-ADDENDUM.md
   — [CORRECTED: the file exists on C:, not in the repo; copy it in or cite the path]),
   F-153, F-162, F-258, F-364, F-388/389/390 (heap.h:75 cites a sub-variant F-390b), F-409, F-483,
   F-528, F-693. **Fix: write entries or explicit void-notes for the 4 true orphans; adjudicate the
   weak ones in one sweep entry.**
2. Numbering: F-654..F-658/F-680 void adjudicated (F-681); F-412..F-429 adjudicated at :9702;
   F-057..F-076 lost-week documented at :2098. No duplicates. 552 headings, not 549.
3. 10-01 entries never diff against a NAMED baseline (census-skill requirement) — process gap, note
   in next session's brief, not a doc edit.

## 4. LONG_TODO_MASTER.md

1. **Do-not re-anchors NOT yet applied** (K-audit confirms all six still stale at :1695):
   - #3: `byte_827D5C70` no longer exists in generated/ or src/ — reword to cite F-013 (:165).
   - #8: HydrateShaderHashTable was REMOVED under F-609 (gpu_device.cpp:4530 comment; ledger :14857)
     — reword to "never re-add hash-table hydration (F-609); INSERT cleanliness unproven".
   - #15: W34 scan cite :5251-5254 is now surface-census code; the scan lives in `MclaW34GfxParseLever`
     (gpu_device.cpp:8641, band check :8728-8729) and ALREADY accepts 0x8206Dxxx since F-437 — only the
     "never fabricate the loader" half remains meaningful.
   - #16: valid; repoint parenthetical to tools/ppc_xrefs.py:6-7 (per-register tracking).
   - #17: valid; cite ppc_config.h "5,6,9,10" (xer is line 6).
   - #18: valid; cite boot_host.cpp:1990 (new `host+0x…` format) and change "unbuilt-in-soak" →
     "unexercised-in-soak" (w684 has 0 owner=guest rip dumps; only owner=host).
   - #20: STALE AND ALREADY FIXED IN CODE — the poll now uses `CpPrimaryWritebackVA()`
     (imports.cpp:4983-4986, comment :4974-4977 documents both old wrong addresses). Anchor the
     do-not to that function, not hex constants; cite F-057 via LONG_TODO:806 (F-057 is in the
     ledger hole, no entry).
   - #21: anchor moved to render_thread.cpp:134 (one-shot clear) and :1024 (heartbeat default),
     closed by the F-610 one-way latch `s_guestContentSeen` (:1029-1031).
   - #22: no edit — satisfied as written (soak_census.py EXC_CODES :258-264, :647).
   - #13: F-B IS defined — at LONG_TODO:1594 (Wave-B spec) and HANDOFF:2895. [CORRECTED: "defined
     nowhere" was wrong.] Repoint the parenthetical to :1594.
2. §0 blocks: the file's own rule is "add a dated superseding block rather than editing someone
   else's"; three hunks in the current uncommitted diff are in-place rewrites (:1211, :1480, :1725).
3. **False attribution at ~:1484-1486**: commit `bc4b489`'s stat shows only `11`, `err.txt` and the
   two script moves — NUL.obj / crash_dump.txt / crash_log_early.txt / GITHUB_APPEAL_*.txt were
   removed by OTHER commits (git log --diff-filter=D). Fix the sentence.
4. Queue: §2 frozen (last inline closure 09-25/26); T41.59→T42.20 live only in the ledger; scorecard
   holds a third queue. Real number collisions: T41.10 (:1003 vs :1198) and T41.11 (:1013 vs :1202)
   — the renumbered Wave queue collides with §2's UI-inflate tasks. [CORRECTED: T41.9's three hits
   are one task + provenance + one distinct task; and "closed-in-ledger open-in-queue" for
   T41.6/T41.7/T42.1 was NOT established — the ledger closures are T41.60/T41.79/T41.80/T41.100.]
   Fix: add a dated note at §2 top declaring precedence (ledger task-series is the operative queue).

## 5. PROGRAM_GUIDE.md

1. §2 repo layout: add rpf3_nested.cpp/h (src/fs/), xma_decoder.h + audlo_extract.h (src/apu/),
   port_net/port_kobj/port_xam_user/port_voice_input (src/kernel/) — all exist, none named.
2. §2 "176 TUs" — correct (176 on disk; 179 under generated/ppc/ is a different tree the doc doesn't
   cover; consider one line noting it).
3. §3: VFS gate is app.cpp:103-105, not :90.
4. §7 vs §7-ADDENDUM: ADDENDUM header says "13 entries" but holds 48 rows; exactly one label
   (INFLATE-J2-WIN-CONT-SKIP) is in both; §7's "verified" line numbers drifted again (kF432
   :19595/:19645 → actual :23177/:23227; kF434 :1410/:11765 → actual :1507/:13081). Undocumented
   mitigation count grew 79→86 (two tool runs today agreed on 86; one later agent read "13" —
   re-run mitigation_audit.py before quoting).
5. §9: 149 rows; GATE-STACK already marked RETIRED in-guide (:637) but still parsed dead;
   CAS-SITE live (imports.cpp:4999) but unregistered; DICT-HYDRATE/swfCMD/GATE-WAIT/PARK-STACK
   comment-only. (Census tool prints these every run — low priority.)
6. §10: add tools/ida_dump.py + ida_bulk_export.py + the x64dbg MCP server (configured in both
   .qoder/settings.json and opencode.json, unmentioned in the guide).
7. §4/§5: consider a dated block noting the pending guest_memory.cpp rework (+320/−18 uncommitted).

## 6. EXECUTION_PHASES.md / plans / skills

1. Part A rule 1's "audit mode" qualifier is stated only inside rule 1; rule 2 reads as a global
   "write exactly two things" contradicting PROGRAM_GUIDE §11 rule 7. Fix: qualify rule 2 with
   "in audit mode".
2. PLAN_VMX128.md header says "Route A LANDED — do not re-execute"; do-not #2's §4 pointer is still
   valid (Route B step 3 gate at :153/:168, TU=176 at :182).
3. Skills: log-census SKILL.md:106-109 still describes soak_census's OLD VEH rot (fixed long ago —
   VEH-NEUTRAL + parking-thread rows exist at soak_census.py:141-143). Editor touched only
   boot-cycle (+9 lines, PowerShell UTF-16 gotcha); the other four skills unverified-against-today.
4. LONG_TODO:977's canonical kill command lacks the MSYS guards the skill mandates
   (SKILL.md:29): use `MSYS_NO_PATHCONV=1 MSYS2_ARG_CONV_EXCL='*' cmd.exe /c "taskkill /F /IM mcla.exe"`.
5. Rule 10's "docs/ is GITIGNORED — git add -f" (LONG_TODO:981, also AGENTS.md:168-169) is STALE:
   docs/ un-ignored since 09-20 (.gitignore:9-12, `git check-ignore` exits 1). Reword: "docs/ is
   tracked since 09-20 — plain git add; never re-ignore."

## 7. Conflict register §8

- Entries 4 and 5 are OBSOLETE (resolved) — close them. Entry 1 needs +x64dbg (3 servers now, not 2).
  Entry 6 must be rewritten for THREE queues (§2 frozen / ledger series / scorecard order) with
  precedence. Entry 7 must add PDBs + 22 untracked tools/* + docs/ref/. Entry 8: drop the IDA-bridge
  clause (tools/ida-bridge.py no longer exists; the courtesy note at :728-732 is dead text).
- NEW entries needed (10-14): scorecard queue; status-template; docs/ref orphans; void-ID vs footer
  (now resolved by editor's §5 — record as closed); RULE 0 vs rule 13.

## 8. De-bloat actions taken by the auditor (explicitly user-requested 2026-10-01)

See the bottom of this file (§9) for the exact manifest — deleted vs archived vs compressed, with
sizes. Nothing tracked was touched; nothing ledger-cited was destroyed.

## 9. De-bloat manifest

**Deleted outright (regenerable, zero information loss):**
- gpu_device.pdb, render_thread.pdb (root strays, 8.4 MB; *.pdb + *.ilk added to .gitignore)
- tools/difftest/__pycache__/ (Python bytecode)
- tools/validators/texture_quad_shaders_gen.h (generated by gen_texture_quad_shaders.py from kept .hlsl sources)

**Archived → docs/archive/ (orphaned-but-authored; README.md there explains each):**
- DAILY_STATUS_TEMPLATE.md (0 inbound citations, competed with HANDOFF live block)
- SYSTEM_DESIGN_SCORECARD.md (09-28 snapshot, superseded by HANDOFF 2026-10-01 block; kept as evidence)
- tools/lzx_raceeditor_offline.c (declared DEAD by F-191), tools/lzx_raceeditor_proof.py (duplicate of the cited proof.c)

**Compressed (evidence preserved — zgrep-readable):** 623 soak logs older than 2026-09-29,
build/*.log 12 GB → 2.1 GB total; build/ 19 GB → 9.8 GB. The 63 logs of the active window
(09-29..10-01, w675..w686) stay raw because the live ledger blocks cite them by line number.

**Second pass (user-requested, ~18:2x):** compressed 67 more logs — everything raw except the live
frontier **w685/w686/w688/w689** (kept raw: w685 is the only line-cited log in the live HANDOFF
block; w688/w689 are today's newest). The 1.73 GB flood log **w687.log → 38 MB .gz** (45:1; zero
line-number citations in any live doc, verified before compressing). Deleted 183 zero-byte
build/*.log + 432 zero-byte attic files; attic's non-empty logs gzipped (105 MB → 7.7 MB).
**Final log state: 4 raw (293 MB) + 691 .gz (677 MB) = ~0.97 GB total log mass, down from 12 GB.
build/ total 19 GB → 8.2 GB** (floor = game_data 6.3 GB retail content). Breadcrumb:
`build/LOGS-ARCHIVED-2026-10-01.txt`.

**Third pass (user-requested, ~18:4x) — `.research/` and stragglers, 9.1 GB → 1.3 GB:**
- Deleted `.research/xenia/build/` (6.2 GB — one day of 2026-08-22 artifacts, zero references from
  any build script; the project reads xenia's *source*, 27 MB, for facts).
- Deleted `XenonRecomp/build/` + `build-msvc/` (417 MB of objs + compiler-probe exes).
  **`build-clang/` and `build-clang-rel/` KEPT — CMakeLists.txt:178 guard: the exe there is the
  only binary carrying the landed JTS-TAILCALL patch (predates the VS upgrade).**
- Removed all 5 `.git/` dirs (1.44 GB) from the frozen reference checkouts; pins recorded in
  `.research/PROVENANCE-2026-10-01.txt` — note: xenia/XenonRecomp/UnleashedRecomp HEADs are
  "auto: bulk commit" import snapshots, so no upstream history was lost; 360tools had real history.
- w688/w689 logs gzipped (273 MB → 10 MB; 6 h old, zero line-citations).
- **Grand total working dir: ~29 GB → 9.4 GB** (build 7.5 GB of which 6.3 GB is game_data retail
  content; .research 1.3 GB; everything else < 15 MB).

**Fourth pass (user-directed, ~19:1x) — citation-filtered log reduction, 0.7 GB → 0.32 GB:**
- Built the citation set from all of docs/ + AGENTS.md (489 distinct cited waves). **123 waves
  never cited anywhere were deleted** (their .gz, 144 MB-equivalent). **570 cited waves converted
  to true single-compression `.xz`** (from the earlier accidental xz-of-gz double container):
  570/570 converted, 0 failed, 295 MB. Verified: `xzgrep -c PSTREAM w420.log.xz` = 52 = the
  original log's count. Raw left: w685/w686 only (22 MB, the live block's line-cited evidence).
- **Access contract changed: use `xzgrep`/`xzless`, not zgrep** — `build/LOGS-ARCHIVED-2026-10-01.txt`
  records this. Uncited waves are NOT recoverable (gone); cited evidence all survives.
- Total log mass: **12 GB → ~0.32 GB (38:1)**. If even this is too much, the next step down is
  deleting cited-but-cold waves — that destroys verifiable evidence and needs an explicit decision.

**Deliberately NOT touched:** anything tracked (needs a commit decision), docs/ENHANCEMENT_PLAN_INTRO.md
(path-cited by ledger :13648), docs/ref/ (xenos_registers.md cited by uncommitted src), .research/
(9.1 GB but gitignored reference checkouts that docs/ref derives from), build/game_data (6.3 GB,
the retail content the emulator runs on), all ledger-cited evidence.

**Lint-tool wiring verdict (from the tool-testing wave):** claim_lint.py + cite_check.py WORK
(exit-1 contracts; claim_lint re-flags 416/623 ledger entries incl. F-683/F-688/F-691 citation-rot)
— wire into the regen gate; accept_check.py into the boot-cycle skill post-soak; api_audit.py
pre-compile. **None of them scans src/ comments — the F-692 symbol-resolver gate is still
unwritten; the surviving F-688 instance (gpu_device.cpp:1799-1818, 22-bit reasoning) is caught by
nobody.** Rule 1b: honored in prose (ledger :14455) but no symbol list; the one load-bearing
unlabeled new symbol found is `DecodeCrtRegistration` (src/boot_host.cpp:1344).

## 10. Wave-16 additions (orphan reconstructions, scorecard, next-ID)

**[2026-10-01 ~15:40 STATUS — most of this worklist is now DONE, split between the concurrent
editing session and the audit session. Verification state per item:]

### Applied by the EDITING session (verified in-tree by the audit session):
- **§4 do-not re-anchors: ALL APPLIED** (LONG_TODO_MASTER do-not line, ~:1271) — #3 F-013 anchor,
  #8 F-609 rewording, #13 F-B definition located (T41.8), #15 MclaW34GfxParseLever + symbol-not-line,
  #16 ppc_xrefs.py docstring, #17 5,6,9,10 + all four defines, #18 symbol cite + "unexercised",
  #20 CpPrimaryWritebackVA + F-057 hole note, #21 symbol cites + F-610 latch. Fuller than this
  worklist asked. **#13 needs no further edit** (its F-B anchor is better than the worklist's).
- **§1 Constitution (AGENTS.md): RULE 0 re-audited heading; both contradictions (0xC0006200,
  empty-buffer) WITHDRAWN AS INCORRECT with evidence; CMakeLists:577 corrected; addr_owners row
  fixed ("hex or sub_ both work"); soak_parallel row fixed (refuses >1); spurious `##` heading gone;
  "6 rules" retitled; rule-10 wording fixed; rule 13 reworded.**
- **§3 Ledger: reconstruction block F-697..F-728 written by the editing session** (F-720..F-723 =
  the four orphan reconstructions with fuller treatment; F-726 adjudicates block start; footer =
  next free **F-729**, superseding this worklist's F-697 and the ledger's old F-693/F-659).
- **§4 LONG_TODO compression: §0 trail relocated** (1,778→~1,415 lines; trail blocks moved by the
  editing session; entry 3 provenance note added to §8).

### Applied by the AUDIT session (this campaign):
- **§2 HANDOFF split**: live file 3,319 → **305 lines**; trail (3,021 lines) →
  `docs/archive/trail-handoff-2026-10.md` with pointer. Old absolute HANDOFF line numbers resolve
  to the archive now.
- **LONG_TODO rule 6** (MSYS-guarded kill command) **and rule 10** ("docs/ tracked since 09-20") —
  the two items the editing session had not reached.
- **§8 dedup**: replaced stale duplicate entries with a pointer to AGENTS.md's maintained copy,
  kept the adjudicated entry 3 + provenance note, registered new conflicts 10-14 (three queues;
  next-free-ID F-729; HANDOFF relocation; docs/ref untracked-cited; RULE 0 record).
- **§5 PROGRAM_GUIDE**: §2 layout updated (rpf3_nested, port_*, xma_decoder, audlo_extract,
  heap_arena); §10 new first bullet (ida_dump.py, ida_bulk_export.py, x64dbg); §7 kF432/kF434
  re-pinned (:23564/:23614, :1508/:13468, re-measured 10-01) with prefer-symbol notes.
- **§6 log-census skill**: T40.4 "fix soak_census" note marked DONE/historical; line cite
  de-pinned to symbol.
- **De-bloat §8/§9** (PDBs, archive, 623 logs gzipped) — unchanged, see §9.

### Still open (nothing new; in priority order):
1. **Commit** — the combined diff (two sessions' work + these doc fixes) is uncommitted on the
   drive that ate the ledger once. Named paths, docs/ included (tracked since 09-20).
2. Ledger F-692 class: the **src/-comment symbol-resolver gate** remains unwritten (claim_lint/
   cite_check cover ledger/docs only; gpu_device.cpp:1799-1818 22-bit reasoning still caught by
   nobody — re-grep before acting, lines move).
3. `DecodeCrtRegistration` (src/boot_host.cpp, ~:1344) needs a rule-1b label; lines move.
4. HANDOFF live block's 6 small factual defects (K-audit: w685.log:25092, Chevy/Chevvy, sub_823964C0
   1 hit not 0, 552 headings not 549, EOF append not prepend, 3014 not 2545) — cosmetic now that the
   trail is relocated, but they are live claims in the live block.

**Next-free-ID conflict (NEW):** the editor's HANDOFF §5 (:208-213, :235) designates **F-697**
(census: F-693 4 cites, F-694 7, F-696 3, F-695 free-but-below-F-696 hence skipped) — but the
ledger footer still reads "first ID above every claim is F-693" and "starting ID F-659". Fix:
amend the ledger footer to F-697 and retire the F-659 pointer; explain the F-695 skip in one line.
§8 register entries 10-14 remain unadded.

**Orphan-entry drafts — paste into the ledger (HEADERS CORRECTED by the worklist author):**
F-150 and F-266 are 09-20-fault losses; **F-694 and F-696 are NOT fault losses — their src comments
are dated 2026-10-01, i.e. same-day citations from the editing session that never wrote the entries
(an F-692-class process failure by the editor itself).** Drafts (verbatim, fix the provenance line
per ID):

- `### F-150 (RECONSTRUCTED 2026-10-01 — original lost in the 2026-09-20 volume fault, see :2098) — the w160 C0000005 exposed by F-149's entity.type expansion is sub_821BE568 (buffered-stream Seek) dereferencing an UNBOUND stream object.` Seek loads device/handle from [stream+0]/[stream+4] (r3=0, r4=0, fault addr 0, lr=0x821BE5F4 vtable bctrl); live but unbound — the read-path shape F-122 fixed, no Seek equivalent. Evidence: gpu_device.cpp:23681/:22870/:22883 (addr_owners: no owner for 0x821BE568). SUPERSEDED-BY F-155 (the missing object is sub_821BE8D8's return). Caveat: reconstruction from citations; original measurement lost.
- `### F-266 (RECONSTRUCTED 2026-10-01 — original lost in the 2026-09-20 volume fault, see :2098) — first-0xCDCDCDCD poison scan over UI decompress dests as a completeness signal.` On first dump of each dest read 8 words, report the pre-poison prefix. Evidence: gpu_device.cpp:4995 (neighbors F-265 :6573, F-267 :6583). SUPERSEDED-BY F-267/F-274 ("validbytes=20" was a first-zero artifact); instrument extended by F-321's nzwords/runs (:5001). Caveat: original w-log numbers UNVERIFIED.
- `### F-694 (WRITTEN RETROACTIVELY 2026-10-01 — cited same-day before entry, see HANDOFF §5) — the CP shader program BODY crosses the F-652 draw-bridge inline with the scalars: dwords(COUNT) vs body[](DATA) split in CpShaderProgram, bodyVs=/bodyPs= appended at CP-DRAW-BRIDGE row end.` Body copied from the same captured img.dwords[] under g_microcodeMutex, exactly min(captured,cap) dwords; shipped-vs-declared (totalDwords) divergence proves bytes crossed. Evidence: gpu_cp.cpp:424,3181,3214,3828; render_queue.h:185,308,317. STILL-RELEVANT (implemented).
- `### F-696 (WRITTEN RETROACTIVELY 2026-10-01 — cited same-day before entry, see HANDOFF §5) — single-anchor scope-guard trace in ReadFileAt (before the OVERLAPPED block) emitting one row per call naming WHICH BRANCH ran, to localize the w682 'chevy' fatal span-ownership collision.` Anchor precedes every early return (size==0, failed ::ReadFile, failed Materialize); reports handle/nested/span_ran (set at the ApplyExpandedSpans call site); rate-limited 16/path then every 4096th. Evidence: vfs_rpf.cpp:2038/:2329/:2373. STILL-RELEVANT — answers which branch serves the guest's 3×32 KiB reads (carconfigs windows swallowing vehicle.lst, stored=166,323 vs logical=294,912), the open F-684 span-ownership question.

**Scorecard (docs/archive/) re-verification — 20 rows:** 13 STILL-TRUE; 3 OVERTAKEN (row 13 Heaps —
F-640 fixed the phys free path: honoured 2511/2512, PHYS-POOL-FULL=0; row 15 VFS — F-643/F-683
31-bit mask, OPEN-REFUSED 74→0, fatal predicate now r29<0 per F-691; row 20 Boot flow — descent
refuted F-627/F-628, boot now DEGRADED with a truthful guest fatal "Unknown manufacturer %s in
vehicle list file" at +15.8 s, 8 draws attempted, 0 pixels, all DRAW-CP-REFUSE no-translated-pso);
2 CANNOT-VERIFY (8 Present/pacing, 12 Threading). Execution order: #2 done, #8 continuous, #1
superseded (RED retired, green gate unmet), rest open. **Action: append a superseding note to the
archived scorecard pointing at HANDOFF 10-01; rows 13/15/20 are actively misleading as written.**

**New frontier the scorecard never knew:** UIXSF-DIVERGE regression (good 144,864→22,145, HANDOFF §3).
