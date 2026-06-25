# XAVC directory & recording-file data structure (consolidated)

Synthesized from Experiment 0001 (29 clips across 3 Sony devices: ILCE-7M4,
ILCE-7RM5, FDR-AX700, 11 DB snapshots). Field-level detail lives in
`database_bin-offsets.md`; this document is the architectural overview.

## 1. Card directory tree (XAVC-S relevant parts)

```
K:\
├── PRIVATE\M4ROOT\                 ← XAVC root (XAVC-S AND XAVC HS share this tree)
│   ├── CLIP\        C####.MP4  +  C####M01.XML    (clip + sidecar, per clip)
│   ├── THMBNL\      C####T01.JPG                  (thumbnail, per clip)
│   ├── SUB\         C####S03.MP4  (proxy — only when Proxy Recording is ON)
│   ├── TAKE\                                      (empty — for XAVC-HD takes)
│   ├── GENERAL\LUT\ , GENERAL\SONY\PXTMP\         (LUTs, proxy workspace)
│   ├── MEDIAPRO.XML                               (card-wide clip manifest)
│   └── STATUS.BIN      (7 bytes, e.g. 01 01 00 00 00 00 00 — meaning UNKNOWN/INFERRED;
│                        first captured in `after7`; timestamp suggests it appeared during
│                        the AX700 session but not traceable through the partial backups)
├── PRIVATE\DATABASE\DATABASE.BIN                   (the media database, ~9.7 MB)
├── PRIVATE\AVCHD\, AVF_INFO\, AVF_ESCP\           (AVCHD/legacy — separate tree, untouched by XAVC-S/HS)
└── DCIM\###MSDCF\                                  (stills — separate catalog)
```

Each recorded clip produces **3 files** sharing the `C####` stem:
- `CLIP/C####.MP4` — the media (self-contained; embeds the NRT metadata track)
- `CLIP/C####M01.XML` — ProDisc NonRealTimeMeta sidecar (a copy of the MP4's NRT track)
- `THMBNL/C####T01.JPG` — 1280×720 thumbnail, with SONY/Model/DateTime EXIF

If **Proxy Recording** is ON, a 4th file appears: `SUB/C####S03.MP4` (see §8).

## 2. Clip numbering

- Format `C####` where `####` is a 4-digit decimal. Each device maintains its own
  numbering; observed ranges on one shared card: 7M4 → 5850+, 7RM5 → 6347+,
  AX700 → 1+. The exact rule each device uses to pick the next number (own
  internal counter vs. scan-card-max+1 vs. something else) is **model/firmware-
  specific and not determined by the data** — the AX700 wrote C0001 while the card
  already held C5865, and the 7M4 later wrote C6349 right after the 7RM5's C6348.
  These two facts are consistent with several different rules, so no general claim
  is made beyond "it varies by model."
- The number **is** stored in DATABASE.BIN as `clip_number × 4` at record `+0x0A`.
- Deleted numbers are retired (slots zeroed, never reused by that device).

## 2b. Recording formats — codec strings & coexistence

All three current Sony XAVC families **share the same `M4ROOT` tree and the same
DB record layout** (`02 00 90 02`). Only the codec string differs. The string
format is `<codec>_<W>_<H>_<profile>@<level>`:

| Example codec string | Family | Meaning |
|---|---|---|
| `AVC140_3840_2160_H422P@L51` | XAVC-S | H.264, 4K, **High 4:2:2** Profile, Level 5.1 (`AVC140` flags 4:2:2) |
| `AVC_1920_1080_HP@L51` | XAVC-S HD | H.264, HD, **High Profile (4:2:0)**, L5.1 — also used for HFR (119.88p) |
| `HEVC_3840_2160_M42210P@L51HT` | **XAVC HS** | H.265, 4K, **Main 4:2:2 10-bit**, L5.1 **High Tier** |
| `HEVC_Proxy_1920_1080_M10P@L41MT` | proxy | H.265, HD, Main 10, L4.1 Main Tier |

- `fps` is stored as a string in MEDIAPRO.XML (`29.97p`, `59.94p`, `119.88p`) —
  handles HFR cleanly.
- The DB clip record does **not** appear to store the codec — it's codec-agnostic
  across the AVC/HEVC/HD-HFR clips examined (all share `02 00 90 02`); the codec
  lives only in MEDIAPRO's `videoType` attribute and the sidecar's
  `<VideoFrame videoCodec>`. Caveat: a few DB fields (`+0x70`/`+0x74`, block trailers)
  remain undecoded and could conceivably carry codec-adjacent info.
- AVCHD is the only format that uses a *different* tree (`PRIVATE\AVCHD\` + `AVF_*`).

## 3. The UMID — the join key

Every clip has a 32-byte UMID threading through all artifacts:

```
[0..15]  universal XAVC label  060A2B340101010501010D4313000000   (same for ALL XAVC clips, all devices)
[16..23] instance              <random/time-based, unique per clip>
[24..31] device/system id      <unique per DEVICE, e.g. 9C50D1FFFEC4F949 = ILCE-7M4>
```

- Sidecar `<TargetMaterial umidRef>` ↔ MEDIAPRO `<Material umid>` ↔ MP4 NRT track
  all carry the **full** UMID (instance intact).
- DATABASE.BIN stores the UMID **only in INDEX segment entries** — the CLIP record
  does **not** contain a UMID. Each INDEX entry stores `[prefix 16B] [zeroed-instance 8B]
  [device-suffix 8B]` (32 bytes). (CORRECTION — an earlier field map wrongly attributed
  the UMID to the CLIP record at `+0xA8`; those bytes are in the INDEX slot.)
- The device suffix is **per-device, not per-card** (corrects the earlier "card
  systemId" naming). Three devices → three distinct suffixes on one card.

## 4. MEDIAPRO.XML — the manifest

```xml
<MediaProfile createdAt="..." version="2.30">
  <Properties>
    <System systemId="<owning device suffix>" systemKind="ILCE-7M4"
            masterVersion="XAVC-M4@2.00.00"/>     ← the device that "owns" this DB
    <Attached mediaId="<card id>" mediaKind="AffordableMemoryCard"/>
  </Properties>
  <Contents>
    <Material uri="./CLIP/C####.MP4" type="MP4" videoType="..." audioType="LPCM16"
              fps="29.97p" dur="<frames>" ch="2" aspectRatio="16:9" umid="<full 32B>">
      <RelevantInfo uri="./CLIP/C####M01.XML" type="XML"/>
      <RelevantInfo uri="./THMBNL/C####T01.JPG" type="JPG"/>
    </Material>
    ... one <Material> per clip, ALL devices mixed ...
  </Contents>
</MediaProfile>
```

- Owned by whichever device initialized the card (here ILCE-7M4).
- `<Material>` entries are in **append / recording-event order across all devices**,
  NOT grouped by device: in `after7` the 7M4 clips appear in two disjoint blocks
  (`C5850–C5865`, then `C6349–C6352`) with the 7RM5 (`C6347/48`) and AX700
  (`C0001/02`) clips between them — i.e. in the chronological order each batch was
  written, not collapsed by source device.
- Lists every clip regardless of source device.
- `masterVersion` can be **downgraded** when an older device writes (AX700 → `1.10.00`).

## 5. C####M01.XML — ProDisc NonRealTimeMeta sidecar

Schema version is **device-generation-specific**:
- ILCE-7M4 / ILCE-7RM5: `nonRealTimeMeta:ver.2.20`
- FDR-AX700 (older): `nonRealTimeMeta:ver.2.00`

Common elements: `TargetMaterial` (umid), `Duration` (frames), `LtcChangeTable`
(Rec Run TC start/end), `CreationDate` (with tz offset), `VideoFormat`
(codec/fps/resolution), `AudioFormat` (LPCM16, 2 ch), `Device` (mfr/model/serial),
`RecordingMode`, `AcquisitionRecord` (gamma/color/coding + sensor ChangeTables).

**Older/simpler devices omit:** `KlvPacketTable` (RecStart marker), `<Lens>`,
`<ExifGPS>`, and the sensor `ChangeTable`s (Gyroscope/Accelerometor/etc.). The
AX700 sidecar has only `CameraUnitMetadataSet` — no Lens (fixed), no GPS, no KLV.

### Recording mode is sidecar-only — no DB field

Both **S&Q motion** and **audio-off** are encoded ONLY in the sidecar XML and
MEDIAPRO — the CLIP record in DATABASE.BIN has no field for them. Examples:

- **S&Q motion** (C6357): `<RecordingMode type="slowAndQuickMotion" cacheRec="false"/>`
  + `<VideoFrame captureFps="7.49p" formatFps="29.97p"/>` (capture fps differs from format fps).
- **Audio-off** (C6357, C6358): still lists `<AudioFormat numOfChannel="2">` with
  `<AudioRecPort ... audioCodec="LPCM16" trackDst="CH1/CH2"/>` — no "muted" or "silent"
  attribute. The audio data is simply absent from the MP4.
- **Both modes confirmed structurally identical to normal recordings** in the DB
  (same `02 00 90 02` layout). No bit, flag, or field changes between audio-on and
  audio-off clips, or between S&Q and normal clips.

## 6. DATABASE.BIN — the media database

Fixed **9,670,656 bytes**, slot-organized. Two regions matter:

### Header / counters (`0x7C00`–`0x801F`)
| Offset | Meaning |
|---|---|
| `0x7C44` | record/event counter (≈+1/clip plus structural extras; 6130 at after10 for 29 clips) |
| `0x7C4C` | **generation/milestone id** (snapshotted into each clip record `+0x56`; NOT a per-clip counter — changed only 3× across 11 snapshots; frozen at 6123 through after10) |
| `0x7C80` | total cataloged items (stills + clips), **net current** |
| `0x7C84` | still count (unchanged by video) |
| `0x7C88` | video-clip count, **net current** (delete + add cancel out) |
| `0x8000–0x8003` | mirrors latest clip's LTC end time |
| `0x800C` | confirmed 0 across all 11 snapshots (earlier 0x000667EC was a misread) |
| `0x8010`,`0x8018` | mirror latest clip's 1024Hz counters (cnt1/cnt2) |
| `0x8014`,`0x801C` | duplicate of an unknown per-clip value (0x000707E6 at after10) |
| `0x7FFC`,`0x42FA` | block-trailer bytes (function unknown — possibly checksums; unresolved) |

### Clip table (starts `0xFE024`, fixed `0xA0` slots)
Each slot is one record type, distinguished by its leading bytes:
- `02 00 …` = **CLIP record** (signature `02 00 90 02` on ILCE; `02 00 18 02` on older AX700)
- `02 20 …` = **INDEX segment** (UMID directory: header `{cap:u16@+2, count:u16@+4}` + 32‑byte UMID entries: `[label‑prefix 16B] [zeroed‑instance 8B] [device‑suffix 8B]`)
- `FF FF FF FF …` = **SENTINEL** (structural boundary marker triggered by power cycle, recording-mode change, audio-format change; carries event-type encoding in payload — see offsets doc)
- `00 00 …` = **EMPTY** (never-used, or zeroed by deletion)

**Allocation rules:**
- **Clip slots are append-only** — new clips take the next free slot at the END;
  deletion zeroes the slot but it is never reused (fragmentation accumulates).
- **INDEX segments are mutable in-place**:
  - **Recording**: the INDEX covering the new clip increments its `count` in-place
    (e.g. `cap1/cnt2`→`cap3/cnt3`→`cap15/cnt6` at the same offset).
  - **Deletion**: the affected INDEX's `count` is **decremented** in-place (slot 8:
    16→14 when C5863/C5864 deleted). If the deletion leaves structural gaps,
    the next recording starts a *new* INDEX segment instead.
- **INDEX header can overflow its slot boundary** — `cap`/`count` can exceed what
  physically fits (max ~4 entries per slot). After10 slot 30: `cap=7, cnt=6` with
  only 3 entries visible. Remaining entries overflow into neighboring slot space.
- **SENTINEL triggers INDEX reset** — after a SENTINEL, the preceding INDEX segment
  stops updating and a new segment (if any) starts after the SENTINEL.

### CLIP record field map (ILCE newer format; `02 00 90 02`)
| Rel | Field | Encoding |
|---|---|---|
| `+0x0A` | **clip number × 4** | u16 LE |
| `+0x0C` | **timezone** | `tz_hours × 4` (quarter-hours) — also at `+0x14` |
| `+0x0D` | **month** | high nibble (1..C) — also at `+0x15` |
| `+0x0E` | **year − 1900** | byte — also at `+0x16` |
| `+0x10` | rec-start counter | u32 LE, **1024 Hz (2¹⁰) real-time, session-relative** |
| `+0x18` | rec-end counter | u32 LE, 1024 Hz (Δ ≈ duration + finalize) |
| `+0x3C` | **LTC start TC** | 4 bytes `[hh,mm,ss,ff]` BCD (Rec Run) |
| `+0x40` | **LTC end TC** | 4 bytes BCD |
| `+0x44` | (zeros) | no UBIT stored |
| `+0x56` | generation ref | low 24b = header `0x7C4C` snapshot, byte3 = **session/power-cycle counter** (cycles 0x00→0x10→0x20→0x30→0x00) |
| `+0x70` | size/value A | u32 LE (0x04023393 for C5850 — close to file-size but inexact) |
| `+0x74` | size/value B | u32 LE (0x00017B4A — no clear mapping to frames/bytes/ticks) |

> **UMID is NOT in the CLIP record** (corrects a documentation error). The UMID
> lives in INDEX segment entries (see §6 "INDEX segments"). The camera links
> a CLIP record to its UMID via the clip-number field `+0x0A` and the INDEX
> entry ordering. Each INDEX entry = `[prefix 16B] [zeroed-instance 8B] [device-suffix 8B]`.

**Older AX700 format** (`02 00 18 02`): same overall skeleton but **tz byte = 0**,
**no LTC stored in the record** (`+0x3C` region zeroed — LTC lives only in sidecar),
and the `+0x14` repeat differs. Matches its older NonRealTimeMeta ver.2.00 schema.

## 7. Time model — three independent time bases

| Source | What it is | Where |
|---|---|---|
| **LTC TC** (`+0x3C/+0x40`) | user-facing SMPTE timecode, **Rec Run** (advances only during recording), 29.97p, continuous across clips AND deletions | DB record + sidecar `<LtcChangeTable>` |
| **1024 Hz counter** (`+0x10/+0x18`) | internal system timer, **real physical time** (independent of wall-clock — ignores manual date changes), session-relative, rebases on power/tz break | DB record |
| **Wall-clock date** (`+0x0C..+0x0F`) | year + month + timezone only (**day/time NOT stored**); derived from the camera clock which the user can set freely | DB record |

The three are decoupled: changing the camera date shifts the wall-clock bytes but
not the 1024 Hz counter; the LTC TC marches independently per Rec Run rules.

## 8. Proxy recording (the `SUB\` asset)

When **Proxy Recording** is ON, each clip also writes a low-bitrate proxy:
- `SUB/C####S03.MP4` — HEVC 1920×1080 @ ~16 Mbps, **AAC-LC** audio (vs main's
  LPCM16), 29.97p. Carries its own embedded NRT metadata track.
- Declared in **two** places in the main clip's metadata:
  - sidecar: `<SubStream codec="HEVC_Proxy_..."/>` element (why proxy sidecars are
    ~50 bytes larger)
  - **MEDIAPRO.XML: a `<Proxy>` child inside the main clip's `<Material>`**, carrying
    `uri`, `videoType`, `audioType`, and the proxy's own UMID:
    ```xml
    <Material uri="./CLIP/C6352.MP4" ...>
      <Proxy uri="./SUB/C6352S03.MP4" type="MP4"
             videoType="HEVC_Proxy_1920_1080_M10P@L41MT" audioType="AAC-LC" ...
             umid="060A2B340101010501010D4313FF0000..."/>
      <RelevantInfo uri="./CLIP/C6352M01.XML" type="XML"/>
      <RelevantInfo uri="./THMBNL/C6352T01.JPG" type="JPG"/>
    </Material>
    ```
    Note the proxy UMID is derived from the main clip's UMID with a `0xFF` flag byte
    set (byte 14: main `0x00` → proxy `0xFF`); instance + device suffix are shared.

**The proxy has no DATABASE.BIN record** (verified: C6352's slot is followed directly
by the next clip, no proxy record between; 0x7C88 clip-count also ignores it). So:
MEDIAPRO knows about the proxy (as a `<Proxy>` child, not a standalone `<Material>`);
DATABASE.BIN does not.

## 9. Cross-device behavior on a shared card

- Each device appends its own clips (own numbering range, own UMID device-suffix,
  own LTC TC sequence) without rewriting the others' records.
- MEDIAPRO.XML accumulates `<Material>` entries from all devices.
- The "owning" `<System>` stays with the original device; `masterVersion` may
  downgrade if an older device writes.
- DATABASE.BIN record layout is **generation-dependent** (newer `02 00 90 02` with
  LTC-in-DB vs older `02 00 18 02` without) — a parser must branch on byte[2].
  Within a generation the observed layout is **codec-agnostic** (AVC / HEVC / HD-HFR
  all share `02 00 90 02`; the codec is not stored in the DB record — though a few
  undecoded fields like `+0x70`/`+0x74` could still carry codec-adjacent info).
- Filename-numbering strategy is **model/firmware-specific** and not pinned down
  here (AX700 wrote C0001 below the card's existing C5865; the 7M4 later wrote
  C6349 immediately after the 7RM5's C6348). Treat the per-device observed ranges
  as data points, not as a derived rule.

## See Also
`0001_xavc-s-cataloging-analysis.md`