#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long N;

    while(scanf("%lld",&N)!=EOF)
    {
        long long sum;
        sum=((1+N)*N)/2;
        sum=sum%2011;
        printf("%d\n",sum);
    }
    return 0;
}
