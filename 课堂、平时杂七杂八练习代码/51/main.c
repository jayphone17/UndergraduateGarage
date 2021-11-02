#include <stdio.h>
#include <string.h>

#define SIZE 20

int main()
{
    char str[SIZE]={'\0'};
    int count=0;
    int flag=0;
    printf("please input the string\n");
    gets(str);
    puts(str);
    int length = strlen(str);
    for (int i=0;i<length;i++)
    {
        //判断是不是空格，是的话flag=0,
        //不是的话判断前面是不是空格即flag是否等于0，
        //是空格的话说明是新单词的开始
        if(str[i]==' ')
        {
            flag=0;
        }
        else
        {
            if(flag==0)
            {
                count++;
                flag=1;
            }
        }
    }
    printf("%d\n",count);
    return 0;

}