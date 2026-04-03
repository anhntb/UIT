$ErrorActionPreference = 'Stop'

$candidateExePaths = @(
  (Join-Path $PSScriptRoot 'ex0702.exe'),
  (Join-Path $PSScriptRoot 'ex0702')
)

$exePath = $candidateExePaths | Where-Object { Test-Path $_ } | Select-Object -First 1
if (-not $exePath) {
  Write-Host "[ERROR] Cannot find executable ex0702(.exe) in $PSScriptRoot" -ForegroundColor Red
  exit 1
}

$tests = @(
  @{Id=1;  Sides=@(0,5,5);    Expected='ERROR'},
  @{Id=2;  Sides=@(100,5,5);  Expected='ERROR'},
  @{Id=3;  Sides=@(5,5,5);    Expected='equilateral triangle'},
  @{Id=4;  Sides=@(5,5,3);    Expected='isosceles triangle'},
  @{Id=5;  Sides=@(4,3,2);    Expected='scalene triangle'},
  @{Id=6;  Sides=@(1,1,1);    Expected='equilateral triangle'},
  @{Id=7;  Sides=@(99,99,99); Expected='equilateral triangle'},
  @{Id=8;  Sides=@(-5,10,10); Expected='ERROR'},
  @{Id=9;  Sides=@(2,4,3);    Expected='scalene triangle'},
  @{Id=10; Sides=@(3,2,4);    Expected='scalene triangle'},
  @{Id=11; Sides=@(3,4,2);    Expected='scalene triangle'},
  @{Id=12; Sides=@(3,5,5);    Expected='isosceles triangle'},
  @{Id=13; Sides=@(5,3,5);    Expected='isosceles triangle'},
  @{Id=14; Sides=@(5,2,2);    Expected='[ERROR] not a triangle'},
  @{Id=15; Sides=@(2,5,2);    Expected='[ERROR] not a triangle'},
  @{Id=16; RawInput='abc 2 3'; Expected='ERROR'},
  @{Id=17; RawInput='1 2';     Expected='ERROR'}
)

function Get-ActualResult([string]$programOutput) {
  $patterns = @(
    '\[ERROR\] invalid input',
    '\[ERROR\] not a triangle',
    'equilateral triangle',
    'isosceles triangle',
    'scalene triangle'
  )

  foreach ($pattern in $patterns) {
    $m = [regex]::Match($programOutput, $pattern)
    if ($m.Success) {
      return $m.Value
    }
  }

  return '<NO_MATCH>'
}

$results = @()
$passCount = 0

foreach ($test in $tests) {
  if ($null -ne $test.RawInput) {
    $inputText = "{0}`n" -f $test.RawInput
    $inputDisplay = $test.RawInput
  }
  else {
    $inputText = "{0} {1} {2}`n" -f $test.Sides[0], $test.Sides[1], $test.Sides[2]
    $inputDisplay = ($test.Sides -join ' ')
  }

  $output = $inputText | & $exePath | Out-String
  $actual = Get-ActualResult $output

  if ($test.Expected -eq 'ERROR') {
    $isPass = $actual.StartsWith('[ERROR]')
  }
  else {
    $isPass = ($actual -eq $test.Expected)
  }

  if ($isPass) { $passCount++ }

  $results += [pscustomobject]@{
    ID       = $test.Id
    Input    = $inputDisplay
    Expected = $test.Expected
    Actual   = $actual
    Status   = if ($isPass) { 'PASS' } else { 'FAIL' }
  }
}

$results | Format-Table -AutoSize
Write-Host ""
Write-Host ("Summary: {0}/{1} passed" -f $passCount, $tests.Count) -ForegroundColor Cyan

if ($passCount -ne $tests.Count) {
  exit 1
}
