# Experiment 0010: C0004 重编码尝试 — 全部失败

Date: 2026-06-25

## 背景

实验 0009 推测 C0004 不可播放的原因是 `deblocking_filter_control_present_flag=0`。本实验通过 x264 重编码验证此假设，并尝试多种方案使 EDIUS HD@59.94p 片段可在 ILCE-7M4 上播放。

**所有尝试均失败。**

## 关键事实纠正

1. **C6359 是相机录制片段**（非之前实验的合成品）。实验 0005/0006 的合成 C6359 已被相机新录制覆盖。C6359 确认可播放。
2. **Level 不是问题**。C6359（相机直出 HD@59.94p）使用 Level 4.2，与 C0004 相同。相机接受 L42。
3. **实验 0005-0007 的全部合成片段均被相机拒绝**。唯一成功的是 0008 中的 EDIUS 原生产出（C0001）。

## C0004 与可播放片段的确认差异

### PPS: deblocking_filter_control_present_flag

| 片段 | 来源 | 分辨率 | 帧率 | deblocking | 状态 |
|------|------|--------|------|-----------|------|
| C0001 | EDIUS | 4K | 29.97p | **1** | ✓ 可播放 |
| C0002 | EDIUS | 4K | 59.94p | **1** | — |
| C0003 | EDIUS | 4K | 29.97p | **1** | ✓ 可播放 |
| C0004 | EDIUS | HD | 59.94p | **0** | ✗ 不可播放 |
| C6359 | 相机 | HD | 59.94p | **1** | ✓ 可播放 |

C0004 是唯一 `deblocking=0` 的片段。但仅修复此参数并未解决问题（见下文）。

### SPS VUI（C0004 EDIUS vs C6359 相机）

| 参数 | C0004 (EDIUS) | C6359 (相机) | C0001 (EDIUS ✓) |
|------|-------------|------------|----------------|
| video_format | 0 (Component) | 5 (Unspecified) | 0 |
| video_full_range_flag | 0 | 1 | 0 |
| colour_primaries | 1 (BT.709) | 2 (Unspecified) | 1 |
| num_units_in_tick | 2002 | 2002 | 4004 |
| time_scale | 240000 | 240000 | 240000 |
| fixed_frame_rate_flag | 1 | 1 | 1 |
| nal_hrd | 1 | 1 | 1 |
| vcl_hrd | 1 | 1 | 1 |

C0001（可播放）与 C0004 有相同的 VUI 风格（full_range=0, colour=BT.709），因此 VUI 值本身不是阻塞点。

## 尝试记录

### 尝试 1: PPS 单 bit 翻转

将 C0004 原始 PPS 中 `deblocking_filter_control_present_flag` 从 0 翻转为 1（byte 0x8E→0xCE，文件偏移 0x7459EF3）。

- ffmpeg 解码报错（slice header 缺少 deblocking 参数，符合预期）
- **相机结果：仍不可显示**

### 尝试 2: x264 重编码（默认参数 + deblocking=1）

用 x264 重编码视频（`-profile:v high -level:v 4.2 -x264-params "deblock=0:0:ref=2:bframes=2:keyint=15:b-pyramid=0:nal-hrd=vbr:vbv-maxrate=60000:vbv-bufsize=60000"`），保留原始音频，用 `xavc_rebuild.c` 重建 XAVC-S 容器（ftyp + PROF + mdat + moov(3 tracks) + meta）。

x264 产出的 SPS/PPS 与 XAVC-S 有大量差异：
- `num_units_in_tick`: 1001 vs 2002
- `time_scale`: 120000 vs 240000
- `fixed_frame_rate_flag`: 0 vs 1
- `vcl_hrd`: 0 vs 1
- `max_num_ref_frames`: 3 vs 2
- `weighted_pred`: 1 vs 0

**相机结果：不可显示**

### 尝试 3: x264 + C6359 的 avcC 替换

将 x264 输出的 avcC 替换为 C6359（相机直出）的 avcC（262 bytes，包含完整 VCL HRD + 自定义 scaling lists）。

- **ffmpeg 解码失败**：`non-existing PPS 0 referenced`
- 原因：C6359 PPS 的 `pps_id=2`，但 x264 slice 引用 `pps_id=0`。不兼容。

### 尝试 4: x264 + C0004 原始 avcC（deblocking 补丁后）

将 x264 输出的 avcC 替换为 C0004 原始 avcC（PPS deblocking 字节 0x8E→0xCE）。

- **ffmpeg 解码失败**：
  - `Reference 2 >= 2`（x264 用了 3 ref frames，但 SPS max_num_ref_frames=2）
  - `top block unavailable for requested intra mode`（PPS scaling lists 与 x264 编码不匹配）
- 原因：不同编码器的 PPS 参数（scaling lists, weighted_pred, ref_idx 等）与 slice 数据必须自洽，不能交叉替换。

### 尝试 5: x264 weightp=0 + x264 自身 avcC

用 `weightp=0` 重编码（匹配 C0004 PPS 的 `weighted_pred=0`），使用 x264 自身的 SPS/PPS（不替换），重建容器。

x264 输出参数：
- `deblocking=1` ✓
- `weighted_pred=0` ✓
- `vcl_hrd=0` ✗
- `num_units_in_tick=1001` ✗
- `time_scale=120000` ✗
- `fixed_frame_rate_flag=0` ✗
- `max_num_ref_frames=3` ✗

**相机结果：不可显示**

## 核心困境

**不同编码器的 PPS 与 slice 数据不可交叉替换。** PPS 中的以下参数影响 slice header 的二进制结构，必须与 slice 编码一致：

1. `entropy_coding_mode_flag`（CABAC/CAVLC）
2. `bottom_field_pic_order_in_frame_present_flag`
3. `weighted_pred_flag` / `weighted_bipred_idc`
4. `deblocking_filter_control_present_flag`
5. `pic_scaling_matrix_present_flag`（影响反量化，错配导致 decode 错误）
6. `redundant_pic_cnt_present_flag`

因此，要么：
- **(A)** 在 C0004 原始 EDIUS 码流上做位流手术——向每个 slice header 注入 3 bit 去块参数（`disable=0, alpha=0, beta=0`），保留 EDIUS 的全部其他编码参数不变
- **(B)** 用 x264 编码后，仅补丁 SPS VUI 字段（timing, vcl_hrd），不替换 PPS——但需要 SPS 位流级补丁工具

## SPS VUI 补丁工具（未完成）

编写了 `tools/sps_patch.c` 用于补丁 x264 SPS 的 VUI 字段。工具存在解析 bug：
- NAL HRD 参数解析后位置偏移 5 bit（可能遗漏 `low_delay_hrd_flag` 等字段）
- 导致 `vcl_hrd_parameters_present_flag` 位置错误读取
- VCL HRD 插入逻辑不可靠

需要修复的 VUI 解析字段（按 H.264 spec E.2.1 顺序）：
```
... timing_info ...
nal_hrd_parameters_present_flag → nal_hrd_parameters()
vcl_hrd_parameters_present_flag → vcl_hrd_parameters()
low_delay_hrd_flag              ← 之前遗漏!
pic_struct_present_flag
bitstream_restriction_flag → [max_dec_frame_buffering 等]
```

## 工具

### tools/xavc_rebuild.c
从 x264 编码的 base MP4 + 原始 XAVC-S 模板构建完整容器。
```
xavc_rebuild <base.mp4> <template.mp4> <output.mp4> [avcc_src.mp4]
```
- base: ffmpeg/x264 输出（视频+音频）
- template: 原始 C0004（提供 ftyp, PROF, rtmd, meta XML）
- avcc_src: 可选，从另一个文件读取 avcC 替换

### tools/sps_patch.c（有 bug，未完成）
尝试补丁 SPS VUI timing 和 VCL HRD 参数。

### tools/avclevelpatch.c
AVC level 补丁工具（实验 0009 使用）。修改 avcC/PROF/XML 中的 level 字节。

## 下一步

1. **修复 sps_patch.c 的 VUI 解析**——正确处理 `low_delay_hrd_flag` 和所有 VUI 尾部字段，然后重试方案 B
2. **或实现位流手术（方案 A）**——在 C0004 原始 EDIUS 码流的每个 slice header 中注入 deblocking 参数，保留所有其他 EDIUS 参数
3. 考虑：相机是否检查 `max_num_ref_frames`？x264 输出 3 而非 2，这是否是方案 5 失败的原因之一？

## 当前 K:\ 状态

- C0004 = x264 重编码 v3（尝试 5），不可播放
- C0001/C0003 = EDIUS 原始，可播放
- C6359 = 相机录制，可播放
- 原始 C0004 备份在 R:\C0004.MP4
