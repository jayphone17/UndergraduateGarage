#include<stdio.h>
#include<math.h>
int main()
{
    int i=120;
    double number;
    int down,up,si;
    while(scanf("%lf",&number)!=EOF)
    {
        if(i>0)
           {
            up=ceil(number);
            down=floor(number);
            si=round(number);
            printf("%d %d %d\n",up,down,si);
            i--;
           }
    }

    return 1;
}