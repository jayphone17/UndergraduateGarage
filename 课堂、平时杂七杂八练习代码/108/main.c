#include<stdio.h>
int main()
{
    long long a,b;  //��ĿҪ��<=2^31-1��
    int m,i;
    while(scanf("%d",&m)!=EOF)  //����Ҫת���Ľ�������
    {
        if(m==0) break; //���m=0��ֹͣ��
        scanf("%lld%lld",&a,&b);    // ����A��B��
        a=a+b;  //��A+B�ĺ�
        int str[50],num=0;  //�������飬
        do  //��do-whileѭ��Ŀ����Ҫ�ѵ�һ�ε�����Ҳ����
        {
            str[num]=a%m;   //������ȡ������
            a/=m;   //�������³���
            num++;  //��һ�����֡�
        }
        while(a!=0);    //ѭ��������
        for(i=num-1; i>=0; i--)//����ȡ�������������������ת��֮��Ľ�������
        {
            printf("%d",str[i]);    //�������
        }
        printf("\n");
    }
    return 0;
}
