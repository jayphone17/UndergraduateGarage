#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
   int n;
   scanf("%d",&n);
   while(n--)
   {
    double a,b,c;
    float s,area;
    scanf("%lf%lf%lf",&a,&b,&c);
    s=(a+b+c)/2;
    area=sqrt(s*(s-a)*(s-b)*(s-c));
    if((a+b>c)&&(a+c>b)&&(b+c>a))
    {
        printf("%.1f\n",area);
    }
    else
    {
        printf("Illegal!\n");
    }
   }

    return 0;
}
