#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector <ll> V[200009],ans;
ll color[200009];
ll flag[200009];

void DFS(ll u)
{
    color[u] = 1;

    ll n = V[u].size();
    for(ll i=n-1;i>=0;i--)
    {
        ll v = V[u][i];
        if(color[v]==0)
            DFS(v);
    }
    ans.push_back(u);
}

void topologicalSort(ll n)
{
    ans.clear();
    for(ll i=n;i>=1;i--)
    {
        if(color[i]==0)
            DFS(i);
    }
    reverse(ans.begin(),ans.end());
}

int main()

{
    ll n;
    cin>>n;

    ll A[n+1];
    ll B[n+1];

    for(ll i = 1;i<=n;i++)
    {
        cin>>A[i];
    }

    for(ll i = 1;i<=n;i++)
    {
        cin>>B[i];
    }

    for(ll i = 1;i<=n;i++)
    {
        if(B[i]!=-1)
        V[i].push_back(B[i]);
    }

    topologicalSort(n);

    ll sum = 0;
    vector<ll> ans2;
    for(ll i=0;i<n;i++)
    {
        ll I = ans[i];
        if(A[I]>0 && flag[I]==0)
        {
            sum+=A[I];
            A[B[I]]+=A[I];
            flag[I] = 1;
            ans2.push_back(I);
        }
    }

    for(ll i=n-1;i>=0;i--)
    {
        ll I = ans[i];
        if(flag[I]==0)
        {
            sum+=A[I];
            flag[I] = 1;
            ans2.push_back(I);
        }
    }

    cout<<sum<<endl;

    for(ll i = 0;i<n;i++)
    {
        cout<<ans2[i]<<" ";
    }

    cout<<endl;

    return 0;
}
