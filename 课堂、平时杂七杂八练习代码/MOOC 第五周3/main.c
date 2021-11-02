#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b;
    printf("Input your birth year:");
    scanf("%d",&a);
    printf("Input this year:");
    scanf("%d",&b);
    int d=0;
    for(int i=a; i<=b; i++)
    {
        if(i%4==0&&i%100!=0||i%400==0)
        {
            printf("%d\n",i);
            d++;
        }
    }
    printf("count=%d\n",d);
}
