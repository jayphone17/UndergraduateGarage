#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    int Pi,Ci;
    int N,X,K;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&N,&X,&K);
        while(N--)
        {
            scanf("%d%d",&Pi,&Ci);
        }
        if(Pi>=X && K==Ci)
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
