#include <stdio.h>
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int i,j,k;
        int max;
        max=0;
        for(i=0; i<=n; i++)
            for(j=0; j<=n; j++)
                for(k=0; k<=n; k++)
                {
                    if((i+j)%2==0 && (j+k)%3==0 && (i+j+k)%5==0)
                    {
                        if(i+j+k>max)
                            max=i+j+k;
                    }
                }
        if(max!=0)
            printf("%d\n",max);
        else if(max==0)
            printf("Impossible\n");
    }
    return 0;
}


//Originated from POJ 2474