
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
ll n, W;
ll w[109];
ll v[109];
ll dp[109][100009];

ll f(ll i, ll wt)
{
    if(dp[i][wt]!=-1)
        return dp[i][wt];
    if(i==n)
        return dp[i][wt] = 0;

    if(wt+w[i]>W)
    {
        ll b = f(i+1,wt);
        return dp[i][wt] = b;
    }

    ll a = 0 , b = 0;

    a = f(i+1,wt+w[i]);
    b = f(i+1,wt);
    return dp[i][wt] = max(v[i]+a,b);
}

int main()
{
    FAST
    cin>>n>>W;

    for(ll i = 0;i<n;i++)
    {
        cin>>w[i]>>v[i];
    }
    memset(dp, -1, sizeof dp);
    cout<<f(0,0)<<endl;
    return 0;
}

