#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXX=111;//设定边界
int map[MAXX][MAXX]; //邻接矩阵存储图
int x[MAXX]; //解分量，记录色号
int sum=0; //记录有多少种方案
int n; //顶点个数
int m;//边的个数
int color_nums; //颜色数量

void createmap() //创建邻接矩阵
{
    int u; //顶点1
    int v; //顶点2
    cout << "请输入边的个数m："<< endl;
    cin >> m;
    memset(map,0,sizeof(map));
    cout << "请输入有边相连的两个顶点u和v："<< endl;
    for (int i=1;i<=m;i++)
    {
        cin >> u>>v;
        map[u][v]=1;
        map[v][u]=1;
    }
}

bool OK(int t) //判断色号是否相同的函数
{
    for(int j=1;j<t;j++) //判断现在扩展点t和前面t-1个顶点有没有相连的
    {
        if(map[t][j]) //如果相连
        {
            if(x[j]==x[t]) //且颜色一样
            {
                return false; //返回false，代表需要换个色号尝试
            }
        }
    }
    return true; //如果色号不一样就是true
}

void backtrack(int t) //回溯、递推函数
{
    if(t>n) //到达叶子节点
    {
        sum++; //方案个数
        cout << "第"<< sum << "种方案"<< endl;
        for (int i=1;i<=n;i++)
        {
            cout << x[i] << "    ";
        }
        cout << endl;
    }
    else
    {
        for (int i=1;i<=color_nums;i++) //尝试别的色号
        {
            x[t]=i;  //记录色号
            if(OK(t)) //如果色号没有撞
            {
                backtrack(t+1); //向下递推
            }
        }
    }
}


int main()
{
    cout << "请输入结点个数n："<< endl;
    cin >> n;
    cout << "请输入颜色的数量："<< endl;
    cin >> color_nums;
    cout << "请输入用邻接矩阵存储的图："<< endl;
    createmap();
    backtrack(1);
    return 0;
}
