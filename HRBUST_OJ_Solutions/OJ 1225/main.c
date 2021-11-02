#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[100];
int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    while(T--)
    {
        int i,len;
        gets(str);
        len=strlen(str);
        if(str[0]>='a' && str[0]<='z')
            printf("%c",str[0]-32);
        else if(str[0]>='A' && str[0]<='Z')
            printf("%c",str[0]);
        for(i=0; i<len; i++)
        {
            if(str[i]==' ' && str[i+1]>='a' && str[i+1]<='z')
            {
                printf("%c",str[i+1]-32);
            }
            else if(str[i]==' ' && str[i+1]>='A' && str[i+1]<='Z')
            {
                printf("%c",str[i+1]);
            }

        }
        printf("\n");
    }
return 0;
}
