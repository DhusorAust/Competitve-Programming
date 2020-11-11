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

    ll n;
    cin>>n;

    priority_queue<ll> q;

    for(ll i = 1;i<=n;i++)
    {
        q.push(i);
    }

    vector<pair <ll, ll> > v;
    while(q.size()>=2)
    {
        ll a = q.top();
        q.pop();
        ll b = q.top();
        q.pop();
        //cout<<a<<" "<<b<<endl;
        v.push_back(make_pair(a,b));
        ll c = (a+b)/2;
        if((a+b)%2!=0)
            c++;
        q.push(c);
    }

    cout<<q.top()<<endl;
    for(ll i = 0;i<v.size();i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }

    return 0;
}

