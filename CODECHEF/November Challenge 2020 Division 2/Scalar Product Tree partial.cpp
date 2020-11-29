#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef unsigned long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

#define mod 4294967296

vector <ll> V[300009];
ll color[300009];
ll parent[300009];
ll arr[300009];
ll prod[300009];

//queue <ll > q;
/*void BFS(ll s)
{
    color[s] = 1;
    q.push(s);
    while(!q.empty())
    {
        ll u = q.front();
        q.pop();

        ll v;
        for(ll i=0;i<V[u].size();i++)
        {
            v = V[u][i];
            if(color[v]==0)
            {
                parent[v] = u;
                q.push(v);
                color[v] = 1;
            }
        }
    }
}*/

void DFS(ll u)
{
    color[u] = 1;

    ll v;

    for(ll i=0;i<V[u].size();i++)
    {
        v = V[u][i];
        if(color[v]==0)
        {
            parent[v]=u;
            ll tmp = (arr[v]%mod*arr[v]%mod)%mod;
            prod[v] = (tmp%mod+prod[u]%mod)%mod;
            DFS(v);
        }

    }

    color[u] = 2;
   // cout<<u<<" ";
}


int main()
{
//    FAST

    ll n, q;
   // cin>>n>>q;
   scanf("%llu%llu",&n,&q);

    for(ll i = 1;i<=n;i++)
    {
        //cin>>arr[i];
        scanf("%llu",&arr[i]);
    }

    for(ll i = 0;i<n-1;i++)
    {
            ll u, v;
           // cin>>u>>v;
            scanf("%llu%llu",&u,&v);
            V[u].push_back(v);
            V[v].push_back(u);
    }
    prod[1] = (arr[1]%mod*arr[1]%mod)%mod;
    parent[1]= -1;
    DFS(1);
  /*  for(int i=1;i<=n;i++)
    {
        cout<<prod[i]<<" ";
    }
    cout<<endl;*/

    while(q--)
    {
        ll u, v;
        ll ans = 0;
        //cin>>u>>v;
        scanf("%llu%llu",&u,&v);

        while(u!=-1)
        {
            if(u==v)
            {  // cout<<"eta "<<ans<<" "<<prod[u]<<endl;
                ans= (ans%mod + prod[u]%mod)%mod;
                break;
            }
            ll tmp = (arr[u]%mod*arr[v]%mod)%mod;
            ans = (ans%mod+ tmp%mod)%mod;
            u = parent[u];
            v = parent[v];
        }

        //cout<<ans<<endl;
        printf("%llu\n",ans);
    }


    return 0;
}

