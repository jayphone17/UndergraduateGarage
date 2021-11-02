#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <windows.h>
#include <stack>
using namespace std;

const int N=111;
const int INF =1e7;
int map[N][N];   //��ʼ���������󳤶�
int dist[N];         //��ʼ�����·����������
int p[N];            //��ʼ����¼ǰ��������
int n;                 //����ĸ���
int m;                //�ߵĸ���
bool flag[N]; //���flag����true�Ļ�˵����������Ѿ��������ˣ���������㼯�ϡ�

void dijkstra(int u)
{
    for(int i=1; i<=n; i++) //��ʼ��
    {
        dist[i]=map[u][i];//��ʼ��Դ��u�����������̾���
        flag[i]=false;
        if(dist[i]==INF)
        {
            p[i]=-1;
            //Դ��u���˶���������������i��Դ��u������
        }
        else
        {
            p[i]=u;//��¼ǰ��
        }
    }
    dist[u]=0;
    flag[u]=true;//��ʼʱ��S����ֻ��Դ��uһ��Ԫ��
    for(int i=1; i<=n; i++)
    {
        int temp=INF;
        int t=u;
        for(int j=1; j<=n; j++) //��V-S������Ѱ�Ҿ���u����Ķ��㣬������S������
            if(!flag[j] && dist[j]<temp)
            {
                t=j;
                temp=dist[j];
            }
        if(t==u) return; //�Ҳ���t������ѭ��
        flag[t]=true;     //�ҵ����t���뼯��S��
        for(int j=1; j<=n; j++)
        {
            if(!flag[j] && map[t][j]<INF)  //��flag[j]��ʾj��V-S�����С�
            {
                if(dist[j]>dist[t]+map[t][j])
                {
                    dist[j]=dist[t]+map[t][j]; //�������·��
                    p[j]=t ;//����p���飬��¼�����ǰ��
                }
            }
        }
    }
}

void findpath(int u)
{
    int x;
    stack<int>mystack;
    cout << "Դ���ǣ�"<< u << endl;
    for(int i=1; i<=n; i++)
    {
        x=p[i];
        while(x!=-1)
        {
            mystack.push(x); //�������ǰ������ѹ��ջ��
            x=p[x]; //
        }
        cout << "Դ�㵽����������·��·���ǣ�" << endl;
        while(!mystack.empty())
        {
            cout << mystack.top() << "--";
            mystack.pop();
        }
        cout << i << "��̾����ǣ�" << dist[i] << endl;
    }
}

int main()
{
    int u; //����
    int v; //��
    int st; //Դ��
    int w; //Ȩֵ
    cout << "�����붥�����n�ͱߵĸ���m��" << endl;
    cin >> n>> m;
    for(int i=1; i<=n; i++) //��ʼ������
    {
        for(int j=1; j<=n; j++)
        {
            map[i][j]=INF;
        }
    }
    cout << "������ÿ������֮���·�ߺ�Ȩֵ��" << endl;
    while(m--)
    {
        cin >> u >> v >> w;
        map[u][v]=min(map[u][v],w);
        //��������֮�����С���룬���¾���
    }
    cout << "��������Դ�㣺" << endl;
    cin >> st;
    dijkstra(st);
    cout << "��Դ������λ�� ��"<< st<<endl;
    for(int i=1; i<=n; i++)
    {
        cout << "��Դ�㣺"<<st<<"-" << "Ҫȥ��λ�ã�"<< i<< endl;
        if(dist[i]==INF)
        {
            cout << "�޷�����"<< endl;
        }
        else
        {
            cout << "��̾����ǣ�"<< dist[i] << endl;
        }
    }
    cout << endl;
    findpath(st);
    return 0;
}
