/**
 * @file generic_file_buffer.c
 * @brief 汎用のファイルバッファ
 * @author lilca
 * @date 2017/1/20
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/typedefs.h"
#include "tag_data_controller.h"

int main(int aArgc, char** aArgs);
int fParseData(const char* aBuffer, uint64 aSize);

//! 入力ファイルのデータ
char* vBuffer;
//! 入力ファイルのサイズ
int64 vFileSize = 0;

/**
 * @fn
 * メイン関数
 * @brief メイン関数
 * @param (aArgc) コマンドラインからの引数の数
 * @param (aArgs) コマンドラインからの引数の文字列リスト
 * @return 0:正常終了、Other:異常終了
 * @sa
 * @detail メイン関数
 */
int main(int aArgc, char** aArgs){
  //! 入力ファイルのパス
  char* vInputPath;
  //! 入力ファイルのファイル変数
  FILE* vIfp;

  // Get input path
  if( aArgc < 2 ){
    printf("ERROR: few parameter.\n");
    return -1;
  }
  vInputPath = aArgs[1];
  // Open input path
  if( ( vIfp = fopen(vInputPath, "rb") ) == NULL ){
    printf("ERROR: Can't open a file.(%s)\n", vInputPath);
    return -1;
  }
  // Get file size
  fseek(vIfp, 0, SEEK_END);
  fgetpos(vIfp, &vFileSize);
  fseek(vIfp, 0, SEEK_SET);
  // Allocate memory
  vBuffer = malloc(vFileSize);
  // Read file data
  fread(vBuffer, 1, vFileSize, vIfp);
  // Parse file data
  fParseData(vBuffer, vFileSize);
  // Terminate
  free(vBuffer);
  fclose(vIfp);
  return 0;
}

/**
 * @fn
 * データストリングをまとめて処理する
 * @brief データストリングをまとめて処理する
 * @param (aBuffer) データポインタ
 * @param (aSize) データ長
 * @return 0:正常終了、Other:異常終了
 * @sa
 * @detail データストリングをまとめて処理する
 */
int fParseData(const char* aBuffer, uint64 aSize){
  /*[tir:begin] ref="#core" [tir:end]*/
  tagDataController_init();
  tagDataController_parse(aBuffer, aSize);
  int len = tagDataController_getSize();
  TAG_ITEM item;
  for(int idx=0; idx<len; idx++){
    item = tagDataController_get(idx);
    printf("%s, %lld\n",tagDataController_getTagName(item.nameId), item.length);
  }
  return 0;
}
