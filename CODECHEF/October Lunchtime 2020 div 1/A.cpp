#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);



int main()
{
    FAST

    ll t;
    cin>>t;

    while(t--)
    {
        ll n, q;
        cin>>n>>q;

        ll arr[n];
        ll dp[n];

        for(ll i = 0;i<n;i++)
        {
            cin>>arr[i];
        }

        while(q--)
        {
            ll x, y;
            cin>>x>>y;
            arr[x-1] = y;
            for(ll i = 0;i<n;i++)
            {
                dp[i] = 1;
            }

            for(ll i = n-2;i>=0;i--)
            {
                if(arr[i]==arr[i+1])
                    dp[i]=dp[i+1];
                else
                    dp[i] = 1+dp[i+1];
            }

           /* for(int i=0;i<n;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;

            for(int i=0;i<n;i++)
            {
                cout<<dp[i]<<" ";
            }
            cout<<endl;*/

            cout<<dp[0]<<endl;


        }





    }

    return 0;
}

