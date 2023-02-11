#ifndef TAG_DATA_CONTROLLER_H
#define TAG_DATA_CONTROLLER_H

#include <stdio.h>
#include <string.h>
#include "../common/typedefs.h"

typedef struct{
  int16 nameId;
  uint64 length;
  int8* data;
} TAG_ITEM;

#define ERROR                   -1
#define NORMAL                  0
#define MAX_TAG_LIST_SIZE       100

int8* tagDataController_getTagName(int16 id);
void tagDataController_init();
uint16 tagDataController_getSize();
int16 tagDataController_put(TAG_ITEM item);
TAG_ITEM tagDataController_get(int16 index);
int16 tagDataController_parse(const int8* ptr, uint64 length);
int16 tagDataController_fwrite(FILE* fp);

#endif
