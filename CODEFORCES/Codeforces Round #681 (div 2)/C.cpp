#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

struct node
{
    ll a, b;
};

bool operator<(node a, node b)
{
    return a.a<b.a;
}
int main()
{
    FAST

    ll t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;

        node arr[n];

        for(ll i = 0;i<n;i++)
        {
            cin>>arr[i].a;
        }
        for(ll i = 0;i<n;i++)
        {
            cin>>arr[i].b;
        }
        priority_queue<node> q;

        for(ll i = 0;i<n;i++)
        {
           q.push(arr[i]);
        }

        ll sum = 0;

        while(!q.empty())
        {
            node A = q.top();
            q.pop();

            if(sum+A.b<=A.a)
                sum+=A.b;
            else
            {
                q.push(A);
                break;
            }
        }
        ll x = 0;
        if(!q.empty())
            x = q.top().a;
        cout<<max(x,sum)<<endl;
    }

    return 0;
}

