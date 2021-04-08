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
        ll arr[n];
        for(ll i = 0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        vector<ll> v;
        for(ll i = 0;i<n;i++)
        {
            if(i!=0 && arr[i-1]==arr[i])
                v.push_back(arr[i]);
            else
                cout<<arr[i]<<" ";
        }
        for(ll i = 0;i<v.size();i++)
        {

                cout<<v[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

