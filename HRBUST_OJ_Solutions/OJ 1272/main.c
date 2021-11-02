#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a;
    while(~scanf("%llf",&a))
    {
        int b=(a*100);
        a=(1.0*b)/100;
        printf("%.2llf\n",a);
    }
    return 0;
}
