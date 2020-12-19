#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
vector<ll> V[100009];
ll color[100009];
ll ans[100009];
ll ans2 = 1;
void DFS(ll u)
{
    color[u] = 1;
    ll mx = 0;
    for(ll i = 0;i<V[u].size();i++)
    {
        ll v = V[u][i];
        if(color[v]==0)
        {
            DFS(v);
        }
        mx = max(ans[v],mx);
    }
    ans[u] = mx+1;
    ans2 = max(ans2,ans[u]);
}
int main()
{
    FAST
    ll n, E;
    cin>>n>>E;
    for(ll i = 0;i<E;i++)
    {
        ll u, v;
        cin>>u>>v;
        V[u].push_back(v);
    }
    for(ll i = 1;i<=n;i++)
    {
        if(color[i]==0)
            DFS(i);
    }
    cout<<ans2-1<<endl;
    return 0;
}

