#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

vector<ll> V[100009];
ll color[100009];

ll P[100009];
ll H[100009];

bool isValid(ll p, ll h)
{
    if((p+h)%2==0)
        return true;

    return false;
}

ll calcA(ll p, ll h)
{
    return (p+h)/2;
}

bool bol = true;

ll DFS(ll u)
{
    color[u] = 1;
    ll sum = 0;

    for(ll i=0;i<V[u].size();i++)
    {
        ll v = V[u][i];
        if(color[v]==0)
        {
            sum+=DFS(v);
            P[u]+=P[v];
        }
    }
    ll A = calcA(P[u],H[u]);

    if(isValid(P[u],H[u]) && A>=0 && A<=P[u] && sum<=A);
    else
        bol = false;

    return A;
}

int main()
{
    FAST

    ll t;
    cin>>t;

    while(t--)
    {
        ll n,m;
        cin>>n>>m;

        bol = true;

        for(ll i = 1;i<=n;i++)
        {
            V[i].clear();
            color[i] = 0;
        }

        for(ll i = 1;i<=n;i++)
            cin>>P[i];

        for(ll i = 1;i<=n;i++)
            cin>>H[i];

        for(ll i = 0;i<n-1;i++)
        {
            ll u,v;
            cin>>u>>v;

            V[u].push_back(v);
            V[v].push_back(u);
        }

        P[0] = 0; DFS(1);

        if(bol)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
