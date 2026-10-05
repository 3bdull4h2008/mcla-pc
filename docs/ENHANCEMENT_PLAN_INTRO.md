# Enhancement plan: intro / legals playback (post-boot)

> Status: SCAFFOLD DEFERRED WITH CAUSE (F-608). Written 2026-09-28.
> Trigger to activate: the game boots to menu (`W35-BOOT-GATE` > 0 or equivalent)
> on the current binary WITHOUT any skip. Until then this plan is parked; do not
> build any of it (no gate-moving hypothesis needs it).

## Why the skip is parked, not built

LARecomp skips `0x822C2F08 -> 0x822C2F7C` (intro movie block inside
`sub_822C2EA8`) via a guest jump patch + a render-pass mask fix at
`0x821315E4` (`r4: -1 -> 0xFEFFFFFF`). Two transfer blockers in OUR tree:

1. A guest-RAM branch patch does nothing here: recompiled code is baked from
   `build/cache/mcla_pe.bin` at build time. Only callee-level hooks transfer.
2. The pre-census (existing `F364_PROBE("SIDE-A")` rows in `w631`/`w633`:
   ENTER 1 + RETURN 1) proves the movie block is reached AND returns. The stall
   is downstream (mount gates `ret=0` F-554; `sub_822C54D8` F-555). Skipping a
   completing block cannot unblock a downstream stall.

LARecomp's skip buys intro-playback SPEED on a working boot, not unblocking of
a stuck one. Revisit only if a soak shows `SIDE-A ENTER` without `RETURN`.

## The real intro job (when the game boots)

1. **Legals branch** (`0x821315E4`, null `dword_82830B14`): apply the mask fix
   (`r4 = 0xFEFFFFFF`) at whatever hook owns that call site by then, else the
   extra render pass draws with unprepared stage (`mgr[24]`) — corrupt frame
   per LARecomp `hooks.cpp:1907-1931`.
2. **Intro movie** (`sub_821F8038`, once per boot): fullscreen quads via the
   INLINE-geometry path (`BeginVertices/EndVertices`), NOT bound-stream draws.
   Needs the draw bridge extended to inline geometry (today: auto-class
   markers only).
3. **`.bik` files** (`intro720.bik` etc. present in `build/game_data`): 360 Bink
   is CPU-decoded by game code into textures — no emulator decoder needed;
   needs working texture upload + present pacing only.
4. **Dismissal**: press-A/skip input path (input stack T41.10 must exist first).
5. **Pacing**: hardcode nothing by present rate (LARecomp removed half-rate
   advancing for exactly this reason); `skip_intro`-equivalent cvar ONLY after
   1-4 play correctly.

## Acceptance (in order)

`SIDE-A ENTER+RETURN` (already true) -> legals frame correct (no corrupt
pass) -> intro movie frames advance with audio -> dismiss works -> THEN an
opt-in skip cvar may be added. A skip that precedes working playback is
forbidden: it would hide the defects this plan exists to fix.
