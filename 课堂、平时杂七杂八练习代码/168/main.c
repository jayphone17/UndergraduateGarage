#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,k;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        if(n>=k && m>=k && (n-k)%2==0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
