#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int N=111;
char str1[N];//��һ���ַ���
char str2[N];//�ڶ����ַ���
int d[N][N];//��¼������ֵ�Ķ�ά����
                //���帨�����飬d[i][j]��ʾstr1ǰi���ַ���str2ǰj���ַ��ı༭���롣

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
            //�ж�str1[i]�Ƿ����str2[j-1]�����Ϊ0������Ϊ1
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
    cout << "�������һ���ַ���str1" << endl;
    cin >> str1;
    cout << "������ڶ����ַ���str2" << endl;
    cin >> str2;
    cout << str1 << "��" << str2 << "�ı༭�����ǣ�"<< DistanceEditting(str1,str2)<< endl;
    return 0;
}
