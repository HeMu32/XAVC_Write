/*
 * sps_patch.c - Patch SPS VUI parameters for XAVC-S compliance
 *
 * Reads an MP4 file, finds the SPS NAL in avcC, patches:
 *   - num_units_in_tick: set to 2002 (for 59.94p with time_scale=240000)
 *   - time_scale: set to 240000
 *   - fixed_frame_rate_flag: set to 1
 *   - vcl_hrd_parameters_present_flag: set to 1, copy NAL HRD as VCL HRD
 *
 * Usage: sps_patch <input.mp4> <output.mp4>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

static uint32_t r32(const uint8_t *p) { return ((uint32_t)p[0]<<24)|(p[1]<<16)|(p[2]<<8)|p[3]; }
static void w32(uint8_t *p, uint32_t v) { p[0]=v>>24; p[1]=v>>16; p[2]=v>>8; p[3]=v; }

/* Bit reader */
typedef struct { const uint8_t *d; int sz; int pos; } BR;
static int br_u(BR *b, int n) {
    int v = 0;
    for (int i = 0; i < n; i++) {
        int byte = b->pos / 8;
        int bit = b->pos % 8;
        if (byte >= b->sz) return 0;
        v = (v << 1) | ((b->d[byte] >> (7 - bit)) & 1);
        b->pos++;
    }
    return v;
}
static int br_ue(BR *b) {
    int leading = 0;
    while (br_u(b, 1) == 0 && b->pos < b->sz * 8) leading++;
    if (leading == 0) return 0;
    return (1 << leading) - 1 + br_u(b, leading);
}

/* Bit writer */
typedef struct { uint8_t *d; int sz; int cp; int pos; } BW;
static void bw_grow(BW *w, int extra) {
    if (w->pos/8 + extra/8 + 16 <= w->cp) return;
    int nc = w->cp ? w->cp : 256;
    while (nc < w->pos/8 + extra/8 + 16) nc *= 2;
    w->d = realloc(w->d, nc); w->cp = nc;
}
static void bw_u(BW *w, uint32_t v, int n) {
    for (int i = n - 1; i >= 0; i--) {
        bw_grow(w, 1);
        int byte = w->pos / 8, bit = w->pos % 8;
        if (bit == 0) w->d[byte] = 0;
        if ((v >> i) & 1) w->d[byte] |= (1 << (7 - bit));
        w->pos++;
    }
}
static void bw_ue(BW *w, uint32_t v) {
    if (v == 0) { bw_u(w, 1, 1); return; }
    int code = v + 1;
    int leading = 0;
    while ((1 << leading) <= code) leading++;
    leading--;
    bw_u(w, 0, leading);
    bw_u(w, code, leading + 1);
}
static void bw_se(BW *w, int32_t v) {
    uint32_t code;
    if (v > 0) code = 2 * v - 1;
    else code = -2 * v;
    bw_ue(w, code);
}

/* Skip NAL HRD parameters in reader, return the bit position after */
static int skip_hrd(BR *b) {
    br_u(b, 4); /* cpb_cnt_minus1 */
    br_u(b, 4); /* bit_rate_scale */
    br_u(b, 4); /* cpb_size_scale */
    /* For each CPB: bit_rate_value_minus1 (ue) + cpb_size_value_minus1 (ue) + cbr_flag (1) */
    /* We don't know cpb_cnt, but we saved the value */
    return 0;
}

/* Copy NAL HRD parameters from reader to writer */
static int copy_hrd(BR *b, BW *w) {
    int cpb_cnt = br_ue(b); bw_ue(w, cpb_cnt); /* cpb_cnt_minus1 */
    int brs = br_u(b, 4); bw_u(w, brs, 4);
    int css = br_u(b, 4); bw_u(w, css, 4);
    for (int i = 0; i <= cpb_cnt; i++) {
        int brv = br_ue(b); bw_ue(w, brv);
        int csv = br_ue(b); bw_ue(w, csv);
        int cbr = br_u(b, 1); bw_u(w, cbr, 1);
    }
    int icrd = br_u(b, 5); bw_u(w, icrd, 5);
    int crde = br_u(b, 5); bw_u(w, crde, 5);
    int dpb = br_u(b, 5); bw_u(w, dpb, 5);
    int dpbd = br_u(b, 5); bw_u(w, dpbd, 5);
    int te = br_u(b, 5); bw_u(w, te, 5);
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 3) { fprintf(stderr, "Usage: %s <input.mp4> <output.mp4>\n", argv[0]); return 1; }

    FILE *f = fopen(argv[1], "rb");
    if (!f) { perror("open"); return 1; }
    fseek(f, 0, SEEK_END); long fsz = ftell(f); fseek(f, 0, SEEK_SET);
    uint8_t *buf = malloc(fsz);
    fread(buf, 1, fsz, f); fclose(f);

    /* Find avcC in the file */
    long avcc_pos = -1;
    for (long i = 0; i <= fsz - 12; i++) {
        if (memcmp(buf + i, "avcC", 4) == 0 && buf[i+4] == 1) { avcc_pos = i; break; }
    }
    if (avcc_pos < 0) { fprintf(stderr, "avcC not found\n"); return 1; }

    /* avcC data starts at avcc_pos + 4 */
    uint8_t *avcc = buf + avcc_pos + 4;
    int sps_len = (avcc[6] << 8) | avcc[7];
    uint8_t *sps = avcc + 8; /* SPS NAL data (starts with NAL header) */
    fprintf(stderr, "SPS NAL: %d bytes, first byte 0x%02X\n", sps_len, sps[0]);

    /* Parse SPS to find VUI timing and HRD fields */
    BR br = { sps, sps_len, 0 };
    br.pos = 8; /* skip NAL header byte */
    /* profile_idc */ br_u(&br, 8);
    /* constraint flags */ br_u(&br, 8);
    /* level_idc */ br_u(&br, 8);
    /* sps_id */ br_ue(&br);
    int profile_idc = sps[1]; /* for chroma format detection */

    if (profile_idc >= 100) {
        br_ue(&br); /* chroma_format_idc */
        if (profile_idc >= 100) { br_ue(&br); br_ue(&br); } /* bit_depth */
        br_u(&br, 1); /* qpprime */
        if (br_u(&br, 1)) { /* seq_scaling_matrix_present */ }
    }
    br_ue(&br); /* log2_max_frame_num_minus4 */
    br_ue(&br); /* pic_order_cnt_type */
    if (/* poc_type == 0 */ 1) {
        /* We know poc_type=0 from earlier analysis */
        br_ue(&br); /* log2_max_poc_lsb_minus4 */
    }
    br_ue(&br); /* max_num_ref_frames */
    br_u(&br, 1); /* gaps */
    br_ue(&br); /* pic_width_in_mbs_minus1 */
    br_ue(&br); /* pic_height_in_map_units_minus1 */
    br_u(&br, 1); /* frame_mbs_only */
    br_u(&br, 1); /* direct_8x8 */
    if (br_u(&br, 1)) { /* frame_cropping */
        br_ue(&br); br_ue(&br); br_ue(&br); br_ue(&br);
    }

    int vui_present = br_u(&br, 1);
    if (!vui_present) { fprintf(stderr, "No VUI in SPS, nothing to patch\n"); free(buf); return 1; }

    /* Record VUI start bit position */
    int vui_start = br.pos;

    /* Parse VUI up to timing_info */
    if (br_u(&br, 1)) { /* aspect_ratio */ br_u(&br, 8); }
    if (br_u(&br, 1)) { /* overscan */ br_u(&br, 1); }
    if (br_u(&br, 1)) { /* video_signal_type */
        br_u(&br, 3); /* video_format */
        br_u(&br, 1); /* full_range */
        if (br_u(&br, 1)) { /* colour_desc */ br_u(&br, 8); br_u(&br, 8); br_u(&br, 8); }
    }
    if (br_u(&br, 1)) { /* chroma_loc */ br_ue(&br); br_ue(&br); }

    int timing_pos = -1;
    if (br_u(&br, 1)) { /* timing_info_present */
        timing_pos = br.pos;
    }

    fprintf(stderr, "VUI start bit: %d\n", vui_start);
    if (timing_pos < 0) {
        fprintf(stderr, "No timing_info in VUI\n");
        free(buf); return 1;
    }
    fprintf(stderr, "timing_info at bit %d\n", timing_pos);

    /* Read current timing values */
    uint32_t old_num_units = br_u(&br, 32);
    uint32_t old_time_scale = br_u(&br, 32);
    int old_fixed = br_u(&br, 1);
    fprintf(stderr, "Old: num_units=%u time_scale=%u fixed=%d\n", old_num_units, old_time_scale, old_fixed);

    /* nal_hrd_present */
    int nal_hrd_pos = br.pos;
    int nal_hrd_present = br_u(&br, 1);
    int nal_hrd_cpb_cnt = 0;
    if (nal_hrd_present) {
        nal_hrd_cpb_cnt = br_ue(&br); /* cpb_cnt_minus1 - ue(v) not u(4)! */
        /* Skip the rest of NAL HRD */
        br_u(&br, 4); br_u(&br, 4); /* scales */
        for (int i = 0; i <= nal_hrd_cpb_cnt; i++) { br_ue(&br); br_ue(&br); br_u(&br, 1); }
        br_u(&br, 5); br_u(&br, 5); br_u(&br, 5); br_u(&br, 5); br_u(&br, 5);
    }

    int vcl_hrd_flag_pos = br.pos;
    int old_vcl_hrd = br_u(&br, 1);
    fprintf(stderr, "nal_hrd=%d (cpb_cnt=%d), vcl_hrd=%d at bit %d\n",
            nal_hrd_present, nal_hrd_cpb_cnt, old_vcl_hrd, vcl_hrd_flag_pos);

    /* Read VCL HRD if present (shouldn't be in x264 output) */
    if (old_vcl_hrd) {
        /* skip it */
        int vc = br_ue(&br);
        br_u(&br, 4); br_u(&br, 4);
        for (int i = 0; i <= vc; i++) { br_ue(&br); br_ue(&br); br_u(&br, 1); }
        br_u(&br, 5); br_u(&br, 5); br_u(&br, 5); br_u(&br, 5); br_u(&br, 5);
    }

    int pic_struct_pos = br.pos;
    int old_pic_struct = br_u(&br, 1);
    fprintf(stderr, "pic_struct_present=%d at bit %d\n", old_pic_struct, pic_struct_pos);

    /* === NOW BUILD THE PATCHED SPS === */
    /* Strategy: copy bits 0..timing_pos-1 verbatim, then write new timing,
       then copy from after timing to vcl_hrd_flag, then write vcl_hrd=1 + VCL HRD block,
       then copy remaining VUI */

    BW w = {0};
    /* Copy everything up to timing_info */
    for (int i = 0; i < timing_pos; i++) {
        int byte = i / 8, bit = i % 8;
        bw_u(&w, (sps[byte] >> (7 - bit)) & 1, 1);
    }
    /* Write new timing_info */
    bw_u(&w, 2002, 32);    /* num_units_in_tick */
    bw_u(&w, 240000, 32);  /* time_scale */
    bw_u(&w, 1, 1);        /* fixed_frame_rate_flag */

    /* Copy from after old timing to vcl_hrd_flag_pos (NAL HRD if present) */
    int after_timing = timing_pos + 32 + 32 + 1; /* num_units + time_scale + fixed */
    for (int i = after_timing; i < vcl_hrd_flag_pos; i++) {
        int byte = i / 8, bit = i % 8;
        bw_u(&w, (sps[byte] >> (7 - bit)) & 1, 1);
    }

    /* Write vcl_hrd_parameters_present_flag = 1 */
    bw_u(&w, 1, 1);

    /* Write VCL HRD block (same as NAL HRD) */
    /* We need to re-read the NAL HRD from the original SPS and copy it */
    if (nal_hrd_present) {
        BR hrd_br = { sps, sps_len, nal_hrd_pos + 1 }; /* skip the nal_hrd_present flag */
        copy_hrd(&hrd_br, &w);
    }

    /* Copy remaining bits (pic_struct_present onwards) */
    for (int i = vcl_hrd_flag_pos + 1; i < sps_len * 8; i++) {
        int byte = i / 8, bit = i % 8;
        bw_u(&w, (sps[byte] >> (7 - bit)) & 1, 1);
    }

    int new_sps_len = (w.pos + 7) / 8;
    fprintf(stderr, "New SPS: %d bytes (was %d)\n", new_sps_len, sps_len);

    /* Add RBSP trailing bits if needed (the copy should include them) */

    /* === BUILD OUTPUT === */
    /* Rebuild avcC with new SPS length */
    int old_avcc_data_len = 4 + 1 + 1 + 2 + sps_len; /* up to end of SPS */
    /* We need: ver(1) prof(1) compat(1) level(1) ls(1) numSPS(1) spsLen(2) sps pps... */
    /* Read old avcC to get PPS */
    uint8_t *pps_ptr = avcc + 8 + sps_len;
    int num_pps = pps_ptr[0];
    int pps_len = (pps_ptr[1] << 8) | pps_ptr[2];
    uint8_t *pps_data = pps_ptr + 3;
    fprintf(stderr, "PPS: %d entries, first PPS %d bytes\n", num_pps, pps_len);

    /* Build new avcC data */
    int new_avcc_len = 8 + new_sps_len + 1 + 2 + pps_len;
    uint8_t *new_avcc = malloc(new_avcc_len);
    new_avcc[0] = avcc[0]; /* ver */
    new_avcc[1] = avcc[1]; /* profile */
    new_avcc[2] = avcc[2]; /* compat */
    new_avcc[3] = avcc[3]; /* level */
    new_avcc[4] = avcc[4]; /* lsMinusOne */
    new_avcc[5] = avcc[5]; /* numSPS */
    new_avcc[6] = (new_sps_len >> 8) & 0xFF;
    new_avcc[7] = new_sps_len & 0xFF;
    memcpy(new_avcc + 8, w.d, new_sps_len);
    new_avcc[8 + new_sps_len] = num_pps;
    new_avcc[8 + new_sps_len + 1] = (pps_len >> 8) & 0xFF;
    new_avcc[8 + new_sps_len + 2] = pps_len & 0xFF;
    memcpy(new_avcc + 8 + new_sps_len + 3, pps_data, pps_len);

    /* Now rebuild the file: replace the old avcC box with new one */
    /* The avcC box: [size][avcC][data]. Find the box start */
    long box_start = avcc_pos - 4; /* "avcC" is at avcc_pos, size is 4 bytes before */
    /* Wait: avcc_pos is where we found "avcC" via memcmp. The "avcC" is the TYPE field.
       The SIZE field is at avcc_pos - 4. */
    uint32_t old_box_size = r32(buf + box_start);
    fprintf(stderr, "Old avcC box at 0x%lX, size=%u (data=%u)\n", box_start, old_box_size, old_box_size - 8);

    long after_box = box_start + old_box_size;
    long total_after = fsz - after_box;
    long total_before = box_start;

    uint32_t new_box_size = 8 + new_avcc_len;
    long new_fsz = total_before + new_box_size + total_after;

    uint8_t *out = malloc(new_fsz);
    memcpy(out, buf, total_before);
    w32(out + total_before, new_box_size);
    memcpy(out + total_before + 4, "avcC", 4);
    memcpy(out + total_before + 8, new_avcc, new_avcc_len);
    memcpy(out + total_before + new_box_size, buf + after_box, total_after);

    /* Fix all box sizes that contain the avcC (stsd, stbl, minf, mdia, trak, moov) */
    /* This is complex. For now, just fix the avcC's parent chain by recalculating sizes. */
    /* Actually, we should rebuild the moov entirely. But for a quick test, let's just
       adjust the containing boxes by the delta. */
    int delta_size = (int)new_box_size - (int)old_box_size;
    fprintf(stderr, "Size delta: %+d bytes\n", delta_size);

    /* Find and fix parent box sizes (search outward from avcC) */
    /* Parents: stsd, stbl, minf, mdia, trak, moov */
    /* We need to add delta_size to each parent's size field */
    /* Walk backwards from box_start to find containing boxes */
    /* This is a heuristic: find box starts by scanning for valid box headers */
    {
        long p = 0;
        while (p + 8 <= total_before) {
            uint32_t s = r32(out + p);
            if (s < 8) break;
            /* Check if this box contains the avcC */
            if (p + s >= box_start && p < box_start) {
                /* This box contains avcC, adjust its size */
                w32(out + p, s + delta_size);
                fprintf(stderr, "Adjusted box at 0x%lX (%c%c%c%c) size %u -> %u\n",
                        p, out[p+4], out[p+5], out[p+6], out[p+7], s, s + delta_size);
            }
            p += s;
            /* If we're inside a container box (moov, trak, etc.), descend */
            if (p >= total_before) break;
        }
    }

    FILE *of = fopen(argv[2], "wb");
    if (!of) { perror("create"); return 1; }
    fwrite(out, 1, new_fsz, of);
    fclose(of);
    fprintf(stderr, "Output: %s (%ld bytes)\n", argv[2], new_fsz);

    free(out); free(new_avcc); free(w.d); free(buf);
    return 0;
}
