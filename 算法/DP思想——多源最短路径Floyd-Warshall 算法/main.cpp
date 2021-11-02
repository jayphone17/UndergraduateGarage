#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int N=111;
const int INF=1e7;

int main()
{
    int map[N][N]; //初始化矩阵的信息
    int n;//顶点个数
    int m;//边的个数
    cout << "请输入顶点个数n和边的个数m："<< endl;
    cin >> n>> m;
    int i,j,k;
    for (i=1;i<=n;i++) //初始化矩阵
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
    for (i=1;i<=m;i++) //输入节点，以及节点之间的距离
    {
        cin >> vertex1 >> vertex2 >> distance;
        map[vertex1][vertex2]=distance;
    }

    //Floyd-Warshall算法核心内容：
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

    cout << "最短路径矩阵为：" << endl;
    //输出最终的结果
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
