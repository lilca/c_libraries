#include <stdio.h>
#include "lilcalib/common.h"
#include "console.h"
#include "console_window.h"

int main()
{
    ConsoleWindow* win = ConsoleWindow_new(80, 24);
//    ConsoleWindow_move(win, 6, 2);

    CWField* field = CWField_new(0, 3, 5, "test");
    CWField_setValue(field, "ABV");
    field->attr.reverse = true;
    field->attr.blink = true;
//    CWField_putValue(field, 2, 2);
//    CWField_free(field);
    ConsoleWindow_addField(win, field);
    CWField* field2 = CWField_new(0, 3, 6, "yes!");
    CWField_setValue(field, "ABV");
    ConsoleWindow_addField(win, field2);
//    printf("@%d@",ConsoleWindow_countOfFields(win));
    ConsoleWindow_show(win);
    ESC_moveCur(3,5);
    ConsoleWindow_free(win);
    while(getch(false) != ' ');
    return TRUE;
}