#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

void Merge(int A[],int low,int middle,int high)
{
    int *B=new int [high-low+1];//����һ���������飬���ȸ�����Aһ����
    int i=low; //��iָ��ָ���һ�ֶε������Ԫ��
    int j=middle+1; //��ָ��ָ��ڶ��ֶε������Ԫ��
    int k=0;//ָ����������һԪ�ص�ָ��
    while(i<=middle && j<=high)
    {
        if(A[i]<=A[j])
        {
            B[k++]=A[i++];
        }
        else
        {
            B[k++]=A[j++];
        }
        //�ȽϷֶ�֮��Ƚ�i��jָ��ָ���Ԫ�ش�С��������С�ķ��븨������B��Ȼ��ָ�����
    }
    while(i<=middle)
    {
        B[k++]=A[i++];
    }
    while(j<=high)
    {
        B[k++]=A[j++];
    }
    //������while�Ǵ���A����ʣ�µ�Ԫ�ء���Ϊ�ֶ�֮�������С��һ��һ���������临�Ƶ�B������ȥ��
    for(i=low,k=0;i<=high;i++)
    {
        A[i]=B[k++];
    }
    //��ʱB���������ź�������֣���������Ԫ�ظ��Ƶ�A������ȥ
    delete []B;//ʹ����B����֮�󣬽���ɾ������
}

void MergeSort(int A[],int low,int high)
{
    if(low<high)
    {
        int middle=(low+high)/2;
        MergeSort(A,low,middle); //����һ�ν��кϲ����򣨷��εݹ飩
        MergeSort(A,middle+1,high); //���ڶ��ν��кϲ�����
        Merge(A,low,middle,high);
        //���պϲ���ɺ��Ƶ�A�������顣
    }
}

int main()
{
    int A[1111];
    int n;
    cout << "������Ԫ�صĸ�����"<< endl;
    cin >> n;
    cout << "�����������е�Ԫ�أ�" << endl;
    for (int i=0;i<n;i++)
    {
        cin>> A[i];
    }
    MergeSort(A,0,n-1);
    cout << "�ϲ�����֮��Ľ����"<< endl;
    for (int i=0;i<n;i++)
    {
        cout << A[i] << " " ;
    }
    cout << endl;
    return 0;
}
