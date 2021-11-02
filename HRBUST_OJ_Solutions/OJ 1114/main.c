#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    char str[1111];
    int array[1111];
    scanf("%d",&n);
    while(n--)
    {
        int max;
        int i,len,d;
        scanf("%s",str);
        len=strlen(str);
        memset(array,0,sizeof(array));
        for(i=0; i<len; i++)
        {
            array[str[i]-'a']++;
        }
        max=0;
        for(i=0; i<26; i++)
        {
            if(array[i]>max)
                max=array[i];
            d=i;
        }
        printf("%c\n",d+'a');
    }
    return 0;
}
