#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1,x2,x3,h,d,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d%d",&x1,&x2,&x3,&h,&d);
        int core;
        core=(x1+x2+x3)/3;
        if(core>d)
        {
            printf("JiaoZhuV5!\n");
        }
        else
        {
            printf("Orz!\n");
        }
    }

    return 0;
}
