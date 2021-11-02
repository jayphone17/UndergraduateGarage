#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    int i,j,x;
    while(scanf("%d",&n)!=EOF)
    {
        int a[n];
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        int k;
        scanf("%d",&k);
        for(j=0; j<k; j++)
        {
            scanf("%d",&x);
            if(a[n-1]<=x)
            {
                printf("Orz\n");
            }
            for(i=0; i<n; i++)
            {
                if(a[i]>x)
                {
                    printf("%d\n",a[i]);
                    break;
                }
            }
        }
    }
    return 0;
}
