#include "zmalloc.h"
#include <stdio.h>
#include <stdlib.h>

void *zmalloc(size_t size)
{
    return malloc(size);
}

void zfree(void *ptr)
{
    free(ptr);
}
