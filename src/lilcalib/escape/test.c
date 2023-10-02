#include <stdio.h>
#include "lilcalib/common.h"
#include "escape.h"

int main()
{
    ESC_print("", 9, 9, 0);
    printf("A");
    for(int idx=1; idx<10; idx++) {
        ESC_print("A", 9, 9, idx);
    }
    ESC_clearScreen();
    return TRUE;
}