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

struct node
{
    ll v, i;
};
bool cmp(node a, node b)
{
    return a.v<b.v;
}
int main()
{
    FAST

    ll t;
    cin>>t;
    while(t--)
    {
        ll n, m, x;
        cin>>n>>m>>x;
        node arr[n];
        for(ll i = 0;i<n;i++)
        {
            cin>>arr[i].v;
            arr[i].i = i;
        }
        sort(arr,arr+n,cmp);
        ll ans[n];
        ll j = 1;
        for(ll i = 0;i<n;i++)
        {
            ans[arr[i].i] = j;
            j++;
            if(j>m)
                j = 1;
        }
        cout<<"YES"<<endl;
        for(ll i =0 ;i<n;i++)
        {
            cout<<ans[i]<<" ";
        }
            cout<<endl;

    }

    return 0;
}

