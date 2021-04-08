#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
//priority_queue<int, vector<int>, greater<int> > min_q;
int main()
{
    FAST
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        ll m[n+9];
        memset(m, 0, sizeof m);
        for(ll i = 0;i<n;i++)
        {
            cin>>arr[i];
            m[arr[i]] = 1;
        }
        set<ll> s;
        for(ll i = 1;i<=n;i++)
        {
            if(m[i]==0)
                s.insert(i);
        }
        auto it = s.begin();
        for(ll i = 0;i<n;i++)
        {
            if(i==0)
            {
                cout<<arr[i]<<" ";
            }
            else if(arr[i]>arr[i-1])
            {
                cout<<arr[i]<<" ";
            }
            else
            {
                cout<<*it<<" ";
                it++;
            }
        }
        cout<<endl;
        for(ll i = 0;i<n;i++)
        {
            if(i==0)
            {
                cout<<arr[i]<<" ";
            }
            else if(arr[i]>arr[i-1])
            {
                cout<<arr[i]<<" ";
            }
            else
            {
                auto L = s.lower_bound(arr[i]);
                L--;
                cout<<*L<<" ";
                s.erase(L);
            }
        }
        cout<<endl;
    }
    return 0;
}
