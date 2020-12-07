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
        ll n, m;
        cin>>n>>m;

        ll arr1[n], arr2[m];

        map<ll,ll> M;
        for(ll i = 0;i<n;i++)
        {
            cin>>arr1[i];
            M[arr1[i]]++;
        }

        ll cnt = 0;
        for(ll i = 0;i<m;i++)
        {
            cin>>arr2[i];
            if(M[arr2[i]]!=0)
                cnt++;
        }

        cout<<cnt<<endl;
    }

    return 0;
}

