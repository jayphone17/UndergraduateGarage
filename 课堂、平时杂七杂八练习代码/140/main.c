//OJ 1967 A Math Puzzle 类似的题目还有 OJ 1985 菊花残

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[20]=" "; //初始化字符串。（相当于清空字符串）
    while(scanf("%s",str)!=EOF) //输入这串数字。
    {
        int t,len;
        len=strlen(str);
        long long sum=0;
        for(int i=0; i<len; i++)
        {
            if(str[i]<='9')   //十二进制跟十进制的1~9都是一样的。
            {
                t=str[i]-'0'; //转成十进制了
            }
            else
                t=str[i]-'A'+10; // 'A'的十进制是10，这里代表是>9或是A、B的情况转成十进制
            sum=sum*12+t; //  sum*12代表十二进制转成十进制，t已经是十进制。
            sum=sum%11; //  对11求余
        }
        if(sum%11==0)  //  判断
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
