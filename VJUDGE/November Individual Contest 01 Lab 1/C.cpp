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
    ll n,k;
    cin>>n>>k;

    ll arr[n];

    for(ll i = 0;i<n;i++)
    {
        cin>>arr[i];
    }

    sort(arr,arr+n);

    ll sum = arr[n-1];

    for(ll i = 0,j = n-2;i<k;i++,j--)
    {
        sum+=arr[j];
    }

        cout<<sum<<endl;
    return 0;
}

