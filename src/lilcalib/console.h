/**
 * コンソールウィンドウのインクルード
 * @file
 */

#ifndef CONSOLE_H
#define CONSOLE_H

#include "common.h"
#include "console/consoleio.h"

/* エスケープコード */
#define ESC "\x1b["

/* 色定義 */
typedef enum {
    CWC_BLACK  = 0, //黒
    CWC_RED    = 1, //赤
    CWC_GREEN  = 2, //緑
    CWC_YELLOW = 3, //黄
    CWC_BLUE   = 4, //青
    CWC_MZENDA = 5, //赤紫（マゼンタ）
    CWC_CYAN   = 6, //水色（シアン）
    CWC_WHITE  = 7, //白
    CWC_STDCLR = 9, //標準色
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
#define ESC_clearScreen() (printf("\x1b[2J"))
#define ESC_clearCur2End() (printf("\x1b[K"))
#define ESC_upCur(n) (printf("\x1b[%1dA",n))
#define ESC_downCur(n) (printf("\x1b[%1dB",n))
#define ESC_rightCur(n) (printf("\x1b[%1dC",n))
#define ESC_leftCur(n) (printf("\x1b[%1dD",n))
#define ESC_downFirstCur(n) (printf("\x1b[%1dE",n))
#define ESC_upLastCur(n) (printf("\x1b[%1dF",n))
#define ESC_movColCur(x) (printf("\x1b[%1dG",x))
#define ESC_moveCur(x,y) (printf("\x1b[%1d;%1dH",y+1,x+1))
#define ESC_invisibleCur() (printf("\x1b[>5h"))
#define ESC_visibleCur() (printf("\x1b[>5l"))

/* 文字強調 */
#define ESC_clearAttr() (printf("\x1b[0m"))
#define ESC_strongAttr() (printf("\x1b[1m"))
#define ESC_italicAttr() (printf("\x1b[3m"))
#define ESC_underlineAttr() (printf("\x1b[4m"))
#define ESC_blinkAttr() (printf("\x1b[5m"))
#define ESC_reverseAttr() (printf("\x1b[7m"))
#define ESC_secretAttr() (printf("\x1b[8m"))
#define ESC_fColorAttr(c) (printf("\x1b[3%1dm",c))
#define ESC_bColorAttr(c) (printf("\x1b[4%1dm",c))
#define ESC_setMode(m) (printf("\x1b[%1dm", m))


#endif