/**
 * コンソールウィンドウのフィールドのソース
 * @file
 */
#include "cw_field.h"

void _setValue(char** target, const char* value);


CWField* CWField_new(int id, int x, int y, const char* defValue) {
    CWField* res = malloc(sizeof(CWField));
    res->id = id;
    res->x = x;
    res->y = y;
    res->defValue = NULL;
    res->value = NULL;
    CWField_init(res, defValue);
    return res;
}
void CWField_init(CWField* field, const char* value) {
    field->length = 1;
    field->type = CWFT_TEXT;
    field->attr.bold = false;
    field->attr.italic = false;
    field->attr.blink = false;
    field->attr.underLine = false;
    field->fColor = CWC_STDCLR;
    field->bColor = CWC_STDCLR;
    CWField_setDefValue(field, value);
    return;
}
void CWField_free(CWField* field) {
    if (field == NULL)
        return;
    if (field->value != NULL)
        free(field->value);
    free(field);
    return;
}
void CWField_print(CWField* field) {
}

void CWField_setDefValue(CWField* field, const char* defValue) {
    int len = strlen(defValue);
    if (field->length < len) {
        field->length = len;
    }
    _setValue(&(field->defValue), defValue);
    _setValue(&(field->value), defValue);
}
void CWField_setValue(CWField* field, const char* value) {
    _setValue(&(field->value), value);
}
void CWField_putValue(CWField* field, int x, int y) {
    char* val = field->value;
    if (val == NULL) {
        return;
    }
    for (int idx=0; idx<strlen(val) && idx<field->length; idx++) {
        ESC_moveCur(x + field->x + idx, y + field->y);
        putchar((int)(field->value[idx]));
    }
}


// Private functions
void _setValue(char** target, const char* value) {
    if (*target != NULL) {
        free(*target);
    }
    int len = strlen(value);
    *target = malloc(len + 1);
    memcpy(*target, value, len+1);
    return;
}