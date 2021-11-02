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
     return min(b.x,a.y) >=min(b.y,a.x);//��������������������
 }

int main()
{
    cout << "�������������ĸ���n��"<< endl;
    cin>> n;
    cout << "����������ÿ����������ڵ�һ̨�����ϵļӹ�ʱ��x�͵ڶ�̨�����ϵļӹ�ʱ��y��"<< endl;
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
    cout << "���ŵĻ�������ӹ�˳���ǣ�"<< endl;
    for (int i=0;i<n;i++)
    {
        cout << T[i].id ;
    }
    cout << endl;
    cout << "���ŵ�����ӹ�ʱ���ǣ�"<< endl;
    cout << f2 << endl;
    return 0;
}
