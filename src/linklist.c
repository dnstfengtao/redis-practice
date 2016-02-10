/**
 * link list implementation file.
 */ 

#include <stdlib.h>
#include <stdio.h>
#include "linklist.h"

list *listCreate(void)
{
    struct list *list;
    if ((list = malloc(sizeof(*list))) == NULL)
        return NULL;
    list->head = list->tail = NULL;
    list->len = 0;
    list->dup = NULL;
    list->match = NULL;
    return list;
}

int main()
{
    list* list = listCreate();
    printf("%ld", list->len);
    return 0;
}
