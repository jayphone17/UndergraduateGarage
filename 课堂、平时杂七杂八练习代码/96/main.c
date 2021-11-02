#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sausage,beer;
    for(sausage=1; sausage<=8; sausage++)
    {
        for(beer=sausage+1; beer<=25; beer++)
        {
            if(fabs(sausage*7.2+beer*2.5-63.5)<1e-6)
            {
                printf("%d %d\n",beer,sausage);
            }
        }
    }
    //sausage=(63.5-beer*2.5)/7.2;
    return 0;
}
