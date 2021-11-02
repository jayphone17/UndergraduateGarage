#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[1000];
    int i,j,t;
    long long n;
    for(i=0;i<1000;i++)
    {
        array[i]=0;
    }
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&t);
        array[t]++;
    }
    for(i=0;i<1000;i++)
    {
        for(j=0;j<array[i];j++)
            {
                printf("%d\n",i);
            }
    }
    return 0;
}
