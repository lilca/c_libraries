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
} ConsoleApp;

/**
 * コンソールアプリのコンストラクタ
 * @return ConsoleWindow* コンソールウィンドウインスタンス
 */
ConsoleApp* ConsoleApp_new();
/**
 * コンソールアプリのコンストラクタ
 * @return ConsoleWindow* コンソールウィンドウインスタンス
 */
ConsoleApp* ConsoleApp_init(ConsoleApp* app, ConsoleWindow* win);
