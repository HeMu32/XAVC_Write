# CAppRemake 已有固件资料交接

2026-11-12，仅查阅现成文档、目录及清单；未运行固件、解包新工件、访问相机或存储卡，未修改产品代码。
Codex 项目名 **CAppRemake** 对应实际目录 **`C:\Users\HeMu\Desktop\CAppRev`**。
本交接不证明 ffmpeg 生成的 1080/59.94p、25 Mbps、8-bit 4:2:0 流已满足机内回放条件。

## 1. 优先资料：7M4 6.02 完整 `/usr` 镜像与原固件

| 已核实存在的路径 | 内容与边界 |
| --- | --- |
| `C:\Users\HeMu\Desktop\CAppRev\artifacts\ble-firmware-static-20261103\inputs\m4-v602\usr.ext2` | 378,580,992 B，完整 `/usr` 分区镜像，**不是整个 rootfs**。既有清单记录 SHA-256 `b33408130538b6b34b3fe196d455bfce6f404a207a5567a0ab13e933024c8637`。 |
| `C:\Users\HeMu\Desktop\a7m4-fl23-works\FwRev\fw\7M4_v602\firmware.tar` | 753,267,200 B；上述镜像来自 TAR 成员 `0700_part_image/dev/nflasha15`。既有来源清单记录 TAR SHA-256 `99d2388bfc6f33987f01fd6ac87bff5bc1ed1e343778eb6b17e9ade6c0eea3b1`。 |
| `C:\Users\HeMu\Desktop\a7m4-fl23-works\FwRev\fw\7M4_v602\firmware.fdat` | 754,521,088 B，加密形态；旁边 `config.yaml` 标记版本6.02、`CXD90057_k8`。已有 TAR 时无需重复从该形态开始。 |
| `C:\Users\HeMu\Desktop\CAppRev\artifacts\ble-firmware-static-20261103\ext2-inventory.json` | 已生成的 M4/RM5 `/usr` 全成员清单：`camera/path/bytes/mode`；筛选 `camera == "m4-v602"`。 |
| `C:\Users\HeMu\Desktop\CAppRev\artifacts\ble-firmware-static-20261103\copy-manifest.json` | 原资料路径、TAR来源链、复制件大小及既有哈希。上述大文件哈希此次未重新计算。 |

**提取树边界：**
`C:\Users\HeMu\Desktop\CAppRev\artifacts\ble-firmware-static-20261103\extracted\m4-v602\usr`
只落地了 BLE/WLAN 白名单子集；不要误认为已展开全部媒体库。
具体已落地成员见同资料根目录的 `extracted-manifest.json`。
旧报告提到的 `C:\Users\HeMu\AppData\Local\Temp\a7m4-gt` **当前不存在**，不能直接引用为可用 rootfs。

## 2. 与当前问题有关的已有定位

下表仅是上述 **M4 `/usr` 镜像现有清单**中的真实成员；镜像内部 `/lib/...` 对应设备 `/usr/lib/...`。
这些媒体成员目前不在 BLE 提取子集中。**未做其 MP4/AVC/SD 编录函数级分析，不能仅凭名称认定职责。**

| 镜像内部成员 | 字节 |
| --- | ---: |
| `/lib/libInfraMediaCommon.so` | 402,656 |
| `/lib/libInfraMediaConfig.so` | 52,344 |
| `/lib/libInfraMediaMount.so` | 65,392 |
| `/lib/libInfraMediaDetect.so` | 98,240 |
| `/lib/libInfraAvbbc.so` | 1,738,760 |
| `/lib/libEsCodecLibrary.so` | 23,024 |
| `/codec/vcd_firmware.bin` | 5,445,340 |
| `/codec/vcd_firmware_imola2.bin` | 10,934,476 |
| `/codec/vcd_firmware_imola2_fpga.bin` | 8,837,324 |
| `/kmod/codec_drv.ko` | 19,216 |

**没有找到本项目已有的以下专项证据：**PROF/VPRF 解析函数、AVC decoder admission 条件、
SD `PRIVATE/DATABASE/DATABASE.BIN` 或 `MEDIAPRO.XML` 的生成/修复调用链，以及能证明25 Mbps流可回放的固件结论。
不能把通用媒体挂载、Veric流媒体或Android MP4解析库当成这些结论的替代。

另有真实存在的 **RM5对照件**：
`C:\Users\HeMu\Desktop\a7m4-fl23-works\r5\part\appFw.so`（97,368,304 B）、
同目录 `nflasha5`（243,789,184 B）和 `nflasha15`（410,652,672 B）。
它们**不是7M4固件**，本交接没有提供它们的媒体函数反编译结论。

## 3. 已有离线工具、Ghidra与索引

令 `S = C:\Users\HeMu\Desktop\CAppRev\artifacts\ble-firmware-static-20261103`，以下路径均已核实存在：

- `S\tools\fwtool\fwtool.py`、`S\tools\fwtool\fwtool\archive\ext2.py`、`fat.py`：已有 fwtool 副本；`ext2.py` 提供 `isExt2/readExt2`。许可证 `S\tools\fwtool\LICENSE.txt`。
- `S\tools\extract_ble_subset.py`：已用过的用户态 ext2 成员读取、哈希和落地范例；**其 TARGET 正则只抽 BLE/WLAN，原样运行不会提取上表媒体成员**。
- `S\tools\DecompileFunc.java`、`FocusBleFirmware.java`、`FocusStackPrivacy.java`、`Invoke-GhidraOffline.ps1`：已有反编译工具；最后一项的 Target 固定为三种蓝牙对象，不能直接当作媒体分析入口。
- `S\ghidra\M4Core.gpr` + `M4Core.rep`：M4 `libInfraBluetoothCore.so` 项目。
- `S\ghidra\Rm5Core.gpr` + `Rm5Core.rep`、`Rm5Stack.gpr` + `Rm5Stack.rep`：RM5蓝牙核心/栈项目。
- `S\analysis\elf-survey\*.symbols.json`、`*.strings.json`：既有蓝牙相关符号/字符串索引。
- `S\analysis\m4-core-expanded`、`rm5-core-expanded`、`rm5-stack`：既有伪C输出，原报告分别记录59/57/39个函数，**均不是MP4回放工程**。
- `C:\Users\HeMu\Desktop\CAppRev\tools\ghidra_scripts\DumpNativeInventory.java`：通用函数/符号/导入/字符串导出脚本。
- 工具环境：`E:\Program Files\ghidra_12.1.4_PUBLIC\support\analyzeHeadless.bat`；
  `E:\Program Files\jdk-21\bin\java.exe`；`E:\anaconda3\envs\test311\python.exe`。

已有分析入口：
`C:\Users\HeMu\Desktop\CAppRev\docs\reviews\2026-11-03-ble-firmware-static-privacy.md`
及 `S\RESUME.md`，可核对来源、工具使用和限制。该报告指出 RM5 的 `UDTRFIRM` 容器还含明确边界的 TAR，
不能仅因7z识别到内嵌更新器SquashFS，就将更新器当成完整运行时文件系统。

**交接结论：**可立即复用7M4 6.02完整 `/usr` 镜像、成员清单与离线解析工具；
现有Ghidra工程/反编译主要是蓝牙专项，尚无可直接移交的PROF/VPRF、AVC准入或SD编录规则实现证据。
