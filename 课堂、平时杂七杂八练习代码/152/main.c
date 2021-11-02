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
        for(i=0;i<len;i++)
        {
            if(str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z')
            {
                str[i]=str[i];
            }
            else if(str[i]>='0' && str[i]<='9')
            {
                str[i]='\n';
            }

        }
        printf("%s\n",str);
    }

    return 0;
}
