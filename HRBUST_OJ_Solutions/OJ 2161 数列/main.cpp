#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
    long long n,q,m;
    while(~scanf("%lld%lld%lld",&n,&q,&m))
    {
        long long s1=0;
        long long s2=0;
        n=n%2 == 1?n+1:n;
        if((n/2)%2)
        {
            s1=1;
        }
        else
            s1=0;
        if(q%2)
        {
            s2=1;
        }
        else
            s2=0;
        if((s1+s2)%2)
        {
            printf("NO\n");
        }
        else
            printf("YES\n");

    }
    return 0;
}



/* int part1,part2,part3;
    int part4;
    int part5;
    int n,q,m;
    while(~scanf("%d%d%d",&n,&q,&m))
    {
    part1=n*n;
        int i;

        int sum=1;
        for(i=0;i<n;i++)
        {
            sum=sum*3;
            part2=sum;     //part2是3^n
        }

        part3=part1*part2; //part3是an.

        int flag=1;
        for(i=0;i<m;i++)
        {
            flag=flag*5;
            part4=flag;    //part4是5^m
        }

        int ans=0;
        for(i=0;i<n;i++)
        {
            ans=ans+part3;
        }

        if(ans+q*part4%2==0)
            printf("YES\n");
        else
            printf("NO\n");    */
