#include "advanced_book_format.h"

ABF_HEADER header;
ABF_BOOKMARKS bookmarks;
ABF_EXCLUDE excludes;

void advancedBookFormat_getHeader(int8* ptr){
  strcpy(header.title, ptr);
  header.bound       = *((uint32*)(ptr+256));
  header.monochrome  = *((uint32*)(ptr+256));
  header.zero_page   = *((uint32*)(ptr+256));
}

void advancedBookFormat_getBookmark(int8* ptr, uint16 size){
  uint64 offset = 0;
  for(int idx=0; idx<size; idx++){
    bookmarks.bookmarks[idx] = *(uint32)(ptr+offset);
    offset += sizeof(uint32);
  }
  res.bookmarkSize = size;
  return res;
}

void advancedBookFormat_getExclude(int8* ptr, uint16 size){
  excludes.excludeList[excludes.excludeListSize] = ptr;
  excludes.excludeListSize++;
}
