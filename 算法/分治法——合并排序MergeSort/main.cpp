#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

void Merge(int A[],int low,int middle,int high)
{
    int *B=new int [high-low+1];//创建一个辅助数组，长度跟数组A一样长
    int i=low; //将i指针指向第一分段的最左边元素
    int j=middle+1; //将指针指向第二分段的最左边元素
    int k=0;//指向辅助函数第一元素的指针
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
        //比较分段之后比较i和j指针指向的元素大小，并将较小的放入辅助数组B，然后指针后移
    }
    while(i<=middle)
    {
        B[k++]=A[i++];
    }
    while(j<=high)
    {
        B[k++]=A[j++];
    }
    //这两个while是处理A数组剩下的元素。因为分段之后数组大小不一定一样。并将其复制到B数组中去。
    for(i=low,k=0;i<=high;i++)
    {
        A[i]=B[k++];
    }
    //此时B数组中是排好序的数字，将其所有元素复制到A数组中去
    delete []B;//使用完B数组之后，将其删除掉。
}

void MergeSort(int A[],int low,int high)
{
    if(low<high)
    {
        int middle=(low+high)/2;
        MergeSort(A,low,middle); //将第一段进行合并排序（分治递归）
        MergeSort(A,middle+1,high); //将第二段进行合并排序
        Merge(A,low,middle,high);
        //最终合并完成后复制到A辅助数组。
    }
}

int main()
{
    int A[1111];
    int n;
    cout << "请输入元素的个数："<< endl;
    cin >> n;
    cout << "请输入数组中的元素：" << endl;
    for (int i=0;i<n;i++)
    {
        cin>> A[i];
    }
    MergeSort(A,0,n-1);
    cout << "合并排序之后的结果："<< endl;
    for (int i=0;i<n;i++)
    {
        cout << A[i] << " " ;
    }
    cout << endl;
    return 0;
}
