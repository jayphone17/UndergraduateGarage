#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <algorithm>
using namespace std;

const int M =1111;
int n; //������
int s[M][M];//��¼���Ų��Զ�ά����
double m[M][M];//��¼����ֵ��ά����
double g[M][M];//��¼������֮��Ȩֵ�Ķ�ά����

void convex_Polygon_Triangulation()
{
    for (int i=1;i<=n;i++) //��ʼ��
    {
        m[i][i]=0;
        s[i][i]=0;
    }
    for(int d=2;d<=n;d++)//dΪ�����ģ��d=2ʵ������������
    {
        for (int i=1;i<=n-d+1;i++)//����iֵ
        {
            int j=i+d-1; //jֵ
            m[i][j]=m[i+1][j]+g[i-1][i]+g[i][j]+g[i-1][j];
            //����Ϊk=i�����
            s[i][j]=i;
            for (int k=i+1;k<j;k++) //ö�ٻ��ֵ�i��j�������
            {
                double temp=m[i][k]+m[k+1][j]+g[i-1][k]+g[k][j]+g[i-1][j];
                if(m[i][j]>temp)
                {
                    m[i][j]=temp;
                    s[i][j]=k;
                }
            }
        }
    }
}

void print (int i,int j)  //�ݹ����������������ҡ�
{
    if(i==j)
        return ;
    if(s[i][j]>i)
    {
        cout << "{v" << i-1 << "v" << s[i][j] << "}" << endl;
    }
    if(s[i][j]+1<j)
    {
        cout << "{v" << s[i][j] << "v" << j << "}" << endl;
    }
    print(i,s[i][j]);
    print(s[i][j]+1,j);
}

int main()
{
    int i;
    int j;
    cout << "�����붥�����n��"<< endl;
    cin >> n;
    n--;
    cout << "��������������������Ȩֵ��" << endl;
    for (i=0;i<=n;++i)
    {
        for (j=0;j<=n;++j)
        {
            cin >> g[i][j];
        }
    }
    convex_Polygon_Triangulation();
    cout << "���������ʷֵ�Ȩֵ����:" << endl;
    cout << m[1][n]<< endl;
    cout << "����ļ����ǣ�"<< endl;
    print(1,n);
    return 0;
}
