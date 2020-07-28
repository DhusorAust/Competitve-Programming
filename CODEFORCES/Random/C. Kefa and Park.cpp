#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

ll n,m;
ll arr[200009];
ll p[200009];
ll cat[200009];

vector <ll> V[200009];
ll color[200009];

queue <ll > q;

void BFS(ll s)
{
    color[s] = 1;
    q.push(s);

    while(!q.empty())
    {
        ll u = q.front();
        q.pop();

        for(ll i=0;i<V[u].size();i++)
        {
            ll v = V[u][i];
            if(color[v]==0)
            {
                q.push(v);
                color[v] = 1;
                if(arr[v]==1)
                {
                    p[v]=p[u]+1;
                }
                else
                {
                    p[v] = 0;
                }
                if(p[v]>m)
                    cat[v] = 1;

                cat[v]+=cat[u];
            }
        }
    }
}

int  main()
{
    FAST

    cin>>n>>m;

    for(ll i = 1;i<=n;i++)
    {
        cin>>arr[i];
    }

    for(ll i = 0;i<n-1;i++)
    {
        ll u,v;
        cin>>u>>v;

        V[u].push_back(v);
        V[v].push_back(u);
    }

    if(arr[1]==1)
        p[1] = 1;
    BFS(1);



    ll cnt = 0;
    for(ll i = 2;i<=n;i++)
    {
        if(V[i].size()==1 && cat[i]==0)
            cnt++;
    }
    cout<<cnt<<endl;


    return 0;
}

