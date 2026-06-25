/*
 * xavc_rebuild.c - Rebuild XAVC-S MP4 from re-encoded base + original template
 *
 * Usage: xavc_rebuild <base.mp4> <template.mp4> <output.mp4>
 *
 * base.mp4:     ffmpeg output with re-encoded video + copied audio (2 tracks)
 * template.mp4: original XAVC-S clip (source of ftyp, PROF, rtmd, meta XML)
 *
 * Output: complete XAVC-S file with 3 tracks (video + audio + rtmd)
 *         mdat layout: [base video+audio data] [rtmd data from template]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

static void die(const char *msg) { fprintf(stderr, "FATAL: %s\n", msg); exit(1); }

/* ---- Endian ---- */
static uint32_t r32(const uint8_t *p) { return ((uint32_t)p[0]<<24)|(p[1]<<16)|(p[2]<<8)|p[3]; }
static uint64_t r64(const uint8_t *p) { return ((uint64_t)r32(p)<<32)|r32(p+4); }
static void w32(uint8_t *p, uint32_t v) { p[0]=v>>24; p[1]=v>>16; p[2]=v>>8; p[3]=v; }

/* ---- Growable buffer ---- */
typedef struct { uint8_t *d; size_t sz, cp; } Buf;
static void buf_need(Buf *b, size_t extra) {
    if (b->sz + extra <= b->cp) return;
    size_t nc = b->cp ? b->cp : 65536;
    while (nc < b->sz + extra) nc *= 2;
    b->d = realloc(b->d, nc); if (!b->d) die("oom");
    b->cp = nc;
}
static void ba(Buf *b, const void *s, size_t n) { buf_need(b, n); memcpy(b->d+b->sz, s, n); b->sz += n; }
static void b_u32(Buf *b, uint32_t v) { uint8_t t[4]; w32(t, v); ba(b, t, 4); }
static void b_u16(Buf *b, uint16_t v) { uint8_t t[2] = {v>>8, v}; ba(b, t, 2); }
static void b_box(Buf *b, const char *type, const void *data, size_t len) { b_u32(b, 8+len); ba(b, type, 4); ba(b, data, len); }
static void b_zero(Buf *b, size_t n) { buf_need(b, n); memset(b->d+b->sz, 0, n); b->sz += n; }
static void b_box_buf(Buf *p, const char *type, Buf *c) {
    b_u32(p, 8 + c->sz); ba(p, type, 4); ba(p, c->d, c->sz); c->sz = 0;
}
static void b_fbox_buf(Buf *p, const char *type, uint32_t vf, Buf *c) {
    b_u32(p, 12 + c->sz); ba(p, type, 4); b_u32(p, vf); ba(p, c->d, c->sz); c->sz = 0;
}

/* ---- Box navigation ---- */
static uint64_t box_sz(const uint8_t *d, size_t p, size_t end) {
    uint32_t s = r32(d + p);
    if (s == 1) return (p + 8 + 8 <= end) ? r64(d + p + 8) : (uint64_t)(end - p);
    if (s == 0) return end - p;
    return s;
}
static int is_type(const uint8_t *d, size_t p, const char *t) { return memcmp(d+p+4, t, 4) == 0; }
static long find_box(const uint8_t *d, size_t start, size_t end, const char *t) {
    size_t p = start;
    while (p + 8 <= end) {
        uint64_t s = box_sz(d, p, end);
        if (s < 8) return -1;
        if (is_type(d, p, t)) return (long)p;
        p += s;
    }
    return -1;
}
static size_t box_hdr(const uint8_t *d, size_t p) { return (r32(d+p) == 1) ? 16 : 8; }

/* ---- File I/O ---- */
static uint8_t *read_file(const char *path, size_t *out) {
    FILE *f = fopen(path, "rb"); if (!f) die("cannot open input");
    fseek(f, 0, SEEK_END); long sz = ftell(f); fseek(f, 0, SEEK_SET);
    uint8_t *buf = malloc(sz); if (!buf) die("oom");
    if (fread(buf, 1, sz, f) != (size_t)sz) die("read");
    fclose(f); *out = sz; return buf;
}

/* ---- Track parser ---- */
typedef struct {
    char hdlr[5];
    uint32_t track_id;
    /* sample table payloads (after fullbox header) */
    const uint8_t *stts, *ctts, *stsc, *stsz, *stss;
    size_t stts_l, ctts_l, stsc_l, stsz_l, stss_l;
    /* stco */
    long stco_pos;     /* box position in file */
    uint32_t stco_cnt;
    /* stsd entry */
    const uint8_t *stsd_entry; size_t stsd_entry_l;
    /* avcC (video only) */
    const uint8_t *avcc; size_t avcc_l;
    /* mdhd raw (after fullbox v+f) */
    const uint8_t *mdhd; size_t mdhd_l;
    /* mdhd timescale */
    uint32_t mdhd_ts;
    /* mdhd duration */
    uint32_t mdhd_dur;
    /* video dimensions */
    uint16_t width, height;
    /* audio params */
    uint16_t channels, sample_size;
    uint32_t sample_rate; /* 16.16 fixed */
} Trak;

typedef struct {
    const uint8_t *d; size_t sz;
    long moov_pos, mdat_pos, mvhd_pos;
    uint64_t moov_sz, mdat_sz;
    size_t mdat_pl;  /* mdat payload start */
    uint32_t mvhd_ts; /* movie timescale */
    uint32_t mvhd_dur;
    Trak traks[8]; int ntrak;
} MP4;

static void parse_mp4(const uint8_t *d, size_t sz, MP4 *m) {
    memset(m, 0, sizeof(*m)); m->d = d; m->sz = sz;
    size_t p = 0;
    while (p + 8 <= sz) {
        uint64_t s = box_sz(d, p, sz);
        if (s < 8) break;
        if (is_type(d, p, "moov")) { m->moov_pos = p; m->moov_sz = s; }
        if (is_type(d, p, "mdat")) {
            m->mdat_pos = p; m->mdat_sz = s;
            m->mdat_pl = p + box_hdr(d, p);
        }
        p += s;
    }
    /* mvhd */
    long mvhd = find_box(d, m->moov_pos+8, m->moov_pos+m->moov_sz, "mvhd");
    m->mvhd_pos = mvhd;
    if (mvhd >= 0) {
        size_t h = box_hdr(d, mvhd);
        m->mvhd_ts = r32(d + mvhd + h + 12);
        m->mvhd_dur = r32(d + mvhd + h + 16);
    }
    /* traks */
    p = m->moov_pos + 8;
    size_t me = m->moov_pos + m->moov_sz;
    while (p + 8 <= me && m->ntrak < 8) {
        uint64_t s = box_sz(d, p, me);
        if (s < 8) break;
        if (is_type(d, p, "trak")) {
            Trak *t = &m->traks[m->ntrak++];
            size_t te = p + s;
            long tkhd = find_box(d, p+8, te, "tkhd");
            if (tkhd >= 0) {
                size_t th = box_hdr(d, tkhd);
                t->track_id = r32(d + tkhd + th + 12);
            }
            long mdia = find_box(d, p+8, te, "mdia");
            if (mdia >= 0) {
                size_t me2 = mdia + box_sz(d, mdia, te);
                long hdlr = find_box(d, mdia+8, me2, "hdlr");
                if (hdlr >= 0) { memcpy(t->hdlr, d+hdlr+box_hdr(d,hdlr)+8, 4); t->hdlr[4]=0; }
                long mdhd = find_box(d, mdia+8, me2, "mdhd");
                if (mdhd >= 0) {
                    size_t mh = box_hdr(d, mdhd);
                    t->mdhd = d + mdhd + mh;
                    t->mdhd_l = box_sz(d, mdhd, me2) - mh;
                    t->mdhd_ts = r32(t->mdhd + 12);
                    t->mdhd_dur = r32(t->mdhd + 16);
                }
                long minf = find_box(d, mdia+8, me2, "minf");
                if (minf >= 0) {
                    size_t me3 = minf + box_sz(d, minf, me2);
                    long stbl = find_box(d, minf+8, me3, "stbl");
                    if (stbl >= 0) {
                        size_t me4 = stbl + box_sz(d, stbl, me3);
                        long stsd = find_box(d, stbl+8, me4, "stsd");
                        long stts = find_box(d, stbl+8, me4, "stts");
                        long ctts = find_box(d, stbl+8, me4, "ctts");
                        long stsc = find_box(d, stbl+8, me4, "stsc");
                        long stsz = find_box(d, stbl+8, me4, "stsz");
                        long stss = find_box(d, stbl+8, me4, "stss");
                        t->stco_pos = find_box(d, stbl+8, me4, "stco");
                        if (stts >= 0) { size_t h=box_hdr(d,stts); t->stts=d+stts+h; t->stts_l=box_sz(d,stts,me4)-h; }
                        if (ctts >= 0) { size_t h=box_hdr(d,ctts); t->ctts=d+ctts+h; t->ctts_l=box_sz(d,ctts,me4)-h; }
                        if (stsc >= 0) { size_t h=box_hdr(d,stsc); t->stsc=d+stsc+h; t->stsc_l=box_sz(d,stsc,me4)-h; }
                        if (stsz >= 0) { size_t h=box_hdr(d,stsz); t->stsz=d+stsz+h; t->stsz_l=box_sz(d,stsz,me4)-h; }
                        if (stss >= 0) { size_t h=box_hdr(d,stss); t->stss=d+stss+h; t->stss_l=box_sz(d,stss,me4)-h; }
                        if (t->stco_pos >= 0) {
                            size_t h = box_hdr(d, t->stco_pos);
                            t->stco_cnt = r32(d + t->stco_pos + h + 4);
                        }
                        if (stsd >= 0) {
                            size_t h = box_hdr(d, stsd);
                            size_t se = stsd + box_sz(d, stsd, me4);
                            size_t ep = stsd + h + 8; /* skip header + vf + entry_count */
                            if (ep + 8 <= se) {
                                uint32_t esz = r32(d + ep);
                                t->stsd_entry = d + ep;
                                t->stsd_entry_l = esz;
                                /* extract avcC and dimensions for video */
                                if (strcmp(t->hdlr, "vide") == 0) {
                                    t->width = r32(d+ep+32) >> 16;
                                    t->height = r32(d+ep+34) >> 16;
                                    long avcc = find_box(d, ep+86, ep+esz, "avcC");
                                    if (avcc >= 0) {
                                        size_t ah = box_hdr(d, avcc);
                                        t->avcc = d + avcc + ah;
                                        t->avcc_l = box_sz(d, avcc, ep+esz) - ah;
                                    }
                                } else if (strcmp(t->hdlr, "soun") == 0) {
                                    t->channels = r32(d+ep+24) >> 16;
                                    t->sample_size = r32(d+ep+26) >> 16;
                                    t->sample_rate = r32(d+ep+32);
                                }
                            }
                        }
                    }
                }
            }
        }
        p += s;
    }
    fprintf(stderr, "Parsed %d tracks, mvhd ts=%u dur=%u\n", m->ntrak, m->mvhd_ts, m->mvhd_dur);
    for (int i = 0; i < m->ntrak; i++)
        fprintf(stderr, "  trak %d: id=%u hdlr=%s stco=%u w=%u h=%u avcc=%zu ch=%u ss=%u\n",
            i, m->traks[i].track_id, m->traks[i].hdlr, m->traks[i].stco_cnt,
            m->traks[i].width, m->traks[i].height, m->traks[i].avcc_l,
            m->traks[i].channels, m->traks[i].sample_size);
}

/* ---- USMT uuid ---- */
static const uint8_t USMT_UUID[16] = {
    0x55,0x53,0x4D,0x54,0x21,0xD2,0x4F,0xCE,
    0xBB,0x88,0x69,0x5C,0xFA,0xC9,0xC7,0x40
};
static const uint8_t MTDT_DATA[20] = {
    0x00,0x01,0x00,0x12,0x00,0x00,0x00,0x0A,
    0x55,0xC4,0x00,0x00,0x00,0x00,0x00,0x01,
    0x00,0x00,0x00,0x00
};
static void build_usmt(Buf *out) {
    Buf mtdt = {0}, inner = {0};
    b_u32(&mtdt, 8+20); ba(&mtdt, "MTDT", 4); ba(&mtdt, MTDT_DATA, 20);
    b_u32(&inner, 8+16+mtdt.sz); ba(&inner, "uuid", 4); ba(&inner, USMT_UUID, 16); ba(&inner, mtdt.d, mtdt.sz);
    ba(out, inner.d, inner.sz);
    free(mtdt.d); free(inner.d);
}

/* ---- dinf/dref ---- */
static void build_dinf(Buf *out) {
    Buf dref_pl = {0}, url = {0};
    b_u32(&url, 12); ba(&url, "url ", 4); b_u32(&url, 1);
    b_u32(&dref_pl, 1); ba(&dref_pl, url.d, url.sz);
    Buf dref = {0}; b_fbox_buf(&dref, "dref", 0, &dref_pl);
    b_box_buf(out, "dinf", &dref);
    free(url.d); free(dref_pl.d);
}

/* ---- Identity matrix ---- */
static const uint8_t MATRIX[36] = {
    0x00,0x01,0x00,0x00, 0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00, 0x00,0x01,0x00,0x00, 0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x40,0x00,0x00,0x00
};

/* ---- tkhd ---- */
static void build_tkhd(Buf *out, uint32_t tid, uint32_t dur, int has_vol, uint32_t w, uint32_t h) {
    Buf b = {0};
    b_u32(&b, 0xE660FD82); /* creation */
    b_u32(&b, 0xE660FD82); /* modification */
    b_u32(&b, tid);
    b_u32(&b, 0);          /* reserved */
    b_u32(&b, dur);
    b_zero(&b, 8);         /* reserved */
    b_u16(&b, 0);          /* layer */
    b_u16(&b, 0);          /* alt group */
    b_u16(&b, has_vol ? 0x0100 : 0);
    b_u16(&b, 0);          /* reserved */
    ba(&b, MATRIX, 36);
    b_u32(&b, w);          /* width 16.16 */
    b_u32(&b, h);          /* height 16.16 */
    b_fbox_buf(out, "tkhd", 7, &b);
}

/* ---- edts/elst ---- */
static void build_edts(Buf *out, uint32_t seg_dur, int32_t media_time) {
    Buf elst = {0};
    b_u32(&elst, 1);
    b_u32(&elst, seg_dur);
    b_u32(&elst, (uint32_t)media_time);
    b_u32(&elst, 0x00010000);
    Buf elst_box = {0}; b_fbox_buf(&elst_box, "elst", 0, &elst);
    b_box_buf(out, "edts", &elst_box);
    free(elst.d);
}

/* ---- hdlr ---- */
static void build_hdlr(Buf *out, const char *type, const char *name) {
    Buf b = {0};
    b_u32(&b, 0); ba(&b, type, 4); b_zero(&b, 12); ba(&b, name, strlen(name)+1);
    b_fbox_buf(out, "hdlr", 0, &b);
}

/* ---- stco with delta shift ---- */
static void emit_stco_delta(Buf *out, const MP4 *m, const Trak *t, int64_t delta) {
    if (t->stco_pos < 0) return;
    Buf pl = {0};
    uint32_t cnt = t->stco_cnt;
    b_u32(&pl, cnt);
    size_t h = box_hdr(m->d, t->stco_pos);
    for (uint32_t i = 0; i < cnt; i++)
        b_u32(&pl, r32(m->d + t->stco_pos + h + 8 + i*4) + (uint32_t)delta);
    b_fbox_buf(out, "stco", 0, &pl);
}

/* ---- Copy raw sample table (payload already includes v+f) ---- */
static void emit_raw(Buf *out, const char *type, const uint8_t *raw, size_t len) {
    if (!raw || !len) return;
    b_box(out, type, raw, len);
}

/* ---- Video stsd (avc1 + avcC) ---- */
static void emit_video_stsd(Buf *out, const Trak *t) {
    Buf entry = {0};
    b_zero(&entry, 6); b_u16(&entry, 1);   /* reserved + dref_idx */
    b_u16(&entry, 0); b_u16(&entry, 0);    /* version + revision */
    b_u32(&entry, 0);                       /* vendor */
    b_u32(&entry, 0); b_u32(&entry, 0);    /* temporal + spatial quality */
    b_u16(&entry, t->width); b_u16(&entry, t->height);
    b_u32(&entry, 0x00480000); b_u32(&entry, 0x00480000); /* h/v res */
    b_u32(&entry, 0);                       /* data size */
    b_u16(&entry, 1);                       /* frame count */
    uint8_t cn[32] = {0}; cn[0]=10; memcpy(cn+1, "AVC Coding", 10);
    ba(&entry, cn, 32);
    b_u16(&entry, 24); b_u16(&entry, 0xFFFF); /* depth + color_table */
    if (t->avcc && t->avcc_l) {
        b_u32(&entry, 8 + t->avcc_l); ba(&entry, "avcC", 4); ba(&entry, t->avcc, t->avcc_l);
    }
    Buf stsd_pl = {0};
    b_u32(&stsd_pl, 1);
    b_u32(&stsd_pl, 8 + entry.sz); ba(&stsd_pl, "avc1", 4); ba(&stsd_pl, entry.d, entry.sz);
    b_fbox_buf(out, "stsd", 0, &stsd_pl);
    free(entry.d); free(stsd_pl.d);
}

/* ---- Audio stsd (twos) ---- */
static void emit_audio_stsd(Buf *out, const Trak *t) {
    Buf entry = {0};
    b_zero(&entry, 6); b_u16(&entry, 1);
    b_u16(&entry, 0); b_u16(&entry, 0); b_u32(&entry, 0);
    b_u16(&entry, t->channels);
    b_u16(&entry, t->sample_size);
    b_u16(&entry, 0); b_u16(&entry, 0);
    b_u32(&entry, t->sample_rate);
    Buf twos_box = {0};
    b_u32(&twos_box, 8+entry.sz); ba(&twos_box, "twos", 4); ba(&twos_box, entry.d, entry.sz);
    Buf stsd_pl = {0};
    b_u32(&stsd_pl, 1); ba(&stsd_pl, twos_box.d, twos_box.sz);
    b_fbox_buf(out, "stsd", 0, &stsd_pl);
    free(entry.d); free(twos_box.d); free(stsd_pl.d);
}

/* ---- rtmd stsd ---- */
static void emit_rtmd_stsd(Buf *out) {
    Buf e = {0};
    b_u32(&e, 16); ba(&e, "rtmd", 4); b_zero(&e, 6); b_u16(&e, 1);
    Buf pl = {0}; b_u32(&pl, 1); ba(&pl, e.d, e.sz);
    b_fbox_buf(out, "stsd", 0, &pl);
    free(e.d); free(pl.d);
}

int main(int argc, char **argv) {
    if (argc < 4) { fprintf(stderr, "Usage: %s <base.mp4> <template.mp4> <output.mp4> [avcc_src.mp4]\n", argv[0]); return 1; }
    size_t base_sz, tpl_sz;
    uint8_t *base = read_file(argv[1], &base_sz);
    uint8_t *tpl  = read_file(argv[2], &tpl_sz);
    MP4 bm, tm;
    parse_mp4(base, base_sz, &bm);
    parse_mp4(tpl, tpl_sz, &tm);

    /* Optional: read avcC from a different source (e.g. C6359 for correct XAVC-S SPS/PPS) */
    const uint8_t *override_avcc = NULL; size_t override_avcc_l = 0;
    if (argc >= 5) {
        size_t as_sz; uint8_t *as_buf = read_file(argv[4], &as_sz);
        MP4 am; parse_mp4(as_buf, as_sz, &am);
        for (int i = 0; i < am.ntrak; i++) {
            if (!strcmp(am.traks[i].hdlr, "vide") && am.traks[i].avcc_l > 0) {
                override_avcc = am.traks[i].avcc;
                override_avcc_l = am.traks[i].avcc_l;
                fprintf(stderr, "Using avcC from %s (%zu bytes)\n", argv[4], override_avcc_l);
                break;
            }
        }
        if (!override_avcc) fprintf(stderr, "WARNING: no video avcC in %s, using base\n", argv[4]);
        /* don't free as_buf — override_avcc points into it */
    }

    /* Find tracks */
    Trak *bv=NULL, *aud=NULL;
    Trak *tv=NULL, *ta=NULL, *tr=NULL;
    for (int i = 0; i < bm.ntrak; i++) {
        if (!bv && !strcmp(bm.traks[i].hdlr, "vide")) bv = &bm.traks[i];
        if (!aud && !strcmp(bm.traks[i].hdlr, "soun")) aud = &bm.traks[i];
    }
    for (int i = 0; i < tm.ntrak; i++) {
        if (!tv && !strcmp(tm.traks[i].hdlr, "vide")) tv = &tm.traks[i];
        if (!ta && !strcmp(tm.traks[i].hdlr, "soun")) ta = &tm.traks[i];
        if (!tr && !strcmp(tm.traks[i].hdlr, "meta")) tr = &tm.traks[i];
    }
    if (!bv) die("no video in base");
    if (!aud) die("no audio in base");
    if (!tr) die("no rtmd(meta) in template");

    /* Override avcC if requested */
    if (override_avcc) { bv->avcc = override_avcc; bv->avcc_l = override_avcc_l; }

    /* Template ftyp + PROF */
    size_t ftyp_sz = box_sz(tpl, 0, tpl_sz);
    long prof_pos = ftyp_sz;
    if (!is_type(tpl, prof_pos, "uuid")) die("no PROF after ftyp");
    size_t prof_sz = box_sz(tpl, prof_pos, tpl_sz);
    size_t new_hdr = ftyp_sz + prof_sz;

    /* Base header size (ftyp + any free) */
    size_t old_hdr = 0;
    while (old_hdr + 8 <= base_sz) {
        uint64_t s = box_sz(base, old_hdr, base_sz);
        if (s < 8) break;
        if (is_type(base, old_hdr, "ftyp") || is_type(base, old_hdr, "free") || is_type(base, old_hdr, "skip"))
            old_hdr += s;
        else break;
    }
    /* Delta: new mdat payload start - base mdat payload start */
    int64_t delta = (int64_t)(new_hdr + 8) - (int64_t)bm.mdat_pl;
    fprintf(stderr, "stco delta: %lld\n", (long long)delta);

    /* Extract base mdat payload (video+audio interleaved) */
    size_t base_mdat_sz = bm.mdat_sz - (bm.mdat_pl - bm.mdat_pos);

    /* Extract rtmd data from template */
    Buf rtmd_data = {0};
    if (tr->stco_pos >= 0) {
        size_t th = box_hdr(tpl, tr->stco_pos);
        uint32_t cnt = tr->stco_cnt;
        /* For each chunk, read samples using stsc + stsz */
        /* Simplified: read stsz to get sample sizes, then read sequentially per chunk */
        /* Even simpler: for each stco entry, read a block of data */
        /* We need the chunk sizes from stsc + stsz */
        /* stsc payload (after v+f): entry_count, then entries of (first_chunk, spc, sdi) */
        /* stsz payload: sample_size(4), count(4), [sizes if uniform=0] */
        uint32_t uniform_size = r32(tr->stsz + 4);
        uint32_t total_samples = r32(tr->stsz + 8);

        /* Parse stsc to get samples-per-chunk for each chunk */
        uint32_t stsc_cnt = r32(tr->stsc + 4);
        struct { uint32_t first, spc; } stsc_entries[64];
        int n_stsc = 0;
        for (uint32_t i = 0; i < stsc_cnt && i < 64; i++) {
            stsc_entries[n_stsc].first = r32(tr->stsc + 8 + i*12);
            stsc_entries[n_stsc].spc = r32(tr->stsc + 8 + i*12 + 4);
            n_stsc++;
        }

        for (uint32_t ch = 0; ch < cnt; ch++) {
            uint32_t chunk_no = ch + 1;
            uint32_t spc = stsc_entries[n_stsc-1].spc;
            for (int e = 0; e < n_stsc; e++) {
                if (stsc_entries[e].first <= chunk_no)
                    spc = stsc_entries[e].spc;
            }
            uint32_t off = r32(tpl + tr->stco_pos + th + 4 + ch * 4);
            size_t chunk_sz;
            if (uniform_size > 0)
                chunk_sz = (size_t)spc * uniform_size;
            else {
                /* variable sizes - need to sum up. For simplicity, read spc*avg */
                chunk_sz = (size_t)spc * 1024; /* fallback */
            }
            if (off + chunk_sz <= tpl_sz)
                ba(&rtmd_data, tpl + off, chunk_sz);
        }
        fprintf(stderr, "rtmd: %u samples, %u chunks, %zu bytes\n", total_samples, cnt, rtmd_data.sz);
    }

    /* rtmd layout in output: appended after base mdat data */
    size_t rtmd_mdat_start = new_hdr + 8 + base_mdat_sz;

    /* ===== ASSEMBLE OUTPUT ===== */
    Buf out = {0};
    /* ftyp + PROF */
    ba(&out, tpl, ftyp_sz);
    ba(&out, tpl + prof_pos, prof_sz);

    /* mdat */
    b_u32(&out, 8 + base_mdat_sz + rtmd_data.sz);
    ba(&out, "mdat", 4);
    ba(&out, base + bm.mdat_pl, base_mdat_sz);
    ba(&out, rtmd_data.d, rtmd_data.sz);

    /* ===== MOOV ===== */
    Buf moov = {0};

    /* mvhd from base */
    {
        size_t h = box_hdr(base, bm.mvhd_pos);
        size_t s = box_sz(base, bm.mvhd_pos, base_sz);
        Buf b = {0}; ba(&b, base + bm.mvhd_pos + h, s - h);
        if (b.sz >= 96) w32(b.d + 92, 4); /* next_track_id */
        b_box_buf(&moov, "mvhd", &b);
        free(b.d);
    }

    uint32_t movie_dur = bm.mvhd_dur;
    /* ---- Video trak ---- */
    {
        Buf stbl = {0}, minf = {0}, mdia = {0}, trak = {0};
        emit_video_stsd(&stbl, bv);
        emit_raw(&stbl, "stts", bv->stts, bv->stts_l);
        emit_raw(&stbl, "ctts", bv->ctts, bv->ctts_l);
        emit_raw(&stbl, "stsc", bv->stsc, bv->stsc_l);
        emit_raw(&stbl, "stsz", bv->stsz, bv->stsz_l);
        emit_stco_delta(&stbl, &bm, bv, delta);
        emit_raw(&stbl, "stss", bv->stss, bv->stss_l);

        Buf vmhd = {0}; b_u32(&vmhd, 20); ba(&vmhd, "vmhd", 4); b_u32(&vmhd, 1); b_zero(&vmhd, 8);
        ba(&minf, vmhd.d, vmhd.sz); free(vmhd.d);
        build_dinf(&minf);
        b_box_buf(&minf, "stbl", &stbl);

        b_box(&mdia, "mdhd", bv->mdhd, bv->mdhd_l);
        build_hdlr(&mdia, "vide", "Video Media Handler");
        b_box_buf(&mdia, "minf", &minf);

        build_tkhd(&trak, 1, movie_dur, 0, ((uint32_t)bv->width)<<16, ((uint32_t)bv->height)<<16);
        build_edts(&trak, movie_dur, 1001);
        b_box_buf(&trak, "mdia", &mdia);
        build_usmt(&trak);
        b_box_buf(&moov, "trak", &trak);
    }

    /* ---- Audio trak ---- */
    {
        Buf stbl = {0}, minf = {0}, mdia = {0}, trak = {0};
        emit_audio_stsd(&stbl, aud);
        emit_raw(&stbl, "stts", aud->stts, aud->stts_l);
        emit_raw(&stbl, "stsc", aud->stsc, aud->stsc_l);
        emit_raw(&stbl, "stsz", aud->stsz, aud->stsz_l);
        emit_stco_delta(&stbl, &bm, aud, delta);

        Buf smhd = {0}; b_u32(&smhd, 16); ba(&smhd, "smhd", 4); b_u32(&smhd, 0); b_zero(&smhd, 4);
        ba(&minf, smhd.d, smhd.sz); free(smhd.d);
        build_dinf(&minf);
        b_box_buf(&minf, "stbl", &stbl);

        b_box(&mdia, "mdhd", aud->mdhd, aud->mdhd_l);
        build_hdlr(&mdia, "soun", "Sound Media Handler");
        b_box_buf(&mdia, "minf", &minf);

        build_tkhd(&trak, 2, movie_dur, 1, 0, 0);
        build_edts(&trak, movie_dur, 0);
        b_box_buf(&trak, "mdia", &mdia);
        build_usmt(&trak);
        b_box_buf(&moov, "trak", &trak);
    }

    /* ---- rtmd trak ---- */
    {
        Buf stbl = {0}, minf = {0}, mdia = {0}, trak = {0};

        emit_rtmd_stsd(&stbl);

        /* rtmd stts: use template's */
        if (tr->stts && tr->stts_l) {
            Buf stts_box = {0}; b_u32(&stts_box, 8+tr->stts_l); ba(&stts_box, "stts", 4); ba(&stts_box, tr->stts, tr->stts_l);
            ba(&stbl, stts_box.d, stts_box.sz); free(stts_box.d);
        }

        /* rtmd stsc: 1 entry, all samples in 1 chunk */
        uint32_t rtmd_samples = tr->stsz ? r32(tr->stsz + 8) : 0;
        uint32_t rtmd_ssize = tr->stsz ? r32(tr->stsz + 4) : 1024;
        {
            Buf pl = {0};
            b_u32(&pl, 1); b_u32(&pl, 1); b_u32(&pl, rtmd_samples); b_u32(&pl, 1);
            b_fbox_buf(&stbl, "stsc", 0, &pl);
        }
        /* rtmd stsz */
        {
            Buf pl = {0};
            b_u32(&pl, rtmd_ssize); b_u32(&pl, rtmd_samples);
            b_fbox_buf(&stbl, "stsz", 0, &pl);
        }
        /* rtmd stco: 1 chunk */
        {
            Buf pl = {0};
            b_u32(&pl, 1);
            b_u32(&pl, (uint32_t)rtmd_mdat_start);
            b_fbox_buf(&stbl, "stco", 0, &pl);
        }

        Buf nmhd = {0}; b_u32(&nmhd, 12); ba(&nmhd, "nmhd", 4); b_u32(&nmhd, 0);
        ba(&minf, nmhd.d, nmhd.sz); free(nmhd.d);
        build_dinf(&minf);
        b_box_buf(&minf, "stbl", &stbl);

        /* rtmd mdhd: use template's timescale */
        Buf mdhd_pl = {0};
        b_u32(&mdhd_pl, 0xE660FD82); b_u32(&mdhd_pl, 0xE660FD82);
        b_u32(&mdhd_pl, tr->mdhd_ts);
        b_u32(&mdhd_pl, tr->mdhd_dur);
        b_u16(&mdhd_pl, 0x55C4); b_u16(&mdhd_pl, 0);
        b_fbox_buf(&mdia, "mdhd", 0, &mdhd_pl);
        build_hdlr(&mdia, "meta", "Timed Metadata Media Handler");
        b_box_buf(&mdia, "minf", &minf);

        build_tkhd(&trak, 3, movie_dur, 0, 0, 0);

        /* tref �?video track 1 */
        Buf cdsc = {0}; b_u32(&cdsc, 4); ba(&cdsc, "cdsc", 4); b_u32(&cdsc, 1);
        ba(&trak, cdsc.d, cdsc.sz); free(cdsc.d);

        build_edts(&trak, movie_dur, 0);
        b_box_buf(&trak, "mdia", &mdia);
        build_usmt(&trak);
        b_box_buf(&moov, "trak", &trak);
    }

    /* ---- meta from template ---- */
    {
        long meta = find_box(tpl, tm.moov_pos+8, tm.moov_pos+tm.moov_sz, "meta");
        if (meta >= 0) {
            size_t ms = box_sz(tpl, meta, tpl_sz);
            ba(&moov, tpl + meta, ms);
        }
    }

    b_box_buf(&out, "moov", &moov);

    /* Write */
    FILE *f = fopen(argv[3], "wb");
    if (!f) die("cannot create output");
    if (fwrite(out.d, 1, out.sz, f) != out.sz) die("write");
    fclose(f);
    fprintf(stderr, "Output: %s (%zu bytes)\n", argv[3], out.sz);

    free(out.d); free(moov.d); free(rtmd_data.d); free(base); free(tpl);
    return 0;
}
