#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=10,k;
    int *p;
    p=&k;
    *p=i;
    printf("%d\n",*p);
    return 0;
}
