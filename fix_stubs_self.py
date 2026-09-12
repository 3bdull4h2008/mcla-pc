#!/usr/bin/env python3
"""Round 2 of the stub cleanup: iterate SELF-spans to a fixed point.

The parent-extension strategy (fix_stubs_iter.py) stalled at 75 sites / 26
targets. Declaring each orphan as a function in its own right dropped that to
38 / 5, so this loop keeps applying that strategy until it converges.

Starts from the config that produced build/xr_self, which already accumulates
the 20 parent spans plus 26 self spans.
"""
import bisect
import collections
import os
import re
import shutil
import subprocess
import sys

ROOT = os.path.dirname(os.path.abspath(__file__))
TOOL = os.path.join(ROOT, ".research", "XenonRecomp", "build-clang",
                    "XenonRecomp", "XenonRecomp.exe")
HEADER = os.path.join(ROOT, "src", "ppc_context.h")
OUTDIR = os.path.join(ROOT, "build", "xr_self2")
STUB = re.compile(r"//\s*ERROR:?\s*(?:0x)?([0-9A-Fa-f]{8})")
MAPENT = re.compile(r"\s*\{ (0x[0-9A-Fa-f]+), sub_")
SPAN = re.compile(r"address = (0x[0-9A-Fa-f]+)")
MAX_ROUNDS = 8


def read(p):
    with open(p, encoding="utf8", errors="ignore") as f:
        return f.read()


def census(d):
    c = collections.Counter()
    for n in os.listdir(d):
        if n.startswith("ppc_recomp.") and n.endswith(".cpp"):
            for m in STUB.finditer(read(os.path.join(d, n))):
                c[int(m.group(1), 16)] += 1
    return c


def mapping_addrs(d):
    out = set()
    for line in read(os.path.join(d, "ppc_func_mapping.cpp")).splitlines():
        m = MAPENT.match(line)
        if m:
            out.add(int(m.group(1), 16))
    return sorted(out)


def declared(cfg_text):
    return {int(m.group(1), 16) for m in SPAN.finditer(cfg_text)}


def main():
    cfg = read(os.path.join(ROOT, "mcla_self_regen.toml"))
    cfg = cfg.replace("build/xr_self", "build/xr_self2")
    src = os.path.join(ROOT, "build", "xr_self")
    known = declared(cfg)
    prev = None

    for rnd in range(1, MAX_ROUNDS + 1):
        mps = mapping_addrs(src)
        c = census(src)
        total, distinct = sum(c.values()), len(c)
        print("round %d: %s -> %d sites, %d distinct: %s"
              % (rnd, os.path.basename(src), total, distinct,
                 " ".join("0x%08X(%d)" % (t, n) for t, n in c.most_common(8))),
              flush=True)
        if total == 0:
            print("CLEAN: zero stub sites.", flush=True)
            break
        if prev is not None and total >= prev:
            print("STALLED at %d sites." % total, flush=True)
            break
        prev = total

        # Self-span: declare the orphan as its own 2-instruction function, but
        # never run past the next known boundary.
        new = []
        for t in sorted(c):
            if t in known:
                continue
            j = bisect.bisect_right(mps, t)
            nxt = mps[j] if j < len(mps) else t + 8
            size = min(8, nxt - t) if nxt > t else 8
            new.append((t, size))
            known.add(t)
        if not new:
            print("STALLED: every remaining target is already declared.", flush=True)
            break
        print("  adding %d self-spans: %s"
              % (len(new), " ".join("0x%08X/0x%X" % ns for ns in new)), flush=True)

        cfg += ("\n\n# round %d self-spans\n" % rnd
                + "".join("\n[[main.functions]]\naddress = 0x%08X\nsize = 0x%X" % ns
                          for ns in new))
        work = os.path.join(ROOT, "mcla_self2_regen.toml")
        with open(work, "w", encoding="utf8", newline="\n") as f:
            f.write(cfg)

        if os.path.isdir(OUTDIR):
            shutil.rmtree(OUTDIR)
        os.makedirs(OUTDIR)
        r = subprocess.run([TOOL, os.path.basename(work), HEADER], cwd=ROOT,
                           capture_output=True, text=True)
        tus = len([n for n in os.listdir(OUTDIR)
                   if n.startswith("ppc_recomp.") and n.endswith(".cpp")])
        print("  tool exit=%d TUs=%d" % (r.returncode, tus), flush=True)
        if r.returncode != 0:
            print("TOOL FAILED:\n" + ((r.stdout or "") + (r.stderr or ""))[-1200:],
                  flush=True)
            break
        src = OUTDIR

    # Undefined-symbol check on the final output: a mapping entry with no body
    # in any TU breaks the link. Match DEFINITIONS only — call sites would make
    # this check falsely report clean.
    DEF = re.compile(r"(?:PPC_WEAK_FUNC\(sub_([0-9A-Fa-f]{8})\)"
                     r"|PPC_FUNC_IMPL\(__imp__sub_([0-9A-Fa-f]{8})\)"
                     r"|void sub_([0-9A-Fa-f]{8})\()")
    if os.path.isdir(src):
        mps = set(mapping_addrs(src))
        defined = set()
        for n in os.listdir(src):
            if n.startswith("ppc_recomp.") and n.endswith(".cpp"):
                for m in DEF.finditer(read(os.path.join(src, n))):
                    defined.add(int(next(g for g in m.groups() if g), 16))
        missing = sorted(mps - defined)
        print("FINAL %s: mapping=%d  entries with no body=%d %s"
              % (os.path.basename(src), len(mps), len(missing),
                 (" ".join("0x%08X" % m for m in missing[:8])) if missing else "(clean)"),
              flush=True)


if __name__ == "__main__":
    sys.exit(main())
