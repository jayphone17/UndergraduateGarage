#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

char graph[21][21];//存储地图

struct node
{
    int x;
    int y;
};

int getnum(int i,int j) //用来获取最大敌人消灭数的函数
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

int main()
{
    struct node que[444];//创建队列
    int head;
    int tail;
    int marked[21][21]={0};//设置一个标记二维数组，初始化全部为0
    int sum; //计算消灭敌人数
    int maxx=0;
    int n; //有n行
    int m; //有m列
    int startx; //起始点x坐标
    int starty; //起始点y坐标
    int tx; //bfs推进坐标
    int ty; //同上
    int mx; //最终放置炸弹x坐标
    int my; //最终放置炸弹y坐标
    int next[4][2]= {{0,1},{1,0},{0,-1},{-1,0}}; //定义四个方向的数组
    cout << "请输入地图的大小，行n和列m，还有起点坐标x和y" << endl;
    cin >> n >> m >> startx >> starty;
    cout << "请输入地图："<< endl;
    for(int i=0; i<=n-1; i++)
    {
        cin >> graph[i];
    }
    //队列初始化
    head=1;
    tail=1;
    //往队列先插入起始点坐标
    que[tail].x=startx;
    que[tail].y=starty;
    tail++;//tail指针后移
    marked[startx][starty]=1;//起始点已经走过
    maxx=getnum(startx,starty);
    mx=startx;
    my=starty;
    while(head<tail) //当队列不为空时
    {
        //枚举四个方向
        for(int k=0; k<=3; k++)
        {
            tx=que[head].x+next[k][0];
            ty=que[head].y+next[k][1];
            //判断边界
            if(tx<1 || tx>n-1 || ty<1 || ty>m-1)
            {
                continue;
            }
            //判断是否是平地和是否已经走过：
            if(graph[tx][ty]=='.' && marked[tx][ty]==0)
            {
                marked[tx][ty]=1;
                que[tail].x=tx;
                que[tail].y=ty;
                tail++;
                sum=getnum(tx,ty);
                if(sum>maxx)
                {
                    maxx=sum;
                    mx=tx;
                    my=ty;
                }
            }
        }
        head++;//前面已经扩展的点用不上了，出列
    }
    cout << "将炸弹放在" << "(" << mx << "," << my << ")"<< "处了以消灭最多敌人：" << maxx << endl;
    return 0;
}
