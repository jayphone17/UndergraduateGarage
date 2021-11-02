#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int maps[305][305];
int main()
{

    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N;
        scanf("%d",&N);
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
                scanf("%d",&maps[i][j]);
        int M;
        scanf("%d",&M);
        int x1,x2,y1,y2;
        for(int i=0; i<M; i++)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            int maxx=0;
            for(int i=x1; i<=x2; i++)
                for(int j=y1; j<=y2; j++)
                    if(maps[i][j]>maxx)
                        maxx=maps[i][j];
            printf("%d\n",maxx);
        }
    }
    return 0;
}
