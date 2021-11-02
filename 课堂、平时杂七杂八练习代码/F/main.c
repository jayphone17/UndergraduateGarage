#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if((n%4==0 && n%100!=0)|| n%400==0)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
}
