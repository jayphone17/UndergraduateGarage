#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        int sum=1,i;
        for(i=0;i<b;i++)
        {
            sum=sum*a;
            sum=sum%10;
        }
        printf("%d\n",sum);
    }


    return 0;
}

