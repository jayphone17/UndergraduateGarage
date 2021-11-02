#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    double R[1111111];
    int n;
    while(~scanf("%s%d",R,&n))
    {
        double x[11111111]=pow(R,n);
        printf("%s\n",x);

    }
    return 0;
}
