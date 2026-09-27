# UI `.xsf` inflate — consolidated plan and Path A / Path B evaluation

Written 2026-09-26, updated the same day through **F-333**; brought up to date
2026-09-27 through **F-451** (any pre-F-391 coverage number below is historical),
and through **F-454** at 03:2x — see §0a, which supersedes the "next host-side lever"
option that F-452 §3 left open.
This is the single reference the
objective asked for ("evaluate Path A and Path B, produce a concrete plan with
file:line citations"). Evidence lives in `docs/ROOT_CAUSE_VALIDATION.md`
(F-244…**F-454**); flags/short-circuits in `docs/PROGRAM_GUIDE.md` §7; markers in §9.
Every claim below carries a log line or a `file:line`; nothing here is inferred
from an earlier summary.

## 0. Objective, and the honest score

| Requirement | Status | Evidence |
|---|---|---|
| (a) UI `.xsf` containers decompressed **in guest memory** | **3 of 4 at 100 %, garage 851,968–917,504 claimed of 1,066,057 (80–86 %), 872,032 durable = `pct=95`** — up from 5.9 % guest-only / 64.9 % with host placement (both figures predate F-391) | `w441`…`w452`: `UIXSF-GOLDEN-REVERIFY pkg=64980000 goldsize=1066057 claimed=917504 still_present=872032 pct=95 first_bad=00030005` (`w452`), `claimed=851968 pct=97` (`w441`/`w442`); raceeditor `pkg=64CB0000 claimed=143069 pct=100 first_bad=FFFFFFFF`; policecam `19337/0` ×2; credits `29655/0` |
| (b) **…so GFx can initialize** | **NOT achieved**, and NOT downstream of (a) | `MOVIE-CTOR` = 0 and `UILOAD-census` = 0 in every soak `w273`→`w308`, and the whole T41.10 gate tuple (`W35-BOOT-GATE`, `BOOT-GATE-ENTER/RETURN`, `XSF-INFLATE`) is still 0 in `w442`…`w452`; the blocker is now localized *upstream* of decode — F-443…F-450: the enumerator's reader at `0x82860C68` holds a shaders `.list` and then XMem-compressed bytes, never the tune text |
| Evaluate Path A (host LZX) | done, §2 | F-295…F-333 |
| Evaluate Path B (guest descriptor construction) | done, §3 — mechanism identified (F-332 §4); eight variants closed by measurement; cause is structural: `obj` and `st` are per-job (F-339) | F-318…F-335 |
| Concrete implementation plan with file:line citations | this document | — |

## 0a. Dated update 2026-09-27 03:2x (F-452 → F-454) — the last host-side lever is now measured out

F-452 §3 left one open candidate for clause (b): re-arm the guest-visible Open-gate bit30
(the `WriteU32BE(entry+8, e8 | 0x40000000)` F-079 retired at `src/gpu_device.cpp:16035`)
**only** for the two tuning-archive TOC entries, and judge it against four already-instrumented
criteria. That soak ran (`w455`, after one wasted selector run `w454`) and **refuted the
hypothesis** — recorded as **F-454**:

- The bit really reached guest memory: `F453-TUNE-GATE … entry=C650CED0 +8 003F0000 ->
  403F0000 readback=403F0000` (`w455.log:116853`) and the same for `C650CEB0` (`:117684`),
  against `w452.log:122150`/`:122870` where those identical entries took the
  "host cache only … guest memory untouched" branch.
- Zero downstream movement: tune `MEMBER-EXPAND` rows 0 (all 51 rows are `shaders/*/preload.list`
  ×5 each + `globaltex.list`), `F442-SECTION` 14 rows all `hits=0`, `F432-GROW-SKIP` 3 → 3,
  `LISTLINE` 171 = 171, `C0000005` 0, `BC140-REC` 7, `nGfx=0` 6, `LZX-FRAME` 32 = 32.
  The fourth criterion (`[0x828CD0AC] > 0`) was **unevaluable, not zero** — that probe printed
  0 rows in both soaks.
- Reverted, and the revert verified in the binary: `src/gpu_device.cpp` has no trace of the
  experiment, and `build/mcla.exe` (57,435,136 B, 03:15) contains 0 occurrences of the marker
  string while still containing `XSF-OPEN-GATE-SKIPPED` / `F447-REFILL` / `F432-GROW-SKIP`.

**What this changes in the plan.** Clause (b)'s host-side option set is now empty by measurement:
serve filter (F-446), host-serve reach (F-450), gate bit (F-454). §1's step "make the guest reach
its own reset between streams" and task #15's descriptor shape are untouched by this, but neither
addresses the tune-enumeration gap. The one cheap live probe is **#66**: tag every `LISTLINE` row
with the path/buffer it came from, which is the only measurement left that can say *why* the loader's
line loop composes shader lists and never tuning lists (F-451, on ground F-107/F-109 already mapped).
The other option stays what it has been: §4 / the user's `F-055` host-forced boot-gate decision.
Clause (a) is unaffected and held through `w455` itself: garage `claimed=851968`, `still_present=851968
pct=100` early, `pct=94-97 / first_bad=00040005` late.
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
| garage | `0x64980000` | 1,066,057 | 851,968–917,504 claimed / 872,032 durable (`pct=95`) post-F-391; the `0x8000`-block wall is gone — `first_bad` is now `00030005`/`00040005`, never `00008000` (`w441`…`w452`) |

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
   past 63,072 **(`kUiXsfFillDryRun` is `false` in the tree — flip it to `true` deliberately, only for a guest-only reading)**. If coverage does not rise, this
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
 (F-346, F-347) — the only remaining Path B lever is the arming order, not a serve knob.** Two log-only/one-behaviour measurements settled it: every served window is byte-identical to the guest's own copy of the container (`w335:2578` ×6, `match=1`), and when the window is positioned so the guest's own preamble check succeeds — which it now does, `src +8`/`srcSz −8` (`w336:3769`) — coverage is still `63,072 / first_bad=00008000`. So the decoder is not rejecting our bytes or our framing; it loses its own continuation state after ten frames and then emits type-1 attempts with `bitbuf=0` forever (102,275 of them in `w337`, `cumprod` frozen). Do **not** re-run: frame-aligned serving (F-333/F-343, measured worse twice), any context-swap variant (F-337–F-342), or the head-serve (F-347). The one shape left is task #15's smaller one — serialise the streamer's arming so one container's frames run to completion before the next is armed, done at `sub_821BC140`'s 28-byte descriptor walk (`generated/ppc_xenon/ppc_recomp.14.cpp:18805`) where the (record, context) pair is actually born. Acceptance unchanged: `LZX-FRAME … ret=32768` lines past the tenth, `cumprod` climbing, `UIXSF-GOLDEN-REVERIFY pkg=64980000 still_present` past 63,072 **(`kUiXsfFillDryRun` is `false` in the tree — flip it to `true` deliberately, only for a guest-only reading)**, plus a same-binary repeat soak and a per-marker table vs `w193` and vs the adjacent control boot. If that fails, Path B is finished and §4 (the user's decision) is the deliverable.
1g. **The ceiling is now measured and it is destination supply, not decoding (F-354).** `PATHB-HOSTDECODE-CHAIN` prints every destination the guest requests per package with its room and the guest's own record: **exactly two**, for each container, unchanged at 300 s (`w348`, `w349_long`). The three finished containers fit inside two requests (143,069 / 19,337 / 29,655) - that is why one-shot Path A completed them - and the garage's 1,066,057 does not, so F-350's 41.3 % *is* the budget, not progress cut short. Stricter: the 2nd request arrives with **policecam's** `exp=19337` and `inPtr` on the stack, i.e. the shared record `0x6D8F20` was re-used and only our map calls that destination garage's, so unambiguous placement is request 1 alone = **131,072 B = 12.3 %**. The slot question is settled by evidence, not choice: the ten successful frames wrote 327,680 B across `s1..s4` straight through the `50054000 -> 60000000` block jump, so position = **next slot in table order** (F-327's list model, confirmed) - which still does not license crossing into another load's table (F-351). Only two levers remain: make the guest issue **more inflate requests per container with a per-request record** (task #15, now carrying a measured reason), or have the consumer allocate by loading the movie (`nGfx`=0 = section 4, the user's decision). Host-allocated destinations are rejected: memory the loader does not own cannot be consumed, so it would not satisfy (a) in any meaningful sense.
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
`kUiXsfFrameServe=false` `:8731` · `kUiXsfFillDryRun=false` (declared **once**, `static constexpr bool kUiXsfFillDryRun = false;` in `src/gpu_device.cpp` — line ~9269 as of 2026-09-27 02:58; the old `=true` `:8738` entry below was wrong and is the source of the contradiction) ·
`kUiXsfReverify=true` `:8888` · `kUiXsfClearResume=false` `:631` · `kUiXsfLocate=true` `:642` · `kUiXsfAppendWindow=false` `:660` · `kUiXsfPrivateCtx=false` `:703` · `kUiXsfSerializeCtx=false` `:731` · `kUiXsfCompareGuestCopy=true` `:455` (log-only) · `kUiXsfStreamHeadServe=false` (F-347 mechanism proven, measured null; briefly re-enabled as F-349's precondition, OFF again) · `kUiXsfWholeStreamWindow=false` (F-349, refuted by its own success, livelocked) · `kUiXsfChunkedHostFill=true` `:506` (F-350, **the placement that works**) · `kUiXsfFillDryRun` = the same flag declared above (F-350: Path A now writes the garage, so `still_present` measures host+guest, which is the deliverable's own standard) · `kUiXsfFillOwnSlots=true` `:9022` (F-350: overwrite a slot of this container's own chain when it holds the guest's failed decode, never one another package owns) · `kUiXsfLayoutAudit=true` `:9035` (F-352, log-only).

**Net shipped effect:** Path A hosts 3 containers outright; the feed follows the
stream and publishes the correct `st+12`; the third container's placement is
**measuring, and writing** (`kUiXsfGoldenFill=true` + `kUiXsfFillDryRun=false`, the flag's actual value),
and frame-aligned serving is off (tested and reverted, F-333). No unregistered
short-circuit: §7 of `PROGRAM_GUIDE` carries each of these.


## 6. Frontier as of 2026-09-27 04:3x (ledger through F-462) — what the objective's two clauses now rest on

Everything below is measured (soak line, raw word or `file:line`); the earlier sections are kept as
the elimination record. Four routes that this document previously listed as open are now closed by
their own experiments:

| route formerly open | verdict | evidence |
|---|---|---|
| guest-visible Open-gate bit30 for the tune archives (F-452 §3) | **refuted** — armed with read-back, nothing downstream moved | `w455.log:116853`/`:117684` vs `w452.log:122150`/`:122870`; F-454 |
| tag `LISTLINE` with its source path (task #66) | **unnecessary** — `LISTLINE` already self-attributes, and its loader is the *shader* preload loader | 166 × `lr=82187958` + 5 × `lr=82189234`; windows ui 16 / city 64 / cars 62 / characters 22 / effects 17; F-455 |
| `h=0` on the tokenizer's reader as a failure marker | **refuted** — `dev=C64AC100 handle=0` on all 14 lookups, four of which hold correct config text | `F456-STREAMID` (kept, `PROGRAM_GUIDE` §9); F-456 |
| extend Path A to the tune container | **closed on the bytes** — no `memory:$` block is an XMem/RSC container | `F457-MEMBLK` 81 heads, 0 with `52534305`/`EF12F50F`; F-457 |

### 6.1 Where clause (b) actually stops now

`sub_821CC6F0` is **not** a per-file read. From the guest's own recompiled body
(`generated/ppc_xenon/ppc_recomp.17.cpp:3931-3996`) it is
`(obj, r4, offset, dst, count)` → call `[[obj+32]+132]` → `r5' = [obj+24] + offset` → call
`[[obj+32]+28](r4, r5', dst, count)`. Census of all 14,363 such calls in a boot: `r3` always
`C64AC100`, `inner=[r3+32]` always `C6537780`, `r4` always the request block
`C64B7600[98B0D2B1 F77F0000 0 0]`; the only variable is the offset, and it takes five values
(`64CA7B89` ×10,251, `0035A000` ×1,287, `64CB0000` ×1,216, `649763D7` ×1,005, `000A0000` ×604) — all
absolute offsets inside `xarchive_cache.rpf` (F-462). **The nested tuning archive's own offsets
(`0x48000`, `0x68000`) never appear**: the guest does not read the nested archive through this stream
at all. F-459's 198 zero-byte rows inside the tune window are therefore meshtextures package refills
(F-457's stale-record spin), not mount traffic — that attribution is corrected in F-462 §3.

Two host-side layers also matter, both new since §4 was written:

1. **`READWRAP-SERVE` has been unreachable since F-091/F-126.** The call site
   `src/gpu_device.cpp:14753` passes `tocEntry=0` and `handle=0xFFFFFFFF`, and only the `tocEntry`
   index can still return true; every other index logs `T413O-SKIP ... would-serve` and falls through
   to `return false` (`:1713-1780`). `READWRAP-SERVE` = 0 rows in `w452`/`w457`/`w460`/`w462` while
   `w460` carries 72 `T413O-SKIP` rows naming bodies that existed (F-461).
2. **Re-arming it by device scan is unsafe and was reverted.** All 7 resolutions named the wrong file
   (`r5=64CB0000`, raceeditor's package, resolved as `garage.xsf`; `64980000` as `legals.xsf`) and
   activating the deliberate w21/w22 `r7==0` `READWRAP-R7Z` lever re-armed the inflate loop:
   `INFLATE-ENTER` 2,378 → 95,913, with the late-boot samples (`W34-NOGFX`, `nGfx=0`, `REVERIFY`)
   lost. Reverted; exe verified back to 57,442,304 bytes (F-461). `PROGRAM_GUIDE` §7 still lists the
   marker as rare at a stale `:9818` — it should read unreachable-by-construction plus
   bypassed-by-lever.

The tune file's own open **does** yield a stream (`BDF20`'s printed field is the stream object
address, settling F-445): the three `.rpf` preload archives each get `0x82860C40`, while
`tune/vehicle/vehicle0008.lst` yields `0` — no stream at all (F-458 §1). And the nested archives are
not present in mountable form: at their TOC offsets the raw bytes are high-entropy with no `RPF3`
header, and exactly one `RPF3` exists in the first 64 MiB — the outer archive's own (F-458 §2,
extending F-442). Upstream offers no help here: the local `.research/xenia` checkout has no
`rpf`/`file_archive` device and no AES key table at all (checked 04:3x in
`src/xenia/vfs/devices/`), so the transform used on those members is title-side and we do not hold it.

### 6.2 The two routes that remain, with their cost

| route | shape | acceptance | cost / owner |
|---|---|---|---|
| **R1 — per-stream record** (task #15) | a `(record, context)` pair per 28-byte descriptor created inside `sub_821BC140`'s walk, `generated/ppc_xenon/ppc_recomp.14.cpp:18805` | at the tune-open millisecond the place pass must inflate against a window whose `pkg` is the tune archive with `*srcSz(in) >= member size` (today: 20 bytes of meshtextures' bounce tail, F-457), holding `LZX-FRAME` 32, `REVERIFY pct>=94`, `LISTLINE` 171, `C0000005` 0, `BC140-REC` 7 and one `F434-SPIN-BREAK` | re-plumbing inside guest-owned structures — a new build class, not a hook; the only route that also serves clause (a)'s last 14 % |
| **R2 — observe the nested mount itself** (T42.8, task #71) | log-only probe on `obj=0x82860C40` inside `sub_821BE250`/`sub_821BE4F0`: print the resolved target offset, whether inner vtable `+132`/`+28` were entered, and what the device answered | the first row that shows a read *attempted against* `0x48000`/`0x68000` — or proof that no such read is ever issued, which would move clause (b) out of emulator reach entirely and into the missing-key problem | one build, low risk; its negative result is decision-grade |

Ruled in for neither column: any serve/filter/gate variant at `CC6F0` keyed from the device (F-461
proves the key must be the request's offset, and no tune offset ever arrives there).

### 6.3 Clause (a), restated with the current numbers (unchanged in substance)

Path A decodes 3 of 4 UI `.xsf` byte-exact into guest memory (`raceeditor 143,069 pct=100`,
`policecam 19,337 ×2`, `credits 29,655`), the garage at `claimed=851,968–917,504` of `1,066,057`
with `still_present` 94–100 % of the claim (`w455`/`w460`), the residual being destination-supply
bound (F-354/F-431) and addressable only by R1 or by host-allocated destinations, which the user has
rejected. `nGfx` remains 0 and is now known to have never been a working GFx counter (F-437); the
event counter `F438-GFXCTOR` with a fired control shows the guest never calls the GFx loader ctor
(F-438), the handler registry is never read (F-440), and the boot-worker queue is only memset
(F-441) — so clause (b) is not downstream of clause (a), and this document's §2/§3 conclusions still
hold.

### 6.4 What would let the objective be called done

(a) is at its measured ceiling and needs no further claim. (b) needs either R1 to land and the tune
sections to resolve (`F442-SECTION` with real tuning text in the buffer, `[0x828CD0A8]` raised above
0 by the guest's own walk) and then `F438-GFXCTOR` to print rows the guest produced, or R2 to show
that no read of the nested archive is ever issued — in which case the remaining blocker is the
archive's transform, and that is a content/key question rather than an emulator one. Until one of
those two is measured, the objective stays open.

## 8. Frontier as of 2026-09-27 05:4x (ledger through F-470) — the enqueue gap is reframed: pacing, not construction

Everything in §6 through F-462 stands as a record of what was excluded. Three new measurements
(F-468's failed experiment, F-469's read-only snapshot, F-470's static read) replace the *model*
that §6.2's R1 was built on, and they change what "Path B" has to mean.

**8.1 The four UI containers are all enqueued, each with a record holding its own full length and
package offset.** `F469-RECSNAP` (`src/gpu_device.cpp:13853-13878`, `w475.log:3450,4652,5497,6983`)
prints the record array at every queue push: garage = `[2 00000002/1066057/64980000]`. So the
F-186/F-187 premise ("opened but never enqueued") is closed as **false**, and no record-construction
task can be the fix, because there is nothing missing to construct.

**8.2 A streamer handle is `(generation << 15) | record_index`, and the dispatch routine throws the
generation away before it reads anything.** `ppc_recomp.14.cpp:18850-18874`: `lwz r11,0(r26)` →
mask with `[0x8283D190+24]-1` → **`stw r9,0(r26)`** → `rec = [0x8283D190+52] + index*28`. It then
reads only `record+4/+8/+16/+24` and never `record+0`, so there is no validity check to satisfy.
Two jobs whose handles differ only in generation resolve to the same record (`w475`: `id=4` and
`id=0x8004` → `rec=C9E24970`).

**8.3 Each push re-stamps the previous container's slot, 22-30 ms later, and every job but the first
dispatches after that.** Push→dispatch waits vs record windows: `0/22` **MATCH**, `76/28`, `781/29`,
`794/25`, `1022/25`, `2691/2213`, `1596/-` all foreign. The single job that read its own record is
the single package at `pct=100` (`pkg=64CB0000`, 143,069 B). One producer thread (`tid=00005A6C`,
`lr=821BC8F0`, pushes #2-#4 from a loop at `sub_821E606C`/`sub_821FDDDC`) never waits on the
consumer (`cnt` 1→4).

**8.4 So R1 ("per-stream record inside `sub_821BC140`") is replaced by two questions, and the first
is cheap and read-only.** T42.14: time `sub_821BC140` entry→exit and record which of its returns the
job took. That decides whether the 22-29 ms window is missed *inside* the routine (the consumer is
slow → the inflate/feed is the lever) or *before* it (the worker is parked elsewhere → this is the
clause-(b) thread, F-394/F-395). Only after that split is a pacing intervention definable, and any
intervention that writes record *values* is pre-excluded by §8.2: the guest will not notice, and the
slot belongs to the next container within 25 ms.

**8.5 Standing rule earned.** F-467 inferred an index-space law from a snapshot taken *at our own hook
site* and F-468 then acted on it; both were artifacts of when our code ran. **A structure read at one
hook site says nothing about the value a *later* dispatch will see — pair an enqueue-time snapshot
with the dispatch-time read of the same field before naming a mechanism.** `F469-RECSNAP` +
`BC140-REC` in one log is that pair, and it is now the reference instrument for this subsystem.

### 8.6 T42.14 and T42.15 answered (F-471/F-472) — the pacing is the title's, not ours

`BC140-REC ↔ POST-EXEC-START` pairs give per-job execution time without a new instrument, and the one
build that split host from guest time (`pre=`/`guest=` on the existing `POST-EXEC-START` line,
`src/gpu_device.cpp:12826`) says: on the four UI containers **our host work is 0 ms and the title's
body takes 21-590 ms**. So the consumer is saturated inside `sub_821BC140`, idle only 1-32 ms between
jobs, and the 22-29 ms record window is unmeetable by design of the title's own loop, not by our
decompression cost.

That leaves exactly two shapes for the remaining work, and they are now separated by a measurable
target rather than by taste:

- **(B) pool-index route (task #15's surviving form).** Job #1 reached `pct=100` because its record
  was intact *at entry*; it then ran 99 ms and the fields it re-reads mid-body (`record+8` device,
  `record+24` package offset — F-470 §2) were the garage's. So the test for any construction is:
  does a **second** package reach `still_present == claimed == goldsize`? That is a one-soak gate,
  and it fails closed — it cannot be satisfied by writing values, only by giving a job a record that
  survives its own body.
- **(A) iteration-count route.** F-393 measured that the body's only exits are `inLeft==0` and
  `outLeft==0`; shortening the body means feeding it so those conditions are reached sooner. That is
  the Path A serve side, which we already own, and it must be measured by the body's own `guest=ms`
  column rather than by a counter of our calls.

### 8.7 The pool contract, as far as it is known (F-473)

`sub_821BCB10` is the enqueuer and it is the only place the title checks a record's identity:
`index = handle & (cap-1)`, require `record[index].+0 == handle` **and** `record[index].+8 != 0`, else
branch to its reject path (`ppc_recomp.14.cpp:20499-20543`). It fires 7 times per boot and each `a0`
is exactly the handle F-469's snapshot then finds in that record (`w476`: `ENQ #2 a0=00000002 …` ↔
`F469-RECSNAP #2 … [2 00000002/1066057/64980000]`). Two call sites only: `0x821BD614` and `0x821E5EF8`
(inside `sub_821E5E58`, the frame F-469's stack walk shows under every loader push).

So §8.6's route (B) is now a contract with two admissible shapes, and both are testable without
touching a record's contents: keep `record[index].+0` equal to the handle for the job's whole body, or
allocate the job a record the enqueuer has never validated. The missing term is the **release** site —
who clears or bumps a `+0` — and #76's remaining half is exactly that.
