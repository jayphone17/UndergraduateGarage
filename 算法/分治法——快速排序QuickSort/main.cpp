#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int Partition(int r[],int low,int high)
{
    int i=low;
    int j=high;
    int pivot=r[low]; //��׼����
    while(i<j) //���½�С���Ͻ��ʱ��ʼѭ��
    {
        while(i<j && r[j]>pivot) //��ʱ���ȴ���������б������ҵ�һ���Ȼ�׼ֵС�����֡�
        {
            j--; //���������ƶ���
        }
        if(i<j)
        {
            swap(r[i++],r[j]); //�ҵ��Ȼ�׼ֵС�����֣��������������֣�Ȼ��ʼ���������ƶ���
        }
        while(i<j && r[i]<=pivot)
        {
            i++;  //���������ƶ���
        }
        if(i<j)
        {
            swap(r[i],r[j--]); //�ҵ�һ���Ȼ�׼ֵ������֣������������֣��ٿ�ʼ���������ƶ���
        }
    }
    return i;  //i��j����ָ�������������м�ֵmiddle
}

void QuickSort(int R[],int low,int high)
{
    int middle;
    if(low<high)
    {
        middle=Partition(R,low,high);
        QuickSort(R,low,middle-1);
        QuickSort(R,middle+1,high);
        //ʹ�õݹ鷽���ٶԷָ���������������п��������ظ������Ĺ��̡�
    }

}

int main()
{
    int a[1111];
    int i;
    int n;
    cout << "������Ҫ������������ֵĸ�����"<< endl;
    cin >> n;
    cout<< "������Ҫ������������ݣ�"<< endl;
    for (i=0;i<n;i++)
    {
        cin>> a[i];
    }
    cout << endl;
    QuickSort(a,0,n-1);
    cout<< "������ɺ������Ϊ��" << endl;
    for (i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

int OptimizedQuickSort(int r[],int low,int high)
{
    int i=low;
    int j=high;
    int pivot=r[low];
    while(i<j)
    {
        while(i<j && r[j]>pivot)
        {
            j--;
        }
        while(i<j && r[i]<=pivot)
        {
            i--;
        }
        //ͬʱ����
        if(i<j)
        {
            swap(r[i++],r[j--]);
        }
    }
    if(r[i]>pivot)
    {
        swap(r[i-1],r[low]);
        return i-1;
    }
    swap(r[i],r[low]);
    return i;
}
