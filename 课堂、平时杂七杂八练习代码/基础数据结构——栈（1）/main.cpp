#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <iostream>
using namespace std;
int main()
{
    char str[11111];
    while(gets(str))
    {
        stack<char>sta;
        int len;
        int i;
        int flag=1;
        len=strlen(str);
        while(!sta.empty())
        {
            sta.pop();
        }
        for(i=0; i<len; i++)
        {
            if(str[i]=='(' || str[i]=='[' || str[i]=='{')
            {
                sta.push(str[i]);
            }
            if(str[i]==')')
            {
                if(!sta.empty() && sta.top()=='(')
                {
                    sta.pop();
                }
                else
                {
                    flag=0;
                    break;
                }
            }
            if(str[i]==']')
            {
                if(!sta.empty() && sta.top()=='[')
                {
                    sta.pop();
                }
                else
                {
                    flag=0;
                    break;
                }
            }
            if(str[i]=='}')
            {
                if(!sta.empty() && str[i]=='}')
                {
                    sta.pop();
                }
                else
                {
                    flag=0;
                    break;
                }
            }
        }
        if(sta.empty() && flag==1)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
}
