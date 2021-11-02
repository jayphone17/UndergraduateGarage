#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char str[20];
        gets(str);
        int i,len;
        len=strlen(str);
        for(i=0; i<len; i++)
        {
            if(str[i]=='1')
                str[i]='O';
            else if(str[i]23=='2')
                str[i]='T';
            else if(str[i]=='3')
                str[i]='T';
            else if(str[i]=='4')
                str[i]='F';
            else if(str[i]=='5')
                str[i]='F';
            else if(str[i]=='6')
                str[i]='S';
            else if(str[i]=='7')
                str[i]='S';
            else if(str[i]=='8')
                str[i]='E';
            else if(str[i]=='9')
                str[i]='N';
            /*else if(str[i]=='')
            str[i]=''
            else if(str[i]=='')
            str[i]=''
            else if(str[i]=='')
            str[i]=''
            else if(str[i]=='')
            str[i]=''
            else if(str[i]=='')
            str[i]=''
            else if(str[i]=='')
            str[i]=''
            else if(str[i]=='')
            str[i]=''
            else if(str[i]=='')
            str[i]=''
            else if(str[i]=='')
            str[i]=''
            else if(str[i]=='')
            str[i]=''
            else if(str[i]=='')
            str[i]=''*/
        }
        int j;
        for(j=20; j>=0; j--)
        {
            printf("%s\n",str);
        }
    }
    return 0;
}
