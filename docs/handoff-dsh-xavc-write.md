# DSH → XAVC_Write handoff (corrected, v2)

Written 2026-11-12, revised same day after the main agent corrected a major factual
error in v1. Read-only: I inspected existing workspace files and ran read-only
string/symbol/binary scans on `libmpr.so` and on the `F:` card clips. I did not
modify the project, run firmware, or write to any card. The `libmpr` Ghidra project
is untouched. No original camera clip is proposed for modification anywhere below.

## 0. Correction notice — what v1 got wrong

v1 of this document (`docs/handoff-dsh-xavc-write.md`) claimed **HD 59.94p requires
`@L52`** and listed `@L42` → `@L52`, `avcC` `0x2A` → `0x33`/`0x34`, and the
`ver.2.00` namespace as blockers. **That was inverted and wrong.** I misread the
GBK-encoded `docs/patching-recipe.md` step 4 through a mojibake transcript. The
actual bytes there decode to:

> HD 59.94p **必须是** `@L42`。若为 `@L52` **需更正**。

i.e. "HD 59.94p **must be** `@L42`; if it is `@L52` it needs correcting" — the
reverse of what v1 said. Measured on the card, all three relevant clips agree:

| Clip | role | `avcC` `level_idc` | `VPRF+16` | `+20` | `+24` | `+28` | `+32` | `+36` |
|---|---|---|---|---|---|---|---|---|
| `C6359.MP4` | **camera-native**, HD 59.94p 50M | `0x2a` | `0x0164002A` | `0x00030002` | 50000 | 50000 | 3928230 | 3928230 |
| `C0007.MP4` | **user-verified working**, EDIUS HD 59.94p 50M | `0x2a` | `0x003BF0A6` | `0x003BF0A6` | 50000 | 50000 | 3928230 | 3928230 |
| `C0008.MP4` | new 25 Mbps candidate | `0x2a` | `0x0164002A` | `0x00030002` | **25000** | **25000** | 3928230 | 3928230 |

So `level_idc = 0x2A` (L4.2) is correct for HD 59.94p, `VPRF+16/+20` in the new
candidate already matches the camera-native clip, and `+32/+36 = 3928230` is identical
in all three. **The only measured difference from both proven-playable clips is
`VPRF+24/+28` = 25000 vs 50000.** That is the real open variable, and it is a
bitrate declaration, not a level.

Also corrected: `C6359M01.XML` (camera) and `C0007M01.XML` (working EDIUS) both use
`halfStep="true"`, `tcFps="30"`, `videoCodec="AVC_1920_1080_HP@L42"`,
`VideoRecPort port="OTHERS"`, `TypicalUbit`, `KeyFrame`, namespace `ver.2.00`, and
UMID prefix `...010D23...`. The new candidate matches all of those. v1's list of XML
"discrepancies" (namespace `ver.2.00`→`ver.2.20`, `OTHERS`→`DIRECT`, `halfStep`,
UMID `0D23`→`0D43`) was wrong on every row — those are camera-only cosmetic
differences that the *working* EDIUS clip does not have either.

`docs/patching-recipe.md` also does not authorise editing a camera original. Its proven
case is `C0006`, an EDIUS output, and its step 4 fix is one line of XML. Nothing in it
requires touching `C6359`.

---

## 1. Existing material and where it is

| Path | What it is |
|---|---|
| `firmware/m4-v602/usr.ext2` | 378,580,992 B, M4 6.02 `/usr` partition image |
| `firmware/m4-v602/usr/` | 997 regular files: `bin codec kmod lib sabin sbin scenario share tool wifi-scripts wlan` |
| `firmware/m4-v602/{inventory,extracted-manifest,copy-manifest}.json` | member inventory + provenance |
| `firmware/tools/fwtool/` | fwtool (ext2/FAT readers) |
| `analysis/ghidra/mpr.{gpr,rep}` | Ghidra project holding **`libmpr.so`**, imported and analyzed |
| `analysis/libmpr-elf.json` | 3,112 symbols with address+size+demangled, 25 sections, 5 segments |
| `analysis/decompile-mpr/*.c` | ~90 decompiled `libmpr` functions, named `<ghidra_addr>_<symbol>.c` |
| `analysis/sd-db.json` | sidb checksum verification of the snapshot `DATABASE.BIN` (all `valid: true`) |
| `analysis/avc-*.json`, `avc-*.log` | per-candidate AVC/MP4 structure dumps |
| `backup/snap_20261112T144251/` | read-only card snapshot, `PRIVATE` tree + `MEDIAPRO.XML` |
| `output/cat-25m/` | the 25 Mbps candidate: `C0008.MP4`, `C0008M01.XML`, `C0008T01.JPG`, `catalog/{DATABASE.BIN,MEDIAPRO.XML,transaction.json}` |
| `tools/` | `sony_mp4.py`, `sony_db.py`, `avc_sony.py`, `xavc_rebuild.c`, `sps_patch.c`, `deblock_inject.c`, `jpeg422.c`, `FocusXavc.java`, `run_ghidra.py`, `elf_survey.py`, `card_snapshot.py` |

---

## 2. ELF VMA vs Ghidra VMA — read this before quoting any address

`libmpr.so` is `ET_DYN` / `EM_AARCH64`, and **segment 0 has `p_vaddr = 0`**
(`p_offset 0`, `p_filesz 3055172`, `p_flags 5`). Segment 1 starts at `p_vaddr 3122248`.

`analysis/libmpr-elf.json` records **ELF VMAs**. Ghidra loads this object with a
**+0x100000** image base, so:

```
Ghidra address = ELF VMA + 0x100000
```

Confirmed by the decompiler output naming: `analysis/decompile-mpr/001ca73c_GetProfileLevel.c`
is Ghidra `0x1ca73c`, and `libmpr-elf.json` records `mpr::GetProfileLevel` at
`0xca73c`. The same +0x100000 shift applies to every address in section 3 below,
which is why they are printed in both columns.

---

## 3. Which ELF libraries to inspect, and which functions

Ranked by what your three questions need. String hits are measured.

| Rank | Library | Bytes | Measured string hits |
|---|---|---|---|
| **1** | `lib/libmpr.so` | 3,549,952 | `VPRF` 2, `PROF` 3, `MEDIAPRO` 2, `DATABASE.BIN` 2, `XAVC` 19, `avc1` 1, `VideoProfile` 2 |
| **2** | `lib/libInfraAvbbc.so` | 1,738,760 | — (the codec bridge `mpr::Codec` talks to) |
| **3** | `lib/appFw.so` | 98,212,632 | — (the app; use a tight `FocusXavc` pattern) |
| **4** | `lib/libObj.so` | 2,884,880 | — (object/param layer) |
| **5** | `lib/libSysDef.so` | 6,041,280 | — (system definition tables) |
| **6** | `lib/libIMDB.so` | 75,632 | — (media database candidate behind sidb) |
| **7** | `codec/vcd_firmware{,_imola2,_imola2_fpga}.bin` | 5.4 / 10.9 / 8.8 MB | — (not ELF; needs its own loader) |
| **8** | `lib/gstplugin/libgstaxcmux.so` | 235,216 | — (independent XAVC muxer) |
| **9** | `lib/libsencore.so` | 381,424 | `PROF` 8 |
| **9** | `lib/libInfraAdjMedia.so` | 322,280 | `PROF` 4, `4.2` 1 |
| — | `libInfraMedia{Common,Config,Detect,Mount}.so`, `libInfraMetaSupplier.so` | 402,656 / 52,344 / 98,240 / 65,392 / 23,048 | nothing |

**No other library in the 293-`.so` tree contains `VPRF`, `PROF`, `MEDIAPRO` or
`DATABASE.BIN`.** `libmpr.so` is the only one that carries the MP4 fourcc, the SD
catalog paths, and the sidb record code together.

---

## 4. `libmpr.so` — functions worth decompiling

`elf` is the value in `analysis/libmpr-elf.json`; `ghidra` is what the project and the
decompiler filenames use.

### AVC sample-entry classification and profile/level

| elf | ghidra | size | symbol |
|---|---|---|---|
| `0x2256fc` | `0x3256fc` | 9,116 | `FUN_003256fc` — **the `avc1` sample-entry classifier** |
| `0x0ca73c` | `0x1ca73c` | 804 | `mpr::GetProfileLevel(libXavcMp4::CodecSpecifcInfo)` |

`FUN_003256fc` is the concrete evidence you cited, and it reads exactly as you said:

- `*(int*)(param_2 + 0xc) != 0x61766331` — `0x61766331` is the fourcc **`avc1`**, so
  this is the AVC sample-entry branch (the `0x68766331` sibling is `hvc1`).
- `*(short*)(param_2 + 0x2a)` is the **width**: `0x780` = 1920, `0xf00` = 3840, `0x1e00` = 7680.
- For width `0x780` (1920) it requires `*(int*)(param_2 + 0x14) == 9000`, then tests
  `*(int*)(param_2 + 0x24)` against `0x320000` and `0x3bf0a6`; when the field is
  neither, it takes the `0x278` branch, otherwise `0x27b`.
- `0x3bf0a6` is therefore the field value the classifier special-cases for AVC 1920 —
  and `3928230 == 0x3BF0A6` is exactly what all three clips carry at `VPRF+32/+36`,
  and what `C6359`/`C0007`/`C0008` carry there identically.

`GetProfileLevel` maps a picture-quality code to `(quality, level)` pairs, e.g.
`0x2196`→level `0x22`, `0x2278`→`0x2c`, `0x2299`→`0x32`, `0x24b7`→`0x3b`.
The `0x2a` you measured is in this family, so L4.2 is the code this table expects for
AVC 1920.

### Playback admission (decoder / player side)

| elf | ghidra | size | symbol |
|---|---|---|---|
| `0x0fe968` | `0x1fe968` | 256 | `mpr::MoviePlayer::Init(InitInParam const&, InitOutParam*)` |
| `0x101d40` | `0x201d40` | 304 | `mpr::MoviePlayer::PbStart(PbStartInParam const&)` |
| `0x104570` | `0x204570` | 508 | `mpr::MoviePlayer::ProcInPlayDecVideoPiStart(PayloadCodec*)` |
| `0x10476c` | `0x20476c` | 300 | `mpr::MoviePlayer::RecvCallbackDecVideoPiStart(PayloadCodec*)` |
| `0x0fec08` | `0x1fec08` | 156 | `mpr::MoviePlayer::RecvCallbackDecodeError(PayloadCodec*)` |
| `0x101014` | `0x201014` | 852 | `mpr::MoviePlayer::RecvCallbackDecChangeSpeedComplete(PayloadCodec*)` |
| `0x1025ec` | `0x2025ec` | 672 | `mpr::MoviePlayer::ProcInPlayChangePbSpeed(...)` |
| `0x104aec` | `0x204aec` | 216 | `mpr::MoviePlayer::ConvertFrameCountTo90kHz(uint, DefStruct::FrameRate)` |
| `0x102f00` | `0x202f00` | 164 | `mpr::MoviePlayer::SetDecCloseParam(AvbbcApi_DecClose*, bool)` |

Public thunks: `MprIf::PlayMovie` at `elf 0x2ce564` / `0x2ce56c`,
`MprIf::ResumePlayMovie` `0x2ce57c`, `MprIf::CancelPlayMovie` `0x2ce574`.

Codec bridge, `mpr::Codec` (216 symbols): `SendMsgToAvbbc_wo_wait(PayloadMpr*)`,
`DecChangeSpeed(AvbbcApi_DecChgSpeed, CodecType, FileFormat, PayloadCodec*)`,
`SetCbFuncForPlayMovie(...)` @ `elf 0x281104`, and
`mpr::ConvertVideoCodecToCodec(DefStruct::VideoCodec, DefStruct::GopStructure)`.
`libInfraAvbbc.so` is the far side of these messages.

### MP4 / NRT / signature

| symbol | note |
|---|---|
| `mpr::ParseNrtFileFromMp4(char const*, NrtMetaWrapper*)` | NRT XML sidecar parse |
| `XavcsMovieReader::MakeInfoList(libXavcMp4::MoviePresentationInfo*, VideoSampleInfo*, AudioSampleInfo*, MetadataSampleInfo*, mpr::BaseList*, TransferParams*)` | builds sample lists |
| `XavcsMovieReader::_make_outband_param_info(...)` | out-of-band params — where a `VPRF`/`PROF` reader would live |
| `mpr::GetMetadata`, `mpr::GetEssenceMarks` | metadata / essence marks |
| `libMp4Signature::GetSignatureInfo(...)`, `GetChunkHashesTargetData(...)` | MP4 chunk-hash verification |
| `libXavcMp4` namespace | `MoviePresentationInfo`, `CodecSpecifcInfo`, `RecRealTimeMetaDataSampleInfo`, `Rotate`, `MatrixInfo` |

### sidb (SD catalog)

| elf | ghidra | size | symbol |
|---|---|---|---|
| `0x1992c8` | `0x2992c8` | 2,852 | `sidb::Load(uint, char, string, string, bool, bool)` |
| `0x18b45c` | `0x28b45c` | 140 | `sidb::CalcChecksum(uchar const*, uint)` |
| `0x18d238` | `0x28d238` | 156 | `sidb::ConvVideoParamToStreamProfile(sidb::VideoParam&)` |
| `0x18d710` | `0x28d710` | 532 | `sidb::ConvVideoParamToVPC(sidb::VideoParam&)` |
| `0x18d924` | `0x28d924` | 544 | `sidb::ConvVideoParamToQualityLevel(sidb::VideoParam&)` |
| `0x292410` | `0x392410` | 3,530 | `sidb::CreateBinaryRecord(...)` |
| `0x29267c` | `0x39267c` | 3,707 | `sidb::CreateArrayBinaryRecord(...)` |
| `0x292a38` | `0x392a38` | 32,618 | `sidb::ConvRecordInfo2RecordStructure(...)` |

`sidb::ConvVideoParamTo{StreamProfile,VPC,QualityLevel}` is the **`videoType` string
builder** — decompile these to learn which `videoType` values the camera emits for a given
`VideoParam`, rather than inferring the string format from one clip.
`mpr::IntegPlayGetRecordInfoFromMp4` / `mpr::GetRecordInfo(uint, sidb::recordInfo&)`
are the MP4↔sidb bridges.

---

## 5. Recording-media transfer-rate checks are **not** playback admission

This is a correction to v1, which called `RateCheck` "the playback bitrate gate". It is not.

`RateCheck::getMediaTransferRateCheckType_*` names **MediaTransferRate** — that is the
**recording-media transfer-rate** check: whether the target media can sustain the *write*
rate for a chosen recording format. Its siblings enumerate the recording formats
(`Normal|SnQ` × `AVC|HEVC` × `Intra|Long` × `FHD|4K|8K`), which is a recording-side
matrix, not a playback decision. Treat `RateCheck` as evidence about **whether the camera
will write** a 25 Mbps clip, not about whether it will play one back.

Playback admission evidence is in the other group: the `avc1` sample-entry classifier
`FUN_003256fc`, `mpr::GetProfileLevel`, `mpr::ConvertVideoCodecToCodec`, and the
`MoviePlayer` init/`PbStart` path. Keep the two groups separate when reading the
decompiler output — v1 conflated them.

| elf | ghidra | size | symbol (recording-media side) |
|---|---|---|---|
| `0x0051d8` | `0x1051d8` | 136 | `RateCheck::getMediaTransferRateCheckType_Normal_AVC_Long_4K` |
| `0x005260` | `0x105260` | 136 | `RateCheck::getMediaTransferRateCheckType_Normal_AVC_Long_FHD` |
| `0x005480` | `0x105480` | 136 | `RateCheck::getMediaTransferRateCheckType_Normal_AVC_Intra_FHD` |
| `0x0053f8` | `0x1053f8` | 136 | `RateCheck::getMediaTransferRateCheckType_Normal_AVC_Intra_4K` |
| `0x0055e8` | `0x1055e8` | 160 | `RateCheck::getMediaTransferRateCheckType_SnQ_AVC_Long_4K` |
| `0x005688` | `0x105688` | 276 | `RateCheck::getMediaTransferRateCheckType_SnQ_AVC_Long_FHD` |
| `0x00579c` | `0x10579c` | 160 | `RateCheck::getMediaTransferRateCheckType_SnQ_AVC_Intra_4K` |
| `0x00583c` | `0x10583c` | 160 | `RateCheck::getMediaTransferRateCheckType_SnQ_AVC_Intra_FHD` |
| `0x005508` | `0x105508` | 224 | `RateCheck::getMediaTransferRateCheckType_Normal(mpr::movieRecParam)` |
| `0x00597c` | `0x10597c` | 200 | `RateCheck::getMediaTransferRateCheckType_SnQ(mpr::movieRecParam)` |
| `0x005a64` | `0x105a64` | 604 | `RateCheck::GetMediaTransferRateInh(char, mpr::movieRecParam, bool&, mpr::InhBit&)` |

The `HEVC_Long_4K`/`HEVC_Long_8K` siblings sit in the same block, which is
consistent with a recording-format matrix.

---

## 6. On-disk layout (measured on the card, read-only)

### `avcC` and `VPRF`

`avcC` content begins `01 64 00 2A`: configurationVersion 1, `AVCProfileIndication 0x64`
(High), `profile_compatibility 0x00`, `AVCLevelIndication 0x2A` (**L4.2**) — in **all three**
clips. `ftyp` is `ftypXAVC`.

`VPRF` field offsets are relative to the `VPRF` fourcc, per `docs/patching-recipe.md`:
`field3 = vprf+24..27`, `field4 = vprf+28..31`, `field5 = vprf+32..35`,
`field6 = vprf+36..39`. That recipe records a trap: the naive `vprf+16` +
`$d+12..$d+15` offset is wrong and silently skips `field3`.

Measured, all three clips:

| Field | `C6359` camera | `C0007` working | `C0008` candidate | Meaning |
|---|---|---|---|---|
| `+16` | `0x0164002A` | `0x003BF0A6` | `0x0164002A` | profile/compat/level word (camera) |
| `+20` | `0x00030002` | `0x003BF0A6` | `0x00030002` | — |
| `+24` | 50000 | 50000 | **25000** | average bitrate |
| `+28` | 50000 | 50000 | **25000** | max bitrate |
| `+32` | 3928230 | 3928230 | 3928230 | `0x003BF0A6` |
| `+36` | 3928230 | 3928230 | 3928230 | `0x003BF0A6` |

**`+24/+28` is the only field where the candidate differs from both proven-playable
clips.** `+16/+20` matches the camera exactly. `+32/+36` is identical everywhere.
`docs/patching-recipe.md`'s `field5/field6` decimal (`3924134`) is a typo — its own hex
`0x003BF0A6` is 3928230, and every clip carries 3928230. Do not "fix" it to 3924134.

### `MEDIAPRO.XML` and CLIP XML

`C6359M01.XML` (camera-native, HD 59.94p) and `C0007M01.XML` (working EDIUS) are
structurally identical:

```xml
<NonRealTimeMeta xmlns="urn:schemas-professionalDisc:nonRealTimeMeta:ver.2.00" ...>
  <TargetMaterial umidRef="060A2B340101010501010D23..."/>
  <LtcChangeTable tcFps="30" halfStep="true"> ... </LtcChangeTable>
  <TypicalUbit value="0000000000000000"/>
  <KeyFrame frameCount="0"/>
  <VideoFormat>
    <VideoRecPort port="OTHERS"/>
    <VideoFrame videoCodec="AVC_1920_1080_HP@L42" captureFps="59.94p" formatFps="59.94p"/>
    <VideoLayout pixel="1920" numOfVerticalLine="1080" aspectRatio="16:9"/>
  </VideoFormat>
  <AudioFormat numOfChannel="2">
    <AudioRecPort port="OTHERS" audioCodec="LPCM16" trackDst="CH1"/>
    <AudioRecPort port="OTHERS" audioCodec="LPCM16" trackDst="CH2"/>
  </AudioFormat>
</NonRealTimeMeta>
```

`C0008M01.XML` matches that on every field. The only differences from the working
`C0007` are cosmetic: `xmlns:lib` is not declared, `standalone="no"` is absent, and
whitespace differs. `ver.2.00`, `port="OTHERS"`, `halfStep="true"`, `tcFps="30"`, the
`0D23` UMID prefix, `@L42` and `1920×1080` are all what the working clip uses.

`MEDIAPRO.XML` (camera, `version="2.30"`, `.../mediaprofile`):

```xml
<Properties>
  <System systemId="9C50D1FFFEC4F949" systemKind="ILCE-7M4" masterVersion="XAVC-M4@2.00.00"/>
  <Attached mediaId="00000000957296D4F9499C50D1FFFEC4" mediaKind="AffordableMemoryCard" mediaName=""/>
</Properties>
<Contents>
  <Material uri="./CLIP/C5850.MP4" type="MP4" videoType="AVC140_3840_2160_H422P@L51"
            audioType="LPCM16" fps="29.97p" dur="75" ch="2" aspectRatio="16:9"
            offset="0" umid="060A2B340101010501010D431300000052868E8E121206C59C50D1FFFEC4F949"
            status="none">
    <RelevantInfo uri="./CLIP/C5850M01.XML" type="XML"/>
    <RelevantInfo uri="./THMBNL/C5850T01.JPG" type="JPG"/>
  </Material>
```

**UMID** (measured across 30 camera entries): `060A2B340101010501010D43` + `13` +
`000000` + 16 hex + 8 hex + 8 hex `systemId`. The last 8 bytes are always
`9C50D1FFFEC4F949` (the `<System systemId>`), and the middle 8 are `1206` + a per-clip
counter. Note the camera uses `0D43` while EDIUS `C0007` and the new `C0008` both use
`0D23` — so `0D23` is the EDIUS convention and is accepted.

`C0008`'s `MEDIAPRO.XML` entry reads
`videoType="AVC_1920_1080_HP@L42" fps="59.94p" dur="1534"`, which matches the working
`C0007`'s `videoType` for the same format. Its trailing padding is a run of `0x20`,
which `docs/patching-recipe.md` note 4 requires.

---

## 7. sidb / `DATABASE.BIN`

`tools/sony_db.py` implements the recovered layout and `analysis/sd-db.json` shows every
checksum in the snapshot is valid:

- Region checksums: `(0x0000,0x3FFC)→0x3FFC`, `(0x7C40,0x03BC)→0x7FFC`,
  `(0x8000,0x3FFC)→0xBFFC`, `(0xC000,0x3FFC)→0xFFFC`, plus 15 ×
  `(0x4000+i*0x400, 0x400)→0x7C00+i*4`.
- Algorithm: pad to 8 bytes, little-endian `uint64` sum, mod `0xFFFFFFFB`.
- Record: `stride` at `0x30`, `capacity` at `0x44`, presence bitmap at `0x4000`,
  records at `0x10000 + index*160`. Record checksum = same sum over `record[:158]`
  mod `0xFFF1`, stored as `uint16` at `+158`.
- Decoded record fields: `type = record[0] & 15`, `content_type = record[7] & 15`,
  `clip_number = u16@14 >> 2`, `path_refs = 4×u16@0x50`,
  `video_info_ref = u16@0x58 | ((record[0x5C]>>4&1)<<16)`.

`output/cat-25m/catalog/transaction.json` records the rebuild: records 67/68/69 added,
64 unchanged, `database_changed_bytes: 93`, header and record checksums valid. It also
records the real open item: `"umid_limit": "sidb compressed UMID middle-instance
reconstruction not yet validated"`. The current `DATABASE.BIN` is 9,670,656 B; do not
hard-code `0xFE024` record offsets, read `stride`/`capacity` from the header.

---

## 8. SD paths (measured strings in `libmpr.so`)

`/PRIVATE/DATABASE/DATABASE.BIN` and `/M4ROOT/MEDIAPRO.XML` appear together at
`elf 0x1d3b5a` / `0x1d3b70`, next to the clip naming templates:

```
/PRIVATE/DATABASE/DATABASE.BIN
/M4ROOT/MEDIAPRO.XML
/DCIM
/M4ROOT
%s%04d.
%s%s
%s/SUB/%sS03.%s
L/%sT01.%s
PbStart / PbStop / PbPause / PbPauseRelease
```

`%s%04d.` is the `C%04d.MP4` template; `%s/SUB/%sS03.%s` is sub-clip naming.

---

## 9. Ghidra setup (already working, do not duplicate)

- Project `analysis/ghidra/mpr` (`mpr.gpr`, `mpr.rep`), `libmpr.so` imported and analyzed.
- Re-run without re-analysis:
  `python tools/run_ghidra.py firmware/m4-v602/usr/lib/libmpr.so --pattern "..." --existing --label mpr`
  passes `-process libmpr.so -noanalysis -readOnly`, so it is safe and fast.
- New binary: drop `--existing`; it imports with `-analysisTimeoutPerFile 180`.
- `tools/FocusXavc.java <outdir> <regex>` — the regex matches function names **and**
  `@<hexaddr>`, and a third argument matches string values and pulls in their referrers.
  That third argument is the shortest path to "who reads `DATABASE.BIN`" or "who reads `VPRF`".
- The `-Djava.system.class.loader=ghidra.GhidraClassLoader` warning in the log is normal.

Suggested patterns (all present in the symbol table):
`GetProfileLevel`, `ConvVideoParamToStreamProfile`, `ConvVideoParamToVPC`,
`ConvVideoParamToQualityLevel`, `_make_outband_param_info`, `ParseNrtFileFromMp4`,
`GetSignatureInfo`, `CreateBinaryRecord`, `CalcChecksum`.
For strings: pass `--strings "VPRF|PROF|MEDIAPRO|DATABASE\.BIN"` to get every referrer.

---

## 10. Proven vs guess

**Proven (measured on the card or in the workspace):**

- `C6359.MP4` is camera-native HD 59.94p 50 Mbps with `avcC level_idc 0x2A`, `VPRF+16 = 0x0164002A`,
  `+24/+28 = 50000`, `+32/+36 = 3928230`; its XML is `@L42`, `halfStep="true"`, `ver.2.00`, `port="OTHERS"`.
- `C0007.MP4` is the user-verified working EDIUS clip with `avcC level_idc 0x2A`,
  `VPRF+16 = 0x003BF0A6`, `+24/+28 = 50000`, `+32/+36 = 3928230`; its XML is `@L42`,
  `halfStep="true"`, `ver.2.00`, `port="OTHERS"`.
- `C0008.MP4` matches those on `avcC`, `VPRF+16/+20`, `+32/+36`; differs only at `+24/+28 = 25000`.
- `docs/patching-recipe.md` step 4 requires `@L42` for HD 59.94p and corrects `@L52`.
- `FUN_003256fc` classifies AVC 1920 using `+0x14 == 9000` and `+0x24` against `0x320000`/`0x3bf0a6`.
- `libmpr.so` holds the `VPRF`/`PROF`/`MEDIAPRO`/`DATABASE.BIN` literals and the symbols above.
- sidb checksums in the snapshot are all valid under the documented algorithm.
- `libmpr.so` segment 0 has `p_vaddr 0`; Ghidra base is +0x100000.

**Guess (plausible, not measured):**

- That `mpr::GetProfileLevel` is where playback admission is decided.
- That `FUN_003256fc`'s branch feeds that decision rather than only metadata.
- That the camera accepts or rejects based on `VPRF+24/+28` at all.
- That `RateCheck` affects playback rather than only recording.
- That `libMp4Signature` chunk hashes gate playback.
- Whether 25 Mbps is admissible where only 50 Mbps is proven.

**Discriminating experiment, without touching any camera original:** copy the
**working EDIUS `C0007`** (not a camera clip) to a scratch name, change only
`VPRF+24/+28` to 25000, and see whether it stops playing. That isolates the
bitrate declaration with no re-encode. Alternatively copy `C0008` and change only
`+24/+28` to 50000. Either way, operate on copies; never on `C6359`.

---

## 11. Do-not-repeat

- Do not claim HD 59.94p needs `@L52`; it needs `@L42`, and `@L52` is what must be corrected.
- Do not suggest editing a camera-original clip (`C6359`, `C5850`, camera `C0000`–`C0005`) as a probe.
- Do not call `RateCheck` a playback admission check; it is a recording-media transfer-rate check.
- Do not quote `libmpr-elf.json` addresses as Ghidra addresses without adding `0x100000`.
- Do not re-extract `usr.ext2` or re-import `libmpr.so`; both are done.
- Do not re-derive the sidb checksum; it is implemented and verified.
- Do not hard-code `0xFE024`; the record table is rebuilt.
- Do not "fix" `VPRF+32/+36` from 3928230 to 3924134; 3928230 is correct.
- Do not write to `F:` or `K:`; the card is read-only by policy.
- Do not trust `docs/handoff-cappremake.md` for media functions; it says it has none.
