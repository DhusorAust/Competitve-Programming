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

    while(t--)
    {
        ll n, k;
        string s;
        cin>>n>>k;
        cin>>s;
        ll dp[n+9];
        memset(dp,0,sizeof dp);
        ll I = -1;
        for(ll i = 0;i<n;i++)
        {
            if(s[i]=='*')
            {
                I = i;
                dp[i] = 1;
                break;
            }
        }
        ll ans = 1;

        for(ll i = 0;i<n;i++)
        {

            if(s[i]=='*')
            {
                I = i;
                dp[i] = 1;
                break;
            }

        }

        for(ll i = I+1;i<n;i++)
        {
            if(s[i]=='*')
            {
               ll miin = INT_MAX;
               for(ll j = 0,kk = i-1;j<k;j++,kk--)
               {
                   if(kk>=0 && s[kk]=='*')
                   {
                       miin = min(miin,dp[kk]);
                   }
               }
               dp[i] = miin+1;
               ans = dp[i];
            }
        }
        /*for(ll i = 0;i<n;i++)
        {
            cout<<dp[i]<<" ";
        }*/
        cout<<ans<<endl;
    }

    return 0;
}


