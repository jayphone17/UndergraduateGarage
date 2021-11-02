#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <windows.h>
#include <stack>
using namespace std;

const int N=111;
const int INF =1e7;
int map[N][N];   //初始化矩阵的最大长度
int dist[N];         //初始化最短路径长度数组
int p[N];            //初始化记录前驱的数组
int n;                 //顶点的个数
int m;                //边的个数
bool flag[N]; //如果flag等于true的话说明这个顶点已经遍历过了，加入个顶点集合。

void dijkstra(int u)
{
    for(int i=1; i<=n; i++) //初始化
    {
        dist[i]=map[u][i];//初始化源点u到各顶点的最短距离
        flag[i]=false;
        if(dist[i]==INF)
        {
            p[i]=-1;
            //源点u到此顶点距离无穷大，所以i与源点u不相连
        }
        else
        {
            p[i]=u;//记录前驱
        }
    }
    dist[u]=0;
    flag[u]=true;//初始时，S集合只有源点u一个元素
    for(int i=1; i<=n; i++)
    {
        int temp=INF;
        int t=u;
        for(int j=1; j<=n; j++) //在V-S集合中寻找距离u最近的顶点，并加入S集合中
            if(!flag[j] && dist[j]<temp)
            {
                t=j;
                temp=dist[j];
            }
        if(t==u) return; //找不到t，跳出循环
        flag[t]=true;     //找到则把t加入集合S中
        for(int j=1; j<=n; j++)
        {
            if(!flag[j] && map[t][j]<INF)  //！flag[j]表示j在V-S集合中。
            {
                if(dist[j]>dist[t]+map[t][j])
                {
                    dist[j]=dist[t]+map[t][j]; //更新最短路径
                    p[j]=t ;//更新p数组，记录顶点的前驱
                }
            }
        }
    }
}

void findpath(int u)
{
    int x;
    stack<int>mystack;
    cout << "源点是："<< u << endl;
    for(int i=1; i<=n; i++)
    {
        x=p[i];
        while(x!=-1)
        {
            mystack.push(x); //将顶点的前驱依次压入栈中
            x=p[x]; //
        }
        cout << "源点到各顶点的最短路径路线是：" << endl;
        while(!mystack.empty())
        {
            cout << mystack.top() << "--";
            mystack.pop();
        }
        cout << i << "最短距离是：" << dist[i] << endl;
    }
}

int main()
{
    int u; //顶点
    int v; //边
    int st; //源点
    int w; //权值
    cout << "请输入顶点个数n和边的个数m：" << endl;
    cin >> n>> m;
    for(int i=1; i<=n; i++) //初始化矩阵
    {
        for(int j=1; j<=n; j++)
        {
            map[i][j]=INF;
        }
    }
    cout << "请输入每个顶点之间的路线和权值：" << endl;
    while(m--)
    {
        cin >> u >> v >> w;
        map[u][v]=min(map[u][v],w);
        //保留顶点之间的最小距离，更新矩阵。
    }
    cout << "请输入起源点：" << endl;
    cin >> st;
    dijkstra(st);
    cout << "起源点所在位置 ："<< st<<endl;
    for(int i=1; i<=n; i++)
    {
        cout << "起源点："<<st<<"-" << "要去的位置："<< i<< endl;
        if(dist[i]==INF)
        {
            cout << "无法到达"<< endl;
        }
        else
        {
            cout << "最短距离是："<< dist[i] << endl;
        }
    }
    cout << endl;
    findpath(st);
    return 0;
}
