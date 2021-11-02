#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int g(int x,int y);
int main()
{
    int a,b;
    printf("Input m,n:");
    scanf("%d,%d",&a,&b);
    if(a<=0||b<=0)
        printf("Input error!\n");
    else
    {
        int t;
        t=g(a,b);
        a=a/t;
        b=b/t;
        printf("%d/%d\n",a,b);
    }
    return 0;
}
int g(int x,int y)
{
    int r;
    while(y>0)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
