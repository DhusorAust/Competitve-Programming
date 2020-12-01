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
        ll n, x;
        cin>>n>>x;

        ll arr[n];

        for(ll i = 0;i<n;i++)
        {
            cin>>arr[i];
        }

        ll cnt = 0;
        ll ans = -1;
        for(ll i = 0;i<n;i++)
        {
            bool bol = true;
            for(ll j = 0;j<n-1;j++)
            {
                if(arr[j+1]<arr[j])
                {
                    bol = false;
                    break;
                }
            }
            if(bol)
            {
                ans = cnt;
                break;
            }

            if(arr[i]>x)
            {
                swap(x,arr[i]);
                cnt++;
            }
        }

        bool bol = true;
        for(ll j = 0;j<n-1;j++)
        {
            if(arr[j+1]<arr[j])
            {
                bol = false;
                break;
            }
        }
        if(bol)
        {
            ans = cnt;
        }

        cout<<ans<<endl;
    }

    return 0;
}

