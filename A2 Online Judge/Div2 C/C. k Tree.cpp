#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
ll n, k, d;
ll dp[105][5];
ll f(ll sum, ll bol)
{
    if(dp[sum][bol]!=-1)
        return dp[sum][bol];
    if(sum==n)
        return dp[sum][bol] = bol;
    ll a = 0;
    for(ll i = 1;i<=k;i++)
    {
        if(sum+i<=n)
        {
            if(bol==1 || i>=d)
                a=(a%mod+f(sum+i,1)%mod)%mod;
            else
                a=(a%mod+f(sum+i,0)%mod)%mod;
        }
    }
    return dp[sum][bol] = a;
}

int main()
{
    FAST
    cin>>n>>k>>d;
    memset(dp, -1, sizeof dp);
    ll ans = f(0,0);
    cout<<ans<<endl;
    return 0;
}

