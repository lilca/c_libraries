/**
 * 共用のメモリ関連のソース
 * @file
 */

#include "../memory.h"

void* _staticToDynamic(void* ptr, int size) {
    void* res = malloc(size);
    memcpy(res, ptr, size);
    return res;
}
