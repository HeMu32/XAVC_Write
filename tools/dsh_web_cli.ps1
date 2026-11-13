[CmdletBinding()]
param(
    [ValidateSet('List', 'Status', 'Events', 'Prompt')]
    [string]$Action = 'Status',
    [string]$SessionId = 'session-7808966c-549e-4d34-90a3-96ec96cbde72',
    [string]$PromptFile,
    [string]$RequestId,
    [ValidateSet('queue', 'steer')]
    [string]$Mode = 'queue',
    [ValidateRange(0, 120)]
    [int]$WaitSeconds = 0
)

$ErrorActionPreference = 'Stop'
Import-Module Microsoft.PowerShell.Utility -ErrorAction Stop
if ($WaitSeconds -gt 0) { Start-Sleep -Seconds $WaitSeconds }
$base = 'http://127.0.0.1:3080'
$log = Get-Content -LiteralPath 'E:\Program Files\dsh\web.out.log' -Raw
$urls = [regex]::Matches($log, 'http://127\.0\.0\.1:3080/\?token=[^\s]+')
if ($urls.Count -eq 0) { throw 'No local dsh launch URL found.' }
$webSession = [Microsoft.PowerShell.Commands.WebRequestSession]::new()
try {
    $null = Invoke-WebRequest -Uri $urls[$urls.Count - 1].Value -WebSession $webSession -TimeoutSec 15
} catch {
    throw 'Local dsh authentication failed; launch URL suppressed.'
}

function Invoke-DshRpc([string]$Method, [hashtable]$Arguments) {
    $body = @{
        type = 'client-request'
        rpcId = [guid]::NewGuid().ToString()
        method = $Method
        payload = @{ args = $Arguments }
    } | ConvertTo-Json -Depth 16 -Compress
    try {
        $response = Invoke-RestMethod -Uri "$base/api/$Method" -Method Post `
            -WebSession $webSession -ContentType 'application/json; charset=utf-8' `
            -Body ([Text.Encoding]::UTF8.GetBytes($body)) -TimeoutSec 45
    } catch {
        throw "Local dsh RPC failed: $Method; request details suppressed."
    }
    if (-not $response.result.ok) {
        throw "DSH RPC rejected $Method ($($response.result.error.code))."
    }
    return $response.result.value
}

switch ($Action) {
    'List' {
        $result = Invoke-DshRpc 'session/list' @{ _request = @{} }
        @($result.items | Where-Object cwd -EQ 'C:\Users\HeMu\Desktop\UM_GenAI_Router' |
            ForEach-Object {
                [pscustomobject]@{
                    sessionId = $_.sessionId
                    title = $_.projections.values.title
                    running = $_.running
                    seq = $_.projections.asOfSeq
                }
            }) | ConvertTo-Json -Depth 5
    }
    'Status' {
        $result = Invoke-DshRpc 'session/projections' @{ request = @{ sessionId = $SessionId } }
        $values = $result.values
        [pscustomobject]@{
            sessionId = $SessionId
            kind = $result.kind
            seq = $result.asOfSeq
            title = $values.title
            modelSelection = $values.modelSelection
            sessionStats = $values.sessionStats
            contextPressure = $values.contextPressure
            inboxCounts = @{
                nextTurn = @($values.inbox.'next-turn').Count
                nextStep = @($values.inbox.'next-step').Count
            }
            recentTurns = @($values.turnOutline | Select-Object -Last 2)
        } | ConvertTo-Json -Depth 8
    }
    'Prompt' {
        if (-not $PromptFile -or -not $RequestId) {
            throw 'Prompt requires a UTF-8 PromptFile and a stable RequestId.'
        }
        $text = Get-Content -LiteralPath $PromptFile -Raw -Encoding UTF8
        if ([string]::IsNullOrWhiteSpace($text)) { throw 'Empty prompt.' }
        $result = Invoke-DshRpc 'session/prompt' @{
            request = @{
                sessionId = $SessionId
                requestId = $RequestId
                mode = $Mode
                content = @(@{ type = 'text'; text = $text })
                clientTimeZone = 'Asia/Shanghai'
            }
        }
        [pscustomobject]@{
            sessionId = $SessionId
            requestId = $RequestId
            accepted = $result.accepted
        } | ConvertTo-Json
    }
    'Events' {
        $projection = Invoke-DshRpc 'session/projections' @{ request = @{ sessionId = $SessionId } }
        $result = Invoke-DshRpc 'session/page' @{
            request = @{
                address = @{ kind = 'session'; sessionId = $SessionId }
                throughSeq = $projection.asOfSeq
                maxMessages = 4
            }
        }
        @($result.records | Select-Object -Last 18 | ForEach-Object {
            $event = if ($_.event) { $_.event } else { $_ }
            [pscustomobject]@{
                seq = $event.seq
                type = $event.type
                recordKeys = @($_.PSObject.Properties.Name)
                dataKeys = @($event.data.PSObject.Properties.Name)
            }
        }) | ConvertTo-Json -Depth 6
    }
}
