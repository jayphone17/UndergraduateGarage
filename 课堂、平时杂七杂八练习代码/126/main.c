OJ 1978 ������һ��Ů����

#include <stdio.h>
int main()
{
    int n;
    while(~scanf("%d",&n))//����Nֵ��
    {
        int i,flag = 0;
        for(i = 1; i<=n; i ++) //ѭ��ִ��
        {
            int t = i;
            while(t)//ѭ��ȡ��ÿһλ��
            {
                if(t%10==1)
                flag++;
                t=t/10; //�������������������10�ٽ���һ�����ࡣ
            }
        }
        printf("%d\n", flag);//������
    }
    return 0;
}
