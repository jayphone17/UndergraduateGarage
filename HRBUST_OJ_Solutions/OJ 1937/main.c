#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    long long  n,k;
    while(scanf("%lld%lld",&n,&k)!=EOF)
    {
        int i;
        long long sum=0;
        for(int i=0;i<len;i++)
        {
            if(n<='9')
            {
                t=n-'0';
            }
            else
            {
                t=str[i]-'A'+10;
            }
            sum=sum*k+t;
        }

    }
    return 0;
}
