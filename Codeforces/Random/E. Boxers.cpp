#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int rear = INT_MAX;
    int cnt = 0;
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]+1<rear)
        {
            cnt++;
            rear = arr[i]+1;
        }
        else if(arr[i]<rear)
        {
            cnt++;
            rear = arr[i];
        }
        else if(arr[i]==rear && arr[i]!=1)
        {
            cnt++;
            rear = arr[i]-1;
        }
    }
    cout<<cnt<<endl;
    return 0;
}

