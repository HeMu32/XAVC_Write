# Experiment 0013: Firmware-Guided SD XAVC-S 25M Candidate

Date: 2026-11-12, Asia/Shanghai.

## Status

Subsequent correction: the user reports that the added candidates are not
listed in the camera playback UI. The original NOT_TESTED language below
describes an earlier checkpoint, not current camera-listing status.
See experiment 0019 for native recording/catalog comparisons and the UMID
precision qualification; exact self-round-trip is not a visibility oracle.

Follow-up 0017 adds **C0009**, a separately deployed HRD-retimed candidate,
and preserves C0008 as the original comparison. C0008's local timing/decoder
checks below were not complete HRD conformance checks: the selected CBR
initial-delay rounding check added in 0017 fails for it. Neither candidate
has physical camera playback evidence.

**Deployed to F:, but camera playback has NOT been tested.**

User report on 2026-11-12: **C0008 plays in Catalyst**. This is a user-observed
desktop playback result, not independently observed camera playback. The user
specifically cautions that Catalyst is substantially more tolerant than the
camera; it must not be used as a camera admission/compatibility oracle.
No further Catalyst playback check is needed to repeat this observation.

Follow-up: experiment `0014_generic_encoder_and_decoder_chain.md` adds a tested
generic local driver, generated rtmd, and a lower-level decoder lead. It does
not change the deployed C0008 or establish camera playback.

The final candidate is `F:/PRIVATE/M4ROOT/CLIP/C0008.MP4`.
Its corresponding local package is `output/cat-25m-coherent/`.
The earlier `output/cat-25m/` package is retained as superseded evidence,
not the current card image.

No original clip or photograph was deleted or overwritten.
Only C0008's three new assets and the two catalogs were written. A subsequent
UMID correction replaced only our own C0008 assets and catalog entries.

## Resulting Media

| Property | Final value |
|---|---|
| Input | `Cat_25-12-25.mp4`, HEVC 3840x2160, 60000/1001p, AAC |
| Video | x264, AVC High@L4.2, 1920x1080, progressive, 8-bit 4:2:0 |
| Frame rate | 60000/1001 |
| Frames | 1534, all source frames retained |
| Duration | 25.592233 seconds |
| Rate control | Nominal 25M CBR/VBV with filler; measured video average 25.295944 Mbps |
| PROF bitrate declarations | Average and maximum both 25000 kbit/s |
| Audio | 48 kHz, stereo, signed 16-bit big-endian PCM |
| Audio samples | 1,228,427; less than one sample of rounding relative to video |
| Metadata | 1534 rtmd samples; top-level NRT XML equals sidecar byte-for-byte |
| Thumbnail | 1280x720 JPEG 4:2:2, embedded 160x120 JPEG, existing tested EXIF layout |
| MP4 bytes | 87,556,543 |
| MP4 SHA-256 | `27ebf88812469b9d5156e32acbfdd189b234ff2712f358d463447792984716b2` |
| UMID | `060A2B340101010501010D4313000000DFFD7A79561306D69C50D1FFFEC4F949` |

The file's overall bitrate is higher than the video bitrate because it also
contains PCM audio and rtmd. The nominal 25M setting is not a claim of exactly
25,000,000 video bits per second averaged over this short clip.

## Materials Collected

The CAppRemake project actually resides at `C:/Users/HeMu/Desktop/CAppRev`.
Its existing M4 6.02 `/usr` partition copy was copied into this workspace:

- `firmware/m4-v602/usr.ext2`: 378,580,992 bytes.
- `firmware/m4-v602/usr/`: 997 regular files, 343,641,957 bytes.
- `firmware/m4-v602/copy-manifest.json`: source paths and copy hashes.
- `firmware/m4-v602/extracted-manifest.json`: member paths and hashes.
- `firmware/tools/fwtool/`: existing user-mode filesystem readers and license.
- `analysis/ghidra/mpr`: independent Ghidra project; shared MCP Edit.exe project untouched.
- `analysis/decompile-mpr/`: 117 function exports at this checkpoint; some exports
  explicitly contain decompiler failure messages and are not successful analyses.

`libmpr.so` SHA-256:
`1a7a8007828810f948eb4fb95b9a269176355553a69977f6d8f2ae59516f5532`.

This is the complete extracted **/usr partition**, not the entire camera rootfs.
Unblob was unavailable; the existing user-mode ext2 parser was used instead.
The extractor was read in bounded chunks to avoid quadratic byte concatenation.
Windows case-colliding ext2 names were preserved with distinct hash-suffixed
filenames, recorded in the extraction manifest. No firmware was executed or flashed.

DSH initially failed with `no healthy upstream`. The user authorized retries;
the retries produced `docs/handoff-dsh-xavc-write.md` and
`docs/handoff-dsh-a7m4-xavc.md`, plus additional ELF symbol inventories.
These are leads, not authoritative specifications. Some incorrect claims were
sent back for correction. In particular, never adopt their early L5.2 recommendation,
mixed ELF/Ghidra addresses, or identification of recording card-speed checks
as playback checks. Some inaccuracies remain in the handoffs.

## Firmware Evidence

ELF VMAs below require **+0x100000** in this Ghidra project.

| ELF VMA | Function / evidence |
|---|---|
| `0x28b45c` | `sidb::CalcChecksum`: wrapping little-endian 64-bit sum, zero-padded tail |
| `0x2992c8` | `sidb::Load`: exact header checksum regions, bitmap, capacities and record counts |
| `0x292410` | `sidb::CreateBinaryRecord`: record payload and checksum construction |
| `0x29267c` | `sidb::CreateArrayBinaryRecord`: array length, occupied-entry bitmap, payload |
| `0x291c28` | `sidb::IncrementArrayBinaryRecordRefCount`: reference count at +8 |
| `0x292a38` | `sidb::ConvRecordInfo2RecordStructure`: references, dates, TC and sizes |
| `0x0b7ecc` | `sidb::ConvDefStructLocalTime2SiDBUInt64`: packed calendar fields |
| `0x28e698` | `sidb::RestorateUMID`: reconstructs material-time bytes from creation LocalTime |
| `0x2cd954` | Material-time helper, checked against original AArch64 instructions |
| `0x2256fc` | MP4 property classification: AVC / 1920 / 59.94 path yields `0x0164002a` |
| `0x1166d8` | XavcsMovieReader `_open_file`: parser/property/audio-format checks |

The classified `0x0164002a` is not proof that every stream with that classification
will pass the hardware decoder. The complete hardware-decoder admission chain
has not been recovered.

### SD Database Checksums

Let `S(data)` be the sum of little-endian uint64 words, with a zero-padded
last partial word and uint64 wraparound. The modulus is applied by callers.

| Covered bytes | Stored field | Modulus |
|---|---|---|
| `0x0000 .. 0x3ffb` | `0x3ffc`, u32 | `0xfffffffb` |
| `0x7c40 .. 0x7ffb` | `0x7ffc`, u32 | `0xfffffffb` |
| `0x8000 .. 0xbffb` | `0xbffc`, u32 | `0xfffffffb` |
| `0xc000 .. 0xfffb` | `0xfffc`, u32 | `0xfffffffb` |
| Each 0x400-byte block in `0x4000 .. 0x7bff` | `0x7c00 + block_index*4`, u32 | `0xfffffffb` |
| First 158 bytes of a normal 160-byte record | Record +158, u16 | `0xfff1` |

There are **15**, not 16, bitmap block checksums: 19 header checks in total.
All 19 match the original snapshot. All 63 non-sentinel original active
records match their record checksum; record 0 is a special root/sentinel.

### Corrected Record Layout

- Record table starts at `0x10000`; stride comes from header `+0x30` (160 here).
- Header `+0x44` is record **capacity**, not occupied record count.
- Bitmap at `0x4000` is little-endian bit order.
- Low nibble of record byte 0 selects content/path/binary/array record types.
- A content record's byte 7 low nibble distinguishes still (1) and movie (2).
- The old `0xfe024` offsets no longer locate clips on this rebuilt card.
- Final candidate allocates records 67 (movie), 68 (video attributes), 69 (UMID array).
- All 64 previously active records remain byte-identical to the original snapshot.
- Database size stays 9,670,656 bytes. Final difference from original: 90 bytes.
- Video count changes 30 -> 31; still count remains 23; total 53 -> 54.
- MEDIAPRO retains every old material semantically and appends exactly one.

### Date And UMID Corrections

The old claim that the low timestamp word is an independent physical 1024-Hz
counter is not supported by the firmware. It contains calendar fields:

`day<<27 | hour<<22 | minute<<16 | second<<10 | subsecond_field`.

The high portion contains year-minus-1900 and month; timezone is stored in
half-hour units. **Day-of-month is stored.** Units of arbitrary observed
subsecond fields should not be inferred solely from this packed layout.

The UMID array keeps the first 13 and final 8 bytes, with the rest zeroed.
The movie record keeps the three instance bytes and material discriminator;
`RestorateUMID` reconstructs bytes 16..22 from creation LocalTime.

The final candidate now uses this same reconstruction. The helper includes
unusual arithmetic (hour multiplier, millisecond numerator and /86400);
`sony_umid.py` preserves the actual instructions rather than silently
"correcting" them to a presumed standard formula. The date portion is
six BCD digits of modified Julian day. The date encoding matches the
camera's 2026-06-25 material date bytes `16 12 06`.

This verifies the final candidate's own round-trip on the analyzed 6.02
algorithm. It does not establish that every historical firmware produces
identical material-time values for the same time.

## Encoding And Packaging

1. Encode Cat with libx264 High@L4.2, 25M VBV, GOP 30, two non-reference B frames,
   two references, four slices, AUD, deblocking, no weighted prediction.
   Exact executed argv is `output/cat-25m/encode-command.json`.
2. Keep x264's own PPS and all coded slice data. Do not substitute camera PPS.
3. Normalize the SPS timing to `2002/240000`, fixed frame rate.
4. Add VCL HRD alongside NAL HRD, preserving the encoder's timing widths.
   Also extend **every buffering-period SEI** with the VCL initial delays.
   Merely inserting VCL HRD into SPS is incomplete.
5. Convert all AVCC NAL length fields from four bytes to three and update avcC.
6. Rebuild all three tracks, sample sizes, sample-to-chunk mappings, offsets,
   durations and edit lists. Interleave rtmd/video/audio in 30-frame chunks.
7. Use camera-native C6359 for structural headers/PROF, not C0007's damaged PROF.
8. Use the first 1534 minimal EDIUS rtmd packets from C0007; validate their
   per-frame timecodes. No copied camera gyro/lens/acquisition measurements.
9. Generate new NRT XML and embedded identical XML, coherent UMID, thumbnail and
   additive SD catalog records. Clear template S-Log3/S-Gamut3 acquisition attributes.

`C0007` is a valuable known-playable **stream** reference, but its VPRF
`avc1`/profile fields were overwritten by an old offset mistake. Its ability to
play does not make that malformed PROF a canonical template.

`0x003bf0a6` equals **3,928,230**, not the old documents' decimal 3,924,134.
Both final VPRF frame-rate fields preserve the camera's exact 0x003bf0a6.

## Verification And Deployment

- 9 unit tests pass, including checksum overflow, EBSP, Exp-Golomb, TC and UMID round-trip.
- 21 package checks pass before writing; card hash check can add a 22nd.
- All 1534 decoded frame hashes **and timestamps** match unmodified base.mov.
- PCM audio is byte-identical to the re-encoded base's audio.
- Full-clip SPS/PPS/SEI trace succeeds; full video decode has zero errors.
- Embedded NRT XML, sidecar, MEDIAPRO and firmware-restored database UMID agree.
- All 19 header and all 66 non-sentinel record checksums pass in the final DB.
- Every pre-existing original media file retains size and modification time.
- Every other pre-existing non-media file retains content hash.
- No card files deleted. Readback hashes match all five intended final files.

Snapshots:

| Snapshot | Purpose |
|---|---|
| `backup/snap_20261112T144251` | Initial original card state |
| `backup/snap_20261112T153844` | Immediately before first write |
| `backup/snap_20261112T153955` | After initial candidate |
| `backup/snap_20261112T155339` | Before correcting only our own candidate |
| `backup/snap_20261112T155529` | Final card state |

Current files: `output/cat-25m-coherent/build-manifest.json`,
`catalog/transaction.json`, `verification.json`, `deployment.json`.

Useful local checks:

```powershell
& 'E:\anaconda3\envs\test311\python.exe' -m unittest discover -s tools/tests -v
& 'E:\anaconda3\envs\test311\python.exe' tools/verify_sony_package.py --build output/cat-25m-coherent --card F:/
```

`deploy_sd_clip.py` is an additive-only writer for a new test clip.
`revise_owned_clip.py` requires a successful prior deployment and all five
previous card/local hashes to match before revising this task's own clip.
Both take a fresh snapshot and perform durable writes plus readback checks.

## Limits And Next Evidence

This is a reproducible **candidate**, not a confirmed camera-playable encoder.
The current encoder driver is Cat-specific and rtmd is template-bounded.
It is not yet a general arbitrary-duration/input implementation.
Necessity of individual VUI/HRD/container constraints has not been isolated.

Next action is physical camera playback of C0008: listing, thumbnail,
normal playback/audio and seeking. If rejected, preserve the exact message
and snapshot the card after the camera's access before changing anything.
Do not repair/rebuild the camera's database or alter C6359 as an uncontrolled test.
