#!/usr/bin/env python3
"""Census every __builtin_debugtrap left in the generated recompiler output.

Why this exists
---------------
The XenonRecomp translator emits a bare host `int3` (``__builtin_debugtrap()``)
for any guest instruction it has no case for.  There is no handler, so the
first time the guest actually executes that instruction the process dies --
which is how most "mysterious crash" reports in this project start.  Nothing
in the tree counts them, so the number only ever goes up by accident.

This tool makes the number measurable with no build and no boot:

  * every ``__builtin_debugtrap`` in ``generated/ppc_xenon/`` is found,
  * attributed to the guest opcode by the ``// <mnemonic>`` comment the
    recompiler writes on the line above it,
  * grouped by opcode, then by ``file:line`` cluster,
  * cross-referenced against ``src/`` to say whether a host implementation of
    that opcode already exists (i.e. the trap is a *missing wiring* rather
    than a *missing implementation*).

Re-runnable: ``--json`` writes a snapshot, ``--baseline <snap.json>`` diffs a
fresh census against it so a later session can prove the count went down and
see exactly which sites were retired.

Exit codes
----------
  0  census produced (always informational)
  1  ``--fail-over N`` was given and the total is still > N
  2  bad arguments
"""

from __future__ import annotations

import argparse
import json
import os
import re
import sys
from collections import defaultdict

# Guest instruction families the translator can leave a trap for.  Anything not
# listed falls into "other" and is reported verbatim -- an unclassified trap is
# itself a finding, so it must never be silently bucketed away.
FAMILIES = (
    ("vmx128_pack", ("vpkd3d128", "vupkd3d128")),
    ("vmx128_cmp", ("vcmpbfp", "vcmpbep", "vcmpbgt", "vcmpbge", "vcmpsbfp")),
    ("vmx128_other", ("vsldoi", "vpermwi", "vmul", "vadd", "vsub", "vsel",
                      "vrl", "vcf", "vcts", "vctuxs", "vcfsx", "vlog",
                      "vmdh", "vmladduhm", "vmsum", "vavg", "vmax", "vmin",
                      "vmerge", "vsel", "vpk", "vupk", "vref", "vrsqrte",
                      "vsqrt", "vrec", "vctsxs", "vneg", "vabs", "vexptefp",
                      "vsl", "vsr", "vsplt", "vtab")),
    ("branch", ("blrl", "blr", "bctr", "bcctrl", "bnelrl", "bclrl", "bctrl")),
)


def family_of(mnemonic: str) -> str:
    """Classify a guest mnemonic.  Exact match first, then prefix."""
    m = mnemonic.split(".")[0]
    for name, prefixes in FAMILIES:
        for p in prefixes:
            if m == p or m.startswith(p):
                return name
    return "other"


# "// vupkd3d128 v63,v0,20"  -- the comment line the recompiler emits directly
# above every translated instruction.
COMMENT_RE = re.compile(r"^\s*//\s*([a-z][a-z0-9_.]*)\b")
TRAP_RE = re.compile(r"__builtin_debugtrap\s*\(\s*\)")

# A guest function body: PPC_FUNC_IMPL(__imp__sub_XXXXXXXX) { ... }
FUNC_RE = re.compile(r"PPC_FUNC_IMPL\s*\(\s*__imp__sub_([0-9A-Fa-f]+)\s*\)")


def census(gen_dir: str, src_dir: str):
    sites = []
    files = sorted(
        f for f in os.listdir(gen_dir)
        if f.endswith((".cpp", ".h", ".c"))
    )
    for fname in files:
        path = os.path.join(gen_dir, fname)
        with open(path, "r", encoding="utf-8", errors="replace") as fh:
            lines = fh.read().splitlines()
        cur_fn = None
        cur_mnemonic = None
        prev_was_comment = False
        for idx, line in enumerate(lines, 1):
            m = FUNC_RE.search(line)
            if m:
                cur_fn = m.group(1).upper()
            cm = COMMENT_RE.match(line)
            if cm:
                cur_mnemonic = cm.group(1)
            if TRAP_RE.search(line):
                prev = lines[idx - 2].strip() if idx >= 2 else ""
                sites.append(
                    {
                        "file": fname,
                        "line": idx,
                        "guest_fn": cur_fn,
                        "mnemonic": cur_mnemonic or "<unattributed>",
                        # True only when the mnemonic comment is the line
                        # immediately above the trap.  When it is False the
                        # attribution is inherited from further back and
                        # something else sits in between -- the signature of a
                        # midasm_hook trampoline (the recompiler emits
                        # `goto loc_<hook_target>;` and then the hooked
                        # instruction's body), which is a different failure
                        # mode from "this opcode has no case".
                        "mnemonic_adjacent": prev_was_comment,
                        "prev_line": prev,
                        "is_hook_trampoline": prev.startswith("goto "),
                        "text": line.strip(),
                        "comment": prev,
                    }
                )
            prev_was_comment = cm is not None

    # Host-implementation cross-reference: does src/ mention the mnemonic
    # outside of comments only?  We count *code* mentions by stripping
    # line comments first, so a file that merely documents the opcode in a
    # comment does not count as an implementation.
    src_text = []
    for root, _dirs, fnames in os.walk(src_dir):
        for f in fnames:
            if f.endswith((".cpp", ".h", ".c", ".hpp")):
                try:
                    with open(os.path.join(root, f), "r", encoding="utf-8",
                              errors="replace") as fh:
                        src_text.append(fh.read())
                except OSError:
                    pass
    blob = "\n".join(src_text)
    # strip // comments and /* */ blocks crudely but well enough for a mnemonic scan
    code_only = re.sub(r"/\*.*?\*/", " ", blob, flags=re.S)
    code_only = re.sub(r"//[^\n]*", " ", code_only)

    for s in sites:
        mn = s["mnemonic"].split(".")[0]
        if mn == "<unattributed>":
            s["host_impl"] = False
            s["host_symbol"] = None
        else:
            # The host implementation is usually NOT spelled with the guest
            # mnemonic: src/cpu/vmx128_pack.cpp exposes mcla_Vupkd3d128_type5,
            # not "vupkd3d128".  So match case-insensitively as a *substring* of
            # an identifier, which covers both spellings.
            hit = re.search(re.escape(mn), code_only, re.I)
            s["host_impl"] = bool(hit)
            s["host_symbol"] = hit.group(0) if hit else None
        s["family"] = family_of(mn if mn != "<unattributed>" else "")
        s["mode"] = pack_mode(s["comment"]) if s["family"] == "vmx128_pack" else None
    return sites


# The pack/unpack "type" is the last immediate of the instruction, e.g.
#   vupkd3d128 v63,v0,20   -> 20 >> 2 == 5   (Xenia PackType index)
#   vpkd3d128  v0,v62,8    ->  8 >> 2 == 2
def pack_mode(comment: str):
    m = re.search(r"\b(?:vpkd3d128|vupkd3d128)\s+(.+)$", comment)
    if not m:
        return None
    ops = [o.strip() for o in m.group(1).split(",")]
    if len(ops) < 3 or not re.fullmatch(r"\d+", ops[2]):
        return None
    imm = int(ops[2])
    return {"imm": imm, "type": imm >> 2}


def summarize(sites):
    by_op = defaultdict(list)
    for s in sites:
        by_op[(s["mnemonic"], s["family"], bool(s["host_impl"]))].append(s)

    by_file = defaultdict(int)
    for s in sites:
        by_file[s["file"]] += 1

    return by_op, by_file


def report(sites, out=sys.stdout):
    by_op, by_file = summarize(sites)
    w = out.write
    w("VMX128 / debugtrap CENSUS -- generated/ppc_xenon\n")
    w("=" * 78 + "\n")
    w(f"TOTAL __builtin_debugtrap sites: {len(sites)}\n")
    w(f"distinct translation units affected: {len(by_file)}\n\n")

    w("BY OPCODE CLASS (mnemonic / family / host impl in src/)\n")
    w("-" * 78 + "\n")
    for (mn, fam, impl), ss in sorted(by_op.items(), key=lambda kv: -len(kv[1])):
        w(f"  {len(ss):4d}  {mn:<22} family={fam:<14} host_impl={'YES' if impl else 'no '}\n")
    modes = defaultdict(list)
    for s in sites:
        if s["family"] == "vmx128_pack":
            key = (s["mnemonic"], s["mode"]["type"] if s["mode"] else "?",
                   s["mode"]["imm"] if s["mode"] else "?")
            modes[key].append(s)
    if modes:
        w("\nVMX128 PACK/UNPACK MODES  (Xenia PackType = imm >> 2)\n")
        w("-" * 78 + "\n")
        for (mn, typ, imm), ss in sorted(modes.items(), key=lambda kv: -len(kv[1])):
            impl = any(x["host_impl"] for x in ss)
            locs = sorted({f"{x['file']}:{x['line']}" for x in ss})
            head = ", ".join(locs[:3]) + (f" (+{len(locs) - 3} more)" if len(locs) > 3 else "")
            w(f"  {len(ss):4d}  {mn} type={typ} (imm={imm})  host_impl={'YES' if impl else 'no '}\n")
            w(f"        {head}\n")
    w("\nBY TRANSLATION UNIT\n")
    w("-" * 78 + "\n")
    for f, c in sorted(by_file.items(), key=lambda kv: -kv[1]):
        w(f"  {c:4d}  {f}\n")
    w("\nfile:line CLUSTERS (consecutive traps grouped)\n")
    w("-" * 78 + "\n")
    per_file = defaultdict(list)
    for s in sites:
        per_file[s["file"]].append(s)
    for f in sorted(per_file):
        ss = sorted(per_file[f], key=lambda s: s["line"])
        clusters = []
        cur = [ss[0]]
        for prev, nxt in zip(ss, ss[1:]):
            if nxt["line"] - prev["line"] <= 6:
                cur.append(nxt)
            else:
                clusters.append(cur)
                cur = [nxt]
        clusters.append(cur)
        for c in clusters:
            rng = f"{c[0]['line']}" if len(c) == 1 else f"{c[0]['line']}-{c[-1]['line']}"
            mn = sorted({s["mnemonic"] for s in c})
            w(f"  {f}:{rng}  n={len(c)}  {','.join(mn)}\n")
    w("\nUNATTRIBUTED (no // mnemonic comment found above)\n")
    w("-" * 78 + "\n")
    un = [s for s in sites if s["mnemonic"] == "<unattributed>"]
    w(f"  {len(un)} site(s)\n")
    for s in un[:20]:
        w(f"    {s['file']}:{s['line']}\n")
    w("\nHOST-IMPL-PRESENT BUT STILL TRAPPED (wiring gap, not a missing impl)\n")
    w("-" * 78 + "\n")
    gap = [s for s in sites if s["host_impl"]]
    miss = [s for s in sites if not s["host_impl"]]
    w(f"  {len(gap)} of {len(sites)} site(s) are for an opcode src/ already\n")
    w("  implements (matched case-insensitively as an identifier substring, e.g.\n")
    w("  src/cpu/vmx128_pack.cpp's mcla_Vupkd3d128_type5).  Those are wiring\n")
    w("  gaps -- the translator still needs a case that calls the host impl --\n")
    w("  not missing functionality, so they are the cheap ones to retire.\n")
    w(f"  {len(miss)} site(s) have NO host implementation at all:\n")
    for s in miss[:20]:
        w(f"    {s['file']}:{s['line']}  {s['comment']}\n")
    hook = [s for s in sites if s["is_hook_trampoline"]]
    stale = [s for s in sites if not s["mnemonic_adjacent"]]
    w("\nmnemonic NOT adjacent (attribution inherited from an earlier line)\n")
    w("-" * 78 + "\n")
    w(f"  {len(stale)} site(s); of those, {len(hook)} sit immediately after a\n")
    w("  `goto loc_...`, i.e. they are midasm_hook trampolines from\n")
    w("  config/mcla_xenonrecomp.toml, not bare 'opcode has no case' traps.\n")
    for s in stale:
        w(f"    {s['file']}:{s['line']}  {s['mnemonic']:<14} prev={s['prev_line'][:48]!r}\n")


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    here = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    ap.add_argument("--gen-dir", default=os.path.join(here, "generated", "ppc_xenon"))
    ap.add_argument("--src-dir", default=os.path.join(here, "src"))
    ap.add_argument("--json", help="write a machine-readable snapshot here")
    ap.add_argument("--baseline", help="diff against a previous --json snapshot")
    ap.add_argument("--fail-over", type=int,
                    help="exit 1 if the total trap count is still above this")
    args = ap.parse_args(argv)

    if not os.path.isdir(args.gen_dir):
        print(f"trap_census: no such dir: {args.gen_dir}", file=sys.stderr)
        return 2

    sites = census(args.gen_dir, args.src_dir)
    report(sites)

    by_op, by_file = summarize(sites)
    snap = {
        "total": len(sites),
        "files": len(by_file),
        "by_opcode": {
            f"{mn}|{fam}": {"count": len(ss), "host_impl": impl}
            for (mn, fam, impl), ss in by_op.items()
        },
        "by_file": dict(by_file),
        "sites": [{k: s[k] for k in ("file", "line", "guest_fn", "mnemonic",
                                     "family", "host_impl", "mode",
                                     "mnemonic_adjacent", "is_hook_trampoline")}
                  for s in sites],
    }

    if args.json:
        with open(args.json, "w", encoding="utf-8") as fh:
            json.dump(snap, fh, indent=1, sort_keys=True)
        print(f"\nsnapshot written: {args.json}")

    rc = 0
    if args.baseline:
        try:
            with open(args.baseline, "r", encoding="utf-8") as fh:
                base = json.load(fh)
        except OSError as e:
            print(f"trap_census: cannot read baseline {args.baseline}: {e}",
                  file=sys.stderr)
            return 2
        print("\nBASELINE DIFF")
        print("-" * 78)
        b, n = base.get("total", 0), snap["total"]
        print(f"  total: {b} -> {n}  ({n - b:+d})")
        bkeys = base.get("by_opcode", {})
        nkeys = snap["by_opcode"]
        for k in sorted(set(bkeys) | set(nkeys)):
            ov = bkeys.get(k, {}).get("count", 0)
            nv = nkeys.get(k, {}).get("count", 0)
            if ov != nv:
                print(f"  {k}: {ov} -> {nv} ({nv - ov:+d})")
        if n == b:
            print("  NO CHANGE")
        print(f"  RESULT: {'IMPROVED' if n < b else ('REGRESSED' if n > b else 'SAME')}")

    if args.fail_over is not None and len(sites) > args.fail_over:
        print(f"\ntrap_census: FAIL total={len(sites)} > --fail-over={args.fail_over}")
        rc = 1
    return rc


if __name__ == "__main__":
    sys.exit(main())
