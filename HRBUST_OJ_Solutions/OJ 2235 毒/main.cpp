#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
double a[1111111];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,K,M;
        scanf("%d%d%d",&n,&K,&M);
        a[1]=1;
        for(int i=2; i<=n; i++) //用这个循环算出除了第一瓶的其他毒药的毒性
        {
            a[i]=a[i-1]+1.0*(((i-1)*K)%M);
        }
        sort(a+1,a+1+n); //将所有毒药的毒性由小到大排序。
        for(int i=n-1;i>=1;i--) //倒序混合，越混越小。。所以最后混合的是最小的。
        {
            a[n]=2.0*sqrt(a[n]*a[i]);
        }
        printf("%.3lf\n",a[n]); //输出最后一瓶的毒性。
    }
    return 0;
}
