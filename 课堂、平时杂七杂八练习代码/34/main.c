#include<stdio.h>
#include<string.h>

int main()
{
    char a[225];
    scanf("%s",a[225]);
    int i,len,digit=0;
    len=strlen(a);
    for(i=0; i<=len; i++)
    {
        if(a[i]>='0'&&a[i]<='9')
            digit++;
    }
    printf("%d\n",digit);
    return 0;
}
