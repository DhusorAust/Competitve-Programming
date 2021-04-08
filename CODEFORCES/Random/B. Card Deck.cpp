#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
//priority_queue<int, vector<int>, greater<int> > min_q;
ll m[100009];
int main()
{
    FAST
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        for(ll i = 0;i<=n;i++)
        {
            m[i] = 0;
        }
        ll arr[n];
        priority_queue<ll> q;
        for(ll i = 0;i<n;i++)
        {
            cin>>arr[i];
            q.push(arr[i]);
        }
        ll i = n-1;
        while(!q.empty())
        {
            while(!q.empty())
            {
                ll a = q.top();
                q.pop();
                if(m[a]==0)
                {
                    stack<ll> s;
                    while(arr[i]!=a)
                    {
                        s.push(arr[i]);
                        m[arr[i]] = 1;
                        i--;
                    }
                    s.push(arr[i]);
                    m[arr[i]] = 1;
                    i--;
                    while(!s.empty())
                    {
                        cout<<s.top()<<" ";
                        s.pop();
                    }
                    break;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}

