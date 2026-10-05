> **Relocated 2026-10-01** from `docs/LONG_TODO_MASTER.md` Â§0: the 18 superseded dated state blocks (2026-09-20..09-25, formerly lines 550-969, `## 0-newest.` through the last `## 0b.` trail). Nothing was deleted â moved verbatim.
> Grep THIS file (not the live one) for any superseded 09-20..09-25 claim; the live file carries a pointer where the trail used to sit, and `## 1. Rules` now follows the keep-zone directly.
## 0-newest. State (2026-09-25 ~05:08, **F-226→F-236: UI-inflate objective RESOLVED; `nGfx=0` end-state DEFINITIVELY gated on a peer-owned rebase/effects-place LIVELOCK, NOT the UI `.xsf`**) — supersedes the F-226 "trace the 0x40003B03 producer" framing below (that lead is closed: F-227 proved host dispatch healthy; F-229/233/235 traced the real block far upstream)

The F-186/F-187 UI-inflate-enqueue objective is fully evaluated, implemented, and soak-validated (`w231`–`w244`): Path A DEAD (F-191, XMem LZX≠CAB); Path B enqueue FUNCTIONAL + the 4 UI records executable (F-205/213). It is proven NOT the `nGfx` gate by a cascade of upstream findings: UILOAD(`sub_822C0980`) is unconditional inside gate `sub_82131008` but the gate is only msg-handler `0x40003B03` never dispatched (F-226/227, host dispatch healthy); the bootstrap main thread never reaches it because it is stuck in the shader/effects PRELOAD reader (`sub_821CFAA8`→`sub_821BE4F0`, F-233), and a 600 s soak (`w244`) proved that reader/loop is a **hard, non-converging rebase-poison LIVELOCK** — `REBASE-POISON n=3,368,026 … skip D890 fatal`, `RenderThread frame=0`, `UILOAD`/`XSF-INFLATE`/LoadBytes all 0 → **the UI `.xsf` are provably NEVER decompressed** (F-235). F-236: the livelock's root is the 17-entry host rebase map (`g_mclaRebaseMap`, `gpu_device.cpp:3835`) missing almost every lookup on the UI resource object `B7B41000` (`P10-MAP`=1 hit vs `P10-GATE`=49,731 poison misses). **Verdict: #1–#3 met (plan = F-226→F-236); #4 end-state is blocked by the peer-owned rebase/effects-place livelock (task_dispatch_trace.cpp:517/777 sub_8217D890 rebase-miss), 3+ stages upstream of the UI pipeline — NOT a UI-inflate fix, and F-055 bars forcing.** Next real `nGfx` work = T41.10 (repurposed: populate/repair the rebase map for `B7B41000`'s children, or stop the poison entries at their serve source) in the peer's effects/serve/rebase domain. Flags OFF; source==baseline exe 97,596,928; no commit; next F-id F-237.

## 0-prev. State (2026-09-25 ~03:38 — **F-226 grounds the exact `nGfx=0` gate via headless IDA; the UI `.xsf` inflate (F-186/187) is confirmed NOT the lever; next = trace the boot-worker message producer (T41.10)**)

The F-186/F-187 UI-inflate-enqueue objective is fully evaluated (Path A dead F-191; Path B enqueue functional F-205/213), implemented, and soak-validated (`w231`–`w239`), and F-226 now proves *why* it can't raise `nGfx`: **decompression runs and produces output** (`GFXINIT`=1 at `lr=82304278`; `INFLATE #3 consumed=2284`; peer `src:7591` "XMem produced 44365500") yet `nGfx=0`. IDA (`decompile`/`get_xrefs_to`/`read_memory_bytes` on `default.xex`) located the real gate: UILOAD `sub_822C0980` is called **unconditionally** inside boot-gate `sub_82131008` (its two `sub_821C0750` event-checks are `nullsub_8` no-ops; only the `dword_8288E6F0==0` atArray-init branch is crash-prone), but `sub_82131008` is never a `bl` target — it is the message-handler for id **`0x40003B03`** in the `{handler,msgid}` table @`0x82102aa0` (installer `sub_82131508`=`0x40008503` publishes the UILOAD r3 `dword_82830998` at the tail of boot thread `sub_82131790`). That message is drained by boot worker `sub_8242FB88` off its item queue (base `0x40004B40`, cursors `ctx+56/+60`), which `w239` shows is **never produced into** (`W36b-QUEUE qWrite=qRead=0 delta=0`; `THREAD-CREATE #12 start=8242FB88`; `WAIT lr=8242FC1C`; `W35-BOOT-GATE`=0) → worker parks → UILOAD never runs → no GFx `vt 0x82073xxx` loader → `nGfx=0`. This CORRECTS the F-207 "sole caller `0x82119c04`" model (that was F-210's data-table false positive) and the F-217 "entire GFx path inert" overstatement. **Next task = T41.10** (trace the `0x40003B03` producer through the 3 `KeInsertQueueDpc`(`0x8242FD00`)-as-funcptr sites `sub_8241C308+0x238`/`sub_8241CB08+0xa8`/`sub_8242FEF8+0x10c`; likely peer kernel + recompiler-stub territory). **do-not: no more UI-inflate/enqueue/serve mitigation; F-055 bars forcing the gate (`src/gpu_device.cpp:1474-1644`); don't touch `kInflateIntervene` (F-194).** Flags OFF; tree==`w230`(`w239`); no commit; next F-id F-227. See `HANDOFF` F-226 block + `ROOT_CAUSE_VALIDATION.md` F-226.

## 0-prev. State (2026-09-25 ~01:43 — **Path B host-hook enqueue CONFIRMED DEAD (F-204b); `record[+4]` is NOT the blocker; only unlock = peer `kInflateIntervene` serve framing**; supersedes §0-new's "Path B turnkey" plan)

Both objective paths are now exhausted as host-side levers, verified by three un-confounded build+soak cycles this session (`w231`/`w232`/`w233`, all reverted; `w234`==`w230`). **Path A** dead (F-191, libmspack≠XMem). **Path B**: §0-new's recipe (re-issue the async `FDD50`/`E5E58` request per UI container) was implemented and cleanly measured — a *single* `FDD50` open fed the **exact** static `arg0` `E2940` uses (`raceeditor`0x8201BAAC etc., tag 0x8201BB28, count 27) still produces `record[+4]=0` (`+24` pkgoff resolves), and a host `+4` seed never even fires because the executor livelocks **upstream** on `XMEM src=CAB28300` (the peer re-point feeding a semaphore handle, F-194/195/196/197). So the earlier "+4 is the blocker / register them so it's non-zero" line (F-203) is wrong: **`+4` isn't achievable via async and isn't sufficient anyway.** Full evidence + file:line in **F-204/F-204b**. **The single remaining unlock is UI serve framing inside `PPC_FUNC(sub_821D5E10)` (`src/gpu_device.cpp:7487`) / `MclaForceServePkgForDest` (`:7765`)** — peer-owned streaming code (uncommitted F-188–F-203 edits); make the re-point serve the real RSC5+XCompress body (magic `0x0FF512EF`, non-zero `inLeft`) not `CAB28300`. `nGfx` still 0. **do-not #9: no more enqueue/re-point short-circuits.** Tree flags all OFF; ledger next ID **F-205**.

## 0-new. State (2026-09-24 ~19:43 — **Path A closed, Path B made turnkey (F-191)**; supersedes §0x's blocker framing for the UI gate)

UI `.xsf` still `nGfx=0`; the menu blocker is unchanged in *frontier* but the *decision* moved. A peer session has F-188/F-189/F-190 (host libmspack LZX + `sub_821E2940`-hook) uncommitted in `src/gpu_device.cpp` (edited 20:56) — **do not stack a second decode on it.** **F-191** settles Path A with an offline harness (`tools/lzx_raceeditor_proof.c` → `build/lzx_raceeditor_proof.exe`, no boot): libmspack's CAB-LZX decodes `raceeditor.xsf` only to **131072 B (4×32 KiB) then `rc=11` DECRUNCH** under every strategy (per-frame, concat, shared) and reset_interval {0,1,0x8000}; `window_bits=17` is the only window giving the valid `DIU` head. Xbox-360 **XMem LZX ≠ CAB LZX** — no host decode reaches full size, so `kHostLzxDecode` will refuse-partial to `XSF-LZX-FAIL`; w202+ soaks of Path A are pointless. The only working 360 LZX decoder is the guest's own `XMemDecompress`. **Path B is now implementation-ready with the ABI decoded from `generated/`** (no IDA needed): `sub_821FDED8` opens each UI container via `sub_821E2940(streamerSlot,path,tag,r6=27,0)` (`ppc_recomp.23.cpp:15963…16053`) but never issues the async request the meshtextures use (`sub_821FDD50`→`E5FD0`→`E5F48`→`E5DC8`(open)+`E5E58`(enqueue)→`BCB10`). Recipe + field map (`I`+0=ctx,+4=slot,+8=handle,+12=sec; `D`+0/+2=u16 counts,+4=12B entries) in **F-191**. Next: after the peer reverts `kHostLzxDecode`, add a per-UI-container request re-issue in the existing `sub_821E2940` hook (`gpu_device.cpp:10200`) and soak vs `w193`.


The preload chain now works end to end for five of the six lists: spans are registered at the guest's first archive I/O, `LISTLINE 79→167`, `'not preloaded properly' → 0`, and `shaders/effects/dcl/star_glow.dcl` opens `ret=1`. This is the committed default (`kExpandListInArchive = true`) and it costs the `C0000005 0` invariant: 50 AVs at the host-completed stream-wrapper site are the new top blocker (T41.4a), then the pre-existing `'swfCMD::Fixup'` fatal and B4. Old frontier is one constant away (`false` → `w96`/`w81`/`w72` exactly). `w98` is the new baseline for every comparison on this branch.

## 0y. State (verified 2026-09-24 02:30 JST — B2's transform settled by F-105; supersedes nothing, adds the seam result)

`*.list` members are raw DEFLATE name lists (all six, expanded length == stored length), `src/raw_inflate.h` reproduces them, and the only seam that makes the guest consume the content is the archive read (`RpfVirtualFileSystem::ReadFileAt`, behind `kExpandListInArchive = false`). With it on, the guest opens the eight textures the list names and then stalls on a 0-byte `C000000D` read of the page holding the named member — that read is T41.3r and is the next gate item. `w78` is the default-tree baseline (`== w72`/`w58`: `C0000005 0`, `Fatal error 2`, `GFx 3`, `GETDEV 168`, `TOC76 334`, `CP-DRAW 52`, `DRAW_INDEXED 0`); `w75`-`w77`,`w79` are poisoned/cause-finding and must not be cited as progress. **F-107 (00:05):** loader reads 77 real names line-by-line on the seam-ON branch (`w84` = its baseline); remaining gap = `effects` list never reached, single `BE250-GUEST` fall-through on wrapper `0x82860C68` (25 KB read / 4 KB buffer) is T41.3t. **Corrected 02:45 by F-106:** the wedge was our own guard-page witness (`gle 998` ERROR_NOACCESS on a page a host `::ReadFile` was targeting), not the guest's paging; with the arming retired, seam-ON `w80` runs all six expansions with ZERO failed reads and `GETDEV 680`/`TOC76 1176` — that is the recommended B2/B3 working branch and its baseline. B3 unchanged; B4/B5 still behind the fatal.

## 0z. State (2026-09-23 — TWO-TREE MERGE LANDED; supersedes every split-tree warning elsewhere)
- `E:\mcla pc` is again the PRIMARY tree: source of truth for src+tools+docs+skills AND the only working
  git repo. `C:\mcla-pc` is RETIRED to read-only archive (its live value was copied here; the frozen
  provenance snapshot is `E:\mcla-c-snapshot-20260923`). Do not build or soak on C: anymore.
- Historical note (how the split happened): the build had moved to C: on 09-21 when E: build/ rejected
  new files; that relocation is now being reversed — see ACCEPTANCE GATE below for whether E: can build.
- Provenance: src+tools from frozen snapshot (cmp-verified); gpu_device.cpp
  true 3-way merge (base 4280c9d; both conflicts = convergent T41.3d/F-066 + F-063 fixes, C wording kept,
  E-only gate census restored); ledger = C base with E's F-069/F-070 spliced before F-077; §2 gains the
  ten T41.3g..n2 items below. Pre-merge E state: commit 35912f0.
- ACCEPTANCE GATE (not yet done): the merged tree has never compiled. Configure + build on E:; if E:
  build/ still rejects writes, fall back to a fresh build dir (`cmake -B build2`) and update this block.
## 0a7. State (verified 2026-09-20 21:31 — the RPF3 format reference is RECOVERED; F-074)

- **`docs/MCLA_RPF3_Technical_Reference.txt` is back** (591 lines, from `82cb758`; destroyed by `5fbc08e`'s
  docs purge). It is the spec `src/fs/vfs_rpf.h:16` was written against and still cites.
- **It names the false assumption outright:** the VFS comment claims file data is **STORED**
  (`file_size == uncompressed`, "no XMem LZX decode is needed") while §7 says compressed iff those differ —
  and all six `.list` members differ (1.96-3.76x). §8 = XMem **LZX**, and the guest's own decoder works
  (`XMEM` 22x, all `ret=0`). So the archive gap is not a mystery: §5's `data_offset` is absolute and the
  region between RSC5 packages is ordinary member data.
- **Reads that were guesses are now decodable** (T41.3e5): §5's 16-byte entry layout + §10's filename
  hashes replace `XsfOffsetCandidates`'s five-branch word guessing — but one census first, because the
  host's in-memory quad does not yet line up 1:1 with §5 (F-074(6)).

## 0a6. State (verified 2026-09-20 21:18 — F-072 methodology: the aggregate counters are NOT comparable)

- **Use per-marker counts, never `host short-circuit lines`.** Four soaks / three builds: identical source
  gives 98 → 176 on that gauge (**±78**), `[warning]` ±431 and `INFLATE` ±116, while `C0000005` 0, `GFx` 3,
  `Fatal error` 2, `PRESENT` 68, `DRAW_INDEXED` 0, `swfCMD` 2, `GETDEV` 185, `CP-DRAW` 24, `MSGBISECT` 35,
  `PKG-SUBST` 19 and *"fault-line lr: none"* are **bit-identical in all four**. Any claim about mitigation
  totals needs a same-source repeat run beside it (F-063's 177→96 predates this rule).
- **The T41.3d plateau reproduces**: `build/w38w.log` is a fresh same-source soak with 0 AVs and the same
  frontier (`swfCMD::Fixup - unknown type`). Baseline stays **`build/w38t.log`**; `w38w` is its duplicate.
- **Inflate branch data (F-071(5))**: 30/40 hook entries take no re-point branch, 9/40 do, and the source
  `magic` is a real XCompress head in **1 of 40** — the guest's inflater is fed non-containers. Tree is
  back to T41.3d only (census block reverted, exe 00:13 = that source).

## 0a5. State (verified 2026-09-20 23:49 — T41.3d BUILT + SOAKED → F-067; supersedes §0/§0a4's baseline)

- **`build/w38t.log` is the new baseline** (exe 23:45, `BUILD_RC=0`, `BOOT_RC=124`, 11,072 lines).
  Deleting the `star_glow`→`rage_im` substitution took **`C0000005` 2 → 0** — no access violation in any
  120 s soak for the first time in the project — plus `VEH W0: parking thread` 1 → 0 and `[error]` 51 → 41.
  The guest now gets past the effect loader and back to **`swfCMD::Fixup - unknown type`** (T38.4), `swfCMD` 0 → 2.
  `DRAW_INDEXED`/`DRAWDISP` 0 and short-circuits 96 → **98** (the guest reaches two more absorbing paths).
- **F-066's "the archive is the only route" was wrong, measured:** the guest asks
  `a:/archive/fxl_final/star_glow.fxc` and `GETDEV` returns **0** for it while the *same* prefix, same
  vtable, same array resolves `a:/archive/resources/ui/*.xsf → C60AC180` (`w38t.log:3891`-`:3893` vs
  `:1903`). The guest's own fatal says **`it probably wasn't preloaded properly`** and
  `shaders/effects/preload.list` is served 8× in the same soak ⇒ **T41.3e** (preload, not archive).
- **Do not read this soak's `UILOAD 0 → 1`:** the single match is the substring in the host's own
  `W34-NOGFX …UILOAD/EF220 never armed` line (`w38t.log:5637`). UILOAD is 0 in substance. Same class as
  do-not #22; scoping that row is folded into T41.4's leftovers.

## 0a4. State (verified 2026-09-20 23:38 — read-only forensic session; adds F-065 + F-066, changes no §0 state)

- **The terminal fatal is caused by a host mitigation that cannot work (F-066).** `star_glow.fxc` is
  legitimately absent from the 15 embedded `fxl_final/*` files the host seeds
  (`src/boot_host.cpp:328-344`; names are full archive paths, read from the image), so
  `AFB76-FALLBACK` substitutes `rage_im`'s body — which contains the obsolete `drawblit` technique at
  `buf+0x1365`, guaranteeing `'drawblit technique is old and busted'`. **No embedded blob holds any
  `star_glow` key name** (measured over all 15) ⇒ the only untried branch is an honest miss: **T41.3d**.
- **F-063's lookup #6 argument is misidentified:** `r4=8200934C` is the string `drawblit`, not
  `draw_starglow` (`0x82040EE0`), so `sub_822FBAF8` never reached its first real `star_glow` lookup.
- **T41.3 step 2 is re-scoped (F-065):** the `{handler,msgid}` array is confirmed and its bounds are the
  PE **EXCEPTION directory** (`VA 0x82102A00`, size `0x27338` = 12,902 records), but a whole-corpus scan
  found **no** `lis/addi` reaching the pair area (14 sites, all in the `0x82128xxx` tail) — stop hunting
  for a literal walker; find who *stores* the directory value. Related known gap: `RtlImageXexHeaderField`
  is a stub (`src/kernel/imports.cpp:1377`) with 5 guest call sites, 0 fired in `w38s.log`.

## 0a3. State (verified 2026-09-20 23:25 — read-only TLS session; adds F-062, changes no §0 state)

- **`sub_821873E8` is decoded: `TLS[12] -> vtable[+8](TLS[12], 72, 16, 0)`** — a **per-thread scratch
  allocator**, not a device or a list (`generated/ppc_xenon/ppc_recomp.9.cpp:4749-4800`). So T38.3(d)'s
  fabricated 16 B object + 72 B block has the right *shape* (F-045) and now a named meaning.
- **Two causes of `slot12=00000000` are refuted, do not re-derive them:** the XEX TLS *template*
  (`TLS_INFO` @ file `0x11D4`: `slot_count=64`, `raw_data_address=0x8294A800`, `data_size=0x94`) is
  **all zeros except slot 14 = `0xFFFFFFFF`**, so copying it cannot yield slot 12; and `_xstart`
  (`0x821322B8`, = PE `AddressOfEntryPoint`, confirmed two ways) **is** called
  (`w38q.log:38, :131`).
- **The surviving structural defect:** `src/kernel/guest_thread.cpp:9-30` already implements real
  per-thread TLS (`TLS_SIZE = 0x100` = exactly 64 slots), but `src/boot_host.cpp:260-286` fabricates a
  fixed block at `0x8F200000` with **one** slot filled, and **25 sites** hard-set
  `r13 = 0x8F200000` (21 in `gpu_device.cpp`) — every guest thread aliases one TLS array, and
  `src/gpu_device.cpp:1071-1090` writes a fabricated allocator into the shared `tlsTable + 12`.
- **Negative result:** the TLS[12] producer is **not findable by text scan** — three scans failed
  differently (5,826 false positives / 0 from missing the indexed `stwx` idiom / 6 offset-12 hits that
  are container inserts). Recorded so the next session goes straight to the dynamic method: **T42.1**.

## 0a. Newest facts (2026-09-20 20:20, tooling session) — read before §0; it adds three facts and changes none of §0's state

- **`build/w38e.log` (20:02, 175 MB / 1,860,449 lines) is poisoned as a baseline — F-054.** The
  crash-path recovery that was still in the binary at that build fired **616,824 times in 31.7 s**
  (`VEH: permanently disabled sub_822FA958` + `patch applied, continuing`, exactly 1:1), so 2 of every
  3 lines in that log are one host loop and its `C0000005` = 616,825 against **1** in `w38c.log`. Its
  guest markers are unchanged from `w38c` (`GFx` 9, `VdSwap[` 2), i.e. it records no guest advance and
  no guest regression. **Compare against `w38c.log`, never `w38e.log`.** `tools/soak_census.py` now
  prints this itself — a `LOG QUALITY` line naming the dominant repeated shape, and a
  **POISONED** verdict when one mitigation/VEH shape accounts for ≥2% of the log (a benign poller
  dominating is listed but not flagged). Verified: `w38e` → 33% + 33% both POISONED; `w38c`/`w38b` →
  the `WAKE[KWFSO]`/`WAIT[KWFSO]` pollers listed, no verdict. 51 s on a 175 MB log.
- `tools/addr_owners.py` gained `--gates <addr>` (F-053): each claim site's enclosing-function
  branch/return lines, printed verbatim and uninterpreted, with the tie broken by grepping the soak
  for the installer's own message. Its two unverified causal sentences are deleted. Guest VdSwap
  `0x827BD6E4` is **resolved, not fixed** — one owner body (`Hooked_VdSwap`) in all three
  `renderer_mode`/`mcla_patch_groups` configurations; T39.7(1) is closed and only T39.7(2) survives.
- Two CVar facts that are easy to get wrong and are cited nowhere else: `build/cache/mcla.toml` does
  **not** exist, so `renderer_mode` runs at its compiled default `"native"`
  (`src/renderer_mode.cpp:8`, not `"legacy"` as `src/app.cpp:85-87` says) and `mcla_patch_groups` at
  `"all"`; and `config/mcla_manifest.toml:16`'s `renderer_mode = "legacy"` is read by **nothing** in
  `src/` (zero grep hits), so that manifest key is inert.

## 0. State (verified 2026-09-20 23:30 — supersedes my own 22:45 block below, whose null-`this` story F-060/F-061/F-063 corrected in place; IDA + the `80000003` facts still stand)

- **Three fixes shipped this session, all built and soaked, none committed.** (i) The forced boot gate
  no longer runs *inside* the guest's own allocator hook on that thread's stack — it is dispatched on
  its own host thread with its own 256 KB guest stack taken from `g_userHeap`
  (`src/gpu_device.cpp:1097-1130`, `GATE-STACK`/`GATE-WAIT`). (ii) `PPC_FUNC(sub_821D3070)` no longer
  skips a buffer request just because the caller set bit 15 of `r4` as a flag — **F-063**, and it is
  the first change in the tree's recent history that makes the guest do more: host short-circuit lines
  **177 → 96**, `[error]` 61 → 51, `o1heapAllocate returned null` 3 → 0. (iii) `tools/soak_census.py`
  no longer counts a PM4 argument dword as an exception code (**T41.4**, do-not #22) and still
  reproduces the F-040 ground truth `C0000005 703 → 1`.
- **The guest now builds a real `star_glow` shader object.** `build/w38s.log`: the 32 KB buffer is
  allocated (`TSLAB-OWNER #16 size=32768 lr=821D30B4`), `[0x8287E334]`'s producer `sub_822F9FA8` runs
  for the first time ever (`MSGBISECT 8 … r3=CA53C700`), the guest's own `sub_82188CF8` ctor runs on
  `A0021270` from the simple pool (`FIX-821873E8` fires **0** times → T38.3(d) is no longer reached on
  this path), and the param/technique lookups address a real object `CA71D388`.
- **New #1 is answered (F-064, 23:32): it is not a hang, it is a GUEST FATAL.**
  `w38s.log:3981` `Fatal error dispatcher invoked` /
  **`'drawblit technique is old and busted, rename to blit_draw.'`** at `lr=0x82188770`
  `r3=0x8200B15C`, immediately after the `"draw_starglow"` technique lookup. The bytes being parsed are
  fabricated: `AFB76-FALLBACK #4 path='embedded:/fxl_final/star_glow.fxc' serve rage_im
  buf=827D2DD0 size=5258` (`w38s.log:3860`) — that buffer+size is the **embedded name list**
  (`PROGRAM_GUIDE` §8), not a shader. So T41.3b step 1 is a read-only TOC question, and the three
  sites that keep the fake in place are `src/gpu_device.cpp:3409`, `:8355`, `:9203`.
- (superseded framing, kept for the trail) One instruction deeper: the `"draw_glow"` technique lookup at guest `0x822FBCFC` never
  returns** (`w38s.log:3980` is the preceding `"draw_starglow"` hit at 23:19:13.745, and
  `MSGBISECT 5-822FBAF8 RETURN` is still 0). That is the shader-dict INSERT path
  `PROGRAM_GUIDE` §8 already names as NULL-on-PC (`82189438/88E50 → 8218C760 → resolver 821BDF20 →
  821CB488`), with `DICT-HYDRATE` as its life-support (do-not #8). Consequences still blocked on it:
  `[0x8287E26C]` = 0 → F-060's singleton factory `sub_822F38C0` never runs.
- **A second frontier appeared by removing a stand-in, and it is honest, not a regression:**
  `UILOAD 1 → 0` because the forced gate's only trigger was the `FIX-821873E8` TLSDEAD branch, which
  the shader fix made unreachable, so `sub_82131008` is now never dispatched; and `GFx 9 → 1` where
  all 8 lost lines are the host's own `GFX-*`/`W34-*` stand-in prints (enumerate in F-063). Plus one
  new **host-side** fault: `Param[1]=0x100000040` (guest EA `0x40`), `ppc ctx=nil tag=none`,
  `rip owner=host … not a mapped guest fn`, parked (`w38s.log:5804`, `:5825`) ⇒ **T40.5 is now on the
  critical path**, not a nice-to-have.
- **Rule 11 is live again:** another session wrote **F-062** + T42.1/T42.2 (TLS structure) into the
  ledger and this file at 23:23-23:25 while this session was soaking. `src/gpu_device.cpp` is 23:17
  (mine). Check mtimes + `tasklist` before the next build. Baseline: **`build/w38s.log`**.

### Trail — the 22:45 block of this session (kept; its IDA and `80000003` bullets stand)

- **IDA Pro is connected, without the bridge.** `idalib-mcp.exe` (PID 13440, started 15:08 on
  `build/game_data/default.xex`) already serves MCP-over-HTTP on `127.0.0.1:8745`; attaching to it
  directly answers `tools/list` (47 tools) and `get_metadata`
  (`base 0x82000000`, `size 0xad3000`, `md5 062233a2db24808d429fd0b539c1d4b4`). This is **how T39.1
  should be closed**: `ida-bridge.py` line 25 is `taskkill /F /IM idalib-mcp.exe`, so running the
  configured command while a session is live destroys it. ⇒ new **T41.1**.
- **The one surviving `C0000005` has an argument-level cause — and it is NOT the gate's `r3`
  (corrected at 22:40 by F-060, which this block overstated).** `w38m.log:3885` does show
  `W35-BOOT-GATE #00001 r3=00000000 r4=00000000 r5=00000000`, and `w38m.log:4379` does show the gate
  thread ending at `lr=822F44E0 write to host addr 0x1000000e0 … declining`, but the null is **loaded
  from a guest global by guest code**: `sub_822F3BD8`'s only caller in `generated/ppc_xenon/` is
  `sub_823045E0` (`ppc_recomp.50.cpp:6063`), whose `lwz r3,-7572(r11)` reads
  **`[0x8287E26C]`**, and the only writer of that word in the entire image is
  `sub_822F38C0` (`ppc_recomp.48.cpp:27313`) — a factory (`alloc 14720` → ctor `sub_822F3498` →
  publish, or **publish 0** if the alloc fails). See **F-060** for the proof chain.
- **Both ends are `(handler, msgid)` table entries, so the guest reaches them by message.** Raw words:
  `0x8210DA98/9C = {sub_822F38C0, 0x40001503}` (creator), `0x8210DED8/DC = {sub_823045E0,
  0x40000B03}` (faulting consumer), `0x82102AC0/C4 = {sub_82131008, 0x40003B03}` (**the gate the
  host has hand-called since W36d is itself a message handler**), `0x8210DEF0/F4 = {sub_823047D8,
  0x4000EA03}`. `src/` contains **no** reference to this table region — nobody walks it. ⇒ **T41.3 is
  re-scoped**: dispatch msg `0x40001503` the way the guest's own message system does, and make the
  `MSGCHAIN` census (`src/gpu_device.cpp:9450+`, built into exe 22:39, soak `build/w38n.log`) say
  which of the five runs.
- **`sub_82131008` is a table-resident callback, not a main() function** (IDA `get_xrefs_to`:
  data refs at `0x82102AC0` and `0x821315F4` inside `sub_82131508`, **zero `bl` sites**); and
  `sub_822F3BD8`'s only code xref is `0x823045F4` in `sub_823045E0` + a data ref at `0x8210DAA8`.
  Both still need the bl-scan verification rule 3/`PROGRAM_GUIDE` §10 requires. ⇒ the host is
  invoking something the guest normally reaches **through its own message/task dispatch**, with the
  arguments that dispatch supplies. That is **T41.3**, and it is the gate to everything downstream.
- **New `80000003` in the 22:12 census is not a VMX trap.** Its single occurrence
  (`w38m.log:3054`) is a *packet argument*:
  `CP-T3-CENSUS op=0x58 … args=80000003 071D82C0 DEADBEEF`. `debugtrap`/`illegal instruction` are
  both 0 in that soak, so `PLAN_VMX128` Route B stays parked. A bare-hex marker matched anywhere in a
  line is not an event — **T41.4** + do-not #22.
- Baseline for the next soak stays `build/w38m.log` (11,514 lines, exe 22:05, `BOOT_RC=124`);
  `CP truth drains=8 last_rptr=001F pub=11 put=11 (caught up)`, `DRAW_INDEXED` 0, `CP-DRAW` 24.

## 0t1. State (verified 2026-09-20 22:12 — trail, superseded by §0 above; T40.6 steps 1-2 shipped)

- **T40.6 steps 1-2 are SHIPPED AND SOAKED → F-059: the guest really does submit draws.** The CP's
  unknown-opcode logger used to collapse every opcode `>= 0x20` into one line — the entire draw range —
  so `skipping TYPE3 opcode=0x3C` was the maximum it could report. It is now
  `LogType3Unhandled` (`src/gpu_cp.cpp:351-367`, first 3 hits/opcode + args), which named **13**
  previously-invisible opcodes in `build/w38k.log` (`0x21 REG_RMW`, `0x2B IM_LOAD_IMMEDIATE`,
  `0x3B INVALIDATE_STATE`, `0x3C WAIT_REG_MEM`, `0x45 COND_WRITE`, `0x46 EVENT_WRITE`, `0x54 INTERRUPT`,
  `0x58 EVENT_WRITE_SHD`, `0x60-0x63 SET_BIN_MASK/SELECT`), and `PM4_DRAW_INDX`/`DRAW_INDX_2` are now
  decoded (`:496-531`, `VGT_DRAW_INITIATOR` per `registers.h:311-326`). Measured in `build/w38m.log`:
  **`CP-DRAW #1…#24`, all `op=0x36 src=2 (kAutoIndex) prim=1 (kPointList) numIdx=1`,
  `hdr=C0003600`, `C71DC180→C71DC238` at an 8-byte stride — 24 packets × 2 dwords = the buffer's full
  declared 48 dwords.** The misaligned-walk explanation was tested and refuted (every header is a
  well-formed Type-3 header), and the count is bounded to `[24, 63]` (no `#64` line).
- **`DRAW_INDEXED` is still 0 and F-059 does not claim otherwise.** Decode ≠ render: the CP models no
  Xenos register file, so there is no VB/IB/shader state behind the submission. The *other* path to a
  pixel — the host-side `sub_82420BA8` hook that does enqueue `RenderCommand::DRAW_INDEXED`
  (`src/gpu_device.cpp:1793-1803`) — is starved for its own documented reason: it only ever sees dummy
  `li r5=0` submits because the guest's D3D9 chain `sub_8217A470 → sub_8241BE78 → sub_8241C308 →
  sub_82420BA8` never runs (`:1829-1835`). ⇒ **T40.6 step 3 = register state**, and the new question is
  what those 24 point draws *are* (overlay? cursor? driver stub?) — answer it from `0x21`/`0x2B`, not by
  logging more draws. No regression: `C0000005` 1→1, `GFx` 9→9, `UILOAD` 1→1, `PRESENT` 68→68,
  `Fatal error` 1→1, short-circuits 178→177.

## 0a2. State (verified 2026-09-20 21:55 — superseded by §0 above; T40.3/T40.4 shipped, T40.1 void)

- **T40.3 + T40.4 are FIXED, BUILT AND SOAKED (`build/w38j.log`, exe 21:45, `BUILD_RC=0`) → F-058, and
  T40.1 is VOID.** The CP now walks indirect buffers through their kernel-VA alias
  (`src/gpu_cp.cpp:454`, `:666`), so the eight IB packets that previously decoded as
  `TYPE0 base=000` (zeros) now carry real Xenos register offsets (`A31/A2F/D02/A02/1DD/1DC/5C8/D04`) and
  **three nested IBs are reached for the first time** (`w38j.log:873-875`). The waiter's census reads the
  CP's own publish target (new `CpPrimaryWritebackVA()`), and `tools/soak_census.py` lost its
  `rptrWB → no consumer` verdict in favour of `CP truth drains=8 last_rptr=001F pub=11 put=11 (caught up)`
  plus a `MARKER NOT IN SRC` check (4 suspicious names today). **`DRAW_INDEXED` is still 0 and the reason
  is now specific:** this CP implements only Type-3 `0x3F`/`0x3D`/`0x48`/`0x64`; the draw packets
  `0x22 PM4_DRAW_INDX` / `0x36 PM4_DRAW_INDX_2` (`xenos.h:1600-1601`) have no handler, and the only Type-3
  the soak hits is `0x3C WAIT_REG_MEM`. ⇒ new #1 is **T40.6 (draws = T37.6 Wave C)**.
- **T40.1 must NOT be implemented.** Its premise came from the 22-agent sweep and it is false: the path
  hard-code and the TOC decode **agree** wherever the log lets us compare (`meshtextures.xtd`,
  `r5=40060000` → `[23:12]` = `0x60000` = what `:291` returns), both call sites already fall back to the
  TOC, and the hard-code is a documented choice because TOC-derived `.xsf`/`.xtd` bodies are AES
  ciphertext (`src/gpu_device.cpp:521-523`). F-057(5)'s last sentence is retracted by F-058. The open
  question there is whether the ciphertext claim is true — a census, not a fix.
- *The 21:30 block below stands except where F-058 corrects it* (its T40.1/T40.3/T40.4 queue numbering is
  now resolved; its dark-blue, CP, parking and F-056 findings are all still current).

## 0b. State (verified 2026-09-20 21:30 — superseded by §0 above except where noted)

- **T38.3f IS DONE (seeds deleted) → F-056 + F-057, and it voids the premise of the whole
  forced-gate era.** Soak `build/w38g.log` (11,298 lines, `BOOT_RC=124`) vs baseline `build/w38f.log`:
  the guest's own `sub_82131008` runs unseeded on real guest-published pointers (`w38g.log:3810-3816`
  six `GATE-FLAG-READ` census lines, `:3823` `BOOT-GATE-ENTER r1=8EFFE920 r13=8F200000`), and the one
  surviving `C0000005` is **unchanged** (`:4331-4359`) — so the flags were never the cause. The fault
  is now named to the source line: `generated/ppc_xenon/ppc_recomp.49.cpp:2660-2661`
  `stvx128 v33,r31,r7` with translator-local `r31 = 0` → guest EA `0xE0`, inside the *caller*
  `__imp__sub_822F3BD8` (`:500`), **not** the leaf `sub_822FA958`; `lr=822F44E0` is sticky (do-not
  #14) and F-055's `[0x8288E334]` is a dropped sign extension — the raw words give **`0x8287E334`**.
- **New #1 is measurement, not the crash.** F-057 overturns five readings this file and §9 still
  carries: `rptrWB=0000` is a wrong-address poll (`src/kernel/imports.cpp:2117` reads `C71D81BC`, the
  CP publishes `C71D82BC` — `w38g.log:794-795`); the CP **drained 8×** to `rptr=001F` with
  `pub==put==11` (`:865`-`:3186`, `GUEST-PUB #5`), so "no consumer" is dead; the boot worker
  **declined and went silent** (0 `parking thread` lines) while the 2,852 `40004D7C` waits belong to
  another thread's satisfied 16 ms heartbeat; the dark blue is **host** fallback proven by a pixel
  capture of the live window (`build/screen_shot.png`, `AVG_RGB=16,26,56` = `0.06,0.10,0.22`,
  `src/render_thread.cpp:85,444,505-507`) — the four guest `PRESENT-FB` "samples" are that same
  constant substituted for a **black** framebuffer, not guest pixels; and UI packages are served from
  a path-string hard-code (`src/gpu_device.cpp:285-296` → `0xA0000`) that bypasses the TOC-derived
  offset at `:272-282`.
- **Ordered plan (roadmap sweep, causal dependency — do NOT fix the crash first):** B1 derive the
  package offset from the TOC instead of the path match → B2 delete the remaining fatal absorbers →
  B3 apply `PhysToKernelVA` to `listPtr` at `src/gpu_cp.cpp:664-666` (the IB is walked at phys
  `0x06258300` instead of `0xC6258300` ⇒ zero packets ⇒ `DRAW_INDEXED=0`) → B4 fix the two measurement
  bugs above → B5 PCR/TLS parity with Xenia → B6 untile/PSO. Acceptance per step is a marker table
  against `build/w38g.log`.
- *State at 20:40, kept for trail (its `[0x8288E334]`, leaf-attribution, "CP ring frozen" and
  "seeds at `src/gpu_device.cpp:1101-1113`" statements are all void — the seeds are deleted and
  F-056/F-057 replace the rest):*

- **T38.3(a)(b)(c) + the three self-contradictory gate stages ARE DELETED → F-055. The boot worker now
  reaches UILOAD for the first time in the project's history, and new #1 is the atArray allocator
  chain behind the one surviving fault.** Soak `build/w38f.log` (10,001 lines, `BOOT_RC=124`) against
  baseline `build/w38c.log`: `C0000005` **1 → 1**, every recovery marker **→ 0** (the `0xC3` host-entry
  patches, the `Rip += 256MB` advance and the float-div-0 park are gone from `src/boot_host.cpp`; the
  handler now declines → generic park), and `w38f.log:3885-3890` carries
  `event1-ret r3=00000000` → `event2-ret r3=00000000` → `UILOAD-enter r3=[82830998]` →
  `UILOAD-param r3=C9A24500` with **no** `UILOAD-ret`. The deleted stages were `sub_823043F8`,
  `sub_82304348` and `sub_821FC008` — the driver seeded `[0x8288E6F0]=1` / `[0x82830B14]=0`
  (`src/gpu_device.cpp:1101-1113`) and then
  called exactly the functions those flags tell the guest to skip (`0x82131020 lwz r11,4(r29)` +
  `beq -> 0x8213103C`, and `0x821310C0`; F-055 §1). **The surviving fault** (`w38f.log:4416-4421`) is a
  **write to guest `0xE0`** (`Param[1]=0x1000000E0`, `tag=forced-boot-gate`,
  `r1=8EFFF510 lr=822F44E0 r7=000000E0 r9=827E0000 r10=00000010`), and `lr-4 = 0x822F44DC` is
  `bl 0x822FA958` — the same leaf the deleted `0xC3` mitigation used to patch out ("broken atArray
  allocator chain", `src/gpu_device.cpp:8381`). `sub_822FA958` is a 22-instruction leaf that reads
  `[0x8288E334]` (image bss = 0, and **no `stw` with immediate `0xE334` exists anywhere in
  `0x82130000`–`0x82800000`**, two negative scans) and stores floats relative to it. ⇒ Do **not** arm
  `[0x8288E334]` (do-not #9): the next step is to stop seeding the gate's flags and let
  `sub_82131008` run its own init. `DRAW_INDEXED`/`DRAWDISP` still **0**, CP ring still
  `put=11 rptrWB=0000`. Tree green (exe 20:10), `mcla.exe` killed, nothing committed.

- **T38.2b WAS DONE (19:55) → F-050 + F-052.** The published-context dump works
  (`w38c.log:4089` `ppc ctx=0x8a7b2fefc0 tag=forced-boot-gate`), the register set moved, and the one
  surviving `C0000005` is **our own gate calling guest `sub_82304348` with `this = 0`**
  (`src/gpu_device.cpp:1203-1206`; `freshVolatiles()` clears only `r5`-`r10`) — a host-fabricated call
  frame, not lost guest progress. Nothing is armable to hide it (do-not #9). F-050 adds two facts
  F-052 lacks: the dump's `+0x144` is a **host** code offset (see new do-not #18), and the block that
  offset falsely points at, guest `0x8230448C`, reads a **fourth** bss singleton
  `0x82839D70` (rage static-instance pattern; 4 writers `0x82180390`/`0x821809FC` clear it,
  `0x82186150`/`0x82186240` publish it; vtables `0x82009D34`/`0x8200AAF4`; **0 owners** in `src/`).
  Built green after the fix (`build/w38d_build.log`, `BUILD_RC=0`, exe 19:52) — **not soaked**.

- **T38.2 IS DONE → F-046 + F-049 (soak `build/w38b.log`, 120 s, 11138 lines, `BOOT_RC=124`).** The
  residual AV is **root-caused**: `Param[1]=0x7E780000` is uniquely `PPC_LOOKUP_FUNC`'s slot for guest
  target **0** (the new `probe` lines — `w38b.log:4022-4027` — identity-test it and rule out every
  dumped register as the index), a null target becomes a *call* rather than an earlier fault because
  `ReadGuestU32` swallows the validity bool and returns 0 (`src/guest_memory.h:82-86`, and
  `PPC_LOAD_U32` *is* that helper at `src/ppc_context.h:57`), and — decisively — **the crash dump's
  `lr` and GPRs belong to the boot worker's root `PPCContext`, while the fault happened inside the
  host-forced BOOT-GATE, which runs every stage on an unpublished local `PPCContext g{}`**
  (`src/gpu_device.cpp:1121-1127`, `:1187-1236` vs `g_faultCtx = &ctx` at `src/boot_host.cpp:706`;
  proof: `w38b.log:3864` and `:4021` carry the *same* `lr`/`r3`/`r8`/`r9` 1.044 s and one GFX-BLOCK
  apart). So the AV is a **mitigation artifact of our own gate driver, not lost guest progress**, and
  the register-based readings in F-044(c)/F-045 are void as attributions. **New #1 = T38.2b**
  (publish the faulting context, one soak, then name the site). Census of the named frame is in
  F-049: `0x82839F68` = the shader/preload-list manager singleton (vtable `0x8200AE8C`, whose slot +4
  is the host-overridden `sub_821873E8`), dumped `r4` = the string `"star_glow"`, and
  `sub_822FBAF8` has **five** indirect-call sites — so the old "one `ctr`-inclusive dump away" framing
  is unreachable anyway: `src/ppc_config.h:5,9,10` make `ctr`/`xer`/`r11`/`r14`-`r31` host locals
  that no VEH handler can read (14 build errors proved it).
- *Uncommitted now (19:20):* `src/boot_host.cpp` (the probe block, builds green),
  `docs/ROOT_CAUSE_VALIDATION.md` (F-044…F-049), `docs/LONG_TODO_MASTER.md`, `.gitignore`,
  `AGENTS.md`, `.qoder/`. New logs: `w38b.log`, `w38b_build.log`, `w38b_build2.log`, `w38b_err.log`.

- **COMMITTED.** `5eb9932` = module reorg + the `.gitignore` data-loss hole closed + the VEH
  RIP-advance runaway removed; `8953cea` = stray root `gpu_device.cpp` dropped. **T37.0 and T37.1
  are DONE** — the 17:05 sequencing note below ("do T37.1 BEFORE T38.0") is satisfied, not open.
  Uncommitted now: `docs/ROOT_CAUSE_VALIDATION.md` (F-040…F-043) + new `AGENTS.md`/`.qoder/` (§7).
- **#1 BLOCKER = the guest never reaches its own GFx loader construction** — the 17:45 bullet below
  ("#1 BLOCKER = GFx loader vtable mismatch") is **VOID, see F-044**. T38.1's raw-image census
  (17:57, no rebuild) shows: `0x8206DFAC` is produced by exactly ONE guest site
  (`sub_82482008+0x18` @ `0x82482020`, `stw r9,0(r3)`), the loader ctor `sub_824C6F08` installs
  `0x820736DC`/`0x820736B0` correctly at `0x824C6F28-38` and then **calls `sub_82482008` twice**
  (`0x824C6F48`, `0x824C6F50`), so `vt0=8206DFAC` **is** the post-construction state ⇒
  `GFX-CTOR-VT-MISMATCH` (`src/gpu_device.cpp:1156`) compares a mid-construction expectation against
  post-construction memory and proves nothing. And in `w37a.log` the guest's real movie-ctor wrapper
  `sub_82482F78` appears **0 times** while `824C6F08` appears once (our forced host call) — the guest
  builds no loader, so the `0x82073xxx` scan at `:5251-5254` finding nothing is honest. The whole
  `GFX-BLOCK` (`src/gpu_device.cpp:1131-1165`) is a fabricated stand-in → catalogue at T38.3.
  Frontier therefore = **why the boot-gate thread dies after 2 `GATE-STAGE` lines**
  (`w37a.log:3797-3798` → AV `:3969`) → **T38.2**. *(19:20: that death is now explained — F-046.)*
- *Superseded 17:45 bullet, kept for trail:* "#1 BLOCKER = GFx loader vtable mismatch
  (`GFX-CTOR-VT-MISMATCH … want 820736DC/820736B0`)". The counts were real (`w37a.log`: `GFx` 9,
  `UILOAD` 1, `C0000005` 1, `GFX-CTOR-VT-MISMATCH` 1, `W34-NOGFX` 1; `DRAW_INDEXED` 0; CP
  `put=11 rptrWB=0000`) — the causal reading of them was not.
- **The VEH runaway is closed and measured** (F-040): `C0000005` **703 → 1**, recovery lines → 0,
  T38.0 acceptance (`≤ 3`) **met**. The one residual AV (`w37a.log:3969-3988`,
  `read of 0x7E780000`, `lr=822FBC28`) is **not** root-caused and kills the boot worker thread —
  F-043 supersedes both earlier attributions of it and shows the crash dump is missing `ctr`, which
  is the only register that can settle it → **T38.2** (logging-only change, one soak).
- **`build/cache/mcla_pe.bin` is back** (10,354,688 B @ 17:14) → rule 3 is operable again. The
  17:05 note below saying it is MISSING is void.
- **Route B / VMX128 still off the critical path** (17:05 note below holds: `sub_822FBAF8` has zero
  `__builtin_debugtrap`, soak has zero `0x80000003`). Do not install LLVM.
- **Agent tooling landed but not yet in force:** `AGENTS.md` + `.qoder/settings.json`
  (`ida-pro`, `renderdoc`) + 5 project skills (`mcla-boot-cycle`, `mcla-guest-raw-decode`,
  `mcla-log-census`, `mcla-finding-ledger`, `mcla-recompiler-regen`). Needs `/mcp reload` + the
  first-use trust prompt → **T39.1**. Conflict register: §8.

## 0x. State (verified 2026-09-20 17:05 — trail, superseded by §0)

- **TREE BUILDS. T37.0 IS DONE.** `build/mcla.exe` mtime **16:41** (moved — rule 12 satisfied),
  `build/cp_nudge19.log` 16:41 was the green attempt. Verified in source: `CpAdvanceGuestPublication`
  now has ONE definition at `src/gpu_cp.cpp:752` in `mcla::gpu` scope, matching the `src/gpu_cp.h:83`
  decl; the 4 formerly-ambiguous call sites are now `:1046/:1111/:1346/:1453`. No mcla.exe/ninja
  running at 17:05, newest log 16 min old → **rule 11 stand-down is lifted, src work is allowed.**
- **#1 BLOCKER IS OUR OWN VEH MITIGATION, not the guest.** See T38.0 — this is new and re-orders
  the backlog. `build/smoke_long2.log` (16:49, 9560 lines, 120 s) contains **703 `code=0xC0000005`
  lines**, all `lr=822FBC28`. The earlier "0 `c0000005`" claim in `HANDOFF_SESSION78.md` §5 is a
  **case-sensitivity false negative** (`grep -c c0000005` = 0, `grep -c C0000005` = 703). Treat that
  claim as void.
- **`build/cache/mcla_pe.bin` IS MISSING** → rule 3 (raw-byte verification) is currently
  **inoperable**, and so are `tools/ppc_disasm.py` + `tools/ida_import_functions.py`. It is dumped
  at runtime by `src/boot_host.cpp:1233`, so any short boot regenerates it. Do this before any
  IDA/raw-byte claim (T38.0 step 1).
- **The type-5 `vupkd3d128` cluster is NOT on the critical path.** `sub_822FBAF8` (the function
  containing the `0x822FBC28` call site, `generated/ppc_xenon/ppc_recomp.49.cpp:20945`) contains
  **zero** `__builtin_debugtrap`/`vupkd3d128`/`vpkd3d128` lines, and the soak has **0 `0x80000003`**.
  ⇒ `PLAN_VMX128.md` Route B stays parked, and **the Clang-20 toolchain blocker is off the critical
  path — do not spend a session installing LLVM.**

## 0b. Prior state (16:23 — trail only, superseded)

- **Committed frontier: W36h** `8f07a39` (TLS allocator `f3bb765`/`b6528ad`, boot-worker trace `e46c386`, boot gate `e1a2435`, GFx loader `cc3a433`, game data + factory `8f07a39`). W36 is documented nowhere else → T37.2 records it.
- **TREE DOES NOT BUILD — live second session fixing it.** `build/cp_nudge*.log` series (13 attempts by 16:23, newest <2 min old = stand down, rule 11): 4× `CpAdvanceGuestPublication` ambiguous `gpu_cp.cpp:1044/1109/1344/1451` (stable all attempts; diagnosis in T37.0) + `src/hooks/alloc_census.cpp` move-injuries (line numbers drift per attempt — read newest cp_nudge log) from the in-flight gpu_device→hooks relocation. gpu_device.cpp untouched since 07:07.
- **Last good boot:** `build/mcla.exe` 14:48 (mtime never moved since — no green build after it, rule 12) + `build/smoke_long.log` (15:18, 2 min): real packfiles (`xarchive_cache.rpf` 2032 MB), TOC76 #69, SUBMIT ×16, GLOBTEX-SERVE alive, threads park, **no fatal** (only `fatal` text = REBASE-POISON census wording). Present = synthetic: guest present-kick ×2 (`native_renderer.cpp:152` census), both `PRESENT-FB` samples = fallback clear rgb(0.06,0.10,0.22) on swap-table slots — F-B reproduced, no real pixels.
- **UNVERIFIED:** "UILOAD executes" (`e1a2435` message) — **0 UILOAD/GFx markers** in smoke_long. Re-verify at T37.3.

Build/soak (Git Bash; MSYS vars REQUIRED or `cmd.exe /c` silently no-ops; `//F//IM` misreads as UNC — `PROGRAM_GUIDE.md` §3):

```bash
MSYS_NO_PATHCONV=1 MSYS2_ARG_CONV_EXCL='*' cmd.exe /c ninja_build.bat
cmd.exe /c "taskkill /F /IM mcla.exe"            # before build AND after soak
timeout 120 ./build/mcla.exe > build/w37a.log 2> build/w37a_err.log   # new name every run
```

