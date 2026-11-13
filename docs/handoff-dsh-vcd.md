# DSH 会话交接：VCD 固件变体 / 加载器 / 镜像结构（有界查证）

写于 2026-11-12。**只做既有材料的有界查找**：未访问相机、未刷写、未改卡、未改任何既有分析。
本文件只回答"我手上已经有什么"，并标注置信度；没有做新的广泛逆向。

---

## 0. 最重要的一条：机型加载的不是你正在分析的那个变体

| 变体 | 文件 | `SW_VER` | 头部偏移 | 被谁引用 |
|---|---|---|---|---|
| `vcd_firmware.bin` | `firmware/m4-v602/usr/codec/vcd_firmware.bin`（5,445,340 B） | `SW_VER_13_11_10_0` | raw `0x10` | **M4 未引用** |
| **`vcd_firmware_imola2.bin`** | `firmware/m4-v602/usr/codec/vcd_firmware_imola2.bin`（10,934,476 B） | `SW_VER_46_21_02_0` | raw `0x10` | **M4 引用** |
| `vcd_firmware_imola2_fpga.bin` | 同目录（8,837,324 B） | `SW_VER_40_11_02_0` | raw `0x10` | M4 未引用 |

**证据（可直接复核）**：`analysis/vcd/nflasha3/files/av-cam.bin`（12,729,680 B，
来自 `FwRev/fw/7M4_v602/firmware.tar` 成员 `0700_part_image/dev/nflasha3`）
在 **raw 偏移 `0x43617F`** 处有一条字面路径：

```
[TSKVIDENC ][RcvINF]VIDEO_ENC_ENCODE_PICTURE
[TSKVIDENC ][RcvINF]VIDEO_ENC_RELEASE_ES
/usr/codec/vcd_firmware_imola2.bin
```

- 全 `/usr` 树 + `/system`（nflasha3）+ p1（nflasha1）+ rootfs（nflasha7）**没有**其它字面量引用
  `vcd_firmware.bin` 或 `vcd_firmware_imola2_fpga.bin`。
- **第二份独立证据**：`analysis/vcd/nflasha5`（210,606,208 B，`nflasha5` 暖启动镜像 = 运行中系统的 RAM 快照）：

  | 字符串 | 出现次数 | 首次偏移 |
  |---|---:|---|
  | `SW_VER_46_21_02_0` | **2** | `0x5C7BA7C` |
  | `/usr/codec/vcd_firmware_imola2.bin` | **3** | `0x66FE21C` |
  | `SW_VER_13_11_10_0` | **0** | — |
  | `SW_VER_40_11_02_0` | **0** | — |
  | `/usr/codec/vcd_firmware.bin` | **0** | — |

  也就是说：**运行时内存里只出现过 imola2 的版本串与路径**，另外两个变体一次都没出现。
- **置信度：高**（"M4 6.02 引用并加载 `vcd_firmware_imola2.bin`"）。
- **未证明**：运行时是否存在回退分支；这需要相机侧跟踪，不在本交接范围。

> 直接后果：你现在反编译的 `vcd_firmware.bin`（`SW_VER_13_11_10_0`）**不是** M4 加载的那一份。
> 它的源码路径族也是旧的（`Spu/control/encode/AVC/…`、`Spu/control/decode/common/…`），
> 而 `imola2` 是新的 `src/ipsx/release/spu/all/ctrl/video/dec/avc/…` 族。

### 0.1 好消息：解码器源文件在 imola2 里同样存在

`vcd_firmware_imola2.bin` 内含 79 个 avc/dec 相关源文件路径，包括你列的同一组：

```
src/ipsx/release/spu/all/ctrl/video/dec/avc/avcdec_ctrl.cxx / .h
src/ipsx/release/spu/all/ctrl/video/dec/avc/avcdec_dpb.cxx
src/ipsx/release/spu/all/ctrl/video/dec/avc/avcdec_frame.cxx
src/ipsx/release/spu/all/ctrl/video/dec/avc/avcdec_proxy.cxx
src/ipsx/release/spu/all/ctrl/video/dec/avc/avcdec_reference.cxx
src/ipsx/release/spu/all/ctrl/video/dec/avc/avcdec_syntax.h
src/ipsx/release/spu/all/ctrl/video/dec/common/vdec_auinfo.h
src/ipsx/release/spu/all/ctrl/video/dec/common/vdec_ctrl_base.h
src/ipsx/release/spu/all/ctrl/video/dec/common/vdec_proxy.cxx
src/ipsx/release/spu/all/ctrl/video/dec/common/vdec_top.cxx
```

所以**源码级结论可以沿用，但地址/GP/SP/函数偏移必须重做**（版本 13→46，代码布局不同）。

---

## 1. 加载器：内核侧有，用户态发送者未定位

### 1.1 `codec_drv.ko`（**已证实是文件加载器**）

`firmware/m4-v602/usr/kmod/codec_drv.ko`（19,216 B）

| 项 | 值 |
|---|---|
| modinfo | `description=Beaune Driver`、`author=Sony Corporation`、`vermagic=4.9.337-scel SMP preempt mod_unload aarch64` |
| 源文件 | `DSP-Drivers-Codec_161H/driver/{bdrv_driver,bdrv_loader,bdrv_thread,bdrv_uipc}.c` |
| 日志前缀 | `[DRVCDC]` |
| 关键函数符号 | `bdrv_loader_file_load`、`bdrv_uipc_send_msg`、`bdrv_uipc_recv_msg`、`bdrv_thread_create_thread` |
| 调用到的内核 API | `filp_open`、`vfs_read`、`filp_close`、`arch_phys_to_noncache` |
| 文件错误串 | `filp_open() is error`、`file size error, read_size=%d > file_size=%d` |
| 消息序列 | `GET_VERSIONINFO start/done` → `LOAD_FIRMWARE start` → `LOAD_FIRMWARE_SHADOW start` → `LOAD_FIRMWARE done` → `enter main loop` |
| 消息 ID 字符串 | `EXTERNAL_CODEC_DRIVER_LOAD_FIRM` |

**结论（高置信度）**：VCD 固件是**内核模块 `codec_drv.ko` 用 `filp_open`+`vfs_read` 从文件系统读出后交给编解码器**的，
不是 mmap 映射 ELF，也不是 `request_firmware`（模块里没有 `request_firmware` 符号）。

**加载顺序（已证实）**：`analysis/vcd/nflasha3/files/initrd.img` 的 raw `0x4E8905` 附近有
`insmod /usr/kmod/codec_drv.ko`（同串还列出 `mmc_drv.ko`、`sata_drv.ko`、`msen_drv.ko`）。

**未定位（中/低置信度）**：哪个用户态库发 `EXTERNAL_CODEC_DRIVER_LOAD_FIRM`。
`/usr` 全树中只有 `codec_drv.ko` 自己含这个字符串，说明发送方用的是**数值 ID**，不是名字。
候选库：`libInfraAvbbc.so`(1,738,760)、`libMWF.so`(353,120)、`libInfraCCPF.so`(1,212,696)、
`libEsCodecLibrary.so`(23,024)、`libInfraVericEsCodecLibrary.so`(22,912)。**未反编译，未证实。**

### 1.2 `liro.ko`：`av-cam.bin` 的容器加载器（**另一件事**）

`firmware/m4-v602/usr/kmod/liro.ko`（121,488 B）

| 项 | 值 |
|---|---|
| 源路径 | `BuildWorkSpace/Etools-LIRO_191H/driver/os/os.c` |
| 模块参数 | `load:int`、`liro_resume_async:int` |
| 字符串 | `Load firmware %s to %p`、`%llx -> %p : %x %lx loaded (%s)`、`Magic unmatched %x != %x`、`Address not set, firmware will no be loaded!`、`/proc/liro/start`、`liroapp resume start/end`、`[LIRO]: liro resume (WBI)` |
| 与 WBI 的关系 | `liro suspend (WBI)` / `liro resume (WBI)` — 与 `nflasha5` 暖启动镜像同一套 resume 路径 |

`av-cam.bin` 的头部（raw 0x00）是 `58 00 00 01 c0 ff ff ff 4f 52 49 4c`，
其中 `4f 52 49 4c` = ASCII **"ORIL"**（"LIRO" 的反写）。`liro.ko` 里没有 ASCII `ORIL`，
说明 magic 是**数值比较**（对应 `Magic unmatched %x != %x`）。

**置信度：中** —— 结构上高度吻合（`Load firmware %s to %p` + magic 校验 + ORIL 头），
但"liro 加载的就是 av-cam.bin"没有直接字符串证据，未做交叉验证。

---

## 2. 镜像结构：我只有"没有 ELF、没有段表"这一条是确定的

对三个变体的前 `0x4000` 字节做检查：

| 检查 | 结果 |
|---|---|
| 内嵌 `\x7fELF` | **0 处**（三个变体都是） |
| 段表 / 节表 ASCII（`.text`、`PT_LOAD` 等） | 前 `0x4000` 内**没有** |
| 固定头 | `0x40` 字节：`0f 00 00 10` + 12 字节 0 + `SW_VER_...`（32 B） |
| `0x30` 处 | `00 60 1a 40 02 d4 1a 00 10 00 5a 33 ec 00 40 13 00 00 00 00 ea 00 00 10` —— **三个变体完全相同** |
| `SW_VER` 出现次数 | 每份 **3 次**（头部 `0x10`，正文各两份）<br>`imola2`：`0x10`、`0x20087C`、`0x235CA4` |

`SW_VER` 有 3 份、且彼此分隔很远，**推测**镜像由多个子镜像/子核拼接（每段自带版本串），
但**没有段表可以证实**——这只是推测，置信度低。

**结论**：
- 「不是 ELF、没有段表」——**高置信度**（可直接复现）。
- 「section / overlay / 各段 load 地址」——**我没有任何材料**。你手上的
  `raw+0x40`、`raw+0x400`、`raw+0x4300`、`GP=0x802f32a0`、`SP=0x804c7998`
  是我见过的唯一结构证据，我无法补充或证伪。

---

## 3. MIPS 扩展：我没有独立证据

- 我没有跑过 Capstone/objdump 去验证 ISA。
- 唯一能提供的旁证：`raw 0x30` 处的 `00 60 1a 40` 按小端读作 `0x401A6000`，
  属于 COP0 类编码（`mfc0` 族），与「MIPS32 + CP0 在启动早期被配置」一致。
  这只是**读字节的观察**，不构成 ISA 结论。
- **置信度：低/无**。

---

## 4. 有没有验证过的 VCD / Mbp / SPU 加载器

**没有。** 我手上没有任何 VCD/Mbp/SPU 的加载器实现或验证过的地址映射。

能提供的相关线索（都未验证）：

| 线索 | 路径 | 说明 |
|---|---|---|
| `libEsCodecLibrary.so` | `firmware/m4-v602/usr/lib/`（23,024 B，53 个函数符号） | ES 编解码封装 |
| `libInfraVericEsCodecLibrary.so` | 同上（22,912 B，44 个符号） | Veric 变体 |
| `libInfraAvbbc.so` | 同上（1,738,760 B） | AVBB 控制，可能是 codec_drv 的用户态调用者（**未证实**） |
| `libInfraAdjMedia.so` | 同上（322,280 B） | 含 `Cmd_PmbpCheckData` / `Cmd_PmbpGetStatus` / `Cmd_PmbpWriteData`（注意：**Pmbp ≠ Mbp 编解码**，这是卡侧 mbp 分区操作） |
| `/usr/codec/adjust/dec/`、`/usr/codec/adjust/enc/` | 被 `av-cam.bin` 引用 | 列出 `AVCVES.bin`、`AVCAES.bin`、`AVCHCFG.bin`、`AVCYCMP.bin`、`AVCLCMP.bin`、`HEVC*` 等；**这些目录在解出的 `/usr` 里不存在**，可能在 VCD 镜像内部，也可能是别的机型的路径 |

---

## 5. 建议的最小下一步（都不需要相机）

1. 把 Ghidra 工程 `analysis/ghidra/vcd` 换成 **`vcd_firmware_imola2.bin`**（`SW_VER_46_21_02_0`）。
   你现在 `0x800b7c64 / 0x800b9c4c / 0x800bda38` 的交叉引用来自 `13_11_10_0`，**不能直接搬**。
2. 先确认 imola2 的镜像内是否存在同样的 `avcdec_ctrl` 字符串簇，用它们做 anchor 反查函数，
   而不是沿用旧版本地址。
3. `>0x804e0000` 段"访问冲突全局"的现象，在 imola2 上先看它是不是**第二个子镜像**的
   独立地址空间（`SW_VER` 出现 3 次是线索），这比在单地址空间里强行统一更可能解释得通。
4. 想确认 `codec_drv.ko` 的用户态发送者，最小代价是在 `libInfraAvbbc.so` 里找
   发送 uipc 消息的调用（`osal_snd_sync_msg` / `osal_snd_msg` 的 xref），不需要整库反编译。

## 6. 一句话

**M4 加载的是 `vcd_firmware_imola2.bin`（`SW_VER_46_21_02_0`），不是 `vcd_firmware.bin`；
加载路径是内核模块 `codec_drv.ko` 的 `bdrv_loader_file_load()`（`filp_open`+`vfs_read`）；
镜像不是 ELF、没有段表，`SW_VER` 在文件里有 3 份；我没有 MIPS 扩展与 SPU/Mbp 加载器的验证结论。**
