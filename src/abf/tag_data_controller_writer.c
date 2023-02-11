#include <stdio.h>

#include "../common/typedefs.h"
#include "tag_data_controller.h"
#include "tag_data_controller_writer.h"

int main(int aArgc, char** aArgs);
void fEditData(char* aBuffer, uint32* aSize);
void fCreateData();

TAG_ITEM item1;
char* title = "Black Angels";
uint32 bound = 1;
uint32 mono = 1;
uint32 zero = 1;
char buffer[268];
TAG_ITEM item2;
uint32 page = 1025;
TAG_ITEM item3;
char* exclude = "info.abf";

int main(int aArgc, char** aArgs){
  //! 出力ファイルのパス
  char* vOutputPath;
  //! 出力ファイルのファイル変数
  FILE* vOfp;

  // Get output path
  if( aArgc < 2 ){
    printf("ERROR: few parameter.\n");
    return -1;
  }
  vOutputPath = aArgs[1];
  // Open output path
  if( ( vOfp = fopen(vOutputPath, "wb") ) == NULL ){
    printf("ERROR: Can't open a file.(%s)\n", vOutputPath);
    return -1;
  }
  // Edit data
  uint32 length = 0;
  char* buffer = NULL;
  fEditData(buffer, &length);
  tagDataController_fwrite(vOfp);
  // Terminate
  free(buffer);
  fclose(vOfp);
  return 0;
}

void fEditData(char* aBuffer, uint32* aSize){
  /*[tir:begin] ref="#core" [tir:end]*/
  fCreateData();
  tagDataController_init();
  tagDataController_put(item1);
  tagDataController_put(item2);
  tagDataController_put(item3);
}

void fCreateData(){
  item1.nameId = 0;
  item1.length = 268;
  item1.data = buffer;
  for(int idx=0; idx<268; idx++) item1.data[idx] = 0;
  char* ptr = buffer;
  strcpy(ptr, title);
  ptr += 256;
  strncpy(ptr, (char*)&bound, 4);
  ptr += 4;
  strncpy(ptr, (char*)&mono, 4);
  ptr += 4;
  strncpy(ptr, (char*)&zero, 4);
  item2.nameId = 1;
  item2.length = 4;
  item2.data = (int8*)&page;
  item3.nameId = 2;
  item3.length = 8;
  item3.data = exclude;
}
