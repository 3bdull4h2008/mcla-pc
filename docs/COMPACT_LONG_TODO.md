# COMPACT_LONG_TODO (2026-10-12, from docs/LONG_TODO_MASTER.md + src read)

> Operative queue only. §2 is a superseded 09-20 snapshot (17 ids vs 100
> ledger ids; collisions T41.10/T41.11/T41.6/T41.7/T42.1) — read it for
> route/gates only. Ledger `Task:` rows decide live/closed.

## Rules (19, short)

Census-before-fix; never edit `generated/`; raw-byte rule (`mcla_pe.bin`,
VA−0x82000000); one owner per guest addr; one log per experiment;
timeout+kill mcla.exe; always-compile; retail-only; no rewrites while not
booting; trail-as-you-go; 2-session coordination; stale-exe trap (mtime);
cite-evidence; static-scan-before-soak (rules 14-16); scratch+cmp writes;
per-file merges; rule 19 (a zero is not a result until the instrument fires
on a known event).

## Operative queue (§6 T43, distance-to-menu order, one build+soak each)

DONE/ANSWERED (one line each): T43.1 verdict-order (F-781); T43.1b
null-guard sweep (F-783); T43.1c sweep cost/aim (F-791); T43.3 rebase table
is host mirror (F-793, refutes §5.2); T43.7 §9 marker registration; T43.8
memcpy writer named (F-784); T43.9 instances detached (F-779); T43.10 EOF−1
→ FFFFFFFF memcpy (F-785); T43.11 EOF provenance + LEN-GUARD (F-786);
T43.12 clamp refusal named (F-787); T43.13 ReadFileAt producer (F-788);
T43.14 deliver `arFull||arClamp` (F-789); T43.15 star_glow=exhaustion (F-790).

OPEN: **T43.2** exhaustion (pool dies over-fragmented, then star_glow);
**T43.4** provenance probe (`sub_82130528` ret @8218B2EC, not landed);
**T43.5** retire 5 stale heap instruments (live but misreading);
**T43.6** F-779 revert test (not run); **T43.16** 16 KiB floor
(`kPhysSlabGranule=0x4000`, `src/kernel/heap.cpp:3237` — comment
UNVERIFIED, gate = decompile guest allocator).

## Gates

`headIs=1` byte-exact, `dstAfter=61786772`, `FATAL-SOFT=0`, `C0000005`,
soak COMPARABLE + no POISONED. Timestamp-coverage decides zeros (§8).

## Deferred + MENU-GATE (2026-10-12)

Parked: VMX128 Route B, vupkd type-2/vcmpbfp128, CODE_OPTIMIZATION_PLAN,
Waves D–G. Gate: no XMA bitstream / native RAGE upload / exotic-prim work
until a soak reaches menu (`src/rage/rage_asset_pipeline.cpp:499-559`
honest-false + `src/rage/rage_ideal_flow.h`). Promotion trigger: a soak
proves a parked item blocks menu.

## Standing corrections (§7+§8 keep, §4 bullets drop)

xrefs "20 callers/0 raw" FALSE (80 raw, 61 listed, cap fixed F-775);
"disasm inverts mr" FALSE (real gap op-30, F-776). Anchors rot (66.7%,
median 2,239 lines) — re-point to symbols, never re-derive.
