/*
 * deblock_inject.c - Inject deblocking filter parameters into H.264 slice headers
 *
 * Reads an XAVC-S MP4, finds all video slice NALs in mdat, inserts
 *   disable_deblocking_filter_idc=0 (ue: "1")
 *   slice_alpha_c0_offset_div2=0  (se: "1")
 *   slice_beta_offset_div2=0      (se: "1")
 * into each slice header (between dec_ref_pic_marking and slice_qp_delta),
 * then patches PPS deblocking_filter_control_present_flag 0�?.
 *
 * The rest of the EDIUS encoding (SPS, PPS, scaling lists, CABAC data, etc.)
 * is preserved unchanged.
 *
 * Usage: deblock_inject <input.mp4> <output.mp4>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

static void die(const char *m) { fprintf(stderr,"FATAL: %s\n",m); exit(1); }
static void logmsg(const char *m) { FILE *lf=fopen("deblock_debug.txt","a"); if(lf){fprintf(lf,"%s\n",m);fclose(lf);} }
static uint32_t r32(const uint8_t *p){return ((uint32_t)p[0]<<24)|(p[1]<<16)|(p[2]<<8)|p[3];}
static void w32(uint8_t *p,uint32_t v){p[0]=v>>24;p[1]=v>>16;p[2]=v>>8;p[3]=v;}

/* ---- Bit reader (operates on raw RBSP, no emulation prevention) ---- */
typedef struct { const uint8_t *d; int sz; int pos; } BR;
static int br_bit(BR *b) {
    if (b->pos/8 >= b->sz) return 0;
    int v = (b->d[b->pos/8] >> (7 - b->pos%8)) & 1;
    b->pos++; return v;
}
static uint32_t br_u(BR *b, int n) {
    uint32_t v=0; for(int i=0;i<n;i++) v=(v<<1)|br_bit(b); return v;
}
static uint32_t br_ue(BR *b) {
    int z=0; while(!br_bit(b) && b->pos<b->sz*8 && z<31) z++;
    if(z==0) return 0;
    return (1UL<<z)-1+br_u(b,z);
}

/* ---- Bit writer (produces raw RBSP) ---- */
typedef struct { uint8_t *d; int sz, cp; } BW;
static void bw_bit(BW *w, int v) {
    if (w->sz/8 >= w->cp) { w->cp=w->cp?w->cp*2:256; w->d=realloc(w->d,w->cp); }
    if (w->sz%8==0) w->d[w->sz/8]=0;
    if (v) w->d[w->sz/8] |= (1<<(7-w->sz%8));
    w->sz++;
}
static void bw_u(BW *w, uint32_t v, int n) { for(int i=n-1;i>=0;i--) bw_bit(w,(v>>i)&1); }
static void bw_ue(BW *w, uint32_t v) {
    if(v==0){bw_bit(w,1);return;}
    uint32_t c=v+1; int z=0; while((1UL<<z)<=c) z++; z--;
    for(int i=0;i<z;i++) bw_bit(w,0);
    bw_u(w,c,z+1);
}
static void bw_se(BW *w, int32_t v) {
    uint32_t c = (v>0) ? (2*v-1) : (uint32_t)(-2*v);
    bw_ue(w,c);
}
static void bw_bytes(BW *w, const void *data, int sz) {
    const uint8_t *p = data;
    for (int i=0; i<sz; i++) bw_u(w, p[i], 8);
}

/* ---- EBSP �?RBSP conversion ---- */
/* Remove emulation prevention bytes: 00 00 03 �?00 00 */
static int ebsp_to_rbsp(const uint8_t *ebsp, int sz, uint8_t *rbsp) {
    int o=0;
    for(int i=0;i<sz;i++) {
        if(i>=2 && ebsp[i-2]==0 && ebsp[i-1]==0 && ebsp[i]==3 && i+1<sz && ebsp[i+1]<=3) {
            continue; /* emulation prevention byte �?skip */
        }
        rbsp[o++]=ebsp[i];
    }
    return o;
}
/* Add emulation prevention bytes */
static int rbsp_to_ebsp(const uint8_t *rbsp, int sz, uint8_t *ebsp) {
    int o=0, zeros=0;
    for(int i=0;i<sz;i++) {
        if(zeros>=2 && rbsp[i]<=3) { ebsp[o++]=3; zeros=0; }
        ebsp[o++]=rbsp[i];
        if(rbsp[i]==0) zeros++; else zeros=0;
    }
    return o;
}

/* ---- SPS constants for C0004 (from trace_headers analysis) ---- */
#define LOG2_MAX_FRAME_NUM 4    /* log2_max_frame_num_minus4=0 �?4 bits */
#define LOG2_MAX_POC_LSB  5     /* log2_max_poc_lsb_minus4=1 �?5 bits */
#define FRAME_MBS_ONLY    1
#define REDUNDANT_PIC_CNT 0     /* PPS redundant_pic_cnt_present_flag=0 */
#define WEIGHTED_PRED     0     /* PPS weighted_pred_flag=0 */
#define WEIGHTED_BIPRED   0     /* PPS weighted_bipred_idc=0 */
#define BOTTOM_FIELD_POC  0     /* PPS bottom_field_pic_order_in_frame_present=0 */

/* ---- Slice header parser: reads up to insertion point, returns bit position ---- */
/* Returns the number of RBSP bits consumed (= insertion point) */
static int parse_slice_header(const uint8_t *rbsp, int rbsp_sz, int nal_type, int nal_ref_idc)
{
    BR b = { rbsp, rbsp_sz, 0 };

    /* first_mb_in_slice */ br_ue(&b);
    uint32_t slice_type = br_ue(&b);
    /* pps_id */ br_ue(&b);
    /* frame_num */ br_u(&b, LOG2_MAX_FRAME_NUM);

    if (!FRAME_MBS_ONLY) {
        /* field_pic_flag, bottom_field_flag �?not present for progressive */
        /* NOT REACHED for our case */
    }

    int is_idr = (nal_type == 5);
    if (is_idr) br_ue(&b); /* idr_pic_id */

    /* pic_order_cnt_lsb */ br_u(&b, LOG2_MAX_POC_LSB);
    /* delta_pic_order_cnt_bottom �?only if bottom_field_pic_order_in_frame_present */
    /* = 0 for our PPS, skip */

    /* redundant_pic_cnt �?only if present in PPS */
    if (REDUNDANT_PIC_CNT) br_ue(&b);

    /* Check slice type for ref list modification */
    int is_b = (slice_type == 1 || slice_type == 6);

    /* direct_spatial_mv_pred for B slices */
    if (is_b) br_u(&b, 1);

    int is_i = (slice_type==2||slice_type==7);
    int is_p = (slice_type==0||slice_type==5);

    /* num_ref_idx_active_override: only for P/SP/B */
    if (is_p || is_b) {
        if (br_u(&b, 1)) { /* override */
            br_ue(&b); /* l0 */
            if (is_b) br_ue(&b); /* l1 */
        }
    }

    /* ref_pic_list_modification: only for P/B */
    if (is_p) {
        if (br_u(&b, 1)) { uint32_t idc; do { idc=br_ue(&b); } while(idc!=3); }
    } else if (is_b) {
        if (br_u(&b, 1)) { uint32_t idc; do { idc=br_ue(&b); } while(idc!=3); }
        if (br_u(&b, 1)) { uint32_t idc; do { idc=br_ue(&b); } while(idc!=3); }
    }

    /* pred_weight_table �?only if weighted pred for P/B */
    if ((WEIGHTED_PRED && (slice_type==0||slice_type==5)) ||
        (WEIGHTED_BIPRED==1 && is_b) || (WEIGHTED_BIPRED==2 && is_b)) {
        /* NOT REACHED for our PPS */
        die("weighted prediction not supported");
    }

    /* dec_ref_pic_marking �?only for reference NALs */
    if (nal_ref_idc != 0) {
        if (is_idr) {
            br_u(&b, 1); /* no_output_of_prior_pics */
            br_u(&b, 1); /* long_term_reference_flag */
        } else {
            if (br_u(&b, 1)) { /* adaptive_ref_pic_marking_mode_flag */
                uint32_t op;
                do { op = br_ue(&b);
                    if(op==1||op==3) br_ue(&b);
                    if(op==2) br_ue(&b);
                    if(op==3||op==6) br_ue(&b);
                    if(op==4||op==5) { br_ue(&b); br_ue(&b); }
                } while (op != 0);
            }
        }
    }

    /* cabac_init_idc: for CABAC non-I/non-SI slices */
    if (!(slice_type==2||slice_type==7||slice_type==3||slice_type==4||slice_type==8||slice_type==9)) {
        br_ue(&b); /* cabac_init_idc */
    }

    /* slice_qp_delta (se(v) = signed exp-golomb, read as raw ue) */
    br_ue(&b);

    /* ===== INSERTION POINT =====
     * Per H.264 spec 7.3.3, deblocking params come AFTER slice_qp_delta:
     *   ... cabac_init_idc, slice_qp_delta, [SP/SI], deblocking_params, ...
     */
    return b.pos;
}

/* ---- Main: process all slices in mdat ---- */
static void dbg(const char*m){fprintf(stderr,m);fflush(stderr);}

int main(int argc, char **argv) {
    if (argc < 3) { fprintf(stderr,"Usage: %s <input.mp4> <output.mp4>\n",argv[0]); return 1; }

    FILE *f = fopen(argv[1],"rb"); if(!f) die("open");
    fseek(f,0,SEEK_END); long fsz=ftell(f); fseek(f,0,SEEK_SET);
    logmsg("File opened"); 
    uint8_t *buf = malloc(fsz);
    if(!buf) die("malloc");
    fread(buf,1,fsz,f); fclose(f);
    {char tmp[128]; sprintf(tmp,"Read %ld bytes",fsz); logmsg(tmp);}

    /* Find top-level boxes */
    long moov_pos=-1, mdat_pos=-1; uint64_t moov_sz=0, mdat_sz=0;
    {
        long p=0;
        while(p+8<=fsz) {
            uint32_t s=r32(buf+p);
            if(s==1) { uint64_t ls=((uint64_t)r32(buf+p+8)<<32)|r32(buf+p+12);
                       if(!memcmp(buf+p+4,"moov",4)){moov_pos=p;moov_sz=ls;}
                       if(!memcmp(buf+p+4,"mdat",4)){mdat_pos=p;mdat_sz=ls;} p+=ls; }
            else if(s==0) { if(!memcmp(buf+p+4,"moov",4)){moov_pos=p;moov_sz=fsz-p;}
                           if(!memcmp(buf+p+4,"mdat",4)){mdat_pos=p;mdat_sz=fsz-p;} break; }
            else { if(!memcmp(buf+p+4,"moov",4)){moov_pos=p;moov_sz=s;}
                   if(!memcmp(buf+p+4,"mdat",4)){mdat_pos=p;mdat_sz=s;} p+=s; }
        }
    }
    if(mdat_pos<0) die("no mdat");
    {char t[128]; sprintf(t,"moov=%ld mdat=%ld",moov_pos,mdat_pos); logmsg(t);}
    int mdat_hdr = (r32(buf+mdat_pos)==1)?16:8;
    long mdat_pl = mdat_pos + mdat_hdr;

    /* Find video stbl in moov */
    /* Walk: moov > trak(vide) > mdia > minf > stbl */
    /* For simplicity, search for "avcC" to locate the video stsd */
    long avcc_pos=-1;
    for(long i=moov_pos;i<moov_pos+moov_sz-4;i++)
        if(!memcmp(buf+i,"avcC",4)){avcc_pos=i;break;}
    if(avcc_pos<0) die("no avcC");
    logmsg("Found avcC");

    /* Get avcC data */
    uint8_t *avcc = buf+avcc_pos+4;
    int ls_minus_one = (avcc[4]&3)+1; /* lengthSizeMinusOne */
    int sps_len = (avcc[6]<<8)|avcc[7];
    int pps_off = 8+sps_len;
    int num_pps = avcc[pps_off];
    int pps_len = (avcc[pps_off+1]<<8)|avcc[pps_off+2];

    dbg("START\n");
    fprintf(stderr,"avcC: ls=%d sps=%d pps=%d(%d entries)\n",ls_minus_one,sps_len,pps_len,num_pps);

    /* Find video stsz, stco, stsc, stss */
    /* Search within moov for these boxes */
    long stsz_pos=-1, stco_pos=-1;
    for(long i=moov_pos;i<moov_pos+moov_sz-8;i++) {
        if(!memcmp(buf+i+4,"stsz",4) && stsz_pos<0) stsz_pos=i;
        if(!memcmp(buf+i+4,"stco",4) && stco_pos<0) stco_pos=i;
    }
    /* Also need stsc for sample-to-chunk mapping */
    /* But for our approach, we process samples sequentially from stsz */

    if(stsz_pos<0) die("no stsz");
    if(stco_pos<0) die("no stco");
    logmsg("Found stsz/stco");

    /* Parse stsz: FullBox, so header = box_hdr(8) + version+flags(4) = 12 */
    int stsz_hdr = (r32(buf+stsz_pos)==1)?16:8;
    uint32_t sample_size = r32(buf+stsz_pos+stsz_hdr+4);  /* skip version+flags */
    uint32_t sample_count = r32(buf+stsz_pos+stsz_hdr+8);
    fprintf(stderr,"stsz: uniform=%u count=%u\n",sample_size,sample_count);
    {char t[128]; sprintf(t,"stsz_pos=%ld uniform=%u count=%u",stsz_pos,sample_size,sample_count); logmsg(t);}

    /* For each sample, find it in mdat and process */
    /* We need stco to get chunk offsets, and stsc for samples-per-chunk */
    /* For simplicity, since all video samples are in the video track's chunks,
       and chunks are interleaved in mdat, we use stco + stsc + stsz to find each sample */

    /* Parse stco: FullBox, header = box_hdr + version+flags */
    int stco_hdr = (r32(buf+stco_pos)==1)?16:8;
    uint32_t stco_count = r32(buf+stco_pos+stco_hdr+4);  /* skip version+flags */
    fprintf(stderr,"stco: %u chunks\n",stco_count);
    {char t[128]; sprintf(t,"stco_pos=%ld count=%u",stco_pos,stco_count); logmsg(t);}

    /* Parse stsc (search for it) */
    long stsc_pos=-1;
    for(long i=moov_pos;i<moov_pos+(long)moov_sz-8;i++)
        if(!memcmp(buf+i+4,"stsc",4)){stsc_pos=i;break;}
    if(stsc_pos<0) { logmsg("stsc NOT FOUND - searching wider"); 
        /* search entire file */
        for(long i=0;i<fsz-8;i++)
            if(!memcmp(buf+i+4,"stsc",4)){stsc_pos=i;break;}
        {char t[128];sprintf(t,"stsc found at %ld",stsc_pos);logmsg(t);}
    }
    if(stsc_pos<0) die("no stsc");
    {char t[128];sprintf(t,"stsc_pos=%ld",stsc_pos);logmsg(t);}
    int stsc_hdr = (r32(buf+stsc_pos)==1)?16:8;
    uint32_t stsc_count = r32(buf+stsc_pos+stsc_hdr+4);  /* skip version+flags */
    {char t[128];sprintf(t,"stsc: hdr=%d count=%u",stsc_hdr,stsc_count);logmsg(t);}
    logmsg("Building sample tables");
    /* stsc entries: first_chunk(4), samples_per_chunk(4), sample_desc_idx(4) */

    /* Build sample offset table */
    /* For each sample, compute its file offset */
    uint32_t *sample_sizes = malloc(sample_count*4);
    if(sample_size>0) {
        for(uint32_t i=0;i<sample_count;i++) sample_sizes[i]=sample_size;
    } else {
        for(uint32_t i=0;i<sample_count;i++)
            sample_sizes[i]=r32(buf+stsz_pos+stsz_hdr+12+i*4);
    }

    /* Map samples to file offsets using stco + stsc */
    uint32_t *sample_offsets = malloc(sample_count*4);
    {
        uint32_t s=0; /* sample index */
        for(uint32_t ch=0;ch<stco_count && s<sample_count;ch++) {
            uint32_t chunk_off = r32(buf+stco_pos+stco_hdr+8+ch*4);
            /* find samples_per_chunk for this chunk */
            uint32_t spc=1;
            for(uint32_t e=0;e<stsc_count;e++) {
                uint32_t fc=r32(buf+stsc_pos+stsc_hdr+8+e*12);
                if(fc<=ch+1) spc=r32(buf+stsc_pos+stsc_hdr+8+e*12+4);
            }
            uint32_t off=chunk_off;
            for(uint32_t i=0;i<spc && s<sample_count;i++) {
                sample_offsets[s]=off;
                off+=sample_sizes[s];
                s++;
            }
        }
    }
    fprintf(stderr,"Mapped %u video samples\n",sample_count);
    {char t[128];sprintf(t,"Mapped %u samples, first off=%u",sample_count,sample_offsets[0]);logmsg(t);}

    /* Process each sample */
    /* New sample data buffers */
    uint8_t **new_samples = malloc(sample_count*sizeof(void*));
    int *new_sizes = malloc(sample_count*4);
    int modified=0;

    for(uint32_t si=0; si<sample_count; si++) {
        long off = sample_offsets[si];
        int sz = sample_sizes[si];
        if(si%200==0 || si>=1170) {char t[128];sprintf(t,"sample %u: off=%ld sz=%d",si,off,sz);logmsg(t);}
        if(off+sz > fsz) { fprintf(stderr,"sample %u out of bounds\n",si); continue; }

        /* Process ALL NALs in this sample, modifying every slice */
        uint8_t *sample = buf+off;
        int pos=0;
        int found_slice=0;
        /* Build new sample using simple buffer + memcpy */
        uint8_t *ns_buf = malloc(sz + 65536);  /* extra room for modifications */
        int ns_pos = 0;
        while(pos+4 <= sz) {
            uint32_t nlen = r32(sample+pos);
            if(nlen==0 || nlen > (uint32_t)(sz - pos - 4)) break;
            uint8_t nal_hdr = sample[pos+4];
            int nal_type = nal_hdr & 0x1F;
            int nal_ref_idc = (nal_hdr>>5)&3;

            if(nal_type==1 || nal_type==5) {
                found_slice=1;
                uint8_t *nal_ebsp = sample+pos+4;
                int nal_hdr_sz = 1;
                int rbsp_buf_sz = nlen + 16;
                uint8_t *rbsp = malloc(rbsp_buf_sz);
                int rbsp_sz = ebsp_to_rbsp(nal_ebsp+nal_hdr_sz, nlen-nal_hdr_sz, rbsp);
                int insert_pos = parse_slice_header(rbsp, rbsp_sz, nal_type, nal_ref_idc);

                /* Deblocking injection with CABAC alignment handling */
                int orig_align = (8 - insert_pos%8) % 8;
                int cabac_start = insert_pos + orig_align;

                if(si<3) {char t[128];sprintf(t,"  si=%u type=%d insert=%d orig_align=%d cabac=%d rbsp=%d",
                    si,nal_type,insert_pos,orig_align,cabac_start,rbsp_sz);logmsg(t);}

                BW w = {0};
                for(int i=0;i<insert_pos;i++) bw_bit(&w,(rbsp[i/8]>>(7-i%8))&1);
                bw_ue(&w,0); bw_se(&w,0); bw_se(&w,0); /* deblocking params */
                int new_hdr = insert_pos + 3;
                int new_align = (8 - new_hdr%8) % 8;
                for(int a=0;a<new_align;a++) bw_bit(&w,1);
                for(int i=cabac_start;i<rbsp_sz*8;i++) bw_bit(&w,(rbsp[i/8]>>(7-i%8))&1);

                int new_rbsp_sz=(w.sz+7)/8;

                /* Debug: compare original vs new RBSP at CABAC boundary */
                if(si<1) {
                    char t[512]; int p=0;
                    p+=sprintf(t+p,"ORIG bytes 0-7:"); for(int b=0;b<8;b++) p+=sprintf(t+p," %02X",rbsp[b]);
                    p+=sprintf(t+p,"\nNEW  bytes 0-7:"); for(int b=0;b<8;b++) p+=sprintf(t+p," %02X",w.d[b]);
                    /* Also check last 8 bytes */
                    p+=sprintf(t+p,"\nORIG last 8:"); for(int b=rbsp_sz-8;b<rbsp_sz;b++) p+=sprintf(t+p," %02X",rbsp[b]);
                    p+=sprintf(t+p,"\nNEW  last 8:"); for(int b=new_rbsp_sz-8;b<new_rbsp_sz;b++) p+=sprintf(t+p," %02X",w.d[b]);
                    /* Check around bytestream 25503 position */
                    int chk = 25503 - 4; /* adjust for 1-byte shift */
                    if(chk >= 0 && chk+8 <= rbsp_sz) {
                        p+=sprintf(t+p,"\nORIG @%d:",chk); for(int b=chk;b<chk+8;b++) p+=sprintf(t+p," %02X",rbsp[b]);
                    }
                    if(chk >= 0 && chk+8 <= new_rbsp_sz) {
                        p+=sprintf(t+p,"\nNEW  @%d:",chk); for(int b=chk;b<chk+8;b++) p+=sprintf(t+p," %02X",w.d[b]);
                    }
                    logmsg(t);
                }
                int ebsp_sz = new_rbsp_sz*3/2+16;
                uint8_t *ne = malloc(ebsp_sz);
                ne[0]=nal_ebsp[0];
                int ne_sz = 1 + rbsp_to_ebsp(w.d, new_rbsp_sz, ne+1);
                if(ne_sz != (int)nlen) modified++;

                w32(ns_buf+ns_pos, ne_sz); ns_pos += 4;
                memcpy(ns_buf+ns_pos, ne, ne_sz); ns_pos += ne_sz;
                free(w.d); free(rbsp); free(ne);
            } else {
                /* Non-slice NAL: copy as-is */
                w32(ns_buf+ns_pos, nlen); ns_pos += 4;
                memcpy(ns_buf+ns_pos, sample+pos+4, nlen); ns_pos += nlen;
            }
            pos += 4+nlen;
        }
        new_samples[si] = ns_buf;
        new_sizes[si] = ns_pos;
    }
    fprintf(stderr,"Modified %d/%u slices (size changes)\n",modified,sample_count);
    logmsg("Slice processing complete");

    /* Calculate new mdat payload size */
    /* New mdat = original mdat payload + delta from modified samples */
    /* But we need to keep audio/rtmd data in mdat unchanged */
    /* The video samples are interspersed with audio/rtmd in mdat */
    /* Strategy: build new mdat by replacing video sample data in-place */

    /* Actually, we need to rebuild the entire mdat because sample sizes changed */
    /* For audio/rtmd, we copy original data */
    /* For video, we use new_samples */

    /* But the interleaving is complex. Simplest: keep original mdat layout,
       just patch each video sample in place if size unchanged, or rebuild if changed */

    /* Check if any sizes changed */
    int total_delta = 0;
    for(uint32_t i=0;i<sample_count;i++) {
        total_delta += new_sizes[i] - sample_sizes[i];
    }
    fprintf(stderr,"Total size delta: %+d bytes\n",total_delta);

    {char t[128];sprintf(t,"total_delta=%d modified=%d",total_delta,modified);logmsg(t);}
    if(total_delta == 0) {
        logmsg("In-place patch: copying samples");
        for(uint32_t si=0;si<sample_count;si++) {
            if(!new_samples[si]) { char t[64]; sprintf(t,"NULL at si=%u",si); logmsg(t); die("null sample"); }
            memcpy(buf+sample_offsets[si], new_samples[si], new_sizes[si]);
        }
        logmsg("In-place patch: fixing PPS");
        /* Patch PPS deblocking flag */
        uint8_t *pps = avcc + pps_off + 3; pps[3] |= 0x40;
        fprintf(stderr,"Patched PPS deblocking flag\n");

        FILE *of=fopen(argv[2],"wb");
        fwrite(buf,1,fsz,of); fclose(of);
        logmsg("File written");
        fprintf(stderr,"Output: %s (%ld bytes, same size)\n",argv[2],fsz);
    } else {
        /* Sizes changed �?need to rebuild mdat and update stco/stsz */
        /* This is more complex. For now, just rebuild the whole file. */
        /* TODO: implement full rebuild */
        fprintf(stderr,"Size changes detected �?full rebuild needed (not yet implemented)\n");

        /* For now, output the original with just PPS patch as fallback */
        /* Actually, let's attempt the rebuild */
        fprintf(stderr,"Attempting full rebuild...\n");

        /* New mdat: copy everything except video samples, replace video samples */
        /* Build new mdat by walking the original mdat and replacing video samples */
        long mdat_end = mdat_pos + (long)mdat_sz;
        uint8_t *new_mdat = malloc((size_t)mdat_sz + total_delta + 1);
        if(!new_mdat) die("malloc new_mdat");
        logmsg("Allocated new mdat");

        long src = mdat_pl;
        long dst = 0;
        for(uint32_t si=0; si<sample_count; si++) {
            if(si%200==0){char t[128];sprintf(t,"rebuild si=%u dst=%ld src=%ld",si,dst,src);logmsg(t);}
            long vstart = sample_offsets[si];
            long vend = vstart + sample_sizes[si];
            /* Copy gap before this video sample using memcpy */
            if(vstart > src) {
                long gap = vstart - src;
                memcpy(new_mdat+dst, buf+src, gap);
                dst += gap; src += gap;
            }
            /* Copy new video sample */
            memcpy(new_mdat+dst, new_samples[si], new_sizes[si]);
            dst += new_sizes[si];
            src = vend;
        }
        /* Copy remaining data after last video sample */
        if(mdat_end > src) {
            memcpy(new_mdat+dst, buf+src, mdat_end - src);
            dst += mdat_end - src;
        }
        {char t[64];sprintf(t,"new mdat built: %ld bytes",dst);logmsg(t);}
        int new_mdat_sz = dst;

        /* Now rebuild the file: ftyp + PROF + new_mdat + new_moov */
        /* For moov, update: stsz, stco, avcC(PPS patch), and all box sizes */

        /* This is getting complex. Let me take a simpler approach: */
        /* Copy the original file, replace mdat content, then fix stsz/stco/moov sizes */

        /* Actually the simplest reliable approach: */
        /* 1. Copy everything up to mdat as-is */
        /* 2. Write new mdat */
        /* 3. Copy moov, patching stsz/stco/avcC and parent box sizes */

        /* Find positions of stsz/stco/stsc/avcC in moov for patching */
        /* Update stsz entries */
        if(sample_size==0) {
            for(uint32_t i=0;i<sample_count;i++)
                w32(buf+stsz_pos+stsz_hdr+12+i*4, new_sizes[i]);
        }
        /* Update stco: offsets shift by cumulative delta of preceding samples */
        /* For each chunk, the offset changes by the total delta of all samples
           in all preceding chunks */
        /* This requires knowing which samples are in which chunk */
        /* ... complex ... */
        /* For now, recompute all stco entries from scratch */

        /* Build new sample offset map (video stco) */
        {
            uint32_t s=0;
            long cur_delta=0;
            for(uint32_t ch=0;ch<stco_count;ch++) {
                uint32_t old_off = r32(buf+stco_pos+stco_hdr+8+ch*4);
                uint32_t new_off = old_off + cur_delta;
                w32(buf+stco_pos+stco_hdr+8+ch*4, new_off);
                uint32_t spc=1;
                for(uint32_t e=0;e<stsc_count;e++) {
                    uint32_t fc=r32(buf+stsc_pos+stsc_hdr+8+e*12);
                    if(fc<=ch+1) spc=r32(buf+stsc_pos+stsc_hdr+8+e*12+4);
                }
                for(uint32_t i=0;i<spc && s<sample_count;i++) {
                    cur_delta += new_sizes[s]-sample_sizes[s];
                    s++;
                }
            }
        }

        /* Update ALL other stco boxes in moov (audio, rtmd) */
        /* For each stco entry, compute shift = cumulative video delta before that offset */
        {
            long mdat_start = mdat_pl;
            for(long p = moov_pos+8; p < moov_pos+(long)moov_sz - 16; p++) {
                if(memcmp(buf+p+4, "stco", 4) != 0) continue;
                if(p == stco_pos) continue; /* already updated */
                int hdr = (r32(buf+p)==1)?16:8;
                uint32_t cnt = r32(buf+p+hdr+4);
                fprintf(stderr,"Updating stco at 0x%lX: %u entries\n",(long)p,cnt);
                for(uint32_t i=0;i<cnt;i++) {
                    uint32_t off = r32(buf+p+hdr+8+i*4);
                    /* Compute cumulative video delta before this offset */
                    long delta = 0;
                    for(uint32_t s=0; s<sample_count; s++) {
                        if(sample_offsets[s] >= off) break;
                        delta += new_sizes[s] - sample_sizes[s];
                    }
                    w32(buf+p+hdr+8+i*4, off + delta);
                }
            }
        }

        /* Patch PPS deblocking flag */
        {
            uint8_t *pps = avcc + pps_off + 3;
            pps[3] |= 0x40;
        }

        /* Update mdat box size */
        uint64_t new_mdat_total = new_mdat_sz + mdat_hdr;
        if(r32(buf+mdat_pos)==1) {
            /* largesize */
            w32(buf+mdat_pos+8, (uint32_t)(new_mdat_total>>32));
            w32(buf+mdat_pos+12, (uint32_t)new_mdat_total);
        } else {
            if(new_mdat_total > 0xFFFFFFFF) {
                /* Need largesize �?complex, skip for now */
                die("mdat too large for 32-bit size, largesize conversion not implemented");
            }
            w32(buf+mdat_pos, (uint32_t)new_mdat_total);
        }

        /* Update moov box size (and all parents) by total_delta */
        /* moov is after mdat, so its position shifts by total_delta */
        /* But actually moov position doesn't change if mdat is before moov */
        /* Wait, mdat grows by total_delta, so moov starts at a later position */
        /* But the moov box itself doesn't change size (stsz/stco are in-place) */
        /* The moov POSITION changes, but since moov is the last box, that's fine */
        /* Actually moov's internal stco offsets already account for the new mdat layout */
        /* The only issue is: audio/rtmd stco also need updating because the
           interleaving shifted */

        /* Audio and rtmd stco also need to shift */
        /* For each non-video stco in the file, shift by the cumulative delta
           at that point in mdat */
        /* This is very complex for interleaved layouts */

        /* Simplified approach: find ALL stco boxes in moov and update them */
        /* For video stco, we already updated above */
        /* For audio/rtmd stco, we need to shift based on how much video data
           before each audio chunk grew */

        /* For now, just output with video stco updated. Audio might be wrong. */
        /* TODO: properly handle audio/rtmd stco */

        /* Write output: everything before mdat + new mdat + everything after */
        long new_fsz = mdat_pos + new_mdat_total + (fsz - mdat_end);
        uint8_t *out = malloc(new_fsz > fsz ? new_fsz : fsz);
        memcpy(out, buf, mdat_pos); /* ftyp + PROF */
        /* Write new mdat header + data */
        if(mdat_hdr==16) {
            w32(out+mdat_pos, 1); /* largesize indicator */
            memcpy(out+mdat_pos+4, "mdat", 4);
            w32(out+mdat_pos+8, (uint32_t)(new_mdat_total>>32));
            w32(out+mdat_pos+12, (uint32_t)new_mdat_total);
        } else {
            w32(out+mdat_pos, (uint32_t)new_mdat_total);
            memcpy(out+mdat_pos+4, "mdat", 4);
        }
        memcpy(out+mdat_pos+mdat_hdr, new_mdat, new_mdat_sz);
        /* Copy moov and everything after (with updated stco/stsz patched in buf) */
        memcpy(out+mdat_pos+new_mdat_total, buf+mdat_end, fsz-mdat_end);

        FILE *of=fopen(argv[2],"wb");
        fwrite(out,1,new_fsz,of); fclose(of);
        fprintf(stderr,"Output: %s (%ld bytes, delta %+d)\n",argv[2],new_fsz,total_delta);
        free(out);
    }

    /* Cleanup */
    for(uint32_t i=0;i<sample_count;i++) free(new_samples[i]);
    free(new_samples); free(new_sizes);
    free(sample_sizes); free(sample_offsets);
    free(buf);
    return 0;
}
