#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "zmalloc.h"
#include "adlist.h"
#include "sds.h"
#include "fmacros.h"
#include "dict.h"
#include "intset.h"

/**
 * SDS hash 算法.
 */
unsigned int dictSdsHash(const void *key)
{
    return dictGenHashFunction((unsigned char *)key, sdslen((sds)key));
}
/**
 * SDS 字符串比较函数
 */
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
/**
 * sds 析构函数
 */
void dictSdsDestructor(void *privdata, void *val)
{
    DICT_NOTUSED(privdata);

    sdsfree(val);
}

/* Sds 字典类型. */
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
    printf("Begin test dict \n\n");
    sds key = sdsnew("name1");
    sds value1 = sdsnew("value1");
    dict *dictTest = dictCreate(&sdsDictType, NULL);
    dictAdd(dictTest, key, value1);
    printf("End test dict \n\n");
}

void testIntSet()
{
    printf("Begin test int set \n\n");
    intset *testIntSet = intsetNew();
    for (int i = 0; i < 8; i++)
    {
        testIntSet = intsetAdd(testIntSet, i, NULL);
    }
    printf("test intset get %lld\n", intsetRandom(testIntSet));
    printf("End test int set \n\n");
}

int main()
{

    testSds();

    testList();

    testDict();

    testIntSet();

    return 0;
}
