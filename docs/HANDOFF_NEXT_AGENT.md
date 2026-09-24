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
