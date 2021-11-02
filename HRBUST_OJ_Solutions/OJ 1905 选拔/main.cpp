#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
using namespace std;

long long  a[35][35];

int main()
{
    int i,j;
    memset(a,0,sizeof a);
    for(i=0;i<=30;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(j==0)
            {
                a[i][j]=1;
            }
            else
            {
                a[i][j]=a[i-1][j-1]+a[i-1][j];
            }
        }
    }
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long N,M;
        scanf("%lld%lld",&N,&M);
        printf("%lld\n",a[N][M]);
    }
    return 0;
}
