/**
 * コンソールアプリのインクルード
 * @file
 */

#ifndef CONSOLE_APP_H
#define CONSOLE_APP_H

/// コンソールアプリの最大ウィンドウ数
#define MAX_OF_CAPP_WINS 256


typedef struct {
    ConsoleWindow* winList[MAX_OF_CAPP_WINS];
    int activeWin;
} ConsoleApp;

/**
 * コンソールアプリのコンストラクタ
 * @return ConsoleApp* コンソールアプリインスタンス
 */
ConsoleApp* ConsoleApp_new();
/**
 * コンソールアプリのコンストラクタ
 * @param[in] app ConsoleApp型のポインタ
 * @return なし
 */
void ConsoleApp_init(ConsoleApp* app);
/**
 * コンソールアプリのデストラクタ
 * @param[in] app ConsoleApp型のポインタ
 * @return なし
 */
void ConsoleApp_free(ConsoleApp* app);
/**
 * コンソールアプリ内の情報を標準出力
 * @param[in] app ConsoleApp型のポインタ
 * @return なし
 */
void ConsoleApp_print(ConsoleApp* app);



/**
 * コンソールアプリにウィンドウ追加
 * @param[in] app ConsoleApp型のポインタ
 * @param[in] win 追加するウィンドウ
 * @return なし
 */
void ConsoleApp_addWindow(ConsoleApp* app, ConsoleWindow* win);
/**
 * コンソールアプリ実行
 * @param[in] app ConsoleApp型のポインタ
 * @return result 実行結果
 */
int ConsoleApp_run(ConsoleApp* app);
/**
 * コンソールアプリのウィンドウ数取得
 * @param[in] app ConsoleApp型のポインタ
 * @return count ウィンドウw数
 */
int ConsoleApp_countOfWindows(ConsoleApp* app);

