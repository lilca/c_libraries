/**
 * コンソールウィンドウクラスのソース
 * @fileS
 */
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
    return;
}

void ConsoleWindow_show(ConsoleWindow* win) {
    //
    for (int jdx=0; jdx<win->height; jdx++) {
        for (int idx=0; idx<win->width; idx++) {
            ESC_moveCur(win->x+idx, win->y+jdx);
            putchar(win->text[idx + jdx * win->width]);
        }
    } 
    // frame
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
    return;
}

void ConsoleWindow_addField(ConsoleWindow* win, CWField* field) {
    if (MAX_OF_CW_FIELD <= win->fields)
        return;
    win->fieldList[win->fields] = field;
    win->field += 1;
    return;
}

