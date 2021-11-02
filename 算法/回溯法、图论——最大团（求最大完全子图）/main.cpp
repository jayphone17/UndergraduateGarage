#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=111; //���þ���Ĵ�С
int graph[N][N]; //���ڽӾ���洢ͼ
bool x[N]; //�Ƿ�i�������������
bool bestx[N]; //��¼�����Ѿ��������еĶ���
int bestn; //��¼����ֵ
int cn; //�Ѿ��������еĽ����
int n;//�������
int m; //�ߵĸ���

bool place(int t) //�ж��Ƿ��ܷŽ�����
{
    bool OK =true;
    for (int j=1;j<t;j++)  //�ж�Ŀǰ��չ��t�����ǰ��t-1�������Ƿ�������
    {
        if(x[j] && graph[t][j]==0) //���������
        {
            OK=false; //����false
            break;
        }
    }
    return OK; //�������������true
}

void backtrack(int t) //���ݣ�����
{
    if(t>n) //������Ҷ�ӽ��
    {
        for(int i=1;i<=n;i++)
        {
            bestx[i]=x[i]; //��¼����ֵ����
        }
        bestn=cn; //��¼����ֵ
        return;
    }
    if(place(t)) //����ܷŽ�����
    {
        x[t]=1;//��Ϊ1
        cn++; //����+1
        backtrack(t+1); //���µ���
        cn--; //���ϻ���
    }
    if(cn+n-t>bestn) //�޽����������������������ܼ������С�
    {
        x[t]=0; //���ܷ������У���Ϊ0
        backtrack(t+1); //���µ��ơ�
    }
}

int main()
{
    int u; //���1
    int v; //���2
    cout << "��������ĸ���n��"<< endl;
    cin >> n;
    cout << "���������m��"<< endl;
    cin >>m;
    memset(graph,0,sizeof(graph));
    cout <<"�������б���������������u��v��"<< endl;
    for (int i=1;i<=m;i++)
    {
        cin >> u>> v;
        graph[u][v]=1;
        graph[v][u]=1;
    }
    bestn=0;
    cn=0;
    backtrack(1);
    cout << "����ŵĽ������У�"<< bestn << endl;
    cout << "����У�"<< endl;
    for (int i=1;i<=n;i++)
    {
        if(bestx[i])
        {
            cout << i << "  "; //������ǽ���
        }
    }
    return 0;
}
