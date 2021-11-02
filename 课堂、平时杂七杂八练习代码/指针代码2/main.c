#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,*p1,*p2,*p;
    printf("please enter two intergers\n");
    scanf("%d%d",&a,&b);
    p1=&a;
    p2=&b;
    if(a<b)
    {
        p=p1;
        p1=p2;
        p2=p;
    }
    printf("a=%d\n b=%d\n",a,b);

    printf("max=%d\nmin=%d\n",*p1,*p2);
    return 0;
}
