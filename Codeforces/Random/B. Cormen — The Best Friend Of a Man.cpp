#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;

int main()
{
    FAST;

    ll n,k;
    cin>>n>>k;

    ll arr[n];

    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ll sum = 0;
    for(ll i=0;i<n;i++)
    {
        if(arr[i]+arr[i+1]>=k)
            continue;
        sum-=arr[i+1];
        arr[i+1] = k-arr[i];
        sum+=arr[i+1];

    }

    cout<<sum<<endl;
    for(ll i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;






    return 0;
}
