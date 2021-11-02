#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        int a1=1,a2=2,a3=4;
        int i;
        int sum;
        for(i=4; i<=N; i++)
        {
            sum=a1+a2+a3;
            a1=a2;
            a2=a3;
            a3=sum;

        }
        if(N==1)
            printf("1\n");
        else if(N==2)
            printf("2\n");
        else if(N==3)
            printf("4\n");
        else if(N>=4)
            printf("%d\n",sum);


    }
    return 0;
}
