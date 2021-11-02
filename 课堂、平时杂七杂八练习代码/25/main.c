#include<stdio.h>
int main()
{
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        int i;
        int m;
        m=N;
        for(i=1; i<=N; i++)
        {
            int j;
            for(j=1; j<=m-i; j++)
            {
                printf(" ");
            }
            for(j=1; j<=10+2*(i-1); j++)
            {
                printf("i");
            }
            printf("\n");
        }
    }
    return 0;
}
