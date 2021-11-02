#include<stdio.h>
#include<string.h>
int main()
{
    char str[105];

    while(gets(str))
    {
        int open=0,flag=0;
        int len;
        len=strlen(str);
        int i;
        for(i=0; i<len; i++)
        {
            if((str[i]>='0'&&str[i]<='9')&&open==0&&flag==1)
            {
                printf("\n");
                open=1;
            }
            else if(!(str[i]>='0'&&str[i]<='9'))
            {
                printf("%c",str[i]) ;
                open=0;
                flag=1;
            }
        }
        if(!(str[len-1]>='0'&&str[len-1]<='9'))
            printf("\n");

    }
    return 0;
}

