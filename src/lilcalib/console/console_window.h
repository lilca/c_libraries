/**
 * コンソールウィンドウのインクルード
 * @file
 */

#ifndef CONSOLE_WINDOW_H
#define CONSOLE_WINDOW_H

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
#define MAX_OF_CW_FIELD 256


/**
 * コンソールウィンドウのクラス
*/
typedef struct {
    uint16 x;
    uint16 y;
    uint16 width;
    uint16 height;
    CWFrame frame;
    CWField* fieldList[MAX_OF_CW_FIELD];
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
/**
 * コンソールウィンドウのフィールド数
 * @param[in] win ConsoleWindow型のポインタ
 * @return ウィンドウのフィールド数
*/
int ConsoleWindow_countOfFields(ConsoleWindow* win);
/**
 * コンソールウィンドウのフィールド出力
 * @param[in] win ConsoleWindow型のポインタ
 * @param[in] fieldID 出力するフィールドID
 * @return なし
*/
void ConsoleWindow_putField(ConsoleWindow* win, int fieldID);

#endif