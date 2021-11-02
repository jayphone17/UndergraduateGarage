#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        long long  a1=3,a2=8;
        int i;
        long long sum;
        for(i=3; i<=N; i++)
        {
            sum=2*a1+2*a2;
            a1=a2;
            a2=sum;
        }
        if(N==1)
            printf("%lld\n",a1);
        else if(N==2)
            printf("%lld\n",a2);
        else if(N>=3)
            printf("%lld\n",sum);
    }
    return 0;
}
