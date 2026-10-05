#!/usr/bin/env python3
"""AK: fmt-arity + literal-text checker for the two new WINWR census rows.

Read-only. Extracts the format string and the argument list of a named
MCLA_LOG_* call out of src/gpu_device.cpp and checks:

  1. ARITY. fmt's `error: call to consteval function` is a HARD error when the
     argument count is SHORT; EXTRA arguments compile clean and are silently
     dropped, which would quietly print a wrong row. Both directions matter,
     so both are reported.
  2. LITERAL BRACES. A bare `{` or `}` in the literal is a placeholder; it must
     be `{{` / `}}`. Counted by comparing placeholder count to brace count.
  3. TRACKED-MARKER COLLISION. An UPPERCASE token of >=4 chars inside the
     literal TEXT of one row can be another marker's name, and a tracked marker
     named inside another marker's prose makes that other marker uncountable by
     line. Listed so the caller can eyeball it.

Usage:  python tools/ak_fmt_arity.py WINWR-WATCH WINWR-REC
Exit:   1 if any arity or brace problem, else 0.
"""
import re
import sys

PATH = "src/gpu_device.cpp"


def load():
    with open(PATH, encoding="utf-8") as f:
        return f.read()


def check(src, name):
    # Anchor on the FORMAT LITERAL itself, not on the bare name: the name also
    # occurs in this file's prose comments, and the first hit is one of those.
    needle = '"' + name
    i = src.index(needle)
    j = src.index(");", i)
    seg = src[i:j]
    # drop comment-only lines: they are not part of the format
    seg = "\n".join(l for l in seg.split("\n") if not l.strip().startswith("//"))
    lits = re.findall(r'"((?:[^"\\]|\\.)*)"', seg)
    fmt = "".join(lits)
    ph = re.findall(r"\{[^{}]*\}", fmt)
    total_open = fmt.count("{")
    total_close = fmt.count("}")
    k = seg.rindex('"')
    rest = seg[k + 1:].strip()
    args = [a.strip() for a in rest.split(",") if a.strip()]
    words = sorted(set(re.findall(r"[A-Z][A-Z0-9-]{3,}", fmt)))

    ok_arity = len(ph) == len(args)
    ok_braces = total_open == len(ph) and total_close == len(ph)
    print("--- %s ---" % name)
    print("  format        = %s" % fmt)
    print("  placeholders  = %d" % len(ph))
    print("  arguments     = %d" % len(args))
    print("  ARITY         = %s" % ("OK" if ok_arity else "*** MISMATCH ***"))
    print("  braces {}=%d/%d  = %s" % (total_open, total_close,
                                       "OK" if ok_braces else "*** UNESCAPED ***"))
    print("  uppercase tokens in literal text: %s" % (words if words else "none"))
    if not ok_arity:
        print("  placeholders list: %s" % ph)
        print("  args list       : %s" % args)
    return ok_arity and ok_braces


def main():
    src = load()
    names = sys.argv[1:] or ["WINWR-WATCH", "WINWR-REC"]
    bad = 0
    for n in names:
        needle = '"' + n
        if needle not in src:
            print("--- %s --- no format literal found in %s" % (name, PATH))
            bad += 1
            continue
        if not check(src, n):
            bad += 1
        print("")
    print("VERDICT = %s" % ("OK" if bad == 0 else "FAIL (%d)" % bad))
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
