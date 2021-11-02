#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int Partition(int r[],int low,int high)
{
    int i=low;
    int j=high;
    int pivot=r[low]; //基准变量
    while(i<j) //当下界小于上界的时候开始循环
    {
        while(i<j && r[j]>pivot) //这时候先从右向左进行遍历，找到一个比基准值小的数字。
        {
            j--; //从右向左移动。
        }
        if(i<j)
        {
            swap(r[i++],r[j]); //找到比基准值小的数字，交换这两个数字，然后开始从左向右移动。
        }
        while(i<j && r[i]<=pivot)
        {
            i++;  //从左向右移动。
        }
        if(i<j)
        {
            swap(r[i],r[j--]); //找到一个比基准值大的数字，交换两个数字，再开始从右向左移动。
        }
    }
    return i;  //i，j两个指针相遇，返回中间值middle
}

void QuickSort(int R[],int low,int high)
{
    int middle;
    if(low<high)
    {
        middle=Partition(R,low,high);
        QuickSort(R,low,middle-1);
        QuickSort(R,middle+1,high);
        //使用递归方法再对分隔开的两段数组进行快速排序，重复上述的过程。
    }

}

int main()
{
    int a[1111];
    int i;
    int n;
    cout << "请输入要进行排序的数字的个数："<< endl;
    cin >> n;
    cout<< "请输入要进行排序的数据："<< endl;
    for (i=0;i<n;i++)
    {
        cin>> a[i];
    }
    cout << endl;
    QuickSort(a,0,n-1);
    cout<< "排序完成后的序列为：" << endl;
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
        //同时进行
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
