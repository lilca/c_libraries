/**
 * コンソールウィンドウのフィールドのインクルード
 * @file
 */

#ifndef CW_FIELD_H
#define CW_FIELD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "console.h"

/**
 * コンソールウィンドウのフィールドタイプの列挙型
*/
typedef enum {
    CWFT_NUMBER,
    CWFT_TEXT,
} CWFieldType;

/**
 * コンソールウィンドウのフィールドタイプの列挙型
*/
typedef enum {
    CWFA_LEFT,
    CWFA_RIGHT,
    CWFA_CENTER,
} CWFieldAlign;

/**
 * コンソールウィンドウのフィールドタイプの構造体
*/
typedef struct {
    bool bold;
    bool blink;
    bool italic;
    bool underLine;
} CWAttr;

/**
 * コンソールウィンドウのフィールドの構造体
*/
typedef struct {
    uint16 id;
    uint16 x;
    uint16 y;
    uint16 len;
    char* value;
    CWFieldType type;
    CWAttr attr;
    int fColor;
    int bColor;
} CWField;

/**
 * コンソールウィンドウのフォールドのコンストラクタ
 * @param[in] id フィールドID
 * @param[in] x フィールドのX座標
 * @param[in] y フィールドのY座標
 * @return CWField* コンソールウィンドウインスタンス
 */
CWField* CWField_new(int id, int x, int y);
/**
 * コンソールウィンドウのフィールドのイニシャライザ
 * @param[in] field CWField型のポインタ
 * @param[in] x フィールドのX座標
 * @param[in] y フィールドのY座標
 * @param[in] value フィールドの幅
 * @return なし
 */
void CWField_init(CWField* field, void* value);
/**
 * コンソールウィンドウのフィールドのデストラクタ
 * @param[in] field CWField型のポインタ
 * @return なし
 */
void CWField_free(CWField* field);
/**
 * コンソールウィンドウのフィールド内の情報を標準出力
 * @param[in] field CWField型のポインタ
 * @return なし
 */
void CWField_print(CWField* field);

/**
 * コンソールウィンドウのフィールド内の情報を標準出力
 * @param[in] field CWField型のポインタ
 * @param[in] value 設定する値
 * @return なし
 */
void CWField_setValue(CWField* field, const char* value);


#endif
