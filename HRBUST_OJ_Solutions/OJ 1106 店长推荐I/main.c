#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[55];
    while(~scanf("%s",str))
    {
        int ans=0;
        int sum=0;
        int flag=0;
        int len,i;
        len=strlen(str);
        for(i=0; i<len; i++)
        {
            if(str[i]=='v')
            {
                ans++;
            }
            else if(str[i]=='g')
            {
                sum++;
            }
            else if(str[i]=='a')
            {
                flag++;
            }
        }
        flag=flag/3;
        if(flag<=ans && flag<=sum)
        {
            printf("THE NUMBER 1S %d.\n",flag);
        }
        else if(ans<=flag && ans<=sum)
        {
            printf("THE NUMBER 1S %d.\n",ans);
        }
        else if(sum<=flag && sum<=ans)
        {
            printf("THE NUMBER 1S %d.\n",sum);
        }
    }
    return 0;
}
