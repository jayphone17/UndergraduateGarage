#include<stdio.h>
int main()
{
    int A,B,sum,i=0;
    while(scanf("%d%d",&A,&B)!=EOF)
    {
        sum=A+B;
        printf("%d\n",sum);
        if(i>0)
            {
                printf("\n");
            }
        i++;
    }
    return 0;
}