#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char s1[20];
        scanf("%s",&s1);
        int len;
        len=strlen(s1);
        if(s1[len-1]=='p' && s1[len-2]=='p' && s1[len-3]=='c' && s1[len-4]=='.')
        {
            printf("c++\n");
        }
        else if(s1[len-1]=='a' && s1[len-2]=='v' && s1[len-3]=='a' && s1[len-4]=='j' && s1[len-5]=='.')
        {
            printf("java\n");
        }
        else if(s1[len-1]=='c' && s1[len-2]=='.')
        {
            printf("c\n");
        }
        else
        {
            printf("none\n");
        }

    }
    return 0;
}
