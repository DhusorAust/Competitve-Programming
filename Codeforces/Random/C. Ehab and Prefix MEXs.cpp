#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int ans[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        ans[i] = -1;
    }
    vector<int>v;
    int lst = -1;
    for(int i=0;i<n;i++)
    {
        for(int j=lst+1;j<arr[i];j++)
        {
            v.push_back(j);
        }
        lst = arr[i];
    }
    int k = arr[n-1]+1;
    for(int i=0;i<n;i++)
    {
        v.push_back(k++);
    }
    for(int i=1;i<n;i++)
    {
        if(arr[i]!=arr[i-1])
        {
            ans[i] = arr[i-1];
        }
    }
    k = 0;
    for(int i=0;i<n;i++)
    {
        if(ans[i]==-1)
        {
            ans[i]=v[k++];
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
