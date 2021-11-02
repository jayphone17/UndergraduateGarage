OJ 1321 木棒和三角形

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if((a+b>c && a+c>b && b+c>a) || (a+b>d && a+d>b && b+d>a) || (a+c>d && a+d>c && c+d>a) || (b+c>d && b+d>c && c+d>b))
        {
            printf("T\n");
        }
        else if(a+b==c || a+c==b || b+c==a || a+b==d || a+d==b || b+d==a || a+c==d || a+d==c || c+d==a || b+c==d || b+d==c || c+d==b)
        {
            printf("S\n");
        }
        else
        {
            printf("I\n");
        }
    }
    return 0;
}
