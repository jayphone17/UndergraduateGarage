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
        //�ж��ǲ��ǿո��ǵĻ�flag=0,
        //���ǵĻ��ж�ǰ���ǲ��ǿո�flag�Ƿ����0��
        //�ǿո�Ļ�˵�����µ��ʵĿ�ʼ
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