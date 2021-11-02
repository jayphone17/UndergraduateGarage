#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    //long long k;
    char str[25]=" ";
    while(scanf("%s",str)!=EOF)
    {
        int t,len;
        len=strlen(str);
        long long sum=0;
        for(int i=0;i<len;i++)
        {
            if(str[i]<='9')
            {
                t=str[i]-'0';
            }
            else
            {
                t=str[i]-'A'+10;
            }
            sum=sum*2+t;
        }
       printf("%d\n",sum);
    }
    return 0;
}
