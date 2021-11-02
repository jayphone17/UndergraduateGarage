#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[105];

int main()
{
    while(scanf("%s",str)!=EOF)
    {
        if(strstr(str,"bkpstor"))
        {
            printf("Warning\n");
        }
        else
        {
            printf("Safe\n");
        }
    }
    return 0;
}
