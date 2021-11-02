#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long N;
        scanf("%lld",&N);
        int i,flag=0;
        double r;
        r=sqrt(N);
        if(r*r==N)
        {
            flag++;
        }

        for(i=1;i<r;i++)
        {
            if(N%i==0)
                flag+=2;;
        }
        printf("%d\n",flag);
    }
    return 0;
}
