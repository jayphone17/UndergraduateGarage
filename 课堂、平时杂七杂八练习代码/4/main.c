#include<stdio.h>
int main()
{
    int n,i,a[100],sum=0;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) break;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            sum=sum+a[i];
        }
    printf("%d\n",sum);
    }
    return 0;
}