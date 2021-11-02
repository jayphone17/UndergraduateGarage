/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N,M;
        scanf("%d%d",&N,&M);
        int i;
        char str[6];
        for(i=0; i<N; i++)
        {
           scanf("%s",str);
        }
        int j;
        int flag=0;
        for(j=0;j<M;j++)
        {
            if(strcmp(str[j],'80')>0)
                flag++;
        }
        printf("%d\n",flag);

    }
    return 0;
}*/




 /*int M;
            scanf("%d",&M);
            int j;
            int str[6];
            for(j=0; j<M; j++)
            {
                scanf("%c",&str);
            }
            int flag=0,g;
            for(g=0; g<M; g++)
            {
                if(strcmp(str[g],'80')>0)
                {
                    flag++;
                }
            }
            printf("%d\n",flag);*/







#include <stdio.h>
#include <stdlib.h>

int a[1005][1005]={0};
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,i,j;
        scanf("%d%d",&n,&m);

        int project=0,number=0;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j]>80)
                {
                    project++;
                }
            }
            if(project>=3)
            {
                number++;
                project=0;
            }
        }
        printf("%d\n",number);
    }
    return 0;
}



