#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int max_size=111;  //����Ĵ�С��Χ
int p[max_size]; //������¼���е�����
int m[max_size][max_size]; //��¼����������ֵ������
int s[max_size][max_size];  //��¼���������Ų��Ե�����
int n; //����ĸ���

void matrixchain()
{
    int i;//ѭ������
    int j;//ѭ������
    int r;//���˵Ĺ�ģ
    int k;//��¼���Ų���
    memset(m,0,sizeof(m));
    memset(s,0,sizeof(s));
    //�������
    for (r=2;r<=n;r++) //r��¼��ģ���ӹ�ģΪ2��ʼ���㣬ֻ��һ������Ļ���������0
    {
        for (i=1;i<=n-r+1;i++) //n-r+1 ��ʾ��Ӧ�������n��Ҫ���ٴ���˴���
        {
            j=i+r-1;
            //j=i+1,i+2,i+3,i+4����
            m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
            //����k=i�ĳ˷�����
            s[i][j]=i;//����������Ų�����i
            for(k=i+1;k<j;k++)//��k��j�����о��ߣ�������ֵ����¼���Ų���
            {
                int t=m[i][k]+m[k+i][j]+p[i-1]*p[k]*p[j];
                if(m[i][j]>t)
                {
                    m[i][j]=t; //��¼����ֵ��
                    s[i][j]=k;//�����Ų��Լ�¼��
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
    //�ݹ�����������ӡ���š�
    cout << ")";
}


int main()
{
    cout << "���������ĸ���n��"<< endl;
    cin >> n;
    int i;
    int j;
    cout << "������ÿ����������������һ�������������"<<endl;
    for (i=0;i<=n;i++)
    {
        cin >>p[i];
    }
    matrixchain();
    print(1,n);
    cout << endl;
    cout << "��С��������ֵΪ��"<<m[1][n]<<endl;
    return 0;
}
