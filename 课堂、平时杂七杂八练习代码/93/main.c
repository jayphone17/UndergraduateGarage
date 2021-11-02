#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A,B,C,D,E;
    while(scanf("%d%d%d%d%d",&A,&B,&C,&D,&E)!=EOF)
    {
        int q,w,e,r,t,y;
        q=A%E;
        w=B%E;
        e=C%E;
        r=D%E;
        t=q*w*e*r;
        y=t%E;
        printf("%d\n",y);
    }

    return 0;
}
