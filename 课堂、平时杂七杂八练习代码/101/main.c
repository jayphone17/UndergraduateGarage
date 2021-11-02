#include <stdio.h>
#include <stdlib.h>

int main()
{
    int C;
    scanf("%d",&C);
    while(C--)
    {
        int N;
        int i;
        double str[1005];
        scanf("%d",&N);
        double average,sum=0;
        for(i=0; i<N; i++)
        {
            scanf("%lf",&str[i]);
            sum=sum+str[i];
        }
        average=sum/N;
        int flag=0;
        for(i=0; i<N; i++)
        {
            if(str[i]>average)
            {
                flag++;
            }
        }
        double a=flag*1000000/N;
        a=a/10000;
        printf("%.3f%%\n",a);
    }
    return 0;
}
