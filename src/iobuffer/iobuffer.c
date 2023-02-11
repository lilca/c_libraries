#include "iobuffer.h"

IOBuffer* IOBuffer_new(void) {
    IOBuffer* res = malloc(sizeof(IOBuffer));
    IOBuffer_init(res);
    return res;
}

void IOBuffer_init(IOBuffer* buf) {
    buf->data = NULL;
    buf->size = 0;
    return;
}

IOBuffer* IOBuffer_alloc(uint32 size) {
    void* tmp = malloc(size + 1);
    if (tmp == NULL)
        return NULL;
    IOBuffer* res = IOBuffer_new();
    res->size = size;
    ((char*)tmp)[res->size] = '\0';
    res->data = tmp;
    return res;
}

IOBuffer* IOBuffer_readFile(char* path) {
    IOBuffer* buf = malloc(sizeof(IOBuffer));
    FILE* fp;
    if (( fp = fopen(path, "r")) == NULL) {
        IOBuffer_free(buf);
        return NULL;
    }
    // Get file size
    fseek(fp, 0, SEEK_END);
    fgetpos(fp, &(buf->size));
    fseek(fp, 0, SEEK_SET);
    // Allocate memory
    buf->data = malloc(buf->size + 1);
    // Read file data
    fread(buf->data, 1, buf->size, fp);
    fclose(fp);
    ((char*)(buf->data))[buf->size] = '\0';
    return buf;
}

int IOBuffer_writeFile(char* path, IOBuffer* buf) {
    FILE* fp;
    if ((fp = fopen(path, "w")) == NULL) {
        return FALSE;
    }
    fwrite(buf->data, 1, buf->size, fp);
    fclose(fp);
    return TRUE;
}

void IOBuffer_free(IOBuffer* buf) {
    if (buf == NULL)
        return;
    if (buf->data != NULL) {
        free(buf->data);
        buf->data = NULL;
        buf->size = 0;
    }
    free(buf);
    return;
}
