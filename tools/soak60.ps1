#Requires -Version 5.1
<#
.SYNOPSIS
  60 s soak harness (PowerShell only) for the MCLA PC DoD gate:
    survive 60 s + zero fatals, compared against the named baseline w193.

.DESCRIPTION
  Materialises the explore-65 / T18 sketch as a real Windows harness.
  Unix `timeout` is NOT used. The wall-clock bound is
  System.Diagnostics.Process.WaitForExit(ms); $false = the process was still
  alive at the deadline = BOOT_RC=124 semantics ("timeout fired = survived"),
  which is the normal good result (.qoder/skills/mcla-boot-cycle).

  Gate (exit 0 only if BOTH hold):
    1. SURVIVE  - mcla.exe is still running after TimeoutSec (default 60).
    2. ZERO FATALS - the soak log has 0 matching lines for the gate tokens
       Fatal error | FATAL-SOFT | C0000005 | assert | skip fatal
       (soak_census / agents.md token set, line counts, case-insensitive).

  Evidence always printed (agents.md rule 13: no claim without a log line):
    tools/soak_census.py <new>.log <baseline>   with baseline = w193.

  Project rules baked in:
    - new log name every run; never overwrite an existing soak log
    - taskkill /F /IM mcla.exe BEFORE the soak and AFTER it (rule 6)
    - named A/B baseline is w193 only (never a poisoned soak: w38e, w75-w77)
    - RD-SUBMIT == 4 => soak is VOID for claims (F-123); advisory here

.EXAMPLE
  powershell -NoProfile -ExecutionPolicy Bypass -File tools\soak60.ps1

.EXAMPLE
  powershell -NoProfile -ExecutionPolicy Bypass -File tools\soak60.ps1 -TimeoutSec 60 -Tag w207

.NOTES
  Exit codes:
    0  PASS  - survived TimeoutSec AND zero fatal-gate lines
    1  FAIL  - early exit and/or one or more fatal-gate lines
    2  SETUP - missing exe / log dir / baseline (unless -SkipCensus)
#>
[CmdletBinding()]
param(
    [ValidateRange(1, 3600)]
    [int]$TimeoutSec = 60,

    # Optional soak tag (e.g. w207). Auto-picks the next free wNNN when omitted.
    [string]$Tag,

    # Path to mcla.exe. Default: <repo>\build\mcla.exe
    [string]$Exe,

    # Directory for soak logs. Default: <repo>\build\logs if present, else <repo>\build
    [string]$LogDir,

    # Named baseline log. Default: w193 under LogDir or <repo>\build
    [string]$Baseline,

    # Skip the soak_census.py comparison (gate still applies).
    [switch]$SkipCensus
)

Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

# ---------------------------------------------------------------------------
# Paths
# ---------------------------------------------------------------------------
$Repo = Split-Path -Parent $PSScriptRoot   # tools\.. = repo root
if (-not $Exe) {
    $Exe = Join-Path $Repo 'build\mcla.exe'
}
$Exe = [System.IO.Path]::GetFullPath($Exe)

if (-not $LogDir) {
    $logsCandidate = Join-Path $Repo 'build\logs'
    $buildCandidate = Join-Path $Repo 'build'
    if (Test-Path -LiteralPath $logsCandidate -PathType Container) {
        $LogDir = $logsCandidate
    } else {
        $LogDir = $buildCandidate
    }
}
$LogDir = [System.IO.Path]::GetFullPath($LogDir)

$BuildDir = [System.IO.Path]::GetFullPath((Join-Path $Repo 'build'))
$Census   = Join-Path $Repo 'tools\soak_census.py'

function Resolve-BaselinePath {
    param([string]$Explicit)
    if ($Explicit) {
        return [System.IO.Path]::GetFullPath($Explicit)
    }
    $candidates = @(
        (Join-Path $LogDir 'w193.log'),
        (Join-Path $BuildDir 'logs\w193.log'),
        (Join-Path $BuildDir 'w193.log')
    )
    foreach ($c in $candidates) {
        if (Test-Path -LiteralPath $c -PathType Leaf) { return [System.IO.Path]::GetFullPath($c) }
    }
    # Prefer the documented location even when the file is absent (clearer error).
    return [System.IO.Path]::GetFullPath($candidates[0])
}

$BaselinePath = Resolve-BaselinePath -Explicit $Baseline

# ---------------------------------------------------------------------------
# Setup checks
# ---------------------------------------------------------------------------
if (-not (Test-Path -LiteralPath $Exe -PathType Leaf)) {
    Write-Host "[soak60] SETUP FAIL: exe not found: $Exe" -ForegroundColor Red
    Write-Host "[soak60] build first (build_on_e.bat / ninja_build.bat), then re-run." -ForegroundColor Yellow
    exit 2
}

foreach ($dir in @($LogDir, $BuildDir)) {
    if (-not (Test-Path -LiteralPath $dir -PathType Container)) {
        New-Item -ItemType Directory -Path $dir -Force | Out-Null
    }
}

if (-not $SkipCensus) {
    if (-not (Test-Path -LiteralPath $BaselinePath -PathType Leaf)) {
        Write-Host "[soak60] SETUP FAIL: named baseline w193 not found." -ForegroundColor Red
        Write-Host "[soak60] looked for: $BaselinePath" -ForegroundColor Yellow
        Write-Host "[soak60] pass -Baseline <path> or -SkipCensus to proceed without the A/B table." -ForegroundColor Yellow
        exit 2
    }
    if (-not (Test-Path -LiteralPath $Census -PathType Leaf)) {
        Write-Host "[soak60] SETUP FAIL: missing $Census" -ForegroundColor Red
        exit 2
    }
}

# ---------------------------------------------------------------------------
# New log name every run (never overwrite) -- auto wNNN if -Tag omitted
# ---------------------------------------------------------------------------
function Get-NextFreeTag {
    $nums = @()
    foreach ($dir in @($LogDir, $BuildDir)) {
        if (-not (Test-Path -LiteralPath $dir -PathType Container)) { continue }
        Get-ChildItem -LiteralPath $dir -Filter 'w*.log' -File -ErrorAction SilentlyContinue |
            ForEach-Object {
                if ($_.BaseName -match '^w(\d+)$') { $nums += [int]$Matches[1] }
            }
    }
    $next = if ($nums.Count -gt 0) { ([int](($nums | Measure-Object -Maximum).Maximum)) + 1 } else { 1 }
    "w$next"
}

if (-not $Tag) {
    $Tag = Get-NextFreeTag
}
if ($Tag -notmatch '^[\w.\-]+$') {
    Write-Host "[soak60] SETUP FAIL: invalid -Tag '$Tag' (use word chars, dot, dash)." -ForegroundColor Red
    exit 2
}

$OutLog    = Join-Path $LogDir "$Tag.log"
$ErrLog    = Join-Path $LogDir "$Tag`_err.log"
foreach ($p in @($OutLog, $ErrLog)) {
    if (Test-Path -LiteralPath $p) {
        Write-Host "[soak60] SETUP FAIL: refusing to overwrite existing log: $p" -ForegroundColor Red
        Write-Host "[soak60] pick a new -Tag (project rule: new log name every soak)." -ForegroundColor Yellow
        exit 2
    }
}

# run_mcla.bat writes cache\mcla.toml in the exe cwd; keep that contract.
$cacheDir = Join-Path $BuildDir 'cache'
if (-not (Test-Path -LiteralPath $cacheDir -PathType Container)) {
    New-Item -ItemType Directory -Path $cacheDir -Force | Out-Null
}
$toml = Join-Path $cacheDir 'mcla.toml'
if (-not (Test-Path -LiteralPath $toml -PathType Leaf)) {
    Set-Content -LiteralPath $toml -Value 'renderer_mode = native' -Encoding ascii
}

# ---------------------------------------------------------------------------
# Header
# ---------------------------------------------------------------------------
$exeItem = Get-Item -LiteralPath $Exe
$deadlineMs = [int]($TimeoutSec * 1000)
Write-Host "=== soak60 -- $Tag ===" -ForegroundColor Cyan
Write-Host "  repo      : $Repo"
Write-Host "  exe       : $Exe"
Write-Host "  exe mtime : $($exeItem.LastWriteTime.ToString('yyyy-MM-dd HH:mm:ss'))  size=$($exeItem.Length)"
Write-Host "  log       : $OutLog"
Write-Host "  err       : $ErrLog"
Write-Host "  timeout   : ${TimeoutSec}s ($deadlineMs ms)  [WaitForExit; \$false = survived = BOOT_RC=124]"
if ($SkipCensus) {
    Write-Host "  baseline  : (skipped)"
} else {
    Write-Host "  baseline  : $BaselinePath"
}
Write-Host ""

# ---------------------------------------------------------------------------
# Kill any leaked mcla.exe BEFORE the soak (rule 6 / mcla-boot-cycle step 1)
# ---------------------------------------------------------------------------
function Stop-MclaByName {
    # taskkill is the project's documented form; ignore "not found".
    $null = & taskkill /F /IM mcla.exe 2>&1
    if ($LASTEXITCODE -ne 0 -and $LASTEXITCODE -ne 128) {
        Write-Host "[soak60] taskkill pre-step exit=$LASTEXITCODE (continuing)" -ForegroundColor Yellow
    }
}

Stop-MclaByName
Start-Sleep -Milliseconds 300

# ---------------------------------------------------------------------------
# Launch (PowerShell-only timeout: Start-Process + WaitForExit)
# ---------------------------------------------------------------------------
$bootRc = $null
$survived = $false
$p = $null

try {
    $psi = @{
        FilePath               = $Exe
        WorkingDirectory       = $BuildDir
        RedirectStandardOutput = $OutLog
        RedirectStandardError  = $ErrLog
        PassThru               = $true
        WindowStyle            = 'Hidden'
    }
    $p = Start-Process @psi

    Write-Host "[soak60] started pid=$($p.Id) at $(Get-Date -Format 'HH:mm:ss'); waiting ${TimeoutSec}s ..."
    $survived = -not $p.WaitForExit($deadlineMs)

    if ($survived) {
        # timeout fired = process still alive = BOOT_RC=124 idiom
        $bootRc = 124
        Write-Host "[soak60] SURVIVED ${TimeoutSec}s (BOOT_RC=124)" -ForegroundColor Green
    } else {
        $bootRc = $p.ExitCode
        Write-Host "[soak60] EARLY EXIT after process end (BOOT_RC=$bootRc)" -ForegroundColor Yellow
        if ($bootRc -lt 0) {
            try { $bootRc = $p.ExitCode } catch { $bootRc = -1 }
        }
    }
}
finally {
    # Always kill mcla.exe after the soak (rule 6). A leaked instance holds
    # the D3D12 device and game-data files open.
    try { if ($p -and -not $p.HasExited) { $p.Kill() } } catch { }
    Stop-MclaByName
    Start-Sleep -Milliseconds 400   # let spdlog flush the redirected handles
}

if (-not (Test-Path -LiteralPath $OutLog -PathType Leaf)) {
    Write-Host "[soak60] FAIL: no soak log was produced at $OutLog" -ForegroundColor Red
    exit 1
}

# ---------------------------------------------------------------------------
# Fatal-gate token counts (soak_census token set, line counts)
#   Fatal error | FATAL-SOFT | C0000005 | assert | skip fatal
# ---------------------------------------------------------------------------
$gatePattern = 'Fatal error|FATAL-SOFT|C0000005|assert|skip fatal'
$gateTokens  = @('Fatal error', 'FATAL-SOFT', 'C0000005', 'assert', 'skip fatal')

Write-Host ""
Write-Host "--- fatal gate (case-insensitive line counts) vs tokens ---" -ForegroundColor Cyan
$totalFatal = 0
$perToken   = @{}
foreach ($tok in $gateTokens) {
    $hits = @(Select-String -LiteralPath $OutLog -Pattern ([regex]::Escape($tok)) -AllMatches -CaseSensitive:$false)
    # Count matching LINES (soak_census contract), not match occurrences.
    $n = $hits.Count
    $perToken[$tok] = $n
    $totalFatal += $n
    $color = if ($n -eq 0) { 'Green' } else { 'Red' }
    Write-Host ("  {0,-14} {1,6}" -f $tok, $n) -ForegroundColor $color
}
Write-Host ("  {0,-14} {1,6}" -f 'TOTAL', $totalFatal) -ForegroundColor $(if ($totalFatal -eq 0) { 'Green' } else { 'Red' })

# Also show the raw multi-pattern hit list for hand-checking (agents.md).
$raw = Select-String -LiteralPath $OutLog -Pattern $gatePattern -AllMatches -CaseSensitive:$false
if ($raw) {
    Write-Host ""
    Write-Host "--- first fatal-gate lines (up to 12) ---" -ForegroundColor Yellow
    $raw | Select-Object -First 12 | ForEach-Object {
        $line = $_.Line
        if ($line.Length -gt 160) { $line = $line.Substring(0, 157) + '...' }
        Write-Host ("  L{0}: {1}" -f $_.LineNumber, $line)
    }
}

# ---------------------------------------------------------------------------
# Mode / quality advisories (not the hard gate, but the claim rules)
# ---------------------------------------------------------------------------
Write-Host ""
Write-Host "--- advisory ---" -ForegroundColor Cyan
$rdSubmit = @(Select-String -LiteralPath $OutLog -Pattern 'RD-SUBMIT' -CaseSensitive:$false)
$rdCount  = $rdSubmit.Count
if ($rdCount -eq 4) {
    Write-Host "  RD-SUBMIT lines = 4  =>  VOID soak for claims (F-123: stalled at the 382,976-byte TOC read)." -ForegroundColor Yellow
    Write-Host "  Repeat until RD-SUBMIT >= 24 before quoting any marker delta as progress." -ForegroundColor Yellow
} elseif ($rdCount -gt 0) {
    Write-Host "  RD-SUBMIT lines = $rdCount  (F-123: >= 24 lines is the good-mode signature; count lines, not firings.)" -ForegroundColor Gray
} else {
    Write-Host "  RD-SUBMIT not found in log (either uncapped absence or printer off) -- cannot mode-check." -ForegroundColor Gray
}

$poison = Select-String -LiteralPath $OutLog -Pattern 'POISONED' -CaseSensitive:$false
if ($poison) {
    Write-Host "  LOG QUALITY: POISONED wording present -- do not name this soak as a baseline (F-054)." -ForegroundColor Yellow
}

$logItem = Get-Item -LiteralPath $OutLog
Write-Host ("  log size  : {0:N0} lines-ish / {1:N0} bytes  ({2})" -f (
    (Select-String -LiteralPath $OutLog -Pattern '.' -CaseSensitive:$false | Measure-Object).Count),
    $logItem.Length, $Tag)

# ---------------------------------------------------------------------------
# soak_census vs named baseline w193 (required evidence for any claim)
# ---------------------------------------------------------------------------
Write-Host ""
if ($SkipCensus) {
    Write-Host "--- soak_census skipped (-SkipCensus) ---" -ForegroundColor Yellow
} else {
    Write-Host "--- soak_census: $Tag vs $(Split-Path -Leaf $BaselinePath) ---" -ForegroundColor Cyan
    $censusOut = & python $Census $OutLog $BaselinePath 2>&1
    $censusRc = $LASTEXITCODE
    if ($null -eq $censusOut) { $censusOut = @() }
    $censusOut | ForEach-Object { Write-Host $_ }
    if ($censusRc -ne 0) {
        Write-Host "[soak60] soak_census exit=$censusRc (census table may be incomplete)" -ForegroundColor Yellow
    }
}

# ---------------------------------------------------------------------------
# Gate verdict
# ---------------------------------------------------------------------------
$surviveOk = [bool]$survived
$fatalOk   = ($totalFatal -eq 0)
$pass      = ($surviveOk -and $fatalOk)

Write-Host ""
Write-Host "=== GATE ===" -ForegroundColor Cyan
Write-Host ("  survive {0}s     : {1}   (BOOT_RC={2})" -f $TimeoutSec, $(if ($surviveOk) { 'YES' } else { 'NO' }), $bootRc)
Write-Host ("  zero fatals     : {0}   (TOTAL={1})" -f $(if ($fatalOk) { 'YES' } else { 'NO' }), $totalFatal)
if ($SkipCensus) {
    Write-Host "  vs w193         : (skipped)"
} else {
    Write-Host "  vs w193         : census table above (baseline = $(Split-Path -Leaf $BaselinePath))"
}
if ($pass) {
    Write-Host "  VERDICT         : PASS" -ForegroundColor Green
    Write-Host "  log             : $OutLog"
    exit 0
} else {
    Write-Host "  VERDICT         : FAIL" -ForegroundColor Red
    if (-not $surviveOk) {
        Write-Host "  reason          : process exited before ${TimeoutSec}s (BOOT_RC=$bootRc)" -ForegroundColor Yellow
    }
    if (-not $fatalOk) {
        Write-Host "  reason          : $totalFatal fatal-gate line(s) in $Tag.log" -ForegroundColor Yellow
    }
    Write-Host "  log             : $OutLog"
    exit 1
}
