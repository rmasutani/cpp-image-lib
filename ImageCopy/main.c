#include <stdio.h>
#include <stdlib.h>

#define BMP_HEADER_SIZE 54
#define BMP_COLOR_TABLE_SIZE 1024
#define CUSTOM_IMAGE_SIZE 1024*1024

int main()
{
    FILE *streamIn = fopen("images/cameraman.bmp","rb");
    FILE *fo = fopen("images/cameraman_copy.bmp","wb");

    if(streamIn ==(FILE*)0)
    {
        printf("Unable to open file\n");
    }
    unsigned char header[54];
    unsigned char colorTable[1024];

    for(int i =0;i<54;i++)
    {
        header[i] =getc(streamIn);

    }

    int width = *(int *)&header[18];
    int height = *(int *)&header[22];
    int bitDepth = *(int *)&header[28];

    if(bitDepth<=8)
    {
         fread(colorTable,sizeof(unsigned char), 1024,streamIn);
    }

    fwrite(header,sizeof(unsigned char),54,fo);
    unsigned char buf[height * width];
   fread(buf,sizeof(unsigned char),(height*width), streamIn);

   if(bitDepth <=8)
   {

       fwrite(colorTable,sizeof(unsigned char),1024,fo);
   }
       fwrite(buf,sizeof(unsigned char),(height *width),fo);
       fclose(fo);
       fclose(streamIn);

       printf("Success !\n");
       printf("Width : %d\n", width);
       printf("Height : %d\n",height);

    return 0;
}

void imageReader(const char *imgName, 
                 int *_height,
                 int *_width,
                 int *_bitDepth,
                 unsigned char *_header,
                 unsigned char *_colorTable,
                 unsigned char *_buf)
{
    int i;
    FILE *streamIn;
}
