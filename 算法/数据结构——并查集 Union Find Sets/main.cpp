#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N=1111;
int father[N]={0};
int n;
int m;
int k;
int sum=0;

void initialize() //��ʼ����������father����ÿ��Ԫ�ص��±�������������
{
    for (int i=1;i<=n;i++)
    {
        father[i]=i;
    }
}

int getfather(int v) //�����ڵݹ麯��
{
    if(father[v]==v) //�����ŵ������ڵı�ţ������Լ��ģ��㷨����
    {
        return v; //�������ڱ��
    }
    else
    {
        //�ڷ���ʱ����·���������˵ı�Ÿ�Ϊ����ҵ����ڵı��
        //�������������ڵı�š�
        //������������ҵ��������������ڱ�ŵ��ٶȡ�
        father[v]=getfather(father[v]); //����ݹ�������ڱ��
        return father[v]; //���շ������ڱ�š�
                                    //����father[v]�ǿ������ڵݹ���ҡ�
    }
}

void Merge(int v,int u)
{
    int t1;
    int t2;
    t1=getfather(v); //��һ�����ı��
    t2=getfather(u); //�ڶ������ı��
    if(t1!=t2) //�����Ų����
    {
        father[t2]=t1; //����С�ı�Ÿ���ϴ�ı�ţ�����ԭ��
    }
}

int main()
{
    int x;
    int y;
    int i;
    cout << "�����������������Ŀǰ֪�����鱨������" << endl;
    cin >> n>> m;
    initialize();
    cout << "�������鱨��˭��˭��ͬ��" << endl;
    for (i=1;i<=m;i++)
    {
        cin >> x>> y; //�����ϵ
        Merge(x,y); //�����ձ��һ���Ľ��ϲ���
    }
    for (i=1;i<=n;i++)
    {
        if(father[i]==i)
        {
            sum++;
        }
    }
    cout <<"�����Ż�ĸ����У�" << endl;
    cout << sum;
    return 0;
}
