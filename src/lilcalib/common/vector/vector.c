/**
 * 可変配列クラスのソース
 * @file
 */

#include "../vector.h"

Vector* Vector_new(void (*freeElement)(void* element)) {
    Vector* vector = malloc(sizeof(Vector));
    vector->list = malloc(sizeof(void*));
    vector->list[0] = NULL;
    vector->freeElement = free;
    return vector;
}
void Vector_free(Vector* vector) {
    if (vector == NULL)
        return;
    if (vector->list != NULL) {
        for (int idx=0; idx<Vector_count(vector); idx++) {
            if (vector->list[idx] != NULL) {
                vector->freeElement(vector->list[idx]);
                //freeNULL(vector->list[idx]);
            }
        }
    }
    freeNULL(vector->list);
    freeNULL(vector);
    return;
}
void Vector_print(Vector* vector) {
    printf("Count of elements: %d\n", Vector_count(vector));
    return;
}


void Vector_add(Vector* vector, void* ele) {
    if (vector->list == NULL) {
        vector->list = malloc(sizeof(void*));
        vector->list[0] = NULL;
    }
    int len = Vector_count(vector);
    vector->list = realloc(vector->list, sizeof(void*) * (len +1/*終端子分*/ +1/*追加分*/));
    vector->list[len] = malloc(sizeof(ele));
    memcpy(vector->list[len], ele, sizeof(ele));
    vector->list[len+1] = NULL;
    return;
}
void Vector_remove(Vector* vector, int index) {
    if (vector->list == NULL)
        return;
    int len = Vector_count(vector);
    if (len < index)
        return;
    // Remove
    for (int idx=index; idx<Vector_count(vector); idx++) {
        if (idx == index) {
            if (vector->list[idx] != NULL) {
                vector->freeElement(vector->list[idx]);
                //freeNULL(vector->list[idx]);
            }
        }
        vector->list[idx] = vector->list[idx+1];
    }
    vector->list = realloc(vector->list, sizeof(void*) * (len +1/*終端子分*/ -1/*削除分*/));
    vector->list[len+1] = NULL;
    return;
}
void Vector_clear(Vector* vector) {
    if (vector->list == NULL)
        return;
    for (int idx=0; idx<Vector_count(vector); idx++) {
        if (vector->list[idx] != NULL) {
            vector->freeElement(vector->list[idx]);
        }
        //freeNULL(vector->list[idx]);
    }
    vector->list = realloc(vector->list, sizeof(void*));
    vector->list[0] = NULL;
    return;
}
void* Vector_get_(Vector* vector, int index) {
    if (vector->list == NULL)
        return NULL;
    int len = Vector_count(vector);
    if (len < index)
        return NULL;
    // Get
    return vector->list[index];
}

int Vector_count(Vector* vector) {
    if (vector->list == NULL)
        return 0;
    for (int idx=0; ; idx++) {
        if (vector->list[idx] == NULL)
            return idx;
    }
}
