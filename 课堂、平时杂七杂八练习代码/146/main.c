#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int L;
    while(scanf("%d",&L)!=EOF)
    {
        double area;
        if(L==0)
            break;
        else
        {
            area=(L*L)*1.0/(2*M_PI);

            printf("%.2lf\n",area);
        }
    }
    return 0;
}
