#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char str[1111];
    while(gets(str))
    {
        int i;
        int len;
        len=strlen(str);
        int small=0;
        int big=0;
        int blanks=0;
        for(i=0; i<len; i++)
        {
            if(str[i]>='a' && str[i]<='z')
            {
                small++;
            }
            else if(str[i]>='A' && str[i]<='Z')
            {
                big++;
            }
            else if(str[i]==' ')
            {
                blanks++;
            }
        }
        printf("%d %d %d\n",small,big,blanks);
    }

    return 0;
}
