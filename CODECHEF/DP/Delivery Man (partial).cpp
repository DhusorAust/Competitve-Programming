#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
ll n, x, y;
ll arr[2][5005];
ll dp[2][5005][5005];

ll f(ll i, ll j, ll cnt)
{
    if(dp[i][j][cnt]!=-1)
        return dp[i][j][cnt];
    if( j==n+1)
        return dp[i][j][cnt] = 0;
    ll a = 0, b = 0;
    if(i==0)
    {
        if(cnt<x)
            a = f(i,j+1,cnt+1);
        if(cnt<=y)
            b = f(i+1,j+1,cnt);
    }
    else
    {
        if(cnt<y)
            a = f(i,j+1,cnt+1);
        if(cnt<=x)
            b = f(i-1,j+1,cnt);
    }
    return dp[i][j][cnt] = arr[i][j]+max(a,b);
}


int main()
{
    FAST

    cin>>n>>x>>y;
    arr[0][0] = 0;
    arr[1][0] = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[0][i];
    }

    for(int i=1;i<=n;i++)
    {
        cin>>arr[1][i];
    }

    memset(dp,-1, sizeof dp);
    ll ans = f(0,0,0);
    cout<<ans<<endl;

    return 0;
}

