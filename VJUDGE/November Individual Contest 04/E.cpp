#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef unsigned long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

ll mod;
ll F1[10000009];
ll fact[10000009];

ll F2(ll x)
{
    ll ans;
    if(x%2==0)
    {
        ans = ( ((x/2)%mod) * ((x+1)%mod) )%mod;
    }

    else
    {
        ans = ( (x%mod) * (((x+1)/2)%mod) )%mod;
    }

    ans = ( (ans%mod) * (x%mod) )%mod;

    return ans;
}

int main()
{
    FAST

    ll n , m;
    cin>>n>>m;

    mod = m;

    fact[0] = 1%mod;
    fact[1] = 1%mod;
    for(ll i = 2;i<=m;i++)
    {
        fact[i] = (fact[i-1]%mod*i%mod)%mod;
    }

    F1[0] = 0;
    F1[1] = 1%mod;

    for(ll i = 2;i<=m;i++)
    {
        F1[i] = (fact[i]%mod*i%mod)%mod;
    }

    for(ll i = 2;i<=m;i++)
    {
        F1[i] = (F1[i]%mod+F1[i-1]%mod)%mod;
    }

    ll arr[n];

    for(ll i = 0;i<n;i++)
    {
        cin>>arr[i];
    }

    ll ans = 0;

    for(ll i = 0;i<n;i++)
    {
        ll xx = arr[i];
        if(arr[i]>=mod)
        {
            xx = mod;
        }
        ll tmp = (F1[xx]%mod+F2(arr[i])%mod)%mod;

        ans =  (ans%mod+tmp%mod)%mod;
    }

    cout<<ans<<endl;



    return 0;
}
