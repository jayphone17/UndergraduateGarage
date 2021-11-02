#include <stdio.h>
#include <stdlib.h>

int main()
{

    int a[10];
    int i;
    int *p;
    p=a;
    for(i=0;i<10;i++)
    {
        scanf("%d",p++);

    }
    p=a;
    for(i=0;i<10;i++,p++)
    {
        printf("%d ",*p);
    }
    printf("\n");
    return 0;
}
