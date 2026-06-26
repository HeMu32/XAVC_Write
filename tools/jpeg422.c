#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jpeglib.h>

static void error_exit(j_common_ptr cinfo)
{
    (*cinfo->err->output_message)(cinfo);
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc != 5) {
        fprintf(stderr, "Usage: jpeg422 <input_yuv> <width> <height> <output.jpg>\n");
        return 1;
    }

    const char *infile = argv[1];
    int w = atoi(argv[2]);
    int h = atoi(argv[3]);
    const char *outfile = argv[4];

    if (w <= 0 || h <= 0 || (w & 1)) {
        fprintf(stderr, "Width and height must be positive, width even.\n");
        return 1;
    }

    int w2 = w / 2;
    size_t y_size = (size_t)w * h;
    size_t c_size = (size_t)w2 * h;
    size_t total = y_size + c_size * 2;

    FILE *fin = fopen(infile, "rb");
    if (!fin) { fprintf(stderr, "Cannot open input: %s\n", infile); return 1; }

    unsigned char *y_plane  = (unsigned char *)malloc(y_size);
    unsigned char *cb_plane = (unsigned char *)malloc(c_size);
    unsigned char *cr_plane = (unsigned char *)malloc(c_size);
    if (!y_plane || !cb_plane || !cr_plane) { fprintf(stderr, "OOM\n"); return 1; }

    if (fread(y_plane, 1, y_size, fin) != y_size ||
        fread(cb_plane, 1, c_size, fin) != c_size ||
        fread(cr_plane, 1, c_size, fin) != c_size) {
        fprintf(stderr, "Short read\n"); return 1;
    }
    fclose(fin);

    struct jpeg_compress_struct cinfo;
    struct jpeg_error_mgr jerr;
    cinfo.err = jpeg_std_error(&jerr);
    jerr.error_exit = error_exit;
    jpeg_create_compress(&cinfo);

    FILE *fout = fopen(outfile, "wb");
    if (!fout) { fprintf(stderr, "Cannot open output: %s\n", outfile); return 1; }
    jpeg_stdio_dest(&cinfo, fout);

    cinfo.image_width = w;
    cinfo.image_height = h;
    cinfo.input_components = 3;
    cinfo.in_color_space = JCS_YCbCr;
    jpeg_set_defaults(&cinfo);

    cinfo.comp_info[0].h_samp_factor = 2;
    cinfo.comp_info[0].v_samp_factor = 1;
    cinfo.comp_info[1].h_samp_factor = 1;
    cinfo.comp_info[1].v_samp_factor = 1;
    cinfo.comp_info[2].h_samp_factor = 1;
    cinfo.comp_info[2].v_samp_factor = 1;
    cinfo.comp_info[0].component_id = 1;
    cinfo.comp_info[1].component_id = 2;
    cinfo.comp_info[2].component_id = 3;
    cinfo.data_precision = 8;
    cinfo.num_components = 3;
    cinfo.jpeg_color_space = JCS_YCbCr;
    cinfo.write_JFIF_header = FALSE;
    cinfo.write_Adobe_marker = FALSE;

    jpeg_set_quality(&cinfo, 95, TRUE);
    jpeg_start_compress(&cinfo, TRUE);

    JSAMPLE *row_buffer = (JSAMPLE *)malloc(w * 3);
    JSAMPROW row_pointer[1] = { row_buffer };

    while (cinfo.next_scanline < cinfo.image_height) {
        unsigned long y = cinfo.next_scanline;
        unsigned char *yp = y_plane  + y * w;
        unsigned char *cbp = cb_plane + y * w2;
        unsigned char *crp = cr_plane + y * w2;
        for (int x = 0; x < w; x++) {
            row_buffer[x*3+0] = yp[x];
            row_buffer[x*3+1] = cbp[x/2];
            row_buffer[x*3+2] = crp[x/2];
        }
        jpeg_write_scanlines(&cinfo, row_pointer, 1);
    }
    free(row_buffer);

    jpeg_finish_compress(&cinfo);
    jpeg_destroy_compress(&cinfo);
    fclose(fout);
    free(y_plane); free(cb_plane); free(cr_plane);
    return 0;
}