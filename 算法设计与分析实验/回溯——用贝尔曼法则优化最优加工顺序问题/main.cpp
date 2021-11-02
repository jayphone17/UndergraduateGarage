#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

 const int MX=11111;
 int n;
 struct node
 {
     int x;
     int y;
     int id;
 }T[MX];

 bool cmp(node a,node b)
 {
     return min(b.x,a.y) >=min(b.y,a.x);//贝尔曼规则条件的排序
 }

int main()
{
    cout << "请输入机器零件的个数n："<< endl;
    cin>> n;
    cout << "请依次输入每个机器零件在第一台机器上的加工时间x和第二台机器上的加工时间y："<< endl;
    for (int i=0;i<n;i++)
    {
        cin >> T[i].x >> T[i].y;
        T[i].id=i+1;
    }
    sort(T,T+n,cmp);
    int f1=0;
    int f2=0;
    for (int i=0;i<n;i++)
    {
        f1+=T[i].x;
        f2=max(f1,f2)+T[i].y;
    }
    cout << "最优的机器零件加工顺序是："<< endl;
    for (int i=0;i<n;i++)
    {
        cout << T[i].id ;
    }
    cout << endl;
    cout << "最优的零件加工时间是："<< endl;
    cout << f2 << endl;
    return 0;
}
