/**
 * コンソールアプリクラスのソース
 * @file
 */
 #include "console_app.h"

ConsoleApp* ConsoleApp_new() {
    ConsoleApp* app = malloc(sizeof(ConsoleApp));
    ConsoleApp_init(app);
    return app;
}

void ConsoleApp_init(ConsoleApp* app) {
    for (int idx=0; idx<MAX_OF_CAPP_WINS; idx++) {
        app->winList[idx] = NULL;
    }
    app->activeWin = 0;
    return;
}

void ConsoleApp_free(ConsoleApp* app) {
    for (int idx=0; idx<MAX_OF_CAPP_WINS; idx++) {
        if (app->winList[idx] != NULL)
            ConsoleWindow_free(app->winList[idx]);
    }
    free(app);
    return;
}

void ConsoleApp_print(ConsoleApp* app) {

}




void ConsoleApp_addWindow(ConsoleApp* app, ConsoleWindow* win) {
    int count = ConsoleApp_countOfWindows(app);
    app->winList[coount] = win;
}

int ConsoleApp_run(ConsoleApp* app) {

}

int ConsoleApp_countOfWindows(ConsoleApp* app) {
    for (int idx=0; idx<MAX_OF_CAPP_WINS; idx++) {
        if (app->winList[idx] != NULL)
            return idx;
    }
    return MAX_OF_CAPP_WINS;
}