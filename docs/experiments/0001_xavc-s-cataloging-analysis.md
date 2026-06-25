# Experiment 0001 — Sony ILCE-7M4 XAVC-S video cataloging format

**Date:** 2026-06-21
**Camera:** Sony ILCE-7M4 (firmware master `XAVC-M4@2.00.00`), lens Sigma 35mm F2 DG DN | Contemporary 02
**Media:** SD card mounted at `K:\` (card systemId `9C50D1FFFEC4F949`, mediaId `00000000957296D4F9499C50D1FFFEC4`)
**Scratch disk (historical):** `R:\` RAM disk was used for early snapshots; all
  backups have since been moved into the workspace `backup\` folder (R:\ no longer used).
**Baseline backup:** `backup\baseline\`
**After-recording copies:** `backup\after\` … `backup\after5\`, plus `backup\current\`

## Objective

Determine how the camera catalogs/records video clips on the card: which files it
writes/updates, what those changes contain, and how the changes correspond to a
specific newly-recorded clip. This is the foundation for being able to write clips
onto the card and have the camera recognize them.

## Method

1. Snapshot the card while it contains **only stills** (no clips). Mirror every file
   except images (`.jpg/.arw/.heif`) and videos (`.mp4/.mov/.mts/.m2ts`) into
   `backup\baseline\`. Also record a CSV manifest of the *skipped*
   media files with full timestamps (`_skipped_media_manifest.csv`) and a snapshot
   of all directory timestamps (`_dir_state.csv`) for diffing.
2. Let the user record two new clips (C5850, C5851) onto the card.
3. Re-list the card; copy the changed metadata files (DATABASE.BIN, MEDIAPRO.XML,
   and the new sidecar XMLs) into `backup\after\`.
4. Diff text files directly; byte-diff DATABASE.BIN and hex-dump the changed regions.

Tooling: PowerShell only — `[System.IO.File]::ReadAllBytes` for byte-level access,
a hand-rolled hex dumper for context, and byte-pattern scans to locate UMIDs /
systemId / path strings. No external hex editor was required for this stage.

## Baseline state (before recording)

Card used 471 MB. **No video clips present** — `MP_ROOT\101ANV01`,
`PRIVATE\M4ROOT\CLIP`, `PRIVATE\M4ROOT\SUB`, `PRIVATE\M4ROOT\TAKE`,
`PRIVATE\M4ROOT\THMBNL`, and `PRIVATE\AVCHD\BDMV\{STREAM,CLIPINF,PLAYLIST}` were
all empty. `DCIM\100MSDCF` held 20 shots (DSC00001–DSC00020, JPG + ARW pairs).

Catalog-relevant files captured in the baseline (20.47 MB total):

| Path | Size | Role |
|---|---|---|
| `AVF_INFO\AVIN0001.{INP,BNP,INT}` | 3.38 MB | Legacy AVCHD index (unchanged by XAVC-S recording) |
| `AVF_ESCP\AVIN0001.{INP,BNP,INT}`, `PRV00001.BIN` | 5.54 MB | Legacy AVCHD escape/preview (unchanged) |
| `PRIVATE\DATABASE\DATABASE.BIN` | 9,670,656 | **Main media database** |
| `PRIVATE\M4ROOT\MEDIAPRO.XML` | 1,415 | **XAVC-S media profile + clip manifest** |
| `PRIVATE\AVCHD\BDMV\{INDEX.BDM,MOVIEOBJ.BDM}` | 620 | AVCHD index stubs |
| `PRIVATE\SONY\SETTING\7M4\CAMSET\HMSET01.DAT` | 125,086 | Camera settings |
| `AUTORUN.INF`, `w2k.ico`, `._turdus_m3rula`, `.fseventsd\` | — | Card-level misc |

## After recording — files changed

Two clips were recorded ~10s apart (C5850 saved 10:46:56, C5851 saved 10:47:06).

| File | Status | Size |
|---|---|---|
| `M4ROOT\CLIP\C5850.MP4` | NEW | 67,253,139 |
| `M4ROOT\CLIP\C5850M01.XML` | NEW | 2,353 |
| `M4ROOT\THMBNL\C5850T01.JPG` | NEW | 97,098 |
| `M4ROOT\CLIP\C5851.MP4` | NEW | 134,363,389 |
| `M4ROOT\CLIP\C5851M01.XML` | NEW | 2,355 |
| `M4ROOT\THMBNL\C5851T01.JPG` | NEW | 58,262 |
| `M4ROOT\MEDIAPRO.XML` | MODIFIED (size still 1415, space-padded) | — |
| `PRIVATE\DATABASE\DATABASE.BIN` | MODIFIED (size still 9,670,656) | — |
| `AVF_INFO\`, `AVF_ESCP\` | **UNCHANGED** | — |

> Conclusion: **XAVC-S cataloging lives entirely in `MEDIAPRO.XML` + `DATABASE.BIN`
> + per-clip sidecar XML/thumbnail.** `AVF_INFO`/`AVF_ESCP` are AVCHD-only and
> irrelevant for XAVC-S.

## The join key: UMID

Every clip has a 32-byte UMID. The *same* value threads through all three artifacts,
which is how a clip in `DATABASE.BIN` is linked to its `MEDIAPRO.XML` entry and its
sidecar XML:

```
C5850: 060A2B340101010501010D4313000000 52868E8E121206C5 9C50D1FFFEC4F949
C5851: 060A2B340101010501010D4313000000 E227419E121206C7 9C50D1FFFEC4F949
       └── universal label (same for all XAVC clips) ─┘ └ instance ┘ └ systemId ┘
```

- `C####M01.XML` → `<TargetMaterial umidRef="…">`  (C5850M01.XML:3, C5851M01.XML:3)
- `MEDIAPRO.XML` → `<Material umid="…">`           (line 8 = C5850, line 12 = C5851)
- `DATABASE.BIN` → **INDEX segment entries** (NOT the CLIP record — earlier field maps
  wrongly placed the UMID in the CLIP record at `+0xA8`). Each INDEX entry stores
  `[prefix 16B] [zeroed-instance 8B] [device-suffix 8B]` (32 bytes). The instance is
  **zeroed inside the DB**, so the UMID alone does *not* distinguish clips within the
  DB; the clip-number field (`+0x0A` = clip_number × 4) and INDEX ordering serve as the join key.

## Text-level findings

### `MEDIAPRO.XML` (XAVC-S media profile)

The `createdAt` attribute was bumped (`2025-10-04T01:29:09` → `2026-06-21T10:47:06`)
and a `<Contents>` block was appended with one `<Material>` per clip, each carrying
`uri`, `videoType`, `audioType`, `fps`, `dur`, `umid`, and `<RelevantInfo>` children
pointing at the sidecar XML and thumbnail JPG. File is right-padded with spaces to
hold size constant (1415 B).

### `C####M01.XML` (ProDisc NonRealTimeMeta sidecar)

Identical structure for both clips. Captures non-real-time metadata:
- `<VideoFrame videoCodec="AVC140_3840_2160_H422P@L51" captureFps="29.97p"/>` —
  H.264/AVC High 4:2:2 Profile @ L5.1, UHD 3840x2160, 29.97p
- `<AudioFormat>` LPCM16, 2 channels
- `<CameraUnitMetadataSet>`: gamma `s-log3-cine`, primaries `s-gamut3-cine`,
  matrix `rec709`
- `<LtcChangeTable>` LTC timecodes, `<Duration>` in frames
  (C5850 = 75 frames ≈ 2.5 s; C5851 = 210 frames ≈ 7 s)
- `<Device manufacturer="Sony" modelName="ILCE-7M4" serialNo="05102212">`,
  `<Lens modelName="35mm F2 DG DN | Contemporary 02">`
- `<ChangeTable>` blocks for Imager/Lens/Distortion/Gyroscope/Accelerometer
  (each just a `start` event at frame 0 — no per-frame data captured this time)

## `DATABASE.BIN` binary diff

**137 bytes changed across 44 contiguous regions**, all within the first ~1 MB.
Unchanged size (9,670,656). See `database_bin-offsets.md` for the full field map.

Summary of regions:

| Region | Meaning |
|---|---|
| `0x42F9`, `0xBFFC` | single bytes — likely page checksum / sequence |
| `0x7C01` | session counter `0xF13BF5E8 → 0xF13CD5E8` |
| `0x7C44 / 0x7C4C` | record-count / pointer fields |
| **`0x7C80`** | **total cataloged items: 20 → 22** |
| **`0x7C84`** | still-image count: 20 (unchanged) |
| **`0x7C88`** | **video-clip count: 0 → 2** ← matches the 2 new clips exactly |
| `0x8000–0x801F` | two "last-update" timestamp fields (~10:46–10:47) |
| **`0xFE024–0xFE0FF`** | **C5850 clip record + INDEX entry (slot 0 + slot 1)**: clip record at `0xFE024` (clip-number, tz/month/year, counters, LTC, genRef); INDEX entry at `0xFE0CC` (UMID prefix, zeroed instance, systemId suffix) — earlier analysis wrongly attributed the UMID to the CLIP record |
| **`0xFE15E–0xFE1FF`** | **C5851 clip record**: timestamps advanced ~10 s relative to C5850, consistent with 10:46:56 → 10:47:06 |

### Path schema inside `DATABASE.BIN` (`0x10161`–`0x11D84`)

The DB stores **wildcard path templates**, not literal clip filenames (so grepping
`C5850`/`C5851` returns nothing). The numeric clip-id field in each clip record is
spliced into `C****` at runtime:

```
A:/PRIVATE/M4ROOT/CLIP/C****.MP4          @0x11D84   main clip
A:/PRIVATE/M4ROOT/CLIP/C****M01.XML       @0x11CE7   sidecar metadata
A:/PRIVATE/M4ROOT/THMBNL/C****T01.JPG     @0x11C49   thumbnail
A:/PRIVATE/M4ROOT/SUB/C****S03.MP4        @0x11BA6   proxy/subtitle
A:/DCIM/***MSDCF/DSC0****.JPG             @0x10161   stills
A:/DCIM/***MSDCF/_DSC****.JPG             @0x490A1   stills (variant)
```

## Verification pass (2026-06-21, post-analysis)

After the first write-up I did a self-audit. Results:

- **All 44 diff regions now dumped.** The two I had skipped (`0x42F9`,
  `0xBFFC`) are dumped and described in `database_bin-offsets.md`. Neither is
  confidently a "checksum" — that earlier label was speculation.
- **Whole-card integrity scan (MD5 vs baseline):** the *only* non-media files
  that differ are `DATABASE.BIN` and `MEDIAPRO.XML`. `AVF_INFO/`, `AVF_ESCP/`,
  `INDEX.BDM`, `MOVIEOBJ.BDM`, `HMSET01.DAT`, `AUTORUN.INF`, `w2k.ico`,
  `._turdus_m3rula`, `.fseeventsd` are byte-identical. System folders
  (`$RECYCLE.BIN`, `System Volume Information`) unchanged. **No missed files.**
- **Found and fixed an off-by-4** in the counter-table offset map (constant `1`
  is at `0x7C40`, not `0x7C44`; the +3 counter is at `0x7C44`).
- **Resolved the "is 0xFE15E really C5851?" doubt.** The shared value `0x17CE`
  appears at header `0x7C4C` and at relative `+0x56` in *both* clip records
  (`0xFE07A`, `0xFE1BA`), so the second record is structurally real, not a
  journal stub.

## Verification pass 2 (exiftool / ffprobe, 2026-06-21)

Used `exiftool`/`ffprobe` (in PATH) on the two MP4s to cross-check and to try to
crack the DB timestamp encoding.

Confirmed:

- **C5851 UMID** `060A2B340101010501010D4313000000 E227419E121206C7 9C50D1FFFEC4F949`
  — instance bytes `E227419E121206C7`, distinct from C5850's `52868E8E121206C5`.
  Both end in card systemId `9C50D1FFFEC4F949`. **Both clips' instance halves are
  zeroed inside `DATABASE.BIN`** (verified earlier), so the DB stores only the
  universal-label prefix + systemId suffix — identical strings for every clip on
  this card. ⇒ within the DB, clips are distinguished by the clip-number field
  (`+0x0A` = clip_number × 4) and INDEX entry ordering, **not** by UMID.
- **The sidecar XML is also embedded inside the MP4** as a `rtmd` "Non-Real Time
  Metadata" track; exiftool parses it as `[XML]` tags and the values match the
  `C####M01.XML` files byte-for-byte semantically. So the sidecar is a *copy* of
  data already in the MP4 — relevant for the synthetic-clip write path.
- **ffprobe cross-check** of C5850.MP4: h264 / 3840×2160 / 30000∶1001 fps /
  PCM signed 16-bit BE / 48 kHz / 2 ch / +1 data stream (the NRT track) /
  duration 2.5025 s / 215 Mbps. Matches the sidecar XML exactly.
- **Thumbnails are plain JPEGs** — no XMP/DocumentID/UMID metadata inside them.
  They are linked to clips only by filename convention (`C####T01.JPG`) and the
  `<RelevantInfo uri>` entry in `MEDIAPRO.XML`. No DB-side metadata to mirror.

Attempted but **NOT resolved** — DB timestamp encoding:

- exiftool gave exact known times (C5850 create 10:46:52 / lastupd 10:46:55 / save
  10:46:56; C5851 create 10:46:58 / lastupd 10:47:05 / save 10:47:06, all +08:00;
  QuickTime `CreateDate` confirmed these in UTC). Correlated against every
  candidate byte window in the DB header (`0x8010`, `0x8018`) and per-clip
  (`0xFE02E/0xFE034/0xFE03C`, `0xFE16E/0xFE174/0xFE17C`).
- **No standard encoding fits.** The 8-byte LE value at `0x8010`
  (`0x000707E6AAAEE800` ≈ 1.98×10¹⁵) does not map to 2026 under FILETIME,
  Unix µs/100ns, QuickTime-epoch s, or 2000/1980/1904 epochs in any unit. The
  two header fields differ by `0x30C5` (12485) which does not divide cleanly
  into the 8–10 s gap between the two clips under any obvious rate.
- **Root cause: insufficient sample diversity.** Both clips were recorded 14 s
  apart — far too little entropy to uniquely identify a proprietary format,
  especially since I can't even confirm these fields *are* timestamps (vs media
  counters). Resolution requires a 3rd sample recorded on a different day/time,
  ideally at a known round value (e.g. exactly 12:00:00). Then the high bytes
  that change day-to-day vs the low bytes that change second-to-second will
  reveal the field layout.



## Later rounds (passes 3–5): what got resolved

After pass 2, three more recording rounds (date set to 2025; timezone changes to
Sydney then Moscow; a clip deletion + re-record; 9 clips cycling through all 12
months) cracked the remaining fields. **The authoritative field map with
per-field confidence is in `database_bin-offsets.md`**; summary:

- **Timezone** IS stored at `+0x0C`/`+0x14` as `tz_hours × 4` (quarter-hours).
  Confirmed across Beijing +8 / Sydney +10 / Moscow +3. *(Retracts the pass-2
  "timezone not in DB" claim — that was based on mis-reading `+0x0C` as day-tens.)*
- **Month** at `+0x0D`/`+0x15` high nibble — confirmed for all 12 months.
- **Year** at `+0x0E`/`+0x16` = year − 1900.
- **Day-of-month is NOT stored** (only year + month + tz).
- **Counter** at `+0x10`/`+0x18` is real-physical-time at **exactly 1024 Hz (2¹⁰)**,
  independent of wall-clock — verified by 4 same-date pairs giving ratio 1024.000
  and date-jumped pairs still yielding clean 1024×seconds.
- **LTC timecode** at `+0x3C` (start) / `+0x40` (end), bytes `[hh,mm,ss,ff]` BCD —
  Rec Run, matches sidecar `<LtcChangeTable>` 15/15. Continuous across the deleted
  C5851 (Rec Run TC never rolls back for deletions).
- **UBIT** not stored (no element in sidecar, zeros in DB).
- **Directory = slot table** (0xA0 slots) with four record types (`02 00` CLIP,
  `02 20` INDEX, `FF FF FF FF…` SENTINEL, `00..` EMPTY). **Clip slots** are
  append-only (deletion zeroes, never reuses); **INDEX segments** are mutable
  in-place during normal recording (deletion spawns a new segment). Sequence id
  `+0x0A` (clip_number × 4) never reuses retired numbers.

## Open questions / next steps

**Resolved (do not revisit):**
- ~~DB timestamp encoding~~ → decoded (year/month/tz/LTC/1024Hz counter). Only the
  header `0x8010` high-u32 and `+0x70`/`+0x74` regions remain unexplained.
- ~~Record-2 UMID location~~ → every clip has its UMID at `+0xA8`; the original
  "zeros at mirror offset" was the C5851 slot which was later deleted.
- ~~Clip numbering~~ → confirmed filesystem-derived (deleting C5851 did NOT cause
  C5856 to reuse `5851`; camera took next free max + 1 = 5856).

**Still open:**
1. **Block-trailer fields `0x7FFC` / `0xBFFC` / byte `0x42F9`** — meaning unknown.
   Resolve via a controlled single-byte edit (does the trailer change like a CRC?).
   This determines whether synthetic-clip writes must recompute them.
2. **Header `0x8010` high-u32** (`0x000707E6…`) and **`+0x70`/`+0x74`** — encoding
   unknown; possibly checksums or media-stat fields.
3. **Why C5856 spawned a new index segment** (slot 8) rather than appending to
   the existing one — correlates with the preceding deletion, trigger unconfirmed.
4. **Formalize the schema** as Kaitai Struct `.ksy` or 010 Editor template.
5. **Write path (the real goal).** Minimum writes for a synthetic clip: MP4 →
   `CLIP/`, sidecar XML → `CLIP/`, thumbnail → `THMBNL/`, append `<Material>` to
   `MEDIAPRO.XML`, add a clip record + bump counters (`0x7C44`, `0x7C80`,
   `0x7C88`) in `DATABASE.BIN`. **Blocked on** #1 (block trailers) and confirming
   the index-segment append logic.

## Artifacts (workspace, `backup\`)

All snapshots live under `C:\Users\HeMu\Desktop\XAVC_Write\backup\` (moved out of
the RAM disk; R:\ is no longer used for backups):

```
backup\
├── baseline\         (0-clip state — full non-media mirror, 20.5 MB)
│   ├── PRIVATE\DATABASE\DATABASE.BIN
│   ├── PRIVATE\M4ROOT\MEDIAPRO.XML
│   ├── AVF_INFO\, AVF_ESCP\, AVCHD\, SONY\, ...
│   ├── _skipped_media_manifest.csv
│   ├── _dir_state.csv
│   └── _robocopy.log
├── after\            (+C5850, C5851 — partial snapshot)
├── after2\           (+C5852 — date set to 2025)
├── after3\           (+C5853/4/5 — Beijing, May-20)
├── after4\           (delete C5851, +C5856 — Sydney tz, January)
├── after5\           (+C5857…C5865 — Moscow tz, 12-month sweep)
├── after6\           (+C0001/2 AX700, +C6347/8 ILCE-7RM5 — multi-device round)
├── after7\           (+C6349…C6352 — format-switch round: XAVC-S HD-HFR, XAVC HS HEVC, proxy) ← latest
└── current\          (stale early full mirror — only 6 sidecars, no thumbnails; superseded by after*)
```

> `current\` was an early "full mirror" but is **incomplete** (made when only 6 clips
> existed; missing thumbnails and all later clips). Treat the `afterN\` snapshots as
> authoritative; `current\` is retained only for history.
