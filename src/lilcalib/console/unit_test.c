#include <stdio.h>
#include "lilcalib/common.h"
#include "console.h"
#include "console_window.h"

int main()
{
    printf("\x1b[2J");
    ConsoleWindow* win = ConsoleWindow_new(80, 24);
    //ConsoleWindow_move(win, 3, 5);

    CWField* field = CWField_new(0, 3, 5);
    CWField_setValue(field, "test");
    ConsoleWindow_addField(win, field);
    ConsoleWindow_show(win);
    ConsoleWindow_free(win);
    while(getch(false) != ' ');
    return TRUE;
}