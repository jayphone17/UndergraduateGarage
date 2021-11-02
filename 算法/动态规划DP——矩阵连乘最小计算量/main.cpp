#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int max_size=111;  //矩阵的大小范围
int p[max_size]; //用来记录行列的数组
int m[max_size][max_size]; //记录子问题最优值的数组
int s[max_size][max_size];  //记录子问题最优策略的数组
int n; //矩阵的个数

void matrixchain()
{
    int i;//循环条件
    int j;//循环条件
    int r;//连乘的规模
    int k;//记录最优策略
    memset(m,0,sizeof(m));
    memset(s,0,sizeof(s));
    //清空数组
    for (r=2;r<=n;r++) //r记录规模，从规模为2开始计算，只有一个矩阵的话计算量是0
    {
        for (i=1;i<=n-r+1;i++) //n-r+1 表示对应矩阵个数n的要多少次相乘次数
        {
            j=i+r-1;
            //j=i+1,i+2,i+3,i+4……
            m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
            //策略k=i的乘法次数
            s[i][j]=i;//子问题的最优策略是i
            for(k=i+1;k<j;k++)//从k到j的所有决策，求最优值，记录最优策略
            {
                int t=m[i][k]+m[k+i][j]+p[i-1]*p[k]*p[j];
                if(m[i][j]>t)
                {
                    m[i][j]=t; //记录最优值。
                    s[i][j]=k;//把最优策略记录。
                }
            }
        }
    }
}

void print(int i,int j)
{
    if(i==j)
    {
        cout << "A["<< i << "]";
        return;
    }
    cout << "(";
    print(i,s[i][j]);
    print(s[i][j]+1,j);
    //递归求解子问题打印括号。
    cout << ")";
}


int main()
{
    cout << "请输入矩阵的个数n："<< endl;
    cin >> n;
    int i;
    int j;
    cout << "请输入每个矩阵的行数和最后一个矩阵的列数："<<endl;
    for (i=0;i<=n;i++)
    {
        cin >>p[i];
    }
    matrixchain();
    print(1,n);
    cout << endl;
    cout << "最小计算量的值为："<<m[1][n]<<endl;
    return 0;
}
