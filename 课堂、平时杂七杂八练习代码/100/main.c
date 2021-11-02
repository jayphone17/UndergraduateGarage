#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int n;
    int ar[100];
    int i;
    while(scanf("%d",&n)!=EOF)
    {
        double average,s=0,variance,sum=0;
        for(i=0; i<n; i++)
        {
            scanf("%d",&ar[i]);
            sum=ar[i]+sum;
        }
        average=sum*1.0/n;
        for(i=0; i<n; i++)
        {
            s=s+((average-ar[i])*(average-ar[i]));
        }
        variance=sqrt(s/n);
        printf("%.4f\n",variance);
    }

    return 0;
}
