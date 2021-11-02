#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

const int N=1111;
int c[N][N]; //计算长度二维数组
int b[N][N]; //存储LCS内容二维数组
char s1[N]; //第一个字符串
char s2[N]; //第二个字符串
int len1; //长度
int len2; //长度

void LCSL()
{
    int i;
    int j;
    for (i=1;i<=len1;i++) //控制序列1
    {
        for(j=1;j<=len2;j++) //控制序列2
        {
            if(s1[i-1]==s2[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=1;
                //来源是策略1
            }
            else
            {
                if(c[i][j-1]>=c[i-1][j])
                {
                    c[i][j]=c[i][j-1];
                    b[i][j]=2;
                    //来源是策略2
                }
                else
                {
                    c[i][j]=c[i-1][j];
                    b[i][j]=3;
                    //来源是策略3
                }
            }
        }
    }
}

void print(int i,int j)
{
    if(i==0 || j==0)
    {
        return;
    }
    if(b[i][j]==1)
    {
        print(i-1,j-1);
        cout <<s1[i-1];
    }
    else if (b[i][j]==2)
    {
        print (i,j-1);
    }
    else
    {
        print(i-1,j);
    }
}

int main()
{
    int i;
    int j;
    cout << "请输入第一个字符串s1" << endl;
    cin >> s1;
    cout << "请输入第二个字符串s2" << endl;
    cin >> s2;
    len1=strlen(s1);//计算s1长度
    len2=strlen(s2);//计算s2长度
    for (i=0;i<=len1;i++)
    {
        c[i][0]=0;//初始化第一列为0
    }
    for (j=0;j<=len2;j++)
    {
        b[j][0]=0;//初始化第一行为0
    }
    LCSL();//调用计算长度的函数
    cout << "s1和s2的最长公共子序列的长度是： " << c[len1][len2] << endl;
    cout << "s1和s2的最长公共子序列是： " << endl;
    print(len1,len2);//递归求解最长公共子序列的内容
    return 0;
}
