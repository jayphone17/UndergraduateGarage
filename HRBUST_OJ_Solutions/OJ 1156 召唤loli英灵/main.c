#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int i;
    while(~scanf("%d",&n))
    {
        if(n<7)
            printf("0\n");
        else
        {
            for(i=1; i<=n; i++)
            {
                if(i%7==0 && (i%10==7 || i%100/10==7 || i%1000/100==7 || i/1000%10==7 ))
                    printf("%d\n",i);
            }
        }
    }
    return 0;
}
