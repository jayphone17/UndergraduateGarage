#include <stdio.h>
#include <stdlib.h>

int main()
{
    double f;
    while(scanf("%lf",&f)!=EOF)
    {
        int a;
        a=f*100;
        double b;
        b=(double)(a/100);
        printf("%f  %d ",f,a);
        printf("%.2f\n",b);
    }
    return 0;
}
