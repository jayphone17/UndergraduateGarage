OJ 1978 我想找一个女朋友

#include <stdio.h>
int main()
{
    int n;
    while(~scanf("%d",&n))//输入N值。
    {
        int i,flag = 0;
        for(i = 1; i<=n; i ++) //循环执行
        {
            int t = i;
            while(t)//循环取出每一位。
            {
                if(t%10==1)
                flag++;
                t=t/10; //不满足上述情况，除以10再进行一个求余。
            }
        }
        printf("%d\n", flag);//输出结果
    }
    return 0;
}
