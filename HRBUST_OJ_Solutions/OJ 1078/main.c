#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1,y1,x2,y2,x3,y3;
    double kAB,kBC,kAC;
    while(scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF)
    {
        kAB=(y1-y2)*1.0/(x1-x2)*1.0;
        kBC=(y2-y3)*1.0/(x2-x3)*1.0;
        kAC=(y1-y3)*1.0/(x1-x3)*1.0;
        if(kAB==kBC && kAB==kAC)
        {
            printf("JiaoZhuV5!\n");
        }
        else
        {
            printf("Orz!\n");
        }

        //printf("%lf %lf %lf\n",kAB,kBC,kAC);
    }
    return 0;
}
