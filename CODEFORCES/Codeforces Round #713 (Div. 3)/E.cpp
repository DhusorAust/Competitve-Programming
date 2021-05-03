#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fout freopen("output.txt","w",stdout)
#define fin  freopen("input.txt","r",stdin)
//priority_queue<int, vector<int>, greater<int> > min_q;
ll f(ll n, ll a)
{
    ll x = (((2*a)+(n-1))*n)/2;
    return x;
}
int main()
{
    FAST
    ll t;
    cin>>t;
    while(t--)
    {
        ll n, l , r, s;
        cin>>n>>l>>r>>s;
        ll k = r-l+1;
        ll mn = f(k,1);
        ll mx = f(k,n-k+1);
        if( !(s>=mn && s<=mx) )
        {
            cout<<-1<<endl;
            continue;
        }
        ll ans[k+9],arr[n+9], m[509];
        memset(m,0, sizeof m);
        for(ll i = 1;i<=k;i++)
            ans[i] = i;
        ll dorkar = s-mn;
        for(ll i = k,j=n;i>=1;i--,j--)
        {
            ll x = min(dorkar,j-i);
            ans[i]+=x;
            dorkar-=x;
        }
        for(ll i = 1;i<=k;i++)
            m[ans[i]] = 1;
        vector<ll> v;
        for(ll i = 1;i<=n;i++)
        {
            if(m[i]==0)
                v.push_back(i);
        }
        for(ll i = 1,x = 1, y = 0;i<=n;i++)
        {
            if(i>=l && i<=r)
            {
                arr[i] = ans[x];
                x++;
            }
            else
            {
                arr[i] = v[y];
                y++;
            }
        }
        for(ll i = 1;i<=n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}
