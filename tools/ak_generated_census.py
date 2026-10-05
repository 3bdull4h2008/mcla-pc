#!/usr/bin/env python3
"""AK-session census of generated/** -- COUNT + BYTES + CONTENT HASH.

Read-only. NOTHING under generated/ is written, and this script opens every file
read-only.

GLOB -- MEASURED, and the first attempt was WRONG. The recursive
`generated/**/*.cpp` glob yields 419 files / 394,049,919 B, which does NOT
reproduce the figures quoted in the session brief (177 / 131,656,770 B). The
non-recursive glob `generated/ppc_xenon/*.cpp` reproduces them EXACTLY:

    generated/ppc_xenon/*.cpp          177 files  131,656,770 B   <- brief matches
      minus ppc_func_mapping.cpp        176 files  130,206,972 B   <- brief matches
    generated/ppc/*.cpp                180 files  131,220,962 B
    generated/default/*.cpp             62 files  131,172,187 B
    177 + 180 + 62 = 419 = the recursive count, so the three are the same set.

Both globs are reported here so the number is never quoted without its glob.
The hash is SHA-256 over the files' bytes in sorted-relpath order, each
preceded by its relpath and length, so the digest pins BOTH content and list.

Usage:  python tools/ak_generated_census.py
Exit:   0 always (this is a census, not a gate).
"""
import hashlib
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GEN = os.path.join(ROOT, "generated")
EXCLUDE = {"ppc_func_mapping.cpp"}

PRIMARY = os.path.join(GEN, "ppc_xenon")   # the glob that reproduces the brief


def census(base, keep, recursive):
    files = []
    if recursive:
        for dirpath, dirnames, filenames in os.walk(base):
            dirnames.sort()
            for fn in sorted(filenames):
                if fn.endswith(".cpp"):
                    files.append(os.path.join(dirpath, fn))
    else:
        for fn in sorted(os.listdir(base)):
            p = os.path.join(base, fn)
            if fn.endswith(".cpp") and os.path.isfile(p):
                files.append(p)
    rels = []
    for p in files:
        rel = os.path.relpath(p, GEN).replace("\\", "/")
        if keep(rel):
            rels.append(rel)
    rels.sort()
    h = hashlib.sha256()
    total = 0
    unreadable = 0
    # BUG FIXED 2026-10-05: this loop iterated `files` (the UNFILTERED list), so
    # keep() had no effect and the EXCLUDING variant silently hashed and counted
    # the same 177 files as the INCLUDING one. It must iterate `rels`.
    for rel in rels:
        p = os.path.join(GEN, rel.replace("/", os.sep))
        try:
            with open(p, "rb") as f:
                b = f.read()
        except OSError as e:
            unreadable += 1
            print("UNREADABLE %s : %s" % (rel, e))
            b = b""
        total += len(b)
        h.update(rel.encode("utf-8"))
        h.update(b"\x00")
        h.update(str(len(b)).encode("ascii"))
        h.update(b"\x00")
        h.update(b)
    return rels, total, h.hexdigest(), unreadable


def main():
    pm_rel = "ppc_xenon/ppc_func_mapping.cpp"
    print("=== PRIMARY GLOB: generated/ppc_xenon/*.cpp  (NON-recursive) ===")
    print("    this is the glob that reproduces the session brief's figures")
    for label, keep in (
        ("EXCLUDING ppc_func_mapping.cpp", lambda r: os.path.basename(r) not in EXCLUDE),
        ("INCLUDING ppc_func_mapping.cpp", lambda r: True),
    ):
        files, total, dig, unread = census(PRIMARY, keep, recursive=False)
        print("  variant      = %s" % label)
        print("  files        = %d" % len(files))
        print("  bytes        = %d" % total)
        print("  sha256       = %s" % dig)
        print("  unreadable   = %d" % unread)
    pm = os.path.join(ROOT, "generated", pm_rel)
    if os.path.exists(pm):
        with open(pm, "rb") as f:
            b = f.read()
        print("  %s bytes = %d  sha256 = %s"
              % (pm_rel, len(b), hashlib.sha256(b).hexdigest()))
    print("")

    print("=== SECONDARY GLOB: generated/**/*.cpp  (RECURSIVE) ===")
    print("    reported so the 419-file figure is never quoted without its glob")
    for sub in ("ppc_xenon", "ppc", "default"):
        files, total, dig, unread = census(
            os.path.join(GEN, sub), lambda r: True, recursive=False)
        print("  generated/%-10s files = %-4d bytes = %-12d sha256 = %s"
              % (sub + "/*.cpp", len(files), total, dig))
    files, total, dig, unread = census(GEN, lambda r: True, recursive=True)
    print("  generated/**/*.cpp     files = %-4d bytes = %-12d sha256 = %s"
          % (len(files), total, dig))
    return 0


if __name__ == "__main__":
    sys.exit(main())
