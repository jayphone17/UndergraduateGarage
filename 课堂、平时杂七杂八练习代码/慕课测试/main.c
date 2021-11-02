#include <stdio.h>
#include <string.h>
int main()
{
    char str[205];
    while(gets(str)!=NULL)
    {
        int len=strlen(str);
        for(int i=0;i<len;i++)
        {
            if(i+8>=len) break;
            if((str[i]=='m'||str[i]=='M')&&(str[i+1]=='a'||str[i+1]=='A')&&
            (str[i+2]=='r'||str[i+2]=='R')&&(str[i+3]=='s'||str[i+3]=='S')&&
            (str[i+4]=='h'||str[i+4]=='H')&&(str[i+5]=='t'||str[i+5]=='T')&&
            (str[i+6]=='o'||str[i+6]=='O')&&(str[i+7]=='m'||str[i+7]=='M')&&
            (str[i+8]=='p'||str[i+8]=='P'))
            {
                str[i]='f';str[i+1]='j';str[i+2]='x';str[i+3]='m';
                str[i+4]='l';str[i+5]='h';str[i+6]='x';
                str[i+7]='*';str[i+8]='*';
            }
        }
        for(int i=0;i<len;i++)
        {
            if(str[i]!='*')
            printf("%c",str[i]);
        }
        printf("\n");
    }
}