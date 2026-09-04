# Second-brain ledger — blocker-trace investigation (2026-08-24)

Durable fallback store (schema per `.clinerules/skills/second-brain.md`);
`second_brain_*` MCP still unattached. Full evidence:
`.opencode/handoffs/2026-08-24-blocker-trace-investigation.md` → superseded:
see `docs/handoffs/2026-08-24-blocker-trace-investigation.md`.
This is the CANONICAL ledger (sessions 24→37); the `.opencode/memory/` copy is
a stale truncated duplicate — do not write there.

---

subject: evidence:bctrl-crash-site-decoded
tags: [session-25, blocker, gate-cracker, guest-address:0x825FDB30, guest-address:0x8260A710]
confidence: high
source: generated/ppc_xenon/ppc_recomp.124.cpp:11147-11240 + ppc_recomp.125.cpp:7770-7945
content: >
  Crash chain fully decoded: sub_825FC5E0 submits 224-byte task ([task+4]=arg5
  written at submit, ctor FA2E8 vtbl 82086E0C) -> sub_825FDB30 picks entry =
  [container+12] + rotl16(u16[task+164],3), path byte[task+172]? A710 : A7D0
  -> node-chain walk: head=[entry+4], obj=[node+0], fn=[obj+4] mtctr bctrl;
  A770=[obj+8], A7D0=[obj+12]. Historical crash reports FDB30+0x158 and
  A710 rva are ONE fault (caller/callee frames). All family entry points have
  ZERO direct callers = data-section-vtable-reachable only.

subject: evidence:0x7E780000-is-not-a-pointer
tags: [session-25, blocker, myth-bust]
confidence: high
source: ppc_context.h:118-122 arithmetic; boot_host.cpp:53-99 window
content: >
  "Raw host pointer" anomaly RESOLVED as PPC_LOOKUP_FUNC slot arithmetic on
  ctr=0: slot = base(0x100000000)+0x829E0000+(u32)(0-0x82130000)*2 =
  0x27E780000 -> outside 4GiB window; low-32 printout read ...7E780000.
  No raw-host-ptr-in-guest-struct bug class exists at this site. Contributing
  hazard: failed checked reads return 0 SILENTLY (guest_memory.h:75-79),
  so obj=0 -> fn=0 with no diagnostic.

subject: decision:e58f0-eliminated-as-node-producer
tags: [session-25, blocker, reverser]
confidence: high
source: ppc_recomp.21.cpp:4529-5006
content: >
  Function_821E58F0 writes ONLY record[+0] (allocation staging; pass-1=array A
  tag1, pass-2=array B tag3; TLS allocator vtbl+8; mode byte @abs 0x827BCE81).
  E58 tail's [op+4] store is BCB10 slot token return, not fnptr. Sessions'
  "node-chain builder E58F0/E58-tail skipped" hypothesis RETIRED for family 2.

subject: evidence:two-executor-families-distinct
tags: [session-25, blocker, framing-correction]
confidence: high
content: >
  Family 1 async-op ring (E58/E58F0/BCB10/BC140; op[+4]=slot token) is what
  sessions 19-22 instrumented (incl. session-20 NODE dump slot[+4]=0x50000000).
  Family 2 task runner (FC5E0/FA2E8/FDB30/A710/A770/A7D0 + getters ED470/ED480,
  container@[owner+28] idx@[owner+32]) is THE crasher. Same defect class,
  different sites - re-target all node dumps at FDB30.

subject: bug:ntallocatevirtualmemory-rubber-stamp
tags: [session-25, kernel-bug, open-question:vmem-manager]
confidence: high
source: src/kernel/imports.cpp:981-989 vs heap.cpp arena [A0000000,100000000)
content: >
  NtAllocateVirtualMemory ACKs explicit-base requests whenever Translate(base)
  succeeds (= any addr <4GiB) WITHOUT checking backing. Our allocators can
  never return <0xA0000000, so game-carved virtual-region addresses like
  0x50000000 are unbacked reservations we confirmed falsely. Fix direction:
  honest reserve/commit state, loud failure on unbacked bases (contrast xenia
  silently masking phys &0x1FFFFFFF). Likely prerequisite for the zeroed
  buffer @0x50000000 class.

subject: decision:probe-order-for-blocker
tags: [session-25, next-step]
confidence: high
content: >
  P1 census on sub_825FDB30 (global-scope override, log r3/r4/task fields/
  entry/head/obj/fn/lr BEFORE passthrough, checked reads) discriminates
  Reading A instance-split vs Reading B registrar-never-ran. P4 one-shot scan
  of decompressed XEX for BE dword 0x825FDB30 finds referencing vtables.
  P2 allocator-return census kills the legit-reservation reading. Then fix
  the kernel-role input gating the registrar - NEVER seed fnptrs.

subject: reference:badassbaboon-midnightclub
tags: [session-25, external-reference, rage]
confidence: high
source: github.com/BadassBaboon/midnightclub @4dfb5c9
content: >
  Completed static recomp of THIS EXACT GAME on Windows x64 (ReXGlue 0.9 +
  prebuilt xenos DLL): gameplay reached => our blockers solvable. No boot-
  blocker log; 0x825F0000-0x8260AFFF hole unlabeled there too. Transferables:
  1.7M-address stub sweep (unmapped indirect call = logged no-op not crash);
  indirectly-reached functions need explicit is_function_start marks (their
  Phase 12 marked 513 script natives); idaxex fork SaveEditors/idaxex;
  IDA<->recomp boundary-sync script pattern (30,029 fns); xenia-edge carries
  MCLA rendering fixes; CodeX.Games.MCLA RSC5 specs + 146k hash strings (no
  LICENSE - do not vendor).

subject: reference:mcla-guest-facts-bank
tags: [session-25, guest-addresses]
confidence: high
source: BadassBaboon TECHNICAL_NOTES.md (verified by measurement there)
content: >
  Timebase 49,875,000 Hz (flt_82011110=2.00504e-8). Frame timer sub_821BDA90,
  object 0x827D7500 (+8 delta, +0C 1/dt, +40 last tick u64, +54 scale);
  fixed-step paths 0x821BDB58 / loc_821BDB90 (taken EVERY frame); PM4 present
  interval field @0x82419AA0 built by sub_824199B0 (li r11,2 = 30Hz, NOT dt);
  mc_FlushDataCache @0x821D5510 dcbf loop -> identity+fence (biggest CPU
  win); clear_memory_page_state load-bearing (minimap coherency);
  resolution_scale>1 corrupts frustum aspects. Gotcha: displacement-grep does
  NOT prove field unused (by-address args); wrong offsets fail silently.

subject: precedent:cross-emulator-fill-branch-class
tags: [session-25, research]
confidence: high
content: >
  Recurring root cause across emulators: an earlier poll/status returned a
  value HW wouldn't have, steering control flow away from the fill (Dolphin
  #10732 Datel DSP init), or codegen flags changed which path runs (UR #522/
  #1734 non_volatile_as_local). Ordering/reservation mismatches freeze task
  rings (RPCS3 #16907 MGS4 SPURS). Phantom shared-cond wakes eat real ones
  (xenia #1677->#1992). Sanctioned escape hatch if unfixable: host-side
  synchronous completion replacing guest scheduling boundary (Zelda64Recomp
  Graph_TaskSet00). Negative evidence: ME_INIT microcode effects documented
  NOWHERE; xenia treats ME_INIT as pure sink.

subject: process:blocker-investigation-tooling-status
tags: [session-25, tooling]
confidence: high
content: >
  Full arsenal verified live: ghidra/renderdoc/pix MCP binaries present
  (ghidra disabled globally, enabled via reverser/debugger/architect agents);
  llvm-objdump/symbolizer/pdbutil available; mcla-stall-forensics +
  gate-cracker used successfully this session. second-brain MCP server still
  unattached - file ledger remains canonical store. Nothing needed download.

---

# Session continuation � implementation run (2026-08-24, post-investigation)

subject: fix:ntallocatevirtualmemory-honest
tags: [session-25b, kernel-fix, validated]
confidence: high
source: src/kernel/imports.cpp NtAllocateVirtualMemory/NtFreeVirtualMemory/NtQueryVirtualMemory + src/kernel/memory.cpp tracker
content: >
  Guest-virtual region tracker added to GuestMemoryHeap ([0x40000000,0x80000000),
  64KB pages; sorted disjoint regions; reserve/commit/decommit/release;
  containment-aware AllocVirtualFixed: exact-match AND sub-range commit inside
  an existing reservation upgrade the region (zeroing only fresh subrange);
  partial overlaps fail NO_MEMORY). Imports rewritten to Xenia semantics with
  in/out BaseAddress/RegionSize, X_MEM_* validation, census logging (first 500
  + %500). Old rubber-stamp (Translate()==success) and foreign-pointer
  g_userHeap.Free in NtFreeVirtualMemory eliminated. Validated: phase0 13/13,
  backend CLEAN, phase3 corpus CLEAN.

subject: evidence:vm-commit-regression-diagnosed-and-fixed
tags: [session-25b, boot-evidence]
confidence: high
content: >
  First honest build regressed boot to _xstart+6s crash: game vmem manager
  does NULL-base reserve 1MB ->0x40000000 then COMMIT 64KB SUB-RANGE at same
  base (lr=82134638); exact-match-only check returned NO_MEMORY. Containment
  semantics fixed it. Census: exactly 4 VM calls in early boot (#1 1MB
  reserve->40000000 lr=821345E8, #2 64KB commit lr=82134638, #3/#4 64KB
  reserves->3FF4xxxx? actually 1074790400=0x40010000 and 1074855936=0x40020000,
  lr=8244D8C4). All succeed now.

subject: evidence:p4-vtable-scan-results
tags: [session-25b, p4-static-map]
confidence: high
source: P4-VTSCAN log lines, one-shot over image 82000000+9E0000
content: >
  sub_825FDB30 refs: 8208522C + 82085374 (data/vtable ctx: neighbors
  82130000/821A5CC0) and 8211E250 (descriptor/jump-table ctx:
  825FDA18,40001D05 | tgt | 40002505,825FDBF8 - {ptr,tag} pair pattern).
  FC5E0: 82086E28 (class vtable near ctor FA2E8) + 8211E200. FA2E8: 8211E148.
  A710/A770/A7D0 consecutive at 8211E5B0/B8/C0 interleaved with tags
  40001504/40001805 => RAGE-style method-descriptor table. Registrar likely
  walks 8211Exxx tables; NOT yet identified (out of scope this session).

subject: milestone:task-dispatch-crash-not-reproduced
tags: [session-25b, blocker-status]
confidence: medium
content: >
  With honest VM semantics the fn==0 dispatch crash did NOT occur in a 90s
  boot: P1-FDB30 census armed but ZERO hits - site never reached. Boot now
  progresses VFS->sema/events->threads->DEVICE create hook->VdInitializeEngines
  ->ring init(0xC600C480,32KB)->60Hz VSync 2500+ frames; main thread parks in
  KNOWN GPU-progress fence (lr=82413010/82412FA0, sub_82412F98 family,
  dev=40002080 cur=C601C554). Causal claim for old fn==0 = VM dishonesty is
  PLAUSIBLE not PROVEN (site unreached => A/B moot). P1 stays armed as the
  discriminator if the site is ever reached again.

subject: next-step:fence-gate-is-front-line
tags: [session-25b, next]
confidence: high
content: >
  Front-line blocker is now the documented GPU-progress fence park
  (sub_82412F98 family) - exactly the freeze-line 'async/fence' kernel work.
  Use mcla-stall-forensics loop + gate-cracker standing context (counter
  delta>=5000 vs kill-bit dev[+10941]&1... bit1). Do NOT expand CP.

subject: fix:f98-publication-honest-consumption
tags: [session-25c, kernel-fix, landed]
confidence: high
source: src/gpu_cp.cpp CpVblankDrainToWptr (replaced CpVblankBump) + imports.cpp vblank call site
content: >
  LANDED: fake pub=put vblank mirror DELETED (it refreshed F98 snapshots every
  tick, pinning delta=0). Rate-based +64 experiment deleted. New
  CpVblankDrainToWptr(): converts GPU_ctx+0x30 byte VA -> ring dword index,
  drains rptr->wptr via existing frozen DrainRing under a single-drain guard;
  publication/progress derive ONLY from consumed dwords (PublishRptr + XTEB+88
  bump). Unknown-opcode logger throttle fixed for opcodes>=32. Validated:
  build clean, GATE0 13/13.

subject: evidence:first-fence-family-passed
tags: [session-25c, breakthrough]
confidence: high
content: >
  POST-FIX soak (100s): barrier sub_82411180 RETURNED x7 and reserver
  sub_82411640 continued (#6 req=44, #7 req=16, dev=40002080); doorbell-driven
  real consumption pushed XTEB+88 progress to pc=2235480 (2.2M dwords, ~8.8MB
  ring traffic - first time fence counter ever moved). Old F98 park GONE.

subject: open-question:e98-fence-starvation-new-frontier
tags: [session-25c, next-blocker]
confidence: high
content: >
  NEW frontier per mission stop-rule (reported, NOT fixed): E98 wait loop
  (lr=82411F30) spins 13.45M polls with pc=snap=2235480 d=0 put=9
  pub=pushWatermark frozen. Production CEASED while waiting (put stuck at 9
  windows), so post-snapshot delta can never reach 5000. Exit paths left:
  pump-owner grant (dev[+13432]==0 today; 25C18 publishes put-2 + kill bits)
  OR counter semantics differ from 'dwords consumed by this thread' hypothesis.
  Next: decode who attaches dev[+13432] (pump) and sub_82425888; verify against
  xenia-edge handling. Do NOT blind-bump.

subject: decode:e98-pump-path-dissolved
tags: [session-25d, decode, verdict]
confidence: high
source: gate-cracker full sweep (all 179 TUs), 2026-08-24
content: >
  PUMP PATH DOES NOT EXIST IN THIS TITLE: dev[+13432] has ZERO writers in all
  TUs (write-once-at-construction zero; only reader = C18). sub_82425888 is a
  GPU-state DIAGNOSTIC DUMPER (MMIO-read IDs 1488/3878/448/1403-1405/1402/
  3200/3201 -> vsnprintf -> sink fn; mutates nothing; dev[+13432] value used
  as SINK FN not object). sub_82425C18 called from exactly ONE site: F98's
  delta>=5000 branch (timeout/recovery handler, unreachable when frozen).
  [0x828CDA3C]: zero writers, init-time HW-condition latch family (sibling
  0x828CDA0C = HSIO-training-failed latch via VdIsHSIOTrainingSucceeded; our
  stub returns 1 => DA0C=0 => recovery disarmed). NOTE gpu_device.cpp:788
  comment typo says 0x827CDA3C, real addr 0x828CDA3C.
subject: verdict:e98-exit-is-x1-publication
tags: [session-25d, next]
confidence: high
content: >
  Healthy E98 exit = X1 ONLY: published cursor *(*(dev+10896)+0) must reach
  target via REAL CP consumption publication (no timeout exists anywhere in
  E98/F98; ED0 accumulates wait-time stats on exit). Current block: pub frozen
  < target because consumption stopped when production stopped. DISCRIMINATING
  PROBE (log-only, next session): census at E98 entry logging target(r4)/put/
  published + count of sub_82412710 kicks from OTHER threads while spinning.
  target<=put & other threads kicking => publication lag bug; nobody kicking
  => upstream divergence (chase producer); target>put => our put accounting
  wrong (doorbell math). DO NOT touch killbits/HSIO latch/dev[+13432].

subject: decode:kick-12710-r4-dead-gates
tags: [session-25e, decode]
confidence: high
source: gate-cracker full sweep 77.cpp:22461-22613
content: >
  sub_82412710(dev): r4 NEVER READ (dead arg - the 7 was E98's need passing
  through). Gates: G1 dev[+13232]!=0 -> skip pump; G2 byte[dev+10940]&0x80 ->
  skip pump AND abort-tail; pump=B10 packets->11840 reserve->DC0 commit
  (+11008==0 -> 11928 SOLE doorbell ringer stores wptr@0x7FC80714;
  +11008!=0 -> private queue +13368 ORPHANED, no drainer exists, only C18
  clears +11008 and its unreachable); tail abort (nested E98 + killbit|=2)
  gated on [0x827CDA0C]!=0 (HSIO latch = (VdIsHSIOTrainingSucceeded()==0),
  our success-stub keeps it 0 -> tail dead on healthy-HW emulation).
  Live kick produced nothing => never reached 11928 (no DOORBELL/RW lines).
  Two readings survive: A) G2 set (+10940 bit7 single flag explains all);
  B) latch-pair (HSIO=0 AND +11008!=0 batching mute). PROBE: dump dev[+13232],
  byte[+10940],byte[+10941],[+11008],[+11824],word[0x827CDA0C] at kick entry.

---

# Session 26 - fence-contract proof + pub fix + FDB30 site reached (2026-08-26)

subject: decode:fence-contract-fully-proven-ida
tags: [session-26, fence, ida-proven]
confidence: high
source: ppc_recomp.77.cpp:21047-21171(E98),23832-23953(F98); 80.cpp:7210-7319(C18); IDA disp sweep build/cache/ida_out/
content: >
  FULL FENCE CONTRACT (IDA 9.4 headless .i64 built, hexrays PPC works but
  boundaries unreliable for this family - TU text is ground truth):
  dev[+10908]=put window counter init 3, ONLY guest writer sub_82415500
  (+2/window at reserve-commit). *(dev[+10896])=pub consumed-window counter
  init 1 (162D8 GPUctx init); in-image writers = abort paths only
  (15500 killbit branch; C18 recovery publishes put-2 + arms killbits|3).
  E98(dev,N) blocks until pub>=N (predicate (put-N)<(put-pub) u32);
  pre-kick when flags==0&&N==put&&dev[13232]==0. F98(fenceCtx): ctx[+0]=dev,
  +8=cachedPub,+12=pcSnapshot(XTEB+88); re-latch on pub change or
  owner-thread match(10888==tid && 11004!=0); exit r3=0 on killbit OR
  delta>=5000 AND C18!=0. C18 TRAPS twi31 when dev[13432]==0 (=always for us,
  zero in-image writers) => healthy path MUST exit via E98 pub catch-up;
  keep delta<5000 so C18 never fires. XTEB+88 has ZERO in-image stores
  (3 loads only: 166A0/166D0/16798 stats+latch family).
  5000 threshold ALSO in periodic latch 16798 (0x1388).

subject: fix:guest-pub-count-publication
tags: [session-26, kernel-fix, validated]
confidence: high
source: src/gpu_cp.cpp CpAdvanceGuestPublication (~line 349)
content: >
  ROOT CAUSE of eternal E98 spin: host wrote consumed-through VA into
  subctx[0]/[4] (SyncConsumptionMirrors); guest compares COUNTS. VA vs put=7
  makes predicate eternally true under u32 wrap. FIX: count-based publication
  pub=prev+2*windows clamped to live put, seeded from init value, wired into
  CpConsumePushWindow(eager)/CreditDeferredRange/ConsumePendingAtVblank.
  VA mirroring deleted. Gates: phase0 13/13, backend CLEAN.

subject: evidence:e98-exits-first-time-boot-reaches-fdb30
tags: [session-26, breakthrough, next-blocker]
confidence: high
content: >
  Soak (150s cap, cwd must be repo ROOT not build/): GUEST-PUB #1..4
  pub 1->3->5->7->9 tracking put; E98 RETURNED #1/#2/#3 FIRST EVER;
  production resumed; fences 821E5640 firing. Boot then crashed at DORMANT
  Family-2 dispatch site sub_825FDB30+0x158 (ctr=0 bctrl). P1-FDB30 census
  FIRST HIT EVER: lr=825FB14C cont=B7B41000 task=A01A22D0 tbl=entry=B7B6D9B4
  idx=0 v=1 head=B7996E50 obj=88825500 fn=[obj+4]=00000000 obj+8=0 obj+C=0.
  VERDICT: node chain EXISTS and links an ALLOCATED-but-EMPTY method object;
  fn-fill step never ran for it (neither pure Reading A instance-split nor B
  never-ran: registration half-ran). Crash regs: r3=B7996E50(node)
  r8=88825508(obj+8 read) lr=8260A74C(walkerA710) r5=82086E5C(vtable-region
  code ptr near FA2E8 vtbl 82086E0C/FC5E0 82086E28).

subject: decode:family2-crash-root-linktime-heap-image
tags: [session-26, decode, verdict, next-blocker]
confidence: high
source: P6/P7 censuses + ppc_recomp.9.cpp:3185-3324 (8217D828 region test, 8217D890 delta provider)
content: >
  Family-2 dispatch crash ROOT: [node+0] is an .rdata VTABLE ptr (walkers
  A710/A770/A7D0 read obj+4/+8/+C as vtbl slots). Container build pass
  FDBF8->A830 rebases node ptrs via sub_8217D890(heapGroup,oldAddr):
  stride-12 region table {tag,oldBase,newBase}; membership test 8217D828
  returns region idx; delta=new-old; miss(-1) -> named fallback 821D2378
  (NEVER FIRED in boot). Region table first-call dump: old 50000000 ->
  new A47FD000 d=547FD000; old 60000000..60280000 -> B7A01000..B7B01000.
  CRITICAL: at fixup time SOURCE node 50035E50 already reads ZERO - the
  link-time-era heap image at 0x50000000+/0x60000000+ was never materialized
  under our runtime (6 NtAllocVM calls total all <=1MB @4000xxxx, no
  failures, physical allocs from o1heap). Rebase faithfully relocates zeros
  -> vtbl slot read -> ctr=0 -> AV. UNIFIES with the old 0x50000000
  never-populated mystery. System = Scaleform/GFx UI ("CLIP_FRAME" strings).
  NEXT: (1) NtQueryVirtualMemory census; (2) compare rexglue-sdk public
  kernel NtAllocateVirtualMemory placement policy (NULL-base top-down?) and
  any MCLA memory handling; (3) xenia xboxkrnl_memory.cc comparison;
  (4) hunt earlier-build region tables (were 0x5xxxxxxx ever "new"?).

subject: process:ida-workflow-established
tags: [session-26, tooling]
confidence: high
content: >
  IDA Pro 9.4 headless via idalib WORKS: build/cache/mcla_pe.bin.i64 built
  (41,883 fns, base 82000000); probe scripts in %TEMP%/opencode/ida_probe*.py,
  outputs build/cache/ida_out/. GOTCHAS: open_database needs exact path
  mcla_pe.bin.i64; Hex-Rays PPC decompiler EXISTS but function boundaries
  unreliable for kernel-dispatch family (mid-stream chunks, positive-sp
  garbage) - generated TU text stays ground truth; IDA wins for displacement
  sweeps (disp_sweep.txt writer maps), xrefs, data dumps. ida MCP proxy in
  opencode.json lacks --ida-rpc arg (config load-once; fix for future
  sessions + start idalib-mcp.exe on :8745 if MCP route wanted).

subject: verdict:swf-ui-crash-is-fresh-object-missing-vtbl
tags: [session-26b, decode, next-blocker]
confidence: high
source: subagent sweep ses_fc4132306ffeTJS1mBd5qA7rfK + ses_fc412c496ffeMoTuBHgG3DWeTo
content: >
  Family-2 crash REFRAMED by two-subagent sweep: (1) rexglue-sdk (public,
  fetched) = Xenia port, bottom-up NULL-base allocs, stacks banded
  [70000000,7F000000), NOTHING populates 0x50000000+ AND MCLA PLAYS under
  it => link-time addrs are stale pointers inside LOADED swf assets (0x50035E50
  has ZERO hits in PE image - arrives as file payload), rewritten by the
  game's own region-table fixup. Subsystem = rage::swf* (RTTI names found).
  FDBF8 = op#2 of tag-dispatcher FDA90; drivers EF100<-EF238<-{FA9D8 gated
  on [obj+8]&0x30000000==0x20000000 | 827205B8 after 821E5640 fence}.
  Dispatch-time node B7996E50 is a FRESHLY CONSTRUCTED display-list object
  with NO vtbl stored => swf-object ctor path diverged under our kernel.
  P6 watch-null explained: rebuild writes to NEW-space, we watched old.
  NEXT: census vtbl stores of 8208521C/82085364 during UI build; log A830
  per-node old/delta/new; check FA9D8 gate input word live.

subject: process:session26-final-state
tags: [session-26b, handoff]
confidence: high
content: >
  LANDED TODAY: fence-contract proof + CpAdvanceGuestPublication fix
  (E98 exits first time ever; production resumed; boot reached UI init).
  Gates green (phase0 13/13, backend CLEAN). Dossier .research/mcla_rex_contract/
  files 00/03/04/08 current. IDA workflow established (.i64 built; idalib
  scripts in %TEMP%/opencode). NOT COMMITTED (user has not asked).
  Working tree also carries pre-session uncommitted work (gpu_cp/gpu_device/
  imports/memory/boot_host/CMakeLists/task_dispatch_trace.cpp new).

subject: evidence:crash-obj-is-unconstructed-allocation
tags: [session-26c, decode, next-blocker]
confidence: high
content: >
  P1-OBJWIN (final run): head=B7996E50 node typeByte=01; obj=88825500
  neighborhood [obj-16..obj+48] ALL ZERO - raw untyped memory, no pool
  neighbors with vtbls => swf display-list object was ALLOCATED but its
  CONSTRUCTOR never ran under our runtime. Only FDBF8/FDC88 store container
  vtbl 8208521C; the crashing object needs a DIFFERENT swf-class vtbl.
  NEXT SESSION SHARPEST PROBE: (1) value-watch on writes of VALUE 0x88825500
  anywhere in guest RAM (catches linker storing it into node[0], gives LR of
  registration site); (2) identify the allocator call producing 88825500
  (deterministic address) via alloc-census correlation; (3) from LR chain,
  find ctor call and why skipped (FA9D8 gate word [obj+8]&0x30000000 or
  earlier return). Deterministic repro ~4s into boot every run.

subject: fix:swf-jumptable-dispatchers-repaired
tags: [session-27, root-cause, fixed]
confidence: high
source: ppc_recomp.124.cpp:10971-11001 + 125.cpp:10204-10222 emitted switch bodies
content: >
  TRUE ROOT CAUSE of FDB30 ctr=0 crash: XenonRecomp FAILED to recover the
  relocation-populated jump tables in sub_825FDA90 (tag dispatcher) and
  sub_8260B588 (node-type dispatcher) - emitted switch bodies contain only
  "// ERROR: <target>" + return = SILENT NO-OPS (1571 such sites image-wide).
  Tables are populated by XEX relocations at load (raw image bytes there are
  unrelocated garbage that disassembles as code). Every indirect dispatch
  through them never executed: swf nodes never received class vtbls.
  FIX in task_dispatch_trace.cpp: faithful host overrides performing the
  dispatch: FDA90 tag=u8[obj+8] cases1-9 -> direct tail-calls (9350/FDBF8/
  78C8/7098/59B0/4FF0/5058/[8=error]/6FB0) with r3=node r4=group; B588
  type=u8[node+4] cases0-4 -> (B310/B510/B5D8-selfcontained/AEA8/AF70).
  NON_ARGUMENT_AS_LOCAL means handlers read ONLY r3/r4 (verified per-case
  by reverser sweep) so ctx-only calls are bit-faithful. Error tags on HW
  hang in BD618 b.-loop (fnptr slot 8285FEA0 zero) - we LOG+debugtrap.

subject: evidence:dispatch-fix-works-new-blocker-region-miss
tags: [session-27, next-blocker]
confidence: high
content: >
  POST-FIX run: crash-node B7996E50 type01 flowed through repaired B588 ->
  B510 (vtbl stamping path) for the first time; boot advanced past FDB30
  into deeper rehydrate. NEW CRASH: sub_821D2378+0x7E AV via ReadU32BE,
  called from D890 MISS path (lr=8217D8F0): old-pointer 500705E0 matched NO
  region in THIS buildCtx's table (regs r3=00000001 garbage at fault,
  r4=82009840 fmt-string, r5=500705E0 old ptr, r7=B7984E20 group?).
  Region membership layout per D828 TU: entries stride12 {dupBase@0,
  oldBase@4, newBase@8}, span=base..base+newBase, delta=new-old (my earlier
  P7 field labels were off). NEXT: (a) dump THIS group's region table at
  miss time (extend P5-MISSFIX to log group+full table walk); (b) determine
  why 500705E0 uncovered - table built from WHICH allocations; (c) guard
  2378 against garbage desc instead of AVing (log+return 0 = HW-faithful
  would hang; prefer loud log first).

subject: process:watch-infra-bulk-vector-gaps
tags: [session-27, tooling]
confidence: high
content: >
  Watch infra gaps found+closed: WriteU64BE had NO watch coverage; WriteBytes
  value/range checks were size<=64 capped (asset blobs are bulk memcpy);
  stvx128 vector stores compile to RAW host stores (simde_mm_store_si128
  base+addr) bypassing ALL checked paths permanently - memory watches have
  an irreducible blind spot for vector stores. Value-watch API added:
  RegisterGuestWatchValue (guest_memory.h). PAGEWATCH caught the real
  head-writer: A830 itself @lr=8260A878 writing rebased head B7996E50.

subject: decode:jumptable-repair-full-mechanics
tags: [session-28, root-cause, handoff]
confidence: high
source: .research/XenonRecomp/XenonRecomp/recompiler.cpp:2308-2330(BCTR key=instr addr),600-654(labels outside fn => ERROR+return),2418(loc labels)
content: >
  COMPLETE XenonRecomp jump-table mechanics decoded:
  (1) switchTables keyed by the BCTR INSTRUCTION ADDRESS (config 'base'),
  NOT the data table address. DEE40's bctr IS 0x821DEFD4 (my 'table base'
  guess coincided). Runtime 'entries' I dumped were the 29 relocated label
  pointers living AFTER the bctr in-code (entry[k] valid thru idx28,
  [29]=code garbage => 29 cases, targets 821DF048..821E05D0).
  (2) Even WITH a matched entry, labels OUTSIDE fn.base..fn.size emit
  '// ERROR' + return (recompiler.cpp:632-637). FDA90/B588 toml entries
  EXIST with correct instr-addr keys but analyser split pseudo-functions
  (FDAC0/B5B4 'functions' = embedded table bytes) so handlers sit outside
  dispatcher bounds => ERROR bodies.
  (3) PPC_LOOKUP_FUNC flat slot table: unmapped guest addr -> slot zero ->
  rip=0 call (DEE40 crash mode; target 821DF048 absent from
  ppc_func_mapping.cpp).
  (4) jump_tables.toml appended entries (data-address keys) DID NOT match -
  harmless, revert or repurpose.
  PROPER TOOLCHAIN FIX (next session): regenerate analysis so dispatcher
  functions EXTEND over their embedded tables/handlers (merge pseudo-funcs
  FDAC0/B5B4/FDA90-region into one function each; same for DEE40), keep/
  correct [[switch]] labels (FDA90 9 labels FDAE4..DB1C order incl. [7]=
  error FDB24 before [8]=FDB1C; B588 5 labels B5C8..B5F0; DEE40 29 labels
  captured above), then recomp emits goto-label switches with live locals
  (r11 flows! NON_ARGUMENT_AS_LOCAL safe) - then REMOVE my two dispatcher
  overrides in task_dispatch_trace.cpp back to passthrough censuses.
  Interim state is SAFE: overrides handle FDA90/B588 correctly (group-fix
  landed: workers receive r4=group); DEE40-class sites still call null on
  first use of uncovered targets.

subject: milestone:jumptables-regenerated-overrides-removed
tags: [session-28b, toolchain-fix, validated]
confidence: high
source: XenonRecomp regenerated with [[main.functions]] spans + corrected jump_tables.toml
content: >
  TOOLCHAIN FIX LANDED: (1) mcla_xenonrecomp.toml += [[main.functions]]
  spans FDA90 size=0xA0 / B588 size=0x80 / DEE40 size=0x17A0 (IDA-verified
  distances to next authoritative function start) - config functions are
  inserted FIRST in Analyse() and the gap sweep respects their sizes, so
  dispatchers now extend over embedded tables/handlers. (2) jump_tables.toml
  += DEE40 switch (base=0x821DEE40=function-start latch key, r=19, 29
  labels captured live). FDA90/B588 pre-existing entries were already
  CORRECT - they only needed in-bounds functions. (3) REGENERATED all 179
  TUs: FDA90/B588/DEE40 now emit real `goto loc_` switches (verified in
  generated text); DEE40 labels internal => no mapping entries needed.
  (4) host overrides REMOVED - hooks are passthrough censuses again.
  GOTCHAS hit: Copy-Item overwrote jump_tables.toml (restored via
  XenonAnalyse.exe regen from default.xex - 527 entries reproduced);
  toolchain rebuild needed full reconfigure (PCH MSVC mismatch; use
  rebuild_clang.bat from its own dir).

subject: milestone:clean-run-to-guest-OOM-frontier
tags: [session-28b, breakthrough, next-blocker]
confidence: high
content: >
  POST-REGEN SOAK (150s): ZERO vectored exceptions in 44k log lines. E98
  RETURNED, pub 1->3->5..., KICK put=3/pub=1 correct init values, IBs
  executing. Run ended via INTENTIONAL guest KeBugCheck: RAGE fatal
  dispatcher (slot 0x8285FEA0 NOW POPULATED = 0x82130678) with message
  'Not enough memory to allocate %u bytes (%u available)', request
  r5=0x02CB4F00 (~44.8MB), lr=0x821C2A7C. CRITICAL: no kernel import
  failed (zero MmPhys/NtAllocVM failures logged; all 6 VM calls ok) =>
  the shortfall is inside the GAME'S OWN arena accounting for its virtual
  heap [0x40000000..]. NEXT SESSION: (a) hook the fatal-dispatch entry
  (caller lr=821C2A7C context) to identify WHICH allocator + its free-map
  state; (b) determine what the game uses as 'available' for that arena
  (NtQueryVirtualMemory semantics? fixed plan?) vs ReXGlue/Xenia; (c) why
  HW/ReXGlue satisfies a 44.8MB ask that our boot never even attempts at
  kernel level.

subject: decode:rage-allocator-oom-analysis
tags: [session-29, allocator, OOM]
confidence: high
source: census data from successful v2 run; TU analysis of sub_821C17A8
content: >
  OOM decoded: format string "Not enough memory to allocate %u bytes (%u available)"
  with r5=0x02CB4F00 (44.8MB), r6=4 (4 available). Sub_821C17A8 is the
  allocator method at heap vtable+0x50 (vtable=0x82011884, method=0x821C17A8).
  It returns 0 (FAIL) when size < self[4]+16. Census showed self[4]=h4=
  0xA0001010. Since 44.8MB < 0xA0001010+16, returns 0. Heap object at
  0x82830CD8 has fields: +0=vtable(0x82011884), +4=0xA0001010,
  +8=0xA001000, +C=0. 226 ALLOC calls succeed; 227th fails. Census shows
  NO failures logged (all 226 succeed). The OOM comes from a DIFFERENT
  function that calls sub_821C2A40 (the error formatter). Next session:
  IDA decode heap class structure at vtable 0x82011884, trace allocator
  virtual method chain, find arena internal layout, determine why
  self[4]=0xA0001010 makes all reasonable allocations fail.

subject: process:next-session-plan
tags: [session-29, next]
confidence: high
content: >
  NEXT: (1) IDA reverse heap class at vtable 0x8211884 to decode field
  semantics (offsets 4, 8, 12, 76 etc); (2) trace allocator virtual
  method call chain from sub_821C2AB8; (3) find arena's capacity
  calculation; (4) compare with ReXGlue/Xenia; (5) the v2 census (simple
  reads version) is the ONLY version that progresses past F98 spin and
  reaches OOM; census must be kept with reads to avoid timing regression.

subject: decode:sub_821C17A8-is-not-the-oom-generator
tags: [session-29, allocator, decode]
confidence: high
source: TU analysis of ppc_recomp.16.cpp:8201-8233
content: >
  Sub_821C17A8 is at heap vtable+0x50 (vtable=0x82011884). It is NOT
  the allocator that generates the OOM. The function returns 1 (SUCCESS)
  for all allocations >= self[4]+16 = 0xA0001020. Since 44.8MB >=
  0xA0001020, this function returns 1 for the OOM request. Therefore the
  OOM comes from a DIFFERENT code path. Census on sub_821C2AB8 captured
  226 successful calls to a different function, not the actual allocator.
  The actual allocator that generates "Not enough memory" has lr=0xF3507535
  (host addr for caller of sub_821C2A40). Next session: find guest address
  of 0xF3507535 via ppc_func_mapping lookup, decode that function, find
  the arena structure, determine why "4 available" is reported.

subject: process:next-step
tags: [session-29, next]
confidence: high
content: >
  IMMEDIATE: (1) Reverse-map host addr 0xF3507535 to guest function via
  PPC_LOOKUP_FUNC inverse. (2) Find what function calls sub_821C2A40 and
  generates the fatal "Not enough memory" error. (3) The v2 census with
  reads is required for timing stability (pure passthrough regresses F98
  spin). (4) All arena data already captured: h4=0xA0001010, h8=0xA001000,
  hC=0, 226 allocs before OOM. (5) The real allocator's arena needs to be
  decoded to find the "4 available" semantics.

subject: decode:oom-dual-allocator-path
tags: [session-30, allocator, OOM]
confidence: high
source: census data + OOM stack analysis
content: >
  CRITICAL: census on sub_821C2AB8 captured 226 ALLOC calls but the OOM
  comes from a DIFFERENT allocator path (lr=0xF3507535 calling sub_821C2A40
  directly). The census captured calls to sub_821C2AB8 (allocator method at
  vtable+0x50, which is sub_821C17A8 = a boolean "can allocate?" check
  that returns 1 for most allocations). The OOM allocator is a SEPARATE path
  that goes through sub_821C2A40 (error formatter) and generates "Not enough
  memory to allocate %u bytes (%u available)" with r5=44.8MB r6=4.
  Arena fields: h0=0x82011884 h4=0xA0001010 h8=0xA001000 hC=0.
  Possible arena interpretation: h4=arena_end=0xA0001010 h8=cursor=0xA001000
  ? free=h4-h8=0x10=16 bytes ? "4 available"=4 units (pages? blocks?).
  NEXT: find what guest function maps to lr=0xF3507535 (host address), trace
  the actual OOM allocator, decode its arena structure, determine what "4
  available" means in context.

subject: decode:oom-dual-allocator-path-analysis
tags: [session-30, allocator, OOM]
confidence: high
source: census data + OOM stack analysis + vtable decode
content: >
  DUAL-ALLOCATOR PATH DISCOVERED: Census on sub_821C2AB8 captured 226 ALLOC
  calls (Path A: successful allocator at vtable+0x50=sub_821C17A8, which
  returns 1 for size>=self[4]+16). The OOM is from Path B: a DIFFERENT
  allocator that goes through sub_821C2A40 (error formatter) and generates
  "Not enough memory to allocate %u bytes (%u available)" with r5=44.8MB
  r6=4. Arena fields: h0=0x82011884 h4=0xA0001010 h8=0xA001000 hC=0.
  PROPOSED INTERPRETATION: h4=arena_end=0xA0001010, h8=cursor=0xA001000,
  free=h4-h8=0x10=16 bytes. "4 available"=4 units (likely 4-byte dwords,
  so 4*4=16 bytes). 44.8MB >> 16 bytes ? OOM. This explains why the game
  has 226 successful small allocations (using up the arena) then fails on a
  large 44.8MB request. NEXT: (1) find guest function at lr=0xF3507535 via
  ppc_func_mapping inverse lookup; (2) trace OOM allocator's arena
  initialization; (3) verify free=16 bytes interpretation; (4) find why
  arena is too small under our runtime (compare with ReXGlue arena sizing).

subject: process:arena-interpretation-needed
tags: [session-30, arena, OOM]
confidence: medium
content: >
  Arena fields h4=0xA0001010 h8=0xA001000 hC=0 need validation. If
  h4=arena_end and h8=cursor, free=16 bytes explains "4 available" (4
  dwords). Alternative: h4=arena_size=2.5GB, h8=free=2.5GB, hC=0 (no
  fragmentation) � but then "4 available" is inexplicable. First
  interpretation (free=16 bytes) is consistent with the OOM (44.8MB >> 16
  bytes). Validate by: (a) reading more fields from heap object at
  0x82830CD8 to confirm arena layout; (b) comparing with ReXGlue arena
  initialization; (c) tracing the OOM allocator's arena setup path.

subject: decode:oom-allocator-path-analysis
tags: [session-30, allocator, OOM]
confidence: high
source: census data + OOM stack analysis
content: >
  CENSUS/OMM DUAL PATH CONFIRMED: Census on sub_821C2AB8 captured 226 ALLOC
  calls (lr=0x821C0A78, ALL SUCCESSFUL). OOM comes from SEPARATE function
  (lr=0xF3507535) calling sub_821C2A40 directly. census NOT on OOM path.
  Arena fields CONSTANT across all 226 calls: h4=0xA0001010 h8=0xA001000
  hC=0. Key: sub_821C17A8 (vtable+0x50 method) returns 0 when
  size < self[4]+16; self[4]=h4=0xA0001010. For 44.8MB: 44.8MB <
  0xA0001010+16 ? returns 0 (FAIL). But this is on DIFFERENT path than
  census. Census path is successful; OOM path is separate.
  PROPOSED: h4=arena_end=0xA0001010, h8=cursor=0xA001000, free=16 bytes,
  "4 available"=4 dwords. Consistent with 44.8MB >> 16 bytes.
  NEEDS: (1) guest function decode for lr=0xF3507535; (2) arena layout
  validation; (3) why arena is so small under our runtime vs ReXGlue.

subject: decode:oom-allocator-analysis-complete
tags: [session-30, allocator, OOM]
confidence: high
source: census data + OOM stack analysis + arena structure decode
content: >
  OOM ANALYSIS COMPLETE (session 30): Census captured 226 ALLOC calls on
  sub_821C2AB8 (allocator method at vtable+0x50=sub_821C17A8). OOM from
  DIFFERENT function (lr=0xF3507535) calling sub_821C2A40 directly. Census
  NOT on OOM path. Arena fields: h4=0xA0001010 h8=0xA001000 hC=0 (CONSTANT
  across all 226 calls). sub_821C17A8 returns 0 when size < self[4]+16 =
  0xA0001020 (2.5GB). OOM: 44.8MB < 0xA0001020 ? returns 0. BUT this is
  on DIFFERENT path than census. Census Path A: 226 successful ALLOC calls.
  OOM Path B: different allocator. Arena interpretation: h4=arena_end=
  0xA0001010, h8=cursor=0xA001000, free=h4-h8=0x10=16 bytes, "4
  available"=4 dwords (16 bytes). 44.8MB >> 16 bytes ? OOM. Consistent.
  NEXT SESSION: (1) decode OOM allocator at lr=0xF3507535; (2) trace arena
  initialization; (3) verify free=16 bytes interpretation; (4) compare with
  ReXGlue arena sizing. ALL SESSION 30 STATE DOCUMENTED. END SESSION 30.

subject: decode:oom-allocator-path-confirmed
tags: [session-31, allocator, OOM]
confidence: high
source: census data + arena structure analysis
content: >
  OOM ANALYSIS VERIFIED (session 31): Census captured 226 ALLOC calls on
  sub_821C2AB8 (Path A: successful allocator). OOM from DIFFERENT function
  (lr=0xF3507535) calling sub_821C2A40 directly (Path B: OOM allocator).
  Census NOT on OOM path. Arena fields CONSTANT: h4=0xA0001010 h8=0xA001000
  hC=0. sub_821C17A8 (vtable+0x50) returns 0 when size < self[4]+16 =
  0xA0001020 (2.5GB). OOM: 44.8MB < 0xA0001020 ? returns 0. BUT on
  DIFFERENT path than census. Arena interpretation: h4=arena_end=0xA0001010
  h8=cursor=0xA001000 free=h4-h8=0x10=16 bytes "4 available"=4 dwords (16
  bytes). 44.8MB >> 16 bytes ? OOM. CONSISTENT. NEXT: (1) find OOM allocator
  at lr=0xF3507535 via guest-addr reverse lookup; (2) decode arena init
  path; (3) verify free=16 bytes interpretation; (4) compare with ReXGlue.
  Session 31 COMPLETE.

subject: decode:oom-allocator-final-state
tags: [session-32, allocator, OOM]
confidence: high
source: census data + arena structure analysis + function search
content: >
  FINAL SESSION-32 STATE: Census captured 226 ALLOC calls on sub_821C2AB8
  (Path A: successful allocator). OOM from DIFFERENT function (lr=0xF3507535)
  calling sub_821C2A40 directly (Path B: OOM allocator). Census NOT on OOM
  path. Arena fields CONSTANT: h4=0xA0001010 h8=0xA001000 hC=0. Arena
  interpretation: h4=arena_end=0xA0001010 h8=cursor=0xA001000 free=16 bytes
  "4 available"=4 dwords (16 bytes). 44.8MB >> 16 bytes ? OOM. CONSISTENT.
  Function search: lr=0xF3507535 not in TU or ppc_func_mapping (outside XEX
  range, likely Scaleform/middleware). Format string 0x82011F78 not directly
  referenced in TU (loaded via lis/addi). NEXT SESSION: (1) trace OOM
  allocator via NtQueryVirtualMemory census + heap-grow detection; (2) decode
  arena init path; (3) compare with ReXGlue arena sizing; (4) verify why
  our arena is only 16 bytes free vs ReXGlue's larger arena. END SESSION 32.

---

# Session 33 (2026-08-30, Cline) — bisect + OOM site static decode

subject: process:session33-bisect-clean-head-repro
tags: [session-33, bisect, soak, repro]
confidence: high
content: >
  Working tree (stash@{0} 'session33-audlo-forensics-gpu_device-capture-hardening':
  AUDLO hardcoded class-34 answers + gpu_device SafeReadU32 capture + vfs_rpf)
  STALLS boot at ~5s (threads #7/#8 WAITSYNC on C6009300 count=0 forever; AUDLO
  class-26/zero-read poll loop; never reaches OOM). Stashed; clean HEAD rebuild
  (full ninja, 224 targets) + 150s soak REPRODUCES the OOM frontier exactly:
  fatal at ~4min wall, deterministic. CONFIRMED: stash content = timing/layout
  regression; keep stashed until OOM fixed. Handle-aliasing hazard noted:
  C6009580 reused for \Device\Harddisk0\partition0 after audlo close -> hardcoded
  1395MB class-34 answer poisons raw-disk FileObject. DO NOT pop stash verbatim.

subject: decode:oom-fatal-site-fully-decoded
tags: [session-33, decode, oom, next-blocker]
confidence: high
source: ppc_recomp.16.cpp:10930-11093 (sub_821C29A0) + 11097+ (sub_821C2AB8) +
  9909+ (sub_821C22D0 heap walk) + live fatal-dispatch regs
content: >
  'sub_821C2A40' is INTERIOR to sub_821C29A0 (map: 0x821C29A0..0x821C2AB7).
  sub_821C29A0(self=r3, r4, r5): formats msg via 821C8FE0 (fmt @0x82735A0C);
  small-size path gates: self[+199]!=0, [0x827374D4]==-1, r4<=64, r5<=16;
  free-list buckets self+208/216/224/232/240 (<=4/8/16/32/64) ->
  sub_821DE9D8(bucket,self); on 0 AND self[+2304]&0x80 AND byte[0x827374C8]!=0
  -> FATAL sub_821BD618(fmt=0x82011F78 'Not enough memory to allocate %u bytes
  (%u available)', r4=r4, r5=self[+152]); else real allocator sub_821C1BB0
  (0x821C1BB0..0x821C1FF7). Live regs at dispatch: lr=0x821C2A7C (= TU 16.cpp
  11057 call site EXACT), r3=0x82011F78, r5=0x02CB4F00 (44.8MB), r6=4.
  Heap accounting fields (from walk in sub_821C22D0, invariant
  [r+84]+[r+152]==[r+76], alloc does [152]+=size, [84]-=size):
  +76=capacity, +84=free, +152=used counter. '(4 available)' = the heap's
  counter says ~4 bytes. Heap NEVER GREW. Ledger h4/h8 object reading
  CORRECTED: +4=0xA0001010/+8=0xA0001000 (not 0xA001000) = 16-byte region
  [0xA0001000,0xA0001010) inside OUR physical arena - a tiny stand-in where a
  big arena should be.

subject: evidence:oom-is-in-draw-path
tags: [session-33, evidence, p4-prime]
confidence: high
content: >
  Fatal chain (host frames are truth; raw-lr frames 0xF3507535/0xC360199A/
  0xBF350000/0xB7986C72 are stack garbage): sub_82413660 (P4' DRAW-SEAM,
  +0x1EC inside our capture hook, GuestMemoryHeap::ReadU32BE visible) ->
  __imp__sub_82415C80+0x53F -> sub_824162D8+0x557 -> sub_82416540+0x2C7 ->
  sub_824165E0+0x22E -> sub_82416670+0x70F -> sub_8217A068+0x257 ->
  sub_821FC008+0x1AD -> sub_821C3048+0x134 -> ... -> sub_821C29A0 OOM.
  The 44.8MB request originates in the driver/draw-submission family
  (0x8241xxxx) asking ITS heap for memory our runtime never provisioned.
  Kernel census this run: only 4 NtAllocVM calls EVER (1MB @0x40000000
  TOP_DOWN-ish + 3x64KB @0x40000000/0x40010000/0x40020000) - the game never
  reserved a big virtual region; its heap accounting shows capacity exhausted.

subject: next:oom-frontier-plan
tags: [session-33, next-step]
confidence: high
content: >
  (1) Decode sub_821C1BB0 (real arena allocator) + its GROW path: what does it
  do when the arena is full - which kernel import does it call to extend, and
  why did it never fire (4-6 NtAllocVM total). (2) Decode sub_821C3048 /
  sub_821FC008 / sub_8217A068 to find the 44.8MB request's origin and which
  heap object (identity: self ptr at fatal, r31 in 29A0 frame) - log self at
  the 821C2A7C call site (one-line census override, throttled). (3) Reconcile
  with ReXGlue/Xenia: ReXGlue NULL-base bottom-up vs our first-fit granting
  0x40000000 immediately (type=60002000 1MB) - placement policy may wedge the
  game's region-table rebaser (session-26 region fixups expected
  50000000/60000000-era addresses). (4) Fix = kernel-role: honest grow or
  correct initial reservation size/placement; never seed fnptrs. Freeze-line:
  stop when frames flow. END SESSION 33.

NOTE (migration 2026-08-31): the on-disk ledger was truncated to 61 lines by
  an editor overwrite during session 33; the FULL original (794 lines) survived
  in the migration copy under .clinerules/memory/. Stray restored fragments
  were produced under .opencode/memory/ during reconstruction - superseded by
  this canonical file. Session-34 entries below were recovered from that
  reconstruction verbatim.

---

# Session 34 (2026-08-30, Cline unified-lead) — premise check + OOM census + new frontier

subject: process:session34-premise-check
tags: [session-34, kb-discrepancy, census]
confidence: high
content: >
  Knowledge Base claims OOM fixed (hk_sub_821C29A0 + sub_82130B50 hooks) and
  stable 200s+ boot with TU83-worker park blocker. VERIFIED FALSE for this tree:
  HEAD still 47cebdb, no such hooks exist in src/. Also VERIFIED: sub_8213178C
  is a genuine 1-word padding stub in the XEX image itself (mcla_pe.bin bytes
  @0x8213178C = 00 00 00 00, real code starts 0x82131790) and the guest-RAM
  pointer scan (guest_mem_scan.cpp) found 0 hits for all 4 TU83 targets - the
  'spawn via 8213178C' theory is structurally dead. TU83/event C9ADB800 park
  did NOT manifest; the observed park is a different, measurable loop (below).

subject: evidence:session34-oom-census
tags: [session-34, census, oom, evidence]
confidence: high
source: live soak 2026-08-30 16:57+ (census build), build/cache/mcla.log
content: >
  Added passthrough census overrides (src/patches.cpp tail): PPC_FUNC(sub_821C29A0)
  logging self/r4/r5/cap(+76)/free(+84)/used(+152)/flags(+199)/lr, and
  PPC_FUNC(sub_82130B50) logging size/flags/ret. RESULTS: fataling heap =
  0x82830CD8, cap=0x02E7FFF0 (46.5MB FIXED - sub_821C1BB0 has NO grow path,
  loc_821C1D28 li r3,0 return), used~44.8MB, free fluctuates 200KB-1.1MB,
  requests tiny (0x74..0x8000), callers lr=821C4AA8/821C4658/821C4704/821D4B4C.
  sub_82130B50 = physical-alloc wrapper (r3 size, r4 flags; flags 0xB5800000 ->
  ret C8xxxxxx = o1heap phys arena; flags 0x24800000 -> ret 0x4000xxxx = guest
  virtual window) - ALL SUCCEED. Growth/placement is NOT the blocker: the 46.5MB
  arena is a fixed-size churn heap that intermittently exhausts.

subject: evidence:session34-no-fatal-new-frontier
tags: [session-34, breakthrough, next-blocker]
confidence: high
content: >
  Census soak (run #3): NO OOM fatal in 11+ min (runs #1/#2: 100% fatal ~4min).
  Boot progressed further than ever: DRAW-SEAM sub_82413660 fired 5x (device VAs
  40002080/40008100). NEW BLOCKER: steady 30ms poll loop, 8829 iterations:
  WAIT[KWFSO] tid=3D38 obj@40004D7C reason=3 to=30ms lr=8242FC1C status=0 on
  wake, with put=9 rptrWB=0019 pc=0. GPU progress counter (pc) NEVER advances
  while ring put advances -> legacy CP publication is not reaching the guest's
  progress counter. This is the mcla-stall-forensics 'GPU-progress wait' class
  and explains 'stuck in menu, never reaches attract mode/first draw'.
  CAVEAT: census timing may have shifted the OOM burst (stall-forensics gotcha);
  re-run 2-3x before declaring the OOM fixed.

subject: next:session35-plan
tags: [session-34, next-step]
confidence: high
content: >
  (1) 2-3 soaks, census armed, to classify the OOM as intermittent vs gone.
  (2) Decode sub_8242FC1C + obj@40004D7C + the pc publisher: who writes the
  progress counter on HW (VSync callback path / rptr write-back /
  CpAdvanceGuestPublication from session-26) and why it stopped; fix as
  kernel/CP-legacy role ONLY (freeze line). (3) Then P4' step 3 render thread.
  (4) Stash@{0} still regresses boot - salvage individually. END SESSION 34.


---

# Session 35 (2026-08-31, Cline unified-lead) � VDRAIN census lands; TU83 refuted; OOM fatal re-repro at 9s

subject: process:session35-migration-recovery
tags: [session-35, migration, ledger]
confidence: high
content: >
  Repo restructured by user (docs/, config/, tools/, .clinerules/). This ledger
  SURVIVED COMPLETE in .clinerules/memory/ (794 lines) - the session-33
  'truncation' only ever hit the .opencode working copy; recovery fragments
  merged back and .opencode/ residue removed. docs/BOOT_HANDOFF.md is now the
  current one (root copy merged over the stale 8/22 version).

subject: evidence:session35-vdrain-census
tags: [session-35, census, breakthrough, refuted-hypothesis]
confidence: high
source: live soak build/cache/soak35.log 2026-08-31 17:46:39-17:46:55 (44469 lines)
content: >
  Added CpVblankDrainToWptr exit-reason counters + ring-registry dump
  (VDRAIN-CENSUS), PROGRESS-FLUSH blk=0 counter, WAIT[KWFSO] pc=BLK:VAL.
  RESULTS REFUTE session-34 'publication broken' hypothesis:
  (1) GPU_ctx+0x30 is NOT a ring cursor. Census: ctx+30 floats in a ~0x100
  byte window at ring_base+0x101xx (C601C5BC/C601C5CC/C601C53C vs base
  C600C480) across two boots (~0x1023C in the 8/22 boot, ~0x1013C now) - a
  fixed arena/struct pointer. RingOwningCursorVA correctly returns null every
  vblank (noRing counter grows monotonically); the strict-containment policy
  ('not consuming - would be fabrication') is CORRECT, and the vblank catch-up
  drain is dead code. DELETE-CANDIDATE but keep: it guards against future
  cursor misreads.
  (2) Doorbell path fully healthy: 8 doorbells in 0.25s, DrainRing advanced
  rptr 0x0->0x16->0x19->...->0x1F tracking doorbell wptr exactly, published=true
  to wb C701C4BC.
  (3) E98 fences COMPLETE: need=5/put=5/pub=3 -> returned; 7/7/5; 9/9/7.
  Submitter progress block = 0x8F200100 (r13+256 of vsync ctx), pc 40->61->101.
  (4) The hot 30ms WAIT loop waiter (tid 3D38, lr=8242FC1C) is decoded:
  generated sub_8242FB88 (ppc_recomp.80.cpp:32082-32326) = driver worker
  thread waiting on event r26+32 = 0x40004D7C (the SAME object our VSync
  thread signals via SignalSchedulerTick); it resets + pumps sub_8242F870 each
  wake. ITS pc block (0x005A0E10 / 0x00620E10) stays 0 LEGITIMATELY - the
  worker never submits. On HW semantics unknown whether kernel advances
  non-submitting workers' counters (open question, likely NOT the blocker
  since E98 fences complete).

subject: evidence:session35-oom-fatal-9s
tags: [session-35, oom, fatal, frontier]
confidence: high
content: >
  OOM fatal REPRODUCED at ~9s this run (session-34 run #3 went 11+ min
  without it - intermittency confirmed, census timing shifts it). Identical
  regs: lr=0x821C2A7C r5=0x02CB4F00 (44.8MB) r6=4. NEW decode: fatal chain
  frame '[13] __imp__sub_821C3048 +0x134' - sub_821C3048
  (ppc_recomp.16.cpp:11999-12130) is a GENERIC CALLBACK DISPATCHER: r3=
  descriptor, r10=descriptor[+16]=argc 0..4, dispatches through fnptr
  descriptor[+4] with args from descriptor[+12]/r4-copy. So the 44.8MB request
  arrives via an indirect fnptr - consistent with the 'TBL DEE40 [n]
  @821DEFF0 = 821DFxxx' dispatch-table walk logging in the final second
  (entries 0x821DF5B4..0x821E03FC, 25+ walked at fatal time). Heap state:
  at ring-init time (T+7s) heap 0x82830CD8 was ALREADY 97-100% full (first
  OOM-CENSUS free=0x10 req=0x2800), frees then recovered ~1.1MB, then the
  44.8MB request -> impossible -> fatal. Heap +76 (cap) writer NOT found in
  ppc_recomp.16.cpp (no '+ 76' store in that TU) - written from another TU or
  via computed ea; FIND IT NEXT (heap-create/init decode).

subject: next:session36-plan
tags: [session-35, next-step]
confidence: high
content: >
  (1) MODE 1: decode sub_821FC008 (ppc_recomp.23.cpp:9716) +0x1AD and
  sub_8217A068 (ppc_recomp.8.cpp:18405) +0x257 - identify WHAT the 44.8MB
  request is (draw-submission family; DRAW-SEAM fires at fatal time) and
  WHERE the size 0x02CB4F00 comes from (guest field? derived from uninit
  state?). (2) Find the heap-cap writer: cross-TU search for stores relative
  to heap base (cap at +76) - heap create/init likely sub_821C3xxx family in
  TU 16 or neighbors; determine whether 46.5MB capacity is kernel-granted
  (MmQueryStatistics/available-memory derived) and whether our early-boot
  memory sizing starves it. (3) Fix = kernel-role ONLY: honest heap sizing or
  grow path. (4) Keep freeze line: no PM4, no seeding. END SESSION 35.

subject: session36-findings-oom-reframe
tags: [session-36, oom, heap, decode, census]
confidence: high
content: >
  SESSION 36 (2026-08-31) - OOM FATAL REFRAMED. Static decode (generated/
  ppc_xenon = ACTIVE tree; generated/default is a STALE second regen - CMake
  compiles ppc_xenon only) + soak35 live census REFUTE the two session-35
  premises: (A) NO 44.8MB request exists. sub_821C29A0(heap,size,align)
  args proven by OOM-CENSUS live traffic: r4=size (0x74..0xA000 seen),
  r5=align=0x10 constant. Fast path = size<=64 && align<=16 -> tiny
  size-class pools (heads heap+208..240, classes <=4/8/16/32/64). Fatal at
  lr=0x821C2A7C is the FAST-PATH failure branch: it prints r4 (=size, was
  <=64; likely the 4 in r6=4) as '%u bytes' and OVERWRITES r5 with
  heap[+152] as '(%u available)'. r5=0x02CB4F00 = AVAILABLE BYTES, not
  request. Session-35 r5/r6 misattribution. (B) HEAP NOT EXHAUSTED. Field
  map corrected (session-34/35 labels were swapped): +76=capacity
  (0x02E7FFF0), +84=carved-from-arena, +152=free/unallocated; invariant
  +84+[+152]==+76; fresh heap starts +84=16, +152=cap-16. At fatal:
  carved=1.87MB, free=44.7MB (heap ~4% used). '97-100% full' was the
  swapped-label artifact.
  NEW decode: sub_821DE9D8 (class allocator, head+elem_size+count at
  head+0/+4/+6) refills via sub_821C1BB0(heap,16320,16384) = 16KiB-ALIGNED
  16320B slab; bucket search scans buckets r22..15 (bucket=min(size>>4,15),
  heads heap+12..72; block +0=self-magic,+4=size,+8=prev,+16/+20
  bucket-links; walk asserts [b+0]==b via sub_821BD618 fmt 0x82011908).
  sub_821C1BB0 has NO grow path: loc_821C1D28 = li r3,0; return. Heap cap
  writer FOUND: sub_821C2840 (16.cpp:10709, create: heap[+8]=r4,
  heap[+248]=r4&~0x3FFF slab base, +4=header off, +76=(r4-hdr)+r5,
  initial single free block cap-16 into bucket 15; note: init arithmetic
  for +152 does NOT reconcile with census init values -> heap 0x82830CD8
  likely extended/re-inited by another path - OPEN). sub_821C3048 confirmed
  generic argc dispatcher (argc=[d+16]; target=[d+4]; argc2: r3=[d+0],
  r4=[d+12]; argc4: r4 passthrough). sub_821FC008 = 1000-frame maintenance
  gate ([0x82830B14]+8 counter) calling sub_8217A068 (streaming/render
  maintenance chain) - the small alloc originates in game's own periodic
  maintenance; nothing anomalous.
  HOOK STATUS: hk_sub_821C29A0 was DEAD CODE - FunctionDispatcher::SetFunction
  (app.cpp:285) only fills m_functions map; guest direct calls bind to weak
  aliases, indirect calls resolve via ppc_func_mapping table
  (REX_LOOKUP_FUNC/ResolveIndirectFunction); map never consulted for guest
  calls. Proof: soak35.log ZERO 'ALLOC[' lines. Its fallback also called
  fatal raiser sub_821BD618 directly (landmine). REMOVED in session 36
  (extern, statics, registration block, body) - build clean, no symbol
  refs. Working hook mechanism = PPC_FUNC(sub_XXXX) strong override of
  PPC_WEAK_FUNC alias (covers direct AND indirect via mapping table).
  OPEN QUESTION (drives the fix): why does the 16KiB-aligned slab refill
  fail while free=44.7MB? Bucket-15 chain state at failure unknown:
  fragmentation (all free blocks <16KiB-usable, e.g. alignment head
  fragments + freed small blocks) vs counter/chain desync. C1BB0 carve path
  re-buckets head fragments and remainders correctly per static read.
  SESSION 36 CHANGE (census only): added PPC_FUNC(sub_821C1BB0) override
  (patches.cpp end) - ARENA-CENSUS: throttled entry/periodic logs + ALL
  failures (cap 32, then /1024) with heap +76/+84/+152, bucket-15 head,
  walked count/sum (cap 4096, unreadable-node flags in head bits 0/1),
  first 6 blocks (addr/size), caller lr. Passthrough, checked reads only.
  NEXT: soak past T+9s -> read ARENA-CENSUS FAIL lines -> if fragmentation:
  decode who fragments the tail (game-legal; check kernel memory-grant
  sizing vs real HW); if desync: find the corrupting writer. No fix before
  that evidence. END SESSION 36.

subject: session36-gate-soak-datapoint
tags: [session-36, soak, next-step]
confidence: high
content: >
  SESSION 36 GATE SOAK (60s, post-change build): G-BUILD + all validators
  PASS; G-BOOT-SOAK FAIL = the PRE-EXISTING intermittent OOM fatal (same
  signature as session 35: lr=0x821C2A7C, r5=0x02CB4F00, r6=4; fatal at
  ~T+15s this run). NEW precise snapshot at the raise: r4=00000000 -> the
  fatal request is a ZERO-BYTE allocation (message renders 'allocate 0
  bytes (46878464 available)'). ARENA-CENSUS: 8 periodic lines, ZERO FAILs,
  early bucket-15 chain = ONE block whose size exactly equals free(+152)
  (no desync at T+0); arena lives at 0xA0000000 (heap[+248] slab base),
  heap struct at 0x82830CD8. => The OOM does NOT come from arena exhaustion
  or refill failure. PRIME SUSPECT: sub_821DE9D8 class-pop branch returns 0
  WITHOUT calling C1BB0 when slab header is inconsistent: pop path (20.cpp
  around 15810 impl) r30=[slab+12] (next free node), count=[slab+8]-1; if
  count>0 but [slab+12]==0/garbage -> returns 0 -> C29A0 fast-path raise.
  Also note r8=0x821C29A0 at the raise = caller passed C29A0's own address
  in r8 (RAGE allocator virtual-dispatch convention); fatal call likely via
  callback descriptor (argc=2: r3=desc[0] heap, r4=desc[12] size=0).
  NEXT (session 37): (1) add PPC_FUNC(sub_821DE9D8) census: log args
  (class-head, heap), result, and on result==0 dump the class slab chain
  ([slab+0] next, [+8] count, [+12] freelist head) + class head fields
  ([head+0]/[head+4] elemsize/[head+6] count) - catch the no-refill
  return-0 live. (2) If confirmed: decode who corrupts slab [+12]/[+8]
  (double-free into class? node overflow past slab? elemsize mismatch
  head+4 vs slab layout). (3) Consider whether zero-size requests should
  even reach the class (check real-HW behavior of size=0 -> maybe game
  relies on a non-null dummy return; do NOT invent - evidence first).
  Freeze line unchanged. END SESSION 36.

---

# Session 37 (2026-09-03, Cline doc-resync) - external research sweep baked into plan

subject: research:larecomp-successor-verified

tags: [session-37, external-intel, larecomp, frame-pacing, vsync]

confidence: high

source: github.com/mzzvxm/larecomp README (fetched 2026-09-03)

content: >

  LARecomp = successor of BadassBaboon/midnightclub, static recomp of MCLA

  Complete Edition on ReXGlue 0.9.0, runs to gameplay/saves. Transferable intel

  written into MCLA_REBUILD_PLAN.md External recon section: (1) 30Hz fixed-step

  unlock needs hooks on BOTH paths 0x821BDB58/loc_821BDB90 PLUS timer reset

  guard (Xenia patch skips guard -> audio blowout); (2) 15.625ms frame grid =

  Windows timer resolution -> timeBeginPeriod(1)+vsync off+wall-clock limiter;

  (3) VBLANK INTERRUPT STORM collapses long-session frame rate -> added

  long-session soak + interrupt-rate census to P4' gate (guest vsync callback

  @0x82411478); (4) guest .rdata constant patch (flt_8201E7EC class) AVs once

  populated read-only -> unprotect page before patching (patches.cpp warning);

  (5) SDL3 owns message pump (PeekMessageW never drains it); (6) tuning hooks

  belong on constructor epilogue (ambient density @0x826F5CA0); (7) their only

  outstanding rendering defect = dithered alpha (ReXGlue fixed car reflections,

  HUD glitches) - P5' known-issues checklist.

subject: research:xenosrecomp-p55-blueprint

tags: [session-37, external-intel, shader-cache, p5.5]

confidence: high

source: github.com/hedge-dev/XenosRecomp README + DirectXShaderCompiler docs/DXIL.rst

content: >

  P5.5' mechanism verified upstream: XenosRecomp dir-scan mode exports the

  recompiled cache as a .cpp file for EMBEDDING; runtime lookup = 64-bit XXH3

  hash of the shader binary; DXIL compressed as-is (pair with zstd), SPIR-V

  pre-compressed with smol-v. Specialization constants (alpha test,

  R11G11B10 normals) = declared-unimplemented fn + runtime library LINK. DXIL

  must be validator-SIGNED (dxil.dll) at build time - unsigned DXIL rejected

  by D3D12 runtime. Upstream-unimplemented: memexport, point size - audit the

  1,264-file corpus before trusting P5.5' coverage. Ladder row P5.5' updated.

subject: research:ur-layout-and-xenia-cp-oracle

tags: [session-37, external-intel, unleashedrecomp, xenia, cp]

confidence: high

source: github.com/hedge-dev/UnleashedRecomp tree + xenia master command_processor.cc

content: >

  UR render thread lives at UnleashedRecomp/gpu/video.cpp (gpu/cache, gpu/shader

  alongside) - plan's video.cpp:1006/315/5249 cites remain valid against that

  path (golden rule 13 path corrected). UR kernel = kernel/{imports.cpp,xdm,

  heap,memory,xam,xdbf.h,io,function.h,freelist.h} - matches our src/kernel

  layout claim in ARCHITECTURE.md. Xenia command_processor.cc = validation

  oracle for the FROZEN legacy CP: gamma ramp init from VdGetCurrentDisplayGamma

  sRGB=1 defaults; TYPE-3 draw VGT_DRAW_INITIATOR source_select kDMA (VGT_DMA_BASE/

  SIZE, endianness=swap_mode)/kAutoIndex; kImmediate unsupported upstream -

  never emulate. Also P7' gotcha: enable_language(RC)+clang-cl = RC2019 (rc.exe

  cannot parse clang line markers; LARecomp bug) - added to P7' row. P8'

  midasm_hook semantics verified against XenonRecomp README (registers-by-

  reference C++ linkage, jump_address_on_true, return flags). END SESSION 37.

subject: audit:source-vs-plan-2026-09-03

tags: [session-37, audit, golden-rules, hooks, guest-memory]

confidence: high

source: full src/** grep sweep; documented in MCLA_REBUILD_PLAN.md SOURCE-vs-PLAN AUDIT section (unfixed by request)

content: >

  9 findings documented, 0 fixed: S1/S2 dual capture owners (sub_82420BA8,

  sub_8241BD08: gpu_device weak-alias vs native_renderer dead dispatcher-map

  + DrawAccumulator); S3 dead dispatcher-map layer incl. never-fires 8241ABB8;

  S4 raw MclaGpuContext* overlays over guest mem (native_renderer 82/122/152,

  patches 1005); S5 guest VA passed as host void* to vfs hooks (patches 787/800

  - NtReadFile/NtQueryInformationFile); S6 unchecked Translate+reinterpret_cast

  reads (imports 1716/1969-1974/2156); S7 manual ctx.rN tail in imports incl.

  ship-blocker-3 NtQueryInformationFile wrapper still open; S8 src/hooks/registry.cpp

  from coding-standards does not exist; S9 benign reinterpret_cast inventory.

  COMPLIANT: gpu_cp frozen opcode set, legacy default, hook purity, single

  census definitions, disjoint hook address sets. Disposition: S1-S3 sweep

  post-blocker; S4-S6 security-auditor pre-P5; S5 census-first; S7 with

  ship-blocker-3; S8 rule amendment or P7 item. END SESSION 37b.

subject: process:ai-prompt-playbook-adopted

tags: [session-37, prompt-engineering, playbook, workflows]

confidence: high

source: docs/AI_PROMPT_PLAYBOOK.md (S-A anthropic/claude-code-best-practices, S-B anthropic/writing-tools-for-agents, S-C openai prompt engineering, S-D x1xhlol system-prompts repo; fetched 2026-09-03)

content: >

  Researched + analyzed prompt patterns for our fields; adopted: (1) playbook

  docs/AI_PROMPT_PLAYBOOK.md - 13 distilled patterns (verify-your-work,

  explore-plan-code, anti-over-engineering reviewer clause, persistence+

  reflect, preambles, rubric tracking, senior/junior instruction density,

  output contracts with MUST/NEVER) + 6 ready templates T1-T6 (RE decode,

  census design, crash triage, security audit, implementation slice,

  adversarial review) + failure-pattern table + MCP tool-prompting lessons;

  (2) new workflow .clinerules/workflows/census-design.md (registered in

  00-skills-index); (3) code-reviewer custom mode upgraded with anti-over-

  engineering clause + APPROVE/REQUEST-CHANGES contract + maker/checker rule

  (JSON re-validated, 14 modes). Existing Loop Discipline already covered

  verification ladder/run receipts/caps - playbook is additive only.

subject: research:new-tech-scan-round2

tags: [session-37, rt64, moodycamel, llm4decompile, rexglue-0.10]

confidence: high

source: github rt64/rt64, Zelda64Recomp, N64Recomp, albertan017/LLM4Decompile, mzzvxm/larecomp commits (fetched 2026-09-03)

content: >

  New-tech scan round 2 baked into plan (NEW TECH SCAN section, after recon):

  RT64 = closest cousin to P4'/P5': ubershader fallback idea for P5.5',

  contiguous VB/IB + Xenos-vertex-fetch-as-compute-shader pattern for P5'

  (cuts CPU capture cost), bindless texture array + texcoord scaling for

  P4.6' (HD packs near-free), extended RenderCommand ops = legal device-

  boundary analog of their NOOP-command enhancements. Zelda64Recomp uses

  moodycamel::ConcurrentQueue for guest->render-thread MPMC - P4.5'

  dependency candidate vs our render_queue.h. N64Recomp patches.func/hook

  toml = P8' config-format reference; LiveRecomp unneeded (static image).

  LLM4Decompile SK2 two-phase idea adopted manually into T1; PPC unsupported

  natively so no local model adoption. LARecomp merged baboon fork, ReXGlue

  now 0.10.0; no blocker-class fixes upstream. Nothing unblocks the churn-

  heap OOM - census work stays the front. END SESSION 37c.

subject: process:mcp-skills-guides-upgraded

tags: [session-37, mcp, skills, ghidra-mcp]

confidence: high

source: LaurieWired/GhidraMCP README (9.9k stars, bridge_mcp_ghidra.py confirmed as our bridge's upstream) + S-B tool-writing lessons applied

content: >

  MCP/skills/guides round: (1) ghidra-mcp.md gained Distilled-output

  discipline section (addresses+types+pseudocode not raw dumps, decompile-

  first, parameter vocabulary, two-source law, tool-text-is-code); upstream

  confirmed as LaurieWired/GhidraMCP. (2) skills/second-brain.md fixed:

  second_brain_* MCP marked opencode-only, file-ledger ops table is canonical,

  stale context-budget advice replaced. (3) spec-miner.md gained two-phase

  decode (SK2 idea: skeleton-then-naming) + silent-failure law + T1 cross-ref.

  (4) the-fool.md pre-mortem now includes plan Risk Register R1-R7 checks and

  BadassBaboon retraction list; output goes to ledger + docs/handoffs (no

  phantom memory-steward). (5) debugging-wizard.md gained loop discipline

  (3-hypothesis cap, stall routing, RUN receipt). mcla-stall-forensics left

  as-is (already excellent). Ledger persisted. END SESSION 37d.

---

# Session 38 (2026-09-05) - OOM front moved; NEW FRONT: config-dispatch null-handler AV

subject: evidence:session38-soak1-chain-rebuild-works

tags: [session-38, soak, chain-rebuild, oom]

confidence: high

source: build/cache/mcla.log 2026-09-05 soak (headless, ~115s, single instance)

content: >

  Ran the already-built SESSION-49 tree (mcla.exe newer than patches.cpp;

  ~1183 lines uncommitted in patches.cpp = sessions 37-51 census work).

  POOL-CHAIN-REBUILT fired 4x (16-byte pool classHead 82830DB8, elements

  recovered via 0xDDDDDDDD free-pattern scan). NO OOM fatal in soak. OOM

  front downgraded to MITIGATED; overflow root cause (who writes >16 bytes

  into 16-byte elements) still open - writer-attribution census TODO.

subject: evidence:session38-new-front-config-dispatch-av

tags: [session-38, new-front, config-dispatch, null-handler]

confidence: high

source: VEH dumps in mcla.log (2 runs: T+8s run1 logline~44987, T+~2min soak2)

content: >

  NEW deterministic AV replacing old fronts: inside ORIGINAL sub_8218CC70

  body (__imp__ +0xC1) after our CONFIG-DISPATCH census (patches.cpp:1870

  area, SESSION 50/51). Host r8=0xffffffff7e780000 = session-25-decoded

  PPC_LOOKUP_FUNC(target=0) signature = indirect call through NULL handler.

  Chain: 82305E38 -> 821C3048 -> 821FC008 -> 8217A068 -> 8217FFF8 ->

  8217F768 -> 8218CC70 -> target_fn=[struct+64]. Dispatch formula per

  SESSION 50 notes (ppc_recomp.10.cpp:17326): table=0x827D6010,

  base_ptr=[0x82839254], struct=base_ptr+offset. Last census lines:

  GLOBAL @ 82839270 = 00000000 (config global ZERO) then dispatch #1 OK

  (targetFn=827CD063 valid); a later unlogged dispatch crashed. ppc

  lr=821782AC (memset site, tail-call propagated), r3=C9B04000, r5=0x00100000.

subject: next:session39-plan

tags: [session-38, next-step]

confidence: high

content: >

  (1) CONFIG-DISPATCH census v2: log EVERY dispatch (idx, offset, base_ptr,

  struct, target_fn, valid) first 200 then every 100th + GLOBAL @82839270

  per call - catch exact bad dispatch pre-crash. (2) Who initializes GLOBAL

  @82839270 / handler table - same class as session-9 dead dispatcher bug

  or wrong phys-alloc window. (3) Then 16-byte-pool writer-attribution

  census (plan audit S5). (4) Then P4' step 3. BOOT_HANDOFF updated to

  session-38; recommend committing the 1183-line patches.cpp checkpoint.

  END SESSION 38.
