#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long long n;
    while(~scanf("%lld",&n))
    {
        if(n%8==2 || n%8==6)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}


