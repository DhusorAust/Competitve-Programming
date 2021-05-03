#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
ll t, n, k;
ll dp[1009][1009];
ll f(ll k2, ll n2)
{
    if(dp[k2][n2]!=-1)
        return dp[k2][n2];
    if(k2==1)
        return dp[k2][n2] = 1;
    ll a = 1, b = 1;
    if( (k-k2)%2==0 )
    {
        if(n2<n)
            a = f(k2, n2+1);
        if(n2>1)
            b = f(k2-1,n2-1);
    }
    else
    {
        if(n2>1)
            a= f(k2, n2-1);
        if(n2<n)
            b = f(k2-1,n2+1);
    }
    return dp[k2][n2] = ((a%mod) + (b%mod))%mod;
}
int main()
{
    FAST
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        memset(dp, -1, sizeof dp);
        cout<<f(k,1)<<endl;
    }
    return 0;
}

