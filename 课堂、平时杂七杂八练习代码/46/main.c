#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    double h,r,V,area;
    while(scanf("%lf%lf",&h,&r)!=EOF)
    {
        area=M_PI*r*r;
        V=1.0/3.0*area*h;
        printf("%.2lf\n",V);
    }
    return 0;
}
