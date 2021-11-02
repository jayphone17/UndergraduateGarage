#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
    long long score;
    long long money;
    long long RP;
};

int main()
{
    struct person man[100],temp;
    int n,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1; i<=n; i++)
        {
            scanf("%lld%lld%lld",&man[i].score,&man[i].money,&man[i].RP);
        }
        for(i=1; i<=n-1; i++)
        {
            for(j=1; j=n-i; j++)
            {
                if(man[j].score<man[j+1].score)
                {
                    temp=man[j];
                    man[j]=man[j+1];
                    man[j+1]=temp;
                }
                else if(man[j].score==man[j+1].score)
                {
                    if(man[j].money<man[j+1].money)
                    {
                        temp=man[j];
                        man[j]=man[j+1];
                        man[j+1]=temp;
                    }
                    else if(man[j].money==man[j+1].money)
                    {
                        if(man[j].RP<=man[j+1].RP)
                        {
                            temp=man[j];
                            man[j]=man[j+1];
                            man[j+1]=temp;
                        }
                    }
                }
            }
        }
        for(i=1; i<=n; i++)
        {
            printf("%lld %lld %lld\n",man[i].score,man[i].money,man[i].RP);
        }
    }
    return 0;
}
