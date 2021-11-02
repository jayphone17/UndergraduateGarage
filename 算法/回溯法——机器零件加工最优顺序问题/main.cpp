#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int INF=999999999;
const int MX=11111;
int n; //��������ĸ���
int bestf; //���żӹ����ʱ��
int f1; //�ڻ���1�ӹ���ʱ��
int f2; //�ڻ���2�ӹ���ʱ��
int x[MX]; //��¼���ŷ�������ı��
int bestx[MX]; //��¼���ŷ����ļӹ�˳��

struct node
{
    int x;//�ڵ�һ̨�����ӹ���ʱ��
    int y;//�ڵڶ�̨�����ӹ���ʱ��
}T[MX];
//�ṹ������洢���л����ӹ�ʱ�䡣

void backtrack(int t)
{
    if(t>n)
    {
        for(int i=1;i<=n;i++)
        {
            bestx[i]=x[i];//��¼��������
        }
        bestf=f2; //��������ֵ.
        return ;
    }
    for(int i=t;i<=n;i++) //ö��
    {
        f1+=T[x[i]].x;
        int temp=f2;
        f2=max(f1,f2)+T[x[i]].y;
        if(f2<bestf) //�޽���������֦������
        {
            swap(x[t],x[i]);
            backtrack(t+1);//��������
            swap(x[t],x[i]);//��λ��������
        }
        f1-=T[x[i]].x;
        f2=temp;
        //��λ����������
    }
}

int main()
{
    cout << "����������ĸ���n"<< endl;
    cin >> n;
    cout << "���������ÿ������ڵ�һ̨�����ӹ���ʱ��x���ڵڶ�̨�����ӹ���ʱ��y"<< endl;
    for (int i=1;i<=n;i++)
    {
        cin >> T[i].x >> T[i].y;
        x[i]=i; //����ı��
    }
    bestf=INF; //�����
    f1=0;
    f2=0;
    memset(bestx,0,sizeof(bestx)); //�������
    memset(x,0,sizeof(x));
    backtrack(1); //����������һ����㿪ʼ����
    cout << "���ŵĻ�������ӹ�˳��Ϊ��"<< endl;
    for (int i=1;i<=n;i++)
    {
        cout << bestx[i] <<" ";
    }
    cout << endl;
    cout << "���ŵĻ�������ӹ���ʱ��Ϊ��"<< endl;
    cout << bestf << endl;
    return 0;
}