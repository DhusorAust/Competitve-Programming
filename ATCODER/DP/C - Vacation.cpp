#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
 ll n;
 ll arr[100009][3];
 ll  dp[100009][5];

ll f(ll i,ll j)
{
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(i==n+1)
        return dp[i][j] = 0;
    if(i==0)
    {
        ll a = 0, b = 0, c = 0;
        a = f(i+1,0);
        b = f(i+1,1);
        c = f(i+1,2);

        return dp[i][j] = max(max(a,b),c);
    }

    ll a = 0, b = 0;
    if(j==0)
    {
        a = f(i+1,1);
        b = f(i+1,2);
    }

    else if(j==1)
    {
        a = f(i+1,0);
        b = f(i+1,2);
    }

    else if(j==2)
    {
        a = f(i+1,0);
        b = f(i+1,1);
    }

    return dp[i][j] = arr[i][j]+max(a,b);

}

int main()
{
    FAST

    cin>>n;

    for(ll i = 1;i<=n;i++)
    {
        for(ll  j =0;j<3;j++)
        {
            cin>>arr[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    cout<<f(0,0)<<endl;

    return 0;
}

