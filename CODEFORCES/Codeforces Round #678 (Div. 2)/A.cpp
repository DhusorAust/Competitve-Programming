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

    int t;
    cin>>t;

    while(t--)
    {
        ll n, k;
        cin>>n>>k;

        ll arr[n];

        ll sum = 0;
        for(ll i = 0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }

        if(sum==k)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}

