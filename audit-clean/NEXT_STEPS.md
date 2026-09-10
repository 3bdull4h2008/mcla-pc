# Clean-state next steps (do not delete old tree)

Work stays in `E:\mcla pc`. This folder is only the audit/plan overlay.

**Checkpoint:** commit `d6df199` — read `docs/HANDOFF_NEXT_AGENT.md` first.

## Do now (priority order)
1. **Root CDCDCDCD** — pool16 slab watch (not o1heap header; PAGEWATCH on
   `0xA0000000` saw zero guest writes). Slim alloc/free hook; do not enable
   full `kPool16CensusEnabled`.
2. **Inflate caller** — if INFLATE-EMPTY still spins, decode `sub_821BC380`
   re-entry condition.
3. **Presents** — add raw enqueue counter (log is throttled at frame≤8).
4. **DRAW_INDEXED** — SUBMIT r5 all zeros; fill VB/IB on device boundary.
5. **Heap AV** — first-fail arena dump is in-code but invariants never fire;
   add canary at `physArenaBase+0x200` or walk fragments on FRAME-END.

## Evidence files
- `docs/HANDOFF_NEXT_AGENT.md` — authoritative next-agent doc
- `boot_stdout_rootcd.log` — watch armed; INFLATE-EMPTY; no A000 write
- `boot_stdout_texsc2.log` — depth fatal 0; AV storm
- `boot_stdout_seh.log` — FRAME-END #200 with SEH heap
- `boot_stdout_inflate_skip.log` — first NATIVE-PRESENT ×6

## Closed this session (do not reopen)
KDELAY join · meshtextures poison · semaphore wake-loss · inflate garbage
copy · o1heap pow2 align · depth backup texture fatal
