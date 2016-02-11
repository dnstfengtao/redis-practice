#include <stdio.h>

#include "adlist.h"

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
    return 0;
}
