# BOOT HANDOFF - updated 2026-09-05 (session 38)

## Current state
- **OOM front: MITIGATED, not closed.** SESSION 49 chain-rebuild in
  patches.cpp fired 4x in the 2026-09-05 soak (16-byte pool, classHead
  82830DB8, ~632 elements recovered per corrupted slab). NO OOM fatal in the
  soak. Root cause of the OVERFLOW (who writes >16 bytes into 16-byte pool
  elements) is still unidentified — chain-rebuild is a mitigation, not the
  cure. Writer-attribution census on the slab range remains TODO.

## NEW FRONTIER (session 38) — CONFIG-DISPATCH null-handler AV
- New deterministic crash, replaces the old fronts (bctrl site, OOM raise):
  **AV inside original `sub_8218CC70` body** (`__imp__sub_8218CC70 +0xC1`),
  T+8s in run 1 (log line ~44987) and T+~2min in soak 2 — reproducible.
- Signature: host r8=**0xffffffff7e780000** = the session-25-decoded
  PPC_LOOKUP_FUNC arithmetic on target=0 ⇒ an indirect dispatch through a
  NULL/garbage handler pointer.
- Call chain (host frames): sub_82305E38 → sub_821C3048 → sub_821FC008 →
  sub_8217A068 → sub_8217FFF8 → sub_8217F768 → sub_8218CC70(config dispatch
  by index) → target_fn. ppc: lr=821782AC (a memset call site — propagates
  through tail-calls per SESSION 51 note), r3=C9B04000, r5=0x00100000,
  r8=0x1000, r9=0xC — 1MB-ish bulk op feeding the dispatch.
- Last census lines before crash:
  `CONFIG-DISPATCH: GLOBAL @ 82839270 = 00000000` (config global is ZERO)
  then `CONFIG-DISPATCH #1 idx=6 ... struct=400020D4 targetFn=827CD063
  [VALID_CODE]` — dispatch #1 fine; a LATER dispatch crashed without being
  logged (census logs sparsely).
- Dispatch formula (ppc_recomp.10.cpp:17326, per SESSION 50 notes):
  table_base=0x827D6010, offset=[table+r3*4], -1=no-op, base_ptr=[0x82839254],
  struct=base_ptr+offset, target_fn=[struct+64].

## Next (session 39)
1. **CONFIG-DISPATCH census v2**: log EVERY dispatch (idx, offset, base_ptr,
   struct, target_fn, valid-bit) for the first 200 calls then every 100th +
   the GLOBAL @82839270 value per call. Catch the exact bad dispatch before
   the crash. Capture-only, checked reads, freeze-line safe.
2. Check who should have initialized GLOBAL @82839270 / the handler table —
   likely another registration never ran (same class as the dead
   FunctionDispatcher bug from session 9) or a 0xB5800000-class phys alloc
   returned wrong memory.
3. After the dispatch front closes: writer-attribution census on the 16-byte
   pool slab range (S5 of the plan audit) to close the overflow root cause.
4. Then P4′ step 3 render thread.

## Warnings
- stash@{0} 'session33-audlo-forensics-gpu_device-capture-hardening' REGRESSES
  boot (stalls ~5s) and hardcodes AUDLO answers - salvage individually, never pop.
- generated/default is a STALE second regen - only generated/ppc_xenon is
  compiled (CMakeLists). Do not decode from generated/default.
- Freeze line: no PM4, no manual GPU seeding, no opcode expansion.
- Worktree has ~1183 lines UNCOMMITTED in patches.cpp (sessions 37-51 census
  work + chain rebuild). Commit checkpoint recommended before further surgery.

## Current state (HISTORICAL - sessions 36-37 audit trail; superseded by session-38 sections above)
- Session-36 build: dead hk_sub_821C29A0 removed; ARENA-CENSUS (sub_821C1BB0
  weak-alias override) added in patches.cpp. Build clean, validators PASS.
- Gate soak 60s: G-BOOT-SOAK FAIL = pre-existing intermittent OOM fatal
  (~T+15s this run), identical signature plus NEW precise regs (below).

## Frontier (session 36) - OOM fatal REFRAMED
1. NO 44.8MB request exists (evidence: .clinerules/memory session36 entries).
   sub_821C29A0(heap,size,align): fatal r5=0x02CB4F00 is heap[+152] printed
   as "(%u available)"; r4=SIZE (0x00000000 in the gate soak!) printed as
   "%u bytes". Field map corrected: +76=cap 0x02E7FFF0, +84=carved,
   +152=free. At fatal: carved 1.87MB, free 44.7MB - heap ~4% used.
   Session-35 "97-100% full" was a swapped-label artifact.
2. ARENA (sub_821C1BB0) exonerated: NO grow path (loc_821C1D28 returns 0)
   but gate soak shows ZERO refill failures; bucket-15 chain healthy
   (walkedsum == free(+152)); arena at 0xA0000000, heap struct 0x82830CD8.
   Heap cap writer FOUND: sub_821C2840 (ppc_recomp.16.cpp:10709).
3. PRIME SUSPECT: sub_821DE9D8 (class allocator, ppc_recomp.20.cpp) can
   return 0 WITHOUT calling C1BB0 when a slab header is inconsistent
   ([slab+8] count>0 but [slab+12] freelist empty/garbage) -> C29A0
   fast-path raise. Zero-byte request via callback descriptor
   (r8=0x821C29A0 at the raise = RAGE virtual-dispatch convention).
4. Hook mechanism truth: dispatcher-map SetFunction is NEVER consulted for
   guest calls (dead hk_sub_821C29A0 removed; proof: soak35.log has zero
   "ALLOC[" lines). Working override = PPC_FUNC(sub_XXXX) weak-alias strong
   def (covers direct + indirect via ppc_func_mapping). Live censuses:
   OOM-CENSUS, PHYSALLOC-CENSUS, ARENA-CENSUS (new).

## Session 37 (2026-09-05) - DONE
- Enhanced PPC_FUNC(sub_821DE9D8) census: every return-0 now dumps the FULL
  slab chain (up to 32 slabs) with per-slab [+0]next, [+4]prev, [+8]count,
  [+12]freelist, [+16]owner, and chainLen. Added head fields (elemsize,
  capacity), summary (totalSlabs, slabsWithFree, totalFree), and
  FIRST-NONZERO diagnostic with count-vs-chainLen match check. Removed
  sampling (logs EVERY failure). Pre/post slab state comparison preserved.
- Build clean: `cmake --build build` → mcla.exe, 1 warning (pre-existing).

## Next (session 38)
1. Run gate soak → capture live POOL-CENSUS FAIL# output → analyze:
   - countMatch=NO → chain corruption (double-free? overflow? stride mismatch?)
   - countMatch=YES, totalFree>0 → pop path's search condition wrong
   - totalFree=0, slabsWithFree=0 → all slabs exhausted, refill didn't run
   - SLAB-CHANGED → concurrent modification (race condition)
2. Root-cause the slab corruption from live data.
3. Then P4' step 3 render thread.

## Warnings
- stash@{0} 'session33-audlo-forensics-gpu_device-capture-hardening' REGRESSES
  boot (stalls ~5s) and hardcodes AUDLO answers - salvage individually, never pop.
- generated/default is a STALE second regen - only generated/ppc_xenon is
  compiled (CMakeLists). Do not decode from generated/default.
- Freeze line: no PM4, no manual GPU seeding, no opcode expansion.
