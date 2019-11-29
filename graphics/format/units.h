#ifndef GRAPHICS_FORMAT_UNITS
#define GRAPHICS_FORMAT_UNITS

#include <stdio.h>
#include <stdlib.h>

#include <common/typedefs.h>

struct __attribute__ ((__packed__)) _fARGB {
    float64 alpha;
    float64 red;
    float64 green;
    float64 blue;
};
typedef struct _fARGB fARGB;

struct __attribute__ ((__packed__)) _BGRA {
    uint8 blue;
    uint8 green;
    uint8 red;
    uint8 alpha;
};
typedef struct _BGRA BGRA;

struct __attribute__ ((__packed__)) _BGR {
    uint8 blue;
    uint8 green;
    uint8 red;
};
typedef struct _BGR BGR;

fARGB* fARGB_new(void);
BGRA* BGRA_new(void);
BGR* BGR_new(void);
void fARGB_init(fARGB* fargb);
void BGRA_init(BGRA* bgra);
void BGR_init(BGR* bgr);
void fARGB_toGray(fARGB* fargb);
void BGRA_toGray(BGRA* bgra);
void BGR_toGray(BGR* bgr);

void fARGB_toBGRA(fARGB* fargb, BGRA* bgra);
void fARGB_toBGR(fARGB* fargb, BGR* bgr);
void BGRA_tofARGB(BGRA* bgra, fARGB* fargb);
void BGRA_toBGR(BGRA* bgra, BGR* bgr);
void BGR_tofARGB(BGR* bgr, fARGB* fargb);
void BGR_toBGRA(BGR* bgr, BGRA* bgra);

#endif