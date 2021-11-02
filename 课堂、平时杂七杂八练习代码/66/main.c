#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long p,q;
        scanf("%lld%lld",&p,&q);
        if(p%2==0 && q%2==0)
        {
            printf("JiaoZhuV5!\n");
        }
        else if(p%2==0 && q%2!=0)
        {
            printf("Orz!\n");
        }
        else if(p%2!=0 && q%2!=0 || q%2==0 && p%2!=0)
        {
            printf("PleaseCallMeFlash!\n");
        }

    }
    return 0;
}
