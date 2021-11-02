#include <stdio.h>
#include <stdlib.h>

int main()
{
    float sausege,beer;
    for(beer=0;beer<25.4;beer++)
    sausege=(63.5-beer*2.5)/7.2;
    if(sausege*7.2+beer*2.5==63.5 && beer>sausege)
    printf("%f%f",beer,sausege);
    return 0;
}
