#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1,x2,x3;
    while(~scanf("%d%d",&x1,&x2))
    {
        if(x1>0 && x2>0 || x1<0 && x2<0)
        {
            printf("%d\n",x1+x2);
        }
        else if(x1>0 && x2<0)
        {
            printf("%d\n",x1-x2);
        }
        else if(x1<0 && x2>0)
        {
            printf("%d\n",x2-x1);
        }
    }
    return 0;

}
