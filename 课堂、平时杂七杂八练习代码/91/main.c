#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100];
    while(scanf("%s",str)!=EOF)
    {
        int X=0,Y=0;
        int i,len;
        len=strlen(str);
        for(i=0; i<len; i++)
        {
            if(str[i]=='0')
            {
                X++;
            }
            else if(str[i]=='O')
            {
                Y++;
            }
        }
        printf("%d %d\n",X,Y);
    }
    return 0;
}
