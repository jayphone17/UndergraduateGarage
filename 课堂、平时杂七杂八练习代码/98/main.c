1910Ï≥≤®¿≠∆ıŒ Ã‚

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        int f0=5,f1=13;
        int i;
        for(i=0; i<N; i++)
        {
            f1=f1+f0;
            f0=f1-f0;
        }
        if(N>=2 && f1%3==0)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
