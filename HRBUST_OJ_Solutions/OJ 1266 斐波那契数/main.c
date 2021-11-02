#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n,m,k;
    unsigned long long f[111111];
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        if(k==1)
            printf("%d\n",n);
        else if(k==2)
            printf("%d\n",m);
        else
        {
            f[1]=n;
            f[2]=m;
            for(int i=3; i<=k; i++)
            {
                f[i]=f[i-1]+f[i-2];
            }
            printf("%llu\n",f[k]);
        }
    }
    return 0;
}
