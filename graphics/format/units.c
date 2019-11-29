#include "units.h"

static void _grayScaleBGR(BGR* bgr);

fARGB* fARGB_new(void) {
    fARGB* res = malloc(sizeof(fARGB));
    fARGB_init(res);
    return res;
}

BGRA* BGRA_new(void) {
    BGRA* res = malloc(sizeof(BGRA));
    BGRA_init(res);
    return res;
}

BGR* BGR_new(void) {
    BGR* res = malloc(sizeof(BGR));
    BGR_init(res);
    return res;
}

void fARGB_init(fARGB* fargb) {
    if (fargb == NULL)
        return;
    fargb->alpha = 1.0;
    fargb->red = 1.0;
    fargb->green = 1.0;
    fargb->blue = 1.0;
    return;
}

void BGRA_init(BGRA* bgra) {
    if (bgra == NULL)
        return;
    bgra->alpha = 0xff;
    bgra->red = 0;
    bgra->green = 0;
    bgra->blue = 0;
    return;
}

void BGR_init(BGR* bgr) {
    if (bgr == NULL)
        return;
    bgr->red = 0;
    bgr->green = 0;
    bgr->blue = 0;
    return;
}

void fARGB_toGray(fARGB* fargb) {
    float64 gray =
        fargb->red * 0.299 +
        fargb->green * 0.587 +
        fargb->blue * 0.114;
    fargb->blue = gray;
    fargb->green = gray;
    fargb->red = gray;
    return;
}

void BGRA_toGray(BGRA* bgra) {
    uint8 gray =
        (uint16)bgra->red * 299 / 1000 +
        (uint16)bgra->green * 587 / 1000 +
        (uint16)bgra->blue * 114 / 1000;
    bgra->blue = gray;
    bgra->green = gray;
    bgra->red = gray;
    return;
}

void BGR_toGray(BGR* bgr) {
    uint8 gray =
        (uint16)bgr->red * 299 / 1000 +
        (uint16)bgr->green * 587 / 1000 +
        (uint16)bgr->blue * 114 / 1000;
    bgr->blue = gray;
    bgr->green = gray;
    bgr->red = gray;
    return;
}

void fARGB_toBGRA(fARGB* fargb, BGRA* bgra) {
    bgra->alpha = fargb->alpha * 255.0;
    bgra->red = fargb->red * 255.0;
    bgra->green = fargb->green * 255.0;
    bgra->blue = fargb->blue * 255.0;
    if(fargb->alpha != 1.0)
        printf("fargb=%llx, bgra=%llx\n", (uint64)fargb, (uint64)bgra);
    return;
}

void fARGB_toBGR(fARGB* fargb, BGR* bgr) {
    bgr->red = fargb->red * 255.0;
    bgr->green = fargb->green * 255.0;
    bgr->blue = fargb->blue * 255.0;
    return;
}

void BGRA_tofARGB(BGRA* bgra, fARGB* fargb) {
    fargb->alpha = (float64)bgra->alpha / 255.0;
    fargb->red = (float64)bgra->red / 255.0;
    fargb->green = (float64)bgra->green / 255.0;
    fargb->blue = (float64)bgra->blue / 255.0;
    return;
}

void BGRA_toBGR(BGRA* bgra, BGR* bgr) {
    bgr->red = bgra->red;
    bgr->green = bgra->green;
    bgr->blue = bgra->blue;
    return;
}

void BGR_tofARGB(BGR* bgr, fARGB* fargb) {
    fargb->alpha = 1.0;
    fargb->red = (float64)bgr->red / 255.0;
    fargb->green = (float64)bgr->green / 255.0;
    fargb->blue = (float64)bgr->blue / 255.0;
    return;
}

void BGR_toBGRA(BGR* bgr, BGRA* bgra) {
    bgra->alpha = 255;
    bgra->red = bgr->red;
    bgra->green = bgr->green;
    bgra->blue = bgr->blue;
    return;
}
