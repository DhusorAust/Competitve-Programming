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
void f(vector<ll>& v1, vector<ll>&v2,ll n1, ll n2,ll l, ll r,long long* m1, long long*m2)
{
    for(ll i = 0;i<n1;i++)
    {
        ll x = min(m1[v1[i]],m2[v1[i]]);
        m1[v1[i]]-=x;
    }
    ll diff = l-r;
    ll x = diff/2;
    ll cost = 0;
    for(ll i = 0;i<n1;i++)
    {
        ll y = m1[v1[i]]/2;
        ll z = min(y,x);
        x-=z;
        cost+=z;
        m1[v1[i]]-=2*z;

    }
    ll sum = 0;
    for(ll i = 0;i<n1;i++)
        sum+=m1[v1[i]];
    cout<<sum+cost<<endl;
}
int main()
{
    FAST
    ll t;
    cin>>t;
    while(t--)
    {
        ll n, l, r;
        cin>>n>>l>>r;
        ll m1[n+5],m2[n+5];
        for(ll i = 0;i<=n;i++)
        {
            m1[i] = 0;
            m2[i] = 0;
        }
        ll arr[n];
        vector<ll> v1, v2;
        for(ll i = 0;i<n;i++)
            cin>>arr[i];
        for(ll i = 0;i<l;i++)
        {
            if(m1[arr[i]]==0)
                v1.push_back(arr[i]);
            m1[arr[i]]++;
        }
        for(ll i = l;i<n;i++)
        {
            if(m2[arr[i]]==0)
                v2.push_back(arr[i]);
            m2[arr[i]]++;
        }
        ll n1, n2;
        n1 = v1.size();
        n2 = v2.size();
        if(l>=r)
            f(v1,v2,n1,n2,l,r,m1,m2);
        else
            f(v2,v1,n2,n1,r,l,m2,m1);
    }

    return 0;
}


