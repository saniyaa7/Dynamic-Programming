#include<bits/stdc++.h>
using namespace std;
int min_subsetSum_diff(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    bool t[n+1][sum+1];
     for(int j=0;j<n+1;j++)
        t[j][0]=true;
    for(int i=1;i<sum+1;i++)
        t[0][i]=false;
   
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
            t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
            else
            t[i][j]=t[i-1][j];
        }
    }
    int diff;
    for(int j=sum/2;j>=0;j--)
    if(t[n][j]==true)
    {
        diff=sum-2*j;
        break;
    }
    return diff;
}
int main()
{
    int arr[]={1,2,7};
    cout<<min_subsetSum_diff(arr,sizeof(arr)/sizeof(arr[0]));
}