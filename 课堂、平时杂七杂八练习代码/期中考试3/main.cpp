#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main()
{
    double n;
    while(~scanf("%lf",&n))
    {
        double jueduizhi;
        jueduizhi=fabs(n);
        printf("%.2lf\n",jueduizhi);

    }
    return 0;
}
