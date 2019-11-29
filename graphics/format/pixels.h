#ifndef GRAPHICS_FORMAT_PIXELS
#define GRAPHICS_FORMAT_PIXELS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <common/typedefs.h>
#include <graphics/format/units.h>
#include <graphics/format/pixels.h>

#define PIXELS_SUFFIX "pix"

struct _Pixels {
    uint32 width;
    uint32 height;
    fARGB* pixels;
};
typedef struct _Pixels Pixels;

Pixels* Pixels_new(void);
int Pixels_init(Pixels* pix);
int Pixels_createEmptyMatrix(Pixels* pix, uint32 width, uint32 height, uint16 depth);
void Pixels_free(Pixels* pix);
void Pixels_print(Pixels* pix);

void Pixels_grayScale(Pixels* pix);
fARGB Pixels_getValue(Pixels* pix, uint32 x, uint32 y);
//uint32* Pixels_getHistColor(Pixels* pix, int32 size);

#endif