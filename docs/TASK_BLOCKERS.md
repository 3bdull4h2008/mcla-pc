# TASK_BLOCKERS — frame-path blockers (one doc, no split)

> Goal: boot → menu. Guest `default.xex` is data; raw bytes are truth
> (offset = VA − 0x82000000 in `build/cache/mcla_pe.bin`).
> Open queue lives in `docs/LONG_TODO_MASTER.md` §6 T43; this file is the
> working summary, not the queue.

## Gates (every experiment must show all four)

- `headIs=1` byte-exact on the ARC head row.
- `dstAfter=61786772` (reader cursor snapshot `a9bd027`; boot no longer fatals).
- `FATAL-SOFT=0` — printer at `src/kernel/imports.cpp:6393`; resource-park
  sibling at `src/kernel/imports.cpp:6413`. Count only lines where the marker
  follows the `] [` level tag.
- MENU-GATE: frame path first; parked items stay parked until a soak reaches
  menu (`src/rage/rage_ideal_flow.h:56-61`).

## Open items (distance-to-menu order)

1. **T43.2 pool exhaustion** — 314 MB asker is `sub_82131228`; pool dies
   over-fragmented, then `star_glow` fatals. Census the pool, do not grow it
   blindly; exhaustion must name itself via `PHYS-POOL-FULL` / `returned null`
   (`src/kernel/heap.cpp`, see floor note below).
   **ANSWERED 2026-10-13 (w759, no new code):** 6/6 `PHYS-LIVE` rows read
   `block_guest=A3A8C000 size=0x12b80000 freed=0 guest_refs=1 pool_refs=0
   ctl=2` — per the row's own table (`heap.cpp:1102-1106`) that is LIVE,
   not a leak: the game still holds the address and the control fires, so
   the sweep isn't blind. Pool occupancy is the price of running. The 6
   refusals after it are 144 KB–1.25 MB asks against 60–68 KB free
   (over-fragmented/exhausted oscillation, 11:30:21, ~21 s in).
## Frontier (2026-10-13, w766 tail-light — read this before any new work)

Main thread's final park, every HB row: `mainwait=B73D8040
mainwaitlr=82135DF8` (sub_82135DC0+0x38), age growing to 286 s — parked
since 12:49:22, 12 s into boot, never wakes. It is a wait-CHAIN stall,
proven level by level, all timestamps: B73D8040 (sema, init=15) last
release 12:49:21 by worker tid=3540 (via RELSEMA/sub_821C9108 from
821CC9E4); 3540 itself waits B73D7040 (WAIT #00300, INFINITE) whose
producer is the next level up — nobody feeds it after ~:21 either.
NOT wake-loss (releases precede the park; count drains to 0 first) and
NOT our code (identical on HEAD control w758). Mechanism (2026-10-13,
read off generated code, no soak needed): the producer
(`__imp__sub_821CC970`, ppc_recomp.17.cpp:4339) is an infinite LOOP that
exits on first EMPTY slot (`b 0x821cc98c` / exit at :4454-4460); main's
consumer (`__imp__sub_821CC800`, :4106) is SINGLE-SHOT (returns via
`b 0x823d9248` at :4214-4215). ~500 releases land by 12:49:21, then zero
forever; main's task runs at :22, after the drain. Producer exit +
late consumer = guest task-ordering race: on another timing main runs
inside the burst (old-PC w756 did) and proceeds. No honest host fix
exists (minting semaphore units or re-dispatching guest tasks would be
fabrication); falsifier: a soak where main's 800-task lands before the
drain proceeds past B73D8040. Next dig: B73D7040's producer, same method
(last RELSEMA/SIGNAL on it + releaser thread's end state). Instrument that made this visible: HB-FLICKER mainwait=* (xdm.h
+ render_thread.cpp:1524, probes in imports.cpp) — keep it; the capped
main-park rows go dark seconds into every run without it.

## T43.17 honesty campaign (2026-10-13, CLOSED by w765 stamp)

Eight verifiers checked every log family against its printer; all code
fixes are log-only, zero behavior change. Fixed: PHYS/XTL-FREE-SUM pct now
over attempted (was 100.0000 while unaccounted=1); TYPE-CENSUS decimal ms
+ objptr domain + same on unknown-type/main-park rows; main-park passes=
denominator (both probes); READAT footers de-literalized (naive counts no
longer double); REVERIFY verifies= cumulative; SEMA double-gate removed
(single shared gate: 78 rows = 60 + 2000-cadence, predicted exactly);
KEWAIT-RESOLVE + FALLBACK-SUM + TYPE5-SUM partition the wait stream
(16,383/1/0 vs ~17.4k waits — closes). Withdrawn with cause in code:
"~99.8% fallback" (opposite measured), GLOBTEX-SERVE-BODY phantom (real
printer is GLOBTEX-BODY). Adjudicated as reader-discipline (rows already
self-describing): FATAL/PRESENT substrings, HB frame=0, XSF-LASTSERVE
name, CAS pc-field. Explained, no fix: PHYS-LIVE 6-vs-254 (per-refusal
emission, fewer refusals), WITHHELD +395 (1:1 with SKIPPED, traffic
scale), TSLAB zeros (hook never called), EVENT×256 (pool init, proven in
generated code), silent-zero chain 822F96E0→822F8F20→82302FA0 (consequence
unknown, recorded). w765 stamp: COMPARABLE, no POISONED, 0 fatals,
frontier unchanged (no draws/menu — same wall, better lit).
2. **T43.16 slab floor** — `kPhysSlabGranule=0x4000` at
   `src/kernel/heap.cpp:3237`. The comment there is UNVERIFIED; gate is
   decompiling the guest allocator (`sub_82130528` family), not tuning the hex.
   **ATTEMPTED 2026-10-12 (unbuilt, unsoaked):** floor scoped to slab-scale
   (`size >= 0x4000` keeps exact old behavior; smaller keeps max(16,pow2),
   explicit large alignments survive both arms) at `heap.cpp:3253-3270` with
   throttled `SLAB-FLOOR kept/relaxed` rows. Falsifier: HEAP76 naming a
   slab-init on a sub-granule block → revert. Needs build + soak before any
   claim.
   **SOAKED 2026-10-13 (w759, 300 s, 105,965 lines):** `SLAB-FLOOR relaxed`
   printed 19 rows (first-8 + 4096-cadence ⇒ ~45k small allocs spared the
   16 KB charge), `kept` 8 (slab-scale only). Pool refusals down vs w756:
   `XTL-ALLOC-REFUSED` 8→1, `PHYS-POOL-FULL` 9→6. Folder fix carried the
   boot (VFS indexed, `cannot load archive` 0, ARC-WINDOW 999 vs 176,
   `headIs=1` 164 vs 19, `dstAfter` 3/3, `FATAL-SOFT` 0). 7×C0000005 all
   the known null-`ctr` class (parked, boot continues). Single-variable
   caveat stands (folder + floor landed together).
3. **T43.4 provenance probe** — `sub_82130528` return at `0x8218B2EC` not
   landed. Probe must print caller + args before any hook claims the address
   (one owner per guest addr: `python tools/addr_owners.py --check`).
4. **T43.5 stale instruments** — 5 heap instruments live but misread; retire
   each only after showing it firing on a known event (rule 19: a zero from an
   unproven instrument is not a result).
5. **CP park** — `src/gpu_cp.cpp` drains; `RingOwningCursorVA` context at
   `src/gpu_cp.cpp:6813`. Park rule: census the ring, never synthesise draws.
6. **ARR-RESTORE before silencer** — fix `FDBF8-ARR-RESTORE`
   (`src/gpu_device.cpp:16818`) before any P5-PHYS silencer; a silencer that
   hides the arr break is a short-circuit stack (do-not #9).

## Done, do not reopen without a soak

T43.1 verdict-order; T43.1b null-guard sweep; T43.7 marker registration;
T43.8 memcpy writer (`sub_823DA950`); T43.10 EOF−1→FFFFFFFF + LEN-GUARD
(`src/gpu_device.cpp:26065`); T43.14 clamp arm `arFull||arClamp`
(`src/gpu_device.cpp:20203-20230`); T43.15 star_glow=exhaustion.

## Build/soak hygiene

`ninja_build.bat`; `taskkill /F /IM mcla.exe` before link and after soak;
one new `build/w*.log` per run; `timeout 120`; verify mcla.exe mtime moved.
Never edit `generated/**`, `config/mcla_xenonrecomp.toml`,
`src/ppc_context.h`, `src/ppc_config.h`, `src/dispatch_guard.cpp`.
