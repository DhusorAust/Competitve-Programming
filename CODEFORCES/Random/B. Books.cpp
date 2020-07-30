#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

int main()
{
    FAST

    ll n,t;
    cin>>n>>t;

    ll arr[n];
    ll prex[n];

    ll sum = 0;
    for(ll i = 0;i<n;i++)
    {
        cin>>arr[i];
        prex[i] = arr[i];
    }

    for(ll i = 1;i<n;i++)
    {
        prex[i]+=prex[i-1];
    }

    ll ans = 0;
    for(ll i = 0;i<n;i++)
    {
        ll ix = upper_bound(prex+i,prex+n,t)-prex;
        ans = max(ans,ix-i);
        t+=arr[i];
    }
    cout<<ans<<endl;

    return 0;
}

