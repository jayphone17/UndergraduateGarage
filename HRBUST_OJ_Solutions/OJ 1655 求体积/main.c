#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926

int main()
{
    double h,volume;
    while(scanf("%lf",&h)!=EOF)
    {
        volume=PI*h*h*h/6;
        printf("%.2lf\n",volume);
    }
    return 0;
}
