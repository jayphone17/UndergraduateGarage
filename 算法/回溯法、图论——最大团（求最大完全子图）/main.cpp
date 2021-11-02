#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=111; //设置矩阵的大小
int graph[N][N]; //用邻接矩阵存储图
bool x[N]; //是否将i个顶点加入团中
bool bestx[N]; //记录最优已经放入团中的顶点
int bestn; //记录最优值
int cn; //已经放入团中的结点数
int n;//顶点个数
int m; //边的个数

bool place(int t) //判断是否能放进团中
{
    bool OK =true;
    for (int j=1;j<t;j++)  //判断目前扩展的t顶点和前面t-1个顶点是否相连。
    {
        if(x[j] && graph[t][j]==0) //如果不相连
        {
            OK=false; //返回false
            break;
        }
    }
    return OK; //如果相连。返回true
}

void backtrack(int t) //回溯，递推
{
    if(t>n) //当到达叶子结点
    {
        for(int i=1;i<=n;i++)
        {
            bestx[i]=x[i]; //记录最优值结点号
        }
        bestn=cn; //记录最优值
        return;
    }
    if(place(t)) //如果能放进团中
    {
        x[t]=1;//标为1
        cn++; //个数+1
        backtrack(t+1); //向下递推
        cn--; //向上回溯
    }
    if(cn+n-t>bestn) //限界条件，进入右子树，不能加入团中。
    {
        x[t]=0; //不能放入团中，标为0
        backtrack(t+1); //向下递推。
    }
}

int main()
{
    int u; //结点1
    int v; //结点2
    cout << "请输入结点的个数n；"<< endl;
    cin >> n;
    cout << "请输入边数m："<< endl;
    cin >>m;
    memset(graph,0,sizeof(graph));
    cout <<"请输入有边相连的两个顶点u和v："<< endl;
    for (int i=1;i<=m;i++)
    {
        cin >> u>> v;
        graph[u][v]=1;
        graph[v][u]=1;
    }
    bestn=0;
    cn=0;
    backtrack(1);
    cout << "最大团的结点个数有："<< bestn << endl;
    cout << "结点有："<< endl;
    for (int i=1;i<=n;i++)
    {
        if(bestx[i])
        {
            cout << i << "  "; //输出的是结点号
        }
    }
    return 0;
}
