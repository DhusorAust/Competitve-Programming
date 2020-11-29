#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

ll n, k;
ll arr[100009];
ll dp[100009];

ll f(ll i)
{
    if(dp[i]!=-1)
        return dp[i];
    if(i==n-1)
        return dp[i] = 0;
    ll miin = INT_MAX;
    for(ll j = i+1,k2=0;j<n && k2<k;j++,k2++)
    {
       miin = min(miin, abs(arr[i]-arr[j])+f(j));
    }
    return dp[i] = miin;
}


int main()
{
    FAST

    cin>>n>>k;
    for(ll i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    memset(dp,-1, sizeof dp);
    cout<<f(0)<<endl;

    return 0;
}

