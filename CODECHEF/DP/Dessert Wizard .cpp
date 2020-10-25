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
        ll n;
        cin>>n;

        ll arr[n],leftmax[n],leftmin[n],rightmax[n],rightmin[n];

        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        leftmax[0] = arr[0];
        leftmin[0] = arr[0];

        for(ll i=1;i<n;i++)
        {
            leftmax[i] = max(leftmax[i-1]+arr[i],arr[i]);
            leftmin[i] = min(leftmin[i-1]+arr[i],arr[i]);
        }

        rightmax[n-1] = arr[n-1];
        rightmin[n-1] = arr[n-1];
        for(ll i=1,j=n-2;i<n;i++,j--)
        {
            leftmax[i] = max(leftmax[i-1]+arr[i],arr[i]);
            leftmin[i] = min(leftmin[i-1]+arr[i],arr[i]);

            rightmax[j] = max(rightmax[j+1]+arr[j],arr[j]);
            rightmin[j] = min(rightmin[j+1]+arr[j],arr[j]);
        }
        ll ans = -1;
        for(ll i=0;i<n-1;i++)
        {
            ll a = abs(leftmax[i]-rightmin[i+1]);
            ll b = abs(leftmin[i]-rightmax[i+1]);
            ll c = max(a,b);
            ans = max(ans,c);
        }
        cout<<ans<<endl;
    }

    return 0;
}



