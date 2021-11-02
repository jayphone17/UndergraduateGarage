#include<stdio.h>
#include<string.h>
#include<stack>

using namespace std;
int main()
{
    char s[105];
    while(gets(s))
    {
        stack<char>sta;
        int flag=1,i;
        int len=strlen(s);
        for(i=0;i<len;i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
            {
                        sta.push(s[i]);
            }
            if(s[i]==')')
            {
                 if(!sta.empty()&&sta.top()=='(')
                 {
                      sta.pop();
                 }
                  else
                  {
                       flag=0;break;
                  }
            }
            if(s[i]=='}')
            {
                   if(!sta.empty()&&sta.top()=='{')
                   {
                        sta.pop();
                   }
                   else
                   {
                        flag=0;break;
                   }
            }
            if(s[i]==']')
            {
                   if(!sta.empty()&&sta.top()=='[')
                   {
                        sta.pop();
                   }
                   else
                   {
                        flag=0;break;
                   }
            }
        }
        if(flag==1&&sta.empty())
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
        while(!sta.empty())
        {
            sta.pop();
        }
    }
    return 0;
}