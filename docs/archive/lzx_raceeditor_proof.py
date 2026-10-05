#!/usr/bin/env python3
"""Offline LZX proof for raceeditor.xsf at xarchive_cache.rpf+0x64CB0000.

Tries three host-decode strategies against XC frames and reports produced size:
  1) concat payloads, one LZX stream (reset_interval=0)
  2) per-frame fresh lzxd
  3) shared LZX state across frames (reset_interval=1 = reset each 32KiB frame)

Goal: produced == 143069.
"""
from __future__ import annotations

import os
import struct
import sys
import traceback

ARCHIVE = r"E:\mcla pc\build\game_data\xarchive_cache.rpf"
OFF = 0x64CB0000
WANT = 143069
WINDOW_BITS = 17
RSC5 = 0x05435352
XCOMP = 0x0FF512EF


def be32(b: bytes, i: int) -> int:
    return struct.unpack(">I", b[i : i + 4])[0]


def parse_package(pkg: bytes):
    if len(pkg) < 24:
        raise ValueError("pkg too small")
    w0 = be32(pkg, 0)
    if w0 == RSC5:
        if be32(pkg, 12) != XCOMP:
            raise ValueError("RSC5 but no XCompress magic at +12")
        payload_off = 20
        want_out = be32(pkg, 16)
    elif w0 == XCOMP:
        payload_off = 8
        want_out = be32(pkg, 4)
    else:
        raise ValueError(f"bad magic {w0:#x}")
    frames = []
    src = payload_off
    while src + 2 <= len(pkg) and len(frames) < 512:
        hb = pkg[src]
        if hb == 0xFF:
            if src + 5 > len(pkg):
                break
            hdr = 5
            uncomp = (pkg[src + 1] << 8) | pkg[src + 2]
            pay = (pkg[src + 3] << 8) | pkg[src + 4]
        else:
            hdr = 2
            uncomp = 0x8000
            pay = (pkg[src] << 8) | pkg[src + 1]
        if pay == 0 or src + hdr + pay > len(pkg):
            break
        frames.append(
            {
                "off": src,
                "hdr": hdr,
                "uncomp": uncomp,
                "pay": pkg[src + hdr : src + hdr + pay],
            }
        )
        src += hdr + pay
    return want_out, frames


class MemFile:
    def __init__(self, buf: bytes):
        self.buf = buf
        self.pos = 0

    def read(self, n: int) -> bytes:
        got = self.buf[self.pos : self.pos + n]
        self.pos += len(got)
        return got


def try_libmspack(frames, want_out: int):
    """Compile-at-runtime is heavy; use the C helper if present, else pure python."""
    return None


def lzx_decompress_stream(src: bytes, want_out: int, reset_interval: int = 0):
    """libmspack-compatible LZX via the 360tools decoder if usable, else mspack dll."""
    # Prefer local pure-python LZX (same family as XMem LZX).
    tools = r"E:\mcla pc\.research\360tools\tools"
    if tools not in sys.path:
        sys.path.insert(0, tools)
    try:
        from lzx_decompress import LZXDecoder  # type: ignore
    except Exception as e:
        return None, f"import LZXDecoder failed: {e}"

    # 360tools LZXDecoder is single-stream; for multi-frame we either concat
    # or feed sequentially depending on strategy. The class API:
    #   dec = LZXDecoder(window_bits=17)
    #   out = dec.decompress(src, out_size)  -- may vary; probe below.
    try:
        dec = LZXDecoder(window_bits=WINDOW_BITS)
    except Exception as e:
        return None, f"LZXDecoder init failed: {e}"

    # Probe method names across revisions.
    for meth in ("decompress", "decompress_bytes", "decode", "decode_block"):
        fn = getattr(dec, meth, None)
        if fn is None:
            continue
        try:
            # common signature: decompress(data) -> bytes
            out = fn(src)
            if isinstance(out, (bytes, bytearray)):
                return bytes(out), meth
            if isinstance(out, tuple) and out and isinstance(out[0], (bytes, bytearray)):
                return bytes(out[0]), meth
        except TypeError:
            try:
                out = fn(src, want_out)
                if isinstance(out, (bytes, bytearray)):
                    return bytes(out), meth
            except Exception as e2:
                last = e2
        except Exception as e:
            last = e
    return None, f"no usable LZXDecoder method ({getattr(sys.modules.get('lzx_decompress'), '__file__', '?')})"


def try_mspack_c(src_frames, want_out: int, mode: str):
    """Call the offline C proof binary if built."""
    exe = r"E:\mcla pc\build\lzx_raceeditor_proof.exe"
    if not os.path.isfile(exe):
        return None, "c proof exe missing"
    import subprocess

    r = subprocess.run([exe, mode], capture_output=True, text=True, timeout=30)
    return r.stdout, f"rc={r.returncode} {r.stderr[:200]}"


def hex16(b: bytes) -> str:
    return b[:16].hex(" ")


def main() -> int:
    with open(ARCHIVE, "rb") as f:
        f.seek(OFF)
        pkg = f.read(4 * 1024 * 1024)
    print(f"read {len(pkg)} bytes at {OFF:#x}")
    print(f"head: {pkg[:32].hex(' ')}")
    print(
        "BE words:",
        " ".join(f"{be32(pkg, i):08X}" for i in range(0, 32, 4)),
    )
    want_out, frames = parse_package(pkg)
    print(f"wantOut={want_out} frames={len(frames)} total_pay={sum(len(fr['pay']) for fr in frames)} total_uncomp_hdr={sum(fr['uncomp'] for fr in frames)}")
    for i, fr in enumerate(frames[:8]):
        print(
            f"  f{i}: off={fr['off']:#x} hdr={fr['hdr']} uncomp={fr['uncomp']} pay={len(fr['pay'])} pay16={hex16(fr['pay'])}"
        )

    # --- Strategy 1: concat payloads, one LZX stream ---
    concat = b"".join(fr["pay"] for fr in frames)
    out1, how1 = lzx_decompress_stream(concat, want_out, reset_interval=0)
    print(f"\n[1] concat+one-lzxd: produced={len(out1) if out1 else 0} via={how1}")
    if out1:
        print(f"    first16={hex16(out1)} match={len(out1)==want_out}")

    # --- Strategy 2: per-frame fresh decoder ---
    # For pure-python single-stream, emulate fresh by decoding each payload alone
    # and appending the first uncomp bytes (or full decode).
    parts = []
    notes = []
    for i, fr in enumerate(frames):
        o, how = lzx_decompress_stream(fr["pay"], fr["uncomp"], reset_interval=0)
        if not o:
            notes.append(f"f{i} FAIL {how}")
            break
        # take min(uncomp, len) as this frame's chunk
        chunk = o[: fr["uncomp"]]
        parts.append(chunk)
        notes.append(f"f{i} -> {len(chunk)}")
        if len(parts) >= 3 and i == 0:
            # still try all frames
            pass
    out2 = b"".join(parts) if parts else b""
    print(f"\n[2] per-frame fresh: produced={len(out2)} notes={notes}")
    if out2:
        print(f"    first16={hex16(out2)} match={len(out2)==want_out}")

    # --- Strategy 3: shared state (reset each 32KiB frame) ---
    # Pure-python LZXDecoder may support incremental decompress; try feeding
    # concatenated with reset_interval semantics by decoding whole stream once
    # (same as 1) if the decoder has no incremental API.
    # Prefer the C proof for true shared-state.
    out3, how3 = lzx_decompress_stream(concat, want_out, reset_interval=1)
    # If the python decoder has decompress_incremental / feed, use it.
    tools = r"E:\mcla pc\.research\360tools\tools"
    if tools not in sys.path:
        sys.path.insert(0, tools)
    try:
        from lzx_decompress import LZXDecoder

        dec = LZXDecoder(window_bits=WINDOW_BITS)
        feed = getattr(dec, "feed", None) or getattr(dec, "decompress_incremental", None)
        if feed is not None:
            acc = bytearray()
            for fr in frames:
                chunk = feed(fr["pay"])
                if chunk:
                    acc.extend(chunk)
            out3 = bytes(acc)
            how3 = "feed-per-frame"
    except Exception as e:
        how3 = f"{how3} (no incremental: {e})"
    print(f"\n[3] shared-state: produced={len(out3) if out3 else 0} via={how3}")
    if out3:
        print(f"    first16={hex16(out3)} match={len(out3)==want_out}")

    # C helper result if any
    for mode in ("concat", "perframe", "shared"):
        out, meta = try_mspack_c(frames, want_out, mode)
        if out:
            print(f"\n[C:{mode}] {meta}\n{out}")

    return 0


if __name__ == "__main__":
    try:
        sys.exit(main())
    except Exception:
        traceback.print_exc()
        sys.exit(1)
