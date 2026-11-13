# 实验 0027：相机“修复影像数据库”后的 SD 编录

日期：2026-11-13，Asia/Shanghai。机身沿用用户的 ILCE-7M4 上下文；逆向对象为
M4 6.02 的 `libmpr.so`，不假定实机当前安装的版本已被独立确认。
本轮不写卡、不删除文件、不重新编码。相机修复操作由用户执行。

## 结论与边界

这次修复的可定位变化是 **sidb 元数据补齐**，未发现视频重编码证据：

- 71 份非媒体文件中，只有 `PRIVATE/DATABASE/DATABASE.BIN` 改变。
  `MEDIAPRO.XML`、全部 sidecar、其他管理文件均逐字节不变。
- 数据库原尺寸不变，修改 2,246 字节；96 → 115 条 active records，视频仍为51条。
  没有记录停用、没有媒体文件新增或移除。
- 38 条稀疏视频、23 条照片从 `raw[6]=0x18` 变为 `0x14`；
  原有13条 `0x90` 视频记录逐字节不变。旧 array72 也更新。
- 修复同时补齐以前能播放和不能播放的片段，**不构成解码／回放通过判据**。
- 得到 HD25、HD50、UHD60 的相机生成完整视频属性，7份独立、绑定媒体哈希的
  原厂 SDK 读出结果与修复后属性逐项相符。
- catalog UMID 的时间字节会被有损重建；11个 UUID 型片段无法用毫秒丢失解释。
  修复后是否仍能正常播放，尚无用户反馈。
- 找到数组缓存句柄的 Load/Create 不对称，局部原指令执行复现搜索差异；
  没有把它归纳为实机错误、重复条目或历史失败的统一根因。
- 修复后 C0007 不再是稀疏模板。当前 `observed_minimal` stager **会拒绝新数据库**；
  没有退回旧库、绕过校验，或擅自部署新候选。

**没有修复后的实机观察。** C6515/C6517/C6518 的“正常”和 C6512/C6513 的
“无法显示”均属于修复前的历史反馈；列出、缩略图、播放、seek、完整时长、音频
仍须分别记录。Catalyst 或以下仿真通过不能替代相机测试。

## 快照与完整性

| 项目 | 修复前 | 修复后 |
|---|---|---|
| 快照 | `backup/snap_20261113T135135` | `backup/snap_20261113T135646` |
| 元数据／媒体清单项 | 71 / 141 | 71 / 141 |
| 快照错误 | 0 | 0 |
| DB字节数 | 9,670,656 | 9,670,656 |
| DB SHA-256 | `58ce96ff2e4c66f2d932e23d99ee30a6090f91dad934963fdac370ed5328ab6b` | `881c2c5ffc31870390656a9bf4768684c0046ef6ca05635ce3772e18c7d71ff5` |

共同 MEDIAPRO SHA-256：
`3b3e9d22ca3a5e5fb14ebbb7ee9e4230e17bb2272233d024e464e018ccde4de7`。

`analysis/snapshot-repair-0027.json` 保存完整逐记录／逐字节变化。
`analysis/repair-comprehensive-0027.json` 另外复核两份快照各71个保存文件的大小和
SHA-256 均仍等于捕获时清单；它不修改快照。

修复后曾对卡上全部141个媒体计算 SHA-256，共 7,592,389,992 字节，零错误：
`analysis/repair-media-hashes-0027.json`，完成于本地14:10:03。
这不是全卡媒体的修复前后哈希对比，因为修复前没有完整媒体哈希。

独立历史证据交叉匹配见 `analysis/repair-media-preservation-0027.json`：

- 31/141个文件、4,206,881,832字节（55.4092%）匹配已知历史字节。
- C6507/C6509、C6511–15、C6517/18、C0007/C6359 共11个重点片段全部匹配。
- C6515/17/18 另有紧邻修复前的直接卡哈希，全部相等。
- 3-byte C6512/C6513 与4-byte C6515/C6514 两组对照均保持原字节。
  所以没有证据表明修复在 MP4 中偷偷重写了 NAL length 或 sample tables。
- 其余110个文件仅有前后大小／mtime一致，不能宣称逐字节不变。
  复制的 build/verification/round 记录不是多个独立实机实验。

后续恢复检查及子任务检查时 F: 已不在可用盘符中，最终在线审计未能执行；
没有把本地快照核验写成“当前卡仍逐字节不变”。卡重新连接后须先再制作快照。

## 修复到底写了哪些记录

原74条内容记录保持成员关系：23条照片 +51条视频。
注意媒体清单有52个MP4，其中一个是次级／proxy资源，不能按文件数推内容数。

新增 record99–117 共19条：

| 类型 | 记录 | 作用 |
|---|---|---|
| type2 / 36-byte binary | 99、100、102、103 | 照片属性 |
| type2 / 40-byte binary | 105–110、113、115–117 | 视频／音频参数组合 |
| type3 / subtype3 / 16-byte entries | 101 | 照片 ImageUniqueID |
| type3 / subtype2 / 32-byte entries | 104、111、112、114 | 共享的 masked UMID |

旧 array72 从 bitmap7、refcount11 变为 bitmapF、refcount23；新增slot3由12条照片引用。
旧空视频属性 record28 保留且字节不变，在已解码的内容／路径／binary引用布局中
没有入边；不据此声称固件具有或不具有通用垃圾回收。

`header+0x7c44` 内容分配游标仍为98，而支持记录已占到117。
下一空位为118，不能将游标98当作“99一定可写”；现有 stager 会扫描 bitmap，
这一点符合观察。没有为验证而实际向118写入。

## 标志位：不再凭差异猜语义

固件 SHA-256：
`1a7a8007828810f948eb4fb95b9a269176355553a69977f6d8f2ae59516f5532`。
本文代码地址均为 **ELF VMA**；保存的 Ghidra 地址需加 `0x100000`。

`mpr::RepairM4Inconsistencies`，`0xb9340`：

1. 检查 `recordInfo+0x61a`。
2. 进入 `GetRecordInfo`，并在需要时读取 still/thumbnail 属性。
3. 成功后设置 `recordInfo+0x619=1`、`+0x61a=0`，调用 `sidb::Update(...false,true)`。
4. 失败分支可能删除记录；**本次前后快照没有任何停用或文件删除**，
   也没有在卡或完整修复仿真中执行这些分支。

`sidb::ConvRecordInfo2RecordStructure`，`0x292a38`，
原指令片段 `0x292b78..0x292b90`：

| recordInfo 字段 | 持久化位置 |
|---|---|
| `+0x619 & 1` | content `raw[6] bit2` |
| `+0x61a & 1` | content `raw[6] bit3` |

执行全部256个初始字节 ×4种字段组合，共1024个写入片段案例，
以及4个 repair assignment 案例，全部符合映射，代码段不变。
因此在这个调用路径上可以称为“待补齐／补齐完成”状态。
bit4 的 root资格、bit3 的待补齐状态、Select初始化的运行时flags仍须区分；
不能把 `0x14` 直接命名为“可播放”，也不能推广解释所有 `raw[6]` 组合。

证据：`analysis/repair-original-field-probes-0027.json`、
`analysis/repair-firmware-0027/001b9340.c` 与 `00392a38.c`。

## MP4 属性及内嵌 NRT 的来源

`mpr::GetRecordInfo` (`0xde778`) 先调用
`GetRecordInfoFromMp4` (`0xde3d8`)，再以 **main MP4路径**调用
`GetRecordInfoFromNrtMeta` (`0xde530`)，不是把 sidecar路径传给后者。

NRT路径进一步调用原 `0x241af0` 打开、`0x242354` 确定长度、
`0x241dac` 读取。它们从 MP4 的 `meta / hdlr(nrtm) / xml ` 查找内嵌XML。
本轮新增 `tools/emulate_nrt_extract.py` 对 C0007、C6512、C6515、C6517、C6518
执行这些原函数：均只打开 main MP4，返回值成功，提取字节与独立 BMFF解析一致，
全部可执行section保持原样。

额外合成测试放置冲突 sidecar、改变内嵌XML、替换为错误handler：
sidecar未被访问，内嵌改动被读出，错误handler被原函数拒绝。
这些验证的是该函数链，不是全相机所有代码路径的 sidecar优先级规则。
未执行完整 repair，也未把这个box scanner当作完整NRT语义解析器。

属性对应关系来自 `GetRecordInfo`：

- SDK `MoviePropertyInfo+0xc` 的7个u32 → `recordInfo+0x28..0x40`。
- SDK `+0x2c` 的u16 → `recordInfo+0x44` 的标称码率字段。
- XML/NRT中的日期、LTC、acquisition、UMID等走另一组字段。
- 该函数明确把创建时间毫秒清零；不应预期 sidb能保留所有原始时间精度。

7份修复前已保存的原厂SDK读出报告，经修复后媒体SHA-256绑定，再与新的原始
record converter输出比较：C6511–15、C6517、C6518 的7个视频枚举和码率全部相等。
它们不是仅根据尺寸猜出来的主机映射。

### 相机生成的三个完整属性组合

以下是40-byte payload中的相对偏移，不含binary record前10字节或checksum。

| 片段 | 支持记录 | 标称码率 | SDK7枚举 | acquisition3枚举 |
|---|---|---|---|---|
| C6512/13/14/15 | 81，旧native记录复用 | 25 | `0,0,2,1,0,0,7` | `53,49,2` |
| C6517 | 113，新建 | 50 | `0,0,2,1,0,0,7` | `53,49,2` |
| C6518 | 115，新建 | 60 | `0,0,3,1,0,0,3` | `53,49,2` |
| C0004/5/7、C6511 | 110，新建 | 50 | `0,0,2,1,0,0,7` | `65535,65535,65535` |

相对record81的原始payload差异：

- record113：`payload+2`，`19 → 32`（十六进制，对应25→50）。
- record115：`payload+2`，`19 → 3c`；`+12`，`03 → 04`；`+16`，`09 → 05`。
- record110：`payload+2`，`19 → 32`；`+17..19`，`353103 → 000000`。

三个payload：

```text
HD25 Rec709 05001900000000000000020203030202093531030000000000000000000002020203000000000000
HD50 Rec709 05003200000000000000020203030202093531030000000000000000000002020203000000000000
UHD60 Rec709 05003c00000000000000020204030202053531030000000000000000000002020203000000000000
```

这里得到的是这几个明确profile的相机生成样本，不是所有帧率／格式的通用编码表。
GOP大类枚举同为0不能证明closed/open-GOP等价，也不等于原始SPS/PPS或硬件准入。
C6512/13 与 C6514/15 复用同一支持记录，再次说明这些粗粒度属性不能鉴别
3-byte／4-byte封装差异。全部51条视频的首尾LTC与其XML一致。

## UMID：两套表示不能强行假设相等

`0x292954` 的mask helper 将共享32字节UMID的13..23清零，单独保存13..15和23。
`sidb::RestorateUMID` (`0x28e698`) 恢复时无条件以创建时间重算16..22，
没有基于 `0D23` UUID label跳过这一步的分支。

独立模型与原始 converter 的 **实际main UMID偏移 `recordInfo+0x4f8`**
在修复后全部51条视频中逐字节相同：

- 6条恢复结果与XML精确相等。
- 40条（含上述6条）可由创建时间同一秒内的毫秒枚举解释。
- 11条在该秒的全部1000个毫秒取值中都不匹配：
  C0001/C0004/C0005/C0007、C6511–15、C6517/C6518。
- 51条的非时间部分都匹配；不是任意字节损坏。

例如 C6515：

```text
XML       060A2B340101010501010D2313000000F14F9DB87D6D406E90E6BF52328E49D8
sidb恢复  060A2B340101010501010D2313000000961784665613066E90E6BF52328E49D8
```

这11条采用EDIUS式UUID材料标识，不能把任意UUID字节当作相机时间计数器。
不应为制造表面相等而伪造UUID、覆盖XML或更改已成功的MP4。
原始MEDIAPRO解析器仍读出原XML中的标识，并对51条全部查找／查询成功；
存在两套不同表示是直接证据，二者在实际播放流程中怎样关联还需进一步追踪。
**没有修复后回放反馈，不能声称这种差异已经被实机容忍或必然导致失败。**

本轮同时修正旧仿真工具的诊断偏移：旧报告曾取 `+0x538` 而不是main UMID的
`+0x4f8`，因此旧“main_umid”字段不是有效的该项证据。
已补独立恢复对照和非零／归零回归；历史报告不追改，生成器与媒体字节未因此改变。

## 照片与数组引用计数

不能只数视频owner来校验共享array：

| record | subtype / entry长度 | bitmap | 存储refcount = 全内容owner数 |
|---|---|---|---|
| 63 | 2 / 32 | 1 | 1 |
| 69 | 2 / 32 | 1 | 1 |
| 72 | 2 / 32 | F | 23 |
| 101 | 3 / 16 | FF | 15 |
| 104 | 2 / 32 | F | 31 |
| 111 | 2 / 32 | F | 4 |
| 112 | 2 / 32 | F | 4 |
| 114 | 2 / 32 | 3 | 2 |

全部匹配，且所有owner都指向occupied slot。record101的15个照片引用只有8种
ImageUniqueID；去重和refcount是不同的数量。
23条照片原converter前后全部顶层成功；修复前23条、修复后8条的可选
subtype3 reference=0 引发嵌套返回 `0x406`，但被converter作为缺省字段处理。
所有非零引用均成功，报告明确保留这些可选零引用状态，未声称所有嵌套调用零返回。

## 数组哈希句柄的不对称：已证部分与未证部分

原函数静态与动态证据：

| 函数 | ELF VMA | 句柄处理 |
|---|---|---|
| `sidb::Load` | `0x2992c8`，size `0xb24` | 数组循环在`0x299d2c..0x299d38`传plain record index给regist |
| `CreateArrayBinaryRecord` | `0x29267c` | 新登记使用 `record << 15 \| slot` |
| `sidbhash::regist` | `0x28a6a4` | 原样存入传入的uint |
| `SearchArrayBinaryRecord` | `0x28e3c0` | 以`handle >> 15`和`handle & 0x7fff`恢复record/slot |

独立 `.dynsym st_value/st_size` 限定范围的Capstone导出位于
`analysis/repair-firmware-0027/array-hash-elf-symbols.capstone.json`；
包括Load完整`0x2992c8..0x299dec`，避免现有Ghidra函数body漏掉尾部代码的误导。

在受控、预分配单候选cache和GOT模型下，对修复前5个、修复后28个 occupied slots：

- 执行原Load参数片段、原hash、原regist、原search。
- plain index原样保存，搜索失败；packed句柄搜索成功并返回正确record/slot。
- 132项附加控制覆盖错误subtype、错误payload、record bitmap清除、slot bitmap清除。
  前三种拒绝；**仅清slot bitmap仍能命中**，如实记录为搜索对缓存候选的行为，
  不是宣称正常数据库可跳过slot bitmap维护。
- 7个检查点核对4个原可执行section，均未变化；guest DB及临时GOT也被恢复。

实际库中多个shared masked payload重复，含旧63/69/72与新104，已按字节分组。
这些现象与“不完全跨load去重”的解释相符，但完整Load/修复调用时序和现场cache
没有捕获。**不能据此宣称已证明相机固件bug影响播放，更不能用它解释C6507/09。**

## 头部时间并非凭空出现

修复后 `header+0x8010=0x667ec72fbdc00` 对应
`2026-12-14T11:59:55+03:00`。精确来源可定位到 C6353 / record53：

- 该片段修复前XML已经包含这个 `CreationDate`，XML本身没有变化。
- 修复后内容记录的日期与之相同，原固件header打包函数给出完全相等的64位值。
- 全部74个内容记录中，它是唯一匹配及 masked最大创建日期。
- 修复前record53是 `11:59:59+00:00`，不是简单复制旧record字段。
- 另一个header字段`+0x8018`仍为`2026-11-13T13:54:48.768+08:00`。

ProvisionalRepairM4/Dcf已有记录路径、`_Load`及`SetHeaderParam(3)`提供静态传递链。
这里比较mask `0x7ffffffffff`不是UTC排序，也不是所有分支都采用同样比较；
丢掉了timezone和部分year位。`ReCreate`等其他分支另有无mask比较，不能合并解释。
当前观察没有现场调用跟踪，不能确定实际经过哪条分支或为何历史文件设为未来日期。
照片EXIF没有独立重读；照片排除只基于全部数据库照片记录，不冒充EXIF核验。
完整证据和148次原record转换见 `analysis/repair-header-time-0027.md/.json`。

## 对下一次写入的影响

修复前C0007是本轮成功路线使用的稀疏模板；修复后它的flag、UMID、LTC和属性
都被补齐，record28也不再由视频引用。

`tools/analyze_sd_repair.py` 在内存中用未占用的C9999作同参数对照：
修复前接受，修复后明确报
`Template is not the supported observed-minimal representation`。
没有创建卡文件或新的本地stage目录。这是模板准入拒绝，不是新卡损坏。

今后需显式解决stager：

1. 首先实机检查修复后的既有成功／失败对照，确认补齐字段是否改变行为。
2. 若保留最小写入方式，应把历史稀疏描述作为独立、哈希固定的模板输入，
   从**新卡快照**分配新记录和计数，不能把整份旧DB写回覆盖修复结果。
3. 或实现三个已观察profile的完整native-style writer，并用原writer/reader、
   引用计数、UMID语义及反例逐项交叉验证。属性映射进展不等于该writer已可部署。
4. 任何路线仍须fresh snapshot、stage、verify、readback和真机测试。

本轮没有实现或部署上述两种新写入路线。既有复现手册已标明修复后的前置限制。
也没有再调用EDIUS writer；此次新结论来自修复差异、固件原函数和已有hash-bound输出，
不虚称覆盖了EDIUS的全部编录逻辑。

## 复跑与测试

以下均在工作区本地运行，不写卡：

```powershell
& 'E:\anaconda3\envs\test311\python.exe' tools/compare_sd_snapshots.py backup/snap_20261113T135135 backup/snap_20261113T135646 --output analysis/snapshot-repair-0027.json
& 'E:\anaconda3\envs\test311\python.exe' tools/emulate_sd_repair_fields.py --snapshot backup/snap_20261113T135135 --snapshot backup/snap_20261113T135646 --output analysis/repair-original-field-probes-0027.json
& 'E:\anaconda3\envs\test311\python.exe' tools/emulate_nrt_extract.py output/profiles-0026-deploy/C6518/C6518.MP4 --output analysis/repair-embedded-nrt-C6518-0027.json
& 'E:\anaconda3\envs\test311\python.exe' tools/investigate_repair_time.py --output analysis/repair-header-time-0027.json
& 'E:\anaconda3\envs\test311\python.exe' -m unittest discover -s tools/tests -v
```

综合报告可复跑命令：

```powershell
& 'E:\anaconda3\envs\test311\python.exe' tools/analyze_sd_repair.py --before backup/snap_20261113T135135 --after backup/snap_20261113T135646 --converter analysis/repair-original-converter-0027.json --manifest output/profiles-0026-hd50/package/build-manifest.json --sdk-report analysis/xavc-reader-C6511-ionly-0025.json --sdk-report analysis/xavc-reader-C6512-ionly-0025.json --sdk-report analysis/xavc-reader-C6513-ionly-0025.json --sdk-report analysis/xavc-reader-C6514-ionly-0025.json --sdk-report analysis/xavc-reader-C6515-ionly-0025.json --sdk-report output/profiles-0026-hd50/package/firmware-reader.json --sdk-report output/profiles-0026-uhd60/package/firmware-reader.json --media-hashes analysis/repair-media-hashes-0027.json --nrt-report analysis/repair-embedded-nrt-C0007-0027.json --nrt-report analysis/repair-embedded-nrt-C6512-0027.json --nrt-report analysis/repair-embedded-nrt-C6515-0027.json --nrt-report analysis/repair-embedded-nrt-C6517-0027.json --nrt-report analysis/repair-embedded-nrt-C6518-0027.json --output analysis/repair-comprehensive-0027.json
```

新增focused tests覆盖：变化范围、照片／视频引用布局、高位reference、完整owner计数、
converter报告哈希绑定、修复后模板拒绝、原代码完整性、数组查找控制、原NRT扫描、
日期打包、哈希时文件漂移和路径别名去重。修正哈希工具按原路径字符串去重的缺口：
现在按resolve后的Path去重，Windows大小写及`./`别名都会拒绝。
交叉匹配报告保留发现时原工具哈希及两项预期失败的历史记录；
修复后这两项已成为普通通过测试，本次141个真实清单路径本来就没有别名冲突。

完整回归：`python -m unittest discover -s tools/tests -v`，
**221 tests passed / 231.069秒**，没有skip、expected failure或failure。
最终补充NRT与媒体哈希绑定反例后，综合分析focused tests再次6项全通过／3.715秒，
8组综合检查全部通过，本文2个PowerShell代码块AST解析零错误。
`git diff --check`只报告用户既有`AGENTS.md:1`尾空白，未清理无关改动。
机器摘要为`analysis/repair-verification-summary-0027.json`。
