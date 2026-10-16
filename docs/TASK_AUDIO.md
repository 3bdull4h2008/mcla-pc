# TASK_AUDIO — XMA framing + silence policy (one doc, no split)

> Status: framing DONE, bitstream PARKED, silence CORRECT. Nothing in
> `src/apu/` can make audio reachable — reachability is a guest problem.

## Why silence is correct (measured, not assumed)

- Raw-word scan of `build/cache/mcla_pe.bin` finds exactly ONE direct `bl`
  to `__imp__XAudioRegisterRenderDriverClient` (at `0x823F3774`, inside
  `sub_823F3718`); that function has ZERO direct callers and lives only as a
  dword in two vtables (`0x8205F0E4`, `0x82112AB8`), neither referenced; no
  address in `0x823F3000..0x823F7000` is in the guest `.CRT$XCU` table
  (`0x827D0010..0x827D13E0`, 1267 pointers). Full record:
  `src/apu/audio.cpp:40-51`.
- Consequence (`src/apu/audio.cpp:53-58`): emitting a frame the guest did not
  ask for, or decoding a stream never handed over, is the fabrication F-609
  forbids. Policy mirror: `src/rage/rage_ideal_flow.h:32-35`.

## What exists

- **Framing complete** — `src/apu/xma_decoder.h`; context math mirrors Xenia
  (`kContextCount = 320` at `src/apu/xma_decoder.h:919`; pointer→index at
  `:952-957`; alloc/release at `:961-975`; worker minus MMIO kick at
  `:1024`). Seam declared for the bitstream backend (`SetFrameDecoder`,
  `:28-32`).
- **Bitstream parked by design** — `src/apu/xma_decoder.h:16-32`: Huffman/VLC
  + IMDCT/overlap-add lives in FFmpeg `xma2dec.c`, absent from this repo's
  checkout; with no decoder registered the layer reports `kNoBackend`,
  consumes nothing, writes nothing, never clears `output_buffer_valid`.
- **True silence** — 440 Hz blip GONE; underrun plays silence with one-line
  `AUDIO-UNDERRUN` warning (`src/apu/audio.cpp:60-62`). Worker runs on a real
  per-thread guest context (`src/apu/audio.cpp:63-64`).

## Gates

- `FATAL-SOFT=0`; soak length unchanged by audio (reference: 149.811 s run
  noted `src/apu/audio.cpp:37`).
- Bitstream work stays parked until a soak reaches menu AND names audio as
  the blocker (MENU-GATE, `src/rage/rage_ideal_flow.h:56-61`).
- Never a tone, never fake PCM (`src/rage/rage_ideal_flow.h:34-35`).
