#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    int a,b,c,d;
    scanf("%d",&N);
    while(N--)
    {

        scanf("%d%d%d",&a,&b,&d);
        c=a+b-d;
        if(b>d || a+b-d>=3600)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        else if(c>0)
        {
            printf("%.2f\n",1.0*c/10);
        }
        else
        {
            printf("0.00\n");
        }
    }
    return 0;
}
