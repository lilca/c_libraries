/**
 * 汎用のファイル一括読み込み
 * @file
 */

#include <stdio.h>
#include <string.h>

#include "typedefs.h"

int main(int aArgc, char** aArgs);
int fParseLine(const char* aBuffer, uint64 aSize);

//! 入力ファイルのデータ
char* vBuffer;
//! 入力ファイルのサイズ
uint32 vFileSize = 0;

/**
 * メイン関数
 * @param[in] aArgc コマンドラインからの引数の数
 * @param[in] aArgs コマンドラインからの引数の文字列リスト
 * @return 0:正常終了、Other:異常終了
 * @details 特になし
 */
int main(int aArgc, char** aArgs){
  // 入力ファイルのパス
  char* vInputPath;
  // 入力ファイルのファイル変数
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
 * データストリングをまとめて処理する
 * @param (aBuffer) データポインタ
 * @param (aSize) データ長
 * @return 0:正常終了、Other:異常終了
 * @details 詳細：データストリングをまとめて処理する
 */
int fParseLine(const char* aBuffer, uint64 aSize){
  /*[tir:begin] ref="#core" [tir:end]*/
  return 0;
}
