#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;

long long a[100005];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        scanf("%lld%lld",&a[0],&a[1]);
        long long x;
        x=__gcd(a[0],a[1]);
        int i;
        for(i=2;i<n;i++)
        {
            scanf("%lld",&a[i]);
            x=__gcd(x,a[i]);
        }
        printf("%lld\n",a[0]/x);

    }

    return 0;
}
