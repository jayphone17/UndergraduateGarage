#include<stdio.h>
int main()
{
    long long a,b;  //题目要求（<=2^31-1）
    int m,i;
    while(scanf("%d",&m)!=EOF)  //输入要转化的进制数。
    {
        if(m==0) break; //如果m=0，停止。
        scanf("%lld%lld",&a,&b);    // 输入A，B。
        a=a+b;  //求A+B的和
        int str[50],num=0;  //定义数组，
        do  //用do-while循环目的是要把第一次的运算也算上
        {
            str[num]=a%m;   //储存所取余数。
            a/=m;   //接着往下除。
            num++;  //下一个数字。
        }
        while(a!=0);    //循环条件。
        for(i=num-1; i>=0; i--)//讲所取的余数倒叙输出（就是转换之后的进制数）
        {
            printf("%d",str[i]);    //输出余数
        }
        printf("\n");
    }
    return 0;
}
