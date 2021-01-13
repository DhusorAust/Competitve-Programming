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
    ll n, m;
    cin>>n>>m;
    cout<<min(n,m)+1<<endl;
    for(ll i = 0, j = m;i<=n && j>=0;i++,j--)
    {
        cout<<i<<" "<<j<<endl;
    }
    return 0;
}

