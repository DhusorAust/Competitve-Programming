
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

ll n, wt;
vector<ll> v;
ll prex[202];
ll dp[202][10002];
ll parent[202][10002];

ll f(ll i, ll w)
{
    if(dp[i][w]!=-1)
        return dp[i][w];
    if(i==n)
       return dp[i][w] = w;
    ll a = INT_MIN, b = 0;
    if(w+v[i]<=wt)
        a = f(i+1,w+v[i]);
    if( prex[i]-w <= wt)
         b = f(i+1,w);
    if(a>b)
        parent[i][w] = 1;
    return dp[i][w] = max(max(a,b),w);
}

string ans[202];
void path(ll i, ll w)
{
    if(i==n)
        return;
    if(parent[i][w]==1)
    {
        ans[i] = "port";
        path(i+1,v[i]+w);
    }
    else
        path(i+1,w);
}

int main()
{
    FAST
    ll t;
    cin>>t;
    while(t--)
    {
        v.clear();
        memset(prex,0, sizeof prex);
        for(ll i = 0;i<202;i++)
            ans[i] = "starboard";
        cin>>wt;
        wt*=100;
        v.push_back(0);
        ll tot = 0;
        while(true)
        {
            ll x;
            cin>>x;
            if(x==0)
                break;
            tot+=x;
            if(tot<=2*wt)
                v.push_back(x);
        }
        n = v.size();
        for(ll i = 1;i<n;i++)
            prex[i] = prex[i-1]+v[i];
        memset(dp, -1 , sizeof dp);
        memset(parent, -1, sizeof parent);
        ll x = f(1,0);
        path(1,0);
        ll sum = 0;
        ll cnt = 0;
        for(ll i = 1;i<n;i++)
        {
            if(ans[i]=="starboard")
                sum += v[i];
            if(sum>wt)
                break;
            cnt++;
        }
        cout<<cnt<<endl;
        for(ll i = 1;i<=cnt;i++)
            cout<<ans[i]<<endl;
        if(t!=0)
            cout<<endl;
    }
    return 0;
}

