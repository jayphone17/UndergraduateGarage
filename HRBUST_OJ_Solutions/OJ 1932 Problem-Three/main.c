#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    int f[111111];
    while(~scanf("%d",&n))
    {
        f[1]=1;
        f[2]=2;
        f[3]=4;
        for(int i=4;i<=n;i++)
        {
            f[i]=f[i-1]+f[i-2]+f[i-3];
        }
        printf("%d\n",f[n]);
    }
    return 0;
}
