$root = "K:\PRIVATE\M4ROOT"
$srcDir = "$root\THMBNL"
$clipDir = "$root\CLIP"
$tmpDir = "R:\tmp_thumb"
$jpeg422 = "$PSScriptRoot\jpeg422.exe"

$templatePath = "$PSScriptRoot\thumb_header.bin"
if(-not (Test-Path $templatePath)) {
    Write-Error "Template not found: $templatePath`nRun: extract from K:\PRIVATE\M4ROOT\THMBNL\C6359T01.JPG first 764 bytes"
    exit 1
}
$header = [System.IO.File]::ReadAllBytes($templatePath)

if(-not (Test-Path $tmpDir)) { New-Item -ItemType Directory -Path $tmpDir -Force | Out-Null }

function Reorder-DHT {
    param([byte[]]$jpg)
    # JPEG: SOI(2), [segments...], SOS, compressed data, EOI
    # Move DHT segments before SOF0
    # Output: SOI + DQT(s) + DHT(s) + SOF0 + SOS + compressed + EOI

    # Find SOS (start of scan)
    $sos = -1
    for($i=2; $i -lt $jpg.Length-1; $i++) {
        if($jpg[$i] -eq 0xFF -and $jpg[$i+1] -eq 0xDA) { $sos = $i; break }
    }
    if($sos -lt 0) { return $jpg }

    $out = New-Object System.Collections.ArrayList
    $out.AddRange($jpg[0..1])  # SOI

    $dqtSegs = New-Object System.Collections.ArrayList  # DQT segments
    $dhtSegs = New-Object System.Collections.ArrayList  # DHT segments
    $otherSegs = New-Object System.Collections.ArrayList  # all non-DQT/DHT segments before SOS

    $i = 2
    while($i -lt $sos) {
        if($jpg[$i] -ne 0xFF) { $i++; continue }
        $marker = $jpg[$i+1]
        if($marker -eq 0xDA) { break }  # SOS - stop

        if($marker -eq 0xD0 -or $marker -eq 0xD1 -or $marker -eq 0xD2 -or $marker -eq 0xD3 -or $marker -eq 0xD4 -or $marker -eq 0xD5 -or $marker -eq 0xD6 -or $marker -eq 0xD7) {
            # RST markers - no length, shouldn't appear before SOS
            $out.AddRange($jpg[$i..($i+1)]); $i+=2; continue
        }

        if($marker -eq 0xD8 -or $marker -eq 0xD9) { $i+=2; continue }

        # Segment with length
        $len = [int]$jpg[$i+2]*256 + [int]$jpg[$i+3]
        $segData = $jpg[$i..($i+$len+1)]

        if($marker -eq 0xDB) { [void]$dqtSegs.Add($segData) }
        elseif($marker -eq 0xC4) { [void]$dhtSegs.Add($segData) }
        else { [void]$otherSegs.Add($segData) }

        $i += $len + 2
    }

    # Write: DQT(s), DHT(s), other(s), then SOS onward
    foreach($s in $dqtSegs) { $out.AddRange($s) }
    foreach($s in $dhtSegs) { $out.AddRange($s) }
    foreach($s in $otherSegs) { $out.AddRange($s) }

    # Copy from SOS to end
    $out.AddRange($jpg[$sos..($jpg.Length-1)])

    return [byte[]]$out.ToArray()
}

function Build-Thumbnail {
    param([string]$clipNum, [string]$ss = "0")

    $raw = $tmpDir + "\" + $clipNum + "_160.raw"
    $raw1280 = $tmpDir + "\" + $clipNum + "_1280.raw"
    $jpg160 = $tmpDir + "\" + $clipNum + "_160_422.jpg"
    $jpg1280 = $tmpDir + "\" + $clipNum + "_1280_422.jpg"
    $clip = $clipDir + "\" + $clipNum + ".MP4"

    echo ("Generate raw YUV422 for " + $clipNum + " (ss=" + $ss + ")")
    & ffmpeg -y -ss $ss -i $clip -vframes 1 -s 160x120 -pix_fmt yuvj422p -f rawvideo $raw 2>&1 | Out-Null
    & ffmpeg -y -ss $ss -i $clip -vframes 1 -s 1280x720 -pix_fmt yuvj422p -f rawvideo $raw1280 2>&1 | Out-Null

    echo ("Encode 422 JPEG for " + $clipNum)
    & $jpeg422 $raw 160 120 $jpg160
    & $jpeg422 $raw1280 1280 720 $jpg1280

    $f160 = [System.IO.File]::ReadAllBytes($jpg160)
    $f1280 = [System.IO.File]::ReadAllBytes($jpg1280)

    # Reorder DHT before SOF0 in both images (match camera order)
    $f160 = Reorder-DHT $f160
    $f1280 = Reorder-DHT $f1280

    echo ($clipNum + ": 160x120=" + $f160.Length + " 1280x720=" + $f1280.Length)

    # Main image: strip leading SOI (FF D8) and trailing EOI (FF D9)
    # In combined format, main image reuses file-level SOI/EOI
    $mainStart = 0
    if($f1280[0] -eq 0xFF -and $f1280[1] -eq 0xD8) { $mainStart = 2 }
    $mainEnd = $f1280.Length
    if($f1280[$mainEnd-2] -eq 0xFF -and $f1280[$mainEnd-1] -eq 0xD9) { $mainEnd = $mainEnd - 2 }
    $f1280_stripped = $f1280[$mainStart..($mainEnd-1)]

    echo ("   stripped main: " + $f1280_stripped.Length + " (removed " + $mainStart + " SOI bytes + " + ($f1280.Length-$mainEnd) + " EOI bytes)")

    $output = New-Object System.Collections.ArrayList
    $output.AddRange($header)
    $output.AddRange($f160)
    $output.AddRange($f1280_stripped)
    $output.AddRange(@(0xFF, 0xD9))  # File-level EOI
    $outBytes = $output.ToArray()

    # Patch IFD1[9] ThumbnailLength at offset 692-695 (LE)
    $newLen = $f160.Length
    $outBytes[692] = $newLen -band 0xFF
    $outBytes[693] = ($newLen -shr 8) -band 0xFF
    $outBytes[694] = ($newLen -shr 16) -band 0xFF
    $outBytes[695] = ($newLen -shr 24) -band 0xFF

    # Patch APP1 Length at offset 4-5 (BE)
    # APP1 must cover from offset 4 to just before main image
    # main image starts at: 764 + thumbnail_size
    $mainStart = 764 + $f160.Length
    $app1Len = $mainStart - 4
    $outBytes[4] = ($app1Len -shr 8) -band 0xFF
    $outBytes[5] = $app1Len -band 0xFF

    $checkLen = [int]$outBytes[4]*256 + [int]$outBytes[5]
    echo ("APP1 Length=" + $checkLen + " mainStart=" + $mainStart)

    # Verify: at offset 4+checkLen should be main image marker
    $checkOff = 4 + $checkLen
    $b1 = $outBytes[$checkOff]
    $b2 = $outBytes[$checkOff+1]
    if($b1 -eq 0xFF -and ($b2 -eq 0xD8 -or $b2 -eq 0xDB)) {
        echo ("OK: main image at " + $checkOff + " starts with FF " + $b2.ToString("X2"))
    } else {
        echo ("ERROR at " + $checkOff + ": " + $b1.ToString("X2") + " " + $b2.ToString("X2"))
    }

    $outBytes = [byte[]]$outBytes
    $outPath = $srcDir + "\" + $clipNum + "T01.JPG"
    [System.IO.File]::WriteAllBytes($outPath, $outBytes)
    echo ("Wrote " + $outPath + " (" + $outBytes.Length + " bytes)")
}

if($args.Count -gt 0) {
    $ss = "0"
    $clips = @()
    $i = 0
    while($i -lt $args.Count) {
        if($args[$i] -eq "-ss") { $i++; $ss = $args[$i] }
        else { $clips += $args[$i] }
        $i++
    }
    foreach($c in $clips) { Build-Thumbnail $c $ss }
} else {
    echo "Usage: build_thumbnails.ps1 [-ss TIMECODE] C0006 [C0007 ...]"
    echo "Example: build_thumbnails.ps1 C0004 C0005"
    echo "         build_thumbnails.ps1 -ss 8.25025 C0007  (thumb from 00:00:08:15)"
}
echo "Done!"