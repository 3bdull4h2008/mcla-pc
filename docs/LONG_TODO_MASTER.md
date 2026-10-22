# LONG TODO MASTER — MCLA PC → Playable Game

> **Authoritative ordered backlog. Rewritten+compressed 2026-09-20 (post-W36h).**
> Token-saving reading order: **this file** → `HANDOFF_NEXT_AGENT.md` live block →
> `PROGRAM_GUIDE.md` on demand. All long-form trail was compressed on 2026-09-20:
> `HANDOFF_NEXT_AGENT.md` now carries a session ledger, `EXECUTION_PHASES.md` phase
> ledgers, `ROOT_CAUSE_VALIDATION.md` the F-001…F-063 ledger (append-only — grep it, the range drifts
> every session). Anything
> deeper lives in git (`git show 8f07a39:docs/<file>`) — grep there, never full-load.
> Every claim below cites a commit or log; commit-only claims are marked UNVERIFIED.
> Older status blocks elsewhere = trail, not truth.

> **STATE (2026-09-27 05:5x, ledger through F-472) — the F-186/F-187 enqueue gap is RE-FRAMED, and the old wording is now known false.** All four UI containers ARE enqueued, each with a record holding its own full length and package offset (`F469-RECSNAP`, `w475`). A streamer handle is `(gen<<15)|record_index`, and `sub_821BC140` masks the generation off and stores the bare index back over the job's own handle at `0x821BC17C` before reading `record+4/+8/+16/+24` — it never reads `record+0`, so writing record *values* is unfalsifiable to the guest (F-468's livelock explained). Each record is re-stamped by the next push 22-30 ms later while per-job execution is 21-1,662 ms with `pre=0 ms` of host work on the four UI jobs (F-472), so **the pacing is the title's**; §2's task #15 is therefore about record **pool lifetime**, and its one-soak gate is *a second package reaching `still_present == claimed == goldsize`*. `XSF-INFLATE` 0, `F438-GFXCTOR` 0 → goal OPEN.
>
> **PLAN (consolidated, verified 2026-09-27 02:0x; ledger through F-442) — the objective's four clauses, each with its citation and its real status.** Read-first artifact: this is the whole plan in one place; the evidence lives in `docs/ROOT_CAUSE_VALIDATION.md` F-432..F-442.
> **(1) "get UI .xsf containers decompressed" — DELIVERED to its measured ceiling.** Path A decodes 3 of 4 byte-exact into guest memory and the garage at 94–100 % durable across soaks (`w430` 95 %, `w432` 94 %, `w434` 94 %, `w441` 95 %): `kPathBHostFullDecode` + `src/gpu_device.cpp:9411-9519` (plan/fill) with `UIXSF-GOLDEN-REVERIFY` as the comparator. The remaining 14 % of garage.xsf is **destination-bound**: the title's own chain totals 917,504 B for a 1,066,057 B body (F-431), and exceeding it requires host-allocated destinations, which are user-rejected, or the descriptor route (task #15), whose only lever `[record+1540]` is never raised by any function in the image (F-432 census: the +1540 stores are `sub_821BC598` writing 0 and `sub_821FB748`, a different 16×96-byte struct).
> **(2) "so GFx can initialize" — NOT achieved, and now shown not to be downstream of (1).** Measured chain, all with controls: GFx loader ctor `sub_824C6F08` never called (F-438: 0 rows in `w435`, 1 row in the `w436` control); it and its wrapper `sub_82482F78` are reachable only as `{fnptr, msgid}` entries at `0x82117820` (→`0x40001905`) and `0x82115F60` (→`0x40001405`) (F-439); that registry is **never read** (F-440: read-watch `src/gpu_cp.cpp:2180-2198`, 0 rows while the same accessor emitted 8 attributed rows elsewhere); the title's boot-worker queue is **only ever memset** (F-441: store-watch `src/gpu_cp.cpp:2169-2188`, 45 rows all zero, all `lr=8241356C` = the return after `bl 0x823d9890(obj,0,size)`); and forcing the far end of the chain produces an object with `movie=NULL` and no GFx (F-436, gate ON in `w433`, flag reverted to `false` at `src/gpu_device.cpp:2130`).
> **(3) The nearest named cause, and the one staged experiment.** `sub_823971D0:0x823973B4` passes `lhz r4,4(0x828CD0A8)` = 0 to `sub_82397060` because the walk that raises it is gated on `sub_821CFF40(&it,"Vehicle",0)` missing (F-432 §3; string VA `0x82051E90`, one xref in the image). The tuning archive itself is present and served correctly (F-442 §1: `XSF-HOSTSERVE ... head=63D46C60` equals the real bytes at `xarchive_cache.rpf+0x48000`), but no member named `.rpf` carries an `RPF3` header (F-442 §2). So the open question is binary: **content gap vs ordering/parse gap**, and the discriminator is already compiled at `src/gpu_device.cpp:17520-17546` (`F442-SECTION`, prints `name`/`ret`/running `hits`). Verdict rule: non-zero returns for other names while "Vehicle" misses → content; `hits` stays 0 → ordering. **Run it as soon as no peer soak is younger than ~2 min** (blocked 02:0x by a concurrent session; nothing committed since `795299a`).
> **PLAN UPDATE 06:2x (ledger through F-475; next ID F-476) — THE ENQUEUE GAP RE-FRAMED: THE ENQUEUE IS NOT MISSING.** F-469's read-only snapshot proved all four UI containers are pushed with a record carrying their own full length and package offset, so every "construct the missing record" framing since F-186 is void (F-464/F-465/F-467/F-468 were three self-corrections and one regression). A streamer handle is `(gen<<15)|record_index`; the enqueuer `sub_821BCB10` validates the generation at push only (F-473) and the dispatch routine `sub_821BC140` masks it away over the job's own handle and never reads `record+0` (F-470), so record *values* cannot be fixed by us (F-468's livelock explained). `sub_821BD220` releases a record by zeroing `+4`, linking it back through `+12` and adding 0x8000 to `+0` — the generation F-469 saw bumped outside the push path (F-474). `record+12` is a refcount decremented by the dispatch routine's own success tail, the same tail that fires the completion callback — and `RELSEMA … lr=821BC538` fires **once per boot, for 1 of 7 jobs** (F-475). F-474 also refuted my own candidate cause: disarming the session-72 `TASKJOIN-SC` busy-clears costs the boot 2 of 7 jobs and 6 `GFx` lines and changes no record lifetime, so the mitigation stays. **Ordered next actions: (1) T42.18 (#77) = name the site that writes `record+12 = 1` — no mapped writer exists, and until it does the ordering fix is a guess, not a plan; (2) only then re-test the disarmed join-clear with that knowledge; (3) gate on `RELSEMA … lr=821BC538` count and a SECOND package at `still_present == claimed == goldsize`.** Do not re-run: record-value writes (F-468/F-470), join-clear disarm as a fix (F-474), CC6F0 serve branch (F-461), host plant (F-463), gate bit (F-454), serve filter (F-446). `XSF-INFLATE` 0 and `F438-GFXCTOR` 0 → objective OPEN; rule-2/`F-055` remains the user's.

> **PLAN UPDATE 02:4x (ledger through F-446).** Step 1 ran and answered: the section enumeration is queried empty-compressed-or-wrong for **five** different names (`F443`), F-444 corrected "empty" to "never the needed text at the needed moment", and F-446 closed the serve-side candidate by measurement (widening `PathLooksLikeArchiveContent` to `.lst`/`tune/` made `tune/vehicle` appear 142x instead of 1x and changed nothing else — reverted, with the result recorded in the comment). **Consequence: the guest's config text never travels through our host-serve path, so no serve/filter change can reach clause (b).** The only unobserved hop left is inside the guest: `sub_821BE4F0` (the tokenizer's refill, called when `pos >= len` on `[inner]` = `0x82860C40`/`0x82860C68`) after `BDF20 #600 path='a:/archive/tune/vehicle/vehicle0008.lst'`. Next action: instrument that refill (bytes obtained, handle used) — not the filters. Note for anyone picking this up: a *concurrent session* has an uncommitted change in `src/gpu_cp.cpp` citing F-443 (a two-level `PAGEWATCH W` budget); do not commit or renumber it.

A THIRD HOST-SIDE ROUTE IS CLOSED BY MEASUREMENT AND THE CAUSE IS NOW THE SHARED RECORD (F-457, `w460`): at the tune-open millisecond the place pass (`lr=821D5EBC`) inflates `st=006D8F20` with `*srcSz(in)=20` at a src inside meshtextures' `pkg=000A0000 walk=0x10000` bounce tail and produces 0, and `F434-SPIN-BREAK` closes it; `F457-MEMBLK`'s 81 block heads contain no RSC5/XMem container and no tune path, so Path A cannot decode config text. Task #15 now carries the tune-specific acceptance test (decompress at the tune open must name the tune package with `srcSz(in)>=member size`).

> **PLAN UPDATE 04:0x (ledger through F-456; next ID F-457) — TASK #66 CLOSED WITH NO BUILD (F-455) AND THE FIRST HOST-SIDE MECHANISM SINCE F-383 IS NAMED (F-456).** `LISTLINE` needed no new tag: its own `lr=`/`r3=` plus the five `BOOTPATH` windows show `sub_82187820` called exactly 5 times for the shader groups ui/city/cars/characters/effects (16/64/62/22/17 lines = 166), so F-109's "four of five lists never get read" is obsolete and F-451's tune inference was vacuous. F-455 also moved the attribution: all 14 `F442-SECTION` rows run on `inner=0x82860C40`. F-456's probe (`F456-STREAMID`, kept, registered §9) refuted its own `h=0` lead — all 14 rows read `dev=C64AC100 handle=0`, including four whose buffer holds correct text — and found instead that the host's slot serve treats that object as `h=1` (`BE250-SLOT #1800 served=2012`) and fills it with a full 4 KiB compressed window at the `Vehicle` lookups. **Ordered next actions:** (1) **T42.3** = name the file the slot serve resolves for `0x82860C40` at those rows (mis-bound serve = fixable in `BE250`/`BE710`; correct path + compressed bytes = F-403's undecodable-member wall, and clause (b)'s host route closes for good); (2) task #15's descriptor shape still parked behind it; (3) `F-055` remains the user's decision. Do not re-run: gate bit (F-454), serve filter (F-446), `LISTLINE` tagging (F-455), the `h=0` hypothesis (F-456). Census `w457` vs `w455`: every structural marker flat (`LISTLINE` 171, `C0000005` 0, `BC140-REC` 7, `REVERIFY` 21, `LZX-FRAME` 32); `Fatal error` 1→2 is the ±1 spread (2 in `w452`, 1 in `w455`), not a delta.

> **PLAN UPDATE 03:2x (ledger through F-454; next ID F-455) — THE LAST HOST-SIDE LEVER FOR CLAUSE (b) IS NOW MEASURED OUT; #66 IS THE ONLY CHEAP LIVE PROBE.** F-447…F-451 then F-452/F-454 finished the config-tune chain: the tokenizer's refill was instrumented (F-447, −1s on `0x82860C40`/`0x82860C68`), its fields named by the code that uses them (F-449: `[+8]` base, `[+24]` pos, `[+28]` end — `0x82860C68` is at `3170/3170`, i.e. *exhausted*), the buffer it actually held was dumped (F-450: a shaders `.list`, then 3,125 B of XMem-compressed bytes), and `LISTLINE` proved the loader's line loop enumerates 171 shader names and **zero** tune names (F-451 — ground F-107/F-109 already mapped). F-452's candidate cause — our own retired guest-visible Open-gate bit30 (`src/gpu_device.cpp:16035`) — was then tested exactly as specified (**F-454**, soak `w455`): the bit really reached guest memory for both tune archive entries (`readback=403F0000` / `40448000`, `w455.log:116853`,`:117684`, against `w452.log:122150`,`:122870`), and **nothing else happened** — tune `MEMBER-EXPAND` 0, `F442-SECTION` still 14 rows all `hits=0`, `F432-GROW-SKIP` 3→3, `LISTLINE` 171, `C0000005` 0, `BC140-REC` 7, `nGfx=0` 6. Criterion 4 (`[0x828CD0AC] > 0`) was **unevaluable, not zero** — that probe prints 0 rows in both soaks, so it is not evidence either way. Experiment reverted (marker absent from `src/` and from the rebuilt 57,435,136-byte exe); `build/w453.log` is quarantined as `w453_STALE-EXE-do-not-cite.log`. Also corrected: F-452's "13 open-gate skips in `w448`" — the literal is 578 (`w448`) / 550 (`w452`) / 548 (`w455`); the tune-shaped subset is 30 / 2 / 0. **Ordered next actions now: (1) T41.99 = task #66** (tag `LISTLINE` with the composed source path — log-only, one soak; acceptance: tune names appear, or the rows prove only `shaders/*` is ever composed, which closes the enumeration route); **(2)** task #15's descriptor shape stays parked behind it (F-339/F-344: per-job `obj`/`st`, and single-container serialisation already measured a 0 frontier delta); **(3)** §4 / the user's `F-055` host-forced boot gate remains the user's decision, not a default. Do **not** re-run: the `.lst`/`tune/` serve filter (F-446), any serve-reach change (F-450), or the guest-visible gate bit (F-454).

> **(4) Ordered next actions.** 1. Soak the staged `F442-SECTION` probe and settle (3). 2a. If content: identify which archive defines a "Vehicle" section and check it against the retail content allow-list (`xarchive_cache.rpf` + audio/music only — `mc4/art` forbidden). 2b. If ordering: the fix is in the init sequence, not in the streamers — start from `sub_82131508`/`sub_82131790` (installer/main boot thread, F-361/F-363) and the queue poster (F-441). 3. Only after GFx objects exist does task #15 (descriptor side of `sub_821BC140`, `ppc_recomp.14.cpp:18805-19170`) become worth re-opening. Kept shipped: `kF406SkipFabricatedServe=true`, `kF432SkipZeroCountGrow=true`, `kF434BreakNoProgressSpin=true`; reverted: `kF368HostDispatchGate=false` (user-owned), `kF427JobHeadAnchor=false`, `kF393NoHijackNonUi=false`.

> **§0 state, 2026-09-27 01:4x (see below) — **F-438/F-439 (2026-09-27 01:4x, ledger through F-439, next ID F-440) — GFx measured with a fired control, and the conclusion immediately bounded.** The guest never calls the loader ctor (`F438-GFXCTOR` 0 rows in `w435`, 1 row in `w436` with the host forcing it — control fired), but the ctor and its wrapper are **table-dispatched** (`0x82117820` ctor→tag `0x40001905`; `0x82115F60` wrapper→`0x40001405`), those tables lie beyond the registry F-358/F-313 cleared, and no marker prints tags. Head task is now **T41.92 (#59): instrument the handle→handler dispatcher and print the requested tag.** Nothing about the containers changed: garage still 917,504/872,032 (95 %, varies 94–100 % across soaks of one binary), 3 of 4 byte-exact, and the last 14 % needs host-allocated destinations, which is user-rejected.

> **§0 state, 2026-09-27 01:3x (ledger through F-437; next ID F-438) — TWO MORE MEASURED NEGATIVES AND A WITHDRAWN METRIC.** (1) **F-436**: the user-authorised conditional test of the host-forced boot gate ran end to end (`GATE-WAIT [8287E26C]=CF58BC80 after 260 ms` → `GFX-ALLOC loader=CF622D00` → `BOOT-GATE-ENTER 82131008` → `W35-BOOT-GATE #1`), is regression-free (`C0000005` 0, `LISTLINE` 171, `BC140-REC` 7 unchanged; the guest's `Fatal error dispatcher invoked` even went 1→0) and still produced no GFx — `GFX-CTOR-VT-MISMATCH got 8206DFAC/8206DFAC want 820736DC/820736B0`. Args were faithful (the ctor's only caller passes r3 through and uses r4 only after). Flag left `false`; tree rebuilt; decision returned. (2) **F-437 supersedes F-435**: that mismatch is *correct guest behaviour*, because `sub_824C6F08` writes `0x820736DC` and then calls `sub_82482008`, which unconditionally overwrites `[obj+0]` with `0x8206DFAC` before returning — and the scan's four bands miss where loader objects are allocated (`CF622D00`). **So `nGfx` has never counted GFx objects: read `nGfx=0` as "not counted", never "does not exist".** The scan now accepts both families, with the mutating lifecycle drive pinned to the old key behind `W34-LIFE-KEYDEFER` (widening a count must not silently arm a lever). **New head: T41.91 (task #58) = a real GFx counter** (post-ctor vtable key + the host-user-heap band); then the "Vehicle" section-lookup question (F-432 §3) for clause (b). Three commits landed: `69af10b`, `f9d2e7c`, `e27468c`.

> **§0 state, 2026-09-27 00:4x (ledger through F-434; next ID F-435) — TWO GUEST INFINITE LOOPS WERE THE WALL; BOTH ARE NOW ROOT-CAUSED AND MITIGATED, AND THE BOOT ENDS IDLE FOR THE FIRST TIME.**
> (1) **F-432/F-433**: the boot worker's "never returns" and the F-371/F-384 heap-header garbage are the SAME bug — `sub_82397060` is entered with `count=0` and its free-list link loop is guarded on `EQ` only, so it runs 2^32-1 times storing `[r9+12]=r9+16` across all 4 GB (`ppc_recomp.61.cpp:17888-17923`). Its single caller is `sub_823971D0:0x823973B4`, passing `lhz r4,4(0x828CD0A8)`, and that halfword is only raised 16-at-a-time by `sub_82396DF8` inside a walk gated on `sub_821CFF40(&it,"Vehicle",0)` (string VA 0x82051E90, exactly one xref in the image) — so clause (b) is now a *named* question, not a hunt. Mitigation `kF432SkipZeroCountGrow` is downstream-equivalent because the caller re-reads the same halfword two instructions later and branches around every use of the container when it is 0.
> (2) **F-434**: with the storm gone, the boot's last live thread burned 23,155,400 iterations of `sub_821BC140`'s place pass on the `st=006D8F20` / `PSTREAM #5` stream (`produced=0`, `inLeft=20`, `consumed` frozen at 32,748) — unreachable by `INFLATE-UNSTUCK` (needs `produced>0`) and by `INFLATE-J2-CONT` (needs a UI dest). `kF434BreakNoProgressSpin` writes the loop's own stream-complete key after 64 frozen sightings.
> **Measured `w430`→`w431`→`w432`:** `C0000005` 4→0→0, `F379-HEAPSTORE-BT` 19→0, `INFLATE-ENTER` 26k→117k→2.4k rows, **`BC140-REC` 5→5→7** (records `8284B990 RLC=17` and `8284BFA4 RLC=2` reach `sub_821BC140` for the first time), `W34-GFX-CENSUS` 3→3→6 rows and the new ones read `vt=82085364 nLiveDest=4 tagNv=2` instead of `CDCDCDCD/0/0`, garage recovered to `claimed=917504 still_present=872032 pct=95`, `LISTLINE` 171 throughout, and the soak tail is ordinary `WAIT[KWFSO] obj@40004D7C to=30ms` polling rather than a loop.
> **What did NOT move: `nGfx` 0 and `GFX-CTOR`/`GFX-BLOCK`/`GFX-ALLOC`/`GATE-WAIT`/`BOOT-GATE started` all 0** — the host-forced boot gate at `src/gpu_device.cpp:2214` never runs, and entering it (and so calling the GFx loader ctor `0x824C6F08`) is the user's `rule-2`/`F-055` boundary, **not** a task to default to. Also do not read `UILOAD`'s grep count as progress: the string lives inside the `W34-NOGFX` message, which is what actually doubled (3→6). Next: T41.89 (task #56).

> **§0 state, 2026-09-26 23:4x (ledger through F-411; next ID F-412) — CLAUSE (a)'s GAP IS OUR OWN PLAN
> RULE, AND THE FIX IS SPECIFIED WITH A PASS GATE.** Same exe, three soaks: the garage's read-list always has
> **52** slots (`PSTREAM` count), but `UIXSF-LAYOUT-AUDIT` shows one *contiguous forward run from a single
> anchor` — `anchor=B7EC1000 slots=6 modelA 1066057/1066057` (`w420` = the entire container),
> `anchor=B7F41000 slots=7 …851968` (`w421`), `anchor=B7F61000 slots=8 …917504` (`w423`). The
> destinations exist; the plan does not wrap to the rest of the list. **T41.85 (task #54)** = fill from the
> whole read-list in list order, gate: `claimed=1066057` in 3/3 soaks, `still_present/claimed>=0.94`,
> `C0000005` 4, `LISTLINE` 171, `BC140-REC` 5, other containers keep `pct=100`; revert if
> `F409-FILL-GUARD` ever prints `CLAIMED_OTHER_UNVERIFIED`. This is host-side policy — it does **not**
> re-open the thirteen closed Path B variants, and it does not touch clause (b).

> **§0 state, 2026-09-26 23:4x (ledger through F-410; next ID F-411) — THE BLOCK ABOVE'S SLOT-ALIASING
> THEORY IS RETRACTED BY THE INSTRUMENT I BUILT TO TEST IT.** `F409-FILL-GUARD` splits the merged
> `PROTECTED(claimed_or_golden)` reason and prints the claimant (`UiDecExpect::pkg/.verified`); `w423` shows
> all five garage refusals as `reason=GOLDEN_ALREADY_PRESENT claimPkg=00000000`. So **no slot is aliased, no
> foreign stream claims one, and nothing correct is withheld** — the `w418` `outPtr` cross-match that
> produced F-408 §1 compared a *different soak* and was simply wrong. What limits clause (a) is the
> **destination chain**: on one binary `claimed` = 1,066,057 / 917,504 / 851,968 while every planned byte is
> golden and 95–97 % of it stays present, and `first_bad` (`0x40005` / `0x30005`) marks the first offset
> with no plan row, not a wrong write. That is F-354's ceiling in clean form → **task #15 (per-stream
> record / longer chain) is the route; there is nothing left to unblock in the fill path.** `BC140-REC` = 5 in
> 6/6 soaks with `kF406SkipFabricatedServe=true` vs 3 in 3/3 without. The `F409-FILL-GUARD` split is kept
> (§9 registered). Clause (b) unchanged (`nGfx=0`, 3 census rows; F-397's zero-count loop; F-405's
> no-host-bypass result).

> **§0 state, 2026-09-26 23:3x (ledger through F-408; next ID F-409) — THE GARAGE'S LAST 14 % IS SLOT
> OWNERSHIP, NOT DECODE, AND F-406'S RECORD GAIN REPRODUCED 5/5.** Three soaks of one exe (`w420`..`w422`):
> `BC140-REC` = 5 in all three (5/5 with `w418`/`w419`; 3/3 without the gate) — F-406 is real.
> `UIXSF-LAYOUT-AUDIT pkg=64980000 … slots=7 modelA 851968/851968 bytes match` → every slot the garage
> holds is byte-exact, so nothing about Path A's decode is wrong. Coverage is **bimodal on the same
> binary**: 1,066,057 claimed / 1,038,617 present (97.4 %) with **0** `UIXSF-GOLDEN-FILL-SKIP` rows, vs
> 851,968 / 806,496 with **8** rows (`reason=PROTECTED(claimed_or_golden)` / `NOT_UNTOUCHED`). The reason
> is now named: the garage's `slot[3]=B7E01000` / `slot[7]=B7E81000` are simultaneously another
> container's serve destination in the same boot, so the F-350 guard refuses to overwrite them — correct
> for a live foreign dest, fatal for our coverage. **T41.83 (task #52)** counts correct vs stale claims in
> one soak and that count sets task #15's shape (disjoint per-stream slots vs an ordering rule). Also
> retracted here: `sub_8260C8E0` is NOT the record builder (1 enter/exit all boot; F-407 §1). Clause (b)
> unchanged (`nGfx=0` in 3 `W34-GFX-CENSUS` rows, F-397's zero-count loop, F-405's no-host-bypass finding).

> **§0 state, 2026-09-26 23:1x (ledger through F-406; next ID F-407) — FIRST KEEPSABLE MOVE ON THE
> ENQUEUE GAP ITSELF: 3 streamer records -> 5, reproduced 2/2 soaks.** `kF406SkipFabricatedServe`
> (`src/gpu_device.cpp:1086`, gate `:11292-11305`) stops writing the guest's inflate record for a dest
> that has **no stream-owned package** — exactly the 4 KiB filler packages `AssignPackageForDest`
> invents — while the containers keep their serves. **This also corrects F-393: its gate used
> `IsUiXsfPkg(AssignPackageForDest(outPtr))`, which is false for the garage's own dest, so `w407` lost all
> 25 serves and garage coverage fell to 143,069. F-393 rejected its own implementation, not the
> hypothesis — read the two entries together.** Result (`w418`, `w419`, same exe): `BC140-REC` 3 → **5**
> (new `slot=8284AD68 RLC=4`, `slot=8284B37C RLC=7`), `INFLATE-HOSTSERVE-PEND` 3 rows = `64980000` +
> `64CA3000` + `6496F000`, garage `still_present` **flat at 917,504**, `C0000005` 4, `LISTLINE` 171,
> `W34-GFX-CENSUS` 3 rows with `nGfx=0`. NOT closed: **the garage still has no record of its own** (the
> two new ones carry pkg `0x000A0000` = legals.xsf) and `INFLATE-ENTER` still reaches ~5.1 M, so the
> filler serve was a lock, not the only lock — T41.81 (task #51) asks what enqueues a package at all.
> Clause (b) is a different thread and is unchanged (F-397's zero-count 4.3-billion-iteration loop in
> `sub_82397060`; F-405 showed the tuning archive cannot be bypassed host-side). Standing: `kF393…=false`,
> `kF368HostDispatchGate=false`, coverage numbers carry soak counts (55–86 % spread on identical code).

> **§0 state, 2026-09-26 22:4x (ledger through F-400; next ID F-401) — CLAUSE (b) IS ROOT-CAUSED, AND IT IS
> NOT A WAIT, NOT OUR HEAP, AND NOT THE UI CHAIN.** The block below is superseded on one point (it says
> "stuck inside the title's XTL allocator"; the allocator is fine — 512+ balanced enter/exit pairs in
> `w415`): the boot worker's non-termination is the title's own free-list initialiser
> `sub_82397060(container 0x828CD064, count)` with `count = lhz [0x828CD0CC] = 0`, whose loop at
> `ppc_recomp.61.cpp:17907-17923` guards only `count-1 == 0` and so runs **4 294 967 295** iterations
> writing `[X+12] = X+16`. That one fact retires F-370's "deterministic garbage", F-384's "the writer
> follows the arena base" and **tasks #41/#43 (the hand-off) — nothing in `src/` publishes guest
> `0x20000`; those stores are the sweep passing through**. The zero is by construction: static constructor
> `sub_827AF370` registers the group via `sub_821C06C8(0x828CD094, 0, 0x82051F14, 0)`, and the four
> sibling descriptors are game-variable group names ("allgrip", "allzone", "allroar", "devonlycars",
> "ctfFlagLimit", "ctfTimeLimit", "forcePowerupsOn", "Auto") read out of `mcla_pe.bin` — so F-398's hope
> that they were the four UI .xsf containers is **refuted: clauses (a) and (b) are independent blockers**.
> Next: T41.76 (read `sub_821C06C8`'s field writes, then find the append-a-variable routine that never
> ran) — static reads, no soak. Standing: `kF393NoHijackNonUi=false`, `kF368HostDispatchGate=false`,
> clause (a) garage 917,504/1,066,057 (`w411`/`w415`) within a 55–86 % boot spread, `nGfx=0`,
> `W35-BOOT-GATE=0`.

> **§0 state, 2026-09-26 22:0x (ledger through F-395; next ID F-396) — CLAUSE (b) IS ROOT-CAUSED, AND IT
> IS NOT A WAIT.** The 21:3x block below is still valid for clause (a) and for F-393; what it called
> "the boot worker parks spinning in the guest-memory access helpers, `nf=0x82131508`" is now resolved
> further: `PARK-UNWIND` (`src/boot_host.cpp:1536-1580`, module RVAs, no names — F-394) narrowed it to
> guest `sub_82397060`, and one enter/exit hook on that function (F-395,
> `src/gpu_device.cpp:17222-17247`) settled the question in a single soak: **1 enter, 0 exits in 120 s,
> argument `want=0`, stuck below `bl sub_82130528` at return site `lr=0x82397124`** — inside the title's
> XTL allocator (`sub_821C08F8` → bank `0x82830CD8` → method `sub_821C29A0`), walking a ~192 KB bank
> whose head words `A0401010/A0401000/A042FFC0` are carved out of **our own** physical arena
> (`kPhysArenaBeginVa = 0xA0400000`). While stuck it re-links `0xA0106000..0xA01067F0` in place
> (`[p]=p+4`, stride 0x10, ~3 passes of 128 slots; `PARAM-STORE`'s 400 rows are its print cap, not a
> total). A 300 s soak (`w412`) is marker-identical to the 120 s one (`still_present` 917,504 both,
> `REVERIFY` 21, `LISTLINE` 171, `C0000005` 4, `nGfx=0`) — **blocked, not slow; do not buy clause-(b)
> evidence with longer timeouts again.** `kF393NoHijackNonUi` stays `false` (measured and rejected).
> T41.73 (task #48) is the next move and it is one soak: cycle vs bound, inside `sub_821C29A0`.

> **§0 state, 2026-09-26 21:3x (ledger through F-393; next ID F-394) — THE 6.7-MILLION-ITERATION SPIN
> IS EXPLAINED, AND IT IS THE TITLE'S OWN LOOP, NOT A RE-SERVE.** F-392's premise was read off a
> counter as if it were a quantity: `INFLATE-HOSTSERVE-PEND` fires **25** times in `w406`, one window
> per destination, 22 of them 4 KiB filler packages (`off=0x1284000..0x1295000`, `pkgSz=00001000`)
> that `AssignPackageForDest` invented for readlist slots of 0x20000/0x4000. The real cost is
> `sub_821BC140`'s descriptor loop, now fully read (`ppc_recomp.14.cpp:19042-19170`): its only two
> exits are `inLeft == 0` (send the stream to its own async read at `loc_821BC2F0`/`310`, credits
> `0x827D74E0` = 1 so never blocking) and `outLeft == 0`, and `sub_82130000` between the inflate step
> and the test **is a bare `blr`** — so with `ret=S_OK, produced=0` the title hangs unconditionally.
> Output descriptors are **12** bytes at `record+8+i*12` with the count at `record+1540` (task #15's
> "28-byte" wording is the join table at `gpu_device.cpp:11650`; F-376's 1,556-byte slots are a third
> thing — all three coexist). `kF393NoHijackNonUi` tested "stop serving, let the title read": it
> broke the spin (serial 6,747,400 → 231,518, `READWRAP` → 463,018) and cost the garage
> 917,504 → 143,069 bytes, because the decision point (`inLeft == 0`) belongs to the one shared
> record `st=006D8F20`. **REJECTED, reverted, and `w408` re-verified the structural set flat**
> (`C0000005` 4=4, `fatal` 60=60, `LISTLINE` 171=171, `UIXSF-GOLDEN-REVERIFY` 21=21). Two things the
> next session must hold: (1) `w408` is the same code as `w406` and its garage coverage is **589,824**
> — so "86.1 %" was one observation, and the honest range is 55–86 %; quote soaks, not numbers.
> (2) clause (b) is unmoved — `w406` has one `W34-GFX-CENSUS` row with `nGfx=0 vt=CDCDCDCD
> nLiveDest=0`, `w408` has none at all, and `W35-BOOT-GATE` is 0 in both — and the boot worker in
> *both* soaks parks spinning in the guest-memory access helpers: `tools/host_rva_resolve.py
> build/mcla.map 0x1b48b1 0x1b4d11` (`w406`) and `0x1b46a0 0x1b46ce` (`w408`) resolve every parked rip
> to `GuestMemoryView::ReadU32BE`/`WriteU32BE`/`IsValidRange`, and the `nf=0x82131508` printed on
> those lines is a **nearest-name artifact 94 KB past the function it names** — do not read it as the
> park site.
> Next: task #15's only surviving form, a per-stream record.

> **§0 state, 2026-09-26 19:0x (ledger through F-383; next ID F-384) — THE HOST-HEAP DESTROYER WAS
> OUR OWN PATH A DRIVER, AND THE FIX IS IN THE TREE.** `MclaXcDecodeFullStream` soft-resets the guest
> xmem state `[ctx+20+12264..12304]` before every window, and two of those words are **base pointers**
> (`[12264]` src, `[12276]` dst — the guest only ever rewrites the offsets 12268/12272/12280), so with
> them zeroed every produced copy went to `0 + offset`: Path A's output never reached its destination
> buffer, and the advancing offset walked over the host `o1heap` instance at guest `0x20000`.
> Named by a **host backtrace** (`F379-HEAPSTORE-BT` → `MclaJob2DecompressAndDistribute` →
> `MclaXcDecodeFullStream` → guest `sub_8244FF20/82460420/82461010` → `sub_823DA950`), proven with the
> args by hooking the guest memcpy (`F382-MEMCPY dst=00000000 len=1612`, then `dst=00001612`).
> `MclaXcSoftResetStream` (`src/gpu_device.cpp:5464-5479`) preserves the bases; vs `w393`:
> `F370-HEAP-HDR` 1→0, `F370-THREAD-CTX-NULL` 1→0, `INFLATE-ENTER` 6,016→3,615, structural set flat
> (`LISTLINE` 171=171, `GETDEV` 698=698). **Retired by this: F-375's "vtable dispatch through
> `[job+8]`" mechanism and F-377's "relocation cannot fix this"** (both measured through a 16-row hard
> cap that hid every second writer, and with the wrong context's registers printed).
> **Residual, and it is the new blocker: the TITLE'S OWN HEAP IS AT GUEST `0x20000`** —
> `sub_82397060` fills a 16-byte-block free list there (`val=addr+4`, `r5=0x10`) on the path
> `_xstart → sub_82131508 → sub_822C2EA8 → sub_822C54D8 → sub_822D4878 → sub_823971D0`, and the host
> faults in `o1heapAllocate+0x98` (`rva=0x206CC8`), so the VEH parks a live thread. **T41.66: move the
> host user-heap arena off the guest heap, and widen `F370-HEAP-HDR` first — it compares only
> `diagnostics.capacity` (constant after `o1heapInit`), so a destroyed `bins[64]` reads as healthy.**
> Goal markers still `nGfx`=0 in every row and `W35-BOOT-GATE`=0 → **objective NOT achieved**; the two
> open halves (garage coverage, GFx init) are now downstream of one measured cause.
>
> **Corrected 30 min later by F-384 (builds 3, soaks `w395`/`w396`):** the "title's own heap is at
> 0x20000" reading above is REFUTED. The arena was moved to `0x20000000` with the positive controls
> firing (`base=0x120000000`, `SELFTEST page=120000000`) and the same writer followed the base
> (`guest=20000000 val=0x20000004`, same `sub_82397060` chain, `sp`/`r13` unmoved) — **the title is
> being handed our arena base**, so `T41.67` replaces `T41.66` and the value was reverted (control
> `w396` ≡ `w394` on every structural marker). The single source of truth stays:
> `src/kernel/heap_arena.h`. The other half of that AV is now the sharper lead: `o1heapAllocate+0x98`
> faults a **write** into `0xE49125FC` with `r8 = Translate(RESERVED_END)` (the physical arena base) —
> a guest VA used as host metadata — 14 s *before* any free-list write, and the line before it in both
> boots is `T413N2-XMEM srcSz=543919776`. **F-385 RETRACTS THAT AS A SIZE: `srcSz`/`destSz` in those
> rows are the guest's POINTER arguments (adjacent stack slots), the trap already being documented at
> `src/gpu_device.cpp:3255` (F-231). With both forms printed, `w397` reads `srcSzPtr=006D8EA0
> srcLen=32748 destSzPtr=006D8EA4 destLen=65536` — sane 32 KiB-in / 64 KiB-out requests.** What stands
> is the AV itself: exactly one per boot in `w394`..`w397`, in the **physical** heap, with
> `rcx=0xE49125D4` (a guest VA) dereferenced as host metadata — that is `T41.68` (bracket the physical
> arena the way F-370 bracketed the user one; check pointer validity, not `capacity`, which is
> constant). And the goal metric did **not** move with any of this: `UIXSF-GOLDEN-REVERIFY
> pkg=64980000 still_present=440720 pct=96 first_bad=00020005` is byte-identical in `w393`, `w394` and
> `w397` — the F-383 fix bought allocator health, not coverage. `nGfx`=0, `W35-BOOT-GATE`=0: goal OPEN.

> **§0 state, 2026-09-26 20:5x (ledger through F-391; next ID F-392) — MILESTONE ON CLAUSE (a).**
> The garage UI container is now **917,504 of 1,066,057 bytes present and byte-exact in guest memory**
> (`UIXSF-GOLDEN-REVERIFY pkg=64980000 recs 5→16, recs_whole 4→16, first_bad 0x20005→none`) versus
> 440,720 / 41.3 % before, and `INFLATE-ENTER` 3,615→34,607. Cause was structural and ours: the host
> PHYSICAL heap arena was bound at guest `0xA0000000`, the same range the title's own XTL dual-buddy
> allocator uses (`F389-BANK` measured its region as `0xA0001000..0xA002FFC0`), so the title's slab
> metadata overwrote our o1heap fragment headers — that, not a wild inflate, is the once-per-boot
> `o1heapAllocate+0x98` AV. Fixed by `kPhysArenaBeginVa=0xA0400000` (`src/kernel/heap_arena.h`) plus
> two keepers: the VEH no longer parks allocator faults that `SehO1Allocate`/`SehO1Free` can absorb
> (F-390), and `Heap::Alloc<T>`/`AllocPhysical<T>` return null instead of placement-new'ing into null
> (F-390b). Controls: `F388-PHYSGUARD SELFTEST page=1A0400000` fired (the probe moved with the arena),
> `F390-SEHPASS` 0 and `returned null` 0 in `w406` (the AV is gone, not hidden),
> `LISTLINE`/`GETDEV`/`XSF-HOSTSERVE` identical. **Clause (b) NOT met: `nGfx`=0, `W35-BOOT-GATE`=0.**
> `w406` parks two different threads now (T41.69): a read of `0xFE78C248` at
> `__imp__sub_82419718+0x23f` (`ppc ctx=nil` — name it by host backtrace, not `lr`), and `rva=0x0`
> = a jump to address zero. Also still owed: the guard arm/disarm is one global flag shared by both
> heaps and all threads (F-386), and the *user*-heap half of F-384 (a writer follows our arena base at
> guest `0x20000`) is still unexplained. All of this is **uncommitted**; `kF368HostDispatchGate=false`.

> **§0 state, 2026-09-26 ~17:4x (ledger through F-375; next ID F-376) — the heap corruption is
> ROOT-CAUSED, and it is the guest.** A streamer job record's object field `[job+8]` holds the size
> **0x20000** instead of a pointer; the guest loads a vtable from the host heap header sitting at
> that address, `bctrl`s into a fragment pointer (its own memcpy), and that writes 16+ dwords over
> `0x20000` → `Heap::Alloc` refuses everything from then on (F-370) and guest thread #16 is never
> created. Named by `F374-HEAPGUARD` (guard page + mandatory SELFTEST) and `F374/F375-HEAPSTORE`
> (caller RVA, then guest arguments): `lr=821BC998` → `bl 0x821bc140` (`ppc_recomp.14.cpp:20142`),
> the 1,556-byte record built by `mulli r11,r11,1556 / add r30,r11,r31`. **T41.64: census who
> publishes `[job+8]`** — the same 28-byte-descriptor machinery as task #15, and 0x20000 = 131072 =
> the `room=` figure in every PATHB row. Retracted by F-375: "deterministic garbage" (F-370 §2 /
> F-372 §3) and "checked vs raw views disagree" (F-373) — both read `bins[]` as though it were the
> diagnostics block (`src/kernel/o1heap.c:133-138`). Frontier markers unchanged (`W35-BOOT-GATE` 0,
> `nGfx` 0, `[obj+92]` wrong), and F-371 already showed a forced dispatch does not produce GFx.
> **(a) 3/4 byte-exact + garage 12.3 %/41.3 %. Goal NOT complete.**

> **§0 state, 2026-09-26 ~17:0x (ledger through F-372; next ID F-373) — F-371 + F-372 close two
> framings.** (i) **The user-approved host dispatch of `sub_82131008` was RUN (`w377`): the gate is
> entered, never returns, and `nGfx` stays 0** — so the gap is not a missing dispatch either; the
> lever is back to `false` and `W35-BOOT-GATE` again means "the guest did it". (ii) **F-370's heap
> corruption survives turning the host chunked fill OFF (`w378`)**, and its "deterministic garbage"
> was per-build only — a new binary corrupts with different bytes, so no byte needle exists.
> Excluded so far: any heap operation, foreign free, checked guest store, host chunked fill, and any
> second explicit owner of guest `0x20000`. Next (T41.63): DR-register data watchpoint over those 40
> bytes — coordinate, DR0/DR1 are B1's (F-094/F-100 rules apply). **(a) 3/4 byte-exact + garage
> 12.3 %/41.3 %. (b) `nGfx`=0, now including the forced-dispatch case. Goal NOT complete.**

> **§0 state, 2026-09-26 ~16:3x (ledger through F-370; next ID F-371) — supersedes F-369 §5/§6:**
> F-369's new `C0000005` was **our own** unchecked `g_userHeap.Alloc(0x40E70)` in
> `src/kernel/guest_thread.cpp:21` (named via `tools/host_rva_resolve.py build/mcla.map` →
> `memset ← GuestThreadContext ctor ← GuestThread::Start`); it is guarded now and
> `C0000005` is back to **0** with the structural set `+0`. The reason that alloc failed is the
> find: the guest user heap's `O1HeapInstance` at guest VA **0x20000** is overwritten with
> deterministic garbage (`w376.log:50327`, `cap=0x96e48487fd98c8e0` vs `want_cap=0x7fe7fdc0`, and
> the same 40 bytes in all three soaks) — after that `Heap::Alloc` refuses everything and the
> guest's **16th** thread is never created (`F370-THREAD-CTX-NULL #1`). Proven NOT to be a heap
> operation (pre/post-alloc + post-free bracket fires only on `pre-alloc`; 0 foreign-free
> rejections) and NOT a guest store through the checked accessors (`WATCH: range armed
> [00020000,00020100)` reported nothing) → a raw `PPC_STORE_U32` or a host overrun across the
> arena start. **T41.63 = name that writer** (DR0/DR1 data watchpoint exists via B1/F-094 but is
> currently owned by the globaltex watch — coordinate, do not steal). F-369 §5's "INFINITE wait on
> exhausted `C501FC00`" is wrong: with a per-handle census budget the waits show 6 `WAIT` + 6
> `RETURNED`(status 0) pairs. Frontier markers unchanged: `W35-BOOT-GATE` 0, `[obj+92]`≠`0x82131008`,
> `nGfx` 0. `kF368HostDispatchGate` still `false` → the approved host-dispatch test is still un-run.
> **(a) 3/4 byte-exact + garage 12.3 %/41.3 %. Goal NOT complete.**

> **§0 state, 2026-09-26 ~15:5x (ledger through F-369; next ID F-370) — the F-368 fix shipped and
> the park is GONE, but F-368's prediction only half held.** `src/gpu_device.cpp:17121-17138` now
> clears `sub_82193AF8`'s `required` argument (byte-verified narrow: `r5` written once
> `ppc_recomp.10.cpp:17741`, read once `:17804`, and that read only gates the fatal at `:17821`).
> In `w373`: `Fatal error` 1→**0**, `FATAL-SOFT` 1→**0**, the boot worker's park moved from
> `sp=8EFFF890 lr=82193BA0`+`NtDelayExecution` to `sp=8EFFF550 lr=82135DF8`+`ZwWaitForAlertByThreadId`
> (a deeper frame whose stack contains the never-before-seen `0x82465194/0x82465674/0x824662A0`), and
> `WAITB8`/`RELSEMA` both reached their `#1000` rows where w371 never passed `#24`/`#40`. **NEW BLOCKER
> (T41.62):** it now waits INFINITE on `C501FC00`, a semaphore created `init=31`
> (`w373.log:197`, `lr=8244ECC8`) — i.e. it consumed every permit and is waiting for job completions
> that never arrive. Producer/consumer question, not an enqueue question. **Still 0:**
> `W35-BOOT-GATE`, `sub_822C2EA8`'s RETURN, `[obj+92]=82131008` — so `0x821315F4` remains unreached.
> **Cost:** one new `C0000005` (`w373.log:52294/52313`, host write through null+`0x20` on a thread with
> `ppc ctx=nil`, 569 ms after the soft-fail) — baseline 0, characterise it, do not wave it off.
> **Note:** `effectFade` is a second `req=1` lookup 20 bytes after `skinningData`
> (`w373.log:49848`); soft-failing only the named one re-parks the same thread one call later.
> `kF368HostDispatchGate` is `false` (`:2047`), so the user-approved host-dispatch experiment is still
> un-run. **(a) 3/4 byte-exact + garage 12.3 %/41.3 %. (b) `nGfx`=0. Goal NOT complete.**

> **§0 state, 2026-09-26 ~15:38 (ledger through F-368; next ID F-369) — supersedes F-367:** The
> registering thread (`tid=000043A4`) is **NOT in a healthy consumer loop**. It completed its
> semaphore waits, progressed to `0x82304B50` (`sub_82379C68` in `ppc_recomp.50.cpp`), called
> `sub_82611298` -> `sub_82193AF8`, and at 15:25:05 hit a **FATAL ERROR**: `SHGRP-VARS #1 group=A003CA30 vt=8200C4C0 arr=A003CA80 nvars=1 req=1 want='skinningData' e0=A003CA90/'' e1=00000000/'' lr=82379D04` (`w371.log:49866`)!
> `sub_82193AF8` called fatal dispatcher `sub_821BD618` at `lr=0x82193BA0` with `r3="Required grmShaderGroupVar '%s' not found."` / `r4="skinningData"`, which enters an infinite `b .` loop (`loc_821BD640`), freezing the thread forever in `PARK-SAMPLE` / `NtDelayExecution` (`w371.log:61561-65076`).
> The non-return of `sub_82131508` is therefore caused by this fatal error inside `sub_82193AF8` aborting the call chain before reaching `0x821315F4`, NOT by an unreachable-by-construction design.
> **(superseded by the block above: the fatal IS removed and the thread does advance — to a new wait.)**

> **§0 state, 2026-09-26 ~15:3x (ledger through F-367; next ID F-368) — closes the
> UILOAD-producer direction for good.** The "non-return" is a healthy **semaphore wait-loop**
> (`SEMA-CREATE #14 h=C61C5800-family C6137A00 init=15 max=32767`; 29 waits from the
> registering thread plus 10 `RELSEMA` and 8 `SIGNAL` on it), so the UI-load registration site
> at `0x821315F4` lies **after** the boot worker's loop entry and is unreachable while the
> title runs — nothing on our side blocks it. The callback that IS installed
> (`obj+92=821FC008`) is a threshold/status routine (`ppc_recomp.22.cpp:9173`), not a loader.
> Both halves of the F-186/F-187 premise are now measured false: no live producer exists in
> this image, and 3/4 containers byte-exact in guest memory already left `nGfx`=0
> (F-299/F-302/F-325). Do not re-open "who posts 0x40003B03" or probe the wait-loop. Two
> routes remain and they are the user's to weigh: (i) the F-055 decision on the seed-free host
> dispatch at `src/gpu_device.cpp:2100` (acceptance `W35-BOOT-GATE` > 0, then `nGfx`), or
> (ii) task #15's streamer re-plumb for the garage's other ~63 %. **(a) 3/4 byte-exact +
> garage 12.3 %/41.3 %. (b) `nGfx`=0. Goal NOT complete.**

> **§0 state, 2026-09-26 ~15:1x (ledger through F-363; next ID F-364) — supersedes the
> enqueue-gap framing of the two blocks below.** The UI-load enqueue gap is **not** a broken
> or missing producer: the registration mechanism is proven to work in our build —
> `F365-COPIER` shows `sub_82305690` writing `obj+92 = 0x821FC008` (before: 0) into
> `[0x8288B9E8]=C61C5800`. What never happens is `sub_82131508`'s *own* registration at
> `0x821315F4`, because the call it makes at `0x82131554` (`sub_822C2EA8`) allocates
> 17,000 B successfully, registers that other callback, and **does not return** — its thread
> stays alive in `PUSH sub_821BC868`. So the whole tail of `sub_82131508` is unreachable
> while the boot runs. **T41.60**: find what that loop waits on to exit (`PUSH` stops at
> `#7`, `q=82849518`) — a queue-completion question, not an enqueue one. Two of my own
> entries were superseded inside the same hour (F-361 "registration never lands" → only for
> the UI-load callback; F-362 "a branch bypasses it" → no branch exists there), for two
> reusable reasons: a memory sample taken *before* the write reads as "never written", and a
> probe window keyed to one caller's lr range hides a shared callee called from another.
> Probes neutral (`w370` vs `w351`: 20 markers `+0`, errors 28=28). **(a) unchanged: 3/4
> byte-exact + garage 12.3 %/41.3 %, ceiling closed both hook-reachable sides. (b) `nGfx`=0.
> Goal NOT complete.**

> **§0 state, 2026-09-26 ~14:2x (ledger through F-361; next ID F-362) — supersedes the
> registration half of the block below.** The UI-load callback's registration **does not
> complete**: `F361-BOOTOBJ` reads `[0x8288B9E8]=C61C5800` with `+88..+104` all zero at four
> late samples from an independent site, while `F360-REGCB #1` proves the registering
> function was entered, and the copier's only skip (byte `obj+4 != 0`) is ruled out (byte is
> 0). So the (b) failure is now **inside `sub_82131508`, before guest `0x821315F4`** — one
> function, one instruction. **T41.59 re-scoped**: census the call sequence at
> `ppc_recomp.0.cpp:3613-3633` and name the last callee entered (one build). Neutrality of
> all four new censuses proven: `w362` vs `w351` = 20 markers `+0`, `[error]` 28=28,
> short-circuit 1,334=1,334. **(a) unchanged: 3/4 byte-exact + garage 12.3 %/41.3 %, ceiling
> closed both hook-reachable sides. (b) `nGfx`=0. Goal NOT complete.**

> **§0 state, 2026-09-26 ~14:0x (ledger through F-360; next ID F-361) — supersedes the
> "0x40003B03 is a table tag / find the table's consumer" frontier of the two blocks below.**
> **The UI-load callback is registered by live guest code.** `sub_82131508+0xec` forms
> `0x82131008` with `lis`+`addi` and hands it to `sub_821C2FD8(&out, fn)`, then
> `sub_82305690(r30, result, 0)` (`ppc_recomp.0.cpp:3616-3633`, caller `sub_82131790`), and
> `F360-REGCB #1 tid=000055A4 lr=82131B5C` proves it executes each boot — while
> `W35-BOOT-GATE` remains 0, so the break sits **between registration and dispatch**. New
> queue item **T41.59** (replaces the closed-as-wrong T41.58): census `sub_821C2FD8` then
> `sub_82305690`, and look for the object in the existing `PUSH sub_821BC868` rows
> (`src/gpu_device.cpp:13395`, already prints `q= tag= cb=` + a 5-deep `chain[]`).
> Acceptance: `W35-BOOT-GATE` > 0, then `nGfx`. Three method rules earned: (1) a
> dword-equality pointer scan cannot see an address built by `lis`+`addi`, so "nothing
> references X" requires the arithmetic instrument — F-359's headline was wrong for exactly
> this reason; (2) my first branch decoder was broken (18-bit LI mask, missing `<<2`) — the
> corrected one matches 270,559 branches and validates twice, and `tools/ppc_xrefs.py` was
> right all along (its only gap, `lis`+`ori`, is now handled; no prior conclusion voided by
> it); (3) **an entry-only hook census cannot prove a function failed to return**, because
> this code family leaves via `JUMPOUT` tail jumps that skip post-call code — the missing
> `F360-REGCB-POST` is not a hang, and the same tid is visible 2.5 s later in `PUSH`. Also
> checked and dismissed as a blocker: `VdInitializeEngines: GPU context pointer not set at
> 0x82839254` is count 1 in `w351`/`w358`/`w359`/`w360`. All three new hooks neutral against
> `w351` (13 named markers `+0`, `[error]` 28). **(a) unchanged: 3/4 byte-exact + garage
> 12.3 %/41.3 %, ceiling closed from both hook-reachable sides (F-356/F-357). (b) `nGfx`=0.
> Goal NOT complete.**

> **§0 state, 2026-09-26 ~13:3x (ledger through F-358; next ID F-359) — the deliverable-(b)
> blocker is LOCATED, and two standing beliefs about it are false.** (1) **`0x40003B03` is not
> a message to be posted**: exactly one dword in the image equals `0x82131008`, at
> **`0x82102AC0`**, and its pair field is that constant — it is a `{handler-code-VA,
> 0x4000xxxx-tag}` record in a stride-8 table (contiguous `0x821065B0..0x82112160`, 6,005
> records). Tasks #11/#20/#21/#22 were tracing a compile-time field. **New queue item
> T41.58: find the consumer that walks that table** — no branch in the image reaches the
> handler, so the walker is the only route to UILOAD `0x82131008` → `0x822C0980` →
> `0x821FD640` → `0x822012E8`. (2) **The host's forced dispatch of that callback has not been
> running**: it lives behind the TLS-dead branch of `PPC_FUNC(sub_821873E8)`
> (`src/gpu_device.cpp:2100`) and the new census `F358-821873E8-ALIVE` shows **every** hit
> taking the alive exit (`slot12=82830B18`), while `FIX-821873E8` and `W35-BOOT-GATE` read 0
> in five soaks. Re-arming it is mechanical but is the fabrication T38.3f deleted on principle
> (F-055) — **user's decision, do not default to it.** (3) **IDA refuted twice by rule 3 in one
> window** (`0x82135358` is `addi r11,r29,-32` not a `bl` to `sub_82134D08`, which nothing in
> the image targets; its "data xref" at `0x82134df4` is a `cmpw` in a list walk), voiding the
> "boot pump posts UILOAD" narrative; byte-check every IDA claim in `0x8210xxxx`–`0x8213xxxx`.
> (4) `sub_82135150` (title init) **does** run — once, returning 1 (`F358-TITLE-INIT`), so
> downstream silence is a consumer problem, not an init problem. Instruments kept after a
> neutrality census (`w358` vs `w351`: `C0000005` 0, `GFx` 13, `INFLATE` 17,784, `LISTLINE`
> 171, `CP-DRAW` 166 all `+0`). **(a) unchanged: 3/4 byte-exact + garage 12.3 %/41.3 %, ceiling
> not request-side (F-356/F-357). (b) `nGfx`=0. Goal NOT complete.**

> **§0 state, 2026-09-26 ~12:5x (ledger through F-357; next ID F-358) — supersedes the
> "raising the ceiling needs more inflate requests per container" line above.** The
> request-side route is now **measured closed**: repeating `sub_821FDD50` for an
> already-requested container returns `00000000` and creates no record and no destination,
> and with a private out slot per request the attempt is **completely inert** — `w354` vs
> `w351` reproduces `recs=5 recs_whole=4`, both garage chunks (131,072 then 393,216 of
> 1,066,057), `claimed=458752 still_present=440720 pct=96`, 18 `XMEM` rows, and `GFx` 13 /
> `W34-GFX-CENSUS` 6 / `INFLATE` 17,784 / `LISTLINE` 171 / `Fatal error` 1 / `C0000005` 0 all
> at `+0` (F-357). Reverted and re-verified neutral (`w355`). **Trap recorded with it:** the
> first attempt (`w352`) shared the primary call's out slot — FDD50 *stores the destination
> there* — so it erased the handle, minted the project's first
> `PATHB-PKGFIX-SKIP … dest=00000000`, cost a record and a chunk, and turned the boot into a
> 238,672-row re-drive of `B7841000`; every downstream reading of `w352` is void (F-357 §3,
> F-308's class). Combined with F-356 (record marking is not the limiter), **neither side of
> the request the hook layer can reach moves the two-destination ceiling**, so deliverable
> (a)'s remaining path for the garage's other 63 % is task #15's per-request record *inside*
> the streamer walk, or the consumer that would legitimately ask again — `nGfx`=0, which is
> deliverable (b) and the user's `rule-2`/`F-055` boundary. **Goal (a) 3/4 byte-exact +
> garage 12.3 %/41.3 % unchanged, (b) `nGfx`=0 — NOT complete.**

> **§0 state, 2026-09-26 ~14:1x (ledger through F-355; next ID F-356).** UI inflate
> enqueue: **the binding limit is destination supply, now measured.** The guest issues
> exactly **two** inflate destinations per UI container (262,144–393,216 B) and a 300-second
> boot adds no third (`w348`, `w349_long`, `PATHB-HOSTDECODE-CHAIN`). Three of four containers
> fit inside that budget — which is precisely why Path A finished them; the garage's
> 1,066,057 B cannot, so F-350's 41.3 % is the ceiling rather than 59 % of a solved problem.
> **Stricter:** request 2 carries **policecam's** `exp=19337` with `inPtr` on the stack — the
> shared record `0x6D8F20` was re-used and only our map still calls it garage — so
> unambiguous placement is **131,072 B = 12.3 %**. Slot model settled by observation: the ten
> successful frames wrote 327,680 B straight through the `50054000→60000000` block jump,
> so position = next slot in table order (F-327's list model), which still does not license
> F-351's cross-table spill. Raising the ceiling needs more inflate requests per container
> with a per-request record (task #15, now with a measured reason) or GFx loading the movie
> (`nGfx`=0 = the user's `rule-2`/`F-055`); host-allocated destinations are rejected.
> Tooling (F-355): `soak_census --json` replaces the awk field-count filters that hid a
> regression today; `tools/test_ppc_disasm.py` measures our hand decoder at **59.4 %**
> agreement vs capstone with **579** unnameable VMX/op-29 words and a real **operand
> reversal on `ori`/`oris`/`xori`/`xoris`**; headless IDA verified live. **Goal (a) 3/4
> byte-exact + garage 12.3 %/41.3 %, (b) `nGfx`=0 — NOT complete.**

> **§0 state, 2026-09-26 ~11:4x (ledger through F-353; next ID F-354).**
> **F-353 corrects the gate evidence of everything before it today.** My neutrality
> filter `awk 'NF==4 && $4!="+0"'` was self-defeating: `soak_census.py` tags only
> non-zero deltas with `<<`/`>>`, giving those rows 6 fields, so the filter can never
> show a regression. Correctly filtered, `w346` vs `w340` keeps every structural/fault
> marker at `+0` (14 named, incl. `C0000005` 0, `LISTLINE` 171, `GFx` 13) but moves
> `INFLATE` 14,492 -> 17,784 and `PRESENT` 46 -> 51, where same-behaviour controls move
> `INFLATE` by +1 - so F-350's Path A placement is a real behavioural change, not the
> "invisible" thing F-350 §4 claimed. `PUT=`/`rptrWB` turned out to swing +242 on an
> identical binary (`w347`), so that one was timing noise - while `INFLATE 17,784` is
> bit-identical across `w346`/`w347`, proving +3,292 is a real, reproducible effect.
> The deliverable number itself is unaffected (garage **41.3 %** = 440,720/1,066,057,
> from guest-memory readback against the decoded body, not from the filter), and the
> three banked containers still verify `match=true`. New rule in `PROGRAM_GUIDE` §9:
> neutrality claims need the corrected filter + named structural counts + a
> same-behaviour control pair. **Goal (a) 3/4 + garage 41.3 %, (b) `nGfx`=0 - NOT
> complete.**

> **§0 state, 2026-09-26 ~11:3x (ledger through F-352; next ID F-353).** UI inflate
> enqueue: **the garage finally moves — 5.9 % → 41.3 % of its decompressed body is
> resident in guest memory.** The blocker was never the decoder: the single-shot host
> decode refused to place the container unless all 1,066,057 bytes fit one 131,072-byte
> dest, so it fell through to a guest that manages exactly ten frames (F-348/F-349).
> F-350 places the body across the destination chain the guest itself requests
> (`PATHB-HOSTDECODE-CHUNK`, verified by reading guest memory back, not by trusting the
> write) and `w346` reports `claimed=458,752 still_present=440,720 pct=96`. Gate clean:
> `soak_census w346 w340` — **no tracked marker differs at all**; vs `w193` only
> `PRESENT 51 vs 34` moves (forward), while `GFx 13/5` and the single `Fatal` pre-date it
> (`w337`/`w340`); the three banked containers still report `match=true`.
> Two limits found the hard way: **F-351 crossed readlists** to reach a bigger number and
> wrote credits' byte-exact destination `B7801000` on a mapping nothing in this boot can
> observe — withdrawn (a coverage figure needs a falsifier). **F-352's layout audit**
> shows sequential and vbase-delta offsets coincide inside a readlist
> (`winner=TIE`, 458,752/458,752 under both), so placement there is model-independent.
> Remaining 58.7 % needs the guest to keep requesting garage destinations = task #15's
> (record, context) per descriptor in `sub_821BC140`'s walk. Also: headless IDA is now
> genuinely usable — `idalib-mcp.exe -v build/cache/mcla_pe.bin` (NOT default.xex) +
> `tools/ida_rpc.py` (Accept pair + SSE reading; the stdio proxy breaks tools/call).
> **Goal (a) 3/4 + garage 41.3 %, (b) `nGfx`=0 — NOT complete.**

> **§0 state, 2026-09-26 ~10:4x (ledger through F-349; next ID F-350).** UI inflate
> enqueue: **source availability is closed as the garage's cause, and Path B is down to
> one untried shape.** `LZX-FRAME` now prints the decoder's own walk state, and because
> `sub_82461530` sets `srcEnd = src + available + 4` (`ppc_recomp.82.cpp:14906`,
> `:14918-14920`), `srcEnd - srcp - 4` reads directly as **bytes presented to that
> frame**: all ten successes end with the source drained to the last 2 bytes,
> `savedcur` is pinned at `stagbase+0x8000` in every frame, and frame 10 is presented
> **zero** bytes with its cursor already on the staging end (`w338`). F-349 tested the
> obvious remedy by handing one inflate call the whole 1,098,825-byte container - it
> demonstrably landed (`got=1098825 whole=1`) and frame 10 failed **identically**, while
> `INFLATE-ENTER` ran 106,697 times vs 4,901 and the garage reverify never printed;
> reverted and per-marker verified in `w340`. So the three content-side causes are each
> excluded by measurement now - bytes (F-346 `match=1`), recognition (F-347 the preamble
> check fires), supply (F-349) - leaving decoder-internal walk state (F-345's candidate
> (ii)) as the standing conclusion. Task #15: its arming-order shape is now **predicted
> null by F-344** (holding one container at a time moved every frontier number by 0);
> only the per-descriptor (record, context) construction inside `sub_821BC140`'s walk
> remains untried, and that is a new build class. Reading cautions this block adds:
> `LZX-FRAME` line counts are throughput not progress, and `grep whole=1` also matches
> `recs_whole=1`. **Goal (a) 3/4 + garage 5.9 %, (b) `nGfx`=0 - NOT complete.**

> **§0 state, 2026-09-26 ~10:2x (ledger through F-347; next ID F-348).** UI inflate
> enqueue: **Path B's serve content is now excluded, and so is head recognition.**
> New log-only comparator `UIXSF-GUESTCOPY` (`src/gpu_device.cpp:517`) proves every
> served window is byte-identical to the guest's own in-memory copy of the container
> (`w335:2578`, `match=1` on six garage windows, both at `walk=0` and `walk=0x0C`);
> `w335` vs `w334` is every tracked marker `+0`, so the instrument is inert.
> F-347 then positioned the window where the guest's own preamble check looks
> (`pkg+0x0C`, + `st+8=0`) and **provably made that check fire** (`XMEM-SRCHEAD`:
> `src +8`, `srcSz 32768→32760`) — durable coverage unmoved at `63,072` /
> `first_bad=00008000`, so it is reverted and recognition is closed as a cause too.
> The frontier is now binary-invariant and specific: **exactly 10 successful
> `LZX-FRAME` decodes in `w335`/`w336`/`w337`, then type-1 attempts with `bitbuf=0`,
> frozen `fsize`/`cumprod`, 102,275 failures.** Two instrument corrections worth
> re-citing before any argument: `*srcSize(out)` is *bytes consumed* (the caller
> advances `src` by exactly it; `9526+0+9254+13968 = 32748 = consumed`), and the
> `exp=196,553` a UI record prints is a stale inherited value on the shared stack
> record, not that stream's total. Task #15 stands, narrowed to one shape: serialise
> the streamer's arming at `sub_821BC140`'s descriptor walk, where the
> (record, context) pair is born — fourteen hook-layer interventions are now
> measured exclusions, and `rule-2`/`F-055` remain the user's to open.
> **Goal (a) 3/4 + garage 5.9 %, (b) `nGfx`=0 — NOT complete.**

> **§0 state, 2026-09-26 ~07:0x (ledger through F-333; next ID F-334).** UI `.xsf`
> inflate: the plan is `docs/UI_INFLATE_PLAN.md` and it now carries the whole
> mechanism. The decode chain is mapped end to end
> (`sub_821BC140` → `sub_821D5E10` → `sub_8244FF20` → `sub_82460420` →
> `sub_82461010` → `sub_82461530` → `sub_82461B98`, F-331 §2), the guest's frame
> decoder fails ~95 % of frames with a return value its caller discards (F-331 §6,
> F-332 §2 — new markers `XMEM-CTX`, `LZX-FRAME`), and the garage's exact
> no-op-and-can't-advance livelock is identified (F-332 §4). **T41.11 and the
> whole "re-point `st+4`" serve family (F-318/320/327/329/333) are closed by
> mechanism, not by count**: F-333 tested latch-clear + frame-aligned serving, it
> un-stuck the driver and coverage went 63,072 → 43,732, reverted and re-verified
> in `w308`. The one remaining Path B design that respects the continuous bit
> stream is **serve in place** (`UI_INFLATE_PLAN.md` §5 step 1). Deliverable (a)
> is 3/4 containers byte-exact + garage 5.9 %; GFx (b) is unmoved and gated
> upstream of decompression, with rule-2/F-055 reserved to the user. **Updates ~07:4x-08:3x (F-336 -> F-339, next ID F-340): the shared-context cause is now MEASURED** - the codec ctx `0x4000FD80` is opened twice per boot against 4,901 inflate entries (marker `XMEM-OPEN-CENSUS`, with a fired control). The private-context fix was then built three times (F-337 as such, F-338 with a disjoint allocation that refuted F-337's aliasing story, F-339 with a publish/restore pair keyed on `st`) and each form took the job's healthy streams down, because `obj` (`0x8283D1B0`) and `st` (`0x6D8F20`) are both per-JOB records - F-339's zero/zero counts are the direct proof. Eight serve variants are closed with named mechanisms, so Path B's remaining scope is task #15 in its original form (`sub_821BC140`, `ppc_recomp.14.cpp:18805`). Reverted and verified: `w321` = 58,002 lines, `INFLATE-ENTER` 4,901, `still_present=63072`, exe back to 57,206,784 bytes. **Harness note: `build_on_e.bat` writes a 0-byte log even on success, so rc / exe mtime / exe size are the only build signals.** **F-340 (~08:5x, next ID F-341): serialising the shared context is a measured null, and `still_present` turns out to vary across boots for the same binary (121,946 in `w322` vs 63,072 in `w323`) — so a coverage claim now requires a same-binary repeat soak or a structural co-signal, which softens F-333's number-only half. `*obj` is a field of the global streamer object at `0x8283D190 + 0x20`, confirming one context per streamer.** **F-341 (~09:0x, next ID F-342): the interference lead was tested by turning `kUiXsfChunkFeed` off - the garage stays at 63,072 and raceeditor at 143,069/143,069, so the serve is INERT for the deliverable (F-320/F-329's `consumed` gains were bookkeeping) and the default stays ON. Coverage over 12 soaks: 63,072 x11, 121,946 x1. Task #15 is the only route left to durable garage bytes.** **F-342 (~09:2x, next ID F-343): per-package context isolation with the key fixed also fails, and harder - the swap succeeds once and then no frame is decoded at all (`failtotal` 0), because the slot is the streamer's live current-context field. Ten Path B variants closed; task #15 narrows to serialising the streamer's *arming* (smaller) or per-descriptor context pointers (larger).** **F-343 (~09:3x, next ID F-344): clearing the driver's walk state on every entry - the pairing F-333 could not do - reproduces 43,732 with `cumprod` 196,608 vs ~917,504 and `failtotal` 70,483 vs ~5,280, so F-333's revert is reinstated on real co-signals and the rule is: respect the walk state, do not erase it. **F-344 (~09:4x, next ID F-345): holding the context by skipping competing inflate calls is also a null (5 holds, 0 handovers, baseline everywhere), and its first run's apparent `failtotal` 6 was a 40-entry stalled boot - read `LZX-FRAME` beside `INFLATE-ENTER`. Thirteen Path B interventions closed; task #15's two shapes remain.******Update ~07:2x (F-334, next ID F-335):** §5 step 1 (serve-in-place) was refuted before implementation by the new `UIXSF-LOCATE` marker — at the refill the guest's `inPtr` is `st + 0x20` (stack-resident, `inLeft=0`), so the surviving Path B design is **step 1b**: one append-only window per UI stream, `*srcSize` the only moving part, never re-point `st+4`. **Update ~07:4x (F-335, next ID F-336):** step 1b was refuted by its own success (the guest's `st+4` returns to `st + 0x20` on the next call, so no buffer can carry continuity; `w311` regressed and `w312` restored 63,072). The only Path B mechanism left is plan step 1c: reach the guest's own codec-ctx reset (`sub_82460F88` / `sub_82461840`) per stream. **Update ~07:4x (F-336, next ID F-337): the shared-context root cause is measured** — the codec ctx `0x4000FD80` is opened twice in a whole boot (`XMEM-OPEN-CENSUS wrapper=2 caller=2` vs a control on 4,901 calls), so step 1c is now “open a private ~215 KB context per UI stream via the guest's own `sub_82460370(0x8EFFF990, 1, newblock)` and publish `*obj`”, not a reset. **Update ~08:1x (F-337, next ID F-338): step 1c implemented and reverted on our own allocator collision** — `Alloc(0x35000)` returned the serve window's address `0xCAF28300`, so the context aliased its input and the boot went shallower (`w316`); `w317` restored 63,072. The slot to republish is static at `0x8283D1B0` (held `0x4000FD80`); retry needs a non-aliasing allocation first.


## 0-newest2. State (2026-09-26 ~00:05, verified — **F-295→F-297: Path A is ALIVE and SHIPPED; 3 of the 4 UI `.xsf` are now decompressed byte-exact into guest memory**) — supersedes two claims in the 05:08 block below: "Path A DEAD (F-191, XMem LZX≠CAB)" and "the UI `.xsf` are provably NEVER decompressed (F-235)". Also supersedes T41.10's "Path A (host-side LZX): DEAD" line.

**What is true now (all soak-verified, `build/w271.log` 120 s + `build/w272.log` 300 s, both BOOT_RC=124):** the UI `.xsf` payload is **raw MS-LZX at `pkg+0x16`, window_bits=17** — not libmspack's CAB-framed LZX, which is why F-191/F-245 capped at 128 KiB. `src/xmem_lzx.h` (`mcla_lzx::host_decode_ui_xsf`) decodes all four containers **byte-exact with zero guest-VM re-entry**, so it sidesteps the F-288/F-290/F-293 re-entrancy wall that closed every guest-decoder route. Two DIU(`44495500`)-gated paths: *single* continuous stream (raceeditor 143069, policecam 19337, credits 29655) and *walk* — per-frame u16-BE headers over ONE shared decoder instance so the sliding window carries (garage, 33 frames, 1066057 > the 128 KiB window). In-emulator: raceeditor `PATHB-HOSTDECODE #1 … decoded=143069 wrote=143069 dest=B7B01000 ok=true`, policecam `PATHB-HOSTDECODE-TOP #977 dest=B7441000 unc=19337 wrote=19337 ok`, credits `#1002 dest=B74E1000 unc=29655 wrote=29655 ok`. **Garage is deliberately REFUSED** (`…TOP-SKIP unc=1066057 room=262144 → guest`) rather than completed truncated — it stays on the guest's own progressive inflate (new queue item T41.11). Shipped as the default: `kPathBHostFullDecode = true` (`src/gpu_device.cpp:440`), targeting dests through the *dynamic* `g_destPkgOff` map + a package-offset allowlist (`:311-345`), never literal addresses. Regression-guarded at build time by `ninja -C build check_xmem_lzx` (4/4 EXACT). No structural regression: every tracked marker +0 vs `w270`; `C0000005` 0, `DRAW_INDEXED` 0, `SEEK-DEAD` 0, `LISTLINE` 171, `REBASE-POISON` 37 vs `w193`'s 153; the single `Fatal error` is the pre-existing `grmShaderGroupVar` soft fatal.

**What did NOT change — `nGfx` is still 0, and that is now measured on 3-of-4 coverage, not inferred.** `W34-GFX-CENSUS #1..#6 … nGfx=0`, `XSF-INFLATE` 0, `UILOAD-census` 0 in both soaks; boot still ends in the `WAIT[KWFSO] obj@40004D7C … lr=8242FC1C` poll with `RenderThread frame=0`. So full UI decompression is **necessary but not sufficient**: the GFx gate is upstream of UILOAD exactly as the 05:08 block concluded, and it stays behind the user-closed wall (rule-2 recompile of `0x82100000..0x8212FFFF` and F-055 gate-forcing are both off-limits without re-approval). **Milestone the user defined for this objective ("UI `.xsf` decompressed in guest memory") is MET for 3/4; the `nGfx>0` end-state is NOT.** Committed `d7da233` + the F-297 follow-up (`1864589`).

**F-298 (2026-09-26 ~00:2x, existing-log verification, no build) upgrades that milestone from "the host wrote N bytes" to "the guest memory holds the validated content".** The pre-existing `BUF-HEAD` census (`DumpBufHead`, `src/gpu_device.cpp:3986-3994`, called at `:9622`) reads each dest back *after* the host write and matches the offline golden's head words exactly, including the two **per-container-distinct** pointer words (`w[1]`/`w[3]`): raceeditor `@B7B01000 44495500 50036570 00706164 5004B2B4` at `w271:3981` (+126 ms), policecam `@B7441000 … 50013690 … 50015304` at `:14985` (+26 ms), credits `@B74E1000 … 500140F0 … 50024884` at `:15480` (+8 ms); `w272` reproduces all of them. Caveats are stated in the entry: 16 bytes per container, not the whole buffer, and a *host* read at the guest's dispatch point, so residency is proven but guest dereference is not. It also confirms `PLACE-44495500` (`src/task_dispatch_trace.cpp:572`) = 0 and every decoded buffer classified `rgxa=no` → skipped by `D2308-INS-SKIP`, i.e. from the consumer side too, nothing arms these containers — the same `nGfx` verdict. Ledger authoritative through **F-299**; next ID **F-300**.

**F-299 (2026-09-26 ~00:27, funded Path A, BUILT + SOAKED `build/w273.log`) discharges F-298's 16-byte caveat: the milestone now rests on a whole-buffer digest match, not a head-word match.** `UiDecRecordExpect` (`src/gpu_device.cpp:365`) FNV-1a-hashes each decoded body at write time and `UiDecVerifyReadback` (`:4028`) re-reads `unc` bytes from the dest later in the same boot: **3/3 `match=true` at full length** — raceeditor 143,069 B `CF1690FDD7A0AF30` (`w273:3949`, +35 ms), policecam 19,337 B `E7513DE33D27FF22` (`:14772`, +27 ms), credits 29,655 B `22A0999B16E5AAC4` (`:15240`, +9 ms). The probe fires only where the host claims a write — garage's dest is censused at `:13423` 261 ms after being *skipped* and correctly prints nothing — so it carries its own selectivity control, and it measures a **zero frontier delta** vs `w271` (every structural marker +0; only the new marker and the `rptrWB`/`PUT=` poll substrings move). Registered in `PROGRAM_GUIDE` §7+§9; `mitigation_audit.py --label PATHB-HOSTVERIFY` classifies it `[other-shaped]`, i.e. not a short-circuit. Undischarged caveats: host-read ≠ guest-dereference, all verifies inside the first ~1 s, and the dest's slack past `unc` is uncovered. `nGfx` still 0 — the GFx gate stays upstream of the UI `.xsf` (F-297 §5) and closed by user decision.

**Fleet wave F1 (2026-09-26 ~04:0x, `F-300`..`F-303`, four READ-ONLY subagents, no build/no boot) rewrites the map of what is left — read F-300..F-303 before starting any of the tasks below.** Four changes, all main-agent re-verified against file or raw bytes:
1. **T41.11 / task #18 is CLOSED NOT-VIABLE (F-303).** A host multi-window fill of garage cannot work: the guest's own source cursor never leaves frame 0 (`src/gpu_device.cpp:8074-8079` — when `consumed == srcSize` neither branch assigns, so `srcOff` falls back to `ls.pos = 0`), and its 52 readlist slots clobber one another (`w272:4433` vs `:4490`, identical dest and incoming size, both drained to 0). The "128 KiB band" was a `MclaDestCapFromPstream` default (`:7515-7529`), not a measured window.
2. **Task #12's title is a category error (F-301).** `0x82100000..0x8212FFFF` is entirely below `PPC_CODE_BASE = 0x82130000` (`src/ppc_config.h:14`) and is a `{handler, msgid}` **data table** (`0x82102AC0=82131008`, `0x82102AC4=40003B03`, …) — recompiling emits **zero functions**, so rule-2 could never have been the fix. F-270's mechanism is falsified (`0x82119C04` = `0x40017406`, a msgid). "Unmapped" is a name-lookup string (`src/boot_host.cpp:376`), not protection (`:292` commits 4 GiB `PAGE_READWRITE`). Real residue is producer-side only: `sub_8242FD00` has 0 callers.
3. **`nGfx` is the wrong instrument (F-302).** Its 4 scan bands (`gpu_device.cpp:6216-6217`) exclude every live object seen (`C60AC100` falls in the inter-band hole; the three UI dests in none), and its `0x82073xxx` predicate rejects the post-ctor vtable `0x8206DFAC` that our own F-044 documents (`stw r9,0(r3)` at `0x82482028`). **Gate on `MOVIE-CTOR` (`src/task_dispatch_trace.cpp:1526`) instead.** F-044's conclusion survives (`MOVIE-CTOR`=0 independently) — this narrows the metric, it does not reverse the verdict.
4. **NEW P0 LEVER, task #19 (F-300) — the only permitted untested route to the resource graph.** F-297 made the decoder dynamic per directive #5; the **consumer never did**: `constexpr kUiCont = 0xB7B41000` (`gpu_device.cpp:9721`) is what reaches the guest's own ROOT place-pass at `:9849`/`:9861`, and in `w273` that dest is garbage (`:6918 vt=003300D9`) while the decoded containers never appear as `obj=`/`child=` anywhere. Proven on a sibling at `:10390-10395` + `w273:6460` (`44495500` → live `childVt=82085364`). Driving it at the `g_uiDecExpect` dest set (`:365`) is **not rule-2, not F-055, not a stacked serve mitigation** — same guest function, different argument, flag-gated. **Also weakens F-297 §5**: that "necessary but not sufficient" was measured while the consumer pointed at a fourth, garbage dest.

Ledger authoritative through **F-308**; next ID **F-309**. **F-308 then refuted F-307's own metric an hour later, and this is now a closed door, not a lead:** the `[arr]!=0` "resolution" was written by host mitigation `W30-ARR-FIX` (`src/gpu_device.cpp:5408`, `arr=00000000->B7B6D9B4 cnt 0->1`) onto an all-`CDCDCDCD` buffer (`w193:13819`), and in the boots where it resolved **7** times `UILOAD-census`/`MOVIE-CTOR`/`nGfx` were **all 0** — identical to the boots where it resolved 0. **The fabricated descriptor never advanced GFx**, and restoring it is forbidden anyway (`gpu_device.cpp:9737`). **Durable rule (F-308 §3): a counter printed from a hook on a *guest* function can still be reporting *host*-written bytes — grep the field names against `Write*` to the same offset before trusting any counter.** `W30-ARR-FIX` is one of the 64 mitigation labels §7 does not register (F-047), which is why nothing flagged it. **Path B's permitted scope is now exhausted** (F-300 repoint dead / F-305-306 ABI decoded and table correct / F-307-308 array was our own fabrication / Path A delivered), so the only permitted axis left is **task #20**: characterize why `sub_8242FD00` has zero callers — **without crossing rule-2 or F-055**. **Objective NOT achieved**: deliverable "so GFx can initialize" is unmet (`MOVIE-CTOR`=0), garage not host-decoded. Do not mark the goal complete. **F-309 (2026-09-26 ~04:5x, BUILT + SOAKED `build/w274.log`, exe `57,110,528`→`57,114,624` @01:48) then MEASURED the ~20-session-old claim and voided its evidence.** Log-only censuses on guest `sub_8242FD00` (KeInsertQueueDpc-shaped DPC appender) and, as control, on adjacent `sub_8242F870`: **producer 0, control ≥12** at ~60 Hz with `r3=40004D5C` = the boot worker's own DPC queue. The producer had **no host hook at all** before this, so every prior "never runs" was a zero without a printer (F-057(6)). The old inference is dead on its own terms — a raw-byte `bl`/`b` scan gives the **running** place-pass `sub_825EF100` exactly **1** caller and the **provably dead** `sub_822C0980` also **1**; caller count does not discriminate, and `src/kernel/imports.cpp:1734` already said "invoked via indirect dispatch". **⚠ Tasks #11/#12/#20 hunted the wrong msgid:** the `{handler,msgid}` registry at `0x82113A90..0x82113ADC` pairs `8242FD00` with **`0x40002204`**, not `0x40003B03` (that pairs with gate `82131008` at `0x82102AC0`). Next: find who broadcasts `0x40002204` — **`ppc_xrefs.py` cannot** (`:136-148` ignores `ori`; "0 sites" is not a negative), so hand-scan the image or get IDA via `/mcp reload`. Probe neutral: **every structural marker +0 vs `w273`**; new markers registered in §9 so `soak_census.py` tracks them (F-307's lesson applied same-session). Ledger through **F-309**; next ID **F-310**. **F-310 (2026-09-26 ~05:0x, no build) then corrected F-309 §4 within one entry and found a bigger gap in an OLDER finding.** `0x40002204` is a **kernel handle, not a msgid** — `gpu_device.cpp:11194-11198` (F-218) already calls the structure `{handler, kernelHandle}` with worked examples, and Xenon handles (`0x4xxxxxxx`) are shaped exactly like msgids, which is the trap; tasks #11/#12/#20 are re-corrected. The registry is real and large (1,124 consecutive pairs at `0x82112728..0x82114A48`, vs a **0.8 %** image-wide base rate — so not chance) and contains `0x8210DED8`/`0x8210DA98`, whose reached handlers demonstrably executed. **"No recompiled code addresses it" is true (0 literals for pages `0x8211`/`0x8212`, 24 for `0x8210`, search validated at 4,172 control hits) but is NOT a blocker** — the dispatcher likely receives the pointer as an argument. **The actionable gap (task #21): `GFX-TABLE-DISP` and `GFXDISP-CALLER` are 0 in `w193` AND `w274`, never observed once, and F-218 named that same hook its own positive control — circular.** By F-100's rule, **F-217/F-218's "terminal gate for nGfx" is unmeasured, not proven-negative**; fix it with the F-309 method (dispatcher + a proven-live neighbour, one build). **F-310 §5, the rule to keep: three of my own searches returned confident zeros today before a known-present token caught them (`{4}` against an 8-hex field; `\b` before a leading `-` never matching; a "non-null" predicate counting payload) — always validate a search against something you KNOW is there before believing anything it misses.** Ledger through **F-310**; next ID **F-311**. **F-311 (2026-09-26 ~05:1x, ZERO builds — log counts + one raw-byte scan) then answered task #21 and corrected F-310 §4 against my own hypothesis.** F-218's `GFX-TABLE-DISP`=0 **IS** a measured negative: independent **fired** controls on the same mechanism class already exist (`MSGCHAIN`=4 via table entries `0x8210DED8`/`0x8210DA98`; F-309's `DPC-SIBLING-CENSUS`≥12), and a `PPC_FUNC` override is a link-time substitution rather than a per-site registration. **The non-exhaustive dichotomy was F-219's**: all four `GFXDISP-CALLER` hooks print 0 and my scan independently reproduces exactly those four direct sites, **but the dispatcher is itself a table member at `0x82107310`** (ascending handler run `0x821072F0..0x82107330`; paired field `0x40002C05` recurs 51×), so **cold from its direct entry set only — the indirect entry set is unmapped**, and F-219's "needs IDA" branch is the one selected. **Calibration, so nobody re-suggests a tempting shortcut:** every *firing* function here also appears exactly once as a data word with exactly one direct call site (1/1), the same profile as the dead dispatcher — **table membership and caller counts predict nothing.** Highest-value open item on the permitted path: **who walks that table?** No absolute literal for the page exists anywhere in `generated/` (F-310 §3), so the walker must be handed the base as an argument → a CFG question → IDA → still blocked on the user's **`/mcp reload`**. Ledger through **F-311**; next ID **F-312**. **F-312 (2026-09-26 ~05:2x, `generated/` reads + two `ppc_disasm` calls, no build) confirmed F-311 §4's "base handed as an argument" pattern and then eliminated its own candidate the same turn — a recorded negative.** The idiom is at `generated/default/mcla_recomp.23.cpp:40966-40996` (duplicated at `ppc_recomp.73.cpp:3325-3444`): `(obj+88, &entry)` → `sub_823DE6E8` / `sub_823E5B70`, entries `0x8210274C/276C/27EC` — all 24 page-`0x8210` sites resolve to only those three and **none reaches `0x82107310`**. `sub_823DE6E8` is a fixed-address vtable setter (`823DE708/710/714`); `sub_823E5B70` copies a fixed `0x8206xxxx` with size 32 and **does dereference the registry pointer and test bit 28** (`823E5BB0/BB4`) — registry-aware but no variable indexing in its first 20 words. **Neither is the walker**, so #22's cheap branch is spent and F-219's escalation stands: **this needs IDA (`/mcp reload`) or a build+census on `sub_823E5B70`.** Also **F-312 §3: fleet wave F1's claim that `0x823de78c/7b0/7d0` are "dead `lis r0`, overwritten before use" is contradicted** — they are `lis r11,0x82100000` + `addi r4,r11,10092`, live and feeding a call argument. Re-read before citing it. Ledger through **F-312**; next ID **F-313**. **F-313 (2026-09-26 ~05:2x, raw-byte decode, no build) resolved #22 as a MISFRAMED question - there is no table walker to find.** True extents decoded (`blr` = the exact word `0x4E800020`): `sub_823E5B70` 32w, `sub_823DE6E8` 16w, `sub_82457D10` 31w, dispatcher `sub_821EBCF0` 43w - **all zero indexed accesses**. A **self-tested** stride-loop detector (control: it must recover FDBF8's `addi r30,r30,8` before printing anything) found **508** stride-loops in the code range and **ZERO** touching the registry span -> the model is **per-entry registration, not a walk**, so the dispatcher is dead merely because its four direct callers are dead (F-311), with no hidden feeder. **Method trap, re-read before retrying: the first detector keyed on `lwzx`/`stwx` returned zero for everything INCLUDING the two provably-walking functions (`sub_825EF100`, FDBF8), which walk with `add`+`bl` - reporting it would have 'closed' #22 on a test that cannot detect its own target.** Residual: misses computed increments, strides >64B, `bctr` dispatch, forward loops -> IDA closes it. Also recorded: I asserted a false memory mid-turn ("FDBF8 contains `stwx` at `0x825FD448`" - that address is 0x7B0 bytes *before* FDBF8 begins) and the gating control caught it. **Consequence: no permitted untested lever remains against 'so GFx can initialize'** - bring that to the user, do not cross rule-2/F-055, do not mark the goal complete (`MOVIE-CTOR`=0). Tasks #20/#22 closed. Ledger through **F-313**; next ID **F-314**. **F-314 (2026-09-26 ~05:3x, `mcla_pe.bin` pointer census, no build) closed F-313's residual without IDA:** a walker needs a base, and both ways to hold one are empty - no immediate (F-310 §3, control 4,172 hits) and **no stored pointer** anywhere in the image targeting page `0x82107xxx`, the dispatcher's table window `0x821072F0..0x82107340`, the gate table at `0x82102AC0`, or the DPC table holding `8242FD00` - against a **701-hit** control on the wider registry span. **So nothing can walk these tables; `sub_821EBCF0` is dead because its four direct callers are dead, with no feeder.** Consequence: **IDA is no longer the cheap falsifier and `/mcp reload` is not blocking this question.** Method note kept in the ledger: five hand-decoded PPC bit fields failed today, each returning a confident zero, until a gated instrument worked - `bctr`=1059 vs `mtctr`=0 for a word known present at `0x825FDAB8` was the tell. **Use `tools/ppc_disasm.py`, never hand-decode, and assert a known-positive before believing a zero.** Ledger through **F-314**; next ID **F-315**. **F-315 (2026-09-26 ~05:4x, BUILT + SOAKED twice, fix then REVERTED): the frame-0 stall is confirmed in code and the obvious fix is insufficient.** `src/gpu_device.cpp:8065-8148` never writes `ls.pos` back nor calls `MclaRecordLastServe`, while the sibling leg `:8015-8020` does both (F-195 fixed the identical bug there) - that is why every `INFLATE-REFORCE` reads `pos=00000000`. Mirroring it behind the existing `kUiServeAdvance` flag gave `w275` **657,657 lines vs `w274`'s 57,886** with **119,352 identical inflate iterations** at `in=512`, gates clean (`C0000005`=0) and `nGfx` prints 6->4 = **shallower, i.e. livelock not crash**. Root cause of the failure and the requirement for any retry: `srcOff >= srcSize` alone is not enough because the only rescue is `if (srcOff >= srcSize && IsJob2UiDest(outPtr))` at `:8081` - a non-Job2 dest leaves `served=false` and `inLeft` unchanged. **Task #23 carries this.** Reverted; `w276` matches `w274` on every per-marker count (and the 102,134-vs-57,886 line total was correctly NOT treated as a baseline test, per F-072). Ledger through **F-315**; next ID **F-316**. **F-316 (2026-09-26 ~05:5x, disasm + `w276` census, no build) quantified the terminal livelock and WITHDREW F-314's global "no permitted lever remains" claim** (the local one stands). The main thread is not blocked but *polling*: `WAIT obj@40004D7C reason=3 to=30ms` **6,626×**, every wake a timeout. That object is released **exactly once**, `lr=00000000` ⇒ host-origin with no guest return address; `KeSetEvent` never fires; the other 40 `SIGNAL`s are `NtReleaseSemaphore` on different objects. And the boot worker **resets the same object ~60×/s** — decoded loop `0x8242FCB0..0x8242FCF0`: `lwarx/stwcx.` decrement → `addi r3,r26,32` (= `0x40004D7C`) → `bl 0x827BD874` = `__imp__KeResetEvent` (`ppc_func_mapping.cpp:44935`) → the 60 Hz consumer. **`KeInsertQueueDpc` is not among the 246 host `__imp__` thunks (only `KeRaiseIrqlToDpcLevel`), so there is no host stub to write — the wall is a guest-side call into `0x8242FD00` that no recompiled code makes.** **Task #24** = one log-only census testing whether the 60 Hz reset races out a later genuine release; **UNVERIFIED** whether one is intended. Also: commit `91354ea` under-delivered (a python heredoc died on nested quotes so only the ledger was included despite the message) — **check `git show --stat`, never just an rc.** Ledger through **F-316**; next ID **F-317**. **F-317 (2026-09-26 ~05:5x, cap analysis + `w276` counts, no build) closed task #24 by refutation, for free, and finished the characterization of the terminal state.** All **6,626/6,626** waits on `obj@40004D7C` are `reason=3 to=30ms` (zero satisfied wakes); `KeSetEvent` printed **0** times and `KeReleaseSemaphore` **exactly 1** (`lr=00000000` ⇒ host-origin). Those are genuine zeros because both printers are capped `n<=40 || n%2000` (`imports.cpp:2081`, `:3295`) — **that shape prints the first forty, so it hides high counts, never low ones** (F-089 §6 applied usefully for once). **No second release exists, so the ~60 Hz `KeResetEvent` cannot be racing one out** — the residual is not a race, timing bug, or missing stub. F-317 §2 also corrected F-316 §3: `KeResetEvent` (`:2098`) **has no log at all**, so the 60 Hz cadence is an `lr`-matched *inference* (`DPC-SIBLING-CENSUS` ~17 ms, `lr=0x8242FCF0` = return address of `bl 0x8242F870` at `0x8242FCEC`, one instruction after the reset call), not an observation — graded as such deliberately. **Consequence for §1/§2 of this file: with Path A delivered (3/4 full-buffer), Path B's four branches closed (F-308), the handler table undispatchable (F-314), the DPC producer dead (F-309) and no in-flight signal being discarded (F-317), there is NO permitted mechanism left in this tree that would produce the signal GFx waits for.** Tasks #23 (garage's coupled serve-framing fix) and #15 (peer place-pass) remain open but neither can produce it. **This is now a user decision on rule-2/F-055, not another attempt; the goal stays OPEN and unmarked.** Ledger through **F-317**; next ID **F-318**. **F-318 (2026-09-26 ~03:3x, BUILT + SOAKED three times: `w277`, `w278`, `w279`) delivered the session's FIRST positive frontier delta and re-framed task #23 out of the way.** The garage UI `.xsf` is now served **five consecutive package windows** (`INFLATE-HOSTSERVE-PEND … pkg=64980000 walk=00000000→00020000 serve=1→5`; guest `consumed` 32,748→196,553) where every soak in the ~250-log evidence base before it died after window 1 — `grep -l "pkg=64980000 walk=00008000" build/w*.log` returns **`w279.log` only**. **Cause: our own B7 no-progress backup-drain** (`INFLATE-J2-DRAIN-B7 … zero outLeft (backup)`, then `FLUSH`), which `return`s *before* the `inLeft == 0` refill block and so made two earlier fix attempts print **zero** markers; the drain was added in Session 73 to stop a different spin — do-not #9 biting my own mitigation. Fix = `kUiXsfChunkFeed` (`src/gpu_device.cpp:589`) + `MclaUiXsfChunkOpen`, keyed on the **dynamic** dest→pkg map and the **stable** pkg offsets (directive #5, no dest addresses), bounded by `retries < 400` and `walk < PackageSizeAt`. **Gate PASS vs same-code control `w274`: `PATHB-HOSTDECODE 5→6`, spins down, every structural marker +0, error lines 28=28, CP caught up, 57,892 vs 57,886 lines.** **F-315 is REFUTED and `kUiServeAdvance` stays OFF:** `st+8 consumed` is **cumulative**, so `ls.pos += consumed` double-counts (that WAS `w275`'s livelock), the `w275` loop was meshtextures `pkg=0xA0000` at **~11 M** inflate calls (printer counter `#10,956,600`, only every 200th printed), and `ls.pos` pinned at 0 is what makes `ls.pos+consumed` an absolute offset — the advance was never needed. **Next (`F-319`): the residual is now a `inLeft=35 magic=DACBF13D` partial-window leftover** (the refill's trigger is `inLeft == 0`) **plus `PackageSizeAt(64980000)` returning the `0x40000` fallback**, which caps the walk at 262,144 B against a 1,066,057 B container. Tasks #23 and #18 are re-opened as that, not as serve framing. Ledger through **F-318**; next ID **F-319**. **F-319 (2026-09-26 ~03:4x, BUILT + SOAKED twice: `w280` failed → `w281` revert verified) REFUTED that residual as the wall, and re-classified it: the garage's leftover is an OUTPUT limit, not input starvation.** Topping the input up at `inLeft=35` was arithmetically right (`UIXSF-TAIL-TOPUP #1 readAt=649A7FDD` = pkg + walk − inLeft, fired once) and the boot then spun to **704,373 lines vs `w279`'s 57,892**, 451,084 naming the garage dest with `consumed` frozen at 196,553 — because `XMEM-SZPTR #24 *destSz 131072→0` shows the 131,072-byte PSTREAM window was already **full** (`XMemDecompress` size params are IN/OUT *remaining*, verified against six lines where `dest(in)−dest(out)` is a round 32,768 multiple). **So the garage needs a second output window from the consumer/place-pass side — T41.11's wall (F-303) reached from the opposite direction and independently confirmed; `INFLATE-UNSTUCK`'s zero-outLeft stays, and raising `PackageSizeAt`'s `0x40000` fallback would buy input only, never 4/4.** `kUiXsfTailTopup=false`. Revert verified correctly this time: `w281` vs `w279` = only `WAIT/WAKE/rptrWB/PUT +7` jitter with `serve=1..5` intact; vs flag-off control `w274` the keeper deltas hold (`PATHB-HOSTDECODE 5→6`, **`INFLATE-HOSTSERVE-PEND 2→6`** — the +4 garage windows as a *tracked* counter now that §9 registers the marker, structural markers all +0, error lines 28=28). Ledger through **F-319**; next ID **F-320**. **F-320 + F-321 (2026-09-26 ~04:1x, BUILT + SOAKED five times `w282`–`w285`, controls `w281`/`w274`) delivered the session's second advance and the objective's first real verifier.** F-320: the feed is now keyed on the **inflate state (the stream)** rather than the dest, because the guest walks its own readlist slot by slot carrying `consumed` forward and only the first slot ever gets a `DEST-PKG` mapping — garage freeze moved **196,553 → 294,912 bytes consumed, three more slots visited, served-window count unchanged at 5 in both logs**, i.e. successor slots simply stopped being aborted. **This supersedes F-319's "output capacity" verdict** (`inLeft=35` was the end of a *slot*). F-321: `UIXSF-SLOT-VERIFY` re-derives the container with the Path A decoder (golden, 4/4 byte-exact offline) and compares each retiring UI dest forward from its first 64 bytes — **with its positive control inside the same run**: `raceeditor compared=143069 mismatch=0`, `policecam 19337/0` in two dests, `credits 29655/0`, and **garage `goldoff=0 compared=262144 mismatch=218959 firstbad=00008000`** — one 32 KiB window byte-exact, then not; sibling slot `B7A41000` all `CDCDCDCD`. Two self-corrections: F-320 §4's fabricated-`0x40000`-bound claim is **refuted** (`MclaUiXsfWalkCeil` reads RSC5 `+0x10`, `ceil=0010C449`, and input stops at the identical 294,912), and `w284`'s `B7A61000 slotcov=860` is a **policecam** dest, not a garage slot — **never carry dest identity across soaks; read the mapping from the log cited.** Gates: `w285` vs `w284` vs `w281` move only poll counters; structural markers +0, error lines 28=28; new markers registered in §9. **Task #25 closes; the garage is now a search, not a guess: where did the guest write container offset `0x8000` onward (the comparator names any dest whose head is in the golden), and must input flow past `consumed=294,912`?** `MOVIE-CTOR`/`nGfx` still 0 — GFx half closed by elimination (F-314/F-317), rule-2/F-055 still the user's. **Objective NOT achieved; do not mark the goal complete.** Ledger through **F-321**; next ID **F-322**. **F-322 + F-323 (2026-09-26 ~04:5x, BUILT + SOAKED nine times `w286`–`w293`, control `w289`) measured the garage and then moved it.** F-322: a slot-hunter scanning the readlist inventory against the golden decode gives the deliverable its first real numbers — raceeditor 143069/143069, policecam 19337/19337, credits 29655/29655 = **100 %**, garage **3.1 %** (32,768 of 1,066,057 in one slot, and NO slot holds any other part); the hunter's first version lied (`slots_matched=0` for a byte-exact container) because it scanned the empty `g_mclaRebaseMap`, so `nmap/scanned/skip_*/anchor_in_map` are now mandatory. F-323: `kUiXsfGoldenFill` writes `golden[slot.vbase - anchor.vbase]` across the anchor's virtual span (F-320's per-job contiguity as a write) → **4 slots / 819,200 bytes / gold_span [0,0xC8000)**, and its poison-only protection saved raceeditor, because **vbase is per-JOB: garage and raceeditor both start at 0x50000000**. Honest coverage after fixing the double-count (the container's 0x40000 blocks repeat, so `bytes_exactly_covered` was summing the same range) is **262,144 = 24.6 %** — the number went DOWN when the instrument got right. **Gate vs fill-off `w289`: structural markers +0, error 28=28, poll −46, and `MOVIE-CTOR`/`UILOAD-census`/`GFx`/`nGfx` UNMOVED by quadrupling verified garage presence — third independent confirmation that GFx is not downstream of decompress.** Task #27/F-324 = the last 246,857 bytes, blocked on the garage job's slot run ending at 0xC8000 (job/place-pass construction). **Objective NOT achieved; do not mark the goal complete.** Ledger through **F-323**; next ID **F-324**. **F-324 + F-325 (2026-09-26 ~05:1x, BUILT + SOAKED `w294`–`w296`, commits `188e140`+`9b8d4ff`) took deliverable (a) to 4/4 and then proved it is not durable.** F-324: a job's virtual ranges are DISCONTINUOUS (`50000000..500C8000` then `60000000..`), so vbase-span placement stopped at golden 0xC8000; `kUiXsfFillListOrder` walks the readlist as an ORDERED destination list instead → **6 slots, 1,066,057 bytes, `gold_span=[0,0x104449)`**, and `MclaUiXsfReverify` (offset-anchored read-back, overlaps merged) certified `still_present=1066057 pct=100` — which also corrected F-323 §3: repeating blocks defeat a needle search, not a compare, so 24.6 % had been an under-estimate. **F-325: sampling that read-back late (every 1,000th inflate entry) drops the garage to `still_present=692445 pct=64 first_bad=00040000`, flat over five samples, while raceeditor stays 100 %** — the guest's own inflate re-uses slot `B7801000` for ANOTHER stream (`consumed` restarts at 32,748), quantitatively confirming F-303 §3's clobber claim. **Consequence: host decode can place all four containers but cannot keep them there, so durable "decompressed in guest memory" is a Path B property; re-filling over guest-written slots was considered and rejected as corrupting live state.** Gates clean (`w296` vs `w295`: own lines + poll jitter, error 28=28, structural markers unchanged; `PRESENT` in a census is a substring collision with `still_present=`, not a marker). **`MOVIE-CTOR`/`UILOAD-census` still 0 after five independent interventions — GFx is not downstream of decompress; rule-2/F-055 stays the user's call. Objective NOT achieved; do not mark the goal complete.** Task #28/F-326 = Path B: make the guest's own inflate produce container bytes past 0x8000. Ledger through **F-325**; next ID **F-326**. **F-326 + F-327 (2026-09-26 ~05:4x, BUILT + SOAKED six times `w297`–`w300`, commit `4c10824`) measured Path B's starting line and closed the serve-framing route to it.** `kUiXsfFillDryRun` keeps the fill's layout claim without writing, so the reverify reports the GUEST's own achievement: `still_present` **63,072 of 1,066,057 (5.9 %)**, flat over five late samples, `first_bad=0x8000` — which means F-325's 64.9 % was 91 % host-written, and every coverage claim must now say by whom. Frame-aligned serving (the container's own `pkg+0x14` 2/5-byte frame headers, the recipe `xmem_lzx.h:531-552` validates offline) **walks the table correctly — 32 frame-sized serves, cursor `64980000→649A6F7A` — and still yields nothing past 0x8000**; it instead stalls with `inLeft=2051` NON-zero at 20.36 M inflate entries (659,319 lines vs 57,866), so the caller loop neither requests input nor retires. **⇒ the blocker is the guest's per-call frame/`outLeft` accounting = Path B's descriptor side (task #15), not serve framing**; `kUiXsfFrameServe=false` with the parser/cursor/`frame=` field kept for that work. Two self-inflicted instrument bugs fixed and logged as rules: making `XMEM-SZPTR`'s `uiDest` dynamic (F-321) removed its rate limit and produced 5.53 M lines of one print on a hot hook (**widen the predicate, narrow the rate in the same edit**), and the late sampler needed an eight-sample cap. Revert verified by the restored NUMBER (43,732→63,072, `first_bad=0x8000`), not by line totals. `MOVIE-CTOR`/`UILOAD-census` still 0 — GFx unmoved by six interventions. **Objective NOT achieved; do not mark the goal complete.** Ledger through **F-327**; next ID **F-328**. **F-328+F-329 (2026-09-26 ~05:5x, `w301` stale-no-op / `w302` / `w303`, commit `85382db`) found and fixed a stale-descriptor bug by READING the recompiled callee.** `sub_821D5E10` (`generated/ppc_xenon/ppc_recomp.18.cpp:10832+`) clamps each call's input to `[st+12]-[st+8]`, and nobody ever wrote `st+12` — w302 shows the garage stuck at `exp=0002FFC9` (196,553, the previous pkg 0xA0000 stream's stall point on shared stack state `006D8F20`). `MclaUiXsfUnc` + `kUiXsfSetExpected` now publish the container's declared total (the RSC5+XMem preamble is 12+8=20 B, matching `xmem_lzx.h`'s `src=20`): `exp=00104449`, `consumed` reaches 262,124. **Kept (gate clean, `PATHB-HOSTDECODE 6→7`, structural markers +0) but it did NOT move the deliverable — guest presence is still 63,072 (5.9 %).** Next lead (F-330), two static reads and zero builds: `sub_8244FF20` is only a codec gate (`[ctx+4]!=1` → `0x80004005`; our `ret=0` proves it passes) and tail-calls `sub_82460420`, which guards a **single global LZX decoder instance at `0x828D38D8`** — one shared decoder across all streams explains frame-0-then-garbage and matches F-325's cross-stream slot re-use; test per-stream reset/interleaving there. Process note: a guessed `Edit` anchor failed silently and I soaked a stale exe as `w301` — caught by mtime + missing field; **`w301` is excluded from all comparisons**. **Objective NOT achieved; GFx unmoved by seven interventions; do not mark the goal complete.** Ledger through **F-329**; next ID **F-330**. **F-330 (2026-09-26 ~06:1x, BUILT + SOAKED `build/f330_build.log`→`w304`, commit `bd3b9f6`) CLASSIFIES the garage wall and closes the serve-side axis: at container offset 0x8000 the guest's 32 bytes appear NOWHERE in the golden within ±4 KiB (`NOT-IN-GOLDEN-NEIGHBOURHOOD`) while the golden there begins a fresh `44495500` ("DIU") block — a shift would have indicted our slicing, unrelated bytes indict the decoder.** So window size (F-318/320), stream keying (F-320), frame-aligned framing (F-327) and the stale `[st+12]` clamp (F-329) are all eliminated by measurement, and the remaining Path B surface is the guest's decoder continuity across an `0x8000` block: the lazy singleton at `0x828D38D8` (`ppc_recomp.82.cpp:12099`) and the per-block step `sub_821D5E10` (`ppc_recomp.18.cpp:10832+`) is not making. `[ctx+4]` codec gating is excluded (`ret=0` proves it passes). **Plan consolidated at `docs/UI_INFLATE_PLAN.md` — the objective's Path A/Path B evaluation, the elimination table, the acceptance test for each remaining step, and the flag register as it actually stands in the tree.** Gate vs w303: read-only classifier, no structural marker moved, error 28=28. **Objective NOT achieved: garage 5.9 % guest-only, `MOVIE-CTOR`/`UILOAD-census` 0; do not mark the goal complete.** Ledger through **F-330**; next ID **F-331**. **F-306 closes F-305 step 1:** the extent directory is the job readlist's `{vbase, pbase, size}` triplet (`gpu_device.cpp:9890-9902`, 12-byte stride) and the host **already materializes it for `sub_8217D890`** (`:9909` comment, `MclaPublishGuestRebaseCtx`/`MclaArmRebaseCtx` `:4074-4102`, **17 arm sites**) — so "no table exists" and "never armed" are both ruled out, and `REBASE-ARM`=0 is a dead-marker artifact of my own invented grep string, not evidence. **F-306 §2's "decisive open question" (host writes `size` where the guest wants `end`) was then REFUTED by F-307 §1:** the publisher matches the guest's header shape (`nmap<<16` → the two summed `lhz` at `8217D838`) and stride (`+4`, ×12 = `8217D878`) exactly, publishes 7× in `w273`, and `Invalid fixup`=0 — my `subf` reading was a mis-attributed register. **Table materialization is NOT the blocker.**

**F-307 (2026-09-26 ~04:3x, existing-log comparison, no build) is now the objective's Path-B target.** The honest, layout-independent metric is **`FDBF8-BUILD` lines whose `[arr]` dereference is non-zero** = "the container's entry array resolved": `w193` **7/9**, `w248` **7/9**, `w251`/`w258` 3/5, and **0 in every log from the `w257` era onward** — including **`w269`/`w270`, which have `PATHB-HOSTDECODE=0`**. So **Path A did not cause it** (the flag-off control already existed in logs; no rebuild needed), and Path B's job is to **restore a resolution the guest achieved 7 times in `w193`**, not to invent a descriptor. Two dead metrics recorded so they aren't re-used: `arr=B7B6D9B4` is address-coincidental (dests move — F-297 §2), and "non-null `arr`" counts raw payload like `003100CB`. **Census blind spot fixed:** `FDBF8-BUILD`/`RSC-PLACE-ARR-GATE`/`REBASE-TABLE` were absent from PROGRAM_GUIDE §7/§9, so `soak_census.py` never tracked them — that's how F-297's "every structural marker +0" coexisted with this going 3 → 0; they are registered now. The loss window is **confounded** (`w257`/`w258`/`w264` were F-285/286/288 experimental variants, not sequential mainline builds), so no clean bisection exists across it. **Next measurement:** in `w193`, who wrote the resolved array (note `B7B6D9B4` == `kArrCand[0]`, `:9797`, and `:9805` records `5006C9B4 → B7B6D9B4`), and do the markers that appear in `w193` but not later (`PLACE-ARR-FIX`/`-PRE`/`-RERUN-DONE`, `W30-ARR-OK`, `W31-BIND-CHECK`, `ARR-GATE` suffix) name the lost producer?

**F-304/F-305 (2026-09-26 ~04:2x, main-agent raw-byte work, no build/no boot) then corrected two of the four points above and turned Path B from a guess into a decoded target.**
- **F-304 supersedes F-300.** Its "sibling container was consumed" evidence is `sub_825FB0D8` = the **swf-container destructor** (`src/task_dispatch_trace.cpp:1138`), **20/20 POISON-SKIP** with `+12=00000000` — that is the failure case (dispatching through such a vtable AVs at `825FB14C`). The repoint plan is also dead on its own terms: `FDBF8-ARR-RESTORE` **0** hits (blocked by `realVt`, `gpu_device.cpp:9851`), `PLACE-ARR-RERUN-DONE` **0**, and `RSC-REBASE-PREPLACE-DONE` runs 3× with `nmap=7` but `headRewritten=0 childRebased=0`. **A marker's text is not its meaning — read the printer.**
- **F-305 decodes the swfC container ABI** from `build/cache/mcla_pe.bin` via `tools/ppc_disasm.py`: `[+0]` vtable (FDBF8 stamps `0x8208521C` at `825FDC18`; place-pass `0x82085364`), **`[+12]` = a CURSOR advanced by a LENGTH** (`825FDC34`, with `sub_8217D890` returning `table[idx].+8 − table[idx].+4` per `8217D8D0 subf`), `[+16]` = **`lhz` u16** cnt, entries **stride 8** via `sub_8260A830`; `sub_825FDA90` = 9-way switch on a **u8 tag at `[rec+8]`**, tag 2 recurses (nested container), invalid → error object `0x82087180`. **A null cursor makes FDBF8 skip the consume entirely** (`825FDC20`), and the project's own comment says the array stays CDCD "**when the preload task never fills it**" (`task_dispatch_trace.cpp:1071-1073`) — i.e. the F-186/F-187 enqueue gap, now stated in ABI terms. **Path B target = supply that cursor + 8-byte entry array + u16 cnt pointing into the payload Path A already placed.** Open: the entry-record unit, and which live object owns the 12-byte extent directory `sub_8217D828`/`sub_8217D890` search (task #19).
- **Discipline note worth keeping (F-305 §7):** item 2 was first written claiming the cursor was *relative*, from a half-read disassembly where the callee had not been opened. Finishing the trace refuted it. **Had the draft been committed, the next session would have "fixed" `gpu_device.cpp:9826` from absolute to relative and broken a correct line** — `kArrCand[]` fails because it guesses, not because it writes an absolute value. Task #12's and #18's titles/statuses were fixed from F-301/F-303; **gate everything here on `MOVIE-CTOR`, never `nGfx` (F-302).**

**[2026-10-01] §0 trail relocated:** the 18 superseded state blocks (09-20..09-25) live in [docs/archive/trail-longtodo-2026-09.md](docs/archive/trail-longtodo-2026-09.md). §1 below starts immediately.

## 1. Rules (all in force; each cost a session)

1. **Census before fix** — no short-circuit without root cause.
2. **Never edit `generated/**`** — recompiler output, input only.
3. **Raw-byte rule (F-023)** — verify every IDA claim vs `build/cache/mcla_pe.bin` (offset = VA − 0x82000000) or the generated TUs.
4. **One owner per guest address** — grep `src/` before adding any hook/override.
5. **One new log per experiment** — `w37` series; never overwrite.
6. **`timeout` every boot; kill mcla.exe after every soak and before every build** (`MSYS_NO_PATHCONV=1 MSYS2_ARG_CONV_EXCL='*' cmd.exe /c "taskkill /F /IM mcla.exe"` — unguarded, Git Bash silently no-ops it; boot-cycle SKILL.md:29).
7. **Tree must always compile** — fix the build before adding anything.
8. **Retail content only** (`xarchive_cache.rpf` + audio/music); never `mc4/art`.
9. **No framework rewrites/optimization while the game isn't booting** — parked in `CODE_OPTIMIZATION_PLAN.md`.
10. **Write the trail as you go** (HANDOFF live block + session ledger; F-### ledger; phase ledger; this file's tables). `docs/` is tracked since 2026-09-20 — plain `git add` suffices; never re-ignore it (a `git clean -xdf` loss is why it was un-ignored).
11. **Two-session coordination (LIVE 09-20 16:18).** Before build: no mcla/ninja running AND newest `build/*.log` older than ~2 min — fresher = another session mid-experiment: docs-only work. Keep src edits additive.
12. **Stale-exe trap** — after any link attempt verify `mcla.exe` mtime moved before soaking.
13. **No claim without evidence.** Cite log line or commit hash; commit-only claims marked UNVERIFIED until a soak reproduces them.
14. **Count the doors before walking the halls (F-094).** Before any multi-cycle build+soak hop-walk to find who calls a guest function, run a whole-image static `bl`-edge scan in `mcla_pe.bin` (4-byte opcode decode, target arithmetic with sign-extended LI). One scan on T41.3n2 proved the entire image has exactly ONE `XMemDecompress` call site — that answer beat three rebuild+soak cycles of lr-attribution.
15. **Scan guest code by encoding, never by disassembly text (F-094).** Text greps miss idioms; word-pattern scans over-match: a `stw/stwu …,-352(…)` hunt returned 99 stack prologues (`stwu r1,-352(r1)`) out of 100 hits before the rt/ra register fields filtered them. A negative scan is only as trustworthy as its encoding mask.
16. **A format doc's claim about THIS image is a hypothesis until the consumer code graph agrees (F-094 supersedes F-073/§7).** `MCLA_RPF3_Technical_Reference.txt` §7 ("stored≠expanded ⇒ XMem LZX") stood in the ledger until the lone-door proof contradicted it for the six `.list` members. Verify any spec mechanism against the code that consumes it before building serve strategy on it.
17. **Never redirect generator output into a live file; scratch + `cmp` + move (09-23 merge, twice-bitten).** A parse-failed `awk > src/gpu_device.cpp` silently truncated the working file to 0 bytes (recovered from git + snapshot), and a `python -c "…"` with backticks in the string let bash command-substitute them away, blanking every name in a written HANDOFF block. Write to a scratch path, verify bytes, move; single-quote `-c` programs containing backticks.
18. **Merges across volumes are per-file 3-way from a FROZEN snapshot, each committed with provenance (09-23).** Both trees held content the other lacked (`gpu_device.cpp` bidirectional; F-069/070 vs F-077…092); copying either side whole destroys work. Sequence that worked: snapshot + cmp-verify → WIP-commit dirty state → per-file `diff` census of E-only/C-only lines → port/merge one file per commit.
19. **A zero from an instrument is not a result until the same instrument is shown firing on an event you know happened (F-100 voids F-095).** `SetThreadContext(CONTEXT_DEBUG_REGISTERS)` on a running, un-debugged thread reports success and silently drops the registers: `w59` logged 18 `B1-ARM … ok=true dr0=1C6157B80` and still zero hits while those same threads ran `ReadBytes(C6157B80,16)` inside the RD-BUF census. Self-report an instrument's *effect*, not its acceptance (force a known trip, or print the value the probe claims to see), and prefer the static/whole-image answer (rule 14) over a dynamic probe you cannot validate.

## 2. Tasks (in order; stop-ship gate each)

> **[2026-10-01] PRECEDENCE — §2 is a SUPERSEDED SNAPSHOT; the operative queue is the ledger's task-series.**
> §2 froze at the 2026-09-20 wave plan. Its **last inline closure is 2026-09-25** (`T41.9 — CLOSED-DEAD
> 2026-09-25 (F-204b)`, the only dated closure inside this section). Real sequencing migrated to ids
> invented **inside `ROOT_CAUSE_VALIDATION.md`'s `- Task:` rows**, which §2 does not contain.
>
> **Measured 2026-10-01, so this is a count and not a claim:**
> - §2 (heading → `## Older queue`) contains **17** `T4x.y` ids: `T41.1`–`T41.15`, `T42.1`, `T42.2`.
> - The ledger contains **100** distinct `T4x.y` ids — `T41.1`–`T41.100` (**53** present) and
>   `T42.1`–`T42.48` (**47** present; `T42.38` is the one gap in that range).
> - **88 of the ledger's ids appear nowhere in §2**, including `T41.59`, `T41.60`, `T42.20` and
>   `T41.100`. The queue shorthand **"task #87" is `T42.39`** (the ledger's `T42.39 (#87)` rows and
>   `HANDOFF_NEXT_AGENT.md`'s `#87`) — also absent from §2.
> - **Rule for this file:** read §2 for the *route* and the *acceptance gates*; read the ledger's
>   `Task:` row for whether an id is **live, re-scoped or closed**. A §2 item with no ledger row is not
>   thereby open. `AGENTS.md` forbids a queue item living in only one of the two places — this note names
>   both so neither can be silently the truth. Cross-reference: `HANDOFF_NEXT_AGENT.md` records the same
>   divergence from its side; the two notes must be updated together.
>
> **Number collisions, measured — do not resolve by guessing which task owns a number:**
> - **`T41.10`** = §2's "CONSOLIDATED IMPLEMENTATION PLAN for the F-186/F-187 UI-inflate objective"
>   **and** §2's "Wave D input (was T37.7)" — the renumbered Wave queue collides with §2's own
>   UI-inflate plan.
> - **`T41.11`** = §2's "garage progressive multi-window host decode" **and** §2's "Wave E audio
>   (was T37.8)".
> - **`T41.6`** / **`T41.7`** — same failure, one level further out: the ledger uses them for the
>   "B4 feed / B3 conversion direction" work while §2 uses `T41.6` for "Wave A (was T37.4)" and
>   `T41.7` for "decide and record which draw path is canonical". Two unrelated tasks, one number.
> - **`T42.1`** — the **ledger** already caught this one and fixed it in its own favour: an experiment
>   "F-452 §3 called `T42.1`" collided with §2's `T42.1` (TLS[12] producer) and was **renamed to
>   `T41.100 (#67)`**. Follow that precedent — rename, never re-use.
> - **`T41.9` is NOT a three-way ambiguity.** Its three hits are (i) the task itself,
>   (ii) that same task's *original recipe, retained for provenance*, and (iii) **one distinct task**,
>   "delete the remaining fatal absorbers" (= `T40.2`). An earlier audit read all three as one id.
>
> **Correction to an earlier audit claim.** The "closed in the ledger but still open in §2" state was
> **not established** for `T41.6` / `T41.7` / `T42.1`. The ledger closures that *are* recorded are
> `T41.59` (closed with a new shape; successor `T41.60`), `T41.60` (closed with a negative that
> redirects the objective), `T41.79` **and** `T41.80` (both done in a single entry), and `T41.100`
> (the renamed `T42.1`). None of those four is in §2.

### T41 — the ordered route from "one AV kills the boot gate" to a playable loop (added 2026-09-20 22:45)

Dependency order, not wishlist order. Every item's acceptance is a `tools/soak_census.py` delta against
the **named** baseline in its own line, per rule 13. Nothing below is "done" without that line.

- **T41.9 — UI `.xsf` inflate enqueue (Path B; F-186/F-187/F-191) — CLOSED-DEAD 2026-09-25 (F-204b).** The recipe below was implemented and cleanly measured (w231/232/233): the async `FDD50`/`E5E58` enqueue *closes the F-186 gap* but does **not** decompress the UI — it cannot size `record[+4]` even with the exact static `arg0`, and the executor livelocks upstream on `src=CAB28300`. `record[+4]` is not the blocker. **Replaced by T41.9b (peer serve-framing fix in `kInflateIntervene`/`MclaForceServePkgForDest`, `src/gpu_device.cpp:7487`,`:7765`).** Original recipe retained below for provenance.

- **T41.9b (serve-framing in `kInflateIntervene`/`MclaForceServePkgForDest`) is SUPERSEDED as the unlock by F-226.** Decompression already runs and produces output (`INFLATE #3 consumed=2284`, "XMem produced 44365500"); the residual is NOT bad serve framing — it's that the whole UI path is never *dispatched*. Do not chase serve framing as the nGfx key.

- **T41.10 — CONSOLIDATED IMPLEMENTATION PLAN for the F-186/F-187 UI-inflate objective (supersedes the stale "trace 0x40003B03 producer / KeInsertQueueDpc stub" version; F-227 disproved that lead). = objective deliverable #3.**
  **Path A (host-side LZX): DEAD** — XMem LZX ≠ CAB LZX; libmspack decodes only 128 KiB then `rc=11` (F-191, offline `tools/lzx_raceeditor_proof.*`). Only the guest's own `XMemDecompress`(`sub_8244FF20`) decodes `.xsf`; a host-decompressed buffer wouldn't drive GFx anyway (GFx init needs the game's own UILOAD path). `kHostLzxDecode=false` (`gpu_device.cpp:329`).
  **Path B (guest descriptor construction): FUNCTIONAL + IMPLEMENTED** — hook `sub_821E2940`→guest async `sub_821FDD50`; the 4 UI records (raceeditor/garage/policecam/credits) open fully executable (`+4` correct, `+8` device `C60AC180`, F-205/213). Branches at `gpu_device.cpp:10418-10475` (single-open static arg0) & `:10496-10660` (post-open enqueue); flags `kPathBEnqueueUI`/`kPathBSingleOpen` OFF (`:397/:403`).
  **PROVEN NOT THE GATE** — the `.xsf` decompress is driven by UILOAD `sub_822C0980`, which is *unconditional* inside boot-gate `sub_82131008` (`0x821310b8`) but the gate is only the msg-handler for id `0x40003B03` (`{handler,msgid}` table `@0x82102aa0`), drained by boot worker `sub_8242FB88`. Host dispatch is HEALTHY (F-227); the gate is never posted because the **main boot thread never returns from the UI bootstrap** (`sub_82131790`→installer `sub_82131508`→`sub_822C2EA8`→byte-reader `sub_821CFAA8`→refill `sub_821BE4F0`→`sub_82249750`), which F-233/F-235 show is stuck in the **effects/scene resource-place pass** (`sub_82587xxx`), NOT UI. 600 s soak `w244`: `REBASE-POISON n=3,368,026 … skip D890 fatal` (`task_dispatch_trace.cpp:517`), `frame=0`, `UILOAD`/`XSF-INFLATE`/LoadBytes all 0 → **UI `.xsf` provably never decompressed.**
  **BLOCKER (the real fix, OUT of UI-inflate scope):** the effects/resource place pass loops resolving poison/mostly-unique resource pointers via rebase provider `sub_8217D890` (host delta-0 fallback at `task_dispatch_trace.cpp:517` turns a would-be `sub_821D2378` "Resource" fatal into an infinite retry). `B7B41000` itself CONVERGES (F-238), so target the `sub_82587xxx` resource serve/rebase, not `B7B41000`. The 24-region rebase map (`g_mclaRebaseMap` `gpu_device.cpp:3834`, per-container by-design) can't just be accumulated (F-237). Real work = fix the RSC serve so resource children resolve / the place pass terminates, in the peer's active, load-bearing streaming/serve code.
- **[2026-10-22] SUPERSEDES the FRONTIER row at :629 (F-861).** That row says: *"the effects/resource place pass loops resolving poison/mostly-unique resource pointers via rebase provider `sub_8217D890` ... `B7B41000` itself CONVERGES (F-238), so target the `sub_82587xxx` resource serve/rebase, not `B7B41000`."*  MEASURED for `build/w874.log`, **both halves are stale**: (a) **`sub_82587xxx` does not run at all** -- the strings `82587`/`82587A50`/`82587350` appear in **ZERO** rows of the 2,242,408-line log, and the `REBASE-POISON` lr histogram is `823C3280`x2693, `821D29A0`x160, `821B4A30`x113, ... ; and (b) **`B7B41000` is the HOST's own empty shell** (a guest-allocated, guest-ZEROED page: 16 `PAGEWATCH W` rows all `= 00000000`), while the real container object is **`0xB5FAC000`** -- and the place pass **worked** on it: `PLACE-CONTAINER #1 obj=B5FAC000 ... placed=1875968 **gap=0** head=44495500`, 17 published rebase regions, `EF100-WALK #001 ... +50=164`, `W32-CONSTRUCT-CENSUS #1 nValidTag=15`, and 327 `W31-FDA90` rows.  **THE REAL FRONTIER, MEASURED:** the GFx loader constructor `0x824C6F08` occurs **EXACTLY ONCE in the whole 10,354,688-byte image**, at `0x82117838`, in a stride-8 **{handler, kernel-handle}** table paired with kernel handle **`0x40001905`**; the only dispatcher for that table, `sub_821EBCF0`, printed **0 rows** (`GFX-TABLE-DISP`); and the loader's only in-image caller `0x82482F78` has **0 direct `bl` callers** (reached as a data-registered handle handler, as F-439 recorded).  **⇒ The guest never issues the GFx handle request, because the chain that would issue it is the SAME chain F-860 found for the UILOAD** -- a `bctrl` on an instance of the class whose vtable is at `0x8201C600`/`0x82038FF0` (whose vptr is never materialised as a word in the image).  **The GFx wall and the UILOAD wall are ONE.**  The place pass and the `sub_82587xxx` serve are NOT the cause.  Also note the class at `0x8201C600` is **`SaveGameMgr`** (the bytes after its 23 entries are the ASCII "SaveGameMgr"), so `0x822012E8` at its slot +44 is a SaveGameMgr virtual method and the tree's `UILOAD-census` hook on `sub_822012E8` may be attached to the wrong function -- the acceptance gate names `sub_822C0980`, which IS reached (36 `MSGCHAIN` rows).  **Also a live citation defect:** `src/gpu_device.cpp:1507`, `:11733`, `:11885`, `:8540-8545` cite "F-806" for the host's container-placement work, but ledger F-806 (:19791) is about o1heap write-watchers -- a local, never-written id; the markers `PLACE-CONTAINER`, `GUEST-REBASE-ROWS`, `PLACE-ENTRY`, `PLACE-DISPATCH` appear in **ZERO** headings of the ledger.
  **DO-NOT:** no UI-inflate/enqueue/serve/rebase/gate/inflate short-circuits (do-not #9; F-183/F-204b inert, F-194 load-bearing, F-079 gate deliberate); F-055 bars forcing `sub_82131008`/UILOAD (`gpu_device.cpp:1474-1644`); peer owns `task_dispatch_trace.cpp`/streaming.
  **Gates for any future attempt (rule 13):** `nGfx>0` + `UILOAD sub_822C0980`>0 + `W35-BOOT-GATE`/`BOOT-GATE-POST`>0 + `XSF-INFLATE`>0 + `W34-NOGFX`→0 vs `w230`, no `C0000005`/`Fatal`/`FATAL-SOFT` regression.
- **[2026-10-22] THE `UILOAD` READING IS A RED HERRING, AND THE `UILOAD-census` MARKER IS A STRUCTURAL ZERO (F-862).**  The function the tree's `UILOAD-census` prints, `sub_822012E8`, is **UNREACHABLE in this build**: the vtable that holds it (slot **+44**) is the `SaveGameMgr` vtable at `0x8201C600` / `0x82038FF0`, and **the address `0x8201C600` is never materialised anywhere in the image** -- 0 `lis`+`addi` pairs, 0 `lis`+`ori` pairs under F-857's corrected operand order, 0 raw words, 0 `base+offset` forms (CONTROL: the same scan DOES find the known `0x82085364` place-vtable build at `0x825EF128`/`0x825EF168`).  The class is therefore never instantiated, so `UILOAD-census` = 0 is a **structural zero, not a missing step**, and every session that recorded "UILOAD = 0" as a blocker was chasing a phantom.  **The gate item itself names `sub_822C0980`, which IS reached** (36 `MSGCHAIN` rows, `consumer-823045E0` #1..#8 all `lr=822C0A0C`), so the gate item is met.  The chain the tree records ("822C0980 -> 821FD640 -> 822012E8 (UILOAD)", src/task_dispatch_trace.cpp:1884-1885 and src/gpu_device.cpp:18390-18391) **names an uncallable function** and is closed.  **The ONE remaining named blocker is the GFx kernel handle:** the loader constructor `0x824C6F08` occurs exactly once in the image, at `0x82117838`, in a `{handler, kernel-handle}` table paired with handle **`0x40001905`**; and `GFX-TABLE-DISP` is **MISNAMED** -- `sub_821EBCF0` is a **FACTORY** (it allocates via `bl 0x82144A20` and stores the new object at `0x8286D014` and `obj+152`, and writes `obj+308 = 0x821FABA8`), not a table dispatcher, so its 0 rows mean **"the object is never created"**.  The next step is a log-only census on the guest's kernel-handle **REQUEST** path, not on the table.
- **[2026-10-22] ACCEPTANCE-GATE STATUS, measured on `build/w874.log` (F-860).** `nGfx>0` **NOT MET** (3 rows, all `nGfx=0`); `UILOAD sub_822C0980`>0 **MET** (36 `MSGCHAIN` rows, `consumer-823045E0` #1..#8 all `lr=822C0A0C` = inside `0x822C0980` -- note the gate item names `sub_822C0980`, which is NOT the `0x822012E8` that `UILOAD-census` prints); `W35-BOOT-GATE`/`BOOT-GATE-POST`>0 **MET** (31 + 8); `XSF-INFLATE`>0 **MET** (1,430 rows, with the F-502 caveat that it is a host-VFS member probe); `W34-NOGFX`->0 vs `w230` **NOT MET** (3 rows); and the no-`C0000005`/`Fatal`/`FATAL-SOFT`-regression clause **MET**. **Three of the five gate items are met and the two unmet ones are the SAME wall** -- the host's own synthesis of `0xB7B41000` leaves `arr=0 / cnt=0` (`W30-ARR-NOKIDS`), so no GFx loader object is ever constructed and `F438-GFXCTOR` cannot fire.
  **Status: objective deliverables #1–#3 complete; #4 end-state blocked on the above peer subsystem (not reachable via UI-inflate work).** See ledger F-186→F-238.
  **SUPERSEDED 2026-09-26 (F-295→F-297, see §0-newest2):** the "Path A: DEAD" line above is wrong — Path A is delivered and shipped (`kPathBHostFullDecode = true`), and 3 of the 4 UI `.xsf` ARE decompressed byte-exact into guest memory. What survives of T41.10 is its `nGfx` verdict: decompression does not arm a GFx loader, and the gates it lists (`nGfx>0`, `XSF-INFLATE>0`, `W34-NOGFX`→0) are still unmet.

- **T41.11 — garage progressive multi-window host decode (the last of the 4 UI `.xsf`; split out of the F-297 milestone by user decision, "a progressive multi-window driver touches VM state and is its own task").** `src/xmem_lzx.h` already decodes garage byte-exact offline via the *walk* path (33 frames, 1066057 bytes, `ninja -C build check_xmem_lzx` → EXACT), and `PATHB-HOSTDECODE-TOP-SKIP … pkg=64980000 unc=1066057 room=262144 → guest` shows exactly why it is refused in-boot: the dest only ever offers a 256 KiB window, and completing a truncated container is worse than leaving it (`src/gpu_device.cpp:7817`, `:8998`). The work is to feed the guest's own progressive window loop — decode frame-range N for the window the streamer is on, write it, advance `g_destPkgWalk[outPtr]`, and let the executor ask for the next window — instead of one whole-container write. **F-298 narrows this materially: garage's FIRST window is already byte-correct from the guest's own inflate** (`build/w271.log:13682` `BUF-HEAD D2308-buf @B7AC1000 44495500 5004E230 00706164 500B1B14` == `build/xmem_golden/garage.bin` head, read 261 ms *after* the host `…TOP-SKIP → guest`), so the gap is bytes ~262,144→1,066,057, not the container from zero — and the F-297 `fits` refusal is confirmed correct (writing would have replaced valid guest output with the same bytes, or overrun a 256 KiB dest). The dest is also a **streaming band, not one buffer**: `JOB2-PKG-SERVE … dest=B7AC1000 destCap=131072` (`w272:4295`) with `INFLATE-REFORCE #1..#12` walking `outPtr` across `B7AF1000`→`B7801000`→`B7809000`→`B7841000`→`B7851000` (`w272:4311`-`:4596`), so no hook instant ever has 1,066,057 bytes of room and a progressive fill must map each band slice to its offset in the decoded blob. **That mapping sits beside the peer's load-bearing `kInflateIntervene` re-point (F-194) — do-not #9: do not stack a second re-point on it.** **Acceptance:** `PATHB-HOSTDECODE*` for `pkg=64980000` with `wrote==1066057` cumulative and no `…TOP-SKIP`, `C0000005` 0, every structural marker +0 vs `w272`, `tools/soak_census.py` against `build/w272.log`. **Do-not:** no guest-VM re-entry from the hook (F-288/F-290/F-293 — that is what the host decoder exists to avoid), no stacking a second serve mitigation (do-not #9), and `nGfx` is NOT this task's gate.
- **T41.9b — (was T41.9) UI serve framing in the peer's inflate re-point.** Make `kInflateIntervene` serve the UI container's real RSC5+XCompress body (magic `0x0FF512EF`, non-zero `inLeft`) instead of `CAB28300`/zeroed-`inLeft`, while staying load-bearing for meshtextures. Peer-owned streaming code (uncommitted F-188–F-203). Gate: `XMEM` livelock gone, UI inflate `produced>0`, `nGfx>0`, no new `C0000005`/`Fatal`. do-not #9: no stacked short-circuits. F-204/F-204b carry the full evidence + file:line.
- **T41.9 (original, DEAD — F-204b).** Path A (host libmspack LZX) is **closed by F-191's offline proof** (XMem LZX ≠ CAB LZX; caps at 131072 B / `rc=11` under every strategy — harness `tools/lzx_raceeditor_proof.c`). Implement by re-issuing the async load request the meshtextures already use for each UI container: in the existing `sub_821E2940` hook (`src/gpu_device.cpp:10200`), after a `resources/ui/*.xsf` open succeeds, build `I`(+0=inflater ctx, +4 slot, +8 handle, +12 sec) + `D`(+0/+2 u16 counts, +4 12-byte entries) and call `sub_821E5E58(r3=I,r4=D,r5=0,r6=0)` — mirroring `sub_821FDD50`'s wiring (`generated/ppc/ppc_recomp.23.cpp:14748`, ABI map + all call sites in **F-191**). **Precondition:** the peer's uncommitted `kHostLzxDecode` (F-188–190) must be reverted first — no stacked short-circuits (do-not #9). **Gate:** `ENQ sub_821BCB10` fires for pkg `0x0A0000`, INFLATE (`lr=821BC380`) runs for `pkg=000A0000`, `W34-NOGFX` `nGfx>0`, `soak_census.py` vs `w193` shows `GFx` up with no new `C0000005`/`Fatal`.

**Stage 1 — make the guest finish its own boot (nothing downstream is measurable until this).**

- **T41.1 — close T39.1 the safe way + record the attach method.** IDA is reachable by HTTP at
  `127.0.0.1:8745` (verified: `tools/list` → 47 tools, `get_metadata` → `default.xex` @ `0x82000000`).
  Write that into `PROGRAM_GUIDE.md` §10 and `AGENTS.md` (attach-to-live-RPC, and *why*: `ida-bridge.py:25`
  `taskkill`s the other session), add `--attach` guidance to the `mcla-guest-raw-decode` skill, and get a
  rendered list of `renderdoc` only if a GPU question actually needs it. Gate: a doc line naming both
  methods and the kill hazard; one IDA `decompile_function` result quoted into an F-### entry.
- **T41.2 — finish the null-`this` proof before touching code.** Two checks: (i) does `:1986`
  `std r31,176(r1)` dominate `:2338` `ld r31,176(r1)` on the executed path (the other slot writers are
  `:1085` `stfs` and `:3351`)? (ii) bl-scan `generated/` + the raw image for callers of `0x822F3BD8`
  (IDA says `sub_823045E0+0x14` only — §10 says verify) and for `0x82131008` (IDA says none — a table
  entry at `0x82102AC0`). Gate: **F-060** written as FACT not INFERENCE, with the raw words or the
  generated line numbers for each step.
- **T41.3 — dispatch msg `0x40001503` (the singleton factory) the way the guest's own message system
  does.** *Re-scoped 22:40 by F-060: it was written as "give the boot gate its real arguments", and the
  gate's `r3` is not the null source.* The null `this` is `[0x8287E26C]`, published only by
  `sub_822F38C0`, which is a `(handler,msgid)` entry at `0x8210DA98` for message `0x40001503`; the
  faulting consumer is that table's entry for `0x40000B03`. Step 1 (in) = read the `MSGCHAIN` census
  rows in `build/w38n.log` to learn which of `sub_822F38C0` / `sub_823045E0` / `sub_822F3BD8` /
  `sub_823047D8` / `sub_822C2EA8` actually run and what `[0x8287E26C]` holds at each. Step 2 = find the
  dispatcher that reads the table region (`0x82102A00`+, ~19k entries — locate the walker by finding
  the `lis/addi` that materialises a table base, not by guessing). Step 3 = make the guest post the
  message through its own queue (`0x82849518` / prod `821BC868` / worker `821BC910` / exec `821BC140`)
  rather than hand-calling a handler. **Forbidden**: writing the object pointer into
  `[0x8287E26C]` from the host, arming `[0x8287E334]`, a vtable or `0xA00xxxxx` scratch to make the
  store land (do-not #9/#18/#19) — if the guest cannot create its own object, *that* is the finding.
  Gate: `MSGCHAIN creator-822F38C0 … RET [8287E26C]!=00000000` in a soak, `C0000005` → 0, and the
  gate's `BOOT-GATE-RETURN 82131008` line (`src/gpu_device.cpp:1211`, 0 occurrences today) appears.
  Baseline `build/w38m.log`.
- **T41.3a — DONE 23:25 (F-063).** `sub_821D3070`'s skip tested the caller's `r4` bit-15 flag; removing
  that clause made the `star_glow` shader allocate its 32 KB buffer and run the guest's own ctor.
- **T41.3b — NEW #1: the shader body the host serves for `star_glow.fxc` is a name list, and the
  guest fatals on it (F-064).** `sub_822FBAF8` reaches the `"draw_glow"` lookup and raises
  `'drawblit technique is old and busted, rename to blit_draw.'` (`w38s.log:3981`, `lr=0x82188770`),
  because `AFB76-FALLBACK` serves `buf=827D2DD0 size=5258` — the `SeedEmbeddedNameList` buffer
  (`PROGRAM_GUIDE` §8) — as the file's contents (`src/gpu_device.cpp:3409`, `:8355`, `:9203`).
  Step 1, **read-only**: census the guest's own `TOC76`/`TOC76-RET` for `fxl_final/star_glow.fxc` and
  find whether the `a:/archive/…` fallback of the session-78 cascade is reachable at all (F-034 says
  the non-archive Mount chain never runs). Do NOT grep the archive — its TOC is encrypted
  (`0xB116A6AB` @ 0x800, guest decrypts), so absence proves nothing. Step 2 depends on step 1: either
  wire the real RPF read (`src/fs/vfs_rpf.cpp:443-459` already exists) or record that the prototype's
  `fxl_final` is not in the retail content, which is a blocking finding, not a fix. Gate for either:
  `MSGBISECT 5-822FBAF8 RETURN` with `[8287E318]`/`[8287E334]` non-zero and that fatal gone.
  Do-not #3/#8 still apply (no dict pokes, no `byte_827D5C70`, hydrate stays until INSERT is clean).
  Baseline `build/w38s.log`.
- **T41.3c — re-arm a trigger for the forced gate, or delete it.** Since F-063, `FIX-821873E8` never
  fires, so `sub_82131008` is dispatched by nobody: `UILOAD 1 → 0`, and the 8 `GFx` lines that vanished
  were the host's own stand-in prints. Two honest options, one soak each: (a) dispatch the gate on
  msg `0x40003B03`'s real path (F-060(4), table `0x82102AC0`) — preferred; (b) delete the whole
  forced-gate + `GFX-BLOCK` stand-in (T38.3(e)) and let T41.6 own UILOAD. Do not "restore" the inline
  dispatch from `sub_821873E8` — that was the hijack F-063 names.
- **T40.5 — promoted onto the critical path by F-063.** The new parked fault has `ppc ctx=nil
  tag=none` and `rip owner=host … not a mapped guest fn`, so nothing in the dump can be attributed;
  printing `SymFromAddr`/`SymGetLineFromAddr64` of `g_report.faultHost` is the only way to name it.
- **T41.3d — DONE 23:49, built + soaked (F-067).** The `AFB76-FALLBACK` `star_glow` branch is deleted
  (`src/gpu_device.cpp:11174`, now a labelled `AFB76-MISS-HONEST` + the shared not-found return). Measured
  vs `w38s.log`: `C0000005` **2 → 0** (no AV in the soak at all), parked thread 1 → 0, `[error]` 51 → 41,
  `swfCMD` 0 → 2 (back to T38.4's stage), short-circuits +2. Its premise about the archive being the next
  stop was corrected by the same soak — see **T41.3e**; the next baseline is `build/w38t.log`.
- **T41.3e — RE-SCOPED 23:53 by F-068: the shader **preload lists** are undecipherable, so do not hunt for `star_glow`'s body. All six `*.list` bodies served in `w38t.log` have non-container heads (`shaders/effects/preload.list` `7590416E 03310845`), while 20 lines in the same soak carry the real XCompress magic `0FF512EF` and 387 `INFLATE`s run — and the `XSF-OPEN-GATE` step **forces bit 30 on the same TOC word the offset is taken from** (`00304E12 -> 40304E12`). First question: is bit 30 an encryption/format flag (F-068(3)); a correct `.list` body should be ASCII names. (Original framing, F-067(4):  The guest's terminal fatal on
  this path is its own: `'Unable to load shader '%s', it probably wasn't preloaded properly.'` with
  `r4 = 0x82040F0C = 'star_glow'`, after `GETDEV` returned **0** for
  `a:/archive/fxl_final/star_glow.fxc` while the identical mount answered `resources/ui/*.xsf`. So the
  question is what `shaders/effects/preload.list` (already served 8×) is parsed *into*, and whether
  `star_glow` is a listed member that the preload step failed to instantiate — a census of the
  preload-list parse (its entries, counts, and where they land), **not** a new file-serving path. Forbidden:
  re-adding the `rage_im` substitution, any new blob swap (F-064), stubbing the fatal (do-not #3), and
  arming `[0x8287E26C]`/`[0x8287E334]` by hand (do-not #9/#18/#19). Gate: `MSGBISECT 5-822FBAF8 RETURN`
  appears, **or** the fatal changes to a named, different cause — both vs baseline `build/w38t.log`.


- **T41.3e1 — DECODED TARGET, and one predicted no-op (added 21:01, F-070).** Do NOT delete the `isList`
  exclusion at `src/gpu_device.cpp:~517` as a fix: lists would fall back to
  `MclaPkgOffFromTocW2(w[2]) = 0x304000`, which lies in a gap and is rejected by `PKG-SUBST`'s own magic
  check ⇒ byte-identical result (F-070(4), stated so it can be falsified). Measured instead: the two
  sampled `.list` members both address the **2,661,399-byte gap `0xCFFE9..0x35A000`** (RSC5 packages
  cover only 70.6% of the archive), and 19/31 serves get a real container while the 12 that don't are
  exactly the 6 lists ×2. Next measurement is the guest's own fetch arithmetic: `sub_821BC380` /
  `sub_821BC940` (the `INFLATE` driver frames, `w38t.log:2231`), IDA via the live `:8745` RPC only.
- **T41.3e2 — DONE 21:11 (census added, soaked `w38u`/`w38v`, then reverted; F-072(4)/(5)).**
  Attribute the inflater hook before touching any serve path (added 21:06, F-071). The
  guest inflates its own archive members (`sub_821BC140` → device vtable `+28` with a 64-bit position at
  `[r1+80]` → `bl 0x821D5E10` at `lr=821BC374/821BC380`), so F-070(5)/F-069(3)'s "host must
  inflate-then-slice" is **void**. The host hook at `src/gpu_device.cpp:6789` instead rewrites the
  inflater's state through five stacked branches (`badMagic`/`stackWalk`/`j2NeedRepoint`/`stackPkgHead` +
  `REFORCE`, waves w20→w28, incl. a **planted 256-byte RSC5 head on the guest stack**) and is measurably
  live (`REFORCE` 32, `W27-XC-FULL` 5 in `w38t.log`). Step 1 is logging-only: put the path/`tocEntry` and
  the taken branch on the `INFLATE`/`REFORCE` lines, soak, and answer whether a `.list` read reaches the
  inflater at all. **Every non-inflate marker must be unchanged (logging-only) and `C0000005` must stay
  0** — that equality is the test that the census addition is inert. Do not delete or extend the branch
  stack on the way; it is the single funnel for all guest content and §7 registers none of it.
- **T41.3e3 — the follow-on T41.3e2's answer opened (21:18, F-072(4)/F-072(5)).** Branch flags recorded in
  F-072(4); the follow-on it enables is **T41.3e3**: the inflater's input is not a container in
  39/40 samples, T41.3e2 is DONE (census ran, block reverted; branch flags in F-072(4)). Next: trace *what the host is feeding `sub_821D5E10`* (the `XSF-HOSTSERVE`/gap path of
  F-070(2)) rather than the hook's branches — and per F-072, run a same-source control soak beside any
  change here, because the aggregate gauges cannot show the effect.
- **T41.3e4 — CLOSED 21:40, REFUTED BY TEST (F-075).** Built, soaked (`w38x`), compared marker-by-
  marker against `w38w`, and reverted. Serving the stored length changed nothing — and the test could
  not have worked: both readings seek to the *same* position, so only the length varied (F-075(3)).
  **Position, not length, is the open unknown.** Original premise, kept as trail: the preload lists are
  LZX and the host reads them at the wrong length (added 21:24, F-073). Decided offline: for a `.list` member, `w[1]` = expanded size, `w[3]&0xFFFF` = stored LZX
  length, `w[3]` bit 30 = "stored compressed" (six members, ratios 1.96-3.76, all in the
  `0xD0000..0x35A000` gap, no overlaps) — and the guest already owns the decoder
  (`XMemDecompress`, `sub_8244FF20`, codec LZX). Defect site: `src/gpu_device.cpp:500-506`, which serves
  `szs = w1` at the compressed position (over-reading 180 of 368 bytes there). Order matters: F-073(5)
  step 1 first (census: are the stored fields as (1) predicts, and is `sub_8244FF20` reached for a
  `.list`?), then step 2 (`szs = w3 & 0xFFFF` + stop `badMagic` implying "copy through"). Acceptance: a
  `GLOBTEX-BODY ascii=` that reads as a name list, then the `wasn't preloaded properly` fatal going away;
  **run a same-source control beside it** (F-072: the aggregate gauges cannot show this effect).

- **T41.3e5 — replace the TOC guesser with the recovered §5 layout (added 21:31, F-074).** The format
  reference is back in `docs/` (recovered from `82cb758`, deleted by `5fbc08e`), so
  `XsfOffsetCandidates`'s five-branch guessing over four dwords is no longer necessary: §5 defines a
  16-byte entry `{name_offset|flags, data_offset, file_size /*compressed*/, uncompressed}` with
  `data_offset` absolute, and §7 decides compression by **`file_size != uncompressed`** — true for all six
  `.list` members (F-073(1)). Two edits follow, in this order: (i) one census matching §5's field order
  against the guest's in-memory entry (`entry+8` currently holds `0x304E12`, which §5 would name
  `file_size`, so the mapping is NOT yet proven — F-074(6)); (ii) serve `file_size` stored bytes and let
  `sub_8244FF20`/LZX inflate, which requires the `badMagic` short-circuit at `src/gpu_device.cpp:6838-6841`
  to stop treating a headerless LZX member as already-inflated (§8 says a member has no `0FF512EF` at its
  start). Also fix the stale comment at `src/fs/vfs_rpf.h:16-18` ("STORED … no XMem LZX decode is needed")
  in the same change — it is the assumption that produced this bug class. Guest's decoder is proven good:
  `XMEM` 22x, all `ret=0` (`w38w.log`, session 75h). Same-source control run required (F-072).
- **T41.4 — DONE 23:00 (do-not #22).** `tools/soak_census.py` counts the exception-code markers
  (`C0000005`/`C0000003`/`C000001D`/`C000008E`/`80000003`/`406D1388`) only inside `code=0x…` context,
  because `80000003` had matched `CP-T3-CENSUS … args=80000003 …` and read as "a new VMX trap".
  Measured: `w38m.log` now reports that marker **0** (was 1) with every other row unchanged, and the
  F-040 ground truth still reproduces (`build/w38n.log` vs `build/smoke_long2.log` =
  `C0000005 1 ← 703`). The `mcla-log-census` skill still needs the same wording — fold it in with T41.1.
- **T41.5 — finish T38.3(d)(e)**: the `sub_821873E8` TLS-dead substitution and the `GFX-BLOCK`
  (`GFX-CTOR-VT-MISMATCH`, `W34-NOGFX`, `GFX-FACTORY-SKIP` — all still firing once each in `w38m.log`).
  Only after T41.3, so the census shows which one the guest now does for itself. Gate: their markers →
  0 while `UILOAD`/`GFx` do **not** drop (a drop means the stand-in was carrying them — that is F-051's
  test and it is a finding, not a failure).

- **T42.1 — name the TLS[12] producer dynamically (added 2026-09-20 23:25, F-062).** One logging-only
  change: set an x86 hardware watchpoint (DR0, `Dr7` local-execute/write) on the guest dword
  `TableBase + 12` = host `g_base + 0x8F20100C`, from the existing VEH in `src/boot_host.cpp`, and log
  the **guest PC + `lr` + value** of every writer (throttle to the first N, or it becomes F-054 poison).
  This is the cheapest thing that can end the 10-day `sub_821873E8` loop: it either names the guest
  function that installs the per-thread allocator — which is what T41.3/T41.3a are hand-standing-in for
  — or proves no guest code ever writes it, which is the finding F-060 was waiting for. It also answers
  an unmeasured question: does **any** thread besides the boot worker use TLS at all, given 25 sites
  share one `r13`. **Forbidden in the same soak:** any change to the *value* at `tlsTable + 12`
  (including the existing `src/gpu_device.cpp:1071-1090` fabrication) — a writer and a substituted
  value in one log is unattributable. Gate: `TLSW-#` lines in a soak vs baseline `build/w38q.log`, and
  the writer's `file:line` in `generated/` resolved by rule 3. If instead it prints 0 writers, that is
  F-063, not a failure.
- **T42.2 — the follow-on, only after T42.1 shows a producer:** route guest threads through
  `src/kernel/guest_thread.cpp`'s real per-thread TLS block instead of the shared fabricated
  `0x8F200000` one (roadmap B5 / PCR-TLS parity), and delete the `tlsTable + 12` substitution. Do not
  start it on F-062's structural observation alone — rule 1.

**Stage 2 — authored pixels on screen (the first real thing a player sees).**

- **T41.6 — Wave A (was T37.4): the guest builds its own GFx loader.** The acceptance signal is
  `sub_82482F78` (the guest movie-ctor wrapper) going from **0** to ≥1 occurrence — F-044's proof that
  no guest loader exists today. Then `UILOAD-enter` must get a matching `UILOAD-ret`, and the SWF tag
  walk (T38.4, `swfCMD::Fixup - unknown type 0xB7` at `lr=8260A8CC`) must be answered as a data
  question first. Gate: menu/legal screen package parsed; no new `[error]` class.
- **T41.7 — decide and record which draw path is canonical, then implement only that one.** Two
  independent routes to a pixel exist and both are short: (a) the **API boundary** —
  `sub_8217A470 → sub_8241BE78 → sub_8241C308 → sub_82420BA8`, which already enqueues
  `RenderCommand::DRAW_INDEXED` (`src/gpu_device.cpp:1793-1803`) and is starved because the chain never
  runs; (b) the **PM4/CP route** — 24 decoded `PM4_DRAW_INDX_2` submissions with no Xenos register
  file behind them (T40.6 step 3). `PROGRAM_GUIDE.md` §1 states the project's own architecture as
  "intent is captured at the draw boundary … **no Xenos CP emulation**", which is (a). Write the
  decision into §1 with the evidence either way, and if (b) wins, say what changed. Gate: a dated
  decision block, and only one of the two becomes the queue's #1.
- **T41.8 — Wave B (was T37.5): a real framebuffer.** Fix the two known `src/render_thread.cpp`
  defects first — Present's HRESULT is never checked anywhere, and `:572-574` clears *after*
  `DrawDynamicMesh` inside the same `BeginFrame` (F-057(4)) — then detile/PSO so `PRESENT-FB sample`
  stops being the `0.06,0.10,0.22` override. Gate: `PRESENT-FB` samples vary, and a pixel capture of
  the live window (`build/cap.ps1`) is not one flat colour for 10 s.
- **T41.9 — T40.2: delete the remaining fatal absorbers** once pixels exist —
  `tools/mitigation_audit.py` currently reports 81 mitigation-shaped labels vs §7's 13 registered.
  Gate: §7 and `src/` agree, each deletion cited.

**Stage 3 — a game you can actually play (each wave gated on the one above).**

- **T41.10 — Wave D input (was T37.7).** `XamInputGetState`: fix **T39.7(2)** first — the live
  dead-hook (`patches.cpp:827-853` replaces the import so the compile-time
  `GUEST_FUNCTION_HOOK` at `imports.cpp:3537` never runs, and it synthesises `r3=0` without chaining).
  Then SDL3→XINPUT mapping. Gate: `XINPUT-STATE` overlay lines and the menu cursor moves on a dpad.
- **T41.11 — Wave E audio (was T37.8).** Census the 0-returning audio stubs, confirm the audlo TOC
  `.xma`, drive `XAudio2SubmitRenderDriverFrame` from an SDL3 callback (silence-stub first, XMA later).
  Gate: non-zero audio samples submitted, no crash, `timeout 120` soak survives.
- **T41.12 — Wave F world (was T37.9).** Post-UI streaming census (retail `xarchive_cache.rpf` only),
  INLINE-EXEC payloads (XCompress + raw), then vehicle/camera/HUD and a free-roam spawn. Gate: car
  spawns, camera follows, 60 s with no fatal.
- **T41.13 — Wave G polish (was T37.10 + `CODE_OPTIMIZATION_PLAN` items 3-4).** Dtor-poison AVs, log
  floods (`WAIT`/`WAKE` are 51 % of `w38m.log`), frame pacing, `.bik` skip, save/load.

**Stage 4 — the housekeeping that keeps the next session honest (do a slice of this every session).**

- **T41.14 — T37.2/T37.3/T39.3/T39.4/T39.6 as one hygiene pass:** W36+W37+W38 ledger rows, the root
  junk (all of `11`, `err.txt`, `NUL.obj`, `crash_dump.txt`, `crash_log_early.txt`, `fix_stubs_*.py`,
  `write_opt_plan.bat`, both `GITHUB_APPEAL_*.txt` — **gone from disk**, but **not all in `bc4b489`**:
  that commit moved only the two scripts; see T39.3 for the per-file commits, and note two of the
  deletions are still uncommitted working-tree removals. The `tools/fix_stubs_*` citation is **fixed**),
  and `addr_owners --check` written into rule 4 or deleted as
  a claim. Ask before deleting user files. **Two items on this list are VOID, do not action them:
  `mcla_jts_regen.toml` is the live regen config (`tools/fix_stubs_iter.py:20` reads it), and "root
  `CODE_OPTIMIZATION_PLAN.md`" was never junk — see §8 item 3.**
  > **[2026-10-01] provenance note.** This bullet was **rewritten in place** (not superseded by a new
  > block) by the 2026-09-28 session. What it overwrote: the original item, which listed the same root
  > junk **as work still to do**, marked the two `GITHUB_APPEAL_*.txt` deletions "that are **not** this
  > line's work", listed `mcla_jts_regen.toml` and root `CODE_OPTIMIZATION_PLAN.md` as junk, and asked
  > for the `tools/fix_stubs_*` citation fix. Verdict: a **legitimate dated current-state update**, not
  > a covert overwrite — but the prior text is no longer in this file. Recover it with
  > `git show HEAD:docs/LONG_TODO_MASTER.md` and search for `T41.14`; **do not** `git checkout` this
  > file, the working tree carries the whole 2026-09-30 ledger era.
- **T41.15 — F-059's open question: what are those 24 point draws.** Answer from `0x21 REG_RMW` +
  `0x2B IM_LOAD_IMMEDIATE` decode (register writes → `VGT_*`/`RB_*`), not from more draw logging. Only
  after T41.7 picks a path; if the answer is (a), this item closes as void.

- **[2026-10-08] REGISTERED: the 16 KiB floor question (F-792 §3's unregistered lead, HANDOFF §18.2) = `T43.16`** — operative row and full spec in **§6's T43 queue table**. One line: is `kPhysSlabGranule = 0x4000` (`heap.cpp:3237`) the guest's slab truth, or a host over-charge costing ≈125 MiB of the 512 MiB pool? That row's gate is now **DISCHARGED** (measured 2026-10-22, recorded in the `T43.16` row itself): the 16 KiB floor was already scoped and now costs 10.97 MiB = 2.14 % of the pool, and it is **REFUTED** as the exhaustion cause -- F-792's "+125 MiB" was a stale `w756` number. The pool's real consumers are the 299.52 MiB never-freed boot block, a 46.52 MiB sibling, and the host's own XSF per-serve physical allocation; see the `T43.16` row for the numbers and the F-856 ledger entry.

## Older queue (still in force where not superseded above)

**T38.0 — kill the VEH RIP-advance runaway, then root-cause the one genuine AV.**
**STATUS 17:45: step 1-2 + acceptance DONE** (removed in `5eb9932`; `w37a.log` `C0000005` = 1 vs
baseline 703, recovery lines 0 — F-040). **Steps 3-4 are still open** and are now T38.2/T38.3; the
step-3 address and callee claims below were **wrong** — see F-043 (the global is `0x82839F68`, the
`0x82859F68` here is a `lis` sign-extension slip, and "vtable+4 = `rage::fiDevice::open`" is not
supported by the raw words).

*Mechanism (verified from `smoke_long2.log` + `src/boot_host.cpp:1011-1039`, not inferred):*
the handler buckets faults by **guest** `lr` and escalates `Rip += 16` (#1) → `Rip += 64` (#2) →
"clean return via `[rsp]`" (#3+) → **`Rip += 4096`** (when the stack slot reads 0). Because the
guest `lr` is frozen at `822FBC28` while the **host** RIP runs away, all 703 faults attribute to one
site and the logged `addr` is the walking RIP, not a data pointer:
`0x3f83a000 → 0x3f920000 → 0x3fab0000 → 0x3fab3000`, exactly +0x1000 per fault, 16:48:43 → 16:49:37
(**53 s of the 120 s soak spent executing unallocated host memory**). The `s_inUILoad` branch at
`:1000` is worse: `Rip += 256MB`.

*Consequence:* the boot-worker thread never returns to guest code after its first AV. It is dead for
the rest of the soak, which is the simplest sufficient explanation for the whole downstream
starvation in the same log — `GFx` 0, `FACTORY` 0, `DRAW_INDEXED` 0, `DRAWDISP` 0, and the CP ring
frozen at `put=11 rptrWB=0000 wb@C71D81BC=00000000` (guest published work, no consumer left).
**So the soak currently measures nothing past 16:48:43.** Do not tune the CP, the GPU or GFx against
it.

*This violates the project's own rules* — rule 1 (no short-circuit without root cause) and
`PLAN_VMX128.md` R5 (never "fix" a trap by skipping the instruction: it leaves stale state and
*looks like progress*). It is a mitigation that destroyed the signal it was guarding.

Steps, in order:
1. Regenerate `build/cache/mcla_pe.bin` with one `timeout 20` boot (rule 3 is dead without it).
2. Make the handler **diagnostic before it is permissive**: on the first fault at an unroot-caused
   `lr`, log guest PC/lr/r3-r12, host RIP, fault addr, and read-vs-execute (`ExceptionInformation[0]`),
   then **park**. Delete `Rip += 16/64/4096` and `Rip += 256MB`. Parking is honest; advancing RIP
   fabricates execution.
3. New soak `w38a`. Read the *single* genuine first fault. Known shape of the site
   (`ppc_recomp.49.cpp:21103-21125`, inside `__imp__sub_822FBAF8`): `r3 = *(u32*)0x82859F68`
   (global object ptr) → `r9 = *r3` (vtable) → `r8 = vtable[+4]` → `mtctr/bctrl`, with
   `r4 = 0x82040F0C` (a name string) and `r31 = 0x82040F0C`. **vtable+4 is `rage::fiDevice::open`**
   per the durable-facts table ⇒ decode the name at `0x82040F0C` (offset `0x40F0C`) and identify the
   callee; the AV is *inside* that callee, and `lr` here is a genuine return address (not sticky-LR,
   since the fault is in the callee body, not after a memset/leaf).
   **(19:25 correction, F-046/F-049 — do not act on the last clause.)** Global is
   `0x82839F68` (shader/preload-list manager singleton, *not* `rage::fiDevice` — its vtable
   `0x8200AE8C` is followed by `"preload.list file missing in '%s'"`/`".shader"`/`".fx"`), the name
   decodes to **`"star_glow"`**, and the "genuine `lr`" claim is **false**: the dumped `lr`/GPRs come
   from the boot worker's root `PPCContext` while the fault is in the gate's unpublished `g`, which is
   precisely why T38.2b exists. Step 2 also under-delivered: `Rip += 256MB` and the `0xC3` patches are
   still live (`src/boot_host.cpp:1003`, `:1040`, `:982`, `:1027`) → they belong to T38.3.
4. Audit the **two other stacked mitigations in this same module** before adding anything (rule 4,
   one owner per address): `boot_host.cpp:971-994` permanently disables `sub_822FA958` and
   runtime-patches its host entry to `0xC3` (RET) when `glr == 0x822F44E0`; and `src/gpu_cp.cpp`
   `:903/:917/:962` re-publishes the CP watermark to unpark the `rptrWB` poll. If step 3's real fix
   makes any of these unnecessary, delete it in the same commit.
5. Acceptance: `grep -c C0000005` on the new soak is **≤ 3** (was 703); no `addr` sequence walking in
   +0x1000 steps; and at least one of `GFx|FACTORY|DRAW_INDEXED|DRAWDISP` becomes non-zero **or**
   `rptrWB` moves off `0000`. If instead a *new* terminal fault appears, that is the real frontier —
   write it up as an F-### entry, do not paper over it.

**T38.1 — GFx loader vtable mismatch. DONE 17:57 — the premise was FALSE; see F-044.**
*What the census found (all raw-image, `mcla-guest-raw-decode` arithmetic, no rebuild):* steps 1-2 ran
and (i) `0x8206DFAC` has one producer in the image (`sub_82482008`, stored at `[arg+0]` by
`stw r9,0(r3)` @ `0x82482020`), (ii) the loader ctor `sub_824C6F08` writes the expected
`0x820736DC`/`0x820736B0` correctly with `this` in **r3** (`mr r31,r3` @ `0x824C6F1C`) and then calls
`sub_82482008` twice, which legitimately re-types the slots — so the host's `GFX-CTOR-VT-MISMATCH`
gate (`src/gpu_device.cpp:1156`) is a mid-vs-post construction comparison and is **worthless as a
defect signal**, (iii) step 3's question ("is `CA71D480` guest-allocated?") answers itself the other
way: it is `mem.Alloc(1024)` from the host, and the guest's own ctor wrapper `sub_82482F78` never
runs (`w37a.log` count **0**), so no guest loader exists to find.
*Deferred, deliberately not done:* the gate's wording and the `GFX-BLOCK` fabrication are handled at
**T38.3** (catalogue or delete), and the `W34` scan predicate must NOT be widened to accept
`0x8206Dxxx` — that would invent loaders out of sub-object memory (do-not #15).
**Follow-on work this spawned → T38.2b (#1) and T38.3.**

**T38.2 — DONE 19:20 → F-046 + F-049, and its own premise was wrong twice over.** (i) `ctr`, `xer`,
`r11` and `r14`-`r31` are **not members of `PPCContext`** — `src/ppc_config.h:5,9,10` make them C++
locals inside each generated function, so no VEH handler can ever print them (14 build errors, not an
opinion). The substitute that worked was identity-testing `Param[1]` against
`PPC_LOOKUP_FUNC(base, y)` for the candidate `y`s already in the struct — three added lines at
`src/boot_host.cpp:736-760` + `:861-890`, and `w38b.log:4023` answered it: the index was **0**.
(ii) The "32-bit truncation" framing above is **void**: with `g_base=0x100000000` the sum is correct
64-bit arithmetic that wraps *below* the window because `(uint32)(0 − 0x82130000) * 2` sign-extends
(host `rcx=0xFFFFFFFEFBDA0000`), and `0x7E780000 + 2y` equals `Param[1]` only at `y = 0`.
(iii) The dump's `lr`/GPRs are the **root** boot context (`g_faultCtx = &ctx`,
`src/boot_host.cpp:706`), not the faulting one — see §0 and F-046(3).

**T38.2b — *was* #1, now CLOSED (see the 19:50 block below). Make the crash dump name the faulting
*context*, then attribute the null call.**
Logging/publishing only, no behaviour change, one soak (`w38c.log`). The gate driver calls every guest
stage on a stack-local `PPCContext g{}` (`src/gpu_device.cpp:1121-1127`, stages `:1187-1236`) that is
never published, so `g_faultCtx` and `SetPPCContext`/`g_ppcContext` (`src/boot_host.cpp:701-706`) both
point at the wrong object whenever the fault is gate-driven — which F-046 says it is. Do the cheapest
of these: set `g_faultCtx = &g` (and the TLS `g_ppcContext`) around the forced stage calls and restore
on exit, or stop using a synthetic context and run the stages on the caller's `ctx`. Print one more
line naming which context the dump came from, so a future reader cannot confuse them.
**Gate:** the AV line's GPR set must *move* (different `r1`) and the `probe` block must then match one
of the dumped candidates; only after that, name the site — candidates are the **five**
`PPC_CALL_INDIRECT_FUNC(ctr.u32)` returns in `sub_822FBAF8` (`0x822FBB20/BC28/BC60/BD78/BDA4`,
`generated/ppc_xenon/ppc_recomp.49.cpp:20945-21334`) plus every other unguarded indirect site
(`dispatch_guard.cpp:36-37` covers exactly **one** guest address, `0x8218CC94`). Write the answer as
**F-050**. **Do not** arm `0x82839F68`, a vtable slot or a call target to make the AV disappear —
F-046(c): the AV is inside our own mitigation, and T38.3 may delete the whole gate driver, in which
case this fault is expected to go away with it (rule 1, do-not #9).

**T38.2b — CLOSED 19:50 → F-052** (census of the live session's `build/w38c.log`, 19:39, 9,726 lines, vs
`w38b.log`). **The gate above is met**: `r1` moved `8EFFF920`→`8EFFF7C0`, the fault `lr` moved
`822FBC28`→**`8230436C`**, `C0000005` stayed **1**, `VEH` 2→**1** (only the honest
`VEH-NEUTRAL … declining`), and the probe still names guest target **0**
(`w38c.log:4090`, `:4092-4096`, `:4113`). The frame names itself:
`generated/ppc_xenon/ppc_recomp.50.cpp:5642` sets `ctx.lr = 0x8230436C` immediately before
`PPC_CALL_INDIRECT_FUNC(ctr.u32)` in `__imp__sub_82304348` (`:5615`), and `sub_82304348` has **0 owners**
in `src/`+`config/`. **Causal answer: `src/gpu_device.cpp:1203-1206` calls that guest function from the
host-forced gate on the value-initialised `PPCContext g{}` (`:1123`) and `freshVolatiles()`
(`:1193-1196`) clears only `r5`-`r10`, never `r3`/`r4` — so `this` is 0, three pointer-chasing loads get
laundered to 0 by `ReadGuestU32` (`src/guest_memory.h:82-86`), `ctr` becomes 0 and the AV is the call
through it.** `:1236-1239` already skips `sub_82304398` for exactly this reason, so the rule was known
and this is the site where it was missed; `sub_823043F8` (`:1198-1201`) has the same shape. ⇒ **The
last residual crash is a host-fabricated call, not lost guest progress.** Do NOT arm
`0x82839F68`/`0x82830ACC`/a vtable slot (do-not #9). Next action = **T38.3(e)**: delete the gate driver
and the `GFX-BLOCK`, which F-051 shows is provably safe for the (a)(b)(c) paths (0 fires in both honest
soaks). → **F-050 written 19:55** (the reserved causal summary): gate verdict met, and it adds the
host-offset trap below plus the `0x82839D70` singleton census of the block that trap points at.

**T38.3 — audit the remaining stacked mitigations in the crash/TLS path (rule 4, do-not #9).**
> **STATUS 2026-09-20 20:40 — (a)(b)(c) DONE (deleted, not documented; F-055), (e) PARTIAL.** The three
> crash-path recoveries are gone from `src/boot_host.cpp` (verified by census: all their markers 0 in
> `w38f.log` while `C0000005` stays 1), and the forced driver's stages 1/2/6 (`sub_823043F8`,
> `sub_82304348`, `sub_821FC008`) are deleted because the driver's own flag-seed tells the guest to
> skip them. **Still open: (d) the `sub_821873E8` TLS-dead branch, (e) the `GFX-BLOCK` (left in place
> this soak deliberately, so the UILOAD delta stays attributable to the stage deletions), and the
> `[0x8288E6F0]=1` / `[0x82830B14]=0` / `[0x82830ACC]=0` seeds themselves** (`src/gpu_device.cpp:1101-1113`)
> — see new **#1 = T38.3f** below. Do not add new mitigations meanwhile.

**T38.3f — NEW #1: stop seeding the gate's flags and let `sub_82131008` run its own init (the
remainder of T38.3(e): the whole forced driver is a stand-in).** The residual AV is now one specific
host-visible fact: a **write to guest `0xE0`** at `lr=822F44E0`, i.e. inside
`0x822F44DC bl 0x822FA958` — the 22-instruction `sub_822FA958` leaf that chases
`[0x8288E334]` (image bss 0; no producer `stw …,0xE334(…)`, negative-scanned across
`0x82130000`–`0x82800000`). F-055 §1-§2. Acceptance: delete the three flag-seeds plus the remaining
forced stages, so `sub_82131008` is entered once with a real `r1`/`r13` and its own branches decide
what runs; then census `UILOAD-enter`/`-ret`, `C0000005` and the CP ring against `w38f.log`. Do **not**
hand-write `[0x8288E334]`, `[0x8288B9AC]` or any vtable to make the store land (do-not #9/#18/#19) —
if the guest cannot build the allocator table itself, the finding is *that*, and it is worth more than
a passing store.
> **STATUS 2026-09-20 21:30 — DONE, and its own premise is refuted (F-056).** The six seed writes are
> deleted (the `src/gpu_device.cpp:1101-1113` block is now a read-only `GATE-FLAG-READ` census) and
> `sub_82131008` is entered once on a 4 KB reserve with `g.lr = ctx.lr`. Soak `build/w38g.log`
> (11,298 lines, `BOOT_RC=124`) vs `w38f.log`: `C0000005` **1 → 1** at the *same* instruction, so the
> flags were never the cause. Two of this task's own facts were wrong: the address is
> **`0x8287E334`** (`lwz r11,-7372(r11)` — sign extension), and the fault is not in the leaf at all but
> in the caller — `generated/ppc_xenon/ppc_recomp.49.cpp:2660-2661 stvx128 v33,r31,r7`, translator-local
> `r31 = 0`, an unchecked raw store, with `lr=822F44E0` sticky. The gate driver itself remains a
> stand-in (T38.3(d)/(e) still open). Queue continues at **T40.1**.

**T40.1 — VOID, DO NOT IMPLEMENT (F-058).** Its premise came from the 22-agent sweep and it does not
survive checking: `MclaPreferredPkgOffForPath` and `MclaPkgOffFromTocW2` **agree** wherever the log
exposes a comparison (`meshtextures.xtd`, `w38j.log` `READWRAP-SERVE #1 … r5=40060000` →
`& 0x00FFF000 = 0x60000`, exactly what `src/gpu_device.cpp:291` returns), both call sites already fall
back to the TOC (`:534`, `:9549-9551`), and the hard-code is a documented decision because the
TOC-derived `.xsf`/`.xtd` bodies are AES ciphertext (`:521-523`). The text below is kept as the trail of
what the sweep claimed. **What is actually open here is a census question:** is the ciphertext claim
true, and if so which of the 6 served UI files get plaintext vs ciphertext?
> ~~`MclaPreferredPkgOffForPath` (`src/gpu_device.cpp:285-296`) returns hard-coded `0xA0000` for
> `.xsf`/`.xtd`/`resources/ui` and `0x60000` for `meshtextures`, bypassing the TOC-derived
> `MclaPkgOffFromTocW2` (`:272-282`); every served UI package is therefore read from the wrong window
> even though 12 of them open and are served (F-057(5)).~~ ← retracted by F-058; the count was 6, and
> the offsets agree.

**T40.2 — delete the remaining fatal absorbers** (rule 1, do-not #9; F-047's 81-label debt). Only
after T40.6, so the delta is attributable. Acceptance: each deleted site's marker → 0 while
`C0000005` and `Fatal error` counts are reported, not hidden.

**T40.3 — DONE 21:45, built and soaked (F-058).** `PhysToKernelVA` is applied to `listPtr` at both
sites (`src/gpu_cp.cpp:454`, `:666`). Measured: the eight IB packets went from `TYPE0 base=000` (zeros)
to real register offsets (`A31/A2F/D02/A02/1DD/1DC/5C8/D04`, `w38j.log:858-872`) and three nested IBs are
now reached (`:873-875`). **Its own acceptance criterion is NOT met** — `DRAW_INDEXED` stayed **0** —
because the diagnosis was one layer short: the missing layer is packet *handlers*, not addressing. That
is T40.6.

**T40.4 — DONE 21:45, built and soaked (F-058).** `CpPrimaryWritebackVA()` (`src/gpu_cp.cpp:986`)
replaces both hard-coded addresses in the waiter census (`src/kernel/imports.cpp:2112-2222`), and
`tools/soak_census.py` gained `dead_tracked()`/`marker_tokens()` and lost its
`rptrWB → "no CP consumer"` verdict for a `CP truth drains=… pub=… put=…` line. Measured on `w38j`:
`drains=8 last_rptr=001F pub=11 put=11 (caught up)`, 4 markers flagged as unexplained.

**T40.6 — NEW #1: implement the draw packets (this IS T37.6 Wave C — do not open a second draw task).**
The CP now parses real streams but handles only Type-3 `0x3F INDIRECT_BUFFER`, `0x3D MEM_WRITE`,
`0x48 ME_INIT` and the host-invented `0x64` (`src/gpu_cp.cpp:361-363`, `:43`). The draws live in
**`0x22 PM4_DRAW_INDX`** and `0x36 PM4_DRAW_INDX_2` (`.research/xenia/src/xenia/gpu/xenos.h:1600-1601`),
neither of which exists here; the only Type-3 the soak actually hits is `0x3C WAIT_REG_MEM`
(`w38j.log`, logged once as unimplemented). Order of work: (1) census every Type-3 opcode + its arg
dwords that the newly-real IB streams contain, so the handler is written against observed packets and
not invented ones; (2) the Type-0/Type-2 register writes into RT/shader state; (3) `DRAW_INDX` → the
existing `DRAW_INDEXED` path. Constraint that has bitten before: **no invented draw data** — a census
hook logs, it does not synthesise (AGENTS.md, non-negotiables). Acceptance: `DRAW_INDEXED > 0` in 120 s
vs baseline `build/w38j.log`.
> **STATUS 2026-09-20 22:12 — steps (1) and (2) DONE; step (3) is the whole remaining task (F-059).**
> The census replaced a logger that collapsed every opcode `>= 0x20` into one line, and it named 13 real
> opcodes (`build/w38k.log`). `DRAW_INDX`/`DRAW_INDX_2` now decode, and `build/w38m.log` shows **24 real
> `PM4_DRAW_INDX_2` submissions** (`CP-DRAW #1…#24`, all `kAutoIndex`/`kPointList`/`numIdx=1`, filling a
> 48-dword nested IB exactly — the misaligned-walk alternative was tested and refuted). `DRAW_INDEXED` is
> still **0** because there is no Xenos register file behind them, so step (3) is now specifically
> `0x21 REG_RMW` + `0x2B IM_LOAD_IMMEDIATE` + the Type-0 register writes into VB/IB/shader state; the
> secondary question is what those 24 point draws actually are. **Baseline for the next soak is
> `build/w38m.log`, not `w38j`.**

**T40.5 — make the crash dump name its own store.** Print `report.faultBytes` plus
`SymFromAddr`/`SymGetLineFromAddr64` of `g_report.faultHost` (`src/boot_host.cpp:615-618`, `:641+`) so
the soak prints the `base + (…)` form directly instead of reconstructing it from registers (F-056's
closing note). Acceptance: next soak prints that line and `rva=0x14D774A` is unchanged.


**Old T38.3 text (the original enumeration, kept for the (d)/(e) items still open):**
Three are live and none is in `PROGRAM_GUIDE.md` §7's table: (a) `boot_host.cpp` ~`:932-951`
float-div-0 at `lr=0x82133440` → writes `0xC3` (RET) over the **host entry of `sub_823D91F8`** and
parks the thread forever; (b) `~:971-994` `isKnownCrashSite` → sets `s_skipSub822FA958` and writes
`0xC3` over `sub_822FA958`'s host entry; (c) `~:960-1003` illegal-instruction / `s_inUILoad`
`Rip += 256MB` "nuclear advance". Plus two **fabrications** to catalogue (F-044/F-045 corrected both
against the earlier "shape bug" theory): (d) the `sub_821873E8` TLS-dead branch
(`gpu_device.cpp:1035-1101`) builds a 16-byte allocator object + vtable and stores
`__xtl_alloc` at `vtable+8` — the **shape is right** (guest reads `[obj+0]` then `[vt+8]`, F-045),
so this one is a *substitution*, not a defect; keep or delete on evidence, not on suspicion.
(e) the `GFX-BLOCK` at `gpu_device.cpp:1131-1165` — host `Alloc(1024)` + zero-fill + forced
`sub_824C6F08` + a vtable expectation that the ctor itself overwrites (F-044): it produces no guest
loader and no UI, and its `GFX-CTOR-VT-MISMATCH` line should be deleted or downgraded so it stops
being read as a blocker. Gate: each one either deleted (because T38.2 removed the need) or
documented in §7 as a named mitigation with its evidence line. Do not add new ones meanwhile.

**T38.4 — `swfCMD::Fixup - unknown type 0xB7`.** Pre-existing (F-042: identical in
`smoke_blue2.log:11129,11143`), fires at `lr=0x8260A8CC` with `r4=0xB7 r5=B7B6D9B4` and is absorbed
by the host `FATAL-SOFT-RESOURCE-PARK` (another §7-uncatalogued mitigation). `0x8260A830` is the
"Invalid fixup" walker (F-036) and the preceding census line is
`P9-B588 #00003 node=B7B6D9B4 type=B7`. Steps: enumerate which SWF tag types the walker handles vs
the `type=` values the place-walk actually feeds it, from the raw image — this is a **C/E-class data
question** (wrong container bytes) before it is a code question. Gate: a table of observed `type=`
values with counts, then a decision. Only after T38.1 (same thread, different symptom).

**T38.5 — CP consumer `rptrWB=0000` / `put=11`.** **DEFER — do not tune the CP, GPU or GFx against
a soak whose boot-worker thread died at the AV** (F-040 says everything past the fault is the GPU
poller tick, F-030). Re-read only after T38.1 and T38.2 land; if `rptrWB` is still `0000` with the
boot worker alive, `src/gpu_cp.cpp:903/:917/:962` (re-publish watermark to unpark the poll) is the
next thing to audit — that is mitigation (d) of the §7 table and it must be proven unnecessary.

**T39.1 — land the agent tooling and put it in force.** `AGENTS.md`, `.qoder/settings.json`
(project MCP: `ida-pro` via `~/.local/share/mcp/ida-bridge.py`, `renderdoc` via
`python -m renderdoc_mcp`) and `.qoder/skills/{mcla-boot-cycle,mcla-guest-raw-decode,mcla-log-census,
mcla-finding-ledger,mcla-recompiler-regen}/SKILL.md` exist on disk; skills are already auto-discovered.
Steps: run `/mcp reload` and accept the project-MCP trust prompt, then `qodercli mcp list` to
confirm both servers, then **verify `ida-pro` end to end** (it `taskkill`s `idalib-mcp.exe` and
re-opens `build/game_data/default.xex` — coordinate with any session already inside IDA, rule 11).
Gate: one real IDA query answered, one RenderDoc capture listed. Commit with
`git add AGENTS.md .qoder .gitignore docs/` (no `-A`).

**T39.2 — one source of truth for MCP config.** `opencode.json` (+ `.opencode/`, both gitignored)
declares the same two servers in a different schema; `.gitignore` also ignores `.mcp.json`, a file
Qoder does not read (don't create it). Decide the canonical one (suggested: `.qoder/settings.json`
for Qoder, `opencode.json` left for the other tool but cross-referenced from `AGENTS.md`) and add a
header comment to each pointing at the other so they cannot drift silently.

**T39.3 — root junk + citation fix. MOSTLY DISCHARGED — re-measured 2026-09-28 16:0x, attribution CORRECTED 2026-10-01 by `git`.** Commit `bc4b489` (2026-09-27 22:36:02 +0300, "Housekeeping: drop 0-byte root junk and relocate the stub-fix scripts to tools/") touched **exactly four paths**: `11` (0 B), `err.txt` (0 B), and the two renames `fix_stubs_iter.py` → `tools/fix_stubs_iter.py`, `fix_stubs_self.py` → `tools/fix_stubs_self.py` (`4 files changed, 0 insertions(+), 0 deletions(-)`). **The 2026-09-28 version of this paragraph wrongly credited that one commit with five more removals.** Corrected, per `git log --all --diff-filter=D --name-only`: `crash_dump.txt` was deleted by **`5fbc08e`** (2026-09-11, "remove docs, build artifacts, and AI tooling files"); `GITHUB_APPEAL_REPLY.txt` **and** `GITHUB_APPEAL_TEMPLATE.txt` were deleted by **`35912f0`** (2026-09-23, "checkpoint: preserve pre-merge E: state"). **`NUL.obj` and `crash_log_early.txt` have no deleting commit at all** — `git log --all --diff-filter=D` for either name is empty and neither is in `HEAD`'s tree, so they were **untracked** files and their removal is invisible to git. Only the two script moves are attributable to `bc4b489`, and those are the ones that discharge the "`PROGRAM_GUIDE.md` §5 cites `tools/fix_stubs_*.py` but the scripts sit at the repo root" defect — do not re-open it. Also note `write_opt_plan.bat` and `docs/f154_staged_be0c8_object_REJECTED.patch` are gone from disk but **still tracked in `HEAD`** and their removal is **uncommitted** (`git status --porcelain` = ` D` for both, added by `6b93978` / `b6528ad`) — they are deleted, not yet committed as deleted. **Not junk, do not
delete: `mcla_jts_regen.toml`** — it is the live jump-table regen config, cited 4x and read as
`BASE_CONFIG` by `tools/fix_stubs_iter.py:20`; the "obsolete span experiments" note above is stale.
**The "duplicate root `CODE_OPTIMIZATION_PLAN.md`" clause was FALSE and is retracted** — see §8 item 3.
`build/xr_spans|xr_iter|xr_self|xr_self2` scratch trees are likewise already gone.
Gate still open: `git status --porcelain` must show only real work (today it also shows 16 untracked
`tools/*` + `src/kernel/heap_arena.h` work-products from the live session), and every doc path citation
must resolve. **Ask before deleting** — these are user files, and `*.log` is evidence: 463 distinct
soak-log names are cited across `docs/` and back the whole F-### ledger, so **never bulk-prune
`build/*.log`**.

> **[2026-10-01] provenance note.** This paragraph was **rewritten in place** by the 2026-09-28
> session — it carries its own date ("re-measured 2026-09-28 16:0x") and it named the commit it acted on,
> so it is an attributed update rather than a silent overwrite. What it overwrote: the original `T39.3`
> task text, which listed all of that junk as **still untracked and NOT ignored**, called
> `mcla_jts_regen.toml` obsolete ("the stub work landed in `75ed486`, census is 0"), called the root
> `CODE_OPTIMIZATION_PLAN.md` a duplicate, and left the `tools/fix_stubs_*` citation defect open.
> **Verdict: legitimate current-state update, with two defects inside it — (a) the `bc4b489`
> attribution, corrected in place above on 2026-10-01 from `git log --diff-filter=D` (only `11`,
> `err.txt` and the two script moves are that commit's); (b) `write_opt_plan.bat` and the `f154`
> patch are gone from disk but still tracked in `HEAD`, so "deleted" ≠ "committed".** The 2026-09-28
> conclusions themselves stand. Nothing was reverted; the original wording is recoverable from
> `git show HEAD:docs/LONG_TODO_MASTER.md` (search `T39.3`) and is not duplicated here.

**T39.4 — docs consistency pass.** `docs/HANDOFF_NEXT_AGENT.md` LIVE block still says
"BUILD BROKEN; work T37.0 first" (17:12) — false since `5eb9932`; rewrite it to the §0 state and add
the W37a rows (reorg + VEH removal + this tooling pass). Also: the GFx vtable blocker existed only
in agent memory until 17:45 — memory is not the trail, so any frontier that matters must be in
`docs/` the same session it is learned (rule 10). Gate: a fresh session reading only `docs/` reaches
the same #1 blocker as this file.

**T39.5 — knowledge/wiki pre-flight config (optional, low priority).** `.qoder/repowiki/wiki_plan.yaml`
does not exist; the `qoder-context:qoder-context-knowledge-plan` skill can create it so generated
knowledge cards pin the canonical facts (image mapping, dict table `0x82839F70`, forbidden paths,
marker inventory) instead of re-deriving them from 11.5k-line files. Only worth doing once the tree
is stable — it re-generates on demand and stale cards are worse than none.

**T39.6 — register the three audit scripts, and make two of them commit gates.** *(added 2026-09-20
19:30, this session; `tools/` is tracked again since `5eb9932` closed the ignore hole.)* Built and
validated 18:53–19:01; **uncommitted**:
- `tools/soak_census.py` (9,488 B) — the executable form of the `mcla-log-census` skill. Counts
  matching LINES case-insensitively per marker, i.e. exactly `grep -ic`, over a 115-marker battery
  (`FRONTIER` + `VEH_PATHS` + the §7 short-circuit set + everything §9 names). Also splits guest `lr=`
  census into all-lines vs fault-lines-only, the CP-ring first/last `put=`/`rptrWB=`,
  `[error]`/`[warning]` levels, and prints a delta against a **named** baseline. Usage
  `python tools/soak_census.py build/w38c.log build/w38b.log`. Exit 0 always (informational).
  **Validated against hand-measured ground truth:** reproduces `C0000005` 703 → 1,
  `boot-worker AV` 703 → 0, `GFx` 7 → 9, `DRAW_INDEXED` 0 → 0, `put=11 rptrWB=0000`, short-circuit
  lines 784 → 166, and baseline **703 fault events / 1 distinct fault `lr`** (`822FBC28`).
  `VEH_PATHS` (added 19:40, F-051) gives each named crash-path mitigation its own row so a soak's VEH
  output can be classified honest-vs-laundering without reading `boot_host.cpp`.
- `tools/addr_owners.py` (22,630 B) — rule-4 machine: guest address → `file:line` → hook name, and
  flags multiple *claiming* owners. 678 sites / 409 claiming / 251 hex addresses + 207 named imports
  + 15 unaddressed bodies. `--check <addr|symbol>` for one site's owners (reverse cross-references
  the symbol too), `--gates <addr>` (added 20:10, F-053) dumps each claiming site's enclosing-function
  branch/return lines **verbatim and uninterpreted** — the tie is then broken by grepping the soak for
  the installer's own log line, never by guessing. `--all`, `--notes`, `--tsv`.
  **Exit 1 = violations**, so it can gate a commit. It prints no causal claim about *which* owner
  wins (the two it used to print were unverified and are gone), so every violation it reports still
  needs a human pass — currently 1 (`0x827BD6E4`), and F-053 is that pass for it.
- `tools/mitigation_audit.py` (10,422 B) — diffs §7 against `src/` (F-047's source). `--tiers`,
  `--label X`, `--comments`, `--limit`. **Exit 1 = findings.** Currently: STALE none, 69
  mitigation-shaped labels unregistered.
Work left: (1) `git add tools/soak_census.py tools/addr_owners.py tools/mitigation_audit.py` — named
paths only, never `-A`; (2) add them to `AGENTS.md`'s skills table (a "Project tools" row) and to
`PROGRAM_GUIDE` §3 so a fresh session finds them instead of re-writing a fourth census loop;
(3) decide whether `addr_owners.py --check` runs before any hook-adding commit — if yes it belongs in
§1's rule 4 text, if no do not pretend it is enforced.

**T39.7 — F-048 follow-ups (rule-4 real findings).** See `ROOT_CAUSE_VALIDATION.md` F-048.
(1) **Three owners of guest VdSwap** (`0x827BD6E4`) — **CLOSED 2026-09-20 20:10, and the premise was
FALSE: see F-053.** There is one owner *body* (`Hooked_VdSwap`, `native_renderer.cpp:162-182`) under
all three `renderer_mode`/`mcla_patch_groups` configurations; `native_renderer.cpp:254` is gated by
the early returns at `:191`/`:197`, which are complementary to `patches.cpp:676`, so the two runtime
installers cannot co-fire, and `imports.cpp:3469` forwards to the same body. Nothing to fix; the
queue item is deleted, not deferred. (2) below is the only surviving half of this task.
(2) **Live dead hook**: `patches.cpp:827-853` `hk_XamInputGetState` (installed by `SetFunction` at
`:516`) *replaces* the import, so the compile-time `GUEST_FUNCTION_HOOK` at `imports.cpp:3537` never
runs; it synthesizes `ctx.r3 = 0` + the StartPulse store and never chains — the same class the tree
already fixed once at `imports.cpp:3464-3467`. Remove the compile-time hook or chain it; 6 of the 8
import overlaps already chain correctly (`imports.cpp:899/:855/:867/:884/:321`, KDELAY-SC `:794-825`).
Only fires with the `in` bisect group on — verify group state in a soak before changing behaviour, and
add no new short-circuit while fixing it.
**Method note from (1), applies to every future overlap in the 8:** read the *enclosing function* of
each claim (`--gates`), then confirm against the soak which installer logged. `addr_owners.py`
deliberately does not decide reachability — see F-053's tooling bullet for why an under-reporting
analyzer was rejected.

**T37.0 — green build.** **DONE 2026-09-20 16:41** (verified §0: single `CpAdvanceGuestPublication`
definition at `gpu_cp.cpp:752`, exe mtime moved, `smoke_long2.log` taken after it). Kept for trail —
the original diagnosis was: TWO functions, `gpu_cp.h:83` (declared in `namespace mcla::gpu`) vs a
definition inside the **anon ns opened `:22`** (closed `:790`; `mcla::gpu` closes `:1728`). Anon-ns
member = separate entity visible throughout `mcla::gpu` → ambiguous at 4 sites outside the anon ns;
the `:576` call was inside it (innermost lookup, no error); `patches.cpp:237` already qualified.
Fix applied: move the definition out of the anon ns to `mcla::gpu` scope (helpers
`GuestPub`/`g_pubMutex`/`g_pubStates` stay anon). Do NOT just qualify call sites — that compiles then
link-errors (header fn left undefined).

**T37.1 — land reorg** as one commit `w37a: module reorg (...)`, no behavior changes mixed in. README/PROGRAM_GUIDE layout already updated 09-20 — verify, don't redo. Acceptance: build green from committed tree; status clean except logs.
> **SEQUENCING DECISION (17:05): do T37.1 BEFORE T38.0.** The dirty tree already mixes the module
> reorg (27 renames into `common/ cpu/ fs/ rage/ renderer/ tools/validators/`) with the T37.0 build
> fix and the doc compression. T38.0 edits `src/boot_host.cpp`, which is already modified — committing
> after that would entangle a behavior change into the reorg and break rule 10's auditability.
> Do **not** try to split the existing mix: the build is green *as it stands*, so land it as one
> commit titled `w37a: module reorg + T37.0 anon-ns build fix + doc compression` and say in the body
> that it is not purely moves. Remember `git add -f docs/` (`.gitignore:9`).
> Also fold in the two loose ends from `HANDOFF_SESSION78.md` §4: move `fix_stubs_iter.py` +
> `fix_stubs_self.py` from the repo root into `tools/` (decision: **move them**, and fix the
> `PROGRAM_GUIDE.md` §5 citation to match), and delete the root `CODE_OPTIMIZATION_PLAN.md` duplicate
> in favour of `docs/CODE_OPTIMIZATION_PLAN.md` (its Phase 0 is VOID per do-not #11). Root junk to
> drop in the same commit: `11` (0 B), `err.txt` (0 B), `NUL.obj` (3 MB build artifact).

**T37.2 — write W36 record** (from the 6 commit diffs + code): per commit list guest addresses owned, host files, new log markers, evidence lines. Output, in the compressed doc set: one row in the HANDOFF session ledger plus the W36 detail it links to, a row in `EXECUTION_PHASES.md`'s phase ledger, and F-040+ entries in `ROOT_CAUSE_VALIDATION.md` Part 3. Acceptance: an agent who never saw W36 can name every new address owner and marker from docs alone.

**T37.3 — re-baseline.** Boot ×2 ×120 s (`w37b`, `w37c`); count markers `UILOAD|GFx*|FACTORY*|NATIVE-PRESENT|FRAME-END|SUBMIT|DRAWDISP|DRAW_INDEXED|TOC76-RET|INFLATE|PKG-SUBST|PRESENT-FB|fatal`. **If UILOAD/GFx still 0: verify W36f claim at code level (marker gating? game-data condition?) before Wave A.** Record fork: (a) UI/GFx progressing → T37.4; (b) GPU/draw-starved → T37.5; (c) new crash family → census per rule 1 first.

**T37.4 — Wave A: UI/GFx → authored pixels.** Re-derive the job#2/swfC delivery state from code (W36 GFx path may have replaced the old PKG-SUBST host-serve — delete stale hooks if so, one owner per address). Acceptance: parse past legals (no font/fixup fatals), 0× CDCD at FDBF8 place-pass.

**T37.5 — Wave B: real framebuffer (M3).** F-B/F-C spec: census `EnqueueNativePresent` — dump `[obj..obj+0x30]` (24 BE words) for obj ∈ {C61D8818, C61D8928, C625894C}; one-hop follow words in 0x40000000–0xE0000000 (first 8 hits); decode `swap_info` 0x004E0D30; correlate TEXCREATE/EDRAM surfaces ≥1280×720 (3.5 MB @32bpp / 1.8 MB @16bpp); detile Xenos `7E`/`8E` → BGRA → `PresentBgra`. Never read EDRAM linear. Acceptance: PRESENT-FB samples vary plausibly; non-flat window 10+ s.

**T37.6 — Wave C: draws.** Verify PKT-CAP still Type-3=0; minimal GPU CP (RT, viewport/scissor, draw indexed); first visible = clear/spinner/legal quads. Acceptance: `DRAW_INDEXED > 0` in 120 s.

**T37.7 — Wave D: input** (`src/kernel/xam.cpp`): `XamInputGetState` (thunk detour failed historically — import-stub or non-hotpatch hook); SDL3→XINPUT map (dpad/stick=nav, A=accept, B=back; later triggers/sticks); `XINPUT-STATE` 1/s overlay. Acceptance: menu cursor moves.

**T37.8 — Wave E: audio** (`src/apu/`): census 0-returning stubs; confirm audlo TOC `.xma`; `XAudio2SubmitRenderDriverFrame` → SDL3 callback (silence-stub first, XMA decode later). Acceptance: any non-zero audio, no crash.

**T37.9 — Wave F: world.** Post-UI streaming census (retail only); INLINE-EXEC payloads (XCompress + raw); vehicle/camera/HUD; free-roam spawn. Acceptance: car spawns, camera follows, 60 s no fatal.

**T37.10 — Wave G: polish.** Dtor poison AVs; log-flood counters (KWFSO/PKT-CAP/PARK-SAMPLE); frame pacing; `.bik` skip flag; save/load.

## 3. File map (post-reorg; re-list before editing — hooks/ is in flight)

`src/` root: boot_host, main, app, patches (registry only), **gpu_device.cpp ~11.5k lines (monolith, being split)**, gpu_cp, gpu_mmio, d3d12_backend, native_renderer, render_thread, renderer_mode, guest_memory, dispatch_guard, early_init, capture_hooks, frame_trace · `src/hooks/`: PPC_FUNC bodies from patches.cpp, now absorbing gpu_device (alloc_census ~94 KB+, LIVE) · `src/common/`: logging.h, cvar.h · `src/cpu/`: vmx128_pack, guest_thread.h, ppc_context.h · `src/fs/`: vfs_rpf · `src/rage/`: rage_asset_pipeline · `src/kernel/`: imports (Nt*/Ke*/Xam*), memory, heap+o1heap, xam (input), xdm, guest_thread · `src/renderer/`: xenos decode, shader IR→DXIL, caches · `src/apu/`, `src/user/` · `tools/validators/`: phase-gate exes · `generated/ppc_xenon/`: 176 TUs, INPUT ONLY · `build/`: mcla.exe, logs, `cache/mcla_pe.bin`.


#### Merge 09-23 — C-side queue items restored from E:/mcla-c-snapshot-20260923

### T41.3g — gate the real `.list` server (was T41.3f; T41.3f is VOID as a no-op — F-077)
Gate `HostServeUiBody` (`src/gpu_device.cpp:568`) at its caller `XSF-POSTOPEN-SERVE` (`:10400`) and
`XSF-OPEN-GATE` (`:10353`) on the `*.list`/`preload`/`globaltex` predicate, and delete the ineffective
`:11030-11034` gate so exactly one mechanism serves list paths. Build + soak from **`C:\mcla-pc`**
(`build_on_c.bat`, then `timeout 120 ./build/mcla.exe > build/w41b.log`), baseline = **`w41a.log`**
(`C:\mcla-pcuild`), census = `python tools/soak_census.py build/w41b.log build/w41a.log`.


### T41.3h — remove both list-path stand-ins and read the real TOC entry layout (F-078)
`XSF-OPEN-GATE` (`src/gpu_device.cpp:10353`, ORs bit30 into `entry+8`) and the list branch of
`HostServeUiBody` (`:473-485`, T41.3g) contradict each other: the same dword is consumed as flags and as
the file offset. Delete/neutralise both, widen `TOC76-XSF` to 8 words with explicit `+0/+4/+8/+C` labels,
and compare one `.xsf` entry (known-good, RSC5 at `0xA0000`) against one `.list` entry. Build+soak from
`C:\mcla-pc` (`build_on_c.bat build`, then `timeout 120 ./build/mcla.exe > build/w41c.log`), baseline
**`w41b.log`**. Keep T41.3g in place until then — it is measured neutral and removes a false signal.

### T41.3i — census the read path on an open list handle (F-080); the open gate is void
Add read-only logging on the packfile size/Read chain for `*.list` handles (handle, requested offset,
requested size, bytes returned, and which branch produced them), rebuild and soak `w41e.log` from
`C:\mcla-pc`, baseline **`w41d.log`**. Decide from that whether the member region is compressed-but-present
(then decompress with the guest's own `sub_8244FF20`) or opaque (then it is a key problem, not an offset
problem, and the queue must move to T40.6 step 3 — the Xenos register file — where `DRAW_INDEXED=0`
actually is). Stand-ins already removed on this tree, each measured behaviour-neutral: the `rage_im`
substitution for `star_glow` (T41.3d), the host serve of `*.list` bodies (T41.3g), the bit-30 open-gate
write (F-080). New baseline chain: `w41a` → `w41b` (T41.3g) → `w41c` (layout dump) → `w41d` (gate deleted).


### T41.3j — name the fatal that now stops the boot (F-082) and clear it for real
`C0000005` is 0 on this tree, so stop treating the AV as the blocker: read the fatal line in
`C:\mcla-pcuild\w41i.log`, and if it is `drawblit technique is old and busted` then the remaining
work is supplying the real `star_glow`/rgxa body (T41.3d deleted the stand-in that faked it), not more
register work. Baseline = `w41i.log`.

### T41.3k — census the `fiDevice` list at `GETDEV #41-#43` (F-084 supersedes T41.3j)
> **CLOSED 2026-09-23 by measurement (F-089, T41.3m).** The array is exonerated: `arr=C60B4E00 cnt=1 cap=16` is byte-identical across all 41 logged lookups, `sub_821CB488`'s device `vtable+4` (`sub_821CDB88`) strips the 11-char mount prefix and tail-calls the archive TOC lookup, and `w42a.log:4414-4467` prints that lookup answering `ret=00000000` for all three star_glow paths, twice each. There is no registry defect here — the file is not in the archive the game mounted. Successor: **T41.3n**.

The shader fatal is `GETDEV` returning 0 for `a:/archive/fxl_final/star_glow.fxc` while the same array
serves `a:/archive/textures/...` — so log the device array (entries, prefix lengths, mount owner) at that
moment. Baseline = `w41i.log`, build/soak from `C:\mcla-pc`.
### T41.3l — remove `HydrateShaderHashTable` under measurement (F-085 §4, F-086 §2)

Delete `HydrateShaderHashTable` (`src/gpu_device.cpp:2054-2090`), its `s_factoryEntryPtrs` /
`s_factoryEntryCount` state, the collection block in `PPC_FUNC(sub_8218B000)` and the `if (n == 10)` trigger.
**Gate:** build from `C:\mcla-pc`, soak twice into new log names, and prove behaviour-neutral by diffing
`DICT-HYDRATE` (11 → 0, expected), `DICTLOOKUP` (0 → 0), `TEXDICT-CALLER` (10 → 10), `GETDEV`/`BDF20` counts
and the fatal block verbatim. If the fatal block changes in any way, **revert** — the removal is only justified
as neutral cleanup, not as a fix. Do not bundle into a T41.3k run.

### T41.3m — DONE (2026-09-23): uncap the archive census at the fatal's file → F-089 §4/§7
`star_glow` added to the `TOC76` `hot` gate + a new uncapped read-only `TOC76-SG` line in
`PPC_FUNC(sub_821CBFC0)`. Acceptance met: the six lines above exist, every gate marker is unchanged,
and the fatal block is verbatim.

### T41.3n — census the guest's own read of ONE preload-list body (F-089 §9)
No log in project history has printed a list body. Target `shaders/effects/preload.list`, whose decrypted
TOC entry is already in the baseline: `w41i.log:4405` `TOC76-LAYOUT #80 … +4=[00000170 00304E12 400000BC
…]` (stored/expanded sizes per F-073). Steps: (1) census the guest's read path on that open handle —
`RD-SUBMIT sub_8244F4C0` / `NFS-CENSUS[Read]` already show 32 KB reads at `off=0x300000`, so log the
buffer the guest ends up holding and whether ASCII names appear; (2) if ASCII names appear, count how many
`.fxc` names the list yields and re-run `TOC76-SG`-style uncapped lookups for those leaves to test whether
the shader bodies are in `xarchive_cache.rpf` at all; (3) if they are absent, stop and escalate the
content-policy question (which archive carries shader bodies — `AGENTS.md` permits only
`xarchive_cache.rpf` + audio/music and forbids `mc4/art`) rather than mounting forbidden art.
Baseline = `w42a.log`, build/soak from `C:\mcla-pc`. Gate: a list-body census line with ASCII names, or a
recorded negative **from an uncapped printer**.

### T41.3n2 — decompress one list member with the guest's own decoder, or prove it cannot (F-091 §1)
The bytes are in guest memory at `C6137A80`/`C6147B00`/`C6157B80`/`C6167C00` (32 KB pages read at the
member's `pos & ~0x7FFF`). Establish, log-only: (1) does the guest ever call `sub_8244FF20`
(`XMemDecompress`) with `srcSz` in the 126-460 range, i.e. a list member? If not, find the guest site that
*should* — `sub_821CCEA0`'s success path stores the entry at `dev+40+idx*68` and returns; the read submitter
is `sub_8244F4C0`, so the consumer of a completed read is the next caller of the entry handle: census the
`sub_821BE250`/`sub_821BE710`/`sub_821CC6F0` trio for a body/length pair and check whether any of them sees
the 32 KB page or only the `legals.xsf` substitute (T41.3o). (2) Only once a real member body is in hand,
test the LZX path by *reading* what the guest computes — never by inflating host-side and writing the
result (do-not #9; F-075's length-vs-position lesson). Baseline = `w44c.log`, build/soak from `C:\mcla-pc`.
**Gate:** a log line carrying `srcSz` in the member-size range and its destination, or a recorded negative
from an UNCAPPED printer.


## 4. Do-not (each cost ≥1 session; carry forward)

1. Edit `generated/`. 2. Regen without the reproducibility gate (`PLAN_VMX128.md` §4 Route B step 3; TU count must stay 176). 3. Poke shader dict / patch the fatal switch / stub fatals. **`byte_827D5C70` is F-013** (compile-time `0x01`, zero runtime writers — the ledger's `### F-013` heading) and **the symbol no longer exists in `src/` or `generated/`** (re-grepped 2026-10-01: 0 hits in both; the name now survives only in docs — `EXECUTION_PHASES.md`, `HANDOFF_NEXT_AGENT.md`, `PROGRAM_GUIDE.md`, ledger). Anchor on **F-013**, not on the name. 4. GETDEV-redirect (F-027). 5. Write `0xA00xxxxx` scratch from SeedPreBootSlots. 6. Treat `525DE064` as magic (stack residue). 7. Depend on `mc4/art`. 8. **Never re-add hash-table hydration (F-609); INSERT cleanliness is unproven.** The old wording here ("Remove hash-table hydration until INSERT proven clean") is **VOID — it is now the opposite instruction**: `HydrateShaderHashTable` was **REMOVED** (a `// REMOVED (2026-09-30) -- Stage C HydrateShaderHashTable, an F-609 NATIVE-ONLY violation` block in `src/gpu_device.cpp`; re-grepped 2026-10-01 — the symbol has **0** hits in `src/` and `generated/`, and the ledger records "`HydrateShaderHashTable` IS removed — and the removal has NEVER been exercised by a soak"). Cite the removal comment / ledger by **symbol**; the line numbers in both records have since drifted. 9. Stack short-circuits without root cause. 10. Leave mcla.exe running. 11. Follow root `CODE_OPTIMIZATION_PLAN.md` Phase 0 (edits generated/) — VOID by rule 2. 12. "Fix" VMX traps by skipping instructions (R5 — stale vectors). 13. Treat PresentKick r4 as framebuffer (F-B: swap-table timestamp slot). **F-B IS defined — it is not folklore:** the spec lives on the `T37.5 — Wave B: real framebuffer (M3). F-B/F-C spec:` entry in this file's *Older queue* (renumbered **`T41.8`** in §2). `HANDOFF_NEXT_AGENT.md` *uses* F-B ("F-B reproduced, no real pixels") but does not define it — so the definition anchor is the `T37.5` entry here, not the handoff. 14. Build caller chains from census `lr` after memset/leaf calls (sticky-LR; use xrefs + arg regs). 15. Write `0x820736DC`/`0x820736B0` into the fabricated loader after `sub_824C6F08` returns — that manufactures a loader out of sub-object memory (F-044). **Only this half of the old entry remains meaningful.** The other half — "widen the `W34` loader scan to accept `0x8206Dxxx` vtables" — is **VOID, and already satisfied in code**: the scan lives in `MclaW34GfxParseLever` (`src/gpu_device.cpp`, one call site; re-grepped 2026-10-01) and its band test is the source line `if (vpage != 0x82073000u && vpage != 0x8206D000u)` — it has accepted `0x8206Dxxx` since F-437, and its `W34-NOGFX` message already says "vt 0x82073xxx/0x8206Dxxx". **The old cite `src/gpu_device.cpp:5251-5254` is stale** — that range is now `XMEM-UIHEAD` surface-census `MCLA_LOG_WARN` argument formatting. Cite `MclaW34GfxParseLever` + the `vpage` compare, never a bare line number. 16. Trust a `lis`/`addi` decode produced by hand or by a scanner that breaks on the *second* of two consecutive `lis`s — the first version of the vtable-producer scan under-reported (`0x824C6F28` missed); re-run with a sliding register state (F-044 §2). The scanner that ships this property is **`tools/ppc_xrefs.py`**, whose module docstring names this very do-not and states the rule: "the second `lis` in a pair is a real hazard (do-not #16), so register state is tracked per-register across the scan instead of pairwise". Cite the docstring, not a bare line number. 17. Read a VEH crash dump's `lr` **or any GPR** as the faulting frame's until the dump's context is known to be the one that faulted — `g_faultCtx` is the boot worker's *root* `PPCContext`, while the forced gate runs stages on an unpublished local `g` (F-046: identical `lr`/`r3`/`r8`/`r9` 1.044 s apart). Also never try to add `ctr`/`xer`/`r11`/`r14`-`r31` to a dump: `ppc_config.h:5,6,9,10` make them host locals, so it cannot compile — that is four `#define`s, one per line: `PPC_CONFIG_CTR_AS_LOCAL`, `PPC_CONFIG_XER_AS_LOCAL`, `PPC_CONFIG_NON_ARGUMENT_AS_LOCAL`, `PPC_CONFIG_NON_VOLATILE_AS_LOCAL`. (The old cite `5,9,10` omitted line 6, i.e. **`xer`**.) 18. Read the `+0x…` in a `rip owner=guest 0xAAAAAAAA +0xBBBB` crash-dump line as a guest PC offset — it is `RtlLookupFunctionEntry`-relative **host code** bytes, so adding it to the guest address lands on a block that never executed (F-050: it pointed this session at `0x8230448C`, a second unrelated null-`bctrl`, while the real fault was the `bctrl` at `0x82304368`). Only the function half of that line is evidence. Fixed in text: the formatter is the `"guest 0x%08zX (host+0x%llX)"` `snprintf` inside `GuestFnAtHostAddr` (`src/boot_host.cpp`; re-grepped 2026-10-01) — **the old cite `src/boot_host.cpp:547` is stale, it now holds `int32_t g_hgDepth = 0;`**, an unrelated heap-guard counter. **Unexercised-in-soak, not unbuilt:** `build/w684.log` holds **0** `owner=guest` rip rows against **1** `owner=host` (11,860,787 B scanned), so the new format has never once appeared in a log. 19. Treat a crash-dump `rip owner=…` line as a *guest*-PC bound at all — `GuestFnAtHostAddr` answers from `RtlLookupFunctionEntry`, which returns the enclosing **unwind** entry, and the XenonRecomp output has one entry per recompiled function with no size bound that tracks the guest basic block. F-055 proved it: the printed owner named neither `sub_822F44DC` (the caller at the fault `lr`) nor `sub_822FA958` (the callee). Attribute a fault with `lr` + rule-3 raw words at `lr - 4`; use `rip owner` as a weak hint about which host region the RIP sits in. **[21:30 correction, F-056: the second half of that sentence is the useful one — in `w38g` the owner line named `sub_822F3BD8` and that *was* the function holding the faulting store; it was F-055's `lr`-based leaf inference that was wrong. So `rip owner` is a valid function-level hint and an invalid PC-level one; never let either alone override the generated-code line.]** 20. Read a census log field as the value of the thing it names — `WAIT[KWFSO] … rptrWB=0000` was a hard-coded **wrong address**, and **the anchor is now a FUNCTION, not a hex constant.** The poll reads whatever `CpPrimaryWritebackVA()` returns — defined in `src/gpu_cp.cpp`, declared in `src/gpu_cp.h`, called from the `WAIT[KWFSO]` poll in `src/kernel/imports.cpp`, whose correcting comment names both retired constants (`0xC71D81BC` is "4 bytes left of the real target"; `0xC701C4BC` is "unrelated"). Re-grepped 2026-10-01: **`C71D82BC` has 0 hits anywhere in `src/`**, and the old cites `imports.cpp:2117` (now a `C0000005` disassembly comment) and `gpu_cp.cpp:951` (now a `VertexFormat` bit-field comment) are both stale. Cite `CpPrimaryWritebackVA` — so "CP ring frozen / no consumer" was an artifact for many sessions while the ring was in fact draining (`w38g.log` 8 × `DRAIN`, `rptr→001F`, `pub==put`). Cross-check every pipeline field against the producer's own log line before claiming starvation (F-057(1)(2)). **Caveat on those tags: `F-057` resolves to NO ledger entry** — it falls inside the documented **`F-056…F-076` hole**, which the ledger itself still lists as unclosed ("20 ids, record surviving only as unnumbered prose"), and the neighbouring `F-058` is in the same hole. The only `F-057` citation in this file worth reading is the retraction line in the *Older queue*: "(F-057(5)) … ← retracted by F-058". 21. Read a colour in a `PRESENT-FB sample` line as guest pixels — the `0.06,0.10,0.22` triple is a **host** constant, not a guest read: it is the heartbeat default (`float cr = 0.06f, cg = 0.10f, cb = 0.22f;`) and the one-shot initial clear (`ClearAndPresent(0.06f, 0.10f, 0.22f, 1.0f)` at the top of the render thread's init path) in `src/render_thread.cpp`, both re-grepped 2026-10-01. So that triple means "no real guest pixels". **The old cite `render_thread.cpp:503-507` is stale** — it now holds `s_cpRefuseStateRefused` / F-652 census statics. **`F-610` changed the mechanism, not the rule:** the gradient *paint* is now behind the one-way latch `static std::atomic<bool> s_guestContentSeen`, set on the first successful `PRESENT-BLIT` and never cleared; once it is set the fallback only **clears** the measured colour and never paints, so a genuinely black frame and a failed read now stay visible. **But any row printed before the first successful blit still carries the synthetic triple**, and `F-610`'s removal trigger ("no soak ever hits `PRESENT-FB read failed` and `blitVA` is never 0 outside the heartbeat") is itself unmeasured — so the rule stands. Present success is still unmeasured — the HRESULT is never checked., and the on-screen dark blue is the host clear (`build/screen_shot.png`: `AVG_RGB=16,26,56`, 79/81 samples `0F1938`). Present success is unmeasured — the HRESULT is never checked (F-057(4)). 22. Read a bare-hex census marker as an event — `80000003` counted **+1** in `w38m.log` and reads as "a new VMX `debugtrap`", but its one occurrence is `CP-T3-CENSUS … args=80000003 071D82C0 DEADBEEF`, i.e. a **PM4 packet argument** (`w38m.log:3054`), while `debugtrap`/`illegal instruction` are both 0 there. Exception-code markers must be matched on exception-shaped lines only. Same class as #20, one layer further down (T41.4).

## 5. Done = playable loop

Legal/menu on screen → navigable → race/free-roam starts → controllable car, camera follows → audio present → 60 s soak no fatal.

## 6. W36 commit map (seeds T37.2)

`e46c386` queue trace 19 files +8.9k (task_dispatch_trace +913) · `f3bb765` gpu_device +52 census sub_8218A008 · `b6528ad` TLS allocator + VEH, dropped 461 MB generated/default blob · `e1a2435` boot gate (boot_host, gpu_device +100, imports) · `cc3a433` GFx vtable (gpu_device +41, CMake +1) · `8f07a39` game data + GFx factory; validators re-added (now moving to tools/validators).

## 7. Agent tooling map (added 2026-09-20 17:45; `AGENTS.md` is the auto-loaded summary)

| Layer | Where | Use for |
|---|---|---|
| Auto-loaded rules | `AGENTS.md` (repo root, tracked) | reading order, the 5 expensive rules, forbidden paths, conflict pointer |
| Workflow skills | `.qoder/skills/mcla-boot-cycle/` | build + kill + stale-exe check + soak into a new log |
| | `.qoder/skills/mcla-guest-raw-decode/` | raw word dumps, `lis` sign-extension trap, call-shape/`lr` attribution |
| | `.qoder/skills/mcla-log-census/` | case-insensitive marker counts vs a named baseline log |
| | `.qoder/skills/mcla-finding-ledger/` | writing F-### entries, doc-sync duties, mitigation labelling |
| | `.qoder/skills/mcla-recompiler-regen/` | Route A/B/C, reproducibility gate, TU-count/`ppc_recomp.10.cpp` invariants |
| Project MCP | `.qoder/settings.json` (tracked) | `ida-pro` (idalib on `build/game_data/default.xex`, RPC :8745 — it kills other idalib sessions), `renderdoc` (`python -m renderdoc_mcp` + `C:\Program Files\RenderDoc`) |
| Built-in MCP | connected already | `node-repl` (manifest TOML edits — never by hand), `browser-use`/`WebSearch` (Xenia/XenonRecomp semantics) |
| Not useful here | `sites`, `qmind`, `canvas`, `petdex`, `find-extensions` | skip; they cost turns and touch nothing in this project |

Skills are auto-discovered from `.qoder/skills/` (verified live 17:36). MCP needs one `/mcp reload`
plus the project-server trust prompt (T39.1).

## 8. Conflict register (audit 2026-09-20 17:45 — resolve via T39.x)

**Standing conflicts live in `AGENTS.md` "Known conflicts" — that is the maintained copy now (newer text: junk DISCHARGED 09-28, MCP servers +x64dbg). Update that one, not a duplicate here.** Retained below: the one adjudicated entry, then the conflicts registered 2026-10-01 by the audit campaign that AGENTS.md does not yet carry.

3. **NOT a duplicate — the old entry here was WRONG, corrected 2026-09-28.** Root
   `CODE_OPTIMIZATION_PLAN.md` is the live **coding policy (Ponytail+)** + MCLA guardrails, "still in
   force" (`:1-8`); `docs/CODE_OPTIMIZATION_PLAN.md` is the 2026-09-20 **compressed task-status** list,
   "Subordinate to `LONG_TODO_MASTER.md`" (`:1-4`) which **cites the root file's guardrails as "all in
   force"** (`docs/CODE_OPTIMIZATION_PLAN.md:22-23`). Complementary, not redundant: docs/ wins on task
   status, root wins on policy. The former "docs/ wins, delete the root duplicate, its Phase 0 is VOID"
   instruction was a misreading of do-not #11 and would have deleted a file a tracked doc cites — it
   propagated to `AGENTS.md` and T39.3 and is retracted in all three. The do-not #11 *rule* stands:
   never follow a Phase 0 that edits `generated/`.
   > **[2026-10-01] provenance note.** Item 3 was **rewritten in place** by the 2026-09-28 session,
   > self-dated and self-retracting. What it overwrote: the older register entry, which read "**Duplicate
   > plan file**: root `CODE_OPTIMIZATION_PLAN.md` vs `docs/CODE_OPTIMIZATION_PLAN.md`; docs/ wins,
   > root's Phase 0 is VOID (do-not #11). T39.3." — a **standing instruction to delete the root file**.
   > **Verdict: legitimate current-state update and a net safety gain** (it retracted a destructive
   > instruction and kept the do-not #11 *rule* alive), but it is an in-place rewrite, so the
   > superseded wording lives only in `git show HEAD:docs/LONG_TODO_MASTER.md` (§8 item 3). It was not
   > reverted.

**Registered 2026-10-01 (audit campaign, `docs/REPAIR_WORKLIST_2026-10-01.md`; fold into AGENTS.md or delete here when it does):**

10. **Three task queues** — this §2 (frozen at the 09-25/26 closures), the ledger's task-series (T41.59→T42.20 + "task #N", the operative one), and the archived scorecard's execution order (09-28 routing). Precedence: **ledger wins**; §2 kept for provenance.
11. **Next-free-ID** — the ledger footer's **F-729** (blocks F-697..F-719 at 12:38 and F-720..F-728 at 14:36, adjudicated by `### F-726`) supersedes HANDOFF §5's "F-697", which is now historical.
12. **HANDOFF trail relocated (10-01)** — blocks 2026-09-30 backward moved to `docs/archive/trail-handoff-2026-10.md`; the live file is 305 lines. Absolute line numbers into old HANDOFF text now resolve to the archive, not the live file.
13. **`docs/ref/xenos_registers.md` is cited by uncommitted `src/` while untracked** — commit both together or the citations dangle.
14. **RULE 0's own record re-audited (10-01)** — two of its glosses were withdrawn as incorrect (`0xC0006200`/BIN_SELECT; "empty buffer" vs F-685); three kills remain uncited as entries ("n=3"; "517 shaders"; 299.5→354 — recorded only in `src/kernel/heap.cpp:950-951` and `docs/PROGRAM_GUIDE.md:727`).

## 9. Deferred / parked (do not start without a state change)

- VMX128 Route B (94 type-5 `vupkd3d128` unpack sites, `0x822Fxxxx`) + the Clang-20 toolchain fix —
  parked per §0; the cluster is not reached and `0x80000003` count is 0. Re-open only if a soak logs
  a type-5 site or a `0x80000003`.
- `vupkd3d128` type-2 unpack (`0x821B43D8`), `vcmpbfp128` (`0x825CEA2C`) — `PLAN_VMX128.md` §2.3/§2.4.
- All of `docs/CODE_OPTIMIZATION_PLAN.md` (rule 9): gpu_device split into `src/hooks/` is in flight,
  PCH, log-flood throttling, unity build — re-measure the 19 s/1.6 GB/200 s/23.6 s baseline first.
- Waves D–G (input, audio, world, polish) = T37.7–T37.10; they are gated on T37.4/T37.5 pixels.

*2026-09-20 19:25. T38.1 CLOSED (F-044/F-045: the GFx vtable "mismatch" was a false gate) and
**T38.2 CLOSED** (F-046/F-049: the residual `0x7E780000` AV is a null indirect-call target inside the
host-forced BOOT-GATE, reached because `ReadGuestU32` returns 0 on invalid reads, and the crash dump
prints the *wrong* `PPCContext` — so no register in it is attributable). Next action: **T38.2b** —
publish the faulting context in the dump, one soak (`w38c.log`), then name the site → **F-050**.
Then **T38.3** (catalogue/delete the gate driver + the `GFX-BLOCK`; F-047 says 69 mitigations are
unregistered vs §7's 13) and **T39.4** (HANDOFF still says BUILD BROKEN). Rule-11 check before any
build; an `idalib-mcp.exe` was live at 19:08 — do not start the IDA bridge over it.*

*2026-09-20 19:32 (tooling session; adds to the 19:25 block, does not amend it). The three audit
scripts behind F-047 are built, validated against hand counts and **uncommitted** — see the new
**T39.6**. F-048 landed two real rule-4 findings (3 owners of VdSwap; 1 live dead hook) → new
**T39.7**; `0x822FBAF8` and `0x82839F68` are otherwise unclaimed in `src/`+`config/`, so T38.2b has
no owner collision to resolve. Note for whoever takes T38.2b: `mcla_pe.bin` is back
(`10,354,688 B`, 17:14) so rule-3 raw decode works, and the ledger footer is at **F-050+**.*

---

# 2026-10-06 — QUEUE AFTER THE BOOT BLOCKER WAS SOLVED

Superseding block. `HEAD = a9bd027`. Everything below is grounded in a measurement quoted from
`build/w734.log` or a tool run; nothing here is inferred. Rule 5 satisfied: this file was last
touched 2026-10-01, so a dated block is the correct form.

## 0. WHAT CHANGED, AND THE ONE NUMBER THAT PROVES IT

```
                             w733 (had a fatal)    w734 (no fatal)
Fatal error dispatcher                  1                  0
FATAL-SOFT                              1                  0
dstAfter=507B5CED  (DEFLATE head)       1                  0
dstAfter=61786772  (shader magic)       0                  1
ARC-WINDOW headIs=1  (byte-exact)       0                  1
WINWR-CMP beqTaken                      0                  1     r7 = r8 = 0x61786772
boot duration                  ~14 s to a fatal      149.811 s, no fatal
DRAW-CP-DRAWN                             -                  4      (was 2)
```

**The plateau is over.** 27 soaks died at 14.494-16.184 s. This one did not die.

**The cause, in one sentence:** `pos` is dword 1 of the reader object the caller passes as `r4` —
the guest's own byte cursor — and the file read it *after* `__imp__sub_821CC1E0` had advanced it
(raw `0x821CC3CC stw r11,4(r31)`), so every read observed the *previous* read's end position.
The file already snapshotted `r4`/`r5`/`r6` around that call and never extended the snapshot to
the two dwords it then read out of guest memory.

**The falsifier that refuted the alternative:** 18 rows, 18 different members, six different
archive offsets, `pos=4096` on every one and **never 8192**. An accumulating cursor cannot read
4096 on eighteen independent first pages.

## 1. TIER 1 — NOTHING AFTER THE BLOCKER HAS EVER BEEN EXERCISED

Ordered by distance from a menu. **None of these has happened once in the project's history.**

| # | item | current measurement | file |
|---|---|---|---|
| 1.1 | **`AUDIO-FRAME` = 0 real rows.** `apu::RegisterClient` = 0 corpus-wide, so the worker never spawns. The import **is** hooked; the guest never calls it. | 0 | `src/apu/audio.cpp` |
| 1.2 | **No XMA bitstream decoder.** `SetFrameDecoder` has **zero callers**. `xma_decoder.h:16-32`. | 0 callers | `src/apu/xma_decoder.h` |
| 1.3 | **No `0x7FEA0000` aperture.** | absent | `src/apu/*` |
| 1.4 | **`XMACreateContext`/`XMAReleaseContext` are silent stubs — `LOG_UTILITY` is `#if _DEBUG` and the build is `NDEBUG`.** **A census blind spot: some code is compiled out entirely in release.** | — | `src/kernel/xam.cpp` |
| 1.5 | **Input EXISTS and is unreachable.** `XamInputGetState` (`xam.cpp:941-1017`) is hooked, has SDL3 gamepads, keyboard fallback, XInput dead zones; `XamInputPoll()` runs every frame from `app.cpp:325` and publishes a live port map every boot. **0 non-NULL polls, ever.** | 0 | `src/kernel/xam.cpp` |
| 1.6 | **The menu has never been reached.** 0 evidence in 261 logs. `W34-NOGFX ngfx=0`, `W35-BOOT-GATE=0`. | 0 | — |
- **[2026-10-22] SUPERSEDES the measurement cell of §1 row 1.6 (F-860).** Row 1.6 still reads **"`W34-NOGFX ngfx=0`, `W35-BOOT-GATE=0`"**, and the second half is now FALSE: in `build/w874.log` `W35-BOOT-GATE` is **31 entry rows + 8 POST rows** (the entry printer is capped at `n<=32`, so the true count is >= 32) and the boot gate's callback **runs and returns**. The first half still holds: `nGfx=0` and `W34-NOGFX` = 3 rows. **The two unmet acceptance-gate items (`nGfx>0` and `W34-NOGFX`->0 vs `w230`) are the SAME wall, and the measurement says it is the HOST'S OWN SYNTHESIS, not the guest's walk**: `0xB7B41000` is host-synthesised (`RSC-ARR-CENSUS ... cls=zero` -> `EF100 #002 ... lr=00000000` (a HOST re-dispatch) -> `W30-DESTHEAD @B7B41000` (the HOST writes the vtable 0x82085364) -> `W30-ARR-NOKIDS obj=B7B41000 -- no already-written 8208xxxx children in PSTREAM/leads; leave arr untouched`), so the shell has `arr=0 / cnt=0` and no GFx loader object is ever constructed. **F-834's CITATION IS WRONG** (it cites `FDBF8-BUILD #002`, which is `obj=B5F67C00`; none of the 16 `FDBF8-BUILD` rows has `obj=B7B41000`). This also **contradicts §6 row :629's "not `B7B41000`" half** -- `B7B41000` is exactly where the host's synthesis produces the empty shell. Row 1.6's own text is left as written; this is the dated superseding block.
| 1.7 | **Only 2 presents, ever.** Gate is `frameNumber<=8` and the guest counter never leaves single digits, so **2 is the complete count.** | 2 | `src/native_renderer.cpp:335` |

## 2. TIER 2 — REGRESSIONS AND DORMANT DEFECTS FOUND 2026-10-05

| # | item | measurement | owner |
|---|---|---|---|
| 2.1 | **TOC WALK HAS NOT RUN IN 10 SOAKS.** `w722` = 1863 slices / 1862 dirs; `w723`-`w734` = **0**, including markers on the unconditional tail, so the function is **never entered**. Its one caller sits behind an early return. **Attribution is N-way and unresolved.** | 0 | `src/gpu_device.cpp:23619` / `:23492` |
| 2.2 | **`generated/ppc_xenon/` mis-emits `ori` immediate-form with SWAPPED operands.** Proven at two sites (`0x8218C848`→`ppc_recomp.9.cpp:18434-18435`; `0x8213DC98`→`ppc_recomp.1.cpp:16207-16028`) and **localised** — six of seven instructions in a window decode identically, only the `ori` diverges. **3,415 `ori`-imm emissions.** `generated/**` is forbidden (rule 2): **route through `.qoder/skills/mcla-recompiler-regen`.** | 2 sites / 3,415 | regen |
| 2.3 | **Regen is currently blocked:** `config/mcla_xenonrecomp_baseline.toml` is **32 lines vs the live config's 257**, missing all four `[[midasm_hook]]` blocks. SKILL.md §3 step 3 says STOP. **Refresh the baseline before any Route B.** | — | config |
| 2.4 | **The CP park never clears.** `PM4_WAIT_REG_MEM` demands `ref=0` while holding `4`; `CP-WAITREG-WRITER-VALUES distinct=2 refAmong=0` — **the demanded zero was never written by anyone.** | 1 park | `src/gpu_cp.cpp` |
| 2.5 | **`r8` at the fatal compare is still UNDECIDED — three agents decoded it three ways.** With `pos` fixed it no longer blocks the boot, but `generated/**` may still mis-emit the `ori` that feeds it. **Do not trust any of the three readings; measure.** | unresolved | regen |
| 2.6 | **`READWRAP-SERVE` = 0, `CD3C8-SERVE` = 0, `CC6F0-PKGSUBST` = 0, zero `key=flagWord` rows — that substitution block has NEVER executed.** `READWRAP`'s lookup at `:18887` passes **`tocEntry=0`**, the only argument reaching the table's only exact arm (`:3799-3804`); every other arm is log-only by design. | 0 | `src/gpu_device.cpp` |
| 2.7 | **The ledger's `file:line` anchors are 66.7% rotted** (18 of 27 adjudicable); named symbols drift a **median of 2,239 lines, max 11,020**; `mitigation_audit` drifted 105->108 shaped. **The reasoning is sound (88/92 mitigations still closed); the pointers are not. Re-point, do not re-derive.** | 66.7% | docs |
| 2.8 | **`BE710-DEAD` now fires (0 -> 4) with `outcome=REFUSE-NO-BODY`.** The refusal path is live and honest. **Watch it: if it climbs, that is a new wall, not a regression.** | 4 | `src/gpu_device.cpp` |
| 2.9 | **`BE8D8-PACK`'s `dst=BACA6280` is a write-only dead end** — 23,807 bytes of correct body into guest memory nothing reads. `slotIsBinding=0` on all rows. | 0 readers | `src/gpu_device.cpp` |

## 3. TIER 3 — THE PLATEAU STATISTICS WERE WRONG, AND THE TOOLS THAT FED THEM

| # | item | measurement |
|---|---|---|
| 3.1 | **"24 soaks, median 14.903 s, stdev 0.530" was computed over a set that was never verified.** 123 `w*.log` exist, only **43 are real soaks** (80 are 0-byte sidecars). The literal `'Unexpected EOF in fiBaseTokenizer::Pop'` is in **2 of 43**; **`w734.log` has 0** because the fatal changed identity. |
| 3.2 | **`TIMEOUT_SURVIVED` = 0 across 232 logs.** Not one log ever ended because the guest was still running. `soak_run.py`'s `process survived` line has been reporting success for ~135 s after every guest died. **It is not a pass condition.** |
| 3.3 | **`MEMBER-SPAN-TAIL-VETO` has 0 real rows and 33 prose mentions.** A naive count gives 33. `MEMBER-SPAN-ALIAS` is **not tracked**. |
| 3.4 | **Six+ harnesses passed while blind**, including one that reported **90.5% of something because it harvested English prose as data**, one that mis-tokenised `[14:08:06.052]` as a leading token, one whose replay used the *final* span table, and one that reported a confident **0** because `re.match` anchored at line start and every line begins with a tab. |
| 3.5 | **A harness served a body out of a zero page and reported fabricated bytes** while passing. **If any harness here told a host pointer from a guest VA by a size comparison, its green result is not evidence.** Audit before trusting. |
| 3.6 | **`git checkout <commit> -- src/gpu_device.cpp` does NOT restore a byte-exact pin** — `core.autocrlf=true`, the file is bare-LF, so a checkout converts line endings. **Verify reverts by content, not by hash.** |
| 3.7 | `soak_census.py` now has **240 markers**, own-row/line semantics, 63 self-test checks. **9 markers have a correct 0**: `slotcov=`, `nGfx`, `-GATE`, `skip fatal`, `rptrWB`, `PUT=`, `UILOAD`, `PRESENT-FB`, `GEN76-ALLOC/FREE`. `INFLATE-ENTER` is a strict prefix of `INFLATE-ENTER-SUMMARY`. `BE710-MAGIC` is a substring of `BE710-MAGIC-CENSUS`. `CP-T3-CENSUS` reads 2 when 1 real row exists. |

## 4. STANDING RULES LEARNED 2026-10-05 — DO NOT REDISCOVER THESE

- **Extract instruction fields nibble by nibble.** Shift-and-mask arithmetic produced **four** wrong answers in one session.
- **`ori`/`addi`/`addis`/`lwz`/`stw` destinations are `b25:21`. `or`/`and`/`xor`/`mr`/`cmp` destinations are `b20:16`.** **Both are right, for different opcodes. Never generalise one from the other.** *(This note was wrong twice before it was right; see `AGENTS.md`.)*
- **Establish the discriminating power of any control you rely on.** A control believed *powerless* was measured to discriminate five wrong-models; a control believed *sufficient* was symmetric and could never have found its bug.
- **A marker's own prose can contain other markers' literals.** `READAT-BRANCH`'s prose contains `raw_positional=1`. 25 of 39 miscounts were this.
- **A marker absent from `src/` has a zero that means nothing.** Prove the literal exists first.
- **`absent from src/` vs `comment-only` vs `dead`** are three different states; `soak_census.py` distinguishes them.
- **Never put a value in a census field that is a constant.** `WINWR-CMP` printed `kAoCmpR8`, a hardcoded literal, and that "measurement" was believed for an hour. Deleted 2026-10-05.
- **`CALLERS (none)` is an IDA carving artefact.** `tools/ppc_xrefs.py calls` reported 20 callers of `0x821BE250` where a raw scan finds **0** (vtable dispatch); its `->` column names the *enclosing* function.
- **`tools/ppc_disasm.py` is a PowerPC disassembler and CANNOT decode Xenos GPU microcode.** It also inverts `mr` and cannot decode `rldicl`. Use `generated/ppc_xenon/*.cpp` as the tiebreaker.
- **Never accept a fix on a marker count.** 9 fixes moved markers and not the boot. The measures that count: `headIs=1` byte-for-byte against a python-`zlib` oracle, `dstAfter=61786772`, `FATAL-SOFT=0`.

# 2026-10-06 22:3x — SUPERSEDING BLOCK: the physical-allocator refusal is FIXED (F-779), and the census that declared it neutral was wrong (F-780)

Superseding block. Rule 5 satisfied: this file was last touched 2026-10-05 23:47, so a dated block is the
correct form. `HEAD = 32127c2`; the working tree is **not committed** (11 paths differ, incl.
`src/kernel/o1heap.c` / `o1heap.h` / `heap.cpp`). Ledger top is now **F-780**, next free ID **F-781**.
Every number below was re-run against `build/w740.log`, `build/w741.log` and `build/w741b.log` in the
half-hour before this block was written; none is carried over from a summary.

## 5. WHAT CHANGED SINCE THE 2026-10-06 BLOCK ABOVE

`build/w741b.log` (300 s, `TIMEOUT`, 22:00:14→22:05:13) vs `build/w740.log` (300 s, 20:29:48→20:34:47),
`soak_census.py` → `DEPTH: 32,157 vs 31,381 lines = 1.02x -> COMPARABLE`, no `POISONED` verdict:

```
                                          w740        w741b
XTL-ALLOC-REFUSED                            4            0     << the fix
o1heap invariants FAIL (case-INsensitive)    4            0     << the fix; `grep -ac` scores 0 in BOTH
PHYS-STATE (own rows)                        0            1     << second, independent proof (see below)
capacity=0x1ffffdc0 / =0x20000000          45 / 0       0 / 46     the pool's modelled capacity
host short-circuit lines (mitigations)     2,043        2,047     +4 — MORE, not fewer
P5-PHYS / P5-MISSFIX / P5-LOOKUP           0/0/0        1/1/1     << NEW: see §5.2
F374-HEAPSTORE                              32           32     unchanged — the guest still writes there
DRAW_INDEXED / NATIVE-PRESENT / C0000005     0 / 2 / 5    0 / 2 / 5     frontier unchanged
Fatal error / FATAL-SOFT / 80000003          0 / 0 / 0    0 / 0 / 0
headIs=1 / dstAfter=61786772                 1 / 1        1 / 1     the two gates that matter
TOCWALK / SLICE / DIRS=                      0 / 1 / 0    0 / 1 / 0     item 2.1's regression: STILL DEAD
```

**5.1 The cause, in one sentence.** Both o1heap instances were placed *inside* their own arenas
(`o1heapInit(base,size)` puts the instance **at** `base` and the first fragment at `base + 0x240`), so the
guest's own 128-byte zeroing sweep at `0xA0400000` and `0x20000` was erasing our allocator's control
blocks; with `diagnostics.capacity` zeroed, `o1heapAllocate` computes `suitable_bins == 0` from
`nonempty_bin_mask == 0` and returns NULL for **every** size while `o1heapDoInvariantsHold` — which never
dereferences a fragment — still returns true. The fix detaches both instances into `VirtualAlloc`'d host
memory (`src/kernel/o1heap.c:363`, `:368`; `src/kernel/heap.cpp:2400-2407`, `:2419-2421`, `:2446-2448`),
**additively**: no statement of `o1heapInit`/`o1heapAllocate`/`o1heapFree`/`o1heapDoInvariantsHold` was
modified, so the "NOTHING ELSE HERE CHANGES" notes at `o1heap.c:569`/`:605` still hold and
`INSTANCE_SIZE_PADDED` is still `0x240` (`:181`), i.e. every hardcoded instance offset in the
instrumentation still means what it says.

**The controlled form of the proof** — both decisive rows carry the **same guest caller `glr=82137904`**,
so it is one allocation site with opposite outcomes:
`w740.log:31065` `[20:32:08.253] AllocPhysical: o1heap invariants FAIL #1 size=0x19d align=0x4000 cap=0 peak=0`
+ `:31068` `XTL-ALLOC-REFUSED #1 size=413 align=16 -> returned 0 (console value) … seen=3195 ok=3194 refused=1`
versus `w741b.log:31871` `[22:02:40.825] PHYS-STATE #1 size=0x41bd align=0x4000 o1_frag=0x8000 class_ok=1
opt_bin=9 … capacity=0x20000000 free=0x22f3000 verdict=healthy why=suitable_class_present split=exact …
oom=1 glr=82137904`. `PHYS-STATE` is a *second* independent proof because it is emitted at
`heap.cpp:3252`, **after** the invariant gate's early `return nullptr` at `:3121` (gate `:3096`), so under
the old layout it was structurally unreachable.

**5.2 What that fix EXPOSED, and why the next task is not the one you would guess.** The three `P5-*` rows
at `w741b` `22:00:29.492` = **+14.9 s** are one guest event: the place-pass in `sub_8260A830` asked the
guest rebase table about `r4=B6FB2F29` (`P5-LOOKUP` printer `src/task_dispatch_trace.cpp:569`), got
`FFFFFFFF`, reached the resource-group-miss→fatal tail `PPC_FUNC(sub_821D2378)` (`:579`), and the
`alreadyPhys` arm at **`:604-611`** did `ctx.r3.u32 = 0; return;` **instead of invoking the guest fatal**
(`b 821BD618`). `0xB6FB2F29` is **inside `[A0400000, C0400000)`** — the arena extent the
`PHYS-POOL phase=init` row at `w741b.log:49` prints for itself, as are `r3=BD40C000` and `desc=BD908000`.
**So the double-ownership that F-779 called "not measured either way" is measured: the guest asked its own
table about one of our physical addresses, missed, and only a w9-vintage host short-circuit stopped a
fatal.** Dormancy, measured over every log on disk: `P5-PHYS` = **14** in `w720`, **14** in `w722`, **0 in
all 18 of `w723`…`w740`**, **1** in `w741` and **1** in `w741b`. Rule 1a is satisfied (only
`heap.cpp`/`o1heap.h`/`o1heap.c` changed between the two exes), so F-779 may be named — **but no revert
run was done.**

> **⚠️ 2026-10-08 SUPERSESSION — F-793 REFUTES both load-bearing claims of 5.2 above.** Do not repeat "the guest asked its own table" or "the double-ownership … is measured" without reading `### F-793`. (a) The "guest rebase table" is **our own host-published mirror**: `REBASE-TABLE @BD40C000 n=7` (`w741b:11364`) prints `s_gRebaseTable` — allocated/filled by `MclaPublishGuestRebaseTable` (`gpu_device.cpp:7400-7419`) and installed as `[group+0]` by `MclaArmRebaseCtx` (`:7429-7430`) — and its 7 records are all 0x50/0x60 vbases, so a `0xB6……` key **structurally cannot hit**: the `FFFFFFFF` was guaranteed, not an accident of emptiness. (b) `0xB6FB2F29` was **never handed out by the arena** (nibble 9 ⇒ not 16-byte/`0x4000`-aligned; provenance = payload word[1] of buffer `B7981000`, `RSC-CHILD-DUMP w741b:11366`), so there was no ownership contest to measure: the row is our `FDBF8-ARR-RESTORE` (`gpu_device.cpp:16783-16822`) promoting payload into a pointer role, with our `P5-PHYS` (`task_dispatch_trace.cpp:604-611`) turning the guest's correct fatal (`sub_821D2378` → `b 821BD618`) into delta-0 ⇒ guest ctor `sub_8260B310+0x24` wrote vtable `0x82088784` into the payload address (`PAGEWATCH W #064`, `w741b:11385`). Dormant: `B6FB2F29` in 2/192 logs (w741/w741b only), 0 in w756. Full chain, the closed `lr` residue, and five falsifiers: **F-793**.

**That also splits item 2.1 in half.** `P5-PHYS` went silent at exactly the `w722 → w723` boundary item
2.1 names for the TOC walk, and came back — but `TOCWALK` (3,987 → 0), `DIRS=` (2 → 0) and `SLICE`
(3,727 → 1) are **still at their `w723` values in `w741b`**. So `w723` is **at least two independent
mechanisms**, and the one feeding `sub_821D2378` is downstream of the physical allocator, not of the TOC
walk. Item 2.1's "attribution is N-way and unresolved" is now too coarse; the TOC walk itself remains
unexplained.

**5.3 What is NOT fixed — do not let the zeros above be read as health.**
- **Exhaustion is live and separate.** `PHYS-STATE #1` at +146 s: `allocated=0x1dd0d000` (477 MiB) of
  `capacity=0x20000000` (512 MiB), `free=0x22f3000` (36 MiB), **`peak_req=0x12b84020` = 314 MiB in one
  request**, `oom=1`. Both soaks already show `allocated=0x17465000` (390 MiB) at **+1.4 s**.
  **`XTL-ALLOC-REFUSED = 0` must NOT be read as "the pool is sufficient"** — the refusal that was removed
  was a destroyed-header refusal (`cap=0`), not an exhaustion one.
- **`F374-HEAPSTORE` is still 32**, same relative times, same 16 distinct `caller_rva`s: the guest still
  zeroes 128 bytes at `0xA0400000` and `0x20000`. Only *what is there* changed.
- **FIVE log-only instruments are now STALE and will mislead** — they read the instance through a *guest*
  address (or through `g_hdrArena`) and now read arena/fragment data. Full citations, re-verified line by
  line, are in **F-779 §9** and in the `PROGRAM_GUIDE` §9 row added 2026-10-06; in short:
  `F373-HEAP-RAW` (printer `heap.cpp:1824-1828`, reads `:1810-1815`, and its `moved=` field at `:1826` is
  now unconditionally 1 — it compares a host pointer to a guest VA, so it can never be 0 again);
  **`F373-HEAP-GOLDEN`** (printer `:2809-2810`, read `:2804-2805` — the worst of the five, because its
  `cap=` stays correct while its `hex=` changes subject, so the F-100 golden reference now diffs a live
  header against arena bytes, which is worse than no reference); `F370-HEAP-HDR`'s **`hdr_off=`** field
  (printer `:1790-1797`, computed `:1794-1796` against `g_hdrArena = heapArenaBase` at `:2422`, decl
  `:447` — now a huge host-address difference, not an offset; its `cap=`/`want_cap=`/`oom=` are
  unaffected); the `boot_host.cpp:468` needle comment ("fragments start +0x240" — no longer true; the
  bucket logic is `:465-468`); and the watch windows at `guest_memory.cpp:60-61` and `:77-78`
  (`kHeapWindows[]` `:79-82`). **`F374-HEAPSTORE` rows after this fix are NOT a failure** — that window is
  now ordinary arena memory the guest is entitled to write. *(This bullet originally said "four" and cited
  `heap.cpp:1810-1815, :2755`: `:2755` is an unrelated comment about the HeapGuardWindow ordering rule,
  and the field at `:1794-1795` is `hdr_off=`, not `moved=`. Both re-measured for F-780.)* Retire or
  re-aim all five in a separate, log-only build — **T43.5**.
- **`PHYS-VERDICT-CHANGE`'s instrumentation-order defect is still NOT landed.** Gate `heap.cpp:3096` logs
  and does `return nullptr` at `:3121`, *before* `EmitPhysState` (`:3252`) and `NotePhysVerdict`
  (`:3255`), so the verdict row keeps its last healthy value exactly while the allocator refuses
  everything. F-779 made it moot for *this* failure; it would hide the next one identically.
- `AttachPhysicalArena` (`heap.cpp:2485-2490`) still rebinds to an **attached** instance. Dead code here;
  wiring it up without detaching reintroduces the collision.
- **Still no menu, still `DRAW_INDEXED` = 0, still 2 presents.** The CP park of item 2.4 is unchanged:
  `CP-WAITREG-TIMEOUT #1 … ref=00000000 … value=00000004 … timedOut=1 - PREDICATE FALSE` then
  `CP: RING A PARKED at rptr=0016 … parkEvents=2`, at **+14.8 s** in `w740` and **+16.0 s** in `w741b` —
  the demanded zero was written by nobody, exactly as item 2.4 records.

## 6. T43 QUEUE — T43.1…T43.8 are allocated HERE for the first time; only T43.9 was cited before this block existed (F-779's Task field), and it is the fix that landed

Ordered by distance to a menu. Each is its **own** build+soak (rule 1a); none may be bundled.

| # | item | why it is here | current measurement |
|---|---|---|---|
| **T43.1** | **Fix the `PHYS-VERDICT-CHANGE` call order** — move `EmitPhysState`/`NotePhysVerdict`/`NotePhysPoolFull` ahead of the invariant gate's `return nullptr` in `Heap::AllocPhysical` (`src/kernel/heap.cpp`; **the three line-number vintages cited for this one defect — `:3006`/`:3031`, `:3096`/`:3121`/`:3252`/`:3255`, `:3162`/`:3165` — are ALL stale now, see F-781 §9; cite the symbols**). `o1Amount` + `NotePhysAttempt()` hoisted above the gate so the gate arm reports the size o1heap actually classified. | log-only, but it is the instrument that would have to catch the *next* allocator failure, and today it cannot | ✅ **DONE AND PROVEN 2026-10-06 23:3x (F-781).** Build 25/25, 0 errors, exe moved 23:09:51 → 23:38:52. **Proven by a FORCED-GATE CONTROL, not a soak:** post-F-779 the gate is dormant (`invariants FAIL` = **0 rows** in `w742`, `w741b`, `w741`), so no normal run can reach the path. `MCLA_T43_FORCE_INV_GATE=1` ⇒ `build/w742ctl.log:210-215`: `invariants FAIL #1 … cap=536870912` → `PHYS-STATE #1` → `PHYS-VERDICT-CHANGE none -> healthy … refusals=1 req_amt=0x2e84020` (**nonzero `req_amt` ⇒ provably the alloc path**, the free path prints `0x0`) → `PHYS-POOL-FULL #1 … attempts=1 served=0 refused=1 … class_present=1`; second refusal `:298-300`. ⚠️ **`cap=536870912` is the control's signature — a real failure reads `cap=0` — so the control proves reachability/emission ONLY, never the `capacity_zero` classification.** No-regression `build/w742.log` (298 s, 31,097 lines, COMPARABLE 1.03x, no POISONED): every brief gate met — `invariants FAIL` 0=0, `headIs=1` 1=1, `dstAfter=61786772` 1=1, `DRAW_INDEXED` 0=0, `FATAL-SOFT` 0=0, `XTL-ALLOC-REFUSED` 0=0, `o1_cap_delta=0x240` 1=1, `C0000005` 5=5, `PRESENT` 49=49. Rule 1a: `heap.cpp` was the only code delta. Rule 1b: new symbols `kT43ForceInvGate` + `#include <cstdlib>`. 🔴 **SPAWNED T43.1b (F-782): the reordering does NOT make the verdict honest on the *exhaustion* path, because `EmitPhysState` faults inside `NotePhysLive` before returning.** |
| **T43.1b** | **Fix the `NotePhysLive` null-guard collision (F-782, spawned by T43.1).** `EmitPhysState` calls `NotePhysLive` unconditionally; that sweep did `std::memcpy(chunk, base + pos, n)` from `pos = 0`, and guest VA 0 is the deliberate `PAGE_NOACCESS` null guard — so it faulted on its first 1 MiB chunk in **every boot, deterministically**. Fix: name the guard (`kNullGuardBytes`, `src/kernel/memory.h`, replacing eight bare `4096` literals in `memory.cpp`) and start the sweep at `kPhysLiveStart = kNullGuardBytes` at all three cursor-zeroing sites in `heap.cpp` (the atomic's initialiser, the new-block reset, and the wrap). | **it blocks T43.2**: the fault lands *between* `EmitPhysState` and `NotePhysVerdict`/`NotePhysPoolFull`, so the exhaustion path still cannot report a verdict however T43.1 is ordered | ✅ **DONE AND VERIFIED 2026-10-07 00:0x (F-783).** Build 25/25, 0 errors, `mcla.exe` + `mcla.map` both moved to 23:38:52 (rule 12). `build/w743.log` = 31,280 lines / 5,159,095 B, 300 s, `23:39:15`→`23:44:15`, **TIMEOUT = survived**; `tools/soak_census.py build/w743.log build/w742.log` → **DEPTH 1.01x COMPARABLE, no POISONED**. **Gates met:** `PHYS-LIVE` **0 → 4** (`:30956/30962/30968/30974` — **the first rows in the instrument's life**, 0 in all 313 prior logs); `PHYS-POOL-FULL` **0 → 4** on a *natural* exhaustion (`cap_o1=0x20000000`, not `w742ctl`'s forced-gate `cap=536870912`); `PHYS-STATE` 1 → 4; **`host addr 0x100000000` 1 → 0**. **No regression:** `invariants FAIL` 0=0, `PHYS-LARGE` 63=63, `headIs=1` 1=1, `dstAfter=61786772` 1=1, `o1_cap_delta=0x240` 1=1, `DRAW_INDEXED` 0=0, `FATAL-SOFT`/`Fatal error`/`80000003` 0=0=0, `w743_err.log` byte-identical to `w742_err.log`. Rule 1a: three files, and the `memory.cpp` change is a **provably value-identical literal→constant substitution**, so the only behavioural variable is `kPhysLiveStart`. Rule 1b: new symbols **`kNullGuardBytes`** (`src/kernel/memory.h`) and **`kPhysLiveStart`** (`src/kernel/heap.cpp`). 🔴 **THE `C0000005` 5 → 4 GATE WRITTEN INTO THIS CELL WAS THE WRONG METRIC AND IS WITHDRAWN (F-783 §4).** Measured **5 = 5**: the count is conserved by SUBSTITUTION, because `VEH[3] (capped)` caps at three rows and the guest's own fault arrives 1 ms after ours stopped and takes the freed slot. **The discriminator is the fault ADDRESS, not the count.** Generalise: a total that counts events from two producers cannot be the acceptance test for removing one of them, and a capped printer hides the substitution. 🔴 **Two new defects this exposed, both queued as T43.1c and NOT fixed here** (fixing them in the same pass would have made `w743` differ from `w742` by two variables and destroyed the rule-1a attribution above). |
| **T43.1c** | **Take `NotePhysLive`'s cost off the allocation path, and re-aim its sweep (both measured in F-783 §7-§8, neither fixed there).** **(a) COST:** each emission `std::memcpy`s `kPhysLiveBudget` = **256 MiB** while `Heap::AllocPhysical` holds `std::lock_guard lock(physicalMutex)` — the source already says so in the comment above `sweep_ppm`'s definition. Measured in `build/w743.log:30954-30976`: refusals at `.779 → .821 → .861 → .903 → .945`, and **the guest's next call lands in the SAME millisecond as the preceding refusal's last row**, so the 40-42 ms gap is entirely our sweep (≈6.2 GB/s) — **~166 ms of injected latency across four refusals, with the guest blocked on the mutex.** **(b) AIM:** the sweep walks linearly from `kPhysLiveStart`, so its first 1 GiB covers guest VA `[0x1000, 0x40001000)` — **neither the guest image (`0x82000000+`) nor the physical arena** — while the block under test (`block_guest=A3A8C000`) is at **2.557 GiB = 63.9% = emission #11 of 16**. `sweep_ppm` reached only **250000 = 25%** with `complete=0 pass=0`. **So `guest_refs=0` is a statement about the sweep's aim, not about the block's liveness** (rule 19: an instrument whose positive result is unreachable in the run being read has not reported a negative). Fix (a) by dropping the budget to something defensible under a lock (or moving the sweep off the allocation path entirely); fix (b) by scanning `[0x80000000, 0xC0400000)` — or the block's own neighbourhood first — instead of from the guard. **Do both in ONE log-only change and re-measure the refusal timeline; a `PHYS-LIVE` row count is also a latency count, so never add rows without re-timing.** | log-only, but it is currently *perturbing* the thing it measures | ✅ **DONE 2026-10-08 (F-791)** — ONE log-only change (`src/kernel/heap.cpp`): budget 256→16 MiB, nine-region priority visit-order cursor (image first), `be()` byte-order fix, `ctl=` positive control, wrap-tally publish, registry arm via `MapVirtual`. **w756** re-timed as demanded: 254 rows = 254 refusals (row count held vs w755's 256, −2), era **10.934 s → 1.596 s** (42.9 → 6.3 ms mean gap), same `star_glow` terminus, 9.2 s earlier boot-relative; census exit 0 (**262 tracked = F-790's prediction**, DEPTH 1.78x COMPARABLE, no poisoned verdict), audit exit 1 baseline. **First positives ever:** `guest_refs=1 hit0=82830B54` (runtime image global naming the span), `reg_hit=2/4951`, `ctl=2` from row #1 (rule 19 discharged). Recorded gap: wrap `complete=1` arm unexercised — fatal at `sweep_ppm=992674`, 2 rows short of pass end. |
| **T43.2** | **Name the physical-pool exhaustion.** `peak_req=0x12b84020` = 314.06 MB (299.52 MiB) in one request against a 512 MiB pool, 390 MiB already allocated at +1.4 s. Find who asks, and whether the console's own pool is really 512 MiB for this title. **UNBLOCKED 2026-10-07 by F-783 — IT IS NO LONGER A HYPOTHESIS WAITING ON A FIX, IT IS A QUANTIFIED CONTRADICTION REPRODUCIBLE FOUR TIMES PER BOOT.** `build/w743.log:30955` reads `size=0x41bd align=0x4000 o1_frag=0x8000 class_ok=1 opt_bin=9 suitable=0x80000 smallest=0x80000 bin_mask=0x801c0 allocated=0x1dd08000 capacity=0x20000000 free=0x22f8000 free_ppm=68298 verdict=healthy why=suitable_class_present split=exact pfrag=0x5000 page_fits=1 pow2_fits=1` — computed, not eyeballed: `free` = 36,667,392 B = **34.97 MiB** = **1,119× the 32 KiB fragment the request needs**; `bin_mask=0x801c0` = bits **{6,7,8,19}**, so `opt_bin=9` is NOT in it and `suitable=0x80000=2^19` means the classifier's plan is *split a bin-19 (512 KiB) fragment down four halvings to bin 9*. **Every one of the model's own tests passes — `class_ok=1`, `page_fits=1`, `pow2_fits=1`, `split=exact`, `full=0`, `over_cap=0`, `over_frag=0`, `destroyed=0` — and `o1heapAllocate` returned null anyway.** So either `O1BinMask` misreads o1heap's internal bin state (bin 19 reported non-empty but not usable) or o1heap's split path has a guard the classifier does not model. **START HERE: `MmAllocatePhysicalMemoryEx +0x38`** (`caller_rva=0x2eb768` on all four `PHYS-LIVE` rows, resolved against `build/mcla.map` from the same build), guest `glr=821325D4` inside `sub_82132578`: **the third physical allocation of the boot** (`alloc_seq=3`) asked for `size=0x12b80000` = **314,048,512 B = 314.05 MB = 299.50 MiB**, got `block_guest=0xA3A8C000`, and per the row **was never freed** (`freed=0`, `big_freed=0`) while the host's own live-pointer registry holds **`reg_hit=0` of `reg_total=3236`** entries inside it. **`freed=0` and `reg_hit=0` are in direct tension, and unlike `guest_refs` the registry count is host-side and NOT subject to T43.1c's aim defect.** Third arm: `PHYS-VERDICT-CHANGE` stayed at **1 row** across all four refusals (`w743.log:802`, the *free* path, `req_amt=0x0`, `caller_rva=0x2d1793` = `DestroyKernelObject +0x133`, 2 m 17 s earlier) — **the classifier does not consider four consecutive refusals a state change, which is a modelling defect, not an ordering one.** ⚠️ **Do NOT read `max_refused=0x0` / `buckets=[all 0]` on the new rows as dead fields:** `NotePhysPoolFull`'s switch puts the histogram and `PhysPoolBumpMax` **only in the `Exhausted` arm**, and these refusals classify `Healthy`, whose own comment says *deliberately NOT bucketed* — that is F-643's arm working as written (F-783 §9). *Superseded trail — F-782 §11's two-armed statement of the same question, kept because it is where the arms were first named:* **F-782 §11 sharpens the question into two named arms:** on the very row where the allocation failed the classifier reports the pool healthy — `w742.log:30798` `returned null #1 size=0x19d o1_amount=0x41bd live=0x1dd08000 cap=0x20000000 oom=1` beside `:30799` `free=0x22f8000 free_ppm=68298 verdict=healthy why=suitable_class_present split=exact suitable=0x80000 cand_mask=0xfffffffffffffe00`. **34.97 MiB free against a 16.8 KB request (F-783 §13a: the `36.8 MiB` this cell said before was 36.7 *decimal* MB wearing a MiB label), and o1heap still returned null.** So either `ClassifyPhysPool`'s "suitable" is not what `o1heapAllocate` will split, or this is fragmentation and `healthy` is a category error. Reproducible across builds (`w741b.log:31870` = `live=0x1dd0d000 free=0x22f3000`). **INPUTS 2026-10-08 (F-790 + F-791 — start from these).** (i) *F-790:* the exhaustion is total and terminal — `XTL-ALLOC-REFUSED` even for 14-byte asks (sizes 144, 640, 128, 112, 14, 9520, 52, 112, `w755:18152-18418`), the refusal era runs uninterrupted from oom #1 (+10.1 s) to the fatal (+25.1 s), the fatal's own instance is `mem.Alloc(89,16)` → `STEP6-ALLOC` (`gpu_device.cpp:24077-24080`), and `content=NOT-CORROBORATED` is a vestigial constant (`gpu_device.cpp:24239` — prints an initialized local, zero information). (ii) *F-791:* the first guest word ever to name the block's span `[0xA3A8C000,0xB6611000)` sits at **VA `0x82830B54`** — runtime-written image .bss (file-at-rest `00 00 00 00`, past code end `0x827CD054`), `guest_refs=1 hit0=82830B54` on all 254 `w756` rows; `pool_refs=0` (the pool names nothing), `freed=0` both boots; registry arm now type-correct: **`reg_hit=2 reg_total=4951`** (2nd entry's identity open). Host `caller_rva` for `alloc_seq=3` is build-dependent — `0x2eb768` (w743) / `0x2f3398` (w755) / **`0x2f36a8` (w756)** — resolve ONLY against the map of the same build; guest `glr=821325D4` (inside `sub_82132578`) is build-stable. Size label (corrected 2026-10-08, F-792 §1): `0x12B80000` = 314,048,512 B = 314.05 MB = **299.50 MiB** (the earlier "313.75 MB = 299.2 MiB" in this cell was hand arithmetic, withdrawn — same trap as F-783 §13a). | `XTL-ALLOC-REFUSED = 0` now hides it; this is the next refusal waiting to happen | 🔴 **NOW UNBLOCKED AND REPRODUCIBLE 4× PER BOOT (F-783).** `w743.log:30954-30976`: `oom=1..4`, `free=0x22f8000` = 34.97 MiB at +140 s, **`verdict=healthy` on all four rows**, `attempts=3812..3815 served=3811 refused=1..4`, `peak_req=0x12b84020`. Entry point named: `MmAllocatePhysicalMemoryEx +0x38` / `alloc_seq=3` / 314 MiB / `block_guest=0xA3A8C000`. **✅ ANSWERED 2026-10-08 (F-792):** the asker is `sub_82131228`'s video-mode size helper `(r7−921600)×16 & 0xFFFF8000`, r7 ∈ `[0x1399000,0x1399800)` (writer of `*(0x82830CD4)` still unknown); the pool is the fixed `kConsolePhysicalBytes = 0x20000000u`; the fill is 354.0 MiB of boot + ~153.7 MiB of XTL micro-allocs each floored at 16.5 KiB by `kPhysSlabGranule=0x4000`, over-charging +125.5 MiB vs the console page model; the pool dies over-fragmented at `free=0x4e000`, and the boot fatals on `star_glow` 1.6 s later (causation = hypothesis, F-792 §2/§4.4). w743's healthy-verdict regime did NOT reproduce. Full chain + residuals in F-792. |
| **T43.3** | **Attribute `P5-LOOKUP -> FFFFFFFF`.** Is the guest's rebase table legitimately empty for `0xB6FB2F29`, or should our arena never have handed that address out? | decides whether §5.2 is our defect or the guest's | ✅ **ANSWERED 2026-10-08 (F-793)** — **both arms are ours, and the question dissolves.** (a) The table is legitimately (structurally) empty for `0xB6FB2F29` **and it is not the guest's table**: `REBASE-TABLE @BD40C000 n=7` (`w741b:11364`) prints `s_gRebaseTable`, allocated/filled by `MclaPublishGuestRebaseTable` (`gpu_device.cpp:7400-7419`) and installed as `[group+0]` by `MclaArmRebaseCtx` (`:7429-7430`, called at `:16833` with rebuild group `pctx.r4=s_rbCtx` `:16839`); all 7 records are 0x50/0x60 vbases (`REQDUMP w741b:11389`, `w756 PSTREAM :3612-3620`) and D828 membership is `vbase<=addr<vbase+size` (`:7381-7386`) ⇒ a B-domain key **structurally cannot hit**. (b) The arena **never handed `B6FB2F29` out** — nibble 9 (not 16-byte/`0x4000`-aligned, `heap.cpp:3237`); provenance = payload word[1] of buffer `B7981000` (`RSC-CHILD-DUMP w741b:11366`, words [4][5][6] gate-bad incl. ASCII `kdp+`). **Root cause = our `FDBF8-ARR-RESTORE`** (`gpu_device.cpp:16783-16822`: `kArrCand` 6 hardcoded buffers, `looksPtr` accepts payload whose word[0]=`B813FA0A` merely resembles a pointer; `break` `:16822`); **our `P5-PHYS`** (`task_dispatch_trace.cpp:600-611`, `a5>=0x80000000` ⇒ delta-0, no third state for "never an address") then turned the guest's correct fatal (`sub_821D2378`, unconditional `b 821BD618`; strings read from raw bytes) into delta-0 ⇒ guest ctor **`sub_8260B310+0x24`** stamped vtable `0x82088784` into the payload address (`PAGEWATCH W #064` `w741b:11385`; exhaustive raw scan = exactly 3 stamplers in the image, no host writer; the row's `lr=821BC53C` = parked `g_ppcContext` of `sub_821BC140`, proven by `COMPLETE #5` `w741b:11322` — F-793 §5). **§5.2's "double-ownership … is measured" REFUTED on both operands** (supersession note added under §5.2). Dormant: `B6FB2F29` in **2/192** logs (w741 + w741b only), 0 in baseline w756. **Fixes NOT implemented** — register `§2` rows first (two-queue rule), **ARR-RESTORE before P5-PHYS** (removing P5-PHYS alone = fatal). |
| **T43.4** | **Provenance probe** on the `sub_82130528` return value at guest `8218B2EC` — the unnamed provider of the `0xA0400000` destination pointer (F-778 §4d(iii)). | additive, log-only; the last unnamed pointer in the corruption chain | not landed |
| **T43.5** | **Retire or re-aim the FIVE staled instruments** (§5.3): `F373-HEAP-RAW` (`heap.cpp:1824-1828`), **`F373-HEAP-GOLDEN`** (`:2809-2810` — the worst, its `cap=` stays correct while `hex=` changes subject), `F370-HEAP-HDR`'s `hdr_off=` field (`:1790-1797`, computed `:1794-1796`), the `boot_host.cpp:468` needle comment, and the `guest_memory.cpp:60-61`/`:77-78` watch windows. | they now read arena data and will produce false findings; a half-working golden reference is worse than none | stale, live in tree |
| **T43.6** | **Revert test for F-779** (revert → refusals return), converting the forward control into a two-sided one. | the only claim in F-779 resting on a single direction | not run |
| **T43.7** | ✅ **DONE AND VERIFIED 2026-10-06 22:4x — add the untracked heap/P5 markers to `PROGRAM_GUIDE` §9's first column.** They were in §7 and not §9, and `markers_from_guide()` (`tools/soak_census.py:813-848`) reads only §9 first cells — so the battery tracked only `P5-GATE` (0 in both) and printed **no row at all** for the three (an untracked literal prints nothing, it does *not* print `+0`; this cell said "`+0` for everything" before it was corrected, and the table did print deltas elsewhere). Scope was measured, not remembered: **8** literals had 0 first-cell rows (`PHYS-POOL`, `PHYS-POOL-FULL`, `P5-LOOKUP`, `P5-MISSFIX`, `P5-PHYS`, `F373-HEAP-RAW`, `F373-HEAP-GOLDEN`, `F374-HEAPSTORE`). **Verification is the tool re-run on the SAME two logs: `257 tracked` (was 249, +8 exactly), `P5-LOOKUP 1 0 +1 <<`, `P5-MISSFIX 1 0 +1 <<`, `P5-PHYS 1 0 +1 <<`, `PHYS-POOL 1 1 +0`, `PHYS-POOL-FULL 0 0 +0`, `F373-HEAP-GOLDEN 1 1 +0`, `F374-HEAPSTORE 32 32 +0`, and one newly visible delta `F373-HEAP-RAW 0 1 -1 >>` (a stale instrument going silent — NOT a regression).** Also landed under this item: §7's `P5-PHYS` citation `:606`→printer `:607`, and a supersede note on §9's `PHYS-STATE` row (eight drifted `heap.cpp` citations; the ordering defect itself is T43.1 and is unchanged). | **a mitigation in §7 and not in §9 is invisible to the tool whose job is to catch mitigations firing** — standing rule now: a new `src/` marker goes into a §9 first cell in the same change | ✅ done + verified |
| **T43.8** | ✅ **TRACED 2026-10-07 (F-784) — the trace ends at a writer, and the writer is guest code.** `0x821BE3B8` = `4821C599` → `bl 823DA950` (guest memcpy), so `lr=821BE3BC` = `sub_821BE250+0x16c`; the stores that destroyed both o1heap cards are memcpy store PCs `__imp__sub_823DA950 +0x2df..+0x3f3` (extent-checked against this build's map), caught live on rows `w748.log:19013-:19017` (`BDA1F000`) and `:19359-:19360` (`BE12A000`) with `pre` values that decode to `FragmentHeader` next/prev/size/next_free (`0x4000` → bin 8, `0x22D6000` → bin 19, exactly matching `PHYS-BINPROBE`); 20-frame host chain resolved in F-784 §6; `sub_8218B0C8`'s four call sites resolved (`+0x64/+0x98/+0x1f4/+0x238`, only `+0x238` passes an alloc dst + stream `r22` len). **Residual — why dst/len was destructive — is T43.10, not this item.** | hottest unexamined path in the boot | w748: writer named on 6 wipe rows, F-784 |
| **T43.9** | ✅ **DONE 2026-10-06 22:05 — separate both o1heap instances from their arenas.** | F-779 (fix) + F-780 (its census correction) | `XTL-ALLOC-REFUSED` 4 → 0 |
| **T43.10** | ✅ **ANSWERED 2026-10-08 (F-785) — (a) CONFIRMED, (b) REFUTED; root cause decoded to the instruction.** Exactly ONE destructive entry in w749: `T4310-HUGE/CARD-MEMCPY #001` @23:33:50.480 `dst=8EFFEFB0 src=82862DF8 len=FFFFFFFF lr=821BE3BC sp=8EFFECD0` (k=1 on both arms; rule-19 control `:204` `prio=[0,0,-1,1] huge=[1,0]` all correct). Guest cause: `sub_8218B0C8` uses **`ReadByte` (`sub_821BE4F0`, returns −1 at EOF) unchecked as the length** at all four sites; the huge call = site **+0x1f4** (`dst=r1+592` → `8EFFED60+0x250=8EFFEFB0`); `sub_821BE250`'s SIGNED `cmpw/ble` guards read −1 as "fits" → never clamp → `memcpy(…,0xFFFFFFFF)`. Wrap measured `:28872` (`F374-HEAPGUARD trip=3 off=0X0 guestLR=821BE3BC` @23:34:54.423 = 63.94 s × 28.3 MiB/s = `0x71001050`; guard declines the null window, no VEH → F-784 §10's tension resolved). Cascade → card-header wipes (6 nonzero-pre, raw = F-784 §5 decode) → refusals 23:36:12 (`:35816+`) → park. | the refusal chain is now explained end-to-end (EOF → 4 GiB copy → header destruction → refusal); residual moved to T43.11 | **w749 = answer run**, built green (`gpu_device.cpp` only), gates +0 on 15/16 markers (16th characterized, F-785 §7); F-785 |
| **T43.11** | ✅ **ANSWERED 2026-10-08 (F-786) — (1) EOF provenance closed, (2) log-only guard landed + verified.** (1) The −1: `CityDefault.fxc`'s invocation header at member coord H=0x5000 was parsed from RAW archive bytes — `STREAM-WINDOW w750:13609 winAbs=0x5000 winHex=C2342C2A95ABAA0A` = `rpf[0x1FA000]` (member base+0x5000 = 12,902 B past the stored end 0x1F6D9A), while `ARC-WINDOW` delivered exactly 5 windows (pos 0..16384, none at 20480, unconditional printer — zero valid) — so a garbage `count=170` walked 23 records (**22/22 value dwords == BESWAP `dstAfter`**) and bytes ran out at rec23 `nl=254 nameAvail=129` → rec24 nameLen → −1; falsifier satisfied (crash at record 24, never 170); byte boundary at 20480 exact (apo-served ≤0x4FFF, count@0x4FFF alternative REFUTED). (2) `T4311-LEN-GUARD` + `T4311-LEN-SELFTEST` at `gpu_device.cpp:25930-25938` (fires iff `count>=0x10000000u`, budget `k<=16||k%4096==0`, no control-flow change), PROGRAM_GUIDE §7 paragraph + §9 row registered in the same change, `addr_owners --check 0x821BE250` = 2 sites exit 0, `markers_from_guide` tracked=True both (234 total), `mitigation_audit` undocumented 89→88. | F-785 §9 open #1/#5 → both closed by F-786; residual = F-786 §7 #1 (the tail-fill branch that wrote pos≥20480 is still UNNAMED — fix work, not yet a queue row) | **w750 = guard run**: guard fired 4× `count=FFFFFFFF lr=8218B2C0` (= return address of `bl 821BE250` @8218B2BC — caller pinned directly), selftest `fire=[1,1,0,0]` = expect, census **16/16 cited markers +0**, function-path printers identical (BE250-GUEST 5, BESWAP-RET 88, F396-ALLOC-EXIT 65, all +0); F-786 |
| **T43.12** | ✅ **ANSWERED 2026-10-08 (F-787) — and the task's own premise was wrong: there is NO bypass.** The tail read enters `sub_821CC1E0` like every granule — probe `T4312-UNDELIVERED #24` (`build/w751.log:13748` = `build/w752.log:13764`: `gate=0 ret=3327 req=4096 retEq=0 rec=B79150A0 win=82862DF8 pos=20480 w1=00005CFF bodySize=23807 posIn=1`) — and is refused by exactly one deliver-gate clause, **`origRet == amIn6`** (`src/gpu_device.cpp:20174`): the original returns 3327 = 23807−20480 (logical-size clamp) for `req=4096` while every other clause passes (deliver would compute `posIn=1 want=3327`); the five earlier granules delivered only because each returned exactly 4096 (`w752:13670/:13695/:13721/:13732/:13735`). Filler = the original body of that same call (full-row elimination over w750 `:13573→:13609` — only guest-stack/phys-arena writes, nothing touches `82862DF8`), source = raw `rpf[member_base+stream_pos]` byte-identical at two measured positions (`WINWR-WATCH #42 w750:13568 src8=rpf[0x1F8000]` = stream 0x3000, then overwritten by `ARC-WINDOW #61 :13570`; tail `winHex=C2342C2A95ABAA0A=rpf[0x1FA000]`, re-verified this session); guest addressing `archive_offset+pos` is its own (`recomp.17.cpp:3220/3238/3239`, raw words `gpu_device.cpp:19956-19971`). **Premise superseded:** `kListMemberSpans` (`gpu_device.cpp:2635-2642`) holds six `.list` entries, **no CityDefault** — the span is dynamic `g_expSpans` `[0x1F5000,0x1FACCF)` (logical 23807) and DOES cover `0x1FA000`. Closure 28+22=50=`WINWR-REC tot=50`; gates: build `[2/2]` (rule 1a), census w752↔w750 12 deltas ≤+213 (control w750↔w749 29, ±1,107), `addr_owners --check 0x821CC1E0` exit 0, `markers_from_guide` 234→235 tracked, `mitigation_audit` exit 1 pre-existing. | F-786 §7 #1 → **closed** | ✅ ANSWERED (F-787; registered PROGRAM_GUIDE §7 `:455`/`:457` + §9 `:758`); residual = **T43.13** |
| **T43.13** | ✅ **ANSWERED 2026-10-08 (F-788) — producer named, every link printed, and the premise's zero was an instrument artefact.** Producer = **`::ReadFile` + OVERLAPPED on the pack handle inside `RpfVirtualFileSystem::ReadFileAt`'s handle branch** (`src/fs/vfs_rpf.cpp:2835-2860`, call `:2842-2843`, span splice `:2852-2855`), issued per 32K page by guest `sub_8244F4C0` via `NtReadFile`'s positional arm (`src/kernel/imports.cpp:3460`; NFS-ARM `lr=8244F548` rows all `pos=1`), completing inside the host override (`RD-BUF` `src/gpu_device.cpp:19279`, `PPC_FUNC(sub_8244F4C0)` `:19225`), then copied guest-side into the window by `sub_821CBE18` (`WINWR-WATCH #42 w754:14250 srcBase=B795C000 src8=rpf[0x1F8000]` byte-exact; same row `w750:13568`/`w753:13735`). The `off=001F8000` histogram zero = **limiter-suppressed rows**, printed directly by the new log-only `READAT-DROP` probe (`vfs_rpf.cpp:2733-2759`, budget `first 1024 + every 4096th` `:2748`, counter `:2614`): `w754:14010 #681 call=949 off=001F0000 req=32768 got=32768` + `:14016 #682 call=950 off=001F8000 ...`, interleaved with their `RD-BUF` completions (`:14012/:14017`, heads byte-exact vs `rpf[0x1F0000]`/`rpf[0x1F8000]`) and bounded by printed `READAT-BRANCH #944/call=948` -> `#947/call=951` — exactly the two missing calls. `001F9000/001FA000` zeros are structural (no read issued there: page granularity 32768, granule fills are guest copies — 0 drop rows either). **Pair-map correction:** the dropped pair = `001F0000`+`001F8000` (the two pages covering the whole member `[0x1F5000,0x1FACCF)`), NOT `001F8000`+`00200000` — `0x200000` lands later (`w754:14254/:14255`, after the fill `:14250`). **Budget lesson (w753):** `first-64-then-every-256th` was consumed by the preamble (64 by call=84, 512 by call=575, total <768) and missed its own target (dropN 513-767) while printing 66 other drops — do not shrink the budget back. Gates: each build `[1/2]+[2/2]` = vfs_rpf.cpp only (rule 1a); `g_readAtDropped` only new symbol (rule 1b); soaks w753 (5,202,487 B) + w754 (5,403,408 B), new log each, `mcla.exe` killed after each; `soak_census w754 vs w750` exit 0 (DEPTH 1.03x, no LOG-QUALITY withholding), `readat-branch` 282=282 (probe observes, not perturbs); guest binary untouched. | F-787 §4 / §13.2 -> **closed** | ✅ ANSWERED (F-788; registered PROGRAM_GUIDE §7 before `## 8.` + §9 first-cell row after `:758`); residual = **the tail-fill fix itself** — separate task, behaviour unchanged (`origRet == amIn6` `gpu_device.cpp:20174` still refuses the 3327 original) |
| **T43.14** | **Deliver the logical-clamped tail granule — retire the `origRet == amIn6` refusal in the ARC-WINDOW deliver gate** (`src/gpu_device.cpp:20174`, the clause F-787 named). The gate opened only when the original body returned exactly `req`; **every EOF-exact clamp short** (`origRet == bodySize - pos`, `0 < origRet < req`, `pos < bodySize`) was refused, leaving the original body's raw pack fill in a window the guest then parses — and for EVERY member on this path the served body is DEFLATE (`stored != logical` in every `SERVE-PROOF` row of `build/w754.log`, e.g. `globaltex.list stored=236 logical=575`, `no_damage.dds 62→824`, `2dnoise3.dds 75147→87509`), so the raw fill is compressed-stream garbage, not a near-miss. Complete census on w754 (the T4312 probe budget covers all rows): **22 clamp refusals per boot = 17 refused member tails** (incl. `rec=B79150A0 pos=20480 ret=3327 = 23807-20480` — the CityDefault tail, head of the measured park chain F-785→F-786: raw `rpf[0x1FA000]` → garbage `count=170` → record 24 `ReadByte` -1 → `len=FFFFFFFF` → header destruction → refusal → park) **+ 5 whole-body reads** (`ret=575/824/260/1246/109 < 4096`, whose ENTIRE window is raw garbage — `globaltex.list`, `no_damage.dds`, …). The 6 remaining probe rows (`pos == bodySize`, `ret=0`) are zero-length EOF reads that `MclaArcWindowDeliver` refuses itself (`arPosInside`/`arWant != 0`) and are NOT opened. Fix: fetch the served body before the gate (same lookup, same sequence — nothing ran between it and the deliver before, nothing does now) and open on `arFull` OR `arClamp`. The deliver already clamps `want` to the body, so `ctx.r3 = ar.want` equals `origRet` on every such row: **guest-visible return unchanged; only the window bytes change** (raw garbage → proved body; same 512-byte-chunk copy; same exact-key + `w1 == body.size` trust anchors — completion of one existing table consumer, not a second short-circuit, do-not #1/#9). | F-787/F-788 named both the refusing clause and the producer (do-not #1 satisfied: root cause measured end-to-end); this clause is the head of the only measured park chain | ✅ **DONE 2026-10-08 (F-789) — landed, soaked, byte-exact; the refusal class is retired.** Gate now `arFull` OR `arClamp` (`src/gpu_device.cpp:20225-20230`, deliver call `:20234`; served-body lookup moved up `:20196-20202`; banner amendment `:20146-20161`), one TU build (rule 1a), no new file-scope symbols (rule 1b: only locals `arFull`/`arClamp`). Soak w755 (120 s survived, 43,932 lines / 7,853,784 B): `T4312-UNDELIVERED` **28 → 3**, tool-classified w754 = 22 clamp-refused + 6 zero-eof → w755 = **0 clamp** + 3 zero-eof; CityDefault tail `ARC-WINDOW #153 pos=20480 want=3327 done=3327 head=05000861` **byte-exact** vs fresh `zlib.decompress(rpf[0x1F5000:0x1F6D9A],-15)[0x5000:0x5004]`, second clamp row `#160 CityDefaultGrime want=2647 = 23127-20480` also exact; park chain all 0 (direct: `T4310-HUGE-MEMCPY` 1→0, `T4311-LEN-GUARD` 1→0, `count=FFFFFFFF` 1→0, `len=FFFFFFFF` 2→0; census: `HEAPHDR-STORE` 202→0, `F374-HEAPSTORE` 32→0, `F631-HEAPWIN` 32→0, `F379-HEAPSTORE-BT` 20→0); depth `ARC-WINDOW #` 62→176, `LISTLINE` 1→81, `GETDEV` 268→620, ceiling broken across four identical baselines (w743/748/750/754 all stall at 62/268/1). `soak_census w755 vs w754` exit 0 DEPTH 1.35× COMPARABLE. **New head of queue (seeded at F-789):** the `star_glow` fatal (`FATAL-SOFT` w755:25836 aux=`star_glow`, preceded by `AFB76-REFUSE` `NO-EMBEDDED-ENTRY blocked=STEP6-ALLOC` — first reach, `star_glow` = 0 rows in all four baselines) and `PHYS-POOL-FULL` 0→9 / `PHYS-LIVE` 0→256 = T43.2's exhaustion phase now reachable. |
| **T43.15** | **Attribute the `star_glow` fatal that first stops the boot (F-789’s seed): embedded-entry table, content corroboration, or pool?** Chain measured on `build/w755.log` + host code, NO BUILD: `AFB8-IN #74/#75` (`:25731/:25747`) → seed list intact (`listCount=15`, no `star_glow` — by design, `gpu_device.cpp:24118-24124`) → guest TOC resolves it (`candidates=1 tocVerdict='OK'`, `:25744`) → STEP4 inflate passes (`tocW1=89` = `inflated=89`, `:25734`) → **STEP6 `mem.Alloc(89,16)` returns 0** (`gpu_device.cpp:24077-24080`) → `AFB76-REFUSE blocked=STEP6-ALLOC` both forms (`:25744/:25763`) → guest `TOC76 #502-505`/`BDF20 #268/#269` all zero-return (`:25792-25813`) → fatal (`:25821-25836`). **The null is the pool:** `o1heapAllocate returned null #1..#8/#100/#200` @14:48:03.578→14:48:12.120, every row `live=0x1ffa8000 cap=0x20000000 peak=0x1ffa8000` (511.7/512 MiB), `caller_rva=0x2bc7aa` = `GuestMemoryHeap::Alloc +0x1a`; `PHYS-STATE #1` = `free=0x58000 free_ppm=671 verdict=over-fragmented why=free_but_no_suitable_class`, `suitable=0x0`, `bin_mask=0x1c0` (`:18139`); `XTL-ALLOC-REFUSED #1..#8` sizes 14..9520 in the same window. F-789 hypotheses: **(a) table-missing REFUTED (list printed); (b) pool CONFIRMED — but the denied step is the body ALLOC, not the corroboration (which passed).** `content=NOT-CORROBORATED` = vestigial constant: init `gpu_device.cpp:24239`, printed `:24328/:24334`, **no assignment**, 14/14 rows identical — never read a corroboration verdict off it. Sampler budget `n <= 8 OR n % 100 == 0` (`heap.cpp:3455`) hides post-#200 refusals — `blocked=STEP6-ALLOC` is this event’s evidence. | diagnosis; no hook, no printer, no build | ✅ **ANSWERED 2026-10-08 (F-790).** Residual is NOT this row’s to fix: with the pool refusing everything the fatal has no fix of its own — **T43.1c → T43.2** (registered order) is the cure. F-790 adds T43.2 three inputs: the in-tree mechanism (`heap.cpp:1976-1982`, `__xtl_free` no-op — arena only grows), w755 `over-fragmented` vs the w743 `healthy` premise (`free` 34.97 MiB → 352 KiB, `bin_mask` lost bit 19), the 314 MiB `alloc_seq=3` block still unfreed. |
| **T43.16** | **Name the 16 KiB floor: is `kPhysSlabGranule = 0x4000` the guest's own physical-slab truth, or a host over-charge?** (Registered 2026-10-08; F-792 §3's unregistered lead, HANDOFF §18.2.) Every one of the 8,000 XTL requests paid ≥16.5 KiB — a 14-byte ask charges `0x402e`, a 128-byte ask `0x40a0` (`w756:18151+`), and `align_bytes = 131,072,000 = 8000 × 16,384` at #8000 ≈ the entire **+125.5 MiB** overcharge (F-792 §2). The comment calling it "the guest's own slab mask, ~0x3FFF" (`heap.cpp:3237-3238`) is UNVERIFIED. | F-792 §3's bounded prediction — console-fair headroom ∈ [56.2, 129.7] MiB vs the measured **4.2 MiB**, "Under the console's own charging the pool would not have been exhausted at this point" — is a **labeled PREDICTION**; this row is what would confirm/refute the floor as the exhaustion root cause (pool dies `free=0x4e000` over-fragmented, then `star_glow`) | **ANSWERED 2026-10-22 (F-856's pool measurement) -- the gate is DISCHARGED and the floor is REFUTED as the exhaustion cause.** The floor was ALREADY SCOPED to slab-scale requests (T43.16, commit 515f4c6, `src/kernel/heap.cpp:3327-3328`: the floor applies only when `size >= kPhysSlabGranule`, else `alignment = max(16, alignment)`), so F-792's "+125.5 MiB" is a **STALE** number from `build/w756.log`. In the tree that produced `build/w872.log` the floor costs **10.97 MiB = 2.14 % of the 512 MiB pool** (`align_bytes` 11,561,248 = 702 kept-served x 16,384 + 3,730 relaxed-served x 16; cross-checked against the `SLAB-FLOOR` counters `relaxed=4096 kept=1339 refused=1000` at w872.log:251424). The 16 KiB NUMBER is the guest's own truth, but only as a POINTER-MASK granule for slab BASES -- guest 0x821C2884 `54880022 rlwinm r8,r4,sh=0,mb=0,me=17,mask=0xFFFFC000` + `911F00F8 stw r8,248(r31)` (sub_821C2840's own heap-init) -- which is why `src/kernel/heap.cpp:3328` must NOT change. The guest NEVER asks for a 16 KiB object: the XTL alloc thunk hardcodes alignment 16 (guest 0x82130538 `38A00010`) and the guest's own physical ask carries `align=0` (w872.log:290 `MMAL-PHYS-BIG #1 ... align=0x0 glr=821325D4`). Removing the whole residual would buy 10.97 MiB = ~3.9 s of headroom and the boot worker's 4 KiB semaphore would STILL fail. **WHERE THE POOL WENT (w872.log):** 299.52 MiB = 58.50 % in ONE never-freed boot block (`A3A8C000`, frag 0x12b85000, `MmAllocatePhysicalMemoryEx+0x1A7`, guest glr=821325D4; `PHYS-LIVE` prints 4,000 rows all `freed=0`; `PHYS-POOL-FULL` prints `big_freed=0` to the last row; the host's own live-pointer registry finds 3 live pointers inside it, `reg_hit=3 of reg_total=4412`); 46.52 MiB = 9.09 % in a second never-freed block the same way (8 named blocks = 400.02 MiB = 78.13 %); and ~120.08 MiB = 23.45 % in ~4,424 served requests ALL through `caller_rva=0x2E4A8A` = `GuestMemoryHeap::Alloc+0x1A`, whose host path is `src/gpu_device.cpp:3948` `dst = mem.Alloc(serveBytes.size(), 16)` -- the host's own XSF/file-serve path charging the PHYSICAL pool a page per served member (the same guest lr 0x821CCF78 appears on 114,627 `XSF-OPEN` rows). **The semaphore is the VICTIM, not the cause**: the pool died at 07:58:02, was 100 % full at 07:58:08, and the semaphore (4 KiB) started failing at 07:58:15. Residual = those three consumers, now the head of the pool queue. |
| **T43.17** | **Stop the host's XSF/file-serve path from charging the guest's physical pool once per serve attempt.** (Registered 2026-10-22 by F-858.) `src/gpu_device.cpp:3948` `dst = mem.Alloc(serveBytes.size(), 16)` allocated a block from the GUEST's 512 MiB physical pool for EVERY served member and never returned it. MEASURED on `build/w872.log`: 1,525 allocations, 37.43 MiB requested / 49.84 MiB page-granular charge, **1,525 DISTINCT buffer addresses (zero reused)**, 606 distinct members, so 919 serves / 25.51 MiB were byte-identical RE-ALLOCATIONS of a member the host already held; and **THE FIRST POOL REFUSAL OF THE WHOLE BOOT IS THIS ALLOCATION** (w872.log:203678, `caller_rva=0x2e4a8a` = `GuestMemoryHeap::Alloc+0x1a`, `glr=821CCF78` = the XSF-OPEN path), with 10,075 further attempts refused outright. The refusal was a **fragmentation** refusal, not absolute exhaustion: `PHYS-STATE #1 ... free=0x6000 verdict=exhausted why=free_below_one_request_class suitable=0x0` -- 24 KiB was free and the boot worker's semaphore needs 4 KiB, but no bin could satisfy a 16 KiB-aligned request. **DONE 2026-10-22 (F-858).** Reuse-before-allocate (the caller looks the member up in `g_servedByEntry` by the guest's TOC RECORD address, the only exact key -- F-091 retired (dev,handle), F-126 retired w3 -- and the serve path proves the bytes with a RUNTIME memcmp and allocates NOTHING on a match), plus the zero-length hole and the never-published bodies handed back. A PUBLISHED body is never freed, on purpose: two readers copy the body pointer out of `g_servedMtx` and read the bytes outside the lock (`:21733`, `:4366-4371`) and the AFB76 path (`:26728`) makes a body guest-reachable, so freeing one would be a use-after-free waiting to happen. **MEASURED (`build/w873.log`, 300 s): `PHYS-POOL-FULL` 58 -> **0**, `o1heapAllocate returned null` 109 -> **0**, `SEMA-OOM` 16 -> **0**, `W35-BOOT-GATE` 0 -> **40**, `XSF-HOSTSERVE` 1,525 -> 30,446 rows over only **529 distinct buffers** for 10,224 members, and **0 members with more than one `buf=`** (the reuse discriminator), `PHYS-ACCT freed_bytes` 8,527,872 -> 1,996,300,288, log 164 MB -> 409 MB.** The 16 KiB floor (T43.16) and the 512 MiB cap are untouched, and `src/kernel/**` was not touched at all. **RESIDUAL:** the guest's own never-freed blocks (the 299.52 MiB whale, FAITHFUL per F-815) plus the guest's own XTL traffic; and a SECOND host leak still open, `BE8D8-PACK` (`:27122`), 198 allocations / 4.62 MiB charged, whose copies ARE guest-reachable and so need their own analysis. |
## 7. TWO §4 "STANDING RULES" ABOVE ARE FALSE — THEY WERE RE-MEASURED ON 2026-10-06 AND MUST NOT BE RE-IMPORTED

1. **§4's "`tools/ppc_xrefs.py calls` reported 20 callers of `0x821BE250` where a raw scan finds 0"** —
   **both numbers were false** (F-775). A raw whole-image op-18 scan finds **80** direct `bl` sites to
   `0x821BE250`; the tool listed **61** with **zero false positives**. The defect was a silent output cap
   (`if n > 60: break`), so the printed number was the *listing cap*, not the count — and the 19 dropped
   were the **highest** addresses, i.e. the callers you are most likely looking for. Fixed: it now scans
   everything, lists ≤60, and prints how many more exist. Scale of what the cap hid: `0x823DA950` (the
   guest memcpy) has **597** call sites, not 61. What §4 got right and still stands: the `->` column names
   the **enclosing** function, and the tool cannot see the **15,392** register-indirect `bctrl`/`bctr`
   sites (op 19), which have no static target.
2. **§4's "`tools/ppc_disasm.py` … inverts `mr`"** — **FALSE** (F-776 §3). Re-measured: `7C9D2378` →
   `mr r29,r4` ✓, `7FC8F378` → `mr r8,r30` ✓, `7C8B5214` → `add r4,r11,r10` ✓ (Capstone agrees). §4's own
   control `0x7FC8F378 = or r8,r30,r30` **is** `mr r8,r30` in long form, so the entry contradicted itself.
   **Acting on it would have broken a correct decoder.** The real rule: **b11:15 is the destination for
   the logical family (`or`/`and`/`xor`, hence `mr`); b6:10 for the arithmetic family (`add`/`subf`)** —
   both right for their own family, neither generalising. What §4 got right and still stands: it cannot
   decode Xenos GPU microcode (it is a PPC disassembler), and op-30 (`rldicl`/`rldicr`, **5,884 words of
   2,588,672 = 0.23%**) was a real gap — now every undecodable word prints
   `NOT-DECODED(use generated/ppc_xenon/*.cpp)` instead of a bare family name, `--selftest` still 25/25.

## 8. STANDING RULES LEARNED 2026-10-06 22:0x — DO NOT REDISCOVER THESE

- **Timestamp coverage, not duration, decides whether a zero is a result.** `w741` (99.0 s) read
  `XTL-ALLOC-REFUSED 4 → 0` exactly like a fix; the baseline's refusals were at **+139.9 s**, which it
  never reached. **A zero is a result only if the new run's timestamps span the moment the baseline event
  occurred.** Equal-or-longer duration is necessary; event-time coverage is sufficient.
- **…and the same rule cuts the other way.** `w741` *does* cover +14.9 s, so it is valid evidence for the
  `P5-PHYS` return and supplies the second post-fix observation. **Voidness is per-event-time, not
  per-file** — never discard a whole log because it was too short for one claim.
- **A `field`-graded marker's own-row count is legitimately 0, so it can hide a mitigation in BOTH
  directions.** `skip fatal` scored 0 own rows in both soaks while its matching lines went 1 → 2 and total
  mitigation lines went 2,043 → 2,047. The census skill has warned about that phrase since 2026-09-20; it
  was re-broken anyway, in the opposite direction from the warning. **Read the `field` owner list
  (`['inflate-skip:1', 'p5-phys:1']`) — it names what actually fired.**
- **Own-rows ≠ matching lines, and both are correct for their own question.** `PRESENT` 49 own rows vs
  254/255 matching lines; `C0000005` 5 vs 7; `F631-HEAPWIN` 32 vs 64 (the extra 32 are `F374-HEAPSTORE`
  rows that carry the literal). Never compare a hand `grep -ic` against the tool's table without saying
  which semantics each number is in.
- **When a `ctx.rN` read is load-bearing, look for a host-side discriminator that does not need it.** A
  `ctx.rN` read inside a generated body can be a stale translator-local writeback, not the live argument.
  F-778 §4d re-based its whole addressing proof on **`caller_rva` distinctness** instead: an `ldu`/`stdu`
  loop has ONE store instruction → ONE `caller_rva`; an unrolled `std rN,k(rB)` block has many. 16 rows,
  16 distinct RVAs, identical ordered lists for both instances — no guest register read required.
- **Never cite an ASLR host address as evidence.** `inst_host` differs every run; the first draft of
  F-779 quoted the *wrong log's* value under the surviving log's filename and it took a re-run to catch.
  Cite `inst_detached`, `o1_cap_delta`, and the `hdr` ≠ `inst_host` inequality instead.
- **A field name you invent can substring-collide with itself.** `inst_detached=1` is a substring of
  `user_inst_detached=1`: **2 occurrences, 1 line** on `w741b.log`. `grep -c` (lines) is the census; an
  occurrence count double-counts one row.
- **Re-run every citation before propagating a number into a second document.** All three errors above
  were caught at that step and none by reasoning. `LONG_TODO_MASTER` §2 item 2.7 measured the scale of the
  problem: **66.7% of the ledger's `file:line` anchors rotted**, named symbols drifting a **median of
  2,239 lines**. **Re-point, do not re-derive.**
- **A fourth tool in this project crashes instead of printing its contract.** `build/soak_run.py --help`
  → `ValueError: invalid literal for int() with base 10: '--help'`; its real contract is
  `python soak_run.py <secs> <tag>`, readable only from its argv handling. Same defect as
  `tools/host_rva_resolve.py` and `tools/ppc_disasm.py`. **Read the argv from source; do not guess.**

## 9. MENU-GATE (added 2026-10-12) — parallel paths stay parked until menu

- **Rule: no XMA bitstream decoder, no native RAGE D3D12 upload, no exotic-prim/depth-resolve expansion until a soak reaches menu.** Frame path (alloc, FS reads, draw, resolve, present, shader key) is implemented honestly or refused with a counted marker; parallel paths stay census/silence/refusal.
- **Landed:** `src/rage/rage_asset_pipeline.cpp:499-559` — `GetTextureData`/`GetOrCreateTexture`/`GetOrCreateModel` now honest `false` + `RAGE-ASSET-REFUSE` (was white 128x128 + `true`). Policy header: `src/rage/rage_ideal_flow.h` (header-only, no build change).
- **Not landed / still fake-free:** XMA bitstream seam empty by design (`src/apu/xma_decoder.h:16-32`); guest never constructs XAudio (`src/apu/audio.cpp:40-51`). Keep silence.
- **Promotion trigger:** a parked item starts only when a soak proves it blocks menu. Until then a zero there means nothing (rule 19).
