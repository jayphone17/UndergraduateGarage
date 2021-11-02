#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;

    while(scanf("%d",&N)!=EOF)
    {
        int a,b;

        if(N==1)
            printf("1\n");

        else if(N==2)
            printf("2\n");

        else if(N==3)
            printf("3\n");

        else if(N%2==0)
        {
            a=N/2;
            b=N-a;
            printf("%d\n",a*b);
        }
        else if(N%2==1)
        {
            a=(N+1)/2;
            b=N-a;
            printf("%d\n",a*b);

        }

    }
    return 0;
}
