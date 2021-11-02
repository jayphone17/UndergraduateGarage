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