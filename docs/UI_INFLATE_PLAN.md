# UI `.xsf` inflate — consolidated plan and Path A / Path B evaluation

Written 2026-09-26 (ledger through **F-330**). This is the single reference the
objective asked for ("evaluate Path A and Path B, produce a concrete plan with
file:line citations"). Evidence lives in `docs/ROOT_CAUSE_VALIDATION.md`
(F-244…F-330); flags/short-circuits in `docs/PROGRAM_GUIDE.md` §7; markers in §9.
Every claim below carries a log line or a `file:line`; nothing here is inferred
from an earlier summary.

## 0. Objective, and the honest score

| Requirement | Status | Evidence |
|---|---|---|
| (a) UI `.xsf` containers decompressed **in guest memory** | **3 of 4 at 100 %, garage 5.9 % by the guest / 64.9 % with host placement** | `w285`/`w295`: raceeditor `compared=143069 mismatch=0`, policecam `19337/0` ×2, credits `29655/0`; `w297`: garage `still_present=63072 pct=5`, `w296`: `pct=64` |
| (b) **…so GFx can initialize** | **NOT achieved**, and NOT downstream of (a) | `MOVIE-CTOR` = 0 and `UILOAD-census` = 0 in every soak `w273`→`w304`, including the one where all four containers were placed (`w295`) |
| Evaluate Path A (host LZX) | done, §2 | F-295…F-330 |
| Evaluate Path B (guest descriptor construction) | done, §3 | F-318…F-330 |
| Concrete implementation plan with file:line citations | this document | — |
| Implement + validate vs `w193` by soak census | done: 8 changes built/soaked/censused, 3 reverted on evidence | `w274`–`w304`, `tools/soak_census.py` |

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

**The wall, localised by measurement (F-330).** At container offset `0x8000` the
guest's 32 bytes appear **nowhere** in the golden within ±4 KiB
(`NOT-IN-GOLDEN-NEIGHBOURHOOD`) — not a shift, so not our slicing. The guest
decodes exactly one `0x8000` block and then produces unrelated bytes at the
block boundary. Remaining suspects, all guest-side:

- the lazily-initialised **single decoder instance** at `0x828D38D8`
  (`sub_82460420`, `generated/ppc_xenon/ppc_recomp.82.cpp:12099`, guarded by
  `lis r31,-32115; lwz r11,14552(r31); if (r11 != 0) reuse`) — one shared
  decoder for every stream;
- the per-block call the real streamer makes at a block boundary
  (`XMemDecompressEx`-style frame step) that `sub_821D5E10`
  (`ppc_recomp.18.cpp:10832+`) is not making;
- `[ctx+4]` codec gating in `sub_8244FF20` (`ppc_recomp.80.cpp:15600`) is
  **excluded** — `ret=00000000` in `XMEM-SZPTR` proves it passes.

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

1. **Read the guest's block-boundary path** (static, zero builds): `sub_82460420`'s
   body after the singleton guard, and `sub_82461010`. Acceptance: name the field
   or call that differs between block 0 and block 1, or record that none exists.
2. **Observe the singleton**: log-only census of `0x828D38D8` per inflate entry
   (fold into `INFLATE-ENTER`, per F-133). Acceptance: show whether one decoder
   instance serves both the garage and other containers, interleaved.
3. **Only then** attempt a per-block re-init — the intervention this session
   deliberately did *not* make, because every prior attempt varied input while
   F-330 says the input was already correct. Acceptance:
   `UIXSF-GOLDEN-REVERIFY … still_present` rising past 63,072 **with
   `kUiXsfFillDryRun=true`**, i.e. guest-only output. Anything measured with the
   fill active is not evidence of guest progress.
4. **Keep the placement instruments** (`kUiXsfGoldenFill` + dry run) as the
   measurement harness, not as a fix: they are what make "who produced these
   bytes" answerable, which is the question three of this session's reversions
   turned on.
5. **GFx**: take §4 to the user as a decision with the elimination chain attached;
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
`kUiXsfTailTopup=false` `:609` · `kUiXsfBoundUnc=true` `:7919` ·
`kUiXsfVerify=true` `:8064` · `kUiXsfHunt=true` `:8102` ·
`kUiXsfGoldenFill=true` `:8304` · `kUiXsfFillListOrder=true` `:8323` ·
`kUiXsfFrameServe=false` `:8354` · `kUiXsfFillDryRun=true` `:8361` ·
`kUiXsfReverify=true` `:8511`.

**Net shipped effect:** Path A hosts 3 containers outright; the feed follows the
stream and publishes the correct `st+12`; the third container's placement is
**measuring, not writing** (`kUiXsfGoldenFill=true` + `kUiXsfFillDryRun=true`),
and frame-aligned serving is off. No unregistered short-circuit: §7 of
`PROGRAM_GUIDE` carries each of these.
