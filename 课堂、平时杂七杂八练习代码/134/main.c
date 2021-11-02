#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char str[100];
        scanf("%s",str);
        int len;
        len=strlen(str);
        int i;
        char ch;
        for(i=0; i<len; i++)
        {
            ch=str[i];

            if(ch=='z')
            {
                ch='a';
            }
            else if (ch=='Z')
            {
                ch='A';
            }
            else
            {
                ch=ch+1;
            }
            printf("%c",ch);
        }
        printf("\n");
    }
    return 0;
}
