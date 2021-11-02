#include<stdio.h>
#include<string.h>
long long a[100];
int main()
{
    a[1]=3;
    a[2]=8;
    for(int i=3;i<=30;i++)
    {
        a[i]=a[i-1]*2+a[i-2]*2;
    }
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("%lld\n",a[n]);
    }
}