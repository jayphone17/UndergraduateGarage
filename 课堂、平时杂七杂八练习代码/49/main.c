#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char str[10000];
        gets(str);
        int i,len,num,count;
        len=strlen(str);
        for(int i=0; i<len; i++)
        {
            if(count == 1)
            {
                if(str[i] != ' ')//������ʼ
                {
                    num++;
                    count = 0;
                }
            }
            else if(str[i] == ' ')//��һ�����ʽ�����
                count = 1;
        }
        printf("%d\n",num);
    }
    return 0;
}
