# COMPACT_HANDOFF (2026-10-12, from docs/HANDOFF_NEXT_AGENT.md :466-1453)

> Live block is :466 `# 2026-10-06 — HANDOFF: the boot blocker is SOLVED`
> through :1453 (w756 baseline). Wrapper :1-34 is a pointer block. Interior
> §§1-19 compress to the lines below; ledger top F-793, next F-794.

## Solved

Blocker `a9bd027`: reader cursor snapshotted pre-device-read — boot no
longer fatals (149.8 s, `dstAfter=61786772`, ARC headIs=1).

## Chain after the blocker (one line each)

Guest memcpy wipe named (F-778/F-784: `sub_823DA950` +0x2df..+0x3f3 via
`lr=821BE3BC`); EOF −1 → FFFFFFFF memcpy (F-785) + LEN-GUARD
(`src/gpu_device.cpp:26065`); CityDefault EOF provenance (F-786);
fill path (F-787); ReadFileAt producer (F-788); clamp arm landed (F-789);
star_glow = pool exhaustion (F-790); sweep off alloc path (F-791);
314 MB asker = `sub_82131228`, death = over-fragmentation (F-792);
P5-LOOKUP is own mitigation stack (F-793, refutes old §5.2).

## Still true

No menu, `DRAW_INDEXED`=0, two presents ever. Census baseline w756.

## Next (in order)

T43.4 provenance probe; fix ARR-RESTORE (`src/gpu_device.cpp:16818`)
before silencer P5-PHYS; T43.16 slab floor; frame path first per
docs/INDEX_COMPACT.md menu-gate (RAGE-ASSET/XMA parked).

## Stale on arrival

Pre-§8 `gpu_device.cpp` line cites drifted (file now 27,275 lines;
`TOCWALK-SUMMARY` only in comments); heap lines "rotated a FOURTH time"
per the file itself — re-point, don't re-derive. Handoff lacked MENU-GATE /
RAGE-ASSET-REFUSE / `rage_ideal_flow.h`; imported from INDEX_COMPACT.
Postdates: `src/rage/rage_asset_pipeline.cpp:510,544,557` + new header.
