# Experiment 0006: VUI/HRD/Chroma Bitstream Patching for Sony ILCE-7M4

## Goal
Create a synthetic XAVC-S clip (C6359) playable on the Sony ILCE-7M4 by reverse-engineering the H.264 VUI (Video Usability Information), HRD (Hypothetical Reference Decoder), and chroma QP offset parameters, using binary bitstream patching where x264's encoder options are insufficient.

## Background
Previous experiments (0001-0005) established that the camera checks SPS/VUI parameters beyond what x264 can produce via command-line options alone. Key differences found:
- Camera: `video_full_range_flag=1`, `colour_primaries=2` (unspecified), `nal_hrd=1`, `vcl_hrd=1`, `chroma_qp_index_offset=3`
- x264 output: `video_full_range_flag=0`, `colour_primaries=1` (BT.709), `nal_hrd=0`, `vcl_hrd=0`, `chroma_qp_index_offset=1`

## Key Findings

### 1. Multiple `-x264-params` Override Bug
**Critical finding**: When ffmpeg receives multiple `-x264-params` arguments (e.g., once for fullrange, once for HRD, once for keyint), **only the last one takes effect**, silently discarding all previous params. This caused all VUI/HRD settings from earlier `-x264-params` to be silently ignored in earlier v8 clips.

**Fix**: Combine all x264 params into a single `-x264-params` string with colon separators.

### 2. x264 Internal Param Names vs ffmpeg Native
Several VUI-related x264 internal param names are NOT recognized by this build (git-2025-06-26):
| Invalid param | Error | Correct approach |
|---|---|---|
| `fullrange=1` | Rejected | ffmpeg native `-color_range pc` |
| `colour_primaries=2` | Rejected | ffmpeg native `-color_primaries unspecified` |
| `transfer_characteristics=2` | Rejected | ffmpeg native `-color_trc unspecified` |
| `matrix_coefficients=2` | Rejected | ffmpeg native `-colorspace unspecified` |
| `vcl_hrd=vbr` / `vcl-hrd=vbr` | `Error parsing option` | Not supported by this x264 build |

**Fix**: Use ffmpeg-native options (`-color_primaries`, `-color_trc`, `-colorspace`) for color VUI; use binary SPS patching for `vcl_hrd`.

### 3. `nal-hrd` and `vbv-*` Require Hyphens
x264 internal param names use **hyphens**, not underscores or equal signs:
- `nal_hrd=vbr` → WRONG (underscore). Correct: `nal-hrd=vbr`
- `vbv_maxrate=140000` → WRONG. Correct: `vbv-maxrate=140000`
- `vbv_bufsize=140000` → WRONG. Correct: `vbv-bufsize=140000`

### 4. `chroma_qp_offset` Hardcoded for High422 Profile
x264 source `encoder/set.c` hardcodes `chroma_qp_index_offset = 1` for chroma_format_idc=2 (4:2:2), overriding the user's `chroma_qp_offset` param. Affects both `chroma_qp_index_offset` and `second_chroma_qp_index_offset` in the PPS.

**Fix**: Binary PPS patching required to change 1→3.

### 5. PPS Bitstream Structure (4:2:2, CABAC)
Original 4-byte PPS `EA ED 49 40` bit layout:
```
bit 0:    pps_id SE(0) = 1               (1 bit, UE)
bit 1:    sps_id SE(0) = 1               (1 bit, UE)
bit 2:    entropy_coding_mode_flag = 1
bit 3:    pic_order_present_flag = 0
bit 4:    num_slice_groups SE(0) = 1      (1 bit, UE)
bits 5-7: refs_l0 SE(2) = 010            (3 bits, UE)
bit 8:    refs_l1 SE(1) = 1               (1 bit, UE)
bit 9:    weighted_pred = 1
bits 10-11: weighted_bipred = 10           (2 bits, u(2))
bit 12:   pic_init_qp SE(0) = 1           (1 bit: range +26)
bit 13:   pic_init_qs SE(0) = 1           (1 bit: range +26)
bits 14-16: chroma_qp_index_offset = 010  (3 bits, SE=+1)
bit 17:   deblocking_filter_control = 1
bit 18:   constrained_intra_pred = 0
bit 19:   redundant_pic_cnt = 0
bit 20:   transform_8x8_mode_flag = 1     (x264 writes unconditionally)
bit 21:   pic_scaling_matrix = 0          (no scaling list data)
bits 22-24: second_chroma_qp_offset = 010 (3 bits, SE=+1)
bit 25:   rbsp_stop_bit = 1
bits 26-31: alignment = 000000
```

**Note on transform_8x8**: The H.264 spec makes this conditional on `entropy_coding_mode_flag && pic_order_present_flag` (which is false: 1 && 0 = 0). However, x264 writes it unconditionally for High 4:2:2 profile. The 4 bytes (32 bits) contain NO scaling list data when `pic_scaling_matrix_flag=0`.

### 6. Patched PPS Structure (chroma=3, second_chroma=3)
Patched 4-byte PPS `EA EC D2 34`:
```
bits 0-13:  same as original (14 bits)
bits 14-18: chroma_qp_index_offset = 00110 (5 bits, SE=+3)
bit 19:     deblocking (shifted +2 from original bit 17)
bit 20:     constrained (shifted from bit 18)
bit 21:     redundant (shifted from bit 19)
bit 22:     transform_8x8 (shifted from bit 20)
bit 23:     pic_scaling_matrix (shifted from bit 21)
bits 24-28: second_chroma_qp_offset = 00110 (5 bits, SE=+3)
bit 29:     rbsp_stop_bit = 1
bits 30-31: alignment = 00
```
Same byte count (4 bytes = 32 bits). Both chroma values expanded from 3 to 5 bits, fitting within original trailing alignment.

### 7. Annex B Start Code Detection
The `h264_mp4toannexb` bitstream filter uses:
- **4-byte** start codes (`00 00 00 01`) for the initial SPS/PPS NALs
- **3-byte** start codes (`00 00 01`) for all subsequent NALs (SEI, IDR slices, subsequent SPS/PPS groups)

`Find-Nal-End` must detect both to correctly locate NAL boundaries.

### 8. x264 SE(v) Encoding Convention
x264's signed Exp-Golomb encoding differs from the ITU-T H.264 spec:
- Positive values: codeNum = 2×val − 1 (odd codeNums)
- Non-positive values: codeNum = −2×val (even codeNums)

Example: chroma_qp_index_offset = +1 → codeNum = 2×1−1 = 1 → UE(1) = `01` (2 bits).
This means SE(+1) = `01`, NOT `010` (which would be codeNum=2 = SE(−1)).

## Current Status
- **PPS chroma patching**: Complete and verified. All 6 PPS NALs patched to `EA EC D2 34`. Confirmed via trace_headers on v7 Annex B file.
- **SPS VUI**: `video_full_range_flag=1`, `colour_description_present_flag=1` (BT.709), `nal_hrd_parameters_present_flag=1` all working via ffmpeg-native options + single `-x264-params` string.
- **Remaining SPS VUI**: `vcl_hrd_parameters_present_flag=0` (needs 1). Requires binary SPS patching to append VCL HRD parameter block after existing NAL HRD block.
- **Container**: stsd patching via `fix_twos_stsd.ps1` works (108B→52B, removes pcmC sub-box).
- **Pipeline**: Not yet run end-to-end with all patches applied.

## Todo / Next Steps
1. Add SPS VUI patching for `vcl_hrd_parameters_present_flag=1` + VCL HRD parameter block
2. Update `full_reencode.ps1` with working PPS+SPS patching (fix `Build-Patched-Pps` trailing bits)
3. Run full pipeline: re-encode → build correct → fix_stsd → copy to card
4. Verify with ffprobe/trace_headers on card file
5. Camera test — if still fails, inject NRT/rtmd metadata track

## Tools & Scripts
- `C:\Users\HeMu\AppData\Local\Temp\opencode\full_reencode.ps1`: Full re-encode with SPS+PPS patching
- `C:\Users\HeMu\AppData\Local\Temp\opencode\build_correct.ps1`: Container rebuild
- `C:\Users\HeMu\AppData\Local\Temp\opencode\fix_twos_stsd.ps1`: stsd box patch
- `C:\Users\HeMu\AppData\Local\Temp\opencode\C6359_v7_patched.h264`: All-PPS-patched Annex B stream
