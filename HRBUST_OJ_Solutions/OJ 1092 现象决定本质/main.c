#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v1,v2;
    while(~scanf("%d%d",&v1,&v2))
    {
        if(v1>0)
        {
            printf("%d\n",v1+v2);
        }
        else if(v1<0)
        {
            printf("%d\n",v1-v2);
        }
    }
    return 0;
}
