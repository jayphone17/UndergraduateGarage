#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int N=111;
char str1[N];//第一个字符串
char str2[N];//第二个字符串
int d[N][N];//记录最优数值的二维数组
                //定义辅助数组，d[i][j]表示str1前i个字符和str2前j个字符的编辑距离。

int DistanceEditting(char *str1,char *str2)
{
    int len1=strlen(str1);
    int len2=strlen(str2);
    for (int i=0;i<=len1;i++)
    {
        d[i][0]=i;
    }
    for (int j=0;j<=len2;j++)
    {
        d[0][j]=j;
    }
    for (int i=1;i<=len1;i++)
    {
        for (int j=1;i<=len2;j++)
        {
            int diff;
            //判断str1[i]是否等于str2[j-1]，相等为0，不等为1
            if(str1[i-1]==str2[j-1])
            {
                diff=0;
            }
            else
            {
                diff=1;
            }
            int temp=min(d[i-1][j]+1 , d[i][j-1]+1);
            d[i][j]=min(temp,d[i-1][j-1]+diff);
        }
    }
    return d[len1][len2];
}

int main()
{
    cout << "请输入第一个字符串str1" << endl;
    cin >> str1;
    cout << "请输入第二个字符串str2" << endl;
    cin >> str2;
    cout << str1 << "和" << str2 << "的编辑距离是："<< DistanceEditting(str1,str2)<< endl;
    return 0;
}
