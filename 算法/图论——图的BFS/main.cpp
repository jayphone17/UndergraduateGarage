#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int N=111;
const int INF=9999999;
int main()
{
    int edge[N][N];
    int marked[N]= {0};
    int n;
    int m;
    int point_a;
    int point_b;
    int cur;
    int que[11111];
    int head;
    int tail;
    cout << "�����붥�����n�ͱߵ�����m��"<< endl;
    cin >> n>> m;
    //��ʼ��
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i==j)
            {
                edge[i][j]=0;
            }
            else
            {
                edge[i][j]=INF;
            }
        }
    }
    cout << "���������ӱߵ��������㣺" << endl;
    for(int i=1; i<=m; i++)
    {
        cin >> point_a >> point_b;
        edge[point_a][point_b]=1;
        edge[point_b][point_a]=1;
    }
    //���г�ʼ��
    head=1;
    tail=1;
    que[tail]=1;
    tail++;
    marked[1]=1;
    while(head<tail && tail<=n)
    {
        cur=que[head];//��ǰ���ʵĽ��
        for(int i=1; i<=n; i++)
        {
            if(edge[cur][i]==1 && marked[i]==0)
            {
                que[tail]=i;
                tail++;
                marked[i]=1;
            }
            if(tail > n)
            {
                break;
            }
        }
        head++;//����
    }
    cout << "��������˳���ǣ�"<< endl;
    for(int i=1; i<tail; i++)
    {
        cout <<que[i];
    }
    cout << endl;
    return 0;
}
