#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;



int main()
{


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
        ll cnt = 1;
        for(ll i = 1;i<n;i++)
        {
            if(arr[i]!=arr[i-1])
                break;
            cnt++;
        }

        cout<<n-cnt<<endl;
    }


    return 0;
}

