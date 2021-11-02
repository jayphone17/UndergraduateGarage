#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int N=111;
const int INF=999999999;
int marked[N];//��������������û�б�����
int edge[N][N];//�����洢��
int sum;//��¼��������ĸ���
int n;//��ĸ���
int m;//�ߵ�����

void dfs(int cur)
{
    cout << cur;
    sum++;
    if(sum==n)
    {
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(edge[cur][i]==1 && marked[i]==0)
        {
            marked[i]=1;
            dfs(i);
        }
    }
    return;
}

int main()
{
    int point_a;
    int point_b;
    cout << "�����붥������ͱߵ�������" << endl;
    cin >> n >> m;
    for (int i=1;i<=n;i++)//��ʼ��
    {
        for (int j=1;j<=n;j++)
        {
            if(i==j)//�Լ����ɴ��Լ�
            {
                edge[i][j]=0; //����Ϊ0
            }
            else
            {
                edge[i][j]=INF; //���ɴ����Ϊ��
            }
        }
    }
    cout << "������ߵ����㣺" << endl;
    for(int i=1;i<=m;i++)
    {
        cin >> point_a >> point_b ;
        edge[point_a][point_b]=1;
        edge[point_b][point_a]=1;
    }
    cout << "����˳���ǣ� "<< endl;
    marked[1]=1;
    dfs(1);
    return 0;
}
