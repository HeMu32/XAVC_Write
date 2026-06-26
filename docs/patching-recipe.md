# XAVC-S HD 50M EDIUS→Sony ILCE-7M4 修补流程

适用范围：EDIUS 导出的 1920×1080 59.94p XAVC-S 50M 片段。  
验证相机：Sony ILCE-7M4。  
不适用范围：4K 片段、HEVC 片段、其他帧率。

## 所需工具

| 工具 | 位置 | 作用 |
|------|------|------|
| `deblock_inject.exe` | `tools/deblock_inject.c`（需编译） | 位流手术 |
| `jpeg422.exe` | `tools/jpeg422.c`（需编译） | 4:2:2 JPEG 编码 |
| `build_thumbnails.ps1` | `tools/build_thumbnails.ps1` | 缩略图全自动构建 |

编译：
```
gcc -O2 -std=c99 -o tools/deblock_inject.exe tools/deblock_inject.c
gcc -o tools/jpeg422.exe tools/jpeg422.c -IC:/MinGW/include -LC:/MinGW/lib -ljpeg -O2
```

## 流程（以新片段 C0006 为例）

### 1. 快照

备份非媒体文件，记录媒体文件时间戳：
```
$snap = ".\backup\snap_$(Get-Date -Format 'yyyyMMddTHHmmss')"
mkdir -p "$snap\PRIVATE\M4ROOT\CLIP", "$snap\PRIVATE\M4ROOT\AVBINF"
cp K:\PRIVATE\M4ROOT\MEDIAPRO.XML "$snap\PRIVATE\M4ROOT\"
cp K:\PRIVATE\M4ROOT\CLIP\C0006M01.XML "$snap\PRIVATE\M4ROOT\CLIP\"
cp "K:\PRIVATE\M4ROOT\AVBINF\DATABASE.BIN" "$snap\PRIVATE\M4ROOT\AVBINF\"
(Get-Item "K:\PRIVATE\M4ROOT\CLIP\C0006.MP4").LastWriteTime.ToString("o") > "$snap\clip_timestamp.txt"
```

### 2. 位流手术

```
tools\deblock_inject.exe K:\PRIVATE\M4ROOT\CLIP\C0006.MP4 K:\PRIVATE\M4ROOT\CLIP\C0006.MP4
```

成功输出示例：
```
avcC: ls=3 sps=41 pps=6(1 entries)
stsz: uniform=0 count=1182
stco: 1 chunks
Mapped 1182 video samples
Modified 3152/3152 slices (size changes)
Total size delta: +3152 bytes
Patched PPS deblocking flag
Output: K:\PRIVATE\M4ROOT\CLIP\C0006.MP4 (nnnnnnn bytes)
```

工具完成以下操作（源码：`tools/deblock_inject.c:190-628`）：
- 遍历所有 slice NAL，在 `slice_qp_delta` 后插入 deblocking 参数 `ue(0)+se(0)+se(0)`（3 bits "111"）
- 翻转 PPS：avcC 中 PPS byte 3 的 bit 1 `|= 0x40`
- 重建 mdat，更新全部三轨 stco（video + audio + rtmd）

验证：
```
ffmpeg -v error -i K:\PRIVATE\M4ROOT\CLIP\C0006.MP4 -f null -
```
应输出 0 错误。若有报错说明位流损坏。

### 3. PROF VPRF 码率

原始值 vs 目标值：

| 字段 | EDIUS 原始（C0004） | 相机目标（C6359） | 含义 |
|------|-------------------|-------------------|------|
| VPRF.field3 | `00 00 B9 8C` (47500) | `00 00 C3 50` (50000) | 平均码率 |
| VPRF.field4 | `00 00 EA 5E` (60000) | `00 00 C3 50` (50000) | 最大码率 |
| VPRF.field5 | `00 3B F0 A7` (3924135) | `00 3B F0 A6` (3924134) | — |
| VPRF.field6 | `00 3B F0 A7` (3924135) | `00 3B F0 A6` (3924134) | — |

```
$f = [System.IO.File]::ReadAllBytes("K:\PRIVATE\M4ROOT\CLIP\C0006.MP4")
$vprf = -1; for($i=0; $i -lt $f.Length-4; $i++) { if($f[$i]-eq0x56-and$f[$i+1]-eq0x50-and$f[$i+2]-eq0x52-and$f[$i+3]-eq0x46){$vprf=$i;break} }
$f[$vprf+24] = [byte]0x00; $f[$vprf+25] = [byte]0x00; $f[$vprf+26] = [byte]0xC3; $f[$vprf+27] = [byte]0x50  # field3 = 50000
$f[$vprf+28] = [byte]0x00; $f[$vprf+29] = [byte]0x00; $f[$vprf+30] = [byte]0xC3; $f[$vprf+31] = [byte]0x50  # field4 = 50000
$f[$vprf+32] = [byte]0x00; $f[$vprf+33] = [byte]0x3B; $f[$vprf+34] = [byte]0xF0; $f[$vprf+35] = [byte]0xA6  # field5 = 3924134
$f[$vprf+36] = [byte]0x00; $f[$vprf+37] = [byte]0x3B; $f[$vprf+38] = [byte]0xF0; $f[$vprf+39] = [byte]0xA6  # field6 = 3924134
[System.IO.File]::WriteAllBytes("K:\PRIVATE\M4ROOT\CLIP\C0006.MP4", $f)
```

注意：PowerShell 5.1 的 `byte[]` 切片赋值（如 `$f[$a..$b] = [byte[]]@(...)`）在某些情况下会静默失败，必须逐字节赋值。原始代码使用 `$d=$vprf+16` 再 `$f[$d+12..$d+15]` 的偏移也是错的——实际字段偏移为 `vprf+24..vprf+39`，且漏掉了 field3（vprf+24）。

### 4. 侧边栏 XML level

打开 `K:\PRIVATE\M4ROOT\CLIP\C0006M01.XML`，查找：
```xml
<videoCodec>AVC_1920_1080_HP@L42</videoCodec>
```
HD 59.94p 必须是 `@L42`。若为 `@L52` 需修正。

### 5. 缩略图

```
tools\build_thumbnails.ps1 C0006
```

成功输出示例：
```
Generate raw YUV422 for C0006
Encode 422 JPEG for C0006
C0006: 160x120=7612 1280x720=149785
   stripped main: 149781 (removed 2 SOI bytes + 2 EOI bytes)
APP1 Length=8372 mainStart=8376
OK: main image at 8376 starts with FF DB
Wrote K:\PRIVATE\M4ROOT\THMBNL\C0006T01.JPG (158159 bytes)
```

脚本完成以下操作（源码：`tools/build_thumbnails.ps1:64-137`）：
1. 提取首帧 → 160×120 raw YUV422 → `jpeg422.exe` 编码为 4:2:2 JPEG
2. 提取首帧 → 1280×720 raw YUV422 → `jpeg422.exe` 编码为 4:2:2 JPEG
3. `Reorder-DHT` 将 DHT 段移到 SOF0 前（匹配相机）
4. 从 `tools/thumb_header.bin` 读取 EXIF 头模板（从相机缩略图预提取）
5. 拼接：EXIF 头 + 嵌入式缩略图 + 主图像（无 SOI/EOI）+ 文件级 EOI
6. 修正 APP1 Length（偏移 4-5, BE）和 IFD1 ThumbnailLength（偏移 692-695, LE）

### 6. MEDIAPRO.XML

编辑 `K:\PRIVATE\M4ROOT\MEDIAPRO.XML`。C0006 的条目目前应类似：

```xml
<Material uri="./CLIP/C0006.MP4" type="MP4" ...>
    <RelevantInfo uri="./CLIP/C0006M01.XML" type="XML"/>
</Material>
```

在 XML sidecar 行后面插入缩略图行（`</Material>` 前面）：

```xml
<Material uri="./CLIP/C0006.MP4" type="MP4" ...>
    <RelevantInfo uri="./CLIP/C0006M01.XML" type="XML"/>
    <RelevantInfo uri="./THMBNL/C0006T01.JPG" type="JPG"/>     ← 插入
</Material>
```

### 7. 验证

```
ffmpeg -v error -i K:\PRIVATE\M4ROOT\CLIP\C0006.MP4 -f null -
:: 应无输出（零错误）

ffprobe -v error -select_streams v -show_entries stream=codec_name,width,height,level \
    K:\PRIVATE\M4ROOT\THMBNL\C0006T01.JPG
:: 应输出 level=42（非 50/51）, width=1280, height=720

ffmpeg -v error -i K:\PRIVATE\M4ROOT\THMBNL\C0006T01.JPG -f null -
ffprobe -v error -show_frames K:\PRIVATE\M4ROOT\THMBNL\C0006T01.JPG | findstr chroma
```

确认缩略图在 Windows 照片查看器中内容正确。

## 注意事项

1. **`deblock_inject.c` 硬编码了 1080p 59.94p 的 SPS 参数**（`#define` 区域：`LOG2_MAX_FRAME_NUM=4`、`LOG2_MAX_POC_LSB=5` 等）。其他分辨率/帧率需要调整这些宏。
2. **PROF 目标值来自 C6359（ILCE-7M4 HD 60p 录制）**。不同相机型号可能不同。
3. **缩略图模板 `tools/thumb_header.bin`**——从相机缩略图（C6359T01.JPG）的前 764 字节提取，存在于工作区。如果从零开始重建，需要先在 K: 上找到任一相机缩略图运行 `$f=[byte[]](Get-Content K:\...\CXXXXT01.JPG -Encoding Byte -TotalCount 764); Set-Content tools\thumb_header.bin -Encoding Byte -Value $f`。

4. **MEDIAPRO.XML 末尾可能有 `0x20` 填充**（索尼相机对齐），编辑时不要破坏。
5. **缩略图不影响播放**——C0003 无缩略图也能正常播放和预览。
