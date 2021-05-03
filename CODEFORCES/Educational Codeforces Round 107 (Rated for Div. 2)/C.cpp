#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fout freopen("output.txt","w",stdout)
#define fin  freopen("input.txt","r",stdin)
ll m[60];
int main()
{
    FAST
    ll n, q;
    cin>>n>>q;
    ll arr[n];
    for(ll i = 0;i<n;i++)
    {
        cin>>arr[i];
        if(m[arr[i]]==0)
           m[arr[i]] = i+1;
    }
    while(q--)
    {
        ll x;
        cin>>x;
        cout<<m[x]<<" ";
        for(ll i = 1;i<=50;i++)
        {
            if(m[i]<m[x])
                m[i]++;
        }
        m[x] = 1;
    }
    cout<<endl;
    return 0;
}
