//ÕýÈ·´ð°¸
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int T;
    float a,b,c;
    double s,area;
    scanf("%d",&T);
    int i;
    for(i=0; i<T; i++)
    {
        if(i!=0)
        {
            printf("\n");
        }
        scanf("%f%f%f",&a,&b,&c);
        s=(a+b+c)/2;
        area=sqrt(s*(s-a)*(s-b)*(s-c));
        if(a+b>c && a+c>b && b+c>a)
            printf("%.3lf\n",area);
        else
            printf("-1\n");
    }
return 0;
}