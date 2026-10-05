"""x64dbg MCP bridge — scripted headless debugging for AI agents.

Runs the x64dbg `headless.exe` console debugger (NOT the GUI) with an
agent-supplied script and returns the session log. Two modes:

- launch: start a target exe under the debugger, run a script, exit when
  the debuggee exits or the timeout fires. Safe and unattended.
- attach: attach to a RUNNING pid. This FREEZES all threads of the target
  while attached and perturbs timing-sensitive behaviour (see F-594: the
  boot stall is a timing creature). Requires confirm_live=true, and must
  never be used on mcla.exe while a soak log is younger than ~2 min
  (rule 11). Preferred use: inspect a PARKED process, read-only.

Typical script shape (x64dbg script language, one command per line):
    bp 0x140001000          ; software breakpoint (use image-base-relative VA)
    bphw addr               ; hardware breakpoint
    run                     ; run until breakpoint/exit
    log {reg}               ; log works inside breakpoint commands too
The `log <text>` output is what comes back. Keep scripts small: every
hit prints, and an unbounded hot breakpoint becomes a log flood (F-054).

Headless CLI reference (from headless.exe -help):
  headless.exe {OPTIONS} [filename] -- [extra args]
  -cf <script>  run script file at startup
  -c <command>  single initial command
  -pid <pid>    attach instead of launch
  -testing      one-shot mode (exit when session ends)
"""

from __future__ import annotations

import os
import subprocess
import sys
import tempfile

from mcp.server.fastmcp import FastMCP

HEADLESS_CANDIDATES = [
    os.path.expandvars(
        r"%LOCALAPPDATA%\Microsoft\WinGet\Packages"
        r"\x64dbg.x64dbg_Microsoft.Winget.Source_8wekyb3d8bbwe"
        r"\release\x64\headless.exe"
    ),
    r"C:\Program Files\x64dbg\release\x64\headless.exe",
    r"C:\x64dbg\release\x64\headless.exe",
]

MAX_OUTPUT_CHARS = 60000
MAX_SCRIPT_CHARS = 8000


def _find_headless() -> str:
    for p in HEADLESS_CANDIDATES:
        if os.path.isfile(p):
            return p
    raise FileNotFoundError(
        "headless.exe not found; reinstall x64dbg (winget install x64dbg.x64dbg)"
    )


def _run_session(args: list[str], timeout_s: int) -> str:
    # NOTE: stdin MUST be DEVNULL. headless.exe enters an interactive
    # command loop on stdin; inheriting the MCP pipe makes it wait forever.
    proc = subprocess.run(
        args,
        capture_output=True,
        text=True,
        timeout=timeout_s,
        errors="replace",
        stdin=subprocess.DEVNULL,
    )
    out = (proc.stdout or "") + (proc.stderr or "")
    total = len(out)
    if total > MAX_OUTPUT_CHARS:
        head = out[:20000]
        tail = out[-40000:]
        out = (
            f"{head}\n...[TRUNCATED {total - MAX_OUTPUT_CHARS} chars]...\n{tail}"
        )
    return f"[rc={proc.returncode} chars={total}]\n{out}"


mcp = FastMCP("x64dbg")


@mcp.tool()
def x64dbg_run(
    target: str,
    script: str,
    target_args: str = "",
    timeout_s: int = 120,
) -> str:
    """Launch target exe under x64dbg headless, run script, return session log.

    target: absolute path to the exe to debug.
    script: x64dbg script text (one command per line). Must end with `run`
      (or breakpoints + `run`); the session ends when the debuggee exits.
    target_args: extra arguments passed to the debuggee after `--`.
    timeout_s: kill the session after this many seconds (max 600).
    """
    if len(script) > MAX_SCRIPT_CHARS:
        raise ValueError(f"script too long ({len(script)} > {MAX_SCRIPT_CHARS})")
    timeout_s = max(5, min(int(timeout_s), 600))
    if not os.path.isfile(target):
        raise FileNotFoundError(f"target not found: {target}")
    headless = _find_headless()
    with tempfile.NamedTemporaryFile(
        mode="w",
        suffix=".txt",
        delete=False,
        encoding="ascii",
        errors="replace",
    ) as f:
        f.write(script if script.endswith("\n") else script + "\n")
        script_path = f.name
    try:
        cmd = [headless, "-testing", "-cf", script_path, target, "--"]
        if target_args:
            cmd.extend(target_args.split())
        return _run_session(cmd, timeout_s + 15)
    finally:
        try:
            os.unlink(script_path)
        except OSError:
            pass


@mcp.tool()
def x64dbg_attach(pid: int, script: str, timeout_s: int = 60,
                  confirm_live: bool = False) -> str:
    """Attach x64dbg headless to a RUNNING pid, run script, return log.

    DANGER: attaching freezes every thread of the target. Do not use on
    mcla.exe during a soak (rule 11) or to observe timing behaviour.
    Legitimate use: read-only inspection of a parked/stuck process
    (registers, memory) via `log` commands.
    Requires confirm_live=true or the call is refused.
    """
    if not confirm_live:
        raise ValueError(
            "refused: attaching freezes the target; pass confirm_live=true "
            "only for a parked process, never mid-soak (rule 11)."
        )
    if len(script) > MAX_SCRIPT_CHARS:
        raise ValueError(f"script too long ({len(script)} > {MAX_SCRIPT_CHARS})")
    timeout_s = max(5, min(int(timeout_s), 600))
    headless = _find_headless()
    with tempfile.NamedTemporaryFile(
        mode="w",
        suffix=".txt",
        delete=False,
        encoding="ascii",
        errors="replace",
    ) as f:
        f.write(script if script.endswith("\n") else script + "\n")
        script_path = f.name
    try:
        cmd = [headless, "-testing", "-pid", str(int(pid)), "-cf", script_path]
        return _run_session(cmd, timeout_s + 15)
    finally:
        try:
            os.unlink(script_path)
        except OSError:
            pass


if __name__ == "__main__":
    sys.stderr.write("x64dbg MCP bridge starting (stdio)\n")
    mcp.run()
