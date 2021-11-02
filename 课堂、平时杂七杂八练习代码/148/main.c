#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char str[1000];
    while(~scanf("%s",str))
    {
        getchar();
        int i,j,len,a=0;
        bool num=false;
        len=strlen(str);
        for(i=0; i<len; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(str[i]==str[j])
                {
                    a=1;
                    break;
                }
                if(a)
                    break;
            }
        }
        if(a==1)
            printf("no\n");
        else
            printf("yes\n");
    }
    return 0;
}
