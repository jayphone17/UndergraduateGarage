#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    int n,m;
    int sum1,sum2;
    int i;
    int temp;
    while(~scanf("%d%d",&n,&m))
    {
        sum1=0;
        sum2=0;
        if(n>m)
        {
            temp=n;
            n=m;
            m=temp;
        }
        for(i=n; i<=m; i++)
        {
            if(i%2==0)
            {
                sum1=sum1+i*i;
            }
            else if(i%2==1)
            {
                sum2=sum2+i*i*i;
            }
        }
        printf("%d %d\n",sum1,sum2);
    }
    return 0;
}
