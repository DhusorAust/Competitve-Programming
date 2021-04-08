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
        map<ll,ll> m;
        set<ll> s;
        priority_queue<ll> q;
        for(ll i = 0;i<n;i++)
        {
            cin>>arr[i];
            m[arr[i]]++;
            s.insert(arr[i]);
        }

        for(auto a = s.begin();a!=s.end();a++)
        {
            q.push(m[*a]);
        }
        ll cnt = 0;
        while(!q.empty())
        {
            if(q.size()==1)
                break;
            ll a = q.top();
            q.pop();
            ll b = q.top();
            q.pop();
            a--;
            b--;
            if(a!=0)
                q.push(a);
            if(b!=0)
                q.push(b);
            cnt+=2;
        }
        cout<<n-cnt<<endl;
    }

    return 0;
}


