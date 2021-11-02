#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,m;
    int i,j,x;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int a[n];
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        for(j=0; j<m; j++)
        {
            scanf("%d",&x);
            if(a[n-1]<x)
            {
                printf("-1\n");
            }
            for(i=0; i<n; i++)
            {
                if(a[i]>=x)
                {
                    printf("%d\n",a[i]);
                    break;
                }
            }
        }
    }
    return 0;
}
