#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int flag,ans;
    char str[100];
    while(~scanf("%s",str))
    {
        getchar();//吸收回车
        flag=0;
        ans=0;
        int i,len;
        len=strlen(str);
        for(i=0; i<len; i++)
        {
            if(str[i]=='0')
                flag++;
            else if(str[i]=='O')
                ans++;
        }
        printf("%d %d\n",flag,ans);
    }
    return 0;
}
