#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long f[5005];


int mult(int K)
{
    int sum=1;
    for(int i=1; i<=K; i++)
    {
        sum=sum*2;
    }
    return sum;
}


int main()
{
    int P,K;
    while(scanf("%d%d",&P,&K)!=EOF)
    {
        if(P==0 && K==0)
            return 0;
        f[1]=0;
        f[2]=1;
        for(int j=3; j<=P; j++)
        {
            f[j]=(f[j-1]+f[j-2])%mult(K);
        }
        printf("%d\n",f[P]%mult(K));
    }
    return 0;
}
