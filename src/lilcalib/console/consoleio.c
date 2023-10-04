/**
 * コンソールウィンドウのフレームのソース
 * @file
 */

#include "consoleio.h"

int getch(bool echo) {
    int res;
    struct termios old, new;
    tcgetattr(STDIN_FILENO, &old);
    new = old;
    if (echo) {
        new.c_lflag &= ~(ICANON);
    } else {
        new.c_lflag &= ~(ICANON | ECHO);
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &new);
    res = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &old);
    return res;
}
