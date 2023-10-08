/**
 * コンソールウィンドウクラスのソース
 * @file
 */
#include <stdio.h>
#include <string.h>
#include "console_window.h"

/// コンソールウィンドウのフレームの初期値
CWFrame CONSOLE_WIN_INIT_FRAME = {'-', 'o', '/', '*', ' ', 'a', '\\', 'C'};

ConsoleWindow* ConsoleWindow_new(int width, int height) {
    ConsoleWindow* res = malloc(sizeof(ConsoleWindow));
    res->width = width;
    res->height = height;
    ConsoleWindow_init(res, 0, 0);
    return res;
}

void ConsoleWindow_init(ConsoleWindow* win, int x , int y) {
    win->x = x;
    win->y = y;
    memcpy(&(win->frame), &CONSOLE_WIN_INIT_FRAME, sizeof(CWFrame));
    win->text = (uint8*)malloc(win->width * win->height);
    for (int idx=0; idx<win->width * win->height; idx++) {
        win->text[idx] = ' ';
    }
    return;
}

void ConsoleWindow_free(ConsoleWindow* win) {
    if (win == NULL)
        return;
    if (win->text != NULL)
        free(win->text);
    free(win);
    return;
}

void ConsoleWindow_print(ConsoleWindow* win) {
    printf("-- ConsoleWindow -------------\n");
    printf("Width = %d\n", win->width);
    printf("Height = %d\n", win->height);
    printf("Text = %s\n", win->text);
    printf("--------------------\n");
    return;
}


void ConsoleWindow_move(ConsoleWindow* win, int x, int y) {
    win->x += x;
    win->y += y;
    ESC_clearScreen();
    return;
}

void ConsoleWindow_show(ConsoleWindow* win) {
    // BackGround
    for (int jdx=0; jdx<win->height; jdx++) {
        for (int idx=0; idx<win->width; idx++) {
            ESC_moveCur(win->x+idx, win->y+jdx);
            putchar(win->text[idx + jdx * win->width]);
        }
    }

    // frames
    for (int idx=0; idx<win->width; idx++) {
        // Top
        if (win->text[idx] == ' ') {
            ESC_moveCur(win->x+idx, win->y);
            putchar(win->frame.top);
        }
        // Bottom
        if (win->text[idx + (win->height-1) * win->width] == ' ') {
            ESC_moveCur(win->x+idx, win->y+win->height-1);
            putchar(win->frame.bottom);
        }
    }
    for (int idx=0; idx<win->height; idx++) {
        // Left
        if (win->text[idx*win->height] == ' ') {
            ESC_moveCur(win->x, win->y+idx);
            putchar(win->frame.left);
        }
        // Right
        if (win->text[idx*win->height + (win->width-1)] == ' ') {
            ESC_moveCur(win->x+win->width-1, win->y+idx);
            putchar(win->frame.right);
        }
    }
    if (win->text[0] == ' ') {
        ESC_moveCur(win->x, win->y);
        putchar(win->frame.topLeft);
    }
    if (win->text[win->width-1] == ' ') {
        ESC_moveCur(win->x+win->width-1, win->y);
        putchar(win->frame.topRight);
    }
    if (win->text[(win->height-1) * win->width] == ' ') {
        ESC_moveCur(win->x, win->y+win->height-1);
        putchar(win->frame.bottomLeft);
    }
    if (win->text[(win->height-1) * win->width+ win->width-1] == ' ') {
        ESC_moveCur(win->x+win->width-1, win->y+win->height-1);
        putchar(win->frame.bottomRight);
    }

    // Fields
    for (int idx=0; idx<ConsoleWindow_countOfFields(win); idx++) {
        CWField_putValue(win->fieldList[idx], win->x, win->y);
    }
    return;
}

void ConsoleWindow_setFrame(ConsoleWindow* win, CWFrame frame) {
    win->frame.top = frame.top;
    win->frame.left = frame.left;
    win->frame.bottom = frame.bottom;
    win->frame.right = frame.right;
    win->frame.topLeft = frame.topLeft;
    win->frame.bottomLeft = frame.bottomLeft;
    win->frame.bottomRight = frame.bottomRight;
    win->frame.topRight = frame.topRight;
}


void ConsoleWindow_addField(ConsoleWindow* win, CWField* field) {
    int count = ConsoleWindow_countOfFields(win);
    if (MAX_OF_CWIN_FIELDS <= count)
        return;
    win->fieldList[count] = field;
    return;
}

int ConsoleWindow_countOfFields(ConsoleWindow* win) {
    for (int idx=0; idx<MAX_OF_CWIN_FIELDS; idx++) {
        if (win->fieldList[idx] == NULL)
            return idx;
    }
    return MAX_OF_CWIN_FIELDS;
}
