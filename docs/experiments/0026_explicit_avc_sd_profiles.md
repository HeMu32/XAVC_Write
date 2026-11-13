# 实验 0026：扩展显式 AVC SD Profile

日期：2026-11-13。仅处理 SD 卡，不处理 CFexpress。

**最新状态：用户已实机确认 C6518、C6517、C6515 均正常。**
Cat 的 HD50M59.94、UHD60M29.97 新生成片段已在7M4回放成功，25M对照也重新确认。
本文保留离线准备与顺序写入过程；末尾“实机结果”绑定用户报告和写入文件哈希。
准备期验证报告保留当时的 `NOT_TESTED`，不是对当前成功结果的否定。

## 范围与证据等级

把已实机成功的 Cat 1080p25M59.94、8-bit 4:2:0 流程扩展到：

| CLI profile | 尺寸 | 帧率 | 标称视频码率 | AVC | GOP / 分块帧数 |
|---|---|---|---|---|---|
| `hd25_5994`，原默认 | 1920x1080 | 60000/1001 | 25Mbps | High@4.2 / yuv420p | 30 |
| `hd50_5994` | 1920x1080 | 60000/1001 | 50Mbps | High@4.2 / yuv420p | 30 |
| `uhd60_2997` | 3840x2160 | 30000/1001 | 60Mbps | High@5.1 / yuv420p | 15 |

三者都使用立体声 LPCM16BE / 48kHz、Rec.709、双 HRD、4-byte NAL
length、闭合 GOP、2 B / no B-pyramid / ref=2 / 4 slices。这里的 CBR
是编码器和 HRD 配置，不能把含封装开销的整段实际平均码率等同于标称码率。

**历史 EDIUS 成功不是这次 ffmpeg 文件的实机验证。**
25M 的 C6514/C6515 和本轮新增的 C6517 / C6518 都已有直接用户成功报告。
新片段成功依据是用户本次实机反馈，不是软件全量解码或局部固件探针。
拖动、完整时长完成、音频和缩略图正常与否没有单独报告，不补写这些观察。

## 历史记录与原始样本核对

参考资料：

- [0008：EDIUS 4K 成功](0008_edius-sample-camera-success.md)。
- [0011：历史 HD 修整](0011_deblock-bitstream-surgery.md)。
- [旧 HD50M 配方](../patching-recipe.md)，仅作为历史证据，不执行其旧覆盖写卡步骤。
- [0025：25M 实机矩阵](0025_source_control_and_compact_container.md)。

历史 HD 修整涉及 PPS/slice deblocking 参数及 PROF 等修改；0011 已有后续
固件证据的范围警告，不能把某个 flag 当作所有播放失败的普遍根因。
本次 libx264 自带完整 deblocking 语法，不对其 VCL 执行旧 EDIUS 专用手术。
0008 记载的是 EDIUS 原始 4K C0001 成功，不能据此虚构一份 4K 专用 patch
清单。新输出复用当前的 SPS VUI / dual-HRD / SEI-BP 修整及一致的四字节封装。

开始时检查了现存 snapshot 格式，再对可读的 F: 制作
`backup/snap_20261113T130454`：69 个非媒体文件、137 个媒体清单项、零错误。
只从卡复制了历史 `C0001.MP4` 到本地，不修改卡上资源。

| 本地参考 | SHA-256 | 用途 |
|---|---|---|
| `analysis/C0001-reference-0026.MP4` | `927fb7c9a622943bfbde54a976a89b05da5de28740012e2d4b93b1c7b857d8bd` | 4K EDIUS 结构、RTMD、UUID 型 UMID label |
| `analysis/C0007-reference-0023.MP4` | `8b0d2c7794ec633b508da6bc93043b009b5468dd3aa0ac38a5e5e292261f773a` | HD EDIUS 结构、RTMD、UUID 型 UMID label |
| `analysis/C6359-reference-0023.MP4` | `50b110211712a816677f9bef60eb882baf0e5365135b8d4c07aa76260dda21ee` | 有效 native PROF 来源，不复制其传感器 RTMD |

容器实测记录：`analysis/profile-reference-boxes-0026.json`。

| 项目 | HD C6359 / C0007 | UHD C0001 |
|---|---|---|
| 视频 / RTMD 时基 | 60000 | 30000 |
| 每帧 duration | 1001 | 1001 |
| 每个完整分块 | 30 视频帧 | 15 视频帧 |
| SPS VUI tick / scale | 2002 / 240000 | 4004 / 240000 |
| XML `tcFps` / `halfStep` | 30 / true | 30 / false |
| PROF 帧率字 | native C6359 `003BF0A6` | EDIUS C0001 `001DF853` |

PROF 帧率字按实际值明确保留；没有从这两个样本推导普遍的取整规则。
HD EDIUS 原始的 `...A7` 与 native `...A6` 的区别保留在历史记录中。

C0007 的 PROF 在旧实验中被错位改写，是 opaque 历史成功样本，不能拿来
当新文件的有效 PROF。新 builder 拒绝这种模板，使用 C6359 的有效单轨
High 4:2:0 VPRF，明确改 level、两份码率、两份帧率字及尺寸，保留其余属性。
HD50M 生成的整个 PROF 与 C6359 逐字节一致。

**UHD 的限度：** C0001 的实际 VPRF 两份码率是 57000 / 99999，不是
60000 / 60000。本轮使用 native-style 的 60000 / 60000，现已在 C6518 的
完整组合中实机成功；这不是声称已经取得原生 UHD60M4208 样本的精确 descriptor。
现有相机原生
4K29.97 示例多为 4:2:2 10-bit，不能挪用它们的 SPS 充当本 profile 依据。
也没有把 EDIUS 的 open-GOP 编码路径与本轮 closed-GOP 候选混为一谈。

## 不能只改编码参数

`tools/sony_profiles.py` 是三种配置的单一显式定义。默认仍为 `hd25_5994`。
`--profile` 同时传给 encoder 和 builder，manifest 记录名称和完整参数。

| 位置 | 本轮覆盖的编辑 |
|---|---|
| 编码器 | scale/pad/fps、High level、bitrate/min/max/buf、GOP、movie/video timescale |
| SPS VUI | 校验实际帧率，输出对应 tick/240000，复制 NAL HRD 到 VCL HRD |
| 基础流准入 | SPS / avcC / avc1 尺寸和 level、8-bit420、progressive、CBR rate/buffer；拒绝重复 SPS ID |
| SEI | 扩充 BP，按真实 NAL/VCL 字节数分别重计初始 delay / offset |
| NAL 封装 | 每一个 NAL 重写 4-byte length；同时更新 avcC、stsz 和全部 track offsets |
| PROF | 单独处理 level、两份码率、两份帧率字、width/height |
| 二进制尺寸 | 视频 avc1 VisualSampleEntry 和 tkhd 16.16 尺寸均更新，不能只改 XML |
| 采样表 | 视频 / RTMD cadence、ctts、stss、elst、轨道与 movie 时基和 duration |
| PCM | `floor(N * 48000 * fps_den / fps_num)`，所有分块边界用同一公式；base 与结构模板的音频描述都须为 twos/2ch/16-bit/48kHz |
| RTMD | 区分 half-step；模板校验后明确把起始时码归零，全部包重新计时 |
| 内嵌 / sidecar XML | codec、layout、capture/format fps、halfStep、首尾 LTC、duration、UMID |
| MEDIAPRO | 新 Material 的 videoType 和 fps 跟随 profile，不再硬编码 HD59.94 |
| DATABASE | 继续 observed_minimal，只新增内容记录并保留旧记录；不虚填视频参数 |
| 验证准入 | schema 5 增加必需的 `selected_profile_consistent`，旧报告须重验 |

`native_reuse` 中的完整 binary video-parameter 映射没有扩展证据，因此新两个
profile 在此模式明确拒绝。它们只走已实机成功路径的 `observed_minimal`：
复用 C0007 的稀疏 support，不写它本来省略的 video parameters / UMID / TC。
这并不意味着任意其他格式都能采用同一路径。

### RTMD 证据

以下是全部 packet 对比，不是只看首包：

| 参考 | packet 数 | RTMD 全部字节 SHA-256，生成值等于参考 |
|---|---|---|
| HD C0007 | 14170 | `a05726bdc50ea8f81c448b75aa840c15ff5deee0d872a666a42534054900ad19` |
| UHD C0001 | 90 | `d7fc2dd50b4d9648f3fac040f9928602b970f910b9b5d5bd98e63279bd4ee6d5` |

对应 `analysis/rtmd-reference-0026-*.json`。UHD 原种子起始时码为
`51140100`，即 00:01:14:11；验证参考时保留这个起点，新候选则把
13..17、20..23 的两套已识别时间字段显式归零，并与 XML 的零起点一致。
其他字节保持 opaque；逐字节匹配不是对其全部语义的逆向证明。
UHD 90 包只覆盖约 3 秒，分钟 / 十分钟 / 24 小时回绕另由合成单元测试覆盖，
不能声称那些边界也已由历史 UHD 参考证实。

## 本地候选和复现

以下目录保留离线准备时的独立编录，不能把两份编录依次直接写卡。实际部署另建
写卡副本并逐段重新 stage，见“后续写入”。**C6517 / C6518 现已占用**；
复现时必须选新目录与新空号，不能照抄编号覆盖已存在的资源。

| 本地包 | 片段 | 状态 |
|---|---|---|
| `output/profiles-0026-hd50/package` | C6517 | 同哈希位流已实机正常；实际写卡包见后续写入 |
| `output/profiles-0026-uhd60/package` | C6518 | 同哈希位流已实机正常；实际写卡包见后续写入 |
| `output/profiles-0026-regression25/package` | C6516 | 本地旧 profile 回归，不是另一份已上机文件 |

以下 PowerShell 在工作区根目录运行。输出目录必须全新。先检查每条外部命令的
`$LASTEXITCODE`；失败即停止。完整写卡步骤及五文件清单见
[25M 完整复现手册](../sd-xavcs-reproduction.md)，本节只给 profile 差异与离线构建。

```powershell
$Py = 'E:\anaconda3\envs\test311\python.exe'
$Profile = 'hd50_5994'
$Clip = 'C6517'
$Run = 'output/profiles-0026-hd50'
$Edius = 'analysis/C0007-reference-0023.MP4'
```

UHD 改为：

```powershell
$Profile = 'uhd60_2997'
$Clip = 'C6518'
$Run = 'output/profiles-0026-uhd60'
$Edius = 'analysis/C0001-reference-0026.MP4'
```

共同流程：

```powershell
& $Py tools/encode_xavc.py Cat_25-12-25.mp4 --profile $Profile --output "$Run/encode" --threads 6 --preset slow
if ($LASTEXITCODE -ne 0) { throw 'Encode failed' }
& $Py tools/build_sony_clip.py --profile $Profile --base "$Run/encode/base.mov" --camera analysis/C6359-reference-0023.MP4 --edius $Edius --structure-template $Edius --umid-mode edius_uuid4 --payload-layout structure_template --nal-length-size 4 --retime-hrd --acquisition rec709 --clip $Clip --output "$Run/package"
if ($LASTEXITCODE -ne 0) { throw 'Build failed' }
& $Py tools/build_sony_thumbnail.py --clip "$Run/package/$Clip.MP4"
if ($LASTEXITCODE -ne 0) { throw 'Thumbnail failed' }
& $Py tools/stage_sd_catalog.py --snapshot backup/snap_20261113T130454 --build "$Run/package" --template-number 7 --catalog-representation observed_minimal
if ($LASTEXITCODE -ne 0) { throw 'Stage failed' }
& $Py tools/verify_sony_package.py --build "$Run/package"
if ($LASTEXITCODE -ne 0) { throw 'Verification failed' }
& $Py tools/verify_staged_catalog_firmware.py --build "$Run/package"
if ($LASTEXITCODE -ne 0) { throw 'Firmware catalog checks failed' }
& $Py tools/emulate_xavc_reader.py "$Run/package/$Clip.MP4" --snapshot backup/snap_20261113T130454 --output "$Run/package/firmware-reader.json" --seek-probe --seek-mode 1 --sample-batches 1 --decode-table-probe --rtmd-probe --max-runtime-seconds 120
if ($LASTEXITCODE -ne 0) { throw 'Selected reader checks failed' }
```

该历史快照仅用于重演本次离线检查；真正写卡必须使用新快照重新 stage，
重新验证、原固件检查、preflight 和逐文件读回。每段片段写入仍然只有
MP4 / sidecar XML / JPG 三份新资源，加 MEDIAPRO / DATABASE 两份编录；
没有额外手工 patch 或旧片段覆盖步骤。

## 25M 回归

使用先前 `output/runbook-check-20261113T104516/encode/base.mov` 重新封装。
`analysis/profile-regression25-payload-0026.json` 证明新旧包：

- 整个 mdat（含全部 AVC、PCM、RTMD）字节一致。
- 全部 track indexed payload、duration、stts/ctts/stss、sample descriptions 一致。
- 绝对 sample table 字节也一致，首 payload 同为 192。

这避免用“测试通过”替代对已成功路径的实际数据回归证据。
新旧完整文件哈希不同是 UMID / 日期等身份字段变化，不是声称文件整体相同。

## 本轮检查结果

| 项目 | C6517 / HD50M | C6518 / UHD60M |
|---|---|---|
| 帧数 / 时长 | 1534 / 25.592233秒 | 767 / 25.592233秒 |
| 实际打包视频码率 | 50.564289Mbps | 60.550391Mbps |
| LPCM sample-frame 数 | 1228427 | 1228427 |
| SPS HRD rate / buffer | 50000000 / 50000000 bits | 60000000 / 60000000 bits |
| 新鲜全量解码 + base framemd5/时间戳 | 通过 | 通过 |
| 音频对齐后逐字节一致 | 通过 | 通过 |
| 全部 SEI / 容器 timing、slice order、选定 CPB 检查 | 通过 | 通过 |
| 所有 RTMD 包 / XML / PROF / 轨道尺寸 / profile 一致性 | 通过 | 通过 |
| 最小编录重建、旧记录不变、校验和 | 通过 | 通过 |
| 只读部署 preflight，无 `--apply` | 通过 | 通过 |
| 写卡 / 实机 | 已写入 / 用户确认正常 | 已写入 / 用户确认正常 |

新 MP4 SHA-256：

```text
C6517 7cdf31983a5f759f3dd297f4a3029c0d3427ae430a34ac0a7f655cddbc40917c
C6518 fcc118a82af71ba849954724c240134fd17c686cc66400d016919f8913307845
```

每包的 `verification.json` 绑定七份资源和 transaction 的哈希，同时保存独立
`verification_runs/run-*` 的新鲜解码及 timing/slice/CPB 日志。
25M 回归包也通过当前 schema5 的完整媒体与编录验证。
额外收紧了 edit-list origin：视频 media_time 在同一媒体时基下必须与 base
一致，音频 / RTMD media_time 必须为零，并有三个轨道的独立篡改反例。

每个新包的 `firmware-catalog-verification.json` 都通过全部9组检查，
独立核对各自50个片段的原始 record conversion、嵌套 readers、恢复路径、
MEDIAPRO 加载 / 查找 / clip-info 与 UMID；源数据库和固件代码段保持不变。
两包分别只新增 record97，原94条 active records 全部保持字节一致，49条
旧 Material 的语义保持一致。不能把两份 stage 当作一个累计51片段的编录。

原固件媒体探针每包完成30次选定调用：打开 / 查询、首个 I-only sample batch、
sample index、原始 SPS/PPS 及 frame-table 转换，对 RTMD 的首 / 次 / 末包
执行原始转换和时码查询。全部返回成功，代码段保持原样。
**它只验证了每个候选的一个 I 帧索引，不覆盖其余 P/B 或完整时长硬件播放。**
报告为各包 `firmware-reader.json`，含原始 runtime helper 的实际 hash。

`analysis/profile-vcd-guards-0026.json` 另以两个真实 trace 执行18组已映射
scalar helpers：每份固件副本各639个测试值，两份真实 trace 的选定字段均
未被修正或标错。没有 emulation 自定义解码指令或硬件，不声称完整 decoder
通过；报告列出缺失的 trace fields 和实际检查范围。

准备时的验证报告保留 `camera_playback=NOT_TESTED`，不追改历史阶段的状态。
本轮实际相机成功另存 `analysis/camera-observations-0026-result.json` 和各写卡包的
`camera-result.json`；不会用历史 EDIUS、Catalyst 或固件局部探针冒充实机反馈。

独立代码复核找到了结构模板音频描述与重复 SPS ID 两处准入缺口，均已补齐
拒绝逻辑和反例测试。当前两个 base 和结构模板在收紧后的真实文件准入中通过。
未发现本轮候选实际存在这两种异常。

只读卡审计 `analysis/card-unchanged-profiles-0026.json`：无新增 / 缺失文件、
69份元数据哈希无变化、137份媒体的大小 / mtime 无变化。媒体未全部重算内容
哈希，此结论不扩大为全卡每字节重验。没有新 `deployment.json`，没有运行
`--apply`，没有删卡文件或覆盖既有片段。

最终完整测试：`python -m unittest discover -s tools/tests`，
**185 tests passed / 210.363秒**。本文3个 PowerShell 代码块经实际
PowerShell AST 解析，零语法错误。只读 preflight 在最终媒体验证后重新通过。
`git diff --check` 仍提示用户既有 `AGENTS.md` 第一行尾空白，本轮未修改该文件，
未为了消除此提示清理无关用户改动。

## 后续写入

用户明确要求准备存储卡以供实机测试后，于同日顺序部署两个候选。
保留原离线包，复制 MP4 / sidecar / thumbnail / build-manifest 四份本地文件
到以下独立写卡目录，分别执行 fresh stage、完整 verification、原固件编录
检查和部署。新旧候选 MP4 哈希一致，没有重新编码或暗中替换位流。

| 写入顺序 | 写卡包 | 生成编录依据 | 新 record | 原固件检查 |
|---|---|---|---|---|
| C6517 | `output/profiles-0026-deploy/C6517` | `backup/snap_20261113T133359`，49 movies | 97 | 50 movies，通过 |
| C6518 | `output/profiles-0026-deploy/C6518` | `backup/snap_20261113T133821`，C6517写后50 movies | 98 | 51 movies，通过 |

两包都通过新鲜全量解码 / PCM / timing / slice / CPB / profile / RTMD / 编录
验证。C6518 从实际中间状态重新 stage，没有使用旧的独立50片段编录覆盖卡。
实际 `--apply` 命令如下，每条均在对应新鲜验证及原固件编录检查通过后执行：

```powershell
& 'E:\anaconda3\envs\test311\python.exe' tools/deploy_sd_clip.py --card F:/ --build output/profiles-0026-deploy/C6517 --apply
if ($LASTEXITCODE -ne 0) { throw 'C6517 deployment failed' }
# C6517 readback -> new snapshot -> stage/verify C6518 -> original firmware checks.
& 'E:\anaconda3\envs\test311\python.exe' tools/deploy_sd_clip.py --card F:/ --build output/profiles-0026-deploy/C6518 --apply
if ($LASTEXITCODE -ne 0) { throw 'C6518 deployment failed' }
```

部署程序各自自动制作写前快照：

- C6517：`backup/snap_20261113T133805`。
- C6518：`backup/snap_20261113T134040`。
- 最终快照：`backup/snap_20261113T134101`，71份非媒体 / 141份媒体清单、零错误。

`analysis/sd-test-round-0026.json` 全部检查通过，六份新资源和最终两份编录的
读回哈希全部匹配。`analysis/snapshot-133359-134101-0026.json` 进一步确认：

- 只新增 C6517 / C6518 各自的 MP4、M01.XML、T01.JPG，共6份。
- 仅更新 `PRIVATE/M4ROOT/MEDIAPRO.XML` 和 `PRIVATE/DATABASE/DATABASE.BIN`。
- Active records 94 -> 96，movies 49 -> 51；仅启用97、98，无旧记录修改 / 停用。
- 旧 Material 未移除或修改，旧媒体大小 / mtime 无变化，无文件删除。
- 最终51片段原固件编录报告的哈希与卡上两份编录一致，包含两个新片段。

写前另对 C0007 / C6515 重新计算完整哈希，分别与已知成功参考
`8b0d2c...f773a` / `f6815d...f63e5` 相符；累计审计没有把其余旧媒体的大小 /
mtime 检查扩大声称为全卡内容哈希。没有格式化、主动修复 / 重建编录或覆盖
任何既有 MP4/XML/JPG。**C6516 仍只是本地回归包，卡上三个对应资源均不存在。**

最终编录哈希：

```text
DATABASE.BIN 58ce96ff2e4c66f2d932e23d99ee30a6090f91dad934963fdac370ed5328ab6b
MEDIAPRO.XML 3b3e9d22ca3a5e5fb14ebbb7ee9e4230e17bb2272233d024e464e018ccde4de7
```

测试表为 `analysis/camera-test-round-0026.json`。建议先用未改写的 C6515 作对照，
再测试 C6517（HD50M59.94）、C6518（UHD60M29.97）；两者均8-bit420，约25.6秒。
分别记录列出 / 缩略图 / 播放 / 完整时长 / seek / 音频，不要求无法取得的
详细相机日志。准备时实机字段为 `NOT_TESTED` 或 null；现已依据下述反馈更新测试表。

## 实机结果

2026-11-13，用户直接报告：

```text
6518 ok
6517 ok
6515 ok
```

沿用此前明确的7M4机身上下文，未报告换用其他机身；实际安装固件版本未单独确认。

| 片段 | 配置 | 本次结果 |
|---|---|---|
| C6518 | Cat，3840x2160 / 30000/1001p / 60M / High@5.1 / 8-bit420 | 用户确认正常回放 |
| C6517 | Cat，1920x1080 / 60000/1001p / 50M / High@4.2 / 8-bit420 | 用户确认正常回放 |
| C6515 | 原有 Cat，1920x1080 / 60000/1001p / 25M / High@4.2 / 8-bit420 | 对照重新确认正常 |

机器记录：

- `analysis/camera-observations-0026-result.json` 保存原始用户报告及三个确切媒体哈希。
- `analysis/camera-test-round-0026.json` 更新为 `PHYSICAL_PLAYBACK_CONFIRMED`。
- 两个写卡包各有 `camera-result.json`；C6515 另存 `camera-result-0026.json`，
  保留其原有0025结果，不覆盖历史记录。

本次记录时核对了本地候选文件、部署日志、七文件验证哈希和累计写入审计，
均能对应前述已读回成功的卡文件。**本次未访问存储卡**，未声称有机身测试后的
新快照或新读回哈希；准备期 `verification.json` 和审计仍保留原来的阶段状态。

由此，三个显式 profile 都已有 Cat 输入经 ffmpeg编码、SPS/SEI及封装修整、
最小 SD 编录、新增资源写入到7M4回放成功的具体证据。UHD C6518 所用
60000 / 60000 PROF 在这个组合中可用，不必把历史 EDIUS 的57000 / 99999
视为本次必需值；但没有由此逐一隔离所有元数据、GOP或修整字段的必要性。

正常回放意味着片段能被访问 / 列出，但缩略图、seek、完整25.6秒完成和音频没有
分别确认，记录为未单独报告。此结论不扩大到任意输入、长片段、其他机身、
CFexpress、规范认证或“所有历史失败已有统一根因”；C6507 / C6509 的历史
独立失败对照仍未在本轮重测。
