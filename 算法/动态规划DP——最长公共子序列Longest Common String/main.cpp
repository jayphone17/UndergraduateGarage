#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

const int N=1111;
int c[N][N]; //���㳤�ȶ�ά����
int b[N][N]; //�洢LCS���ݶ�ά����
char s1[N]; //��һ���ַ���
char s2[N]; //�ڶ����ַ���
int len1; //����
int len2; //����

void LCSL()
{
    int i;
    int j;
    for (i=1;i<=len1;i++) //��������1
    {
        for(j=1;j<=len2;j++) //��������2
        {
            if(s1[i-1]==s2[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=1;
                //��Դ�ǲ���1
            }
            else
            {
                if(c[i][j-1]>=c[i-1][j])
                {
                    c[i][j]=c[i][j-1];
                    b[i][j]=2;
                    //��Դ�ǲ���2
                }
                else
                {
                    c[i][j]=c[i-1][j];
                    b[i][j]=3;
                    //��Դ�ǲ���3
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
    cout << "�������һ���ַ���s1" << endl;
    cin >> s1;
    cout << "������ڶ����ַ���s2" << endl;
    cin >> s2;
    len1=strlen(s1);//����s1����
    len2=strlen(s2);//����s2����
    for (i=0;i<=len1;i++)
    {
        c[i][0]=0;//��ʼ����һ��Ϊ0
    }
    for (j=0;j<=len2;j++)
    {
        b[j][0]=0;//��ʼ����һ��Ϊ0
    }
    LCSL();//���ü��㳤�ȵĺ���
    cout << "s1��s2������������еĳ����ǣ� " << c[len1][len2] << endl;
    cout << "s1��s2��������������ǣ� " << endl;
    print(len1,len2);//�ݹ��������������е�����
    return 0;
}
