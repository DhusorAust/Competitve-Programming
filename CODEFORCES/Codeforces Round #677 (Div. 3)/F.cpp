#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

ll n, m, k;
ll arr[75][75];
ll dp[75][75][75][75];

ll f(ll i, ll j, ll cnt , ll mod)
{
    if(dp[i][j][cnt][mod]!=-1)
        return dp[i][j][cnt][mod];
    if(i==n)
    {
        if(mod==0)
            return dp[i][j][cnt][mod] = 0;
        else
            return dp[i][j][cnt][mod] = INT_MIN;
    }
    ll a = INT_MIN, b = INT_MIN;
    if(j<m-1)
    {
        a = f(i,j+1,cnt, mod);
        if(cnt<m/2)
            b = f(i,j+1,cnt+1,(mod+arr[i][j])%k);
    }
    else
    {
        a = f(i+1,0,0,mod);
        if(cnt<m/2)
           b = f(i+1,0,0,(mod+arr[i][j])%k);
    }

    return dp[i][j][cnt][mod] = max(a,arr[i][j]+b);
}

int main()
{
    FAST

    cin>>n>>m>>k;

    for(ll i = 0; i<n;i++)
    {
        for(ll j = 0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }

    memset(dp, -1 , sizeof dp);

    cout<<max(0LL,f(0,0,0,0))<<endl;

    return 0;
}

