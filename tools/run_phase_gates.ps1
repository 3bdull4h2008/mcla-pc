# G0 Phase-Gate Runner (B2S discipline adopted 2026-08-22)
# One command: build -> validators -> boot soak -> log assertions -> JSON report.
# Exit 0 only when every ENFORCED gate passes. Tracked gates are recorded but do
# not fail the run until their phase activates them (see MCLA_REBUILD_PLAN.md).
#
# Regression law: an ENFORCED gate that was green in the newest previous report
# and is red now marks REGRESSION and fails the run regardless of anything else.
param(
    [int]$SoakSeconds = 60,
    [switch]$SkipBoot
)

$ErrorActionPreference = 'Stop'
$repo   = Split-Path -Parent $PSScriptRoot
$build  = Join-Path $repo 'build'
$logPath = Join-Path $build 'cache\mcla.log'
$gatesDir = Join-Path $build 'gates'
New-Item -ItemType Directory -Force -Path $gatesDir | Out-Null

$commit    = (git -C $repo rev-parse --short HEAD)
$timestamp = (Get-Date).ToUniversalTime().ToString('yyyy-MM-ddTHH:mm:ssZ')
$results   = [System.Collections.Generic.List[object]]::new()
$anyRegression = $false

function Add-Gate {
    param([string]$Id, [string]$Status, [bool]$Pass, [hashtable]$Metrics)
    $reg = $false
    if ($Status -eq 'enforced' -and -not $Pass) { }
    $script:results.Add([ordered]@{
        id = $Id; status = $Status; pass = $Pass; regression = $reg; metrics = $Metrics
    })
}

function Invoke-Step {
    param([string]$Id, [scriptblock]$Body)
    try { & $Body }
    catch {
        Write-Host "[$Id] EXCEPTION: $_" -ForegroundColor Red
        Add-Gate -Id $Id -Status 'enforced' -Pass $false -Metrics @{ error = "$_" }
    }
}

# ---------------------------------------------------------------- G-BUILD
Invoke-Step 'G-BUILD' {
    $out = cmd /c "`"C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat`" >nul 2>&1 && cmake --build `"$build`" 2>&1"
    if ($LASTEXITCODE -ne 0) { throw "cmake --build failed (exit $LASTEXITCODE)" }
    Add-Gate -Id 'G-BUILD' -Status 'enforced' -Pass $true -Metrics @{ exitCode = 0 }
}

# ------------------------------------------------------------- G-VALIDATORS
$validators = @(
    'phase0_validator', 'xenos_decode_validator', 'shader_pipeline_validator',
    'phase3_validator', 'texture_decode_test', 'capture_dump_validator',
    'xtr_dump_validator', 'backend_validator'
)
$validatorResults = @{}
$validatorOutputs = @{}
# xenos_decode scans the RAW-UCODE corpus (translatable via XenosRecomp pipeline).
$validatorArgs = @{ 'xenos_decode_validator' = '.research\findings\xenia\shader_dumps' }
# These two still require Rockstar .fxc containers (input format TBD - tracked).
$corpusValidators = @('shader_pipeline_validator', 'phase3_validator')
Invoke-Step 'G-VALIDATORS' {
    foreach ($v in $validators) {
        $exe = Join-Path $build "$v.exe"
        if (-not (Test-Path $exe)) { $validatorResults[$v] = -999; continue }
        $psi = New-Object System.Diagnostics.ProcessStartInfo
        $psi.FileName = $exe
        $psi.WorkingDirectory = $repo
        $psi.UseShellExecute = $false
        $psi.RedirectStandardOutput = $true
        if ($validatorArgs[$v]) { $psi.Arguments = $validatorArgs[$v] }
        $p = [System.Diagnostics.Process]::Start($psi)
        $validatorOutputs[$v] = $p.StandardOutput.ReadToEnd()
        if (-not $p.WaitForExit(180000)) { $p.Kill(); $validatorResults[$v] = -998; continue }
        $p.WaitForExit()
        $validatorResults[$v] = $p.ExitCode
    }
    # xenos_decode exit 1 = decoder found unknown/opcodes+oob on real shaders -
    # a TRACKED decoder-quality finding, not a harness failure.
    $failed = @($validatorResults.GetEnumerator() | Where-Object {
        $_.Value -ne 0 -and -not (
            ($corpusValidators -contains $_.Key -and $_.Value -in 1,2) -or
            ($_.Key -eq 'xenos_decode_validator' -and $_.Value -eq 1)
        )
    } | ForEach-Object { $_.Key })
    Add-Gate -Id 'G-VALIDATORS' -Status 'enforced' -Pass ($failed.Count -eq 0) `
        -Metrics @{ exits = $validatorResults; failed = $failed }

    # Corpus gates: xenos_decode ENFORCED on coverage over the ucode corpus;
    # fxc-container validators stay tracked until their input format lands.
    $xdFiles = -1
    $xdMetrics = @{}
    $m = [regex]::Match($validatorOutputs['xenos_decode_validator'], '(?m)^files=(\d+)')
    if ($m.Success) { $xdFiles = [int]$m.Groups[1].Value }
    $m2 = [regex]::Match($validatorOutputs['xenos_decode_validator'], 'unknown_instrs=(\d+) oob=(\d+)')
    if ($m2.Success) {
        $xdMetrics.unknownInstrs = [int]$m2.Groups[1].Value
        $xdMetrics.oobExecs = [int]$m2.Groups[2].Value
    }
    $xdMetrics.filesScanned = $xdFiles
    Add-Gate -Id 'G-CORPUS-XENOS-DECODE' -Status 'enforced' -Pass ($xdFiles -ge 1000) `
        -Metrics $xdMetrics
    # Decoder cleanliness on the corpus: tracked until unknown-opcode/oob gaps
    # in DecodeMicrocode are fixed (real findings, see metrics above).
    Add-Gate -Id 'G-XENOS-DECODE-CLEAN' -Status 'tracked' `
        -Pass ($validatorResults['xenos_decode_validator'] -eq 0) `
        -Metrics @{ exitCode = $validatorResults['xenos_decode_validator'] }
    foreach ($v in $corpusValidators) {
        Add-Gate -Id "G-CORPUS-$v" -Status 'tracked' `
            -Pass ($validatorResults[$v] -eq 0) `
            -Metrics @{ exitCode = $validatorResults[$v]; note = 'needs .fxc container input format' }
    }

    $m = [regex]::Match($validatorOutputs['phase0_validator'], '(\d+) passed, (\d+) failed')
    $passedN = if ($m.Success) { [int]$m.Groups[1].Value } else { -1 }
    $failedN = if ($m.Success) { [int]$m.Groups[2].Value } else { -1 }
    Add-Gate -Id 'G-PHASE0' -Status 'enforced' -Pass ($passedN -eq 13 -and $failedN -eq 0) `
        -Metrics @{ passed = $passedN; failed = $failedN }
}

if (-not $SkipBoot) {
    # ------------------------------------------------------------ G-BOOT-SOAK
    Invoke-Step 'G-BOOT' {
        if (-not (Test-Path $logPath)) { throw 'no boot log - never booted?' }
        $preLines = [System.IO.File]::ReadAllLines($logPath).Count

        $proc = Start-Process -FilePath (Join-Path $build 'mcla.exe') -WorkingDirectory $repo -PassThru
        Start-Sleep -Seconds $SoakSeconds
        $stillAlive = -not $proc.HasExited
        $exitCode = if ($stillAlive) { $null } else { $proc.ExitCode }
        if ($stillAlive) { Stop-Process -Id $proc.Id -Force -ErrorAction SilentlyContinue }
        Start-Sleep -Seconds 2

        $all = [System.IO.File]::ReadAllLines($logPath)
        $slice = if ($preLines -lt $all.Count) { $all[$preLines..($all.Count-1)] } else { @() }
        $slice | Set-Content (Join-Path $gatesDir 'last-run-log-slice.txt')

        $fatalHits = @($slice | Select-String -Pattern '0xC0000005|KeBugCheck|FATAL|std::terminate').Count
        $vsyncStarts = @($slice | Select-String -Pattern 'VSync thread started').Count
        $ringSamples = @($slice | Select-String -Pattern 'RING:').Count
        $createdCount = @($slice | Select-String -Pattern 'DEVICE: created @').Count
        $createdMatch = @($slice | Select-String -Pattern 'DEVICE: created @ .*match\)').Count
        $selfTestOk = @($slice | Select-String -Pattern 'redirected \d+/101 default RS slots.*readback=ok.*thunkResolved=true').Count
        $rsThunkHits = @($slice | Select-String -Pattern 'RS-default-thunk hit').Count
        $rsRealHits = @($slice | Select-String -Pattern 'RS-real-thunk hit').Count
        $helperHits = @($slice | Select-String -Pattern 'HELPER-thunk').Count

        Add-Gate -Id 'G-BOOT-SOAK' -Status 'enforced' -Pass ($stillAlive -and $fatalHits -eq 0) -Metrics @{
            soakSeconds = $SoakSeconds; stillAlive = [bool]$stillAlive; exitCode = $exitCode; fatalPatterns = $fatalHits
        }
        Add-Gate -Id 'G-VSYNC-CHAIN' -Status 'enforced' -Pass ($vsyncStarts -ge 1) `
            -Metrics @{ vsyncThreadStarts = $vsyncStarts; ringProbeSamples = $ringSamples }

        Add-Gate -Id 'G-P4-CREATE-HOOK' -Status 'enforced' `
            -Pass ($createdCount -ge 1 -and $createdMatch -ge 1 -and $selfTestOk -ge 1) -Metrics @{
                createdCount = $createdCount; createdMatch = $createdMatch; redirectSelfTestOk = $selfTestOk
            }

        # Tracked: real-handler passthrough proof (activates when a real slot is thumbed)
        Add-Gate -Id 'G-P4-RS-THUNK-HITS' -Status 'tracked' -Pass (($rsRealHits + $helperHits) -ge 1) `
            -Metrics @{ realThunkHits = $rsRealHits; helperHits = $helperHits }

        # Tracked: PM4-free frames (activates at P6'; currently the legacy ring is alive by design)
        $putVals = @($slice | Select-String -Pattern 'RING: ctx\+30=([0-9A-F]{8})' |
            ForEach-Object { $_.Matches[0].Groups[1].Value })
        $pm4Free = ($putVals.Count -ge 2) -and ($putVals[-1] -eq $putVals[-2])
        Add-Gate -Id 'G-P6-PM4FREE-FRAMES' -Status 'tracked' -Pass $pm4Free -Metrics @{
            ringSamplesUsed = $putVals.Count; lastPut = if ($putVals.Count) { $putVals[-1] } else { 'none' }
        }
    }
}

# ------------------------------------------------------------- regressions
$prevFile = Get-ChildItem $gatesDir -Filter '20*.json' -ErrorAction SilentlyContinue |
    Sort-Object Name -Descending | Select-Object -First 1
if ($prevFile) {
    try {
        $prev = Get-Content $prevFile.FullName -Raw | ConvertFrom-Json
        foreach ($r in $results) {
            if ($r.status -ne 'enforced') { continue }
            $prevGate = $prev.gates | Where-Object { $_.id -eq $r.id } | Select-Object -First 1
            if ($prevGate -and $prevGate.pass -and -not $r.pass) {
                $r.regression = $true
                $script:anyRegression = $true
            }
        }
    } catch { Write-Host "regression compare skipped: $_" -ForegroundColor Yellow }
}
foreach ($r in $results) {
    if ($r.status -eq 'enforced' -and -not $r.pass) { $script:anyRegression = $true }
}

# ------------------------------------------------------------------ report
$report = [ordered]@{
    commit = $commit; timestamp = $timestamp; soakSeconds = $SoakSeconds
    overallPass = ((@($results | Where-Object { $_.status -eq 'enforced' -and (-not $_.pass -or $_.regression) }).Count) -eq 0)
    gates = $results
}
$date = (Get-Date).ToString('yyyy-MM-dd')
$outFile = Join-Path $gatesDir "$date-gate-report.json"
$report | ConvertTo-Json -Depth 5 | Set-Content $outFile -Encoding UTF8

Write-Host ''
foreach ($r in $results) {
    $color = if ($r.pass) { 'Green' } elseif ($r.status -eq 'tracked') { 'Yellow' } else { 'Red' }
    $tag = if ($r.regression) { ' [REGRESSION]' } else { '' }
    Write-Host ("{0,-24} {1,-9} {2}{3}" -f $r.id, $(if ($r.pass) {'PASS'} elseif ($r.status -eq 'tracked') {'TRACKED-FAIL'} else {'FAIL'}), $r.status, $tag) -ForegroundColor $color
}
Write-Host ''
Write-Host ("OVERALL: {0}  (report: {1})" -f $(if ($report.overallPass) { 'PASS' } else { 'FAIL' }), $outFile) `
    -ForegroundColor $(if ($report.overallPass) { 'Green' } else { 'Red' })
exit $(if ($report.overallPass) { 0 } else { 1 })


