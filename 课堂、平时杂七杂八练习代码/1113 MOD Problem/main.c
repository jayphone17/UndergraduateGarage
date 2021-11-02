#include <stdio.h>
#include <string.h>
int main()
{
    char a[10000]= {'\0'};//清空字符串
    while(~scanf("%s",a) && a[0]-'0'!=0)
    {
        int s=0;
        for(int i=0; a[i]!='\0'; i++)
        {
            s=(s*10+a[i]-'0')%33;
        }
        if(s==0)
            printf("OK\n");
        else
            printf("Orz\n");
    }
    return 0;
}
