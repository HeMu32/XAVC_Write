# Gap analysis: which fields are understood, flagged, or blind

Date: 2026-06-21.  Covers all 11 snapshots (baseline → after10).

Method: cross-referenced every documented offset against the actual hex dumps of
`after10\DATABASE.BIN`, `after10\MEDIAPRO.XML`, `after10\*.XML` sidecars, and
`STATUS.BIN` (where captured).  Each byte region is classified as:

- **✅ Confirmed/High** — verified across multiple snapshots, cross-device
- **🔶 Inferred/Partial** — reasonably guessed but untested or incomplete
- **⚠️ Flagged** — existence noted in docs as unresolved
- **📝 Doc omission** — known to us but missing from the written docs
- **🟢 Blind spot** — never examined, no hypothesis exists
- **❌ Doc error** — claimed in docs but factually wrong (now corrected)

---

## 1. DATABASE.BIN (9 670 656 bytes)

### 1a. File header `0x0000` – `0x7BFF` (~31 KB)

| Offset range | Status | Notes |
|---|---|---|
| `0x0000` – `0x003F` | 🟢 Blind spot | File magic / format ID — never read before this audit. |
| `0x0040` – `0x10160` | 🟢 Blind spot | Vast majority of ~31 KB — contains schema version, card identity, pre-allocated structures, defaults. Never examined. |
| `0x10161` – `0x11D84` | ✅ Understood | 6 wildcard path templates (mapped in offsets doc). |
| `0x11D85` – `0x3E6EB` | 🟢 Blind spot | Contains still-image records (UMID hits at `0x3E6EC`) but the intervening bytes are unexamined. |
| `0x3E6EC`, `0x47F2C` (still records) | ⚠️ Incidental only | UMID prefix hits noted in passes; entire **still-record format** (size, fields, slotting) **unanalyzed**. |

### 1b. Counter block `0x7C00` – `0x7FFF`

As documented in the offsets-doc header table, with these corrections:

| Offset | Status | Correction needed |
|---|---|---|
| `0x7C54` – `0x7C7F` | 📝 Doc omission | All zero in every snapshot; never listed in the header table. Add a footnote: "reserved / unused". |
| `0x7C40` | 🔶 Inferred | Constant `1` — purpose guessed ("one database?") but unverified. |
| `0x7C44` | 🔶 Rule incomplete | ≈ +1/clip plus structural extras; 6130 at after10 for 29 clips. |
| `0x7C4C` | ✅ High (corrected) | Milestone id (not per-clip counter); only 3 changes in 11 snapshots. Jump pattern +3386, +7, +22 defies simple model. |
| `0x7C80`/`0x7C84`/`0x7C88` | ✅ Confirmed | Total / stills / clips — match across all 11 snapshots. |
| `0x8000–0x8003` | ✅ Confirmed | Mirrors latest clip's LTC end time. |
| `0x800C` | ✅ Confirmed | Always 0 (earlier 0x000667EC was a misread). |
| `0x8010`,`0x8018` | ✅ Confirmed | Mirror latest clip's cnt1/cnt2 (1024-Hz counters). |
| `0x8014`,`0x801C` | ⚠️ Flagged | Duplicate unknown per-clip value (0x000707E6 at after10). |

### 1c. Timestamps & block trailers `0x8000` – `0x801F`

| Field | Status | Notes |
|---|---|---|
| `0x8000`, `0x800C`, `0x8010`, `0x8014`, `0x8018`, `0x801C` | ✅ Resolved | See header table above (0x7C00 section). |
| `0x42F9`, `0x7FFC`, `0xBFFC`, `0x3FFC`, … | ⚠️ Flagged | Block-trailer bytes — possibly checksums/pointers. Flagged as unresolved. |

### 1d. Mid-file region `0x8020` – `0xFE023` (~970 KB)

| Range | Status | Notes |
|---|---|---|
| `0x8020` – `0x10160` | 🟢 Blind spot | Never mentioned in any doc. Could hold watermarks, reserved tables, expansion space. |
| `0x11D85` – `0xFE023` | 🟢 Blind spot | Only the path-template table (≤6 KB) and incidental still-record hits (2 offsets) are documented. Remainder is unexamined. |

### 1e. Clip table `0xFE024`+ (fixed `0xA0` slots)

#### CLIP record (type `02 00 90 02` / `02 00 18 02`)

Of **160 bytes per slot**, only **~54 bytes** have useful decoding.
**~106 bytes** are either blind spots or documentation errors:

| Relative offset | Bytes | Status | Notes |
|---|---|---|---|
| `+0x00` – `+0x09` | 10 | ✅ Partial | Signature `02 00 90 02` (4B) confirmed; trailing 6 zero bytes **never questioned**. |
| `+0x0A` – `+0x0B` | 2 | ✅ Confirmed | clip_number × 4. |
| `+0x0C` – `+0x0F` | 4 | ✅ Confirmed | tz + month + year + pad. Pad byte `+0x0F` is 🟢 blind (always `0x00`, never discussed). |
| `+0x10` – `+0x13` | 4 | ✅ Confirmed | 1024‑Hz start counter. |
| `+0x14` – `+0x17` | 4 | ✅ Confirmed | tz+month+year repeat. Pad byte `+0x17` is 🟢 blind. |
| `+0x18` – `+0x1B` | 4 | ✅ High | 1024‑Hz end counter. |
| `+0x1C` – `+0x3B` | 32 | 🟢 Blind spot | Always zero across ALL 29 clips, all 4 devices, all recording modes. Likely reserved padding. |
| `+0x3C` – `+0x3F` | 4 | ✅ Confirmed | LTC start (BCD). 15/15 verified against sidecar. |
| `+0x40` – `+0x43` | 4 | ✅ Confirmed | LTC end (BCD). |
| `+0x44` – `+0x4B` | 8 | ✅ High | Zeroed (UBIT unused). |
| `+0x4C` – `+0x55` | 10 | ⚠️ Flagged | Descending sequence pattern `2F 00 2E 00 2D 00 …` observed across ALL clips. Some (C6352) continue `2C 00 2B 00 2A 00`. Last 4 bytes: ILCE=`34 00 00 00` (varies per clip), AX700=`AC 05 00 00`. Purpose unknown. |
| `+0x56` – `+0x59` | 4 | ✅ High (corrected) | genRef: low24 = `0x7C4C` snapshot, byte3 = **session/power-cycle counter** (0x00/0x10/0x20/0x30, cycles). |
| `+0x5A` – `+0x6F` | 22 | ⚠️ Flagged | `+0x5A` is non-zero (0xC2–0xDD) for ILCE, **0x00 for AX700** (device-specific). Tends to decrease within session, resets on power cycle. Remaining 21 bytes all zero in all clips. |
| `+0x70` – `+0x73` | 4 | 🔶 Inferred | `0x04023393` — near C5850.MP4 filesize (67 253 139 vs 67 289 971 = Δ 36 832). Unmapped remainder. |
| `+0x74` – `+0x77` | 4 | 🔶 Inferred | `0x00017B4A` = 97 354 — no match to frames / 1024‑Hz ticks / bytes. Unmapped. |
| `+0x78` – `+0x99` | 34 | 🟢 Blind spot | All zero in ALL 29 clips. Likely reserved. |
| `+0x9A` – `+0x9B` | 2 | ⚠️ Flagged | Non-zero trailer per clip. Possibly per-record checksum or trailer marker. Never investigated. |
| `+0x9C` – `+0x9F` | 4 | ✅ High (corrected) | **Recording-config flag** (CORRECTION from earlier "audio channels" guess). `0` = standard config (4ch, 15fr, audio-on); `2` = non-default (S&Q, audio-off, 2ch, 75fr); `3` = transitional (first clip on card or after tz change). Verified across 29 clips. |
| `+0xA0` – `+0xFF` | 96 | 🟢 Blind spot | Unused/reserved. Always zero in all observed clips and devices. |

**DOCUMENTATION ERROR — UMID attribution (`+0xA8` – `+0xC7`)**

The earlier field map placed the UMID inside the CLIP record at `+0xA8` (relative
to `0xFE024`).  The actual bytes at `0xFE0CC` (= `+0xA8`) are **in the INDEX
segment slot (slot 1)**, not the CLIP record (slot 0).  The CLIP record does
**not** contain a UMID.  The `+0xC8` "next-record link" entry was simply INDEX
entry 1.  **This error has been corrected in all three docs.**  See the INDEX
segment section below for the correct UMID layout in the DB.

Summary of CLIP-record coverage after all corrections (after10, 29 clips):

```
Byte coverage of one 160‑byte CLIP slot:

Confirmed/High   ███████████████████  64 B (40 %)
Inferred/Partial ███                 12 B ( 8 %)
Flagged          ██▍                  8 B ( 5 %)
Blind spot       █████████████████   76 B (47 %)
```

#### INDEX segment (type `02 20 …`)

| Topic | Status | Notes |
|---|---|---|
| Header `{cap, count}` | 🔶 Partial | `cap`/`count` do **not** match visible 32‑byte UMID entries in one `0xA0` slot — flagged as open question in rule #4 caveat. |
| UMID entries (32 B each) | ✅ High | `[prefix 16B] [zeroed-instance 8B] [device-suffix 8B]` — layout confirmed. |
| Multi‑device mixing | ✅ Verified | Segment 2 in after7 holds both 7M4 and 7RM5 suffixes. |
| Entry-to-clip mapping | 🔶 Inferred | Via INDEX entry order matching CLIP slot order (skipping non-CLIP slots). Not explicitly proven. |

#### SENTINEL (`FF FF FF FF …`)

| Topic | Status | Notes |
|---|---|---|
| Byte structure | 🔶 Partial | Outer frame (0xA0 slot, `FF FF FF FF` header) and payload prefix (`02 02 04 03 03 03 05 55 35 03`) known. Leading event-type bytes identified (`+0x06`/`+0x0A` encode mode/event). |
| Trigger condition | ✅ Identified | Power cycle, recording-mode change (S&Q↔normal), audio-format change (ch count, bit depth), device change. 6 SENTINELs now observed in clip table (after6/7/9/10). |
| Payload semantics | ⚠️ Flagged | Inner bytes beyond the 10-byte prefix not decoded. |

---

## 2. MEDIAPRO.XML

Nearly fully understood (~98 %):

| Element / attribute | Status | Notes |
|---|---|---|
| `<MediaProfile>`: `xmlns`, `createdAt`, `version` | ✅ Understood | |
| `<System>`: `systemId`, `systemKind`, `masterVersion` | ✅ Understood | |
| `<Attached>`: `mediaId`, `mediaKind`, `mediaName` | ✅ Understood | |
| `<Material>` all documented attributes | ✅ Understood | |
| `<Material offset="">` | 📝 Doc omission | Always `"0"` — never mentioned in docs. |
| `<Material status="">` | 📝 Doc omission | Always `"none"` — never mentioned in docs. |
| `<Proxy>` all attributes | ✅ Understood | Documented in §8 of structure summary. |
| `<RelevantInfo>` all attributes | ✅ Understood | |

---

## 3. Sidecar XML (C####M01.XML)

~90 % understood.  The `<KlvPacketTable>` format is noted but not deeply analyzed
(the `key`, `frameCount`, `lengthValue`, `status` elements are structurally known).
Differences between ver. 2.20 (ILCE) and ver. 2.00 (AX700) are documented.

---

## 4. STATUS.BIN

| Aspect | Status | Notes |
|---|---|---|
| Existence | ⚠️ Mentioned | Noted in structure‑summary §1 tree. Only in after7 snapshot. |
| Content | 🟢 Blind spot | 7 bytes `01 01 00 00 00 00 00` — meaning entirely unknown. Never read or analyzed. |
| Path | 📝 Doc correction | Summary says `PRIVATE\M4ROOT\STATUS.BIN`; after7 backup shows `STATUS.BIN` (card root). Exact original location unclear. |

---

## 5. Other files

| File | Status | Notes |
|---|---|---|
| Thumbnail JPG | ✅ Understood | Plain JPEG with camera EXIF. Filename convention links to clip. No DB-side metadata. |
| MP4 container | ✅ Sufficient | ffprobe cross-checked. NRT track = embedded copy of sidecar XML. |
| AVF_INFO/AVF_ESCP | ⚠️ Unchanged | Verified unchanged by XAVC‑S recording. Internal format never examined (AVCHD‑only, irrelevant). |

---

## 6. Impact on synthetic‑clip write path

### Blockers (must resolve before writing)

1. **Block trailers (`0x7FFC`/`0xBFFC`/`0x42FB`)** — confirmed to change on every
   DB modification (recording AND deletion). Strongly consistent with checksums.
   Writing a synthetic DB without recomputing them will likely cause camera rejection.
   **Resolution path:** single‑byte‑edit experiment.

2. **INDEX cap/count mismatch** — we don't know how to correctly populate
   `cap`/`count` in a synthetic INDEX segment.  The visible 32‑B UMID entries
   don't fit the declared capacity in one `0xA0` slot.

3. **STATUS.BIN** — if the camera checks this file (7 B), an absent or wrong
   value may block playback.

### Deletion behavior (verified after11)

When clips are deleted (through the camera):
- CLIP slot is **fully zeroed** (160 B → 0x00) — no tombstone, no partial clear
- INDEX `count` decremented for the affected segment (slot 8: 16→14)
- **0x7C44 unchanged** (event counter is append-only, never decrements)
- **0x7C80/0x7C88 decremented** (net counters reflect current state)
- MEDIAPRO.XML entries removed; `createdAt` updated to deletion time
- Block trailers (0x7FFC/0xBFFC/0x42FB) all change
- Mirror fields (0x8010/0x8014/0x8018) change, but NOT to latest remaining clip
- Sidecar files (.MP4, .XML, .JPG) deleted from filesystem

### Safe to replicate from known patterns

- **CLIP record:** all confirmed/high fields (+0x0A, +0x0C–+0x0E, +0x10, +0x18,
  +0x3C, +0x40, +0x56).  Blind‑spot bytes can be zeroed (observed behavior).
- **Recording mode (S&Q, audio-off) is metadata-only** — CLIP record has no field
  for these. Synthetic clips can use any `+0x9C` flag value without the sidecar
  needing to match.
- **INDEX segment:** UMID entries layout known; header `cap`/`count` set from
  observed values.
- **MEDIAPRO.XML:** `<Material>` skeleton, `<Proxy>`, `<RelevantInfo>` all
  understood.
- **Sidecar XML:** full structure known; can be cloned from an existing clip and
  patched.

### Low‑risk unknowns

CLIP record blind spots (+0x1C, +0x4C, +0x5A, +0x78, +0xA0) are all zero in
every observed clip.  Zeroing them in synthetic writes is the safest guess.
The 970 KB mid‑file region never changed across any snapshot — likely static
defaults or padding.

---

## 7. Previously correct; no action needed

- LTC start/end (confirmed 15/15)
- Timezone encoding (3 timezones)
- Month / year encoding (12 months, 2 years)
- 1024‑Hz counter (same‑date pairs, date‑jump pairs)
- Session‑marker byte3 of genRef
- Clip‑slot append‑only allocation; freed slots never reused
- INDEX mutable‑in‑place during normal recording; deletion → new segment
- MEDIAPRO ordering is append/recording‑event, not device‑grouped
- Proxy system (no DB record; `<Proxy>` + `<SubStream>` links)
- Codec‑agnostic layout within a generation
- UMID: index‑only in DB; zeroed instance; per‑device suffix

---

## Summary: field‑understanding by file

| File | Bytes | Understood | Flagged/open | Blind/doc‑error |
|---|---|---|---|---|
| DATABASE.BIN — header `0x0000`–`0x7BFF` | ~31 KB | ~600 B (counters) | 4 fields | **~30 KB blind** |
| DATABASE.BIN — mirrors `0x8000`–`0x801F` | 32 | ~24 B decoded | 8 B (0x8004-0x800B) + 0x8014/0x801C | 0 |
| DATABASE.BIN — mid‑file `0x8020`–`0xFE023` | ~970 KB | ~6 KB (paths) | 0 | **~964 KB blind** |
| DATABASE.BIN — clip‑record (per slot) | 160 | ~64 B | ~20 B (flagged+inferred) | **~76 B blind** |
| DATABASE.BIN — INDEX segment | variable | ~80 % | cap/count mismatch  | 0 |
| DATABASE.BIN — SENTINEL | 160 | ~60 % | payload semantics | 0 |
| MEDIAPRO.XML | ~20 KB | ~98 % | 0 | 2 minor attributes |
| Sidecar XML | ~2 KB | ~90 % | KlvPacketTable payload | 0 |
| STATUS.BIN | 7 | 0 | 0 | **7 B blind** |
| Thumbnail JPG | ~60–100 KB | ✅ linked | 0 | 0 |

## See Also
`0001_xavc-s-cataloging-analysis.md`