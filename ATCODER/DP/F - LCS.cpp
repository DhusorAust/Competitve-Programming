#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

string s1, s2;
ll n, m;

ll dp[3005][3005];
ll p[3005][3005];

ll f(ll i, ll j)
{
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(i==n || j==m)
        return dp[i][j] = 0;
    ll a, b;
    if(s1[i]==s2[j])
    {
        a = f(i+1,j+1);
        p[i][j] = 2;
        return dp[i][j] = a+1;
    }
    a = f(i+1,j);
    b = f(i,j+1);
    if(a>=b)
        p[i][j] = 1;
    else
        p[i][j] = 0;

    return dp[i][j] = max(a,b);
}

void path(ll i, ll j)
{
    if(i==n || j==m)
        return;
    if(p[i][j]==2)
    {
       // cout<<i<<","<<j<<endl;
        cout<<s1[i];
        path(i+1,j+1);
        return ;
    }
    if(p[i][j]==1)
    {
        path(i+1,j);
        return ;
    }
    else if(p[i][j]==0)
    {
        path(i,j+1);
        return;
    }

}

int main()
{
    FAST
    cin>>s1>>s2;
    n = s1.size();
    m = s2.size();
    memset(dp, -1, sizeof dp);
    memset(p, -1, sizeof p);
    ll x = f(0,0);
    /*for(ll i = 0;i<n;i++)
    {
        for(ll j = 0;j<m;j++)
        {
            cout<<p[i][j]<<"\t";
        }
        cout<<endl;
    }*/
    path(0,0);
    cout<<endl;
    return 0;
}

