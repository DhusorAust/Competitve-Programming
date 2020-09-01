#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
ll A[500009];
#define mod 1000000007

int main()
{
    FAST

    A[0] = 1;
    for(ll i = 1;i<500009;i++)
    {
        A[i] = (A[i-1]%mod*2%mod)%mod;
    }

    ll t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;

        ll arr[n];

        for(ll i = 0;i<n;i++)
        {
            cin>>arr[i];
        }

        ll ans[n];

        for(ll i = 1;i<n;i++)
        {
            cout<<A[n-i]<<" ";
        }

        cout<<A[0]<<endl;
    }

    return 0;
}

