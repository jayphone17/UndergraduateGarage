#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int N=11111;
int maze[N][N]; //地图数组
int marked[N][N];//标记数组
int n; //记录行数
int m;//记录列数
int p;//记录目标横坐标
int q;//记录目标纵坐标
int minn=9999999;

void dfs(int x,int y,int step)
{
    int tx;
    int ty;
    int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    //分别是向右走，向下走，向左走，向上走。

    if(x==p && y==q) //判断坐标是否相等
    {
        if(step<minn)
        {
            minn=step; //更新最小步数
        }
        return;
    }

    for (int k=0;k<=3;k++)
    {
        tx=x+next[k][0];
        ty=y+next[k][1];
        if(tx<1 || tx>n || ty<1 || ty>m)
        {
            continue;
        }
        if(maze[tx][ty]==0 && marked[tx][ty]==0) //判断是否是障碍物或者是否已经在路径中
        {
            marked[tx][ty]=1;//说明这个点已经走过了
            dfs(tx,ty,step+1);
            marked[tx][ty]=0;//尝试结束，取消这个点的标记。
        }
    }
    return;
}

int main()
{
    int startx;
    int starty;
    cout << "请输入地图的大小：n和m" << endl;
    cin >> n>> m;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            cin >> maze[i][j];
        }
    }
    cout << "请输入起点的坐标和终点的坐标：" << endl;
    cin >> startx >> starty >> p >> q;
    marked[startx][starty]=1;//此时起点出发，说明已经在路径中
    dfs(startx,starty,0);
    cout << "A同学到达B同学位置的最短步数是：" << endl;
    cout << minn<< endl;
    return 0;
}
