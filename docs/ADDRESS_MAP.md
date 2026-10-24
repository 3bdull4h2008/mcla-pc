# MCLA PC — Guest Address Map (نفضة العناوين)

Organized census of every guest address this project has measured. Built 2026-10-24
from F-873..F-878 ledger entries, w897/w898/w899 soak logs, raw image scans of
`build/cache/mcla_pe.bin` (offset = VA − 0x82000000, big-endian), and the RTTI/string
sweep of 2026-10-24.

**Rules of this document.** Every claim cites a tool output (log row, raw-word scan,
`addr_owners`, or RTTI bytes). "UNKNOWN" is a valid answer. Values marked `w899` are
final-state reads from that soak. Watch-caps caveat (from the globals sweep): the
PAGEWATCH R budget is 8 rows *lifetime per run* and the W window is 64 rows shared —
absence of rows after 22:39:15 in w899 is structural, not evidence of absence.

---

## 1. CLASS IDENTITIES (RTTI-resolved, the naming correction)

| What we called it | Real identity (byte-level) | Evidence |
|---|---|---|
| "GFx gate object" `A0487720` | **`mcGraphics` instance** (84 B) | RTTI `.?AVmcGraphics@@` at `0x827E55DC`; base `rage::datBase` (TD `0x827D1538`); vptr at object offset 0; sole vtable slot `sub_823046A8` (string-sweep agent, 2026-10-24) |
| "gate vtable" `0x82041D58` | `mcGraphics` vtable | vptr `0x82041D58` resolves through COL; sibling COLs `0x820E7B3C→0x82041D4C`, `0x820E7B88→0x82041D54`, `0x820E7BF0→0x82041D5C` (positive controls for the instrument) |
| "loader ctor" `sub_824C6F08` | kernel-export implementation, handle `0x40002005` | export table at `0x82117838`: `[40002005 824C6F08 40001905 824C6F70 40003D03 824C7068]` (raw words, F-878) |
| "Movie lifecycle" `sub_824C6F70` | kernel-export `0x40001905` **and** slot in BOTH loader vtable families (`0x8206DF70`, `0x820736E8`) | vtable scan, 3 image hits exactly (F-878) |
| "GFx-GATE check" `sub_822C0980` | `mcGraphics`-dispatch path reading `mem[0x8288B9AC]+72` | raw disasm `:822C09C0..09E0` (F-876) |
| "queue at [0x8288B9E8]" | **`mcRenderThread` Flash semaphore queue** | strings `mcRenderThread::FlashSemaWait/Signal('%s')` at `0x82042128/0x82042188`; semaphore names exactly two image-wide: `Update` `0x82042178`, `Draw` `0x82042180` |

Semantic note: the word "gate" does not exist in the image (0 `Gate`/`gate`/`Sema`
strings). The +68/+72 countdown is `mcGraphics`-related state; keep calling the
*instrument* GFx-GATE (it is our marker name), but do not reify the class name.

---

## 2. KERNEL EXPORT TABLE (consumer still unidentified)

At `0x82117838` (raw words, w899-era scan):

| handle | fn | fn identity | host impl (src/kernel/imports.cpp) | dispatched in w899 |
|---|---|---|---|---|
| `0x40002004` | `0x824C6E88` | (full table pending background agent) | pending | pending |
| `0x40002005` | `0x824C6F08` | "loader ctor" | pending | no (no loader object ever constructed; nGfx=0, W34-NOGFX) |
| `0x40001905` | `0x824C6F70` | "Movie lifecycle" / loader-vtable slot | hooked log-only (`task_dispatch_trace.cpp:1980`, W35-MOVIE-LIFE) | **no — 0 rows ever** |
| `0x40003D03` | `0x824C7068` | pending | pending | pending |

Static calls to `0x824C6F70`: **0** (`ppc_xrefs.py calls`). Reach is vtable-only, and
no object carries either loader vtable family in w899 (nGfx=0).
Consumer hunt so far: `ppc_xrefs.py xref 0x82117838/0x82117840` = 0 sites; raw
`lis 0x8211 + disp 0x78xx` scan = 0 pairs. Background agent is sweeping wider
(r13-relative / addis splits).

---

## 3. STATIC GLOBALS (the 14-address sweep, w899 + raw image)

| Address | Role | Paired materializers | Armed in w899 | Final value (w899) | Notes |
|---|---|---|---|---|---|
| `0x8288B9AC` | mcGraphics-instance ptr (was "gate obj ptr") | **73** (86 hits) | yes | **A0487720** | written once by `lr=82304724` (F-875 installer) |
| `0x8288B9E8` | mcRenderThread queue obj ptr | 77 (106 hits) | no | UNKNOWN (A04876A0 via F360/F879 hooks) | 100 access-class sites |
| `0x8288E6F0` | tick-inhibit switch | 0 paired (3 access, unpaired) | yes | **00000000** | single init write `lr=821327F8`; never non-zero |
| `0x82830B14` | dispatcher-entry global (sub_821FC008 checks `[[..]+8] > 1000`) | 29 | no | UNKNOWN | 37 access sites |
| `0x82830998` | mgr ptr (GFx-GATE `mgr=`) | 3 paired | no | UNKNOWN (A050A320 in gate rows) | |
| `0x82830990` | boot-init struct (sub_82131508 `r31`) | 6 paired | no | UNKNOWN | sub_82131508 runs exactly once |
| `0x82839D70` | second object (vt+24 = 0x821827E8, "lookup helper") | **196** (253 hits) | no | UNKNOWN | the busiest global we track |
| `0x82839254` | **GPU context ptr** | 125 | yes | **40002080** (a kernel handle!) | `GpuContextPoller: Started polling` |
| `0x82860844` | device-registry header | 4 paired | yes | **A0485450** | |
| `0x828CD078` | manufacturer table | 4 paired | yes | UNKNOWN | **armed but zero rows ever** — the init burst skipped its stripe; not a cap artifact |
| `0x8289B9EC` | FlashSema debug flag (`sub_82305870` prints if non-zero) | 0 paired (8 access) | no (note: `8288B9EC` armed — different page!) | UNKNOWN | |
| `0x8289B9F4` | mcRenderThread frame counter (sub_82305E38 loop) | 0 paired (12 access) | no | UNKNOWN | |
| `0x8289B9FC` | FlashSema depth counter | 0 paired (4 access) | no | UNKNOWN | |
| `0x8286D810` | 17,000-byte alloc result (F-363b/F-563) | **245** (333 hits) | no | **A0419850** (via F361-BOOTOBJ ×4) | the alloc SUCCEEDED |

---

## 4. HEAP OBJECTS (w899 lifecycle — detail pending background agent)

| Object | Class/role | First | State at soak end |
|---|---|---|---|
| `A0487720` | mcGraphics instance (84 B) | 22:39:14.919 | alive; +68=5/+72=5 armed by F878 hook; tick consumed 5→0 at 22:42:16+ |
| `A04876A0` | mcRenderThread queue | 22:39:15.653 | alive; item `[+92]=821FC008 [+104]=1` landed 22:39:16.035; callback dispatched 8+×; never consumed |
| `A0485450` | device registry array | 22:39:01.153 | alive |
| `A050A320` | mgr (GFx-GATE rows) | pre-gate | alive |
| `A0513FC0` | owner read at gate+4 | 22:39:50.124-era | alive (read ×4 by lr=821C1BB8) |
| `B5FAC000` | **movie root, VALID** (DIU head, 1793 chars, 164 frames @60fps, 1356×705) | 22:39:15-era | constructed: `[B5FAC000]` stamped `82085364` (swfC) — in-place construct BY DESIGN |
| `B5F67C00/B5F678C0/B5F67C60` | child containers (vt `C4445500` family) | 22:39:15-era | unconstructed children (F-801 known issue) |
| `B7B41000` | dest container (vt `82085364`) | early | arr=0 cnt=0 in place rows |
| `B3ABBC20` | movie characters array (1793 entries) | with movie root | alive |

---

## 5. VTABLES

| VA | Family | Contents known |
|---|---|---|
| `0x82041D58` | **mcGraphics** | sole slot `sub_823046A8`; object = 84 B at A0487720 |
| `0x8206DFAC` / `0x8206D000` page | GFx loader family A | contains slot `sub_824C6F70` at `0x8206DF70` (full dump pending) |
| `0x820736E8` / `0x82073000` page | GFx loader family B | contains slot `sub_824C6F70` (full dump pending) |
| `0x82085364` | swfC (constructed movie container) | stamped over serialized DIU root at B5FAC000 |
| `0xC4445500` / `0xD0815500` | unconstructed-child markers | B5F67Cxx children |

---

## 6. CALL CHAINS (measured)

### UILOAD / queue chain (ALIVE end-to-end, w898+w899)
```
sub_82134D08 (boot pump) ──posts──> item{cb=0x82131008}          [F-358]
sub_82131508 (runs ONCE) ──> sub_82304708 (mcGraphics ctor)       [F360-REGCB, F878]
                              └─ installs mem[0x8288B9AC]=A0487720
copier sub_82305690      ──lands──> queue[A04876A0]+92=821FC008   [F365, w898 20:38:41.004]
dispatcher @lr=82305F80  ──calls──> sub_821FC008 (8+×)            [F879-QUEUECB, w899]
sub_821FC008 ──> sub_82305870(queue,1) = FlashSemaSignal('Update'/'Draw')
                   └─ release @queue+52 via 0x821C8F08            [raw disasm]
```

### mcGraphics countdown chain (ARMED AND WORKING since F878)
```
F878 hook: +68=5,+72=5 at install ──> tick sub_823043F8: 5→4→3→2→1→0
sub_822C0980: +72>0 ? gate=1 : gate=0            [w898: gate=1 for 4 ticks]
gate=1 ──> sub_82304428 ──> 0x823083F8 (generic ctor, 24 call sites)
```

### The wall (current frontier)
No GFx loader object (nGfx=0, W34-NOGFX): export `0x40002005` (`sub_824C6F08`)
is never dispatched; vtable families `0x8206D000/0x82073000` never instantiate.
The movie root data is VALID and CONSTRUCTED as a container, but no Scaleform
Movie/loader ever parses it.

---

## 7. INSTRUMENT OWNERSHIP (rule 4 ledger)

| Guest addr | Host hook | File:line | Status |
|---|---|---|---|
| `sub_823043F8` | F875-GFX-TICK | task_dispatch_trace.cpp:1921 | log-only, fires |
| `sub_82304708` | F878-GFX-GATE-INSTALL | task_dispatch_trace.cpp:1956 | writes +68/+72 (mitigation, labelled) |
| `sub_825FDBF8` | FDBF8 census | task_dispatch_trace.cpp:1088 | log-only |
| `sub_825FB0D8` | FB0D8-DTOR | task_dispatch_trace.cpp:~1290 | log-only, guards dtor AV |
| `sub_821FC008` | F879-QUEUECB | task_dispatch_trace.cpp (new) | log-only |
| `sub_82305870` | F879-QUEUEPUMP | task_dispatch_trace.cpp (new) | log-only |
| `sub_824C6F70` | W35-MOVIE-LIFE (misattributed name) | task_dispatch_trace.cpp:1980 | log-only, never fires |
| `0x82041D58` | none | — | addr_owners: unclaimed (correct) |

---

## 8. HEAP LIFECYCLE DETAIL (2026-10-24, w899 census agent — supersedes §4 partials)

**Instrument caveats (measured):** PAGEWATCH printed only 58 rows in w899 (1:1 for
#001–#040, then #5000 at 22:39:16.491 and #10000 at 22:39:46.220, then silence) —
absence of a W row is NOT proof of no write. FB0D8 prints ~every 200 calls.

### Corrections to earlier framing (all measured, w899 line numbers exact)

1. **Gate object memset is 0x60 = 96 bytes, not 84** — `FIX-8244D150 #942 lr=821C1FEC
   r3=A0487720 r5=00000060` (L4745). F-875's "84 bytes" was the allocator ARGUMENT;
   the live memset is 96 B.
2. **A0513FC0 (gate+4 "owner") is a construction transient.** HEAPHDR-STORE sequence
   at 22:39:14.918–.919: `A0487724 ← A0513FC0 (lr=821C1BB8)` → `← 0 (lr=82304724)` →
   `← A04600E0 (lr=82304724)`. **Final owner = A04600E0**; A0513FC0 never appears
   again in 2.25 M lines. Do not cite A0513FC0 as the owner.
3. **The three child containers ARE constructed in w899** (the "C4445500 never
   constructs" framing from F-801 is outdated for this boot):
   - `B5F67C00`: vt `C4445500→8208521C` at 22:39:15.955 (lr=`8260A8CC`, W31-FDA90
     wroteVt=1); `+20` task ptr `A05A6920` by 16.448
   - `B5F678C0`: same at 15.956; `+20` by 16.448
   - `B5F67C60`: same at 16.011; `+20`→`A05A5CE0` by 16.494
   All three get FB0D8 dtor-family reads (lr=`825FB31C`) and P1-FDB30 task walks.

### The movie root timeline (B5FAC000) — the wall, precisely

```
22:39:15.935  BUDDY76-ALLOC #80 dual=B5FAC000 size=0x20000 (512 KiB slab)
22:39:15.950  PLACE-CONTAINER #1 … bytes=1875968 placed=1875968 gap=0 head=44495500
              p12=5006C9B4 p24=5004FC20 p50=164            ← FULL IMAGE FILL (1.87 MB!)
22:39:15.951  RSC-REBASE-PREPLACE ×4 (root +4/+C/+18/+38 → heap ptrs)
22:39:15.954  FDBF8-CHASE #1: DIU@=B5FAC000, VFT=44495500, chars=1793, frames=164
22:39:15.954  FDBF8-BUILD #001 (pre-construct, serialized state)
22:39:15.954  FDBF8-CHASE #2: vt ALREADY 82085364, DIU@=FFFFFFFF   ← construct ≤2 ms
22:39:16.448  W32-CONSTRUCT-CENSUS #7: vt=82085364 +24=B3ABBC20 +50=164 nValidTag=15
22:39:16.495  PLACE-DISPATCH-DONE #1 … diuMagic=44495500 → vt=82085364 entry24=B3ABBC20
   ---- after this: ZERO writes printed; FB0D8 reads only; 0 rows in last 80,237 lines
22:42:05.556  last FB0D8 row (hits=4281, span_calls=295399 — sampled reads)
```

**FDBF8-CHASE full extraction: 24 rows in a 42 ms window (15.954–15.996), never
again.** DIU@=B5FAC000 exactly once (#1, pre-construct); FFFFFFFF ×23 after. The
serialized DIU pointer is cleared BY the construct — the live identity is carried by
the heap pointer, not the DIU field. Not corruption.

### The consumer chain finally fires — at gate-open, 3 minutes later

`22:42:32.065 MSGCHAIN consumer-823045E0 #1 a0=A0487720 [8287E26C]=A09A4EE0
lr=822C0A0C chain[f0=8213154C f1=82131B54 f2=821BD810 f3=82132454]` — **the same
timestamp the gate opens** (GFx-GATE #5 is the first gate=0 row; consumer rows #1–#16
run every 4 s through 22:43:32). Note `[8287E26C]=A09A4EE0` is NON-ZERO here (it was
0 in the MSGCHAIN/MSGBISECT rows of earlier sessions — F-875 recorded 0).

`sub_823045E0` is the gate-fail path callee from the F-875 raw disasm
(`:822C0A08 bl 0x823045E0`) — it runs when the gate is CLOSED, and the consumer rows
appear while the gate is OPEN too (#1 at 22:42:32.065 is 0.4 s after GFx-GATE #5
printed gate=0). Its callees: `0x822F3BD8` (uses r3) and `0x82306A20` (zeroes a
strided array from `0x8288BC3C`).

### Summary table (w899)

| object | first | last | writes after construct |
|---|---|---|---|
| A0487720 mcGraphics | L4745 · 14.919 | L2246452 · 22:43:32 | **YES** — F878 (+68/+72=5), tick (+72 5→0) |
| A04876A0 queue | L4697 · 14.918 | L2232678 · 22:42:15 | **YES** — +92/+104 ← 821FC008/1 |
| A050A320 mgr | L6700 · 15.636 | L2237851 · 22:42:44 | none printed |
| A0513FC0 | L4696 · 14.918 | L4743 · 14.919 | transient (→A04600E0) |
| B5FAC000 movie root | L10702 · 15.935 | L2170868 · 22:42:05 | construct only; **zero for last 4.7 min** |
| B5F67C00/8C0/C60 children | 15.951–16.011 | 22:40:01–22:40:03 | **YES** — vt 8208521C + task ptrs |
| B7B41000 dest | L92 armed · 14.919-era | L2241420 · 22:43:04 | vt write inside W27 op (16.436→16.440) |
| B3ABBC20 chars array | L10905 · 15.951 | L29615 · 16.495 | 8 slot patches at construct; none after |

### Refined frontier (2026-10-24)

The movie container is fully placed (1.87 MB), rebased, vtable-stamped, children
constructed with task pointers — **and then never driven again**. The consumer chain
(`consumer-823045E0`, chain f0=8213154C→f3=82132454) only begins at gate-open
(22:42:32), reading `[8287E26C]=A09A4EE0`. The open questions are now: (a) what does
the consumer chain DO with the constructed movie (does it ever reach
`sub_824876E0`/LoadBytes or the mcGraphics slot `sub_823046A8`)?; (b) why does the
mcGraphics tick/consumer path not walk `B5FAC000`'s 1793 characters into draw calls.

---

## 9. CORRECTIONS (2026-10-24, F-879 — supersedes §1/§2 framings)

1. **§1/§2 "kernel export table" → per-function attribute table.** The region
   `0x82102A00..0x82129D38` (20,071 slots × 8 B = 0x27338; PE "EXCEPTION directory")
   stores **fn word FIRST, tag second** (my §2 pairs joined tag-of-slot-k to
   fn-of-slot-k+1). All 20,071 fn words 0x8-shaped and strictly ascending — a sorted
   function directory. **Zero `lis 0x8211` words exist image-wide**; a runtime
   read-watch produced 0 rows in a full boot (F-440). **F-359 is the authority**
   ("per-function attribute table, not a dispatch registry"). The table is never
   dispatched; "implement the missing export" plans are dead on arrival.
2. **§2's "dispatched in w899: no (hook silent)" reframed:** all three loader-family
   functions are ALREADY hooked — `824C6E88` (task_dispatch_trace.cpp:1812/1814),
   `824C6F08` (gpu_device.cpp:27978/27979), `824C6F70` (task_dispatch_trace.cpp:2039/
   2041). The guest simply never calls them. The wall is guest control flow, not host
   coverage.
3. **§4 gate object:** memset is 96 B (`FIX-8244D150 #942 r5=0x60`), not 84; gate+4
   final owner is **A04600E0** (A0513FC0 was a ≤1 ms construction transient).
4. **§4 children:** B5F67C00/8C0/C60 ARE constructed in w899 (vt→8208521C, lr=8260A8CC;
   +20 task pointers A05A6920/A05A6920/A05A5CE0) — the "C4445500 never constructs"
   framing is outdated for this boot.
5. **New hard fact:** the movie root B5FAC000 receives **zero printed writes for the
   last ~4.7 minutes** of w899 after PLACE-DISPATCH-DONE (16.495). The consumer chain
   (`consumer-823045E0`, a0=A0487720, `[8287E26C]=A09A4EE0`) starts only at gate-open
   (22:42:32) and produces no Movie. Next instruments: chain f0..f3
   (8213154C/82131B54/821BD810/82132454, rule 4 first), and whether sub_823045E0's
   strided-array zeroing at 0x8288BC3C erases state the movie needs.
