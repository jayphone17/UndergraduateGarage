#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a1,b1,a2,b2,c,day;
        scanf("%d%d%%d%d%d",&a1,&b1,&a2,&b2,&c);
        double grow,original;
        grow=(a1*b1-a2*b2)/(b1-b2);
        original=a1*b1-grow*b1;
        day=original/(c-grow);
        printf("%d\n",day);
    }
    return 0;
}
