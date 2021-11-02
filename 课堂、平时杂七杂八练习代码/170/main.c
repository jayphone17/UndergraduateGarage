#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char b[25],g[25],x[25];
    while(scanf("%s%s%s",b,g,x)!=EOF)
    {
        printf("%s will win\n",g);
    }

    return 0;
}
