#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int N=111;
const int INF=1e7;

int main()
{
    int map[N][N]; //��ʼ���������Ϣ
    int n;//�������
    int m;//�ߵĸ���
    cout << "�����붥�����n�ͱߵĸ���m��"<< endl;
    cin >> n>> m;
    int i,j,k;
    for (i=1;i<=n;i++) //��ʼ������
    {
        for (j=1;j<=n;j++)
        {
            if (i==j)
            {
                map[i][j]=0;
            }
            else
            {
                map[i][j]=INF;
            }
        }
    }
    int vertex1,vertex2,distance;
    for (i=1;i<=m;i++) //����ڵ㣬�Լ��ڵ�֮��ľ���
    {
        cin >> vertex1 >> vertex2 >> distance;
        map[vertex1][vertex2]=distance;
    }

    //Floyd-Warshall�㷨�������ݣ�
    for (k=1;k<=n;k++)
    {
        for (j=1;j<=n;j++)
        {
            for(i=1;i<=n;i++)
            {
                if(map[i][j]>map[i][k]+map[k][j])
                {
                    map[i][j]=map[i][k]+map[k][j];
                }
            }
        }
    }

    cout << "���·������Ϊ��" << endl;
    //������յĽ��
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            cout << map[i][j]<< "\t";
        }
        cout << endl;
    }
    return 0;
}
