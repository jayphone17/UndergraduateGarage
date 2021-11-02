#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int flag=0;
    for(i=1;i<1000000;i++)
    {
        if(1000000%i==0)
            flag++;
    }
    printf("%d\n",flag);
    return 0;
}
