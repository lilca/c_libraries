#include <stdio.h>
#include "../memory.h"

typedef struct {
    int val;
    char* pstr;
    char str[256];
}AClass;

int main(int argc, char** argv) {
    AClass a;
    a.val = 4;
    a.pstr = "Ptr of Static";
    strcpy(a.str, "Array");
    printf("Before: a.val=%d, a.pstr=%s, a.str=%s\n", a.val, a.pstr, a.str);
    AClass* b = staticToDynamic(a);
    printf("After: a.val=%d, a.pstr=%s, a.str=%s\n", a.val, a.pstr,a.str);
    printf("After: b.val=%d, b.pstr=%s, b.str=%s\n", b->val, b->pstr, b->str);
    b->val = 6;
    b->str[1] = 'Z';
    printf("Change: b.val=%d, b.pstr=%s, b.str=%s\n", b->val, b->pstr, b->str);
    // b->pstr[1] = '*'; is bus error.
    freeNULL(b);
    return 0;
}
