#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int M=1111111;

struct package
{
    int weight; //����
    int value;//��ֵ
    int cost_performance;//�Լ۱�
}s[M];

bool cmp(package a,package b)
{
    return a.cost_performance>b.cost_performance;
}
//���Լ۱ȴӴ�С�������ں����sort������

int main()
{
    int n;//��n������
    double m;// �����������
    cout << "�����뱦������������������������" << endl;
    cin >> n>>m;
    cout << "������ÿ������������ͼ�ֵ���ÿո�ֿ�" << endl;
    for (int i=0;i<n;i++)
    {
        cin >> s[i].weight >> s[i].value;
        s[i].cost_performance=s[i].value / s[i].weight;
        //ÿ������ĵ�λ�Լ۱�
    }
    sort(s,s+n,cmp);//���Լ۱ȴӴ�С����
    double sum=0.0; //��ֵ֮��
    for(int i=0;i<n;i++)
    {
        if(s[i].weight<m)
        {
            sum+=s[i].value;
            m-=s[i].weight;
        }
        else //��ʣ������,�ָ����
        {
            sum+=m*s[i].cost_performance;
            break;
        }
    }
    cout << "װ�뱦�������ֵΪ��" <<sum << endl;
    return 0;
}
