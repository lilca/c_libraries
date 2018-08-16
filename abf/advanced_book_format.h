#ifndef ADVANCED_BOOK_FORMAT_H
#define ADVANCED_BOOK_FORMAT_H

#define ABF_BOUND_LEFT_SIDE   0
#define ABF_BOUND_RIGHT_SIDE  1

#define ABF_MONOCHROME        0
#define ABF_COLOR             1

#define ABF_MAX_BOOKMARKS     100
#define ABF_MAX_EXCLUDES      100

#include "../common/typedefs.h"


typedef struct{
  int8 title[256];
  uint32 bound;
  uint32 monochrome;
  uint32 zero_page;
} ABF_HEADER;

typedef struct{
  uint32 bookmarks[ABF_MAX_BOOKMARKS];
  uint32 bookmarkSize;
} ABF_BOOKMARKS;

typedef struct{
  int8* excludeList[ABF_MAX_EXCLUDES];
  uint32 excludeListSize;
} ABF_EXCLUDE;

#endif
