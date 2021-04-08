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
        ll n, u, v;
        cin>>n>>u>>v;
        set<ll> s;
        ll a[n];
        for(ll i = 0;i<n;i++)
        {
            cin>>a[i];
            s.insert(a[i]);
        }
        if(s.size()==1)
        {
            cout<<v+min(u,v)<<endl;
            continue;
        }
        bool bol = false;
        for(ll i = 1;i<n;i++)
        {
            if( abs(a[i-1]-a[i])>=2)
            {
                bol = true;
                break;
            }

        }
        if(bol)
        {
            cout<<0<<endl;
            continue;
        }
        cout<<min(u,v)<<endl;
    }


    return 0;
}

