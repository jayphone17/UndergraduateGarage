#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct shopping
{
    int discount;
    int price;
};

int main()
{
    int T;
    int i,j;
    int struct shopping a[111111];
    int money[111111];
    scanf("%d",&T);
    while(T--)
    {
        int profit=0;
        int n,m;
        int temp;
        scanf("%d%d",&n,&m);
        for(i=1; i<=n; i++)
        {
            scanf("%d%d",&a[i].discount,&a[i].price);
        }
        for(i=1; i<=n-1; i++)
        {
            for(j=1; j<=n-i; j++)
            {
                if(a[j].price<a[j+1].price)
                {
                    temp=a[j].price;
                    a[j].price=a[j+1].price;
                    a[j+1].price=temp;
                    if(a[j].discount<a[j+1].discount)
                    {
                        temp=a[j].discount;
                        a[j].discount=a[j+1].discount;
                        a[j+1].discount=temp;
                    }
                }
            }
        }
        for(i=1; i<=m; i++)
        {
            scanf("%d",&money[i]);
        }
        for(i=1; i<=m; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(money[i]>=a[j].price)
                {
                    c[i]=c[i]-a[j].discount;
                    break;
                }
            }
        }
        profit=profit+c[i];
    }
    return 0;
}
