#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=111;
char graph[N][N];
int marked[N][N];
int maxx;
int n;
int m;
int mx;
int my;

int getnum(int i,int j)//返回最大消灭敌人数的函数
{
    int sum=0;
    int x;
    int y;
    x=i;
    y=j;
    while(graph[x][y]!='#')//只要没有到边界
    {
        if(graph[x][y]=='G')//是敌人
        {
            sum++;//增加消灭数
        }
        x--;//继续向上寻找
    }
    x=i;
    y=j;
    while(graph[x][y]!='#')//只要没有到边界
    {
        if(graph[x][y]=='G')//是敌人
        {
            sum++;//增加消灭数
        }
        x++;//继续向上寻找
    }
    x=i;
    y=j;
    while(graph[x][y]!='#')//只要没有到边界
    {
        if(graph[x][y]=='G')//是敌人
        {
            sum++;//增加消灭数
        }
        y--;//继续向上寻找
    }
    x=i;
    y=j;
    while(graph[x][y]!='#')//只要没有到边界
    {
        if(graph[x][y]=='G')//是敌人
        {
            sum++;//增加消灭数
        }
        y++;//继续向上寻找
    }
    return sum;
}

void DFS(int x,int y)
{
    int next[4][2]= {{0,1},{1,0},{0,-1},{-1,0}}; //定义四个方向的数组
    int tx;
    int ty;
    int sum;
    sum=getnum(x,y);
    if(sum>maxx)
    {
        maxx=sum;
        mx=x;
        my=y;
    }
    for(int k=0; k<=3; k++)
    {
        tx=x+next[k][0];
        ty=y+next[k][1];
        if(tx<1 || tx>n-1 || ty<1 || ty>m-1)
        {
            continue;
        }
        if(graph[tx][ty]=='.' && marked[tx][ty]==0)
        {
            marked[tx][ty]=1;
            DFS(tx,ty);
        }
    }
    return ;
}

int main()
{
    int startx;
    int starty;
    cout << "请输入地图的行数n和列数m以及起点的坐标"<< endl;
    cin >> n>> m>> startx>>starty;
    cout << "请输入地图"<< endl;
    for(int i=0; i<=n-1; i++)
    {
        cin >> graph[i];
    }
    marked[startx][starty]=1;
    maxx=getnum(startx,starty);
    mx=startx;
    my=starty;
    DFS(startx,starty);
    cout << "将炸弹放在" << "(" << mx << "," << my << ")"<< "处了以消灭最多敌人：" << maxx << endl;
    return 0;
}
