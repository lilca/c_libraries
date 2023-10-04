#include <stdio.h>
#include "lilcalib/common.h"
#include "console.h"
#include "console_window.h"

int main()
{
    printf("\x1b[2J");
    ConsoleWindow* win = ConsoleWindow_new(80, 24);
    //ConsoleWindow_move(win, 3, 5);

    ConsoleWindow_show(win);
    while(getch(false) != ' ');
    ConsoleWindow_free(win);
    return TRUE;
}