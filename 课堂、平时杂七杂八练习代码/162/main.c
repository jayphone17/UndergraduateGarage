#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int x1,y1,x2,y2,v;
    double distance,time;
    while(scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&v)!=EOF)
    {
        y1=-y1;
        distance=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        time=distance/v;
        printf("%.2lf\n",time);
    }

    return 0;
}
