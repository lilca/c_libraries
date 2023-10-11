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
#include "lilcalib/console.h"

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
    bool italic;
    bool blink;
    bool underLine;
    bool reverse;
    bool secret;
} CWAttr;

/**
 * コンソールウィンドウのフィールドの構造体
*/
typedef struct {
    uint16 id;
    uint16 x;
    uint16 y;
    uint16 length;
    char* defValue;
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
CWField* CWField_new(int id, int x, int y, const char* defValue);
/**
 * コンソールウィンドウのフィールドのイニシャライザ
 * @param[in] field CWField型のポインタ
 * @param[in] x フィールドのX座標
 * @param[in] y フィールドのY座標
 * @param[in] value フィールドの幅
 * @return なし
 */
void CWField_init(CWField* field, const char* value);
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
 * コンソールウィンドウのフィールドのデフォルト値を設定
 * @param[in] field CWField型のポインタ
 * @param[in] defValue 設定するデフォルト値
 * @return なし
 */
void CWField_setDefValue(CWField* field, const char* defValue);
/**
 * コンソールウィンドウのフィールドの値を設定
 * @param[in] field CWField型のポインタ
 * @param[in] value 設定する値
 * @return なし
 */
void CWField_setValue(CWField* field, const char* value);
/**
 * コンソールウィンドウのフィールドを出力
 * @param[in] field CWField型のポインタ
 * @param[in] x 出力開始するX座標
 * @param[in] y 出力開始するY座標
 * @return なし
 */
void CWField_putValue(CWField* field, int x, int y);

#endif
