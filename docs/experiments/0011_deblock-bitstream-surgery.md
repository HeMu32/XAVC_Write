# Experiment 0011: 位流手术 — EDIUS HD 59.94p 片段修复

Date: 2026-06-25

## 问题

EDIUS 导出的 HD@59.94p XAVC-S 片段（C0004、C0005）在 Sony ILCE-7M4 上报"无法显示"。同一 EDIUS 导出的 4K@29.97p 片段（C0001、C0003）可正常播放。相机直出的 HD@59.94p 片段（C6359）也可正常播放。

## 根因

C0004/C0005 的 PPS `deblocking_filter_control_present_flag=0`，而所有可播放片段均为 1。此外 PROF VPRF 码率字段与相机 HD 60p 规格不一致。

## 修复步骤（可复现）

以下步骤以 C0004 为例。C0005 用相同流程修复。

### 前提

- 源文件是 EDIUS 导出的 XAVC-S MP4（ftyp=XAVC, 3 tracks: video/audio/rtmd）
- 视频为 H.264 High Profile, 1920×1080, 59.94p, Level 4.2
- `deblocking_filter_control_present_flag=0`
- 工具源码在 `tools/deblock_inject.c`

### 步骤 1: 位流手术（deblocking 参数注入）

编译工具：
```
gcc -O2 -std=c99 -o tools/deblock_inject.exe tools/deblock_inject.c
```

运行：
```
deblock_inject.exe <input.mp4> <output.mp4>
```

工具自动完成：
1. 解析 moov，定位视频轨 stsz/stco/stsc（注意 FullBox 偏移：条目从 box_start+20 开始）
2. 遍历每个 video sample 中的所有 slice NAL（type 1 或 5）
3. 对每个 slice：
   - EBSP→RBSP 转换（仅移除 `00 00 03` 后接 ≤0x03 的 emulation prevention byte）
   - 按 H.264 spec 7.3.3 解析 slice header 至 `slice_qp_delta` 之后（含 cabac_init_idc）
   - 插入 3 bit deblocking 参数：`ue(0)` + `se(0)` + `se(0)` = "111"
   - 跳过原始 CABAC alignment，添加新的 alignment（1-bits 到字节对齐）
   - 从原始 CABAC 数据起始位置复制剩余 RBSP
   - RBSP→EBSP 转换（注意：传入修改后的 buffer `w.d`，不是原始 `rbsp`）
4. 翻转 PPS `deblocking_filter_control_present_flag`：avcC 中 PPS NAL byte 3，bit 1（from MSB），`|= 0x40`
5. 重建 mdat（修改后的 video + 原始 audio/rtmd）
6. 更新**全部三轨** stco（video + audio + rtmd）。对非视频轨的每个 stco 条目，按其原始偏移之前的视频样本累积 delta 计算新偏移
7. 更新视频轨 stsz（新 sample sizes）

验证：
```
ffmpeg -v error -i <output.mp4 -f null -
```
应输出零错误。

### 步骤 2: PROF VPRF 码率参数补丁

定位 VPRF track 数据：在文件中搜索 "VPRF" 字符串（`56 50 52 46`），其后跳过 size(4) + type(4) + version(4) + num_tracks(4) = 16 字节，到达 track 数据起始。track 数据布局：

```
偏移  内容            C0004/C0005 原始    C6359（目标值）
+0    handler         61 76 63 31         (不变)
+4    flags           01                  (不变)
+5    profile         64                  (不变)
+6    constraint      00                  (不变)
+7    level           2A                  (不变)
+8    field1          00 03               (不变)
+10   field2          00 02               (不变)
+12   field3(码率)    00 00 B9 8C        00 00 C3 50
+16   field4(码率)    00 00 EA 5E        00 00 C3 50
+20   field5          00 3B F0 A7        00 3B F0 A6
+24   field6          00 3B F0 A7        00 3B F0 A6
+28   width           07 80               (不变)
+30   height          04 38               (不变)
+32   field7          00 01               (不变)
+34   field8          00 01               (不变)
```

对于 C0004/C0005 这类文件（ftyp 在 offset 0，PROF uuid box 在 offset 0x1C），VPRF track 数据起始在文件 offset 0x8C，因此：
- field3 在 0x98
- field4 在 0x9C
- field5 在 0xA0
- field6 在 0xA4

补丁方法：直接覆写这 4×4 = 16 字节。

### 步骤 3: 缩略图

生成：
```
ffmpeg -y -i <input.mp4> -map 0:v:0 -frames:v 1 -s 1280x720 -q:v 2 -update 1 <K:\PRIVATE\M4ROOT\THMBNL\C####T01.JPG>
```

在 MEDIAPRO.XML 的对应 Material 条目中，在 XML RelevantInfo 之后添加：
```xml
<RelevantInfo uri="./THMBNL/C####T01.JPG" type="JPG"/>
```

**已知问题**：ffmpeg 生成的缩略图满足相机识别/播放片段的要求，但**缩略图画面本身未被相机正常显示**。C0004 和 C0005 的缩略图均有此问题。相机直出的缩略图（如 C6359T01.JPG）可能包含特定 EXIF 元数据或 JPEG 编码参数，ffmpeg 生成的 JPEG 不满足这些要求。此问题不影响片段播放，仅影响缩略图预览。

### 步骤 4: Sidecar XML

确保 sidecar XML 中 `videoCodec` 的 level 标记与实际码流一致（`@L42`）。

## 已应用的片段

| 片段 | 帧数 | 时长 | 位流手术 | PROF | 缩略图 | 相机 |
|------|------|------|---------|------|--------|------|
| C0004 | 1182 | 19.7s | 3152 slices, +3152B | ✓ | ✓ | ✓ 可播放 |
| C0005 | 4988 | 83.7s | 13301 slices, +13301B | ✓ | ✓ | 待测试 |

## 未隔离的变量

最后一次对 C0004 的改动同时应用了步骤 2（PROF）和步骤 3（缩略图），未隔离测试。因此无法确认：
- PROF 补丁单独是否必需
- 缩略图单独是否必需（C0001 可播放但未做过缩略图干预——它保留了被替换的旧片段的缩略图）

已确认必需的只有**步骤 1（位流手术）**——这是 C0004/C0005 与所有可播放片段的唯一码流级差异。

## 排除的假设

| 假设 | 验证方式 | 结果 |
|------|---------|------|
| Level 4.2 不兼容 | C6359 相机直出也是 L42 | ✗ 排除 |
| PPS flag 单独翻转 | 实验 0009，slice 缺参数 | ✗ 排除 |
| x264 重编码匹配参数 | 实验 0010，无法匹配全部 XAVC-S 参数 | ✗ 排除 |
| SPS VUI 差异 | C0001 与 C0004 VUI 相同 | ✗ 排除 |
| NRT XML 结构 | C0001 与 C0004 结构相同 | ✗ 排除 |
| 容器结构（free/iinf/uuid） | C0001 无这些元素仍可播放 | ✗ 排除 |
| ftyp minor version | C0001 用 0x001FFFFF 可播放 | ✗ 排除 |
| DATABASE.BIN | C0001 未改动 DB 即可识别 | ✗ 排除 |

## 工具

### tools/deblock_inject.c
位流手术工具。编译：`gcc -O2 -std=c99 -o deblock_inject.exe deblock_inject.c`
用法：`deblock_inject <input.mp4> <output.mp4>`

注意: 这个工具仅用于补丁EDIUS输出的1080p 59.94p XAVC-S 50M视频, 其他文件格式有待商榷. 

关键实现注意点（调试中发现的问题）：
- FullBox 的 version+flags（4B）在所有 box 解析中必须跳过
- `br_ue` 需限制 `z<31` 防止越界
- NAL 长度检查需防止 uint32 溢出
- RBSP buffer 需动态分配（1080p IDR 帧可超 64KB）
- `ebsp_to_rbsp` 不应移除非 emulation prevention 的 0x03
- deblocking 参数位于 `slice_qp_delta` **之后**（非之前）
- `cabac_init_idc` 仅对 P/B slice 存在
- `num_ref_idx_active_override` 仅对 P/SP/B slice 存在
- CABAC alignment 插入后需重新计算
- `rbsp_to_ebsp` 必须传入修改后的 buffer，不是原始 buffer
- 必须更新全部三轨 stco（video + audio + rtmd）

## 当前 K:\ 状态

- C0004 = 已修复（位流手术 + PROF + 缩略图）— ✓ 可播放
- C0005 = 已修复（同上）— 待测试
- C0001/C0003 = EDIUS 原始 4K — ✓ 可播放
- C6359 = 相机录制 HD — ✓ 可播放
- 注意：R:\ 已被清空，原始 C0004 备份已丢失

## 缩略图显示问题

截至当前，C0004 和 C0005 的缩略图（ffmpeg 生成的 1280×720 JPEG）均未被相机正常显示。相机直出的缩略图（C6359T01.JPG 等）能正常显示。差异可能在 EXIF 元数据或 JPEG 编码参数。此问题待后续研究，不影响片段播放。
