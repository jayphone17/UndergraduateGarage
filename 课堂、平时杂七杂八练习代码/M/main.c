#include<stdio.h>
#include<string.h>
int a;
int main()
{
    char str[105];
    while(~scanf("%s",str))
    {
        int len;
        len=strlen(str);
        for(int i=len-1; i>=0; i--)
        {
            printf("%c",str[i]);
        }
        printf("\n");
    }
}
