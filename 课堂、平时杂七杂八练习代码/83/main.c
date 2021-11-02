#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long x,y;
    while(scanf("%lld%lld",&x,&y)!=EOF)
    {
        int tuzi,ji;
        tuzi=y/2-x;
        ji=2*x-y/2;
        if(y%2==0 && x>=0 && y>=0 && tuzi>=0 && ji>=0)
        {
          printf("chicken:%d rabbit:%d\n",ji,tuzi);
        }
        else
        {
            printf("something wrong\n");
        }

    }
    return 0;
}
