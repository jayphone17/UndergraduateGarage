#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int M=1111111;
int x; //Ҫ���ҵ�����
int n; //n������
int i; //ѭ��
int s[M];//�����洢���ִ�

int BinarySearch(int n,int s[],int x)
{
    int low=0; //ȷ���½�
    int high=n-1; //ȷ���Ͻ�
    while(low<=high)
    {
        int middle=(low+high)/2; //���ҵ������е��м�ֵ
        if(x==s[middle])
        {
            return middle; //���ҳɹ����м�ֵ����Ҫ���ҵ�Ԫ��
        }
        else if(x<s[middle])
        {
            high=middle-1;//û�в��ҳɹ�����ʱ֪��Ҫ���ҵ�Ԫ�����м�ֵ����ߣ����Ը����Ͻ�high��λ��
        }
        else
        {
            low=middle+1; //û�в��ҳɹ�����ʱ֪��Ҫ���ҵ�Ԫ�����м�ֵ���ұߣ����Ը����½�low��λ��
        }
    }
    return -1;
}

int main()
{
    cout<<"������Ԫ�صĸ��� : " << endl;
    while(cin>>n)
    {
        cout << "�����������е�Ԫ�� ��" << endl;
        for (i=0 ; i<n ; i++)
        {
            cin>>s[i] ;
        }
        sort(s,s+n); //�Դ�õ�Ԫ�ؽ��д�С���������
        cout << "����õ������ǣ�" << endl;
        for (i=0;i<n;i++)
        {
            cout << s[i] << " ";
        }
        cout<< "������Ҫ���ҵ�Ԫ�أ�" << endl;
        cin >> x;
        int number=BinarySearch(n,s,x);
        if(number==-1)
        {
            cout << "��������û��Ҫ���ҵ�Ԫ��" << endl;
        }
        else
        {
            cout << "Ҫ���ҵ�������" << number+1 << "λ" << endl;
        }
    }
    return 0;
}
