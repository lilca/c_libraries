/**
 * コンソールウィンドウのインクルード
 * @file
 */

#ifndef CONSOLE_WINDOW_H
#define CONSOLE_WINDOW_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lilcalib/common.h"
#include "lilcalib/console.h"
#include "cw_frame.h"
#include "cw_field.h"

/// コンソールウィンドウのX座標の初期値
#define CONSOLE_WIN_INIT_X 0

/// コンソールウィンドウのY座標の初期値
#define CONSOLE_WIN_INIT_Y 0

/// コンソールウィンドウの最大フィールド数
#define MAX_OF_CWIN_FIELDS 256


/**
 * コンソールウィンドウのクラス
*/
typedef struct {
    uint16 x;
    uint16 y;
    uint16 width;
    uint16 height;
    uint16 focusFieldID;
    CWFrame frame;
    CWField* fieldList[MAX_OF_CWIN_FIELDS];
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
void ConsoleWindow_init(ConsoleWindow* win, int x, int y);
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
 * @param[in] frame フレーム文字群
 * @return なし
*/
void ConsoleWindow_setFrame(ConsoleWindow* win, CWFrame frame);

/**
 * コンソールウィンドウのコーナー変更（個別）
 * @param[in] win ConsoleWindow型のポインタ
 * @param[in] field フィールド
 * @return なし
*/
void ConsoleWindow_addField(ConsoleWindow* win, CWField* field);
/**
 * コンソールウィンドウのフィールド数
 * @param[in] win ConsoleWindow型のポインタ
 * @return ウィンドウのフィールド数
*/
int ConsoleWindow_countOfFields(ConsoleWindow* win);

#endif