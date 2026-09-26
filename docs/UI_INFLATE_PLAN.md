# UI `.xsf` inflate — consolidated plan and Path A / Path B evaluation

Written 2026-09-26, updated the same day through **F-333**. This is the single reference the
objective asked for ("evaluate Path A and Path B, produce a concrete plan with
file:line citations"). Evidence lives in `docs/ROOT_CAUSE_VALIDATION.md`
(F-244…**F-333**); flags/short-circuits in `docs/PROGRAM_GUIDE.md` §7; markers in §9.
Every claim below carries a log line or a `file:line`; nothing here is inferred
from an earlier summary.

## 0. Objective, and the honest score

| Requirement | Status | Evidence |
|---|---|---|
| (a) UI `.xsf` containers decompressed **in guest memory** | **3 of 4 at 100 %, garage 5.9 % by the guest (63,072, now measured stable across 11 of 12 boots; one 121,946 outlier) / 64.9 % with host placement** | `w285`/`w295`: raceeditor `compared=143069 mismatch=0`, policecam `19337/0` ×2, credits `29655/0`; `w297`: garage `still_present=63072 pct=5`, `w296`: `pct=64` |
| (b) **…so GFx can initialize** | **NOT achieved**, and NOT downstream of (a) | `MOVIE-CTOR` = 0 and `UILOAD-census` = 0 in every soak `w273`→`w308`, including the one where all four containers were placed (`w295`) |
| Evaluate Path A (host LZX) | done, §2 | F-295…F-333 |
| Evaluate Path B (guest descriptor construction) | done, §3 — mechanism identified (F-332 §4); eight variants closed by measurement; cause is structural: `obj` and `st` are per-job (F-339) | F-318…F-335 |
| Concrete implementation plan with file:line citations | this document | — |
| Implement + validate vs `w193` by soak census | done: 17 changes built/soaked/censused, 8 reverted on evidence (latest `w316`→`w317`) | `w274`–`w317`, `tools/soak_census.py` |

**Score: goal NOT achieved.** Two independent blockers remain, and only one of
them is mine to work on (§4).

## 1. Container inventory (stable facts)

Package offsets are stable; **destinations are re-rolled every boot** — which is
why every predicate below keys on the package offset, never on a dest address
(user directive #5, and confirmed the hard way by F-324 §4 / F-322 §4).

| Container | pkg | decoded size | state |
|---|---|---|---|
| raceeditor | `0x64CB0000` | 143,069 | 100 % verified in guest memory |
| policecam | `0x64CA3000` | 19,337 | 100 % (two dests in `w285`) |
| credits | `0x6496F000` | 29,655 | 100 % |
| garage | `0x64980000` | 1,066,057 | 5.9 % guest-only; stops at the first `0x8000` block boundary |

Header layout, read offline from `build/game_data/xarchive_cache.rpf` at
`+0x64980000`: `+00 05435352` (RSC5) · `+0C 0FF512EF` (XMem) ·
`+10 00104449` (uncompressed length) · `+14` frame table. So the preamble the
streamer parses is **12 + 8 = 20 bytes**, which is `src = 20` in
`src/xmem_lzx.h:531`, and the decoded form is a sequence of `0x8000`-aligned
blocks each beginning `44495500` ("DIU") — measured at
`UIXSF-DIVERGE … golden=[44495500 …] at 00008000` (`w304`).

## 2. Path A — host-side LZX decode

**Mechanism.** `src/xmem_lzx.h` (raw MS-LZX, `window_bits=17`, DIU-validated;
two recipes: `single` at `pkg+0x16`, per-frame `walk` at `pkg+0x14` sharing one
decoder). Build-time guard: `ninja -C build check_xmem_lzx` → 4/4 byte-exact
offline. In boot: `kPathBHostFullDecode` (`src/gpu_device.cpp:468`) decodes at
the top of the inflate handler (`PATHB-HOSTDECODE-TOP`) and at the corrupt-serve
leg, and writes straight into the dest when `decH.size() <= outLeft`.

**What it achieved.** 3 of 4 containers, byte-exact, verified twice from
independent directions: F-299's FNV-1a full-buffer readback of what the host
*wrote*, and F-321's `UIXSF-SLOT-VERIFY` of what is *in the dest at retirement*.

**Where it stops, and why that is structural.**
1. **Capacity.** The garage needs 1,066,057 bytes; the guest's window is
   `PSTREAM size=0x20000` (131,072) and the successful host write is gated on
   `decH.size() <= outLeft` (`src/gpu_device.cpp:7884`), so Path A refuses by
   design (a truncated prefix marked complete would corrupt the tail).
2. **Durability.** Placing the rest by host write works and is verifiable —
   `kUiXsfGoldenFill` + `kUiXsfFillListOrder` (`:8304`, `:8323`) put all
   1,066,057 bytes across 6 slots, `still_present=1066057 pct=100` at fill time
   (`w293`) — **but the guest owns those slots**: sampled late it drops to
   `692,445 pct=64`, because `INFLATE-ENTER` shows the guest re-using the same
   slots for other streams (`w296`: `B7A61000 → B7A81000 → B7AA1000` with
   `consumed` carried forward). Re-filling over guest-written data was considered
   and rejected as corrupting live state (do-not #9).
3. **Consequence.** Path A can *place* a container but cannot make the guest
   *hold* it. Durable decompression is therefore a Path B property.

## 3. Path B — guest descriptor construction / the guest's own inflate

Everything the host can do without guest re-entry has been tried on this path and
measured; the table is the important part, because each row was a plausible
mechanism that a soak killed.

| Varied | Change | Result | Evidence |
|---|---|---|---|
| window count | refill every empty retry, not only `retries == 3`; 400-retry budget (`kUiXsfChunkFeed`, `:589`) | garage died at window 1 → 5 windows | `w279` |
| abort policy | exempt a dynamically-keyed UI `.xsf` dest from the B7 no-progress backup-drain, which `return`ed before the refill block | the drain was killing it (do-not #9, our own mitigation) | `w277`/`w278` printed 0 markers → `w279` |
| cursor key | dest → **inflate state (the stream)**, `MclaUiXsfChunkOpen(st, outPtr)` + `g_uiXsfStreamPkg/Walk` | freeze 196,553 → **294,912** consumed, 3 more slots, same served windows | `w281` vs `w282` |
| cursor arithmetic | `ls.pos += consumed` (F-315's proposal) | **refuted**: `st+8` is cumulative, so this double-counts and livelocked `w275` at ~11 M inflate calls | F-318 §1 |
| framing | serve the container's real frame boundaries (`MclaUiXsfFrameAt`, `kUiXsfFrameServe`, `:8354`) | walks the table correctly (32 frame-sized serves) and **still** stops at 0x8000; then stalls with `inLeft=2051` non-zero | `w298`/`w299`, reverted |
| leftover | top up the input at the 35-byte leftover (`kUiXsfTailTopup`, `:609`) | livelock 704,373 lines; **reverted** — that leftover turned out to be a *slot* end, not a container end | `w280` |
| descriptor clamp | publish the container's declared total into `st+12` (`MclaUiXsfUnc`, `kUiXsfSetExpected`, `:603`) — it had never been written, so the stream inherited the **previous** stream's value (196,553 = the pkg `0xA0000` stall point) on shared stack state `006D8F20` | consumed reaches 262,124; **output unchanged** | `w302`/`w303` |
| latch clear + frame-aligned serving | clear `[ctx+20+12276]`/`[+12280]` (the driver's saved cursor and its **byte offset inside the current frame**) when installing a frame-sized window - `kUiXsfClearResume` + `kUiXsfFrameServe` | un-stuck (the garage's real frames 9572/5206/3344/4072 B at offsets 0/0x2564/0x39BA/0x46CA) and coverage got **worse**: 63,072 -> 43,732, ~89,000 failed frames | `w307`, reverted in `w308` (F-333) |
| append-only window | one window per stream sized for the whole container, filled forward, `st+4` written once | the window opened and appended correctly; on the next call `st+4` was back at `st + 0x20` - the record is re-armed every call, so buffer layout cannot carry continuity | `w311`, reverted in `w312` (F-335) |
| private codec context per stream (three forms) | replay the guest's own Open (`sub_82461378(0x8EFFF990, 1, block, 0x3492E)`, `r7` unread) and republish `*obj`; disjoint allocation; then a publish/restore pair keyed on `st` | all three took the job's healthy streams down: **`obj` (`0x8283D1B0`) and `st` (`0x6D8F20`) are BOTH per-job records**, so per-stream identity does not exist at this layer - F-339's publish count 0 / restore count 0 is the direct proof | `w316`/`w318`/`w320`, reverted in `w317`/`w319`/`w321` (F-337/338/339) |
| **staging / availability census** | print `srcEnd`(`S+11016`), the staging triple `S+12264/12268/12272`, `savedcur` `S+12276`, `frameoff` `S+12280` per frame; `srcEnd - srcp - 4` = bytes the caller presented | **frame 10 is presented ZERO bytes and its cursor is already on the context's staging end** (`savedcur` pinned at `stagbase+0x8000` in every frame) — the driver has left the caller's buffer behind | `w338` (F-348) |
| **give one call the whole stream** | one 1,07 MB window, `st+4` written once (`kUiXsfWholeStreamWindow`, with the F-347 head position) | refuted by its own success: `got=1098825 whole=1` and frame 10 failed **identically** (`frameoff=5698`, same cursor, same 10 successes, `cumprod` frozen). Also livelocked (`INFLATE-ENTER` 106,697 vs 4,901, no reverify line at all) | `w339`, reverted in `w340` (F-349) |
| **serve content vs the guest's own copy** | record `pkgOff -> (buf,size)` at the XSF open and memcmp every served window against the guest copy (`kUiXsfCompareGuestCopy`, log-only) | **`match=1` on all six garage windows** (`diff=0`, `cmp=32768`, at `walk=0` and at `walk=0x0C`) — the archive region we serve IS the container the guest holds, so the serve content is excluded as a cause | `w335` (F-346) |
| serve from the XCompress sub-header (`pkg+0x0C`) + `st+8=0` | put the head the guest's own preamble check looks for under its nose, and clear the shared record's `consumed` so the check runs | the check **fires** (`src +8`, `srcSz 32768→32760`) — first time in the project — and coverage is **bit-identical**: 63,072 / `first_bad=00008000`, every marker +0. Recognition closed as a cause too | `w336`, reverted in `w337` (F-347) |
| **the serve itself** | turn the whole UI refill off (`kUiXsfChunkFeed=false`), which reproduces `w322`'s fingerprint deliberately (`UIXSF-LOCATE` 0, `PEND` 2) instead of waiting for another outlier boot | durable coverage **identical** - garage 63,072, raceeditor 143,069/143,069 - so the serve feeds nothing that reaches the outcome, and F-320/F-329's `consumed` gains were bookkeeping | `w325`/`w326` A/B, default restored in `w327` (F-341) |
 | **per-package context, keyed on the entry's destination** | lazily open one private context per package with the guest's own Open and swap the global slot per entry, restoring the original for non-UI entries — the design F-339 asked for, with the key fixed | the swap happens once, correctly, and **no LZX frame is ever decoded again** (`failtotal` 0, `INFLATE-ENTER` 32): the global is the **streamer's own live current-context field**, read outside anything we hook | `w328`, reverted in `w329` (F-342) |
 | clearing the driver's walk state on **every** entry (the pairing F-333 could not do, since the record is re-armed per call) | `kUiXsfClearResumeEvery` + `kUiXsfFrameServe`; `UIXSF-RESUME-EVERY` shows the offset reaching 0 and staying there, so the mechanism worked | same as F-333 and now with co-signals: coverage 43,732, `cumprod` 196,608 vs ~917,504, `failtotal` 70,483 vs ~5,280 - **the walk state is the stream's real position and must be respected, not corrected** | `w330`, reverted in `w331` (F-343) |
 | hold the shared context by skipping the competing containers' inflate **calls** (F-340 withheld refills, which F-341 showed are inert, so this is the real test) | `kUiXsfHoldCtx`, package-keyed ownership with a bounded run cap and rotating handover | **null**: 5 hold events, 0 handovers, every frontier number at baseline - so container interleaving on the shared context is not the cause. Plus the trap: the first run's `failtotal` 6 was a 40-entry stalled boot, not better frames | `w332`/`w333`, reverted in `w334` (F-344) |

**The wall, localised by measurement (F-330, then re-read by F-331/F-332/F-333).** At container offset `0x8000` the
guest's 32 bytes appear **nowhere** in the golden within ±4 KiB
(`NOT-IN-GOLDEN-NEIGHBOURHOOD`) — not a shift, so not our slicing. What the
three later entries establish is *where* that comes from, and they retire the
suspects this section used to list:

- **RETRACTED (F-331 §1): there is no decoder instance at `0x828D38D8`.** That
  address appears nowhere in `generated/` (`grep` for `14552`, the `ori` half,
  returns 0 hits) and `ppc_recomp.82.cpp:12099` is `sub_82460420`, a
  status-mapping wrapper. Likewise "`[ctx+4]` codec gating is excluded because
  `ret=0`" was void: `ret=0` is the success value of the whole chain.
- **The chain is one call graph, and it is now fully mapped** (F-331 §2):
  `sub_821BC140` (streamer job loop, `ppc_recomp.14.cpp:18805`, 28-byte
  descriptors) → `sub_821D5E10` (`ppc_recomp.18.cpp:10832`, our
  `INFLATE-ENTER`) → **calls** `sub_8244FF20` at `:10933` → `sub_82460420` →
  `sub_82461010` (`ppc_recomp.82.cpp:14065`, the frame-table driver, state at
  `ctx+20`) → per frame `sub_82461530` (`:14885`) → `sub_82461E68` +
  `sub_82461B98` (`:15846`, the LZX frame decode). Its guest framing code is
  byte-identical to the offline recipe in `src/xmem_lzx.h:531-552`.
- **The guest decodes frame 0 and then fails every frame, silently** (F-331 §6,
  F-332 §2): `sub_82461530` bumps its frame counter unconditionally but
  accumulates produced only on success, and `sub_82461010` **discards the return
  value**, so a −1 frame costs nothing and reports S_OK. ~95 % of all frames in
  a boot return −1.
- **For the garage specifically** (F-332 §4): the frame driver is entered with
  its per-frame byte offset `[S+12280]` non-zero (left over from whichever
  stream last used the shared `ctx 4000FD80`; the routines that would clear it,
  `sub_82460F88` / `sub_82461840`, are not reached between streams), so it
  resumes mid-frame from the stale saved cursor `[S+12276]` in another buffer,
  **consumes 0 input, writes 0 output and returns S_OK** — and because
  `*srcSize(out)=0` the caller can never advance. Eight byte-identical
  `XMEM-SZPTR` lines in `w306`, with the garage's served bytes sitting right at
  the advertised `src`.
- **And the obvious reading of that is a trap** (F-333): clearing the latch and
  handing the driver a frame-aligned window *does* unstick it and makes coverage
  **worse** (63,072 → 43,732, ~89,000 failed frames), because the decoder is one
  continuous bit stream — `[S+12276]`/`[S+12280]` are not junk, they *are* the
  stream position, and moving `src` under them is wrong in both directions.

## 4. The GFx half is a different problem, and it is the user's to open

`MOVIE-CTOR` = 0 and `UILOAD-census` = 0 in every soak this session, including
`w295` where all four containers were present in guest memory. The producing
mechanism is closed off by elimination, not assumption: DPC producer
`sub_8242FD00` measured 0 with a fired control (F-309); the handler table is
undispatchable — no walker, no stored pointer, no immediate (F-313/F-314);
`KeInsertQueueDpc` is not among the 246 host `__imp__` thunks (F-316); and no
release is being produced and lost — 6,626/6,626 waits are 30 ms timeouts
(F-317). Crossing `rule-2` (recompile `0x82100000..0x8212FFFF`) or `F-055`
(force the gate) is barred without an explicit user decision, and F-301/F-310
show the region is a data table below `PPC_CODE_BASE`, so rule-2 as titled could
not have been the fix anyway.

## 5. Plan, in order, with acceptance tests

**Steps 1 and 2 of the 09-26 morning version of this plan are done, and their
target turned out not to exist**: the static read of `sub_82461010` /
`sub_82461B98` (F-331 §2, §7) and the census of the decoder's own state (F-331 §6,
F-332) are what produced the diagnosis above, and the `0x828D38D8` singleton they
were aimed at is not in the image. What remains:

1. ~~**Serve in place — stop moving `src`**~~ — **WITHDRAWN by F-334 before it was implemented.** At the refill trigger the guest's `inPtr` is `st + 0x20`, i.e. inside its own stack-resident inflate record with `inLeft = 0` (`UIXSF-LOCATE` ×6 in `w310`, needle matches nowhere in 4 MB of the package), so there is no container window belonging to the guest to extend in place. The text is kept because it documents the assumption that failed. In the
   refill, at the `WriteU32BE(st + 0, got)` / `WriteU32BE(st + 4, s_hsBuf)` pair
   immediately above the `kUiXsfClearResume` block
   (`src/gpu_device.cpp:10003`), for a UI `.xsf` stream write the container's
   continuation bytes at `inPtr + inLeft` **into the buffer the guest is already
   pointing at** and raise `st+0` by the count, leaving `st+4` untouched, so the
   driver's `[S+12276]`/`[S+12280]` pair stays consistent with the bytes under
   it. The only genuinely new derivation is mapping the guest's current buffer
   position to a package offset — do it by locating the tail (≥16 distinctive
   bytes) of what is already in that buffer inside the host-side package image,
   never by assuming a window base. Guard with `IsValid` plus a check that the
   target is not one of the readlist slots. Acceptance: `LZX-FRAME … ret=32768`
   lines after the first ten, and `UIXSF-GOLDEN-REVERIFY … still_present` rising
   past 63,072 **with `kUiXsfFillDryRun=true`**. If coverage does not rise, this
   line closes too, and the remaining candidate is making the guest reach its
   own reset (`sub_82460F88` / `sub_82461840`, which zero exactly this state)
   between streams — a different mechanism, not another framing knob.
1b. ~~**Append-only window per UI stream**~~ — **REFUTED by F-335, by its own success.** The window opened (`cap=1,098,825` at the garage's own serve address), appended 65,536 bytes twice in correct order, and produced nothing: on the very next call `st+4` was back at `st + 0x20`, so the guest **re-arms its inflate record every call** and continuity is not something a buffer can provide. 131,072 contiguous, frame-0-aligned bytes were offered and `cumprod` stayed frozen at 327,680, which also kills the “longer contiguous run” hope. w311 regressed (682,178 lines, INFLATE-ENTER 109,072, garage reverify absent) and was reverted. The text below is kept as the record of the assumption. **Append-only window per UI stream** (F-334 §4 — the surviving form of the serve idea). Each refill today overwrites the same `s_hsBuf` from its start while `walkPos` advances, so any absolute position the frame driver kept refers to different bytes than it did one call earlier, and F-332 showed the driver's own saved cursor sits in the ctx's staging area (`0x4003xxxx`), never in our window. Change: allocate ONE window per UI stream, big enough for the whole container (garage: 1,066,057 + header), fill it **append-only** starting at the container's frame 0, and let `*srcSize` be the only moving part — never re-point `st+4` to another base and never overwrite bytes the driver has already seen. Evidence that one call can carry many frames: `LZX-FRAME #1..#10` decoded ten consecutive frames out of one contiguous ~23 KB run and produced 327,680 bytes. Acceptance: `LZX-FRAME` successes past the tenth (`cumprod` beyond 327,680), and `UIXSF-GOLDEN-REVERIFY … still_present` past 63,072 with `kUiXsfFillDryRun=true`. If that fails, the remaining candidate is the shared ctx's LZX table/history across streams (F-331 §7's type-1/2 self-reset), i.e. making the guest reach `sub_82460F88` /
    `sub_82461840` per stream — a different subsystem, not a serve knob.
1c. ~~**A codec context PER UI stream**~~ (**final form closed by F-342: the swap itself halts the decode, so this must be built where the pair is born, or done by serialising the streamer's arming — see §3's last row**)  - **CLOSED by F-339, at the layer of the record rather than the fix.** Built three times: F-337 (replay the guest's Open and republish `*obj`), F-338 (same with a provably non-aliasing allocation, which refuted F-337's aliasing story), F-339 (a publish/restore pair keyed on `st`). Every form took the job's healthy streams down with it, because `obj` **and** `st` are per-JOB records - F-339's zero publish and zero restore counts are the proof, since the binding already applied to every entry of the job. So there is no per-stream handle below the guest's job loop and Path B's remaining scope is not a descriptor field but **task #15 in its original form**: construct a stream-private (record, context) pair where `sub_821BC140` (`ppc_recomp.14.cpp:18805`) walks its 28-byte descriptors. The earlier notes below are kept because each one is a measured negative. Original F-337 framing: — **tried twice, reverted both times, and the shared-slot form is now closed by F-338.** F-337 blamed our allocation aliasing; F-338 disproved that with a disjoint context (`ctx=CAF5D300`, serve windows at `C8A0xxxx`) and the boot still stopped progressing 6 ms after the republish. The reason is the scope of the slot: `obj = 0x8283D1B0` is a **per-JOB** record (F-323: vbase is per-job), so writing a private context into it hijacks every stream in the job, healthy ones included. Two options remain, in order of cost, and neither has been tested: (i) **paired publish/restore** inside the inflate hook — save the shared ctx at bind time, force `*obj = priv` only for entries whose `st` is the bound stream, restore the shared value for every other `st`; (ii) **a per-stream descriptor object**, which is the enqueue side (task #15).  The replay works (`r7` is unread by the wrapper; `r6=0x3492E` is the size) and the republish works (the static slot `0x8283D1B0` held `*obj = 0x4000FD80` and took the private ctx), but `mem.Alloc(0x35000)` returned `0xCAF28300` — the address the XSF serve window already uses — so the context and its own compressed input aliased, and the boot went shallower (27,760 lines, INFLATE-ENTER 32, no garage reverify). **F-338 note: that pre-flight was done and did not help — see the paragraph above.** Everything below is F-336's finding, which stands. 1d. **Same avenue, the three forms in order** — rewritten by F-336, which found the reason every serve design failed: the codec ctx at `0x4000FD80` is opened TWICE in an entire boot (`XMEM-OPEN-CENSUS wrapper=2 caller=2` against a control that fires on all 4,901 inflate entries), so the garage inherits a context whose walk state and history belong to another container. The old framing of this step (“reach the guest's own reset”) is wrong — resetting a shared context does not unshare it. Recipe: allocate a block the size the guest uses (the two observed contexts sit `0x34940` apart ≈ 215 KB) and call the guest's own Open wrapper `sub_82460370(r3=0x8EFFF990, r4=1, r5=newblock)` — the exact call that produced `4000FD80` — then publish `*obj = newblock` for that stream so `sub_821D5E10`'s `r3 = *obj` picks it up.
    **Before replaying it, extend `XMEM-OPEN-CENSUS` to print `r6`/`r7`** — the wrapper forwards `r6` into a stack slot that becomes `sub_82461840`'s `r4`, and `r7` arrives as its `r5` (`ppc_recomp.82.cpp:14611-14636`), so an Open with only `r3`/`r4`/`r5` reproduced would be guessing at two arguments. Also expect `*obj` to be re-armed by the caller every call (F-335 §2), so the private-ctx publication has to be re-applied per entry, not once. (`sub_82460F88` `ppc_recomp.82.cpp:13973` / `sub_82461840` `:15324` zero exactly `S+12264…S+12296`, and are only reached from the Open wrapper `sub_82461378` `:14590`, which has one call site and runs twice per boot.) Require `LZX-FRAME` successes past `frameIdx=10` and `UIXSF-GOLDEN-REVERIFY … still_present` past 63,072 with `kUiXsfFillDryRun=true`. If it fails, Path B's remainder is the LZX table/history semantics inside `sub_82461B98` — i.e. reimplementing the guest's decoder host-side, which is a different class of work and a user decision, not another flag.
2. **Do not re-run the redirect family.** F-318, F-320, F-327, F-329 and F-333
   cover re-pointing `src` with five different offsets, latches and framings;
   correct output moved in none of them and went *down* in the last. A further
   variant needs new evidence, not a new flag.
3. **Keep the placement instruments** (`kUiXsfGoldenFill` + dry run) as the
   measurement harness, not as a fix: they are what make "who produced these
   bytes" answerable, which is the question three of this session's reversions
   turned on. `LZX-FRAME` and `XMEM-CTX` are the other two instruments worth
   keeping — between them they are the first things in the tree that see the
   decoder's own progress.
1d. **The failure is now inside the type-2 arithmetic decoder (F-345, static deduction).** The three exits from  to  are enumerated and two are excluded by logged values (type is 2, and  = 32,768 is non-zero), so the failing garage frames die in  after its tables have already been reinstalled from / (:16008-16060). The remaining split is cursor-content vs decoder-internal state, and F-345 §2 names the log-only measurement that decides it (per-frame cursor sequence within one outer call, against the offline walk). Everything in steps 1/1b/1c is upstream of that, which is why none of it moved output.
1e. **Availability is now closed too (F-348, F-349) — Path B is down to one shape, and it is a different class of build.** w338 makes the failure arithmetically readable (`srcEnd - srcp - 4` = bytes presented; `sub_82461530` arms both fields from its own args at `ppc_recomp.82.cpp:14906`,`:14918-14920`): the ten successes each end with the source consumed to the last 2 bytes, and frame 10 is presented **zero** bytes with its cursor already on the context's staging end (`savedcur` = `stagbase+0x8000`, pinned on every frame). The obvious inference — feed it more — was built and falsified itself: presenting the entire 1,098,825-byte container in one call changed frame 10 **not at all** (same `frameoff=5698`, same cursor, same ten successes) and livelocked the boot (`INFLATE-ENTER` 106,697 vs 4,901, the garage reverify never ran). So the empty source is a symptom of the walk leaving the caller's buffer, and the three content-side causes are now each excluded by measurement: bytes (F-346), recognition (F-347), availability (F-349). **Do not re-run any of them, and do not build the arming-order variant of task #15** — F-344 already held one container at a time and moved every frontier number by exactly 0, so if the state is lost within one stream, order between streams cannot recover it. What remains that is not predicted-null is task #15's larger shape, a (record, context) pair per 28-byte descriptor created inside `sub_821BC140`'s walk (`generated/ppc_xenon/ppc_recomp.14.cpp:18805`), i.e. constructing the stream identity where the guest constructs it rather than steering the shared one from the hook layer — a new build class, and §4 (the user's `rule-2`/`F-055` decision) is now the better-value half of the objective.
 (F-346, F-347) — the only remaining Path B lever is the arming order, not a serve knob.** Two log-only/one-behaviour measurements settled it: every served window is byte-identical to the guest's own copy of the container (`w335:2578` ×6, `match=1`), and when the window is positioned so the guest's own preamble check succeeds — which it now does, `src +8`/`srcSz −8` (`w336:3769`) — coverage is still `63,072 / first_bad=00008000`. So the decoder is not rejecting our bytes or our framing; it loses its own continuation state after ten frames and then emits type-1 attempts with `bitbuf=0` forever (102,275 of them in `w337`, `cumprod` frozen). Do **not** re-run: frame-aligned serving (F-333/F-343, measured worse twice), any context-swap variant (F-337–F-342), or the head-serve (F-347). The one shape left is task #15's smaller one — serialise the streamer's arming so one container's frames run to completion before the next is armed, done at `sub_821BC140`'s 28-byte descriptor walk (`generated/ppc_xenon/ppc_recomp.14.cpp:18805`) where the (record, context) pair is actually born. Acceptance unchanged: `LZX-FRAME … ret=32768` lines past the tenth, `cumprod` climbing, `UIXSF-GOLDEN-REVERIFY pkg=64980000 still_present` past 63,072 **with `kUiXsfFillDryRun=true`**, plus a same-binary repeat soak and a per-marker table vs `w193` and vs the adjacent control boot. If that fails, Path B is finished and §4 (the user's decision) is the deliverable.
1f. **Path A placement is what moved the garage, and it is now at 41.3 % (F-350, kept; F-351/352, the limits).** The container was never blocked by the decoder: the single-shot host decode refuses unless the whole 1,066,057-byte body fits one 131,072-byte dest, so it fell through to a guest that manages ten frames. Place the body across the destination chain the guest itself requests (write `room` bytes at the requested dest, advance a per-package offset, mark that record complete) and resident coverage goes 5.9 % -> **440,720 bytes**, verified by readback, `still_present` sampling late at `pct=96` of the claim. Two boundaries found on the way, both now enforced: **do not cross readlists** (F-351 spilled into `B7801000`, which the same boot reports as credits' byte-exact destination, on a vbase mapping nothing observes - withdrawn), and **the sequential vs vbase-delta layout question is unanswerable inside a table because the two models coincide there** (F-352's audit reports `winner=TIE`, 458,752/458,752 under both). To go past 458,752 legitimately the guest must keep requesting garage destinations - the shared-record/arming problem (task #15) - or `nGfx` must come up and consume them, which is section 4.
4. **GFx**: take §4 to the user as a decision with the elimination chain attached;
   do not spend soaks on it meanwhile.

## 6. Validation recipe (do not improvise this)

```
MSYS_NO_PATHCONV=1 MSYS2_ARG_CONV_EXCL='*' cmd.exe /c "taskkill /F /IM mcla.exe"
MSYS_NO_PATHCONV=1 MSYS2_ARG_CONV_EXCL='*' cmd.exe /c build_on_e.bat build   # ninja → build_ninja.log, NOT stdout
ls -l build/mcla.exe build/CMakeFiles/mcla.dir/src/gpu_device.cpp.obj        # rule 12: BOTH mtimes must move
cd build && timeout 120 ./mcla.exe > w<NNN>.log 2> w<NNN>_err.log; echo BOOT_RC=$?   # 124 = survived
python ../tools/soak_census.py w<NNN>.log w<control>.log                     # one baseline per call
```
**A coverage number needs two soaks.** `UIXSF-GOLDEN-REVERIFY … still_present` varies across boots for the same binary: 57,210,368 produced garage coverage of 121,946 in `w322` and 63,072 in `w323` (F-340 §3). So a claim of the form “coverage rose/fell” is only admissible with a same-binary repeat soak beside it, or with a structural co-signal outside the spread (a `failtotal` or `INFLATE-ENTER` change of multiples, not tens of percent). F-326's “stable across five samples” was five samples inside one boot. Gate: **per-marker**, never line totals (F-072) — boot-to-boot variance is
57,886 vs 102,134 lines for the same binary (`w274` vs `w276`). Structural
markers (`LISTLINE 171`, `CP-DRAW 166`, `Fatal error 1`, `C0000005 0`,
`SEEK-DEAD 0`, error-lines 28) must stay at +0; revert immediately if any moves,
or if one repeating shape exceeds ~10 % of lines, or if the exe mtime did not
move (a stale-exe soak is worse than no soak — it produces confident
non-evidence).

## 7. Flag register, as it actually stands in the tree

`kPathBEnqueueUI=true` `:87` · `kPathBHostFullDecode=true` `:468` ·
`kPathBSingleOpen=false` `:545` · `kUiServeAdvance=false` `:571` ·
`kUiXsfChunkFeed=true` `:589` · `kUiXsfSetExpected=true` `:603` ·
`kUiXsfTailTopup=false` `:609` · `kUiXsfClearResume=false` `:631` ·
`kUiXsfBoundUnc=true` `:8104` · `kUiXsfVerify=true` `:8425` ·
`kUiXsfHunt=true` `:8463` · `kUiXsfGoldenFill=true` `:8665` ·
`kUiXsfFillListOrder=true` `:8684` ·
`kUiXsfFrameServe=false` `:8731` · `kUiXsfFillDryRun=true` `:8738` ·
`kUiXsfReverify=true` `:8888` · `kUiXsfClearResume=false` `:631` · `kUiXsfLocate=true` `:642` · `kUiXsfAppendWindow=false` `:660` · `kUiXsfPrivateCtx=false` `:703` · `kUiXsfSerializeCtx=false` `:731` · `kUiXsfCompareGuestCopy=true` `:455` (log-only) · `kUiXsfStreamHeadServe=false` (F-347 mechanism proven, measured null; briefly re-enabled as F-349's precondition, OFF again) · `kUiXsfWholeStreamWindow=false` (F-349, refuted by its own success, livelocked) · `kUiXsfChunkedHostFill=true` `:506` (F-350, **the placement that works**) · `kUiXsfFillDryRun=false` `:9011` (F-350: Path A now writes the garage, so `still_present` measures host+guest, which is the deliverable's own standard) · `kUiXsfFillOwnSlots=true` `:9022` (F-350: overwrite a slot of this container's own chain when it holds the guest's failed decode, never one another package owns) · `kUiXsfLayoutAudit=true` `:9035` (F-352, log-only).

**Net shipped effect:** Path A hosts 3 containers outright; the feed follows the
stream and publishes the correct `st+12`; the third container's placement is
**measuring, not writing** (`kUiXsfGoldenFill=true` + `kUiXsfFillDryRun=true`),
and frame-aligned serving is off (tested and reverted, F-333). No unregistered
short-circuit: §7 of `PROGRAM_GUIDE` carries each of these.
