#ifndef GRAPHICS_FORMAT_BMP
#define GRAPHICS_FORMAT_BMP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <common/typedefs.h>
#include <iobuffer/iobuffer.h>
#include <graphics/format/pixels.h>

#define BMP_SUFFIX "bmp"
#define BMP_FILEHEADER_SIZE 14
#define BMP_INFOHEADER_SIZE 40
#define BMP_DEPTH_24BIT 24
#define BMP_DEPTH_32BIT 32
#define BMP_COMPRESSION_BI_RGB 0
#define BMP_WAY_BOTTOM2TOP 0
#define BMP_WAY_TOP2BOTTOM -1

struct _BMP {
    int32 fileSize;
    int32 offset;
    int32 headerSize;
    int16 way;
    int32 width;
    int32 height;
    int16 depth;
    int32 compType;
    int32 dataSize;
    int32 xPPM;
    int32 yPPM;
    int32 pallets;
    int32 impPallet;
    void* imageData;
};
typedef struct _BMP BMP;

struct __attribute__ ((__packed__)) _BMPFileHeader {
    char bfType[2];
    uint32 bfSize;
    uint16 bfReserved1;
    uint16 bfReserved2;
    uint32 bfOffBits;
};
typedef struct _BMPFileHeader BMPFileHeader;

struct __attribute__ ((__packed__)) _BMPInfoHeaderWB {
    uint32 bcSize;
    uint32 bcWidth;
    uint32 bcHeight;
    uint16 bcPlanes;
    uint16 bcBitCount;
    uint32 biCompression;
    uint32 biSizeImage;
    uint32 biXPixPerMeter;
    uint32 biYPixPerMeter;
    uint32 biClrUsed;
    uint32 biClrImportant;
};
typedef struct _BMPInfoHeaderWB BMPInfoHeaderWB;

struct __attribute__ ((__packed__)) _BMPInfoHeaderOS2 {
    uint32 bcSize;
    uint16 bcWidth;
    uint16 bcHeight;
    uint16 bcPlanes;
    uint16 bcBitCount;
};
typedef struct _BMPInfoHeaderOS2 BMPInfoHeaderOS2;

BMP* BMP_new(void);
void BMP_init(BMP* ptr);
BMP* BMP_importFromStream(IOBuffer* buf);
IOBuffer* BMP_exportToStream(BMP* bmp);
BMP* BMP_importFromPixels(Pixels* pix);
Pixels* BMP_exportToPixels(BMP* bmp);
void BMP_free(BMP* bmp);
void BMP_print(BMP* bmp);

#endif
