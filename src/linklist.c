/**
 * link list implementation file.
 */ 

#include <stdlib.h>
#include <stdio.h>
#include "listhead.h"

list *listCreate(void)
{
    struct list *list;
    if ((list = zmalloc(sizeof(*list))) == NULL)
        return NULL;
    list->head = list->tail = NULL;
    list->len = 0;
    list->dup = NULL;
    list->match = NULL;
    return list;
}

