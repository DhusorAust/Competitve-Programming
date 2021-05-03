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


int main()
{
    FAST
    vector<ll> v;
    ll a = 2050;
    for(;a<=1000000000000000000;)
    {
        v.push_back(a);
        a*=10;
    }


    ll t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;
        ll m =v.size();
        ll sum = 0;
        for(ll i = m-1;i>=0;i--)
        {
            sum+=n/v[i];
            n%=v[i];
        }
        if(n!=0)
            cout<<-1<<endl;
        else
            cout<<sum<<endl;
    }

    return 0;
}

