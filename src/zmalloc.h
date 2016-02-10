#ifndef __ZMALLOC_H
#define __ZMALLOC_H

#define __xstr(s) __str(s)
#define __str(s) #s

#include <stdlib.h>

/* Prototypes */
void *zmalloc(size_t size);
void zfree(void *ptr);

#endif
