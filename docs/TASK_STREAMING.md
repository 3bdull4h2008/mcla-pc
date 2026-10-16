# TASK_STREAMING — RPF / VFS / inflate (one doc, no split)

> Policy (`src/rage/rage_ideal_flow.h:24-26`): `vfs_rpf` + `rpf3_nested`
> serves outer + nested RPF, expanded spans, raw-deflate lists — on the boot
> path, kept. Guest owns bytes: every multi-byte guest read goes through
> `ReadU16BE`/`ReadU32BE` (`src/capture_hooks.cpp:453-457`); no
> reinterpret_cast on guest data.

## Layers

- **Outer + nested RPF** — `src/fs/vfs_rpf.cpp`, `src/fs/rpf3_nested.cpp`.
  On-disk TOC is AES; in-guest copy is hash-sorted cleartext — use
  `tools/rpf_offline.py` (`header`/`names`/`member`), never a raw-archve
  byte guess.
- **Expanded spans** — archive range `[off, off+logical)` served as a member
  (`src/gpu_device.cpp:3078`); substitution point at `:3132`; logged shape at
  `:3238` (`logical=`/`spanHead=`). Missing span ⇒ refuse + count, never
  synthesise bytes.
- **Inflate** — `src/raw_inflate.h`, `src/xmem_lzx.h`; host-full-decode knob
  `kPathBHostFullDecode` at `src/gpu_device.cpp:1265`. XCompress/LZX UI
  containers decode host-side; keep, do not bypass silently.
- **Drops** — `READAT-DROP` printer at `src/fs/vfs_rpf.cpp:2750`; budget note
  at `:2612`. A drop row must carry call/seen/path/off/req.

## Clamp arm (landed, log-only)

- `arFull` = original gate (`origRet == amIn6`); `arClamp` = T43.14 arm —
  both defined `src/gpu_device.cpp:20203-20230`, delivered at `:20230`
  (`if (arFull || arClamp)`), guest return unchanged.
- Probe `T4312-UNDELIVERED` at `src/gpu_device.cpp:20256`, printer `:20316`.
- Guard `T4311-LEN-GUARD` at `src/gpu_device.cpp:26065` (EOF−1→FFFFFFFF).
- Provenance: CityDefault EOF (F-786); producer ReadFileAt (F-788).

## Gates

Boot no longer fatals (`dstAfter=61786772`, `headIs=1`, `FATAL-SOFT=0`).
A streaming change passes only if the soak stays fatal-free AND the drop/
refusal rows move in the predicted direction. One new `build/w*.log` per
experiment; never stack short-circuits (do-not #9).
