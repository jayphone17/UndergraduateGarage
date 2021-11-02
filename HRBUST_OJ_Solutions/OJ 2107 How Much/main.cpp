#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
    int T;

    int money;
    int total;
    scanf("%d",&T);
    if(T>100)
        return 0;
    while(T--)
    {
        int s;
        scanf("%d",&s);
        int n;
        scanf("%d",&n);
        int sum=0;
        while(n--)
        {
            int number,price;

            scanf("%d%d",&number,&price);

            money=number*price;
            sum=sum+money;
        }
        total=s+sum;
        printf("%d\n",total);
    }
    return 0;
}
