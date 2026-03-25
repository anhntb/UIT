# Auto Test Runner - Two modes: CAPTURE (build baseline) and VERIFY (test against baseline)

param(
    [string]$Mode = "verify"  # "capture" or "verify"
)

$testDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$exePath = Join-Path $testDir "ex0502.exe"
$baselineFile = Join-Path $testDir "test_baseline.txt"

# Compile
$sourceFile = Join-Path $testDir "ex0502.c"
if (-not (Test-Path $exePath)) {
    Write-Host "Compiling..." -ForegroundColor Yellow
    &gcc.exe -Wall -Wextra -std=c11 "$sourceFile" -o "$exePath"
}

# Define test inputs
$testInputs = @()
$testInputs += @{ ID="TC01"; Input="4`n100 85 40 60"; Desc="Normal: 4 students, scores 100,85,40,60" }
$testInputs += @{ ID="TC02"; Input="4`n-1 85 40 60"; Desc="Normal: with NA (-1)" }
$testInputs += @{ ID="TC03"; Input="1`n60"; Desc="Boundary: n=1, score=60" }
$testInputs += @{ ID="TC04"; Input="1`n59"; Desc="Boundary: score=59" }
$testInputs += @{ ID="TC05"; Input="9`n-1 0 59 60 100 100 -1 80 21"; Desc="Boundary: n=9" }
$testInputs += @{ ID="TC06"; Input="3`n-1 -1 -1"; Desc="Edge: all NA" }
$testInputs += @{ ID="TC07"; Input="2`n100 100"; Desc="Edge: all 100" }
$testInputs += @{ ID="TC08"; Input="0"; Desc="Invalid: n=0" }
$testInputs += @{ ID="TC09"; Input="10"; Desc="Invalid: n=10" }
$testInputs += @{ ID="TC10"; Input="-3"; Desc="Invalid: n=-3" }
$testInputs += @{ ID="TC11"; Input="3`n50 -2 60"; Desc="Invalid: score=-2" }
$testInputs += @{ ID="TC12"; Input="3`n50 101 60"; Desc="Invalid: score=101" }
$testInputs += @{ ID="TC13"; Input="4`n-1 101 -2 85"; Desc="Edge: multiple invalid" }
$testInputs += @{ ID="TC14"; Input="3`n102 50 40"; Desc="Edge: first score invalid" }
$testInputs += @{ ID="TC15"; Input="3`n60 59 0"; Desc="Edge: pass rate 33%" }
$testInputs += @{ ID="TC16"; Input="5`n-1 70 -1 80 90"; Desc="Edge: NA don't affect min/max" }
# $testInputs += @{ ID="TC17"; Input="a"; Desc="Invalid type: n is alphabetic character" }
# $testInputs += @{ ID="TC18"; Input="@"; Desc="Invalid type: n is special character" }
# $testInputs += @{ ID="TC19"; Input="4.5`n100 85 40 60"; Desc="Invalid type: n is floating-point value" }
# $testInputs += @{ ID="TC20"; Input="4a`n100 85 40 60"; Desc="Invalid type: n is mixed alphanumeric" }
# $testInputs += @{ ID="TC21"; Input="3`na 50 60"; Desc="Invalid type: first score is alphabetic" }
# $testInputs += @{ ID="TC22"; Input="3`n50 a 70"; Desc="Invalid type: middle score is alphabetic" }
# $testInputs += @{ ID="TC23"; Input="2`n80 #"; Desc="Invalid type: score is special character" }
# $testInputs += @{ ID="TC24"; Input="1`n12.5"; Desc="Edge type: score is floating-point with n=1" }
# $testInputs += @{ ID="TC25"; Input="3`n50 60.5 70"; Desc="Invalid type: score is floating-point in sequence" }
# $testInputs += @{ ID="TC26"; Input="2`n80x 90"; Desc="Invalid type: score is mixed alphanumeric" }

if ($Mode -eq "capture") {
    Write-Host "`n=== CAPTURE MODE: Building baseline ===" -ForegroundColor Cyan
    $baseline = @()
    
    foreach ($test in $testInputs) {
        $output = $test.Input | &"$exePath" 2>&1
        $baseline += "$($test.ID)|||$($test.Desc)|||$([string]::Join("|||", @($output)))"
        Write-Host "[Captured] $($test.ID)" -ForegroundColor Green
    }
    
    $baseline | Out-File -FilePath $baselineFile -Encoding UTF8
    Write-Host "`nBaseline saved to: $baselineFile`n" -ForegroundColor Yellow
    
} elseif ($Mode -eq "verify") {
    
    if (-not (Test-Path $baselineFile)) {
        Write-Host "Baseline not found. Run with -Mode capture first." -ForegroundColor Red
        exit 1
    }
    
    Write-Host "`n=== VERIFY MODE: Testing against baseline ===" -ForegroundColor Cyan
    Write-Host "Running $($testInputs.Count) tests...`n"
    
    $baselineData = @{}
    Get-Content $baselineFile -Encoding UTF8 | ForEach-Object {
        $parts = $_ -split '\|\|\|', 3
        if ($parts.Count -ge 3) {
            $baselineData[$parts[0]] = $parts[2]
        }
    }
    
    $passed = 0
    $failed = 0
    
    foreach ($test in $testInputs) {
        $currentOutput = $test.Input | &"$exePath" 2>&1
        $currentStr = [string]::Join("|||", @($currentOutput))
        
        if ($baselineData[$test.ID] -eq $currentStr) {
            Write-Host "[PASS] $($test.ID) - $($test.Desc)" -ForegroundColor Green
            $passed++
        } else {
            Write-Host "[FAIL] $($test.ID) - $($test.Desc)" -ForegroundColor Red
            $failed++
            
            # Show diff (first line only)
            $baselineLines = $baselineData[$test.ID] -split '\|\|\|' | Where-Object { $_ }
            $currentLines = $currentStr -split '\|\|\|' | Where-Object { $_ }
            if ($baselineLines.Count -gt 0 -and $currentLines.Count -gt 0) {
                Write-Host "  Expected: $($baselineLines[0])" -ForegroundColor DarkGray
                Write-Host "  Got:      $($currentLines[0])" -ForegroundColor DarkGray
            }
        }
    }
    
    Write-Host "`nResult: $passed passed, $failed failed out of $($testInputs.Count)`n" -ForegroundColor Cyan
    
    if ($failed -gt 0) {
        exit 1
    }
}
