#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> V[200009],vv;
ll color[200009];
ll color2[200009];
ll cnt = 0;
queue <ll> q;
struct node
{
    ll A,B;
};
bool cmp(node a, node b)
{
    return a.A*b.B>b.A*a.B;
}
void BFS(int s)
{
    color[s] = 1;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        cnt++;
        int v;
        for(int i=0;i<V[u].size();i++)
        {
            v = V[u][i];
            if(color[v]==0)
            {
                q.push(v);
                color[v] = 1;
            }
        }
    }
}
void BFS2(int s)
{
    color2[s] = 1;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vv.push_back(u);
        int v;
        for(int i=0;i<V[u].size();i++)
        {
            v = V[u][i];
            if(color2[v]==0)
            {
                q.push(v);
                color2[v] = 1;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vv.clear();
        for(ll i=1;i<=n;i++)
        {
            color[i] = 0;
            color2[i] = 0;
            V[i].clear();
        }
        node arr[n+1],arr2[n+1];
        ll hor = 1;
        for(ll i=1;i<=n;i++)
        {
            cin>>arr[i].A;
        }
        for(ll i=1;i<=n;i++)
        {
            cin>>arr[i].B;
            arr2[i] = arr[i];
        }
        sort(arr+1,arr+n+1,cmp);
        node maax = arr[1];
        ll theka;
        map<ll,ll>mp;
        ll theka2 = 0;
        while(m--)
        {
            ll u,v;
            cin>>u>>v;
            if(arr2[u].A*maax.B==maax.A*arr2[u].B && arr2[v].A*maax.B==maax.A*arr2[v].B)
            {
                theka2++;
                V[u].push_back(v);
                V[v].push_back(u);
                mp[u] = 1;
                mp[v] = 1;
            }
        }
        if(theka2==0)
        {
            cout<<1<<endl;
            cout<<theka<<endl;
            continue;
        }
        ll ans1 = -100000000000,ans2 = 0;
        for(ll i=1;i<=n;i++)
        {
            if(color[i]==0 && mp[i]==1)
            {
                cnt = 0;
                BFS(i);
                if(cnt>ans1)
                {
                    ans1 = cnt;
                    ans2 = i;
                }
            }

        }
        BFS2(ans2);
        cout<<ans1<<endl;
        for(ll i=0;i<vv.size()-1;i++)
            cout<<vv[i]<<" ";
        cout<<vv[vv.size()-1]<<endl;
    }
    return 0;
}

