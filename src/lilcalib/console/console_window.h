/**
 * コンソールウィンドウのインクルード
 * @file
 */

#ifndef CONSOLE_H
#define CONSOLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common.h"
#include "console.h"
#include "cw_frame.h"
#include "cw_field.h"

/// コンソールウィンドウのX座標の初期値
#define CONSOLE_WIN_INIT_X 0

/// コンソールウィンドウのY座標の初期値
#define CONSOLE_WIN_INIT_Y 0

/// コンソールウィンドウの最大フィールド数
#define MAX_OF_CW_FIELD 256;

/* エスケープコード */
#define ESC "\x1b["

/* 色定義 */
typedef enum {
    BLACK  = 0, //黒
    RED    = 1, //赤
    GREEN  = 2, //緑
    YELLOW = 3, //黄
    BLUE   = 4, //青
    MZENDA = 5, //赤紫（マゼンタ）
    CYAN   = 6, //水色（シアン）
    WHITE  = 7, //白
    STDCLR = 9, //標準色
} CWColor;

/* 属性定義 */
#define ESC_MODE_RESET   0 //属性リセット
#define ESC_MODE_BOLD    1 //太文字
#define ESC_MODE_LOW     2 //低輝度
#define ESC_MODE_ITALIC  3 //イタリック
#define ESC_MODE_UNDER   4 //下線
#define ESC_MODE_BLINK   5 //点滅
#define ESC_MODE_HBLINK  6 //高速点滅
#define ESC_MODE_REVERSE 7 //反転
#define ESC_MODE_SECRET  8 //隠す
#define ESC_MODE_CANCEL  9 //取消線
/*
[2   //画面クリア
[K	  //カーソル位置から行末までをクリア 
[nA  //カーソルを上にn行移動
[nB  //カーソルを下にn行移動
[nC  //カーソルを右にn桁移動
[nD  //カーソルを左にn桁移動
[r;cH  //カーソルをr行のn桁目に移動
*/

/*
[0m	//属性を標準に戻す
[1m	//強調（太字）
[4m	//下線
[7m	//反転
[3m	//文字色（前景色または背景色）を指定
*/

/*
void ESC_print(char* str, int fClr, int bClr, int mode)
{
    ESC_clearAttr();
    ESC_setMode(mode);
    ESC_fColorAttr(fClr);
    ESC_bColorAttr(bClr);
    printf("%s", str);
    return;
}
*/

/**
 * コンソールウィンドウのクラス
*/
typedef struct {
    uint16 x;
    uint16 y;
    uint16 width;
    uint16 height;
    CWFrame frame;
    CWField fieldList[MAX_OF_CW_FIELD];
    uint8* text;
} ConsoleWindow;

/**
 * コンソールウィンドウのコンストラクタ
 * @param[in] width ウィンドウの幅
 * @param[in] height ウィンドウの高さ
 * @return ConsoleWindow* コンソールウィンドウインスタンス
 */
ConsoleWindow* ConsoleWindow_new(int width, int height);
/**
 * コンソールウィンドウのイニシャライザ
 * @param[in] win ConsoleWindow型のポインタ
 * @param[in] x ウィンドウのX座標
 * @param[in] y ウィンドウのY座標
 * @param[in] width ウィンドウの幅
 * @param[in] height ウィンドウの高さ
 * @return なし
 */
void ConsoleWindow_init(ConsoleWindow* win, int x, int y, int width, int height);
/**
 * コンソールウィンドウのデストラクタ
 * @param[in] win ConsoleWindow型のポインタ
 * @return なし
 */
void ConsoleWindow_free(ConsoleWindow* win);
/**
 * コンソールウィンドウ内の情報を標準出力
 * @param[in] win ConsoleWindow型のポインタ
 * @return なし
 */
void ConsoleWindow_print(ConsoleWindow* win);


/**
 * コンソールウィンドウの移動
 * @param[in] win ConsoleWindow型のポインタ
 * @param[in] x 移動方向のX座標
 * @param[in] y 移動方向のY座標
 * @return なし
*/
void ConsoleWindow_move(ConsoleWindow* win, int x, int y);
/**
 * コンソールウィンドウの表示
 * @param[in] win ConsoleWindow型のポインタ
 * @return なし
*/
void ConsoleWindow_show(ConsoleWindow* win);
/**
 * コンソールウィンドウのフレーム変更（１種類）
 * @param[in] win ConsoleWindow型のポインタ
 * @param[in] chr フレーム文字
 * @return なし
*/
void ConsoleWindow_setFrameAll(ConsoleWindow* win, char chr);
/**
 * コンソールウィンドウのコーナー変更（１種類）
 * @param[in] win ConsoleWindow型のポインタ
 * @param[in] chr コーナー文字
 * @return なし
*/
void ConsoleWindow_setCornorAll(ConsoleWindow* win, char chr);
/**
 * コンソールウィンドウのフレーム変更（個別）
 * @param[in] win ConsoleWindow型のポインタ
 * @param[in] chr フレーム文字列(上左下右)
 * @return なし
*/
void ConsoleWindow_setFrame(ConsoleWindow* win, char chr);
/**
 * コンソールウィンドウのコーナー変更（個別）
 * @param[in] win ConsoleWindow型のポインタ
 * @param[in] chr コーナー文字
 * @return なし
*/
void ConsoleWindow_setCornor(ConsoleWindow* win, char chr);

/**
 * コンソールウィンドウのコーナー変更（個別）
 * @param[in] win ConsoleWindow型のポインタ
 * @param[in] field フィールド
 * @return なし
*/
void ConsoleWindow_addField(ConsoleWindow* win, CWField* field);

#endif