# Auto Test Runner for ex0502.c

$testDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$exePath = Join-Path $testDir "ex0502.exe"

# Compile if needed
$sourceFile = Join-Path $testDir "ex0502.c"
if (-not (Test-Path $exePath)) {
    Write-Host "Compiling..." -ForegroundColor Yellow
    &gcc.exe -Wall -Wextra -std=c11 "$sourceFile" -o "$exePath"
}

# Define test cases
$testCases = @()
$testCases += @{ ID="TC01"; Input="4`n100 85 40 60"; Expected=@("n = 4", "scores = 100 85 40 60", "#students = 4", "#passed = 3 (75%)", "ave = 71.3", "max = 100", "min = 40") }
$testCases += @{ ID="TC02"; Input="4`n-1 85 40 60"; Expected=@("n = 4", "scores = -1 85 40 60", "#students = 4", "#passed = 2 (50%)", "ave = 61.7", "max = 85", "min = 40") }
$testCases += @{ ID="TC03"; Input="1`n60"; Expected=@("n = 1", "scores = 60", "#students = 1", "#passed = 1 (100%)", "ave = 60.0", "max = 60", "min = 60") }
$testCases += @{ ID="TC04"; Input="1`n59"; Expected=@("n = 1", "scores = 59", "#students = 1", "#passed = 0 (0%)", "ave = 59.0", "max = 59", "min = 59") }
$testCases += @{ ID="TC05"; Input="9`n-1 0 59 60 100 100 -1 80 21"; Expected=@("n = 9", "scores = -1 0 59 60 100 100 -1 80 21", "#students = 9", "#passed = 4 (44%)", "ave = 60.0", "max = 100", "min = 0") }
$testCases += @{ ID="TC06"; Input="3`n-1 -1 -1"; Expected=@("n = 3", "scores = -1 -1 -1", "#students = 3", "#passed = 0 (0%)", "ave = 0.0", "max = 0", "min = 0") }
$testCases += @{ ID="TC07"; Input="2`n100 100"; Expected=@("n = 2", "scores = 100 100", "#students = 2", "#passed = 2 (100%)", "ave = 100.0", "max = 100", "min = 100") }
$testCases += @{ ID="TC08"; Input="0"; Expected=@("n = 0", "ERROR: invalid number of students (0)") }
$testCases += @{ ID="TC09"; Input="10"; Expected=@("n = 10", "ERROR: invalid number of students (10)") }
$testCases += @{ ID="TC10"; Input="-3"; Expected=@("n = -3", "ERROR: invalid number of students (-3)") }
$testCases += @{ ID="TC11"; Input="3`n50 -2 60"; Expected=@("n = 3", "scores = 50 -2", "ERROR: invalid score (-2)") }
$testCases += @{ ID="TC12"; Input="3`n50 101 60"; Expected=@("n = 3", "scores = 50 101", "ERROR: invalid score (101)") }
$testCases += @{ ID="TC13"; Input="4`n-1 101 -2 85"; Expected=@("n = 4", "scores = -1 101", "ERROR: invalid score (101)") }
$testCases += @{ ID="TC14"; Input="3`n102 50 40"; Expected=@("n = 3", "scores = 102", "ERROR: invalid score (102)") }
$testCases += @{ ID="TC15"; Input="3`n60 59 0"; Expected=@("n = 3", "scores = 60 59 0", "#students = 3", "#passed = 1 (33%)", "ave = 39.7", "max = 60", "min = 0") }
$testCases += @{ ID="TC16"; Input="5`n-1 70 -1 80 90"; Expected=@("n = 5", "scores = -1 70 -1 80 90", "#students = 5", "#passed = 3 (60%)", "ave = 80.0", "max = 90", "min = 70") }

# Run tests
$passed = 0
$failed = 0
Write-Host "`nRunning $($testCases.Count) tests...`n" -ForegroundColor Cyan

foreach ($test in $testCases) {
    $output = $test.Input | &"$exePath" 2>&1
    $actualLines = @($output -split "`r?`n" | ForEach-Object { $_.Trim() } | Where-Object { $_ })
    
    $allMatch = $true
    foreach ($exp in $test.Expected) {
        if ($actualLines -notcontains $exp) {
            $allMatch = $false
            break
        }
    }
    
    if ($allMatch) {
        Write-Host "[PASS] $($test.ID)" -ForegroundColor Green
        $passed++
    } else {
        Write-Host "[FAIL] $($test.ID)" -ForegroundColor Red
        Write-Host "  Expected: $($test.Expected[0])" -ForegroundColor DarkGray
        Write-Host "  Got:      $($actualLines[0])" -ForegroundColor DarkGray
        $failed++
    }
}

Write-Host "`nResult: $passed passed, $failed failed`n" -ForegroundColor Cyan
