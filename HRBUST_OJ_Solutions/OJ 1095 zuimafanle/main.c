#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
    {
        long long  score;
        long long  money;
        long long  RP;
    };

struct person man[10000];

int compare(person a,person b)
{
    if(a.score==b.score)
    {
        if(a.money==b.money)
        {
            if(a.RP>b.RP)
            return 1;
            else
            return 0;
        }
        else if(a.money> a.money)
            return 1;
        else
            return 0;
    }
    else if (a.score > b.score )
        return 1;
    else
        return 0;
}


int main()
{

    int N;

    scanf("%d",&N);
    while(N--)
    {
        int i;
        for(i=0;i<N;i++)
        {
            scanf("%lld%lld%lld",&man[i].score,&man[i]money,&man[i].RP);
        }
        for(i=0;i<N-1;i++)
            for(int j=n-1;j<N;j++)
        {
            if(compare (man[i],man[j])==1)
            {
                person temp=man[i];
                man[i]=man[j];
                man[j]=temp;
            }
        }
        for(i=0;i<N;i++)
        {
            printf("%lld%lld%lld\n",score,money,RP);
        }
    }
    return 0;
}
