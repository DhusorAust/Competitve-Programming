#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int arr[n],a,b,m,diff = INT_MAX;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>m;
        sort(arr,arr+n);
        for(int i=0,j=n-1;i<=j;)
        {
            if(arr[i]+arr[j]==m && (arr[j]-arr[i]) <diff)
            {
                a = arr[i];
                b = arr[j];
                i++;
                j--;
            }
            else if(arr[i]+arr[j]>m)
                j--;
            else
                i++;
        }
        cout<<"Peter should buy books whose prices are "<<a<<" and "<<b<<"."<<endl<<endl;
    }
    return 0;
}
