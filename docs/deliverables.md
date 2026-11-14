# 产出与交付索引

整理日期：2026-11-14。范围是当前工作区的源码、操作方法、媒体实例、测试与研究证据。
本次只整理本地文件、补记用户反馈；不访问存储卡，不创建新的卡快照，不写卡或删文件。
这是交接索引，不是Sony格式认证、安装包或“任意输入一键导入器”。

## 1. 已经交付了什么

| 产出 | 当前可用程度 | 入口 |
|---|---|---|
| 从输入到相机SD卡回放的可复现方法 | 多份具体输入/配置已有实机成功证据；需要分步骤操作和验证 | [完整复现手册](sd-xavcs-reproduction.md) |
| 编码、Sony封装、缩略图、编录、部署与审计源码 | 可在本机现有环境运行；不是无依赖的独立软件 | `tools/`，见第4节 |
| 五项普通编码配置 | Cat输入已有具体成功实例，不保证所有输入 | [当前状态](current-status.md)，第2节矩阵 |
| 4M低码率研究与可播放实例 | 独立诊断入口；未加入普通配置注册表 | [实验0029](experiments/0029_4m_prof_diagnostic.md) |
| 长输入C0010 | 用户明确确认正确播放，且本次修复数据库后仍正常播放 | [新增实机反馈](../analysis/camera-observations-0033-result.json) |
| 软件与原厂读取验证、回归测试 | 全量软件检查与有限原厂探针分别留证，不冒充硬件播放 | `tools/tests/`、包内验证报告、`analysis/` |
| SD编录与固件读取/修复机制研究 | 已形成可用写卡规则及受限原厂代码交叉验证 | 第6节 |
| EDIUS写入器研究、早期修补方法 | 研究材料/历史路线，不能替代当前SD编录流程 | 第6节 |
| 快照、参考媒体、构建包和原始工程 | 本机保留；其中大量材料不在Git中 | 第7节 |
| 本地机器可读盘点 | 文件存在性、部分文本哈希、包及快照清单；不是新验证 | [盘点JSON](../analysis/deliverables-inventory-20261114.json) |

图像压缩与实际码率分配由libx264完成。本项目提供参数配置、Sony封装及时序调整、
编录和验证，没有另写视频码率控制算法，见[通俗说明](bitrate-control-explained.md)。

## 2. 实机能力矩阵

以下视频均为8-bit、4:2:0、逐行H.264，音频采用双声道48kHz PCM。
“正常播放”是用户概括性反馈，不补填未单独报告的完整时长、音频、缩略图或跳转。
“修复后”必须与具体修复轮次和具体媒体版本绑定。

| 配置/实验 | 图像规格 | 实际视频目标 | Sony码率声明 | 实机证据与限制 |
|---|---|---:|---:|---|
| `hd25_5994` | 1080p59.94，High4.2 | 25M | 25M/25M | C6515正常；C6514是另一已成功容器布局 |
| `hd50_5994` | 1080p59.94，High4.2 | 50M | 50M/50M | C6517正常 |
| `uhd60_2997` | 2160p29.97，High5.1 | 60M | 60M/60M | C6518正常 |
| `hd50_2997` | 1080p29.97，High4.1 | 50M | 50M/50M | C6519正常 |
| `hd16_2997` | 1080p29.97，High4.0 | 16M | 16M/16M | C6520原版正常；XML修正版列出已恢复，再次修复后数据库记录保留并补全 |
| 4M/29.97诊断A | 1080p29.97，High4.0 | 4M | 16M/16M | C6521原版可播；XML修正后列出恢复。新长输入C0010本次修复前后均获正常播放反馈 |
| 4M/59.94诊断A | 1080p59.94，High4.2 | 4M | 25M/25M | C6523可播，已有此前修复后仍正常的反馈 |
| 4M/59.94诊断B | 同上一行的编码载荷 | 4M | 4M/4M | C6524可播，已有此前修复后仍正常的反馈 |
| 4M/29.97诊断B | 与29.97诊断A原始载荷相同 | 4M | 4M/4M | C6522不能播放；原厂媒体属性查询返回3；最新快照仍为稀疏记录，不是成功交付样本 |

C6520/C6521修正版没有获得与C0010相同的“本次修复后正常播放”补充反馈。
4M成功不能推导普遍最低码率，也不证明每个缓冲/元数据字段都必需或都可省略。
配置来源见[0025](experiments/0025_source_control_and_compact_container.md)、
[0026](experiments/0026_explicit_avc_sd_profiles.md)、
[0028](experiments/0028_hd2997_50m_16m.md)、[0029](experiments/0029_4m_prof_diagnostic.md)。

## 3. 可交接的媒体实例

盘点JSON逐项列出所有本地`build-manifest.json`包及两份定点修正版。
同一片段可能有预备包、部署副本、修正版，不能按编号去重后混用哈希。
这些目录是实例与证据，不是可以原样再次写卡的通用安装包。

| 目录/文件 | 用途 | 必须保留的边界 |
|---|---|---|
| `output/cat-compact4-C6515/` | 25M/59.94主成功样本 | 新写入须另分空号、重建身份和当前编录、重新验证 |
| `output/cat-aligned4-C6514/` | 25M/59.94替代布局成功样本 | 不是独立的新编码配置 |
| `output/profiles-0026-deploy/C6517/`、`C6518/` | 50M HD与60M UHD实际部署实例 | 对应`profiles-0026-hd50/`、`profiles-0026-uhd60/`还保留预备副本 |
| `output/profiles-0028-hd50-2997/package/` | 50M/29.97成功实例 | 旧验证报告不等于当前准入 |
| `output/profiles-0028-hd16-2997/package/` | C6520原始成功实例 | 含L40旧名称，禁止作为当前合格包直接部署 |
| `output/repair-0031/C6520/`、`C6521/` | 两段的已写入XML修正版 | `repair-manifest.json`、`repair-deployment.json`为定点操作证据，不是普通构建清单 |
| `output/bitrate-0029-29/`、`output/bitrate-0029-59/` | 四份原始4M配对实验 | 保留A/B同载荷证据及失败对照；C6521此处不是后来的XML修正版 |
| `output/mux-0030-29/encode/base.mov` | 长输入已经编码的4M结果 | 可以作为后续重新封装的来源；需要原规格、编码命令和假设记录 |
| `output/mux-0032-29/A/C0010.MP4`及同目录 | 长输入实际部署、修复后正常播放的实例 | 新反馈只确认这个具体输入、配置和修复轮次 |
| `output/mux-0032-29/B/` | 同载荷4M声明的本地拒绝对照 | 未部署；不得当成成功样本 |
| `output/mux-0030-29/A/`、`B/` | 旧长输入准备包 | 含L40错误，保留历史，不能直接部署 |
| `output/source-control-C6511/` | 历史源内容对照，已可播 | 不是从任意输入重新编码的证明 |
| `output/cat-compact-C6512/`、`cat-aligned3-C6513/` | 三字节NAL长度失败对照 | 能列出、有缩略图但不能播放；不得交作可播实例 |
| `output/runbook-check-20261113T104516/` | 操作手册离线演练 | C6516未部署，未实机验证，也没有预留该编号 |
| 其余`output/`目录 | 早期候选、原生对照、合成输入或中间编码 | 以实验记录判断；文件存在或旧`passed=true`不代表当前合格 |

C0010媒体SHA-256：
`5c30633d67fafab81af53c366df9d7194b558ac7a866933505862c3dc032bff5`。
图像5276帧、约176.043秒，实际视频平均约3.999M，整个MP4约5.783M。
原输入是`mux_playfull_ytb_1080.mp4`；另一主要测试输入为`Cat_25-12-25.mp4`。

## 4. 可复用操作链与本地文件

完整命令、先后关系和逐字节编辑清单以[复现手册](sd-xavcs-reproduction.md)及各配置实验为准。
下表是工具导航，不是可省略验证的快捷流程；所有构建/缩略图/编录先写工作区。

| 阶段 | 主工具 | 产物/作用 |
|---|---|---|
| 取证与分配前快照 | `tools/card_snapshot.py` | 保存非媒体文件，媒体只记大小及时间；不是完整卡镜像 |
| 输入转换与编码 | `tools/encode_xavc.py` | `base.mov`、输入探测、参数假设、完整命令和日志 |
| Sony封装 | `tools/build_sony_clip.py` | MP4、内嵌XML、旁路XML、身份及`build-manifest.json` |
| 缩略图 | `tools/build_sony_thumbnail.py` | 两级JPEG及相机样式`T01.JPG`，依赖`jpeg422.exe`和`thumb_header.bin` |
| 当前编录暂存 | `tools/stage_sd_catalog.py` | 两份本地编录和`catalog/transaction.json`；历史模板须核验当前依赖 |
| 完整软件/结构验证 | `tools/verify_sony_package.py` | schema 6的`verification.json`及独立`verification_runs/` |
| 原厂编录交叉检查 | `tools/verify_staged_catalog_firmware.py` | `firmware-catalog-verification.json` |
| 原厂媒体/XML检查 | `tools/emulate_xavc_reader.py`、`emulate_nrt_semantics.py` | 有界原厂读取报告，单独记录调用与状态，不等于全片硬件解码 |
| 写卡预检与执行 | `tools/deploy_sd_clip.py` | 默认只预检；显式`--apply`写新三资源及两编录，写前快照并逐项读回 |
| 写后取证与审计 | `card_snapshot.py`、`audit_sd_test_round.py`、`compare_sd_snapshots.py` | 新快照、累计写入审计和记录变化 |
| 实机确认 | 用户机身操作，另记`camera-observations-*.json` | 列出、缩略图、播放、完整时长、音频、跳转、数据库修复分别留证 |

卡上只新增片段MP4、旁路XML、缩略图三份资源，更新MEDIAPRO及DATABASE两份编录。
编码MOV、中间JPEG/YUV、manifest、transaction和验证日志不复制到卡。
目前没有覆盖以上全部步骤的一键入口，也没有已实现的任意长度自动分卷。
部署器不强制读取独立的原厂编录验证报告，因此操作者仍必须按手册完成该项交叉检查。
这项边界是现状说明，本次没有改变部署器行为。

## 5. 工具分类与测试

| 类别 | 代表性产出 | 定位 |
|---|---|---|
| 核心格式模块 | `sony_mp4.py`、`sony_db.py`、`sony_profiles.py`、`sony_rtmd.py`、`sony_umid.py`、`sony_nrt_codec.py` | MP4/编录/配置/逐帧信息/身份及独立XML名称规则 |
| AVC验证 | `trace_avc.py`、`check_avc_timing.py`、`check_avc_slice_order.py`、`check_avc_cpb.py`、`compare_avc_payloads.py` | 语法、时序、缓冲、切片及图像载荷证据；单项通过不能代替整包 |
| 4M诊断 | `bitrate_experiment.py`、`compare_bitrate_pair.py`、`bitrate_reader_evidence.py`、`verify_bitrate_media.py`、`summarize_bitrate_round.py` | 独立规格、配对证明及精确预期拒绝；部署须显式`--allow-diagnostic` |
| 卡与修复研究 | `compare_sd_snapshots.py`、`analyze_sd_repair.py`、`hash_snapshot_media.py`、`catalog_listing_matrix.py` | 快照差异、媒体哈希、引用图及证据汇合 |
| 固件离线探针 | `emulate_sidb_readers.py`、`emulate_sidb_converter.py`、`emulate_mediapro.py`、`emulate_nrt_extract.py`、`emulate_nrt_semantics.py`、`emulate_sd_repair_fields.py`、`emulate_vcd_guards.py`、`emulate_vcd_status_flow.py` | 只运行选定函数和建模依赖，不是完整机身模拟器 |
| 静态逆向辅助 | `elf_survey.py`、`inspect_mpr_linkage.py`、`survey_vcd.py`、`run_ghidra.py`及Java脚本 | 固件/程序逆向环境与导出工具 |
| 历史定点操作 | `repair_clip_codec_0031.py`、`revise_owned_clip.py`、`investigate_repair_0031.py`、`analyze_repair_0033.py` | 固定实验或授权目标；不是可以自行扩大范围的通用修复器 |
| 旧EDIUS补丁链 | `deblock_inject.c`、`sps_patch.c`、`xavc_rebuild.c`、`avclevelpatch.c`、`build_thumbnails.ps1` | 保留早期成功/失败历史；不纳入当前普通主流程，部分含原地操作或旧盘符 |
| 盘点与本机协作 | `inventory_deliverables.py`、`dsh_client.py`、`dsh_web_cli.ps1` | 前者只整理工作区；后两者依赖本地服务，不是媒体生产依赖 |

完整脚本、测试文件和反编译导出路径见盘点JSON，不只限于此表。
不要批量执行所有脚本的`--help`：部分历史脚本没有参数解析器，可能直接运行。
测试入口为`python -m unittest discover -s tools/tests -v`。
上次完整回归为[0033日志](../analysis/0033-regression.log)：308项通过；
它属于当时版本，不自动等于本次新增盘点代码的全量回归结果。
原厂仿真测试依赖本地固件；换机器时必须区分“通过”和因缺材料而“跳过”。

## 6. 研究知识与证据

| 主题 | 文档/材料 | 已有结论与未完成部分 |
|---|---|---|
| 早期EDIUS和码流修补 | [历史修补手册](patching-recipe.md)，实验0001至0012 | C0006/C0007等历史成功路线；不是当前新输入复现规范 |
| 编码与原厂解码路径 | 实验0013至0018，`analysis/vcd/`、`analysis/decompile-*/` | 原厂有界读取、状态传播、切片顺序和缓冲时序；不是全部硬件解码规则 |
| SD编录与界面消费链 | 实验0019至0022，[appFw笔记](appfw-catalog-notes.md) | 文件/目录、记录、引用、校验与UI侧调用证据；没有单一线索解释所有历史失败 |
| 从能列出到能播放 | [0023](experiments/0023_listed_but_cannot_display.md)、[0024](experiments/0024_sample_tables_and_metadata.md)、[0025](experiments/0025_source_control_and_compact_container.md) | 四字节NAL封装的配对实机证据，区分列出/缩略图/播放 |
| 多配置扩展 | [0026](experiments/0026_explicit_avc_sd_profiles.md)、[0028](experiments/0028_hd2997_50m_16m.md) | 五项普通配置及独立历史稀疏模板流程 |
| 数据库修复行为 | [0027](experiments/0027_camera_database_repair.md)、[0031](experiments/0031_repair_codec_name.md)、[0033](experiments/0033_second_repair_observation.md) | 补全记录、XML L4/L40问题及修正后的实际重建证据；不是所有修复循环的保证 |
| 低码率与长输入 | [0029](experiments/0029_4m_prof_diagnostic.md)、[0030](experiments/0030_mux_1080p_2997_4m.md)、[0032](experiments/0032_mux_low_number_sd.md) | 图像码率与Sony声明解耦；C0010经本次修复后正常播放 |
| EDIUS写入器逆向 | [EDIUS笔记](edius-writer-catalog-notes.md)，`analysis/edius-catalog/` | 已定位XAVC-S MP4相关实现，保留模块采集及MXF结束路径；未证明完整SD注册/提交序列，不能把MXF逻辑套用到MP4 |
| 对外协作上下文 | `docs/handoff-*.md`、`docs/handoff-*.txt` | 原始问题、跨会话来源与调查请求；不是规范或认证结论 |

原始证据按用途分为：`camera-observations-*`实机反馈、
`camera-test-round-*`准备摘要、`sd-test-round-*`写后审计、
`*-reader-*`/`*-nrt-*`原厂读取、`*-pair-*`配对证明、快照差异和回归日志。
软件、原厂读取、磁盘编录、机身回放是不同证据层次。
早期字段表和`Proj_StartingPoint.md`保留历史；当前操作先读README和current-status。
`model*`/`attempt*`仿真开发报告、超时与运行库缺失不能计作相机媒体拒绝证据。

## 7. 交接材料分层

| 交接层 | 应包含的材料 | 本机/Git边界 |
|---|---|---|
| 源码与说明 | 当前`tools/`源码、测试、`docs/`、README、AGENTS、`.gitattributes`和相关文本证据 | 主要由Git管理；本次新增整理尚未另行提交 |
| 本机复现材料 | 对应配置的PROF/结构/RTMD参考MP4、原始输入、`jpeg422.exe`、`thumb_header.bin`、Python与FFmpeg环境 | EXE、MP4、`output/`等被忽略，克隆Git不等于材料齐全 |
| 原厂验证材料 | 固件6.02的`libmpr.so`、`libexpat.so.1.6.11`、`libstdc++.so.6.0.22`及所需快照 | 固件版本/哈希固定；不能从旧报告代替缺失依赖 |
| 案例证据 | 选定成功/失败包的媒体、构建/修正清单、编码命令、验证运行、部署审计、实机反馈 | 应以具体文件哈希绑定，不能只交MP4和一句“验证通过” |
| 研究归档 | `backup/`、`firmware/`、`analysis/appfw-catalog/`、`analysis/edius-catalog/`、Ghidra工程、原始反编译/汇编/采集日志 | 大量仅在本机或未跟踪；未制作可携带完整归档，不能默认具有第三方二进制再分发授权 |

当前快照系列最新已记录卡状态为`backup/snap_20261114T013129`，
对应78份元数据、155项媒体清单；不是当前插卡状态保证，也不是完整视频备份。
C0010写后快照为011354；名称修正后为002832；独立稀疏模板的已用来源为
`backup/snap_20261113T135135`。所有快照完整清单见盘点JSON。
任何下一次写卡仍必须取得新快照并核对依赖，不能用这些整库覆盖当前卡。

## 8. 迁移与尚未产品化的部分

- 推荐使用已配置的`E:\anaconda3\envs\test311\python.exe`；需要Python 3.11相关API、
  支持libx264及当前滤镜/PCM的FFmpeg/ffprobe，固件探针另需Unicorn和pyelftools。
- 当前缩略图需要本机`tools/jpeg422.exe`。源码为`jpeg422.c`，重编译另需C编译器及libjpeg；
  不是仅复制Python源码便可完整运行。
- 主流程不需要启动EDIUS或Catalyst，但仍依赖从原生/历史EDIUS样本提取的结构与逐帧信息。
  25M和29.97p用的参考组合不同，详见复现手册依赖表及实验0028。
- 编录、清单和验证报告有绝对路径与哈希绑定。移动目录后要核对路径、重建必要证据；
  不能手改报告绕过准入。未提供统一环境锁、自动安装器或跨平台迁移验证。
- 当前封装器内存构建，输出必须小于4GiB；没有自动跨文件分卷。
- 尚不支持CFexpress、任意H.264参数、10-bit/4:2:2、任意更低码率或普遍最低码率保证。
  不能把“尚未研究/实现”写成“机身一定不支持”。
- 当前SD写入不是完整原生编录生成器；稀疏模板必须与当前支持/路径依赖匹配，
  失败即停止。不自动回滚旧库，不擅自改已有片段，不删除卡文件。
- 暂未建立所有成功文件的完整时长、音频、跳转及多次数据库修复的统一实机回归矩阵。

## 9. 盘点复现与使用顺序

先读本索引，再按current-status选择对应配置/实验，最后按复现手册执行。
若只交接研究，保存源码、证据及本机材料的区别即可，不应运行部署或修正工具。
若下一步是增加新视频，应重新分配身份和空号、从新卡状态编录、完成验证与机身测试。

本次机器盘点通过以下命令生成，执行时只读取工作区并创建一份新的JSON：

```powershell
& 'E:\anaconda3\envs\test311\python.exe' tools/inventory_deliverables.py --output analysis/deliverables-inventory-20261114.json
```

输出已存在时拒绝覆盖，复盘应另取文件名。盘点记录普通文档/源码及顶层证据、
本地包、编码中间文件、快照摘要与研究目录；不递归枚举大型原始工程和提取固件。
小型文本记录哈希，媒体只记存在性、大小、时间及历史声明哈希，不重新哈希媒体。
它不重新验证旧报告、不获得卡的新状态、不建立播放成功，也不产生新的部署授权。
此前提交`334b1b2`是0029至0033实现与证据的归档点；本次补充反馈和盘点另行留在工作区，
没有自动提交、打包、发布或清理文件。
