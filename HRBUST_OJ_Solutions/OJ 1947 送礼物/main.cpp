#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <stack>
using namespace std;
char str[11111];

int main()
{
    while(gets(str))
    {
        stack<char>s;
        int len;
        int x;
        int i;
        len=strlen(str);
        while(!s.empty())
        {
            s.pop();
        }
        for(i=0; i<len; i++)
        {
            if(str[i]=='(')
            {
                s.push(str[i]);
            }
            if(str[i]==')' && !s.empty())
            {
                s.pop();
            }
            if(str[i]=='B')
            {
                x=s.size();
                break;
            }
        }
        printf("%d\n",x);
    }
    return 0;
}
