#include<stdio.h>
#include <string.h>
#define N 50
int a[N][N];
int main()
{
    int n,m;
    int i,j;
    while(~scanf("%d%d",&n,&m))
    {
        for(i=1;i<=n;i++)
        {
            a[i][1]=1;
            a[i][i]=1;
        }
        for(i=2;i<=n;i++)
        {
            for(j=2;j<=i-1;j++)
            {
                a[i][j]=a[i-1][j-1]+a[i-1][j];
            }
        }
        printf("%d\n",a[n][m]);
    }
    return 0;
}