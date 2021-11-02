#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=111;
int e[N][N];//存储边
int matched[N];//判断是否已经匹配
int marked[N]; //判断是否已经访问
int n;
int m;

int dfs(int u)
{
    for(int i=1;i<=n;i++)
    {
        if(marked[i]==0 && e[u][i]==1) //没有被访问过且可达
        {
            marked[i]=1;
            if(matched[i]==0 || dfs(matched[i])) //如果没有配对，将i与u配对。
                                                                //用dfs遍历一编i，看有没有配对。如果没有配对，返回0
            {
                matched[i]=u;
                return 1;//配对成功返回1.不用进行dfs
            }
        }
    }
    return 0;
}

int main()
{
    int edge1;
    int edge2;
    int sum=0;
    cout << "请输入n个顶点m条边" << endl;
    cin >> n >> m;
    cout << "请输入所有可进行配对的顶点： "<< endl;
    for (int i=1;i<=m;i++)
    {
        cin >> edge1 >> edge2;
        e[edge1][edge2]=1;//说明这两个顶点之间存在边。
    }
    //初始化匹配数组。
    for (int i=1;i<=n;i++)
    {
        matched[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            marked[j]=0; //清空上次搜索访问过的记录
        }
        if(dfs(i))
        {
            sum++;
        }
    }
    cout << "最大匹配数是："<< endl;
    cout << sum << endl;
    return 0;
}
