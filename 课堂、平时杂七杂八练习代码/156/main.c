#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    long long n,m;
    while(~scanf("%lld%lld",&m,&n))
    {
        if(m%2==0&&n%2==0) //
            printf("%lld\n",m/2*n);
        if(m%2==1&&n%2==0)
            printf("%lld\n",n/2*m);
        if(m%2==0&&n%2==1)
            printf("%lld\n",m/2*n);
        if(m%2==1&&n%2==1) //
            printf("%d\n",(m*n+1)/2);
    }
    return 0;
}
