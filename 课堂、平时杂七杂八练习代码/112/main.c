#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[105];
    while(gets(str))
    {
        int i,len;
        len=strlen(str);
        for(i=0; i<len; i++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
