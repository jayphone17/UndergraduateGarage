#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    printf("Input n:");
    scanf("%d",&n);
    if(n<1000||n>1000000)
    {
        printf("Input error!\n");
        return 0;
    }
    for(int i=999; i>99; i--)
    {
        if(n%i==0)
        {
            n=i;
            break;
        }
    }
    printf("%d\n",n);
}
