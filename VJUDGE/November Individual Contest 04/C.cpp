#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

#define mod 1000000007

vector <int> V[100009];

int color[100009];

ll cnt;

void DFS(int u)
{
    color[u] = 1;
    cnt++;

    int v;

    for(int i=0;i<V[u].size();i++)
    {
        v = V[u][i];
        if(color[v]==0)
            DFS(v);
    }

    //color[u] = 2;
   // cout<<u<<" ";
}


int main()
{
    FAST

    ll t;
    cin>>t;

    while(t--)
    {
        ll n, m;
        cin>>n>>m;

        for(ll i = 0 ;i<=n;i++)
        {
            V[i].clear();
            color[i] = 0;
        }

        for(ll i = 0;i<m;i++)
        {
            ll u, v;
            cin>>u>>v;

            V[u].push_back(v);
            V[v].push_back(u);

        }

        ll cnt2 = 0;
        ll ans = 1;
        for(ll i = 1;i<=n;i++)
        {
            if(color[i]==0)
            {
                cnt = 0;
                DFS(i);
                cnt2++;
                ans = (ans%mod*cnt%mod)%mod;
            }

        }

        cout<<cnt2<<" "<<ans<<endl;
    }

    return 0;
}

