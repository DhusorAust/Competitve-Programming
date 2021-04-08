#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
//priority_queue<int, vector<int>, greater<int> > min_q;
int main()
{
    FAST
    ll t;
    cin>>t;
    while( t--)
    {
        ll n;
        cin>>n;
        ll arr[n+1];
        ll dp[n+1];
        memset(dp, 0 , sizeof dp);
        for(ll i = 1;i<=n;i++)
        {
            cin>>arr[i];
        }
        for(ll i = 1;i<=n;i++)
        {
            dp[i]+=1;
            dp[max(0LL,i-arr[i])]-=1;
        }
        for(ll i = n-1;i>=0;i--)
        {
            dp[i]+=dp[i+1];
        }
        for(ll i = 1;i<=n;i++)
        {
            if(dp[i]==0)
                cout<<dp[i]<<" ";
            else
                cout<<1<<" ";
        }
        cout<<endl;
    }
    return 0;
}

