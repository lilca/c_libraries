/**
 * ビットマップファイルクラスのソース
 * @file
 */
#include "bmp.h"

static int _parseHeader(BMP* bmp, uint8** pp);
static int _parseInfoHeader(BMP* bmp, uint8** pp);
static void* _toPixels(BMP* bmp);
static uint32 _getWidthSize(BMP* bmp);
static uint32 _getImageSize(BMP* bmp);
static int _copy_data(BMP* dst, uint8* src);
static void* _getPixelAddr(BMP* bmp, uint32 x, uint32 y);
static int _create_copy_data(void** dst, uint8* src, int width, int height, int depth);

BMP* BMP_new(void) {
    BMP* res = malloc(sizeof(BMP));
    BMP_init(res);
    return res;
}

void BMP_init(BMP* bmp) {
    bmp->fileSize = 0;;
    bmp->offset = 0;
    bmp->headerSize = 0;
    bmp->way = BMP_WAY_BOTTOM2TOP;
    bmp->width = 0;
    bmp->height = 0;
    bmp->depth = 0;
    bmp->compType = BMP_COMPRESSION_BI_RGB;
    bmp->dataSize = 0;
    bmp->xPPM = 0;
    bmp->yPPM = 0;
    bmp->pallets = 0;
    bmp->impPallet = 0;
    bmp->imageData = NULL;
    return;
}

BMP* BMP_importFromStream(IOBuffer* buf) {
    if (buf == NULL)
        return NULL;
    BMP* bmp = BMP_new();
    uint8* ptr = buf->data;
    if (!_parseHeader(bmp, &ptr)) {
        BMP_free(bmp);
        return NULL;
    }

    if (!_parseInfoHeader(bmp, &ptr)) {
        BMP_free(bmp);
        return NULL;
    }
    return bmp;
}

IOBuffer* BMP_exportToStream(BMP* bmp) {
    if (bmp == NULL)
        return NULL;
    uint32 imageSize = _getImageSize(bmp);
    uint32 allocSize = BMP_FILEHEADER_SIZE + BMP_INFOHEADER_SIZE + imageSize;
    IOBuffer* buf = IOBuffer_alloc(allocSize);
    void* p = buf->data;

    BMPFileHeader fh;
    fh.bfType[0] = 'B';
    fh.bfType[1] = 'M';
    fh.bfSize = BMP_FILEHEADER_SIZE + BMP_INFOHEADER_SIZE + imageSize;
    fh.bfReserved1 = 0;
    fh.bfReserved2 = 0;
    fh.bfOffBits = BMP_FILEHEADER_SIZE + BMP_INFOHEADER_SIZE;
    memcpy(p, &fh, sizeof(BMPFileHeader));
    p += sizeof(BMPFileHeader);

    BMPInfoHeaderWB ih;
    ih.bcSize = BMP_INFOHEADER_SIZE;
    ih.bcWidth = bmp->width;
    ih.bcHeight = bmp->height;
    ih.bcPlanes = 1;
    ih.bcBitCount = bmp->depth;
    ih.biCompression = BMP_COMPRESSION_BI_RGB;
    ih.biSizeImage = imageSize;
    ih.biXPixPerMeter = bmp->xPPM;
    ih.biYPixPerMeter = bmp->yPPM;
    ih.biClrUsed = bmp->pallets;
    ih.biClrImportant = bmp->impPallet;
    memcpy(p, &ih, sizeof(BMPInfoHeaderWB));
    p += sizeof(BMPInfoHeaderWB);

    memcpy(p, bmp->imageData, imageSize);
    return buf;
}

BMP* BMP_importFromPixels(Pixels* pix) {
    if (pix == NULL)
        return NULL;
    BMP* bmp = BMP_new();
    bmp->width = pix->width;
    bmp->height = pix->height;
    bmp->depth = BMP_DEPTH_32BIT;
    uint32 imageSize = _getImageSize(bmp);

    bmp->fileSize = BMP_FILEHEADER_SIZE + BMP_INFOHEADER_SIZE + imageSize;
    bmp->offset = BMP_FILEHEADER_SIZE + BMP_INFOHEADER_SIZE;
    bmp->headerSize = BMP_INFOHEADER_SIZE;
    bmp->way = BMP_WAY_BOTTOM2TOP;
    bmp->compType = BMP_COMPRESSION_BI_RGB;
    bmp->dataSize = imageSize;
    bmp->xPPM = 0;
    bmp->yPPM = 0;
    bmp->pallets = 0;
    bmp->impPallet = 0;
    bmp->imageData = malloc(imageSize);

    if (bmp->imageData == NULL)
        return NULL;
    fARGB* src = pix->pixels;

    BGRA* dst;
    for (int jdx = 0; jdx < pix->height; jdx++)
        for (int idx = 0; idx < pix->width; idx++) {
            dst = (BGRA*)(_getPixelAddr(bmp, idx, jdx));
            fARGB_toBGRA(src, dst);
            src++;
        }

    return bmp;
}

Pixels* BMP_exportToPixels(BMP* bmp) {
    Pixels* pix = Pixels_new();
    pix->width = bmp->width;
    pix->height = bmp->height;
    pix->pixels = _toPixels(bmp);
    if (pix->pixels == NULL) {
        free(pix);
        return NULL;
    }
    return pix;
}

void BMP_free(BMP* bmp) {
    if (bmp == NULL)
        return;
    if (bmp->imageData != NULL)
        free(bmp->imageData);
    free(bmp);
    return;
}

static int _parseHeader(BMP* bmp, uint8** pp) {
    if (strncmp((char*)*pp, "BM", 2) != 0)
        return FALSE;
    *pp += 2;
    bmp->fileSize = *((int32*)*pp);
    *pp += 4;
    // Skip reserve area
    *pp += 4;
    bmp->offset = *((int32*)*pp);
    *pp += 4;
    return TRUE;
}

static int _parseInfoHeader(BMP* bmp, uint8** pp) {
    uint8* p = *pp;
    bmp->headerSize = *((int32*)*pp);
    *pp += 4;
    if (bmp->headerSize == 40) {
        bmp->width = *((int32*)*pp);
        *pp += 4;
        bmp->height = *((int32*)*pp);
        *pp += 4;
        if (bmp->height < 0){
            bmp->height = -bmp->height;
            bmp->way = BMP_WAY_TOP2BOTTOM;
        } else
            bmp->way = BMP_WAY_BOTTOM2TOP;
        // Skip Planes
        *pp += 2;
        bmp->depth = *((int16*)*pp);
        *pp += 2;
        bmp->compType = *((int32*)*pp);
        *pp += 4;
        bmp->dataSize = *((int32*)*pp);
        *pp += 4;
        bmp->xPPM = *((int32*)*pp);
        *pp += 4;
        bmp->yPPM = *((int32*)*pp);
        *pp += 4;
        bmp->pallets = *((int32*)*pp);
        *pp += 4;
        bmp->impPallet = *((int32*)*pp);
        *pp += 4;
        //bmp->imageData = p;
        if(!_copy_data(bmp, *pp))
            return FALSE;
    } else if (bmp->headerSize == 12) {
        bmp->width = *((int16*)*pp);
        *pp += 2;
        bmp->height = *((int16*)*pp);
        *pp += 2;
        // Skip Planes
        *pp += 2;
        bmp->depth = *((int16*)*pp);
        *pp += 2;
        //bmp->imageData = p;
        if(!_copy_data(bmp, *pp))
            return FALSE;
    } else {
        return FALSE;
    }
    return TRUE;
}

static void* _toPixels(BMP* bmp) {
    void* res = NULL;
    int size;
    // Allocate memories
    size = bmp->width * bmp->height * sizeof(fARGB);
    if ((res = malloc(size)) == NULL)
        return NULL;

    // Compression
    if (bmp->compType == BMP_COMPRESSION_BI_RGB) {
    } else {
        free(res);
        return NULL;
    }
    // Convert
    if (bmp->depth == BMP_DEPTH_24BIT) {
        fARGB* dst = res;
        for (int jdx = 0; jdx < bmp->height; jdx++) {
            for (int idx = 0; idx < bmp->width; idx++) {
                BGR* src = (BGR*)_getPixelAddr(bmp, idx, jdx);
                BGR_tofARGB(src, dst);
                dst++;
            }
        }
    } else if (bmp->depth == BMP_DEPTH_32BIT) {
        fARGB* dst = res;
        for (int jdx = 0; jdx < bmp->height; jdx++) {
            for (int idx = 0; idx < bmp->width; idx++) {
                BGRA* src = (BGRA*)_getPixelAddr(bmp, idx, jdx);
                BGRA_tofARGB(src, dst);
                dst++;
            }
        }
    } else
        return NULL;
    return res;
}

void BMP_print(BMP* bmp) {
    printf("-- BMP -------------\n");
    printf("File size = %d\n", bmp->fileSize);
    printf("Offset = %d\n", bmp->offset);
    printf("Header size = %d\n", bmp->headerSize);
    printf("Way = %d\n", bmp->way);
    printf("Width = %d\n", bmp->width);
    printf("Height = %d\n", bmp->height);
    printf("Depth = %d\n", bmp->depth);
    printf("Compression = %d\n", bmp->compType);
    printf("Data size = %d\n", bmp->dataSize);
    printf("x ppm = %d\n", bmp->xPPM);
    printf("y ppm = %d\n", bmp->yPPM);
    printf("Pallets = %d\n", bmp->pallets);
    printf("Imp Pallet = %d\n", bmp->impPallet);
    printf("Image(Addr) = %llx\n", (uint64)(bmp->imageData));
    printf("--------------------\n");
    return;
}

static uint32 _getWidthSize(BMP* bmp) {
    uint32 w = bmp->width * bmp->depth / 8;
    return w + (4 - w % 4) % 4;
}

static uint32 _getImageSize(BMP* bmp) {
    uint32 widthSize = _getWidthSize(bmp);
    return widthSize * bmp->height;
}

static int _copy_data(BMP* dst, uint8* src) {
    uint32 size = _getImageSize(dst);
    void* tmp = malloc(size);
    if (tmp == NULL)
        return FALSE;
    memcpy(tmp, src, size);
    dst->imageData = tmp;
    return TRUE;
}

static void* _getPixelAddr(BMP* bmp, uint32 x, uint32 y) {
    uint32 widthSize = _getWidthSize(bmp);
    uint32 xx = x * bmp->depth / 8;
    return bmp->imageData + xx + (bmp->height - y - 1) * widthSize;
}
