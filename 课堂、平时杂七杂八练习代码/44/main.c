#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        double a,b,c;
        double s,area;
        scanf("%lf%lf%lf",&a,&b,&c);
        s=(a+b+c)/2;
        area=sqrt(s*(s-a)*(s-b)*(s-c));
        if(a+b>c && a+c>b && b+c>a)
        printf("%.2lf\n",area);
        else
            printf("it's not a triangle!\n");
    }
    return 0;
}
