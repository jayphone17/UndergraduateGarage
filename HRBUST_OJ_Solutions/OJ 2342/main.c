#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[10005];
    while(gets(str))
    {
        int i,flag=0,len;
        len=strlen(str);
        for(i=0;i<len-1;i++)
        {
            if(str[i]=='i' && str[i+1]=='f')
                flag++;
        }
        printf("%d\n",flag);
    }
    return 0;
}
