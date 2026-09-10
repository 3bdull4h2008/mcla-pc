# Clean-state next steps (do not delete old tree)

Work stays in `E:\mcla pc`. This folder is only the audit/plan overlay.

## Do now (priority order)
1. **SEH-guard o1heapFree** — same class of AV as Allocate; Free is unguarded.
2. **Stop inflate spin** — `in=0 consumed=0xFFFFFFF4` forever; zero the
   stream state once emitted-empty so the guest stops re-entering.
3. **Root CDCDCDCD** — watch writes to a known-good pool16 slab; do not
   add more use-site zeros.
4. **Presents past 6** — PresentKick stops while FRAME-END continues;
   dump render-queue depth / flip queue at present #6.
5. **DRAW_INDEXED** — SUBMIT r5 is all zeros; find who should fill VB/IB.

## Evidence files (latest)
- `boot_stdout_texsc2.log` — depth fatal 0; AV storm kills process
- `boot_stdout_seh.log` — FRAME-END #200 with SEH heap
- `boot_stdout_inflate_skip.log` — first NATIVE-PRESENT ×6
- `docs/BOOT_HANDOFF.md` — full session 72 trail

## Closed this session (do not reopen)
KDELAY join · meshtextures poison · semaphore wake-loss · inflate garbage
copy · o1heap pow2 align · depth backup texture fatal
