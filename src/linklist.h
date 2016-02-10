/**
 * link list header file.
 */
#ifndef __LINK_LIST_H__
#define __LINK_LIST_H__

typedef struct listNode {
    struct listNode *prev;
    struct listNode *next;
    void *value;
} listNode;

typedef struct listIter {
    listNode *next;
    int direction;
} listIter;

typedef struct list {
    listNode *head;
    listNode *tail;
    void *(*dup)(void *ptr);
    void *(*free)(void *ptr);
    int (*match)(void *ptr, void *key);
    unsigned long len;
} list;

/* Functions implementation as macros */
#define listLength(l) ((l) -> len)
#define listFirst(l) ((l) -> head)


#endif
