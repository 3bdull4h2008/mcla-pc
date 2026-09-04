# Second-brain ledger — session 4 (2026-08-23)

Durable fallback store (schema per `.clinerules/skills/second-brain.md`) because
`second_brain_*` / `codebase_memory_*` MCP servers were not attached when these
were recorded. Full evidence: `docs/handoffs/2026-08-23-session4-packet-capture.md`.
Import into the graph/MCP when next available.

> ⚠️ Path note (2026-09-03): written when the ledger lived under `.opencode/`;
> the canonical ledger directory is now `.clinerules/memory/` and handoffs live
> in `docs/handoffs/`. This file is historical — do not write here.

---
subject: decision:pushbuffer-reserver-semantics
tags: [session-4, phase-4, hook, guest-address:0x82411640, reverser]
confidence: high
source: generated/ppc_xenon/ppc_recomp.77.cpp:18924-20014 + Ghidra waves
content: >
  sub_82411640 = push-buffer SPACE RESERVER (dev r3, flags r4, sizeSlot r5 ->
  reads ONLY slot[0] = requested bytes, returns reserved window VA r3, writes
  back consumed bytes). NOT a packet writer. sub_82411180 = wait-for-space
  barrier. sub_82411618 = push-buffer attach; 0xA0009100 = SECOND GuestDevice
  instance (same class, bound at create via sub_82413588).

subject: evidence:r5-only-meaningful-at-entry
tags: [session-4, capture-pitfall, reverser]
confidence: high
source: reverser + research-scout independent agreement
content: >
  Packed value pairs seen in captured stack (92 40 93 40 ...) are STALE STACK
  GARBAGE, not registers or microcode. Only r5[0] is meaningful at 640 entry.
  Never treat captured stack pairs as register state.

subject: decision:gpu-device-capture-v2-deferred-drain
tags: [session-4, phase-4, implementation]
confidence: high
source: src/gpu_device.cpp capture v2
content: >
  Capture v2 = DEFERRED-DRAIN: windows are empty at reservation time (builders
  fill them afterwards); snapshot dev/flags/slotAddr/alignBytes pre-call,
  passthrough, read consumed=slot[0] post-call, queue {window,dwords,flags,
  align}, drain pending windows on NEXT submission, tail drained at summary.
  Pitfall recorded: eager window reads yield zeros (early-read-zeros), proven twice.

subject: evidence:640-init-seam-not-perframe
tags: [session-4, phase-4, pm4-evidence]
confidence: high
content: >
  Captured real PM4 through hook 640: C0043C00 type-3 WAIT_REG_MEM count=5
  (payload 03/0A31/00000000/80000000/08), batch tokens 00000A31, t0 x8 reg
  writes, phys addr 06234000. 640 fires only ~4x/boot => INIT/STATE SEAM,
  NOT the per-frame draw seam.

subject: open-question:per-frame-draw-seam-location
tags: [session-4, phase-4, next-step]
confidence: medium
content: >
  Per-frame draw seam location unknown (NOT 640). Candidates:
  Function_8241E498 (VSync worker, direct writes {5C8,20000} + paired
  0xC0022100 at dev+0x30), sub_82429328/sub_82429428/sub_824296E8, and other
  sub_82411840 consumers incl. ppc_recomp.79.cpp:30985 sub_82420BA8.
  Plan: hook + gate on >=1 hit during menu soak.

subject: open-question:indirect-dispatch-zero-windows
tags: [session-4, phase-4]
confidence: medium
content: >
  4-dword indirect-dispatch windows read zeros even one submission later —
  suspect flush-time patching of ring bytes. Decode via sub_82411DC0(win,args)
  parameters instead of reading ring window content; confirm before trusting.

subject: milestone:shader-corpus-decode-clean
tags: [session-4, gates, shader-translator]
confidence: high
source: corpus validators, xenia shader.cc:34
content: >
  Shader corpus decode fully CLEAN: 806/806 binary microcode, 0 unknown /
  0 oob / 0 returns. Root cause fix: .ucode.bin.* dumps are HOST-ENDIAN (LE)
  per xenia shader.cc:34 -> byte-reversal needed; text-companion files skipped.
  Gates flipped tracked->ENFORCED, all green: G-XENOS-DECODE-CLEAN,
  G-CORPUS-shader_pipeline_validator, G-CORPUS-phase3_validator. New shared
  helper src/renderer/raw_ucode_corpus.h.

subject: process:packet-strides-xenia-ground-truth
tags: [session-4, reference]
confidence: high
source: .research/xenia/src/xenia/gpu/command_processor.cc ExecutePacketTypeN
content: >
  Packet stride ground truth = Xenia command_processor.cc ExecutePacketTypeN:
  t0 = field+2 dwords TOTAL, t1 = THREE dwords, t3 = field+2. There is NO
  packet.h in the vendored tree — do not look for one.

subject: handoff:2026-08-23-session4
tags: [session-4, handoff]
confidence: high
content: >
  Lossless handoff written to .opencode/handoffs/2026-08-23-session4-packet-capture.md
  (base 23dd69a; gate report build\gates\2026-08-23-gate-report.json OVERALL PASS).

---

# Session-4 continuation (2026-08-23)

subject: evidence:park-not-in-function-824e5350-case9
tags: [session-4-cont, park-investigation, reverser]
confidence: high
source: park-sampler runtime samples
content: >
  Main thread does NOT park in Function_824E5350 case-9 — static hypothesis
  RETIRED. Park-sampler shows spin inside guest driver VBlank/present state
  machine: mcla.exe RVA cluster 0x86E19-0x87202, attribution near sub_824296E8
  region; return addrs into sub_82411E98 / sub_82411F30 idle-wait family;
  one sample at sub_82412F98.

subject: tool:park-sampler-boot-host
tags: [session-4-cont, diagnostics]
confidence: high
source: src/boot_host.cpp
content: >
  Park-sampler diagnostic thread lives in src/boot_host.cpp: suspends guest
  worker every 500ms, logs rawrip/base/RVA-resolved guest VAs + stack returns.
  USE IT FIRST for any parked-thread question before static analysis.

subject: fix:xmsg-sync-complete-and-session-handles-vsync-r3
tags: [session-4-cont, implementation, kernel-fixes]
confidence: high
source: kernel/XAM impls + ppc_recomp.158.cpp:27368-27420
content: >
  Three fixes landed: (a) XMsgStartIORequest completes sync + unconditionally
  (MCLA posts event-less overlappeds, polls Error); (b) XamSessionCreateHandle /
  XamSessionRefObjByHandle now typed identity-handle impls returning 0 —
  guest msg-251 gate requires r3==0; (c) VSync interrupt type flips r3=0 ->
  r3=1 every tick (swap-release branch).

subject: open-question:park-persists-ring-cursor-frozen
tags: [session-4-cont, next-step, park-investigation]
confidence: high
content: >
  Park persists after all three fixes; ring put cursor still frozen; submit
  family zero hits. Next: (1) decode exact spin-loop word via PDB symbolization
  of RVA cluster (llvm-symbolizer DIA broken; `llvm-pdbutil dump -symbols`
  works), (2) fix sampler state reads — poller slot 0x82839254 holds DEVICE
  ptr not GPU_ctx, (3) then satisfy awaited condition Xenia-style.

subject: gotcha:log-utility-not-mcla-log
tags: [session-4-cont, logging-pitfall]
confidence: high
source: build log inspection
content: >
  LOG_UTILITY comes from the .research/UnleashedRecomp include-path logger and
  does NOT write to build/cache/mcla.log. Use MCLA_LOG_* macros for runtime
  probes.
