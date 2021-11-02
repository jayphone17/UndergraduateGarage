#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N=111;
int nodeset[N];//结点的集合。
int n;//结点的数量
int m;//边的数量

struct Edge //边的结构体
{
    int u;//结点
    int v;//结点
    int w;//点和点之间的权值
}e[N*N];
//构造一个邻接矩阵


bool cmp(Edge x,Edge y) //将权值从小到大排序的一个函数
{
    return x.w < y.w;
}

void init(int n) //初始化结点函数（相当于把每个结点都当成孤立的连通分支）
{
    for (int i=1;i<=n;i++)
    {
        nodeset[i]=i;
    }
}

int Merge(int a ,int b) //合并集合的函数（避圈法）
{
    int p=nodeset[a];
    int q=nodeset[b];
    if (p==q)
        return 0;//如果两个结点号一样就会形成联通，不符合最小生成树的条件。
    for (int i=1;i<=n;i++)
    {
        if (nodeset[i]==q)
        {
            nodeset[i]=p;//把结点数小的换成大的。合并成一个集合。
        }
    }
    return 1;
}

int Kruskal(int n)
{
    int ans=0;//记录权值之和
    for (int i=0;i<m;i++)
    {
        if (Merge(e[i].u,e[i].v)) //如果合并成功，将结点之间的权值相加。（通过邻接矩阵）
        {
            ans+=e[i].w;
            n--;
            if(n==1)//达到n-1次权值相加，已经生成最小生成树。
            {
                return ans;
            }
        }
    }
    return 0;
}

int main()
{
    cout << "请输入结点数n和边数m" << endl;
    cin >> n >> m;
    init(n);//将结点形成独立连通分支
    cout << "请输入结点编号u，v和结点之间的权值w"<< endl;
    for (int i=0;i<m;i++)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e,e+m,cmp); //将边值从小到大排序
    int ans=Kruskal(n);
    cout << "最小生成树的最小花费是："<<ans << endl;
    return 0;
}
