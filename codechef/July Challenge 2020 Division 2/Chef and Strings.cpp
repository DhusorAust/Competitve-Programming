
#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

int main()
{
    FAST

    int t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;

        ll arr[n];

        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        ll sum = 0;

        for(ll i = 1;i<n;i++)
        {
            if(arr[i]>arr[i-1])
                sum+=arr[i]-arr[i-1]-1;
            else
                sum+=arr[i-1]-arr[i]-1;
        }

        cout<<sum<<endl;
    }

    return 0;
}


