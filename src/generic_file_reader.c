/**
 * @file generic_file_buffer.c
 * @brief 汎用のファイルバッファ
 * @author lilca
 * @date 2017/1/20
 */

#include <stdio.h>
#include <string.h>

#include "typedefs.h"

int main(int aArgc, char** aArgs);
int fParseLine(const char* aBuffer, uint32 aSize);

//! 入力ファイルのデータ
char* vBuffer;
//! 入力ファイルのサイズ
uint32 vFileSize = 0;

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
  if( ( vIfp = fopen(vInputPath, "r") ) == NULL ){
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
  free(vBuffer);
  fclose(vIfp);
  // Terminate
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
int fParseLine(const char* aBuffer, uint64 aSize){
  /*[tir:begin] ref="#core" [tir:end]*/
  return 0;
}
