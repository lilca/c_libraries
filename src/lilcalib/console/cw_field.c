/**
 * コンソールウィンドウのフィールドのソース
 * @file
 */
#include "cw_field.h"

CWField* CWField_new(int id, int x, int y) {
    CWField* res = malloc(sizeof(CWField));
    res->id = id;
    res->x = x;
    res->y = y;
    CWField_init(res, NULL);
    return res;
}
void CWField_init(CWField* field, void* value) {
    field->len = 1;
    field->value = value;
    field->type = CWFT_TEXT;
    field->attr.bold = false;
    field->attr.italic = false;
    field->attr.blink = false;
    field->attr.underLine = false;
    field->fColor = CWC_STDCLR;
    field->bColor = CWC_STDCLR;

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

void CWField_setValue(CWField* field, const char* value) {
    if (field->value != NULL)
        free(field->value);
    int len = strlen(value);
    field->value = malloc(len + 1);
    strncpy(field->value, value, len+1);
    return;
}