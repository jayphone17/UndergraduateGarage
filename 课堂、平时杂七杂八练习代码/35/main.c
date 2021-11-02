#include<stdio.h>
#include<string.h>
int main()
{
    int number=0;
    int i;
    char s[225];
    while(1)
    {
        scanf("%s",s);
        int y;
        y=strlen(s);
        printf("%d",y);
        for(i=0; i<y; i++)
        {
            if(s[i]<='9'&&s[i]>='0')
                number++;
        }
        printf("%d\n",number);
    }
}
