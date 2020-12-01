
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

ll f(ll i, ll val)
{
    if(dp[i][val]!=-1)
        return dp[i][val];
    if(i==n && val==0)
        return dp[i][val] = 0;
    if(i==n && val!=0)
        return dp[i][val] = INT_MAX;

    ll a = 0, b = 0;
    if(val-v[i]>=0)
    a = f(i+1,val-v[i]);
    b = f(i+1,val);

    return dp[i][val] =  min(a+w[i],b);

}

int main()
{
    FAST
    cin>>n>>W;
    ll sum  = 0;
    for(ll i = 0;i<n;i++)
    {
        cin>>w[i]>>v[i];
        sum+=v[i];
    }
    memset(dp, -1, sizeof dp);
    for(ll i = sum;i>=0;i--)
    {
        ll wt = f(0,i);
        if(wt<=W)
        {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}

