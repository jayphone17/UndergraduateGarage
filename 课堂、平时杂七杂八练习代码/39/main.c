#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i,sum=1;
        for(i=1;i<=n;i++)
        {
            sum=sum*i;
        }
        printf("%d\n",sum);
        sum=1;//�ع��ʼֵ
    }
    return 0;
}
