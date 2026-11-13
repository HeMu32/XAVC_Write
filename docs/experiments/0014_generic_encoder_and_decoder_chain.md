# Experiment 0014: Generic Encoder Checks And Decoder-Chain Follow-Up

Date: 2026-11-12, Asia/Shanghai.

## Status And Card Identity

The current SD card is **F:**. Historical K: paths are not current.
The camera candidate remains `F:/PRIVATE/M4ROOT/CLIP/C0008.MP4`.
Its SHA-256 is still
`27ebf88812469b9d5156e32acbfdd189b234ff2712f358d463447792984716b2`.
**Physical camera playback has NOT been tested.**

This continuation performed **no card writes or deletions**. In particular,
the local C9999 test media and locally staged catalogs below were NOT deployed.
The original C0007 and C6359 references were only read.

Before card analysis, inspected the previous snapshot schema and created
`backup/snap_20261112T161740`: 51 copied metadata files, 101 media timestamp
entries, no errors. All 22 existing C0008 package/card checks passed again.
Final read-only audit `analysis/card-unchanged-0014.json` found no added/missing
files, no changed metadata hashes, and no changed media sizes/write times.
It did not hash all original media, so this is the requested coarse media audit.

## Reusable Encoder

`tools/encode_xavc.py` replaces the Cat-only front-end for new local experiments.
`tools/encode_cat.py` remains as the executed historical recipe for C0008.

The new driver:

- Selects the actual video stream, excluding attached pictures, and the first audio stream.
- Requires a finite video duration; prioritizes exact duration_ts/time_base.
- Produces 1920x1080, 60000/1001p, AVC High@L4.2, 8-bit 4:2:0.
- Retains the original candidate's x264 constraints: nominal 25M CBR/VBV,
  GOP30, two non-reference B frames, two references, four slices, no weighted prediction.
- Preserves display aspect with square-pixel scaling and black padding.
- Uses bwdif on frames marked interlaced, with field-rate output.
- Converts supported, explicitly tagged SDR matrix/transfer/primaries to
  limited-range BT.709 instead of merely changing output labels.
- Records missing color-field assumptions in `input-assumptions.json`.
  Untagged YUV is assumed BT.709/limited; untagged RGB is assumed BT.709
  primaries with sRGB transfer. These assumptions are not recovered facts.
- Recognizes ffprobe's bt470m/bt470bg transfer aliases as gamma22/gamma28.
- Rejects PQ/HLG HDR or unsupported color transforms instead of relabeling them.
- Generates finite silent stereo when audio is absent; converts other audio to
  48 kHz stereo signed 16-bit BE PCM, preserving its offset relative to video.
- Refuses an existing output directory and never overwrites previous experiments.

Example, using a new directory:

```powershell
& 'E:/anaconda3/envs/test311/python.exe' tools/encode_xavc.py Cat_25-12-25.mp4 --output output/new-experiment
& 'E:/anaconda3/envs/test311/python.exe' tools/build_sony_clip.py --base output/new-experiment/base.mov --output output/new-experiment --clip C9999
```

The second command reads F: structural references but writes only the selected
local output directory. It does not create a thumbnail or stage/deploy catalogs.
Thumbnail creation must finish before `stage_sd_catalog.py`, which reads its size.

## Generated rtmd And Audio Alignment

`tools/sony_rtmd.py` now generates a minimal 1024-byte metadata packet for every
output frame, using the first zero-TC EDIUS packet as a structural template.
The builder no longer copies a finite prefix of the reference's metadata track.
It does not invent camera sensor/lens/gyro measurements.

`tools/verify_rtmd_reference.py` compared **all 14,170** packets in C0007:

- Mismatches: **0**.
- SHA-256 of the concatenated actual and generated metadata:
  `a05726bdc50ea8f81c448b75aa840c15ff5deee0d872a666a42534054900ad19`.
- First packet SHA-256:
  `dd2f35164c20c2daafb98534563e2d4a5884ae8c73351320a6e9cd9fc145e7af`.
- Persisted evidence: `analysis/rtmd-reference-check.json`.

Header bytes 13..15 encode binary hour/minute/second. Bytes 16..17 encode the
full-frame number in that second, BE. Bytes 20..23 encode the half-step LTC.
The header follows drop-frame timecode too: frame 3600 has header
`00 01 00 00 04` and LTC `42 00 01 00`. The previous continuation's naive
frame//60 header approach would be wrong at that boundary.

This matches the observed reference duration, including minute boundaries.
Hour/day behavior outside the reference interval remains inferred, not
camera-observed.

Stereo PCM is trimmed or zero-padded to `floor(frames * 1001 * 4 / 5)` samples.
The builder validates the PCM sample entry and records both original sample
count and the amount trimmed/padded. The verifier hashes this same expected
aligned source PCM, not an unrelated full-source audio duration.

## Reduced PCM Index Memory

Previously `sony_mp4.py` materialized a size and absolute offset for every PCM
sample. That grows at 48,000 Python entries per second per array.

Uniform sample sizes now use an O(1) `ConstantSizes` sequence. Uniform-track
offsets use chunk-prefix sample counts plus binary search, O(chunks), without
changing sample indexing behavior. Variable-size video retains explicit offsets.
The builder also uses a constant-size sequence when serializing PCM stsz.

This is not a streaming builder: encoded video, metadata, PCM and the output
mdat are still accumulated in memory. Long-input memory limits remain.

## Local Integration Results

`tools/smoke_generic_encoding.py` generates fixtures, encodes them, rebuilds
Sony media locally, decodes both sides and saves machine-readable results.
Run `output/generic-smoke-02/report.json` is the final six-case run.

| Input case | Frames | Result |
|---|---:|---|
| Portrait 25 fps, no audio | 72 | Pass |
| 24 fps; mono 44.1 kHz delayed 250 ms; timeline starts at 5 s | 120 | Pass |
| 30 fps with only 400 ms mono audio | 90 | Pass |
| VFR input with dropped source timestamps | 90 | Pass |
| 720x480 interlaced, non-square pixels, SMPTE170M | 90 | Pass |
| RGB input without audio | 60 | Pass |

Every case passed:

- All decoded frame hashes and timestamps equal its unmodified x264 base.
- Expected dimensions, cadence, pixel format, High profile and level 42.
- Progressive, BT.709 limited output metadata.
- Correct PCM duration/hash and generated rtmd packet count/content.
- Full-stream trace_headers error check and full video decode.
- Silent-source audio remains silent.

The delayed-mono case has significant-signal onset at **0.250020833 s** and
end at **1.25 s**, measured from packaged PCM. The short-audio case ends at
0.4 s and has a silent padded tail. A 3 ms tolerance accommodates resampler edges.

These checks exercise color conversion but are not a calibrated colorimetry
validation or proof of camera acceptance.

Unit tests: **25 pass**, covering the original nine tests plus exact input
timing, cover-art selection, silence, audio offsets, HDR/unsupported transfers,
color assumptions/conversion construction, PCM trimming/padding/hash, compact
sample indexing, and rtmd drop-frame boundaries.

```powershell
& 'E:/anaconda3/envs/test311/python.exe' -m unittest discover -s tools/tests -v
& 'E:/anaconda3/envs/test311/python.exe' tools/smoke_generic_encoding.py --output output/a-fresh-smoke-run
```

## Generic Cat Package: LOCAL ONLY

`output/cat-generic-01/` now contains a complete local test package named C9999,
including thumbnail and staged catalogs based on snapshot 161740.

| Property | Value |
|---|---|
| Frames / duration | 1534 / 25.592233 s |
| PCM samples | 1,228,427, no trim/pad needed |
| Measured video rate | 25.295027 Mbps |
| Video SHA-256 | `fdc31cff2249a580b5ea5505cfb3eb3b7e5aca6daea88f8d2dd5cfe469b4dd2d` |
| UMID | `060A2B340101010501010D431300000045BBEC35561306C89C50D1FFFEC4F949` |
| Checks | All 21 local package checks pass; full SEI trace and video decode pass |
| Card status | NOT DEPLOYED |

Cat is tagged BT.709 matrix/primaries but **gamma 2.2** transfer. This new
experiment converts that transfer to BT.709. C0008's historical recipe merely
labeled its output BT.709; it was deliberately not changed during these tests.
Decoded equivalence claims are between each package and its own base, not
between the two different Cat encodes.

Evidence: `verification.json`, `build-manifest.json`, `encode-command.json`,
`base.framemd5`, `C9999.framemd5`, and `catalog/transaction.json` in that directory;
`analysis/avc-generic-cat-all-sei.json` and its full log.

## Decoder Message Chain

Additional exports in `analysis/decompile-mpr/` and `analysis/decompile-avbbc/`
separate player preflight from actual decoder syntax handling.
Addresses in this table are Ghidra addresses, NOT ELF symbol VMAs.

| Library / address | Observed behavior |
|---|---|
| libmpr 0x001c01d8 CheckPbStartParam | Playback identity/media-state checks, not a complete SPS validator |
| libmpr 0x002016f0 SetDecOpenParam | Initializes decoder buffers/table capacities |
| libmpr 0x00201888 SendCodecDecOpen | Leads into codec open |
| libmpr 0x00385b14 Codec::DecOpen | Chooses command 0x220 for one decoder; copies a 0x90-byte-per-decoder structure; sends to AVBBC |
| libInfraAvbbc 0x001e5f1c SetParameter | Passes a 0x38-byte request and associated stream/table parameters to parameter control |
| libInfraAvbbc 0x0022b02c ExecCmd_MC_DecOpen::ExecCmd | Converts command 0x520; sends via OsalSndMsg to 0x805700f9 |

libmpr and libInfraAvbbc in these projects use ELF VMA +0x100000. The Ghidra
project for libInfraAvbbc is `analysis/ghidra/avbbc`; it does not disturb the
shared MCP project.

Neither CheckPbStartParam nor the AVBBC forwarding layer proves that a
particular SPS/slice structure is accepted by hardware.

## Raw VCD Firmware Lead

`tools/survey_vcd.py` records the three images' hashes, headers, selected
strings and actual startup disassembly in `analysis/vcd-survey.json`.
Unblob/binwalk are unavailable in this environment; this was a read-only manual
survey, not successful automated extraction. No firmware was executed.

All three images have plausible MIPS32 little-endian startup sequences,
including CP0 accesses, branch delay slots, and explicit cached/uncached aliases.
For **vcd_firmware.bin**, SW_VER_13_11_10_0:

- Raw +0x400 loads GP 0x9fc088c8 and bootstrap SP 0xbfc00cc8.
- It transfers into address 0x80004300.
- Raw +0x4300 contains matching startup code, loads GP 0x802f32a0 and
  SP 0x804c7998, then enters 0x800f2c58.
- This corroborates a provisional main mapping of `0x80000000 + file offset`.
- Raw strings +0x2ec248 / +0x2ec26c / +0x2ec284 / +0x2ec2f4 identify
  avcdec_ctrl.cxx / avcdec_ctrl.h / avcdec_syntax.h / avcdec_dpb.cxx.
- Later strings include dec_avc_syntax.c, dec_avc_slicehdr.c,
  dec_avc_pict_param.c, dec_avc_decode.c and dec_avc_parse.c.

Independent headless import: `analysis/ghidra/vcd`, using MIPS:LE:32:default.
`tools/PrepareVcd.java` asserts the exact version string, seeds the startup
entry points, and sets the observed main GP over the provisional main range.
Seven candidate functions were exported; this is not seven fully validated
functions. The import completed, but the log contains P-code errors.

Potentially useful main-region references:

| Main address | Narrow observation |
|---|---|
| 0x800b7c64 | Decoder control allocation/queue path; assertion cites avcdec_ctrl.cxx |
| 0x800b9c4c | Populates a decoder parameter structure; cites avcdec_ctrl.cxx |
| 0x800bda38 | Reference-picture parameter setup; asserts an internal address index <=0x3d |
| 0x8015783c | Internal ud_body / detect_sei pointers must be 64-byte aligned before cache operations |

These internal index/alignment assertions are **not file-level constraints**.
In particular, they do not imply MP4 NAL offsets must be 64-byte aligned.

Late exports at 0x804f1d80, 0x804f2580 and 0x804f4968 have unresolved P-code
and/or apparent writes into main-region string addresses. Their load mapping,
GP and instruction extension context are not validated. They are retained as
diagnostic output, **excluded from format conclusions**.

### DSH Follow-Up: imola2 Is The Relevant Static Target

The authorized existing DSH a7m4 session returned
`docs/handoff-dsh-vcd.md` and placed additional local material under
`analysis/vcd/`. Independently rechecked the primary bytes:

| Material | Independently verified evidence |
|---|---|
| `analysis/vcd/nflasha3/files/av-cam.bin` | One `/usr/codec/vcd_firmware_imola2.bin` literal at raw +0x43617f; no original/fpga path literal |
| `analysis/vcd/nflasha5` | imola2 version token twice, first +0x5c7ba7c; imola2 path three times, first +0x66fe21c; zero original/fpga version tokens |

SHA-256 of av-cam.bin:
`d70ea2d700bc5fb7aa1bcfdb46eb5adb45e7d8ed703f2167fb7526f89d177d3f`.
SHA-256 of nflasha5:
`13120416073b09b13f8501324839d37b84545267dac3d183041fceb8af5a53ca`.
The latter is supplied as an update's warm-start image, not a memory dump
acquired from the physical camera in this task. The string evidence strongly
supports targeting imola2 in this firmware build; it does not observe actual
runtime loading or rule out fallback branches.

Do not use the original variant's addresses as ILCE-7M4-specific evidence.
The earlier original-variant exports remain a comparison, not a target solution.
Similarly, lack of `.text`/`PT_LOAD` ASCII in a raw header does NOT prove absence
of a binary segment table; that stronger claim in the DSH handoff is unsupported.
Its quoted COP0 byte offset also does not match the current image: rely on the
actual Capstone evidence in vcd-survey.json, not copied handoff hex.

The imola2 boot at raw +0x5a4 loads address **0x80009300** and jumps there.
At raw +0x9300, its own startup loads **GP 0x8024eb58** and
**SP 0x8070b100**, then transfers to **0x8005c34c**.
The BSS-clear loop begins at address 0x80248e08.
Thus the original variant's entry, GP and provisional main-data boundary
must not be copied.

`PrepareVcd.java` now checks the exact version and seeds the independently
observed values for each supported variant. imola2 uses its own independent
`analysis/ghidra/vcd-imola2` project. Full overlay mapping and custom instruction
extensions remain unresolved; only correctly contextualized main-region
functions can support further conclusions.

The initial import completed and eight related functions have been exported
to `analysis/decompile-vcd-imola2/`:

- 0x8003a584 and 0x8003c878: AVC controller parameter/queue preparation.
- 0x80043cc0: reference-picture parameter preparation.
- 0x80040354: builds picture/format-related decoder parameters, consuming
  parsed fields and copying dimensions/crop-related values.
- 0x80043f00: proxy parameter fields, including reads from address 0xbe000064;
  exact hardware-register semantics have not been established.
- 0x801b44e4 and 0x801b49a0: control/queue handling and internal buffer cache
  alignment, respectively.
- 0x80035efc: HEVC decoder frame path has an "unsupported bit depth"
  assertion, allowing equal field pairs 8/8, 10/10 or 12/12 in that path.
  Its source reference is hevc/hevcdec_frame.cxx, not an AVC-specific syntax
  validator. Do NOT turn this into an AVC profile admission rule.

The importer still reports errors in later, incorrectly contextualized regions.
Neither these exports nor the bit-depth assertion solve the hardware SPS/SEI
admission question. They supply the next trace points in the appropriate
firmware variant without changing the validated C0008 experiment.

## Remaining Gaps

Follow-up: experiment 0015 adds per-MBP GP contexts, an explicitly opaque
instruction model, actual SPS/PPS/VUI paths and execution of scalar guards.
It narrows the earlier "unknown parser" gap without proving hardware playback.

1. Physical camera playback of C0008: listing, thumbnail, picture, audio, seeking.
2. Runtime variant selection/fallback and validated mapping into the lower AVC parser.
3. Actual hardware necessity of individual SPS/HRD/SEI/PROF restrictions.
4. Single-clip builder rejects output >=4 GiB; spanning/splitting is not implemented.
5. Builder is memory-bound; compact PCM indexing alone does not enable arbitrary length.
6. HDR, log/unusual transfers, untagged color accuracy, corrupted or unusual
   timestamp/edit-list behavior need explicit policy or further fixtures.
7. Catalog construction still uses a compatible observed SD record/template
   structure. It is not a complete general sidb writer or CFexpress writer.

Do not replace C0008 with the local C9999 package just because local checks
pass. First obtain the physical playback result for the unchanged deployed
candidate. Preserve the camera's exact error and snapshot the card afterward;
do not repair/rebuild its catalog as an uncontrolled test.
