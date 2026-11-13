# DSH 会话交接：M4 6.02 固件侧证据（AVC 准入 / PROF·VPRF / SD 编录）

写于 2026-11-12。来源：DSH 会话 `a7m4-fl23-works`（M4 6.02 固件研究）+ 本工作区已有分析。
**本次只读**：未访问相机、未刷写固件、未改存储卡、未修改 `a7m4-fl23-works` 里的任何东西。
本文件不重复 `docs/handoff-cappremake.md` 已写的内容；只补它没有的固件侧证据与路径。

---

## 0. 先说结论

| 问题 | 状态 |
|---|---|
| 有 7M4 6.02 完整 `/usr` 与全部媒体库 ELF | ✅ 已在 `firmware/m4-v602/usr`（997 个文件） |
| 有 libmpr 的 Ghidra 工程与 94 个函数反编译 | ✅ `analysis/ghidra/mpr` + `analysis/decompile-mpr` |
| 有 SD `DATABASE.BIN` 的校验和与记录布局 | ✅ 已由 `sidb::Load` / `CalcChecksum` 反编译证实 |
| 有 MP4 → 记录属性的映射（PROF/level/codec/分辨率/帧率） | ✅ `mpr::GetProfileLevel` + `FUN_00328fa8` 已反编译 |
| 有 (codec, width, fps) → 内部分类码 | ✅ `FUN_003256FC` 已反编译（见 §3.1c） |
| 有 UMID 重建路径 | ✅ 符号索引齐全，函数未反编译 |
| 有"回放准入"的完整判定链 | ❌ 只到 `CheckMovieRecParam` 这一层，未反编译 |
| 有 MEDIAPRO.XML 的生成/修复代码 | ❌ 只有格式与字符串，没有写入函数 |

---

## 0.1 两条必须先说清楚的约定

### （a）地址换算：ELF VMA 与 Ghidra VMA 差 0x100000

- `analysis/libmpr-elf.json` 的 `symbols[].address` 与 `analysis/elf-survey/*.symbols.json` 都是 **ELF `.dynsym` 的 `st_value`，即 ELF VMA**。
- `analysis/ghidra/mpr` 工程把 `libmpr.so` 装载在 **ELF VMA + 0x100000**，所以反编译文件名与
  `FocusXavc.java` 打印的都是 **Ghidra VMA**。
- 例：`mpr::GetProfileLevel` 的 ELF VMA 是 `0x0CA73C`，Ghidra 地址是 `0x1CA73C`
  （`analysis/decompile-mpr/001ca73c_GetProfileLevel.c`）。

**因此**：本文 §3 表格给的是 **ELF VMA**；`tools/run_ghidra.py --pattern "@<地址>"` 需要 **Ghidra 地址**，
必须把表中的值 **加 0x100000** 再用。直接抄表里的地址会落到错误的函数上。

### （b）录制卡速检查 ≠ 回放准入

这两件事在固件里是不同函数、不同层：

| 类别 | 函数 | 什么时候用 |
|---|---|---|
| **录制**媒体传输率 | `RateCheck::getMediaTransferRateCheckType_*` | 按「录制格式 × 卡速等级」判断这张卡能不能录 |
| **回放**记录信息 | `mpr::GetRecordInfoFromMp4` / `XavcsMovieReader::*` | 从 MP4 读出记录属性 |
| **流分类** | `FUN_003256FC` | 把 (codec, width, fps) 映射成内部分类码 |
| **录制参数** | `mpr::CheckMovieRecParam` | 开始录制前校验参数 |

本文**不主张**其中任何两个等价。`RateCheck::*` 只用于录制侧，不能拿来解释回放是否被接受。

---

## 1. 固件与提取树

| 路径 | 内容 | 备注 |
|---|---|---|
| `firmware/m4-v602/usr/` | 997 个常规文件，来自 `nflasha15` ext2 | `/lib`、`/codec`、`/kmod`、`/scenario`、`/sabin` |
| `firmware/m4-v602/inventory.json` | 全成员清单（path/bytes/mode） | |
| `firmware/m4-v602/extracted-manifest.json`、`copy-manifest.json` | 提取来源与哈希 | |
| `firmware/tools/` | fwtool 副本（`ext2.py`、`fat.py`） | |

上游原始包（未在本工作区，需时再取）：
`C:\Users\HeMu\Desktop\a7m4-fl23-works\FwRev\fw\7M4_v602\firmware.tar`（753,267,200 B），
成员 `0700_part_image/dev/nflasha15` 就是上述 ext2 的来源。

### 1.1 与本问题相关的库（都在 `/usr/lib`）

| 库 | 字节 | 作用（名称推断，见 §4 的证伪要求） |
|---|---:|---|
| `libmpr.so` | 3,549,952 | **MPR 媒体引擎**：MP4 读写、sidb 记录、UMID、KLV |
| `libInfraMediaCommon.so` | 402,656 | `mcmn_*` 媒体/驱动公共层 |
| `libInfraAdjMedia.so` | 322,280 | 卡/设备 FS 抽象：`AdjFsBase::ReadFile/WriteFile`、`AdjFsVFS`、`AdjFsFsys::Format` |
| `libInfraMediaDetect.so` | 98,240 | 卡检测线程 |
| `libIMDB.so` | **75,632** | **只有 3 个导出函数**：`IMDB_find_entry` / `IMDB_get_entries` / `IMDB_find_target_bit` |
| `libInfraMediaMount.so` | 65,392 | 挂载线程 |
| `libInfraMediaConfig.so` | 52,344 | 媒体 ID / 备份 / `SetBackupVal` |
| `libInfraMetaSupplier.so` | 23,048 | 元数据供给 |
| `libEsCodecLibrary.so` | 23,024 | ES 编解码封装 |
| `libInfraVericEsCodecLibrary.so` | 22,912 | 同上（Veric 变体） |
| `libupdatermedia.so` | 10,144 | 更新用媒体接口 |
| `codec/vcd_firmware*.bin` | 5.4–10.9 MB | **硬件编解码器固件，不是 ELF** |

> `libXavcMp4.so` **不存在**：`libXavcMp4::*` 与 `XavcsMovieReader/Writer` 都静态链进 `libmpr.so`。

### 1.2 本次新生成的符号索引（可直接用）

`tools/elf_survey.py` 已对下列库各生成一份 `analysis/elf-survey/<name>.symbols.json`
（含 path、sha256、header、segments、sections、`.dynsym` 全部 `STT_FUNC` 与 demangle 名）：

```
analysis/elf-survey/libIMDB.symbols.json
analysis/elf-survey/libInfraMediaCommon.symbols.json
analysis/elf-survey/libInfraAdjMedia.symbols.json
analysis/elf-survey/libInfraMediaDetect.symbols.json
analysis/elf-survey/libInfraMediaConfig.symbols.json
analysis/elf-survey/libInfraMediaMount.symbols.json
analysis/elf-survey/libEsCodecLibrary.symbols.json
analysis/elf-survey/libInfraMetaSupplier.symbols.json
analysis/elf-survey/libupdatermedia.symbols.json
analysis/elf-survey/libInfraVericEsCodecLibrary.symbols.json
```

已有的 `analysis/libmpr-elf.json` 是 libmpr 的同类索引（3,112 个函数符号）。

---

## 2. 已证实的事实（读代码得出，不是推断）

### 2.1 `sidb::CalcChecksum` 是"小端 64 位字求和"

`analysis/decompile-mpr/0038b45c_CalcChecksum.c`：

```c
long sidb::CalcChecksum(uchar *p, uint n) {
  long sum = 0;
  for (i = 0; i < n >> 3; i++) sum += *(long*)(p + i*8);   // LE u64
  if (n & 7) { 把尾部 0..7 字节放进 8 字节缓冲（其余补 0）再相加; }
  return sum;                                                // 不取模
}
```

**没有取模**——取模发生在调用点。

### 2.2 `sidb::Load` 的校验区域（已证实）

`analysis/decompile-mpr/003992c8_Load.c:210-226`：

```c
s0 = CalcChecksum(this + 0x0000, 0x3FFC);   // 存于 0x3FFC
s1 = CalcChecksum(this + 0x7C40, 0x03BC);   // 存于 0x7FFC
s2 = CalcChecksum(this + 0x8000, 0x3FFC);   // 存于 0xBFFC
s3 = CalcChecksum(this + 0xC000, 0x3FFC);   // 存于 0xFFFC
for (p = 0x4000; p < 0x7C00; p += 0x400)      // 16 块
    CalcChecksum(this + p, 0x400) == *(u32*)(this + 0x7C00 + (p-0x4000)/0x100);
```

比较式是 `*(int*)(this+0x3FFC) == (int)s + (int)(s / 0xFFFFFFFB) * 5`，
即 32 位截断下的 `s mod 0xFFFFFFFB`（因为 `0xFFFFFFFB = 2^32 - 5`）。

记录内校验（`tools/sony_db.py:48`）：`checksum(record[:158], 0xFFF1) == *(u16*)(record+158)`。
模数 `0xFFF1 = 65521`。

> 你笔记里的"LE 64-bit sum mod 0xFFFFFFFB / 记录 mod 0xFFF1"与代码完全一致。

### 2.3 记录表位置是**动态**的，不是固定 0xFE024

`sidb::Load` 从头部字段取：

| 偏移 | 含义 | 代码位置 |
|---|---|---|
| `0x000` | 16 字节 magic，与 `g_magic` 比较 | `Load:208` |
| `0x028` | `short`，必须 `== 1` | `Load:206` |
| `0x02C` | 文件总长 | `Load:187` |
| `0x030` | **记录 stride**（当前 0xA0 = 160） | `Load:312` |
| `0x044` | **记录数** | `Load:233` |
| `0x10000` | **记录表起点** | `Load:313` |
| `0x10000 + i*stride` | 第 i 条记录 | |
| `0x7C80/0x7C84/0x7C88` | 三类记录计数（type0 / type1 / type3） | `Load:363` |

所以"记录表在 0x10000 + count*stride"，重建后的卡上旧固定偏移必然失效——**这点你的判断正确**。

### 2.4 记录字段布局（`sidb::ConvRecordInfo2RecordStructure`，已证实）

`analysis/decompile-mpr/00392a38_ConvRecordInfo2RecordStructure.c`，`param_2` 是 `recordInfo`，`param_4` 是 160 B 的 `recordStructure`：

| recordInfo 偏移 | 写到记录结构的哪 | 语义 |
|---|---|---|
| `+0x00` | `[7]` 低 4 位 | 内容类型（`ContentType2ContentTypeInternal`） |
| `+0x04` bit1..7 | `[4]` bit1.. | 数值（24 位的一部分） |
| `+0x08` (int) | `[8]` bit8.. | 24 位数值的高位 |
| `+0x0C` | `[0x10]/[0x14]` | LocalTime（创建时间） |
| `+0x1C` bit0 | `[6]` bit4 | |
| `+0x20` 低 3 位 | `[6]` bit5..7 | |
| `+0x24` bit0 | `[4]` bit0 | |
| `+0x25` | `[7]` bit4.. | |
| `+0x26` | `[6]` bit1 | 视频标志 |
| `+0x28` | 视频编解码 | `defStruct2sidb_VideoCodec` |
| `+0x2C` | GOP 结构 | `defStruct2sidb_GopStructure` |
| `+0x30` | 分辨率 | `defStruct2sidb_VideoResolution` |
| `+0x5F0/0x5F1/0x5F2` | `[6]` bit0/1/2 | |
| `+0x614` | | 内部内容类型 |
| `+0x619/0x61A` | `[6]` bit2/3 | |

反向函数 `sidb::ConvRecordStructure2RecordInfo` 在 `0x28e754`（3,580 B，未反编译）。

### 2.5 `sidb::Load` 按记录类型分派（已证实）

`Load:313-359`：

| type | 恢复方式 | 哈希表 |
|---|---|---|
| 0 | `+0x10004` 的 bit0 判断，计入 `iVar10` | — |
| 1 | `RestorateFilePath` → `string_hash` | `g_stringHash` |
| 2 | `RestorateBinaryRecord` → `binary_hash` | `g_binaryHash` |
| 3 | 16 个子记录 `RestorateArrayBinaryRecordForLoad` | `g_binaryArrayHash` |

`sidbhash` 每槽 0x1FE8 字节。

### 2.6 MP4 → 记录属性的映射（已证实）

`analysis/decompile-mpr/001ca73c_GetProfileLevel.c`：`mpr::GetProfileLevel(libXavcMp4::CodecSpecifcInfo)` 是一张
`CodecSpecifcInfo → (profile, level)` 的大 switch。观察到的 (参数, 返回) 对：

```
0x24B7→(0x3B,0x24B7)  0x2278→(0x2C,…)  0x2196→(0x22,…)  0x2199→(0x24,…)
0x219C→(0x26,…)  0x21B4→(0x27,…)  0x21B7→(0x28,…)  0x21BA→(0x29,…)
0x2178→(0x20,…)  0x217B→(0x21,…)  0x178→(0x1F,…)  0x278→(0x2B,…)
0x27B→(0x2D,…)  0x227B→(0x2E,…)  0x2296→(0x2F,…)  0x2299→(0x32,…)
0x229C→(0x35,…)  0x22B4→(0x37,…)  0x22B7→(0x38,…)  0x22BA→(0x39,…)
0x2496→(0x30,…)  0x2499→(0x33,…)  0x249C→(0x36,…)  0x24B4→(0x3A,…)
0x14D0028→4  0x14D0029→5  0x14D4015→0  0x14D401E→1  0x1640028→0x10
0x1640029→0x11  0x1640032→0x13  0x1640033→0x14  0x164003C→0x16
0x17A0029→0x18  0x17A0033→0x1B  0x17A0034→0x1C  0x17A003C→0x1D
0x7A1029→0x18  0x7A102A→0x19  0x7A1032→0x1A  0x7A1033→0x1B  0x7A1034→0x1C
默认→0x3D
```

`FUN_00328fa8`（`analysis/decompile-mpr/00328fa8_FUN_00328fa8.c`）把解析结果写进 `MoviePropertyInfo`：
它先按 `avc1`(0x61766331) 找视频轨，再按 `hvc1`(0x68766331) 判断 HEVC；
`param_2+0x0C = (codec==hvc1)`，`+0x14 = f(0x0F00,0x0870)`（分辨率 3840×2160 的编码），
`+0x2C = 帧时长/1000`，`+0x18/0x1C/0x20/0x34/0x38/0x40/0x44` 来自 `DAT_003db730/38/40/50` 等小表。
**这几张表就是"分辨率/帧率/等级"的枚举表，值得在 Ghidra 里直接看数据。**

### 2.7 相机 MP4 的盒布局（已证实，来自 `analysis/sample-structure.json`）

| 片段 | 盒序列 |
|---|---|
| 相机 4K（C5850） | `ftyp`(28) `uuid`(148) `free`(130880) `mdat` `moov`(2283) `meta`(10239) |
| 相机 HD（C6359） | 同上，`mdat` 67,108,880 |
| 早期尝试（C0007） | `ftyp`(28) `uuid`(148) `mdat` `moov`(141689) `meta`(1272) |
| ffmpeg base.mov | `ftyp`(20) `wide`(8) `mdat` `moov`(33859) — **无 `uuid`、无 `meta`** |

- `uuid` 盒 148 B 是唯一的非标准顶层盒，`tools/sony_mp4.py` 已把它作为 `report["prof"]` 原样导出。
- libmpr 里存在四字符 `4VPRF`（`0x350029`）与 `XAVC-M4@2.00.00`（`0x2d3a1c`）。
- libmpr 里的路径常量：`/PRIVATE/DATABASE/DATABASE.BIN`(0x2d20f0)、`/M4ROOT/MEDIAPRO.XML`(0x2d3b68)、`./CLIP/`(0x2d348f)、`./THMBNL/`(0x2d3497)、`M01.XML`(0x2d3523)、`%s/CLIP/%sM01.%s`、`%s/THMBNL/%sT01.%s`。
- libmpr 里还有 `uuid_generate_random` / `uuid_unparse_lower` / `mpr::GetXmpUUID`，说明 **UMID 由相机本地随机生成再写入**，不是外部给定。

---

## 3. 该看哪些函数（按你的三个问题分组）

地址都来自 `analysis/libmpr-elf.json` 的 `.dynsym`，可直接用
`tools/run_ghidra.py ... --pattern "@<地址>|..."` 拉出来反编译。

### 3.1 AVC 回放/记录属性判定（`libmpr`）

**地址列是 ELF VMA**；`tools/run_ghidra.py --pattern "@<地址>"` 需要 **Ghidra VMA = ELF VMA + 0x100000**（见 §0.1a）。
例：`CheckMovieRecParam` 的 ELF VMA 是 `0x0CD9B4`，Ghidra 地址是 `0x1CD9B4`。

| 函数 | ELF VMA | 大小 | 状态 |
|---|---|---:|---|
| `mpr::CheckMovieRecParam(mpr::movieRecParam&)` | `0xcd9b4` | 1044 | **符号有，未反编译** ← 首选 |
| `mpr::CheckMovieCaptureTypeParam` | `0xcd8b4` | 256 | 未反编译 |
| `mpr::CheckPbStartParam` | `0xc01d8` | 376 | 未反编译 |
| `mpr::CheckRecStartInParam` | `0xcd5a4` | 784 | 未反编译 |
| `mpr::CheckRecordTarget` | `0xb9b20` | 296 | 未反编译 |
| `mpr::CheckM4ForReConstruct` | `0xb8e98` | 364 | 未反编译 |
| `mpr::CheckDcfForReConstruct` | `0xb8d2c` | 364 | 未反编译 |
| `MprIf::CheckSeveralMoviesRecordable` | `0x2cf4ec` | 8 | thunk |
| `MprIf::CheckAppStructureExist` | `0x2cef8c`/`0x2cef94` | 8 | thunk |

> 这一组是**参数与属性判定**（录制启动参数、回放启动参数、数据库重建），不是卡速检查。
> 卡速检查在 §3.1b，流分类在 §3.1c，三者不要互相代替。

**`videoType` 里不含码率**：4 条相机 HD 59.94p 记录（C0004/C0005/C0007/C6359）都是
`AVC_1920_1080_HP@L42`，其中既有 50 Mbps 尝试也有相机原生片段；4K 才出现 `AVC140_…` 前缀。
所以码率只体现在 **SPS 的 HRD 字段**与 **VPRF**，不在 `videoType` 字符串里（已证实）。

### 3.1b 录制侧：卡速检查（**不属于回放准入**）

| 函数 | ELF VMA | 大小 |
|---|---|---:|
| `RateCheck::getMediaTransferRateCheckType_Normal_AVC_Long_FHD` | `0x105260` | 136 |
| `RateCheck::getMediaTransferRateCheckType_SnQ_AVC_Long_4K` | `0x1055E8` | 160 |
| `RateCheck::getMediaTransferRateCheckType_Normal_AVC_Intra_4K` | `0x1053F8` | 136 |
| `RateCheck::getMediaTransferRateCheckType_Normal_HEVC_Long_4K` | `0x105370` | 136 |
| `RateCheck::getMediaTransferRateCheckType_SnQ_AVC_Intra_4K` | `0x10579C` | 160 |

> 名字里的 `FHD` / `4K` / `Long` / `SnQ` / `Intra` 说明这是**按录制格式 × 卡速等级**分档的。
> **推断（仅凭名字，未反编译）**：25 Mbps 1080p 落在 `Normal_AVC_Long_FHD` 这一档。
> 即使这条成立，它也只约束**录制**，不能用来解释一个已存在的 MP4 为什么能/不能被回放。

### 3.1c 流分类：`(codec, width, fps) → 内部分类码`

`analysis/decompile-mpr/003256fc_FUN_003256fc.c`（ELF VMA `0x2256FC`，Ghidra `0x3256FC`）已反编译。
入参 `param_2` 是视频参数结构，出参 `*param_3` 写分类码：

| 入参偏移 | 含义 | 观察到的取值 |
|---|---|---|
| `+0x0C` (int) | codec fourcc | `0x61766331`="avc1"、`0x68766331`="hvc1" |
| `+0x2A` (u16) | 宽度 | `0x280`=640、`0x500`=1280、`0x780`=1920、`0x5A0`=1440、`0xF00`=3840、`0x1000`=4096 |
| `+0x14` (int) | 帧率字段 | 6000/9000/12000/16000/21000/25000/26000/50000/60000/93000/100000/240000/250000/300000/400000/480000/500000/600000 等 |
| `+0x18` (long) | 标签 | `0xA00000002`（与 `+0x14` 联合判定） |
| `+0x24` (u32) | 第二分类字段 | `0x190000/0x320000/0x640000/0x1DF853/0x17F9DC/0x77E14F/0x3BF0A6/0xEFC29F` |
| `+0x34` (int) | 标志 | `0` / `1` / 其它 |

返回的是**复合码**：高 16 位是类别，低位是变体，例如

```
0x0164002A = (0x0164 << 16) | 0x2A     AVC 1280 段
0x014D4015 = (0x014D << 16) | 0x4015   AVC 640 段
0x017A002A = (0x017A << 16) | 0x2A     AVC 1920 + fps 0x3BF0A6
0x07A102A  = (0x07A1 << 16) | 0x2A     另一支（`+0x14 == 0x36330` 时为 0x07A1032）
```

已证实的 AVC 1920（`0x780`）路径：`+0x24 == 0x3BF0A6` 时，
`+0x34 == 0` 且 `+0x18 == 0xA00000002` 且 `+0x14 == 50000` → `0x017A002A`；
`+0x34 != 0` 且 `+0x14 == 0x36330` → `0x07A1032`，否则返回 `+0x14 - 0x2D2A8`。

> 这是 `mpr` 内部的**流分类**，与 §3.1b 的卡速检查、§3.1 的录制参数校验都是不同函数。
> 三者不要互相代替，也不要据此断言回放准入只看这一处。

### 3.2 MP4 读（回放）路径

| 函数 | 地址 | 大小 | 状态 |
|---|---|---:|---|
| `mpr::IntegPlayGetRecordInfoFromMp4(std::string, MoviePropertyInfo&)` | `0xc2ffc` | 556 | 未反编译 |
| `mpr::IntegPlayGetRecordInfo(sidb::recordInfo&)` | `0xc3228` | 340 | 未反编译 |
| `mpr::GetRecordInfoFromMp4(char const*, MoviePropertyInfo&)` | `0xde3d8` | 344 | **已反编译** |
| `mpr::GetRecordInfo(unsigned int, sidb::recordInfo&)` | `0xde778` | 1168 | 未反编译 |
| `mpr::GetProfileLevel(libXavcMp4::CodecSpecifcInfo)` | `0xca73c` | 804 | **已反编译** |
| `XavcsMovieReader::GetMetadata(...)` | `0x10dda0` | 9204 | 未反编译 |
| `XavcsMovieReader::MakeInfoList(...)` | `0x10d7d8` | 656 | 未反编译 |
| `XavcsMovieReader::GetEssenceMarks` | `0x113278` | 772 | 未反编译 |
| `XavcsMovieReader::MakeSpecial{Video,Audio,Meta}Info` | `0x10c894/0x10c8dc/0x10c924` | 72/72/116 | 未反编译 |
| `XavcsMovieReader::_make_outband_param_info` | `0x11075c` | 864 | 未反编译 |
| `XavcsMovieReader::ConvertLibSizeAndFrameRateToMprStreamProperty` | `0x10ccec` | 1220 | 未反编译 |
| `XavcsMovieReader::ConvertLibXavcMp4CodingType` | `0x10cc7c` | 12 | 未反编译 |
| `XavcsMovieReader::OpenAndLockNrtFiles(sidb::recordInfo const&,…)` | `0x10c018` | 56 | 未反编译 |
| `mpr::GetXmpUUID(char*, int)` | `0xe5410` | 168 | 未反编译 |

> `GetRecordInfoFromMp4` 里 `local_398[0] = 0x58415643` = ASCII `"XAVC"`，
> `local_390 = 0xa00000`，缓冲区 `0x20000`——**这就是"打开 XAVC MP4"的入口参数**。
> 要弄清 PROF/VPRF 到底在哪一步被读，从 `0xde3d8` 往下跟 `FUN_0032af44`（open）/`FUN_0032a380`（parse）即可。

### 3.3 sidb / SD 编录

| 函数 | 地址 | 大小 | 状态 |
|---|---|---:|---|
| `sidb::Load` | `0x2992c8` | 2852 | **已反编译** |
| `sidb::Flush` | `0x2b567c` | 1412 | 未反编译（**写 DATABASE.BIN 的出口**） |
| `sidb::CalcChecksum` | `0x28b45c` | 140 | **已反编译** |
| `sidb::Init(sidb::initParam const&)` | `0x299dec` | 980 | 未反编译 |
| `sidb::Select` | `0x28f550` | 592 | 未反编译 |
| `sidb::GetRootSet(...)` | `0x2a8760` | 1420 | 未反编译 |
| `sidb::GetRemain(...)` | `0x28ce48` | 592 | 未反编译 |
| `sidb::Reallocate` | `0x28bd34` | 220 | 未反编译 |
| `sidb::ConvRecordInfo2RecordStructure` | `0x292a38` | 4480 | **已反编译** |
| `sidb::ConvRecordStructure2RecordInfo` | `0x28e754` | 3580 | 未反编译 |
| `sidb::ConvVideoParamToStreamProfile` | `0x28d238` | 156 | **已反编译** |
| `sidb::ConvVideoParamToVPC` | `0x28d710` | 532 | 未反编译 |
| `sidb::ConvVideoParamToQualityLevel` | `0x28d924` | 544 | 未反编译 |
| `sidb::RestorateUMID` | `0x28e698` | 88 | 未反编译 |
| `sidb::IssueUniqueId` | `0x290f3c` | 736 | 未反编译 |
| `sidb::RestorateFilePath` | `0x28dcdc` | 340 | 未反编译 |
| `sidb::RestorateBinaryRecord` | `0x28e298` | 296 | 未反编译 |
| `sidb::RestorateArrayBinaryRecord` | `0x28e5ac` | 236 | 未反编译 |
| `sidb::SetFlushArea` / `SetFlushAreaHeader` | `0x2913e4` / `0x28ff20` | 128 / 88 | 未反编译 |
| `mpr::SidbFlush(void*)` | `0xaa594` | 248 | 未反编译 |
| `mpr::DirectUpdateSidb(...)` | `0xaf150` | 416 | 未反编译 |
| `mpr::RegisterM4RecordInfoOnSidb(...)` | `0xb9848` | 728 | 未反编译 |

`sidb::ConvVideoParamToStreamProfile` 已反编译，是个小枚举转换：

```c
// 0x38d238，param[0]=codec(0=AVC,1=HEVC)，param[8]=质量码，param[0x10]=标志
// 返回 StreamProfile 枚举：0 / 1 / 2 / 4 / 5 / 6
```

这与你 `videoType="AVC_1920_1080_HP@L42"` 里 `HP@L42` 的取值是同一套枚举族。

### 3.4 UMID（`sidb` 侧"重建"到底重建什么）

| 函数 | 地址 | 大小 |
|---|---|---:|
| `sidb::RestorateUMID(uchar*, LocalTime const&, uchar const*, uchar)` | `0x28e698` | 88 |
| `mpr::UMID::CreateBasicUMID(...)` 四个重载 | `0x2cdbfc`(676) / `0x2cdea0`(216) / `0x2cdb58`(80) / `0x2cdba8`(84) | 未反编译 |
| `mpr::UMID::SetTimeInfo(LocalTime const*)` | `0x2ccc88` | 28 |
| `mpr::UMID::SetDivisionType(_DIVISION_TYPE)` | `0x2ccd90` | 12 |
| `mpr::UMID::SetDeviceNodeID(uchar const*, uint)` | `0x2ccc00` | 100 |
| `mpr::UMID::SetInstanceNoParam(uchar const*, uint)` | `0x2ccd60` | 48 |
| `mpr::UMID::SetUniversalLabel(_MATERIAL_TYPE,_MATERIAL_NO_GEN_METHOD,_INSTANCE_NO_GEN_METHOD)` | `0x2ccd9c` | 476 |
| `mpr::UMID::CreateMaterialNumber` / `CreateInstanceNumber` | `0x2cda98` / `0x2ccf78`·`0x2cd0fc`·`0x2cd168` | 192 / 40·108·224 |
| `mpr::UMID::GetBasicUMID(...)` 三个重载 | `0x2ccc00` 附近 | |
| `mpr::UMID::GetDeviceNodeIdString` / `GetMaterialNoString` / `GetBasicUmidString` | `0x2cd620` / `0x2cd638` / `0x2cd688` | 24 / 80 / 40 |
| `mpr::IsPairUMID(uchar const*, uchar const*)` | `0xa5a78` | 144 |
| `mpr::GetFilePathAndClipUmid(movieRecParam&, uint*, uint, uchar, RecSequenceInfo*, bool, bool)` | `0xce39c` | 1608 |
| `mpr::GetXmpUUID(char*, int)` | `0xe5410` | 168 |

> `RestorateUMID`（88 B）是把"记录里存的 UMID"还原成 32 字节；`CreateBasicUMID` 才是生成。
> 相机侧有 `uuid_generate_random` + `uuid_unparse_lower`，说明 **UMID 是相机自己随机生成的**，
> 因此修复 MEDIAPRO.XML / 记录时**不要重新生成 UMID**，只从记录里读出来原样使用。
> 这一条与 C0008 的 `umid="060A2B340101010501010D231300000029C9067C71384417B335E1B55D077759"`
> 以及 `TargetMaterial umidRef` 的用法一致。

### 3.5 MP4 写（SPS/PPS/等级）

| 函数 | 地址 | 大小 |
|---|---|---:|
| `XavcsMovieWriter::GetParameterSetPerInfo(uint, StreamType, uchar, PpsInfo_t*, bool)` | `0x11cad4` | 780 |
| `XavcsMovieWriter::ConvertVPCToLevel(VideoParamComb, VQuality, FrameRate, NRTDEF::Level*)` | `0x117c24` | 388 |
| `XavcsMovieWriter::ConvertMPFPictureQualityLevel(...)` | `0x119838` | 132 |
| `XavcsMovieWriter::ConvertVideoCodecTypeName(VideoRecFormat, StreamType, char*)` | `0x1198fc` | 160 |
| `XavcsMovieWriter::MakeVideoEsList` / `MakeAudioEsList` | `0x11c868` / `0x11c9a8` | 320 / 300 |
| `XavcsMovieWriter::SetVideoInfoList` / `SetAudioInfoList` | `0x118d00` / `0x118e3c` | 316 / 168 |
| `XavcsMovieWriter::SetClipStatus(sidb::ClipStatus)` | `0x11b164` | 180 |
| `XavcsMovieWriter::IsEditAvailable` | `0x11acd4` | 56 |

### 3.6 媒体配置层（写 `MEDIAPRO.XML` 的可能出口）

`analysis/elf-survey/libInfraMediaConfig.symbols.json`：
`GetMediaInfoCmd`、`SetMediaInfo`、`SetMediaInfoByDevInfo`、`SaveBackup`、`ReadBackupConfigInfo`、
`GetBackupVal`/`SetBackupVal`、`CreateFuncInfoByBackup`、`SetDevicePathByDeviceID`、`ConvNode2DeviceID`。

`analysis/elf-survey/libInfraAdjMedia.symbols.json`：
`AdjFsBase::ReadFile/WriteFile`、`AdjFsVFS::ReadFile/WriteFile/ReadDir`、`AdjFsFsys::Format`、
`AdjDevice::CallbackPointForMediaTemperatureInfo`。

> **这两层是"真正落盘"的位置**：`mpr`/`sidb` 只产出字节，`InfraAdjMedia` 才做 FS 写。
> 要查"MEDIAPRO.XML 谁写"，从 `libInfraMediaConfig` 的 `SetMediaInfo` 往上找调用者。

---

## 4. 现有工具（都能直接跑）

| 工具 | 作用 |
|---|---|
| `tools/elf_survey.py` | 生成 `.dynsym` 全函数索引 + 指定字符串（VPRF/avcC/MEDIAPRO/DATABASE/M4ROOT/deblock/SPS/play-check）。本次已对 10 个库跑过。 |
| `tools/run_ghidra.py` | **headless Ghidra 独立分析**（不是 MCP 共享工程）。`--existing` 复用 `analysis/ghidra/mpr`，`--pattern` 支持 `@地址` 拉函数+xref，第三参数按字符串 xref 选函数。 |
| `tools/FocusXavc.java` | `run_ghidra.py` 的 postScript：按正则/@地址/字符串 xref 选函数并导出伪 C。 |
| `tools/sony_mp4.py` | 严格 ISO BMFF 读取器；输出顶层盒、三轨表、`avcC`、`uuid`（`report["prof"]`）、`meta`。 |
| `tools/sony_db.py` | `DATABASE.BIN` 读取：校验和区域、记录表、type0 记录字段。 |
| `tools/avc_sony.py`、`tools/trace_avc.py` | SPS/PPS/VUI/HRD 字段级解析与差异追踪。 |
| `tools/xavc_rebuild.c`、`tools/build_sony_clip.py` | 三轨重建（mdat + 三轨 stco）与 Sony 片段封装。 |
| `tools/deblock_inject.c`、`tools/sps_patch.c`、`tools/avclevelpatch.c` | 位流手术（去块参数、SPS 重写、等级改写）。 |

### 4.1 headless 调用示例（反编译未覆盖的函数）

```powershell
cd C:\Users\HeMu\Desktop\XAVC_Write
& 'E:\anaconda3\envs\test311\python.exe' tools\run_ghidra.py `
  firmware\m4-v602\usr\lib\libmpr.so `
  --pattern "@1cd9b4|@1c01d8|@1b8e98|@3992c8|@3b567c|@38e754|@3a8760|ConvRecordStructure2RecordInfo|GetRootSet" `
  --existing --label mpr2
```

工程：`analysis/ghidra/mpr.gpr`（`libmpr.so` 只读工程）。
脚本路径会自动加 `tools`，日志在 `analysis/ghidra-mpr2.log`，伪 C 在 `analysis/decompile-mpr2/`。

---

## 5. 对 C0008 的具体建议（基于上面的事实）

已证实可用作对照：

1. **`videoType` 字符串**：相机 HD 59.94p 用的是 `AVC_1920_1080_HP@L42`（`MEDIAPRO.XML` 里 4 条记录都是），
   4K 用 `AVC140_3840_2160_H422P@L51`。你的 `C0008M01.XML` 已经写 `AVC_1920_1080_HP@L42`，一致。
2. **`Duration` 是帧数**：相机侧 `C6359M01.XML` = `30`（59.94p）、`C6350M01.XML` = `60`（119.88p）、
   `C5850M01.XML` = `75`（29.97p）；`C0007` = `14170`。你的 `C0008M01.XML` 写 `1534`，与 `build-manifest` 的 `frames: 1534` 一致。
3. **`MEDIAPRO.XML` 的 `dur` 与 sidecar 的 `Duration` 同值**：C6359 两处都是 `30`，C5850 两处都是 `75`。
   所以 `dur` 也是**帧数**，不是秒（这一点从两处一致可以确认，不是猜的）。
4. **UMID 不要重新生成**：`uuid_generate_random` 在相机侧，`RestorateUMID` 只做还原。
5. **`DATABASE.BIN` 校验**：改记录后必须重算 `0x4000..0x7C00` 的 16 个块校验 + `0x3FFC/0x7FFC/0xBFFC/0xFFFC`，
   并且 `0x7C80/0x7C84/0x7C88` 计数变化时要重算 `0x7FFC`（`Load:363-370`）。
   `tools/sony_db.py --output ...` 会打印 19/19 校验是否通过。

未证实、需要用上面 §4.1 的命令补的：

| 待查 | 建议入口 |
|---|---|
| 回放准入到底看哪些字段 | `0x0CD9B4` `CheckMovieRecParam` → `0x0C01D8` `CheckPbStartParam` |
| 回放时的流分类落在哪一支 | `0x2256FC` `FUN_003256FC`（已反编译，见 §3.1c）+ `0x0CA73C` `GetProfileLevel` |
| PROF/VPRF 是顶层 `uuid` 盒还是 `moov` 里的 box | `0x0DE3D8` → `0x428FA8`，再对 `uuid` 载荷做字节比对；`4VPRF` 在 ELF `0x350029` |
| `sidb` 记录 type1/2/3 是否也必须补 | `0x2992C8` 的 `Load:313` 分支 + `0x2B567C` `Flush` |
| `MEDIAPRO.XML` 由谁写 | `libInfraMediaConfig::SetMediaInfo` 的调用者 |
| 卡速检查是否影响已存在片段 | `0x105260` `RateCheck::…Normal_AVC_Long_FHD`（**录制侧**，不是回放） |

---

## 6. 当前工作区状态（供接手）

- `output/cat-25m/C0008.MP4`（87,556,543 B）与 `C0008M01.XML`、`C0008T01.JPG` 已生成；`base.mov` 与 `C0008` 的 1534 帧哈希/时间戳完全一致。
- `analysis/sd-db.json`：当前卡 `DATABASE.BIN` 64 条记录（53×type0、7×type1、3×type2、1×type3），19/19 校验通过。
- 本文件只新增了 `analysis/elf-survey/` 下 10 份符号索引；**没有**改任何既有分析、工具或卡内容。

## 7. 一句话

固件侧能证明的是：**校验和算法、记录表动态位置、记录字段布局、MP4→profile/level 映射、流分类码、UMID 生成在相机侧**；
不能证明的是：**回放准入的具体判定顺序**与**MEDIAPRO.XML 的写入者**——这两块只差反编译，地址已在 §3 给出。

---

## 8. 对 `docs/handoff-dsh-xavc-write.md` 的更正（不是本文档的观点）

另一份交接（`docs/handoff-dsh-xavc-write.md`，22,892 B）反复主张「HD 59.94p **必须是** `@L52`，
`@L42` 需要改成 `@L52`」。**这条是错的，不要沿用。** 本文档不持有该主张。

### 8.1 反证

| 证据 | 内容 | 可自查路径 |
|---|---|---|
| 相机原生片段 `F:/PRIVATE/M4ROOT/CLIP/C6359.MP4` | `AVC High`，SPS `level_idc = 42`（`0x2A`） | `analysis/avc-camera.json` → `level_idc: [42]`；来源见 `analysis/avc-camera.log` 第 5 行 |
| 该片段自带的 `C6359M01.XML` | `videoCodec="AVC_1920_1080_HP@L42"`、`halfStep="true"`、`tcFps="30"` | `backup/snap_20261112T144251/PRIVATE/M4ROOT/CLIP/C6359M01.XML` |
| 用户已验证可回放的 EDIUS `C0007` | 同样 `High@L42` | `analysis/avc-edius.json` → `level_idc: [42]` |
| `docs/patching-recipe.md` 第 4 步 | 明写「HD 59.94p 必须是 `@L42`；若为 `@L52` 需修正」 | `docs/patching-recipe.md:91-93` |
| `analysis/decompile-mpr/003256fc_FUN_003256fc.c` | AVC 1920 分支的分类码高字为 `0x0164`/`0x017A`，与 `@L42` 同族 | 见本文 §3.1c |

也就是说：**`@L42` 是正确值，`@L52` 才需要改成 `@L42`**。把方向搞反会诱导去改一个本来正确的字段。

### 8.2 另一处要小心的地方

同一份交接把 `RateCheck::getMediaTransferRateCheckType_*` 与回放准入混为一谈。
那组函数名里的 `FHD`/`4K`/`Long`/`SnQ`/`Intra` 指向的是**录制时的卡速档位**，
不是「这个 MP4 能不能回放」。两者在固件里是不同函数、不同调用点（见本文 §0.1b）。

### 8.3 建议的判别实验（**不要改相机原生片段**）

若要把「`@L42` vs `@L52`」的影响与「SPS HRD / VPRF」的影响分开，安全的做法是：

1. 只改**自己生成的** `C0008` 候选，分别产出 `@L42` 与 `@L52` 两个副本；
2. 保持 `halfStep`、`Duration`、`LtcChangeTable` 与相机片段一致，只动 `videoCodec` 字符串；
3. 每次只插一张卡、只放一个候选，看机身是否列出该片段；
4. **不要**去改 `C6359` 或任何 `C5850` 起的相机原生片段作为对照。

> 本文档不主张 `halfStep` 与 `@L42/@L52` 有因果关系；`halfStep="true"` 在相机片段上出现，
> 只说明它与 59.94p 的帧计数（`tcFps="30"`、`Duration` 为帧数）同时出现，**不是** level 的判据。

