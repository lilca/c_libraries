#include <stdio.h>
#include "../vector.h"

typedef struct {
    int val;
    char* str;
}AClass;

void AClass_free(void* ele) {
    AClass* tar = (AClass*)ele;
    freeNULL(tar->str);
    freeNULL(tar);
}
void int_free(void* ele) {
    int* rr = (int*) ele;
    freeNULL(rr);
}

int main(int argc, char** argv) {
    int* ele = malloc(sizeof(int));
    *ele = 1213;
    int* ele2 = malloc(sizeof(int));
    *ele2 = 56;
    int* ele3 = malloc(sizeof(int));
    *ele3 = 92;
    Vector* v = Vector_new(int_free);
//    int a = 6;
//    Vector_add(v, &a);
    Vector_add(v, ele);
    Vector_add(v, ele2);
    Vector_add(v, ele2);
//    Vector_remove(v, 4);
    for (int idx=0; idx<Vector_count(v); idx++) {
        printf("%d\n", *Vector_get(v, idx, int));
    }
    Vector_print(v);
    printf("@0\n");
    Vector_clear(v);
    printf("@1\n");
    for (int idx=0; idx<Vector_count(v); idx++) {
//        printf("%d\n", *Vector_get(v, idx, int));
    }
    printf("@2\n");
    Vector_print(v);
    printf("@3\n");
    Vector_free(v);
    printf("@4\n");
    return 0;
}
