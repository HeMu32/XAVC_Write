# Experiment 0009: 为什么 EDIUS 的 HD@60p 片段无法在相机上播放

Date: 2026-06-25

## 问题

- `C6359.MP4` (相机直出) — 可播放
- `C0003.MP4` (EDIUS 软件生成, 4K@29.97p) — **可播放**
- `C0004.MP4` (同一 EDIUS 软件, HD@59.94p) — **无法播放**

C0003 与 C0004 来自同一软件, 容器结构、PROF、ftyp、3-track 布局、NRT/rtmd 轨道
均完全一致。差别只可能在分辨率/帧率/level 等编码参数。

## 方法

对每个片段运行 `ffmpeg -bsf:v trace_headers` 提取权威 SPS/PPS 解码, 配合
`exiftool`、自写的 `avcC_parse.c`、`boxdump.c`, 逐一对比 SPS 字段与 MEDIAPRO
`videoType` 串。

## 关键对比 (SPS + MEDIAPRO videoType)

| 片段 | 来源 | 分辨率 | 帧率 | **level_idc** | videoType | 相机表现 |
|---|---|---|---|---|---|---|
| C5850 | 相机 4K 422 | 3840×2160 | 29.97p | **5.1** | AVC140_..._H422P@L51 | ✓ |
| C6358 | 相机 4K 422 | 3840×2160 | 29.97p | **5.1** | AVC140_..._H422P@L51 | ✓ |
| C6350 | 相机 HD HFR | 1920×1080 | 119.88p | **5.1** | AVC_1920_1080_HP@**L51** | ✓ |
| C0001 | EDIUS 4K | 3840×2160 | 29.97p | **5.1** | AVC_3840_2160_HP@L51 | ✓ (exp 0008) |
| C0003 | EDIUS 4K | 3840×2160 | 29.97p | **5.1** | AVC_3840_2160_HP@L51 | ✓ |
| **C0004** | **EDIUS HD** | **1920×1080** | **59.94p** | **4.2** | AVC_1920_1080_HP@**L42** | **✗** |
| C0002 | EDIUS 4K | 3840×2160 | 59.94p | **5.2** | AVC_3840_2160_HP@**L52** | (未测, 嫌疑大) |

**规律**: 凡是能在 ILCE-7M4 上播放的 XAVC-S 片段, 无论 HD 还是 4K, 也无论 29.97p
还是 119.88p, SPS 中的 `level_idc` 一律是 **51 (Level 5.1)**, MEDIAPRO/sidecar 中的
`videoType` 一律是 `@L51`。

C0004 用 Level 4.2, C0002 用 Level 5.2 — 都不是 L51。理论上 L4.2 足以承载
1080p59.94 (H.264 表格允许), 但 Sony 的解码器/索引器不接受。

## C0004 与 C6350 (相机 HD) 的 SPS 逐字段对比

只有以下字段在 SPS 中不同 (除分辨率/帧率外):

| 字段 | C0004 (失败) | C6350 (相机 HD) | 备注 |
|---|---|---|---|
| **level_idc** | **42 (4.2)** | **51 (5.1)** | **首要嫌疑** |
| video_format | 0 (Component) | 5 (Unspecified) | 视觉提示, C0001/C0003 也是 0 且能播放 |
| video_full_range_flag | 0 (TV) | 1 (Full) | C0001/C0003 也是 0 且能播放 |
| colour_primaries | 1 (BT.709) | 2 (unspec) | C0001/C0003 也是 1 且能播放 |
| transfer_characteristics | 1 | 2 | 同上 |
| matrix_coefficients | 1 | 2 | 同上 |
| num_units_in_tick | 2002 (60p) | 1001 (120p) | 时间基, 跟帧率绑定 |
| pic_struct_present_flag | 0 | 1 | C6350 因为是 HFR; C0001/C0003 也是 0 且能播放 |
| bitstream_restriction_flag | 0 | 1 | C0001/C0003 也是 0 且能播放 |

色彩/全范围/pic_struct/bitstream_restriction 这些字段, 在已确认可播放的 EDIUS
4K 样本 (C0001/C0003) 中都与 C0004 相同 (都是"软件风格"), 与相机直出不同。
所以这些**不是**导致 C0004 失败的原因。**唯一独有 C0004 的异常变量是
`level_idc = 42`**。

## 其它结构差异 (不构成阻塞)

- **mvhd timescale**: C0003=90000, C0004=60000。仅影响容器层时间表示, 与解码无关。
- **frame_cropping_flag**: C0004=1 (1088→1080 底部裁剪 8 像素), C6350 也是 1。
  这是 HD 1080 在 H.264 中的标准做法 (1080 非 16 的倍数), 不是问题。
- **mdat 大小字段使用 64-bit (size=1)**: C0001/C0003/C0004 都是这样, 不是问题。
- **PPS 字节差异**: 仅 `pic_init_qp_minus26` 一类内容相关字段, 与可播放性无关。

## 结论

**根本原因: H.264 Level 不匹配。**

ILCE-7M4 的 XAVC-S 播放路径对 `level_idc` 有硬性要求, 必须是 51 (Level 5.1),
不论实际分辨率/帧率。EDIUS 在导出 HD@59.94p 时按 H.264 规范选择了最低够用的
Level 4.2 (`@L42`), 4K 高码率片段选择了 Level 5.2 (`@L52`)。两者都不是 L51,
因此被相机拒绝。

这与 C0001/C0003 (4K@L51) 能播放、C6350 (相机 HD@L51) 能播放的现象完全一致。

注意: 这是**软件分流器/解码器层面**的检查, 而不是文件索引层面 — C0003 与 C0004
的 DATABASE.BIN/MEDIAPRO.XML 条目结构完全相同 (软件写入, 相机接受编目), 区别
仅在于实际按下播放后, 解码器拒绝非 L51 的码流。

## 验证路径 (待执行)

1. 把 C0004 的所有 SPS NAL (`level_idc` 字段, byte offset 1 内的第 3 字节,
   值 0x2A→0x33) 原地补丁为 51;
2. 同步更新 sidecar XML 与 MEDIAPRO.XML 的 `videoType` 串为
   `AVC_1920_1080_HP@L51`;
3. 写回卡上, 测试相机播放。
4. 若成功, 即确认 Level 是唯一阻塞因素。

(注: 改 `level_idc` 不需要重排 SPS 位, 因为 level 是固定 8-bit 字段, 直接字节替换
即可, 不影响其它字段位置。avcC 与所有 in-band SPS 都要改。)

## 工具

- `C:\Users\HeMu\AppData\Local\Temp\opencode\avcC_parse.c` — 提取 avcC, 解析 SPS 关键字段
- `C:\Users\HeMu\AppData\Local\Temp\opencode\boxdump.c` — ISOBMFF box 树打印
