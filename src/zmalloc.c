#include "zmalloc.h"
#include <stdio.h>
#include <stdlib.h>

void *zmalloc(size_t size) {
    return malloc(size);
}

void zfree(void *ptr) {
    free(ptr);
}

void *zcalloc(size_t size) {
    return calloc(1, size);
}

void *zrealloc(void *ptr, size_t size) {
    return realloc(ptr, size);
}
