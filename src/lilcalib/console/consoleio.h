/**
 * コンソール入力のインクルード
 * @file
 */

#ifndef CONSOLE_IO_H
#define CONSOLE_IO_H

#include <stdio.h>
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>

/**
 * コンソール入力
 * @param[in] echo エコーあり:true, なし:false
 * @return int 入力文字
 */
int getch(bool echo);

#endif
