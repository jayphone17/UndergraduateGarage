#include <stdio.h>
#include <stdlib.h>

int main()
{
    int f0=5,f1=13,fN;
    int i;
    long long  N;
    while(scanf("%lld",&N)!=EOF)
    {
        if(N==1)
        {
            fN=13;
        }
        else
        {
            for(i=2; i<=N; i++)
            {
                fN=f0+f1;
                f0=f1;
                f1=fN;
            }
        }

        if(fN%3==0)
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
