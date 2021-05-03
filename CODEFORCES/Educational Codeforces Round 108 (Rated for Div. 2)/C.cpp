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

ll m[200009];
ll ans[200009];
ll sz[200009];


int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll n;
        cin>>n;
        for(ll i = 0;i<=n;i++)
        {
            m[i] = 0;
            ans[i] = 0;
        }
        ll arr1[n], arr2[n];
        vector<ll> v;
        vector<ll>V[n+5];
        for(ll i = 0;i<n;i++)
        {
            scanf("%lld",&arr1[i]);
            if(m[arr1[i]]==0)
            {
                v.push_back(arr1[i]);
                m[arr1[i]] = 1;
                sz[arr1[i]] = 0;
            }
        }
        for(ll i = 0;i<n;i++)
        {
            scanf("%lld",&arr2[i]);
            V[arr1[i]].push_back(arr2[i]);
            sz[arr1[i]]++;
        }
        ll x2 = v.size();
        for(ll i = 0;i<x2;i++)
        {
            sort(V[v[i]].begin(),V[v[i]].end(),greater<ll>());
        }

        for(ll i = 0;i<x2;i++)
        {
            ll x1 = sz[v[i]];
            for(ll j = 1;j<x1;j++)
            {
                  V[v[i]][j] += V[v[i]][j-1];
            }
        }
        for(ll j = 0;j<x2;j++)
        {
            ll sz1 = sz[v[j]];
            for(ll i = 1;i<=sz1;i++)
            {
                ll r = sz1-sz1%i-1;
                ans[i]+=V[v[j]][r];
            }
        }
        for(ll i =1;i<=n;i++)
        {
            printf("%lld ",ans[i]);
        }
        printf("\n");
    }

    return 0;
}


