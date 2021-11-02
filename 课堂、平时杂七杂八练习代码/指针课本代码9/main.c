#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int *p;
    int a[10];
    p=a;
    for(i=0; i<10; i++)
    {
        scanf("%d",p++);
    }
    p=a;
    for(i=0; i<10; i++,p++)
        printf("%d ",*p);
    printf("\n");
    return 0;
}
