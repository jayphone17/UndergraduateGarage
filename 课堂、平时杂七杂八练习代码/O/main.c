#include<stdio.h>
#include<string.h>
int a[10005];
int main()
{
    char str[10005];
    while(gets(str))
    {
        int len=strlen(str);
        memset(a,0,sizeof(a));
        int Max=0;
        char c;
        for(int i=0; i<len; i++)
        {
            if(str[i]>='A'&&str[i]<='Z')
            {
                a[str[i]-'A']++;
                if(a[str[i]-'A']>Max)
                {
                    Max=a[str[i]-'A'];
                    c=str[i];
                }
            }
        }
        printf("%c:%d\n",c,Max);
    }
}
