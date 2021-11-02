#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[100];
    while(scanf("%s",str)!=EOF)
    {
        if(str[0]=='J')
        {
            printf("Yao\n");
        }
        else if(str[0]=='Y')
        {
            printf("Check now\n");
        }
    }
    return 0;
}


