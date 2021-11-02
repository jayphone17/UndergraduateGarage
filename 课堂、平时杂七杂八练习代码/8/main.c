#include<stdio.h>
#include<math.h>
int main()
{
    int i;
    for(i=0;i<=120;i++)
    {
        double number;
        while(scanf("%lf",&number)!=EOF)
        {
            double down,up,si;
            up=ceil(number);
            down=floor(number);
            si=round(number);
            printf("%lf%lf%lf",up,down,si);
        }
    }

    return 0;
}