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
| (a) UI `.xsf` containers decompressed **in guest memory** | **3 of 4 at 100 %, garage 5.9 % by the guest / 64.9 % with host placement** | `w285`/`w295`: raceeditor `compared=143069 mismatch=0`, policecam `19337/0` ×2, credits `29655/0`; `w297`: garage `still_present=63072 pct=5`, `w296`: `pct=64` |
| (b) **…so GFx can initialize** | **NOT achieved**, and NOT downstream of (a) | `MOVIE-CTOR` = 0 and `UILOAD-census` = 0 in every soak `w273`→`w308`, including the one where all four containers were placed (`w295`) |
| Evaluate Path A (host LZX) | done, §2 | F-295…F-333 |
| Evaluate Path B (guest descriptor construction) | done, §3 — mechanism identified (F-332 §4); four serve designs closed by measurement | F-318…F-335 |
| Concrete implementation plan with file:line citations | this document | — |
| Implement + validate vs `w193` by soak census | done: 15 changes built/soaked/censused, 6 reverted on evidence (latest `w316`→`w317`) | `w274`–`w317`, `tools/soak_census.py` |

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
1c. **A codec context PER UI stream** — **implemented in F-337, reverted on a boot regression that is OURS, not the hypothesis's.** The replay works (`r7` is unread by the wrapper; `r6=0x3492E` is the size) and the republish works (the static slot `0x8283D1B0` held `*obj = 0x4000FD80` and took the private ctx), but `mem.Alloc(0x35000)` returned `0xCAF28300` — the address the XSF serve window already uses — so the context and its own compressed input aliased, and the boot went shallower (27,760 lines, INFLATE-ENTER 32, no garage reverify). **Pre-flight before retrying: allocate the private ctx once at startup at an address asserted disjoint from every serve window, then re-run the same acceptance test.** Everything below is F-336's finding, which stands. 1c. **A codec context PER UI stream** — rewritten by F-336, which found the reason every serve design failed: the codec ctx at `0x4000FD80` is opened TWICE in an entire boot (`XMEM-OPEN-CENSUS wrapper=2 caller=2` against a control that fires on all 4,901 inflate entries), so the garage inherits a context whose walk state and history belong to another container. The old framing of this step (“reach the guest's own reset”) is wrong — resetting a shared context does not unshare it. Recipe: allocate a block the size the guest uses (the two observed contexts sit `0x34940` apart ≈ 215 KB) and call the guest's own Open wrapper `sub_82460370(r3=0x8EFFF990, r4=1, r5=newblock)` — the exact call that produced `4000FD80` — then publish `*obj = newblock` for that stream so `sub_821D5E10`'s `r3 = *obj` picks it up.
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
Gate: **per-marker**, never line totals (F-072) — boot-to-boot variance is
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
`kUiXsfBoundUnc=true` `:7991` · `kUiXsfVerify=true` `:8136` ·
`kUiXsfHunt=true` `:8174` · `kUiXsfGoldenFill=true` `:8376` ·
`kUiXsfFillListOrder=true` `:8395` ·
`kUiXsfFrameServe=false` `:8442` · `kUiXsfFillDryRun=true` `:8449` ·
`kUiXsfReverify=true` `:8599` · `kUiXsfClearResume=false` `:631`.

**Net shipped effect:** Path A hosts 3 containers outright; the feed follows the
stream and publishes the correct `st+12`; the third container's placement is
**measuring, not writing** (`kUiXsfGoldenFill=true` + `kUiXsfFillDryRun=true`),
and frame-aligned serving is off (tested and reverted, F-333). No unregistered
short-circuit: §7 of `PROGRAM_GUIDE` carries each of these.
