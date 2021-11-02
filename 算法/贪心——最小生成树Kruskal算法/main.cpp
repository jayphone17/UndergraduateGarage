#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N=111;
int nodeset[N];//���ļ��ϡ�
int n;//��������
int m;//�ߵ�����

struct Edge //�ߵĽṹ��
{
    int u;//���
    int v;//���
    int w;//��͵�֮���Ȩֵ
}e[N*N];
//����һ���ڽӾ���


bool cmp(Edge x,Edge y) //��Ȩֵ��С���������һ������
{
    return x.w < y.w;
}

void init(int n) //��ʼ����㺯�����൱�ڰ�ÿ����㶼���ɹ�������ͨ��֧��
{
    for (int i=1;i<=n;i++)
    {
        nodeset[i]=i;
    }
}

int Merge(int a ,int b) //�ϲ����ϵĺ�������Ȧ����
{
    int p=nodeset[a];
    int q=nodeset[b];
    if (p==q)
        return 0;//�����������һ���ͻ��γ���ͨ����������С��������������
    for (int i=1;i<=n;i++)
    {
        if (nodeset[i]==q)
        {
            nodeset[i]=p;//�ѽ����С�Ļ��ɴ�ġ��ϲ���һ�����ϡ�
        }
    }
    return 1;
}

int Kruskal(int n)
{
    int ans=0;//��¼Ȩֵ֮��
    for (int i=0;i<m;i++)
    {
        if (Merge(e[i].u,e[i].v)) //����ϲ��ɹ��������֮���Ȩֵ��ӡ���ͨ���ڽӾ���
        {
            ans+=e[i].w;
            n--;
            if(n==1)//�ﵽn-1��Ȩֵ��ӣ��Ѿ�������С��������
            {
                return ans;
            }
        }
    }
    return 0;
}

int main()
{
    cout << "����������n�ͱ���m" << endl;
    cin >> n >> m;
    init(n);//������γɶ�����ͨ��֧
    cout << "����������u��v�ͽ��֮���Ȩֵw"<< endl;
    for (int i=0;i<m;i++)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e,e+m,cmp); //����ֵ��С��������
    int ans=Kruskal(n);
    cout << "��С����������С�����ǣ�"<<ans << endl;
    return 0;
}
