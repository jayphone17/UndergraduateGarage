#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

char a[205];

int main()
{
    while(gets(a)!=NULL)
    {
        int len;
        int i;
        len=strlen(a);
        for(i=0; i<len; i++)
        {

            if((  a[i]=='M'||  a[i]=='m'  )&&
                    (a[i+1]=='A'||a[i+1]=='a')&&
                    (a[i+2]=='R'||a[i+2]=='r')&&
                    (a[i+3]=='S'||a[i+3]=='s')&&
                    (a[i+4]=='H'||a[i+4]=='h')&&
                    (a[i+5]=='T'||a[i+5]=='t')&&
                    (a[i+6]=='O'||a[i+6]=='o')&&
                    (a[i+7]=='M'||a[i+7]=='m')&&
                    (a[i+8]=='P'||a[i+8]=='p'))
            {
                a[i]='f';
                a[i+1]='j';
                a[i+2]='x';
                a[i+3]='m';
                a[i+4]='l';
                a[i+5]='h';
                a[i+6]='x';
                a[i+7]='*';
                a[i+8]='*';
            }
        }
        for(i=0; i<len; i++)
        {
            if(a[i]!='*')
                printf("%c",a[i]);
        }
        printf("\n");
    }
    return 0;
}
