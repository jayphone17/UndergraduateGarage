#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    while(T--)
    {

        int i,num=0,word=0;
        char str[10000];
        gets(str);
        for(i=0; str[i]!='\0'; i++)
        {
            if(str[i]==' ')
            {
                word=0;
            }
            else if(word==0)
            {
                word=1;
                num++;
            }
        }
        printf("%d\n",num);
    }
    return 0;
}

