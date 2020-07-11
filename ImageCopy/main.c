#include <stdlib.h>
#include <stdio.h>

int main() {
    FILE *streamIn = fopen("images/cameraman.bmp", "rb");
    FILE *fout = fopen("images/cameraman_copy.bmp", "wb");

    if (streamIn == (FILE*)0) {
        printf("Unable to open file\n");
    }

    unsigned char header[54];
    unsigned char colorTable[1024];

    for (int i=0; i < 54; i++) {
        header[i] = getc(streamIn);
    }

    // printf("header[10]: %d\n", header[10]);
    // printf("(int)header[10]: %d\n", (int)header[10]);
    // printf("(void *)&header[10]: %s\n", (void *)&header[10]);
    // printf("&header[10]: %p\n", &header[10]);
    // printf("*(int *)&header[10]: %d\n", *(int *)&header[10]);


    int width = *(int *) &header[10];
    int height = *(int *) &header[22];
    int bitDepth = *(int *) &header[28];

    if (bitDepth <= 8) {
        fread(colorTable, sizeof(unsigned char), 1024, streamIn);
    }

    fwrite(header, sizeof(unsigned char), 54, fout);
    unsigned char buf[height*width];
    fread(buf, sizeof(unsigned char), (height*width), streamIn);

    if (bitDepth <= 8) {
        fwrite(colorTable, sizeof(unsigned char), 1024, fout);
    }
    fwrite(buf, sizeof(unsigned char), (height*width), fout);
    fclose(fout);
    fclose(streamIn);

    printf("Sussess!\n");
    printf("Width: %d, Height: %d", width, height);

    return 0;
}