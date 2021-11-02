#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c1,c2,c3,c4,c5;
    while(~scanf("%d%d%d%d%d",&c1,&c2,&c3,&c4,&c5))
    {
        int sum;
        sum=c1+c2+c3+c4+c5;
        if(sum%5==0 && sum!=0) //判断非0。
            printf("%d\n",sum/5);
        else
            printf("%d\n",-1);

    }
    return 0;
}
