# Handoff — MCLA Native PC (E:\mcla pc) — 2026-08-23 (session 4)

**Base:** `23dd69a`. Tree clean after this session's commits. All ENFORCED gates
PASS; tracked G-P4-RS-THUNK-HITS + G-P4-PACKET-CAPTURE PASS; OVERALL PASS
(`build\gates\2026-08-23-gate-report.json`).

## SEAM SEMANTICS PINNED (reverser, generated-TU ground truth)

`sub_82411640` is a push-buffer **SPACE RESERVER**, not a packet writer:

```cpp
sub_82411640(GuestDevice* dev /*r3*/, u32 flags /*r4*/,
             u32* sizeSlot /*r5*/, u32 alignBytes /*r6*/) -> windowVA /*r3*/
```

- Reads ONLY `sizeSlot[0]` (= requested bytes). Writes back consumed bytes.
- Bounds-check vs `dev[+14908]`; commits pending put at `dev[+14916]`.
- `sub_82411180(dev,newEnd,seq)` = wait-for-space BARRIER (no packet bytes).
- `sub_82411618(dev)` = push-buffer attach; **A0009100 is a SECOND GuestDevice**
  of the same class (bound at create, `sub_82413588`:24931).
- Submission classes through 640: `(f=1,a=32)`→`sub_82411B10` descriptor batches
  `(1+flags)*11 dwords`, fills `{00000A31 token, sizePages, gpuAddr, C0013C00…}`;
  `(f=1,a=4)`→`sub_82412710` chain, filled later by `sub_82411DC0`;
  `(f=2,a=32)`→`sub_82412318` raw envelopes.
- **Packed pairs (92 40 93 40…) = STALE STACK.** Only `r5[0]` is meaningful at
  640 entry (reverser + research-scout independently agree).

## CAPTURE V2 LIVE (`src/gpu_device.cpp`)

Deferred-drain design — windows are EMPTY at reservation return (builders fill
afterwards; reading eagerly yields zeros — proven twice):

1. Pre-call snapshot dev/flags/slotAddr/**alignBytes** (volatile regs clobber!).
2. Passthrough → post-call read consumed=`slot[0]`, window=`ctx.r3`.
3. Queue `{window,dwords,flags,align}`; DRAIN+scan previous pendings on NEXT
   submission (they're filled by then). Tail drained at summary time.
4. Summary cadence `n<=32 || n%100==0` (640 fires ~4×/boot — init-only!).

**Captured evidence:** `C0043C00` = type-3 **WAIT_REG_MEM** (count=5, payload
`03/0A31/00000000/80000000/08`), `00000A31` batch tokens, t0×8 reg writes,
`06234000` phys addr. `midpkt` counts honestly (batch format is driver-private).

## OPEN QUESTIONS / NEXT STEPS (in order)

1. **Per-frame draw seam ≠ 640.** It fires ~4×/boot only. Candidates:
   `Function_8241E498` (VSync worker, direct writes `{5C8,20000}` +
   paired `0xC0022100` at `dev+0x30`), `sub_82429328/9428/96E8`,
   other `sub_82411840` consumers: ppc_recomp.77.cpp:21634/22114;
   79.cpp:7980/13390/13506/19741/22945/30985(sub_82420BA8!);
   80.cpp:9014/32832. Hook + gate on ≥1 hit during menu soak.
2. **4-dword indirect windows read zeros** even one submission later — likely
   flush-time patched. Decode via `sub_82411DC0(win,args)` params instead of
   ring bytes; confirm before trusting.
3. Debug overlay (D1) once render-thread data exists (P4.5′).
4. P4.5′ RenderCommand queue design AFTER draw seam proven.

## ALSO LANDED THIS SESSION

- **Shader corpus fully CLEAN**: `.ucode.bin.*` are HOST-LE dumps (Xenia
  shader.cc:34 stores host-endian) needing byte-reversal; text disasm
  companions skipped. Binary rollup 806/806, unknown/oob/returns = 0/0/0.
  G-XENOS-DECODE-CLEAN + both G-CORPUS-* validators now ENFORCED and green.
  New header-only `src/renderer/raw_ucode_corpus.h` (shared classify/decode).
  phase3 fetch-constant assertion scoped to container-proven programs (Rev 04)
  — raw ucode lacks descriptors; observations printed, never asserted.
- **Review/audit fixes applied** (code-reviewer blocker + minors, security-
  auditor SAFE-with-lows): alignBytes pre-call snapshot; packet strides fixed
  to Xenia ground truth (t0=field+2 dwords total command_processor.cc:641,
  t1=THREE dwords :666-670, t3=field+2); opcode mask 0xFF (bits15:8);
  u64 VA-overrun guard (no wrap near 0xFFFFFFFF into low RAM); counters split
  clampedWindow/midPacket/oddBytes; ps1 `-AllMatches` for dual draw counters.
- Gate runner: single-instance rule honored throughout; reports under
  `build\gates\2026-08-23-gate-report.json`.

## GOTCHAS (do not regress)

- Global-scope override binding + r-register snapshots BEFORE passthrough.
- Never trust window bytes at reservation time — DEFER capture.
- Xenia packet.h doesn't exist in tree; packet sizes come from
  command_processor.cc ExecutePacketTypeN functions.
- Repo path has spaces → temp .cmd wrappers for build commands.

---

# SESSION 4 CONTINUATION (same day): park found, sampler built

## RUNTIME TRUTH (park-sampler, `src/boot_host.cpp`)

New diagnostic thread suspends the guest worker every 500ms, logs host RIP +
stack return addresses resolved to guest VAs (`NearestFunctionName`) + raw RIP
(`rawrip=`; subtract logged `base=` for RVA) + driver state words. **This tool
works — use it first next session.**

FINDINGS:
- Main thread does NOT park in Function_824E5350 case-9 (static hypothesis
  retired). It SPINS inside guest driver code: RVA cluster `0x86E19–0x87202`
  (mcla.exe RVAs; symbolize via PDB — llvm-symbolizer DIA broken, use
  llvm-pdbutil dump -symbols or add function-size map). Attribution heuristic
  says `sub_824296E8`±next-function region = **VBlank/present state machine**;
  return addrs touch `sub_82411E98/sub_82411F30` (idle-wait family,
  w3_82412990.c `do{}while(dev[+0x2b00])` shape) and one sample hit
  `sub_82412F98` (GPU fence-wait override).
- Ring put cursor stays FROZEN through everything; submit family
  (`sub_82420BA8`/`sub_8241BD08`/`sub_82429570` census overrides) ZERO hits.
  Game reaches present path but waits forever on a completion we never deliver.
- State words sampled were MISREAD (used poller slot 0x82839254 which holds
  DEVICE ptr; +0xD0 needs GPU_ctx chain `*(u32*)0x82000864` deref first).

## FIXES LANDED THIS CONTINUATION (uncommitted→commit)

1. `XMsgStartIORequest` completes synchronously UNCONDITIONALLY (Error=SUCCESS
   + Length even when hEvent==0) — MCLA posts event-less overlappeds and polls
   (ppc_recomp.159.cpp:1100-1116). UR's bare-return stub insufficient here.
2. `XamSessionCreateHandle` / `XamSessionRefObjByHandle`: typed impls replacing
   void-garbage stubs. Guest flow REQUIRES both return 0 (158.cpp:27368-27420:
   create writes *r22 out-param; ref gates msg-251 post via bne). Identity-
   handle model: handle = guest VA of 16-byte heap object.
3. VSync interrupt type r3: 0→**1** every tick (imports.cpp ~1336). The r3==1
   branch runs swap callback + releases frame semaphore (77.cpp:19460-19526);
   type-0 only drains CP. Park persists after this flip alone → the waited-on
   completion is something else (see OPEN).
4. xbox.h: added STATUS_INVALID_PARAMETER/_HANDLE/_NO_MEMORY defines.
5. Gates: G-P4-SUBMIT-FAMILY-HITS tracked gate (census lines ≥1); ps1 fixed
   PS5.1-compatible (no `??`), -AllMatches draw counting.

## OPEN (next session, in order)

1. **Decode the spin loop exactly**: symbolize RVA cluster 0x86E19-0x87202 via
   mcla.pdb (llvm-pdbutil dump -symbols parses OK; S_GPROC32 w/ offsets needs
   different dump flag OR build a host-start↔guest-VA map from
   g_hostToGuest at runtime — log it once under debug cvar). Read the loop's
   polled guest word; make THAT word transition (researched, not seeded).
2. Fix sampler state-word reads (GPU_ctx = `*(u32*)(*(u32*)0x82000864)` chain
   vs device ptr; verify which object +21648/+10942/+0xD0 belong to).
3. If spin = waiting-for-VBlank-flag: consider driving the guest VBlank state
   machine from our timer the way Xenia does (advance put/get or signal its
   semaphore), still no invented data — read what it compares first.
4. PIX/RenderDoc MCPs ready (user confirmed) — usable for reference captures
   once frames flow.

---

# SESSION 5 RESOLUTION (same day): "mystery function" dissolved — spin fully decoded

## A. The RVA cluster 0x86E19–0x87202 is OUR code, not a mystery host fn

llvm-symbolizer --obj=build\mcla.exe resolves the whole cluster onto
`src/guest_memory.cpp`: SetMemoryBase:12, IsValidRange:19, GetHostPtrMutable,
ReadU16BE/U32BE/F32BE/ReadBytes/WriteU16BE/WriteU32BE/WriteBytes,
GetActiveGuestMemoryView:143 (layout order == sampled range; sweep saved
%TEMP%\opencode\sweep.txt). Reason: `PPC_LOAD_U32/PPC_STORE_*` expand to
`mcla::native::ReadGuestU32/...` (generated/ppc_xenon/ppc_context.h:51 — ONLY
ppc_xenon tree builds; generated/ppc is unreferenced). Every guest ld/st on the
worker passes through these accessors ⇒ RIP lives there between every guest
insn. The "+delta from sub_82429570" was NearestFunctionName fallback artifact:
accessors are linked ~78KB after that TU and legitimately have no g_hostToGuest
entry (map built only from PPCFuncMappings, boot_host.cpp:134-147).
**No non-guest function exists. Q1-Q3 closed.**

## B. The actual spin: sub_82412F98 decoded (generated/ppc_xenon/ppc_recomp.77.cpp:23832-23953)

Wait-for-GPU-progress primitive, r31=waitCtx, r29=*r31 (driver extension):
- early-exit: byte dev[+10941] bit1 set → ret r3=0
- progress counter C = *(*(r13+256)+88); delta = C - *(r31+12);
  delta<5000 → ret r3=1 immediately (busy-but-alive)
- stall ≥5000 → pump sub_82425C18(r29) (80.cpp:7210): kicks 0xC0003138 via
  sub_82425420, submits with dev[+13432] via sub_82425888; abort path does
  byte dev[+10941] |= 3 + ring write *(dev[+10896]) = dev[+10908]-2 +
  sub_82427528. Loop exits only if pump returns ≠0.
- also refreshes snapshot when *(*(dev+10896)) changes and when
  *(dev+10888)==sub_8244FEC8() && *(dev+11004)!=0.
Two direct RIP samples INSIDE its body (+0x80/+0x107) confirm it runs.
**Root cause shape: rptr frozen ⇒ no drain ⇒ TLS+88 counter frozen ⇒ stall
forever; pump never satisfies; bit1 never set.** Handoff hypothesis 2 CONFIRMED
with exact words. NOTE: there is NO override at 0x82412F98 (rg src = 0 hits);
earlier handoff line about "fence-wait override" was wrong.
Census zero-hits are CORRECT behavior: first submit blocks upstream here.
OPEN (reverser): who increments TLS+88 / returns pump≠0 on HW — presumably the
graphics-interrupt handler chain once interrupts flow correctly; verify via
callers of sub_82425C18 and ISR dispatch before touching anything.

## C. Xenia ground truth (research-scout, cited)

- r3 semantics INVERTED in our imports.cpp (~1336): Xenia vblank = r3=0
  (MarkVblank → DispatchInterruptCallback(0,2), graphics_system.cc:97-118,
  263-273); r3=1 fires ONLY from draining a PM4_INTERRUPT packet
  (command_processor.cc:900-913, case table :725). Fix: timer fires r3=0;
  emit r3=1 only when consuming an INTERRUPT packet from captured stream.
- Ring progress = CP worker writes rptr back to VdEnableRingBufferRPtrWriteBack
  address (xboxkrnl_video.cc:244-250; command_processor.cc:243-246,315-324).
  Guest polls THAT word. We must advance it as we consume captured windows.
- Ordering: interrupt handler progress gates CP progress (MarkVblank comment,
  graphics_system.cc:269-272) — process ring BEFORE releasing frame semaphore.
- WAIT_REG_MEM word has no external writer: satisfied by EVENT_WRITE/scratch/
  COHER side effects or guest CPU (command_processor.cc:955-1035, :1196-1214).
- MCLA known-broken in Xenia too (game-compat #426 freezes; #688/#610 unknown
  GPU regs) — we are not chasing a Xenia-solved path.

## D. Probe misreads explained

- ud=FFFFFFFF: userData VA 0xA0003080 lives in the 360 UNCACHED alias segment
  (A0000000→phys alias) ABOVE our 512MB view → ReadU32BE OOB sentinel.
  Earlier zeros = bounds-reject default. NEED: segment alias translation
  (A0000000/C0000000/E0000000 → phys) in GuestMemoryView or callers.
- cur=0xC62346BC frozen = put cursor VALUE is a C-segment phys pointer.
- flg=0x34020000 junk = misaligned read at +10942 (real fields: u8 +10941,
  u32s +10888/10896/10904/11004/11008/13432 — same driver-ext object as B).
- pctx/D0 mixed identity: pollerCtx=*(0x82839254) is NOT the dev chain object;
  D0 read returned a guest CODE-looking ptr (0x8276A032). Retire that probe.
- Early all-zero lines: sampler loop stops at g_bootDone (boot_host.cpp:795)
  i.e. pre-init window. Publish slot *(u32*)0x82000864 itself remains valid
  (our working reserver overrides use the same chain, gpu_device.cpp:24-25).

## E. Next actions (priority order)

1. Commit boot_host.cpp WIP + this handoff (tree otherwise clean @318d40e).
2. Segment alias translation in GuestMemoryView (unblocks ALL probes + userData).
3. Interrupt rework per C: r3=0 vblank timer; r3=1 only from real packet drain;
   advance rptr write-back word while draining captured windows (researched
   addresses only); THEN re-check whether TLS+88/pump start moving by themselves.
4. Sampler upgrade: per-PC histogram (0x10 buckets) + ctx.r3/r4/r29/r31/TLS
   dump at sample time; symbolize misses via llvm-symbolizer --obj (DIA broken,
   native PDB works).
5. Reverser pass: pump≠0 condition + TLS+88 writer identity (see B OPEN).

---

# SESSION 5 EXECUTION (same day, after the resolution above): landed + reverted + verified

## Commits (in order, all on master)

- `7ac2b9a` boot_host: sampler v2 (exact-owner binary search + device chain
  `**(u32**)0x82000864` probes + VSync userData probe) — evidence milestone.
- `8685d1f` kernel: vsync interrupt r3 1→0 per §C (MarkVblank semantics).
  VERIFIED LIVE: boots, callbacks @60fps, no fault.
- `4b744d2` boot_host: sampler v3 — per-PC 0x10-bucket RVA histogram +
  summary line, guest r3/r4/lr/r13/TLS from `g_faultCtx` (boot_host.cpp:61,
  points at BootWorker's live PPCContext), guest-frame slots [r1-8/-16/-24]
  via prologue convention (lr/r31/r30; NOTE PPC_CONFIG_NON_VOLATILE_AS_LOCAL
  means r14-r31 are compiler locals, NOT context members), retired
  ExactOwners + pollerCtx probes. PARK-HIST live result: 120 samples,
  33 buckets, top = 0x86E60–0x87200 (the accessor window, confirms §A).
- `83d9b58` guest_memory: A/C→0x8-slot alias convergence … **REVERTED**, see below.
- `2487e4d` kernel: physical arena → segment E … **REVERTED** (was the F1/F2 fix).
- `583ea6a`/`e9c9445` reverts of the two above.
- `c69fb1f` boot_host: dual-alias userData probe (0xA0003080 raw AND
  0x80003080 cached-slot, side by side in every PARK-SAMPLE line).

## Why convergence was reverted (evidence, keep for future attempts)

Security audit on 83d9b58 found the real hazard class: storage living where
convergence folds ([0xA0000000,0xE0000000)) makes chunk VAs read/write ~1.5GiB
off their bytes (F2/F3; F1's stated mechanism was wrong — g_memory is the raw-
identity Memory struct at memory.h:113, its Translate never folded). The seg-E
arena relocation fix (2487e4d) was mechanically sound but shrank physical
capacity 1.5G→512M ⇒ **guest fatal "ExternalAllocator - Out of virtual memory"
seconds into boot** (14:22:45 run). Title legitimately needs >512MB physical ⇒
identity-safe capacity inside a u32 window (segs 0-3 = 2GB + seg7 = 0.5GB)
cannot cover userHeap(≈2GB)+reserved(≈0.5GB)+physical(1.5GB).
**Conclusion: system-wide A/C alias convergence is INFEASIBLE with this
title's allocator footprint. Alias questions are handled per-probe
(c69fb1f) unless a researched per-object alias map justifies scoped routing.**

## Live verification state (post-revert, c69fb1f build)

Boot healthy → park reproduced (sub_82429570 window + sub_82411E98/F30/
82412F98/8244FEC8 family) under r3=0 delivery. phase0 13/13 PASS.
backend_validator CLEAN. ud/ud8 both read 0 during first-minute samples —
whether userData populates later is OPEN (probe now always-on).

## Open (next session, in order)

1. §B OPEN remains the front line: who advances TLS+88 / satisfies pump —
   reverser pass on callers of sub_82425C18 + ISR dispatch chain.
2. §E.3 interrupt rework (r3=1 only from real packet drain + advance rptr
   write-back word while draining captured windows).
3. Check late-run PARK-SAMPLE lines for ud/ud8 divergence once world is up.

---

# SESSION 5 RE VERDICT (same day): park exit = rptr word change; TLS+88 unwritable-by-guest

Reverser pass, all claims cited to generated TUs:

1. **sub_82425C18 is NOT a pump/doorbell**: _vsnprintf+DbgPrint ("0xC0003138"
   was format-string offset misread) + debug-state dump sub_82425888
   (fn-table dev[+13432], sentinels 0x80050110/0x0BADF00D). Returns ≠0 iff
   dev[+13432]!=0 AND [0x8287DA3C]==0; TRAPs (`twi 31,r0,22`,
   80.cpp:7294-7309) if dev[+13432]==0 on the stall path. Unreachable while
   delta<5000 busy-return holds (77.cpp:23918-23930).
2. **TLS+88 has ZERO writers module-wide** (all 13 `lwz ,256(r13)` sites
   audited). Kernel-owned block (+332 thread id, +268 cpu byte). Host may
   emulate writes later (inference-level).
3. **ISR type-0 branch**: gated `[0x7FCE6544]&1` (77.cpp:19534-19542 —
   CORRECTED address 0x7FC**E**6544, prior notes said 0x7FC86544; single
   read-only accessor module-wide). Ungated it runs sub_82419718 =
   flip-request array processor (drains dev[+16572+i*8], MMIO store
   0x7FC80000+24848=0x7FCE6110 per entry, callback dev[+16544]) — NEVER
   drains PM4 / advances rptr / touches TLS+88.
4. **Park exit predicate**: ring waiters unwind the moment `subctx[+60]`
   changes (poller sub_82411218 reads it as RB rptr for circular free-space,
   77.cpp:19051-19122; companion sub_82411188 polls `subctx[+4]`).
   `subctx = *(dev+10896)`; write-back target = phys(subctx+60)
   (VdInitializeRingBuffer/VdEnableRingBufferRPtrWriteBack,
   77.cpp:23339-23377); guest seeds same word at :23422. Matches captured
   ~phys 0x072344BC (imports.cpp:1232 CpEnableRPtrWriteBack).
5. **STRUCTURAL CONCLUSION**: no vblank-only path starts progress. External
   CP consumer MUST advance the write-back word.
   **Ph4 word: BE u32 CP_RB_RPTR read-index at phys(dev[+10896]+60)**,
   written via checked WriteU32BE as captured windows are consumed
   (src/gpu_cp.h:11-17 semantics). Secondary: subctx+4.
   HAZARD: ensure dev[+13432]!=0 before any code path can reach delta>=5000
   (else guest traps).

## Next implementation front (P4, needs phase-gate skill invocation)

Minimal drain loop: consume one captured/reserved window → advance
write-back word by consumed bytes → observe waiter unwind (park-sampler +
G-P4-SUBMIT-FAMILY-HITS census as gates). Then gate-flag emulation
([0x7FCE6544]=1) for the flip path (present), THEN interrupt-type fidelity
(r3=1 from real INTERRUPT packets only).

---

# SESSION 6 (same day): ROOT CAUSE + drain chain LIVE — next gate = TLS+88

## Disk incident (context for lost work)

E: suffered hardware read failures (disk Event 51, error 433). Recovered:
src@ c69fb1f fully backed up to D:\mcla_backup_2026-08-23; C:\mcla-pc exists
as a clone+overlay mirror. Lost: git history ≥11a8e97 local-only, older
handoffs, manifests (regenerable via node tooling). gpu_device.cpp census
edit was corrupted pre-commit and re-applied. E: repaired by user; work
resumed ON E:.

## THE ROOT CAUSE (commit 41a08e9)

**App never created FunctionDispatcher ⇒ mcla_ApplyPatches silently no-op'd
on every boot** (app.cpp: `if (m_dispatcher)` with m_dispatcher never
assigned). The ENTIRE patch layer was dead incl. CpInstallMmioRouting = the
doorbell consumer. Fix: make_unique before ApplyPatches.

## Chain now VERIFIED LIVE

1. Routing installed → doorbell stores land (`CP: doorbell wptr=…`)
2. DrainRing consumes: drains=4, rptrWB 0→0x1F, math exact
   (1+18+4×3 dwords = INDIRECT_BUFFER head + 3-dword type3s)
3. Ring units = DWORD indices, mask dev[+14900]=0x1FFF (32KB)
4. GuestDevice VA = **A0003080** (VSync userData IS the device; A-segment,
   identity-mapped) — all earlier 0x82-chain probes read the WRONG object
5. ctx+30 put cursor MOVES now; submit family fires: 13660 ×5,
   11840 cls=11/cls=4, second device **A0009100** seen in r3

## Current stall (next session's front line)

After drain #2-4 the submitter parks INSIDE sub_82412F98-family waits again
(samples labeled 0x82411928(+0x13axx) are fallback artifacts = unmapped
wait-fn bodies linked after 11928). Exit needs TLS+88 delta ≥5000 or the
dev[+10888]==threadid(dev[+11004]!=0) refresh — i.e. the KERNEL-OWNED
progress counter. Our rptr mirrors alone don't satisfy this layer.
Also involved: second device A0009100 (r3 of a 13660 call).

## Next steps (in order)

1. Reverse who advances TLS+88 on HW: likely kernel progress counter bumped
   per completed frame/command-buffer by the ISR/dispatch path — decide
   emulation point (host write to *(tlsblk+88) on drain completion?)
   WITHOUT inventing values: derive per-drain increment from consumed data.
2. Second device A0009100: census its role (13660 r3=A0009100 hit).
3. Gate-flag [0x7FCE6544]=1 for flip path once submits flow.
4. Then P4′ step 3+: real VB/IB through captured windows.

---

# SESSION 6 FINAL (18:30): progress counter mechanism CONFIRMED — volume gate identified

Commits: 41a08e9 (dispatcher+drain LIVE) → 5ba8f5a (progress bump).

## VERIFIED WORKING (rung-2 evidence, live runs)

- Progress counter chain REAL: *(r13+256)+88 with r13=main-thread TLS,
  block=0x8F200080. RW census prints `pc=<blk>:<val>`.
- DrainRing bump lands EXACTLY: after drain#1 (22 dwords) counter 0→22.
- Increment = consumed dword count (derived, not invented).

## THE REMAINING GATE (precisely)

sub_82412F98 exits its wait only at delta>=5000. Total doored traffic =
31 dwords (INDIRECT_BUFFER head 19 + 4×3 type3s). delta caps at ~25 ⇒
busy-forever. The BULK init traffic (~65KB, seen as put cursor C62345CC→
C6234684 moving WITHOUT any RW/doorbell lines) enters via the RESERVER
SEAM sub_82411640 (capture v2 already captures those windows!) and NEVER
gets doored/consumed/counted.

## NEXT SESSION — single focused task

Wire capture-v2's drained windows into consumption accounting: for each
deferred-drain window {windowVA,dwords}, advance g_rptrIndex by dwords
(wrap mod cap), PublishRptr + counter bump with that amount — IF those
windows are kernel-ring-resident (VERIFY: windowVA range vs ringBase
C6224480+0x8000; if they live in a separate push buffer, instead route a
doorbell-equivalent consume on their completion). Success criterion:
counter reaches snapshot+5000 → F98 exits → RW census resumes past #5 →
G-P4-SUBMIT-FAMILY-HITS goes ≥1 per-frame.

## Gotcha

mcla.exe held open by running game = link "permission denied" — kill PTY
before rebuild (hit 3× this session).

---

# SESSION 6 ADDENDUM (18:50): watermark accounting landed; F98 exit logic = next read

Commit 4f3ad6b: CpConsumePushWindow(endVA,dwords) — monotonic VA watermark
into subctx[+0]/[+4] + progress-counter bump per captured window. Live:
pc accumulates from BOTH paths (kernel drains + push windows): 0→58 by RW#5.
Mirrors now carry driver-space VA watermark (NOT ring index — earlier write
of dword-index into VA-space mirrors was semantically wrong, fixed).

## PARK STILL HOLDS — counter 58 << threshold 5000

Init-stage windows are small (dw=11..30). The ≥5000 delta is unreachable at
this boot stage ⇒ the counter CANNOT be "dwords consumed" alone on HW —
either it grows via another driver (vblank-tick bump? ISR progress?) or the
F98 exit has a path we haven't honored.

## NEXT SESSION — first action, one read

Decode sub_82412F98 tail EXACTLY (77.cpp:23900-23953): all exit conditions,
the snapshot-refresh branch (dev[+10888]==sub_8244FEC8() && dev[+11004]!=0),
and what r3 values mean to callers. THEN pick emulation point with full
knowledge. Do NOT guess rates/kinds of counter bumps before that read.

Secondary leads: second device A0009100 role (13660 r3=A0009100);
gate-flag [0x7FCE6544]=1 for flip path.

---

# GATE-CRACKER VERDICT (agent .opencode/agent/gate-cracker.md, run 1)

F98 exit table (77.cpp evidence in report):
- E1: dev[+10941]&2 → r3=0 kill-switch (do NOT use for boot)
- E2: (uint)(C−ctx[12])<5000 → busy r3=1
- E3: delta>=5000 && sub_82425C18(dev)!=0 → r3=0 CLEAN (+25888 deferred flush)
- E4: delta>=5000 && pump==0 → re-baseline ctx[12]=C, busy r3=1
- Refresh branch (23900-16): writes ONLY ctx[12]=C, never returns; trigger
  dev[+10888]==P_live() && dev[+11004]!=0. TRAP: mirroring +10888 every frame
  with +11004!=0 makes the gate infinitely patient.
- CORRECTION: blocker global = [0x827CDA3C] (earlier notes said 8287DA3C).
- Callers treat F98 as while(F98()) with SECONDARY producer-cursor escapes:
  11218 re-checks its wrap window vs *(*dev[10896]+60) each pass; so once
  F98 busy-returns, published wb CAN still free the waiter.
- ctx[+12] baseline written by EA0 (=C at wait start); ctx = 24B stack
  struct @r1+80.

## Next emulation decision (informed)

Primary stays #1 (consumption bumps) BUT init volume insufficient ⇒ likely
need pump path honest emulation: ensure dev[+13432] accumulates per guest
logic and blocker [0x827CDA3C]==0 when appropriate, letting guest's OWN
stall-path pump run E3. Probe first: log 13432/blocker values at park time
(extend RW census) BEFORE touching anything.

## PROBE RESULT (commit 882f895, 19:20)

dev[+13432]=00000000, blocker=00000000 at park. NO store to +13432 exists
in the module (reads only, 80.cpp:7241/7248) ⇒ kernel-owned registration.
CRITICAL REALIZATION: E3/E4 require delta>=5000 FIRST — pump never runs
while delta is small regardless of +13432. Therefore on HW the counter C
MUST grow via a second kernel-side driver beyond consumption.

PRIME SUSPECT: per-vblank liveness bump (kernel ISR increments each
MarkVblank-analog tick; 5000 @ ~1/17ms tick ≈ 85s worst-case, faster if
multi-unit). NEXT SESSION: verify against xenia source first — grep xenia
for thread-progress/liveness counters bumped in vblank/MarkVblank path
(graphics_system.cc / xboxkrnl Vd* interrupt handling). If found: mirror
its exact rate+field. If not found: run EXPERIMENT bump (+N/tick, labeled,
revertible) to falsify.

Also unresolved: second device A0009100 role.

---

# SESSION 7 CLOSE (19:45): PARK BROKEN — boot advances past first wait

Commits: 882f895 (pump probe) → 68e6883 (vblank bump EXPERIMENT).

## What broke the park

1. xenia-scout verdict: xenia NEVER synthesizes KTHREAD+0x58 (xthread.h:100
   `unk_58`); MCLA freezes in xenia too. Counter must be synthesized.
2. Implemented: CpVblankBump(64) per vsync tick from imports.cpp pump;
   g_progressBlk captured by DrainRing's counter path. Labeled falsifiable.
3. RESULT: counter crossed 5000 (6589 → 13044), **RW#0006 fired for the
   FIRST TIME EVER**, submitter completed a second full reserve→write→
   doorbell cycle, drains 4→8, rptrWB=0x1F, put cursor advanced again.

## New state

Boot settles into a NEW steady-state stall one layer later: drains=8,
no swaps yet, RING probe static at head=C0114800. Next session FIRST ACTION:
run with PARK-SAMPLE active, identify the new park owner exactly (same
method that cracked the last three layers). Then repeat the loop:
decode predicate → find legitimate kernel-role emulation → verify.

## Standing experiment ledger

- CpVblankBump(64)/tick — labeled EXPERIMENT, revert if a real writer is
  ever identified or rate proves wrong.
- All other bumps = derived from consumed dwords (grounded).

## Session totals (today)

7 commits; root cause (dead dispatcher) killed; drain chain closed-loop;
progress-counter mechanism decoded via gate-cracker agent + verified live;
park broken after ~6 layers of precise diagnosis. Remaining to P4 gate:
iterate park→decode→emulate loop until XE_SWAP flows, then wire D3D12
present to swap packets.

## SESSION 8 (20:10, context wall reached — checkpoint)

Commits: 68e6883 (vblank bump, PARK BROKE) → 0784386 (chase-put mirrors +
PDB park naming via SymFromAddr fallback in NearestFunctionName).

State: submitter now completes MULTIPLE reserve/write/doorbell cycles
(RW#0006+ fires every run), drains reach 4-8 (run-variance), then settles
into active spin inside sub_82411E94-family wait (uninstrumented sibling;
PDB-named samples prove it: F98 + accessor churn, rare ZwDelayExecution).
Chase-put mirror (dev[+10908] → subctx[0]/[4] per tick) landed but stall
shape persists with variance.

NEXT SESSION FIRST ACTIONS:
1. Add sub_82411E94 entry census (mirror of RW census: r3=dev,r4=needed,
   r5; read put=dev[+10908], subctx0=*(*dev[10896])) — pin exact predicate
   values at stall.
2. Check whether new PKT-CAP/RW lines continue AFTER the settle (throttle
   n%2000 may hide them) before assuming deadlock.
3. Suspects queue: E94 needs wb-index vs its OWN scale; or second device
   A0009100 owns a parallel ring needing same treatment.
Loop discipline: decode → emulate kernel role → verify, one layer at a
time. It is WORKING — three layers fallen today.

---

# SESSION 9 (21:00-21:50): MMIO gate fix arms flip path; stall re-identified

Commits: 0784386 → `61150c0` (this session). phase0 13/13 PASS after changes.
New project skill installed: `.opencode/skills/mcla-stall-forensics/SKILL.md`
(the decode→emulate→verify loop + predicate map + gotchas; visible after
opencode restart).

## Verified this session (rung-2 evidence)

1. **sub_82411E94 is an EMPTY padding stub** (`PPC_FUNC_PROLOGUE(); // .long
   0x0`, 77.cpp:21041-21044). Real body = sibling **sub_82411E98**
   (77.cpp:21047-21170), fully decoded: waits while `needed(r4) >
   published(*(*(dev+10896)+0))`; early-outs r4==0 / free>=used /
   `(r7&0xFF)==0 && needed==put && dev[+13232]==0 → sub_82412710`; wait loop =
   sub_82412EA0 init ctx → sub_82412F98 poll → recheck → sub_82412ED0.
   E98 census: fires ~3× at init on dev=A0003080 with tiny values
   (need=5..7), passes once mirrors land — NOT the final park.
2. **MMIO interrupt-status fix (the big one):** game's vsync ISR type-0
   branch gates flip processing on `[0x7FC80000+0x6544]&1`
   (77.cpp:19534-19542 = reg index **0x1951**). Xenia answers
   `case 0x1951: return 1; // vblank` (graphics_system.cc:191-192) and
   persists ALL register writes for read-back (:207-223). Our CpMmioRead
   returned 0 and CpMmioWrite swallowed everything ⇒ gate could never open.
   FIXED: hardcoded xenia read set (0x0F00/0x0F01/0x194C/0x1951/0x1961,
   each cited) + 16K-entry register shadow. **VERIFIED LIVE: FLIP census
   shows sub_82419718 firing every vsync tick** (~17ms cadence).
   NOTE session-5's "corrected" address 0x7FCE6544 was WRONG; it is
   0x7FC8**6544** in-window (lis 32712 base + lwz 25924 offset).
3. **Mirror maintenance generalized**: single `g_driverDevCtx` scalar →
   4-slot device registry (`CpAttachDriverCtx` idempotent, logs attach);
   PublishRptr + CpVblankBump maintain ctx[+0]/[+4] for EVERY attached
   device (second GuestDevice A0009100 now covered automatically).
4. **ISR fully decoded** (77.cpp:19438-19553): r3==1 → swap-callback bctrl
   via `*(*dev+10900)+16` (arg [+20], sentinel 0x0BADF00D traps); r3==0 →
   spinlock-clear mask at dev[+10900][0] then gated flip processor.
5. **Zero SIGNAL lines all run**: KeSetEvent/KeReleaseSemaphore NEVER fire
   module-wide during boot/soak. All worker wakeups are kernel-role or
   direct guest header writes.

## Current stall (re-identified, precise)

Main guest thread parks in **TU83 worker loop** (contains loc_82456A18;
global block **0x827D3738** built via lis -32115/addi 14136):
- fields: CS@+16, event-handle@+52 (=**C9ADB800**, PARK-SAMPLE r3),
  deadline@+128/+132, flags@+184(lazy-init via sub_82455648)/+188/+196/
  +200/+208/+212, self-ref@+256, counts@+28/+32/+40
- loop shape: RtlEnterCriticalSection(+16) → compute timeout from deadline
  (clamps 30000/10000 tiers) → RtlLeave → NtWaitForSingleObjectEx(handle,
  UserMode, alertable=1, timeout) via helper sub_82135DC0
  (ppc_recomp.0.cpp:18590-18654, retry-on-257) → recheck/clear flags → repeat
- WAITHELP census: boot threads park INFINITE (t=0xFFFFFFFF al=0) on driver
  events C622xxxx (near ring base C6224480); main thread's variant uses
  ~unit timeouts (PARK-SAMPLE r4=1)
- **No guest signaller exists** (zero SIGNAL lines) ⇒ waking these workers
  is KERNEL-ROLE emulation (HW: kernel GPU ISR/DPC signals driver events)

## Next actions (priority order)

1. Census **sub_824569C8** (ppc_recomp.83.cpp:16774) = the TU83 worker-loop
   function ENTRY (its sibling 824569C4 is another EMPTY padding stub —
   same pattern as E94/E98; always check the sibling!). Head builds r26 =
   0x82945A80 and bctrls [r26+16]. Dump block fields
   +52/+128/+132/+188/+196/+208/+212 at entry AND decode the loop tail past
   :17033 to find which field transition exits the outer loop.
2. NtCreateEvent census (handle out + caller LR): find creation site of
   C9ADB800-class handles → static identification of intended signaller.
3. Decide kernel-role emulation point: our vsync pump already dispatches the
   guest ISR; consider ALSO signaling [0x827D3738+52]-registered events per
   tick IF that matches HW ISR behavior — research first: what does the real
   360 kernel do after calling the registered VdSetGraphicsInterruptCallback?
   (xenia DispatchInterruptCallback analog; check xenia irq handling.)
4. FLIP queue producer: who fills dev[+16572+i*8] on HW? If VdSwap/kernel
   flip completion, wire XE_SWAP drain → queue entry + signal chain.
5. Run variance note: drains settle at 2..8 depending on timing; rptrWB
   observed 0x00/0x19 across runs.

## Gotchas added

- MMIO read logging now covers hardcoded regs (first-touch per reg slot);
  old warn-once-global flag hid every poll address after the first.
- Build wrapper: repo-root `ninja_build.bat` exists; `_build_mcla.bat` is
  GONE (disk incident). Temp wrapper pattern works: vcvars64 + cmake --build.

---

# SESSION 10 (22:00-22:40): main-thread park FULLY traced — async-fence on kernel-completed op

Commits: `2f47482` → (this session's censuses: WORKER/WAITB8/WAITSYNC/FENCE/
EVENT-CREATE/SEMA-CREATE). Build clean, phase0 untouched-green.

## Park chain traced end-to-end (runtime evidence)

```
main thread -> sub_821E5FD0 (async submit+wait wrapper; callers in ~17 TUs)
  -> sub_821E5640(obj=r1+80 STACK struct, blocking=1) [TU21:4085]
     obj tag[+0]=4 | state[+4]=&[0x827CDA3C] | event[+8]=C9ADB800
  -> INFINITE non-alertable wait on C9ADB800:
     sub_821C90C0 (TU17:10837) -> sub_82135DB8 (li r5,0 thunk)
     -> sub_82135DC0 -> NtWaitForSingleObjectEx  [PARK-SAMPLE lr=82135DF8]
```

- FENCE census fired EXACTLY ONCE then park — single submit, never completes.
- **C9ADB800 was NOT created by any import**: all 356 EVENT-CREATEs come from
  one bulk pool site lr=8244EE94 (handles C6xxxxxx); SEMA-CREATEs from
  lr=8244ECC8 (C5/C6xxxxxx). It is an EMBEDDED identity-handle event inside
  the driver's op struct (inline-initialized dispatcher header — no import
  involved, so no creation record exists).

## Retired wrong leads (do not re-chase)

- sub_82411E94-family spin theory: E98 passes at init (session 9).
- TU83 worker loop sub_824569C8 as park owner: census ZERO hits — it NEVER
  runs. Its decode (work-list @block+136, NtWriteFile drainer) is real but
  that thread idles normally.
- PARK-SAMPLE r4=1 is a register sample artifact, not timeout semantics;
  actual wait = INFINITE.

## Converging evidence — third kernel-owned word

[0x827CDA3C]: (a) pump sub_82425C18 returns 0 iff dev[+13432]!=0 AND
[this]==0 (80.cpp:7254-7261); (b) it is the async-op STATE pointer
([obj+4]) of the parked fence; (c) ZERO module writers (only read at
80.cpp:7256). Family: TLS+88 (no writer; emulated EXPERIMENT), dev[+13432]
(no writer; still 0), [0x827CDA3C] (no writer). All three are KERNEL-ROLE
GPU-service state.

## In-image completers exist but never ran

Only in-image KeSetEvent sites: TU82 **sub_8244E388 / sub_8244E468 /
sub_8244E538** (×3 — kernel-service cluster adjacent to the event/semaphore
bulk-create pools at 8244EE94/ECC8) and TU74 sub_823EBB50 / 823EC410 /
823EC8C8 / 823ECA40. None executes during boot→stall ⇒ their dispatchers
(kernel interrupt/DPC tables) are not modeled by us.

## Next session (in order)

1. Decode **sub_8244E538** (three KeSetEvents): which events, what gates.
   Then find who registers/dispatches it (callers or registration-store of
   its address; remember lis/addi sign-correction: lo>=0x8000 => hi+1).
2. Decode sub_821E5F48 (async SUBMIT): what op tag=4 enqueues and into which
   queue → names the completer subsystem precisely.
3. THEN choose emulation point: likely "when CP drain/vsync completes work,
   kernel-role must signal fence events of ops whose state points into the
   kernel-service block" — derive mapping op-tag→completer from #2, do NOT
   invent rates.
4. If completer = flip/swap path: wiring XE_SWAP→completion may unstick both
   this fence AND the FLIP queue producer question from session 9.

## Census inventory now in tree (gpu_device.cpp unless noted)

RW/RW4/DOORBELL/SUBMIT/E98/FLIP(sub_82419718)/WAITHELP(DC0)/WAITB8(DB8)/
WAITSYNC(821C90C0)/WORKER(824569C8, dead)/FENCE(821E5640) +
EVENT-CREATE/SEMA-CREATE + SIGNAL KeSetEvent/KeReleaseSemaphore +
THREAD-CREATE (imports.cpp). Throttles tuned: finite-timeout WAITHelp up to
400 logged.

---

# SESSION 11 (23:30-00:00): GHIDRA MCP cracked the completer chain

Method note: drove ghidra_* MCP via reverser subagent twice (per-agent tool
config works well). Ghidra project mcla_findings:/default.xex has a systemic
flow-truncation defect (mflr/bl-glue marked no-return) — reverser repaired
locally per function. ALWAYS re-verify lis/addi pages: sign-correction means
my handoff pages 0x827D/0x827C were WRONG (gate-cracker's too).

## CORRECTED addresses (lis -32115 => 0x828D0000, NOT 0x827D0000)

- TU83 global block = **0x828D3738** (not 827D3738)
- Blocker scalar = **0x828CDA3C** (page 0x828C; sole reader
  Function_82425C18@0x82425C5c absolute-addressed; zero writers CONFIRMED by
  full-image byte scan incl. data)
- Cluster 0x828CD900-D9AC = TU74 event-pair work queue: obj id 0x828CD968,
  event 0x828CD978, wait-semaphore 0x828CD988, ctrl block DAT_828CD9BC
  (+0x12C count, +0x130 threshold)

## The parked object IDENTIFIED (same-run match)

FENCE event handle C9ADB800 == **SEMA-CREATE #31 h=C9ADB800 init=0 max=32767
lr=8244ECC8** (Function_8244EC78 -> NtCreateSemaphore). It's a SEMAPHORE,
not an event. Completion = NtReleaseSemaphore(C9ADB800,...) — ZERO fired.

## COMPLETION CHAIN (Ghidra ground truth)

```
submit: sub_821E5FD0 -> sub_821E5F48 -> Function_821E5E58
  - FUN_821c9060 -> Function_8244EC78 -> NtCreateSemaphore (embedded sema)
  - Function_821CB488(buf,1): name-keyed class factory ("alloc:" strings,
    registry walk @0x82860844, entry stride 0x114) -> bctrl prototype vtbl
  - vtbl slots: +54 size/id, +7C poll (returns -1 while pending),
    +80 finalize, +8C metadata, +78 flags
  - Function_821BCB10 registers into table DAT_8283D1C4 (1C-stride hash)
wait:   Function_821C90C0 -> 82135DB8 -> 82135DC0 -> NtWaitForSingleObjectEx
release: Function_821C9108 -> NtReleaseSemaphore (31 in-image callers;
         e.g. FUN_821bc8c8 releases *(base+0x616C))
worker: Function_823EC990 loop: KeWaitForSingleObject(0x828CD988) ->
        Function_823EC248 pumps DAT_828CD9BC items (XAudio voice-category
        ord-503/504 queries!) -> writes results ->
        KeReleaseSemaphore(0x828CD988, 1, pending-1, 0) @0x823EC2F0
```

- XamTaskSchedule worker sub_8244E538 = **DEAD CODE** (FUN_8244EB08 has zero
  xrefs; unreferenced data dword @0x82114288 only).

## Thread inventory (THREAD-CREATE census)

15 spawns: #1-11,14,15 start=**0x821C91C8** (registration trampoline — real
proc hidden inside ctx block at 8285FEA8/8285FED4; registers into list
0x8285FEA8-area then presumably dispatches); #12,#13 start=**0x8242FB88**
ctx=A0005D5C/A0005DAC (driver-cluster worker loop w/ counters +56/+60,
lwarx/stwcx lock at obj+44 — spawned exactly at GPU-init second).
NO spawn site found for Function_823EC990 family yet.
NOTE: LOGF_UTILITY is compiled out in our logger config — utility logs were
silently invisible all along.

## Next session (in order)

1. Decompile **sub_8242FB88** fully (threads #12/#13 body): what do they
   wait on / pump? Candidates as the op completers (spawned at GPU init,
   live in driver cluster).
2. Map trampoline 0x821C91C8 ctx blocks (8285FEA8/8285FED4) -> real thread
   procs of the 13 registered threads; check whether any is the
   823EC990-family drainer.
3. Ghidra: find spawn/reference of Function_823EC990 as DATA (function
   pointer store), including .pdata-only hits and vtable slots.
4. If completer thread exists-but-blocked: instrument its wait. If absent:
   derive honest kernel-role completion for op tag=4 — NOTE the pump handles
   XAudio voice-category queries, which WE already answer synchronously in
   XAudioGetVoiceCategoryVolumeChangeMask; a researched tag->query mapping
   may let us complete the op inline + release its semaphore legitimately.
5. Keep in mind: FLIP queue producer question (session 9) may resolve via
   the same worker family once any completer runs.

---

# SESSION 12 (00:15-00:40): task pool decoded — workers starve, producers never enqueue

Commits: `b7ff914` → (this session: THREAD-NODE dump, NtReleaseSemaphore +
TASK-DONE censuses). Ghidra subagent hit provider network_errors 3x this
session — retried later or work locally via generated TUs.

## Thread real-procs revealed (THREAD-NODE census)

Trampoline 821C91C8 copies 44 bytes from ctx node to stack then bctrls
[node+52]=proc / [node+56]=arg (TU16/17 decode + runtime node dump):

| Threads | Real proc | Role |
|---|---|---|
| #1-8 | **0x821C4528** | sysTaskExecutor pool (args A02138C0..A024CC30 = per-worker executor objs) |
| #9 | 0x821CD590 | ? |
| #10 | 0x82306230 | ? |
| #11 | 0x82306070 | ? |
| #14,#15 | 0x821BC910 | arg=0/1 |
| #12,#13 | 0x8242FB88 | direct driver workers |

## Pool worker proc DECODED (sub_821C4528, TU16:15372-15483)

```
loop:
  q = [worker+204]
  WAIT INFINITE on semaphore [q+1076]        <- via sub_821C90C0 (WAITSYNC
                                                lr=821C454C handles C622xxxx!)
  idx ring at [q+8+1024]; pop task ptr
  if task==0 -> thread EXITS
  copy 156B task descriptor from [task+156]
  bctrl [worker+52](...)                     // execute task
  sub_8244EE00([worker+36])                  // post-execute completion
```

Runtime proof workers ARE parked in that wait (WAITSYNC caller=821C454C,
handles C6220B80/F00/1180/1300 = SEMA-CREATE #9-30).

## THE SMOKING GUNS

1. **NtReleaseSemaphore fired EXACTLY ONCE EVER** (`obj=C5218280 count=1
   lr=8244ED20`, a boot handshake) — prior sessions censed the WRONG TWIN
   (KeReleaseSemaphore). All wake/completion signals go through
   NtReleaseSemaphore; after that single boot release, silence.
2. **TASK-DONE sub_8244EE00 count = 0** — NOT ONE pool task has ever
   executed. The 8 workers starve: nobody enqueues tasks / releases their
   queue semaphores.
3. Therefore op tag=4's completion chain breaks BEFORE enqueue: submit path
   creates sema (#31 C9ADB800), registers op in DAT_8283D1C4, returns
   "pending", waits... but the corresponding TASK never reaches the pool.

## Next session (single focused question)

**Why does the async submit never enqueue its task?**
1. Decode sub_821E5E58 enqueue tail (Ghidra, retry reverser - provider was
   down): between factory-create and return-pending, find the push-to-
   executor + NtReleaseSemaphore(wake-sema) sequence and what input gates it
   (likely a kernel import return value we get wrong).
2. Census candidates on that path: whatever import feeds the executor
   object ([worker+204] chain), plus NtCreateEvent/other allocs around
   submit time. Compare live values vs HW expectations.
3. If gate = our stub's wrong return: fix semantics (researched), tasks
   should flow -> pool wakes -> TASK-DONE fires -> NtReleaseSemaphore
   completes fences -> main thread unsticks. This is THE bottleneck for
   everything downstream (FLIP producer, draws, P4' gate).
4. Watch for: queue-full paths (ring is 256 entries), executor obj fields
   ([worker+204], [+48..+60] fn ptrs) needing init we skip.

---

# SESSION 13 (01:15-01:45): enqueue WORKS, wake FIRES, consumer never wakes

Commits: `79be4b2` -> (this session: ENQ/INLINE-EXEC/RINGB-CONSUMER
censuses). Ghidra delivered the full chooser decode before provider issues.

## The submit chain is HEALTHY through enqueue (all same-millisecond)

```
01:29:51.465 RINGB-CONSUMER ENTER #1/#2   <- threads #14/#15 start proc 821BC910(arg 0/1)
01:29:51.465 NtReleaseSemaphore(C5218280) <- submit's wake release (lr=8244ED20)
01:29:51.466 ENQ sub_821BCB10 -> r3=82849B2C  <- task PUSHED, ring B slot
            (ring B base 0x82849518 stride 0x6174 per Ghidra)
01:29:51.466 FENCE park (op tag=4 waits C9ADB800)
=> ZERO RINGB-CONSUMER CYCLE lines over the whole run: consumers NEVER
   return from their first wait despite waiting on exactly C5218280.
```

Ghidra chooser decode (Function_821BCB10): [obj+4]!=0 -> inline ret -1;
affinity==-1 -> ring A 0x8283D218; else ring B; queue-full -> ret 0 silent.
Producer Function_821BC868: lock, [q+0x6168]<15 check, copy 0x614 slot,
unlock, **NtReleaseSemaphore([q+0x616C],1,0)** - confirmed by our census.
Consumer twin Function_821BC910: waits [q+0x616c], pops [q+0x6164],
executes via 821bc140 iff slot[0x60C]!=0.

NOTE: first ENQ census version read guest memory inside the override ->
CRASHED first invocation (fault sub_821BCB10+0x7B, vtable-dispatch region).
Lesson: keep PPC_FUNC overrides register-only when the target dispatches
through vtables early. Minimal version ran clean.

## THE REMAINING BUG (isolated to our kernel layer)

Consumers park via NtWaitForSingleObjectEx(C5218280) -> IsKernelObject ->
GetKernelObject()->Wait(INFINITE). Producer releases via
NtReleaseSemaphore(typed XKSEMAPHORE*) -> QueryKernelObject<Semaphore>(
Handle->Header)->Release(1) -> count+=1; notify_all(). Host primitives look
correctly paired (kernel_objects.h Semaphore Wait/Release). Yet no wake.

Suspects (in order):
1. **Wrapper identity split**: waiter resolves wrapper W1 for handle
   C5218280; releaser's QueryKernelObject path resolves/creates W2 (lazy-
   wrap marking mismatch for kernel-CREATED objects?). Verify by logging
   `this` pointer in Semaphore::Wait + Semaphore::Release.
2. IsKernelObject(C5218280) false -> assert path swallowed (asserts off in
   RelWithDebInfo?) returning STATUS_TIMEOUT without blocking - but then
   consumers would CYCLE; they don't. So probably genuinely blocked on W1.
3. XKSEMAPHORE typed-arg translation: verify Handle->Header address ==
   C5218280 at runtime (log it).

## Next session (one focused fix)

Add two-line probes in kernel_objects.h Semaphore::Wait(entry, INFINITE
branch) + Semaphore::Release: log `this`, count, caller module hint. Run.
If two different `this` values appear -> fix identity resolution (likely
QueryKernelObject creating a second wrapper because NtCreateSemaphore's
guest header lacks OBJECT_SIGNATURE marking, or xdm.cpp lookup divergence).
If same `this` -> inspect notify semantics under std::atomic<uint32_t>::wait
(possible missed-wakeup: notify_all before waiter arms? No - waiter blocks
in wait(); but check count.load order vs notify).
THEN: consumer wakes -> pops -> INLINE-EXEC fires -> task completes ->
NtReleaseSemaphore(C9ADB800) -> main thread unsticks -> boot proceeds.
This single fix likely unlocks EVERYTHING downstream (FLIP producer,
draws, P4' gate progress).

---

# SESSION 14 (05:30-06:00): WAKE-LOSS ROOT FOUND — ring B has no consumer

Commits: probe landed (SEMA-wait/release identity probes via inline
spdlog in kernel_objects.h - do NOT include logging.h there, breaks
mutex.h windows.h ordering; phase0 must stay linkable so probe is inline).

## Probe evidence (one millisecond, 05:45:09)

```
.545 SEMA-wait this=0x1c5218300 / 0x1c5218280   <- ring-A semas HAVE consumers (#14/#15)
.545 SEMA-wait this=0x1c6220b80..2200           <- pool workers on executor semas
.546 SEMA-release this=0x1c9adb880 count=GARBAGE<- wake lands HERE: ring-B sema
.547 SEMA-wait this=0x1c9adb800                 <- fence park (op tag=4)
=> ZERO consumer cycles. NOBODY ever waits 0xC9ADB880.
```

Host addresses = 0x100000000 + guest VA (identity) - wrapper resolution on
the WAIT side is correct everywhere.

## Interpretation (high confidence)

The submit routed op tag=4 to **RING B** (chooser: affinity != -1 ->
0x82849518-family queue). Ring B's wake semaphore [q+0x616C]=C9ADB880 got
released into the void: no thread waits on it. Ring A (0x8283D218 family,
semas C5218280/C5218300) HAS consumers - threads #14/#15 running
Function_821BC910(arg 0/1). Garbage count on phantom wrapper = lazy-wrap
QueryKernelObject wrapped raw guest bytes at C9ADB880 (never-kernel-created
embedded semaphore) - benign for the probe, but proves no real wrapper
exists for it either.

## Next session (priority order)

1. **Chooser affinity source**: in Function_821BCB10 raw disasm, trace r23
   (affinity) back - which field of what object decides ring A vs B? Ghidra
   raw-disasm region 0x821bcda0-0x821bce30.
2. Decide honest fix:
   a. If affinity derives from data we mis-emulate (e.g., a kernel return
      that should be different) -> fix semantics, task flows to ring A,
      existing consumers execute it. PREFERRED (no invented threads).
   b. If HW genuinely spawns a ring-B consumer later in boot -> find that
      spawn trigger; our boot diverged before reaching it.
3. Verify chain after fix: RINGB/POOL cycles fire -> INLINE/TASK-DONE ->
   NtReleaseSemaphore(C9ADB800) -> FENCE returns -> main thread unsticks ->
   RW traffic resumes past drains=4 -> FLIP producer question reopens with
   live tasks running.

## Standing gotcha added

Never read guest memory inside a PPC_FUNC override whose target dispatches
through vtables early (crashed at sub_821BCB10+0x7B). Register-only until
after __imp__ passthrough.

---

# SESSION 15 (06:00-06:20): A/B INVERTED — producer/consumer queue-instance mismatch

Commits: `39e0134` -> (this session: static trace, no code changes).
User decision: option (a) trace-first. Ghidra delivered decisive correction.

## Corrections (Ghidra ground truth, flow-repaired)

1. **Ring choice is NOT r7-derived.** r7=0x821BC548 is the DEFAULT COMPLETION
   CALLBACK (F48 forces li r5,0 @821e5f84; E58 turns aff==0 into callback
   ptr via lis/subi 0x821BC548). Selection reads table
   **@0x827D74E4 + 3*idx(=[0x8283D1DC]) + r9(=0)**: bytes `00 01 FF|FF FF 00`
   -> idx0 col0 = 0x00 -> extsb -> cmpwi -1 fails -> **RING B BY DESIGN**.
2. **Threads #14/#15 (Function_821BC910) ARE ring B's consumers** -
   BC910 hardcodes ring B base (`subi r11,r11,0x6ae8`), stride 0x6174,
   waits [q+0x616C] @821bc938-3c, pops [q+0x6164] mod 0x10, executes
   821bc140 iff slot[0x60C]!=0. My earlier "ring A" attribution WRONG.
3. FD0 callers: five identical wrappers (822d5fa0/822d77a0/826e2d90/
   826f8640/82791400) - all forward their own r6; irrelevant since F48
   zeroes it.
4. FUN_821bc9a8 supervises BOTH rings (holds 0x82849518 AND 0x8283D218).
5. Ring-B destructor exists (827B89D8) - queue lifecycle managed in-image.

## THE REAL DIVERGENCE (runtime + decode combined)

Producer pushed to ring B and released **[prodQ+0x616C]=C9ADB880**
(probe: SEMA-release this=0x1c9adb880 garbage-count = lazy-wrapped raw
bytes - never a kernel-created object). Consumers BC910 wait
**[theirQ+0x616C]=C5218280/C5218300** (WAITSYNC lr=821bc940 handles match;
probe SEMA-wait confirms). Same offset, DIFFERENT QUEUE INSTANCES.

=> The producer resolved a different ring-B queue object than the
consumers registered with. Likely mechanisms:
- queue base derived from TLS/per-thread storage or arg (BC910 arg 0/1!)
  vs producer deriving from op/object field ([op+4]->&0x828CDA3C chain)
- or multiple ring instances created during init; consumers attached to
  instance 1, producer wrote instance 2 whose wake sema lives in raw
  memory (hence never-created wrapper)

## Next session (single question)

**Pin both queue base pointers.**
1. Census sub_821BC868 (producer push) entry: log r31/queue base + computed
   [q+0x616C] handle. Census BC910 wait loop: log ITS queue base + sema.
   Compare - they WILL differ; note each base's derivation chain.
2. Decode how each side derives the base: producer side from BCB10
   (r10=subi 0x2de8/0x6ae8 from WHICH source reg - global, TLS, or arg);
   consumer side from BC910 entry (base reg origin + role of arg 0/1).
3. Then decide fix: if producer should target the consumers' instance,
   find why our kernel returns divergent instance data (likely an
   unimplemented import returning wrong table pointer); if consumers
   attach late/wrong instance, find registration site (FUN_821bc9a8?).
4. After fix, expect cascade: consumer cycles -> INLINE/TASK executes ->
   fence C9ADB800 released -> main thread unsticks -> drains resume.

---

# SESSION 16 (11:30-12:00): WAKE-LOSS FIXED — tasks execute, stall broken

Commits: `39e0134` -> **`ac4d613` (THE FIX)**. phase0 13/13 PASS.

## Root cause (probe-proven, one call)

NtReleaseSemaphore received guest C5218280, hdrOff=0 correct - yet
QueryKernelObject<Semaphore>(Handle->Header) returned a PHANTOM wrapper at
guest C9ADB880 with garbage count. Mechanism: the game's driver RE-
INITIALIZES dispatcher headers after NtCreateSemaphore (it owns these
structs), wiping our OBJECT_SIGNATURE -> Flink!='XBOX' -> lazy-wrap branch
allocated a fresh wrapper over raw bytes. Waiters were unaffected because
NtWaitForSingleObjectEx uses GetKernelObject = pure identity translation
(no signature gate). Asymmetric resolution = wake lost.

## The fix (imports.cpp NtReleaseSemaphore)

Resolve via identity translation first (guestHandle=hostPtr-base;
mem.IsValid; direct->IsValid() wrapper check), fallback to QueryKernelObject
only for unknown addresses. Symmetric with the wait path.

## Cascade VERIFIED LIVE (rung-2)

```
SEMA-release this=0x1c5218280 count=0        <- CORRECT wrapper now
INLINE-EXEC sub_821BC140 #1 a0=82849B2C      <- parked op tag=4 task EXECUTED
INLINE-EXEC #2 a0=8284A140                   <- second task flows
SIGNAL NtReleaseSemaphore guest=C6221780     <- executor pool being fed!
```

Then the run crashed at **sub_825FDB30+0x158** (exit C0000005) - NEW code,
inside freshly-executing paths. RINGB-CONSUMER CYCLE=0 just means consumer
was mid-execute at crash. Fence-park status: superseded by crash.

## Next session (in order)

1. Decode sub_825FDB30 + crash context (PARK-SAMPLE/crash frames): what is
   it, what does it touch (import? MMIO? null field?). The crash is INSIDE
   the newly-flowing task path - likely an unimplemented dependency of the
   task body (op tag=4 work).
2. Check whether main thread unstuck pre-crash: grep post-submit traffic
   (RW lines past #0006, FENCE RETURNED, new submits).
3. Same latent bug family to audit (all QueryKernelObject users on
   kernel-CREATED objects where game may re-init headers):
   KeSetEvent/KeResetEvent/KeReleaseSemaphore/NtReleaseMutant etc. Apply
   identity-first resolution pattern where evidence demands.
4. After crash fixed: resume P4' front line (drains past 4, FLIP producer,
   draws).

---

# SESSION 17 (12:00-12:20): new crash decoded — main-thread AV, boot continues past old stall

No code changes this cycle. Crash report analysis of run @ac4d613.

## GOOD NEWS first

Timeline shifted: GPU init now happens ~2s post-boot (11:54:58) WITH live
main thread (PARK-SAMPLE shows it running through submit traffic RW#0001-2,
SUBMIT-census firing). The old fence park did NOT recur before crash.
Also observed: `NtQueryInformationFile: class=26 -> STATUS_INVALID_INFO_CLASS`
warnings twice right before traffic (class 26 = FileIoPriorityInformation?
verify against xenia class table - possible missing-info divergence feeding
the later crash).

## The real crash (original exception, main thread)

```
Vectored exception C0000005 READ addr=0x7E780000 (HOST address!)
frames: [10] __imp__sub_82131508+0x115
        [11] __imp__sub_82131790+0xB2C
        [12] __imp__sub_821BD7C0+0x322
        [13] __imp___xstart+0x55E
```

sub_82131508 = TU0 boot-init fn (generated ppc_recomp.0.cpp:3465+, big
init: calls 82304708/822BF880/822C2EA8/822BF970/821FFC28/822C4EB8...).
+0x115 lands ~line 3605 region - NOT yet pinpointed to an exact insn.
Host addr 0x7E780000 is NOT a Translate() product (those are
0x1Cxxxxxxxx); it smells like a RAW pointer stored somewhere (host heap /
SDL / d3d / or guest value used as host ptr by our runtime code).

Secondary nested fault during dump handling (thread same): frames
[12] __imp__sub_8260A710+0x116 / [13] __imp__sub_825FDB30+0x158 - the
task-execution path faulted again while UnhandledExceptionFilter ran.
sub_825FDB30 body (TU124:11126): calls 825F9390 / 8260A710 / 8260A7D0 /
825F93F0 with r3=task-derived (rotl([r31+164],3)+[r30+12]) - graphics/
command-buffer flavored work.

## Next session (in order)

1. Symbolize EXACT faulting instructions: llvm-symbolizer --obj=build\mcla.exe
   for host RVAs of both faults (crash log gives module rva only for one;
   recompute from nf= offsets: sub_82131508 entry host addr via PDB/SymFromAddr
   then +0x115). Identify which pointer is 0x7E780000 (dump r3/r4 regs at
   fault via crash ctx if available; add reg dump to UnhandledExceptionFilter
   output if missing).
2. Check NtQueryInformationFile class 26 semantics vs xenia
   (NtQueryInformationFile FileInformationClass table) - implement honest
   answer (likely FileIoPriorityInformation -> return STATUS_SUCCESS with
   default priority 0? verify) IF evidence ties it to the fault chain.
3. THEN resume cascade verification: does boot reach menu once 82131508
   crash fixed? Watch drains/RW#>6/XE_SWAP as P4' gates.
4. Standing audit (from SESSION 16 list): identity-first resolution for
   KeSetEvent family still pending - do AFTER crash is understood (avoid
   confounding two changes).

---

# SESSION 18 (13:00-13:30): bug family FIXED systemically; remaining defect = NULL fnptr in task node

Commits: `7a4513f` (host reg dump) -> `86fd835` (family-wide identity-first
resolution). phase0 13/13 PASS.

## Done

1. **ResolveCreatedObject<T> helper** applied to KeSetEvent / KeResetEvent /
   KeReleaseSemaphore / KeWaitForSingleObject (Event+Semaphore cases) /
   NtReleaseSemaphore: direct identity translation when a valid wrapper
   exists at the guest address, QueryKernelObject lazy-wrap only as
   fallback. Phantom-wrapper class killed game-wide.
2. Host GP register dump added to vectored handler (boot_host.cpp).

## Remaining defect pinned precisely

Crash unchanged at sub_8260A710 dispatch region. objdump of faulting insn:

```
movl 0x20(%rsp),%eax        ; rax = fnptr READ from task node [+4] (checked read)
callq *(%r12,%rax,2)        ; PPC_CALL_INDIRECT_FUNC - dispatch
FAULT: rax=0 => ctr=0 => slot = base+0x829E0000+((0-0x82130000)*2) far OOB
regs every run: rbx=0xb7baee50 r8=0x88825508 (heap-ish values), base OK in rdx/rdi/r9
```

=> **The dispatched function pointer is ZERO**: the task descriptor's
callback field was never filled. The op tag=4 descriptor reaches the
consumer with a NULL callback because an upstream prep step silently no-
ops under emulation - prime suspects Function_821E58F0 (prep/validate,
called right before BCB10; its return gated the enqueue and returned ok)
or the name-keyed factory methods (+0x54/+0x78/+0x8C) that should stamp
the exec function pointer into the descriptor.

## Next session (in order)

1. Extend INLINE-EXEC census (sub_821BC140 entry): guarded dump of node
   chain a0 -> [a0+4]=node1 {node1[0],node1[4](fnptr),node1[12]=next} up to
   3 nodes. Confirms which field is zero + whether ANY field holds code VAs.
2. Ghidra: decompile Function_821E58F0 fully - list what it writes into the
   descriptor (offsets!) and which import/kernel-return gates each write.
3. Fix the gated write whose kernel input we get wrong; verify cascade:
   non-zero fnptr -> task body runs -> fence C9ADB800 released -> main
   thread unsticks.
4. Then P4' gates resume (drains>4, FLIP producer, draws).

---

# SESSION 19 (13:40-14:10): zero-fnptr mechanism narrowed — stale-pop prime suspect

Commits: `86fd835` -> `6c1f5c5` (NODE-CHAIN dump census added, not yet run).
Ghidra decoded Function_821E58F0 + descriptor lifecycle.

## Descriptor lifecycle (Ghidra ground truth)

- E58 default-fills fn: desc+0x60C = **0x821bc548** (stw r19,0x66C(r1)
  @821BCD40; desc base r1+0x60) - matches BC140 read offsets exactly.
- E58F0 only writes entry+0 (alloc offsets); NEVER touches node fnptrs.
- Factory vtbl methods never supply exec-fnptrs. ONLY writer of +0x60C
  anywhere in image = zero-init Function_82165980 @82165A04.
- Contention branch: FD0 when Function_821BC5D0 lock probe reports HELD ->
  Function_821BD520 pushes a RAW STACK TEMPLATE (1548B, unfilled +0x60C)
  via BC868 directly.

## Reconciliation with runtime censuses

Our run: BCB10 fired (ENQ -> slot 0x82849B2C, lr=821BCE0C ring-B branch =
BCB10's OWN internal BC868 push of the FILLED descriptor) AND exactly ONE
PUSH total. Yet consumer dispatched fn=0. Since the pushed copy contained
0x821bc548 at +0x60C, the consumer must have popped a DIFFERENT/STALE slot:
**producer write idx [q+0x6160] vs consumer pop idx [q+0x6164] desynced**
(count [q+0x6168] >=1 spuriously before our push - e.g., leaked increment
from an earlier phantom release), so the wake delivered a stale zeroed slot
while the real task waits at another index.

## Next session (micro-steps)

1. Extend PUSH census: also print [q+0x6160]/[+0x6164]/[+0x6168] after
   passthrough. Extend RINGB-CONSUMER cycle line: same three counters.
2. If counters prove stale-pop: find the leaked increment source (earlier
   spurious NtReleaseSemaphore on C5218280? audit ALL releases pre-submit;
   SESSION 12 said exactly one boot-handshake release exists - check whether
   IT incremented this very queue sema before consumers attached).
3. Alternative if counters clean: BD520 contention branch DID run for a
   second op; probe Function_821BC5D0 lock word to see why it reports held.
4. Fix honestly per whichever mechanism proves; then cascade verify ->
   P4' gates.

---

# SESSION 20 (14:20-14:40): stale-pop DISPROVEN — node-list builder skipped

Commits: `6c1f5c5` -> `0871dde` (counter probes + NODE dump). Run evidence:

```
PUSH #1 q=82849518 wIdx=1 pIdx=0 cnt=1      <- counters CLEAN (perfect first push)
INLINE-EXEC #1 a0=82849B2C                   <- our slot
NODE[0] @ 0x50000000 w0=0 fn=0 next=0       <- [slot+4] = 0x50000000 GARBAGE
PUSH #2 / INLINE-EXEC #2 same shape          <- second op identical
crash: same bctrl site (dispatches fn=0 via chain from garbage "node")
```

## Conclusion

Queue mechanics FULLY WORKING (indices, count, wake, pop all correct).
The defect is upstream: **the slot's node-list pointer field [+4] was
never initialized** by the descriptor builder - value 0x50000000 is raw
garbage from BCB10's stack frame region that BC868 copied verbatim.
BC140 then treats [slot+4] as first node ptr -> reads zeros at 0x50000000
-> fn=0 -> bctrl dispatch crash.

Who SHOULD write [+4]: per SESSION 19 decode, E58F0 pass-1/pass-2 write
entry+0 offsets into the pkt area and allocate; the node LIST HEAD likely
gets stored into the descriptor by E58F0 pass-2 or the E58 tail AFTER
allocation succeeds. Under emulation some input to that step (allocator
vtbl+8 call result via [[r13]+0x1C] object? DAT_8286CE81 bulk flag?)
diverges so the list-head store never executes while earlier stores do.

## Next session (single question)

1. Ghidra: in Function_821E58F0 post-repair, find the store to [desc+4]
   (or wherever slot+4 originates - trace what BC910/BC140 receive:
   BC910 pops slot ptr from ring; slot IS the copied descriptor; so find
   writer of desc+4 in E58/E58F0/BCB10 stack-frame setup). Identify the
   conditional that skips it under our kernel returns.
2. Note: 0x50000000 may itself be diagnostic - check if it equals an
   uninitialized-stack pattern or a real allocation base our side returned.
3. Fix => NODE[0].fn becomes valid code VA => task runs => fence release =>
   main thread unsticks => P4' gates.

---

# SESSION 21 (14:50-15:10): FULL CHAIN CLOSED - unimplemented PM4 opcodes leave work buffers zeroed

Commits: 0871dde -> (this session: analysis only). Ghidra Q&A + runtime
NODE dump reconciled into one causal chain.

## Reconciliation (all evidence fits)

- desc+4 is written ONLY by BCB10's memcpy of count*12 RECORD bytes
  (guarded count>0 @821BCCAC); records = {+0 objPtr,...} stride 0xC.
- Our run: fn@0x60C valid (0x821bc548) BUT first record objPtr=0x50000000
  with ZEROED CONTENTS ([0x50000000+0/+4/+12] all read 0 - checked reads
  succeeded => mapped memory, just empty).
- 0x50000000 = legitimate work-buffer address the game EXPECTS to be
  populated by EARLIER GPU INIT COMMANDS. Those commands are the ones our
  CP drain SKIPS every boot:
    CP: skipping TYPE3 opcode=0x48 count=18
    CP: skipping TYPE3 opcode=0x3F count=2
- Zeroed buffer -> node obj zeroed -> fn=[obj+4]=0 -> bctrl ctr=0 -> AV.
  (Allocator-failure / count==0 paths from prior Ghidra pass exist but
  runtime counters + valid fn rule them out.)

## ROOT CAUSE (whole stall chain)

Unimplemented PM4 TYPE3 opcodes 0x48 and 0x3F in our DrainRing leave init-
phase work buffers zeroed; the async task referencing them executes null
function pointers. Same family as the original F98/rptr stalls: our CP
emulation handles only TYPE0/TYPE2/XE_SWAP/skip-log.

## Next session (single focused task)

1. Identify opcodes 0x48 and 0x3F in xenia gpu/xenos.h PM4 tables
   (check command_processor.cc ExecutePacketType3 switch + xenos.h enum).
   Implement honest handling: at minimum their memory-write/register side
   effects so init buffers get populated.
2. Re-run: NODE[0].fn should become valid code VA -> INLINE-EXEC completes
   -> NtReleaseSemaphore(C9ADB800) -> main thread unsticks -> RW traffic
   past #0006 -> XE_SWAP > 0 = P4' breakthrough gate.
3. Then continue P4' ladder (FLIP producer, draws) per plan.

---

# SESSION 22 (15:30-16:00): PM4 0x48/0x3F/0x3D implemented + IB executor live; populator still missing

Commits: c5b0156. phase0 13/13 PASS.

## Landed (xenia-cited)

- DrainIndirectBuffer: linear IB executor, depth-guarded, TYPE2/TYPE0/TYPE3
- PM4_INDIRECT_BUFFER(0x3F) recursion in primary ring + IBs (VERIFIED: 4 IBs
  walked @062B44C0 dwords=11 / @06234480 dwords=64/27 - contents TYPE0
  reg-writes base=000)
- PM4_ME_INIT(0x48): consume+log (no side effects per xenia :880-890)
- PM4_MEM_WRITE(0x3D) with GpuSwap32 endianness mirror

## Remaining

Work buffer @0x50000000 STILL zeroed at task-dispatch time; init stream has
NO MEM_WRITEs. Candidates for its real filler:
1. ME_INIT microcode semantics (CP micro-engine RUNS and writes?) - xenia
   just bins the bytes, but on HW ME processes subsequent commands
2. Register-file side effects: IB contents are TYPE0 reg-writes base=000 -
   on HW some register ranges TRIGGER memory actions (e.g. context/RB window
   writes); our register file is absent so effects lost
3. The buffer is filled by CPU DMA (game-side memcpy we DO see) but LATER
   than task dispatch - ordering issue vs our fence release timing
Next: instrument reads of page @0x50000000 (who touches it pre-crash), and/
or implement register-file for base=000 TYPE0 writes to see if they alias.

## Standing state

Stall chain otherwise SOLVED: semaphore identity fix + queue mechanics +
IB execution all verified. Single remaining gap = one zeroed buffer.

---

# SESSION 23 (16:10-16:40): PLAN RE-ANCHORED - P4' HOOK SET FULLY SPECIFIED

User decision: stop CP expansion (CP FREEZE LINE written into
MCLA_REBUILD_PLAN.md - legacy-only, retired P6'); proceed P4' device-boundary
takeover. Remaining async/fence boot blocker re-scoped as KERNEL work
(SESSION 21-22 state stands for whenever we return to boot-soak).

## P4' HOOK SET (Ghidra-verified, minimal)

1. PresentKick: sub_824294E0 (r3=dev, r4=fbAddr) / sub_82429570
   (vsync-aware flip picker: backbuffer idx dev[+0x5498] vs count
   [+0x5494], base [+0x548c]). Both write PM4 0xC0025800,0x80000003,
   fbAddr|2 then fence word 0xDEADBEEF (binary literal; prior DEBCBEEF =
   transcription error). Frame boundary capture point.
2. SubmitBatch: sub_82420BA8 = per-batch geometry submit (DrawIndexedPrimitive-
   equivalent). Args: r3=dev, r4=primType/flags (bits26+ prim, low nibble
   stream class), r5=VB-desc{base,stride,size,size}, r6=IB-desc (+0x20 base
   page-aligned|fmt bits0-5; +0x24 index-count halves 11/13-bit split by
   tiling dev[+0x30]&0x600==0x400; +0x28 bit31-30 index width), r7=VB2-desc.
   CAPTURE: snapshot dirty masks dev[+0x10/+0x18/+0x20] + shadow reg block
   dev[+0x28CC..+0x2FA0] BEFORE ring emission - full state lives there,
   NO per-handler overrides needed for the 101 RS slots.
3. (optional) sub_8241BD08 flush - drain boundary only.

## Facts that de-risk implementation

- RS table @dev+0x40 (101 slots) = SetRenderState-class handlers ONLY;
  draws never dispatch through it. Shadow table @+0x224. Defaults applied
  via RS[i](dev,default) from template PTR_FUN_827ec368 (101x12B:
  {shadowFn,ringFn,defaultValue}). Samplers @+0x1D4(20)+0x3B8.
- Flips reach display via fence consumed by ISR 0x82411478 - no title-level
  VdSwap dependency on this path.
- sub_82413660 = scissor/window packet builder (misnamed draw-packet).

## NEXT SESSION - implement P4' step 3 hooks

1. Override sub_82420BA8 (global-scope PPC_FUNC, register-only pre-snapshot):
   capture {primType, VB descs, IB desc, dirty masks, shadow block} into a
   RenderCommand; passthrough unchanged (legacy still renders).
2. Override sub_824294E0/9570: mark frame boundary + fbAddr in command.
3. Native render thread consumes commands -> D3D12 (P4.5' queue design).
4. Gate: one real draw captured + full state set = P4' gate criterion.
5. Boot-blocker kernel work (async/fence) resumes AFTER hooks prove out -
   or in parallel if soak needs main thread alive longer.

---

# SESSION 24 (16:50-17:20): GENERATED TREE VERIFIED INTACT - full regeneration byte-identical

User hypothesis: generated src broken (post disk incident) -> regenerate.
Verified definitively:

1. /generated/ is GITIGNORED - zero VCS protection; no backup existed
   (D:\mcla_backup generated tree EMPTY; C:\mcla-pc mirror lacks it).
2. Rebuilt XenonRecomp from .research/XenonRecomp/build-clang (exe present,
   no work needed); restored lost input path build/game_data/default.xex
   (disk-incident loss; copied from game_data/).
3. Regenerated all 179 TUs + func_mapping: **BYTE-IDENTICAL** to the live
   tree (robocopy /XX diff: only ppc_context.h differed = template echo
   artifact from my passback; restored clean copy).
4. Unrecognized-instruction warnings during regen (vsel128/mulhdu/frsqrte/
   dcbst at 0x827A1B04/0x827BF4C0/0x827C2D08/C2E28/C6E80) are REPRODUCIBLE
   codegen gaps, not corruption - same output as Aug 17 baseline.

CONCLUSION: generated source is NOT broken. Runtime defects are genuine
emulation gaps (current front: work-buffer populator @0x50000000, see
SESSION 21-22). Regeneration now repeatable: tool builds via
cmake --build .research/XenonRecomp/build-clang --target XenonRecomp;
requires build/game_data/default.xex input path.

---

# SESSION 25 (19:30-20:00): page-watch landed; crash re-characterized as EARLY deterministic dispatch fault

Commits: c17e11b (P4 hooks) -> 96ddd54. Build green, phase0 13/13.

## Landed

- P4' capture hooks armed (CapturedDrawV1 + PresentKick) - ZERO fire: boot
  crash precedes any draw.
- PAGE-WATCH on guest 0x50000000 via checked accessors
  (guest_memory.cpp range check -> gpu_cp.cpp PageWatchOn{Read,Write} with
  guest-lr attribution). RESULT: ZERO touches all boot - the populator never
  ran through checked path (or writes bypass it entirely).
- VFS root hijack fixed: my build/game_data/default.xex restore for the
  regen made app resolve 'Game data root: build\game_data' -> missing rpfs
  -> early fatal. Removed dir; REGEN PROCEDURE MUST REMOVE IT AFTERWARD.

## NEW characterization (important)

Crash reproduces EARLIER now - before ANY task-queue traffic (no
INLINE-EXEC/PUSH/NODE lines in final run) - at the SAME dispatch site with
IDENTICAL deterministic registers every run:

    rva~0x26D2xxx-26D5xxx (sub_8260A710 region), READ @0x7E780000,
    rbx=0xb7baee50 r8=0x88825508 r10=0xcd r11=0xe base(rdx/rdi/r9)=OK

=> There is a SINGLE deterministic indirect-dispatch site crashing with a
NULL/garbage fnptr EARLY in boot; the earlier INLINE-EXEC sightings were
downstream instances of the same defect class. 0x50000000 zero-buffer is
likely a SYMPTOM instance, not the root.

## Next session

1. Identify the exact function containing rip rva ~0x26D2416/0x26D3436/
   0x26D5816 (varies by build): llvm-symbolizer fails there ('??:0') ->
   dump symbols around those RVAs via llvm-pdbutil EXR / moddump, or add
   SymFromAddrW in the VEH (works: NearestFunctionName pattern).
   Determine WHICH guest fn's bctrl faults and WHAT object supplies the
   null slot (rbx/r8 values are stable guest-space keys - find their owner).
2. Then trace why that object's dispatch slot is zero under emulation
   (likely another identity/lazy-wrap or unimplemented-init gap).
3. Keep PAGEWATCH active - once the early site is fixed, later buffer
   population may appear.
