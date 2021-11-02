#include<stdio.h>
#include<stdlib.h>

#define PI 3.1415927

int main()
{
    double r;
    double V;
    while(~scanf("%lf",&r))
    {
        V=4*PI*r*r*r/3;
        printf("%.3lf\n",V);
    }
    return 0;
}
