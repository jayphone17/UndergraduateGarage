#include <stdio.h>
#include <stdlib.h>

int main()
{
    double n;
    while(scanf("%lf",&n)!=EOF)
    {
        while(n>18)
        {
            n/=18;
        }
        if(n<=9)
            printf("Stan wins.\n");
        else
            printf("Ollie wins.\n");
    }
    return 0;
}
