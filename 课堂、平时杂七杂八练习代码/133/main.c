#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long n;
    while(scanf("%lld",&n)!=EOF)
    {
        if(n==0)
        {
            printf("1\n");
        }
        else
        {
            printf("%lld\n",1+(2*n-1)*(2*n-1));
        }
    }
    return 0;
}
