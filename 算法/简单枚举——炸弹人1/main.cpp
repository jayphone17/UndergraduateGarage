#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int N =111; //地图最大大小

int main()
{
    char graph[N][N];//存储地图的二维矩阵
    int n;//有多少行
    int m;//有多少列
    int p;//记录放置炸弹x坐标
    int q;//记录放置炸弹y坐标
    int sum;//记录最多消灭敌人个数
    int maxx=0;
    int x;
    int y;
    cout << "请输入地图的行n和列m" << endl;
    cin >> n >> m;
    cout << "请输入地图：" << endl;
    for(int i=0; i<=n-1; i++)
    {
        cin >> graph[i];
    }
    for(int i=0; i<=n-1; i++)
    {
        for(int j=0; j<=m-1; j++)
        {
            if(graph[i][j]=='.') //判断此时位置是否是平地
            {
                sum=0;//初始化最大消灭敌人数是0
                //将坐标i，j复制到新变量x，y中，以便上下左右统计可以消灭地人数
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
                if(sum>maxx)
                {
                    maxx=sum;
                    p=i;
                    q=j;
                }
            }
        }
    }
    cout << "将炸弹放置在" <<"("<<p<<","<<q<< ")" <<"最多可以消灭" << sum << "个敌人"<< endl;
    return 0;
}
