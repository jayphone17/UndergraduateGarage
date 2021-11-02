#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    int T;
    while(scanf("%d",&T)!=EOF)
    {
        char str[10000];
        scanf("%c",str);
        int i,len,num;
        len=strlen(str);
        for(i=0; i<len; i++)
        {
            if((str[i] >='a' && str[i] <='z') || (str[i] >='A' && str[i] <='Z'))
            {
                num++;

            }
            printf("%d",num);
        }
    }
    return 0;
}
