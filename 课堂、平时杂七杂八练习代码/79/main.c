#include <stdio.h>
#include <stdlib.h>

int main()
{
    double f;
    while(scanf("%lf",&f)!=EOF)
    {
        double a;
        a=f*100;
        a=(int)(a);
        double b;
        b=(double)(a/100);
        printf("%.2f\n",b);
    }
    return 0;
}
