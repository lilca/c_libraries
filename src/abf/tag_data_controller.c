#include "tag_data_controller.h"

#define TAG_NAMES 3

int16 parseTagName(int8* ptr);

int8* tagNames[] = {
  "HEADER  ",
  "BOOKMARK",
  "EXCLUDE ",
  ""
};

TAG_ITEM tagList[MAX_TAG_LIST_SIZE];
uint16  tagListSize = 0;

int8* tagDataController_getTagName(int16 id){
  if( id < 0 )
    return NULL;
  return tagNames[id];
}

void tagDataController_init(){
  for(int16 idx=0; idx<MAX_TAG_LIST_SIZE; idx++){
    tagList[idx].nameId = ERROR;
  }
  tagListSize = 0;
}

uint16 tagDataController_getSize(){
  return tagListSize;
}

int16 tagDataController_put(TAG_ITEM item){
  if( tagListSize >= MAX_TAG_LIST_SIZE )
    return ERROR;
  tagList[tagListSize] = item;
  tagListSize++;
  return NORMAL;
}

TAG_ITEM tagDataController_get(int16 index){
  if( index >= tagListSize || index < 0 ){
    TAG_ITEM res;
    res.nameId = ERROR;
    return res;
  }
  return tagList[index];
}

int16 tagDataController_parse(const int8* ptr, uint64 length){
  tagListSize = 0;
  if( length <= 0 )
    return ERROR;
  int8* start = (int8*)ptr;
  int8* cur = (int8*)ptr;
  while( length > (cur - start) ){
    // TagName
    int16 tagId = parseTagName(cur);
    tagList[tagListSize].nameId = tagId;
    if( tagId < 0 )
      return ERROR;
    cur += 8;

    // Tag Length
    tagList[tagListSize].length = *((uint64*)cur);
    cur += 8;

    // Tag Data
    tagList[tagListSize].data = cur;
    cur += tagList[tagListSize].length;
    //
    tagListSize++;
  }
  return NORMAL;
}

int16 tagDataController_fwrite(FILE* fp){
  for(int idx=0; idx<tagListSize; idx++){
    if( tagList[idx].nameId == ERROR )
      continue;
    fwrite(tagDataController_getTagName(tagList[idx].nameId), sizeof(int8), 8, fp);
    fwrite(&tagList[idx].length, sizeof(uint64), 1, fp);
    fwrite(tagList[idx].data, sizeof(int8), tagList[idx].length, fp);
  }
  return NORMAL;
}

int16 parseTagName(int8* ptr){
  for(int16 idx=0; idx<TAG_NAMES; idx++){
    if( strncmp(ptr, tagNames[idx], 8) == 0 )
      return idx;
  }
  return ERROR;
}
