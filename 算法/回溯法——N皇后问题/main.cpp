#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=111;
int n;
int x[N];
int countn;

bool OK(int t)
{
    bool ok=true;
    for(int j=1;j<t;j++)
    {
        if(x[t]==x[j] || (t-j) ==fabs(x[t]-x[j]) )//约束条件
        {
           ok=false;
           break;
        }
    }
    return ok;
}

void backtrack(int t)
{
    if(t>n)
    {
        countn++;
        for (int i=1;i<=n;i++)
        {
            cout << x[i] << "   ";
        }
        cout << endl;
        cout << "——————" << endl;
        cout << endl;
    }
    else
    {
        for (int i=1;i<=n;i++)
        {
            x[t]=i;
            if(OK(t))
            {
                backtrack(t+1);
            }
        }
    }
}

int main()
{
    cout << "请输入皇后的个数" << endl;
    cin >> n;
    countn=0;
    backtrack(1);
    cout << "答案的个数是："<< countn << endl;
    return 0;
}
