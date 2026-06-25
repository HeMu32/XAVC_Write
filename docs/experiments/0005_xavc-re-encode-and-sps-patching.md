# Experiment 0005: Re-encoding & SPS Patching for Sony ILCE-7M4 Playback

## Goal

Create a synthetic XAVC-S clip (C6359) playable on the Sony ILCE-7M4 by reverse-engineering the camera's 4K H.264 encoding parameters and ensuring every bitstream and container detail matches.

## Background

The camera produces H.264 High 4:2:2 10-bit 4:2:2 at 29.97 fps, 3840×2160, ~142 Mbps. Previous attempts to write a software-encoded clip to the SD card resulted in "无法显示" (cannot display) on the camera, even though the clip played correctly on PC.

## Key Findings

### 1. Camera's H.264 SPS Parameters (from C6358.MP4)

| Parameter | Camera Value | x264 Default |
|-----------|-------------|--------------|
| profile_idc | 122 (High 4:2:2) | 122 (High 4:2:2) |
| chroma_format_idc | 2 (4:2:2) | 2 (4:2:2) |
| bit_depth_luma_minus8 | 2 (10-bit) | 2 (10-bit) |
| bit_depth_chroma_minus8 | 2 (10-bit) | 2 (10-bit) |
| video_full_range_flag | 1 (Full/PC range) | 0 (Limited/TV range) |
| colour_primaries | 2 (unspecified) | 1 (BT.709) |
| transfer_characteristics | 2 (unspecified) | 1 (BT.709) |
| matrix_coefficients | 2 (unspecified) | 1 (BT.709) |
| log2_max_frame_num_minus4 | 0 (max frame num = 16) | matches |
| log2_max_pic_order_cnt_lsb_minus4 | 1 (max POC = 32) | matches |
| **max_num_ref_frames** | **2** | **4** |
| gaps_in_frame_num_allowed_flag | 0 | matches |
| pic_struct_present_flag | 1 | matches |
| fixed_frame_rate_flag | 1 (VUI) | 0 (VUI) |
| entropy_coding_mode | 1 (CABAC) | matches |
| deblocking_filter_control_present_flag | 1 | matches |
| transform_8x8_mode_flag | 1 | matches |
| **max_dec_frame_buffering (VUI)** | **- (not present?)** | **4 (explicitly signaled)** |

### 2. GOP Structure

The camera's GOP pattern (15 frames in display order):
```
Display: B(0), B(1), I(2), B(3), B(4), P(5), B(6), B(7), P(8), B(9), B(10), P(11), B(12), B(13), P(14)
Decode:  I(2), P(5), B(0), B(1), P(8), B(3), B(4), P(11), B(6), B(7), P(14), B(9), B(10), I(17), B(12), B(13), ...
```

This is an **open GOP** pattern: 2 B-frames appear before the IDR in display order, referencing the previous GOP's reference frames. x264's default **closed GOP** produces I at display position 0 (no B-frames before IDR).

### 3. PROF UUID Box

The camera clip contains a `PROF` UUID box (UUID `50524F46-21D2-4FCE-BB88-695C`) right after ftyp, containing 3 tracks (video + audio + NRT/rtmd metadata). The track count must match the actual number of tracks in the MP4 file.

### 4. ftyp Brand

Camera ftyp: `XAVC` v1.11.65535, compatible brands `XAVC`, `mp42`, `iso6`.

## Attempted Fixes

### Attempt 1: Baseline Re-encode (29.97p)

- Video: 3840x2160, yuv422p10le, full range, x264 High 4:2:2@L5.1
- Audio: PCM16BE 48kHz stereo
- GOP: keyint=15, bframes=2, no-scenecut, min-keyint=1
- PROF box copied from camera, track_count adjusted from 3 → 2
- ftyp fixed to XAVC
- **Result**: "无法显示" on camera

### Attempt 2: Patch max_num_ref_frames 4→2 in SPS

**Problem**: x264 refuses to signal max_num_ref_frames < 4 for 10-bit 4:2:2 4K@L5.1, even with `ref=2`. The camera signals 2, which may exceed the decoder's DPB memory budget (theoretical 64 MB limit for 10-bit 4:2:2 at 4K: dpb = 4 × 3840 × 2160 × 2.5 bytes/pixel ≈ 82.8 MB > 64 MB).

**Solution**: Manually patch the H.264 SPS bitstream:
- Find ue(v) `max_num_ref_frames` at SPS bit position 49
- Change code "00101" (5 bits, codeNum=4, value=4) → "011" (3 bits, codeNum=2, value=2)
- This removes 2 bits from the SPS, shifting all subsequent fields
- Must re-insert emulation prevention bytes and update avcC + parent box sizes

**Implementation**: Extract raw Annex B bitstream from MP4, patch SPS NAL(s), remux with ffmpeg.

**Result**: Container-level avcC SPS patched to max_num_ref_frames=2. In-band SPS (sent per GOP) still show 4 because only the first SPS in the stream was patched. File written to card. **Still fails with "无法显示"**.

### Attempt 3: (Planned) Patch All In-Band SPS

**Theory**: The camera decoder may re-read SPS from the bitstream (not just avcC), so ALL SPS NAL units need max_num_ref_frames=2.

**Plan**: Modify the raw patching script to find and patch every SPS NAL in the bitstream.

### Attempt 4: (Planned) Open GOP Re-encode

**Theory**: The camera expects open GOP (B-frames before IDR in display order). x264's closed GOP may cause decode/display order confusion.

**Plan**: Re-encode with `open-gop=1`, `keyint=15` to match the camera's 15-frame display GOP with I at position 2.

### Attempt 3: Patch ALL In-Band SPS (Complete – 2026-06-21)

**Theory**: The camera decoder may re-read SPS from the bitstream (not just avcC), so ALL SPS NAL units need max_num_ref_frames=2.

**Implementation**: 
- Patched all 40 SPS NAL units in the raw Annex B bitstream using in-place byte replacement
- Each SPS is 24 bytes, `max_num_ref_frames` UE(v) field at bit position 49
- Changed code "00101" (5 bits, codeNum=4) → "011" (3 bits, codeNum=2), removing 2 bits from SPS
- Re-inserted emulation prevention bytes; size unchanged (24 bytes → 24 bytes), so in-place patching was used
- All 40 SPS + avcC verified with `trace_headers`: 41 references to `max_num_ref_frames=2`, 0 references to `=4`

**Result**: File written to K:\PRIVATE\M4ROOT\CLIP\C6359.MP4 with audio + PROF box + ftyp. **Still fails with "无法显示"**.

**Key insight**: Even with all SPS containing max_num_ref_frames=2, the camera rejects the clip. Root cause is elsewhere.

## Remaining Differences (Camera C6358 vs Our C6359)

| Aspect | Camera | Our Clip | Impact |
|--------|--------|----------|--------|
| **NRT/rtmd track** | Present (3rd track) | Missing (2 tracks only) | Camera may check for it |
| **Audio FourCC** | `twos` (0x736F7774) | `ipcm` (0x6D637069) | Both PCM16BE, different tag |
| **GOP type** | Open GOP (B,B,I) | Closed GOP (I,B,B) | Different frame reference pattern |
| **video_full_range_flag** | 1 (Full) | 0 (Limited) | x264 default, VUI hint |
| **fixed_frame_rate_flag** | 1 | 0 | VUI timing flag |
| **nal_hrd/vcl_hrd_params** | Present | Absent | Buffer model |
| **colour_primaries etc.** | 2 (unspecified) | 1 (BT.709) | Color metadata |
| **max_dec_frame_buffering** | 4 (same!) | 4 (same after patch) | Not the issue |
| **creation_time** | Set | Missing | Container metadata |
| **file size/duration** | 67 MB / 1.5s / 45 frames | 351 MB / 19.8s / 594 frames | Camera may reject large files |
| **Frame count vs GOP** | 45 = 3×15 | 594 = 39.6×15 (not integer) | Last GOP incomplete |

## Next Investigations (2026-06-21)

Priority order:
1. **Frame count/GOP alignment** – Camera clip is exactly 3 GOPs (45 frames). Test 90 frames (6×15).
2. **Open GOP re-encode** – Re-encode with `open-gop=1` to match camera's B,B,I pattern
3. **Audio FourCC `twos`** – Force `-tag:a twos` in remux
4. **VUI parameter matching** – full range, unspecified colorimetry, HRD params, fixed frame rate
5. **Short clip first** – Test with ~90 frames (3s) to isolate size/duration issues
6. **NRT/rtmd metadata track** – If above all fail, inject rtmd track from camera clip
7. **DATABASE.BIN block trailer** – Last resort

## Key Parameters for Future Re-encodes

```powershell
ffmpeg -y -r 30000/1001 -f rawvideo -pix_fmt yuv422p10le -s 3840x2160 -i pipe:
  -c:v libx264 -preset fast
  -profile:v high422 -pix_fmt yuv422p10le
  -color_range pc -colorspace bt709
  -x264-params "fullrange=1:pic-struct=1:colorprim=undef:transfer=undef:colormatrix=undef"
  -x264-params "keyint=15:min-keyint=1:no-scenecut=1:bframes=2:ref=2:no-deblock=0"
  -x264-params "open-gop=1"
  -b:v 140M -maxrate 140M -bufsize 140M
  -r 30000/1001
```

## Container Modifications

### PROF UUID Box

Extracted from camera clip offset 28..175 (148 bytes):
- UUID: `50524F46-21D2-4FCE-BB88-695C` (ASCII "PROF" + binary UUID)
- Track count at offset 0x1C within the box (0x3C in file): 3 → 2 for our 2-track clip

### ftyp Box

Camera: 28 bytes, brand `XAVC` v1.11.65535, compatible `XAVC`/`mp42`/`iso6`
Our file: 32 bytes (4-byte padding to avoid size mismatch gaps)

## File Sizes

- Camera clip (C6358.MP4): ~67 MB (varies)
- Our re-encoded clip (C6359.MP4): ~351 MB (higher bitrate ~142 Mbps)
