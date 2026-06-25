# DATABASE.BIN — reverse-engineered field map (Experiment 0001)

Source: byte-diff of `backup\baseline\PRIVATE\DATABASE\DATABASE.BIN`
vs `backup\after\DATABASE.BIN` after recording 2 clips (C5850, C5851).
File size is constant at **9,670,656 bytes**. 137 bytes changed in 44 regions.

> Offsets are absolute file offsets in hex. All multi-byte values observed so far
> are **little-endian**. Confidence is marked per field; anything not yet
> cross-validated against multiple recordings is `INFERRRED`.

## Header / counters

| Offset | Size | Before → After | Meaning | Confidence |
|---|---|---|---|---|
| `0x7C00` | u32 | baseline N/A, after → after10: see tracking below | volatile — jumps by varying amounts (2480 to 4.9M) across snapshots, overflow/wrapped once. Function unknown. | INFERRED |
| `0x7C40` | u32 | `0x00000001` | constant (1 database?) | INFERRED |
| **`0x7C44`** | u32 | baseline 6092 → after10 6130 | **record/event high-water mark.** ≈+1/clip plus structural extras. | MEDIUM (rule incomplete) |
| `0x7C48` | u32 | 1830 (0x0726) — **never changed** across 11 snapshots | stills-related count? Frozen after card init. | INFERRED |
| **`0x7C4C`** | u32 | baseline 2708, jumped to 6094 (first clip), 6101 (delete+readd), 6123 (C6353 alone), frozen at 6123 since | **milestone/generation id** — NOT a per-clip counter. Changed only 3× across 11 snapshots. Snapshotted into each CLIP record's +0x56 low24 bits. Update rule unknown. | MEDIUM (corrected) |
| `0x7C50` | u32 | 6089 (0x17C9) — **never changed** across 11 snapshots | frozen after card init | INFERRED |
| **`0x7C80`** | u32 | `0x14 → 0x16` (20 → 22) | **total cataloged items (stills+clips)** | HIGH (matches 20 stills + 2 clips) |
| **`0x7C84`** | u32 | `0x14` (20) unchanged | **still-image count** | HIGH |
| **`0x7C88`** | u32 | `0x00 → 0x02` | **video-clip count** | HIGH (exactly the 2 new clips) |


### `0x7C00` tracking (across all snapshots with baseline as reference)

The 0x7C00 field is highly volatile, jumping by varying amounts with no clear
correlation to clip count or events. `0x7C48` and `0x7C50` are frozen.

| Snapshot | 0x7C00 | Δ from prev | 0x7C48 | 0x7C50 |
|----------|--------|-------------|--------|--------|
| after    | `0xF13CD5E8` | (N/A) | 1830 | 6089 |
| after2   | `0xF13DD5E8` | +65536 | 1830 | 6089 |
| after3   | `0xF14BD5E8` | +917504 | 1830 | 6089 |
| after4   | `0xF17B55E8` | +3112960 | 1830 | 6089 |
| after5   | `0x713B55ED` | (wrapped) | 1830 | 6089 |
| after6   | `0xF13B5638` | +2147483723 | 1830 | 6089 |
| after7   | `0xF13B5FE8` | +2480 | 1830 | 6089 |
| after8   | `0xF13BA5E8` | +17920 | 1830 | 6089 |
| after9   | `0xF14055E8` | +307200 | 1830 | 6089 |
| after10  | `0xF18B55E8` | +4915200 | 1830 | 6089 |

### Deletion behavior (verified after11 — C5863, C5864 deleted)

When clips are deleted (through the camera), the following happens:

| Component | Change | Detail |
|-----------|--------|--------|
| CLIP slots | **Fully zeroed** (160 bytes → 0x00) | No tombstone, no partial clearing. Slots 15 and 16 entirely zeroed. |
| INDEX count | **Decremented** | Slot 8 count: 16 → 14 (= −2, matching deleted clips) |
| 0x7C44 | **Unchanged** | Event high-water mark never decreases (6130) |
| 0x7C80 | **Decremented** | 49 → 47 (= −2, total items) |
| 0x7C88 | **Decremented** | 29 → 27 (= −2, video clips) |
| 0x7C4C | **Unchanged** | Generation id frozen (6123) |
| 0x8010/0x8014/0x8018 | **Changed** | Mirrors updated, but NOT to latest remaining clip (C6358). Now point to C6353 cnt1 and an unmatched cnt2 value. Mirror logic is more complex than "latest clip." |
| 0x801C | **Unchanged** | 460774 (still mirrors some unknown value) |
| MEDIAPRO.XML | **Entries removed** | 29 → 27 materials; `createdAt` updated to deletion time |
| Sidecar files | **Deleted from filesystem** | .MP4, .XML, .JPG all removed |
| Block trailers | **Changed** | 0x7FFC (−4), 0xBFFC (full change), 0x42FB (FF→CF) |

Key rule confirmed:
- **0x7C44 is append-only** — it tracks cumulative events, NOT net clips. On deletion it stays.
- **Net counters (0x7C80/0x7C88) reflect current state** — they decrement on deletion.
- **Block trailers change on any DB modification** — consistent with being checksums or integrity values.

### `0x7C54`–`0x7C7F` reserved/unused

All zeros in every snapshot — never listed in earlier docs. Likely padding or
reserved for future use.

### Counter history (full, all snapshots)

Charted to verify field semantics (single-state reading is misleading):

```
snap       0x7C44  0x7C4C  0x7C80 0x7C84 0x7C88  clips
baseline   6092    2708    20    20    0     0
after      6095    6094    22    20    2     2      ← 0x7C4C jumps +3386 on first clips
after2     6096    6094    23    20    3     3
after3     6099    6094    26    20    6     6
after4     6100    6101    26    20    6     6      ← 0x7C4C +7 on delete+readd; net clips unchanged
after5     6110    6101    35    20    15    15
after6     6115    6101    39    20    19    19
after7     6120    6101    43    20    23    23
after8     6121    6123    44    20    24     24     ← 0x7C4C jumped +22 (6101→6123) for C6353 alone
after9     6127    6123    47    20    27     27     ← frozen 0x7C4C; +6 for 3 clips
after10    6130    6123    49    20    29     29     ← +3 for 2 clips + structural
```

- `0x7C80`/`0x7C88` track **net current** clip count (delete+add cancels).
- `0x7C44` ≈ +1/clip plus occasional extras on structural events.
- **`0x7C4C` is NOT a counter** — changed only 3× in 11 snapshots (baseline→after, after3→after4, after7→after8), then froze at 6123 through +5 more clips. Update rule completely unknown.

### Header LTC/counter mirrors (`0x8000`–`0x801F`) — DECODED (correcting earlier "timestamp" guess)

These are **mirrors of the latest recorded clip's key fields**, not timestamps:

| Offset | Size | Mirrors | Verified |
|--------|------|---------|----------|
| `0x8000`–`0x8003` | 4 B | latest clip's LTC end time (BCD) | C6358 = `03-50-27-63` |
| `0x8004`–`0x800B` | 8 B | unknown (static data, unchanged) | |
| `0x800C` | 4 B | **always 0** (earlier `0x000667EC` was a misread) | all 11 snapshots |
| `0x8010` | 4 B | latest clip's cnt1 (1024-Hz start counter) | C6358 cnt1 = 2891649024 |
| `0x8014` | 4 B | unknown per-clip value (= 0x801C) | 460774 (0x000707E6) at after10 |
| `0x8018` | 4 B | latest clip's cnt2 (1024-Hz end counter) | C6358 cnt2 = 2891651810 |
| `0x801C` | 4 B | unknown per-clip value (= 0x8014, same as 0x8014) | 460774 (0x000707E6) at after10 |

The earlier "timestamp" hypothesis was based on the first-ever recording where
these values changed and happened to fall in a time-of-day range. Cross-snapshot
tracking proved they mirror clip records instead.

## Near-block-boundary trailer fields (`0x7FFC`, `0xBFFC`) — MEANING UNKNOWN

Single fields within 4 bytes of the 16 KB block boundaries changed. Earlier I
speculated "page checksum/sequence"; **that is not confirmed and probably wrong.**

| Offset | Before → After | Notes |
|---|---|---|
| `0x42F9` | `0x00 → 0xE0` | isolated single byte set in otherwise-zero fill (in block `0x4000`–`0x7FFF`). `E0` = `1110 0000`. Could be a 3-bit slot/usage flag (matches the +3 at `0x7C44`?) — **unproven** |
| `0x7FFC` | u32 `0x0000CB48 → 0x00010D7D` (52040→68989) | smallish value — looks like an **offset/counter**, NOT a CRC (CRC32 would use all 4 bytes). At block-`0x4000` end |
| `0xBFFC` | u32 `0x5DD36C50 → 0xB8A69FC9` | both values span the full u32 range — consistent with a **hash/CRC**, but could also be a 64-bit-timestamp half. At block-`0x8000` end |
| `0x3FFC`, `0xFFFC`, `0x13FFC` | unchanged | the block trailers that did *not* change belong to blocks whose content did not change — consistent with (but not proving) a per-block checksum model |

**Honest status:** I cannot yet tell whether `0x7FFC`/`0xBFFC` are checksums,
free-space pointers, or timestamp halves. `0x7FFC` looks too small to be a CRC.
Resolving this needs either (a) a deliberately tiny single-byte edit followed by
a re-dump to see if the trailer changes as a CRC would, or (b) the Sony DB schema
(see open questions).

## Clip records (table starts at `0xFE024`)

Each clip occupies a fixed `0xA0` (160-byte) slot. The first clip (C5850) is at
`0xFE024`; subsequent clips append at `0xFE024 + k·0xA0`. There are two record
types (see "Directory organization" below for the full slot map); this section
documents the **CLIP record** (`02 00 90 02 …`). Every clip record is **immutable
once written** — only the index segments and header change on later recordings.

All 15 clips (C5850, C5852–C5865) were verified. C5851 was deleted mid-experiment;
its slot at `0xFE164` was zeroed and is documented in the deletion section below.

### C5850 record layout (relative to base `0xFE024`)

| Rel offset | Abs offset | Bytes | Meaning | Confidence |
|---|---|---|---|---|
| `+0x00` | `0xFE024` | `02 00 90 02 00 00 00 00 00 00` | record signature / type tag (`02 00`?) | INFERRED |
| `+0x0A` | `0xFE02E` | u16 LE = **clip_number × 4** | **clip id** — e.g. C5850→`0x5B68` (5850×4), C6347→`0x632C`, C0001→`0x0004`. Each device uses its own counter space (7M4: 5850+, 7RM5: 6347+, AX700: 1+). **CONFIRMED 19/19 across 3 devices** | **CONFIRMED** |
| **`+0x0C`** | `0xFE030` | **timezone offset in quarter-hours (tz_hours × 4)** | Beijing `+8`→`0x20`(32), Sydney `+10`→`0x28`(40), Moscow `+3`→`0x0C`(12). **CONFIRMED across 3 timezones** (replaces earlier "FUZZY day-tens" hypothesis — that was wrong) | **CONFIRMED** |
| **`+0x0D`** | `0xFE031` | high nibble = **month** (`0x1`..`0xC`) | all 12 months verified (Jan=1, Feb=2, …, Dec=C) | **CONFIRMED** (12 samples) |
| `+0x0E` | `0xFE032` | `0x7E`/`0x7D` | **wall-clock year − 1900** (126→2026, 125→2025) | **CONFIRMED** |
| `+0x10` | `0xFE034` | u32 LE | **session-uptime counter at 1024 Hz** (rec start). Ignores wall-clock date changes (verified: Moscow session advanced 1024 u/s even as calendar month jumped Jan→Feb→Aug→…→Dec between clips). Rebases (can go negative) on session/tz break. | **CONFIRMED** |
| **`+0x14`** | `0xFE038` | tz (quarter-hours) | timezone (repeat of +0x0C) — verified across ALL 29 clips | CONFIRMED |
| `+0x15` | `0xFE039` | high nibble = month | wall-clock month (repeat of +0x0D) — verified across ALL 29 clips | CONFIRMED |
| `+0x16` | `0xFE03A` | `0x7E`/`0x7D` | wall-clock year − 1900 (repeat of +0x0E) — verified across ALL 29 clips | CONFIRMED |
| `+0x18` | `0xFE03C` | u32 LE | second 1024 Hz counter (rec end / save). Δ(cnt2−cnt1) ≈ recording duration + finalize | HIGH |
| **`+0x3C`** | **`0xFE060`** | 4 bytes `[hh,mm,ss,ff]` BCD | **LTC timecode START** (Rec Run). Each byte = BCD field; frame tens = bits 4-5 only (bits 6-7 = flag). Verified across all 15 clips — matches sidecar `<LtcChangeTable>` exactly. | **CONFIRMED** (15/15) |
| **`+0x40`** | **`0xFE064`** | 4 bytes `[hh,mm,ss,ff]` BCD | **LTC timecode END** | **CONFIRMED** |
| `+0x44` | `0xFE068` | 8 zero bytes | no UBIT / user-bits stored here (sidecar has no UBIT element either — UB appears unused) | HIGH |
| **`+0x56`** | **`0xFE07A`** | u32 LE, e.g. `0x000017CE`, `0x100017CE`, `0x300017D5` | **low 24 bits** = snapshot of header `0x7C4C` at record time (`0x17CE`=6094 early, `0x17D5`=6101 from C5856 onward, `0x17EB`=6123 from C6353 onward — 0x7C4C is now frozen at 6123 through after10). **high byte (byte3)** = **session/power-cycle counter** (CORRECTION — was wrongly called a per-clip "sub-index"): literal byte values `0x00`/`0x10`/`0x20`/`0x30` (the *high nibble* is the counter 0/1/2/3, cycling 0→1→2→3→0), and clips recorded in the **same power-on session share it** (e.g. all 9 Moscow-session clips C5857–C5865 = `0x10`; C6349–C6352 = `0x30`; C6354–C6356 = `0x10`; C6357–C6358 = `0x20`). It is not a per-clip index. Verified: changing recording mode (S&Q) requires power cycle → byte3 increments. | HIGH (corrected) |
| `+0x70` | `0xFE094` | `93 33 02 04` (u32 LE = `0x04023393` = 67289971) | file size in bytes? C5850.MP4 = 67253139, Δ=36832 (close but not exact) | INFERRED |
| `+0x74` | `0xFE098` | `4A 7B 01 00` (u32 LE = `0x00017B4A` = 97354) | second value — not frames (75), not ticks/1024 (≈95s), not bytes | INFERRED (no clear mapping) |
| **`+0x9C`** | varies | value `0`/`2`/`3` | **recording-config flag** — not audio channels (correcting earlier guess). `0` = standard config (4ch, 15fr, audio-on, normal mode); `2` = non-default recording condition (2ch mode, S&Q motion, audio-off, non-standard duration, etc.); `3` = transition/initial clip (first clip on card, first after timezone change). Verified across 29 clips. Bit 1 (`0x02`) = "non-default config" flag; bit 0 (`0x01`) = "transitional" flag (C5850, C5856 = 3 = both bits set). **Caveat**: C6356 (2ch/16bit, audio-on) has +9C=0 despite 2ch mode — camera may reset the "default" baseline after a SENTINEL or consider audio-related menu changes separately from mode/device changes. | HIGH (corrected) |

> **UMID location: INDEX entries, NOT the CLIP record (CORRECTION).**
> The earlier field table placed the UMID at `+0xA8`–`+0xC7` relative to the CLIP
> record's base (`0xFE0CC`–`0xFE0F3`). That is **incorrect** — those bytes are
> in the **INDEX segment** slot (slot 1 at `0xFE0C4`), not in the CLIP record
> (slot 0 at `0xFE024`). The CLIP record does **not** contain a UMID. The camera
> links a CLIP record to its UMID via the clip-number field `+0x0A` and the
> INDEX segment's ordered entry list. Each INDEX entry is 32 bytes:
> `[UMID-label 16B] [zeroed-instance 8B] [device-suffix 8B]`.
> The old `+0xC8` "next-record link" entry was simply INDEX entry 1.
> See the INDEX slot tables for the correct UMID layout.

> **Date field layout (confirmed):** the 4 bytes at `+0x0C` form `[tz_quarters][month<<4][year−1900][0x00]`
> (LE), and `+0x14` repeats it. So one u32 holds timezone + month + year.
> **Day-of-month is NOT stored** in the DB — only year, month, tz. Same-month/different-month
> byte-diff shows month changes *only* `+0x0D`/`+0x15`; no byte tracks day. Day/time
> lives only in the MP4/sidecar.
> **Counter is real-physical-time at exactly 1024 Hz (2¹⁰), independent of wall-clock**
> — it ignores manual date changes (verified: 4 same-date pairs give ratio exactly
> 1024.000; date-jumped pairs still yield clean 1024×seconds). This is why it could
> appear to "go backwards" when wall-clock year was set back — it never actually
> tracked wall-clock.
> **LTC TC (`+0x3C/+0x40`)** is the user-facing SMPTE timecode (Rec Run, 29.97p);
> the 1024 Hz counter is a separate internal system timer. Two independent time bases.

> **Historical note:** the 2025-06-21 sample (C5852, date set back one year) was
> the key that first separated wall-clock from the internal counter — the year byte
> dropped `0x7E`→`0x7D` while the counter *increased*. Later rounds (Sydney/Moscow
> tz changes, 12-month sweep, LTC decode) filled in the rest of the layout above.

> **Note on the layout above:** it is the canonical CLIP record, verified against
> all 15 recordings. The same shape repeats at every clip slot. The earlier
> "label-code field at +0x3C" note (from the 2-clip draft) was wrong — that region
> is the LTC timecode, not labels. C5851 (deleted) followed the same layout before
> its slot was zeroed.

**Recording mode: S&Q motion and audio-off are metadata-only (verified after10)**
- Two new clips tested: C6357 (Slow & Quick Motion, captureFps=7.49p, formatFps=29.97p, audio-off) and C6358 (normal, 45fr, audio-off) were recorded and analyzed.
- **No CLIP record field encodes S&Q vs normal or audio-on vs audio-off.** The CLIP record layout is structurally identical to C6356 (normal 15fr audio-on). The only differences are seq, cnt1/2, LTC, genRef byte3 (incremented by power cycle), +0x70/0x74/0x5A/0x9C (normal clip-specific variance).
- S&Q mode is ONLY declared in the sidecar XML: `<RecordingMode type="slowAndQuickMotion"/>` with `<VideoFrame captureFps="7.49p" formatFps="29.97p"/>`.
- Audio-off mode still records LPCM16 with 2 audio channels in the XML — no "silent" flag exists in any metadata.
- **IMPLICATION**: The DATABASE.BIN has no concept of recording mode or audio status. Synthetic clips can be written with any CLIP record regardless of the mode being simulated.

**+0x5A — variable per-clip value (INFERRED)**
- Varies between ~0xC2 and 0xDD across ILCE-7M4/7RM5 clips. **Not monotonic**, no simple relationship to clip number, LTC, or duration.
- Tends to decrease within a session (C6354=0xD7, C6355=0xD6, C6356=0xD4) and resets after power cycle (C6357=0xD9 after reboot).
- **AX700 (older)**: +0x5A = `0x00` for both clips — device-specific variation.
- Possibly a random nonce or derived from media data (hash of clip content?).

**+0x4C area — descending sequence (FLAGGED)**
- All ILCE clips show `2F 00 2E 00 2D 00` at +0x4C, some continue descending (`2C 00 2B 00 2A 00`) for C6352. Likely a per-clip event sequence number or internal frame counter. Purpose unknown.
- **Device-specific suffix**: last 4 bytes of the 10-byte region differ by camera: ILCE-7M4/7RM5 = `… 34 00 00 00` (C6350: `E6 17 00 00`, C6351: `02 01 00 00`, C6352: `2A 00 00 00`); AX700 = `… AC 05 00 00`.

**+0x70 — always 0x0402xxxx (INFERRED)**
- The prefix `0x0402` is invariant across all 29 clips regardless of duration, codec, audio mode, or camera model. The low 16 bits vary per clip but do not correlate with file size, frame count, or recording duration. May encode file-system metadata or be a composite value.

**+0x74 — varies per clip (INFERRED)**
- Always `0x0001xxxx` or higher. Low 16 bits vary per clip with no mapping to known parameters. May be device-specific or session-specific.

**+0x9A-0x9B — trailer value (FLAGGED)**
- Non-zero value at end of every CLIP slot (+0x9A as UInt16 LE). Varies per clip. Possibly a per-record checksum or trailer id.

**SENTINEL records — updated findings (after10)**
- New SENTINELs appear at slots 36 and 38 in after10, between C6357 (S&Q) and C6358 (normal), and after C6358.
- **Trigger condition refined**: SENTINEL appears on: power cycle (byte3 changes), recording mode change (S&Q↔normal), audio format change (LPCM24↔LPCM16, 2ch↔4ch), and possibly format-related changes. It is NOT strictly a device separator.
- SENTINEL payload pattern confirmed: `FF FF FF FF 51 00 XX 00 8C 00 YY 00 00 00 00 00 02 02 04 03 03 03 05 55 35 03 00 00 …`. The `XX` byte at +0x06 and `YY` byte at +0x0A encode event type (0x0005 for normal transitions, 0x0001 for end-of-session; 0x0008 for S&Q mode).

**Generation/format variants (verified across after6/after7):**
- **Older devices (FDR-AX700)** use signature `02 00 18 02` with a stripped layout:
  `+0x0C` tz byte = `0x00`, **no LTC in the record** (`+0x3C` region zeroed — LTC
  lives only in the sidecar), `+0x14` repeat differs. Matches its older
  NonRealTimeMeta ver.2.00 schema.
- **Codec-agnostic within a generation**: XAVC-S 4K H.264 4:2:2, XAVC-S HD HFR
  (119.88p), and XAVC HS 4K H.265 10-bit clips ALL share `02 00 90 02` and the same
  field map. The codec string is **not** in the record — only in MEDIAPRO.XML
  (`videoType`) and the sidecar (`<VideoFrame videoCodec>`). (Caveat: `+0x70`/`+0x74`
  and block-trailer fields remain undecoded and could carry codec-adjacent info.)

## Clip-ID — IS stored, as `seq / 4` at `+0x0A` (CORRECTION)

> **Retraction:** an earlier version of this section claimed the clip number was
> "NOT stored in DATABASE.BIN" because grepping for `5850` (`0x16DA`) found nothing.
> That was wrong — the encoding is **`clip_number × 4`** (e.g. 5850 → `0x5B68`).
> Verified for all 19 clips across 3 devices (ILCE-7M4 C5850–C5865, ILCE-7RM5
> C6347/C6348, FDR-AX700 C0001/C0002). Deleted C5851's slot (seq `0x5B6C`) was
> zeroed and its id retired.

**Numbering is per-device, not card-wide.** Each device carries its own internal
counter and writes `counter × 4` into `+0x0A`. When multiple devices share a card,
their id ranges coexist (7M4: 5850+, 7RM5: 6347+, AX700: 1+) with no coordination —
the earlier "max+1 filesystem-derived" hypothesis only appeared true because a
single device's counter happened to track the running max.

## Path-template table (`0x10161`–`0x11D84`)

Wildcard strings (`C****` = clip number, `***MSDCF` = still folder, `DSC0****` /
`_DSC****` = still number). Each template is preceded by a length byte and a
`01 00 00 00 FF FF FF FF` marker and an `A:` drive prefix.

| Abs offset | Template |
|---|---|
| `0x10161` | `A:/DCIM/***MSDCF/DSC0****.JPG` |
| `0x11BA6` | `A:/PRIVATE/M4ROOT/SUB/C****S03.MP4` |
| `0x11C49` | `A:/PRIVATE/M4ROOT/THMBNL/C****T01.JPG` |
| `0x11CE7` | `A:/PRIVATE/M4ROOT/CLIP/C****M01.XML` |
| `0x11D84` | `A:/PRIVATE/M4ROOT/CLIP/C****.MP4` |
| `0x490A1` | `A:/DCIM/***MSDCF/_DSC****.JPG` |

## Byte-pattern scan results (in the earliest `after` snapshot)

> These counts are from the 2-clip `after` state and are historical. In `after5`
> (15 clips) the counts are higher — the systemId appears in every clip record and
> every index entry; the UMID prefix appears once per clip record + per index entry.

- SystemId `9C 50 D1 FF FE C4 F9 49` → **24 occurrences** in `after` (pervasive;
  used in still records + clip record at `0xFE0E4` + index entries).
- UMID prefix `06 0A 2B 34 01 01 01 05 01 01 0D 43 13` → in `after`, **3 occurrences**
  (`0x3E6EC`, `0x47F2C`, `0xFE0CC`); the stills records reuse the same universal-label
  prefix, and each clip record carries it at `+0xA8`.

## Directory organization (verified across delete + re-record + timezone change)

The clip table starts at `0xFE024` and grows in fixed **`0xA0` (160-byte) slots**.
Each slot is one of four record types, distinguished by its leading bytes:

| byte[0..3] | Type | Meaning |
|---|---|---|
| `02 00 …` | **CLIP record** | per-clip catalog entry (signature `02 00 90 02` on ILCE; `02 00 18 02` on older AX700) |
| `02 20 …` | **INDEX segment** | UMID directory header `02 20 [cap:u16@+2] [count:u32@+4]` + UMID entries (per-clip prefix + zeroed-instance + **device suffix** — a segment can mix devices, e.g. seg-2 in `after7` holds both 7M4 and 7RM5 suffixes) |
| `FF FF FF FF 51 00 05 00 …` | **SENTINEL** | structural boundary/segment marker (4th type) — see §"SENTINEL records" below |
| `00 00 …` | **EMPTY** | zeroed slot (never-used or freed by deletion) |

Slot map in `after4` (6 clips, after deleting C5851 + adding C5856):

```
slot 0  0xFE024  CLIP  C5850 (seq 0x5B68, 2026-06)
slot 1  0xFE0C4  INDEX cap=15 count=5   ← main index, shrunk 6→5 after C5851 deletion
slot 2  0xFE164  EMPTY (freed)          ← was C5851; fully ZEROED on delete
slot 3  0xFE204  CLIP  C5852
slot 4  0xFE2A4  CLIP  C5853
slot 5  0xFE344  CLIP  C5854
slot 6  0xFE3E4  CLIP  C5855
slot 7  0xFE484  CLIP  C5856 (seq 0x5B80, 2026-01)  ← appended at END, did not reuse slot 2
slot 8  0xFE524  INDEX cap=1  count=1   ← NEW segment created for C5856 (post-deletion)
```

### Behavioral rules (confirmed)

1. **Append-only allocation.** New clips take the next free slot at the END. The
   freed slot 2 was *not* reused for C5856 — fragmentation accumulates.
2. **Deletion zeroes the entire slot.** C5851's 160 bytes went all-`00`. No tombstone.
3. **Sequence id (`+0x0A`, +4/clip) never reuses retired numbers.** C5851's `0x5B6C`
   is gone; C5856 took `0x5B80`.
 4. **Index segment is mutable in-place.** Changes tracked across all snapshots:
    - **Recording**: the INDEX that covers the new clip gets its `count` incremented
      in-place (e.g. one segment went `cap1/cnt2` → `cap3/cnt3` → `cap15/cnt6`
      at the same offset across `after`→`after2`→`after3`).
    - **Deletion**: INDEX `count` is **decremented** in-place for the affected segment.
      Verified: slot 8 count 16→14 when C5863/C5864 deleted (after10→after11).
      Additionally, if the deletion leaves the segment with stale entries, a *new*
      segment is created for the next recording (after3→after4 C5851-delete case:
      seg-1 count 6→5, then C5856 opened seg-2 at a new offset).
   - Caveat / open: `cap`/`count` do NOT match the number of visible 32-byte UMID
     entries in the segment's slot (a `cap=15/count=16` segment holds only ~3–4
     visible entries in one `0xA0` slot). So either entries are smaller/variable or
     `count` is an abstract clip-tally rather than an entry count. Entry layout not
     fully decoded.
5. **Net counters** (`0x7C80` total, `0x7C88` clips) reflect *current* state, not
   cumulative: delete 1 + add 1 → stayed at 6.
6. **~~Timezone is NOT in the DB~~ — RETRACTED, timezone IS stored.** The earlier
   claim (based on 2 timezones) was wrong: I had mis-identified `+0x0C` as a
   day-tens nibble. With 3 timezones (Beijing/Sydney/Moscow) it is unambiguous:
   `+0x0C` and `+0x14` = **timezone offset in quarter-hours (tz_hours × 4)**.
   See the field table above. The DB stores year + month + tz; the offset is NOT
   only in the sidecar as I previously wrote.

### after10 slot map (29 clips, latest snapshot)

Full layout of all occupied slots in the clip table as of after10. Slots are
0-indexed from `0xFE024`:

```
Slot  0  CLIP   C5850   seq=23400  b3=0x00  9C=3     ← first clip ever on card
Slot  1  INDEX          cap=15 cnt=5 visible=4         ← root index (first 5 clips minus C5851)
Slot  2  EMPTY                                         ← C5851 was deleted
Slot  3  CLIP   C5852   seq=23408  b3=0x10  9C=0
Slot  4  CLIP   C5853   seq=23412  b3=0x20  9C=0
Slot  5  CLIP   C5854   seq=23416  b3=0x20  9C=0
Slot  6  CLIP   C5855   seq=23420  b3=0x30  9C=0
Slot  7  CLIP   C5856   seq=23424  b3=0x00  9C=3     ← first after tz-change
Slot  8  INDEX          cap=15 cnt=16 visible=4        ← covers slots 0-17 minus gap
Slot  9  CLIP   C5857   seq=23428  b3=0x10  9C=0
Slot 10  CLIP   C5858   seq=23432  b3=0x10  9C=0
Slot 11  CLIP   C5859   seq=23436  b3=0x10  9C=0
Slot 12  CLIP   C5860   seq=23440  b3=0x10  9C=0
Slot 13  CLIP   C5861   seq=23444  b3=0x10  9C=0
Slot 14  CLIP   C5862   seq=23448  b3=0x10  9C=0
Slot 15  CLIP   C5863   seq=23452  b3=0x10  9C=0
Slot 16  CLIP   C5864   seq=23456  b3=0x10  9C=0
Slot 17  CLIP   C5865   seq=23460  b3=0x10  9C=0
Slot 18  CLIP   C6347   seq=25388  b3=0x20  9C=2     ← 7RM5 device appears
Slot 19  SENTINEL       XX=0x0005 YY=0x0000           ← device change
Slot 20  CLIP   C6348   seq=25392  b3=0x20  9C=0
Slot 21  CLIP   C0001   seq=00004  b3=0x00  9C=0     ← AX700
Slot 22  CLIP   C0002   seq=00008  b3=0x00  9C=0     ← AX700
Slot 23  CLIP   C6349   seq=25396  b3=0x30  9C=0     ← 7M4 returns
Slot 24  CLIP   C6350   seq=25400  b3=0x30  9C=2     ← 75fr mode
Slot 25  SENTINEL       XX=0x0005 YY=0x0000           ← format switch
Slot 26  CLIP   C6351   seq=25404  b3=0x30  9C=0
Slot 27  CLIP   C6352   seq=25408  b3=0x30  9C=0
Slot 28  CLIP   C6353   seq=25412  b3=0x00  9C=2     ← isolated 75fr, new 0x7C4C
Slot 29  SENTINEL       XX=0x0005 YY=0x0000           ← session boundary
Slot 30  INDEX          cap=7 cnt=6 visible=3          ← covers audio-test clips
Slot 31  CLIP   C6354   seq=25416  b3=0x10  9C=0     ← 4ch/24bit
Slot 32  CLIP   C6355   seq=25420  b3=0x10  9C=2     ← 2ch/24bit
Slot 33  SENTINEL       XX=0x0005 YY=0x0000           ← audio-format change
Slot 34  CLIP   C6356   seq=25424  b3=0x10  9C=0     ← 2ch/16bit
Slot 35  CLIP   C6357   seq=25428  b3=0x20  9C=2     ← S&Q motion + audio-off
Slot 36  SENTINEL       XX=0x0001 YY=0x0008           ← recording-mode change, S&Q flag
Slot 37  CLIP   C6358   seq=25432  b3=0x20  9C=2     ← normal + audio-off
Slot 38  SENTINEL       XX=0x0001 YY=0x0000           ← end-of-session
Slot 39+ EMPTY (slots 39-199 unused)
```

Key observations from the slot map:
- **Chronological ordering**: slots are in recording-time order, mixing all 4 devices
- **3 INDEX segments**: slots 1, 8, 30 — each covering a contiguous block of clips
- **6 SENTINELs**: inserted at session boundaries (device change, mode change, format change, end)
- **1 EMPTY slot** (slot 2): C5851 was deleted, never reused
- **29 clips total**: 25 ILCE-7M4 + 2 ILCE-7RM5 + 2 FDR-AX700
- **SENTINEL cap = 0x0001** (slot 36, 38) vs **0x0005** (others) marks session-end vs mid-stream

### SENTINEL records (`FF FF FF FF 51 00 05 00 …`)

Discovered by tracking all 8 snapshots historically (a single-state view misses
that these predate the video). Full appearance history:

| snapshot | sentinel offsets | new vs previous |
|---|---|---|
| baseline (0 clips) | `0x12084`, `0x1A144`, `0x3F624` | already present — in the **still-photo** region, predate any video |
| after … after5 | same 3 | none (despite +15 video clips) |
| after6 | +`0xFEC04` | between C6347/C6348 (both ILCE-7RM5, multi-device round) |
| after7 | +`0xFEFC4` | between C6350/C6351 (both ILCE-7M4, format-switch round) |
| after9 | +`0xFF4C4` (slot 33) | between C6355 (2ch/24bit) and C6356 (2ch/16bit) — audio-format change |
| after10 | +`0xFF6A4` (slot 36) | between C6357 (S&Q motion) and C6358 (normal) — recording-mode change |
| after10 | +`0xFF7E4` (slot 38) | after C6358 — end-of-session |

Structure (0xA0 slot): `FF FF FF FF | 51 00 XX 00 | 8C 00 YY 00 | 00 00 00 00 |
<payload: 02 02 04 03 03 03 05 55 35 03> | …zeros… | <u16 tail at +0x9A>`.
- `XX` at +0x06: `0x0005` = mid-stream separator (device change / mode change / format change — recording continues past it); `0x0001` = session-boundary separator (trailing sentinel, or boundary after last clip of a session block).
- `YY` at +0x0A: `0x0000` = standard mode context; `0x0008` = S&Q mode was active in the session block (observed at slot 36 between C6357/S&Q and C6358/normal).

Conclusions:
- **Not video-specific, not per-clip** — 3 exist from the still-only baseline.
- **Not a device separator** — multiple clip-table sentinels sit between two *same-device* clips.
- **Refined trigger model**: SENTINEL is written when the camera detects a "session boundary" — power cycle (byte3 changes), recording mode change (S&Q↔normal), audio format change (LPCM24↔LPCM16, 2ch↔4ch). The SENTINEL may serve as a checkpoint that causes the INDEX to stop updating (C6355/C6356 not indexed on same side of SENTINEL).
- The trailing `XX`/`YY` bytes encode the event type and mode.

### Cross-validation wins this round

- **Month nibble fully confirmed across 29 clips**: June=`0x6_`, May=`0x5_`,
  **January=`0x1_`** (C5856).
- **Year byte confirmed**: `0x7E`=2026, `0x7D`=2025.
- **+0x9C flag validated**: 29/29 clips match the pattern (0=standard, 2=non-default,
  3=transitional). Edge case: C6356 (2ch/16bit, audio-on) = 0 — camera may reset
  "default" baseline after SENTINEL.
- **genRef byte3** cycles 0x00→0x10→0x20→0x30→0x00 and clips in the same
  power-on session share it. Verified for all 29 clips across 4 devices.
- **0x8000-0x801C** confirmed as mirrors of latest clip's LTC end, cnt1, cnt2,
  plus an unknown duplicated value (0x8014=0x801C).
- **`0x7C44` rule is NOT fully resolved.** ≈+1/clip plus structural extras.
  The extra-`+1` trigger is unknown — candidates: power-cycle session count,
  index-segment cap-rewrite.

### Unresolved items

- **Block trailers** (`0x7FFC`, `0xBFFC`, `0x42FA`): function unknown — possibly
  checksums that could cause camera rejection if not recomputed. Resolution path:
  single-byte-edit experiment.
- **INDEX cap/count mismatch**: visible UMID entries (max 4 per 0xA0 slot) don't
  match the declared cap/count (e.g. `cap=7 cnt=6` with only 3 visible entries).
  Entries must overflow into neighboring slot space, but the exact mechanism is
  unknown.
- **0x7C4C update rule**: jumps +3386 (first clips), +7 (delete+readd), +22
  (single clip C6353), then freezes. No obvious trigger. Needs controlled experiment.
- **0x7C44 extra +1**: ≈+1/clip but occasional extra +1 on structural events.
  Exact trigger unknown.
- **+0x5A**: non-zero for ILCE (0xC2-0xDD), 0x00 for AX700. Varies per clip,
  tends to decrease within session. Purpose unknown (nonce? hash?).
- **+0x70/+0x74**: encode some per-clip value with invariant prefix
  (0x0402xxxx / 0x0001xxxx). No correlation to file size, frame count, or duration.
- **+0x4C area**: descending sequence `2F 00 2E 00 2D 00 …` across all clips.
  C6352 continues to `2C 00 2B 00 2A 00`. Last 4 bytes: ILCE=`34 00 00 00` (varies),
  AX700=`AC 05 00 00`. Purpose unknown.
- **0x7C00 field**: volatile with no pattern, overflow/wraps. Function unknown.
- **0x8014/0x801C**: duplicate unknown value (0x000707E6 at after10). Origin unknown.
- **CLIP record blind spots**: +0x1C–+0x3B (32 B), +0x78–+0x99 (34 B), all zero
  in all 29 clips. Likely reserved padding.
- **C6352 anomaly**: only clip with non-zero +0x44/+0x48 (duplicates LTC start/end).
  Cause unknown.

## See Also
`0001_xavc-s-cataloging-analysis.md`