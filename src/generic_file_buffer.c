/**
 * 汎用のファイル行単位読み込み
 * @file
 */

#include <stdio.h>
#include <string.h>

/** @def
 * 汎用のバッファサイズ
 */
#define BUF_SIZE 256

int main(int aArgc, char** aArgs);
int fParseLine(const char* aLine);

/**
 * メイン関数
 * @brief メイン関数
 * @param [aArgc] コマンドラインからの引数の数
 * @param [aArgs] コマンドラインからの引数の文字列リスト
 * @return 0:正常終了、Other:異常終了
 * @sa 特になし
 * @detail メイン関数
 */
int main(int aArgc, char** aArgs){
  //! 入力ファイルのパス
  char* vInputPath;
  //! 入力ファイルのファイル変数
  FILE* vIfp;
  //! 入力ファイルから読込れた一行
  char vLine[BUF_SIZE];

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
  // Read lines
  while( fgets(vLine, BUF_SIZE, vIfp) != NULL ){
    fParseLine(vLine);
  }
  fclose(vIfp);
  // Terminate
  return 0;
}

/**
 * @fn
 * 一行ごとの処理を実行
 * @brief 一行ごとの処理を実行
 * @param (aLine) 一行のテキストデータ
 * @return 0:正常終了、Other:異常終了
 * @sa
 * @detail 一行ごとの処理を実行
 */
int fParseLine(const char* aLine){
  printf("%s",aLine);
  return 0;
}
