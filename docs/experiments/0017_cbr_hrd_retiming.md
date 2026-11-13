# Experiment 0017: CBR HRD Retiming And C0009

Date: 2026-11-12, Asia/Shanghai.

## Outcome

Follow-up 0018 integrates fresh decode, timing, slice and selected CPB checks
into the package verifier and both writers' admission contract. C0009 now
passes 26 package/card checks under verification schema 2; the current unit
suite has 68 passing tests. The media and catalog bytes are unchanged.

**C0009 is deployed to F:, but physical camera playback is NOT TESTED.**
C0008 is retained unchanged as the comparison. No card file was deleted.
Catalyst playback of C0008 remains only the user's desktop playback evidence.

New candidate:

| Property | Value |
|---|---|
| Card video | `F:/PRIVATE/M4ROOT/CLIP/C0009.MP4` |
| Local package | `output/cat-25m-hrd/` |
| Source encoder output | `output/cat-25m/base.mov`, FFmpeg/x264 Cat encode |
| Video | 1920x1080, 60000/1001p, High@L4.2, 8-bit 4:2:0 |
| Rate | Nominal 25 Mbps; measured video 25.295944 Mbps |
| Duration / frames | 25.592233 seconds / 1534 |
| Audio | Stereo 48 kHz 16-bit big-endian PCM |
| SHA-256 | `67392a22ff8ba52193b896178afbce2c11d2cfc42180292a6ec96fcb429eee97` |

This is a metadata/HRD revision of the already re-encoded Cat, not another
lossy generation. All 6136 VCL NAL units are byte-identical to C0008, as are
all other non-SEI NALs, video configuration/timing tables and non-BP SEI
payloads. Exactly 51 later buffering-period payloads changed.
Evidence: `analysis/c0008-c0009-payload-comparison.json`.

## Why Earlier Checks Were Insufficient

The previous checks covered decode, syntax, selected scalar guards and slice
ordering. They did not model CPB arrival or subsequent CBR buffering-period
initial-delay constraints.

`check_avc_timing.py` first compares parsed SEI timing against container
timestamps using exact fractions. Both C0008 and the original base pass:
1534 picture-timing messages, 52 buffering periods, clock tick 1001/120000.
CPB removal delay agrees with DTS relative to the previous buffering period;
DPB output delay agrees with PTS minus DTS. Passing this is NOT a complete
HRD test.

The CBR CPB check then exposes a different issue. At the selected NAL-unit
stream conformance point, the later initial delays do not satisfy the
C.3 rounding constraint. Copying NAL HRD delay pairs into VCL HRD does not
account for the difference between the two counted streams.

Example, initialization at sample 0, later BP at sample 30:

| Group | Old signaled delay | Derived value in 90-kHz ticks |
|---|---|---|
| NAL | 85670 | 85663.8944 |
| VCL | 85670 | 85693.76 |

The allowed integer is floor or ceiling of the derived value. The old values
are outside those intervals. Do not reinterpret this as proof that the
camera specifically rejects this condition: no physical rejection has been
observed and the hardware's actual conformance-point handling is unresolved.

## Source Evidence And Download Limitation

Primary standard consulted: ITU-T H.264 (08/2021), Annex C, printed pages
309, 314, 315, 320 and 321 (PDF pages 331, 336, 337, 342 and 343).
The key equations are C-2, C-6 through C-10, C-14 and C-16.

Official acquisition URL:
`https://www.itu.int/rec/dologin_pub.asp?lang=e&id=T-REC-H.264-202108-S!!PDF-E&type=items`

**Both download attempts were interrupted. Neither local PDF is a verified
complete download.** The server reported 16,426,192 bytes; the retained files
are 15,537,127 and 15,050,537 bytes. The server did not support range resumption.
Do not mistake `analysis/H264-202108-S.pdf` for a fully verified archive.

Poppler rendered the relevant pages from the first incomplete copy.
PyMuPDF 2.1 independently opened it with `is_repaired=True` and extracted
the relevant equation text. Those viewed page images are preserved as
`analysis/h264-hrd-331.png`, `h264-hrd-336.png`, `h264-hrd-337.png`,
`h264-c3.png` and `h264-c3-continued.png`. The incomplete-source limitation
remains explicit despite successful viewing of these sections.

First partial-copy SHA-256:
`24a7940f254ba6019bd9b44436319d099fefdb8b97b2634240cf45bd97b9b754`.

x264 primary implementations were also inspected, without modifying them:

- `analysis/reference-x264-ratecontrol.c`: HRD arrival/removal calculations.
- `analysis/reference-x264-set.c`: buffering-period and picture-timing writers.

Their upstream locations are `https://raw.githubusercontent.com/mirror/x264/master/encoder/ratecontrol.c`
and `https://raw.githubusercontent.com/mirror/x264/master/encoder/set.c`.
The local source hashes are respectively
`b272d6dee85abb6465db38159a98a5c56e8b7ff5838a2414337e524d0b5125d2`
and `908fa4b19c5cbbad23b3c376e08ef7e39ad44622823f5eec6aac804771a86b86`.
These downloads retain their original copyright/license headers.

## Selected CPB Model

`tools/check_avc_cpb.py` checks one CBR CPB per present HRD with an unchanging
SPS, progressive syntax and low_delay_hrd_flag=0. It consumes a hash-bound
FFmpeg trace and requires the independent SEI/container timing check to pass.

The chosen conformance point is a NAL unit stream:

- NAL HRD counts every in-sample NAL byte.
- VCL HRD counts VCL AND filler NAL bytes, not VCL alone.
- MP4 NAL-length fields are not counted.
- No unspecified Annex B reconstruction or out-of-band parameter transport
  overhead is silently added.

For each possible buffering-period initialization, the model starts empty,
uses its signaled initial delay, models contiguous CBR arrival, and checks
each AU's arrival deadline, pre-removal occupancy, and later initial-delay
floor/ceiling constraint. It uses exact rational arithmetic.

This does NOT check decoded-picture/reference management, every profile/level
constraint, every syntax/SEI rule, or Sony hardware behavior. A pass must be
called a selected CPB check, not full AVC/XAVC certification.

| Candidate | Init points per group | AU checks per group | Selected result |
|---|---:|---:|---|
| C0008 | 52 | 39988 | 1326 C-16 failures per group |
| C0009 | 52 | 39988 | No selected failures in either group |

There were no modeled CPB overflow/underflow failures for C0008; its new
failure was the initial-delay constraint. C0009's peak modeled occupancy
is about 23.8 Mbit, below the declared 25 Mbit capacity.
See `analysis/cpb-c0008.json` and `analysis/cpb-c0009.json`.

## Repair

`avc_hrd.py` retains the coded slice bytes and picture-timing messages.
It independently recomputes each group's BP delay from elapsed decode time
and the cumulative actual escaped NAL bytes preceding that BP. It updates
the corresponding offset, then re-escapes the SEI and accounts for its final
bytes before processing the next AU.

The builder now enables this by default. `--no-retime-hrd` is only for
explicit historical/control reproduction. Do not use legacy normalization as
the ordinary recipe after this finding.

Low-complexity smoke input exposed a necessary preflight: blindly keeping
the encoder's initial delay can put the selected stream too close to the
fixed-capacity boundary. `retime_cbr_samples` derives separate feasible
initial-delay intervals, reserves bounded escaping headroom and selects
delays within them. No feasible interval causes an explicit failure, not
silent buffer expansion or a false valid output.

For Cat, the existing initial delay remains usable; later NAL/VCL delays
are distinct. The current algorithm additionally handles the low-complexity
fixtures without changing the declared rate/capacity or coded pictures.

## Verification

- 60 unit tests pass, including counter wrap, missing timing, malformed spans,
  independent group retiming, initial-delay selection, infeasible-capacity
  refusal, and CPB failures that are distinct from C-16 failures.
- `output/generic-smoke-05/report.json`: all six input cases pass the new
  timing, slice-order and selected CPB checks plus prior decode/audio/color
  checks. No card writes occur in that suite.
- Smoke 04's failure is retained as evidence of the initial-delay selection
  issue; it was not converted into a pass or hidden.
- C0009 full-frame decoded hashes AND timestamps equal the base for all
  1534 frames. PCM matches the base byte-for-byte.
- C0009 passes its full-sample timing and selected slice-order checks.
- All 22 package/card checks pass, including hashes of all five deployed
  files. C0008's three assets also retain their prior hashes.

## SD Write

Snapshots: `snap_20261112T180430` before this analysis,
`snap_20261112T184803` before staging, and `snap_20261112T185759` immediately
before deployment.

Post-deployment snapshot `snap_20261112T190318` contains 52 metadata files
and 103 skipped-media timestamp entries, with no snapshot errors.

Only C0009.MP4, C0009M01.XML and C0009T01.JPG were added. DATABASE.BIN and
MEDIAPRO.XML were updated additively. Three new records are 70, 71 and 72;
all 67 prior active records remain byte-identical.
The deployment reports no unexpected existing-file changes. Prior-media
preservation uses size/write-time checks except the explicitly rehashed
C0008 assets; it is not a hash audit of every original video.

Deployment: `output/cat-25m-hrd/deployment.json`.
Verification: `output/cat-25m-hrd/verification.json`.

## Reproduce

Use a fresh local output folder and an unused clip number for building.
Staging/deploying is separate and requires a current snapshot and package
verification, as in the existing scripts.

```powershell
& 'E:/anaconda3/envs/test311/python.exe' tools/build_sony_clip.py --base output/cat-25m/base.mov --output output/cat-25m-hrd-new --clip C9998 --retime-hrd
& 'E:/anaconda3/envs/test311/python.exe' tools/check_avc_timing.py output/cat-25m-hrd/C0009.MP4 --output analysis/timing-c0009.json
& 'E:/anaconda3/envs/test311/python.exe' tools/check_avc_cpb.py output/cat-25m-hrd/C0009.MP4 --timing analysis/timing-c0009.json --output analysis/cpb-c0009.json
& 'E:/anaconda3/envs/test311/python.exe' -m unittest discover -s tools/tests -v
```

## Next External Gate

Test **C0009 on the physical camera**, retaining C0008 for comparison.
Record whether it is listed, plays through, seeks and has working audio.
Capture any exact error. No Catalyst retest is needed as a substitute.
Do not call the goal complete without physical camera evidence.
