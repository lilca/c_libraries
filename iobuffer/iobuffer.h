#ifndef IOBUFFER_H
#define IOBUFFER_H

#include <stdio.h>
#include <stdlib.h>

#include <common/typedefs.h>

struct _IOBuffer {
    void* data;
    int64 size;
};
typedef struct _IOBuffer IOBuffer;

IOBuffer* IOBuffer_new(void);
void IOBuffer_init(IOBuffer* buf);
IOBuffer* IOBuffer_alloc(uint32 size);
IOBuffer* IOBuffer_readFile(char* path);
int IOBuffer_writeFile(char* path, IOBuffer* buf);
void IOBuffer_free(IOBuffer* buf);

#endif