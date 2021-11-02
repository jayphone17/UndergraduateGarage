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
    cout << "请输入顶点个数n和边的条数m："<< endl;
    cin >> n>> m;
    //初始化
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
    cout << "请输入连接边的两个顶点：" << endl;
    for(int i=1; i<=m; i++)
    {
        cin >> point_a >> point_b;
        edge[point_a][point_b]=1;
        edge[point_b][point_a]=1;
    }
    //队列初始化
    head=1;
    tail=1;
    que[tail]=1;
    tail++;
    marked[1]=1;
    while(head<tail && tail<=n)
    {
        cur=que[head];//当前访问的结点
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
        head++;//出列
    }
    cout << "遍历结点的顺序是："<< endl;
    for(int i=1; i<tail; i++)
    {
        cout <<que[i];
    }
    cout << endl;
    return 0;
}
