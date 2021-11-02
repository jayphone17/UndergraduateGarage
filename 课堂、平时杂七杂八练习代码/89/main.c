#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    while(scanf("%d" ,&a)!=EOF)
    {
        unsigned b=1;
        printf("%u\n",a+b);
    }
    return 0;
}
