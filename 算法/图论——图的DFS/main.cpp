#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int N=111;
const int INF=999999999;
int marked[N];//用来标记这个点有没有被遍历
int edge[N][N];//用来存储边
int sum;//记录遍历顶点的个数
int n;//点的个数
int m;//边的条数

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
    cout << "请输入顶点个数和边的条数：" << endl;
    cin >> n >> m;
    for (int i=1;i<=n;i++)//初始化
    {
        for (int j=1;j<=n;j++)
        {
            if(i==j)//自己不可达自己
            {
                edge[i][j]=0; //设置为0
            }
            else
            {
                edge[i][j]=INF; //不可达，设置为∞
            }
        }
    }
    cout << "请输入边的两点：" << endl;
    for(int i=1;i<=m;i++)
    {
        cin >> point_a >> point_b ;
        edge[point_a][point_b]=1;
        edge[point_b][point_a]=1;
    }
    cout << "遍历顺序是： "<< endl;
    marked[1]=1;
    dfs(1);
    return 0;
}
