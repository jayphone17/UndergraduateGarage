#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int ll(int s)
{
    if(s==1||s==0)
        return 1;
    else
        return s*ll(s-1);
}
int main()
{
    for(int i=100;i<=999;i++)
        {
        int q,w,e;
        q=i/100;
        w=i/10%10;
        e=i%10;
        int m;

        m=ll(q)+ll(w)+ll(e);
        if(m==i){
            printf("%d\n",m);
        }
    }
}
