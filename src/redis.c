#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "zmalloc.h"
#include "adlist.h"
#include "sds.h"
#include "fmacros.h"
#include "dict.h"

unsigned int dictSdsHash(const void *key)
{
    return dictGenHashFunction((unsigned char *)key, sdslen((char *)key));
}

int dictSdsKeyCompare(void *privdata, const void *key1, const void *key2)
{
    int l1, l2;
    DICT_NOTUSED(privdata);

    l1 = sdslen((sds)key1);
    l2 = sdslen((sds)key2);
    if (l1 != l2)
        return 0;
    return memcmp(key1, key2, l1) == 0;
}

void dictSdsDestructor(void *privdata, void *val)
{
    DICT_NOTUSED(privdata);

    sdsfree(val);
}

/* Sds dictType. */
dictType sdsDictType = {
    dictSdsHash,       /* hash function */
    NULL,              /* key dup */
    NULL,              /* val dup */
    dictSdsKeyCompare, /* key compare */
    dictSdsDestructor, /* key destructor */
    NULL               /* val destructor */
};

void testSds()
{
    sds s = sdsnewlen("111,hello world", 15);
    printf("%s\n", s);

    sds s1 = sdsnew("finleyfeng");
    printf("Copy the literal string into the sds buffer value is %s\n", s1);
    // Test can get the original pointer by the buf pointer.
    struct sdshdr *ptr = getSdshdrPtnBySds(s1);
    printf("len is -> %zu\n", sdslen(s1));
    printf("available is -> %zu\n", sdsavail(s1));

    s1 = sdscat(s1, "will append the string into my original sds string.");
    printf("len is -> %zu\n", sdslen(s1));
    printf("available is -> %zu\n", sdsavail(s1));
}

void testList()
{
    list *listTest = listCreate();
    listTest->free = zfree;

    for (int i = 0; i < 2; i++)
    {
        sds eachItem = sdsnew("item");
        listAddNodeHead(listTest, getSdshdrPtnBySds(eachItem));
    }

    listIter *it = listGetIterator(listTest, AL_START_TAIL);
    listNode *node;

    while ((node = listNext(it)) != NULL)
    {
        printf("%d\n", ((struct sdshdr *)node->value)->len);
    }

    listReleaseIterator(it);
    listRelease(listTest);
}

void testDict()
{
    dict *dictTest = dictCreate(&sdsDictType, NULL);

    sds *key = sdsnew("name1");

    sds *value = sdsnew("value1");

    dictAdd(dictTest, key, value);
}

int main()
{

    testSds();

    testList();

    testDict();

    return 0;
}
