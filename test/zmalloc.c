#include "zmalloc.h"
#include <stdio.h>

int main()
{
    char* value = __xstr(1111);
    printf("%s\n", value);
    return 0;
}
