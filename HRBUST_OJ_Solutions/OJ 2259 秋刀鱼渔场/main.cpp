#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int a[11111111];

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int yartnumber;
        int fishnumber;
        scanf("%d",&yartnumber); //渔场的数量。
        int i;
        for(i=0;i<yartnumber;i++)
        {
            scanf("%d",&a[i]);    //每个渔场有几条鱼。
        }
        scanf("%d",&fishnumber); //要收的鱼的数量。

        sort(a,a+yartnumber,cmp);
        int ans=0;
        int sum=0;
        for(i=0;i<yartnumber;i++)
        {
            ans++;
            sum=sum+a[i];
            if(sum>=fishnumber)
            {
                printf("%d\n",ans);
                break;
            }
        }

    }
    return 0;
}
