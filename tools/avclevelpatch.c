#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

static uint32_t rb32(const uint8_t *p)
{
    return ((uint32_t)p[0]<<24)|((uint32_t)p[1]<<16)|((uint32_t)p[2]<<8)|p[3];
}
static uint64_t rb64(const uint8_t *p)
{
    return ((uint64_t)rb32(p)<<32)|rb32(p+4);
}

static const char *base(const char *path)
{
    const char *s = strrchr(path, '\\');
    return s ? s+1 : path;
}

/* read box size, handle largesize (==1) and unknown (==0) */
static uint64_t box_total(const uint8_t *d, long sz, long off, int *hdr_bytes)
{
    if (off+8 > sz) return 0;
    uint32_t s32 = rb32(d+off);
    if (s32 == 1) {                          /* largesize */
        if (off+16 > sz) return 0;
        if (hdr_bytes) *hdr_bytes = 16;
        return rb64(d+off+8);
    }
    if (s32 == 0) {                          /* to EOF */
        if (hdr_bytes) *hdr_bytes = 8;
        return (uint64_t)(sz - off);
    }
    if (s32 < 8) return 0;                   /* invalid */
    if (hdr_bytes) *hdr_bytes = 8;
    return s32;
}

/* find a top-level box, return offset or -1 */
static long find_box(const uint8_t *d, long sz, const char *type,
                     uint64_t *total_out, int *hdr_out)
{
    long off = 0;
    while (off+8 <= sz) {
        int hdr;
        uint64_t tot = box_total(d, sz, off, &hdr);
        if (tot < 8) break;
        if (memcmp(d+off+4, type, 4) == 0) {
            if (total_out) *total_out = tot;
            if (hdr_out)   *hdr_out   = hdr;
            return off;
        }
        off += (long)tot;
    }
    return -1;
}

static void usage(void)
{
    fprintf(stderr,
        "Usage: avclevelpatch <file> [--old LV] [--new LV] [--backup DIR] [--dry-run]\n"
        "  level: decimal (42/51/52) or hex (0x2A/0x33/0x34)\n"
        "  default: --old 42 --new 51\n");
}

int main(int argc, char **argv)
{
    const char *path = NULL, *bkdir = NULL;
    int ol = 42, nl = 51, dry = 0;

    for (int i = 1; i < argc; i++) {
        if      (!strcmp(argv[i],"--old") && i+1<argc) ol = (int)strtol(argv[++i],0,0);
        else if (!strcmp(argv[i],"--new") && i+1<argc) nl = (int)strtol(argv[++i],0,0);
        else if (!strcmp(argv[i],"--backup") && i+1<argc) bkdir = argv[++i];
        else if (!strcmp(argv[i],"--dry-run")) dry = 1;
        else path = argv[i];
    }
    if (!path) { usage(); return 1; }

    uint8_t ob = ol&0xFF, nb = nl&0xFF;
    if (ob == nb) { fprintf(stderr,"old==new 0x%02X\n",ob); return 1; }

    FILE *f = fopen(path, "rb");
    if (!f) { perror(path); return 1; }
    fseek(f,0,SEEK_END); long sz = ftell(f); fseek(f,0,SEEK_SET);
    uint8_t *d = malloc((size_t)sz);
    if (!d) { fprintf(stderr,"malloc(%ld)\n",sz); fclose(f); return 1; }
    if ((long)fread(d,1,(size_t)sz,f) != sz) { perror("read"); free(d); fclose(f); return 1; }
    fclose(f);

    printf("%s  (%ld bytes)  %s\n  level 0x%02X -> 0x%02X\n\n",
           base(path), sz, dry ? "[DRY-RUN]" : "", ob, nb);

    int n = 0;

    /* 1. avcC box
     * Need to patch:
     *   - AVCLevelIndication field at data+3
     *   - level_idc inside the SPS NAL data at data+8+3
     *   (these are independent copies of the same value)             */
    int ls = 4;
    for (long p = 0; p <= sz-12; p++) {
        if (memcmp(d+p, "avcC", 4)) continue;
        if (d[p+4] != 1 || d[p+5] != 0x64) continue;

        /* ---- AVCLevelIndication at data+3 ---- */
        if (d[p+7] == ob) {
            printf("  [avcC] +0x%lX  AVCLevelIndication: 0x%02X->0x%02X\n",
                   (long)p, ob, nb);
            if (!dry) d[p+7] = nb;
            n++;
        }

        /* ---- read lengthSizeMinusOne ---- */
        ls = (d[p+8] & 3) + 1;

        /* ---- patch level inside embedded SPS NALs ---- */
        int num_sps = d[p+9] & 0x1F;           /* lower 5 bits */
        /* avcC data: ver(1) prof(1) compat(1) level(1) ls(1) numSPS(1) [spsLen(2) SPS...]+ */
        long sps_off = p + 10;                 /* start of first SPS entry (spsLenHi) */
        for (int s = 0; s < num_sps; s++) {
            if (sps_off + 2 > sz) break;
            int nal_len = (d[sps_off] << 8) | d[sps_off+1];
            if (nal_len < 4 || sps_off+2+nal_len > sz) break;
            /* NAL header at sps_off+2 */
            long nal = sps_off + 2;
            if ((d[nal] & 0x1F) == 7 && d[nal+1] == 0x64 && d[nal+3] == ob) {
                printf("  [avcC] +0x%lX  SPS NAL level: 0x%02X->0x%02X\n",
                       (long)nal, ob, nb);
                if (!dry) d[nal+3] = nb;
                n++;
            }
            sps_off += 2 + nal_len;
        }
        /* skip PPS (no level inside) — just continue */
    }

    /* 2. PROF / VPRF */
    for (long p = 0; p <= sz-20; p++) {
        if (memcmp(d+p, "VPRF", 4)) continue;
        if (memcmp(d+p+12, "avc1", 4)) continue;
        if (d[p+17] != 0x64) continue;
        if (d[p+19] == ob) {
            printf("  [PROF] +0x%lX  @+19: 0x%02X->0x%02X\n",
                   (long)p, ob, nb);
            if (!dry) d[p+19] = nb;
            n++;
        }
    }

    /* 3. In-band SPS in mdat */
    uint64_t mtotal;
    int mhdr;
    long mbox = find_box(d, sz, "mdat", &mtotal, &mhdr);
    if (mbox < 0) {
        printf("  [SPS]   mdat not found\n");
    } else {
        long mpl = mbox + mhdr;
        long mend = mbox + (long)mtotal;
        printf("  [mdat] box +0x%lX  hdr=%dB  payload %lX..%lX  lenSize=%d\n",
               (long)mbox, mhdr, (long)mpl, (long)mend, ls);
        int sn = 0;

        /* AVCC: sliding-window scan for length-prefixed SPS NALs */
        for (long pos = mpl; pos+ls+4 <= mend; pos++) {
            uint32_t plen = rb32(d+pos);          /* candidate length prefix */
            if (plen < 8 || plen > 200) continue; /* SPS NAL is ~30-60 bytes */
            if ((long)plen > mend-pos-ls) continue;
            long nal = pos+ls;
            if (((d[nal]&0x1F)!=7) || d[nal+1]!=0x64 || d[nal+3]!=ob) continue;
            printf("  [SPS]   +0x%lX  AVCC len=%u nal=0x%02X  @+3: 0x%02X->0x%02X\n",
                   (long)nal, plen, d[nal], ob, nb);
            if (!dry) d[nal+3] = nb;
            sn++; n++;
            pos += ls + (long)plen;                /* skip past this NAL */
        }

        /* Annex B fallback */
        if (sn == 0) {
            for (long p = mpl; p <= mend-8; ) {
                int sc = 0;
                if      (d[p]==0&&d[p+1]==0&&d[p+2]==1) sc = 3;
                else if (d[p]==0&&d[p+1]==0&&d[p+2]==0&&d[p+3]==1) sc = 4;
                if (!sc) { p++; continue; }
                long nal = p+sc;
                if ((d[nal]&0x1F)==7 && d[nal+1]==0x64 && d[nal+3]==ob) {
                    printf("  [SPS]   +0x%lX  AnnexB %dB nal=0x%02X  @+3:0x%02X->0x%02X\n",
                           (long)p, sc, d[nal], ob, nb);
                    if (!dry) d[nal+3] = nb;
                    sn++; n++; p = nal+3;
                } else { p = nal+1; }
            }
        }
    }

    /* ---- 4. XML sidecar (C####M01.XML) ---- */
    /* global replacement: only one clip in sidecar, safe to replace all @Lold */
    {
        char dir[512]; snprintf(dir,sizeof dir,"%s",path);
        char *sl = strrchr(dir,'\\');
        if (sl) {
            *sl = '\0';
            const char *fn = sl+1;
            char sp[1024]; sp[0]=0;
            if (strlen(fn)>=6 && fn[0]=='C' && fn[5]=='.')
                snprintf(sp,sizeof sp,"%s\\%.5sM01.XML", dir, fn);
            if (sp[0]) {
                FILE *xf = fopen(sp, "rb");
                if (xf) {
                    fseek(xf,0,SEEK_END); long xsz = ftell(xf); fseek(xf,0,SEEK_SET);
                    uint8_t *xd = malloc((size_t)xsz);
                    if (xd && (long)fread(xd,1,(size_t)xsz,xf)==xsz) {
                        fclose(xf);
                        char old_s[16], new_s[16];
                        snprintf(old_s,16,"@L%d",ol);
                        snprintf(new_s,16,"@L%d",nl);
                        int ch = 0;
                        for (long p = 0; p+(long)strlen(old_s) <= xsz; ) {
                            if (memcmp(xd+p,old_s,strlen(old_s))==0) {
                                if(!dry) memcpy(xd+p,new_s,strlen(new_s));
                                ch++; n++; p+=strlen(new_s);
                            } else p++;
                        }
                        if (ch) {
                            printf("  [XML]   %s: %s -> %s (x%d)\n", sp, old_s, new_s, ch);
                            if (!dry) { FILE *wf=fopen(sp,"wb"); if(wf){fwrite(xd,1,(size_t)xsz,wf);fclose(wf);} }
                        }
                    }
                    free(xd);
                }
            }
        }
    }

    /* ---- 5. MEDIAPRO.XML (parent dir) ---- */
    /* targeted: only patch @Lold on the line mentioning the clip file */
    {
        char dir[512]; snprintf(dir,sizeof dir,"%s",path);
        char *sl = strrchr(dir,'\\');
        if (sl) {
            *sl = '\0';
            const char *fn = sl+1;
            /* MEDIAPRO is one level up from the CLIP dir */
            char *sl2 = strrchr(dir, '\\');
            char mp[1024];
            if (sl2) {
                *sl2 = '\0';
                snprintf(mp,sizeof mp,"%s\\MEDIAPRO.XML", dir);
                *sl2 = '\\'; /* restore */
            } else {
                snprintf(mp,sizeof mp,"%s\\MEDIAPRO.XML", dir);
            }
            FILE *xf = fopen(mp, "rb");
            if (xf) {
                fseek(xf,0,SEEK_END); long xsz = ftell(xf); fseek(xf,0,SEEK_SET);
                uint8_t *xd = malloc((size_t)xsz);
                if (xd && (long)fread(xd,1,(size_t)xsz,xf)==xsz) {
                    fclose(xf);
                    char uri[128]; snprintf(uri,sizeof uri,"./CLIP/%s",fn);
                    char old_s[16], new_s[16];
                    snprintf(old_s,16,"@L%d",ol);
                    snprintf(new_s,16,"@L%d",nl);
                    int indry = 0; /* 0=searching, 1=in-clip-entry */
                    long line_start = 0;
                    int ch = 0;
                    for (long p = 0; p <= xsz; p++) {
                        if (p == xsz || xd[p]=='\n' || xd[p]=='\r') {
                            if (indry) {
                                /* we were in the clip's entry — this is end of line */
                                /* patch @Lold on this line */
                                for (long q = line_start; q < p; ) {
                                    if (q+(long)strlen(old_s) > p) break;
                                    if (memcmp(xd+q,old_s,strlen(old_s))==0) {
                                        if (!dry) memcpy(xd+q,new_s,strlen(new_s));
                                        ch++; n++; q+=strlen(new_s);
                                    } else q++;
                                }
                                indry = 0;
                            }
                            if (xd[p]=='\r') p++; /* skip \r\n */
                            line_start = p+1;
                            continue;
                        }
                        if (!indry && xd[p]==uri[0]) {
                            /* check if we're at the clip's URI */
                            if (p+(long)strlen(uri) <= xsz &&
                                memcmp(xd+p,uri,strlen(uri))==0) {
                                indry = 1;
                                line_start = (p > 0 && (xd[p-1]=='\n'||xd[p-1]=='\r')) ? p : p;
                            }
                        }
                    }
                    if (ch) {
                        printf("  [XML]   %s (%s): %s -> %s (x%d)\n", mp, fn, old_s, new_s, ch);
                        if (!dry) { FILE *wf=fopen(mp,"wb"); if(wf){fwrite(xd,1,(size_t)xsz,wf);fclose(wf);} }
                    }
                }
                free(xd);
            }
        }
    }

    printf("\nTotal: %d\n", n);
    if (n == 0) { fprintf(stderr,"no match for 0x%02X\n",ob); free(d); return 1; }

    /* backup */
    if (bkdir && !dry) {
        char b[1024]; snprintf(b,sizeof b,"%s\\%s",bkdir,base(path));
        FILE *bf = fopen(b,"wb");
        if (bf) { fwrite(d,1,(size_t)sz,bf); fclose(bf); printf("Backup: %s\n",b); }
        else perror(b);
    }

    /* write */
    if (!dry) {
        char tmp[1024], bak[1024];
        snprintf(tmp,sizeof tmp,"%s.patched",path);
        snprintf(bak,sizeof bak,"%s.original",path);
        FILE *o = fopen(tmp,"wb");
        if (!o) { perror(tmp); free(d); return 1; }
        fwrite(d,1,(size_t)sz,o); fclose(o);
        remove(bak); rename(path,bak); rename(tmp,path);
        printf("Written: %s\nOriginal: %s\n", path, bak);
    }

    free(d);
    return 0;
}
