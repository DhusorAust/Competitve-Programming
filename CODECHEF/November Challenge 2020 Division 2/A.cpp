#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

ll n;
ll tot;
ll dp[10][30];
ll inf = 25;
ll arr[10];

ll f(ll i, ll sum)
{
    if(dp[i][sum]!=-1)
        return dp[i][sum];
    if(i==n)
        return dp[i][sum] = inf;
    ll a = f(i+1,sum);
    ll b = f(i+1,sum+arr[i]);
    ll c = sum+arr[i];
    ll d = tot-c;
    c = max(d,c);
    a = min(a,b);
    return dp[i][sum] = min(a,c);
}

int main()
{
    FAST
    ll t;
    cin>>t;

    while(t--)
    {
        tot = 0;
        cin>>n;

        for(ll i = 0;i<n;i++)
        {
            cin>>arr[i];
            tot+=arr[i];
        }

        memset(dp,-1,sizeof dp);

        cout<<f(0,0)<<endl;
    }

    return 0;
}

