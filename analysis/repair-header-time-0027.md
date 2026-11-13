# Experiment 0027: Header Time Provenance

Scope: offline comparison of `backup/snap_20261113T135135` (before) and
`backup/snap_20261113T135646` (after). No card reads/writes, no new snapshots,
no Ghidra project changes. JSON contains every active content record's two
stored timestamps, restored paths, media manifest times, XML dates, hashes,
original-instruction evidence, and native time-helper test vectors.

## Finding

The exact source value is identifiable, not merely a similar future date:

| Evidence | Value |
| --- | --- |
| After `DATABASE.BIN+0x8010` | `0x000667ec72fbdc00` |
| Decoded header | `2026-12-14T11:59:55.000+03:00` |
| After content record 53, file offset `0x12120`, date at `+0x10` | `0c c0 7e 00 00 dc fb 72` |
| Original converter's record 53 creation LocalTime | `b4 00 ea 07 0c 0e 0b 3b 37 00 00 00` |
| Original firmware header-packing helper on that LocalTime | `0x000667ec72fbdc00`, exact 64-bit match |
| Restored main path | `PRIVATE/M4ROOT/CLIP/C6353.MP4` |
| Restored XML path | `PRIVATE/M4ROOT/CLIP/C6353M01.XML` |
| XML `CreationDate`, before **and** after | `2026-12-14T11:59:55+03:00` |
| XML `lastUpdate`, before **and** after | `2026-12-14T11:59:58+03:00`, not the header value |
| XML SHA-256, before **and** after | `3e69d1100656567d8a492a7920775a590878ead131f30cae4e25a461afaf68f9` |

Before record 53 instead encoded `2026-12-14T11:59:59+00:00`
(`00 c0 7e 00 00 ec fb 72`). Its header-equivalent value is
`0x000607ec72fbec00`, **not** the after header. Thus a blind copy of that
old record's date cannot explain the exact after bytes: seconds and timezone
both changed to match the already-existing XML. This identifies a precise
metadata/record source, without proving which runtime reader supplied it.

The before header is `0x000707eb6b4ed400`, or
`2026-11-13T13:14:53+08:00`, exactly matching C6518's creation time.
The after header `+0x8018` remains in November:
`2026-11-13T13:54:48.768+08:00`; it exactly matches record 53's
separate `+0x18` update-argument timestamp. These are distinct date fields.

## Exhaustive Content-Time Check

- Both snapshots have 74 active type-0 content records: 23 photos and 51 videos.
  Every content checksum and database header checksum passes.
- The original offline record converter returns success for all 148 record
  observations. All 148 creation LocalTime structures match the independent
  packed-record decoder, including photo records.
- After record 53 is the **unique** maximum creation date under the provisional
  existing-record comparator's mask `0x7ffffffffff`, among both videos and all
  contents. It is also the unique UTC maximum in this dataset.
- After photos' maximum creation time is record 26,
  `DCIM/103MSDCF/DSC00003.JPG` / `.ARW`:
  `2026-06-22T17:05:25.412+08:00`. No photo record matches the anomalous header.
- All 51 after video record creation dates match their XML CreationDate exactly;
  before, only 22/51 match. Only C6353 XML matches the after header exactly.
- All 141 media manifest entries are represented by restored record paths.
  This includes 52 MP4 files, because one content may reference a secondary MP4;
  record count and file count are not interchangeable.
- Media size/write-time manifests agree across snapshots. This is not a media
  hash comparison or independent verification of EXIF/embedded video dates.

## Original Firmware Path

Firmware: `firmware/m4-v602/usr/lib/libmpr.so`, SHA-256
`1a7a8007828810f948eb4fb95b9a269176355553a69977f6d8f2ae59516f5532`.
Below, addresses are ELF VMAs; saved Ghidra addresses add `0x100000`.
The JSON includes freshly decoded original instruction bytes and the hashes of
the corresponding saved decompilations.

| Function | Observed date handling |
| --- | --- |
| `0xaa87c`, `ConvDefStructLocalTime2SiDBUInt64(LocalTime const&)` | Returns the header-form date, with timezone encoded as `(tz_minutes / 30 + 0x60) << 44`. Four isolated original-code test vectors agree with the Python model. |
| `0xb7ecc`, overload with output pointers | Returns date and signed half-hour timezone separately. Original-code candidate vector outputs date `0x7ec72fbdc00`, timezone `6`. It must not be confused with the first overload. |
| `0xbded4`, `ProvisionalRepairM4` | Existing-record merge loop converts `ExistedFileInfo+0x50`, compares both dates masked by `0x7ffffffffff`, retains the **full** winning packed date. At `0xbe1e4`/`0xbe1f0` are the masks; `0xbe200` stores the winner. |
| `0xbc1d8`, `ProvisionalRepairDcf` | Corresponding existing-photo merge loop uses the same masked-date/full-winner pattern. Thus photos participate in a separate accumulator, not an assumed video-only maximum. |
| Both provisional functions, remaining-object registration loops | Use the output-pointer overload and an unmasked unsigned comparison. They are not identical to the existing-record loops. |
| `0xbe8f4`, `_Load` | If either repair flag is set, compares Dcf/M4 accumulators **masked**, then calls `SetHeaderParam(slot, 3, winner)` at `0xbef10`. The compare/select is at `0xbeef8..0xbef08`. |
| `0xbf1b0`, `ReCreate` | If either repair flag is set, compares Dcf/M4 accumulators **without masking**, selects one, and calls header parameter 3 at `0xbf4d0`. |
| `0x290bc4`, `SetHeaderParam<unsigned long>` | Case 3 writes database base `+0x8000+0x10`; original store at `0x290d64`. Then recalculates the header checksum and marks header flush state. |

The masked comparison is a local-calendar bit comparison, not UTC conversion.
It drops bits 43 and above, including timezone and the high year-offset bit;
the observed years are below 2028, so the year truncation does not affect this
dataset. A full unsigned maximum over the after **records** would instead choose
C5856 because its timezone is `+10:00`. Therefore it is not valid to summarize
all these branches as one universal unmasked "maximum timestamp" operation.

## Interpretation And Limits

The exact C6353 XML/record match, its unique masked maximum, original-code
packing, and the provisional repair-to-header static path together support
the interpretation that repair propagated an existing future-dated content
creation value into header `+0x8010`. They do **not** independently prove a
particular caller, branch, or reader ran on the camera.

In particular, the provisional code takes LocalTime from `ExistedFileInfo`,
not directly from the stored database record examined here. Construction of
that intermediate object and NRT embedded-path behavior are intentionally left
to the parent analysis. No full repair routine or camera filesystem was emulated.

F: was reported unavailable, so no attempts were made to wait, mount, or read
it. The snapshots exclude media bytes; photo EXIF could not be independently
checked. No standalone saved EXIF export was identified in the targeted local
artifact inventory. Photo exclusion here is based on **all database photo
record dates**, not a claim about independently read EXIF.

These dates do not establish actual capture dates, the historical reason for
future camera settings, or that the repair-time camera clock jumped forward.
The future XML date already exists in the before snapshot.

## Reproduction

Run with bytecode disabled to avoid incidental workspace writes:

```powershell
& 'E:\anaconda3\envs\test311\python.exe' -B tools\investigate_repair_time.py --output analysis\repair-header-time-0027.json
& 'E:\anaconda3\envs\test311\python.exe' -B -m unittest discover -s tools\tests -p test_investigate_repair_time.py -v
```

The tool rejects output paths other than the designated JSON report.
Five focused tests cover the exact candidate bytes, before/after distinction,
timezone/subsecond packing, and masked versus full unsigned comparison.
