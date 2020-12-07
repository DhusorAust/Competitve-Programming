#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

ll arr[200009];


ll diff(ll i, ll j)
{
    return abs(arr[i]-arr[j]);
}

ll calc(ll i)
{
    ll sum = 0;

    sum+= diff(i,i-1);
    sum+= diff(i,i+1);

    return sum;
}

int main()
{
    FAST

    ll t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;

        for(ll i = 0;i<n;i++)
        {
            cin>>arr[i];
        }

        ll sum = 0;

        for(ll i = 1;i<n;i++)
        {
            sum+=diff(i,i-1);
        }

      //  cout<<sum<<endl;

        ll miin = sum;

        for(ll i = 1;i<n-1;i++)
        {
            ll store = arr[i];
            //cout<<calc(i)<<endl;
            ll rem = sum-calc(i);
            ll now = rem;
           // cout<<rem<<endl;
            arr[i] = arr[i-1];
            now+=calc(i);
            //cout<<now<<endl;
            miin = min(miin, now);

            now = rem;
            arr[i] = arr[i+1];

           /* for(ll i = 0;i<n;i++)
            {
                cout<<arr[i]<<" ";
            }
           cout<<endl;*/
            now+=calc(i);
            //cout<<now<<endl;
            miin = min(miin, now);
            arr[i] = store;
        }

        ll rem = sum-abs(arr[0]-arr[1]);
        miin = min(rem,miin);

        rem = sum-abs(arr[n-1]-arr[n-2]);
        miin = min(rem,miin);

        cout<<miin<<endl;

    }

    return 0;
}
