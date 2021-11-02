#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    int y;
    while(~scanf("%d",&x))
    {
        if(x<0)
        {
            y=x-1;
        }
        else if (x==0)
        {
            y=0;
        }
        else if (x>0)
        {
            y=x+1;
        }
        printf("%d\n",y);
    }
    return 0;
}
