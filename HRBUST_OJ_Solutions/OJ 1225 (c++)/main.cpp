#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    char s[200];
    while(cin>>T)
    {
        getchar();//要注意吸掉回车换行，本人就是这个地方卡了好久，没看出来！
        while(T--)
        {
            gets(s);
            int len=strlen(s);
            if(s[0]>='a'&&s[0]<='z')
            printf("%c",s[0]-32);
            else if(s[0]>='A'&&s[0]<='Z') printf("%c",s[0]);
            for(int i=1;s[i]!='\0';i++)
                {
                    if(s[i]==' '&&(s[i+1]>='a'&&s[i+1]<='z'))
                printf("%c",s[i+1]-32);
                else if(s[i]==' '&&(s[i+1]>='A'&&s[i+1]<='Z'))
                    printf("%c",s[i+1]);
                }
                printf("\n");
        }
    }
    return 0;
}