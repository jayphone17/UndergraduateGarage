#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a1,b1,a2,b2,c;
        scanf("%d%d%d%d%d",&a1,&b1,&a2,&b2,&c);
        int sum1,sum2,growing,days,original;

        sum1=a1*b1;

        sum2=a1*b2;

        growing=(sum1-sum2)/(b1-b2);

        original=b1*(a1-growing);

        days=original/(c-growing);

        printf("%d",days);

    }

    return 0;
}
