#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    int T;
    int str[20];
    int len,i;
    while(T--)
    {
        scanf("%d",&str);
        len=sizeof(str);
        for(i=len; i>0; i--)
        {

            if(str[i]==1)
                printf("O");
            if(str[i]==2)
                printf("T");
            if(str[i]==3)
                printf("T");
            if(str[i]==4)
                printf("F");
            if(str[i]==5)
                printf("F");
            if(str[i]==6)
                printf("S");
            if(str[i]==7)
                printf("S");
            if(str[i]==8)
                printf("E");
            if(str[i]==9)
                printf("N");
        }
    }
    return 0;
}
