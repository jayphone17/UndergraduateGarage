#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

char a[100005];

int main()
{
    int flag,num;
    while(gets(a))
    {
        int len;
        flag=0;
        num=0;
        len=strlen(a);
        int i;
        for(i=len-1; i>=0; i--)
        {
            if(a[i]==' ')
                flag++;
            else
                break;
        }
        len=len-flag;
        for(i=len-1; i>=0; i--)
        {
            if(a[i]>='a' && a[i]<='z' || a[i]>='A' && a[i]<='Z')
                num++;
            else
                break;
        }
        printf("%d\n",num);
    }
    return 0;
}
