#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int i,m=0;
        for(i=3;i<=n;i++)
        {
            if(n%i==0)
            {
                m++;
            }
        }
        printf("%d\n",m);
    }
}
