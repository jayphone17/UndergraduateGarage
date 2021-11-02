#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    double x1,y1,x2,y2;
    double len;
    while(~scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2))
    {
        len=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        printf("%.2lf\n",len);
    }
    return 0;
}
