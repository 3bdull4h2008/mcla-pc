#!/usr/bin/env python3
"""Resolve a host runtime address / RVA to a link-map symbol.

Log inputs: VEH `rva=` (src/boot_host.cpp:1085,1393) and `??? 0x<raw>` stack frames (:1469),
PARK-SAMPLE `base=`/`rawrip=` (:2028/:2147), PARK-UNWIND module RVAs (:2174), and the
absolute `rip owner=host 0x...` (:1400) -- host addrs our guest-name helpers cannot map.
This build links /MAP but no PDB (CMakeLists.txt:405-410), so NearestFunctionName's dbghelp
probe (:934) misses it and its nearest-preceding guest-map scan (:945) misnames host code.

  python tools/host_rva_resolve.py build/mcla.map --base 0x7ff6ad800000 0x337BCF0 0x7ff6ae05dbf9

Hex needs 0x (bare = DECIMAL). v >= --base (the arg after the map path, that log's PARK-
SAMPLE base=) is runtime: (v - base) + pref; v < 0x10000000 is an rva: v + pref; larger as-is.
"""
import bisect
import re
import sys


def load(path):
    pref = 0
    syms = []
    in_pub = False
    row = re.compile(r"^\s*([0-9A-Fa-f]{4}):([0-9A-Fa-f]{8})\s+(\S+)\s+([0-9A-Fa-f]{16})")
    with open(path, "r", errors="replace") as fh:
        for line in fh:
            if line.startswith(" Preferred load address"):
                pref = int(line.split()[-1], 16)
            elif "Publics by Value" in line:
                in_pub = True  # header row; cols Address|Publics by Value|Rva+Base|Lib:Object -- group 4 = pref + rva
                continue
            elif in_pub and line.strip() and not line[0].isspace():
                break  # left-margin guard; rows in build/mcla.map are all indented -- table runs to EOF, never fires
            elif in_pub:
                m = row.match(line)
                if m:
                    syms.append((int(m.group(4), 16), m.group(3)))
    syms = [s for s in syms if s[0]]
    syms.sort()
    return pref, [s[0] for s in syms], [s[1] for s in syms]


def main():
    args = sys.argv[1:]
    if not args:
        sys.exit(__doc__)
    path = args.pop(0)
    base = 0
    if args[:1] == ["--base"]:
        base = int(args[1], 16)
        args = args[2:]
    pref, vas, names = load(path)
    print(f"{len(vas)} public symbols, preferred base {pref:#x}")
    for raw in args:
        v = int(raw, 16) if raw.lower().startswith("0x") else int(raw)
        kind = "abs"
        if base and v >= base:
            v = pref + (v - base)
            kind = f"runtime(-base+pref)"
        elif v < 0x10000000:
            v = pref + v
        i = bisect.bisect_right(vas, v) - 1
        if i < 0:
            print(f"  {raw}: {kind} -> below first symbol")
            continue
        print(f"  {raw}: -> {names[i]} +{v - vas[i]:#x}")


if __name__ == "__main__":
    main()
