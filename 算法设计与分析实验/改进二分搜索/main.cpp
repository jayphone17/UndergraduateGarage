#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int M=1111;
int x; //Ҫ���ҵ�����
int n; //n������
int number_array[M];//�����洢���ִ�

int linjiefeng_BinarySearch(int n,int number_array[],int x) //n�������С��number_array�Ǵ洢���ֵ����飬x��Ҫ���ҵ�����
{
    int low=0; //ȷ���½�
    int high=n-1; //ȷ���Ͻ�
    int i=0;
    int j=0;
    while(low<=high)
    {
        int middle=(low+high)/2; //���ҵ������е��м�ֵ
        if(x==number_array[middle])
        {
            //���ҳɹ����м�ֵ����Ҫ���ҵ�Ԫ��
            i=middle;
            j=middle;
            cout << "���ҳɹ���i,j��ֵ�ǣ�"<< i <<" "<< j << endl;
            return middle;
        }
        else if(x<number_array[middle])
        {
            high=middle-1;//û�в��ҳɹ�����ʱ֪��Ҫ���ҵ�Ԫ�����м�ֵ����ߣ����Ը����Ͻ�high��λ��
        }
        else
        {
            low=middle+1; //û�в��ҳɹ�����ʱ֪��Ҫ���ҵ�Ԫ�����м�ֵ���ұߣ����Ը����½�low��λ��
        }
    }
    i=low;
    j=high;
    cout << "û�в��ҳɹ���i��j��ֵ�ǣ�"<< i << " " << j << endl;
    return -1;
}

int main()
{
    cout<<"������Ԫ�صĸ��� : " << endl;
    while(cin>>n)
    {
        cout << "�����������е�Ԫ�� ��" << endl;
        for (int i=0 ; i<n ; i++)
        {
            cin>>number_array[i] ;
        }
        cout<< "������Ҫ���ҵ�Ԫ�أ�" << endl;
        cin >> x;
        int number=linjiefeng_BinarySearch(n,number_array,x);
   }
    return 0;
}
