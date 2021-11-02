#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char s[102];
    while(scanf("%s",s)!=EOF)
    {
        getchar();
        int i,len;
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
