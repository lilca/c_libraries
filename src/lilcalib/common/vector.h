/**
 * 可変配列クラスのインクルード
 * @file
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <lilcalib/common.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * 可変配列の構造体
*/
typedef struct {
    void** list;
} Vector;

/**
 * 可変回列のコンストラクタ
 * @return Vector* 可変配列のインスタンス
 */
Vector* Vector_new();
/**
 * 可変配列の解放
 * @param[in] vector Vector型のポインタ
 * @return なし
 */
void Vector_free(Vector* vector);
/**
 * 可変配列の内容出力
 * @param[in] vector Vector型のポインタ
 * @return なし
 */
void Vector_print(Vector* vector);


/**
 * 可変配列に要素追加
 * @param[in] vector Vector型のポインタ
 * @param[in] ele 追加する要素
 * @return なし
 */
void Vector_add(Vector* vector, void* ele);
/**
 * 可変配列に要素削除
 * @param[in] vector Vector型のポインタ
 * @param[in] index 削除する要素のインデックス
 * @return なし
 */
void Vector_remove(Vector* vector, int index);
/**
 * 可変配列をクリア
 * @param[in] vector Vector型のポインタ
 * @return なし
 */
void Vector_clear(Vector* vector);
/**
 * 可変配列の要素を取得
 * @param[in] vector Vector型のポインタ
 * @param[in] index 参照するインデックス 
 * @return 取得する要素
 */
#define Vector_get(vector, index, type) ((type*)Vector_get_(vector, index))
void* Vector_get_(Vector* vector, int index);
/**
 * 可変配列の要素数を取得
 * @param[in] vector Vector型のポインタ
 * @return 可変配列の要素数
 */
int Vector_count(Vector* vector);
#endif
