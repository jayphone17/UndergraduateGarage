#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int i,j;
        for(i=1;i<=n;i++) // 控制列数不超过n
        {
            for(j=i;j<i+n;j++) //控制行数
            {
                if(j<=9)   //9以上的数字前面不需要空格
                {
                    printf(" ");
                }
                printf("%d",j); //

            }
            printf("\n");
        }
    }
    return 0;
}