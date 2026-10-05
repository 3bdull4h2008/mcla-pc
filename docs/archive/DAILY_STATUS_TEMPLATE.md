# Daily Status — Oct Ship | YYYY-MM-DD

**Baseline** `wNNN` · **HEAD** `sha` · **Delta** unchanged | advanced

## Blockers
| ID | Blocker | Owner | Cleared when |
|----|---------|-------|--------------|
|  |  |  |  |
|  |  |  |  |

## Soak
`tools/soak_census.py <new>.log build/logs/<base>.log`

| Marker | Base | Now | Δ | Gate |
|--------|------|-----|---|------|
| C0000005 |  |  |  | ≤3, root-caused |
| Fatal / FATAL-SOFT |  |  |  | 0 |
| LISTLINE |  |  |  |  |
| GETDEV / TOC76 |  |  |  |  |
| CP-DRAW / DRAW_INDEXED |  |  |  | >0 / >0 |
| PRESENT fb≠0 |  |  |  |  |
| UILOAD / GFx |  |  |  |  |

## F-numbers
- **New** F-NNN — one-sentence claim + evidence (`file:line` / `log:line`)
- **Update** F-NNN (supersedes F-MMM)
- **Void** F-NNN — reason

## Next 24h
1. Pre-declared experiment → soak vs named baseline → F-NNN
2. Close blocker: …
3. …

**Do-not:** soak lines as claims without evidence; single-soak verdicts on bimodal markers; hooks on hot recomp blocks (F-125).
