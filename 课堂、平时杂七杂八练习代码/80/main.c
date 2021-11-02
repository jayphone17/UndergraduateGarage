#include <stdio.h>
#include <math.h>

int main()
{
    double f;
    double n,t;
    while(scanf("%lf",&f)!=EOF)
    {
        n=f*100;
        t=floor(n);
        printf("%.2lf\n",t/100);
    }
    return 0;
}