#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a1,a2,a3,b1,b2,b3;
        double a,b,c;
        double s,area;
        scanf("%d%d",&a1,&b1);
        scanf("%d%d",&a2,&b2);
        scanf("%d%d",&a3,&b3);
        a=sqrt((a1-a2)*(a1-a2)+(b1-b2)*(b1-b2));
        b=sqrt((a2-a3)*(a2-a3)+(b2-b3)*(b2-b3));
        c=sqrt((a3-a1)*(a3-a1)+(b3-b1)*(b3-b1));
        s=(a+b+c)/2;
        area=sqrt(s*(s-a)*(s-b)*(s-c));
        if((a+b)>c&&fabs(a-b)<c&&fabs(a-c)<b&&(a+c)>b&&fabs(b-c)<a&&(b+c)>a)
        {
            printf("%.2f\n",area);
        }
        else
        {
            printf("fail\n");
        }
    }
    return 0;
}
