#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

int main()
{
    FAST

    ll t;
    cin>>t;

    while(t--)
    {
        ll n,x;
        cin>>n>>x;

        ll arr[n];

        for(ll i=0;i<n;i++)
            cin>>arr[i];

        sort(arr,arr+n);

        ll taken  = 1;
        ll cnt = 0;
        for(ll i=n-1;i>=0;i--)
        {
            if(arr[i]*taken++>=x)
            {
                taken = 1;
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }

    return 0;
}

