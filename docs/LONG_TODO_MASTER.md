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


## 0y. State (verified 2026-09-24 02:30 JST — B2's transform settled by F-105; supersedes nothing, adds the seam result)

`*.list` members are raw DEFLATE name lists (all six, expanded length == stored length), `src/raw_inflate.h` reproduces them, and the only seam that makes the guest consume the content is the archive read (`RpfVirtualFileSystem::ReadFileAt`, behind `kExpandListInArchive = false`). With it on, the guest opens the eight textures the list names and then stalls on a 0-byte `C000000D` read of the page holding the named member — that read is T41.3r and is the next gate item. `w78` is the default-tree baseline (`== w72`/`w58`: `C0000005 0`, `Fatal error 2`, `GFx 3`, `GETDEV 168`, `TOC76 334`, `CP-DRAW 52`, `DRAW_INDEXED 0`); `w75`-`w77` are poisoned (storm/loop) and must not be cited as progress. B3 unchanged; B4/B5 still behind the fatal.

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

## 1. Rules (all in force; each cost a session)

1. **Census before fix** — no short-circuit without root cause.
2. **Never edit `generated/**`** — recompiler output, input only.
3. **Raw-byte rule (F-023)** — verify every IDA claim vs `build/cache/mcla_pe.bin` (offset = VA − 0x82000000) or the generated TUs.
4. **One owner per guest address** — grep `src/` before adding any hook/override.
5. **One new log per experiment** — `w37` series; never overwrite.
6. **`timeout` every boot; kill mcla.exe after every soak and before every build** (`cmd.exe /c "taskkill /F /IM mcla.exe"`).
7. **Tree must always compile** — fix the build before adding anything.
8. **Retail content only** (`xarchive_cache.rpf` + audio/music); never `mc4/art`.
9. **No framework rewrites/optimization while the game isn't booting** — parked in `CODE_OPTIMIZATION_PLAN.md`.
10. **Write the trail as you go** (HANDOFF live block + session ledger; F-### ledger; phase ledger; this file's tables). `docs/` is GITIGNORED — `git add -f` new docs or they die on `git clean -xdf`.
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

### T41 — the ordered route from "one AV kills the boot gate" to a playable loop (added 2026-09-20 22:45)

Dependency order, not wishlist order. Every item's acceptance is a `tools/soak_census.py` delta against
the **named** baseline in its own line, per rule 13. Nothing below is "done" without that line.

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
  junk (`11`, `err.txt`, `NUL.obj`, `crash_dump.txt`, `crash_log_early.txt`, `fix_stubs_*.py`,
  `mcla_jts_regen.toml`, `write_opt_plan.bat`, root `CODE_OPTIMIZATION_PLAN.md`), the two
  `GITHUB_APPEAL_*.txt` deletions that are **not** this line's work, `tools/fix_stubs_*` citation, and
  `addr_owners --check` written into rule 4 or deleted as a claim. Ask before deleting user files.
- **T41.15 — F-059's open question: what are those 24 point draws.** Answer from `0x21 REG_RMW` +
  `0x2B IM_LOAD_IMMEDIATE` decode (register writes → `VGT_*`/`RB_*`), not from more draw logging. Only
  after T41.7 picks a path; if the answer is (a), this item closes as void.

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

**T39.3 — root junk + citation fix.** Untracked and NOT ignored: `11` (0 B), `err.txt` (0 B),
`NUL.obj`, `crash_dump.txt`, `crash_log_early.txt`, `write_opt_plan.bat`,
`GITHUB_APPEAL_REPLY.txt`/`GITHUB_APPEAL_TEMPLATE.txt`, `fix_stubs_iter.py`, `fix_stubs_self.py`,
`mcla_jts_regen.toml` (obsolete span experiments — the stub work landed in `75ed486`, census is 0),
and the duplicate root `CODE_OPTIMIZATION_PLAN.md` (its Phase 0 is VOID, do-not #11). Also
`build/xr_spans|xr_iter|xr_self|xr_self2` scratch trees. `PROGRAM_GUIDE.md` §5 cites
`tools/fix_stubs_*.py` but the scripts sit at the repo root. Gate: `git status --porcelain` shows
only real work, and every doc path citation resolves (`mcla-guest-raw-decode`-style `ls` check).
**Ask before deleting** — these are user files, and `*.log`/`crash_dump.txt` are evidence-adjacent.

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

1. Edit `generated/`. 2. Regen without the reproducibility gate (`PLAN_VMX128.md` §4 Route B step 3; TU count must stay 176). 3. Poke shader dict / patch `byte_827D5C70` / stub fatals. 4. GETDEV-redirect (F-027). 5. Write `0xA00xxxxx` scratch from SeedPreBootSlots. 6. Treat `525DE064` as magic (stack residue). 7. Depend on `mc4/art`. 8. Remove hash-table hydration until INSERT proven clean. 9. Stack short-circuits without root cause. 10. Leave mcla.exe running. 11. Follow root `CODE_OPTIMIZATION_PLAN.md` Phase 0 (edits generated/) — VOID by rule 2. 12. "Fix" VMX traps by skipping instructions (R5 — stale vectors). 13. Treat PresentKick r4 as framebuffer (F-B: swap-table timestamp slot). 14. Build caller chains from census `lr` after memset/leaf calls (sticky-LR; use xrefs + arg regs). 15. Widen the `W34` loader scan (`src/gpu_device.cpp:5251-5254`) to accept `0x8206Dxxx` vtables, or write `0x820736DC`/`0x820736B0` into the fabricated loader after `sub_824C6F08` returns — both manufacture loaders out of sub-object memory (F-044). 16. Trust a `lis`/`addi` decode produced by hand or by a scanner that breaks on the *second* of two consecutive `lis`s — the first version of the vtable-producer scan under-reported (`0x824C6F28` missed); re-run with a sliding register state (F-044 §2). 17. Read a VEH crash dump's `lr` **or any GPR** as the faulting frame's until the dump's context is known to be the one that faulted — `g_faultCtx` is the boot worker's *root* `PPCContext`, while the forced gate runs stages on an unpublished local `g` (F-046: identical `lr`/`r3`/`r8`/`r9` 1.044 s apart). Also never try to add `ctr`/`xer`/`r11`/`r14`-`r31` to a dump: `ppc_config.h:5,9,10` make them host locals, so it cannot compile. 18. Read the `+0x…` in a `rip owner=guest 0xAAAAAAAA +0xBBBB` crash-dump line as a guest PC offset — it is `RtlLookupFunctionEntry`-relative **host code** bytes, so adding it to the guest address lands on a block that never executed (F-050: it pointed this session at `0x8230448C`, a second unrelated null-`bctrl`, while the real fault was the `bctrl` at `0x82304368`). Only the function half of that line is evidence. Fixed in text at `src/boot_host.cpp:547` (now `(host+0x…)`), unbuilt-in-soak. 19. Treat a crash-dump `rip owner=…` line as a *guest*-PC bound at all — `GuestFnAtHostAddr` answers from `RtlLookupFunctionEntry`, which returns the enclosing **unwind** entry, and the XenonRecomp output has one entry per recompiled function with no size bound that tracks the guest basic block. F-055 proved it: the printed owner named neither `sub_822F44DC` (the caller at the fault `lr`) nor `sub_822FA958` (the callee). Attribute a fault with `lr` + rule-3 raw words at `lr - 4`; use `rip owner` as a weak hint about which host region the RIP sits in. **[21:30 correction, F-056: the second half of that sentence is the useful one — in `w38g` the owner line named `sub_822F3BD8` and that *was* the function holding the faulting store; it was F-055's `lr`-based leaf inference that was wrong. So `rip owner` is a valid function-level hint and an invalid PC-level one; never let either alone override the generated-code line.]** 20. Read a census log field as the value of the thing it names — `WAIT[KWFSO] … rptrWB=0000` is a hard-coded **wrong address** (`src/kernel/imports.cpp:2117` polls `0xC71D81BC` while the CP publishes to `C71D82BC`, `src/gpu_cp.cpp:951`), so "CP ring frozen / no consumer" was an artifact for many sessions while the ring was in fact draining (`w38g.log` 8 × `DRAIN`, `rptr→001F`, `pub==put`). Cross-check every pipeline field against the producer's own log line before claiming starvation (F-057(1)(2)). 21. Read a colour in a `PRESENT-FB sample` line as guest pixels — `src/render_thread.cpp:503-507` substitutes the host's `0.06,0.10,0.22` whenever the sampled framebuffer sums below 0.02, so that triple means "the guest framebuffer is black", and the on-screen dark blue is the host clear (`build/screen_shot.png`: `AVG_RGB=16,26,56`, 79/81 samples `0F1938`). Present success is unmeasured — the HRESULT is never checked (F-057(4)). 22. Read a bare-hex census marker as an event — `80000003` counted **+1** in `w38m.log` and reads as "a new VMX `debugtrap`", but its one occurrence is `CP-T3-CENSUS … args=80000003 071D82C0 DEADBEEF`, i.e. a **PM4 packet argument** (`w38m.log:3054`), while `debugtrap`/`illegal instruction` are both 0 there. Exception-code markers must be matched on exception-shaped lines only. Same class as #20, one layer further down (T41.4).

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

1. **Two MCP config dialects.** `opencode.json` (gitignored) vs `.qoder/settings.json` (tracked)
   declare the same `ida-pro` + `renderdoc` servers → drift risk. T39.2.
2. **`.mcp.json` is ignored by `.gitignore` and unread by Qoder** — a plausible-looking file that
   does nothing. Don't create it. Documented in `AGENTS.md`.
3. **Duplicate plan file**: root `CODE_OPTIMIZATION_PLAN.md` vs `docs/CODE_OPTIMIZATION_PLAN.md`;
   docs/ wins, root's Phase 0 is VOID (do-not #11). T39.3.
4. **Doc-vs-doc contradiction still live**: `HANDOFF_NEXT_AGENT.md` LIVE block says "BUILD BROKEN,
   work T37.0"; `LONG_TODO_MASTER.md` §0 says T37.0/T37.1 done and committed. T39.4 fixes the
   former. Until then trust §0 of this file (reading order puts it first for that reason).
5. **Memory held the #1 blocker, docs did not** — `GFX-CTOR-VT-MISMATCH` existed only in agent
   memory until this pass. Memory is not the trail; rule 10. T39.4.
6. **Two task queues**: `TaskCreate` (per-session scratch) vs this §2 (durable). Nothing may live
   only in the session list; the session list must not resurrect closed §2 items.
7. **Root junk, untracked and unignored** (§T39.3 list) → `git add -A` would commit 0-byte files, a
   3 MB `NUL.obj` and stale experiments. Always stage named paths.
8. **Shared build/boot resource across concurrent sessions** — `taskkill /F /IM mcla.exe` and the
   IDA bridge both kill another session's process. Rule 11's 2-minute log check is the guard; the
   IDA bridge needs the same courtesy (check for `idalib-mcp.exe` first).
9. **Address-transcription conflict** — three different globals were cited for the same fault site
   inside one hour (`0x82859F68` here, `0x82839F68` per F-043, `0x827C9F70` historically). The skill
   encodes the arithmetic check; any address quoted in a claim must come from generated-code text or
   a computed dump, never from a hand decode.

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
