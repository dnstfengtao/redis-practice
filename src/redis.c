#include <stdio.h>
#include <stdlib.h>

#include "zmalloc.h"
#include "adlist.h"
#include "sds.h"

int main() {
    list *list = listCreate();
    char *value1 = "111";
    char *value2 = "222";

    listAddNodeHead(list, value1);
    listAddNodeHead(list, value2);

    listIter *it = listGetIterator(list, AL_START_HEAD);
    listNode *node;
    while ((node = listNext(it)) != NULL) {
        printf("%s\n", node->value);
    }
    listReleaseIterator(it);
    listRelease(list);

    sds s = sdsnewlen("111,hello world", 15);
    printf("%s\n", s);

    sds s1 = sdsnew("finleyfeng");
    printf("Copy the literal string into the sds buffer value is %s\n", s1);
    // Test can get the original pointer by the buf pointer.
    struct sdshdr *ptr = (void *) (s1 - sizeof(struct sdshdr));
    printf("%d\n", ptr->len);
    printf("%d\n", ptr->free);

    s1 = sdscat(s1, "will append the string into my original sds string.");
    printf("%d\n", ptr->len);
    printf("%d\n", ptr->free);

    return 0;
}
