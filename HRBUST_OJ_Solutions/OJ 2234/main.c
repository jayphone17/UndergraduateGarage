#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int P,Q;
        scanf("%d%d",&P,&Q);
        if(P==1)
        {
            printf("%d\n",Q);
        }
        else
        {
            int sum=0,ans=0;
            for(int i=14;i>=0;i--)
            {
                while(sum+pow(P,i)<=Q)
                {
                    ans++;
                    sum=sum+pow(P,i);
                }
                if(sum==Q)
                    break;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
