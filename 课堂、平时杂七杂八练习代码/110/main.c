#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long a,b;
    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
        printf("%lld\n",a+b);
    }
    return 0;
}
