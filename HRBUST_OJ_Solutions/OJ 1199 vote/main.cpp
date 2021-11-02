#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
    int N,a[105],i;
    int sum;
    while(~scanf("%d",&N))
    {
        if(N==0)
            return 0;
        for(i=0; i<N; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+N);
        sum=0;
        for(i=0; i<=N/2; i++)
        {
            sum+=a[i]/2+1;
        }
        printf("%d\n",sum);
    }
    return 0;
}
