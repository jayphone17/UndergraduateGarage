#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    while(~scanf("%d",&x))
    if(x<=3)
    {
        printf("1\n");
    }
    else
    {
        printf("%d\n",x-3+1);
    }
    return 0;
}
