#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=111;

struct note
{
    int x;//横坐标
    int y;//纵坐标
    int step;//步数
};

int next[4][3]= {{0,1},{1,0},{0,-1},{-1,0}};

int main()
{
    struct note que[N*N];//队列
    int head;
    int tail;
    int maze[N][N]= {0}; //初始化地图
    int marked[N][N]= {0}; //标记数组，判断是否被访问
    int next[4][3]= {{0,1},{1,0},{0,-1},{-1,0}};//方向数组。
    int n;
    int m;
    int startx;
    int starty;
    int p;
    int q;
    int tx;
    int ty;
    int flag;
    cout << "请输入迷宫的行数n和列数m" << endl;
    cin >> n>> m;
    cout << "请输入迷宫maze" << endl;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin >> maze[i][j];
        }
    }
    cout << "请输入起点的坐标和目标的坐标："<< endl;
    cin >> startx >> starty >> p >> q;
    head=1;
    tail=1;
    //指向队列头
    //往队列插入迷宫入口坐标：
    //第一步将（1，1）加入队列，因为此处是起点，默认已经在队列中
    que[tail].x=1;
    que[tail].y=1;
    que[tail].step=0;
    tail++;//往下走
    marked[1][1]=1;//此时（1，1）已经访问过。
    flag=0;//用来标记是否已经到达目标点。

    while(head<tail)
    {
        //枚举四个方向
        for(int k=0; k<=3; k++)
        {
            tx=que[head].x+next[k][0];
            ty=que[head].y+next[k][1];
            //判断是否越界：
            if(tx<1 || tx>n || ty<1 || ty>m)
            {
                continue;
            }
            //判断是否是障碍物和是否已经访问：
            if(maze[tx][ty]==0 && marked[tx][ty]==0)
            {
                marked[tx][ty]=1; //此时已经访问过
                que[tail].x=tx;
                que[tail].y=ty;
                que[tail].step=que[head].step+1;
                tail++;
            }
            if(tx==p && ty==q)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            break;
        }
        head++;//将已经扩展过的点出列。
    }
    cout << "A同学找到B同学的最短距离是："<< que[tail-1].step << endl;
    return 0;
}
