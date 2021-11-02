#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int a[1000000];

int main()
{
    int k;
    long long n;
    int i;

    while(scanf("%lld%d",&n,&k)!=EOF)
    {
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        printf("%d\n",a[k-1]);
    }
    return 0;
}
