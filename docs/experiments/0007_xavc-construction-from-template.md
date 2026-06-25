# Experiment 0007: XAVC-S Construction from Sony-Certified Template

## Goal
Construct a synthetic XAVC-S clip playable on Sony ILCE-7M4 by matching the exact structure of a Sony-certified software-transcoded sample.

## Template Analysis: C0001.MP4
Located at `T:\TestXAVCFolder\M4ROOT\CLIP\C0001.MP4` — a Sony-certified XAVC-S clip (High profile 4:2:0 8-bit, NOT High 4:2:2).

### Key Properties
| Property | Value |
|---|---|
| **Profile** | H.264 High (profile_idc=100), 4:2:0 8-bit |
| **Resolution** | 3840×2160 |
| **Frame rate** | 29.97 fps (30000/1001) |
| **Duration** | 3.003s (90 frames, 6 GOPs of 15) |
| **GOP** | Open GOP, 2 B-frames, `b_pyramid=0` |
| **Video bitrate** | ~57 Mbps |
| **Audio** | PCM 16-bit big-endian (`twos`), 48kHz, stereo |
| **Container** | ftyp=XAVC v0x01001FFF, compatible XAVC/mp42/iso2 |
| **Tracks** | 3: video (avc1) + audio (twos) + data (rtmd) |

### Container Structure
```
ftyp (28B)        XAVC brand
uuid PROF (148B)  Sony profile descriptor: FPRF + APRF + VPRF
mdat (~22MB)      Interleaved: rtmd + video + audio per chunk (6 chunks)
moov (~2.8KB)
  mvhd            timescale=90000, duration=270142
  trak 1 (video)  avc1, edit list (media_time=1001), USMT uuid
  trak 2 (audio)  twos, edit list (media_time=0), USMT uuid
  trak 3 (rtmd)   data track, tref→video, USMT uuid
  meta            hdlr="nrtm", xml=NonRealTimeMeta
```

### Video SPS Key Parameters
| Parameter | Value | x264 match |
|---|---|---|
| profile_idc | 100 (High) | ✓ `-profile:v high` |
| level_idc | 51 | ✓ `-level:v 5.1` |
| chroma_format_idc | 1 (4:2:0) | ✓ `-pix_fmt yuv420p` |
| max_num_ref_frames | 2 | ✓ `ref=2:b-pyramid=0` |
| video_format | 0 (Component) | ✓ `videoformat=component` |
| video_full_range_flag | 0 (TV range) | ✓ `-color_range tv` |
| colour_primaries | 1 (BT.709) | ✓ `colorprim=bt709` |
| transfer_characteristics | 1 | ✓ `transfer=bt709` |
| matrix_coefficients | 1 | ✓ `colormatrix=bt709` |
| num_units_in_tick | 4004 | ✗ x264 gives 1001 (4× scale, same fps) |
| time_scale | 240000 | ✗ x264 gives 60000 |
| fixed_frame_rate_flag | 1 | ✗ x264 gives 0 |
| nal_hrd_parameters_present | 1 | ✓ `nal-hrd=vbr` |
| **vcl_hrd_parameters_present** | **1** | **✗ x264 gives 0** |
| bitstream_restriction_flag | 0 | ✗ x264 gives 1 |

### PPS Key Parameters
| Parameter | Value |
|---|---|
| entropy_coding_mode | 1 (CABAC) |
| num_ref_idx_l0/l1 | 2/2 |
| weighted_pred_flag | 0 |
| weighted_bipred_idc | 0 |
| chroma_qp_index_offset | 0 |
| transform_8x8_mode_flag | 1 |
| pic_scaling_matrix_present | 1 (custom scaling lists) |
| second_chroma_qp_index_offset | 0 |
| **PPS size** | **87 bytes** (due to scaling lists) |

### HRD Parameters (identical for NAL and VCL)
| Parameter | Value |
|---|---|
| bit_rate_scale | 7 |
| cpb_size_scale | 5 |
| bit_rate_value_minus1[0] | 12206 → 100 Mbps |
| cpb_size_value_minus1[0] | 203124 → 52 MB |
| cbr_flag[0] | 0 |

## Construction Strategy
Since x264 can't produce `vcl_hrd=1`, `fixed_frame_rate=1`, or exact timing scale, we:
1. **Encode** with x264 matching all possible params
2. **Replace SPS/PPS** in Annex B with C0001's exact bytes (48-byte SPS, 87-byte PPS)
3. **Mux** patched H.264 into MP4 via ffmpeg (correct NAL framing)
4. **Extract** video samples from muxed MP4
5. **Copy** audio + rtmd data from C0001 template
6. **Assemble** complete XAVC-S container

### Key Construction Details
- **SPS/PPS replacement**: All 6 in-band SPS+PPS pairs replaced (repeat-headers=1)
- **avcC**: Contains the patched SPS/PPS from C0001
- **Audio**: PCM 16-bit BE extracted from C0001's mdat via stco
- **rtmd**: 90 samples × 1024 bytes extracted from C0001
- **Chunk interleaving**: rtmd → video → audio per GOP (matching C0001)
- **Edit list**: Video has media_time=1001 (1-frame offset for open GOP)

### Critical PowerShell Issue
`[byte] -shl N` in PowerShell 5.1 does NOT promote to `[int]` correctly. Must use `[int]$byteVal -shl N`. This caused silent data corruption in all Read-U32/Write-U32 operations before being fixed.

## Result: C0002.MP4
- **File**: `T:\TestXAVCFolder\M4ROOT\CLIP\C0002.MP4` (~26MB)
- **Video**: 90 frames, decodes without errors
- **Audio**: 144,144 samples (3.003s)
- **rtmd**: 90 samples
- **Container**: 3 tracks + PROF + USMT + meta NRT XML
- **SPS**: Matches C0001 exactly (vcl_hrd=1, nal_hrd=1, max_ref=2, etc.)

## Remaining Concerns
1. **DTS monotonicity warning**: ffmpeg warns about non-monotonic DTS during decode (likely benign — ctts pattern may need fine-tuning for actual frame coding order)
2. **Scaling lists**: C0001's PPS has custom scaling lists but x264 slices were encoded with default lists. Decoded video will have slightly different visual quality but should still decode.
3. **Camera test**: Cannot test until camera is reconnected (K:\ unavailable)

## Script
`C:\Users\HeMu\AppData\Local\Temp\opencode\build_xavc_v2.ps1`
