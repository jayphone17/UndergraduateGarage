#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long A,B,sum;
    int m;
    int i;
    while(scanf("%d",&m)!=EOF)
    {
        if(m==0)break;
        scanf("%lld&lld",&A,&B);
        sum=A+B;
        int str[50],num=0;
        do
        {
            str[num++]=sum%m;
            sum=sum/m;
        }
        while(sum!=0);

        for(i=num-1;i>=0;i--)
        {
            printf("%d",str[i]);
        }
        printf("\n");
    }
    return 0;
}
