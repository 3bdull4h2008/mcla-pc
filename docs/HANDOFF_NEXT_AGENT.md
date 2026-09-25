## 2026-09-26 ~05:5x (F-316, `ppc_disasm` on the boot-worker loop + `w276` signal census, **no build**) — **the terminal livelock is quantified end to end, and it makes me withdraw F-314's global claim that "no permitted lever remains."** Ledger through **F-316**; next ID **F-317**.

- **The main thread is not blocked — it is polling.** `WAIT[KWFSO] obj@40004D7C reason=3 to=30ms` fires **6,626 times** in 120 s: every wake is a timeout. That object was released **exactly once** (`SIGNAL KeReleaseSemaphore obj=40004D7C inc=1 adj=1 lr=00000000` at 02:39:51.603 — **`lr=0` means host code with no guest return address**), `KeSetEvent` never fires at all, and the other 40 `SIGNAL` lines are `NtReleaseSemaphore` on *other* objects (`C5000280`/`C9CF8180`/`CAF28300`…).
- **Meanwhile the boot worker resets that same object ~60×/s.** Raw decode of `0x8242FCB0..0x8242FCF0`: `lwarx`/`stwcx.` atomic decrement → `cmpli r3,0102` → **`addi r3,r26,32`** (`r26=0x40004D5C` ⇒ `r3=0x40004D7C`) → **`bl 0x827BD874` = `__imp__KeResetEvent`** (`ppc_func_mapping.cpp:44935`) → `bl 0x8242F870` (the 60 Hz consumer) → `b 0x8242FBA8`. A live loop reaching into host kernel emulation.
- **So F-314 §2 was overstated.** It scoped "no permitted lever" to *who dispatches the handler table* — that part stands — but it predated this loop, which is a host-adjacent path it had not considered. **Withdrawing the global form, keeping the local.** Recurring today: every "closed" claim proved narrower than its wording (`F-297 §5`→`F-304 §4`, `F-309 §4`→`F-310`, `F-314 §2`→here).
- **`KeInsertQueueDpc` is NOT a host import** — across all **246** `__imp__` thunks the only Dpc-named one is `KeRaiseIrqlToDpcLevel`. So the enqueue is guest xkrnl code with no caller and **no host stub to write**; the wall is drawn exactly: a guest-side call into `0x8242FD00` that no recompiled code makes.
- **Narrow, cheap, permitted test (task #24):** does the ~60 Hz `KeResetEvent(0x40004D7C)` race out a release the guest genuinely makes later? One log-only census pairing `SIGNAL obj=40004D7C` against reset timestamps settles it. **UNVERIFIED so far:** that any second release was ever intended, or that the reset is untimely — I established only that both are observable.
- **Discipline that earned its keep:** 41 `SIGNAL` lines existed and only 1 matched my `obj=` pattern, so I read all 41 formats *before* writing "signalled exactly once" — same error class as the seven bad instruments earlier today.
- **Integrity note on commit `91354ea`:** my python heredoc died on nested quotes, so that commit contained **only** the ledger while its message implied the handoff/plan docs too. Corrected here; verify a commit's `--stat`, not just its rc.

## 2026-09-26 ~05:4x (F-315, **BUILT + SOAKED twice**, fix then reverted) — **F-303's frame-0 stall is CONFIRMED in the code, and the obvious fix LIVELCKS. Reverted clean.** Ledger through **F-315**; next ID **F-316**.

- **The defect is real:** `src/gpu_device.cpp:8065-8082` takes `ls` as a **local copy** from `MclaFindLastServe` and, across the entire branch `:8065-8148`, **never writes `ls.pos` back and never calls `MclaRecordLastServe`** — while the sibling leg at `:8015-8020` does both (F-195 fixed the identical bug there; its comment at `:8004-8013` says so). That is why **every** `INFLATE-REFORCE` line in every soak reads `pos=00000000`.
- **The naive fix fails.** Mirroring the sibling (advance + persist, behind the existing `kUiServeAdvance` flag at `:554`, an exact isolation since `kPathBEnqueueUI` already satisfies the sibling) gave `w275` **657,657 lines vs `w274`'s 57,886**, with **119,352 identical `INFLATE` iterations** and 238,704 `XMEM` lines at `in=512` on the same src/dest. Gates stayed clean (`C0000005`=0, `Fatal`=1 pre-existing) so this is **progress starvation, not a crash** — and `nGfx` prints falling **6→4** proves the boot got *shallower*, which is the signal I'd have missed if I'd only checked for absence of faults.
- **WHY, and therefore what a correct attempt must include:** making `srcOff >= srcSize` true is not enough, because the only rescue is `if (srcOff >= srcSize && IsJob2UiDest(outPtr))` at `:8081`. For a dest that is **not** a Job2 UI dest, nothing serves, `served` stays false, and the guest re-enters inflate on the same 512 bytes forever. **Any retry must also handle the non-Job2 exhausted-entry exit** — widen that predicate, or reset `inLeft`/fall through. Captured as task #23.
- **Revert verified properly, not assumed:** `w276` came in at **102,134 lines vs `w274`'s 57,886** and I did **not** call that restored on a line total — the per-marker table matched exactly (`PATHB-HOSTDECODE` 5=5, `PATHB-HOSTVERIFY` 3=3, `nGfx` 6=6, `LISTLINE` 171=171, `C0000005` 0=0) and the 119K repeating shape was absent, so the total was aggregate churn. **F-072 again: a line total is not a baseline test.** Also: the build yielded an **identical-size exe with no new log literal**, so rule 12's mtime check was insufficient — compilation was confirmed by `gpu_device.cpp.obj` mtime vs source plus grepping the flag.
- **Tree:** `kUiServeAdvance = false` (shipped behaviour unchanged); the gated code stays with the diagnosis in the comment at `:551-560` so nobody re-attempts it blind. **Garage is still 1 of 4 un-decompressed and `MOVIE-CTOR`=0 — objective not complete.**

## 2026-09-26 ~05:3x (F-314, `mcla_pe.bin` pointer census, **no build**) — **closes F-313's residual without IDA: no stored pointer anywhere in the image targets any of the three handler tables.** Ledger through **F-314**; next ID **F-315**.

- A walker needs a base. Both ways to hold one are empty: as an **immediate** (F-310 §3, control-validated at 4,172 hits) and as a **stored pointer** (here, validated by **701** hits across the wider span `0x82100000..0x8212FFFF`). The specific targets all return **0**: page `0x82107xxx`, the dispatcher's table window `0x821072F0..0x82107340`, the gate table at `0x82102AC0`, and the DPC table holding `8242FD00`. **So nothing can walk them** - `sub_821EBCF0` is dead because its four direct callers are dead (F-311), with no feeder.
- **This reverses last turn's recommendation, stated plainly:** F-313 called IDA 'the cheapest falsifier'. It is not. Three independent control-validated negatives agree, and IDA would only be confirming the shape of something whose anchor is absent in every representation. **`/mcp reload` is no longer blocking this question** (it still helps the msgid/`ori` blind spot, F-301 §5 - a different question).
- **The method cost, so it is not paid again:** five hand-decoded PPC field extractions failed before one worked, and **every one produced a confident zero rather than an error.** The tell that finally localized the bug: `bctr` returned 1059 while `mtctr` returned **0 for a word demonstrably present at `0x825FDAB8`** - if half a pattern works and the other half returns nothing, suspect your bit fields, not the image. **Rule: do not hand-decode PPC here; `tools/ppc_disasm.py` prints correct mnemonics, and assert a known-positive before believing any zero.** The only two findings that survived today are the two whose instruments were gated that way.

## 2026-09-26 ~05:2x (F-313, raw-byte decode only, **no build**) — **task #22's premise is very likely false: there is no table walker to find.** First negative result this session that *removes* work. Ledger through **F-313**; next ID **F-314**.

- **Three converging lines.** (a) F-310 §3: no absolute literal for the registry pages anywhere in `generated/` (control-validated). (b) F-312: the only references into the span are **24 fixed per-entry addresses** (`0x8210274C/276C/27EC`) handed to `sub_823DE6E8` (16 words) and `sub_823E5B70` (32 words) — leaf marshallers, zero indexing. (c) A **self-tested** stride-loop detector found **508** stride-loops in `0x82130000..0x827CD054` and **ZERO** with either endpoint inside the registry span. ⇒ the model is **per-entry registration, not a walk**, so `sub_821EBCF0` is dead simply because its four direct callers are dead (F-311) — no hidden feeder.
- **THE METHOD TRAP, and it is the reason to read F-313 before retrying anything here.** My first detector keyed on **indexed access** (`lwzx`/`stwx`) and reported zero for everything — **including the two functions that provably walk**: place-pass `sub_825EF100` and FDBF8. Both walk with **`add` + `bl`** (`825FDC54 add r3,r11,r30` / `825FDC60 bl 0x8260A830` / `825FDC6C addi r30,r30,8`), never an indexed load. **Reporting that result would have "closed" #22 on a test that cannot detect its own target.** The replacement test was gated on a known-positive (it must recover FDBF8's stride-8 loop before printing anything) — the discipline that should have been applied to all six broken instruments today.
- **Residual, so this stays an inference.** The detector misses computed increments (`add rA,rA,rB`), strides >64 bytes, `bctr` dispatch, and forward-iterating loops. **IDA would close it — the user's `/mcp reload` is still the cheapest falsifier.** If item 2 holds, F-219's "escalate to the producer, needs IDA" branch has no target at all.
- **⚠ I also re-confirmed a false memory of my own, worth watching for:** mid-turn I asserted "FDBF8 demonstrably contains `stwx` at `0x825FD448`". `0x825FD448` is **0x7B0 bytes before FDBF8 begins**, and FDBF8's true extent is `0x825FDBF8..0x825FDD20` (74 words) containing **zero** indexed accesses. The gate caught it because a control that *cannot* pass is as dangerous as one that fails. **Do not cite an address you have not re-read in the current window.**
- **Objective: unchanged and now boxed in.** Path A delivered (3/4, full-buffer). Path B's four branches closed (F-304→F-308). GFx dispatch dead at both ends with fired controls (F-309/F-311) and no feeder (F-313). **There is no remaining permitted, untested lever against "so GFx can initialize."** That is a result to bring to the user — **not** a licence to cross rule-2 / F-055, and **not** a reason to mark the goal complete (`MOVIE-CTOR`=0, `nGfx`=0, garage not host-decoded). Tasks #20/#22 closed as resolved/misframed.

## 2026-09-26 ~05:2x (F-312, `generated/` reads + two `ppc_disasm` calls, **no build**) — **F-311 §4's prediction confirmed, then its own candidate eliminated the same turn. A negative result, recorded as one.** Ledger through **F-312**; next ID **F-313**.

- **The "base handed as an argument" pattern is real.** `generated/default/mcla_recomp.23.cpp:40966-40996` (and duplicated at `ppc_recomp.73.cpp:3325/3345/3364/3444`) runs a repeated idiom: `(obj+88, &registry_entry)` passed to **`sub_823DE6E8`** and **`sub_823E5B70`**, with entry pointers `0x8210274C`/`0x8210276C`/`0x821027EC` — **all 24** page-`0x8210` sites resolve to just those three, and **none reaches `0x82107310`**, the dead dispatcher's own slot.
- **Neither is the walker.** `sub_823DE6E8` is a **fixed-address vtable setter** (`823DE708 lis r11,8206` / `823DE710 addi -11508` / `823DE714 stw r11,0(r31)`) that forwards our pointer to `sub_823DE568`. `sub_823E5B70` copies a fixed `0x8206xxxx` source with size 32 (`823E5B98 li r5,32` → `bl 823DA950`) and then **does dereference the registry pointer and test bit 28 of its first word** (`823E5BB0 lwz r11,0(r31)` / `823E5BB4 rlwinm …,mb=28,me=28`) — genuinely registry-aware, but **no variable indexing in its first 20 words**.
- **Why this is worth an entry:** the tempting finding was one read away from being written as "we found the walker", and it was false. It also means **task #22's cheap branch is spent** — the dispatcher's indirect route is not readable out of `generated/` by call-idiom grepping. F-219 named the correct escalation many sessions ago: **this needs the CFG, i.e. IDA, i.e. the user's `/mcp reload`.**
- **F-312 §3 — a wave-F1 claim now in doubt, do not inherit it silently.** Fleet wave F1 reported the sites at `0x823de78c/7b0/7d0` as "`lis r0` … overwritten before use → **dead, not references**." At those addresses the instructions are `lis r11, 0x82100000` + `addi r4, r11, 10092` — **live, feeding a call argument.** Either it looked at different instructions or it mis-tracked the register. Same failure mode as F-308 and F-309 §1. **Re-read before citing, and F-301 §2's `blr` histogram stays flagged subagent-sourced for the same reason.**
- **Objective status unchanged:** dispatcher dead, DPC producer dead, `MOVIE-CTOR`/`nGfx` 0, Path A banked at 3/4 full-buffer. **Not complete.** Remaining permitted moves are now all either an IDA session or a build+census on `sub_823E5B70` (option 3 in task #22) — the free-lunch phase of this inquiry is over.

## 2026-09-26 ~05:1x (F-311, **0 builds** — log counts + raw-byte scans) — **answers task #21, and answers it AGAINST my own hypothesis: F-218's zero IS measured. The non-exhaustive dichotomy was F-219's, not F-218's.** Ledger through **F-311**; next ID **F-312**.

- **F-310 §4 flagged a circularity (F-218 named `GFX-TABLE-DISP` as its own positive control). The flaw is real; the consequence I inferred was wrong.** Independent **fired** controls on this exact mechanism class already exist in the tree: `MSGCHAIN`=4 (`sub_823045E0`/`sub_822F38C0`, reached via table entries `0x8210DED8`/`0x8210DA98`) plus F-309's `DPC-SIBLING-CENSUS`≥12. A `PPC_FUNC` override is a **link-time substitution, not a per-site registration**, so those establish that this class of hook works. **`sub_821EBCF0` therefore genuinely never runs — a measured negative, not an unmeasured one.**
- **The actual gap is F-219's dichotomy.** All four `GFXDISP-CALLER` hooks print 0, and my own `bl`/`b` scan independently reproduces exactly those four sites (`0x821E742C`, `0x821F5B88`, `0x8269FA20`, `0x8269FE38`) — so within a direct-call model its branch holds. **But the dispatcher is itself a table member at `0x82107310`**, inside an ascending handler run `0x821072F0..0x82107330` (paired field `0x40002C05`, which recurs **51×** and also pairs with `821EBF38` four slots later). So the honest statement is **cold from its *direct* entry set; the indirect entry set is unmapped**, and F-219's own escape hatch — "escalates to the producer (needs IDA)" — is the branch actually selected.
- **Calibration that closes a tempting inference for good:** every function whose census **fires** here also appears **exactly once as a data word** with **exactly one** direct call site (`8242F870`, `823045E0`, `822F38C0` — all 1/1), the same profile as the dead dispatcher. **Table membership and caller counts have zero predictive value for whether a guest function runs.** F-309 §1, reproduced on an independent sample. Do not let "it's in the table" stand in for "it's reachable", or "few callers" for "dead".
- **Highest-value remaining unknown on the permitted path (new task):** **who walks the `0x821072F0..0x82107330` table?** It is the only route into `sub_821EBCF0` left. F-310 §3 already showed no absolute literal for that page exists anywhere in `generated/`, so a walker must be **handed the base as an argument** — which is a CFG question, i.e. IDA, i.e. still blocked on the user's **`/mcp reload`**.
- **Economy, deliberately:** task #21 was closed with grep counts and one scan, **zero builds**, because F-309's single build had already established the control pattern that generalises here. Two of the five self-corrections this session were likewise free. **The cheap move is usually to look for a control that already exists before manufacturing one.**
- **Objective unchanged and NOT complete:** GFx dispatch dead at both ends (dispatcher + DPC producer), UI containers decompressed and unconsumed, `MOVIE-CTOR`=0, garage not host-decoded.

## 2026-09-26 ~05:0x (F-310, raw-byte + `generated/` scans, no build) — ~~I corrected my own F-309 §4 within one entry, mapped the GFx dispatch table, and found that F-218's "terminal gate for `nGfx`" has never been measured.~~ **§4's "never measured" verdict is CORRECTED by F-311: it IS measured (MSGCHAIN=4 is an independent fired control); the non-exhaustive dichotomy was F-219's. F-310's handle-vs-msgid correction and §5's search-validation rule both stand.** Ledger through **F-310**; next ID **F-311**.

- **`0x40002204` is a KERNEL HANDLE, not a msgid.** F-309 §4 retargeted tasks #11/#12/#20 to "hunt broadcasts of `0x40002204`" — wrong. `src/gpu_device.cpp:11194-11198` (F-218) already calls the structure a **`{handler, kernelHandle}`** table with worked examples (`sub_824C6F08`→`0x40001905`, `sub_824C6F70`→`0x40003D03`). Xenon handles are `0x4xxxxxxx`, identical in shape to msgids — that is the trap. **Tasks re-corrected.**
- **What survives of F-309, all solid:** producer `sub_8242FD00` measured **0 entries** with a **fired control** (`sub_8242F870` ≥12 at ~60 Hz, `r3=40004D5C` = the boot worker's DPC queue); caller counts proven non-discriminating; **the queue is serviced and never appended to.**
- **Registry is real and large:** 1,124 consecutive `{0x82xxxxxx, 0x4xxxxxxx}` pairs, `0x82112728..0x82114A48` (~8.9 KB), justified by a base rate of **0.8 %** image-wide — 100 % over 1,124 is not chance. It contains `0x8210DED8`/`0x8210DA98`, and `gpu_device.cpp:11282,11287` names handlers reached via those that **demonstrably executed**, so the table is live data.
- **"No recompiled code addresses it" — true, not upgraded into a blocker.** `generated/`: 0 literals for pages `0x8211`/`0x8212`, 24 for `0x8210`; search validated (4,172 hits for a signed-`lis` form I had seen on screen). Benign explanation: dispatcher `sub_821EBCF0` likely **receives the table pointer as an argument**, so no absolute reference is expected.
- **THE ACTIONABLE GAP (task #21):** `GFX-TABLE-DISP` and `GFXDISP-CALLER` are **0 in `w193` and `w274`** — never observed once. F-218 nonetheless concluded "GFx handler dispatch never executes → the terminal gate for nGfx" and named **that same hook** its positive control. **Circular** — a hook that never fires cannot show it *can* fire, and F-100 says publish such a reading as *unmeasured*. So **F-217/F-218's conclusion is unproven, not proven-negative.** Fix = the F-309 method again: one build, hook the dispatcher **and** a proven-live neighbour, then interpret the zero.
- **F-310 §5 — read before writing another scan.** Three of my own searches gave confident wrong answers today before a known-present probe caught them: `[0-9A-F]{4}` against an 8-hex field (all zeros); **`\b` before a leading `-` never matches**, so I scanned 0 for a constant I had *just read on screen*; and a "non-null `arr`" predicate counting raw payload. **Run a known-present token through every new search and require it non-zero before letting any of its misses mean anything.** A zero from an unvalidated pattern is indistinguishable from a real negative.
- **No build, no boot this entry. `w274` is still the newest soak; goal NOT complete** (`MOVIE-CTOR`=0, `GFX-TABLE-DISP`=0 *unmeasured*, garage not host-decoded).

## 2026-09-26 ~04:5x (F-309, **BUILT + SOAKED `build/w274.log`**) — **first measured answer to a ~20-session-old claim, and it voids the evidence that claim rested on.** ~~Ledger through **F-309**; next ID **F-310**.~~ **§4's msgid retargeting is corrected by F-310 above; the rest of F-309 stands.**

- **Measured:** `sub_8242FD00` (KeInsertQueueDpc-shaped DPC appender) is entered **0 times**. `sub_8242F870` — the adjacent entry in the same registry table, added as the control — fires **≥12 times** at ~60 Hz. Same build, same neighbourhood, so the zero is real: **the producer has never actually been measured before now; it had no host hook at all**, so every prior "never runs" was a zero without a printer (F-057(6)).
- **The old evidence is void.** "Zero static `bl` callers ⇒ nothing posts the DPC" collapses under its own control: my raw-byte scan finds the **demonstrably running** place-pass `sub_825EF100` with exactly **1** caller and the **provably dead** `sub_822C0980` also with **1**. Caller count does not discriminate here — and `src/kernel/imports.cpp:1734` already said the function "is invoked via indirect dispatch", i.e. the refutation was sitting in our own comment.
- **New functional picture:** the control's `r3 = 0x40004D5C` is **the boot worker's own DPC queue context** (`W36b-QUEUE bwR26=40004D5C`; main thread waits on `40004D7C` = `r26+32`). So the queue is **serviced continuously at ~60 Hz while nothing ever appends** — F-269's "queue stays forever empty" is now split into a live consumer and a never-entered producer, which is why `qWrite=0 qRead=0 delta=0`.
- **⚠ Tasks #11/#12/#20 have been hunting the WRONG msgid.** The registry at `0x82113A90..0x82113ADC` (alternating `{handler, msgid}`, verified in `mcla_pe.bin`) pairs `8242FD00` with **`0x40002204`**, not `0x40003B03`. `0x40003B03` is paired with the gate `82131008` at `0x82102AC0` (F-301). So the missing broadcast is **`0x40002204`** — 76 data-word occurrences vs 65.
- **Next step + its trap:** find who broadcasts `0x40002204`. **`tools/ppc_xrefs.py` cannot do this** — `:136-148` never tracks `ori` (op 60), so `lis`+`ori` materialisation is invisible to it and its "0 sites" is not a negative. Needs a hand scan for the immediate, or IDA (still waiting on the user's `/mcp reload`).
- **Probe hygiene, because that is the standard here:** rule-4 clean before hooking (`addr_owners --check 0x8242FD00` → 1 site, map only, `RC=0`); exe verified moved (`57,110,528 → 57,114,624 @01:48`) **and** both literals grep-confirmed in-image before soaking (F-296's stale-exe trap); BOOT_RC=124; mcla.exe killed after; **zero frontier delta vs `w273`** (every structural marker +0, incl. `PATHB-HOSTDECODE` 5=5, `PATHB-HOSTVERIFY` 3=3, `LISTLINE` 171=171, `CP-DRAW` 166=166, `[error]` 28=28). New markers registered in `PROGRAM_GUIDE` §9 so `soak_census.py` tracks them — applying the F-307 blind-spot lesson in the same session it was learned.
- **Caveats:** `r13=005A0260` is not a guest-shaped TLS value, so my `cpuArr + idx*80` arithmetic is untested (moot at 0 firings); and this is one 120 s boot — "the guest never reached this broadcast in this boot", nothing stronger. **`w274` outcome unchanged: `MOVIE-CTOR`=0, `nGfx`=0, `UILOAD-census`=0. Goal NOT complete.**

## 2026-09-26 ~04:4x (F-308, existing logs + one `grep`, no build) — **I refuted my own F-307 an hour after writing it. Path B's permitted scope is now exhausted, branch by branch, and the objective is NOT achieved.** Ledger through **F-308**; next ID **F-309**.

- **`[arr]!=0` was measuring our own patch, not the guest.** The "resolution" F-307 treated as lost guest progress was written by host mitigation `W30-ARR-FIX` (`src/gpu_device.cpp:5408`): `arr=00000000->B7B6D9B4 cnt 0->1 arr[0]=B7B41000` onto a buffer that `J2-DIST-ARR` (`w193:13819`) shows is all `CDCDCDCD` fill-on-alloc. **F-307's "the guest achieved this 7 times" is false — the host achieved it 2 times.**
- **The decisive negative, which is why this is a closed door rather than a retraction:** in `w193`/`w248` where it resolved **7** times, `UILOAD-census`=**0**, `MOVIE-CTOR`=**0**, `nGfx`=**0** — byte-identical outcome to `w270`/`w273` where it resolved **0** times (`GFXINIT-census`=1 in all five, so not a boot-depth artifact). **The fabricated descriptor never advanced GFx.** Restoring it is also a forbidden technique (`:9737` "Never invent vtables or FEX over live dests").
- **Durable rule, cheaper than the four corrections it took:** *a counter printed from a hook on a **guest** function can still be reporting **host**-written bytes.* Before citing any counter as frontier progress, grep its field names against the `Write*` calls targeting the same guest offset. `W30-ARR-FIX` is one of the 64 mitigation labels `tools/mitigation_audit.py` reports as **unregistered** in §7 (F-047) — that gap is why nothing flagged the overlap. Pairs with F-302's `nGfx` finding: **twice this session the counter we were gating on was not the thing we meant.**
- **Path B, all four permitted branches now closed:** (a) F-300 consumer repoint → dead (F-304); (b) F-305/306 descriptor ABI → decoded, region table materialized *correctly* (F-307 §1); (c) F-307 "restore the array" → our own fabrication (F-308); (d) Path A → delivered and exonerated from (c) by pre-existing flag-off logs. **There is no remaining untested permitted lever on the UI `.xsf` → GFx chain.**
- **The one axis left is characterization, task #20:** why does `sub_8242FD00` (presumed producer of msgid `0x40003B03`) have zero callers, when F-271 shows the ring consumer works? Read-only, no build, and **it must not end by crossing rule-2 or F-055** — if it concludes those walls are required, that is a question for the user, not a licence.
- **Completion audit, stated plainly (F-308 §5).** Objective deliverable 1 (evaluate Path A + Path B, `file:line` plan) — **done**. Deliverable 2 (UI `.xsf` decompressed in guest memory = the user's finish line (a)) — **met, full-buffer-proven, 3/4**. Deliverable 3 ("**so GFx can initialize**") — **NOT met** (`MOVIE-CTOR`=0, `UILOAD-census`=0, `nGfx`=0). Deliverable 4 (garage) — **not host-decompressed**, approach closed NOT-VIABLE (F-303). **Goal is NOT complete and was not marked complete.** Four commits this session: `1614bd8`, `0d59d12`, `ffca200`, `2613689`, `34842d2`.

## 2026-09-26 ~04:3x (F-307, existing-log comparison only — no build, no boot) — ~~the container-descriptor regression is real…~~ **SUPERSEDED by F-308: `[arr]!=0` was counting our own `W30-ARR-FIX` mitigation, and the boots where it fired had identical zero GFx signals. F-307 §1 (F-306 retraction) and §4 (census blind spot) STAND.** Original block follows. Ledger through **F-307**; next ID **F-308**.

- **F-306 §2 retracted.** My "host writes `size` where the guest wants `end`" mismatch was a **mis-attributed register**, not a bug: `MclaPublishGuestRebaseTable` (`src/gpu_device.cpp:4074-4102`) matches the guest's header shape exactly (`nmap<<16` → the two summed `lhz` at `8217D838`) and its stride (`+4`, ×12 = `8217D878`), and the table publishes 7× in `w273` with **`Invalid fixup` = 0** — the very symptom a malformed table produces. Third self-correction of the session, second from the same failure mode (half-read trace → confident claim). **What finally works: find the marker that fires if the structure is wrong, and count it.**
- **THE METRIC: `FDBF8-BUILD` lines whose `[arr]` dereference is non-zero.** Layout-independent, and it means "the container's entry array resolved". `w193` **7/9**, `w248` **7/9**, `w251`/`w258` 3/5, **`w257`/`w264`/`w269`/`w270`/`w271`/`w272`/`w273` = 0**.
- **The Path-A-displacement hypothesis died without a build.** I proposed the control in F-307 §5 and ran it against logs that already existed: **`w269`/`w270` have `PATHB-HOSTDECODE=0` and already sit at `[arr]!=0` = 0.** So Path A neither caused the loss nor is expected to restore it. F-307 §7 also flags that the window is **confounded** — `w257`/`w258`/`w264` were F-285/286/288 experimental variants, not sequential mainline builds, so no clean bisection exists across it.
- **Two metric traps I created and then fixed, recorded so nobody re-uses them:** (a) `arr=B7B6D9B4` is **address-coincidental** (F-297 §2 already proved dests move between boots, so it measures "landed where w193 landed"); (b) "non-null `arr`" is **junk** — `003100CB` is non-null raw payload. Two of my own regexes were also silently broken before I caught them (a `{4}` quantifier against an 8-hex field matched nothing, producing an attractive column of zeros): **a zero from a mis-specified pattern looks exactly like a zero from a real negative** (F-089 §6, re-run by me).
- **Census blind spot fixed (docs-only).** `soak_census.py` derives its tracked set from PROGRAM_GUIDE §7/§9, and `FDBF8-BUILD`/`RSC-PLACE-ARR-GATE`/`REBASE-TABLE` were in **neither** — which is how F-297 could report "every structural marker +0 vs w270" while this went 3 → 0. They now have a §9 row carrying the read-`[arr]`-not-`arr` warning. **Any future "no regression" claim is scoped to the tracked set.**
- **Net for Path B:** the target is no longer "invent a descriptor" (which `gpu_device.cpp:9737` forbids anyway) but **"restore a resolution the guest achieved 7 times in `w193`"**. Task #19 rewritten to that. **Goal still OPEN** — decompress 3/4 banked, `[arr]!=0` = 0, `MOVIE-CTOR` = 0.

## 2026-09-26 ~04:2x (F-306, `grep`/`sed` + `w273` marker counts, no build) — **F-305 step 1 is ANSWERED, and it rules out the easy explanation.** ~~Ledger through **F-306**; next ID **F-307**.~~ **F-306 §2's field-role mismatch is REFUTED by F-307 §1 above; §1/§3/§4 (directory identified, table published for `sub_8217D890`, 17 arm sites, dead-marker warning) all stand.**

- **The extent directory `sub_8217D890` searches is the job readlist's `{vbase, pbase, size}` triplet — and the host already materializes it into guest memory for that exact consumer.** `src/gpu_device.cpp:9890` `struct Reb { uint32_t vbase, pbase, size; }`, read at `:9896` as `slotAddr + 4 + si*12` (**12-byte stride, three BE u32** — same shape as the guest's `8217D878 addi r10,r10,12`), count from `slotAddr+1540`, and the comment at **`:9909` literally says "Publish for sub_8217D890 / sub_82184458"**. `MclaArmRebaseCtx` (`:4074-4100`) writes `e+0/e+4/e+8`. **So Path B does not need a table discovered or invented — it needs the existing published one reached with a valid cursor.**
- **"It's never armed" is NOT the explanation: 17 arm sites** (`:5418, 5690, 5859, 7090, 7273, 8200, 8259, 9844, 10040, 10103, 10159, 10212, 10364, 10440, 10489` + def `:4108`).
- **My grep for `REBASE-ARM`/`REBASE-CTX` returning 0 means NOTHING** — those strings are mine, not markers this tree prints (`MclaArmRebaseCtx` may be silent by design). Cited here only to forbid a future session reading it as a negative. That is the F-057(6) dead-marker trap, and I fell into it in the same breath as documenting it.
- **The decisive open question, which I am NOT resolving by guessing (F-305 §7 discipline): field roles don't reconcile.** If the host writes `{vbase, pbase, size}` at `+0/+4/+8` and the guest returns `entry[+8] − entry[+4]` (`8217D8C8/CC/D0 subf`), the "length" is **`size − pbase`** — nonsense for an absolute `pbase`, and FDBF8 then does `[obj+12] += `it. So either my register mapping at that instruction window is wrong, or `MclaArmRebaseCtx` materializes with the **wrong field roles**, or `sub_8217D890` isn't the function `:9909` claims. Pinning this needs the *caller's* search key (`r4`) traced through FDBF8 — raw-byte work, no build.
- **Net:** Path B narrowed from "build a descriptor" to "reconcile two struct definitions and then supply the cursor the preload task never wrote." Task #19 carries it.

## 2026-09-26 ~04:2x (F-304/F-305, main-agent raw-byte work — no build, no boot) — **I was wrong about my own F-300, and now the Path-B target is decoded.** Ledger through **F-305**; next ID **F-306**.

- **F-304 supersedes F-300 §2.** The "sibling container was consumed" evidence I cited (`w273:6460`) is a **destructor**: `sub_825FB0D8` is "the swf-container family destructor" (`src/task_dispatch_trace.cpp:1138`), and **20 of 20** hits in `w273` are `POISON-SKIP` with `+4=CDCDCDCD +12=00000000`. A vtable stamped on a CDCD body is the *failure* case, not success — dispatching through it AVs at `825FB14C`. **My grep confirmed the line existed; it did not confirm what the line means.** I read a marker without reading its printer.
- **F-304 §3 also kills the repoint idea outright.** `FDBF8-ARR-RESTORE` = **0** hits (gated by `realVt` at `src/gpu_device.cpp:9851`, and `B7B41000`'s `vt=003300D9` fails it); `PLACE-ARR-RERUN-DONE` = **0**; `RSC-REBASE-PREPLACE-DONE` fires 3× with `nmap=7` but **`headRewritten=0 childRebased=0 childGate=0`** — the existing machinery already runs and replaces nothing. Repointing it at the decoded dests would have inherited a dead path and produced a null result I would have mis-attributed.
- **F-305 decodes the swfC container ABI from `build/cache/mcla_pe.bin` with `tools/ppc_disasm.py`** (rule 3, no IDA needed — the `/mcp reload` is not a blocker for this): `[obj+0]` vtable, FDBF8 stamps `0x8208521C` (`825FDC10 lis r11,8208` + `825FDC14 addi r10,r11,21020` + `825FDC18 stw r10,0(r31)`), place-pass stamps `0x82085364`; **`[obj+12]` is a CURSOR that FDBF8 advances by a LENGTH** (`825FDC34 add r10,r3,r11` where `sub_8217D890` returns `table[idx].+8 − table[idx].+4`, see `8217D8D0 subf r3,r9,r10`); `[obj+16]` is a **`lhz` u16** count; entries are **stride 8**, each handled by `sub_8260A830`. `sub_825FDA90` is a 9-way switch on a **u8 tag at `[rec+8]`**, tags 1-8 valid, **tag 2 recurses into FDBF8 (nested containers)**, invalid → error object `0x82087180`.
- **The single most useful sentence, from the project's own comment:** `src/task_dispatch_trace.cpp:1071-1073` — the container's `[+12]` array "stays CDCD **when the preload task never fills it**". That is the F-186/F-187 **enqueue gap restated in ABI terms**, and it is why a null `+12` makes FDBF8 skip the whole consume (`825FDC20 cmpli cr6,r4,0000` → `825FDC3C`). The objective's Path B is now precisely: **supply the cursor + 8-byte entry array + u16 cnt the preload task would have written, pointing into payload Path A already placed byte-exactly.**
- **F-305 §7, and read this one literally.** Item 2 first went down as a confident claim — "the array is *relative*, that's the whole ballgame" — from a **half-read** disassembly: I had the `add` but had not opened the callee to see what it added. Finished the trace, it was a length, and the claim died. **Had I committed the draft, the next session would have "fixed" `gpu_device.cpp:9826` from absolute to relative and broken a line that is already correct in kind.** `kArrCand[]` is wrong because it *guesses*, not because it writes an absolute value.
- **Next (task #19, rescopied):** read-only — identify the 12-byte-stride **extent directory** `sub_8217D890` searches (`sub_8217D828`: header = two summed `lhz` counts at `+0`/`+2`, stride 12 at `8217D878`, key matched against `entry+0` or `entry+0 + entry+8`) and whether any entry covers the decoded UI payloads. No build, no boot. **Gate on `MOVIE-CTOR` (`src/task_dispatch_trace.cpp:1526`) plus a NON-`POISON-SKIP` `FDBF8-BUILD` line — never on `nGfx` (F-302).**

## 2026-09-26 ~04:0x (F-300..F-303, fleet wave F1 — 4 READ-ONLY research subagents, no build/no boot) — ~~the decompress deliverable is unchanged, but three things the objective believed about what remains are now wrong, and one permitted lever nobody has tried surfaced.~~ **SUPERSEDED ON TWO POINTS by F-304/F-305 above: F-300's sibling-consumption evidence was a destructor, and its repoint plan is dead. F-301 (data table, not unmapped code) and F-302 (`nGfx` is a weak instrument) and F-303 (garage host-fill not viable) all stand and were re-verified by hand.** Original block follows. Ledger authoritative through **F-303**; next ID **F-304**.

- **Read this block first if you are picking up task #12 or #18 — both are mis-scoped.** Task **#18 (T41.11, garage multi-window host fill) is CLOSED NOT-VIABLE (F-303)**: the guest's own source cursor never leaves frame 0 (`src/gpu_device.cpp:8074-8079` — once `consumed == srcSize`, neither branch assigns and `srcOff` falls back to `ls.pos = 0`, so it re-serves the same 32 KiB bounce forever), and its 52 readlist slots **clobber** each other (`w272:4433` vs `:4490`: same dest `B7809000`, same `destSz(in)=229376`, both drained to 0). A host write to slice *k* is overwritten. Also: the "128 KiB streaming band" in F-298 §3 was a **default** (`MclaDestCapFromPstream`, `:7515-7529`), not a measured window.
- **Task #12's TITLE is a category error (F-301).** `0x82100000..0x8212FFFF` is not unmapped code awaiting recompilation — it lies entirely below `PPC_CODE_BASE = 0x82130000` (`src/ppc_config.h:14`) and is a **message-subscription data table**: raw BE words I verified myself, `0x82102AC0=82131008 | 0x82102AC4=40003B03 | 0x82102AC8=821310F8 | 0x82102ACC=40002A03` (alternating handler↔msgid). **Recompiling it would emit ZERO functions, so rule-2 could never have been the fix.** F-270's mechanism is falsified by the bytes: the word at `0x82119C04` is `0x40017406`, another msgid, not a jump-table row. And "unmapped at runtime" came from a **function-name-lookup string** (`src/boot_host.cpp:376`); guest memory is one 4 GiB `PAGE_READWRITE` `VirtualAlloc` (`:292`), and handlers reached *via* two entries inside this window (`gpu_device.cpp:11282,11287`) actually executed. What is left is **producer-side only**: `sub_8242FD00` has 0 callers.
- **`nGfx` is the WRONG GATE for the next experiment (F-302) — this is the trap that has been reading us for weeks.** The scan reads only 4 bands (`src/gpu_device.cpp:6216-6217`: `A0000000-A0800000`, `C5000000-C6000000`, `C7000000-C8000000`, `CA000000-CB000000`), and every live object observed is outside them (`C60AC100` sits in the *hole*, `CB248B00` above the last band, the three UI dests in none). Its predicate needs `0x82073xxx`, but the ctor `sub_82482008` re-types `[obj+0]` to `0x8206DFAC` (our own **F-044 §1**, `stw r9,0(r3)` at `0x82482028`) and `0x8206DFAC & 0xFFFFF000 = 0x8206D000` — so a **finished** loader is invisible by construction. **Use `MOVIE-CTOR` (`src/task_dispatch_trace.cpp:1526`) instead.** F-044's headline still holds (`MOVIE-CTOR`=0 independently), so this narrows the metric, it does not overturn the conclusion.
- **THE LEVER (F-300, task #19, P0 — the only permitted untested route to the resource graph).** F-297 made the *decoder* dynamic per user directive #5; the **consumer never changed**. `constexpr uint32_t kUiCont = 0xB7B41000u` (`src/gpu_device.cpp:9721`) is still what gets fed to the guest's own ROOT place-pass at `:9849`/`:9861` — and in `w273` that dest holds **garbage** (`:6918 vt=003300D9`), while the three decoded containers never appear as `obj=`/`child=` of anything (0 hits). The mechanism is **proven on a sibling**: `:10390-10395` says `sub_825EF100` run as ROOT converts a `44495500` head into a live object (`childVt=82085364`), and `w273:6460` shows it happening to `B7521000`. Generalising the drive to the `g_uiDecExpect` dest set (`:365`) is **not rule-2, not F-055, not a serve/inflate/rebase short-circuit** — same guest function, different argument. Flag-gate it; record the revert.
- **Attribution honesty (do not skip).** All four findings are from subagents and every line-number and raw word I relied on was **re-read by me** before this entry was written; F-301 §2's `blr` histogram and F-300 §4's "this could move `nGfx`" are marked UNVERIFIED in the ledger and are NOT conclusions. F-300 also weakens **F-297 §5**: that "decompress is necessary but not sufficient" was derived from an experiment where the consumer was pointed at a fourth, garbage dest — so it is a narrower result than it was written as. **Goal still OPEN**: decompress 3/4 banked, `MOVIE-CTOR`/GFx init not reached, garage still guest-side.
- **Tooling state this session:** `Superpowers` plugin v6.3.0 (Jesse Vincent, official market) installed user-scope → `C:\Users\abdul\.qoder\plugins\cache\qoder-marketplace\superpowers\6.3.0`, 14 skills, registry-confirmed. It registers a **synchronous `SessionStart` hook** (`hooks/hooks.json`, matcher `startup|resume|clear|compact`) that injects ~5 KB of imperative skill text into **every** session including on compaction — costs context on a tree whose AGENTS.md is already token-conscious; disabling just that hook is a reasonable user call. `ida-pro` and `renderdoc` are declared in `.qoder/settings.json` and their backends are **healthy** (`ida-bridge.py` present; `python -c "import renderdoc_mcp"` OK from `C:\Python314`) but **neither is connected** — a `/mcp reload` (user-side trust prompt) is required; I cannot approve it.

## 2026-09-26 ~00:27 (F-299, funded Path A — BUILT + SOAKED `build/w273.log`) — the milestone is now verified at **full-buffer content** level, closing F-298's 16-byte caveat. Committed `1614bd8`.

- **What was added:** a one-shot whole-buffer residency probe. `UiFnv1a` (`src/gpu_device.cpp:350`) + `UiDecRecordExpect` (`:365`) digest the decoded body **at write time**; `UiDecVerifyReadback` (`:4028`) later re-reads `unc` bytes from the dest through the checked `GuestMemoryHeap::ReadBytes` (`src/guest_memory.h:27`) and re-digests them. Wired at both decode-write sites (`:7880` top hook, `:9068` corrupt-serve) and called from the `D2308-buf` census site (`:9680-9681`). Log-only, one-shot per dest, no behaviour change.
- **Result — 3/3 `match=true` at full length:** raceeditor `unc=143069 want=got=CF1690FDD7A0AF30` (`w273:3949`), policecam `unc=19337 E7513DE33D27FF22` (`:14772`), credits `unc=29655 22A0999B16E5AAC4` (`:15240`), at **+35 / +27 / +9 ms** after their writes (`:3218`/`:13850`/`:14973`). Three distinct lengths, three distinct digests — not a degenerate hash over zeroed memory. Chained with `check_xmem_lzx` 4/4 `EXACT` (F-297 §8), the claim is now: the decoder reproduces the goldens offline **and** guest memory holds those bytes at full length in a live boot.
- **The probe has a built-in negative control (why its `true`s mean something):** `D2308-buf` censuses **seven** dests in `w273` but `PATHB-HOSTVERIFY` prints **three**. Garage's `B7AC1000` is read at `:13423` — 261 ms after the host *skipped* it (`:4282`) — and correctly stays silent, because no expectation was recorded for a container the host did not write. A blanket-firing probe would be worthless.
- **Zero frontier delta (F-125/F-133, the precondition for citing a new instrument):** vs `w271` every structural marker is **+0** — `C0000005` 0=0, `Fatal error` 1=1, `LISTLINE` 171=171, `GFXINIT` 1=1, `PRESENT` 34=34, `SUBMIT` 56=56, `CP-DRAW` 166=166, `DRAW_INDEXED` 0=0, `SEEK-DEAD` 0=0, `PATHB-HOSTDECODE` 5=5, `INFLATE` 14,489=14,489, `[error]` 28=28, CP truth identical. Only movers: the new marker (3 vs 0), the poll-count substrings `rptrWB`/`PUT=`/`WAIT`/`WAKE` +6, `PARK-SAMPLE`/`PARK-STACK` −2, warning lines 36,797 vs 36,798. vs `w193` the deltas are exactly F-297's.
- **Build evidence is the exe, not a log** (`build/f298v_build.log` is 0 bytes): `build/mcla.exe` moved 57,101,312 → **57,110,528 @00:27** and both new literals were grep-confirmed in-image *before* soaking — the F-296 stale-exe lesson applied.
- **Registered, and correctly classified:** `PATHB-HOSTVERIFY` has a §9 row and is named in the §7 `kPathBHostFullDecode` paragraph. `tools/mitigation_audit.py --label PATHB-HOSTVERIFY` → `[other-shaped]`, `sec 7: yes`, `gpu_device.cpp:4041` — the audit does not treat it as a short-circuit, which is right (it gates nothing). Its rc=1 is the pre-existing F-047 §7-vs-src gap (25 vs 89), unchanged.
- **Still NOT proven (F-298 caveats 5b/5c stand):** this is a *host* read, so residency is proven and guest dereference is not (`D2308-INS-SKIP … not rgxa`, `PLACE-44495500`=0); all three verifies are in the first ~1 s of a 120 s boot; and the digest covers `unc` bytes, so a dest's slack past the container is unverified — `match=true` ≠ "the whole 256 KiB window is golden".
- **Goal state: still OPEN, correctly.** `nGfx`=0 on all six `W34-GFX-CENSUS` prints, `XSF-INFLATE` 0, run ends in the `WAIT[KWFSO] obj@40004D7C … lr=8242FC1C` poll. The user's milestone (directive #1, finish line (a)) is met for 3/4 with full-buffer evidence; garage is T41.11 (#18, user-deferred); rule-2 / F-055 stay off-limits (directive #2). Do NOT mark complete.

## 2026-09-26 ~00:2x (F-298, existing-log verification — NO build, NO new instrumentation) — the F-297 milestone is now verified at **guest-memory content** level, and T41.11 (garage) is materially narrowed. ~~Ledger authoritative through **F-298**; next ID **F-299**.~~ Superseded on the ledger line by F-299 above. Nothing in `src/` changed in this block; the F-297 follow-up is committed as `1864589`.

- **Why this entry exists:** F-297's chain proved (a) `host_decode_ui_xsf` is byte-exact vs golden *offline* (`check_xmem_lzx` 4/4) and (b) the host *issued* a `WriteBytes` of N bytes that returned true. Neither proved the bytes were **still resident in guest memory** — the guest's own executor could run further windows over the dest (F-278/280 first-window behaviour), or the peer's `kInflateIntervene` re-point could re-serve into it. Verified with instrumentation that already existed, so no build and no zero-frontier-delta proof was needed (F-125/F-133: a new log line is itself a variable).
- **The readback:** `DumpBufHead` (`src/gpu_device.cpp:3986-3994`, 4 BE dwords via the checked `ReadU32BE`, log-only), called as `D2308-buf` at `:9622`. raceeditor `@B7B01000 44495500 50036570 00706164 5004B2B4` (`w271:3981`/`:3983`, **+126 ms** after the write at `:3224`); policecam `@B7441000 … 50013690 … 50015304` (`:14985`, **+26 ms**); credits `@B74E1000 … 500140F0 … 50024884` (`:15480`, **+8 ms**). Each equals its `build/xmem_golden/*.bin` head. **The discriminating part is `w[1]`/`w[3]`** — four distinct per-container pointer pairs; `w[0]=44495500` and `w[2]=00706164` are shared by all four and alone would prove nothing. `w272` reproduces all eight `BUF-HEAD` lines.
- **NEW and actionable for T41.11: garage's first window is ALREADY byte-correct from the guest's own inflate.** `w271:13682` `BUF-HEAD D2308-buf @B7AC1000 44495500 5004E230 00706164 500B1B14` == `garage.bin` head, read **261 ms after** `PATHB-HOSTDECODE-TOP-SKIP #86 … room=262144 → guest` (`:4296`). So the F-297 `fits` refusal was correct (a full write would overrun a 256 KiB dest; a truncated one would replace valid guest output with the same bytes), and **T41.11's gap is bytes ~262,144→1,066,057, not the container from zero.** The dest is a **streaming band**, not one buffer: `JOB2-PKG-SERVE … dest=B7AC1000 destCap=131072` (`w272:4295`) with `INFLATE-REFORCE #1..#12` walking `outPtr` `B7AF1000`→`B7801000`→`B7809000`→`B7841000`→`B7851000` (`w272:4311`-`:4596`) ⇒ no hook instant has 1,066,057 bytes of room, and a progressive fill must map each band slice to its blob offset. That sits beside the peer's load-bearing `kInflateIntervene` re-point (F-194) — **do-not #9: do not stack a second re-point.**
- **Consumer-side corroboration of the `nGfx` verdict:** `PLACE-44495500` (real printer, `src/task_dispatch_trace.cpp:572`) = **0** in `w272`, and every decoded buffer is classified `rgxa=no` → `D2308-INS-SKIP #1/#3/#4 … not rgxa (preload pack); AFB76-FALLBACK will serve rage_im`. Correct: a UI `.xsf` is not an rgxa effects pack. So three byte-exact UI containers sit resident with nothing arming them — F-297 §5 seen from the consumer side. Two further `BUF-HEAD` hits (`@B7521000`, `@B5049000`, both `44495500 50023DE0 00706164 5006C9B4`) are a **different, non-UI** container — do not mistake them for a fifth UI dest.
- **Bounded caveats (do not over-read):** 16 bytes per container, not the full 143,069 / 19,337 / 29,655 — whole-buffer residency is inferred from `WriteBytes`==true plus the head surviving, not measured (a full check needs a new readback+hash probe and its own frontier-delta proof). `DumpBufHead` is a **host** read, so residency is proven, guest dereference is not. All eight `BUF-HEAD` lines fall in the first ~2 s (last 23:45:21.565 vs soak end 23:55:47), so nothing speaks to survival at the 5-minute mark.
- **Goal state: still OPEN, correctly.** `nGfx`=0; the user's milestone (directive #1, finish line (a)) is met for 3/4 with content-level evidence; garage is T41.11 (#18, user-deferred); rule-2 / F-055 stay off-limits (directive #2). Do NOT mark complete.

## 2026-09-25 ~23:50 (F-297, funded Path A) — SUPERSEDES the "BLOCKED NEXT STEP / environmental boot regression" line in the ~16:20 block below. **Boot is recovered, the milestone is met for 3/4 containers, and the work is COMMITTED (`d7da233` + the F-297 follow-up).** `kPathBHostFullDecode=true` is now the SHIPPED DEFAULT (user decision 09-25: "e is healthy again, make it as deafult").

- **What changed since F-295/F-296:** (1) the hook no longer keys on literal dest addresses — `PeekPackageForDest(outPtr)` reads the serve path's own `g_destPkgOff` map and `IsUiXsfPkg(off)` allowlists the four stable *package offsets* (`src/gpu_device.cpp:311-345`, used at `:7775-7856` and `:8944-9010`); (2) a container is only marked complete when the WHOLE decoded body fits the dest room (`decH.size() <= outLeft`, `:7817`/`:8998`), so garage is now refused (`PATHB-HOSTDECODE-TOP-SKIP … → guest`) instead of being completed with a truncated 262144-of-1066057 tail (the f298 bug); (3) `tools/xmem_lzx_test.cpp` is wired as a CMake build-artifact check (`CMakeLists.txt:479-494`) — `ninja -C build check_xmem_lzx` → 4/4 `EXACT`, `PASS (0 failures)`, never linked into `mcla.exe`, never a soak dependency.
- **Result (`build/w271.log`, 120 s, BOOT_RC=124, 57,962 lines; confirmed by `build/w272.log`, 300 s, BOOT_RC=124, 80,278 lines, same five decode lines and no late change): 3/4 UI `.xsf` byte-exact in guest memory** — raceeditor `PATHB-HOSTDECODE #1 off=64CB0000 decoded=143069 wrote=143069 dest=B7B01000 ok=true` (`w271:3224`), policecam `PATHB-HOSTDECODE-TOP #977 dest=B7441000 unc=19337 wrote=19337 ok` (`:14111`), credits `#1002 dest=B74E1000 unc=29655 wrote=29655 ok` (`:15204`); garage left to the guest (accepted scope, user directive #3). policecam+credits decoded in-emulator **for the first time**.
- **No structural regression on either baseline.** vs `w270` (same-tree prior): every tracked structural marker +0, with `INFLATE`/`INFLATE-ENTER`/`skip fatal`/warning-lines all DOWN. vs `w193` (the objective's gate): `C0000005` 0=0, `DRAW_INDEXED` 0=0, `SEEK-DEAD` 0=0, `LISTLINE` 171=171, `GFXINIT` 1=1, `REBASE-POISON` 37 vs 153, host short-circuit lines 1,313 vs 43,639; `Fatal error` 1 vs 0 is the pre-existing `grmShaderGroupVar` soft fatal (`:42830`, task #16), not a new one. The lower line count is churn reduction, not a shallower boot.
- **`nGfx` STILL 0 — re-confirmed on 3/4 coverage.** `W34-GFX-CENSUS #1..#6 nGfx=0`, `XSF-INFLATE` 0, `UILOAD-census` 0. **H-trap for the next session:** `soak_census.py`'s `UILOAD` row reports 6, but that is the *substring* inside the `W34-NOGFX` text ("UILOAD/EF220 never armed"); `grep -c UILOAD-census` is 0 in `w271`/`f298`/`w193`/`w270`. Do not read that row as `sub_822012E8` firing.
- **F-296's environmental regression is gone.** A clean reconfigure forced a full 227/227 rebuild → exe **57,101,312** (vs 97,6xx,xxx incrementally linked); all five Path A marker literals verified present in the image *before* soaking, then it booted fine. The "stale incremental object" half of F-296's hypothesis was the operative one.
- **Attribution honesty:** dynamic keying and the no-truncation rule shipped together, and the discriminating control (hardcoded + no-truncation, exe 97,662,464 @23:17) was never soaked — so which of the two lifted coverage 1/4→3/4 is **not separately measured**. The no-truncation rule is the likelier cause (it is the only one that can let the streamer proceed past garage).
- **Tree state:** `kPathBHostFullDecode=true` (DEFAULT), `kPathBEnqueueUI=true`, `kJ2DistReplay=true`, `kHostLzxDecode=false`, `kXcWindowBits=17`. COMMITTED `d7da233` (Path A decoder + ledger F-188..F-296 backlog); F-297's dynamic keying + CMake check + ledger entry are the follow-up commit `1864589`. Ledger authoritative through **F-306** (see the blocks above); next ID **F-307**. Remaining open: **task #19 (F-306 — reconcile the `MclaArmRebaseCtx` vs `sub_8217D890` field roles, then supply the `[obj+12]` cursor / 8-byte entry array / `+16` cnt the preload task never wrote)**, the producer-side question retitled from #12 (#18/T41.11 CLOSED NOT-VIABLE by F-303; F-300's repoint retired by F-304), and the user-closed GFx wall (#12/#15 — rule-2 and F-055 stay off-limits; F-301 shows #12's stated mechanism never existed).

## 2026-09-25 ~16:20 (F-295/F-296, funded Path A) — SUPERSEDES the "(2) host LZX is dead / research-grade" line in every block below. **Path A is DELIVERED and byte-exact.** A self-contained host XMem/raw-LZX decoder now exists at `src/xmem_lzx.h` (`mcla_lzx::host_decode_ui_xsf`); the offline standalone test `tools/xmem_lzx_test.cpp`→`build/xmem_lzx_test.exe` is **4/4 byte-exact** vs `build/xmem_golden/{raceeditor,garage,policecam,credits}.bin` (garage golden newly written). Corrected recipe (authoritative in `tools/xmem_decode.py`): RSC5 header, wb17; **two DIU(`44495500`)-validated paths** — (1) single raw-LZX stream at `pkg+0x16` (raceeditor/policecam/credits), (2) shared per-frame RSC5 walk from `pkg+0x14` for garage (33 frames, `block_remaining`/window/R0-2 carry across frames). The F-294 "concat payloads into one stream" guess was WRONG (mis-parses the single-stream files). **In-emulator PROVEN (build/f295.log, flag-ON corrupt-serve):** `PATHB-HOSTDECODE #1 off=64CB0000 path=1 decoded=143069 wrote=143069 dest=B7B01000 ok=true`, `C0000005=0`, **every structural frontier marker +0 vs w270** — a UI `.xsf` FULLY decompressed into guest memory by a pure host decode, with NO guest-VM re-entry ⇒ this SIDESTEPS the whole F-288/290/293 corrupt-serve re-entrancy conflict that blocked every prior full-decompress attempt. Wired under `kPathBHostFullDecode` at the corrupt-serve (`gpu_device.cpp:8856`) AND a unified four-dest hook (`:7723`, keys B7B01000/B7AC1000/B7441000/B74E1000→their pkgoffs) — **that literal-dest keying is superseded by F-297's dynamic mapping.**
- **nGfx STILL 0 — this is the key negative result.** Full decompression of a UI container is NECESSARY but NOT SUFFICIENT: GFx init is gated UPSTREAM of UILOAD (msgid `0x40003B03` producer region `0x82100000..0x8212FFFF` unmapped + the systemic resource-serve place-pass livelock, task #15). That is the wall the user CLOSED ("STOP AT THE WALL"). So the F-186/187 *decompression* deliverable is MET; the *so-GFx-initializes* end-state is a separate, user-gated blocker. **Goal correctly OPEN — do NOT mark complete.**
- **BLOCKED NEXT STEP (an ENVIRONMENTAL regression, NOT a code bug — F-296):** since ~16:0x the emulator self-exits at `[boot] kernel heaps` (`boot_host.cpp:1403`) before XEX load (`:1438`), ~6 s, rc 0, no error line. Reproduces on the flag-OFF build whose exe is **byte-identical in size to the f293r baseline (97,628,672, both host-decode branches dead-code-eliminated)**, though f295 booted to 58,895 lines at 15:48. No peer edits (git status: only `src/gpu_device.cpp`+`src/xmem_lzx.h`), game_data+cache readable, no held procs, 697 G free — matches [[project-e-volume-failing-2026-09-24]]. **To validate the four-dest hook (all 4 decompressed in-emulator + the F-295 goal "soak census vs w193"): first recover boot (clean reconfigure+rebuild; if flag-OFF baseline still dies at kernel-heaps, it's the E: volume → copy game_data / relink on healthy storage), then set `kPathBHostFullDecode=true`, rebuild, soak, grep `PATHB-HOSTDECODE-TOP` for all 4 dests.** Do NOT conclude the decoder is broken — offline 4/4 stands; only the soak is blocked.
- **Tree state:** `kPathBHostFullDecode=false` (shipped safe; flag-OFF exe == baseline). `kPathBEnqueueUI=true`, `kJ2DistReplay=true`. UNCOMMITTED: `src/gpu_device.cpp` (modified), `src/xmem_lzx.h` (new), `tools/{xmem_decode.py,xmem_lzx_test.cpp}` (new), `build/xmem_golden/garage.bin`, ledger F-295/F-296. Ledger authoritative through F-296; next ID F-297.

## 2026-09-25 ~ (F-270→F-288 session consolidation; SUPERSEDES the "A decompress DONE" claim in the F-269 block below — it was an over-claim) — the F-186/187 decompress deliverable is PARTIAL (all-4 first-window), a full-decompress engine is proven but experimentally NOT applicable in-boot, and GFx (nGfx) remains walled. Do NOT re-try the proven-dead paths listed below.

- **Decompress = PARTIAL, not DONE (corrects F-274's over-claim, fixed by F-278/279):** each of the 4 UI `.xsf` decompresses only its FIRST window. Mechanism (F-280): the guest inflate executor `sub_821BC140` window loop advances a window only while pgStreamer bytes-available `[r22+0x74C0]`>0; it premature-completes after window 1. All 4 ARE correctly SERVED (RSC5, `XSF-HOSTSERVE pass=1`, sizes 143069/1066057/19337/29655).
- **Full-decompress ENGINE is proven (F-281/282):** host `MclaXcDecodeFullStream` (`gpu_device.cpp:4702`, the W27 loop over guest `sub_8244FF20`) fully decompresses raceeditor to exact uncLen (`produced=143069`), offline in a scratch buffer.
- **But it CANNOT be applied in-boot — experimentally confirmed (F-286/287/288):** writing it into the dest from the corrupt-serve hook fully decompresses raceeditor BUT regresses policecam+credits to 0-inflate and collapses boot depth ~3× (w262 28K lines vs w257 88K). Controls: scratch-only (w258) and ISOLATED-STACK (w264, `stk=CA128980`) BOTH regress identically ⇒ the cause is **re-entrantly calling the guest VM decoder from inside the guest's own inflate hook**, not the dest write, not stack/ctx corruption. Every host-decompress call site (`MclaJob2DecompressAndDistribute` 9315/9778/9894, `MclaForceServePkgForDest(hostInflate=true)` 9389) is a re-entrant `PPCContext` guest-hook context — no non-re-entrant apply point exists. **All dest-write/synchronous-apply variants were REVERTED; tree is at the safe all-4-first-window state (build f288r, w265 verified: all 4 XMEM-SZPTR=1, depth 87K, exe 97,628,672).**
- **DO NOT re-try (proven dead):** (1) synchronous/isolated-stack/ctx dest-write of the full container from any guest-hook context → re-entrancy collapses boot (F-288). (2) host LZX (Path A) → F-245 libmspack rc=11, Xbox XMem-LZX is non-standard; a bespoke decoder is research-grade. (3) 7MB-whole-source, reset-suppression, record-completion-as-gate (F-249/248/265).
- **Two remaining LARGE, non-trivial paths to full decompress:** (A) defer host decompress OUT of the guest-hook into the host frame loop between guest quanta (architectural, race-free vs the guest's own dest writes) — then it still won't reach nGfx unless full decompress moves the frontier (UNTESTED; F-277 inferred no from partial builds); (B) drive the guest's OWN progressive streamer read `[r22+0x74C0]` (peer-owned F-143→F-204b / task #15 subsystem).
- **End state (F-269/270→277, UNCHANGED):** `nGfx`=0. GFx-init is gated on the effects/scene place-pass converging (`sub_825EF1xx`, peer task #15) THEN msgid `0x40003B03` (a broadcast XAM msg, ~8 subscribers incl gate `sub_82131008`) being produced by a `KeInsertQueueDpc` path with zero compiled callers + the producer/dispatch table `0x82100000..0x8212FFFF` being UNMAPPED (needs rule-2-forbidden recompile; hook can't fire in unexecuted code). The user EXPLICITLY chose "STOP AT THE CONSTRAINT WALL" (F-269 Q) — do NOT cross rule-2 (recompile forbidden config) or F-055 (force the gate) without their re-approval.
- **Objective audit verdict:** Path A evaluated (dead); Path B evaluated + engine proven; `file:line` plan complete (F-269→F-288); the F-186/187 enqueue gap is resolved to its SAFE extent (all-4 first-window, RSC content validated F-274) but full decompression is NOT achievable without path A/B above; nGfx=0. **Goal correctly OPEN, NOT complete.** Flag `kPathBEnqueueUI` ON (OFF==baseline 97,596,928); everything this session is UNCOMMITTED in src/gpu_device.cpp. Ledger authoritative through F-288; next ID F-289.

## 2026-09-25 ~ (F-269, raw-byte + live-log) — ROOT-CAUSED the last blocker F-267/268 could only bound. msgid `0x40003B03` is a **BROADCAST kernel/XAM message** with ~8 subscribers (raw `{handler,msgid}` table at VA `0x82102AC0` / `mcla_pe.bin:0x102ac0`: `sub_82131008`, `0x82152A48/17 1C48/18 2918/19 5910/20 1EA0/20 EF00/21 E408`) — the UI gate is just ONE subscriber. Producer `KeInsertQueueDpc`=`sub_8242FD00` is **fully recompiled** (`ppc_recomp.78.cpp:27365`), NOT a stub, but has **zero call sites and is never entered**; the boot-worker ring `0x40004B40` sits at `delta=0` forever (`w257 W36b-QUEUE`), the boot worker (`0x821322B8`) wakes on `0x40004D7C` and drains nothing. Host `SignalSchedulerTick` (`imports.cpp:1730/1782`) pokes the wake semaphore only, never posts `0x40003B03`. ⇒ **A (UI .xsf decompress) DONE; B (GFx init) blocked on a class-D kernel XAM broadcast, categorically NOT the F-186/187 UI-inflate enqueue** (the named objective gap, resolved). Fix (dedicated kernel task, not a flag, F-055 bars faking the gate): drive the guest's own broadcast that posts msgid `0x40003B03` into ring `0x40004B40` via `sub_8242FD00` on the boot-worker context so the dispatcher fans out to its 8 subscribers. `nGfx`=0 both baseline and Path-B; goal stays OPEN. Flag ON (OFF==baseline byte-identical). Next ID F-270.

## 2026-09-25 ~06:49 - **F-249/F-250 (read-only trace + `MclaJob2DecompressAndDistribute` body read) — the terminal blocker is NOT the re-point/reset/whole-package-source; it is that pkg `0xA0000` is a MULTI-`.xsf` CONTAINER.** Ledger F-226→F-250.

- The looping `B7841000` `XMEM destSz=7179940 ret=0` is the GUEST whole-package `XMemDecompress` on a container that has no single 7 MB stream (`gpu_device.cpp:6708-6712` comment + the replay `:6575` already tries decode paths A/B/C/D + `MclaJ2FrameExtract` and returns `wrote=0` even in baseline `w244`).
- **Do NOT retry:** the `IsJob2UiDest` allowlist (F-247 fixed), `JOB2-PKG-RESET` suppression (F-248 ruled out), pos-pinned `LastServe` advance (F-195/248), or "give the full 7 MB source" (F-249 premise refuted by F-250). The remaining fix is a correct **per-file XMem container decoder+distributor** — the F-143→F-250 emulator-wide archive-container defect, a SEPARATE project-sized subsystem, NOT the UI-inflate enqueue.
- **Session net:** UI-inflate enqueue + wrong-package (`AssignPackageForDest` guess) + incomplete allowlist all FIXED → job2/UI dests read real RSC5 for the first time; effects `REBASE-POISON` collapsed 3.36M→~40 (coupled, supersedes F-243). All code flag-gated OFF; flag-OFF == exact baseline (exe 97,596,928, `w248`==`w244`). No commit. `nGfx`=0 → objective NOT complete (end-state gated on the container-serve subsystem).

## 2026-09-25 ~06:30 - **F-247 (USER-AUTHORIZED route 1 "serve-framing rework", 3 build+soak cycles w245/w246/w247 + flag-OFF parity w248) — the UI-inflate wrong-package ROOT CAUSE found and ~90% fixed; job2/UI dests decode REAL RSC5 for the first time; REBASE-POISON collapsed 3.36M→409.** Ledger F-226→F-247.

- **Root cause (concrete, supersedes F-242/243's diffuse framing for the UI path):** `AssignPackageForDest` (`gpu_device.cpp:207`) has no dest→pkgoff knowledge for the 4 standalone `.xsf` (not in `IsJob2UiDest`), so it serves "the first unclaimed `g_rscTab` entry" = the WRONG package (w231 `DEST-PKG B7B01000 -> off=00060000`=meshtextures, not raceeditor's real `+24=0x64CB0000`). Guest inflate reads non-XCompress bytes → stack-keyed `LastServe` re-point re-imposes the 7MB meshtexture bounce → livelock.
- **3 gated fixes (all reverted to `kPathBEnqueueUI=false`; flag-OFF exe byte-identical 97,596,928 + w248==w244 marker parity ⇒ code inert/safe):** fix#1 `PATHB-PKGFIX` (~:10680) registers each UI dest's true pkgoff → w245 `B7B01000` reads `magic=05435352`. fix#2 hardcode 4 pbase dests into `IsJob2UiDest` → fixed B7881000 (spins 9554→0) but moved to B7121000 (⇒ allowlist systematically incomplete). fix#3 `MclaIsCurrentJob2Pbase` dynamic membership (:3941) → `produced=0` 12106→**2**, all job2 dests decode real RSC5.
- **Coupling discovery:** fix#3 collapsed `REBASE-POISON` (the effects place-pass, F-235/243 "peer central blocker") 3.36M→409. The "effects livelock" and "UI-inflate mis-serve" are the SAME job2 slices, NOT the independent chains F-243/F-246 assumed. **This reopens F-246's "B is a separate wall": if the walk loop is cleared, the bootstrap may now reach msgid 0x40003B03 → UILOAD → GFx.**
- **Remaining wall (task #15, needs auth — structural, meshtexture-regression risk):** `XSF-INFLATE`=0/nGfx=0 because the SHARED `g_job2SharedWalk` (one cursor) can't serve many independent job2 pbase slices; `JOB2-PKG-RESET` (`:7375-7391`) thrashes it to 0 on every non-RSC5 continuation (w247 ×14) → re-serve-head soft loop. That's the F-195/196 J2-DIST-replay↔inflate-re-point collision. Fix = per-slice cursor OR let J2-DIST replay own job2 dest filling & skip the per-dest re-point OR don't reset on legit continuation. **Objective #4 not met (nGfx=0)** but moved from "hard livelock, never decodes" to "decodes real RSC5, blocked only by a shared-walk cursor."

## 2026-09-25 ~05:57 - **F-244/245/246 (controls + honest negative + completion-audit split) — three refinements that CLOSE the last "cheap escape" hypotheses and pin exactly what authorization is needed.**

- **F-244 (clean OFF/ON control, no build):** baseline `w244` (kPathBEnqueueUI=false) → `grep -ic INFLATE`=**361**, `grep -ic CAB28300`=**0**. `w231` (flag=true) → all 4 UI records created with **correct sizes** (`PATHB-REC … +4=00022EDD <==ENQ` for raceeditor, +garage/policecam/credits) yet `INFLATE`→47,182 on `src=CAB28300`. ⇒ Path-B enqueue is PROVEN GOOD; the CAB28300 livelock is genuinely Path-B-TRIGGERED (not baseline noise), via the `LastServe` re-point (`gpu_device.cpp:469-508`) re-imposing the meshtexture sbuf on the UI record → guest rejects 'not in XCompress format' (F-194).
- **F-245 (refutes the Path-A "wrong-API" revival hope):** hypothesis was that F-191 killed Path A only via libmspack's CAB-level call. FALSE — `tools/lzx_raceeditor_proof.c:75-79,256` already drives libmspack low-level `lzxd_init`/`lzxd_decompress` with 0x8000 frames + a `window_bits` sweep (Xenia-shaped, cf. `lzx.cc:97-121`) and still produces 0. Host decode needs a **bespoke XMem-LZX** (large, unscoped). Real payload confirmed addressable offline (`xarchive_cache.rpf+0x64CB0000`: RSC5, XMem magic `0x0FF512EF`, uncLen 143069, hdrLen 27).
- **F-246 (completion-audit split):** decompressing `.xsf` (A) ≠ GFx init (B). `W34-NOGFX` proves the GFx loader is **never armed** (UILOAD/EF220 never armed; `LoadBytes`=0) because it sits behind msgid `0x40003B03` dispatch that the F-243 effects livelock blocks; F-055 bars forcing it. So BOTH walls to END STATE cross a hard constraint or a large build.

**Decision the objective now needs from the user (all three remaining routes are authorization-gated, not flag-flips):** (1) authorize a **serve-framing rework** in the load-bearing streaming/re-point stack (gpu_device `:469-508` + J2-DIST) so the guest's own `XMemDecompress` receives the real UI payload — high meshtexture-regression risk, do-not #9; (2) authorize a **bespoke XMem-LZX host decoder** (Path A revival, F-245) — but per F-246 still not sufficient for GFx init; (3) authorize taking over the **peer-owned effects/serve livelock** (`task_dispatch_trace.cpp`, F-243/task #12) — the only route that clears (B). Absent one of these, the safe in-scope work is exhausted; `nGfx`=0 so the goal is NOT complete. Ledger F-226→F-246.

## 2026-09-25 ~05:17 - **F-238 (log census `w244`) — CORRECTION to the F-237 hand-off target: do NOT chase `B7B41000`. Its `RSC-REBASE-PREPLACE` pass CONVERGES (16 nestPasses, finite). The non-terminating loop is the broader effects/scene resource-place pass at `sub_82587xxx` (the `lr=82587A30/82587350` the bootstrap parks in), still making ~87K rebase resolutions (87K lookups > 39K distinct ids ⇒ re-scanning = a retry loop) at the 600 s cutoff.** So the peer-facing root is the effects/scene resource assembly resolving poison/mostly-unique resource pointers forever (the F-143→F-204b grmShaderGroup/shadinggroup/serve domain), not `B7B41000`'s children. End-state verdict unchanged (see F-226→F-237).

## 2026-09-25 ~05:13 - **F-237 (static, no build) — the last bounded fix hypothesis ("accumulate the rebase map across jobs") is DISCONFIRMED on the architecture.** `kMclaRebaseMax=24` and the table is materialized as the guest's OWN per-container ≤24-region table (`gpu_device.cpp:3834/3858/9071-9095`); accumulating across Job2s overflows it and breaks the per-container rebase contract. Root = serve-corruption of `B7B41000`'s child resource pointers (the F-143→F-204b streaming/serve core), a peer-owned subsystem rework — NOT a flag fix, NOT UI-inflate, forcing barred (F-055). Objective #4 end-state determined NOT FEASIBLE within scope (proven). Ledger F-226→F-237 is the authoritative close-out.

## 2026-09-25 ~05:05 - **F-235 (LONG 600 s baseline soak `w244`, no build) — DEFINITIVE END-STATE VERDICT: the game is in a HARD, NON-converging rebase-poison LIVELOCK, so the UI `.xsf` are provably NEVER decompressed and GFx never initializes. Resolves F-234's "convergence-untested": it does not converge. No build; exe==baseline; no commit.**

- `w244` (04:51:54→05:01:54, 600 s): `UILOAD`=0, `BOOT-GATE`=0, `nGfx` 0 both times; `RenderThread HB-FLICKER #17160 **frame=0**` (zero frames advanced in 10 min); last line `REBASE-POISON #00222 **n=3368026** … lr=822494E0 (skip D890 fatal)` (`src/task_dispatch_trace.cpp:517`). `XSF-INFLATE`=0, `sub_824EF220`(LoadBytes)=0, 0 inflate for the 4 UI pkgoffs (`64CB0000/64980000/64CA3000/6496F000`).
- **Mechanism:** the host `skip D890 fatal` mitigation returns delta 0 for a poison resource pointer (`val=E04AFBCD`); the guest effects/place-pass re-attempts the same entry forever → infinite loop (a crash-avoidance short-circuit sustaining a livelock — the do-not #9 failure mode). `sub_8217D890` rebase-miss is the peer's documented OPEN investigation (`task_dispatch_trace.cpp:777`).
- **Objective final disposition:** #1 Path A dead (F-191); #2 Path B enqueue functional+implemented (F-205/213); #3 plan delivered (F-226→F-235); #4 end-state (UI .xsf decompressed → GFx init) is **NOT reachable via this objective** — it's gated on the rebase/effects-place livelock, three-plus stages upstream (F-226/227 dispatch, F-233 shader-preload, F-235 livelock). Real fix = eliminate poison resource entries / break the loop legitimately, in the peer's effects/serve/rebase domain; do NOT stack mitigations (do-not #9); F-055 no forcing. Next F-id F-236.

## 2026-09-25 ~04:49 - **F-234 (LONG 300 s baseline soak `w243`, no build) — the bootstrap is NOT parked/idle (corrects F-233): it BUSY-resolves a very large, non-converging-within-300 s RSC-rebase pass (`sub_8217D890`/`P10-GATE`), so it never advances to post msgid `0x40003B03` → UILOAD → `.xsf` → GFx. No build this turn; exe==baseline; no commit.**

- `w243` last NON-park line @ the 300 s cutoff = `P10-GATE #090452 … lr=822493A4 → delta 0 (not in rebase map/phys)` — counter still INCREMENTING at cutoff ⇒ the rebase pass had not finished in 300 s. 39,388 distinct resource ids → delta 0; callers dominated by the effects/place pass `lr=82587364/82587A50/82587E3C` (~14K each) plus the F-233 reader-wait `822493A4/82249578`.
- Repeated ids OBSERVED (`0x00FFFFFF`×1581, `00FFFF00`×717) — flagged, NOT proven infinite (convergence beyond 300 s untested).
- This is the peer's documented OPEN rebase-miss investigation — `src/task_dispatch_trace.cpp:777` "prove WHY `0x500705E0` misses its region" (sub_8217D890). Likely host-side: the rebase map (group `8EFFF150`/`D10DCA00`) not populated ⇒ every resource misses → delta 0 → effects place-pass doesn't terminate → loading never completes → UI never loads.
- Objective disposition unchanged: #1–#3 met; #4 `nGfx>0` gated on this rebase/effects-place pass terminating (peer domain), NOT the UI `.xsf` inflate (upstream-disconnected F-226/227/233/234). Next F-id F-235.

## 2026-09-25 ~04:40 - **F-233 (BUILD+SOAK `w242` of a read-only `sub_821BE4F0` byte-reader census, now REVERTED) — DEFINITIVE: the UI-bootstrap blocked reader is refilling SHADER/EFFECT files, NOT the UI `.xsf`. `nGfx=0` is gated on the game's shader/effects PRELOAD completing, two stages upstream of UI load. Census reverted; exe back to baseline 97,596,928; `w242`==`w230`.**

- **Method:** hooked `sub_821BE4F0` (addr-owner-clean, 1 site) gated to `lr==0x821CFB40` (the reader `sub_821CFAA8`'s refill call, generated `ppc_recomp.17.cpp:12420-12424`) and dumped the stream-object name field. `w242` `BE4F0-READER #1..#2432` all `obj=82860C40` `device=C60AC180`, names: `AlphaModulate.fx`, `WheelRubber.fx`, `Character.fx`, `// Shaders listed he…`, `Version: 103` (F-143 entity.type shadinggroups) → **shader/effect preload reads**, then last read 04:35:46.779 → main thread parks 04:35:51.309 in `sub_82249750←sub_821CFB40←sub_821BE4F0`.
- **Conclusion:** the bootstrap stalls in the shader/effects preload phase and never reaches the point that posts msgid `0x40003B03` → UILOAD → `.xsf` decompress → GFx init. This bounds F-229/230/231 (the meshtextures/trash streamer loads are concurrent bootstrap work, but the terminal park is the shader-reader) and CONFIRMS F-224/F-225 (shader/effects loading screen).
- **Objective status (honest):** Path A dead (F-191); Path B enqueue functional+records-executable (F-205/213); the DIRECT 4-UI-`.xsf` inflate proven NOT the gate TWICE (GFx-dispatch F-226/227; shader-preload-precedes-UI F-233). Deliverables #1–#3 met & soak-validated (`w231`–`w242`); the #4 end-state (`nGfx>0`) is NOT reachable by safe UI-inflate/host changes — the gate is the peer's shader/effects-preload→menu domain (P10-PRE / GLOBTEX preload.list / D2308-INS-SKIP / AFB76 = known mitigations), and F-055 bars forcing. Next real `nGfx` movement = a dedicated shader-preload-completion investigation (which registered shader/effect stream starves after ~2432 reads), peer-coordinated. Flags OFF; source==baseline; no commit; next F-id F-234.

## 2026-09-25 ~04:27 - **F-231 (build+soak `w240` of a read-only BC140 pre/post record census, now REVERTED) TESTS & REFUTES the F-230 "make the bootstrap containers inflate" fix-idea and re-localizes `nGfx=0` to an aggregate preload-completion SPIN. `w240`==`w230` on every structural marker ⇒ census was inert.**

- **Refutation:** in `w240` trash's inflate dest `B7111000` DID fire 2× (it was 0 in `w239` — boot is bimodal, F-169), yet the main thread still spins at `lr=82249750` and `nGfx=0` / `UILOAD=0` / `W35-BOOT-GATE=0`. So per-container inflate is neither necessary nor sufficient; F-230's streaming-length lever claim is wrong.
- **Confound found:** the 3 bootstrap streamer tasks (meshtextures/legals/trash) all hash `id & 0x7FFF = 4` = ONE recycled record slot (gen 0/1/2). The post-`__imp__` read of the slot for exec #1 already showed the NEXT task's pkgID (`+16=D454283D`=legals) ⇒ any per-record post-read is overwritten before you can observe it. (Reason the F-231 census was reverted.)
- **CORRECTED target:** the UI bootstrap (`sub_82131508→sub_822C2EA8→…→sub_82249750`) is a BUSY-SPIN (`r3` monotonically increasing each sample, NOT a blocked KeWait) waiting on an **aggregate preload-completion condition** for group **`0x8EFFF150`** (the `r4` the spin holds). This is the game's loading→menu count — the peer's active P10-PRE/preload-list domain (F-225).
- **Next (task #12):** read the `0x8EFFF150` pending/complete counters per spin iteration + dump the outstanding member names → find which registered preload never completes. Do NOT stack serve/gate/inflate mitigations (do-not #9); F-055 no forcing; kInflateIntervene load-bearing (F-194); F-079 gate write deliberate. Source reverted == baseline; exe still carries the inert `w240` log until next build; no commit; next F-id F-232.

## 2026-09-25 ~04:09 - **F-229 CORRECTS F-228: the `nGfx` blocker is NOT unreachable flowgraph — the MAIN boot thread is synchronously PARKED inside the UI bootstrap waiting on async STREAMING loads (`meshtextures.xtd`, `trash.xrn`) issued via `sub_821E5FD0`, i.e. the SAME `sub_821BCB10`→`sub_821BC140`→inflate pipeline the F-186/F-187 objective targets. The streaming-completion question is load-bearing for `nGfx` after all. Task #12 reopened with the decisive census.**

- **Parked chain (w239 PARK-STACK, persists 02:56:37→end):** `sub_82131790 →sub_82131508(installer,+0x44) →sub_822C2EA8 →sub_82304B3C →sub_822F0CB8 →sub_821CFB40 →sub_8224BFC4 →sub_82249750`. The bootstrap opened the msgid-`0x40003B03` gate prerequisite but is blocked BEFORE returning → gate never posted → `nGfx=0`.
- **Named blocking loads (raw-PE decoded names):** `ASYNC-REQ sub_821E5FD0 #1 a0=8201BA64='meshtextures'+'.xtd'` → `STREAM-OPEN #5 rec[+4]=240531 lr=821E5E10`; `#2 a0=8202B444='trash'+'.xr n'` → `STREAM-OPEN #7 rec[+4]=10799 id=0x10004 lr=821E5E10`. Both served by host (`XSF-HOSTSERVE trash.xrn size=10799 head=05435352`, advancing chunks). **meshtextures `XSF-OPEN` (sub_821CCEA0, already hooked) repeats 18×** = a re-open/retry loop → the load likely never reaches guest-visible completion.
- **DECISIVE EXPERIMENT (next turn, read-only, robust):** hook-level log (UNCAPPED, per-record-id, WITH a positive control) whether records #5/#7 are executed by `sub_821BC140` and drain `+4→0` (the existing `BC140-REC n<=60` / `INFLATE # n<=8` caps make their silence non-informative — F-089§6). Outcomes: never executed → the enqueue→execute gap for these records IS the nGfx lever (distinct from the refuted record[+4] framing, since here +4 is correct); executed but waiter unsignalled → completion-signal gap. Then a targeted fix + soak vs `w230`.
- **HARD CONSTRAINTS:** do NOT stack a serve/gate/inflate mitigation (do-not #9); `XSF-OPEN-GATE-SKIPPED`'s guest bit30 write is a DELIBERATE F-079 removal (`src/gpu_device.cpp:12295` commented out) — do not re-enable it blindly; `kInflateIntervene` load-bearing (F-194); F-055 bars forcing `sub_82131008`. Peer owns streaming/gpu_cp — coordinate. Flags OFF; `w239`==`w230`; no commit; next F-id F-230.

## 2026-09-25 ~03:56 - **F-228 (`w239` CP/render re-read + IDA on the worker ring) CLEARS the host render backend AND host kernel as `nGfx` levers and rejects the "gate-on-stack" artifact — the residual is purely the game's main-thread wait before posting msgid `0x40003B03`. Task #12 refined with the one decisive instrument.**

- **Quiescence timeline:** `w239` last real markers `P10-PRE #087334` @02:56:36 (a ~10 s boot burst from 02:56:26), then **40 s of pure idle** (02:56:36→02:57:16) with only the boot worker `WAIT[KWFSO] tid=4054 obj@40004D7C` poll.
- **Render-idle = EFFECT not cause (closes any render-thread lever):** CP `VDRAIN-CENSUS … doorbells=8 drains=8 swaps=0 sameWptr=1969→2969 primaryWptr=0000001F(frozen)` — the CP drained every doorbell it got, then the guest wrote nothing more. `grep swaps=[1-9]` = **0 lines for the entire log**. F-224's "2000 FLIPs healthy" was host present-ticks on a static frame (`HB-FLICKER frame=0`, `queue depth 30`), not guest frames. So the game STOPPED; the render backend did not stall.
- **Host kernel cleared:** `decompile 0x8242F870` (worker's dispatcher) = standard MPSC ring (spinlock + `write(a1+60)!=read(a1+56)` + process) with **no host stub** in enqueue/drain → the "unmapped `KeInsertQueueDpc` stub" (W36d) is not the actionable gate for `nGfx`.
- **Artifact rejected:** `PARK-SAMPLE … s1/nf=0x82131008 (+0x235cf)` — the `+0x235cf` is host-code bytes (do-not #18) and the function-attribution is weak (do-not #19); same class as the retracted F-208 "byte-packer park." NOT evidence the gate runs.
- **Decisive next instrument (task #12):** census whether the GUEST ever calls the routine that bumps the worker ring write-cursor (`0x40004D98` = ctx+60) / appends to base `0x40004B40`. If never called → boot-flow (game hasn't reached the UI-post step). If called but ring stays empty → ring-layout mismatch = fixable host emulation. Plus: what `KeWait` the main boot thread `sub_82131790` parks in AFTER its installer tail (`+0x3c8`, already reached — `dword_82830998` valid). Peer flowgraph/runtime; F-055 bars forcing; don't touch kernel DPC (works); no more UI-inflate/serve mitigations. Flags OFF; `w239`==`w230`; IDA terminated; no commit; next F-id F-229.

## 2026-09-25 ~03:48 - **F-227 (headless IDA + `w239` KWFSO re-read) PROVES the host boot-worker/message dispatch is HEALTHY → `nGfx=0` is the game NEVER posting msgid `0x40003B03` (boot-flow), NOT a kernel/DPC defect and NOT the UI `.xsf` inflate. This closes the producer-side open question from F-226 and re-points task #12.**

- **Worker runs + drains:** `sub_8242FB88` (tid 4054) does `WAIT[KWFSO] obj@40004D7C to=30ms` ×3063 with paired `WAKE status=00000000` — the host's `SignalSchedulerTick` (`src/kernel/imports.cpp:1783`) IS waking it; its park loop is alive. It finds its MESSAGE queue empty each wake (`W36b-QUEUE qBase=40004B40 qWrite=0 qRead=0 delta=0` = the `a1[15]==a1[14]` test the decompile shows) and re-parks. `W35-BOOT-GATE`/`BOOT-GATE-ENTER`=0 → gate `sub_82131008` (→ unconditional UILOAD) never executes because msgid `0x40003B03` is never enqueued by the game.
- **Guard against a real trap (F-057(1) class):** the `put=5→11` advancing on the same KWFSO line is `ReadU32BE(gpuCtx[0x82839254]+10908)` = the **GPU command-ring put** (`src/kernel/imports.cpp:2126`, `src/gpu_device.cpp:3446`), NOT the worker message-queue depth — do not read a rising `put` as "the queue is producing."
- **Consequence:** no safe host-side nGfx lever exists here short of F-055-forcing the gate (prior W36b attempts crashed the `dword_8288E6F0==0` atArray init on the wrong thread). The real path is task **#12**: what does the game await before posting `0x40003B03` (installer `sub_82131508`=msg `0x40008503` already ran — `dword_82830998` valid per `gpu_device.cpp:1476`), likely the loading→menu flowgraph / shader-preload (F-225). Peer `task_dispatch_trace.cpp`/W33-36 + runtime. Flags OFF; `w239`==`w230`; IDA terminated; no commit; next F-id F-228.

## 2026-09-25 ~03:38 - **F-226 (headless IDA on `default.xex`) GROUND the exact `nGfx=0` gate and CORRECT the F-207 model below: `sub_82131008` is NOT reached via a `bl` from `0x82119c04` (that was a data-table false positive, F-210) — it is the message-handler for id `0x40003B03` in the `{handler,msgid}` table @`0x82102aa0`, dispatched by boot worker `sub_8242FB88` off an item queue that is NEVER produced into. The UI `.xsf` inflate (F-186/187) is confirmed upstream-disconnected: decompression RUNS and produces output, yet `nGfx=0`.**

### What F-226 proved (each link IDA-raw, not inferred)
- **UILOAD is unconditional inside the gate.** `decompile 0x82131008`: two `sub_821C0750(…)` event-checks are **no-ops** (`→ nullsub_8`); `v0 = sub_822C0980(dword_82830998)` at `0x821310b8` always runs. Only `if(dword_8288E6F0==0){sub_823043F8;sub_82304348}` (atArray allocator) is crash-prone.
- **Gate is a message handler, never a call target.** `get_xrefs_to 0x82131008` = data-only: table `0x82102ac0` + inside installer `sub_82131508@0x821315f4`. Table @`0x82102aa0` (stride 8, `read_memory_bytes`): gate→**`0x40003B03`**, installer `sub_82131508`→`0x40008503` (it publishes the UILOAD r3 `dword_82830998`, called at tail `+0x3c8` of boot thread `sub_82131790`, which is `__noreturn` and spawns the [RAGE]/[MC4] loading tasks).
- **The dispatching queue is empty.** `decompile 0x8242FB88` = `while(1){ if(a1[15]==a1[14]) KeWaitForSingleObject(a1+8,…,-300000) }`. `w239`: `THREAD-CREATE #12 start=8242FB88 ctx=40004D5C`, `W36b-QUEUE qBase=40004B40 qWrite=0 qRead=0 delta=0`, `WAIT lr=8242FC1C`, `W35-BOOT-GATE`=0. Worker parks; gate/UILOAD never dispatched.
- **Decompress ≠ the gate.** `GFXINIT sub_82177948`=1 (`lr=82304278` in `sub_823041E8`); `INFLATE #3 consumed=2284 out=524288`; peer `src:7591` "XMem produced 44365500" → inflate yields bytes yet `nGfx=0` (`W34-NOGFX`=2). F-217's "entire GFx path inert" = overstated (only per-movie loader `vt 0x82073xxx` is cold).

### Real next frontier (task #11 — peer kernel/`task_dispatch_trace.cpp` + recompiler-stub, NOT UI-inflate)
1. Producer-side (INFERENCE): msgid/queue-base are runtime-derived (`ppc_xrefs xref 0x40003b03/0x40004b40`=0). `KeInsertQueueDpc`(0x8242FD00) is passed as a **func-pointer arg** at `sub_8241C308+0x238`, `sub_8241CB08+0xa8`, `sub_8242FEF8+0x10c` → trace which installs the `0x40003B03` handler and whether its trigger stub is recompiler-mapped.
2. If an unmapped stub → `mcla-recompiler-regen` (toolchain currently broken, memory `project-recompiler-toolchain-broken`).
3. **Do NOT** re-run the forced boot-gate lever `src/gpu_device.cpp:1474-1644` (`s_uiLoadCalled`, fires 0×/wrong-thread TLS crash, F-055 fabrication). **Do NOT** touch `kInflateIntervene` (load-bearing for meshtextures, F-194). Do NOT add another UI-inflate/enqueue/serve mitigation.
- Flags OFF; tree == `w230` (`w239` confirmed); IDA server terminated; no commit. `nGfx`=0 → goal NOT complete. Next ID F-227.

## 2026-09-25 ~02:09 - **F-207 REFRAME: `nGfx=0` is gated UPSTREAM of the UI `.xsf` inflate — the GFx boot-gate `sub_82131008` (SOLE caller of `UILOAD`/`sub_822C0980`) never runs and no GFx movie object is ever created. The F-186→F-206 "decompress the UI .xsf" line was a downstream symptom. Supersedes F-204b/F-205/F-206 serve-framing.**

### Markers (`w230` baseline) — read before touching UI-streaming code
- `UILOAD sub_822C0980` executes **0×**; ONLY caller = `0x821310b8` inside `sub_82131008` (`ppc_xrefs calls 822C0980`).
- `W35-BOOT-GATE`(+`-POST`) census on `sub_82131008` (`src/task_dispatch_trace.cpp:1577`) = **0×** → gate never runs.
- `W35-MOVIE-LIFE` census on `sub_824C6F70` (GFx loader lifecycle) = **0×** → no `0x82073xxx` loader object (`nGfx`'s target) ever created.
- `GFXINIT sub_82177948`=1 (early static init only). ⇒ GFx inits but never loads a UI file, so `nGfx=0` regardless of any `.xsf` decompression.

### So what's already settled (do not re-litigate)
- Path A dead (F-191). F-205: the 4 UI records ARE executable (`+4` correct, `+8`=device `C60AC180`). F-206: no ring read-list + `sub_821FDED8` never enqueues them (sync-consume design). ⇒ **inflating the .xsf cannot raise `nGfx` — the gate is prior.** Flags OFF; tree == `w230` (`w234`/`w236`). Next ID F-208.

### Real next frontier for `nGfx>0` (boot-sequencing; likely peer/IDA)
1. Why does the game never reach `sub_82131008`? Its sole caller `0x82119c04` has NO generated code (unreached region) — name that fn, check reachability.
2. `[0x8287E26C]` singleton the gate needs is published by `sub_823047D8`'s tail (forcing without it AV'd — F-060); `sub_823047D8`≈0 in `w230`. Why no complete?
3. `GFXINIT`#1 at `lr=82304278` — is the boot-thread reaching `sub_82131008` the same `sub_823047D8`/`sub_82304278` chain? Trace it. **Do NOT add another UI-inflate/enqueue/serve mitigation.**

## 2026-09-25 ~01:43 - **F-204/F-204b: Path B host-hook enqueue CONFIRMED DEAD; `record[+4]` is NOT the blocker; the real unlock is peer `kInflateIntervene` serve framing. Tree reverted to w230 baseline (verified w234). nGfx still 0.** [serve-framing part SUPERSEDED by F-207]

### What was settled this session (F-204, F-204b in `docs/ROOT_CAUSE_VALIDATION.md`)
Static RE made the whole async path end-to-end code-verified: `FDD50(r3=outSlot,r4=template,r5=tag,r6=count)` → `E5FD0` (`ppc_recomp.20.cpp:1689-1703`, passes r4/r5/r6 **straight** to `E5C78`, no snprintf) → `E5F48`→`E5DC8` (`:1344-1395`, builds request `I={+0:slot,+4:0,+12:bc7a0}`) → `E5E58` (`:1473-1523`, calls `BCB10` producer). `BCE68` writes `record[+4]=sub_823DD7F0(name+6)+sub_823DD7F0(sub_823DD850(name,44)+1)` **only if `sub_823DD850(name,44)!=0`** (`ppc_recomp.14.cpp:21005-21036`).

Three un-confounded experiments, each built + soaked + censused vs `w230`, each REVERTED:
- **w231** (double-open, `kPathBEnqueueUI=true`): enqueue regressed but `arg0used=CDCDCDCD` — the `E5C78` static capture never fires through `__imp__sub_821E2940` (confounded).
- **w232** (SINGLE-open, hardcoded exact static `arg0` = `raceeditor`0x8201BAAC / `garage`0x8201BA9C / `policecam`0x8201BA88 / `credits`0x8201BA78, tag 0x8201BB28, count 27): the enqueued record gets **`+24`=correct pkgoff but `+4`=0**. So async open CANNOT size the length for these 4 even with byte-exact `E2940` inputs → **refutes F-203's "register/fix +4 unlocks it"**.
- **w233** (+ a host seed of the known length 143069/etc into `+4` at `E5E58` entry): seed **never fired**; livelock identical.

All three regress identically: `INFLATE` 361→~48K on `XMEM src=CAB28300` (the peer re-point feeding a semaphore handle, F-194/195/196/197), `GFx` 5→1, `W34-GFX-CENSUS`/`W34-NOGFX` 2→0, `FATAL-SOFT` 0→1, `C0000005` 0. **Conclusion: `record[+4]` is neither achievable via async nor the actual blocker; the executor livelocks upstream on `src=CAB28300`.**

### The ONLY remaining unlock (NOT an enqueue/registration/host-hook)
**UI serve framing inside `kInflateIntervene`** — `PPC_FUNC(sub_821D5E10)` (`src/gpu_device.cpp:7487`) and `MclaForceServePkgForDest` (`:7765`): make the re-point serve the UI container's real RSC5+XCompress body (magic `0x0FF512EF`, non-zero `inLeft`) instead of the `CAB28300`/zeroed-`inLeft` it currently feeds, while staying load-bearing for meshtextures. This is peer-owned streaming code (uncommitted F-188–F-203 edits). **do-not #9: do NOT add another enqueue/re-point short-circuit.** `kServeFromXCompressHead` already proved zero-effect (F-183). Path A (host libmspack LZX) is dead (F-191).

### Tree / handoff state
- `src/gpu_device.cpp`: all Path B flags **OFF** (`kPathBEnqueueUI=false`, `kPathBSingleOpen=false`); the two Path B experiments I added (hardcoded-static-arg0 single-open `:10433`, `E5E58` +4-seed `:10387` region) are compiled but **gated inert** behind those flags. `w234.log` (reverted build) == `w230.log` on every tracked marker (`INFLATE` 361, `GFx` 5, `W34-NOGFX` 2, `C0000005` 0, `Fatal` 0, `FATAL-SOFT` 0). Fresh exe 97,593,856 @ 01:40. **No commit made** (per project rule; commit only when asked).
- New soaks this session: `w231`(double-open),`w232`(single-open static arg0),`w233`(+4 seed),`w234`(confirm-revert). `w230` remains the valid safe baseline.
- `nGfx` still 0; goal NOT met. Ledger next ID: **F-205**.

## 2026-09-24 ~19:55 - **F-188/F-189/F-190 Path A progress: host LZX wired; w199 partial 32KB then rc=11; refuse-partial + concat fix applied; w200/w201 TOC stalls are void. Named baseline = w193**

### What landed (F-188)
Host-side XCompress LZX decoder is wired into the CC6F0 serve path (`src/gpu_device.cpp`,
frame parse already at `:4005-4009`). UI `.xsf` payloads (codec=1 LZX, not DEFLATE) are
decompressed on serve so guest inflate is no longer required. Path A chosen over Path B
(guest descriptors) to avoid `sub_821E5E58` register corruption (F-187).

### Failures and the fix (F-189 / F-190)
- **w199**: host LZX produced a **partial 32KB** output then returned **rc=11** (LZX
  underflow / incomplete window fill). Guest never accepted the short buffer; UI still
  stayed compressed (nGfx remains 0).
- **Fix**: refuse partial decode (drop any short frame instead of serving it) and concat
  multi-frame XCompress members before LZX window close. This is the mitigation label for
  the partial-32KB class — cite at the refuse-partial site in `gpu_device.cpp`.
- **w200 / w201**: **void**. Both soaks stalled in TOC walk (archive parse hang) and
  produced no comparable marker census. Do **not** read either as a Path A regression or
  as evidence for/against the concat fix.

### Named baseline
**w193** is the named baseline for all Path A A/B compares (soak_census: `tools/soak_census.py
<new>.log build/logs/w193.log`). w194/w195 remain the UI-OPEN and failed-enqueue reference
soaks from F-186/F-187; they are not Path A baselines.

### Next (if concat is still partial)
1. Re-soak after the refuse-partial + concat fix against **w193**.
2. If the next LZX serve is still partial/short, move to **shared-state LZX**: one decoder
   instance with persistent window/history across CC6F0 serves (instead of per-serve
   reset). That is the remaining Path A lever before falling back to Path B.
3. Re-check UI-OPEN census (`sub_821E2940` at `src/gpu_device.cpp:9877`) and W34-NOGFX
   `nGfx` — success signal is GFx nGfx>0 and no Fatal 0→2 regression.

### Key addresses (unchanged from ~18:50)
`sub_821E2940` UI open (`:9885`); `sub_821E5E58` enqueue (needs descriptors); `sub_821E5F48`
non-UI open+enqueue; `sub_821FDED8` UI caller / inject `0x821FE5D0`; `0x8201BB28` shared
resource desc (not inflate desc).

## 2026-09-24 ~18:50 - **F-186/F-187: UI enqueue gap confirmed, direct fix failed — two paths remain (host LZX or guest descriptors). Commit `cdd9949`, frontier w193/w195 identical**

### What was found (F-186)
4 UI `.xsf` containers opened through `sub_821E2940` (lr=`821E29C4`) but NEVER enqueued for
async inflate. Only non-UI path (`sub_821E5DC8` lr=`821E5E10` → `sub_821E5E58` → `sub_821BCB10`)
enqueues. GFx stays at nGfx=0 because UI data stays compressed. F-170 truncation refuted:
archive is complete (2.1 GB, valid RSC5 at all UI offsets).

### What was tried (F-187)
Direct call to `sub_821E5E58` from inside `sub_821E2940` hook **corrupted guest state**: 3/4
subsequent opens failed with handle=FFFFFFFF. Root cause: `sub_821E5E58` needs TWO descriptor
objects per container (inflate descriptor at r3 with context pointer at +0, data/layout
descriptor at r4 with halfwords at +0/+2 and data pointer at +4) that the UI path never
constructs. Passing the open struct as r3 returned `0x736F7572` ("sour") = garbage.

### Census hook retained
`sub_821E2940` override in `src/gpu_device.cpp:9877` logs all 4 UI opens with struct/path/handle.
Verified working in w194: raceeditor handle=0, garage=1, policecam=2, credits=3, all ret=1.

### Two fix paths for next agent

**Path A — Host-side LZX decompressor (recommended, ~300 lines):**
RSC5 payloads are XCompress LZX (codec=1), NOT DEFLATE. No host LZX decoder exists.
XCompress frame format already parsed at `gpu_device.cpp:4005-4009`. Implement host LZX,
decompress UI packages when served through CC6F0, serve decompressed bytes directly.
Eliminates guest-state dependency entirely.

**Path B — Guest descriptor construction:**
Call `sub_821E5C78` + `sub_821BC5D0` to build inflate/data descriptors before calling
`sub_821E5E58`. Must happen at caller level (`sub_821FDED8` at address `0x821FE5D0`, after
all 4 opens complete) to avoid register corruption. Fragile — replicates guest setup logic.

### Other findings from parallel investigation
- **CP/IB route NOT the answer**: CP already has full IB following (opcode 0x3F), ring walker,
  nested IB support. DRAW_INDEXED=0 because draw chain (`sub_8217A470→sub_8241BE78→
  sub_8241C308→sub_82420BA8`) delivers null VB descriptors. PM4_WAIT_REG_MEM (0x3C)
  unimplemented but not the blocker.
- **Input**: Real XamInputGetState wired correctly (SDL mapper at `src/kernel/xam.cpp:261-322`),
  synthetic removed in F-092. Guest never polls during boot. B5 criterion 2 (PRESENT-FB) met:
  `rgb=(0.06,0.10,0.22)` dark blue frame at 1280×720.
- **Mitigations**: 73 undocumented in src/. FIXWALK-GATE easiest to retire (7 firings). P10-PRE
  biggest do-not #9 violator (305/soak). kInflateIntervene hardest (highest blast radius).
  SLOT-RECYCLE blocked on per-stream slot allocation (F-161).

### Soaks this session
- w193: REC4-CHANGE sampler relocated, confirmed record[+4] consumption lifecycle
- w194: UI-OPEN census hook verified (4 containers, handles 0-3, all succeed)
- w195: Direct enqueue attempt — 3/4 opens broke, zero delta on all markers. Reverted.

### Key addresses
- `sub_821E2940`: UI open path (hooked at `src/gpu_device.cpp:9885`)
- `sub_821E5E58`: enqueue function (needs descriptors, not raw struct)
- `sub_821E5F48`: non-UI caller that does Open+enqueue correctly
- `sub_821FDED8`: UI caller, injection point at `0x821FE5D0` (after all 4 opens)
- `sub_821BC7A0`: metadata lookup only, no enqueue
- `0x8201BB28`: shared global passed as r5 to all UI opens (resource descriptor, NOT inflate desc)
## 2026-09-24 ~18:35 - **F-186: UI containers opened but NEVER enqueued for inflate — the dispatch gap, not data or truncation**

- REC4-CHANGE sampler relocated to unconditional CC6F0 entry (was in unreached branch in w192).
  w193 shows one transition: sentinel→0 at lr=`821BC334` (inside BC140 itself) = consumption.
- **The 4 UI `.xsf` containers are opened through `sub_821E2940` (lr=`821E29C4`) which does NOT
  enqueue.** Only the 3 non-UI containers opened through `sub_821E5DC8` (lr=`821E5E10`) proceed
  to `sub_821E5E58` → `sub_821BCB10` → ring buffer → `sub_821BC140`. Evidence: STREAM-OPEN
  #1-#4 lr=`821E29C4` no ENQ; #5-#7 lr=`821E5E10` each followed by ENQ. BC140 fires exactly 3×.
- **F-170 truncation refuted:** archive is 2.1 GB (0x7F008000); offset 0x64CB0000 has 439 MB
  remaining with valid RSC5 headers and non-zero payloads. Data is present; dispatch is broken.
- W34-NOGFX fires 2× with `nGfx=0`: GFx loader never initializes because UI data stays compressed.
- Call chains: non-UI = `E5F48→E5DC8(Open)→E5E58(enqueue)→BCB10`; UI = `E2940(Open)→BC7A0→ret`.
- **Next:** either hook `sub_821E2940` post-Open to call enqueue, or host-side inflate UI containers
  on serve. Four background agents investigating: UI path detail, CP/IB B4 route, mitigation audit,
  input status.
## 2026-09-24 ~18:20 - **F-182..F-185: ran the experiment I had pre-declared. Removing our InflateBegin re-point makes the guest attempt inflate ONCE and fail its OWN `not in XCompress format` check (spin 149→1, XMem 40→1) - but it costs `Fatal error 0→2`, `FATAL-SOFT 0→2`, `GFx 5→1`, so it is reverted and both switches are off. Frontier restored: `w191` == `w188`**

- Two new named switches in `src/gpu_device.cpp` (registered in PROGRAM_GUIDE §7):
  `kInflateIntervene` (`:7085`, `true`) and `kServeFromXCompressHead` (`:315`, `false`). Flip the first
  to `false` for the honest-guest test; it is the removal probe for the whole inflate hook.
- F-183 is a clean negative: serving RSC5 members from `pkg+0x0C` so the stream starts with
  `0x0FF512EF` changed **nothing** (`w190` ≡ `w189` on all 18 markers). The stream the guest validates
  is its own stack copy, not the XSF-served body - so do not spend another soak on serve framing.
- F-185 closes the first candidate for the remaining question: `sub_821BC140` has **no** store through
  `r28` anywhere in its 586 lines, so it does not decrement `record[+4]`. Open seeds it correctly
  (F-181: 240,531 / 196,553 / 10,799) and it is 0 by the next execution (F-180) together with
  `record[+12]: 0 → 4`, i.e. one state-advancing writer touches both.
- **Read next, static and cheap:** the store lists of `sub_821BC674`-`0x821BC694` and
  `sub_821BCB10` (both also materialise the `0x8283D190` class static) for writes to `+4` and `+12` of
  a `[base + (id & 0x7FFF)*28]` record. That is the last unexplained step before the guest's own LZX
  path can be expected to run on the UI containers.
- Census inventory added this session, all measured zero-delta on the structural frontier: `REQFILL`,
  `STREAM-OPEN` (+ per-record length), `STUB-SLOT`, `BC140-REC`. And per F-178: **never** treat
  `INFLATE-ENTER`/`READWRAP` totals as evidence - they count a timed spin.
- Plan state: B1/B2/B3 closed; **B4 gate (`DRAW_INDEXED >= 1` from a non-zero constant bank) unmet**;
  B5 criteria 1-2 unmet, criterion 3 met. F-172's separate B4 lead (Type-0 `0x0A2F/0x0A30`
  size+address pair → `0x08A11000`/`0x08A15000`, unimplemented `PM4_WAIT_REG_MEM`) is still open,
  still unverified, and may be the cheaper road to renderer feed.
## 2026-09-24 ~18:05 - **F-180 + F-181: the streamer record is finally read directly - `record[+4]` IS the byte count, `pgStreamer::Open` seeds all seven containers CORRECTLY (143,069 / 1,066,057 / 19,337 / 29,655 / 240,531 / 196,553 / 10,799), and the zero `sub_821BC140` sees is that same record after consumption. So the archive, the TOC, the device vtable and Open are all innocent; our `InflateBegin` re-point is the remaining suspect**

- `BC140-REC` (3 checked reads inside the existing INLINE-EXEC hook) shows one shared 28-byte record at
  `C9A24970` = `[[0x8283D190+52]] + (id & 0x7FFF)*28`, ids `4 / 0x8004 / 0x10004` = index 4 with a
  generation tag. Layout: `{+0 id|gen<<15, +4 remaining bytes, +8 device, +12 state, +16 package ID,
  +20 entry offset, +24 package offset}` - the last three re-confirm F-171's per-record package decode.
- `STREAM-OPEN` extended with the same reads proves Open writes correct lengths and `+12 = 0`; at the
  second execution `+12 = 4` and `+4 = 0` ⇒ the streaming path mutates the record, F-180's "one Open
  leaves 0" is corrected by F-181.
- All **139** inflate-loop reads (`lr=821BC334`) are `r7=0` - the loop never interleaves a real read.
  With F-172 (all 34 `XMEM` calls are our replay: `j1SrcSz=7179936`, `src` = semaphore+0x14, `ret=0`),
  the remaining suspect is the re-point inside `PPC_FUNC(sub_821D5E10)` (`src/gpu_device.cpp:7067`-ff),
  which fires because the guest's stack-primed `st+0/st+4` look invalid (`-12` / `stack+12`).
- **Running now (F-182): retire that re-point so the guest's own XMem/LZX decoder sees the whole bodies
  F-169/F-171 already serve.** Pass criteria in order: `XMEM` with a per-file `srcSz` and `ret != 0`,
  or the guest's own `not in XCompress format` path becoming observable. Revert on any structural
  regression - and per F-178 judge it on `LISTLINE`/`TYPINIT`/`C0000005`/`SEEK-DEAD`/`Fatal error`/
  `FATAL-SOFT`/`GETDEV`/`CP-DRAW`/`PRESENT`/`DICTLOOKUP`/`[error]`/`DRAW_INDEXED`, **not**
  `INFLATE-ENTER`/`READWRAP` (timed-spin counters).
- Censuses added and kept this session, each with a measured zero structural delta: `REQFILL`,
  `STREAM-OPEN`, `STUB-SLOT`, `BC140-REC`. Two of my own claims were retired on the way
  (F-174, F-178) and one reversed-then-restored (F-179 vs F-181) - the ledger has the details.
- Frontier unchanged and clean: `LISTLINE 171`, `Fatal 0`, `FATAL-SOFT 0`, `C0000005 0`,
  `SEEK-DEAD 0`, `TYPINIT 3/3`, `GETDEV 694`, `CP-DRAW 166`, `PRESENT 34`, `swfCMD 0`,
  `XSF-INFLATE 0`, **`DRAW_INDEXED 0`**. B4's gate and B5 criteria 1-2 still unmet.

## 2026-09-24 ~17:45 - **F-177: the menu's root cause is a device vtable slot we answer with zero - `pgStreamer::Open` sets `record.length := dev->vtable[+84](dev)`, the `memory:` device's +84 is the shared `li r3,0; blr` stub, and we additionally force that stub to 0. `w185` == `w183` on all 17 counters, so the new `STREAM-OPEN` census is admissible and stays**

- **The store, verbatim** (`sub_821BCE68` = `pgStreamer::Open`, `ppc_recomp.14.cpp:21190`-`21250`):
  call the factory fnptr at `[0x8283D1F0]`, then `bl sub_821CB488(name,1)` (=
  `fiDevice::GetDevice`) -> object; `stw obj,8(record)`; `lwz r10,84(vtable); bctrl`;
  **`stw r3,4(record)`**. F-172's `r30 = [record+4]` is exactly that value, and F-176 showed
  `sub_821BCB10` only searches these records, so nothing else writes it.
- **Measured** (`w185`): Open runs **7x**, returning handle ids `0,1,2,3,4,0x8004,0x10004`, and its
  **`r5` = `27,27,27,27,9,27,5442`** - byte-for-byte the `RSC5+0x04` word of the seven packages
  (legals/credits/garage/policecam/raceeditor 27, meshtextures 9, trash.xrn 5442). That independently
  confirms F-171's per-record package decode from the guest side. The three executed requests carry
  ids 4/0x8004/0x10004 = Opens #5/#6/#7.
- **Why it is 0**: the archive device `0x82012BDC` has a **real** `+84` (`0x821CC498`, which does
  `[dev+0]->vt[+144](dev, [dev+36]+off)`); the `memory:` device `0x82012918` has `+84 = +88 = +124 =
  0x821A5CC0` = `li r3,0; blr`. And `src/gpu_device.cpp:12642`-`12646` strongly overrides that stub
  with `ctx.r3 = 0` (installed so `sub_8218C760`'s `device+88` call wouldn't AV), pinning all
  thirteen slots that share it.
- **Fix design for F-178 (an implementation, not a mitigation)**: give the `memory:` device a real
  `+84` - it cannot be keyed on `sub_821A5CC0`'s address (thirteen slots share it), so install a
  distinct pointer at `kMemVtable + 84` returning the served body's size for the handle the stream
  carries (`MakeMemoryStream`/`XSF-BIND` already know that number). Pre-declared pass criteria:
  `READWRAP … r7=0 lr=821BC334` becomes non-zero, `INFLATE-ENTER`'s `st+0` stops being `0xFFFFFFF4`,
  `XMEM`'s `srcSz` stops being our constant 7,179,936. Revert if `LISTLINE`/`C0000005`/`SEEK-DEAD`
  regress. Alternative considered and not chosen: stop handing the memory device to archive-name
  opens (touches F-163's re-open path).
- Frontier unchanged and still clean: `LISTLINE 171`, `Fatal 0`, `FATAL-SOFT 0`, `C0000005 0`,
  `SEEK-DEAD 0`, `TYPINIT 3/3`, `GETDEV 694`, `CP-DRAW 166`, `PRESENT 34`, `READWRAP 278`,
  `INFLATE-ENTER 149`, `XSF-INFLATE 0`, `swfCMD 0`, **`DRAW_INDEXED 0`**. B4's gate and B5
  criteria 1-2 remain unmet. F-172's separate B4 lead (Type-0 `0x0A2F/0x0A30` size+address pair at
  `0x08A11000`/`0x08A15000`, unimplemented `PM4_WAIT_REG_MEM`) is still open.

## 2026-09-24 ~17:25 - **F-174: correcting myself twice before it costs a build - the streamer control block is `0x8283D190` (F-172's `0x8203D190` came from mis-signing a `lis`), and `sub_821867A0` is NOT the writer of the zero-count slot (F-173's mechanism withdrawn, its facts kept)**

- **Address fix, use this one:** `sub_821BC140`'s `lis r10,-32124` = `-2105278464` = `0x82840000`, and
  `addi r19,r10,-11888` -> **`r19 = 0x8283D190`**. Request-array base = `[0x8283D1C4]`, capacity-minus-one
  mask = `[0x8283D1A8]`. F-172's conclusion is untouched (length = `[r28+4]`, `r28 = [r19+52] +
  [task+0]*28`, and that length is 0), only the cited constant was wrong. Same failure mode as
  F-157's phantom `0x82861740`, caught statically this time.
- **Why F-173's writer claim fails:** every store inside `sub_821867A0` is to `r22 = r3` or
  `idx*28 + r22`, and its ONE caller (`sub_82187150+0x1A8`) passes `r1+224 + idx*28` - a caller-local
  buffer (visible in `REQFILL` itself: `r3=8EFFF1E0`, `r6/r7` 8 bytes apart in the same frame). So the
  `r5 = 0` there is **not** the origin of the zero `[slot+4]`. `REQFILL` stays (2 firings/boot,
  returns ids 3 and 4, registers-only, proven zero frontier delta) but it bounds a *request builder*,
  not the pool.
- **Where to look next, all static, one named starting point:** only five sites materialise
  `0x8283D190` - `sub_821BC140+0x24`, reads at `0x821BC674`/`0x821BC680`/`0x821BC694`, and
  `sub_821BCB10+0x44` (the `ENQ` chooser). Exactly one site materialises the array base
  `[0x8283D1C4]`: **`sub_821BCE68+0x2C`**, un-hooked. Read `sub_821BCE68` and those three reads
  (same code page as the inflate loop, plausibly its completion path) to find who sets a slot's
  `[+4]`. No new instrument needed for that, and `sub_821BC140` already has an owner so a second hook
  there would need rule 4 checked again.
- Unchanged frontier: `w182`/`w183` == `w180`/`w181` (LISTLINE 171, Fatal 0, FATAL-SOFT 0, C0000005 0,
  SEEK-DEAD 0, TYPINIT 3/3, GETDEV 694, CP-DRAW 166, PRESENT 34, DICTLOOKUP 22, [error] 14,
  INFLATE-ENTER 149, XSF-INFLATE 0, swfCMD 0, **DRAW_INDEXED 0**). B4's gate and B5 criteria 1-2 are
  still unmet; F-172's separate B4 lead (Type-0 `0x0A2F/0x0A30` size+address pair naming
  `0x08A11000`/`0x08A15000`, and unimplemented `PM4_WAIT_REG_MEM`) is still open and unverified.

## 2026-09-24 ~17:20 - **F-173: the zero inflate count traced to its only source - `sub_821867A0` (the streamer's request registrar) has exactly ONE caller, `sub_82187150+0x1A8`, and it is called twice per boot with `r5 = 0`; the new `REQFILL` census has a proven-zero frontier delta (`w183` == `w182` on all 17 counters) so it stays in the tree**

- Chain, all cited: `sub_821BC140` reads its transfer length as `[r28+4]` where
  `r28 = [0x8203D190+52] + [task+0]*28` (`ppc_recomp.14.cpp:18873` → `:18966`, no write to `r28`
  between - this re-confirms F-172 and my momentary doubt about it is closed: the surface-looking
  arithmetic after `:18966` reads *other fields of the same slot*). `sub_821867A0` writes that slot
  (four `[entry+4]` stores, one of them the **literal 6** when bit 1 of the request flags is set).
- `REQFILL … #1 r3=8EFFF1E0 r4=8EFFF980 **r5=00000000** r6=8EFFF170 r7=8EFFF178 -> r3=00000003`
  and `#2 … r5=00000000 … -> r3=00000004`. Four of the five args are stack pointers; **`r5` is the
  only scalar and it is 0 both times**. Return values are slot ids 3 and 4, and `REQDUMP #1`'s task
  selects slot **4** - the one `REQFILL #2` registered, whose `[+4]` the streamer later reads as 0.
- `sub_82187150` is reachable from `0x822FBBA0` = inside `sub_822FBAF8`, i.e. the same init chain
  whose `MSGBISECT 5-822FBAF8 RETURN` line the frontier already prints. So this is not a path that
  never runs; it is a path that runs with a zero length.
- **The guest knows the sizes.** The streamer task descriptors carry 3-dword `{virtual src, dst,
  size}` records (`REQDUMP #1 … 50000000 A47FD000 00002000 | 60000000 B7A01000 00080000 | …`), so
  the lengths exist in the context and simply do not reach the request slot.
- **Next step, static only (no build):** trace which of `sub_821867A0`'s four `[entry+4]` stores
  actually runs and from which register, then find that register's producer in
  `sub_82187150+0x140`-`0x1AC`. If a caller-side scalar is the missing size, the fix is a field
  transfer we control, not a codec.
- Census hygiene note: `REQFILL` is **registers-only on purpose** - `src/gpu_device.cpp:8404`-ff
  records that a census in this same subsystem AV'd its consumer by reading guest memory. Keep it
  that way if it is extended.
- Plan state unchanged: B1/B2/B3 closed, **B4's gate (`DRAW_INDEXED >= 1` from a non-zero constant
  bank) unmet**, B5 criteria 1-2 unmet / criterion 3 met. F-172's separate B4 lead (the Type-0
  `0x0A2F/0x0A30` size+address pair at `0x08A11000`/`0x08A15000` and unimplemented `WAIT_REG_MEM`)
  is still unverified and still open.

## 2026-09-24 ~17:05 - **F-172: the "RSC5 payload codec" question is CLOSED as the wrong question - the guest's inflate loop is entered with a byte count of 0, and every XMem line at this frontier is our own re-point machinery feeding the guest's LZX decoder a semaphore handle. `w182` == `w181` on every counter; the read-site edit that produced that proof is REVERTED, so HEAD stays `3584fca`**

- **Read the contract off the generated listing, not from a guess:** `sub_821BC140` is the *only*
  caller of `zlibInflater::InflateBegin` (`ppc_xrefs calls 0x821D5E10` -> `0x821BC37C`). It takes
  `r30 = [r28+4]` (bytes still to inflate), asks the device for `min(r30, 32768)` into a **stack
  buffer at `r1+128`**, and primes the stack inflater state **only if the read returns exactly that
  many bytes**: `st+0 = r3 - r29`, `st+4 = (r1+128) + r29`, then `InflateBegin(r4 = r1+96)`
  (`ppc_recomp.14.cpp:19040`-`19140`). `InflateBegin` wants `st+8 == 0`, compares `*st+4` against
  `0x0FF512EF`, consumes 8, and calls `sub_8244FF20` = **XMemDecompress** - so the LZX stream starts
  at **`pkg+0x14`**, and the magic appears exactly once per package, always at `pkg+0x0C` (measured
  across each package's whole declared range).
- **The fingerprint that proves it:** `READWRAP sub_821CC6F0 #1 r5=00060000 r6=006D8F40 r7=0 ret=0
  lr=821BC334` = a **0-byte** inflate read, and the very next `INFLATE-ENTER #1 st=006D8F20
  in=4294967284 inPtr=006D8F4C` is that zero read *passed through the priming arithmetic*:
  `0 - 12 = 0xFFFFFFF4` and `(r1+128)+12 = 0x006D8F4C`, with `r1 = 006D8EC0` visible as `r1in=`. Two
  derivations agreeing to the dword.
- **So the XMem census has been measuring us:** all 34 `XMEM` lines carry our hard-coded
  `j1SrcSz=7179936`/`j1DestSz=7179940` (`src/gpu_device.cpp:4322`-`4323`) and `ret=0`, and
  `src=CA327114` is `CA327100`+0x14 where `CA327100` is a **semaphore** (`SEMA-CREATE #31`,
  `PRELOAD-CTX #1 arcDev=CA327100`). Withdraw these: "the payload is encrypted / an unimplemented
  codec" (F-170) and "the one inflate door was reached and produced 0" (F-091/F-102's reading) - the
  door has never been fed real bytes.
- **Refuted in the same build (my own hypothesis, recorded so nobody re-walks it):** the
  `sub_821CC6F0` read-site *is not the truncator*. Preferring the record's validated package there and
  sizing the bounce by the declared length changed **nothing** (`w182` identical to `w181` across
  `LISTLINE 171`, `TYPINIT 3/3`, `Fatal 0`, `FATAL-SOFT 0`, `C0000005 0`, `SEEK-DEAD 0`, `GETDEV 694`,
  `CP-DRAW 166`, `PRESENT 34`, `DICTLOOKUP 22`, `[error] 14`, `INFLATE-ENTER 149`, `XSF-INFLATE 0`,
  `swfCMD 0`, `DRAW_INDEXED 0`) because `CC6F0-PKGSUBST`/`CC6F0-PKGCONT` fire **0 times** - the branch
  is dead. F-171's "open asymmetry at `:10032`" is therefore inert too. Edit reverted; tree == HEAD.
- **Next step, named:** find who fills `[r28+4]` for a container member and why it is 0 while the TOC
  entry has the size (`TOC76-LAYOUT +4=[0002FFDD 000A001B D454283D 0040626E]`). `r28` = {+4 count,
  +8 device}; the census serve already publishes a size through `XSF-POSTOPEN-SERVE` / the
  `CDE/Open (CCEA0)` wire (`src/gpu_device.cpp:800`-ff). Read `sub_821BC140`'s entry block for
  `r28`'s provenance - no new instrument needed. If the count becomes real, either the guest's LZX
  decodes (UI follows) or it prints `not in XCompress format` through its own path; **both are
  answers.**
- Plan state: B1/B2/B3 closed. **B4's gate (`DRAW_INDEXED >= 1` from a non-zero constant bank)
  unmet**; B5 criteria 1-2 unmet, criterion 3 (zero `FATAL-SOFT`) met.
- **New lead for B4, found in the same `w182` and NOT yet verified (do not cite it as a finding
  until it is):** the two `PKT-CAP` windows that hold real ring bytes decode cleanly by hand -
  `00000A31 02000000` and `00010A2F 00001000 08A11000` are **Type-0 register writes** (reg `0x0A31` =
  1 dword, reg `0x0A2F` = 2 dwords), and `C0043C00 00000003 00000A31 00000000 80000000 00000008` is
  **`PM4_WAIT_REG_MEM`** (op `0x3C`, `wait_info=3`, poll reg `0x0A31`, ref 0, mask `0x80000000`,
  `wait=8`) - which is one of the ten opcodes sitting in `CP-T3-CENSUS` as unhandled. The `0x0A2F`
  payloads are `0x00001000 0x08A11000` then `0x00001000 0x08A15000` = a size/64-bit-address pair
  pointing at **16 KB blocks 0x4000 apart**, i.e. the shape of an indirect-buffer submission. The
  summaries for those windows read `t0=146/147/151 indirect=3/4 dw=307..335 clamped=1`, so the scan
  *is* counting Type-0 packets but only over a clamped few hundred dwords. Question to ask next,
  statically: does `DrainPacketAt` follow indirection at all (implemented ops are
  `0x3F/0x48/0x3D/0x22/0x36/0x21/0x2B` - `0x33` is not among them, and no `0x33` line appears in
  `CP-T3-CENSUS` either), and if the ring's real packets live behind that pair, F-159's "the register
  file contains no VB/IB/constant state" is a statement about a walk that never entered them.

## 2026-09-24 ~16:30 - **F-171 (this commit): each container member is now served from the package its OWN TOC record names (magic + ID verified), and the local archive was replaced with a complete copy - so all seven UI packages exist and bind at their own sizes. `w180`/`w181` identical, `Fatal error 0` / `FATAL-SOFT 0` / `C0000005 0` / `TYPINIT 3/3`**

- **The bug was a 20-bit mask plus a scan-bounded table.** `MclaPkgOffFromTocW2` used `& 0x00FFF000`,
  so `credits.xsf`'s word[2] `0x6496F01B` decoded to `0x96F000` - any package above 16 MB was
  unreachable - and membership in `BuildRscPackageTable` (which scans only `kScan = 0x2000000`) was
  required, so a correct candidate was still rejected. Now `& 0xFFFFF000` and the caller validates
  **RSC5 magic at `pkg+0` AND `[pkg+8] == record word[3]`** (`src/gpu_device.cpp:278`, `:702`-`730`).
  That validation is what lets the table go away: a wrong offset cannot pass both.
- **The archive is whole** (F-170's required action): replaced with the complete 2,130,739,200-byte
  copy from `E:\MCLA-Standalone\game_data\`; measured `last_nonzero = 2,130,710,477` (was
  0x5C000000). The truncated file is preserved as `xarchive_cache.rpf.truncated-20260924`, not
  deleted. All seven packages now show an RSC5 header whose ID equals its record's word[3].
- **Measured (w180 + w181, same binary):** `PKG-SUBST` names 7 distinct packages
  (00060000/000A0000/0035A000/6496F000/64980000/64CA3000/64CB0000) where every `.xsf` used to get
  legals' body; `XSF-BIND size=` per path = credits 29,655 / garage 1,066,057 / policecam 19,337 /
  raceeditor 143,069. Unchanged-or-better frontier: `LISTLINE 171`, `GETDEV 694`, `CP-DRAW 166`,
  `PRESENT 34`, `DICTLOOKUP 22`, `[error] 14`, GFx 4→5, `DRAW_INDEXED 0`.
- **Still the blocker on this route, and it is now offline-decidable:** `XSF-INFLATE` 0 and `swfCMD`
  0 - the RSC5 payload at `0x0FF512EF` is not raw deflate in any framing tried over `+0x14..+0x2F`
  (F-170). Seven complete packages + the guest's own inflate entry `sub_821D5E10` = a codec/keys
  problem that needs no soak loop to attack.
- **Recorded, not silently carried:** the read/continuation site (`src/gpu_device.cpp:10032`-`10036`)
  still prefers `MclaPreferredPkgOffForPath` and does no magic/ID validation, so it can bind a member
  to the substring-mapped package. The map is a *labelled* fallback only at the census site (`:730`).
  Watch `CC6F0-PKGSUBST` when that one is retired.
- Plan state unchanged: B1/B2/B3 closed; **B4's gate (`DRAW_INDEXED >= 1` from a non-zero constant
  bank) unmet**; B5 criterion 3 (zero `FATAL-SOFT` masking) met, criteria 1-2 unmet.

## 2026-09-24 ~16:00 - F-170: STOP on the UI/menu until the archive is re-acquired. build/game_data/xarchive_cache.rpf is a TRUNCATED COPY - 587,235,328 bytes (27.6%) past 0x5C000000 are zeros, and 4 of the 5 UI .xsf packages live in that tail

- Found offline, no soak needed. A TOC record's word[1] is the member SIZE and word[2] is
  (packageOffset | headerLength), so each UI file names its own package: credits 0x6496F000,
  garage 0x64980000, policecam 0x64CA3000, raceeditor 0x64CB0000 - all past the last non-zero byte
  (0x5C000000). No other volume reaches that far (audio is 1,615,757,312 bytes), which also corrects
  F-167's volume-selector guess.
- Present and ID-verified: legals.xsf 0xA0000, meshtextures.xtd 0x60000, trash.xrn 0x35A000. So the
  "every .xsf -> 0xA0000" substring map is pointing the UI at the one .xsf package on this disk, not
  making an arbitrary choice.
- Second blocker on the package that does exist: its payload is not deflate (every framing of
  +0x14..+0x2F tried, raw windows -15/-12/15, nothing inflates) and XSF-INFLATE has fired 0 times in
  all of today's soaks, while W34-NOGFX / nPtr=0 say the movie gets no tags. Encrypted, or a codec
  behind the 0x0FF512EF header that we have not implemented.
- Action is data recovery, not code: re-copy xarchive_cache.rpf and verify it is materialized through
  0x7F008000 before more menu work. Prime suspect: the recorded E: volume trouble (09-20 data loss,
  09-24 05:35 fsync failures).
- Frontier keeps F-163 (registration completes, C0000005 0) and F-169 (UI bodies at declared length).
  DRAW_INDEXED 0 and swfCMD 0 remain; B4's gate and B5 criteria 1-2 are unmet.

## 2026-09-24 ~15:50 - **F-169 (commit `3d93392`): the UI's RSC5 bodies are now served at their declared length - and the boot is BIMODAL, which invalidates single-soak verdicts on several counters we have been using all day**

- **Fixed:** `XSF-BIND size=` was `32768` for all six container members; it is now the length the
  package header declares at `+0x10` (`trash.xrn` 10,799 / four `.xsf` 196,553 / `meshtextures.xtd`
  240,531), non-containers untouched. Use the declared length as a **replacement**; `max()` with the
  package-table size over-reads into neighbouring archive data (`w174`: `Fatal error 1→4`).
- **Not yet won:** `swfCMD` is still 0 in all four soaks. The UI has its real bytes; what the guest
  does with them is the next question.
- **The hazard to internalise before reading any soak:** three soaks of the *same* binary give
  `TYPINIT 3/3, Fatal 0, [error] 14`, `3/3, 0, 14`, and `4/4, Fatal 1, [error] 28`. The last is the
  pre-fix profile, from the fixed executable. So `TYPINIT`, `Fatal error`, `FATAL-SOFT`, `[error]`,
  `DICTLOOKUP`, `REQ` and `nValidTag` are **two-soak minimum** signals, and F-163's
  `DICTLOOKUP 14→23` / `[error] 42→28` deltas should be treated as unproven (its `C0000005 1→0`,
  `SEEK-DEAD 1→0`, `TYPINIT-RET 0→4` held in every post-fix run, so the fix itself stands).
- **Still true and still the plan's problem:** `DRAW_INDEXED 0` in every soak today; all 34 `PRESENT`
  are heartbeat; B5's criteria 1-2 unmet; and `skinningData` remains a content gate (F-164).
## 2026-09-24 ~15:35 - **F-165..F-168: the menu's blocker is located and it is ours - the UI's RSC5 packages are served 6x short. Frontier is still `w171` / HEAD `ae944c8`; no code changed for these four (all offline archive reads)**

- **Symptom, measured in `w171`:** six different UI members all bind at `size=32768`
  (`credits/garage/policecam/raceeditor.xsf`, `meshtextures.xtd`, `trash.xrn`) while non-container
  members get true sizes (`fog.dds` 3,268,608 / `preload.list` 1246). Downstream that is what an empty
  UI looks like: `W32-CONSTRUCT-CENSUS arr=0 nValidTag=0`, `W26-PLUS24-NODE swfc=0`, `W34-NOGFX`,
  `swfCMD` 0 in every soak.
- **`RSC5` header layout, 3 for 3 from the archive:** `+00` magic `05435352` | `+04` header length
  (27/9/66) | `+08` package ID | `+0C` `0x0FF512EF` (Xcompress) | **`+10` the UNCOMPRESSED size** =
  `legals.xsf` 196,553 / `meshtextures.xtd` 240,531 / `trash.xrn` 10,799. A 32,768 bind is therefore a
  truncation, and `legals.xsf` is the boot's first screen.
- **What is NOT the bug (three dead ends closed so nobody re-walks them):** the TOC offset is not the
  data (F-166: high-entropy bytes at every UI `tocOff`); the substring map is not what misdirects
  `legals`/`meshtextures` (F-167: `MclaPreferredPkgOffForPath` and the TOC decode agree for them, and
  `:686` already prefers the substring, so flipping the priority is a no-op); and F-126's "w[3] is
  only FLAGS" is now too strong (w3 == package ID at `+8` in 3 of 3 resolvable cases).
- **Open, and it is one experiment:** is the *stored* length elsewhere in the header (the trailing
  `00 50 62 00 74 13 00 70 00 00 ff 5f` is unread), or is simply loading a bigger window enough? The
  window is capped at `0x8000` in `MclaLoadPkgWindow` (`src/gpu_device.cpp:309-311`) and floored to the
  same at `:689-690`, and `XSF-INFLATE` can only expand what it was given. Raise it keyed on `+0x10`,
  then look for per-path `XSF-BIND size=` and `nValidTag > 0` / any `swfCMD` line.
- **Measurement discipline from this session (F-164/F-166):** do not add log lines or per-call reads
  to measure it - a second line plus ~22 reads in one hook moved `Fatal error 1->4` and `FATAL-SOFT
  1->7`. And `INFLATE` / the `fatal`-substring count are run-unstable (358 / 17,220 / 7,597 / 5,022
  across consecutive boots); rely on `LISTLINE`, `TYPINIT`/`TYPINIT-RET`, `DICTLOOKUP`, `SLOT-*`,
  `C0000005`, `Fatal error`, `[error]`.
- **Also still open from F-164:** `skinningData` is a content gate (the `.mtlgeo` templates are not in
  the served archive), so the vehicle-material route stays closed; the UI route above is the live one.
## 2026-09-24 ~15:20 - **F-163 IS THE FRONTIER NOW (`w171`, commit `0136855`): the entity-type registration completes for the first time, and F-164 shows the `skinningData` gate is a content gate one level up (the `.mtlgeo` templates are not in the archive we serve)**

- **The fix.** All 179 `memory:$` re-opens come from one site (`lr=821BE988`, inside the guest's own
  `sub_821BE8D8` tail), so F-153/F-155/F-156's blanket object return re-shaped 178 consumers that
  legitimately store a slot handle. The dereferencing caller is exactly one - `sub_82191040`, seen as
  `BE8D8-CALLER #4 lr=82191070 first at n=190` - so `sub_821BE8D8` now latches a one-shot flag around
  *that* call and `sub_821BE0C8` returns a guest-shaped stream object only then (4 fires/boot).
- **Measured (`w171` vs `w170`, deterministic counters only):** `C0000005 1->0`, `VEH-NEUTRAL 1->0`,
  `SEEK-DEAD 1->0`, `TYPINIT` 4 enters / `TYPINIT-RET 0->4`, `DICTLOOKUP 14->23`, `REQ 135->154`,
  `[error] 42->28`, with `LISTLINE 171`, `GETDEV 694`, `CP-DRAW 166`, `PRESENT 34`, `DRAW_INDEXED 0`
  unchanged. Cost stated: `Fatal error 0->1` / `FATAL-SOFT 0->1` (B5 criterion 3 regresses) because the
  `skinningData` lookup is now actually reached - `SHGRP-VARS` sees
  `group=A003CA30 arr=A003CA80 nvars=1` instead of the `group=0` it has carried since w138.
- **F-164 - do not re-litigate the parser.** All ten `entity.type` spans inflate cleanly offline and
  none declares `skinningData`; they reference `Template "RimMain"` / `blackmatte 0 { }` and the
  material files (`T:/mc4/art/.../ext_matteblack.mtlgeo`) have **0 TOC records** in
  `xarchive_cache.rpf` (control: `entity.type` returns 12 in the same run). The group's single var
  points at a name buffer of 16 zero bytes, i.e. an unresolved template placeholder. B4's gate is not
  reachable through these vehicle-material groups.
- **Two measurement hazards found the hard way (`w172`/`w173`, both reverted):** a second log line +
  ~22 extra per-call reads in `sub_82193AF8` moved `Fatal error 1->4` and `FATAL-SOFT 1->7`; and
  `INFLATE` / the `fatal`-substring line count swing wildly boot to boot (358 / 17,220 / 7,597 /
  5,022, two of them the same binary) - cite them as context, never as a gain.
- **State:** HEAD `0136855` + these docs; `src/` is exactly the F-163 code (rebuilt exe 97,553,408 B =
  the `w171` binary). Ledger to F-164, census 138 markers.
- **Candidate next steps, both consistent with the objective:** (a) the UI/GFx route - the boot already
  shows `GFx 3` / `UILOAD 1` but `swfCMD 0`, i.e. the menu's own draw path; (b) a group whose vars are
  declared inline - the `RimMain 1 { shaderMaterialId { int 2 } }` form above proves that shape exists
  in this content, so a material that resolves without the missing templates may draw.
## 2026-09-24 ~14:55 - **F-161 (commit `818c158`, pushed): step 2 of the slot-release work is REFUTED by measurement and reverted - `w168`/HEAD is the frontier again**

- Extending F-160's release to the **read** sites (`sub_821BE250`/`sub_821BE710`, at the exact moment
  `slot pos >= size` - F-135 tier-1's own condition) was built and soaked as `w169`: `Fatal error 0→2`,
  `FATAL-SOFT 0→3`, fatal-shaped lines `37→5,946`, `INFLATE 358→168`, `[error] 42→61`, while
  `LISTLINE 171` / `TYPINIT 1` / `GETDEV 694` / `CP-DRAW 166` / `DRAW_INDEXED 0` did not move at all.
- **Why:** `SLOT-RECYCLE-SHARED` legitimately hands the same index to consecutive bodies (all of them
  are described by the one shared static `kMemStreamSlot`), so a slot that reads as "consumed" IS the
  slot another live handle is still aliasing - `w169` shows 6 of 12 releases hitting recycled `h=15`.
  The copy-out site stays the only provable-dead point (the bytes are already in `dst`).
- **So the retirement order is fixed:** remove the `kMemStreamSlot` shared-static aliasing so each
  body owns a distinct slot, *then* release on consumption, *then* F-135/F-135b can go. Releasing
  better cannot do it. The 16-entry bound is the guest's own (decoded at `0x821CB2B0`-`0x821CB2BC`),
  so widening the table is not an option either.
- **State:** `src/gpu_device.cpp` is comment-only vs the F-160 commit and the rebuild is byte-size
  identical to the `w168` binary (97542144 B), so `w168` remains the measured frontier - no soak
  burned re-proving it. Census tracks 136 markers; ledger to F-161.
- **Still open from the 14:40 block:** F-159's refutation of B4's premise stands (the guest submits no
  geometry at this frontier), and the user has not yet re-approved the change of means.

## 2026-09-24 ~14:40 - **F-160 (commits `1f1f653`, pushed): the slot-release mechanism is found, decoded and now used - and the frontier is unchanged, which is the honest part**

- `sub_821CB2A0` decoded from raw words: rejects `h<0 || h>=16` (**the 16-entry bound is the guest's
  own**, not our constant), indexes `0x82860740+h*16`, rejects an empty entry, frees `[entry+0]` only
  when the flag byte at `+12` is non-zero, then `stw r11,0(r31)` - the only store in the image that
  releases a table entry. It is a **Close**, so F-135/F-153's "device Seek at vtable+44" is wrong.
- `w167` installed a read-only census on it **first** (rule 1): `SLOT-CLOSE 0` with every frontier
  marker identical to `w161` (`LISTLINE 171`, `TYPINIT 1`, `C0000005 1`, `GETDEV 694`, `BE0C8 358`,
  `CP-DRAW 166`, `SLOT-REG 24`, `SLOT-RECYCLE 30`, `SLOT-RECYCLE-SHARED 24`, `[error] 42`). Nothing
  called it - our `BE8D8` host path was *emulating* the clear by hand.
- `w168` replaces that hand-written clear with a call through the guest's routine (r1 moved down 256
  bytes first because it saves LR at `-8(r1)` before its own `stwu`; flag byte left 0 so it must not
  free our buffer). Positive control fired: `BE8D8-CLOSE #1 h=1 slot=82860750 entry0_after=00000000`,
  `SLOT-CLOSE` 6× (`lr=8218C804`). Frontier still identical to `w161`.
- **What it does NOT do:** retire F-135/F-135b. 6 releases vs 173 bodies served, and
  `SLOT-RECYCLE 30` / `SLOT-RECYCLE-SHARED 24` are unchanged. Extending it means releasing on the
  `sub_821BE250`/`SlotTableServeRead` and `PACK` paths too, which needs a consumed-the-body signal
  (`pos` reaching `size` is not tracked for most bodies - that is exactly why F-135b's `pos>=size`
  test recycled only 1 of 15).
- **Committed state:** HEAD `1f1f653`, tree builds clean, `w168` = frontier. Census now tracks 136
  markers (`SLOT-CLOSE`, `BE8D8-CLOSE` added). Ledger runs to F-160.
- **Open plan question this session raised and did NOT resolve unilaterally:** F-159 refuted B4's
  premise (no geometry is submitted at this frontier, so the constant-capture step has no input). B4's
  gate is still the target but its means must change. See the F-159 entry; the user has not yet
  re-approved a pivot.
## 2026-09-24 ~14:25 - **F-158/F-159: B4's premise is EMPTY (measured three ways) - the guest has submitted no geometry, so the constant-capture step has nothing to capture. The blocker is now "why does the boot stop submitting", and it is measured, not assumed**

- **The three measurements (F-159, all re-verified from the log/source, not from a subagent
  summary).** (1) `sub_82420BA8` - the only producer of `DRAW_INDEXED` - is called **2x per boot**,
  both `r5=0` with the device's own stream count (`dev+12748`) at **0** → `DRAW-GATE dummy`,
  `plausible` never increments. (2) The 24 CP-side AUTO draws are all `numIdx=1 idxSize=0
  dmaBase=00000000` - and that site is census-only by design (`src/gpu_cp.cpp:643-647`), it pushes
  nothing. (3) The 22 distinct `0x2xxx` registers the guest pokes are **raster/backend state only**
  (`RB_SURFACE_INFO`, `PA_SC_*`, `VGT_MAX_VTX_INDX`, `SQ_PROGRAM_CNTL`, ... named against
  `.research/xenia/src/xenia/gpu/register_table.inc`) - no VB base/stride, no index buffer, no
  constant bank, and PM4 `0x2D SET_CONSTANT`/`0x2F LOAD_ALU_CONST` are not implemented at all
  (`src/gpu_cp.cpp:606-702`), while `CpExecImLoad` **discards the microcode** it loads.
- **Withdraw the F-139/F-140 basis.** `PKT-CAP` clamps every window to 256 dwords
  (`kPktCapMaxDwords`, `src/gpu_device.cpp:1574`) and scanned **904 dwords total** against windows
  requesting 131,072+; its `draw_indx=0 set_const=0` was a sample, not a property of the stream. The
  conclusion happened to survive (via measurement 2), the evidence did not.
- **The corrected frontier picture.** All 34 `PRESENT` are heartbeat (`HB-FLICKER #2880 frame=0`);
  `RenderThread: PRESENT` (the guest-kicked one) is **0 lines**. The CP is caught up
  (`pub=11 put=11 drains=8`) and the main thread parks in `NtDelayExecution` on a 30 ms poll
  (`WAIT[KWFSO] reason=3 to=30ms lr=8242FC1C`, 130 identical `PARK-SAMPLE`s). So the guest is idle in
  its own loop, not blocked on us - the next task is to name what that loop waits on.
- **F-158** (same commit): B5's criterion 1 as written is unsatisfiable - there is no
  `src/xam.cpp`. The real printers are `src/kernel/xam.cpp:318` (`buttons=`, cap 8) and
  `src/patches.cpp:744` (`buf=0x`, cap 100) and **both use the same `XamInputGetState[` prefix**, so
  the test is `grep "XamInputGetState\[.* buttons="`. Neither fires at this frontier (input is never
  polled before a menu).
- **Unchanged from the 14:10 block:** F-157 closed the stream-object re-open as a 3-build measured
  loss and withdrew the `0x82861740` phantom; `w161` is still the frontier (`LISTLINE 171`,
  `Fatal 0`, `FATAL-SOFT 0`, `TYPINIT 1`, `C0000005 1` VEH-masked). Census now tracks 134 markers
  (was 124) including `LISTLINE` itself.

## 2026-09-24 ~14:10 - **F-157: the stream-object re-open question is CLOSED as measured-negative (three builds), and F-154's `0x82861740` "second handle table" is withdrawn as a phantom. Frontier unchanged: `w161` = `LISTLINE 171`, `Fatal 0`, `FATAL-SOFT 0`, `TYPINIT 1`, `C0000005 1` (VEH-masked), `DRAW_INDEXED 0`**

- **What ran.** `docs/f154_staged_be0c8_object.patch` was NOT applied as written - its second-table
  writes are aimed at `0x82861740`, and a full-image `addis`+`addi` census of
  `build/cache/mcla_pe.bin` shows the guest forms no such constant (the only handle-table base is
  `0x82860740`, addis at `0x821CAF50`). Re-ran the object return twice without those writes:
  `w165` (fresh `Alloc` per open) and `w166` (one pooled `Alloc(8*64,16)`). Both reproduce `w164`
  exactly - `C0000005 0` and `SEEK-DEAD 0`, but `LISTLINE 171->167`, `TYPINIT 1->0`, `FACTORY 1->0`,
  `DICTLOOKUP 14->2`. Same four `embedded:/rage_*` + `rmptfx_collision` tokens lost every time.
- **Verdict.** The object shape itself costs the ground; neither the phantom writes nor guest-heap
  churn was the confound. Reverted (F-151's own condition); `src/gpu_device.cpp` is now
  code-identical to HEAD (comment-only diff), so `w161` remains the frontier baseline.
- **Corrected attribution (use this, not F-151's).** `sub_82191040` binds `r31` to **`sub_821BE8D8`**'s
  return (`generated/ppc_xenon/ppc_recomp.10.cpp:10912-10993`) and then uses `r31` as a stream object
  at four sites. The missing object is therefore *our host `BE8D8` return*
  (`src/gpu_device.cpp:12160`, printed as `stream=00000001`), one layer below where F-152..F-154 were
  editing. `sub_821BE0C8`'s index return is what its own consumers need.
- **Do not** re-try an object return at `sub_821BE0C8`, and do not treat the single VEH-masked
  `C0000005` as B4's blocker - `TYPINIT`/`REALIZE-CAST end=0x1E5`/`LISTLINE 171` all still happen
  with it present. If it is revisited it belongs at `sub_821BE8D8`'s return, and that requires
  removing the index/object duality in `MakeMemoryStream` rather than routing around it.
- **B4 state unchanged and still the next thing:** `DRAW_INDEXED 0` in all four builds; F-139/F-140
  measured every captured CP packet `set_const=0 load_alu=0 draw_indx=0`. Peer's F-155/F-156
  (texture decode path) is the other live thread on this frontier.

- **UPDATE 13:45 (supersedes the two bullets below on this question):** `SEEK-DEAD` ran and caught it (F-150..F-154). The `skinningData` fatal stays gone (`w160`/`w161`/`w163`: `Fatal error 0`, `FATAL-SOFT 0`), and the remaining `C0000005 1` is the guest's own `Seek`/`Read` on a value our `sub_821BE0C8` returns as a slot INDEX. `w164` measured a full fix attempt: it clears the AV but costs `LISTLINE 171->167`, so it was reverted. **Next action: `git apply docs/f154_staged_be0c8_object.patch`, build, verify `BUILD_RC`+exe mtime, soak `w165`** - it also feeds the memory device's own handle table at `0x82861740`, which is why the first attempt lost `LISTLINE`.

## 2026-09-24 ~13:00 - **F-143..F-150: the `skinningData` fatal is FIXED (commit `a654d1f`, pushed) and `w160` is the new frontier: `Fatal error 0`, `FATAL-SOFT 0` for the first time since `w138`. New blocker = the guest's own `Seek` on a stream whose device pointer is 0 (`C0000005 1`).** (Supersedes the 10:35 block, whose "content wall" premise is withdrawn.)

- **What the fatal actually was.** `Required grmShaderGroupVar 'skinningData' not found.` is raised by `sub_82193AF8(group=0, "skinningData", required=1)`. `group` is **`[object+8]`** of the type object `sub_82379C68` allocates, and `sub_82611298` stores 0 there *by construction*; the only writer is `sub_826113A8`, whose first act is a resource lookup `sub_821CA6A8(0x827D7770, "entity.type", "type", 0, 1)`. That "type" argument is a **file class**, not an entity type: `0x827D7770` is the resource path manager (it is fed `$/resources/ui`, `globaltex`, `$/tune/shaders/lib` by `sub_821CA540`), it composes `a:/archive/vehicle/shared_utility/sst_trail/entity.type` and calls `sub_821BDF20` to open it.
- **Root cause (F-148, proven both offline and in-guest).** That member is a **headerless raw-DEFLATE stream**, and the TOC's `size` word is the **inflated** length (255 stored -> 480 out; the text begins `Version: 103
shadinggroup {`). Our serve handed the guest the compressed bytes, so the first-token test in `sub_821CFE80(reader, "Version:", 0)` failed and the group was never published. `Version:` and `103` are the literal token and constant in `sub_82611018`, so the format was confirmed from the guest's own code, not guessed.
- **The fix (F-149).** `kTypeMemberSpans` + `kExpandTypeMembersInArchive` in `src/gpu_device.cpp:537`-ff register those ten members through F-105's existing expanded-span mechanism at the first archive I/O. No host-written word, no gate weakened. Proof in `w160`: `REALIZE-CAST ... tok='Version:' -> r3=00000001`, and `SHGRP-VARS` / `Fatal error` / `FATAL-SOFT` all **0**.
- **Withdrawn, do not repeat:** F-136's "skinningData is a proven content wall" (F-142 retracted the hash claim; F-149 kills it outright); F-145's "the file opens successfully" (F-147: `PATHMGR-OPEN`'s non-zero ret is one of three *reused static* wrappers `0x82860C18/C40/C68`, each with its own 4 KB buffer at `+0x1DF8`); F-143's "failed 128-byte allocation" and "type registry" framing.
- **Cost, stated (F-150).** `C0000005 0 -> 1`, VEH-neutralized. Resolved through `build/mcla.map` (same link, F-120): `sub_821864C0+0x71 -> sub_82192448+0x2E8 -> sub_82191040+0x413 -> sub_821BE568+0x31D`. `sub_821BE568` is a buffered-stream **Seek**, and its `loc_821BE5D0` is `lwz r3,0(r31) / lwz r4,4(r31) / lwz r11,0(r3) / lwz r10,44(r11) / bctrl` - it loads the **device** out of `[stream+0]`, and the fault registers say exactly that (`r3=0`, `r4=0`, `lr=0x821BE5F4`, guest address 0). So the guest seeks a stream object that is live but **unbound** - the same dead-wrapper shape F-122 fixed for the *read* path (`sub_821BE250`), with no equivalent for Seek. Its caller `sub_82191040` does lookup -> `sub_821BE8D8` (load whole file) -> `sub_821BE4F0` (a resource-type code: 26 = the text/reader branch) -> and for the other codes calls `Seek(obj, 0)` **without checking `[obj+0]`**.
- **In flight at the time of writing:** `w161` runs a read-only `SEEK-DEAD` census on `sub_821BE568` (`src/gpu_device.cpp:12580`-ff, rule 4 clean, one checked read per call so F-125 timing perturbation is bounded) naming the object and its `dev/h/cur/end/cap`. Read it before proposing anything: the fix belongs in *binding that object's device+handle for these loads* (F-122/F-127/F-128 machinery), not in a null guard.
- **Plan state.** B1/B2/B3 closed. **B4 gate still unmet and its premise still empty** (`DRAW_INDEXED 0`; F-139/F-140 measured every captured packet `set_const=0 load_alu=0 draw_indx=0`) - the renderer cannot be fed until entity-type registration completes, which is what this Seek blocks. B5: criterion 3 (zero FATAL-SOFT) met at `w160`; criteria 1-2 (real `XamInputGetState`, guest-drawn `PRESENT-FB`) unmet.
- **Two masking sources now live in `src/` from concurrent sessions** - quote them with any frontier claim: `P10-PRE` poison-id skip (`task_dispatch_trace.cpp:780`-ff, 13 / 5,812 / 59,505 per run depending on mode) and `FIXWALK-GATE ... delta-0 skip` (`task_dispatch_trace.cpp:1048`, ~38,800 lines/soak, another session's work in progress).
- **Tool gotchas learned this session (do not re-derive).** `tools/rpf_offline.py find` is sound only against `build/toc_parsed.bin` - against `build/toc_decrypted.bin` it returns 0 records even for a path the same soak proves present, so always run a control. `DEVCLAIM`'s `r3=0` is **not** a decline (that loop keys on `r4 != -1`). Build with `build_on_e.bat build` - `build_on_c.bat` no longer exists and the `mcla-boot-cycle` skill still names it. `tools/addr_owners.py --check` **misses** `MCLA_BISECT_HOOK`-defined hooks (it reported `sub_821CA540` free; the compiler found the duplicate at `gpu_device.cpp:9779`) - grep the symbol as well as running the tool.

## 2026-09-24 ~10:35 — **F-136 (supersedes only the "next step" line of the 10:15 block below): the gate F-135 revealed is a CONTENT wall, and the renderer feed has not moved yet.**

- `Required grmShaderGroupVar 'skinningData' not found.` = `sub_82193AF8(group, name, required=1)`, called by the game's material setup `sub_82507FE0` against a hardcoded required-name list. The resolver path (`sub_8218A568` → `sub_821C9790`) **case-folds plaintext and never hashes**, so a plaintext search of the image is the guest's own test.
- Measured: `'skinningData'` occurs **once** in `mcla_pe.bin` (10,354,688 B) — the code-side name at `0x8204A408` — and **not once** inside the 13 embedded `rgxa` containers. Positive control fired: `VS_TransformLit` and 106 `Texture` strings DO appear inside that span, so container name tables are plaintext.
- **The F-135 fix advanced the file walk (LISTLINE 167→171) but not the renderer feed**: `w138` vs `w147` CP counts are identical (`PKT-CAP summary 15`, `CP-REG-T 1171`, `INDIRECT_BUFFER 11`, `DRAW-SEAM 10`, `CP-DRAW 166`, `DRAW_INDEXED 0`) and no CP marker occurs after the fatal. So B4's gate is still blocked, and this gate is on its path.
- Group layout for whoever probes next: var count = halfword `[group+12]`, var pointer array = `[group+8]`, and `count<=0` jumps **straight to the same fatal** — so "empty group" and "different group" are indistinguishable from the log (the group pointer is a callee-saved r23, and r14-r31 are host locals here).
- Decision point for the plan, stated rather than assumed: B4 cannot be satisfied through the `skinningData` material from resident content (the only candidate source is the archive's v1 effect family, which F-131 showed this v3 runtime rejects). Next move is either to drive the draw from a shader group whose variables ARE resident, or to record B4 as content-blocked and proceed on the paths that are not (the `PlaceTexture` bad-resource-type and invalid-fixup gates).
## 2026-09-24 ~10:15 — **F-132…F-135: the frontier's `0xFFFFFFFF` is root-caused and FIXED — the guest's own `GetSize` error return, caused by our host slot table having no recycle. `LISTLINE 167 → 171` (four more embedded effects load) and the boot now dies inside the renderer: `grmShaderGroupVar 'skinningData' not found`.** (Supersedes every block below on the frontier question; `w138` remains the committed good-mode baseline for marker comparison, `w147` is the new frontier soak.)

- **F-132** The last deterministic guest event, identical every boot: `LISTLINE #167` → `BDF20 #532 path='embedded:/fxl_final/rage_postfx.fxc' ret=0x82860C40` → `AllocPhysical … size=0xffffffff align=0x10` (`w138:12555`) → park. The "3.5 min of silence" is the guest's own buffered-stream refill memcpy (`lr=0x821BE3BC`, `ppc_recomp.14.cpp:24266-24300`), ~321 MB in `w140`.
- **F-133** Store-level census measured the copy's length register: `r5 = 0xFFFFFFFF`. The census itself perturbed the frontier (`P5-PHYS`/`W34-*` stopped firing) and is reverted; the datum stands because it is corroborated by baseline lines.
- **F-134** Full attribution, no instrument left standing: not `XAllocMem` (`XALLOC-HUGE` 0 in `w143`) and not `MmAllocatePhysicalMemoryEx`; it is the guest's `__xtl_alloc`, fed by `sub_821BE8D8`'s unchecked `size = vt[+56](dev,handle)`, and `GetSize` (`0x821CD3C8` / `0x821CABB8`, both decoded from `mcla_pe.bin`) answers `li r3,-1` for a handle the guest's Seek contract rejects. `BE8D8-RAGESZ` found the single doomed call with `h=0x82905500` — the pointer our own `AFB76-HIT` returned once `GuestSlotTableInsert` ran out of the 15 usable indices.
- **F-135 (the fix, `src/gpu_device.cpp:11652`)** Recycle a slot before falling back to a pointer. Iteration 1 (`pos >= size`) was insufficient and measured so (`w146`: still 8 `SLOT-TABLE-FULL`, still doomed); iteration 2 reuses the index this same host path last handed out — labelled MITIGATION, registered in `PROGRAM_GUIDE` §7, justified by `MakeMemoryStream` already sharing the one static `kMemStreamSlot`.
- Verified frontier (`w147`, 205 s, `RD-SUBMIT 24` = good mode): `size=0xffffffff` **0**, `doomed=1` **0**, `SLOT-TABLE-FULL` **0**, `LISTLINE` **171**, no `CDCD-FILL` storm at comparable duration (`w140` 4,041 → `w147` 24), `C0000005 0`, `swfCMD 0`, `GETDEV 694`, `CP-DRAW 166`, `PRESENT 34`, `PRESENT-FB 4`, `DRAW_INDEXED 0`.
- **Cost to be honest about:** `Fatal error 0 → 10`, `FATAL-SOFT 0 → 18`, so B5's zero-masking criterion regressed while B4's feed advanced. The masked fatals are new gates, all named: `Required grmShaderGroupVar 'skinningData' not found.` (`r4` string at `0x8204A408`, `lr=82193BA0`) preceded by `P5-LOOKUP … r4=CDCDCDCD -> FFFFFFFF POISON` (`lr=8224C074`, 14,185 attempts), `Resource 'Invalid fixup, address is neither virtual nor physical'` (`lr=82184514`), `Bad resource type %d in grcTextureFactoryXenon::PlaceTexture` (`lr=8217EC4C`).
- **Next step (B4):** the poison key in `P5-LOOKUP` is one level below the `skinningData` failure — name what should have written that handle for the shader group, rather than adding another magic-word mitigation. `BE710-MAGIC` went 166 → 332 with this fix, so its retirement condition (F-128) is further from being met, not closer.

## 2026-09-24 ~08:08 — **F-130 + F-131: the archive-shader route is CLOSED by content vintage, not by a host bug. Frontier restored in `build/w138.log`; B4's shader feed must come from the XEX's own `embedded:` containers.**

- F-130 (kept, correct, inert at the frontier): `ApplyExpandedSpans` substitutes a member only when it fits whole inside one read window, so page-straddling members reached the guest still DEFLATE-compressed - measured by `MEMBER-EXPAND` firing for just 6 offsets with **zero** `-FAIL`/`-SIZE` lines, and `w134`'s `pass=0` 0 / `72677861` 0. `HostServeUiBody` now prefers a candidate whose head is a real container magic and inflates a non-magic candidate with `mcla::RawInflate` first (`w136`: `XSF-INFLATE … off=001DD1E8 head=9556CD6F->72677861`).
- F-131 (the closed door, measured offline per rule 3): image `0x827D2DD0` = `rgxa 03 ff 03 10` + `VS_TransformLit` (13 `rgxa` containers in the XEX); the archive member at its own TOC `0x1DD1E8`/`0xC62` = `rgxa 01 ff 01 12` + `VS_UnlitTransform`. Different version fields, same magic - which is exactly what `sub_8218C760` reports as `'Old version of rage effect found. You need to recompile your shaders!'` (`lr=8218C864`). Delivering the *correctly decoded* archive body (`w136`) still ends there, so this is content vintage: the prototype's effect runtime is v3, the retail cache's compiled shaders are v1.
- Reverted accordingly: no pending-open serve, and `g_servedOnce`/`XSF-BIND-REGONLY` are gone from the file. Kept: the magic-preferred candidate pass + per-candidate inflate, `BE710-MAGIC-CENSUS`/`BE710-BODY`, and the labelled `kBe710MagicWrite = true` switch.
- Verified frontier (`w138`, good-mode): `LISTLINE 167`, `Fatal error 0`, `FATAL-SOFT 0`, `C0000005 0`, `CP-DRAW 166`, `GETDEV 694`, `DISCCHK2 41`, `PRESENT-FB 4`, `GFx 3`, `XSF-INFLATE 0`, `DRAW_INDEXED 0`.
- **Where that leaves B4:** the shader bytes for the UI must come from the embedded family the guest already opens (`AFB8-IN #1 path='embedded:/fxl_final/rage_im.fxc'`, device `827D838C`) — the `rgxa v3` set at `0x827d2dd0…0x82801b00` — not from `xarchive_cache.rpf`. The next concrete step is to enumerate what the guest asks those embedded streams for (their reads are the ones `BE710-MAGIC` currently stamps) and serve the image's own containers from their real headers, then re-check whether `plausible`/`SETSTREAMS`/`DRAW_INDEXED` move. Do not re-try archive `.fxc` bodies: five soaks now prove the version gate stops them.

## 2026-09-24 ~08:46 — **F-129: what the rage-effect gate is handed is a name list sliced from mid-string, plus archive members that are still undecrypted (two different members share the first 8 bytes `ED5C0D70 1BC7757E`). Census committed read-only; frontier equal to `w128`.**

- `w132` `BE710-BODY #68` (`size=3170`) = `'imeAlpha.fx' CRLF 'UnlitRuntimeColor.f…'` — the 3,170-byte member is *name-table text* at a non-record offset, and `HostServeUiBody`'s only candidate filter rejects sentinel words (`0/CDCDCDCD/FFFFFFFF`), which text and ciphertext both pass. Defect 1: content-blind candidate acceptance.
- Defect 2: five of six bodies are high-entropy with no zlib header, and `#71`/`#72` (20,882 B / 19,328 B, different members) begin identically — a keystream signature, so non-list members reach the guest still encrypted. F-105's `MarkMemberExpanded` expansion covers the three `.list` spans and nothing else.
- This closes F-128 §4's question: the gap is both a wrong candidate offset and a missing decode — not our read position. Pass condition for the next attempt stays mechanical: with `kBe710MagicWrite = false`, the pipeline must deliver a body whose first word is `0x61786772`. T41.11 order: make candidate acceptance content-based (log the reject), then locate the guest's own archive decode (the repeated keystream start is the fingerprint; `tools/ppc_xrefs.py find-str` on the archive header strings). Do not write another host-side word over it - F-128 proved that is what hides this layer.

## 2026-09-24 ~08:40 — **F-128: `BE710-MAGIC` fires 166× per boot (not 2), and removing it for one call ends the boot at the rage-effect gate — the mitigation is now proved load-bearing by control, and the real gap is the `.fxc` transform.** Frontier `build/w128.log`; `src/` carries a read-only census + a labelled switch at `true`.

- ON/OFF pair on the same tree: `w128` (ON) `LISTLINE 167`, `Fatal error 0`, `C0000005 0`, `CP-DRAW 166`, 166 census lines. `w130` (OFF, one `constexpr` flag) → `BE710-MAGIC-OFF` 1 line, then `'%s: Old version of rage effect found. You need to recompile your shaders!'`, `Fatal error 1`, `FATAL-SOFT 1`, `LISTLINE 1`, `GETDEV 196`, `DISCCHK2 23` (`C0000005` still 0, `CP-DRAW` still 166).
- Shape: all 166 calls carry `obj=82860C68` and `stream=82905500` (one reused wrapper slot) with a different `sbuf` each time — the guest validates the **first word of every served effect body**. Measured heads: `3170→696D6541`, `16482→ED5B0F70`, `3125→95564D6C`, `20882/19328→ED5C0D70`, `14981→ED5B0D8C`; none is `0x61786772`. The `ED5x…` family looks compressed/transformed — the same state `.list` members were in before F-105's expansion.
- Null result, don't reuse it: scanning the 2.13 GB `xarchive_cache.rpf` for `rgxa`/`axgr`/`RSC5`/`XComp` gives 0 hits, which means nothing because the payload is encrypted on disk (F-099). Plaintext is only visible through `RpfVirtualFileSystem`.
- **T41.10 (next, census-first):** print 32 bytes + ASCII of one served effect body (the `BE8D8-PACK … head=[…] ascii='…'` pattern already exists for list bodies) and decide raw-DEFLATE vs a different container. If DEFLATE, extend the `MarkMemberExpanded` span mechanism (F-105) to the effect members — a discovered transform, not another host-written word. Pass condition: a body beginning `rgxa` from the host pipeline with `kBe710MagicWrite = false` and the frontier markers intact.
- Mode-check remains mandatory (`RD-SUBMIT == 4` ⇒ void); `w128` and `w130` were both good-mode.

## 2026-09-24 ~08:27 — **F-127: the pending-open serve was an ADVANCE, not a regression — it reaches the guest's rage-effect magic gate, which the frontier only passes because `BE710-MAGIC` writes the expected word for it.** Committed: the label + §7 registration (no behaviour change). Frontier stays `build/w127.log` (`src/` = this commit).

- Measured: `lr=8218C864` appears **0 times** in `w107`/`w113`/`w115`/`w127` and **31-33 times** in `w117`/`w124`/`w125` (the serve-on soaks), with `'%s: Old version of rage effect found. You need to recompile your shaders!'`. So F-123/F-126's "refuted" reading was wrong: `LISTLINE 167→1` / `GETDEV 694→196` are downstream of stopping at a *newly reached* gate, not corruption.
- The gate, from `generated/` (`sub_8218C760`): read ONE word via `sub_821BE710` into `[r1+80]`, then `cmpw` against `lis 24952 | ori 26482` = **`0x61786772`** (`'axgr'`, the `rgxa` magic LE); equal → `loc_8218C878` (continues), else Fatal. Our `BE710-DEAD`/`BE710-MAGIC` (`src/gpu_device.cpp:12326`/`:12336`) writes exactly that word into the caller's buffer for a dead-device stream — **the frontier's shader path is propped by it**. Now labelled `MITIGATION, load-bearing (F-127)` at the site and registered in §7 with its conversion target.
- Both earlier explanations of the collapse are dead: the `w3` registry key (deleting it changed nothing: `w125` == `w124`) and allocation overlap (served bodies land `C9BD7C80…CBBF2C62`, far above the list pages `C6157B80`/`C6167C00`).
- **T41.9 (next, one census + one soak):** print the word that sits at `sub_821BE710`'s read position for the `embedded:/fxl_final/rage_im.fxc` stream (device `827D838C`, `vt=82012918`) and compare with `0x61786772`, then run one soak with the `BE710-MAGIC` write gated off. Either the archive/embedded body does carry the magic and our read position is wrong (fix the position → the gate passes honestly and the pending-open serve becomes viable), or it does not, and the finding is that this prototype's compiled shaders disagree with its embedded effect runtime — in which case B4's shader feed must come from the `embedded:` family, not `xarchive_cache.rpf`. Pass condition: `lr=8218C864` reached with the magic write disabled and `FATAL-SOFT 0` maintained.
- Keep the serve-off variants out of the frontier until then: they trade `Fatal error 0 → 1` + `FATAL-SOFT 0 → 1`, which breaks B5's third criterion, and `DRAW_INDEXED` stays 0 either way.

## 2026-09-24 ~08:20 — **F-126: three variants of "host-serve the pending archive opens" are measured-refuted (the `.list` walk dies every time), and the served-body registry's `w3` index — the TOC record's FLAGS dword, shared by 52 distinct records — is deleted, frontier-neutral in `w127`.** Baseline stays `build/w115.log`; new baseline candidate for the next claim: `build/w127.log`.

- Refuted, all reverted: T41.7 (`w117`, serve `ret==1` wholesale) → `LISTLINE 167→1` + the guest's own Open went `1→2` into the fatal dispatcher; T41.7b (`w124`, registration only, both guest writes skipped) → `PACK-MISS 21→0`, `BADPTR 55→0`, `unavailable 166→0`, **but `LISTLINE 1` and `GETDEV 694→196`**; T41.7b + w3-deleted (`w125`) → identical to `w124`, so the bad key was **not** the explanation either.
- Kept (`w127`): only the `w3` index deletion. `MclaRegisterServedBody` no longer indexes `w[3]` and neither lookup consults it; both `find` sites and the map are gone, F-091's `T413O-SKIP` log-only pattern retained. Measured: `LISTLINE 167`, `Fatal error 0`, `FATAL-SOFT 0`, `C0000005 0` (`fault-line lr: none`), `PRESENT 34`/`PRESENT-FB 4`/`NATIVE-PRESENT 4`, `GFx 3`, `CP-DRAW 166`, `DISCCHK2 41`, `GETDEV 694`, `TOC76 2,079`, `BE8D8-PACK 5` (no serve lost), `unavailable 166`, `CP truth pub=11 put=11`. Throughput-shaped counters moved (`INFLATE 419→358`, `JOIN 83→34`, `PAGESLOT 27→9`, `READWRAP 376→276`) — **not** claimed as improvement.
- **Why the pending-serve breaks the lists (next hypothesis, unmeasured):** the files it serves are `textures/global/cars/globaltex/*.dds` members, and `HostServeUiBody` allocates guest memory for each inflated body in the same arena the seam's expanded `.list` text lives. Test before serving anything: log the allocation range per `HostServeUiBody` call against the list pages `C6157B80`/`C6167C00` (the B1 watch targets). `GETDEV 694→196` says the whole list-walk phase is truncated, not just one file.
- Measurement discipline still applies: mode-check every soak (`RD-SUBMIT == 4` ⇒ void; `w116`/`w118`-`w121` were, `w122`/`w123`/`w124`/`w125`/`w127` weren't), and no `PPC_FUNC` census on the `sub_821E0FF0` block seam (F-125 restored the `swfCMD` fatal there).

## 2026-09-24 ~08:02 — **F-125: a "log-only" `PPC_FUNC` census on `sub_821E0FF0` is NOT observationally neutral — it re-creates the F-117 fatal (`Fatal error 0 → 52`, `FATAL-SOFT 0 → 104`, `'swfCMD::Fixup - unknown type %d' lr=8260A8CC`) in both runs. Hook reverted; `src/` = `666aed1` and the frontier (`w115`) stands.**

- The hook did work (positive control: 2,047 entry lines and 2,047 `-RET` lines, last counter `#401400` in *both* `w122` and `w123`), so `sub_821E0FF0` is entered ≥401k times per boot and always returns. Everything else about the frontier held under it (`LISTLINE 167`, `CP-DRAW 166`, `C0000005 0`, `PRESENT 34`, `NATIVE-PRESENT 4`, `TOC76 2,079`) — which is exactly why the fatal delta is the finding and not noise.
- Suspected mechanism (**inference, not measured**): `0x821E0FF0` is a recompiler *block* seam reached by branch, its body starts with the elided-prologue write `ctx.lr = 0x821E0FF8`, and under `PPC_CONFIG_NON_VOLATILE_AS_LOCAL` each `sub_` has its own zero-initialised `r14`–`r31`. Overriding the weak symbol puts a host frame on that seam. Testable cheaply by hooking a sibling block that only real `bl` sites enter.
- What the unpacker is handed (fact): `r3 == r4` pointing into the `0xC60AC000` device array (`C60ACE00/E10/E20`, 0x10 stride; also `C6114DE0/E70/EA0`), `r5 = 0x8EFFEE80` (boot worker's guest stack) with `[r5+480]=14`. **This kills F-124's guess that `[r5+240..252]` are loop bounds** — those are stack locals. So the stalled-mode bound is still unnamed, and the next instrument must be hook-free: the B1 `DR0`–`DR3`/guard-page machinery, or `midasm_hook`.
- Soak modes: `w122`/`w123` were both good (`RD-SUBMIT 24`, `LISTLINE 167`) after `w116`/`w118`/`w119`/`w120`/`w121` all stalled — ~2 of 5 runs are void, so keep applying the F-123 check.

## 2026-09-24 ~07:50 — **F-124: the stalled soaks are not deadlocks.** `src/` is unchanged (`002b847`); T41.7b is still unmeasured because the stall happens before any `*.fxc` open.

- Measured: in `w119` (stalled, 912 lines) `WAIT[KWFSO]`=8 and `WAKE`=0 versus `w115`'s 1,309/1,307, and its last WAIT is 80 s before its last line — after the stall **no guest thread enters or leaves a logged wait**, while host timers (`VSYNC-ISR`, `TICK-PROBE`, `RING … swaps=0`) keep running.
- Where the boot worker sits: `lr=821E0FF8` in 93 of 114 park samples. That LR is the elided-prologue write of **`sub_821E0FF0`**, whose body merges bytes from `[r3+4]/[r3+5]/[r3+8]` with `rotlwi …,8` against `lis r11,-32255` (= `0x81C10000`) — an unpacker that reassembles guest pointers from stored bytes. It also dominates the good `w113` (64 samples), so it is normal work that in the stalled mode never finishes.
- Ruled out with measurements (all in F-124): AVs (`C0000005 0`, `BADPTR 0`), the volume (128 MB/s read, 32 MB write+fsync 1.16 s, clean `git` writes), a full render queue (depth warnings appear in good runs too), and T41.7b (`XSF-BIND-REGONLY` prints 0 times — the stall precedes the code path).
- **Next instrument, not a thread dump:** bound `sub_821E0FF0`'s loop — iteration count plus the guest words that feed the bound, capped — then ask who writes those words (the B1 guard-page/DR machinery already exists for the writer question). Until that is understood, every soak needs the F-123 mode check (`RD-SUBMIT == 4` ⇒ void) or a repeat.
- Re-apply-ready when soaks are trustworthy: T41.7b = `serveThisOpen = ret==0 || ret==1` + one inflate per `tocEntry` + `return` before the `WriteU32BE(tocEntry+4, xsz)` / `kBdf20Wrap {dev,handle}` binds when `ret != 0`. Its rationale and the w117 refutation of the *un*gated form are in F-123.

## 2026-09-24 ~07:38 — **F-123: the `.fxc` shader bodies are missing because our host-serve only fires on the guest's `ret==0` opens (33) while 876 opens answer `1` (pending) — and making it fire fixes the read storm but breaks the boot elsewhere. Two hazards to work around, both measured.** Baseline stays `build/w115.log`; `src/` is back at `7c125b4` (the refuted change is reverted, code unchanged this block).

- **The fork (from `w115`, all counts printed `XSF-OPEN … ret=`):** `-1` × 332, `0` × 33, `1` × 876 (498 `*.fxc`). `XSF-POSTOPEN-SERVE` fires exactly on the 33. The consequence for one file is fully logged: `BE8D8-PACK-MISS` (no served body) → `CD3C8 ret=3170` (the guest knows the size) → `DISCCHK2 route=guest-disc-read` → the guest allocates its own buffer and re-opens it as `BE0C8 pth='memory:$CA5DF680,3170,1:unavailable'` (the word *unavailable* is the guest's) → ~600 refused one-byte reads.
- **T41.7 (`serveThisOpen = ret==0 || ret==1`) — both predictions hit and it still failed:** `BE8D8-PACK-MISS 21→0`, `BE250-MEM-BADPTR 600→0`, **but** `LISTLINE 167→1`, `Fatal error 0→1`, and the guest's Open answer for the same path changed `1 → 2` before the fatal dispatcher (`lr=8218C864`). So the serve is not inert: it writes into state the guest reads back. Reverted.
- **T41.7b is written but UNMEASURED** (registration only; `return` before `WriteU32BE(tocEntry+4, xsz)` and before the `kBdf20Wrap=0x82860C18` `{dev,handle}` bind when `ret!=0`). Those two writes are the suspects — the wrapper bind in particular points the **global** BDF20 stream at the last-served file, which is the §7-registered loose-match hazard and the obvious way to lose 166 of the 167 list lines. **Re-run it, and do not trust the first soak (next bullet).**
- **Soak reliability (this is the finding that saves the next session time):** roughly half the runs stop at ~900 lines on the *same* binary that also produced a full boot. The site is the 4th disc read — `RD-SUBMIT sub_8244F4C0 #4` / `NFS-CENSUS[Read] … len=382976 off=0x800 evt=00000000 apc=00000000`, i.e. submitted with no event and no APC — after which only `RenderThread: queue depth …` lines appear. E: is healthy (128 MB/s read, 32 MB write+fsync 1.16 s, `git hash-object -w` clean), and queue-depth warnings appear in the good runs too. **Discriminator: `RD-SUBMIT == 4` ⇒ VOID; `>= 24` ⇒ reached the frontier** (`w115`=24, `w117`=24, `w116`/`w118`/`w119`=4). F-122's "w114 was I/O contention" verdict is corrected here: it was this stall.
- **Unchanged:** `DRAW_INDEXED 0` in every run, good or stalled → **B4's gate is still unmet**; `C0000005 0` holds wherever the boot got far enough to show it.

## 2026-09-24 ~07:10 — **F-122: the 50 access violations were OURS. `w115` is the first soak with `C0000005 0` and the frontier intact, and the thing in front of `DRAW_INDEXED` is now one unbound guest wrapper (`0x82860C68`).** Baseline for frontier claims moves to `build/w115.log`.

- **What was actually wrong.** Our `sub_821BE250` hook sends any wrapper with a dead `[+0]` device into `MemoryStreamServeRead`, which assumes the `MakeMemoryStream` shape (`+4`=buf, `+8`=size, `+24`=cursor). The faulting object is a **guest-native buffered wrapper**, whose real shape is `+8`=buffer, `+24`=cursor, `+28`=end, `+32`=cap (`generated/ppc_xenon/ppc_recomp.14.cpp:24080` ff proves it: `lwz r11,8(r31)` … `add r4,r11,r10` → copy). Reading its `+4` (`0xFFFFFFFF`, a handle) as a buffer and adding `+24` (`0xC62`) wraps to guest **`0x00000C61`** — inside the 4 KB null guard page that `GuestMemoryHeap::Initialize` deliberately makes `PAGE_NOACCESS`.
- **Two host bugs, both fixed:** (1) `IsValid` (`src/kernel/memory.cpp:311`) only tested `guestAddr < m_size` on a flat 4 GB window, so a "checked" helper handed a guard-page pointer to `memcpy` and relied on SEH to survive; (2) `MemoryStreamServeRead` (`src/gpu_device.cpp:11677`) now refuses the shape mismatch **and names the object** (`BE250-MEM-BADPTR`, 55 lines in `w115`). `/MAP` frames 5-13 are what located it: `MoveSmall1 ← MemoryStreamServeRead+0x23B ← our hook+0x278 ← __imp__sub_821BE4F0+0xD6 ← sub_8218C1C0 ← sub_8218C760 ← sub_82188E50` — no recompiled guest body below the copy, so F-121's "guest memcpy" attribution was wrong (corrected in the ledger).
- **Census vs `w107`:** `C0000005 50→0`, `VEH-NEUTRAL 50→0`, `VEH 123→25`, `[error] lines 119→15`, fault-line lr = *none*. Invariants held: `LISTLINE 167`, `Fatal error 0`, `FATAL-SOFT 0`, `PRESENT 34`, `PRESENT-FB 4`, `NATIVE-PRESENT 4`, `GFx 3`, `CP-DRAW 166`, `DISCCHK2 41`, `GETDEV 694`, `TOC76 2,079`. Advanced: `INFLATE 358→419`, `PAGESLOT 9→27`, `JOIN 34→83`, `READWRAP 276→376`, `WAIT/WAKE` halved. Still zero: `DRAW_INDEXED`, `swfCMD`, `SETSTREAMS` — **B4's gate is unmet**, but not because of an exception storm.
- **`w114` is VOID — the control is the lesson.** It looked like a 920-line catastrophe (`TOC76 0`, `GETDEV 12`), but its *pre-guest* phases were stretched too (image load 35 s vs 19 s), and re-soaking the **same exe** as `w115` reproduced the frontier exactly. Host I/O contention, not the change. If a soak is slow before the guest runs, repeat it before believing anything.
- **Next (T41.6b).** `0x82860C68` sits 0x50 past the wrapper `XSF-POSTOPEN-SERVE` binds (`0x82860C18`) and arrives with `[+0]=0`, `[+4]=FFFFFFFF`. Either bind that sibling at the same site with the guest-native fields, or give it a live device and let `sub_821BE250` serve it itself. Then re-ask `swaps`: the wait that F-121 saw at this site is the same one holding `swaps=0`.
- **F-121's T41.5d also landed:** with `kExpandListInArchive = false` (`w112`) the faults vanish but `LISTLINE 167→2` and the `'…wasn't preloaded properly'` fatal returns, so seam **ON** stays the committed frontier (`src/gpu_device.cpp:529`).

## 2026-09-24 ~06:31 — **F-119/F-120: the boot worker is SPINNING in the guest device layer, not blocked — and host PCs are now nameable via `/MAP`.** Baseline stays `build/w107.log` (frontier numbers); `w110`/`w111` add the thread-state view.

- **F-119 (guest side).** `PARK-STACK` (new) walks the boot worker's guest frames: dominant chain in 62/97 samples is `sub_821BD7C0 → sub_82131790+0x284 → sub_822C4630+0x424 → sub_821CD7A0+0x298`. It also fixed a real instrument bug: `g_faultCtx` is `thread_local` (deliberately, F-046), so the sampler and `GetBootWorkerReg()` were reading their **own null copy** — that, not "no guest context", is why every `r3=/lr=/[r1-8]=` field in `w108`/`w109` printed 0. Now a process-wide `g_bootWorkerCtx` mirror is published for cross-thread readers; the VEH path is untouched.
- **F-120 (host side, corrects F-119's wording).** `CMakeLists.txt` links with `/MAP` → `build/mcla.map` (149,080 symbols, link-time only, no compile-flag risk). Resolving `w111`'s host PCs: 47+11 samples in `std::_Check_load_memory_order` / `_Atomic_storage<unsigned>::load`, i.e. the thread is **hot-looping on device loads through our atomic-checked accessor**, not parked in a wait. So the blocker is "the guest polls a device value that never changes", consistent with `swaps=0` and `pub=11 put=11` (F-118).
- **Do not build the obvious wrong instrument.** `sub_821CD7A0+0x298`'s inner loop is NOT a wait: the `addic./bne` loop at `0x821CD944` is a bounded **5-dword byteswap** (`r10=5`, rotates+`stw`), i.e. this is a hot conversion helper on the poll path. Counting `CpRegPeek` would prove nothing either — the guest's MMIO reads go through the load accessor, not `CpRegPeek` (that is host-side hook code). The needed measurement is **which guest address the poll loads**: capture the fault-free load target for the boot worker (e.g. sample the accessor's address argument in the ring that `PARK-SAMPLE` already reads, or watch the specific page with the existing B1 DR0/DR3 machinery) and then ask who was supposed to write it.
- **Why this is the right hill.** Naming that address is simultaneously F-112's conversion target (retiring `kDiscChkForcedAck`), the reason `swaps` stays 0 (F-118), and the precondition for B4's `DRAW_INDEXED ≥ 1` → B5's menu. Commits this session: `5094d56` `cbd9a93` `07396be` `244bcf3` `21cfbfb` `6775494` (all pushed).
- **Volume note still applies:** `w105.log` is void (mid-flush `taskkill` on a failing E:); re-read artifacts from a fresh process before citing them.

## 2026-09-24 ~06:05 — **F-117 + F-118: the last fatal was OURS and is deleted; the frontier is now a thread stall with `swaps=0`.** Baseline for frontier claims: `build/w107.log`. Volume caution at the end — read it before trusting any log written around 05:30.

- **F-117 (P0 result).** `'swfCMD::Fixup - unknown type %d'` was manufactured by `W30-PLACE` re-entering guest code (`sub_825EF100`) on a hand-built `PPCContext` (`r1=0x006D8EC0`, `r13=8F200000`) over `obj+12`, a field `W30-ARR-FIX` fills with the hard-coded address `0xB7B6D9B4`. The guest reads `u8[obj+12 → node+4]` as a type, so it printed the top byte of OUR pointer (`0xB7`). Deleting the synthetic re-entry (`kW30SyntheticPlaceRedispatch = false`, `src/gpu_device.cpp:~4610`) gives **`Fatal error 0`, `swfCMD 0`, `FATAL-SOFT 0`** (B5's third criterion) with `LISTLINE 167` intact and `CP-DRAW 52 → 166`. Commit `5094d56`, ledger `cbd9a93`.
- **F-118.** The remaining blocker is pre-existing, not caused by that fix: `w103` and `w107` end identically — 2 GPU workers (`start=8242FB88`) timing out at 30 ms on `obj@40004D7C`, 13 pool workers (`start=821C91C8`), and **`swaps=0` in every `RING` / `VDRAIN-CENSUS` line of both runs**. `PARK-SAMPLE` could not show this (it printed only on RIP *change*, and only for the first 60 s), so it read as "no stall". Fixed to a 2 s heartbeat over 300 s (`src/boot_host.cpp:1512-1548`, commit `07396be`); `w108` then shows the boot worker holding one host RIP for 57 of 122 samples, guest frames resolving to `0x82131008`. **`build/mcla.pdb` does not exist**, so host RVAs cannot be symbolized (`llvm-symbolizer` returns `??`) — phrase host-side stall claims as RVAs, never as function names.
- **Next (T41.5b).** Dump the main thread's *guest* return-address chain every heartbeat (the sampler already has `Rsp`, `g_faultCtx->lr`, and the saved `lr`/`r30`/`r31` slots) and resolve the innermost address to a mapped `PPC_FUNC`; then ask who must satisfy that wait, and whether it is also what the 13 pool workers wait on. `DRAW_INDEXED ≥ 1` sits behind this, because per the F-116 correction **no VB/IB register has ever been written** in these logs.
- **Volume caution.** Around 05:35–05:45 E: failed `fsync`: git littered `.git/index.lock` (two moved aside, not deleted), two soak logs killed mid-flush became `OSError 22`-unreadable, and `w106` segfaulted on the poisoned spdlog sink. **`w105.log` is VOID** — its byte count and marker totals differ between reads; cite `w107`/`w108`. Read back anything written from a fresh process before believing it. Episode backups: `C:/Users/abdul/Documents/mcla-E-fail-20260924/`.

## 2026-09-24 ~05:05 — **F-112/F-113/F-114: B3 CLOSED, B4's real blocker located.** Baseline is now `build/w103.log` (`LISTLINE 167`, `'not preloaded properly' 0`, `DRAW_INDEXED 0`, `C0000005 50 lines / 2 events`).

- **B3 done.** DISCCHK's `[dev+12]` word is the RPF3 TOC record's **4th dword** (`rec=C60F7A40 size=23F offs=D0000 flags=400000EC` == `globaltex.list`'s record), bit30 is set on *every* cache-packfile record, and the executed check (`generated/ppc_xenon/ppc_recomp.17.cpp:3114`‮) enters the disc-read block iff `bit30 && !bit31`. Inside it the guest issues its own read and fatals when `sub_821DEE40(io,2)` returns **negative** — `w101` measured `-3`. So bit31 = "the read completed", and `kDiscChkForcedAck` means "pretend resident". Kept ON (removing it costs 13k lines: `w100`/`w101` die at 4,528), now labelled at `src/gpu_device.cpp:10443`. Conversion target: make that completion return 1.
- **Do not trust `tools/ppc_disasm.py` for direction** (F-113): it prints `mr A,B` inverted and prints `bc bo=/bi=` with no polarity (`bo=12,bi=EQ` **is** `beq`), and `PPCContext` has **no `r14`–`r31` members** (`PPC_CONFIG_NON_VOLATILE_AS_LOCAL`) so a hook can never see a callee-saved register. Read `generated/` instead. This nearly put a false refutation in the ledger.
- **B4 hygiene landed:** the post-draw `ClearAndPresent()` (a second Present that cleared what was just drawn) is gone, and heartbeat presents now log `HB-FLICKER` — which revealed that **every** previous `RenderThread: PRESENT` line was our 33 ms timer (w99: 34 lines, counter #2880; w103: **0**), and the guest's real swaps are 4 `NATIVE-PRESENT` on slots `C71D82C0…CC`.
- **F-115 (same session, static + existing logs) sharpens T41.4c into two concrete moves:**
  **UPDATE 05:20 — (a) is DONE: F-116 / `build/w104.log`. The 54-poke batch is now dumped as
  `CP-DRAW-REGS` (`src/gpu_cp.cpp:64-82`, `:679-695`), and the AUTO draw's 3D state really is in the
  register file: `r01DD=071D8380`+`r01DC=00020037` (a surface pair; +0xC0000000 = the swap family
  `NATIVE-PRESENT` reports), four `0xA02..0xA05` 16.16-looking values, and ten `0x2xxx` writes (the
  band F-090 widened for). `r057C=0BADF00D` is an unexplained sentinel. Next: name the ids against
  `.research/xenia/src/xenia/gpu/` (no `reg_base.h`/`REG_OFFSET` in this tree — locate the offset enum
  first), then decode VB/IB + float constants from the file and bind them at `d3d12_backend.cpp:1462`.
  Frontier unchanged by the census (`w104` == `w103`).
  (b) `'swfCMD::Fixup - unknown type %d'` (`generated/ppc_recomp.8.cpp:1120-1152`,
  `CP-DRAW src=2` = AUTO vertex source), so `plausible` at `gpu_device.cpp:1948` can never open — dump the
  draw's 54-write register batch and decode the VB from registers, do **not** widen the gate;
  (b) `'swfCMD::Fixup - unknown type %d'` reads `type=0xB7` out of B7-heap node `B7B6D9B4`, a block our own
  `W30-ARR-FIX`/rebase path installed (all `CDCDCDCD` at 05:01:22) — census the node's first 8 words *at*
  the Fixup entry, not 2 s earlier. Do not touch the `alreadyPhys` predicate (`task_dispatch_trace.cpp:600`).
- **Next (T41.4c):** the feed, not the backend. `sub_82420BA8` is called only twice with `r5=NULL`, `streams=0`, `vb0=[0,0,0]` → `plausible=false`, and `SETSTREAMS-census`/`sub_8241C308` have never fired, so the 75b chain is not this boot's path; the 26 `CP-DRAW op=0x36 numIdx=1 dmaBase=0` packets are setup-pass shaped. Also still masking the frontier: `'swfCMD::Fixup - unknown type %d'` (`FATAL-SOFT`), which stops the guest before any UI draw. The zero-filled CBV (`d3d12_backend.cpp:1462`) has nothing to bind to until one of those lifts.
- Committed: `07a6501` (B3) + `c0e4831` (B4 hygiene). Program guide §6/§7/§9 updated for `DISCCHK2*`/`HB-FLICKER`.

## 2026-09-24 ~01:15 — **F-111: B2's GATE IS MET — `'wasn't preloaded properly'` is gone and `star_glow`'s own `.dcl` opens.** Registering the six list spans at the guest's FIRST archive I/O (`MclaMarkKnownListMembers()` from `sub_8244F4C0` at `n==1`, `src/gpu_device.cpp`), rather than lazily at the first TOC query that F-110 showed loses the race with the page pump, makes the loader read five of the six lists: `LISTLINE 79 → 167`, `Fatal error 2 → 1`, `'not preloaded properly' → 0`, and `shaders/effects/dcl/star_glow.dcl` now opens **`ret=1 toc=[D8DABDFA 00000059 00305F0C …]`** (89 bytes at `0x305F0C`). Reproduced twice (`w97`, `w98`); nothing new is masked (`FATAL-SOFT 3→2` in step with the removed fatal, `using fallback` 0 in both). **THE COST, chosen deliberately:** the committed default now carries `C0000005 = 50` (all `rva=0x58D5384` reading guest `0xC61`, `ppc lr=821BE508 r3=82860C68`) — the wrapper family F-108 localised, now hit far more because far more files are opened; the fault value differs per run (`0xE17` in `w80`, `0xC61` now), so it is computed downstream, NOT a stale field (F-108's census proved the fields sane). **NEXT (T41.4a, in order):** (1) trace the wrapper data-flow at `sub_821BE508`'s callee chain and complete that emulation until `C0000005` is 0 on this branch — do not clamp the pointer, do not revert the switch to hide it; (2) then the surviving fatal `'swfCMD::Fixup - unknown type %d'` (which already existed in the old frontier) and B4's renderer feed; (3) B3/DISCCHK is untouched (6 firings in both trees) and still owes its retirement. Baselines: `w98` = new default; `w96`/`w81`/`w72` = old frontier with the switch off; `w97` = first run of the same state; `w95` = lazy-registration branch; `w75`-`w77`,`w79`,`w94` void/poisoned (w94 = stale exe after a failed build — check `build_ninja.log` + exe mtime before naming a log).

## 2026-09-24 ~01:00 — **F-110: B2's last unknown is solved — it is OUR ordering, not the game.** `sub_821CFAA8`, which I had been reading as a stream reader, is a whitespace WORD splitter (its body compares against 32/9/10/13/0); the loader tokenizes the guest's own page-cache copy of the member. Printing that buffer settled it: for `ui` it is binary (`buf='??pP??5h'`) and for `city` it is the expanded text (`'//'`, `'Shaders'`, `'listed'`, `'here'`, `'are'`, `'real'`, then `'CityDefault'`) — i.e. expansion is registered lazily at the first TOC query while the page pump is eager, and only `city`'s page happened to be pumped after its mark. That also re-validates F-101's "consumed as-is, no decoder" witness as a view of the PRE-registration copy. **Two self-corrections worth keeping:** F-109's refutation of page-residency was worthless because it leaned on `NFS-CENSUS[Read]`, whose printer is capped `n<=20 || (n%100)==0` (rule 19 again, aimed at me); and `w94` is VOID — the build had failed on a `'
'` mangled to a raw newline by a patch script, and the soak silently ran the old exe (check `build_ninja.log` + exe mtime before naming a log). `w92`'s cleared-slot candidate is also refuted (slot and wrapper identical for ui and city). **NEXT (T41.3v, concrete):** register the six spans from the decrypted TOC by leaf hash: every `preload.list` record carries `[entry+0]=0DB1C876` and `globaltex.list` carries `3D9B8154` (`w95`) — so no offset/size is hardcoded; pick the site (existing `dumpOnce(0xC60B7780, 382976, …)` TOC dump vs the mount routine `sub_822C4630+0x20C`) by comparing timestamps against the first member-page pump, not by guessing. Prediction to check: LISTLINE 77 → ~189 (15+78+61+18+17 across the five preload lists) and the guest should then request `shaders/effects/dcl/star_glow.dcl` / `fxl_final/star_glow.fxc` (F-109: it currently never tries the prefixed form, which IS the fatal). New log-only censuses kept: `DB730-LOADER`, `CFAA8-LOADER` (stream words + wrapper + slot + `buf=`), `A490-LOADER` — all filtered to the loader's `lr`, all silent-ish off-branch. Default tree: seam OFF, `w96` == `w81` == `w72` on every marker (`PRESENT 67` vs `68` jitter, `LISTLINE 2`); branch baseline is now `w95`.

## 2026-09-24 ~00:25 — **F-109: the fatal is a missing GROUP PREFIX, and B2 is down to one question.** In `w88` (seam ON + a new `ascii=` field on `BE8D8-PACK`) all five list bodies arrive as verified plaintext (`ui 'AlphaModulate.fx..'`, `cars 'WheelRubber.fx..'`, `effects '// Shaders listed here…'`), yet only `shaders/city/preload.list` is line-read — 77 of its 78 lines (the 58+19 split across two `BOOTPATH` windows is ONE continuous read; its tail simply names `Character_visor_norm`/`Character_plastic_norm`, which are city entries). For every name in that one list the guest DOES reach the group-prefixed asset forms and they RESOLVE: `shaders/city/dcl/CityDefault.dcl ret=1 toc=[B8A98D20 0000006D 001F43BF 40000062]`, `shaders/city/fxl_final/CityDefault.fxc ret=1` (379 resolved vs 140 empty-TOC `.dcl/.fxc` opens). For `star_glow` the prefixed forms are never attempted at all — only `dcl/star_glow.dcl`, `fxl_final/star_glow.fxc`, `embedded:/…`, and the doubled `star_glow/dcl/star_glow/dcl/star_glow.dcl` — hence `'wasn't preloaded properly'`. Two dead ends now closed, so do not re-run them: (a) page-residency/late-registration is REFUTED (mark and expansion are same-millisecond for all six); (b) content shape is refuted (city and effects lists both begin with the same comment line, only city is read). **NEXT (T41.3u): census `sub_823DB730`, called twice at the loader loop head `0x82187920-0x82187944`, whose `r3` decides whether `sub_82188E50`/`bl 821CFAA8` run — log its arg and both returns per group and find where ui/cars/characters/effects diverge from city.** Baselines: default `w89`/`w85`/`w83`/`w81` == `w72` (`C0000005 0`,`Fatal 2`,`GFx 3`,`GETDEV 168`,`TOC76 334`,`CP-DRAW 52`,`DRAW_INDEXED 0`; `PRESENT 67` vs `68` = jitter); seam-ON branch baseline `w88` (supersedes `w84`/`w86`: adds the delivered-content field). `w75`-`w77`,`w79` still poisoned.

## 2026-09-24 ~00:10 — **F-108: F-107's proposed next fix is REFUTED by its own census.** The 24-word dump of the fall-through wrapper (`BE250-OBJ`, `w86`) shows a perfectly coherent buffered `fiFile` — `dev=C60AC180 h=1 buf=82862DF8 cap=0x1000@+0x20`, all other words 0 — and `0xE17` is nowhere in it, so `w80`'s AV address is computed downstream (guest refill arithmetic or a device-vtable callee), not read from this object. Do NOT bind this wrapper on F-107's guess. Seam-ON branch reproduces cleanly: `w84` and `w86` both give LISTLINE 79 = 77 loader names + 2 reporter reads, zero failed reads, one fall-through. B2 now has two separate open items: (i) the loader stops after `characters` and never line-reads `shaders/effects/preload.list` (which is where `star_glow.fx` is named — measured content in F-105), and (ii) 5 host AVs at `rva=0x58D0564` reading guest `0xE17`, which occur *between* loader lines without stopping them. Next census for (i): the loader's five per-group calls (F-102 named the sites at `lr=82304844/64/84/A4/C4`) — which group index does the 77th name belong to, and what does the call after `characters` return; for (ii) the host symbol at `rva 0x58D0564` (module base + that) rather than more guest speculation. Default tree: `kExpandListInArchive=false`, guard arming retired, `w87` == `w81` on every marker (`PRESENT 67` vs `68` = jitter); branch baseline is `w84`/`w86`.

## 2026-09-24 ~00:05 — **F-107: B2's mechanism is CONFIRMED — the guest's own preload-list loader reads 77 real names.** With the seam ON and `LISTLINE`'s cap raised (the old `n<=40` hid the true count exactly when it mattered), `w84` shows `sub_82188E50` called from `sub_82187958` inside the loader `sub_82187820` yielding `CityDefault`, `CityGrime*`, `CityRoad*`, `CityTunnel*` … then `Character_visor_norm`, `Character_plastic_norm` — two whole members consumed line by line (city 78 newlines, characters 18). Baseline `w81`/`w85` prints 2 LISTLINEs, both the fatal reporter's own reads. NOT yet cleared: `shaders/effects/preload.list` (whose text holds `star_glow.fx`) is never line-read and the boot still ends at `lr=0x82189270 r3=0x8200B358`. The single fall-through into the guest's real `Read()` is `w82`'s `BE250-GUEST #400 obj=82860C68 dev=C60AC180 h=1 count=25286 +8=82862DF8 +32=00001000 +24=+28=0 lr=821BE93C` — a 25 KB read through a 4 KB wrapper buffer on the sibling of the `0x82860C18` wrapper our `XSF-POSTOPEN-SERVE` binds, i.e. the same object family as `w80`'s `guest 0xE17` AV. **NEXT (T41.3t, in order): bind/serve that sibling wrapper the way `0x82860C18` is bound (completion of our emulation, not a short-circuit), then re-count LISTLINE on the seam-ON branch (`w84` is its baseline) and see whether `effects` is reached and the fatal moves.** Default tree unchanged (seam OFF, arming retired): `w85` == `w81` (only `PRESENT 67` vs `68`). New log-only censuses in this commit: `BE250-GUEST`, wide `LISTLINE`; both silent/unchanged at seam-OFF.

## 2026-09-24 ~02:45 JST — **F-106: the read-retry spin was OUR instrument, and fixing it quadrupled the archive walk.** `w79`'s new `gle=` field on the failed-read census printed `ERROR_NOACCESS (998)` on `path='xarchive_cache.rpf'`: F-101's guard-page witness marks the archive page-cache buffers `PAGE_NOACCESS`, and a host-side `::ReadFile` into such a page just FAILS (no exception for our VEH), so any page the guest re-reads loops (`w76`/`w77`: 1339 retries, ~800k lines). B1's verdict was already earned, so the arming is retired (`kB1GuardArmFromReads=false`, `src/gpu_device.cpp:10242`) — instrument kept in `src/boot_host.cpp`. With arming off AND `kExpandListInArchive=true`, **`w80` expands all six lists (ui 0x1DD11C/260/15, city 0x1F41FB/1246/78, cars 0x27F1AF/1108/61, characters 0x2DB9A1/496/18, effects 0x304E12/368/17, globaltex 0xD0000/575/17), has ZERO failed reads, and moves further than any soak ever: `GETDEV 168→680`, `TOC76 334→1176`, `-GATE 75→320`, `DISCCHK 6→16`, `BLIT-CAP 5→22`.** Two blockers survive it: (i) the boot STILL ends at `lr=0x82189270 r3=0x8200B358` = the `'wasn't preloaded properly'` string (so B2's gate is not yet cleared), and (ii) a new host AV ×5 at `rva=0x58D0564` reading `Param[1]=0x100000e17` (guest pointer `0xE17`, i.e. near-null) with `ppc lr=821BE508 r3=82860C68` — the stream-wrapper family we host-complete. DEFAULT TREE = both switches OFF, verified `w81` == `w78` == `w72` on every marker (`C0000005 0`, `Fatal 2`, `GFx 3`, `GETDEV 168`, `TOC76 334`, `CP-DRAW 52`, `DRAW_INDEXED 0`). NEXT (B2, in order): work the seam-ON branch on baseline `w80` — find who leaves `0xE17` in the wrapper field at `sub_821BE508`'s caller (census the field's writer, do NOT patch the AV away), then re-read why the fatal still fires with the lists consumed (`LISTLINE` is the witness). `w75`-`w77`,`w79` = poisoned/cause-finding; `w80` = seam-ON baseline; `w81`/`w78`/`w72` = default-tree baselines.

## 2026-09-24 ~02:30 JST (w74..w78, local clock; earlier blocks here use another) — **F-105: B2's transform is FOUND and VALIDATED, and the archive-layer seam is the one the guest actually consumes.** All six `*.list` members are headerless raw-DEFLATE streams; each expands to a CRLF name list and expanded length == TOC `[entry+4]` stored length (so `stored != expanded` cannot detect compression in this archive — F-073's 126-460 numbers are level-9 recompression sizes, corrected). `src/raw_inflate.h` (new, self-contained) reproduces Python zlib byte-for-byte on all six. The image carries zlib 1.2.3 itself (" inflate 1.2.3 Copyright 1995-2005 Mark Adler " @VA `0x82017F00`, `length_base`/`dist_base` @`0x82017F30`/`0x82017FB0`) yet all 149 of its decompressor entries are the RSC5 package path — it never inflates a `.list`. Two seams tested: (1) host-served body expanded (T41.3g refusal retired, `src/gpu_device.cpp:473-500`) = frontier identical to `w72` (loader ignores what `BE8D8` hands it; F-104's "missing stream contract" is thereby superseded); (2) expanded **inside `RpfVirtualFileSystem::ReadFileAt`** (`src/fs/vfs_rpf.cpp:646`, registered from the guest's own TOC words behind `kExpandListInArchive` at `src/gpu_device.cpp:10814`) = the guest parses `globaltex.list` and opens all eight named textures (`2dnoise3/4`, `anisodir`, `billettanmap`, `cf_bump2`, `dmg_scrape`, `no_damage`, `powerup_beam`) — first content consumption in this project's history — then wedges: `NtReadFile h=C60B7680 off=0x158000 len=32768 got=0 status=C000000D` x1339 at off=0, 798k lines, fatal never reached. **`w75`-`w77` are POISONED soaks, not baselines.** Refuted sub-hypothesis: killing the host GLOBTEX name-injection stand-ins (`kHostGlobaltexNameInjection`, `:854`) does not change the spin, so the stand-ins are back ON and B3 is untouched. Next experiment (B2's remaining half, census first): why the read of the page holding `0x158000` — inside the `0xD1000` texture the list just named — returns 0 bytes/`C000000D` and what the guest does with that; do NOT widen the substitution (a substring predicate matched `globaltex/*.dds` and registered 87,509-byte spans — `w75`). Baselines: `w78` (default tree, == `w72`/`w58` on every guest marker), `w74` (host seam live), `w72`. `soak_census` flags `HOSTSERVE-BLOCKED` as NOT IN SRC — correct, that refusal is gone.

## 2026-09-24 ~07:55 — B1 ANSWERED on a working instrument (F-101, baseline `w64` == `w58`). The guard-page watchpoint in `src/boot_host.cpp` (`B1GuardArm`/`B1GuardHandle`, armed from the RD-BUF census) self-tests on every arm, so its trips are earned: the archive member windows ARE consumed right after the fill — `trip 6` at the exact head `C6157B80` from `sub_821CBE18+0x78` (`lwz r11,8(r31); add r4,r11,r29; bl 823DA950` = a copy-out with a computed address) and `trip 2/4` at TOC+4 from `sub_821E0FF0+8` (`lbz r9,4(r3)`), with **no** `XMemDecompress` in between. So F-094's fork resolves to "the prototype tolerates the bytes as-is"; F-095's "nothing ever reads them" is dead (inert `SetThreadContext` watchpoint — F-100). Two earlier instrument versions (`w62`,`w63`) leaked a second thread's in-window fault into the park machinery and MOVED the frontier (`C0000005 3`, `GETDEV 116`, fatal lost); the fix is to claim every fault on a page we armed, and `w64` proves it behaviour-neutral. NEXT (B2, in order): (i) the faithful member-open route — `HOSTSERVE-BLOCKED` answers `shaders/*/preload.list` with `buf=0 size=0 handle=0` (`w58:4527-4554`), so give the guest a real member handle with position/length from its own TOC entry (F-099 already proved our offsets byte-exact, so the defect is the *handle*, not the offset); (ii) name the target of `sub_821CBE18`'s copy — that is where a list body would become a table. `star_glow` = `shaders/effects/{dcl,fxl_final}/` (F-100) and the group prefix is NOT missing data: the guest resolves all five `shaders/<group>/preload.list` by full path. Baselines `w58`/`w59`/`w64`; `w60` = dead instrument, `w62`/`w63` = frontier-moving runs, none citable. Frontier still `DRAW_INDEXED 0`, `C0000005 0`, `Fatal error 2`.

## 2026-09-24 ~07:05 — B2c CLOSED BY IDENTITY (F-099, baseline `w58` vs `w46`). d0 = `xarchive_audlo.rpf`, d1 = `xarchive_cache.rpf`: the guest's own mount list literal @`0x8203966C` is executed exactly, both TOCs decrypt→parse→hash-sort, and the 18 KB d0 table decodes to audio/`vp_*`-paint content with ZERO shader names — so F-096's "index-population failure on d0" is retired (correct behaviour for an audio archive) and F-098's CSR@0x60000 lead is retired as `INFLATE-HOSTSERVE` self-feeding (`src/gpu_device.cpp:6887-6899` re-points the guest's inflate state; anything downstream measures the host). New instrument `tools/rpf_offline.py` (header/names/find/member/islands) + `TOC-DUMP3` query-time dump. Durable: RPF3 header dwords are LE (+4 = TOC length the guest asks for: cache 382976, audlo 18432, audio 30720, music 2048) while TOC records are BE; on-disk TOC is AES so `find` on the raw archive returns 0 by design — use the in-guest dump. The fatal's full candidate list is GETDEV #38-#43 (`w58.log:5255-5328`): `embedded:/dcl/star_glow.dcl`, `embedded:/star_glow.dcl`, `embedded:/fxl_final/star_glow.fxc`, `a:/archive/star_glow/dcl/star_glow/dcl/star_glow.dcl`, `a:/archive/dcl/star_glow.dcl`, `a:/archive/fxl_final/star_glow.fxc` — six, none ever carrying a `shaders/<group>/` prefix; the doubled #41 is the guest's own (clean forms bracket it). Offline route to the list bodies is DEAD (122 MB plaintext scan = 0 hits for star_glow/fxl_final/.fxc/preload.list/shaders/). NEXT (B2 finish): the group prefix cannot come from the lists the guest never decodes (F-094/F-095), so test the alternative that a *mount root* supplies it — (i) static: does `shaders/<group>/dcl/` exist in `build/toc_parsed.bin` (GtaO `dcl`), i.e. are all six candidates real paths modulo one prefix; (ii) are the unmounted-but-allowed `xarchive_audio.rpf`/`xarchive_music.rpf` the archives whose TOC roots are group-relative; (iii) if neither, B2 records criterion-(b) and the fatal's gate must be reached legitimately (its own 'not preloaded properly' path is retail's, so the mount/preload phase that fills the group table is the blocker to name). Frontier still `DRAW_INDEXED 0`; nothing regressed.

## 2026-09-23 ~22:40 — T41.3n2 CLOSED (F-094, criterion b). Durable: the guest image has exactly ONE XMemDecompress call site (0x821D5EB8, inside a 12-byte-block container walker = the 7 MB streamables path); the *.list page path (sub_821CC970 pager -> vtable[+28] -> PUMP2 sub_821C5038 -> sub_8244F4C0 -> host NtReadFile) never touches it and the member windows (0xD0000 etc., position proven byte-exact vs raw RPF) are neither plaintext nor container. DISCCHK is load-bearing for reaching star_glow. Baselines now w47..w50 identical-frontier (all on E:). NEXT candidate (NEW task, needs user go — do NOT stack stand-ins): VEH hardware watchpoint on C6157B80/C6167C00 to see if ANY other consumer touches the member pages; that decides between "missing decrypt stage" and "TOC entries pointing at junk the prototype itself ignored". Also star_glow content-absence (F-089) still stands — six .list bodies were never even required to be valid for real-hardware boot evidence-wise.

## 2026-09-23 ~22:20 — T41.3n2 IN FLIGHT (session: E-primary, goal active). State:
- S2/S3 committed + pushed (origin @ `T41.3n2 S2/S3`): XMemDecompress census fixed (entry-lr,
  uncapped dedup). w48 verdict: all 14 boot decoder calls are the 7 MB streamables job;
  zero list-member feeds. Frontier w48 == w47 (C0000005 0, Fatal 2, GFx 3, star_glow 41).
- S4b PROVEN so far (raw bytes vs logs, on E:): globaltex.list runtime entry =
  entry+0=GtaO 3D9B8154, +4=stored 0x23F (575), +8=data_offset 0x000D0000, +12=0x400000EC.
  On-disk xarchive_cache.rpf @0xD0000 head `75914d4e...` == RD-BUF #5 guest buffer
  (C6157B80) head byte-for-byte -> POSITION IS CORRECT. 64 zero bytes at 0xD023F = exactly
  member end -> data region NOT AES-CBC (ciphertext cannot pad to zeros); members are
  headerless LZX (F-073 stands). All reads (TOC + list pages) come from ONE guest pump,
  RD-SUBMIT #1-#8 lr=821C50A4 (inside fiDevice archive code). openGateBit30=1 appears 36x
  in w48 (package entries carry bit30 in +8); the six .list entries have plain offsets
  there — that is the flag DISCCHK forces (peer 21:00 thread, consistent).
- NEXT (exact): disassemble the consumer of C6157B80 after 821C50A4 returns (ppc_disasm.py
  on build/cache/mcla_pe.bin, offset VA-0x82000000) — find the branch that would call
  sub_8244FF20: candidate gates = (a) XMem-header magic check on the page (bytes lack it),
  (b) stored-vs-expanded compare using +12&0x3FFFFFFF=0xEC (236), (c) bit30 of +8 as
  in-package flag. Naming (a)/(b)/(c) with the branch words completes T41.3n2 criterion (b).
- UPDATED after first decode pass: 0x821C50A0-0x821C5108 IS NOT THE GATE. It decodes as a
  pure submit/wait/resubmit PUMP: bl 8244F4C0 -> cmpi r3 -> wait-helper 82135DB0 -> per-item
  bctrl callback at 821C50DC (callee = array @ [r26=0x8286FEA0]) -> second bl 8244F4C0 ->
  loop; tail-exit b 823D9240. The decompress-vs-parse decision is INSIDE that bctrl callee.
  Next session: read [0x8286FEA0] (callback array; runtime, so read from a soak dump or VEH
  census, or find its .data init in mcla_pe.bin @ VA-0x82000000), resolve the callee VA,
  then walk its head for the (a)/(b)/(c) gate. Pump function start is < 821C4E00 (no prologue
  in that window; scan further back if needed). NOTE the F-071(5) "1 of 40 magic" census was
  HOST re-point-branch entries (our mitigation), not a guest-branch count — do not cite it as
  guest behaviour.
- Baselines: w48 (E, post-fix census) vs w47 (E, T41.3o) vs w46 (E, merge-verify) vs w45b (C, frozen).

# HANDOFF — next agent, read this first

> Compressed 2026-09-20. Queue: `LONG_TODO_MASTER.md` (T37.0 first). This =
> frontier + ledger + durable facts. Also: `PROGRAM_GUIDE.md`,
> `ROOT_CAUSE_VALIDATION.md`, `EXECUTION_PHASES.md`, `PLAN_VMX128.md`,
> `CODE_OPTIMIZATION_PLAN.md`. Full text in git
> (`git show 8f07a39:docs/HANDOFF_NEXT_AGENT.md`). Old paths = trail, re-grep.
> `docs/` is **tracked** since `5eb9932` (verified 19:25: `git check-ignore -v docs/*.md` → rc=1) —
> plain `git add docs/…` is correct now; only a *newly created* doc needs `git add -f`.

## LIVE — 2026-09-23 20:16: **`XamInputGetState` detour failure fixed — and underneath it was a second owner faking "no buttons" on the whole input path** (F-092, `build/w45b.log`)

Two deletions + one tool fix; both soaks neutral; frontier numbers are §0f's. Detail in **§0g** / ledger **F-092**.

- The error was **impossible, not a regression**: `FF 25` was demanded of `&__imp__XamInputGetState`, which `GUEST_FUNCTION_HOOK` (`kernel/function.h:351`) defines as a host stub in this binary. Had it matched, the write would have patched 12 bytes of a live emulator function. Deleted with the analysis that hung off it.
- **What actually mattered:** `patches.cpp`'s `SetFunction(0x827BDC64, hk_XamInputGetState)` overrode the slot `ppc_func_mapping.cpp:44998` assigns to `kernel/xam.cpp:261`'s real SDL→pad mapping, and that hook reports no buttons unless a synthetic timer pulses. `app.cpp:337-341` + the post-`InstallFunctionTable` ordering prove the fake always won. Removed.
- **Input is still unexercised — 0 calls** in both baselines, because the boot dies at the shader fatal. Structural correctness + measured neutrality only.
- New tool behaviour worth knowing: if `addr_owners.py --check` on an `0x827BDxxx` import slot says `0 site(s)`, suspect the table — it now reads `ppc_func_mapping.cpp`, but only where src/config claim nothing.
- **T39.9:** 29 `MCLA_LOG_*` calls print their own format string (printf specifiers into an fmt logger), incl. the `BuildInputLayoutFromGrcFvf`/`UploadPacketGeometry`/`GPU MMIO` diagnostics needed for T42.1. Fix them before debugging that path.
- Uncommitted: `src/patches.cpp`, `src/patches.h`, `tools/addr_owners.py`, `tools/ppc_disasm.py`, `src/gpu_cp.cpp`, `src/gpu_device.cpp`, 4 docs, 5 skills. `mcla.exe` not running. Baseline `build/w45b.log`.

## LIVE — 2026-09-23 19:10: **second fleet (7 agents) + the measurement this project has been circling: the guest DOES have the preload-list bytes, they are not ASCII, and nothing feeds them to its own decoder** (F-091, `build/w44c.log`)

**Read this before the 17:25 block.** Its T42.1 plan stands, but its #1 (preload-list body census) is now
DONE and answered, one of its "unverified" items is adjudicated, and the register-file fix it describes is
the last code change before this one.

- **Answered (P0).** 16 new `RD-BUF` lines print read-buffer *content* for the first time ever: the RPF3
  header, the 382,976-byte TOC into `C60B7700`, and the 12 list page reads (32768 B, `read=1`,
  `nz=16/16`, `ascii=4-10/16`) → the guest holds **real, non-ASCII** RPF bytes. So the suspicion that our
  own `NtReadFile` `memset+SUCCESS` branch (`src/kernel/imports.cpp:1103-1108`) was faking the lists is
  **REFUTED** (`C60B7600` is a real `FileObject` handle), F-077's discriminator resolves to "payload
  opaque", and the gap is that **no list member is ever passed to `sub_8244FF20`** (all 16 `XMEM` calls
  carry `srcSz=7179936`). New #1 = **T41.3n2**.
- **A live fabrication found on that same path (P0).** `MclaFindServedBody`'s loose `(dev,handle)` /
  `flagWord` fallbacks (`src/gpu_device.cpp:668-690`) hand the guest a **`resources/ui/legals/legals.xsf`
  body as the body of all five `shaders/*/preload.list` loads** (`BE8D8-PACK #2-#6`, `w43a.log`). It is
  unregistered in §7, untracked by the census tool, and is the same family as F-066's `rage_im` stand-in.
  Delete it as **T41.3o**, its own soak, revert if the fatal block moves.
- **The disassembler lied about calls (fixed, class H).** `tools/ppc_disasm.py` masked op-19 XO to 9 bits,
  so `bctr`/`bctrl` (528) printed as "bclr" — indistinguishable from `blr` (16). Every computed CALL in
  past raw decodes read as a RETURN. Also fixed: reversed `ori/xori` operands, `mr` printed for any `or`
  (dropping RB), `nand` keyed to 476, missing `nor`/`eqv`/`orc`. **F-089 re-audited and holds** — the
  `sub_821CB488 → vtable+4` probe is a genuine `bctrl` call. Re-check any older doc citing a `bclr`.
- **F-090 §7 adjudicated (it was 3/4 wrong).** The "bit30 of `[entry+8]` blocks Open" reading is dead —
  `0x821CCEE0` is `nor r11,r10,r11` and that result is overwritten one instruction later; the real gate is
  `[entry+12]` **bit30 clear AND low byte zero** (`0x821CCF88`-`0x821CCFA4`). `XSF-OPEN ret=` is callee
  residue, not a status/index, so the host's `if (ret == 0)` serve test (`:10434`) is wrong. `[entry+4]`
  is contaminated by our own `WriteU32BE(tocEntry+4,…)` at `:10470`. F-079/F-080: one sentence to fix.
- **Clean foundation, now proven:** 200 executed functions × 20,217 instructions vs raw bytes = **0
  mismatches**; 0 stub markers tree-wide; the "33 % `.long 0x0`" is inter-function padding, none of it on
  the path. `45,190` vs `44,707` mapping entries is a counting-scope difference (`boot_host.cpp:1282`),
  not a loss.
- **Independent blocker named (so fixing the fatal would not be enough):** `XamInputGetState` = 0 calls,
  double-owned (`imports.cpp:3540` vs `patches.cpp:516`), **both** detours failed (`w43a.log:93-94`), and
  `patches.cpp:827` zeroes `wButtons` without a synthetic pulse. 63 `GUEST_FUNCTION_STUB` bodies return
  arg0 in `r3`; 0 `XAudio*`/`XMA*` calls.
- **§7/§9 rewrite is data-ready** (F-091 §7): 330 labels fire, **135 guest-affecting lines/soak are in
  neither §7 nor the census tool**, 226 fired labels are untracked (including `CP-REG-HI` and `RD-BUF`,
  so this session's own gains are invisible in `soak_census` output) ⇒ **T39.8**.
- **User action, do not defer (F-091 §8):** `C:\mcla-pc` has no git and holds the only copy of today's
  work; `E:\mcla pc` has a working 158-commit repo whose tree is OLDER and which uniquely holds
  F-061/065/068-071/074/075 + ~26 queue items. Copy C:'s src/docs/tools/.qoder/build/*.log to a third
  volume, then commit from E: and push. Never copy C: over E:. `xarchive_music.rpf` is 780,304,384 B on
  E: vs a 0-byte stub on C:.
- **State:** `src/gpu_device.cpp` (RD-BUF census) + `src/gpu_cp.cpp` (F-090's widen) + `tools/ppc_disasm.py`
  + these docs + the 5 skills modified, **uncommitted**; `mcla.exe` not running; E: read-only-usable.

## LIVE — 2026-09-23 17:25: **15-agent fleet audit → a real GPU fix landed (Xenos register file was 24 % narrow) and four "frontier" numbers were killed** (F-090, `build/w43a.log`)

**Read this before the 16:20 block below** — that block's `CP-DRAW 52`, its `0x82839F70` citation and its
content-policy escalation are all superseded here; its star_glow conclusion (F-089) stands.

- **What changed in code:** `src/gpu_cp.cpp:52` `kXenosRegCount` `0x2000u → 0x5003u` (upstream
  `register_file.h:40`, read from the local checkout), because type-0 indices are 14-bit and `CpRegPoke`
  returned *before* incrementing `g_xenosRegWrites` — so **every 3D register write the guest ever issued
  was dropped invisibly**. New `CP-REG-HI` line (dedup by base, no counter cap) proves 22 previously-dropped
  bases now land, incl. `val=1000000E` @`0x2180`, `0000FFFF` @`0x2100`, `00000004` @`0x2208`.
- **Measured boot impact: zero, honestly reported.** `DRAW_INDEXED 0→0`, `DRAWDISP 0→0`, `SUBMIT 48→48`,
  `GETDEV 168→168`, `C0000005 0→0`, `w43a.log:4513` fatal verbatim. The widen is a prerequisite, not a
  fix: `grep -c "g_commandQueue|RenderCommand|DrawIndexedCommand" src/gpu_cp.cpp` = **0**, the sole
  enqueue sits behind `sub_82420BA8` (entered 2×, caller hard-zeros `r5`/`r7` at `0x8217BB00-04`), and
  `CpExecImLoad` decodes shader microcode then discards it ⇒ **new #1 = T42.1** (3 census lines: `CP-SHADER`
  retention, coalesce the padding writes, `CP-DRAW-3D`).
- **Numbers to stop quoting:** `CP-DRAW 52` = 24 `CP-DRAW #` + 28 `CP-DRAW-STATE #`, and 24 is that
  printer's cap → say "~28 draw packets, `DRAW_INDEXED` 0". `CP-REG-T0 1171` is a *sample* count under
  `n % 250`. `0x82839F70`'s raw pair is `0x82188E5C`+**`0x82188E64`** (E60 is unrelated) and belongs to
  **F-085(1)**, not F-024. `0x8242FCB0` = **0** lines (only `8242FC1C` is the 13,237-hit site).
- **Escalation withdrawn — no policy call needed:** `mc4/art` is **two 0-byte files** (forbidden tree,
  empty anyway); `default.xex` resource-dir count = **0**; `embedded:/` = 15 hard-coded CRT blobs at
  `src/boot_host.cpp:332-344`, `star_glow` not among them; and **`src/` has no on-disk RPF TOC parser**
  at all, so no host-side "not in the archive" claim is possible — only the guest's (F-089 §4).
- **Fleet refutations worth knowing:** F-063's `D3070` removal is **already in src** (`:11397-11401`) —
  the standing "re-apply it" note in the 06:45/16:20 blocks is obsolete and no build is owed.
  `mitigation_audit.py` → exit 1, §7 registers **13** mitigations vs **80** in `src/`.
  `soak_census.py` tracks **116**, ~49 live markers print behind caps, and `TOC76-SG` is untracked (my
  own gain is invisible in its table). **One agent's TOC field map + inverted bit-30 gate claim is
  UNVERIFIED and listed as such in F-090 §7 — re-read `0x821CCEED`-`0x821CCFF0` before acting on it.**
- **Environment:** `git` is dead on `C:\mcla-pc` (no HEAD/index, empty `objects/`, rc 128) → `git show
  8f07a39:…` in AGENTS.md/skills is unusable, backups are only `C:\mcla-emergency-20260921-0112\`. **E:
  reads fine today** (that is how I checked upstream) but still no writes → build/soak on C: only.
  Ledger has **no numbered F-057…F-076** while `src/` cites seven of them; do not read that as fabrication.
- **Skills fixed on C::** 10 dead `cd "E:/mcla pc"`, `ninja_build.bat` → `build_on_c.bat build` (the
  former hard-codes E: and silently builds nothing), the real `### F-0NN —` ledger format + the next ID,
  the capped-printer rule, and a backup warning on the irreversible `ppc_context.h` step. E:'s copy is
  what a session rooted on E: loads, so those edits only protect C:-rooted sessions until E: is repaired.
- **Uncommitted:** `src/gpu_cp.cpp` (the widen + `CP-REG-HI`), `src/gpu_device.cpp` (F-089's census),
  these 3 docs + `docs/EXECUTION_PHASES.md`, and the 5 skills. `mcla.exe` killed; nothing running.

## LIVE — 2026-09-23 16:20: **T41.3k CLOSED — the device array was never the problem; the archive says `star_glow.fxc` is absent, and the census that proves it was blind until today** (F-089, `build/w42a.log`)

**Read this before the 06:45 block.** That block's next-action #1 (T41.3k) is finished and its premise
was false. Its other two actions are untouched (T41.3l, T40.6 step 4) and its measurements all still hold.

- **What landed:** one log-only census edit + one build + one soak, from `C:\mcla-pc`. `sub_821CB488` is
  now fully decoded (prefix chain → static devices, else registry @`0x82860844`, 276-byte entries,
  `dcnt>1` → call each device's `vtable[+4]`), and the archive's `vtable+4` = `sub_821CDB88` =
  `lwz r11,36(r3); add r4,r11,r4; b 0x821CCEA0` — **strip the mount prefix, tail-call the TOC lookup**. So
  GetDevice's return *is* the guest's own archive answer. `w42a.log:4414-4467` prints it for the first
  time: `TOC76-SG #81-#86`, `fxl_final/star_glow.fxc` + `dcl/star_glow.dcl` +
  `star_glow/dcl/star_glow/dcl/star_glow.dcl`, two calls each, **all `ret=00000000`**.
- **Consequence:** `star_glow` is not findable by path, and it is a **hard-coded effect name** — one
  occurrence in the whole image, at `0x82040F0C` (the fatal's `r4`), inside a table with
  `draw_starglow`/`StarTexture`/`CentrePosition`; the only complete `.fxc` literal image-wide is
  `fxl_final/rage_im.fxc` @`0x820093DE`. The guest's own message ("wasn't preloaded properly") is the
  accurate description. Next = **T41.3n**: get one preload-list **body** in front of us (never done in
  project history) and test whether the names it lists have bodies in this archive; if not, the
  content-policy question goes to the user — do **not** mount `mc4/art` to get past a fatal.
- **Two census traps I hit and wrote down (F-089 §6/§7), both class H:** the `TOC76` printer is capped at
  `n <= 80` and `w41i.log` stops at **#80**, 1 ms before the star_glow lookups — so every
  "TOC76 never fired for X" reading of any pre-today log is worthless. And
  `PathLooksLikeArchiveContent` (`src/gpu_device.cpp:102-110`) has no branch that can match `.fxc`/`.dcl`,
  so the archive census was structurally blind at the exact file the boot dies on. I extended the *gate*,
  not the predicate, because the predicate also drives the Open-gate **write** in `PPC_FUNC(sub_821CCEA0)`.
- **Neutrality:** `w42a` vs `w41i` — `DRAW_INDEXED 0→0`, `CP-DRAW 52→52`, `GETDEV 168→168`,
  `DICT-HYDRATE 11→11`, `TEXDICT-CALLER 11→11`, `C0000005 0→0`, `GFx 3→3`, `[error] 39→39`; only
  `TOC76 +18`/`TOC76-RET +6` (= the new prints) plus KWFSO poll jitter. Rule 12 satisfied (exe
  56,839,168 B @09-21 02:32 → 56,841,728 B @09-23 16:16). `mcla.exe` killed before and after; E: still
  refuses writes (not re-probed this session).
- **Not committed.** `src/gpu_device.cpp` (census only, now 501,9xx B) + these docs.

## LIVE — 2026-09-21 06:45: **prediction→evidence audit of Phase 0 / Phase 1 / §0 landed (F-085, F-086, F-087)** — and it voids the baseline named in the 23:32 heading below

**Read this before the 23:32 block.** Three things in that block are now measured false:

1. **"Newest soak baseline: `build/w38s.log`" is VOID.** `w38s.log` was produced by a tree that no longer
   exists — it carries `MSGBISECT` markers, and `MSGBISECT` appears **0 times** in current `src/`. That census
   was a concurrent session's uncommitted work, destroyed by the E: volume failure. Worse, the only reason
   `w38s` ever got past `star_glow` is that the host **served the 5,258-byte `rage_im.fxc` body in answer to
   `star_glow` requests** (`w38s.log:3848`, `:3860` `AFB76-FALLBACK … serve rage_im`). That fabrication was
   removed by T41.3d. **`w38s.log` is not a baseline and not a target — do not try to restore its frontier.**
   The standing baselines are **`build/w41g.log` and `build/w41i.log`** (both from `C:\mcla-pc`).
2. **Phase 0's "hydration fixed the fatal" is false.** The shader hash-table hydration runs on every boot and
   changes nothing: `sub_82189138` is called **0 times** in `w41i.log` while the fatal still occurs, and in
   `w38s.log` it returned **success** (`DICTLOOKUP-OK … slot=10`) immediately before a *different* fatal. The
   ten objects it writes are `0xA002xxxx` pointers whose +4 word is `00000000` and whose names are empty, so no
   match by name hash is possible. Removal is queued as **T41.3l** under a behaviour-neutral gate.
3. **§0's frontier is stale.** Measured on `w41i.log`: `DRAW_INDEXED` **0**, `DRAWDISP` **0**, `CP-DRAW`
   **52**, CP ring `put=11`, `C0000005` **0**, `GATE-STAGE` **0**,
   `UILOAD-enter/param/ret` **0**. §0's "the boot worker reaches UILOAD for the first time" does **not**
   reproduce — `w41i.log:6400` reads `W34-NOGFX #1 … UILOAD/EF220 never armed after inflate`. Read
   `LONG_TODO_MASTER.md` **§0c** (new, inserted above §0a) instead of §0.

**Still trustworthy after re-measurement (raw bytes, not IDA):** F-024's table `0x82839F70` (`3D608284` +
`3B8B9F70` at `0x82188E5C`/`0x82188E60` inside `sub_82188E50`) · A2's vtable+4 `= sub_821CAFB8` (words at
`0x82012918`: `821CAE50 821CAFB8 …`, preceded by RTTI `820DDDC8 821D61F8`) · F-049's `0x8200AE8C` slot+4
`= sub_821873E8`, a word that appears at only **two** addresses image-wide · F-035's `memory:` literals at
`0x82012A28`/`0x820127D8` · F-033's exactly-two `MOUNT76` (`a:/archive/`, `lr=821CBF54`) · F-031 (TOC76
reaches #80, no `#22` hang) · the whole A1 `GETDEV #38-#43` capsule, verbatim.

**Stop quoting these (refuted):** A2's wrapper `sub_8218C9D8` — 0x1000 bytes of its body contain no `lis` that
can form any of the four `embedded:/` literals; the real builders are `sub_82189138`+0xA8, device-vtable slot 0
`sub_821CAE50`+0x20, and `sub_821CB488`+0x3C, and the measured caller of `sub_821BDF20` on the shader path is
**`sub_8218C760`** (`lr=8218C7F4`). `sub_821CB488` is a **7-byte `memory:` comparator** (compares against
`0x820127D8`), not a "resource handler lookup returning NULL". **Withdrawn by F-088: `40004D7C` is NOT a bad citation** — it is the wait **object** address
(`obj@40004D7C`, `w41i.log:19927`); my 0-in-image test searched the wrong space. Both hot `lr` sites (`8242FC1C`, `8242FCB0`) are `bl 0x827BD5A4` =
`KeWaitForSingleObject` + an MSR-guarded `lwarx/stwcx.` refcount release (13,237 hits/boot), and `reason=3` in that line matches `li r4,3` in the decode — so **F-030 stands**; only its "GPU-worker" label is unverified. **Also withdrawn:** `rptrWB=001F` is a **host-published** gauge (`src/gpu_cp.cpp:161`, `:423-424`), not ring progress (do-not #20), and the `star_glow` → `rage_im` mechanism is **already F-066's** (`LEDGER-ADDENDUM.md:45-54`). See F-088.
`sub_8218C650` is **not a function** — it is `sub_8218C638 + 0x18`. F-055's "no `stw` with immediate `0xE334`
exists in `0x82130000`–`0x82800000`" is **false** — 22 instructions carry that field, three are `stw`, and two
are proven writers of the singleton (F-062 had already refuted that scan; F-087 re-verifies it). And the singleton is **`[0x8287E334]`, not `[0x8288E334]`** (PPC
sign-extends: `0xE334` = `-0x1CCC`; §0's value treated it as unsigned, off by exactly `0x10000`).

**Tree state after this pass.** Comment-only edits, no code and no behaviour change, **not rebuilt**:
`src/gpu_device.cpp:2037-2046` (the false Stage-B root-cause block, replaced with the measured account) and
`:2091-2095` (the "scans 256 slots comparing entry+4 hash" assumption, now labelled assumed). `src/gpu_device.cpp`
is 501,318 B. Because nothing but comments changed, `build/mcla.exe` still corresponds to `w41g`/`w41i`; the
next agent should still verify the exe mtime moved after any real build (rule 12).
Docs updated: `ROOT_CAUSE_VALIDATION.md` 136,694 B (F-085/F-086/F-087), `LONG_TODO_MASTER.md` 64,534 B
(new **§0c** + **T41.3l**), `EXECUTION_PHASES.md` 16,345 B (dated correction blocks on Phase 0 and Phase 1).
**E: still refuses writes** (`No such device` on a plain `printf >` probe at 05:56) — keep building from
`C:\mcla-pc`. No `mcla.exe`, `ninja` or `clang` was running during this pass.

**Next actions, in order:** **T41.3k** (census the `fiDevice` array at `GETDEV #41-#43` — why the same
`arr=C60B4E00 cnt=1 cap=16` serves `a:/archive/textures/…` at #26 but returns 0 for
`a:/archive/fxl_final/star_glow.fxc` at #43) → **T41.3l** (measured, revertible removal of the inert
hydration) → **T40.6 step 4** (drive the host draw enqueue from `CP-DRAW`/`CP-DRAW-STATE`).

## LIVE — 2026-09-20 23:32: IDA attached, three fixes shipped (F-063 is the good one), and the frontier is now **one guest instruction deep inside the `star_glow` shader init** — T41.3b. Newest soak baseline: `build/w38s.log`. Read the 23:32 addendum first; it supersedes the 22:12/21:55 headings for anything about the last `C0000005`.

### Addendum — 23:32: the last AV was a downstream symptom. The blocker is `sub_822FBAF8`, and one over-broad guard was starving it

Session start: the user asked to connect IDA via `opencode.json`, follow `docs/`, produce a long
backlog, and keep going to playable. IDA came up by **attaching to the already-live
`idalib-mcp.exe` RPC on `127.0.0.1:8745`** (47 tools, `get_metadata` = `default.xex` @ `0x82000000`);
`ida-bridge.py` was deliberately NOT run, because its line 25 `taskkill`s that process and another
session owned it. The backlog is `LONG_TODO_MASTER.md` §2 **T41.1–T41.15** (four stages, every item
with a named baseline soak as its gate).

- **The chain, end to end (F-060 → F-061 → F-063).** The last `C0000005` writes to guest `0xE0`
  because `sub_822F3BD8`'s only caller, `sub_823045E0`, passes `this = [0x8287E26C]` = 0
  (`ppc_recomp.50.cpp:6059-6063`), and that word's **only writer in the image** is the factory
  `sub_822F38C0` (`ppc_recomp.48.cpp:27313`) — which is never reached, because the statement before it
  in `sub_823047D8` is a call to **`sub_822FBAF8`, the `star_glow` effect init, which never returns**.
  Both ends turn out to be `(handler, msgid)` table entries (`0x8210DA98` = msg `0x40001503`,
  `0x8210DED8` = `0x40000B03`, `0x82102AC0` = the boot gate's own msg `0x40003B03`) and `src/` has no
  walker for that table — F-060(4).
- **F-063 is the shipped fix and it works.** `PPC_FUNC(sub_821D3070)` skipped any request whose `r4`
  had bit 15 set — a bit its *caller* `8C760` sets as a flag — so the shader's own 32 KB buffer was
  silently dropped. Removing that one clause from the skip condition gives: `D3070-SKIP` 2 → **0**,
  `TSLAB-OWNER size=32768` for the shader buffer, `sub_822F9FA8` (`[0x8287E334]`'s producer — the
  global F-055 said had none) running **for the first time in the project's history**, the guest's own
  `sub_82188CF8` ctor on a simple-pool object (so the `FIX-821873E8` fabrication is no longer reached
  on this path), **host short-circuit lines 177 → 96**, `[error]` 61 → 51, bogus `AllocPhysical` nulls
  3 → 0.
- **Where it stops now, and why (F-064 — read this before T41.3b).** One statement later, the guest
  raises a **fatal**: `'drawblit technique is old and busted, rename to blit_draw.'`
  (`w38s.log:3981`, `lr=0x82188770 r3=0x8200B15C`), right after
  `MSGBISECT 14-8218B688 technique-lookup #6 r3=CA71D388 r4=8200934C` (`:3980`). Cause: the bytes it is
  parsing are fabricated — `AFB76-FALLBACK #4 … serve rage_im buf=827D2DD0 size=5258` (`:3860`) hands
  the guest the **embedded name-list buffer** as `star_glow.fxc`. So the next task is a *data* question,
  read-only: what does the guest's own `TOC76` lookup for `fxl_final/star_glow.fxc` return, and is the
  archive path reachable (F-034)? Never grep the archive to answer it — its TOC is encrypted.
  `DICT-HYDRATE` and do-not #3/#8 both still apply.
- **Two marker drops that are NOT regressions, said plainly.** `UILOAD 1 → 0` and `GFx 9 → 1`:
  the forced gate's only trigger was the `FIX-821873E8` TLSDEAD branch, which the fix made
  unreachable, so `sub_82131008` is now dispatched by nobody — and the 8 lost `GFx` lines are the
  host's own `GFX-*`/`W34-*` stand-in prints, not guest output (F-051's test; **T41.3c** owns the
  choice between dispatching the gate on its real message and deleting the stand-in). The gate also
  no longer runs re-entrantly inside the guest's allocator hook on that thread's stack — it has its own
  host thread + its own `g_userHeap` guest stack (`GATE-STACK`; from the phys o1heap it caused 3 bogus
  `AllocPhysical` nulls).
- **New parked fault, unattributed:** `code=0xC0000005 Param[1]=0x100000040` (guest EA `0x40`),
  `ppc ctx=nil tag=none`, `rip owner=host … not a mapped guest fn`, parked
  (`w38s.log:5804`/`:5825`) ⇒ **T40.5** (symbolise the host fault address) is now on the critical path.
- **Concurrent session, live:** another session wrote **F-062** + **T42.1/T42.2** (the fabricated
  shared TLS block at `0x8F200000`, `r13` hard-set at 25 sites, two refuted causes of `slot12=0`) at
  23:23-23:25 while this one was soaking. F-063's last bullet is the measurement T42.1 §7 asked for,
  for this path. Check mtimes and `tasklist` before building.
- **State on disk:** tree green (`build/w38s_build`… exe 23:17 → w38s), `mcla.exe` killed, IDA left
  running for the other session. **Nothing committed.** Dirty now: the previous session's 14 files,
  plus this session's `src/gpu_device.cpp`, `tools/soak_census.py`, 4 `docs/*.md`, `AGENTS.md`, and
  new logs `w38n`…`w38s`. Never `git add -A` here.


### Addendum — 22:12: T40.6 steps 1-2 shipped; **the guest really does submit draws** (F-059)

Soak `build/w38m.log` (exe 22:05, `BOOT_RC=124`) vs baseline `build/w38j.log` (and `build/w38k.log` for
the census-only step):

- **The CP's own logger was hiding the draws.** `LogUnknownOpcode` reported each opcode `< 0x20` once
  and collapsed **every** opcode `>= 0x20` into a single line — precisely the draw range
  (`PM4_DRAW_INDX = 0x22`, `PM4_DRAW_INDX_2 = 0x36`). Replaced by `LogType3Unhandled`
  (`src/gpu_cp.cpp:351-367`): first 3 hits per opcode with argument dwords. It named 13 previously
  invisible opcodes in `w38k.log` (`0x21 REG_RMW`, `0x2B IM_LOAD_IMMEDIATE`, `0x3B INVALIDATE_STATE`,
  `0x3C WAIT_REG_MEM`, `0x45 COND_WRITE`, `0x46 EVENT_WRITE`, `0x54 INTERRUPT`, `0x58 EVENT_WRITE_SHD`,
  `0x60-0x63 SET_BIN_MASK/SELECT` — names from `xenos.h`).
- **`DRAW_INDX`/`DRAW_INDX_2` now decode** (`src/gpu_cp.cpp:496-531`, `VGT_DRAW_INITIATOR` fields per
  `.research/xenia/src/xenia/gpu/registers.h:311-326`), and the result is concrete: **24 real
  `PM4_DRAW_INDX_2` submissions** — `CP-DRAW #1…#24`, every one `op=0x36 src=2 (kAutoIndex)
  prim=1 (kPointList) numIdx=1 initiator=00010081 hdr=C0003600`, `C71DC180→C71DC238` at an 8-byte
  stride, which is 24 packets × 2 dwords = the nested IB's entire declared 48 dwords. The "misaligned
  walk over data" alternative was tested, not waved away: every header is a well-formed Type-3 header,
  and the absence of a `#64` line bounds the total to `[24, 63]`.
- **`DRAW_INDEXED` is still 0 — decode is not render.** The CP models no Xenos register file, so there
  is no VB/IB/shader state behind a submission. The host-side path that *does* enqueue `DRAW_INDEXED`
  (`src/gpu_device.cpp:1793-1803`) is starved separately and for a documented reason: the
  `sub_82420BA8` hook only sees dummy `li r5=0` submits because the guest's D3D9 chain
  (`sub_8217A470 → sub_8241BE78 → sub_8241C308 → sub_82420BA8`) never runs (`:1829-1835`).
- **No regression:** `C0000005` 1→1, `GFx` 9→9, `UILOAD` 1→1, `PRESENT` 68→68, `Fatal error` 1→1,
  `VEH W0: parking thread` 0→0, short-circuits 178→177. **Next soak's baseline is `build/w38m.log`.**
- **Next:** T40.6 step 3 = register state (`0x21 REG_RMW`, `0x2B IM_LOAD_IMMEDIATE`, the Type-0 writes)
  into VB/IB/shader, and answer what those 24 point draws are — from the register writes, not from more
  draw logging.

### Addendum — 21:55: two of the three fixes are in and soaked; the third task was a false premise (F-058)

Soak `build/w38j.log` (11,120 lines, `BOOT_RC=124`, exe 21:45, `w38i_build2.log` `BUILD_RC=0`) vs
baseline `build/w38g.log`:

- **T40.3 SHIPPED.** `PhysToKernelVA` on the PM4 `INDIRECT_BUFFER` list pointer at both sites
  (`src/gpu_cp.cpp:454`, `:666`). The eight IB packets went from `CP[IB]: TYPE0 base=000` (walking
  zeros) to real Xenos register offsets `A31/A2F/D02/A02/1DD/1DC/5C8/D04` (`w38j.log:858-872`), and
  **three nested IBs are now reached** where `w38g` had none (`:873-875`).
- **T40.4 SHIPPED.** New `CpPrimaryWritebackVA()` (`src/gpu_cp.cpp:986`) replaces the two hard-coded
  addresses in the waiter census (`src/kernel/imports.cpp:2112`+), and `tools/soak_census.py` now prints
  `CP truth drains=8 last_rptr=001F pub=11 put=11 (caught up)` and flags any tracked marker whose
  literal is in neither `src/` nor `generated/` (4 today). Its `rptrWB → "no CP consumer"` verdict is
  deleted, and the `mcla-log-census` skill carries the same correction.
- **`DRAW_INDEXED` is still 0 — the diagnosis was one layer short.** Addressing was wrong, but the
  missing capability is packet *handlers*: this CP implements only Type-3 `0x3F/0x3D/0x48/0x64`, while
  the draws are `0x22 PM4_DRAW_INDX` / `0x36 PM4_DRAW_INDX_2` (`xenos.h:1600-1601`). New #1 is
  **T40.6**, which is T37.6 Wave C — census the real Type-3 stream first, then state, then the handler.
  Do not invent draw data.
- **T40.1 is VOID and must not be implemented.** The "wrong package window" blocker was a sweep artifact:
  the path hard-code and the TOC decode give the *same* offset for the one file where the log exposes
  both (`meshtextures.xtd`, `r5=40060000` → `0x60000`), both call sites already fall back to the TOC, and
  the hard-code is documented as deliberate because TOC-derived `.xsf`/`.xtd` bodies are AES ciphertext
  (`src/gpu_device.cpp:521-523`). F-057(5)'s last sentence is retracted. Lesson for the next session:
  a fleet finding is a hypothesis — check it against the log before queueing work from it.
- Unchanged, as expected: `C0000005` 1 → 1 (same instruction), `GFx` 9 → 9, `PRESENT` 68 → 68,
  `PRESENT-FB` 4 → 4, `Fatal error` 1 → 1, short-circuits 185 → 178. The census's `VEH` 1 → 2 is the
  substring in `ser**ve H**ead` on one new `READWRAP-SERVE` line, not a second AV.

> This block supersedes the 20:40 block (now "Trail"). That block's `[0x8288E334]`, its leaf
> attribution, and its `DRAW_INDEXED 0, CP put=11 rptrWB=0000` line are all **void** — F-056 corrects
> the first two, F-057 the third. Its deletion list, UILOAD-first-time claim and do-not #19 note stand.

**Take `docs/LONG_TODO_MASTER.md` §2 T40.6** (was T40.1 — void, see the addendum). What `build/w38g.log` (exe 20:39, 11,298 lines,
`BOOT_RC=124`, baseline `build/w38f.log`) plus a 22-agent read-only sweep of every `src/`, `docs/` and
`tools/` file established:

- **T38.3f ran and settled the question.** The six seed writes are deleted (`src/gpu_device.cpp:1101+`
  is now a read-only `GATE-FLAG-READ` census) and `sub_82131008` is entered once, unseeded, on a 4 KB
  reserve with `g.lr = ctx.lr` (`w38g.log:3810-3823`). `C0000005` stayed **1** at the *same*
  instruction → the flags were never the cause, and F-055's "the seed lies, so the allocator table is
  never built" hypothesis is not what the surviving fault tests. The forced gate driver is still a
  stand-in; T38.3(d)/(e) remain open.
- **The fault is now named to a generated-code line** (F-056):
  `generated/ppc_xenon/ppc_recomp.49.cpp:2660-2661` `// stvx128 v33,r31,r7` →
  `simde_mm_store_si128((__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), …)` — a **raw, unchecked**
  store (no `IsValidRange`, unlike `PPC_STORE_U32`), with translator-local `r31 = 0` (proved by
  `:2614-2615 addi r10,r31,16` against the dump's `r10=00000010`) and `ctx.r7 = 224` (`:2583-2585`).
  It is inside `__imp__sub_822F3BD8` (opens at `:500`), **not** the leaf `sub_822FA958`; `lr=822F44E0`
  is sticky from `:1965-1966`. And the address F-055 chased is `0x8287E334`, not `0x8288E334` —
  raw `822FA96C 816BE334 lwz r11,-7372(r11)` with `822FA958 3D608288 lis r11,8288`: the D-field
  sign-extends. Do-not #19 now carries a dated correction: `rip owner=` was *right* at function level
  here; it is the PC bound that it cannot give.
- **The pipeline is not starved — we were misreading our own census** (F-057). `WAIT[KWFSO] …
  rptrWB=0000` polls hard-coded `0xC71D81BC` (`src/kernel/imports.cpp:2117`) while the CP publishes to
  `C71D82BC` (`src/gpu_cp.cpp:951`, `w38g.log:794-795`) — 4 bytes to the left, so it can only print 0.
  The ring **drained 8×** to `rptr=001F` with `pub==put==11` (`w38g.log:865`-`:3186`, `GUEST-PUB #5`),
  so "no consumer" is dead. The real `DRAW_INDEXED=0` cause is one line away: `src/gpu_cp.cpp:664-666`
  hands `DrainIndirectBuffer` a raw phys `listPtr` (`0x06258300`) instead of `PhysToKernelVA(...)`
  (`0xC6258300`) → zero packets. That is **T40.3**.
- **Nobody is parked.** `parking thread` = **0** in `w38g.log`; the 2,852 `obj@40004D7C` waits are
  `tid=00000C90 lr=8242FC1C`'s satisfied 16 ms heartbeat (2,851 × `WAKE status=00000000`). The boot
  worker (`tid=19552`, `tag=forced-boot-gate`) stops at `w38g.log:4335`/`:4359` because the handler
  **declined** and the thread was abandoned mid-gate — which is honest, and is why the gate never
  returns.
- **The dark blue is real on screen and 100 % host.** Pixel capture of the live window
  (`build/screen_shot.png`, 33 s into `w38h_screen2.log`): `AVG_RGB=16,26,56`, 79/81 samples `0F1938`,
  title `MCLA Native`, empty client area. That is `0.06,0.10,0.22` — `src/render_thread.cpp:85`,
  `:444`, `:505-507` — presented every ~33 ms because each heartbeat `PRESENT #n … fb=00000000`
  short-circuits the blit (`:535-539`). The four guest `PRESENT-FB sample rgb=(0.06,0.10,0.22)` lines
  in `w38g.log` are *not* guest pixels: `:503-507` substitutes that triple for any framebuffer whose
  sample sums below 0.02, i.e. they report **black** guest frames. Two live defects: Present's HRESULT
  is never checked, and `:572-574` clears *after* `DrawDynamicMesh` inside the same `BeginFrame`.
- **Assets are being read from the wrong window** (F-057(5) → **T40.1**): 6 named UI packages (`resources/ui/`: 5 × `.xsf` + `meshtextures.xtd`, 57 `XSF-OPEN ret=0`) open and
  are served, `xarchive_cache.rpf` is intact, and the real-archive reader already exists
  (`src/fs/vfs_rpf.cpp:443-459`) — but `MclaPreferredPkgOffForPath` (`src/gpu_device.cpp:285-296`)
  picks the offset by path string (`0xA0000` for `.xsf`/`.xtd`/`resources/ui`) instead of using the
  TOC word that `MclaPkgOffFromTocW2` (`:272-282`) already decodes.
- **Tool rot to fix before the next soak** (T40.4): `tools/soak_census.py`'s `VEH_PATHS` has 9 markers,
  **8 of which exist nowhere in `src/`** (verified literal-by-literal), while the one that does fire —
  `VEH W0: parking thread`, `src/boot_host.cpp:1064` — is missing from the list;
  `tools/mitigation_audit.py` self-reports 626 label-shaped tokens → 81 mitigation / 64 census /
  **481 unclassified**; `tools/ppc_disasm.py` decodes no FP/VMX (`?op48:`, `float/ps`) — its claimed
  `ori`/`rlwinm` operand swap is **UNVERIFIED and unsupported** (F-057(6)); the `mcla-log-census` skill
  still teaches `rptrWB=0000` = "no consumer", which F-057(1) forbids (corrected in place at 21:30).
- Verified state at 21:30: tree green (`build/w38g_build.log` `BUILD_RC=0`, exe 20:39), `mcla.exe`
  killed after both the soak and the capture run, `idalib-mcp.exe` live (do **not** start the IDA
  bridge). Uncommitted: `src/boot_host.{h,cpp}`, `src/gpu_device.cpp`,
  `docs/{ROOT_CAUSE_VALIDATION,LONG_TODO_MASTER,HANDOFF_NEXT_AGENT,PROGRAM_GUIDE}.md`. New evidence:
  `build/w38g.log`, `build/w38h_screen2.log`, `build/screen_shot.png`, `build/cap.ps1` (the capture
  script — reusable, takes the HWND from `Get-Process mcla`).

## Trail — 2026-09-20 20:40: T38.3(a)(b)(c)+stages DONE (F-055) — UILOAD reached for the first time; frontier was **T38.3f** stop seeding the gate's flags

> This block supersedes the 19:55 heading below. That block's "delete the gate driver and this AV
> disappears" prediction is **half right**: the crash-path mitigations and the three self-contradictory
> stages are gone, `C0000005` stayed **1**, and the UI layer was entered anyway — so the AV was never
> the gate's own blocker. Its do-not #18 bullet and the `0x82839D70` census are still valid.

**Take `docs/LONG_TODO_MASTER.md` §2 T38.3f** (new #1). What `build/w38f.log` (20:10 build, 10,001
lines, `BOOT_RC=124`, baseline `build/w38c.log`) established:

- **Deleted, with guest justification (F-055 §1):** forced driver stages 1/2/6 — `sub_823043F8`,
  `sub_82304348`, `sub_821FC008` — because the driver *itself* seeds `[0x8288E6F0]=1` and
  `[0x82830B14]=0`, and raw `0x82131020 lwz r11,4(r29)` + `beq → 0x8213103C` / `0x821310C0` show those
  flags make the guest branch over exactly those calls. Also deleted from `src/boot_host.cpp`: the
  `0xC000008E` float-div-0 park + `0xC3` host-entry patch over `sub_823D91F8`, the `0xC000001D` UI-load
  `Rip += 256MB`, and the `isKnownCrashSite` (`0x822F44E0`/`0x82133440`) `s_skipSub822FA958` + `0xC3` +
  `Rip += 256MB` + park chain (`src/boot_host.cpp:1021` has the dated comment). The handler now
  **declines** (`EXCEPTION_CONTINUE_SEARCH`) → generic park.
- **First-ever UILOAD entry, deterministic across two builds** (`w38f.log:3885-3890`; same four lines
  at `w38e.log:3876-3881`): `event1-ret r3=00000000` → `event2-ret r3=00000000` →
  `UILOAD-enter r3=[82830998]` → `UILOAD-param r3=C9A24500`, and **no `UILOAD-ret`**. The event-out
  slots `[r1+80]`/`[r1+84]` are seeded to −1 because guest `0x8213103C li r11,-1` +
  `stw r11,80(r1)`/`84(r1)` do exactly that before the two `bl 0x821C0750`.
- **The one surviving fault is now precise** (`w38f.log:4416-4421`): a **write to guest `0xE0`**
  (`Param[1]=0x1000000E0`, `tag=forced-boot-gate`, `r1=8EFFF510 lr=822F44E0 r7=000000E0 r9=827E0000
  r10=00000010`). `lr-4 = 0x822F44DC` is `bl 0x822FA958` — the 22-instruction leaf the deleted `0xC3`
  mitigation used to patch out. It chases `[0x8288E334]`, which is image bss (0), and **two negative
  scans found no `stw` with immediate `0xE334` anywhere in `0x82130000`–`0x82800000`** — no host-side
  producer exists to copy. ⇒ The next move is to delete the remaining seeds (`[0x8288E6F0]=1`,
  `[0x82830B14]=0`, `[0x82830ACC]=0`) and let `sub_82131008` build its own state, **not** to write
  `[0x8288E334]` by hand (do-not #9).
- **Two new limits on our instrumentation** (do-not #19): `rip owner=…` is a `RtlLookupFunctionEntry`
  *unwind* bound — in `w38f` it named neither `sub_822F44DC` nor `sub_822FA958`, so it cannot bound a
  guest PC at all (F-050's #18 is now generalised). And `build/w38e.log` (1.86 M lines) is **poisoned
  as a baseline** — F-054: one recovery loop = 616,824 of its lines; compare against `w38c`/`w38f`.
- **Still present deliberately:** `GFX-BLOCK` (`src/gpu_device.cpp:1137-1171`, incl. the
  `GFX-FACTORY-SKIP` line) and the `sub_821873E8` TLS-dead branch — left in so this soak's UILOAD delta
  stays attributable to the stage deletions. `DRAW_INDEXED`/`DRAWDISP` **0**, CP `put=11 rptrWB=0000`.
- Verified state: tree green (`build/w38f_build.log` `BUILD_RC=0`, exe 20:10), `mcla.exe` killed,
  `idalib-mcp.exe` live (do **not** start the IDA bridge). Uncommitted: `src/boot_host.{h,cpp}`,
  `src/gpu_device.cpp`, `docs/{ROOT_CAUSE_VALIDATION,LONG_TODO_MASTER,HANDOFF_NEXT_AGENT,PROGRAM_GUIDE}.md`.

## Trail — 2026-09-20 19:55: T38.2b CLOSED (F-050 + F-052); frontier was **T38.3(e)** delete the forced gate

> This block supersedes the 19:25 heading below ("frontier = T38.2b") — items 1-2 of that block are
> still correct as *history*; item 1's "→ T38.2b" is now done.

**Take `docs/LONG_TODO_MASTER.md` §2 T38.3(e).** What `w38c.log` (19:39, 9,726 lines, exe mtime 19:37)
plus this session's raw decode established:

- The instrument works: `w38c.log:4089` prints `ppc ctx=0x8a7b2fefc0 tag=forced-boot-gate`, `r1` moved
  vs `w38b`, `C0000005` stayed **1**, and nothing advanced (expected — T38.2b was diagnostic only).
- **The last residual crash is a call the *host* invented**: `src/gpu_device.cpp:1203-1206` enters
  guest `sub_82304348` with `r3 = 0` on a value-initialised `PPCContext` (`freshVolatiles()` at
  `:1193-1196` clears only `r5`-`r10`). Three pointer-chasing loads (`lwz r3,4(r3)` → `lwz r11,0(r3)`
  → `lwz r10,16(r11)`) are each silently answered with 0 by `ReadGuestU32`, `ctr` becomes 0 and the AV
  is the `bctrl` at guest `0x82304368` — `lr=8230436C` is that call's *own* return address
  (`ppc_recomp.50.cpp:5642`), so for once `lr` is honest. `:1236-1239` already skips `sub_82304398`
  for exactly this reason; `sub_823043F8` (`:1198-1201`) has the same null-`this` shape.
- ⇒ Deleting the gate driver + `GFX-BLOCK` (T38.3(e), and F-051 shows the crash-path mitigations fire
  **0** times in both honest soaks) is expected to make this AV disappear. Prove it with a full marker
  census vs `w38c.log`, not by the absence of the AV alone — and if `GFx`/`UILOAD` counts *drop*, that
  tells you the gate was carrying them, which is its own finding.
- **New do-not #18:** in `rip owner=guest 0xAAAAAAAA +0xBBBB`, the offset is **host** code bytes
  (`RtlLookupFunctionEntry`-relative), not a guest PC. Adding it lands on a block that never ran; that
  false reading is what briefly sent this session hunting a non-existent `0x82839D70` null. Message now
  says `(host+0x…)` at `src/boot_host.cpp:547` (built green `build/w38d_build.log`, `BUILD_RC=0`, exe
  19:52, **not soaked**). Bonus fact worth keeping: `0x82839D70` *is* a real rage static-instance
  singleton (4 writers: `0x82180390`/`0x821809FC` dtor-clear, `0x82186150`/`0x82186240` publish;
  vtables `0x82009D34`/`0x8200AAF4`; 0 owners in `src/`) — unrelated to the AV, don't arm it.
- Uncommitted here: `src/boot_host.{h,cpp}`, `src/gpu_device.cpp` (the `FaultContextScope` publishes),
  `docs/{ROOT_CAUSE_VALIDATION,LONG_TODO_MASTER,HANDOFF_NEXT_AGENT,PROGRAM_GUIDE}.md`.

## Trail — 2026-09-20 19:25: TREE BUILDS GREEN; frontier was T38.2b (dump the *faulting* context)

**Work `docs/LONG_TODO_MASTER.md` §2 T38.2b next** — all rules, verified state and the full trail
live there. This block supersedes items 1-3 of the 17:12 mirror below, which said "tree does not
compile": that was fixed by T37.0 in `5eb9932`, and this session built clean twice
(`build/w38b_build.log` 18:21, `build/w38b_build2.log` 18:39).

1. **The one residual `C0000005` is root-caused and is OUR artifact (F-046).** `Param[1]=0x7E780000`
   is `PPC_LOOKUP_FUNC`'s slot for guest target **0** (identity-probe matched it uniquely,
   `w38b.log:4023`); nulls reach a call because `ReadGuestU32` returns 0 on invalid reads instead of
   faulting (`src/guest_memory.h:82-86`, and `PPC_LOAD_U32` *is* that helper); and the fault is inside
   the **host-forced BOOT-GATE**, which runs guest stages on an unpublished local `PPCContext g{}`
   (`src/gpu_device.cpp:1121-1127`) while `g_faultCtx = &ctx` points at the boot worker's **root**
   context (`src/boot_host.cpp:706`) — so the dump's `lr` **and every GPR** describe a different frame
   (`w38b.log:3864` vs `:4021`: identical `lr`/`r3`/`r8`/`r9`, 1.044 s apart). → **T38.2b**. Loop worth
   noting: the p3b session's "TLS slot-12 host-complete (kills 0x7E780000)" mitigation *is* the path
   that now produces the surviving AV.
2. **Frontier after that = the guest never builds its own GFx loader** (F-044: the guest movie-ctor
   wrapper `sub_82482F78` appears **0** times in any soak, and `GFX-CTOR-VT-MISMATCH` is a false gate —
   do-not #15). Downstream stays starved: `DRAW_INDEXED` 0, `DRAWDISP` 0, CP `put=11 rptrWB=0000`.
3. **`ctr`/`xer`/`r11`/`r14`-`r31` can never appear in a dump** — `src/ppc_config.h:5,9,10` make them
   host locals (proved by 14 build errors this session). Use the lookup-address probe instead.

*Trail (17:12 block, superseded by the three items above — kept so the diagnosis is not re-derived):*

1. **Tree does not compile; another session is LIVE on it** — `build/cp_nudge*.log` series (13
   attempts by 16:23, ~2 min cadence): 4× `CpAdvanceGuestPublication` ambiguous
   `src/gpu_cp.cpp:1044/1109/1344/1451` (T37.0 has the verified diagnosis + the ONE correct
   fix: move the `:328` definition out of the anon ns opened `:22` — do NOT just qualify call
   sites, that link-errors) plus drifting move-injuries in `src/hooks/alloc_census.cpp`
   (gpu_device→hooks relocation in flight). Newest `build/*.log` < 2 min old = stand down
   (LONG_TODO rule 11; docs-only work is safe).
2. **Frontier = W36h** (`8f07a39`): TLS allocator, VEH recovery, boot gate, GFx loader vtable
   + factory call, game data. "UILOAD executes" is commit-claimed only (0 markers in the last
   soak) — UNVERIFIED. W36 is documented nowhere else → T37.2 must record it.
3. **Last good boot** = `build/mcla.exe` @ 14:48 (mtime never moved — no green build since) +
   `build/smoke_long.log` (15:18, 2 min): real packfiles (`xarchive_cache.rpf` 2032 MB),
   TOC76 #69, SUBMIT ×16, GLOBTEX-SERVE alive, threads park, no fatal (only "fatal" text =
   REBASE-POISON census wording). Present is synthetic: guest present-kick ×2
   (`native_renderer.cpp:152` census), both `PRESENT-FB` samples = fallback clear
   rgb(0.06,0.10,0.22) on swap-table slots — F-B reproduced, no real pixels.
4. Everything below = **trail** (pre-W36 paths/line numbers — re-grep before trusting).

## Session ledger — 2026-09-11 → 2026-09-20 (newest first; full text in git)

| Session | Date | What it established / landed | Commit(s) · evidence |
|---|---|---|---|
| **w38a→w38m** | 09-20 | **Eight blockers voided, four code fixes shipped, and the first real draw submissions ever decoded.** Shipped: T38.3(a)(b)(c) deleted the three crash-path recoveries so the handler declines honestly; T38.3f deleted the six forced-gate flag seeds and let guest `sub_82131008` run its own init; **T40.3** `PhysToKernelVA` on the PM4 `INDIRECT_BUFFER` pointer (IB packets went from `TYPE0 base=000` zeros to real register offsets + 3 nested IBs); **T40.4** `CpPrimaryWritebackVA()` + `tools/soak_census.py` `dead_tracked()` and a `CP truth` line (its false `rptrWB → no consumer` verdict deleted); **T40.6 steps 1-2** per-opcode Type-3 census + `DRAW_INDX`/`DRAW_INDX_2` decode → **24 real `PM4_DRAW_INDX_2` packets** (`CP-DRAW #1…#24`, kAutoIndex/kPointList, filling a 48-dword nested IB exactly). VOIDED the same day: the VEH RIP-advance runaway (F-040), the GFx vtable mismatch (F-044), the guest-frame dump reading (F-046), three-owners-of-VdSwap (F-053), `w38e` as a baseline (F-054), F-055's `[0x8288E334]` + leaf attribution (F-056 — the fault is `stvx128 v33,r31,r7` with a null translator-local at `ppc_recomp.49.cpp:2660`, and the real address is `0x8287E334`), five pipeline readings incl. the dark blue being guest pixels (F-057), the “wrong package window” blocker (F-058 — **T40.1 voided, never implement it**), and the logger that hid the draws (F-059). Also proven: the boot worker declines and goes silent rather than parking, and the on-screen dark blue is `src/render_thread.cpp:85,444,505-507` (`build/screen_shot.png`, `AVG_RGB=16,26,56`). **Nothing committed** — 14 modified files in the working tree (`src/gpu_cp.{cpp,h}`, `src/kernel/imports.cpp`, `src/boot_host.{h,cpp}`, `src/gpu_device.cpp`, 4 `docs/*.md`, `AGENTS.md`, `tools/soak_census.py`, 2 `.qoder/skills/*/SKILL.md`). Separately, `GITHUB_APPEAL_REPLY.txt` + `GITHUB_APPEAL_TEMPLATE.txt` show as **deleted** in the working tree (tracked since `e1a2435`, 1156/1093 B) — **not this session's doing**; re-census before any `git add`, and never `git add -A` here. Next: T40.6 step 3 (Xenos register file so the 24 decoded submissions can render); baseline `build/w38m.log`. |
| **W36a–h** | 09-20 | TLS allocator + VEH boot-worker recovery + boot gate + GFx loader vtable + factory call + game data; validators re-added (now moving to `tools/validators/`). Commit map in `LONG_TODO_MASTER.md` §6; no other doc records it (T37.2). | `e46c386` queue trace (19 files, `task_dispatch_trace` +913) · `f3bb765` gpu_device +52, census `sub_8218A008` · `b6528ad` TLS allocator + VEH, dropped the 461 MB `generated/default` blob · `e1a2435` boot gate · `cc3a433` GFx vtable (gpu_device +41) · `8f07a39` game data + GFx factory |
| **p3b** | 09-17 | star_glow fatal GONE: preload inflate host-serve + RSC5 header skip (guest refill Read returns 0 → host-serve 32 KB from `xarchive_cache.rpf` @ 0x60000; head is RSC5 `05435352`, XCompress at +12, `INFLATE-RSC5` strips 12 B); `sub_821873E8` TLS slot-12 host-complete (kills 0x7E780000); guest-memory view self-test PASSED (guard-page addrs ≥ 0x1000). Frontier: job #2 (swfC, tag 0x8004, dest B7B41000) — blind RPF host-serve serves wrong bytes (`INFLATE-SKIP` magic 6655A8B1); present still INERT (draw_indx=0, picker=0); residual AVs on the swfC dtor path. | soaks `build/boot_stdout_p3*.log` |
| **p2t** | 09-17 | `821873E8` fixed + self-test PASS; star_glow frontier reached. | `EXECUTION_PHASES.md` → PHASE 2 log |
| **p2p** | 09-15 11:20 | **F-039** identity-semaphore fix (`NtCreateSemaphore` handle was never registered → Release woke a phantom wrapper = T5 root cause). Preload RUNS; GPU frames start. | ledger F-039 |
| **p2f–p2o** | 09-15 | Preload crash chain FIXED (three-guard neutralization of poison container walks, **F-038**; `GetKernelObject` raw-cast AV, **F-037**), boot stable 240 s+. | F-036/F-037/F-038 |
| **p2f** | 09-15 07:00 | rgxa magic check decoded (**F-036**: preload `.xsf`/`.xtd` stream containers never filled — CDCD); rgxa FIXED → new frontier 825FDC64. | `EXECUTION_PHASES.md` p2d/p2f |
| **p2c** | 09-15 | Second fix: BE8D8-HOST path + slot-0 guard. | p2c log |
| **p2b** | 09-15 | First Phase-2 fix: `MakeMemoryStream` inserts into the guest slot table. | p2b log |
| **p2a** | 09-15 | Static-analysis pass: T2/T3/T5 decoded **before** any boot (no code change). | p2a log |
| **t24d analysis** | 09-14 | No code changed, three corrections: (1) boot is not parked, it is a **0xCDCDCDCD fill marathon** (`CDCD-FILL #135,640,000 @ AC8EE8C4`, lr `821BE3BC` inside `sub_821BE250`, frontier walked A0024020→AC8Exxxx ~210 MB at ~1.5 MB/s); our own CDCD watcher may dominate cost. (2) TLS is **not proven wiped** — `tls0`=8F201000 (armed) in every park sample of t23b…t24c, `ATARRAY-TLSDEAD` fired 0×; real disease = new threads get a zeroed TLS table by design (`src/kernel/guest_thread.cpp:20-35`) and only the slot-28 alloc chain is ever armed — **TLS slot +12** (atArray 16 B family) and **FuncBlock+16** (realloc) are armed by nobody. (3) Streaming is half-alive: NFS reads happen at thread-spawn (`evt=0/apc=0` = the 75w dormant-pending-slot issue) but INFLATE/READWRAP/XMEM = 0; the executor's 3-slot 32 KB page cache serves 0 on a miss and contains no fetch call (batch-1 fetches went through `sub_8244F4C0`, later batches never arm it). | handoff "ANALYSIS PASS" + `build/*t24*` logs |
| **t23a→t24c** | 09-14 | Boot PARKED, 13 guest threads, 0 AVs. `0x7E780000` decoded = `PPC_LOOKUP_FUNC(guest 0)`, i.e. `bctrl` through a NULL guest fn ptr — the whole "AV storm" family was null-indirect calls. atArray ctor guards `sub_8218AF68` (16 B), `sub_82189F00` (32 B, tails 0xFFFF), `sub_8218BFF0` (16 B #2) → poisoned count/cap becomes an empty array. XTL import strong overrides `sub_82130528` (alloc) / `550` (alloc-max) / `588` (free) call `__xtl_alloc/free` directly — **ABI: set r4=size, r5=16, r6=0 before `__xtl_alloc`** (leaking stale r4 produced a host-pointer/nul AllocPhysical storm in t24a). `sub_821D30E8` (buffer Grow via TLS FuncBlock+16 realloc) hooked host-side, realloc semantics kept. BE250 dead-stream reads host-served (`MemoryStreamServeRead`) instead of −1 (the −1 poisoned count/cap). | commit `f9278c5` |
| **t4–t15 rounds** | 09-13/14 | Successive boot-init fix rounds (seed/rebase, TLS slot arming, host-complete of guest stubs — e.g. BE0C8, T8b AV chase, t11b→t15b soaks): every round = boot ×2 into a new log, then a new documented frontier. Jump targets/host-completed addresses live in the pre-compression text (git) and in the cheat sheets below. | `build/boot_stdout_t*.log` |
| **T4-final** | 09-13 | star_glow fatal gone; memory-device vtable **0x82012918** installed on the static device; PE section table parsed (`mcla_pe.bin` = decompressed linear image, identity `file_off = VA − 0x82000000`; PE raw pointers are NOT offsets into it). GETDEV prefix returns static Device* `0x827D838C`; fallback slot `0x827D8380` (later identified as the `fiDeviceMemory` type_info/VFT object, **not** a holder — `PROGRAM_GUIDE.md` §8); host dead-ctor replay `ReplayDeadMemoryDeviceCtor()` + strong overrides of CRT `sub_827B8B38`/`sub_827B8B20` (CRT was clobbering the vtable with base `0x8201206C`). Never write guest-heap scratch (`0xA00xxxxx`) from these hooks. Boots: `t4final2`/`t4final4` = GETDEV 24/5, star_glow 0, fatal 0, VSYNC 120. | soaks `boot_stdout_t4final*.log` |
| **weaker-model plan** | 09-13 | AFB8 hook landed: `sub_821CAFB8` resolves `embedded:/` via the D22E8/D2308 name list (head `0x82860AF8`) using CRT embed-seed (`SeedEmbeddedNameList`: `node 0x828495B8, name 0x820093D4, buf 0x827D2DD0, size 0x148A`); new signal `AFB76-HIT` (2 boots). **EMB76 stays 0 forever** — INSERT uses vtable+4 (AFB8), not +16 (CB070). Post-inflate D2308-INS wired but skipped (`inflSize=12` sentinel). | `boot_stdout_t5c.log`, `t5d.log` |
| **session 78** | 09-12 | **Broken-stub census 91 → 0.** Last 30 distinct stub targets were one defect repeated: the recompiler under-measured 19 functions, orphaning their exit blocks; fixed by a JTS-TAILCALL tool patch + a dispatch-guard hook. | commit `75ed486` |
| **session 77** | 09-12 | **Systemic jump-table defect FIXED and landed** (patched XenonRecomp regen): each jump-table switch had recompiled to a `// ERROR: 0x…` stub (1557 sites / 873 targets). 863 mapping entries dropped (none referenced from `src/`), dispatcher spans `0x825FDA90`/`0x8260B588`/`0x821DEE40` survived, `ppc_context.h` came back content-identical; output is **176 TUs, not 179** (CMakeLists updated — re-check on any future regen). `sub_8226B450` (29 sites) had to be host-defined in `patches.cpp` (`38600001 4E800020` = `li r3,1; blr`) because the tool registered it without a body. Boot behavior-neutral vs 76y. Residual backlog: 30 distinct targets still stubbed — `0x8255FD48` ×9, `0x8264B38C` ×6, `0x82135C28` ×6, `0x82397FF4` ×5, `0x82388030`/`0x8238802C` ×4 each. Regen config `mcla_jts_regen.toml` (bare filename; scratch copy in `build/xr_jts`). | commit `b3d7dab`; soak `boot_stdout_jts_regen.log` |
| **76t–76y** | 09-12 | **The 0x7E780000 GetDevice crash FIXED.** Root cause = buffer OVERFLOW, not poison: `sub_8218DCE8` (texture pitch) is a jump-table switch emitted as `ERROR: 0x…` stubs → pitch never written → the "missing texture" checkerboard path sized its buffer 32 B but filled 4096 B, over the device-registry holder. Fix = faithful host override `PPC_FUNC(sub_8218DCE8)` in `patches.cpp` reconstructed from the raw image (jump table @0x8218DD14, bodies @0x8218DD6C-30; fmt 1 → `w*4`). New frontier: clean guest fatal (exit 3) `'Unable to load shader 'star_glow', it probably wasn't preloaded properly.'` — the `memory:` mount never happens. Also: BOOTPATH census hook AV'd on garbage descriptor fields → rewritten with checked `ReadBytes`; allocator instrumentation (GEN76-ALLOC ≥4096 B, GEN76-FREE, BUDDY76-*, TEXCTOR) added. | soak `boot_stdout_76y.log` |
| **76j–76s** | 09-12 | Crash decoded: the "missing texture" checkerboard **overwrites the device-registry holder**; allocator fully mapped (3 RE subagents); PAGEWATCH caught the `FF00FF00` writer, FFBT gave the host callstack; lockFlag=FFFFFFFF verified. Evidence: `boot_stdout_76k…76s.log`, `crash_dump.txt` (deterministic signature r3=FF00FF00 r4=8EFFF540 r6=A0082510 r7=A008272C lr=821CB670, AV read at 0x7E780000 = first uncommitted page below the scan). | 76k–76s logs |
| **76i** | 09-12 | Registrar caught: `lr=821C2AAC` writes the registry array; the **count is never written**. PAGEWATCH on registry header `0x82860844` (12 bytes). | `boot_stdout_76i.log` |
| **76h** | 09-12 | Device registry decoded: head `0x82860844`, **stride 264**, entry match fn `821CAA28` (loop in `sub_821CB488` tail, TU18:1419+). | `boot_stdout_76h.log` |
| **76g** | 09-12 | Crash = `fiDevice::GetDevice` walking a BAD device entry (device-list dump in `crash_dump.txt`). | 76g log |
| **76f** | 09-12 | The "ui" preload-list global is **never populated** (watch-proven). | 76f log |
| **76e** | 09-12 | Crash is in **"ui" resource-package processing** (`BOOTPATH` census `sub_82187820`; full decoded chain). | 76e log |
| **76d** | 09-12 | **Positional-read race FIXED** (`ReadFileAt` in `src/fs/vfs_rpf.cpp`: positional OVERLAPPED for real RPF handles; two threads had shared one position). Remaining crash = uninitialized task handle (poison family). | 76d log |
| **76c** | 09-12 | Bad `r8` (0xFFFFFFFF7E780000) is **built in registers** — pinned via llvm-symbolizer + PDB to the inlined call site of `sub_8218F308` inside `__imp__sub_821FA438` (`ppc_recomp.23.cpp:5274`). | 76c log |
| **76b** | 09-12 | The 0x7E780000 pointer is **computed, not copied**: a needle scan of stacks/inflate-out/phys-heap found 0 occurrences. | 76b log |
| **76a** | 09-12 | Host segfault decoded — the crash filter DID work (`crash_dump.txt`): guest AV at 0x7E780000 in the boot-init chain, `ppc lr=821782AC r3=C98C4000 r5=2000 r8=0x1000`. SLOT-READY hardened to require a completed-read set (correctness gate). | 76a log |
| **75z** | 09-11 | 'Fatal disc error' FIXED — `sub_821CC1E0` fatals when `[dev+12]` bit30 set && bit31 clear; our devices had bit30 set and bit31 never set. `DISCCHK` hook sets the ack **before** the original runs. New frontier: reproducible host segfault. | gpu_device.cpp DISCCHK hook |
| **75w** | 09-11 | **Boot stall DEAD.** `sub_821CBE18(slot)` = "wait for slot": waits on the slot's event while `[slot+12]==1`. Our `NtReadFile` completed every read synchronously with evt=0/apc=0 and signalled nothing → the refill loop spun forever. Fix = `SLOT-READY` marks the slot done when the read already completed. Result: `INFLATE-PENDING` 18+spin → 0, SLOT-READY ×3, boot advances past the weeks-long loading-screen stall into 'Fatal disc error'. | soak `boot_stdout_sr.log` |
| **75v** | 09-11 | Page cache is alive; **our NtReadFile violates the Xbox async contract**. Kernel wrapper `sub_8244F4C0` presets `ioStatus=259` (STATUS_PENDING), calls `NtReadFile`, then takes the async path only if r3==259. `RD-SUBMIT` fired 24+ (32 KB reads into page buffers, lr 821C50A4 via vtable slots `0x820121B4`/`0x821062C8`); PAGESLOT real state: `slot @A0083788 base=0x13 size=0x8000 buf=A00E5880 state=2 event=C6009900`, `base=0x14 size=0x8000 buf=A00ED900 state=1`. Fix target: return 259 + `Information`=bytes + signal the event. Also fixed a PAGESLOT dump bug (inner object = `[join_entry4+8]+32` = A0083660, not the vtable). | soak `boot_stdout_75v*` |
| **75u** | 09-11 | Executor decode: 3-slot 32 KB page cache serves 0 bytes on a miss and contains **no fetch call**; batch-1's fetches went through `sub_8244F4C0`, later batches never arm it. This retracts the 75r/75s/75t readings. | 75u log |
| **75o** | 09-11 | Boot requests NAMED: message `0x40003803` → handler `sub_821E5FD0`; task chain captured. Warning recorded: IDA xref lists on this raw bin must be bl-scan-verified. | 75o log |
| **75n** | 09-11 | Boot load machinery verified WORKING (queue, worker `sub_821BC910`, executor, inflate, ~4 MB reads, 15 resource bodies, 1550 shader dicts) — the stall is UPSTREAM in the game-logic init sequence. `INLINE-EXEC` node dump replaced by REQDUMP (16 dwords + ASCII name scan). | 75n log |
| **75m** | 09-11 | The "dead loaders" are dead on hardware too; the dict factory is the **SHADER pipeline** (names are technique names: `draw`, `zprepass_draw`, `multilight_drawskinned`, `CopyDepth`…). File I/O dies after one 4 MB burst (sequential 32 KB reads 0x800→0x3D8000 then zero reads for the rest of a 90 s soak). The streaming/UI loaders are registered in (handler,msgid) tables in `.rdata` (streaming table `0x82104B10`) — reachable only by messages. | 75m log |
| **75l** | 09-11 | Recompiler gap found + fixed: `sub_8221D9D0` had no body (a bogus 4-byte "function" at `0x8221D9CC` swallowed it → the build was broken). DICTFACT decode: `sub_8218BF20`'s r4 is a live deserialization stream slot — 40-byte slot array `0x82860C18`, slot allocator `sub_821BDDE8`, per-slot 4 KB buffer `0x82860DF8 + i*0x1000`, free-slot count `0x827C8874`. Env gotcha: `build/game_data/mcla extracted cache/` must exist or `app.cpp:90` skips `vfs.Initialize` and every `game:/*.rpf` open fails. | soak `boot_stdout_dfact.log` |
| **75k** | 09-11 | GLOBTEX-BOOT: host reads `globaltex.list` (cars+city) and calls the guest insert linker `821854C8(noneObj, name)` per first token → `GLOBTEX-BOOT inserted=20 noneObj=A010B7E0` (the game's own insert on the game's own `none` object). | soak `boot_stdout_gtex.log` |
| **75j** | 09-11 | Insert path works (5×) — ctor `82185648` → insert `821854C8`; but only 3 real names are ever constructed (`"Not Implemented"`, `"uiOverlay"`, `"uiOverlayDepth"`); `STREAMTEX`/`UILOAD` = 0; `REBASE-POISON` 32. Factory parent `sub_8218C760` → `sub_8218C1C0` → `8218BF20`. | soak `boot_stdout_ins2.log` |
| **75i** | 09-11 | Empty-dict factory vs real loader mapped: `sub_8218BF20` zeros dict fields then `8218B000` registers; bulk loaders still dead. | 75i log |
| **75h** | 09-11 | XMemDecompress works — `XMEM` hook `sub_8244FF20` fired 14×, **all `ret=0`** (LZX decompress succeeds); outputs are not texture dicts. | soak `boot_stdout_xmem2.log` |
| **75g** | 09-11 | RSC5/.xtd layout: sample `vnyl_tears_05.xtd` (1227 B) starts `05 43 53 52` = version 5 + "CSR" (RSC5) with XCompress at +12 — matches the inflate 12-byte header skip. | soak + `docs/MCLA_RPF3_Technical_Reference.txt` (lost to the gitignore; folded into `PROGRAM_GUIDE.md` §4/§6) |
| **75e** | 09-11 | IDA MCP live (`:8745`, `mcla_pe.bin`, base 0x82000000). Texture-dict path decoded: named lookup `sub_821849C0` (`"none"`→`0x82839CF0`, else hash `sub_82183E80(&0x82839E2C)`, else list `0x82839ED0`; miss → fatal `"Unable to find texture '%s' in any active texture dictionary!"` @ `0x82009E20`); register `sub_82197598` (not in `ppc_func_mapping.cpp` → no `PPC_FUNC`; census on caller `sub_8218B000`). Dictionaries DO register (10×) but named lookups miss → dict *contents* empty. | soak `boot_stdout_c75f.log` |
| **75d** | 09-11 | TEXINIT runs; named registry fill still missing. Texture registry decoded (`sub_821811C0` lookup, hash table `0x82839E2C`). **Ghidra MCP retired** — IDA Pro idalib is the only RE backend. | soak `boot_stdout_c75e.log` |
| **75c** | 09-11 | Loading gate mapped: `DRAWDISP` (`sub_82227428`) never entered; inflate `-12` / magic `525DE064` is **not** the geometry gate (**stack residue**, not a format magic — 0 hits in src/ + generated/); the `8242FC1C` wait is the healthy GPU-worker tick (`40004D7C`). | soak `boot_stdout_c75d.log` |
| **75b** | 09-11 | `DRAW_INDEXED` mapped: real geometry path `sub_8217A470` → `sub_8241BE78` (SetStreams) → `sub_8241C308` (needs r6=IB) → `sub_82420BA8` **NEVER RUNS**; only the dummy/HUD submit `sub_8217B7B0` (r5=0, streams=0). `DRAW_INDEXED=0` is a symptom of never leaving loading, not a draw-builder bug. | soak `boot_stdout_c75.log` |
| **75** | 09-11 | VMX128 type-2 pack LANDED (Route A): 4 `[[midasm_hook]]` entries in `config/mcla_xenonrecomp.toml` @ `0x821B3814`, `0x821B3C2C`, `0x821B3E90`, `0x821B4788` + host impl `mcla_Vpkd3d128_type2`; no `0x80000003` in any soak. Regen reproducibility proven: 181/183 files byte-identical (only `ppc_context.h` trailing newline and `ppc_recomp.10.cpp`, which carries a hand safety patch inside `sub_8218CC70` — **never full-replace that file**). Caveat: `VMX128-PACK` counter never fired → not runtime-validated. | `boot_stdout_vmx2/3.log` |
| **74** | 09-11 | Heap AV storm CLOSED — `BLIT-OOB-GUARD` (`gpu_device.cpp` `sub_82431A40`: skip blit when `rectW*rectH` provably exceeds the exact tracked alloc; smoking gun `nearestAlloc=CAEBB000 size=0xa000 gap=0x4`). D3D12 backend up (RTX 3070, 1280×720). New blocker = unimplemented VMX128 ops (host `int3`). | `boot_stdout_blit3.log` |
| **72–73 baseline** | 09-10 | KDELAY stall passed (`SLEEP60270`=0); meshtextures fatal passed via `REBASE-POISON` + D890 skip; ring-B consumers drain; **native present works** (`FRAME-END` ×9+, `NATIVE-PRESENT` ×6, `SWAP-COMP`=9); `DRAW_INDEXED`=0 (empty VB/IB); CDCDCDCD still poisons object fields. | `PROGRAM_GUIDE.md` §7 table |
| **≤ s64** | ≤ 09-09 | Guest park blocker closed: spinlock seed 1→0 in `VdInitializeEngines` + host-side kernel-wrapper identity map; game ran 10+ min in loading screens, 0 crashes. | `docs/BOOT_HANDOFF.md` (lost to the gitignore) |

## Durable facts (still cited; carried forward from the compressed blocks)

**Boot-stack layer map** (layer → status as of the last good soak; use it to place any new
frontier):

| # | Layer | Status |
|---|---|---|
| 1 | CRT init / module load | DONE |
| 2 | Kernel imports (xam/xboxkrnl, 46k stubs, 0 broken) | DONE |
| 3 | Memory device / VFS (`memory:`, `embedded:`, RPF packs — rgxa accepted at BE710, memory-stream reads host-served at BE250) | DONE |
| 4 | Title subsystem ctors (atArray factory family, XTL allocator imports) | DONE (t23a→t24c guards/overrides) |
| 5 | Worker-thread spawn + streaming loads (13 guest threads, entries `821C91C8` + `8242FB88`, semaphores, NTWFSO waits, CP doorbell drain `gpuCtx=40002080`) | REACHED — threads wait on work/streams; W36 moved this further |
| 6 | GPU submit / draw calls / presentation | NOT reached cleanly (`DRAW_INDEXED`=0; present is synthetic) |

**TLS / allocator** (the t24d correction is the current truth):

- New guest threads get a **zeroed TLS table by design** (`src/kernel/guest_thread.cpp` zeroes the
  whole PCR+TLS+TEB+STACK block — was lines 20-35 in the pre-reorg tree). `boot_host` arms ONLY the
  slot-28 alloc chain: **TLS slot +12** (atArray 16 B family) and **FuncBlock+16** (realloc) are
  armed by nobody → first-use AV through a never-armed slot looks exactly like a wipe. `tls0`/[r13]
  is intact (`8F201000`), `ATARRAY-TLSDEAD` never fired.
- Physical pool: one `MmAllocatePhysicalMemoryEx` → o1heap arena at guest VA
  **`0xA0000000`–`0xFFFFFFFF`**; pool16 slabs inside it (`A0014xxx`). Never write `0xA00xxxxx`
  scratch from `SeedPreBootSlots` (o1heap corruption) or from the dead-ctor replay.
- Guest allocator: registry `0x82830B18`; dispatch `sub_821C08F8` →
  `m_Allocators[(r6+1)*4]` = **sysMemDualBuddyAllocator** (arenas `B7xxxxxx`) for default
  allocs; the simple allocator (pool `A0001010..A2E81000`) serves direct callers only. Tiny-slab
  `sub_821DE9D8` memsets every returned element with `0xCD` (so `0xCDCDCDCD` =
  never-initialized field, *not* corruption).

**Executor / streaming** (t24d + 75l–75w):

- The executor's 3-slot 32 KB page cache serves 0 bytes on a miss and contains no fetch call;
  batch-1 fetches go through `sub_8244F4C0`, later batches never arm it → the executor fetch
  gate is the starvation, not the loader.
- File I/O dies after one 4 MB burst (sequential 32 KB reads then 0 reads for the rest of a
  soak) — the game itself never queues another request.
- Host `NtReadFile` completes synchronously; the Xbox contract expects
  submit → STATUS_PENDING (259) → completion finalizes the slot. `SLOT-READY` (`sub_821CBE18`)
  is the honest equivalent while the IO really did complete; `RD-SUBMIT`, `PAGESLOT`,
  `READWRAP` censuses exist for this path.
- Streaming/UI loaders are reachable only by messages ((handler,msgid) tables in `.rdata`;
  streaming table `0x82104B10`); boot loads arrive as msg `0x40003803` → `sub_821E5FD0`.
- Dict-factory stream slots: 40-byte slot array `0x82860C18`, allocator `sub_821BDDE8`,
  per-slot 4 KB buffer `0x82860DF8 + i*0x1000`, free-slot count `0x827C8874`.

**Device / filesystem (`rage::fiDevice`)** — locked facts:

| Fact | Value |
|---|---|
| Guest image | `build/cache/mcla_pe.bin`, identity `off = VA − 0x82000000`, instruction words big-endian |
| Memory-device vtable | `0x82012918` (`+0` `sub_821CAE50` exists/size, accepts `embedded:/` via list; `+4` `sub_821CAFB8` open, **only `memory:`**; `+16` `sub_821CB070` table insert = `EMB76` census; `+80` `sub_821CB400`) |
| Static Device* / dead pointer | `0x827D838C` — returned by the GETDEV prefix checks *and* the dead pointer for `memory:`/`embedded:`. `0x827D8380` is the `fiDeviceMemory` type_info/VFT object, **not** a holder (`PROGRAM_GUIDE.md` §8); base fiDevice vtable (open = stub) `0x8201206C` |
| Name-buffer list | head `0x82860AF8`, node `{+0 name, +4 buf, +8 size, +12 next}`; insert `sub_821D22E8(node,name*,buf,size)`, lookup `sub_821D2308(name,&buf,&size)` |
| Device registry | header `0x82860844` = `{Device** @+0, u16 count @+4, u16 cap @+6}` (cap 16 from `0x827D8384`), entry stride **264**, best-prefix match `sub_821CAA28`; the registrar writes the array but never the count |
| Mount | `sub_821CB9D8`, only 3 call sites; the non-archive chain never executes (F-034) — `MOUNT76`=2 in every boot |
| INSERT resolution | `sub_821BDF20` → GETDEV → **vtable+4** (AFB8), so `EMB76`(+16) is never the acceptance signal |
| Packfile vtable / TOC | `0x82012BDC` / embedded `0x82012B44`; TOC lookup = vtable+144 `sub_821CBFC0` (0 if `[obj+8]==0`); Open `sub_821CDB88` |
| `memory:` strings | `"memory:$%p,%d,%d:%s"` @ `0x82012A28`, `"memory:"` @ `0x820127D8` |
| RPF3 | header `0x800`, TOC `0x1000`, 16-byte BE entries; `xarchive_cache.rpf` has the `0xB116A6AB` TOC-encrypt marker at 0x800 (guest decrypts with the embedded key — works). Compression is XMem LZX, not zlib. |

**Shader / texture dictionary** (used by the T37.4/T37.5 waves):

- Lookup `sub_82189138` (r3=name, −1 on miss, `ppc_recomp.9.cpp`); INSERT `sub_82188E50`
  fails because the resource handler `sub_821CB488` returns NULL; dict hash table
  **`0x82839F70`** (256×4 B; the early `0x827C9F70` was a decode error), active list
  `0x82839ED0`; factory `sub_8218BF20` via `sub_8218B000` (10 entries); ctor `82185648` →
  insert `821854C8` is the working named-texture path.
- Fatal switch `byte_827D5C70` = compile-time 0x01 with zero runtime writers — never patch it.
  Fatal raiser `sub_821BD618` → slot `0x8285FEA0` = `0x82130678` (a real function), host
  override `patches.cpp:441`; `DICT-HYDRATE` (commit `3c8744e`) stays until INSERT proves clean
  without it. Preload lists: `a:/archive/shaders/{ui,city,cars,characters,effects}/preload.list`.
- RSC5 `.xtd`: `05 43 53 52` (version 5 + "CSR"), XCompress at +12 → the inflate hook
  (`sub_821D5E10`, magic `0x0FF512EF`, unknown magic → skip-fatal) strips 12 bytes;
  `XMemDecompress` (`sub_8244FF20`) works (14× ret=0).

**Draw/present path**: real geometry `sub_8217A470` → `sub_8241BE78` (SetStreams, writes
`dev+12748` count + VB descs at `dev+12756`) → `sub_8241C308` (needs r6=IB) → `sub_82420BA8`;
the only live submit is the dummy/HUD one (`sub_8217B7B0`, r5=0). Present swap-table handshake
at `dev+21624/21628` (2 slots per kick, guest writes ZERO, HW fills timestamps LE; completion
processor `sub_824286A0` advances only when slot `(completed+1 & 7)+16` is ready). Task-join
table: count `0x8283D1A8`, entries `0x8283D1C4`, stride 28, wait word `entry+12`.

**Lessons that cost sessions (process):**

- Guest-LR attribution lies after memset/slab-wrapper calls (sticky LR; `0x8244D158`,
  `0x821C2AAC` are artifacts) — use xrefs + arg regs, or the `FFBT` host-backtrace probe.
- `0xFF00FF00`/`0xFFFF00FF` = checkerboard "missing texture" texels, NOT poison.
  `0x7E780000` = `PPC_LOOKUP_FUNC(guest 0)` (null indirect call). `525DE064` = stack residue.
  `0x80000003` = XenonRecomp `__builtin_debugtrap()` for an unimplemented VMX128 mode.
- Before calling a "field never written / garbage value" bug a poison bug: grep the ERROR stubs
  on the involved functions (`grep -hn "ERROR: 0x" generated/ppc_xenon/ppc_recomp.N.cpp`) —
  silent stub returns caused weeks of misdiagnosis (texture pitch → heap overwrite).
- One new log name per experiment; `timeout` every boot; kill `mcla.exe` before linking and
  after every soak; verify `mcla.exe` mtime moved after a link (stale-exe trap). Never build
  while an old `mcla.exe` is running.
- When two statements conflict, the higher/newer one wins — later blocks overturn earlier ones.


## LIVE — 2026-09-21 02:30 (shell clock): **the working copy is `C:\mcla-pc`, not `E:\mcla pc`** — register file landed, draws are 52 not 24

**Read this before anything else.** The E: volume is progressively poisoning files: `build/` refuses new
files, `.git` is unusable (`git status`/`diff`/`ls-files` exit **127 with no output** because the pack
`.idx` is unreadable), and `docs/`, `src/gpu_device.cpp`, `generated/default/*` and `.research/xenia` have
each gone unreadable at some point during this session. **Do not build, soak or write docs on E:.** This
directory (`C:\mcla-pc`) is a sha256-verified copy plus the reconstructed sources, and every claim below
was measured here.

**The loop (all of it works today):**
```
cd /c/mcla-pc && MSYS_NO_PATHCONV=1 MSYS2_ARG_CONV_EXCL='*' cmd.exe /c "C:\mcla-pc\build_on_c.bat"        # full configure+build
cd /c/mcla-pc && ... cmd.exe /c "C:\mcla-pc\build_on_c.bat build"                                          # incremental build only
cd /c/mcla-pc && timeout 120 ./build/mcla.exe > build/wNN.log 2> build/wNN_err.log; echo BOOT_RC=$?           # 124 = survived
cd /c/mcla-pc && python tools/soak_census.py build/wNN.log build/w41g.log                                    # per-marker census
```
Verify the exe moved (`ls -l build/mcla.exe`) before believing a soak — rule 12 caught a real case here:
`w41e.log`/`w41f.log` were soaks of a **stale exe** after two of my patches aborted on their own
assertions, so **no conclusion may be drawn from those two logs**. Kill after: `taskkill /F /IM mcla.exe`.

**Landed this session, each measured as a one-variable A/B (ledger F-077…F-081):**
- **T41.3d** deleted the `rage_im` stand-in for `star_glow` (`src/gpu_device.cpp`, marker
  `AFB76-MISS-HONEST`); **T41.3g** gates the `*.list` bodies in `HostServeUiBody` (`:473-485`, marker
  `HOSTSERVE-BLOCKED`); **F-080** deleted the bit-30 `XSF-OPEN-GATE` write. All three are
  behaviour-neutral (`PRESENT` 73, `GFx` 9, `CP-DRAW`, `C0000005` 1 unchanged) and each removed a false
  signal.
- **F-078** `GLOBTEX` 98 → 2 with the serve blocked ⇒ that counter was **our own buffer walk**, never a
  guest event. **F-079/F-080** the guest never sets bit 30 and `Open` returns 0 regardless ⇒ the `*.list`
  problem is the **body read**, not the open (T41.3i).
- **F-081 / T40.6 step 3 (the big one):** the CP now has a 13-bit Xenos register file; Type-0 payload
  dwords are stored instead of discarded; `0x21 REG_RMW` and `0x2B IM_LOAD_IMMEDIATE` are implemented
  (xenia `command_processor.cc:927-948`, `:1135-1161`). `CP-REG-T0` 0 → **1,171**, `CP-IM-LOAD` 0 → 8
  (first shader uploads ever seen: vertex 24 dwords, pixel 9), **`CP-DRAW` 24 → 52** because REG_RMW
  consumes 4 dwords and the old `count + 1` desynced the stream. **F-059's "24 draws" is void: ≥52.**
  Baseline chain `w41a → w41b(T41.3g) → w41c(layout) → w41d(gate deleted) → w41g/w41h(register file)`;
  `w38w.log` is **not** comparable (different tree).

**What remains for "a working game end to end"** — none of it is done: `DRAW_INDEXED` is **0**, there are
no authored pixels, no menu, no input, no audio. In priority order:
1. **T40.6 step 4 — render from the register file.** Replace the starved host-side enqueue
   (`src/gpu_device.cpp:1793-1803`, hung off `sub_82420BA8`, which only ever sees dummy `li r5=0`
   submits) with one driven by `CP-DRAW`/`CP-DRAW-STATE`. The `r08B/r0DD/...` names in the current log
   line are a *probe list chosen to be observable*, **not** spec register names — take indices from
   `xenos.h`/`registers.h` (upstream, or re-fetch: E:'s `.research/xenia` is unreadable).
2. **Re-apply the peer's F-063 `D3070` clause removal**, which exists only as this doc's prose — the code
   was destroyed on E: (`tools/soak_census.py` reports `MARKER NOT IN SRC` for `D3070-RUN`, `MSGBISECT`,
   `MSGCHAIN`, `GATE-STACK`). It is the likely reason `C0000005` is 1 on this tree instead of 0, so do it
   **before** chasing the `0x82304348` AV as new work.
3. **T41.3i** — census the read path on an already-open `*.list` handle (offset/size/bytes-returned/source
   branch) to settle compressed-vs-opaque, then decide whether UI textures are a decompression task or a
   key task.

**Housekeeping for the user (needs admin, not an agent):** `chkdsk E:` / identify what E: actually is
(WinError 433 = dropped provider, yet `fsutil` says "Fixed Drive"); regenerate the git index once the
volume is healthy — `git index-pack .git/objects/pack/pack-ca27fa73….pack` then `git read-tree HEAD`; and
note `origin/master` is **`b6528ada`**, which is *not* this tree's `4280c9d`, so do not `git pull` before
checking which history is whose. Nothing here has been committed (commits only on request), so the
durable record is `C:\mcla-pc\docs` + the mirror in `C:\mcla-emergency-20260921-0112` (both patched
sources, `w41a…h.log`, the HEAD blobs and the two verified patches).
### B1 static pass (rule 14) — same session, minutes later
Static walk ABOVE the pager finished what w50 started: pager-caller sub_821C91C0 registers the window request into the global pending list ([0x828606E8/06EC] lock-protected, counter++), bctls the pager at 821C9260, and returns 0 — **zero post-read work in the caller**. 821C92A0+ = completion-list splice (unlink r11=[r8+0x848], state words 48/47 at +2112 — slot-state flip territory, our SLOT-READY lives at exactly this data). So the member-page consumer is reached by DATA (slot bookkeeping), not by any call edge: static analysis is exhausted, the DR0-3 watchpoint on C6157B80/C6167C00 (stable across w47-w50) is now the only clean discriminator. Implementation next attempt: arm via SuspendThread/SetThreadContext on boot-worker (boot_host.cpp:1320 handle) + each guest thread (kernel/guest_thread.cpp create site), Dr0=base+C6157B80 Dr1=base+C6167C00 Dr7 RW=10 LEN=3(8B), log EXCEPTION_SINGLE_STEP in the existing VEH with thread id + current guest lr (thread_local g_ppcContext), re-arm Dr7 from context on every hit (Windows clears on context switch), cap 32 lines. Frontier must stay w50-identical (watchpoint is read-only; if it adds faults, revert per goal criterion).
