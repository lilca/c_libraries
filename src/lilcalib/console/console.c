/**
 * コンソールウィンドウクラスのソース
 * @file
 */
#include "console.h"

#define ESC_clearScreen() (printf("\x1b[2J"))
#define ESC_clearCur2End() (printf("\x1b[K"))
#define ESC_upCur(n) (printf("\x1b[%1dA",n))
#define ESC_downCur(n) (printf("\x1b[%1dB",n))
#define ESC_rightCur(n) (printf("\x1b[%1dC",n))
#define ESC_leftCur(n) (printf("\x1b[%1dD",n))
#define ESC_downFirstCur(n) (printf("\x1b[%1dE",n))
#define ESC_upLastCur(n) (printf("\x1b[%1dF",n))
#define ESC_movColCur(x) (printf("\x1b[%1dG",x))
#define ESC_moveCur(x,y) (printf("\x1b[%1d;%1dH",y+1,x+1))
#define ESC_invisibleCur() (printf("\x1b[>5h"))
#define ESC_visibleCur() (printf("\x1b[>5l"))

/* 文字強調 */
#define ESC_clearAttr() (printf("\x1b[0m"))
#define ESC_strongAttr() (printf("\x1b[1m"))
#define ESC_underlineAttr() (printf("\x1b[4m"))
#define ESC_reverAttr() (printf("\x1b[7m"))
#define ESC_fColorAttr(c) (printf("\x1b[3%1dm",c))
#define ESC_bColorAttr(c) (printf("\x1b[4%1dm",c))
#define ESC_setMode(m) (printf("\x1b[%1dm", m))

/* フレーム位置 */
#define FRAME_TOP       0
#define FRAME_LEFT      1
#define FRAME_BOTTOM    2
#define FRAME_RIGHT     3
#define FRAME_CORNOR_TL 4
#define FRAME_CORNOR_BL 5
#define FRAME_CORNOR_BR 6
#define FRAME_CORNOR_TR 7

/// コンソールウィンドウのフレームの初期値
const uint8 CONSOLE_WIN_INIT_FRAME[] = {'=', '|', '-', '@', '*', '\\', '/', '>'};


ConsoleWindow* ConsoleWindow_new(int width, int height) {
    ConsoleWindow* res = malloc(sizeof(ConsoleWindow));
    ConsoleWindow_init(res, 0, 0, width, height);
    return res;
}

void ConsoleWindow_init(ConsoleWindow* win, int x , int y, int width, int height) {
    win->x = x;
    win->y = y;
    win->width = width;
    win->height = height;
    memcpy(win->frame, CONSOLE_WIN_INIT_FRAME, 8);
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
            putchar(win->frame[FRAME_TOP]);
        }
        // Bottom
        if (win->text[idx + (win->height-1) * win->width] == ' ') {
            ESC_moveCur(win->x+idx, win->y+win->height-1);
            putchar(win->frame[FRAME_BOTTOM]);
        }
    }
    for (int idx=0; idx<win->height; idx++) {
        // Left
        if (win->text[idx*win->height] == ' ') {
            ESC_moveCur(win->x, win->y+idx);
            putchar(win->frame[FRAME_LEFT]);
        }
        // Right
        if (win->text[idx*win->height + (win->width-1)] == ' ') {
            ESC_moveCur(win->x+win->width-1, win->y+idx);
            putchar(win->frame[FRAME_RIGHT]);
        }
    }
    if (win->text[0] == ' ') {
        ESC_moveCur(win->x, win->y);
        putchar(win->frame[FRAME_CORNOR_TL]);
    }
    if (win->text[win->width-1] == ' ') {
        ESC_moveCur(win->x+win->width-1, win->y);
        putchar(win->frame[FRAME_CORNOR_TR]);
    }
    if (win->text[(win->height-1) * win->width] == ' ') {
        ESC_moveCur(win->x, win->y+win->height-1);
        putchar(win->frame[FRAME_CORNOR_BL]);
    }
    if (win->text[(win->height-1) * win->width+ win->width-1] == ' ') {
        ESC_moveCur(win->x+win->width-1, win->y+win->height-1);
        putchar(win->frame[FRAME_CORNOR_BR]);
    }
}
