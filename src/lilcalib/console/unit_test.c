#include <stdio.h>
#include "lilcalib/common.h"
#include "console.h"

int main()
{
    printf("\x1b[2J");
    ConsoleWindow* win = ConsoleWindow_new(9, 3);
    ConsoleWindow_move(win, 3, 5);

    ConsoleWindow_show(win);
    while(getchar() != ' ');
    ConsoleWindow_free(win);
    return TRUE;
}