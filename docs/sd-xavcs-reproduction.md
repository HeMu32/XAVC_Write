# SD 卡 XAVC-S 25M 写入复现手册

更新日期：2026-11-13。工作区：`C:\Users\HeMu\Desktop\XAVC_Write`。

**修复数据库后的模板选择：** 用户执行“修复影像数据库”后，C0007已从稀疏模板
变为完整记录，下述不带额外参数的`observed_minimal` stage仍会拒绝直接套用。
实验0028增加显式`--template-snapshot`：历史快照仅提供稀疏描述，并核对其全部
支持／路径依赖与当前库相同；分配和所有旧记录始终来自新鲜卡快照，绝不能把
修复前整库写回。新参数与HD29.97 50M/16M步骤见
[实验0028](experiments/0028_hd2997_50m_16m.md)。
本文下述成功过程仍保留为修复前历史记录；修复后使用时须显式选择独立模板来源。

本文是**操作手册和完整编辑清单**，不是早期实验笔记。主路线复制已经在
ILCE-7M4 实机正常回放的 **C6515** 配置：1920x1080、60000/1001p、
nominal 25Mbps、AVC High@4.2、8-bit 4:2:0、Rec.709、双声道 48kHz
16-bit big-endian PCM，使用 SD 卡 `PRIVATE/M4ROOT` 编录。

50M HD59.94 和 60M UHD29.97 的显式 profile 扩展、命令差异和实机结果见
[实验0026](experiments/0026_explicit_avc_sd_profiles.md)。用户已确认 C6517 /
C6518 正常，C6515 对照也重新确认正常；三种配置均为8-bit420，已具备本次
Cat 输入在7M4回放的具体证据，其他输入仍需验证。本文继续以25M作为主操作示例；
新脚本默认不变，也可以显式传入 `--profile hd25_5994`。
当前 verification schema 为5，增加 profile 贯穿一致性检查；旧的 schema4
报告仍是历史证据，写卡前须用当前脚本重新验证，不能改版本号来绕过检查。

HD29.97 的50M（C6519）和16M（C6520）也已获用户正常回放反馈，详见
[实验0028实机结果](experiments/0028_hd2997_50m_16m.md)。
目前五个显式profile都有Cat输入的具体实机证据，仍不是任意输入保证。

依据：

- [实机结果](C:/Users/HeMu/Desktop/XAVC_Write/analysis/camera-observations-0025-result.json)。
- [实验 0025](C:/Users/HeMu/Desktop/XAVC_Write/docs/experiments/0025_source_control_and_compact_container.md)。
- [成功包 C6515](C:/Users/HeMu/Desktop/XAVC_Write/output/cat-compact4-C6515/build-manifest.json)。
- [整轮写入审计](C:/Users/HeMu/Desktop/XAVC_Write/analysis/sd-test-round-0025.json)。
- [50M / UHD60M 实机结果](C:/Users/HeMu/Desktop/XAVC_Write/analysis/camera-observations-0026-result.json)。

## 1. 范围和不可省略的约束

1. **只适用于本工作区已经识别的 SD 编录布局，不适用于 CFexpress。**
2. 已实机证实的是 Cat 输入和 C6514/C6515；其他输入仍须完整验证和实机检查。
3. 正式候选必须明确使用 **4-byte NAL length**。不能只把 `avcC` 改成 4-byte，
   而保留 3-byte 样本。C6512/C6513 是已确认不能播放的诊断对照，不是复现目标。
4. 使用 `observed_minimal` 编录，模板编号为 7。这是已经实机成功的描述形式，
   不是声称补齐所有字段的原生写入器。
5. **不删除卡上文件，不覆盖任何已有片段或其 XML/JPG。**只新增三个片段资源，
   更新两份现有编录。不得格式化卡、主动重建/修复编录、运行旧的原地补丁脚本。
6. 每次卡接回电脑，先制作新快照；每写完一个片段，下一个片段必须从新的卡状态
   重新 stage。不能重复使用下面举例的历史快照写当前卡。
7. 阶段验证通过后，不手工修改输出文件、manifest 或 transaction。任何修改都使
   原验证失效。重新 stage 后也必须重新验证。
8. 当前 builder 在内存中构建载荷，输出必须小于 4GiB；没有自动分卷。长视频须先
   在工作区拆分并分别验证。不要将本文理解为任意长度/格式的通用导入器。
9. 每段命令必须成功退出才继续。PowerShell 的 `$ErrorActionPreference` 本身
   不能可靠代替外部程序退出码检查，下面提供统一的检查函数。

## 2. 一个文件究竟改哪些地方

以尚未占用的 `C6516` 为例。**6516 仅是示例，不是已保留的空号。**

### 卡上写入清单

| 顺序 | 目标路径，以卡根目录为基准 | 操作 |
|---|---|---|
| 1 | `PRIVATE/M4ROOT/CLIP/C6516.MP4` | 独占创建新文件 |
| 2 | `PRIVATE/M4ROOT/CLIP/C6516M01.XML` | 独占创建新文件 |
| 3 | `PRIVATE/M4ROOT/THMBNL/C6516T01.JPG` | 独占创建新文件 |
| 4 | `PRIVATE/M4ROOT/MEDIAPRO.XML` | 写入已验证的完整 staged 文件 |
| 5 | `PRIVATE/DATABASE/DATABASE.BIN` | 写入已验证的完整 staged 文件 |

注意数据库的路径是 **`PRIVATE/DATABASE/DATABASE.BIN`**，不是旧笔记中的
`PRIVATE/M4ROOT/AVBINF/DATABASE.BIN`。

本路线**不修改**旧的 MP4/XML/JPG、任何 `AVBINF` 文件、照片目录或其他管理文件。
不需要新增 C6511 来源对照，也不需要再生成 C6512/C6513 失败对照。

### 工作区文件清单

| 阶段 | 创建/更新的本地文件 |
|---|---|
| 快照 | `backup/snap_<timestamp>/` 下的非媒体文件镜像、四份清单/摘要 |
| 编码 | `encode/base.mov`、`input-probe.json`、`input-assumptions.json`、`encode-command.json`、`encode.log` |
| 封装 | `package/C6516.MP4`、`C6516M01.XML`、`build-manifest.json` |
| 缩略图 | `C6516-160.yuv`、`C6516-160.jpg`、`C6516-1280.yuv`、`C6516-1280.jpg`、`C6516T01.JPG` |
| 编录 stage | `catalog/DATABASE.BIN`、`catalog/MEDIAPRO.XML`、`catalog/transaction.json` |
| 软件验证 | `verification.json`、每次独立的 `verification_runs/run-*/` 日志、framemd5、timing/slice/CPB JSON |
| 固件编录验证 | `firmware-catalog-verification.json` |
| 选定固件媒体探针 | 本次运行目录中的 `firmware-reader.json` |
| 写入 | `package/deployment.json`，并自动再做一份写卡前快照 |
| 收尾 | 读回/累计审计 JSON、写后快照、快照差异 JSON |
| 实机结果 | 单独记录 `camera-result.json`；不改写历史验证报告冒充实机证据 |

中间的 MOV/YUV/JPG、日志、manifest、transaction、验证报告都**不复制到卡上**。

## 3. 工具、模板和依赖

不要只复制本文而遗漏工作区的脚本/二进制依赖。使用当前工作区的完整 `tools`
目录，以及下表中的本地参考文件。

| 文件/程序 | 用途及必须保留的性质 |
|---|---|
| `E:\anaconda3\envs\test311\python.exe` | Python 3.11 环境；不要误用 PATH 中缺包的 base Python |
| PATH 中的 `ffmpeg`、`ffprobe` | 需要 libx264、colorspace、bwdif、PCM MOV、trace_headers/framemd5 等现有功能 |
| `tools/jpeg422.exe`、`tools/jpeg422.c` | 专用 4:2:2 JPEG 编码；不是视频的 4:2:0 参数 |
| `tools/thumb_header.bin` | 已使用的 764-byte EXIF/缩略图头模板 |
| `output/native-control-C6507/C6507.MP4` | **只作为有效 PROF/轨道模板来源**，不是已证明可播的原生对照 |
| `analysis/C0007-reference-0023.MP4` | 完整本地参考；用于 ftyp/轨道结构、最小 RTMD 种子及 UUID 型 UMID 标签 |
| `analysis/camera_observations_20261112_233331.json` | stage 程序读取的旧观测结构，包含 C0007 的已列出证据；不可改动以免破坏历史哈希绑定 |
| `firmware/m4-v602/usr/lib/libmpr.so` | 固件读函数验证，SHA-256 固定检查 |
| `firmware/m4-v602/usr/lib/libexpat.so.1.6.11` | 固件 XML 解析依赖 |
| `firmware/m4-v602/usr/lib/libstdc++.so.6.0.22` | 选定媒体探针读取的原始运行库，路径在现有 probe 中明确指定 |
| Python `unicorn`、`elftools` | 原固件代码探针；优先使用已经配置好的 test311 |

不要将上述固件依赖替换成其他版本。libmpr/expat 的固定哈希检查失败时停止，
不要删除检查；媒体探针还会记录实际 libstdc++ 哈希和调用到的原始 helper。
文档核对时的本机 Python 为3.11.13，PATH中ffmpeg为
`n8.0.1-64-g15504610b0-20260226`；这些是本机实测版本，不是“最新版本”声明。

固定参考的 SHA-256：

```text
output/native-control-C6507/C6507.MP4
87e49bcb2d8f79536413dcc22498c780587d550cbd7fc98e23e545812afa3764

analysis/C0007-reference-0023.MP4
8b0d2c7794ec633b508da6bc93043b009b5468dd3aa0ac38a5e5e292261f773a

tools/thumb_header.bin
8ce5331dfd4a62823f34e84b0b5394d70ca4da060dc4c89df36484164edeb7fd

tools/jpeg422.exe
d3d31eef659d1754e39032f96cd4e4956f56e41df33bebfe16ea2c3e4d3c3d9e
```

`C0007` 的 PROF 曾被早期补丁改写，不能拿它当新 25M 文件的有效 PROF。
本路线刻意将 `--camera` 和 `--structure-template` 分开，不能合并这两个参数。
这里也没有使用 EDIUS 重新编码或调用 Catalyst 导出。

## 4. 初始化 PowerShell 会话

以下 PowerShell 代码块按顺序在**同一会话**执行。不要执行本文的 XML/二进制说明
作为额外补丁；所有数据编辑已由列出的 Python 脚本完成。复现不需要编辑 `.py`
或 `.c` 源码；手动输入的是本节路径/编号变量和第13节实际观察结果。

```powershell
$ErrorActionPreference = 'Stop'
$Root = 'C:\Users\HeMu\Desktop\XAVC_Write'
$Py = 'E:\anaconda3\envs\test311\python.exe'
$Card = 'F:\'
$Clip = 'C6516'
$InputVideo = Join-Path $Root 'Cat_25-12-25.mp4'
$Run = Join-Path $Root ('output\reproduce-' + $Clip + '-' + (Get-Date -Format 'yyyyMMddTHHmmss'))
$Encode = Join-Path $Run 'encode'
$Build = Join-Path $Run 'package'
$BaseVideo = Join-Path $Encode 'base.mov'
$CameraTemplate = Join-Path $Root 'output\native-control-C6507\C6507.MP4'
$EdiusTemplate = Join-Path $Root 'analysis\C0007-reference-0023.MP4'
$Observations = Join-Path $Root 'analysis\camera_observations_20261112_233331.json'

Set-Location -LiteralPath $Root
function Invoke-CheckedPython {
    param([Parameter(Mandatory=$true)][string[]]$ArgList)
    & $Py @ArgList
    if ($LASTEXITCODE -ne 0) {
        throw "Python step failed with exit code $LASTEXITCODE"
    }
}
if ($Clip -notmatch '^C[0-9]{4}$') { throw 'Expected C plus four digits' }
if (Test-Path -LiteralPath $Run) { throw 'Use a fresh local run directory' }
foreach ($Path in @($Py, $InputVideo, $CameraTemplate, $EdiusTemplate,
                    $Observations, (Join-Path $Root 'tools\jpeg422.exe'),
                    (Join-Path $Root 'tools\thumb_header.bin'))) {
    if (-not (Test-Path -LiteralPath $Path -PathType Leaf)) { throw "Missing: $Path" }
}
Get-Command ffmpeg, ffprobe
New-Item -ItemType Directory -Path $Run | Out-Null
```

可先确认本地参考没有变：

```powershell
$References = @(
    @{ Path=$CameraTemplate; Hash='87e49bcb2d8f79536413dcc22498c780587d550cbd7fc98e23e545812afa3764' },
    @{ Path=$EdiusTemplate; Hash='8b0d2c7794ec633b508da6bc93043b009b5468dd3aa0ac38a5e5e292261f773a' },
    @{ Path=(Join-Path $Root 'tools\thumb_header.bin'); Hash='8ce5331dfd4a62823f34e84b0b5394d70ca4da060dc4c89df36484164edeb7fd' },
    @{ Path=(Join-Path $Root 'tools\jpeg422.exe'); Hash='d3d31eef659d1754e39032f96cd4e4956f56e41df33bebfe16ea2c3e4d3c3d9e' }
)
foreach ($Reference in $References) {
    $Actual = (Get-FileHash -LiteralPath $Reference.Path -Algorithm SHA256).Hash
    if ($Actual -ne $Reference.Hash) { throw "Reference changed: $($Reference.Path)" }
}
```

尚未创建 `$Encode` 和 `$Build` 是有意的，编码程序要求新输出目录。
`$Run` 必须在本地工作区，不能指向存储卡。

## 5. 第一项卡操作：快照和空号检查

先查看既有快照的格式，例如
`backup/snap_20261113T014211/_snapshot.json`，再生成**当前卡**的新快照。

```powershell
$SnapshotText = Invoke-CheckedPython -ArgList @(
    'tools/card_snapshot.py', '--card', $Card, '--output', (Join-Path $Root 'backup')
)
$SnapshotInfo = ($SnapshotText -join [Environment]::NewLine) | ConvertFrom-Json
if (@($SnapshotInfo.errors).Count -ne 0) { throw 'Snapshot has errors' }
$Snapshot = $SnapshotInfo.snapshot
$Snapshot
```

快照复制所有非媒体文件并校验 SHA-256；图片/视频不复制，写入
`_skipped_media_manifest.csv` 的大小及创建/写入/访问时间。其他输出为
`_metadata_manifest.csv`、`_dir_state.csv`、`_snapshot.json`。
这不是所有旧媒体内容的全备份。

接着检查三个目标文件、数据库和 MEDIAPRO，不能只检查 MP4 文件名：

```powershell
foreach ($Relative in @(
    "PRIVATE\M4ROOT\CLIP\$Clip.MP4",
    "PRIVATE\M4ROOT\CLIP\${Clip}M01.XML",
    "PRIVATE\M4ROOT\THMBNL\${Clip}T01.JPG"
)) {
    if (Test-Path -LiteralPath (Join-Path $Card $Relative)) {
        throw "Clip asset already exists: $Relative"
    }
}
$InventoryPath = Join-Path $Run 'database-before.json'
Invoke-CheckedPython -ArgList @(
    'tools/sony_db.py', (Join-Path $Snapshot 'PRIVATE\DATABASE\DATABASE.BIN'),
    '--output', $InventoryPath
)
$Inventory = Get-Content -LiteralPath $InventoryPath -Raw | ConvertFrom-Json
$ClipNumber = [int]$Clip.Substring(1)
if (@($Inventory.records | Where-Object {
    $_.content_type -eq 2 -and $_.clip_number -eq $ClipNumber
}).Count -ne 0) { throw 'Clip number already exists in DATABASE.BIN' }
[xml]$Profile = Get-Content -LiteralPath (Join-Path $Snapshot 'PRIVATE\M4ROOT\MEDIAPRO.XML') -Raw
foreach ($Material in $Profile.SelectNodes("//*[local-name()='Material']")) {
    if ($Material.GetAttribute('uri') -eq "./CLIP/$Clip.MP4") {
        throw 'Clip URI already exists in MEDIAPRO.XML'
    }
}
```

如卡号、编录或模板状态与脚本支持的结构不符，停止分析，不要通过清空记录、复制
历史 DATABASE 或删除冲突文件来“修复”。

## 6. 从输入重新编码 MOV 基底

```powershell
Invoke-CheckedPython -ArgList @(
    'tools/encode_xavc.py', $InputVideo, '--output', $Encode,
    '--threads', '6', '--preset', 'slow'
)
```

程序用 ffprobe 选第一个非封面视频轨和第一个音轨。根据输入时间戳处理偏移，输出
有限长度；没有音轨时生成双声道静音。核心编码参数是：

```text
-c:v libx264 -preset slow -profile:v high -level:v 4.2 -pix_fmt yuv420p
-b:v 25000k -minrate 25000k -maxrate 25000k -bufsize 25000k
-x264-params nal-hrd=cbr:filler=1:force-cfr=1:keyint=30:min-keyint=30:scenecut=0:bframes=2:b-adapt=0:b-pyramid=none:ref=2:weightp=0:weightb=0:open-gop=0:slices=4:aud=1:repeat-headers=0:deblock=0,0
-color_range tv -colorspace bt709 -color_primaries bt709 -color_trc bt709
-c:a pcm_s16be -ar 48000 -ac 2
-video_track_timescale 60000 -movie_timescale 60000 -write_tmcd 0 -f mov
```

视频处理包含：归零时间戳、对标记为隔行的画面 bwdif 去隔行、处理输入 SAR、
真正转换到 limited-range BT.709、等比缩放并补边到 1920x1080、转换到
`fps=60000/1001`。Cat 原输入的 gamma22 被转换，不是只改成 Rec.709 标签。
音频按照输入相对视频起点的时间偏移重新采样/对齐，截到视频长度。

应检查 `input-assumptions.json`；缺失色彩标签时脚本会记录采用的假设。
HDR/PQ/HLG 和不支持的转换会被拒绝，不能靠删检查或强贴 Rec.709 标签绕过。
完整实际 ffmpeg argv 保存在 `encode-command.json`，不要用本节摘要替代它。

`base.mov` 不是可直接放卡的最终 XAVC-S：仍缺少本路线的专门封装、RTMD、
NRT、缩略图和卡编录。

若只是复现**已经成功的相同编码数据**而不重新编码，可跳过本节，将
`$BaseVideo` 指向 `output/cat-rec709-base-C6508/base.mov`，并校验其 SHA-256 为
`605b2ec6f9e9234f54f4f7e1e967bd7b7e650d7b7afb44d5a4600fcb4309a09c`。
这叫复用已编码基底，不要记作“本轮重新编码”。不得误用旧 gamma22 基底。

## 7. 构造三个轨道、内外 XML 及新身份

主路线完整参数如下，**不要省略参数而落回早期默认模板/UMID模式**：

```powershell
Invoke-CheckedPython -ArgList @(
    'tools/build_sony_clip.py',
    '--base', $BaseVideo,
    '--camera', $CameraTemplate,
    '--edius', $EdiusTemplate,
    '--structure-template', $EdiusTemplate,
    '--umid-mode', 'edius_uuid4',
    '--payload-layout', 'structure_template',
    '--nal-length-size', '4',
    '--retime-hrd',
    '--acquisition', 'rec709',
    '--clip', $Clip,
    '--output', $Build
)
```

这一步创建 MP4、旁文件 XML、build-manifest；没有写卡。新 UMID 是观察到的
16-byte EDIUS 标签 `060a2b340101010501010d2313000000` 加新的 UUID4 材料号，
不能复制旧 UMID，也不能把 Sony 的时间/MAC 材料号生硬接在这个标签后面。

C6515 路线的布局为：

```text
ftyp                 XAVC，模板的 minor version / iso2 compatibility
uuid PROF            来自有效 native-template，改为 25M，不能来自 C0007 opaque PROF
mdat extended header 16 bytes
  每最多30帧一组: rtmd -> video -> audio
moov
  mvhd
  video trak: avc1/avcC, edts, sample tables, 原模板的 USMT
  audio trak: twos, edts, sample tables, 原模板的 USMT
  metadata trak: rtmd, tref/cdsc -> video track 1, edts, sample tables, USMT
meta
  hdlr
  xml : 与旁文件一致的 NonRealTimeMeta
```

本模板下首个 mdat payload 在文件偏移 **192**，不添加 131072 对齐用的 free。
这里 ftyp 的来源与 PROF 的来源不同，是成功方案的有意设计。

完整的内部编辑见第 15 节；尤其包括 SPS VUI 和 SEI/HRD 处理，
**不是仅仅重新 mux 或修改一个 avcC 字节**。最终所有视频 NAL 长度都是
4-byte big-endian，并且样本大小、偏移和盒尺寸重新计算。

`--no-retime-hrd`、`--diagnostic-framing-control`、Sony 型 UMID、其他 acquisition
都不是本文成功主路线，不应在首次复现时混用。

## 8. 生成专用缩略图

```powershell
Invoke-CheckedPython -ArgList @(
    'tools/build_sony_thumbnail.py', '--clip', (Join-Path $Build "$Clip.MP4")
)
```

程序提取最终 MP4 首帧，分别生成 160x120 和 1280x720 的 raw YUV422，再调用
`jpeg422.exe` 编码，组合相机式 EXIF/嵌入缩略图结构。不能用一个普通 ffmpeg
JPEG 直接替代。这里 JPEG 为 4:2:2，最终视频仍为 4:2:0。

如果 EXE 不在而需要本机重新编译，现有源码对应旧编译命令如下；编译后的二进制
哈希会改变，应另行记录并验证，不能冒称上面的已用 EXE：

```text
gcc -o tools/jpeg422.exe tools/jpeg422.c -IC:/MinGW/include -LC:/MinGW/lib -ljpeg -O2
```

## 9. 只在工作区更新两份编录

```powershell
Invoke-CheckedPython -ArgList @(
    'tools/stage_sd_catalog.py',
    '--snapshot', $Snapshot,
    '--build', $Build,
    '--template-number', '7',
    '--catalog-representation', 'observed_minimal',
    '--observations', $Observations
)
```

程序从**本次快照**的 DATABASE 和 MEDIAPRO 创建 staged 文件。应看到：

- 只新增一个内容记录，`modified_existing_records` 为空。
- 复用 C0007 的已观察到的稀疏视频属性记录；不伪造新增完整视频属性。
- `catalog_schema=3`、`catalog_representation=observed_minimal`。
- 不分配/增加 UMID array 记录；省略的视频参数、UMID 和时码被明确记为省略。
- MEDIAPRO 只新增一个 Material，原材料语义不变。
- transaction 包含当前快照路径、两份编录 before/after SHA-256、记录编号、
  时间、模板及观察证据哈希。

**本阶段仍没有改卡。**完整字段和校验和操作见第 16、17 节。
不能手动把 C0007 记录直接追加到文件末尾，也不能把 record index 当成 clip number。

## 10. 验证整个包和原固件编录读路径

先做软件/结构验证：

```powershell
Invoke-CheckedPython -ArgList @(
    'tools/verify_sony_package.py', '--build', $Build
)
$Verification = Get-Content -LiteralPath (Join-Path $Build 'verification.json') -Raw | ConvertFrom-Json
if (-not $Verification.passed -or $Verification.verification_profile -ne 'encoded_avc') {
    throw 'Candidate package did not pass complete current verification'
}
```

它重新运行两个完整视频 framemd5 解码，检查帧数/帧时间/解码像素一致性；比较
基底 PCM 与最终 PCM（按目标样本数修剪/补零后的期望值）；检查 SEI/容器时间、
slice 顺序、选定 CPB 约束；核对 4-byte framing、PROF、XML、UMID、Rec.709、
两份编录、旧记录/材料保留、精确最小编录重建，以及完整七文件哈希绑定。

独立原固件编录检查也要运行：

```powershell
Invoke-CheckedPython -ArgList @(
    'tools/verify_staged_catalog_firmware.py', '--build', $Build
)
$FirmwareCatalog = Get-Content -LiteralPath (Join-Path $Build 'firmware-catalog-verification.json') -Raw | ConvertFrom-Json
if (-not $FirmwareCatalog.passed) { throw 'Original firmware catalog verification failed' }
```

它执行已有 libmpr 原始记录转换、调用到的嵌套读函数和 MEDIAPRO 解析/查询；
检查包括新片段在内的所有电影集合、路径、计数、UMID 和原始代码未改动。
**当前 deploy 程序不会自动调用/强制检查这个单独的固件报告，因此操作人不能漏掉。**
分析库来自M4 v6.02，不代表用户实机安装的固件版本；实际机身版本应单独记录。

为保持与成功实验同样的选定媒体探针覆盖，再运行：

```powershell
Invoke-CheckedPython -ArgList @(
    'tools/emulate_xavc_reader.py', (Join-Path $Build "$Clip.MP4"),
    '--snapshot', $Snapshot,
    '--seek-probe', '--seek-mode', '1',
    '--sample-batches', '1', '--decode-table-probe', '--rtmd-probe',
    '--max-runtime-seconds', '120',
    '--output', (Join-Path $Run 'firmware-reader.json')
)
```

这是第一帧 I-only、参数准备/表构建及选定 RTMD 包的探针，**不是正常连续播放、
硬件解码或真实快进测试**。软件/固件超时是工具未完成，不是“相机拒绝”。
失败时停止，不要删除错误检查、改报告中的 passed 或将旧报告拷贝来充数。

## 11. 最后检查和实际写入

写前可对照起始快照，检查卡在离线处理期间是否变化：

```powershell
Invoke-CheckedPython -ArgList @(
    'tools/audit_card_snapshot.py', '--card', $Card, '--snapshot', $Snapshot,
    '--output', (Join-Path $Run 'before-write-audit.json')
)
Invoke-CheckedPython -ArgList @(
    'tools/deploy_sd_clip.py', '--card', $Card, '--build', $Build
)
```

第二条不带 `--apply`，只应输出预检通过、没有卡修改。
deploy 检查当前 verification schema/profile/全部检查、完整七文件哈希、
三个目标资源不存在，以及**两份当前卡编录**与 transaction 的 before 哈希完全相同。

确认无误后，下面这条才真正写卡：

```powershell
Invoke-CheckedPython -ArgList @(
    'tools/deploy_sd_clip.py', '--card', $Card, '--build', $Build, '--apply'
)
$Deployment = Get-Content -LiteralPath (Join-Path $Build 'deployment.json') -Raw | ConvertFrom-Json
if ($Deployment.status -ne 'deployed' -or -not $Deployment.existing_files_unchanged) {
    throw 'Deployment not cleanly complete; keep the card connected and investigate'
}
```

实际写入顺序就是第 2 节的五个文件。每个新资源使用独占创建，流式复制、
flush/fsync、SHA-256 读回。编录更新前再次检查 before 哈希，写后 flush/fsync
和读回。deploy 会**自动再做一次写前快照**，路径写在 deployment.json 中。

不需要额外复制文件、追加 XML 行或手工编辑 DATABASE；这些操作已经包含在 stage
的两个完整文件中。`Copy-Item` 三个媒体资源而漏掉这两份编录，不是完整写入流程。

## 12. 写后验证、快照及审计

只写一个片段时也可以使用累计审计工具：

```powershell
Invoke-CheckedPython -ArgList @(
    'tools/audit_sd_test_round.py', '--card', $Card, '--before', $Snapshot,
    '--build', $Build, '--output', (Join-Path $Run 'readback-audit.json')
)
$AfterText = Invoke-CheckedPython -ArgList @(
    'tools/card_snapshot.py', '--card', $Card, '--output', (Join-Path $Root 'backup')
)
$AfterInfo = ($AfterText -join [Environment]::NewLine) | ConvertFrom-Json
if (@($AfterInfo.errors).Count -ne 0) { throw 'Closing snapshot has errors' }
$AfterSnapshot = $AfterInfo.snapshot
Invoke-CheckedPython -ArgList @(
    'tools/compare_sd_snapshots.py', $Snapshot, $AfterSnapshot,
    '--output', (Join-Path $Run 'snapshot-diff.json')
)
```

必须确认：只新增三文件，旧文件不丢失；只改两个旧编录；旧媒体大小/修改时间
不变；旧数据库记录不变；旧 Material 语义不变；新增 movie/Material 各一条，
所有已验证文件的读回哈希匹配。旧媒体不全部计算内容哈希，不要据此宣称全卡
逐字节审计。

如果需要再次执行全部软件验证并同时校验当前卡的五文件，可运行：

```powershell
Invoke-CheckedPython -ArgList @(
    'tools/verify_sony_package.py', '--build', $Build, '--card', $Card
)
```

这只读卡，但会重写工作区的 verification.json 并新建 verification_runs。
必须在这个包仍拥有当前最终编录时运行；写入下一个包以后，前包的 staged
catalog 不再等于当前卡编录。多包收尾应按实际部署顺序给 audit_sd_test_round
重复传 `--build`，由最后一包提供最终编录。

## 13. 安全弹出、实机结果和下一次写入

所有命令结束并审计通过后，正常弹出卡，放入 7M4，先按正常回放验证，
不主动修复/重建编录。分别记录：

| 项目 | 应如何记录 |
|---|---|
| 列出 | 是否出现在回放界面，不能从桌面播放推定 |
| 缩略图 | 是否正常，和视频播放单独记录 |
| 播放 | 开始播放/是否正常，失败时原文，如“无法显示” |
| 完整时长 | 是否真正播完，没测试就写未测试 |
| 快进/跳转 | 是否实际操作并通过，不能从 emulator 的 seek-mode 推定 |
| 音频 | 是否听过并正常 |
| 机身/固件 | 记录实际机身和已知固件版本，不从分析固件文件推定 |

结果写到该本地包的独立 `camera-result.json`，包含片段编号、日期、机身、
build-manifest 的 media SHA-256、实际报告来源及上述各项。没报告的项不能填成功。
不要把预部署 verification.json、transaction.json 中历史 NOT_TESTED 直接改为
成功；它们与结果报告的时间和作用不同，且前者有哈希绑定。

卡再次连回后，**先重新快照再分析变化**，再决定是否添加下一个片段。旧包不能再
执行 `--apply`：它的文件已存在，编录基线也可能已过期。

## 14. 失败、重试和恢复规则

| 情形 | 正确处理 |
|---|---|
| 编码/封装失败 | 保留日志，用新本地目录重做；未写卡，不需要改卡 |
| 同号文件/数据库条目已存在 | 换一个确认空闲的新号，不覆盖、不删除 |
| snapshot 或验证失败 | 停止；检查输入、依赖、模板和报告，不改 passed |
| 卡在 stage 后变化 | 重新快照；归档本地 catalog 后从新基线 stage，再重做全部验证 |
| stage 目录已经存在 | 不直接覆盖它；确认需重 stage 时使用 `--archive-local-stage` |
| 写入途中异常 | 查看 deployment.json；保持卡连接，先快照/比对，不盲目再次写 |
| 已成功写入后想撤销 | 本手册没有删除步骤；需用户另行明确授权并单独设计撤销事务 |

重新 stage 的参数是第 9 节的同一组参数，加上 `--archive-local-stage`，
并把 `$Snapshot` 换成**新快照路径**。这只将本地 catalog 改名归档，不删除卡文件。
随后必须重新运行第 10 节，不能复用旧 verification。

deploy 的异常处理会尝试恢复本次已触及的两个编录：正在写入的编录从本次自动
快照恢复；已完成的编录只有仍匹配本事务写入哈希时才恢复。**不会删除已经复制
或复制一半的新 MP4/XML/JPG。**因此失败后通常需要新的片段号。

这个事务没有断电原子性，两份编录之间存在更新窗口；异常恢复也可能遇到拔卡/
I/O 错误。不能把它当作文件系统 journal，也不能随意拿旧快照覆盖相机后来新增的
记录。任何恢复动作都应先核对当前卡、deployment 和快照的具体状态。

## 15. MP4、XML、RTMD、缩略图的完整编辑清单

本节解释脚本到底编辑什么，供审计/重实现使用，**不是在第 7、8 节后再手动执行**。

### 15.1 AVC 与 HRD

脚本：`build_sony_clip.py`、`avc_sony.py`、`avc_hrd.py`。

| 对象 | 操作 |
|---|---|
| 编码 VCL、PPS、编码相关 SPS 参数 | 不用相机参数集替换；不执行旧 deblock/slice 位流手术 |
| SPS VUI timing | 要求原视频为 60000/1001；归一化为 `num_units_in_tick=2002`、`time_scale=240000`、fixed=1 |
| SPS HRD | 要求已有 NAL HRD；复制其参数为 VCL HRD，拒绝对已有 VCL HRD 的结果重复打补丁 |
| Buffering-period SEI | 为新增的 dual HRD 扩展对应 delay/offset；再执行 CBR 时序 retiming |
| CBR retiming | 基于实际 NAL/VCL 位数和 1001/60000 cadence 选择/修正 BP delay/offset，manifest 逐个记录 |
| 非 BP SEI、AUD、VCL NAL 顺序 | 不因 3/4-byte reframing 而删除或重排 |
| 最终 sample framing | 每个 NAL 前写 4-byte big-endian 长度；`avcC.lengthSizeMinusOne=3`，即长度字段字节通常为 `0xff` |
| 长度、偏移 | 由最终样本重新构建 stsz/stco/mdat/盒尺寸，不只改 avcC 声明 |

注意：实现内部先产生 3-byte 形式供现有 retimer 使用，再通过
`--nal-length-size 4` 转为最终格式。不能截取中间步骤作为成品，也不能对已经
归一化的最终 MP4 再执行同一套 SPS 补丁。CPB 验证的计数点不包含 MP4 长度前缀；
软件通过也不代表真实硬件解码保证。

### 15.2 音频和 RTMD

- 音频源是新编码 MOV 的 stereo PCM16BE，不是复制相机或 EDIUS 音轨。
- 对 N 帧，目标 PCM stereo sample-frame 数为 `floor(N * 1001 * 4 / 5)`，
  每个 sample-frame 4 bytes；过长修剪、过短补零，manifest 记录两种数量。
- metadata 轨每视频帧一个 1024-byte RTMD。使用本地 C0007 第一包作为种子，
  原模板须以零时码开始且符合 `sony_rtmd.py` 的结构检查。
- 逐包更新 offsets13..15 的十进制时/分/秒、offset16..17 的 big-endian 帧号，
  以及 offsets20..23 的 drop-frame/half-step 时码；其他种子字节保留。
- 不复制原片的传感器测量，不编造机身/镜头数据。

### 15.3 容器和 profile

| 对象 | 操作 |
|---|---|
| ftyp | 从 structure template 保留 XAVC、minor version、compatible brands |
| PROF UUID/FPRF/APRF | 从有效 CameraTemplate 复制结构 |
| VPRF | 保留 `avc1`、profile/level 等字节；在 VPRF payload 偏移20/24写 `25000/25000`，保留已核验59.94字段 |
| mdat | 16-byte extended header；每30视频帧依次 rtmd、video、audio；尾组按实际帧数 |
| mvhd | duration=`N*1001`、timescale=60000、更新创建/修改日期 |
| tkhd | 每轨 duration 使用 movie ticks；日期更新，其他模板固定字段保留 |
| mdhd | 视频/RTMD timescale60000、duration=N*1001；音频 timescale48000、duration=PCM sample-frame 数 |
| avc1/avcC | 固定 VisualSampleEntry 来源模板；使用本次编码归一化后的 SPS/PPS/4-byte length 配置 |
| twos/rtmd stsd | 保留匹配的模板 sample description |
| stts | 视频/RTMD `(N,1001)`；音频 `(samples,1)` |
| ctts/stss | 使用本次基底视频的 composition/sync 数据，不能从 C0007 拷贝另一段视频的表 |
| stsc/stsz/stco | 按最终30帧chunk安排、样本数、最终字节长度和实际文件位置重建 |
| edts/elst | 一条version0 edit；video media_time来自base MOV，成功样本为1001；音频/RTMD为0 |
| USMT、tref、media handler、dinf等 | 保留模板中相应轨道结构；metadata指向video track1 |
| 顶层meta | EDIUS样式hdlr加一份生成的NRT XML；没有移植 native iinf/iloc/idat 等额外结构 |
| 时间格式 | QuickTime header 时间使用Unix秒数+2082844800；当前脚本生成的NRT日期固定`+08:00` |

VPRF 的偏移以 **`VPRF` box payload 起点**为基准，不是通过全文件搜索字符串后的
任意偏移。不要照搬旧 50M 手工写字节的示例。

### 15.4 内嵌 NRT 与旁文件

生成同一份 UTF-8 XML，写入 MP4 顶层 `meta/xml ` FullBox 的 XML 部分，以及
`C6516M01.XML`。对本编码候选，二者 XML 字节相等。

| 元素/属性 | 写入内容 |
|---|---|
| NonRealTimeMeta / lastUpdate | 本次 stamp；命名空间 `urn:schemas-professionalDisc:nonRealTimeMeta:ver.2.00` |
| TargetMaterial / umidRef | 本次新UMID，须与manifest和MEDIAPRO一致 |
| Duration / value | N，单位视频帧，不是秒 |
| LtcChangeTable | tcFps=30、halfStep=true；frame0 increment和frameN-1 end |
| CreationDate | 本次stamp |
| TypicalUbit / KeyFrame | 全零ubit、frameCount=0 |
| VideoRecPort / VideoFrame | OTHERS；`AVC_1920_1080_HP@L42`；captureFps/formatFps=`59.94p` |
| VideoLayout | pixel=1920、numOfVerticalLine=1080、aspectRatio=16:9 |
| AudioFormat/AudioRecPort | 2ch；CH1/CH2、OTHERS、LPCM16 |
| RecordingMode | normal、cacheRec=false |
| AcquisitionRecord | CameraUnitMetadataSet下CaptureGammaEquation、CaptureColorPrimaries、CodingEquations均为rec709 |

不新增虚构的 Sony Device、机身序列号、镜头或采集传感器信息。

### 15.5 缩略图字节编辑

- 两张 JPEG 的头部段按 DQT、DHT、其他段、SOS及压缩载荷重新排列。
- 以 764-byte `thumb_header.bin` 组合嵌入160x120图和1280x720主图。
- header offset692 的 little-endian u32 改为嵌入JPEG长度。
- header offset4 的 big-endian u16 改为 `len(header)+len(embedded)-4`。
- 主JPEG去掉其独立SOI/EOI后拼接，最后写文件级 `ff d9`；检查APP1长度不溢出。

## 16. MEDIAPRO.XML 的所有编辑

脚本读取 `$Snapshot/PRIVATE/M4ROOT/MEDIAPRO.XML` 并在本地重序列化。
命名空间为 `http://xmlns.sony.net/pro/metadata/mediaprofile`。

1. 更新根 `createdAt` 为 stage 时间。
2. 保留所有旧 Material 的元素/属性/子节点语义与顺序。
3. 在 Contents 末尾新增一个 Material：

```xml
<Material uri="./CLIP/C6516.MP4"
          type="MP4" videoType="AVC_1920_1080_HP@L42"
          audioType="LPCM16" fps="59.94p" dur="N" ch="2"
          aspectRatio="16:9" offset="0" umid="NEW_UMID" status="none">
  <RelevantInfo uri="./CLIP/C6516M01.XML" type="XML"/>
  <RelevantInfo uri="./THMBNL/C6516T01.JPG" type="JPG"/>
</Material>
```

其中编号、N、NEW_UMID由本次实际manifest生成，不是字面占位符。
输出XML declaration为UTF-8、CRLF、Tab缩进，末尾用空格补齐：
大小取“原文件长度”和“新XML长度向上对齐1024”两者较大值，不缩小。

这里承诺的是**旧材料语义不变**，不是旧 MEDIAPRO 全文件字节不变；XML排版和
根时间本来会改变。不要额外补写第二份同名Material。

## 17. DATABASE.BIN 的所有编辑：observed_minimal schema3

以下偏移来自当前支持的 SD sidb 布局，非通用格式标准。所有数字/校验值由
`sony_db.py` 和 `stage_sd_catalog.py` 计算。**不要直接复制这些偏移写任意卡。**

### 17.1 前置检查与分配

- 要求 record stride=160、数据库分配长度符合capacity、头部各校验通过、
  所有非root活动记录校验通过。
- 按 clip_number 查找模板 C0007，不将“第7个记录”误认为C0007。
- 核验模板 movie offset6为0x18，预期省略区域为零；支持属性记录是预期的
  稀疏40-byte形式，payload为空。任何不同均拒绝。
- 从 header `0x7C44` 的 content cursor 之后查 bitmap，选择一个未使用且
  原160-byte槽全零的index。当前没有自动wraparound/回收旧槽。
- 新槽文件偏移为 `0x10000 + index*160`；它不是由片段号直接算出的。

### 17.2 新160-byte内容记录

先逐字节复制模板记录，再仅做下列编辑：

| 新记录相对偏移 | 编辑 |
|---|---|
| `+0x04`，u16 LE | `(generation << 1) | (旧最低bit)`；generation来自header0x7C40 |
| `+0x0E`，u16 LE | `(新clip_number << 2) | (旧最低2bits)` |
| `+0x10`，8 bytes | 用manifest stamp打包creation date |
| `+0x18`，8 bytes | 用stage时间打包update date |
| `+0x70`，u32 LE | MP4文件大小的高32bits |
| `+0x74`，u32 LE | MP4文件大小的低32bits；注意不是直接写一个LE u64 |
| `+0x78`，u32 LE | 最终T01.JPG长度 |
| `+0x9E`，u16 LE | 对前158bytes计算记录校验和 |

日期打包保留原标志位，编码年/月/日/时/分/秒/毫秒和半小时单位时区，准确算法是
`set_date()`；不要把Unix epoch直接写进去。其时间主体：

```text
packed = ((year-1900)&255)<<36 | month<<32 | day<<27
       | hour<<22 | minute<<16 | second<<10 | millisecond
high_u32 = (old_u32 & 0xff000001)
         | (((packed>>32)&0xfff)<<12)
         | ((timezone_half_hours & 127)<<1)
low_u32 = packed & 0xffffffff
```

其余模板字节全部保留，包括路径引用、属性引用、未知字段和省略形式。
现有路径模板引用和视频属性支持记录直接复用，不另建路径记录或修改旧支持记录。
不新增native video参数，不填入native时码，不创建UMID array；不会将随机UUID
材料号强行塞进需要creation-time重建的原生UMID布局。

### 17.3 全局区域

| 文件偏移 | 编辑 |
|---|---|
| `0x4000 + index//8` | 只设置该index的活动bitmap bit |
| `0x7C44`，u32 LE | content cursor改为新index |
| `0x7C80`，u32 LE | 总内容计数+1 |
| `0x7C88`，u32 LE | movie计数+1，与MEDIAPRO Material数一致 |
| `0x8010`，u64 LE | manifest stamp的packed_header_time |
| `0x8018`，u64 LE | stage时间的packed_header_time |
| 下述校验字段 | 重新计算并写入 |

`packed_header_time` 的年/月/日/时/分/秒/毫秒主体与上面的packed相同，
最高另加 `((timezone_half_hours + 0x60) & 255) << 44`。
本模式不改变 `0x7C4C` 的UMID-array cursor，不修改任何既有记录。

### 17.4 校验和

不是CRC，也不是随意保留旧值。共同算法：输入末尾补零到8byte倍数，按LE u64
求和，先对2^64截断，再对指定modulus取模。

- 记录：前158bytes，modulus=`0xFFF1`，结果u16 LE写在record+158。
- 全局/bitmap：modulus=`0xFFFFFFFB`，结果u32 LE写在下表字段。

| 输入区间，左闭右开 | 输出字段 |
|---|---|
| `[0x0000,0x3FFC)` | `0x3FFC` |
| bitmap从0x4000到0x7C00，每0x400 bytes一块 | `0x7C00 + (block_start-0x4000)/0x100` |
| `[0x7C40,0x7FFC)` | `0x7FFC` |
| `[0x8000,0xBFFC)` | `0xBFFC` |
| `[0xC000,0xFFFC)` | `0xFFFC` |

先更新bitmap校验，再更新四个全局区。重算未改变区域的结果通常与原来相同。
验证器检查分配bitmap只有新bit变化、旧记录逐字节不变、只新增一条movie、
数据库分配长度不变、所有指定校验有效，并重建新数据库以要求整文件完全相等。

## 18. 成功基准、替代布局和复现定义

成功 C6515：1534 frames，25.592233秒，MP4 SHA-256：

```text
f6815df190cda04a3dcd500aba0df6c4ac1859f22838297b337c3b2f1b0f63e5
```

新号会有新UMID、日期、编录分配位置；重新编码也可能因ffmpeg/libx264版本等
改变编码结果。**不要求新文件全哈希等于C6515**，要求本次完整验证通过并实机验证。
要检查处理的确来自哪份输入/编码，应查看该次probe、encode-command、日志、
build-manifest、七文件验证绑定、transaction、deployment和实机结果。

另一已实机成功的路线 C6514 保持4-byte和其余参数，只将第7节的
`--structure-template` 改为 `$CameraTemplate`，`--payload-layout` 改为
`camera_aligned`。对应native-style iso6和首payload131072，并添加free。
首次复现建议保持C6515主路线，不需要同时制作两种布局。

本工作区旧 `docs/patching-recipe.md` 是 **50M EDIUS原地修补历史记录**；
其旧盘符、旧数据库路径、原地覆盖和手工字段解释不是本文步骤。
这次成功流程不运行 `deblock_inject.exe`、`xavc_rebuild.exe`、
`build_thumbnails.ps1`，也不把Catalyst可播当作相机可播。

## 19. 文档验证记录

2026-11-13，在当前本机环境中完成下列检查：

- 全部15个PowerShell代码块通过PowerShell AST语法解析；没有将写卡代码块作为
  自动测试执行。
- 从手册原文提取并执行 `Invoke-CheckedPython` 函数，确认含空格的实参保持完整，
  Python返回7时会抛错阻止后续步骤。
- 从原始 `Cat_25-12-25.mp4` 新运行第6节的编码器，不是复用旧base MOV。
- 按第7、8节参数新建本地C6516封装及缩略图。
- 用已有 `backup/snap_20261113T014211` **作为离线测试夹具**，新stage一条记录，
  从94条活动记录/49个电影变为95条活动记录/50个电影；94条旧记录未改。
- 整包软件验证全部通过；原固件编录验证全部通过，覆盖50个电影。
- I-only/参数/表转换/选定RTMD媒体探针通过，仍只代表文档中注明的有限范围。

演练目录：
[output/runbook-check-20261113T104516](C:/Users/HeMu/Desktop/XAVC_Write/output/runbook-check-20261113T104516)。
摘要：[runbook-validation.json](C:/Users/HeMu/Desktop/XAVC_Write/output/runbook-check-20261113T104516/runbook-validation.json)。

```text
新编码base.mov SHA-256
2b15e052777ab73e735223cbb5dcb0b626174c7f47697b50f4338297ee6e3f4d

本地C6516.MP4 SHA-256
7dc7c3c2c0642a8b758f3ec5068c84c62f25a5ed7f1a82dbafcad8da3d8a57aa
```

**这份C6516没有部署，没有实机结果，也不构成当前卡的空号声明。**本次文档任务
没有访问或改写F:。实时快照、live preflight、实际写入和写后卡审计没有在此演练
中重跑；这些命令依据前述C6514/C6515已经实际成功的脚本和审计核对。
再次实际使用时，必须执行第5节取得当前快照，不能把这份离线stage拿来直接写卡。
新编码内容与历史成功编码不要求逐字节相同，仍需实际回放验证。
