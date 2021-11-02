#include <iostream>
using namespace std;
const int MAXN=1005;
int a[MAXN],L[MAXN],X[MAXN][MAXN];

int IncreaseOrder(int n)
{
    int i,j,k,index;
    for(i=0;i<n;i++)
    {
        L[i]=1;
    }
    for(i=1;i<n;i++)
    {
        int maxL = 1;
        int dj;
        for(j=i-1;j>=0;j--)
        {
            if(a[j]<a[i] && L[j]+1>maxL)
            {
                maxL=L[j]+1;
                dj=j;
            }
        }
        L[i] = maxL;
        for(k=0;k<maxL-1;k++)
            X[i][k] = X[dj][k];
        X[i][maxL-1] = a[i];
    }
    index = 0;
    for(i=1;i<n;i++)
        if(L[i]>L[index])
            index = i;
    cout<<"最长递增子序列:"<<endl;
    for(i=0;i<L[index];i++)
        cout<<X[index][i]<<" ";
    cout<<endl;
    return L[index];

}

int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<IncreaseOrder(n)<<endl;
    return 0;
}