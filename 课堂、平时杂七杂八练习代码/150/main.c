#include <stdio.h>
#include <stdlib.h>

long long fan(int n)
{
    if(n==1)
    {
        return 3;
    }
    else if(n==2)
    {
        return 8;
    }
    else
    {
        return 2*fan(n-2)+2*fan(n-1);
    }
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        printf("%lld\n",fan(n));
    }
    return 0;
}
