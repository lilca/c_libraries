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

/// コンソールウィンドウのX座標の初期値
#define CONSOLE_WIN_INIT_X 0

/// コンソールウィンドウのY座標の初期値
#define CONSOLE_WIN_INIT_Y 0

/* エスケープコード */
#define ESC "\x1b["

/* 色定義 */
#define ESC_CLR_BLACK   0 //黒
#define ESC_CLR_RED     1 //赤
#define ESC_CLR_GREEN   2 //緑
#define ESC_CLR_YELLOW  3 //黄
#define ESC_CLR_BLUE    4 //青
#define ESC_CLR_MZENDA  5 //赤紫（マゼンタ）
#define ESC_CLR_CYAN    6 //水色（シアン）
#define ESC_CLR_WHITE   7 //白
#define ESC_CLR_STDCLR  9 //標準色

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
 * コンソールウィンドウの構造体クラス
*/
typedef struct {
    uint16 x;
    uint16 y;
    uint16 width;
    uint16 height;
    uint8 frame[8];
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

#endif