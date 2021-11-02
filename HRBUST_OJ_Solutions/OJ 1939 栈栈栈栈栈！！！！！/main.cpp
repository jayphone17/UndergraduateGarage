#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stack>

using namespace std;



int main()
{
    int T;
    while(scanf("%d",&T)!=EOF)
    {
        int x;
        char a[20];
        stack<int>sta;
        while(T--)
        {
            scanf("%s",a);
            if(strcmp(a,"push")==0)
            {
                scanf("%d",&x);
                sta.push(x);
            }
            if(strcmp(a,"pop")==0)
            {
                if(sta.empty())
                {
                    printf("this is empty!\n");
                }
                else
                {
                    printf("%d\n",sta.top());
                    sta.pop();
                }
            }
            if(strcmp(a,"query")==0)
            {
                if(sta.empty())
                {
                    printf("this is empty!\n");
                }
                else
                {
                    while(!sta.empty())
                    {
                        printf("%d\n",sta.top());
                        sta.pop();
                    }


            }
        }
        printf("\n");
    }
    return 0;
}
