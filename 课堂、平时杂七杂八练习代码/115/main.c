#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int i,j;
        for(i=1;i<=n;i++) // ��������������n
        {
            for(j=i;j<i+n;j++) //��������
            {
                if(j<=9)   //9���ϵ�����ǰ�治��Ҫ�ո�
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