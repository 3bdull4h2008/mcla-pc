---
name: mcla-boot-cycle
description: Build, soak and re-baseline the MCLA PC Xbox 360 emulator in E:\mcla pc the way the project's rules require (MSYS path-conv guards, kill mcla.exe, rule-11 concurrent-session check, stale-exe trap, new log name every run). Use whenever a change to src/ must be compiled and booted, or when asked to "soak", "re-baseline" or reproduce a boot.
---

# MCLA boot cycle

Nine sessions were lost to getting this wrong. Follow the steps **in order**; each one has a
failure mode that is invisible if you skip it.

## 0. Stand-down check (rule 11 — another agent session may be live)

```bash
cd "E:/mcla pc"
tasklist | grep -iE "mcla|ninja" || echo "no build/boot process running"
ls -lt --time-style=+%m-%d_%H:%M build/*.log 2>/dev/null | head -5
```

If the newest `build/*.log` is **less than ~2 minutes old**, another session is mid-experiment:
do docs-only work. Do not build, do not boot, do not `git commit`.

Also re-check doc mtimes before writing any doc (`ls -l --time-style=+%H:%M docs/`) — if a doc
moved since you read it, re-read it before editing, and write a **dated superseding block**
instead of rewriting someone else's section.

## 1. Kill before build (rule 6)

```bash
MSYS_NO_PATHCONV=1 MSYS2_ARG_CONV_EXCL='*' cmd.exe /c "taskkill /F /IM mcla.exe"
```

The `MSYS_NO_PATHCONV`/`MSYS2_ARG_CONV_EXCL` pair is **mandatory**: without it Git Bash rewrites
`/F /IM` into Windows paths and `cmd.exe /c` silently no-ops. Never write `//F//IM` — it parses
as a UNC path.

## 2. Build (rule 7 — tree must always compile)

```bash
cd "E:/mcla pc" && MSYS_NO_PATHCONV=1 MSYS2_ARG_CONV_EXCL='*' cmd.exe /c build_on_c.bat build > build/<wave>_build.log 2>&1; echo "BUILD_RC=$?"
```

`build_on_c.bat` is the **only** C:-path script (bare arg = configure, `build` = ninja-only; rc 2=vcvars, 3=configure). `ninja_build.bat` and `configure.bat` hard-code `cd /d "E:\mcla pc"` — the poisoned volume — so they silently build nothing here. **Never use them.**

Capture `rc=$?` **immediately** and in the same command. Piping ninja to `tail` reports `0` on a
failed build — this has bitten the project three times.

## 3. Verify the exe actually moved (rule 12 — stale-exe trap)

```bash
ls -l --time-style=+%m-%d_%H:%M build/mcla.exe
```

If the mtime did not move, the link failed or produced nothing: **soaking would re-measure the old
binary and every conclusion would be false.** Stop and fix the link.

## 4. Soak into a NEW log name (rule 5)

```bash
cd "E:/mcla pc/build" && timeout 120 ./mcla.exe > w43a.log 2> w43a_err.log; echo "BOOT_RC=$?"
```

`BOOT_RC=124` means the timeout fired = **the process survived**, which is the normal good result.
Never reuse or overwrite an existing soak log; they are the evidence base and are gitignored, so
a lost log is a lost claim.

## 5. Regenerate the guest image if it is missing (rule 3)

`build/cache/mcla_pe.bin` is dumped at runtime by `src/boot_host.cpp`. If it is absent, no raw-byte
verification is possible: run one `timeout 20 ./build/mcla.exe > build/pe_dump.log 2>&1` first.

## 6. Kill after the soak (rule 6)

Same command as step 1. A leaked `mcla.exe` holds the D3D12 device and the game-data files open and
makes the next session's results uninterpretable.

## 7. Census the result

Use the `mcla-log-census` skill — count markers case-insensitively and compare against the named
baseline log. Then `mcla-finding-ledger` for anything new.

## Gate before reporting "done"

Build green + exe mtime moved + new log + marker table + the mcla.exe killed. A claim with no
soak-log line is not a claim (rule 13).
