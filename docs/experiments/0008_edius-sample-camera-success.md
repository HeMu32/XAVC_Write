# Experiment 0008: EDIUS 样本写入相机 — 成功

Date: 2026-06-25

## 结论

Sony 认证软件 (EDIUS) 生成的 XAVC-S 样本 **被相机正确识别并解码**。
这是首次确认软件生成的 XAVC-S 片段可以在 ILCE-7M4 上播放。

## 样本来源

`T:\TestXAVCFolder\M4ROOT\CLIP\C0001.MP4` — 由 EDIUS (Sony 认证的非线性编辑软件) 转码生成。
非相机直出, 非我们构造。我们只是将其写入了存储卡。

## 样本格式

| 属性 | 值 |
|---|---|
| Profile | H.264 High (profile_idc=100), 4:2:0, 8-bit |
| 分辨率 | 3840×2160 |
| 帧率 | 29.97p (30000/1001) |
| 时长 | 3.003s, 90帧, 6 GOP × 15 |
| GOP | Open GOP, 2 B-frames, b_pyramid=0 |
| 视频码率 | ~57 Mbps |
| 音频 | PCM 16-bit big-endian (`twos`), 48kHz, 2ch |
| 容器 | ftyp=XAVC, compatible: XAVC/mp42/iso2 |

### 容器结构 (C0001.MP4)

```
ftyp (28B)          XAVC v0x01001FFF
uuid PROF (148B)    FPRF + APRF(twos) + VPRF(avc1)
mdat (~22MB)        6 chunks, 交替排列 rtmd→video→audio
moov
  mvhd              timescale=90000
  trak 1 (video)    avc1/avcC, edit list (media_time=1001), USMT uuid
  trak 2 (audio)    twos, 48kHz stereo, USMT uuid
  trak 3 (rtmd)     data track, tref→video, 90×1024B samples, USMT uuid
  meta              hdlr="nrtm", xml=NonRealTimeMeta
```

### SPS 关键参数

| 参数 | 值 |
|---|---|
| profile_idc | 100 (High) |
| chroma_format_idc | 1 (4:2:0) |
| bit_depth | 8 |
| max_num_ref_frames | 2 |
| video_full_range_flag | 0 (TV range) |
| colour_primaries | 1 (BT.709) |
| nal_hrd_parameters_present | 1 |
| vcl_hrd_parameters_present | 1 |
| fixed_frame_rate_flag | 1 |
| bitstream_restriction_flag | 0 |
| pic_struct_present_flag | 0 |
| num_units_in_tick | 4004 |
| time_scale | 240000 |

### PPS 关键参数

| 参数 | 值 |
|---|---|
| entropy_coding_mode | CABAC |
| weighted_pred_flag | 0 |
| weighted_bipred_idc | 0 |
| chroma_qp_index_offset | 0 |
| transform_8x8_mode_flag | 1 |
| pic_scaling_matrix_present | 1 (自定义量化矩阵, PPS 87字节) |
| second_chroma_qp_index_offset | 0 |

## 写入方式

C0001.MP4 替换了卡上原有的 AX700 录制的 C0001.MP4。
这不是新增片段, 而是替换已有编录条目。

### 文件系统修改

| 文件 | 操作 |
|---|---|
| `CLIP/C0001.MP4` | 用 EDIUS 样本覆盖 (22,086,323 bytes) |
| `CLIP/C0001M01.XML` | 用 EDIUS 样本 sidecar 覆盖 (Duration=90) |
| `THMBNL/C0001T01.JPG` | **未更新** — 仍为原始 AX700 缩略图 (需修复) |

### MEDIAPRO.XML 修改

C0001 条目更新: `dur="45"→"90"`, `umid` 改为 EDIUS 样本的 UMID (`0D23` 变体)。

### DATABASE.BIN 修改

clip table 当前位于 `0x10F04` (相机重建过 DB, 与 backup 中的 `0xFE024` 不同)。

C0001 记录 (`02 00 18 02` AX700 格式) @ `0x10F04`:
- `+0x70` (文件大小近似值): 更新为 22,089,651 (≈ 22,086,323 + 3,328 delta)
- 其余字段未改动 (时间戳、LTC 等仍是 AX700 原始值)

**block trailers 未重新计算** — 相机正常识别。trailers 的功能仍属未知。

## 工具

### xavc_build.c (C/gcc)

`C:\Users\HeMu\AppData\Local\Temp\opencode\xavc_build.c`

用 ffmpeg muxed MP4 + C0001 模板, 构造 3-track XAVC-S 容器:
- 从 base MP4 提取 video/audio sample tables (stts, ctts, stsc, stsz, stco, stss)
- 从模板提取 ftyp, PROF, rtmd data, meta XML
- 重建 moov: 修正 audio stsd (ipcm→twos), 调整 stco delta, 添加 USMT uuid + rtmd trak + meta
- 输出: ftyp + PROF + mdat + moov

编译: `gcc -O2 -Wall -o xavc_build.exe xavc_build.c`

用法: `xavc_build.exe <base.mp4> <template.mp4> <output.mp4>`

### 构造流程

```
# 1. ffmpeg 编码视频 + 复制模板音频
ffmpeg -f lavfi -i "testsrc2=size=3840x2160:rate=30000/1001:duration=3" \
    -i C0001.MP4 -map 0:v -map 1:a \
    -c:v libx264 -profile:v high -level:v 5.1 -pix_fmt yuv420p \
    -x264-params "keyint=15:min-keyint=15:..." \
    -c:a copy -f mp4 base.mp4

# 2. C 程序构造完整容器
xavc_build.exe base.mp4 C0001.MP4 output.mp4
```

## 教训

1. **PowerShell 不适合字节操作** — `[byte] -shl` 不提升为 `[int]`, `Read-U32LE`/`Write-U32LE` 多次出错。以后所有二进制操作用 C。
2. **覆盖文件前必须备份** — 我覆盖了 K:\ 上原始 AX700 C0001.MP4, 无法恢复。
3. **block trailers 功能未知** — 修改 DB 后相机正常识别, 但这不能说明 trailers 是或不是校验和, 只能说这次修改没有被拒绝。
4. **EDIUS 样本的结构就是目标** — 不再猜测, 以 C0001.MP4 为标准。

## 下一步

1. **生成缩略图** — 用 ffmpeg 从 C0001.MP4 提取一帧, 生成 1280×720 JPEG 替换 C0001T01.JPG
2. **构造自制 XAVC-S** — 用 x264 编码 + xavc_build.c 构造, 以 C0001 为模板逐步对齐参数
3. **测试相机播放** — 将自制的 MP4 写入卡上, 验证相机能否解码
4. **新增片段 (非替换)** — 需要在 DATABASE.BIN 中追加 CLIP 记录 + INDEX 条目, 更新计数器

## 当前 K:\ 状态

- C0001 = EDIUS 样本 (相机可播放) ✓
- C0002 = 已删除 (文件 + DB 记录 + MEDIAPRO) ✓
- C0001 缩略图 = 未更新 (原始 AX700 缩略图)
- 其余 26 个片段 = 相机原始录制, 未改动
