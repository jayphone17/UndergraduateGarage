#include<stdio.h>
int main()
{
    long long int n,a;
    while(~scanf("%lld",&n))
    {
        if(n==0)
            printf("1\n");
        else
        {
            printf("%lld\n",1+(2*n-1)*(2*n-1));
        }

    }
    return 0;
}