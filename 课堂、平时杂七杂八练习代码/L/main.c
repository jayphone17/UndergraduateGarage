#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m;
    int flag=0;
    while(~scanf("%d%d",&n,&m))
    {
        int i;
        int j;
        int x;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&x);
                if(x==0)
                {
                    flag++;
                }
            }
        }
        printf("%d\n",flag);
    }
    return 0;
}
