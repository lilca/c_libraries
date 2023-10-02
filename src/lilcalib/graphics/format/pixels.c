#include "pixels.h"

Pixels* Pixels_new(void) {
    Pixels* res = malloc(sizeof(Pixels));
    Pixels_init(res);
    return res;
}

int Pixels_init(Pixels* pix) {
    pix->width = 0;
    pix->height = 0;
    int32 size = 0;
    pix->pixels = NULL;
    return TRUE;
}

int Pixels_createEmptyMatrix(Pixels* pix, uint32 width, uint32 height, uint16 depth) {
    pix->width = width;
    pix->height = height;
    int32 size = width * height * sizeof(fARGB);
    pix->pixels = malloc(size);
    return TRUE;
}

void Pixels_free(Pixels* pix) {
    if (pix == NULL)
        return;
    if (pix->pixels == NULL)
        return;
    free(pix->pixels);
    pix->pixels = NULL;
    free(pix);
    return;
}

void Pixels_print(Pixels* pix) {
    printf("-- PIXELS ----------\n");
    printf("Width = %d\n", pix->width);
    printf("Height = %d\n", pix->height);
    printf("Image(Addr) = %llx\n", (uint64)(pix->pixels));
    printf("--------------------\n");
    return;
}

void Pixels_grayScale(Pixels* pix) {
    uint32 size = pix->width * pix->height;
    fARGB* src = pix->pixels;
    for (int idx = 0; idx < size; idx++) {
        fARGB_toGray(src++);
    }
    return;
}

fARGB Pixels_getValue(Pixels* pix, uint32 x, uint32 y) {
    return pix->pixels[x + y * pix->width];
}

int Pixels_getHistogram(Pixels* pix, int32* array, int32* arraySize, int depth) {
    *arraySize = depth / 3;
    uint32 size = pix->width * pix->height;
    fARGB* src = pix->pixels;
    for (int idx = 0; idx < size; idx++) {
        fARGB_isHist()
    }
    return;
}

/*
int Pixels_isHit(Pixels* pix, fARGB val, float64 dx) {
    pix
    return TRUE;
}
*/
/*
uint32* Pixels_getHistColor(Pixels* pix, int32 size) {
    uint32 arraySize = size * size * size;
    uint32* res = malloc(arraySize * sizeof(uint32));
    if (res == NULL)
        return NULL;
    for (int a = 0; a < arraySize; a++)
        res[a] = 0;
    for(int jdx = 0; jdx < pix->height; jdx++)
        for(int idx = 0; idx < pix->width; idx++) {
            float64 val = Pixels_getValue(pix, idx, jdx);
            uint32 index =
                (uint32)(val.red * size) +
                (uint32)(val.green * size) * size+
                (uint32)(val.blue * size) * size * size;
            res[index]++;
        }
    return res;
}

uint32 Pixels_getHistCount()
*/