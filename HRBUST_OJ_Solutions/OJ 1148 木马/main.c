#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100005];
    char stock[100005];
    int K;
    int i;
    int Circle;
    while(scanf("%s",str)!=EOF)
    {
        scanf("%d",&K);
        int len;
        len=strlen(str);

        int Circle=K%len;

        for(i=0; i<len; i++)
        {
            stock[i]=str[i];
        }
        for(i=0; i<len-Circle; i++)
        {
            str[i+Circle]=stock[i];
        }
        for(i=0; i<Circle; i++)
        {
            str[i]=stock[len-Circle+i];
        }
        printf("%s\n",str);
    }
    return 0;
}
