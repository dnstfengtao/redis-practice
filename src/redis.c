#include <stdio.h>
#include <stdlib.h>

#include "zmalloc.h"
#include "adlist.h"
#include "sds.h"

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
    list *listHolder = listCreate();

    for (int i = 0; i < 2; i++)
    {
        sds eachItem = sdsnew("item");
        listAddNodeHead(listTest, eachItem);
        listAddNodeHead(listHolder, eachItem);
    }

    listIter *it = listGetIterator(listTest, AL_START_TAIL);
    listNode *node;

    while ((node = listNext(it)) != NULL)
    {
        printf("%d\n", (getSdshdrPtnBySds((sds)node->value))->len);
    }

    listReleaseIterator(it);
    listRelease(listTest);

    listIter *itAfterFree = listGetIterator(listHolder, AL_START_TAIL);
    listNode *nodeAfterFree;

    while ((nodeAfterFree = listNext(itAfterFree)) != NULL)
    {
        printf("%d\n", (getSdshdrPtnBySds((sds)nodeAfterFree->value))->len);
    }
}

int main()
{

    testSds();

    testList();

    return 0;
}
