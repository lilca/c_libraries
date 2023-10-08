/**
 * メモリ関連の定義
 * @file
 */

#ifndef LILCALIB_MEMORY_H
#define LILCALIB_MEMORY_H

#include <stdlib.h>
#include <string.h>

/**
 * NULL代入込みのfree関数
 */
#define freeNULL(ptr) (free(ptr),ptr=NULL)
/**
 * コピー
 */
#define staticToDynamic(var) (_staticToDynamic(&var,sizeof(var)))

void* _staticToDynamic(void* ptr, int size);

#endif
