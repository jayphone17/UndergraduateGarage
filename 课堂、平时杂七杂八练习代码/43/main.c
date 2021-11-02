#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int T;
    double a,b,c,s,area;
    scanf("%d",&T);
    int i;
    for(i=0; i<T; i++)
    {
        scanf("%lf%lf%lf",&a,&b,&c);
        s=(a+b+c)/2;
        area=sqrt(s*(s-a)*(s-b)*(s-c));
        if(a+b>c && a+c>b && b+c>a)
            printf("%.3lf\n",area);
        else
            printf("-1\n");
    }
return 0;
}
