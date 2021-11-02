#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a,b,r1,r2;
    while(scanf("%d%d%d%d",&a,&b,&r1,&r2)!=EOF)
    {
        int d1,d2;
        d1=2*r1;
        d2=2*r2;
        if(a>=b)
        {
            if(d1+d2<=b)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
        else
        {
            if(d1+d2<a)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}
