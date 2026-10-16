#!/usr/bin/env python3
"""Self-review for working-tree changes. No approval needed to run.
Usage: python tools/self_review.py [--log build/w766.log]

Checks (each prints PASS/FAIL/WARN with evidence):
 1. Forbidden files untouched vs HEAD (rule 2).
 2. Changed src files count (rule 1a N-way) + new static/extern taint (rule 1b).
 3. Stale-exe trap: mcla.exe newer than every changed src file (rule 12).
 4. New headers referenced (untracked .h must be #included somewhere).
 5. Log gates on --log: no cannot-load-archive, no FATAL-SOFT/Fatal error,
    VFS indexed, boot reached guest (THREAD-CREATE>0).
Exit 0 = all PASS (WARNs allowed), 1 = any FAIL.
"""
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
FORBIDDEN = [
    'generated/', '.research/', 'config/mcla_xenonrecomp.toml',
    'src/ppc_context.h', 'src/ppc_config.h', 'src/dispatch_guard.cpp',
]

results = []


def verdict(name, ok, detail):
    results.append(ok)
    print(('PASS ' if ok == 'PASS' else 'FAIL ' if ok == 'FAIL' else 'WARN ') + name + ' :: ' + detail)


def git(*args):
    # MinGit first (known good, no UAC); plain `git` only as fallback.
    # A candidate counts only on returncode 0 with decodable output.
    cands = [[os.path.join(os.environ.get('TEMP', ''), 'mingit', 'cmd', 'git.exe')] + list(args),
             ['git'] + list(args)]
    for c in cands:
        try:
            r = subprocess.run(c, cwd=ROOT, capture_output=True, timeout=60)
            if r.returncode != 0:
                continue
            try:
                r.stdout.decode('utf-8', errors='strict')
            except UnicodeDecodeError:
                continue
            r.stdout = r.stdout.decode('utf-8', errors='replace')
            return r
        except (OSError, subprocess.SubprocessError):
            continue
    return None


def main():
    logpath = None
    if '--log' in sys.argv:
        logpath = sys.argv[sys.argv.index('--log') + 1]

    st = git('status', '--short')
    if st is None:
        verdict('git-available', 'FAIL', 'no git binary (tried PATH + MinGit)')
        changed, untracked = [], []
    else:
        changed, untracked = [], []
        for ln in st.stdout.splitlines():
            if len(ln) < 4:
                continue
            code, path = ln[:2].strip(), ln[2:].strip().strip('"')
            (untracked if code == '??' else changed).append(path)
    verdict('tree-read', 'PASS', '%d changed, %d untracked' % (len(changed), len(untracked)))

    hits = [p for p in changed for f in FORBIDDEN if p == f or p.startswith(f)]
    verdict('forbidden-clean', 'FAIL' if hits else 'PASS',
            'touched: %s' % hits if hits else 'none of %d forbidden paths in %d changed' % (len(FORBIDDEN), len(changed)))

    src_changed = sorted(p for p in changed if p.startswith('src/') and p.endswith(('.cpp', '.h', '.c')))
    verdict('bisect-scope', 'WARN' if len(src_changed) != 1 else 'PASS',
            '%d src files: %s (rule 1a: attribution %s)' % (
                len(src_changed), src_changed,
                'SINGLE-VARIABLE' if len(src_changed) == 1 else 'N-WAY provisional'))

    taint = []
    d = git('diff', 'HEAD', '--', 'src/')
    dtext = d.stdout if d is not None else ''
    if d is None:
        verdict('diff-readable', 'FAIL', 'git diff failed; taint unchecked')
    else:
        for ln in dtext.splitlines():
            if ln.startswith('+') and not ln.startswith('+++'):
                code = ln[1:].strip()
                if code.startswith('//') or code.startswith('*'):
                    continue  # comment text, not a symbol
                if re.search(r'\b(static|extern)\b', ln):
                    taint.append(ln[:100])
    verdict('new-symbol-taint', 'WARN' if taint else 'PASS',
            '%d new static/extern lines (rule 1b provisional until revert): %s' % (len(taint), taint[:5]))

    # T43.18 (2026-10-13, standing user rule): no NEW hardcoded guest
    # addresses. Added lines with 8-digit 0x8/0x9/0xA/0xC/0xE/0x4 literals
    # are guest VAs or physical views; each must be measured (raw bytes)
    # or resolved (mapping/symbol), never typed from memory. WARN lists
    # them for justification; pre-existing lines are grandfathered (diff
    # only). Comment lines skipped.
    hardaddr = []
    if d is not None:
        for ln in dtext.splitlines():
            if ln.startswith('+') and not ln.startswith('+++'):
                code = ln[1:].strip()
                if code.startswith('//') or code.startswith('*'):
                    continue
                m = re.findall(r'\b0x[984ACEace][0-9A-Fa-f]{7}\b', code)
                if m:
                    hardaddr.append((m, ln[:110]))
    verdict('hardcoded-guest-addr', 'WARN' if hardaddr else 'PASS',
            '%d added guest-range literals (justify each: measured or resolved): %s' % (len(hardaddr), hardaddr[:6]))

    new_headers = [p for p in untracked if p.startswith('src/') and p.endswith('.h')]
    orphan = []
    for h in new_headers:
        base = os.path.basename(h)
        found = False
        for dp, _, fns in os.walk(os.path.join(ROOT, 'src')):
            for fn in fns:
                if not fn.endswith(('.cpp', '.h')):
                    continue
                fp = os.path.join(dp, fn)
                if os.path.abspath(fp) == os.path.abspath(os.path.join(ROOT, h)):
                    continue
                try:
                    with open(fp, encoding='utf-8', errors='replace') as f:
                        if base in f.read():
                            found = True
                            break
                except OSError:
                    pass
            if found:
                break
        if not found:
            orphan.append(h)
    verdict('headers-referenced', 'FAIL' if orphan else 'PASS',
            'unreferenced new headers: %s' % orphan if orphan else 'all %d new headers #included' % len(new_headers))

    exe = os.path.join(ROOT, 'build', 'mcla.exe')
    if not os.path.exists(exe):
        verdict('exe-exists', 'FAIL', 'build/mcla.exe missing')
    else:
        # T43.18: a changed src file with no .obj under build/CMakeFiles is
        # not compiled into any target (e.g. src/rage/*, absent from
        # CMakeLists add_executable) -- it cannot stale the exe. Verified
        # 2026-10-13 the hard way: ninja correctly did "no work to do".
        import glob as _glob
        unbuilt = []
        for p in changed:
            if p.startswith('src/') and p.endswith(('.cpp', '.c')):
                # CMake obj names keep the source suffix: foo.cpp.obj.
                obj = os.path.basename(p) + '.obj'
                if not _glob.glob(os.path.join(ROOT, 'build', 'CMakeFiles', '**', obj), recursive=True):
                    unbuilt.append(p)
        exe_mt = os.path.getmtime(exe)
        stale = []
        for p in changed:
            fp = os.path.join(ROOT, p)
            if p not in unbuilt and os.path.isfile(fp) and os.path.getmtime(fp) > exe_mt:
                stale.append(p)
        if unbuilt:
            verdict('unbuilt-files', 'WARN', 'not compiled into any target (cannot stale exe): %s' % unbuilt)
        verdict('exe-fresh', 'FAIL' if stale else 'PASS',
                'src newer than exe (STALE BUILD): %s' % stale if stale else 'exe newer than all %d built changed files' % (len(changed) - len(unbuilt)))

    if logpath:
        lp = logpath if os.path.isabs(logpath) else os.path.join(ROOT, logpath)
        try:
            with open(lp, 'rb') as f:
                raw = f.read().lower()
            gates = {
                'no-cannot-load-archive': raw.count(b'cannot load archive') == 0,
                'no-fatal-soft': len(re.findall(rb'\] fatal-soft:', raw)) == 0,
                'no-fatal-error': len(re.findall(rb'\] fatal error', raw)) == 0,
                'vfs-indexed': raw.count(b'vfs: indexed') >= 1,
                'guest-reached': raw.count(b'thread-create') >= 1,
            }
            for g, ok in gates.items():
                verdict('log-' + g, 'PASS' if ok else 'FAIL', logpath)
        except OSError:
            verdict('log-readable', 'FAIL', logpath + ' missing')

    print('RESULT: %s' % ('FAIL' if 'FAIL' in [r for r in results] else 'OK'))
    return 1 if 'FAIL' in results else 0


if __name__ == '__main__':
    sys.exit(main())
