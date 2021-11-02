#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10];
    int i;
    int *p;
    p=&a;
    for(p=a;p<(a+10);p++)
    {
        scanf("%d",p);
    }
    for(p=a;p<(a+10);p++)
    {
        printf("%d ",*p);
    }
    printf("\n");
    return 0;
}
