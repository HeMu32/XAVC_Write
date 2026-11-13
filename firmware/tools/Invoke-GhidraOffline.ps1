[CmdletBinding()]
param(
    [Parameter(Mandatory)]
    [ValidateSet('Rm5Core', 'M4Core', 'Rm5Stack')]
    [string]$Target,
    [switch]$ExportExisting
)
$ErrorActionPreference = 'Stop'
$taskRoot = [IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))
$java = 'E:\Program Files\jdk-21\bin\java.exe'
$utility = 'E:\Program Files\ghidra_12.1.4_PUBLIC\Ghidra\Framework\Utility\lib\Utility.jar'
$relative = switch ($Target) {
    'Rm5Core' { 'inputs\rm5-live-readback\libInfraBluetoothCore.so' }
    'M4Core' { 'extracted\m4-v602\usr\lib\libInfraBluetoothCore.so' }
    'Rm5Stack' { 'extracted\rm5-update\usr\lib\libbluetoothdefault.so' }
}
$inputPath = Join-Path $taskRoot $relative
$scriptName = if ($Target -eq 'Rm5Stack') { 'FocusStackPrivacy.java' } else { 'FocusBleFirmware.java' }
$output = Join-Path $taskRoot ('analysis\repro-' + $Target)
$arguments = @(
    '-Xmx2G', '-Djava.awt.headless=true',
    '-Djava.system.class.loader=ghidra.GhidraClassLoader', '-Dfile.encoding=UTF8',
    '-cp', $utility, 'ghidra.Ghidra', 'ghidra.app.util.headless.AnalyzeHeadless',
    (Join-Path $taskRoot 'ghidra'), $Target
)
if ($ExportExisting) {
    $arguments += @('-process', [IO.Path]::GetFileName($inputPath), '-noanalysis', '-readOnly')
} else {
    $arguments += @('-import', $inputPath, '-analysisTimeoutPerFile', '180')
}
$arguments += @('-scriptPath', $PSScriptRoot, '-postScript', $scriptName, $output, '-max-cpu', '2')
# Explicit argv keeps dotted Java -D properties intact in PowerShell.
& $java @arguments
if ($LASTEXITCODE -ne 0) { throw "Offline Ghidra failed with exit $LASTEXITCODE" }
