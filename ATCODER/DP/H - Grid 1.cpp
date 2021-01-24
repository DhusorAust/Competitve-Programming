#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
ll n, m;
char arr[1009][1009];
ll dp[1009][1009];
ll f(ll i, ll j)
{
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(i==n-1 && j==m-1)
        return dp[i][j] = 1;
    if(i>=n || i< 0 || j<0 || j>=m)
        return dp[i][j] = 0;
    if(arr[i][j]=='#')
        return dp[i][j] = 0;
    ll a = f(i+1,j);
    ll b = f(i,j+1);
    return dp[i][j] = (a%mod+b%mod)%mod;
}

int main()
{
    FAST
    cin>>n>>m;
    for(ll i = 0;i<n;i++)
    {
        for(ll j = 0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    cout<<f(0,0)<<endl;

    return 0;
}

