#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[101];
    while(gets(str))
    {
        int len;
        len=strlen(str);
        for(int i=0; i<len; i++)
        {
            if(str[i-1]==' ')
                printf("%c",str[i]-32);
            else
                printf("%c",str[i]);
        }
        printf("\n");
    }
    return 0;
}
