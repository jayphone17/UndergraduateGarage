#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x,y,i,j;
    while(~scanf("%lf%lf%lf%lf",&x,&y,&i,&j))
    {
        int m;
        double n;
        n=(y+j)/(i-x);
        m=(int)n;
        if(y+j==0)
        {
            if(i-x==0)
            {
                printf("He is right\n");
            }
            else
            {
                printf("Back to the adult, it surely has something\n");
            }
        }
        else
        {
            if(m==n && m>=1)
            {
                printf("He is right\n");
            }
            else
            {
                printf("Back to the adult, it surely has something\n");
            }
        }

    }
    return 0;
}
