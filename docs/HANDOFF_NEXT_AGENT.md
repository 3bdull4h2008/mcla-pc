## 2026-10-02 — SUPERSEDING BLOCK. Ledger through **F-745**. Read this, then the 2026-10-01 block below, which is now trail.

**Nothing below this line is deleted.** This block is the state as of 2026-10-02 06:16 local. The full
evidence — every citation, every falsifier, and three corrections to the brief that produced this block —
is in `docs/ROOT_CAUSE_VALIDATION.md` § **F-729…F-745**. This block is a pointer, not a substitute.
**Next free ledger ID: `F-746`. Do not take `F-695`.**

### One-word state: **FIRST PIXEL, THEN FROZEN.**

Two facts, in this order, and the order matters:

1. **The project reached its first confirmed rendered pixel today.** `build/w700.log` (8,487,020 B,
   sha256 `AA6DBADF20DB29D66E190331DC53B22C9EA893E08A682582CFF1791833BE8B0A`, 55,946 lines) contains the
   first pixel values this backend has ever reported:
   `DRAW-CP-PIXEL #2 draw=2 rgba=(5,8,13,255) at (640,360) rowPitch=5120` and
   `D3D12-DRAW-PIXEL #1 create hr=0x00000000 heap=READBACK bytes=3686400 rowPitch=5120 rows=720
   backBuffer=1280x720 flags=0x1`. The enabling fix is `D3D12_HEAP_TYPE_READBACK` — a heap type that is
   mappable by definition, which four prior paths had declined to use. **Ledger `### F-729`.**
2. **The boot then freezes, correctly, on an unsatisfied memory wait.** `CP: RING A PARKED at
   rptr=0016 header=C0013F00 on an unsatisfied PM4_WAIT_REG_MEM (op=0x3C)`. `rptr` stuck at `0016` for
   **156.349 s** across 20 of 36 `CP: VDRAIN-CENSUS` rows. The wait wants `ref=00000001` at
   `pollByte=1840B284`; the log's own `CP-SCRATCH-WB #2 … dest=1840B284 val=00000001` matches both fields
   exactly but **writes the flat view while the poll reads the pool view, and never calls
   `CpNoteMemWriteDest`.** **OPEN — that is the blocker. Ledger `### F-735`.**

**THE FREEZE IS THE BLOCKER. THE CENSUS IS OPEN. THE COMMIT IS STILL UNMADE.**

### Three things the next session must not get wrong

**1. The pixel census is arithmetically impossible and is OPEN — do not cite those fields.**
`meanChannel=26.0000` **exceeds** `maxChannel=13`, which cannot happen for one region.
`nonBlack=921600/921600` = 100 % on a probe of `rgba=(0,0,0,0)`. And **both `DRAW-CP-PIXEL` rows carry
byte-identical census fields despite different probe values** (row #1 `rgba=(0,0,0,0)`, row #2
`rgba=(5,8,13,255)`, identical `nonBlack`/`maxChannel`/`meanChannel`; row #2's probe sums to exactly 26).
**The probe is real evidence and the summary is not.** An agent is on it. Ledger `### F-732`.

**2. The work is NOT committed, and no single-variable attribution exists.**
HEAD = `83859255b0b7bdff740aeaf8d7195beccfe6e96c`. **`git diff --name-only HEAD -- src/` = 45 files**, so
rule 1a's single-variable check **cannot** be satisfied by anything in today's block: every claim in
`F-729`…`F-745` is **N-way**. Do not let any of it harden into "the fix was X" without a bisect.

**3. Two marker families born today are NOT in `PROGRAM_GUIDE.md` §9, so `tools/soak_census.py` does not
track them** — `DRAW-CP-PIXEL`, `D3D12-DRAW-PIXEL`, `CP-SCRATCH-WB`, `CP-EVENTWRITE`,
`CP-WAITREG-WRITER-MISMATCH`, `D3D12-BEGINFRAME-REFUSE`, `D3D12-FRAME-ABANDONED`, `CP-COLORFMT-VSRTV`.
Their `w700` counts are `DRAW-CP-PIXEL` 2, `D3D12-DRAW-PIXEL` 5, `CP-SCRATCH-WB` 2, `CP-COLORFMT-VSRTV`
2, and **0** for the other four. **A zero for a marker §9 does not list is not evidence of anything.**
Adding them to §9 is the cheapest outstanding task in the project and this session did not have time.

### Kills recorded today — read these before re-asserting anything

- **`CP-WAITREG-NEVERWRITTEN` made a false statement for days.** It queried a **pool VA**
  (`0xB840B284`) against a set keyed on **guest-physical** addresses (`0x1840B284`) — **0xA0000000
  apart, a guaranteed false negative.** Refuted by the log's own earlier line: `CP-EVENTSHD #1
  … dst=1840B284 … written=1`, **2.785 s** before the wait. **`### F-733`.**
- **`PM4_EVENT_WRITE` is not a memory writer.** The reference's `count == 1` form has **no address
  operand and no value operand** (`command_processor.cc:1181-1189`, whose own comment reads *"Just an
  event flag? Where does this write?"*). **The packet that motivated implementing it ran 2.001 s
  BEFORE the park, not behind it.** **`### F-737`.**
- **The standing "PS register N ≡ interpolant N" is dead.** The derivation used a **read** rule and
  invented a `TEXCOORD0` for a shader that writes colour 0 and reads r0 — a register nothing writes.
  That assumption rested on `n = 1`, and that one instance was wrong. The *register-space* reading
  (0–15 are interpolants) survives; only the inference dies. **`### F-739`.**
- **`snapCover` vs `rsPresent` is NOT a contradiction** — same field, same mask, 786 ms apart in
  emission time. **Pair those rows by TIME, never by draw number.** **`### F-743`.**
- **`PM4_WAIT_REG_MEM`'s `budget=2000ms` is host policy, not from the packet.** The reference's writers
  are CPU-side stores and its wait has **no timeout**, so the reference **would hang** where this host
  parks. The host is strictly more conservative — the correct posture. Don't "fix" it toward the packet.
  **`### F-738`.**
- **`DRAW-CP-DRAWN` was counting a refused path**; now gated on `m_stats.drawsIssued`. **`### F-730`.**
- **`layoutRefusal` was set unconditionally and never reset — the layout-completeness proof was DEAD
  CODE**, and a PSO could have been built from an unproven layout. **`### F-740(f)`.**
- **`sizeof(kPrefix)` on a `const char*` = 8, not `strlen` = 20** — off by 13, landing the digit scan
  inside `"float4"` so it read `'a'`, and **every VS emitting an interpolant was refused.**
  **`### F-740(g)`.**
- **`CreateReflection` asked for `IID_IDxcContainerReflection`**; measured matrix says the **IID was
  the whole fault** — the container works under `IID_ID3D12ShaderReflection`, `S_OK`. **`### F-740(i)`.**

### Also worth knowing

- **Log volume reclaimed: 111,153,290 (`w693.log`) → 8,487,020 B; tail 95.59 % → 51.72 %.** The old tail
  was 95.59 % of the file repeating the head's constants verbatim. All four offenders already had a
  cadence gate — the problem was the **population**: a modulus linear in an unbounded serial cannot
  bound volume. Now stride 2^18 with power-of-two summaries, so a truncated soak's last `total=N`
  **bounds the truth to `[N, 2N)`**. Ranks 5–25 got **no edit** — they are the poller-rate and
  drain-truth measurements the freeze diagnosis reads. **`### F-742`.**
- **The abandon loop is closed.** `beganFrame` and abandons each moved **+4800**; 30.0561/s vs 30.0543/s
  = the 33 ms heartbeat, i.e. one completing iteration per tick, **not a spin and not a livelock**. Root
  cause: `ClearAndPresent`'s first act was `MayWriteBackBuffer`, whose own `BeginFrame` ran *after* the
  refusal. **`w700` has 0 `D3D12-FRAME-ABANDONED`** (literal present in the binary) and `FRAME-OWNER`'s
  refusal text is byte-identical. **`### F-741`.**
- **The frame latch had SIX `BeginFrame` failure paths, not three**, and **clearing the latch alone is a
  trap**: `ID3D12CommandAllocator::Reset` then fails `0x80070057`, converting a truthful `already-in-frame`
  into a misleading `allocator-reset`. **The `Close()` is load-bearing.** **`### F-731`.**
- **OPEN: a real off-by-one in the TYPE-0 walker.** `CP: IB-OPC-CENSUS #7 … dwords=1038134
  walked=1038135`. The TYPE-0 arm advances `count + 1` (`gpu_cp.cpp:4307-4315`) so the overshoot is
  bounded by **`count`, not 1**, and `CpType0Apply` feeds out-of-bounds guest memory into `CpRegPoke` —
  a real register write from a foreign buffer. **Clamping `p` is unsafe and incomplete** (the read
  already happened inside `CpType0Write`; `p` also feeds `AccumProgress(p)` at `:4714`). Fix belongs at
  the read boundary, with its own measurement. **`### F-744`.**
- **`chevy` REFUSED again, harder.** Replaying all 108 `MEMBER-SPAN-OWNER` windows byte-for-byte against
  the real `xarchive_cache.rpf`: **`HOLE == bytesChanged` at 100 % for every candidate rule**, including
  F-693's own reverted cap. The range `[004709B3,00490000)` is claimed by **two real byte streams** and a
  flat window can hold only one — a representational impossibility, not a rule-selection problem. The
  `MEMBER-SPAN-ALIAS` premise is also falsified (90 of 92 rows carry `ownerImageIsArchive=0`; bootscripts
  and cameratune contribute **zero** rows), and so is the nested-RPF premise (`handle_nested=0` on all 8
  carconfigs windows; `NESTED-RPF-MOUNT`/`-REGISTER` = 0). **Victim table is 178 spans, not 177.**
  **The file is byte-identical; nothing shipped.** **Narrowest live lead:** `vehicle.lst` **is** decoded
  (`MEMBER-EXPAND off=00471000 … expanded=22391`) and **then never served** — zero `XSF-HOSTSERVE` /
  `SERVE-PROOF` / `LIST-SERVE-VERIFY` rows for it, while those markers fire for other paths in the same
  log. **`### F-745`.**

**NOT DONE BY THIS SESSION, deliberately:** `AGENTS.md`, `LONG_TODO_MASTER.md` and `PROGRAM_GUIDE.md`
were **left alone**. Not enough time to do them properly, and a bad edit to those is worse than none.
`PROGRAM_GUIDE.md` §3/§4/§5/§7 and `LONG_TODO_MASTER.md` §0/§2 are now **behind** this block — §9 needs
the eight markers above, §7's short-circuit registry needs the killed fixes in `F-740`, and
`LONG_TODO_MASTER.md` §2's queue needs "freeze" as the top item.

---

**End of the 2026-10-02 block. Written by a subagent under a 30-minute budget; no build, no soak, no
game run, no git operation. Files written: `docs/ROOT_CAUSE_VALIDATION.md` (append-only, plus the one
`### F-726`-authorised footer amendment) and this file.**
## 2026-10-01 — SUPERSEDING BLOCK. Ledger through **F-692**. Read this, then the 2026-09-30 11:5x block below, which is now trail.

**Nothing below this line is deleted.** This block is the state. Every number below was produced by a
byte-exact count (`bytes.count()` over the whole decoded log, never `findstr`) in the session that wrote
this block; every guest/host address is cited to the log line or the `file:line` that printed it. Where I
could not measure something it says **UNVERIFIED** and says why. **The 09-30 block's "Next free ID: F-654"
is dead — see §5. The 09-28 block's "The tree is RED. It does not boot." is RETIRED — see §7.**

**One-word state: DEGRADED.** `build/w685.log` (12,433,581 B, sha256
`ebe396d085a9b997291df5933f6adaab36758b418860163cf4a9c010d2f65252`, first line `[2026-10-01 08:45:03.260]`,
last `[08:48:03.108]`) builds, reaches the render thread, submits **8** draws, and ends in a **truthful
guest assert** at **+15.847 s** (`Fatal error dispatcher invoked - terminating game`, **line 25092**. Corrected in place 2026-10-01: the block said "line 25,091", and 25091 is an `F442-SECTION #10` row, not the fatal. `build/w685.log` is **raw** — 12,433,581 B, not `.gz` — because the 2026-10-01 de-bloat (`build/LOGS-ARCHIVED-2026-10-01.txt`) compressed only logs older than 2026-09-29, so a plain line number is correct here and no `zgrep` is needed,
`fatal message: 'Unknown manufacturer %s in vehicle list file'`). Zero host AVs (`C0000005` 0,
`Access violation` 0). Not GREEN — 0 pixels and an open regression (§3). Not RED — see §7.

---

### 1. Boot state, `build/w685.log` vs `build/w684.log`

Both logs censused the same way in one pass. `w684.log` = 11,860,787 B, sha256
`2f85adb65b7f498594f3683ca572c0f77bb40b471b50dbbbee0868df95ff644b2`, 71,798 non-empty lines,
`06:58:17.192`→`07:01:16.883`. `w685.log` = 75,874 non-empty lines. Counts are case-insensitive whole-file
substring counts; **the one `%`-note matters, see row 2.**

| marker | w684 | w685 | note |
|---|---|---|---|
| `Fatal error dispatcher invoked - terminating game` | 1 | 1 | boot still ends in a **truthful guest assert at +15.847 s** |
| `fatal %%s arg:` | 1 | 1 | `'chevy'`; `fatal-dispatch regs: lr=0x823966E8`. **Note the two percent signs.** The single-`%` form `fatal %s arg:` is **0 occurrences in `src/`**; `fatal %%s arg:` is 3 (`src/fs/vfs_rpf.cpp`, `src/gpu_device.cpp`, `src/kernel/imports.cpp`) and 1 in `build/mcla.exe` |
| `C0000005` / `Access violation` | 0 / 0 | 0 / 0 | no host AV in either log |
| `OPEN-REFUSED-STATUS` | 74 (36 paths, all `reason=UNPROVED-BODY`) | **0** | the widened proof gate landed |
| — its bytes | `sum(served)`=`sum(logical)`=**3,941,814 B**, `sum(stored)`=9,075,788 B | — | no field on the row sums to 1,234,796 B; if you have a "1.23 MB" figure, name its field before reusing it |
| `SERVE-PROOF-SCOPE` | 0 | **24**, `ran=1` on 24/24 and `ok=1` on 24/24, 12 distinct paths | first firings of this marker in project history |
| `XSF-HOSTSERVE` (`pass=0` subset) | 94 rows, `pass=0` on **6** | 24 rows, `pass=0` on **0** | needle is `pass=0` after `pkgSubst=`, not right after the marker |
| `XSF-INFLATE-SIZE` | 8 | **0** | |
| `LIST-CONTENT-MISMATCH` | 0 | **0** | held — no wrong-bytes regression; literal present in `build/mcla.exe` |
| `GUESTVIEW-U32-FABZERO` | 16 rows / **7 distinct `caller_rva`** | **3** rows / 3 distinct (`0x213dbc`, `0x213ddb`, `0x213e00`) | host→guest context fix landed: 4 of the 7 call sites are gone. Whether the 3 survivors are a self-test is **UNVERIFIED** — no row and no comment in either log or in `src/` contains "self-test" |
| `SYNCTX-STACK` | 0 | 1 — `base=BA2A5280 top=BA2B5280 bytes=00010000 r13=8F200000` | new marker |
| `OPEN-ACCEPTED` | 20 rows / 10 paths | 24 rows / 12 paths | **but 4 paths LEFT** — see §3 |
| `DRAW-CP-REFUSE` | 8 | 8 | all 8 carry `what=no-translated-pso` |
| `DRAW-GATE` plausible / dummy | 0 / 8 | 0 / 8 | 8 draws attempted, **0 pixels** |
| `CP-SHADER-BODY` | 9, `printOmitted=0` on 9/9 | 9, `printOmitted=0` on 9/9 | full bodies in both |
| `CP-WAITREG-ISSUED` / `-SATISFIED` / `-TIMEOUT` | 8 / 8 / 87 | 8 / 8 / **88** | issued=satisfied=8/8; the +1 timeout tracks the extra wait, not a fault |
| `PHYS-POOL-FULL` / `o1heapAllocate returned null` / `MEMBER-EXPAND-SIZE` / `BE710-SLOT-MISS` | 0 / 0 / 0 / 0 | 0 / 0 / 0 / 0 | four wins hold. **All four literals verified present in `build/mcla.exe`** (61,617,664 B, mtime 2026-10-01 08:44:08) — counts 1 / 2 / 2 / 1 — so these are real zeros, not F-057(6) dead text |
| last `XTL-FREE-SUM` | `attempted=8064 honoured=2479 refused=5585 honoured_pct=30.7416 unaccounted=0` | **identical** | |
| last `PHYS-FREE-SUM` | `attempted=2512 honoured=2511 refused=0 honoured_pct=100.0000 unaccounted=1 phys_freed_bytes=25538560 glr=821E0640` | **identical** on every named field | the identity fields (`o1_allocated` `0x1bf0d000`→`0x1b642000`, `caller_rva` `0x2abf7f`→`0x2acfbf`) differ because the two runs are different builds; the counts do not |

**Poison check — and a correction to the claim that was handed to me.** `w685.log`: 75,874 non-empty lines,
600 distinct marker tokens (token 3 after `[ts] [level]`). Top shares: `READWRAP` 13,182 = **17.37 %**,
`CAS-SITE` 10,088 = 13.30 %, `WAIT[KWFSO]` 10,088 = 13.30 %, `WAKE[KWFSO]` 10,086 = 13.29 %,
`INFLATE-ENTER` 6,605 = 8.71 %, `CP-REG-T0` 2,136 = 2.82 %, **`TOCWALK-SLICE` 1,863 = 2.46 %**,
`TOCWALK-DIR` 1,862 = 2.45 %. **`TOCWALK-SLICE` at 1,863/75,874 = 2.46 % is confirmed — and it is the
7th-ranked shape, not the top.** **"No 3-token shape exceeds 10 %" is FALSE as stated.** By marker token the
top is 17.37 %; by `tools/soak_census.py`'s own shape collapse its `LOG QUALITY` lines report **13 %** as the
max (`#CAS-SITE ## lr=#FC#C …`, 10,087 rows; same for `WAKE[KWFSO]` 10,086 and `WAIT[KWFSO]` 10,048).
The honest reading: **`w685` is not newly poisoned** — `w684` was 14.47 % / 14.02 % on the same three
markers, and the tool emitted no `POISONED` verdict — but write **17.4 % by marker token / 13 % by the
tool's collapse, essentially flat vs w684**, never "under 10 %".

**Also from `tools/soak_census.py build/w685.log build/w684.log`, the one honest pipeline signal:**
`CP truth drains=16 last_rptr=0016 pub=49 put=49 (caught up)` — the command processor is **caught up**, not
frozen (this is the `put` column, not a waiter's `rptrWB=` field, which F-057(1)/F-058 retired as evidence).

### 2. Proven this session (nothing here is inherited)

- **`OPEN-REFUSED-STATUS` 74 → 0** while `SERVE-PROOF-SCOPE` 0 → 24/24 `ran=1 ok=1`: the proof gate is
  widened and 24 bodies are now actually proved and served. First data of this kind. §1 table.
- **The `chevy` token really is in the file, and it is capital-C.** Offline, reproducible in one line:
  `zlib.decompressobj(-15).decompress(rpf[0x00471000 : 0x00471000+0x933])` = **22,391 bytes**, matching the
  TOC `w1` logical exactly, and **`Chevy` occurs 8 times** at inflated offsets `[206, 3584, 4862, 7456,
  9154, 9587, 17960, 21899]`. **Re-measured 2026-10-01 from that same one-liner: case-SENSITIVE `Chevy` = 8, case-INSENSITIVE `chevy` = 8, lowercase `chevy` = 0** — so §4's `'Chevvy' x8` is the same 8 and the two spellings in this block never disagreed. (An audit pass reported them as an internal contradiction; it did not reproduce. The guest's own lowercaser `sub_82183870` is why the LOG prints `'chevy'` — `w685.log:25096` — while the member holds capital-C.) Context at 206:
  `…\tName\t\tChevy\r\n\tCanBeOnFire\t1\r\n…`. TOC from the log: `toc=[E94BDE63 00005777 00471000 40000933]`
  (`stored = 0x933 = 2355`, `logical = 0x5777 = 22391`, `off = 0x00471000`).
- **A raw stored-byte scan of the whole 2,130,739,200-byte archive finds exactly 1 case-insensitive
  `chevy` hit.** So all 8 real occurrences in this member are structurally invisible to a raw scan — that is
  the whole reason the earlier "not in the file" reading was wrong. (I did **not** locate the offending
  comment or confirm it has been corrected: **UNVERIFIED**.)
- **`XSF-OPEN` ret flipped 0 → 1 on the four `tune/*` paths that left `OPEN-ACCEPTED`**, with the same TOC
  words: `XSF-OPEN #595 … path='tune/vehicle/vehicle.lst' len=24 ret=0` (w684) → `ret=1` (w685), and
  `XSF-OPEN #537 … path='tune/rmptfx/tireptx.lst' len=23 ret=0` → `ret=1`. (`len=` is the path-string length,
  not the member length.) §3.
- **`GUESTVIEW-U32-FABZERO` 16 → 3 rows and 7 → 3 distinct `caller_rva`.** §1 table.

### 3. OPEN — the KNOWN REGRESSION, stated plainly and **not** softened

**Two first-seen markers in w685, 0 rows in w684, verbatim:**

```
UIXSF-REC pkg=64980000 shot=100 dest=B6282280 goldoff=00040000 len=262144 good=22145 firstbad=+5 probe=03657000 found_at=FFFFFFFF FOREIGN-CONTAINER foreign_pkg=64CB0000@5     (6 of 30 rows)
UIXSF-DIVERGE pkg=64980000 at=00040005 slot=B6282280+00000005 guest=[03657000 70616450 04B2B400 01CDCD00] golden=[04E23000 70616450 0B1B1400 01CDCD00] NOT-IN-GOLDEN-NEIGHBOURHOOD                                  (6 rows)
```

**A container belonging to package `64CB0000` has landed at offset +5 of a 262,144-byte guest-visible UI
region.** Stated as fact: that is what the two rows say. Stated as *open*: **what put it there is not
known, and I am not claiming a mechanism.** Across the 30 `UIXSF-REC` rows: `firstbad=+5` +
`FOREIGN-CONTAINER` + `foreign_pkg=64CB0000@5` on **6**, `firstbad=+0` + `UNKNOWN` +
`foreign_pkg=00000000@FFFFFFFF` on **24**; `len` ∈ {115785, 131072, 262144, 32768}.

**The size of the regression has a measured baseline in this ledger.** `docs/ROOT_CAUSE_VALIDATION.md:11073`
(F-515/F-516, soaks `w520`/`w521`) records the *same shot and the same `goldoff`/`len`*:
`UIXSF-REC pkg=64980000 shot=100 dest=B7C01000 goldoff=00040000 len=262144 good=144864 firstbad=+0 …
UNKNOWN foreign_pkg=00000000@FFFFFFFF`. **`good` 144,864 → 22,145 at identical `goldoff=00040000` and
`len=262144`.** That is the number to argue with, not the marker count.

**Falsifier for the whole item.** A w686/w687 soak that reprints `UIXSF-REC` at `shot=100` with
`good` back near 144,864 and `firstbad=+0` **kills the regression** and it was a one-boot artefact. A soak
that holds `good≈22k firstbad=+5 FOREIGN-CONTAINER` **confirms** it and makes the cause load-bearing. Until
one of those two lands, treat it as open in both directions.

**Second half of the same window — 4 paths LEFT `OPEN-ACCEPTED`:**
`tune/vehicle/vehicle.lst`, `tune/vehicle/vehicle0001.lst`, `tune/vehicle/vehicle0002.lst`,
`tune/rmptfx/tireptx.lst`. 6 paths NEW:
`textures/Random3D.dds`, `textures/effects/fog.dds`, `textures/effects/star_glow.dds`,
`textures/lightglow.dds`, `textures/random3d.dds`, `tune/lighting/SC.ppp`.

- `XSF-OPEN-GATE-SKIPPED path='tune/vehicle/vehicle.lst' entry=B737DE30 +8 00471000 -> host cache not
  poisoned, bit30 withheld from w2, would-be 40471000 (guest memory untouched)` — **fires in BOTH logs**,
  so the gate-skip is *not* new; only the `ret` flip is. `vehicle0002.lst` has **0** gate-skipped rows in
  either log, so "all four went through the gate-skip" is **false as written**.
- **`BDF20 ret` gained a third value in w685 that w684 never printed.**
  w684 = `{−2105144296: 1, −2105144256: 64, −2105144216: 139, 0: 70}`;
  w685 = `{−2105144296: 1, −2105144256: 12, −2105144216: 189, 0: 70, −2105144176: 2}` (274 rows each).
  Writing only "`-2105144256` → `-2105144216`" hides the new `−2105144176`.
- **`MEMBER-SPAN-OWNER refused=1` windows: 52 such rows in w684, 47 in w685.**
  `off=00448000 stored=166323 logical=294912 window=[00470000,00478000) bytes=1 refused=1
  firstRefused=00471000 tail=00490000` — present in **both**, so it **still refuses**. A **second**
  window `window=[00478000,00480000) refused=1 firstRefused=00479000` is **w685-only**.
  These are the *same* offsets as the two gate-skips above (`vehicle.lst +8 00471000`,
  `vehicle0001.lst +8 00479000`). **That is a coincidence of numbers I have measured, not a mechanism I am
  asserting.** Falsifier: show the two window owners are unrelated, or show they are the same span walked
  twice.
- **A regression hunt is in flight.** Do not re-derive any of the above; do not "fix" `UIXSF-DIVERGE` or
  `MEMBER-SPAN-OWNER` by suppressing them (do-not #1/#9).

### 4. The `chevy` fatal — the current chain, and the claims that were KILLED

**Chain, as measured in `build/w685.log` (10 `F442-SECTION` rows in the whole run):**

```
F442-SECTION #2 / #4 / #6  name='Manufacturer' r5=00000000 ret=00000000 hits=0 lr=82397290    (w685)
  -> 10 F442-SECTION rows total; ret distribution {00000000: 9, 00000001: 1}
  -> lr set {821874E8, 82397290 x3, 823972FC x3, 82397350, 823964E8, 82396510}
  -> Fatal error dispatcher invoked - terminating game
     fatal-dispatch regs: lr=0x823966E8 r1=0x8EFFF3A0 r3=0x82051DE8 r4=0x8EFFF4F0 r5=0x00000080
     fatal message: 'Unknown manufacturer %s in vehicle list file'
     FATAL-SOFT: 'Unknown manufacturer %s in vehicle list file' lr=823966E8 - guest paused
  -> 'Chevvy' x8 in the INFLATED tune/vehicle/vehicle.lst at [206,3584,4862,7456,9154,9587,17960,21899]
```

Carried from the ledger and **not re-decompiled this session** (no IDA run): the parser is `sub_821CFF40`
(`docs/ROOT_CAUSE_VALIDATION.md:13856`: "`sub_821CFF40(&it,"Vehicle",0)` found nothing, so `[0x828CD0AC]`
stayed 0"; `:9357` names the same call site `loc_82397328`), the walker is `sub_823971D0`
(`:8552`, `:8918`, `:8983`), the u16 count at `0x828CD07C` and its static registration at `0x828CD0A8`
(`:8946` = `### F-398`, `:9065`), and the reporter is `sub_821BD618` (`:12808`, `:13629`).
**UNVERIFIED this session — but the "0 hits each" here is WRONG, corrected in place 2026-10-01.** The brief handed to this session also names `0x828CD078` as the 8-byte-stride entry
array and `sub_823964C0` as `AllocateCarData`. Measured now over the whole file: `docs/ROOT_CAUSE_VALIDATION.md` holds **`sub_823964C0` ×3** (`:9568` in `### F-443`, `:15119` in `### F-700`, `:15669` in `### F-719`) and **`0x828CD078` ×2** (`:15119`, `:15823`); `### F-700`
states the brief's own chain verbatim ("`0x828CD078` is the 8-byte-stride entry array -> `sub_823964C0` finds `idx == count`"). **`AllocateCarData` itself is still 0 hits anywhere in the tree.** The epistemic status is unchanged — this session decompiled neither function — but
they are no longer *absent from the ledger*, so cite `### F-700` instead of re-grepping. Treat the two links as unproven until `tools/ida_dump.py` or `tools/ppc_disasm.py` prints them.

**Four claims that were killed, so nobody re-derives them:**

1. **"we serve only 10.5 % of vehicle.lst" is FALSE.** `stored`/`logical` is the **DEFLATE compression
   ratio**, not a served fraction: `2355 / 22391 = 10.52 %` — that is where the number came from. I inflated
   the member and got **exactly** the TOC `w1` logical length (§2). **The generalised form "41/41 members
   serve at full logical length" is UNVERIFIED by me**: neither `41/41` nor `10.5` occurs anywhere in
   `docs/ROOT_CAUSE_VALIDATION.md` (grep, 0 hits each), so I cannot cite its entry. Re-derive it or drop it.
2. **"XSF-BIND fired only twice so two files never bound" — the *gate* is confirmed, the *corroboration* is
   not available in w685.** The print is gated `if (n <= 16 || (n % 8) == 0)` at **`src/gpu_device.cpp:20420`**
   (the `MCLA_LOG_WARN("XSF-BIND …")` is `:20421`), and `n` is the **global open ordinal** — the rows beside
   it read `XSF-OPEN #595`. So 2 rows in w684 and 3 in w685 are a **filtered print, not a census**.
   The row that would corroborate it: **`NULL-HANDLE-CHECK` has 24 rows naming vehicle/tireptx in w684** (24
   of 129; sample `path='tune/rmptfx/tireptx.lst' ret=0 … proved=1 bound=1 slotHeldNoBody=0`) and **0 such
   rows in w685** (59 rows total, 24 with `proved=1 bound=1`, none on a `vehicle`/`tireptx` path).
   **So "proved=1 bound=1 for all three vehicle paths" is a w684 fact that w685 does not reprint.** Re-establish
   it before relying on it.
3. **The `walked == 2*t0` framing I was handed is WRONG, and the correction matters.** Both fields **are**
   printed — `CP: IB-OPC-CENSUS #1 ibTotal=1 win=B7C8A2C0 dwords=11 depth=0 trace=1 walked=11 t0=2 t1=0 t2=0
   t3=1 nonzeroT3=1 firstT3Off=5 firstT3Hdr=C0043C00 || op=0x3C count=1` — 32 rows in **each** log, so the
   identity **is** measurable. `### F-685` (`docs/ROOT_CAUSE_VALIDATION.md:14707-14718`) holds **8/8 in
   `w680`** and attributes it to a **TYPE degeneracy** (a zero dword scores TYPE-0 because `hdr>>30 == 0`),
   explicitly *not* to an empty buffer — and says the load-bearing evidence is the raw `CP: INDIRECT_BUFFER`
   dump showing 16 zero dwords where `PKT-CAP` read real bytes `0x20000000` lower, a *pointer-base*
   disagreement, which is what F-680's `CpPhysToPoolVa` addresses.
   **My byte-exact recount of the two current logs: `walked == 2*t0` holds 0 of 32 in w684 and 0 of 32 in
   w685.** So it is not a standing 8/8 invariant any more. **What is genuinely unsupported is the
   `holds=` metric: there is no `holds=` field on any row of either log (0 of 32 in both),** so any
   "real register writes" number keyed on `holds` is a F-057(6) tautology. Write it that way, not as
   "`walked`/`t0` are unmeasurable".
4. **Two dead instruments, both confirmed dead.** **`MEMBER-SPAN-TAIL-VETO`**: the string occurs on
   **194 rows in w684 and 196 in w685** and **every single one is a `MEMBER-EXPAND-OVERRUN` row** (it is
   prose inside that marker's message); 4 src occurrences, all in `src/fs/vfs_rpf.cpp`; 2 in
   `build/mcla.exe`. It has never once printed its own row. **`GUESTVIEW-U32-SUMMARY`**: 1 src occurrence
   (`src/guest_memory.cpp`), 1 in `build/mcla.exe`, **0 rows in both logs.** Per `AGENTS.md`/`F-057(6)` a
   marker's zero means nothing until you have proved the literal exists and can fire — here both fail.

### 5. Next free ID — measured, and the dead pointer retired

**Do NOT follow the 09-30 block's "Next free ID: F-654".** `### F-681` adjudicated it unsafe
(`docs/ROOT_CAUSE_VALIDATION.md`, `### F-681`: *"The instruction to begin at `F-654` is falsified by the
tree"*; the ledger carries the sentence *"NEXT FREE ID: F-654" IS UNSAFE. This is the reason this block
starts at F-681 and not F-654."*).

**CENSUS RE-MEASURED 2026-10-01, IN PLACE. This supersedes every number in the table below and the §5 prose under it; the reasoning is unchanged.** `docs/ROOT_CAUSE_VALIDATION.md` is **2,218,346 B** with **584** `### F-(\d+)` heading lines, **min F-77, max F-728**. Count only `^### F-\d+` headings — a naive `F-(\d+)` token scan of the file returns 5,684 and over-reports. **NEXT FREE ID IS `F-729`, NOT `F-697`.**
Seven ids repeat on a `^### F-\d+` scan (`F-111, F-200, F-204, F-595, F-612, F-617, F-681`), but only **four** are real duplicated headings (`F-111`, `F-595`, `F-612`, `F-617`); `F-200`/`F-204`/`F-681` repeat only via the lettered `### F-200b`/`### F-204b`/`### F-681b` and the compound `### F-612/F-613` / `### F-617/F-618` headings, exactly as `### F-681b` adjudicated — **left untouched, not renumbered.**
`### F-726` in the ledger records the same max and count and prints its own falsifier: a max other than `F-728` or a count other than **584** means another session appended mid-block and every next-free-id statement here is stale — re-run the census. It also records that `F-697`…`F-728` are all written, that **`F-693`/`F-694`/`F-696` are retroactively written as `### F-724`/`### F-722`/`### F-723`** (so their rows below are retired), and that **`F-695` is declared PERMANENTLY UNUSABLE** — 0 `src/` citations, 0 headings, genuinely free, but sitting *below* the consumed `F-696`, so do not back-fill it and do not "tidy" the sequence. The ledger's own footer reads *"NEXT FREE ID: `F-729`. Do not take `F-695`."*

| what | measured | verdict |
|---|---|---|
| max `### F-NNN` heading | **F-728** (was **F-692** when this block was written) | naive "next" = **F-729** |
| **safe next free ID** | **`F-729`** (was **F-697**) | `F-697`…`F-728` are all written; `F-693`, `F-694`, `F-696` are now **entries**, not orphan citations |
| `### F-681` … `### F-728` | **48** headings present (was 12 through `F-692`) | the real sequence starts at F-681 |
| **`F-693`** | **4 citations, 0 entries** — 3 in `src/fs/vfs_rpf.cpp`, 1 in ledger prose at `docs/ROOT_CAUSE_VALIDATION.md:14992` | **CITED, NOT AN ENTRY.** Allocating F-693 collides **[SUPERSEDED 2026-10-01: retroactively written as `### F-724`; no longer an orphan.]** |
| **`F-694`** | **7 citations, 0 entries** — **all 7 in `src/`** (`src/gpu_cp.cpp`, `src/render_queue.h`), **0 in any doc** | **CITED, NOT AN ENTRY.** Note: it appears in *no* ledger prose, so nothing warns you **[SUPERSEDED 2026-10-01: retroactively written as `### F-722`; no longer an orphan.]** |
| **`F-696`** | **3 citations, 0 entries** — all 3 in `src/fs/vfs_rpf.cpp`, 0 in any doc | **CITED, NOT AN ENTRY.** This id was **not** in the brief that produced this block; I found it by census **[SUPERSEDED 2026-10-01: retroactively written as `### F-723`; no longer an orphan.]** |
| `F-629` | 18 citations (2 in `src/gpu_device.cpp`, 16 in docs), 0 entries | **documented VOID SLOT** — ledger: *"VOID SLOT F-629 - F-629 EXISTS ONLY IN CODE"*; `AGENTS.md` forbids reuse. Do not renumber; reconstruct as a new F-6xx/7xx citing 629 |
| `F-654`…`F-659`, `F-680` | 0 entries; my counts 25 / 18 / 6 / 40 / 9 / 5 / 37 = **140 citations** | cited with no entry, adjudicated by `### F-681`. My 140 ≠ F-681's 91 because my scan counts `docs/ROOT_CAUSE_VALIDATION.md`'s own prose too; **do not present either number as the other's** |

**Full orphan-citation list (cited somewhere, no `###` heading). 114 ids, in two classes:**

- **Class A — below the ledger's first heading (76 ids): `F-001`…`F-076`.** The ledger's minimum heading is
  F-77, so nothing below it can have a heading; each is cited **once** in ledger prose and **zero** times in
  `src/`. This is the pre-compaction range (`AGENTS.md` describes the ledger as compacted to
  "claim + evidence"), not a new loss.
- **Class B — inside the range, no heading (38 ids), with my citation counts:**
  `F-150`×6, `F-153`×8, `F-162`×5, `F-258`×5, `F-266`×1, `F-329`×29, `F-364`×5, `F-388`×6, `F-389`×4,
  `F-390`×6, `F-409`×3, `F-412`×64, `F-427`×7, `F-429`×5, `F-460`×1, `F-466`×1, `F-483`×5, `F-494`×3,
  `F-511`×27, `F-516`×10, `F-524`×11, `F-528`×3, `F-610`×79, `F-615`×6, `F-618`×17, `F-625`×20,
  `F-628`×50, `F-629`×18, `F-654`×25, `F-655`×18, `F-656`×6, `F-657`×40, `F-658`×9, `F-659`×5,
  `F-680`×37, `F-693`×4, `F-694`×7, `F-696`×3.
  Of these, **`src/` alone** carries: `F-412`×55, `F-610`×52, `F-680`×25, `F-654`×12, `F-657`×34,
  `F-655`×16, `F-694`×7, `F-696`×3, `F-658`×6, `F-656`×4. **`F-694` and `F-696` are the only two with
  zero doc citations at all** — a `src/` comment can be the sole record of a finding, and both are invisible
  to anyone who reads only the docs.

**Rule to carry forward: allocate the next id above `max(heading)` **and** above every orphan citation.
Today that is **F-729** — `F-697` when this block was written, which is now itself an entry (`### F-697`, ledger `:15001`). F-681 is the precedent for refusing a lower allocation.**

**The two-queue rule, and where the queue actually lives.** `docs/LONG_TODO_MASTER.md` §2 is
`## 2. Tasks (in order; stop-ship gate each)` at **line 992**, running to before `## 3. File map` at
**line 1606**. **Measured drift:** `T41.59` and `T41.60` appear only at LTM lines **315 / 331 / 344** —
all inside a `§0` state block, **not** in §2. `T42.20` → **0** hits anywhere in LTM. `task #87` → **0**
hits in LTM. `F-692` → **0** hits in LTM. Real sequencing migrated to ids invented **inside the ledger**
(`T41.59`→`T42.20`, "task #87") that §2 does not contain. **Both places are named here so neither is
silently the truth: the durable queue is §2, the live sequencing is the ledger, and they have diverged.**
Per `AGENTS.md` a queue item may not live in only one of them.

### 6. Durability — read this before you trust a number that is not in a log

- **HEAD is `83859255b0b7bdff740aeaf8d7195beccfe6e96c`, dated `2026-09-27 23:23:27 +0300`**
  (`rpf_offline.py: stop names/find crashing on a truncated tail record`). **The 09-30 block's "last commit
  `d7125d1`" was the last commit that *touches the ledger* — `git log -1 -- docs/ROOT_CAUSE_VALIDATION.md`
  = `d7125d1e48a9088871cf2aebfd1294a93600b65d` — not HEAD.** Both facts are recorded because only one of
  them was true and the block stated the other.
- **F-572…F-692 plus ~42 modified / 13 untracked `src/` files exist ONLY in the working tree**, on the E:
  drive that zeroed this ledger once on 09-20. Measured today: `git status --porcelain` = **99 lines**
  (56 ` M`, 2 ` D`, 41 `??`); under `src/` **55** = **42 ` M` + 13 `??`**. `git diff --shortstat HEAD` =
  **58 files changed, 53,764 insertions(+), 16,220 deletions(-)**; `src/` alone = **42 files,
  +34,453 / −2,916**.
- **The ledger's uncommitted delta — corrected in place 2026-10-01. The 09-30 block's "~194 KB of uncommitted
  ledger work" is stale, and so was the version of this line written with the block.** Measured now: working copy
  **2,218,346 B** vs HEAD blob **1,846,156 B** = **Δ +372,190 B**; `git diff --numstat HEAD -- docs/ROOT_CAUSE_VALIDATION.md` = **+16,078 / −12,965 lines**; `git diff --shortstat` on that path = **1 file changed, 16,078 insertions(+), 12,965 deletions(-)**; counted off the diff text itself, **+2,202,187 / −1,832,776 B**.
  **Name the field you mean** (file size vs size delta vs lines vs diff bytes). Those are four different figures, not variants of one, and the audit brief's "~2.0 MB added / 1.4 MB deleted" matches none of them exactly.
- **A verified off-volume backup now exists at `C:\mcla-pc-uncommitted-20261001\`** (C:, off the E: volume
  that lost the ledger). Re-measured this session: `tracked.patch` **6,729,792 B**, sha256
  **`466ed6a739cd50712c0a80cb61c1a1915f58cf5c2a1e08229dd4b36d6a14f6e1`** — matches `MANIFEST.txt:29`;
  **`untracked\` holds 46 files**, re-counted this session; `staged.patch` is **0 B**. `MANIFEST.txt:12-13`
  records `git diff --stat HEAD : 58 files changed, 53633 insertions(+), 16216 deletions(-)` and
  `of which under src/ : 42 files, +34322 / -2912`; `MANIFEST.txt:97` records
  `46 of 46 files re-hashed source-vs-copy, 0 mismatches (sha256 AND byte length)`; `MANIFEST.txt:3` says
  *"Purpose: PROTECT uncommitted work. NOT a commit. Repo untouched."* and `MANIFEST.txt:7` pins the same
  HEAD sha.
  **Honest caveat: the tree has drifted since the manifest was written** — my recount is +53,764/−16,220
  overall and +34,453/−2,916 under `src/`, i.e. **+131 and +131 lines** past the manifest. The backup is a
  verified snapshot of an earlier moment, not of right now. Re-run it before relying on it.
- **Project rule: commit only when asked. NO COMMIT HAS BEEN MADE.** This block is a working-tree edit to
  one doc. Nothing was staged, nothing was stashed, no code was edited, no build was run, no game was run.
- **Do not `git add -A` here.** `docs/HANDOFF_NEXT_AGENT.md` was **already ` M`** before this block (pre-edit
  sha256 `8134f2cc32e1778cb809a9b624bcca2b81b2e3e536ab5d0b649effa1263b174a`, 495,673 B, mtime 2026-09-30 12:10:47). **The line count is corrected in place 2026-10-01: the block said "2,545 lines", which is impossible — the true pre-edit count is 3,014 lines.** HEAD's blob is **2,601 lines / 447,107 B, 2,601 LF and 0 CRLF** (`git cat-file -s HEAD:docs/HANDOFF_NEXT_AGENT.md`) and `git diff --numstat HEAD` = `718  0`, so the file is now **3,319 = 2,601 + 715 + 3**; this block is lines 1-301 and the pre-edit file was lines 303-3316 = **3,014 lines**. Reconstructing those bytes gives **495,667 B**, Δ6 B from the 495,673 quoted above — the ±1 separator blank at the block boundary is unresolvable — so **the quoted byte figure and sha256 stand as the author's own measurement, UNVERIFIED by me.**
  Stage named paths only; `git add -f docs/…` for a newly tracked doc.

### 7. RETIRED: the 09-28 "The tree is RED. It does not boot."

The 2026-09-28 19:5x block's line 1 sentence — **`**The tree is RED. It does not boot.**` (this file, line
116 of the pre-edit text, quoting `build/w657.log` at 1,173 lines)** — is **RETIRED as of this block.**
`build/w685.log` builds, boots 180 s, reaches the render thread, submits **8** real draw submissions
(`DRAW-CP-REFUSE` 8, `DRAW-GATE dummy` 8, `DRAW-GATE plausible` 0), has **0** host AVs, and terminates in a
**truthful guest assert** — the guest correctly refusing a manufacturer it cannot find. That is a
**different failure class** from "does not boot": the pipeline runs, the guest is talking, and the guest is
telling us the data is missing. **Do not delete the 09-28 block — it is superseded here and kept as trail.**

### 8. Bookkeeping for the session that wrote this block

- **One file touched: `docs/HANDOFF_NEXT_AGENT.md`. This block is PREPENDED at lines 1-301 and no pre-existing line was
  edited, reordered or deleted by it (per `AGENTS.md` rule 5). **"Prepended only" was FALSE as written — corrected in place 2026-10-01, not by deleting the evidence:** `git diff -U0 HEAD` on this file is exactly two hunks, `@@ -0,0 +1,715 @@` and `@@ -2601,0 +3317,3 @@`, i.e. **718 insertions / 0 deletions**, so 3 lines were also **appended at EOF** by another session. They are lines **3317-3319**, they are **all blank**, they carry **no date header and no content**, they are not attributable to this block, and they were deliberately **left in place**. (The 715-line top hunk is this block's 301 lines, plus the blank separator at :302, plus the whole uncommitted 2026-09-30 block; HEAD's newest `##` block is the 2026-09-27 20:2x one.) **`AGENTS.md`, `docs/PROGRAM_GUIDE.md` and
  `docs/ROOT_CAUSE_VALIDATION.md` are untouched by me** — and note this means **the ledger has still gained
  no row for this session's work**; whoever owns `### F-693`+ should record it there.
- **Every marker literal quoted in §1–§3 was verified present in `src/` or in `build/mcla.exe` before its
  zero was interpreted** (the F-057(6) rule). The three exceptions are named as exceptions in §4.4.
- **Pre-edit sha256 of this file: `8134f2cc32e1778cb809a9b624bcca2b81b2e3e536ab5d0b649effa1263b174a`**
  (495,673 B). Post-edit sha256 is recorded in the session report, not here.

---


---
**[2026-10-01] Session trail relocated to [docs/archive/trail-handoff-2026-10.md](docs/archive/trail-handoff-2026-10.md)** (blocks 2026-09-30 backward; nothing deleted).

---

# 2026-10-06 — HANDOFF: the boot blocker is SOLVED. Read this first.

`HEAD = 3606e30`. Working tree clean under `src/`, 0 staged. **Do not redo anything below.**

---

## 1. THE BLOCKER IS FIXED. THE EVIDENCE, AND THE MEASURES THAT PROVE IT

`a9bd027` — **`gpu_device`: snapshot the reader cursor before the device read.**

**Cause, in one sentence.** `pos` is dword 1 of the reader object the caller passes as `r4` — the
guest's own byte cursor into the member's logical bytes. The file already snapshotted `r4`/`r5`/`r6`
around `__imp__sub_821CC1E0` but **never extended the snapshot to the two dwords it then read out of
guest memory**, so every read observed the *previous* read's end position. The callee's tail advances
it: raw `0x821CC3CC stw r11,4(r31)`.

**The falsifier that killed the alternative reading** — do not re-derive it:
> 18 rows, 18 different members, six different archive offsets, `pos=4096` on every one and
> **never 8192**. An accumulating cursor cannot read 4096 on eighteen independent first pages.

**Measured, `build/w734.log` and `build/w736.log`:**
```
                             w733 (had a fatal)   w734/w736 (no fatal)
Fatal error dispatcher / FATAL-SOFT     1                 0
dstAfter=507B5CED   (DEFLATE head)     1                 0
dstAfter=61786772   (shader magic)     0                 1
ARC-WINDOW headIs=1 (byte-exact)       0                 1
WINWR-CMP beqTaken                     0                 1    r7 = r8 = 0x61786772
boot duration              ~14 s to a fatal    149.8 s, no fatal
DRAW-CP-DRAWN                            -                 4    (was 2)
golden pct=100                          25                30
```
**The plateau is over.** 27 soaks died at 14.494–16.184 s. These do not die.

**The window is NOT a ring** — settled, do not re-open: the fill is clamped by
`uncompressedSize - cursor` (raw `0x821CC260`–`0x821CC27C`), `cur`/`end` are monotone, and two
windows exist one page apart (`0x82861DF8`, `0x82862DF8`). Double-buffering, not a ring.

---

## 2. THE CURRENT WALL — narrow, measured, and NOT a fix you can guess

```
VEH[3] code=0xC0000005  lr=8218B458  read of host addr 0x7e780000
     slot_guest_va=0xFFFFFFFF7E780000
preceded by: BE710-DEAD … outcome=REFUSE-NO-BODY
             XTL-ALLOC-REFUSED size=413 -> returned 0
             o1heap invariants FAIL
```

**The arithmetic is solved.** `slot_guest_va = 0xFFFFFFFF7E780000` becomes host `0x7E780000` via
the **same expression `src/ppc_context.h:127` evaluates.** An agent predicted `would_read_host =
0x7E780000` analytically, before running anything, and a soak reproduced it to the digit.

**The gate is not solved.** A guard on `sub_8218B0C8` was written, soaked, **and reverted** because:

```
AVGUARD-CTR-OOR #8  vt_read_ok=0  vt=00000000  slot_read_ok=0  passthru=0
```
**`passthru=0`** — the host could not read `ctx.r3` at all, so the guard refused **every** call,
including legitimate ones. `FATAL-SOFT` went 0 → 1, `dstAfter=61786772` 1 → 0, `DRAW-CP-PIXEL`
2 → 0. Reverted with `git checkout 3606e30 -- src/gpu_device.cpp`; the good state is restored and
re-verified in `w736.log`.

**THE QUESTION TO ANSWER: why is `ctx.r3` unreadable at `sub_8218B0C8`?** That is a guest-object
resolution problem, not a fault to guard against. `IsKernelObject(handle)` is only
`Translate(handle) != nullptr` (`src/kernel/xdm.cpp:32-39`) and `Translate` returns `m_base +
guestAddr` for **every** `guestAddr < kSize` (`src/kernel/memory.cpp:476-481`, `kSize = 0x100000000`).
**Establish whether that predicate should admit `0xFFFFFFFF7E780000`, and what the real object is.**

⚠️ **A guard that removes the crash while destroying the boot is a net loss.** The crash is a
symptom; reaching the shader check is progress.

---

## 3. A REGRESSION THAT IS NOT ONE — and why it matters more than it looks

```
TOCWALK-SLICE   w685..w722 = 1863 (34 logs, perfectly constant)
                w723..w736 = 0     (14 logs)
AFB8-IN         35 -> 1     BE710-MAGIC 114 -> 0
```
**The TOC walk never ran legitimately.** It ran 1863 times *only because the `kBe710MagicWrite`
fabrication kept the guest limping past 57 dead bodies* long enough to miss `EmbeddedListLookup`
35 times. Remove the lie → 1 open → 0 walks. **This was attributed by content plus a measured
single-variable revert**, because a commit-date bisect is structurally impossible: **all 13
commits have committer-date ≥ 10-05 16:28, i.e. 14 h after w723. The good state was uncommitted.**

**The serve gate is NOT the cause.** Reverting `ret >= 0` at `gpu_device.cpp:22297`:
```
AUtoc_head_control   TOCWALK-SLICE=0  fatal=False
AUtoc_revert_gate    TOCWALK-SLICE=0  fatal=True    <- the fatal RETURNS
```
**So the gate widening is load-bearing for the no-fatal property. Do not revert it.**

**`REFUSE-NO-VERDICT` = 0 in ALL 45 real soaks including healthy ones — it carries ZERO
information.** Its only literal (`gpu_device.cpp:21738`) is inside `if (verdict == nullptr)`, which
is unreachable once `TOCWALK-SUMMARY` has stored a verdict. **Do not use it as evidence.**

---

## 4. CORRECTIONS TO THE RECORD — do not re-import these

| the record said | the truth |
|---|---|
| `F-647`: all three decompilers render rotate-masks backwards | **INVERTED.** MB=1,ME=1 ⇒ bit 30 ⇒ `0x40000000`, which is what the ISA, `ComputeMask`, IDA and `ppc_recomp.17.cpp` all print. Corrected in `AGENTS.md`. |
| `ori`'s destination is `b20:16` | **`b25:21`.** Correct for `ori`/`addi`/`addis`/`lwz`/`stw`; `b20:16` is correct for `or`/`and`/`xor`/`mr`/`cmp`. **Both right, different opcodes.** |
| `rec[8]` is zero | **wrong address** — `[rec+8]` is the caller's state object; the archive offset is `[[rec+0]+8]`, and it is **non-zero**, 4 KiB-aligned. |
| `o8` is page-quantised | **exact archive offsets** (`0xE4000/0x10000 = 14.25`). |
| `o8=0x000F5000` is "one hex digit" from `0x001F5000` | **1 MiB apart, different member** (`cf_bump2.dds`). Coincidence. |
| `TOCWALK-SUMMARY` at `vfs_rpf.cpp:21174` | **`gpu_device.cpp:21665`**. `REFUSE-NO-VERDICT` is `:21738`, not `:21247`. |
| "24 soaks, median 14.903 s" | **45 real soaks exist, not 43 or 123** — 42 are 0-byte sidecars. The literal `'Unexpected EOF…'` is in **2 of 45**. |
| `AUDIO-FRAME`'s zero is prose | **the marker is compiled and leads its own row.** The zero is real. |
| `M6_PAGE_SPLICED_AT_+0x5000` / `M6_PAGE_RAW_AT_+0x5000` | **do not exist anywhere in `src/`.** Phantom. |
| `TIMEOUT_SURVIVED` = a pass | **= 0 across 232 logs.** Not one log ever ended because the guest was running; every soak dies of a fatal then thrashes to the cap. **`process survived` is NOT a pass condition.** |

---

## 5. A NEW ENCODING FINDING THAT MAKES 123,273 TARGETS RESOLVABLE

**opcode-18 branches use a 26-bit LI at word bits 2..27, AA at bit 1, LK at bit 0.**
The textbook 32-bit I-form (bits 6..31) puts **0 of 147,363** opcode-18 words inside the image;
this reading puts **144,170** inside and lands **123,273** on functions that exist in
`ppc_func_mapping.cpp`.

**`AGENTS.md` currently says op18 targets are "unresolvable both ways". That is now wrong, and it
was propagated into briefs that told three agents to give up.** ⚠️ **Verify on a second sample before
correcting `AGENTS.md` — I have already put one wrong rule in that file tonight.**

---

## 6. THE STANDING RULES THAT COST THE NIGHT — read these before touching anything

- **Extract instruction fields nibble by nibble.** Shift-and-mask produced **four** wrong answers.
- **`ppc_disasm.py` is a PowerPC disassembler and CANNOT decode Xenos GPU microcode.** It also inverts `mr` (F-112) and cannot decode `rldicl`. Use `generated/ppc_xenon/*.cpp` as the tiebreaker.
- **`ppc_xrefs.py calls` invents callers on vtable dispatch** — it reported 20 "callers" of `0x821BE250` where a raw scan finds **0**. Its `->` column names the *enclosing* function.
- **`CALLERS (none)` is an IDA carving artefact, not evidence.**
- **Never put a constant in a census field.** `WINWR-CMP` printed `kAoCmpR8`, a hardcoded literal, and that "measurement" was believed for an hour. Deleted.
- **Establish the discriminating power of any control.** One believed *powerless* discriminates five wrong-models; one believed *sufficient* was symmetric and could never have found its bug.
- **A marker's prose can contain other markers' literals.** `READAT-BRANCH`'s prose contains `raw_positional=1`. **25 of 39 miscounts were this.**
- **A marker absent from `src/` has a zero that means nothing.** `AUDIO-FRAME` is live; `MEMBER-SPAN-ALIAS` is not tracked; `MEMBER-SPAN-TAIL-VETO` has 0 real rows and 33 prose mentions.
- **Never accept a fix on a marker count.** Nine fixes moved markers and not the boot. The measures that count: `headIs=1` byte-for-byte against a python-`zlib` oracle, `dstAfter=61786772`, `FATAL-SOFT=0`.
- **`git checkout <commit> -- <file>` does NOT restore a byte-exact pin** — `core.autocrlf=true`, files are bare-LF, checkout converts. **Verify reverts by content.**
- **Six+ harnesses passed while blind.** One served a body out of a **zero page** and reported fabricated bytes while passing. One reported **90.5%** because it harvested English prose as data. One reported a confident **0** because `re.match` anchored at line start and every line begins with a tab.
- **E: FAILED MID-SESSION.** 158 `.obj` files and `mcla.exe` became unreadable *and undeletable*; `src/gpu_device.cpp` lost its content. A reboot cleared it. **Verify `build/mcla.exe` begins `4D 5A` before every build** — a corrupt exe reports `BUILD_RC=0 error=0`.

---

## 7. THE QUEUE

`docs/LONG_TODO_MASTER.md`, dated block "2026-10-06 — QUEUE AFTER THE BOOT BLOCKER WAS SOLVED",
39 items in three tiers. **Tier 1 is everything behind the blocker that has never once been
exercised:** audio (the guest never constructs the XAudio object — `sub_823F3640` has no caller
and is not in `.CRT$XCU`), input (implemented, hooked, polled every frame, **0 non-NULL polls
ever**), and **the menu, which has 0 evidence in 261 logs.**

⚠️ **71 `LOG_UTILITY` sites in `src/kernel/imports.cpp` compile to nothing under `NDEBUG`, with no
log line at all.** Parts of this project are invisible to every log we have; their zeros are
tautologies.

**The charter win stands and must not be undone:** `kBe710MagicWrite` wrote the exact value the
guest was about to check for, suppressing **57** fatals. Deleted. Verify absent at all times:
`kBe710MagicWrite` = 0, `WriteU32BE(ctx.r4` = 0 across `src/`.
