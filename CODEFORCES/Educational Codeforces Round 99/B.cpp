#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
//priority_queue<int, vector<int>, greater<int> > min_q;
ll x;

ll f(ll n)
{
   return  (n*n-n)/2;
}


ll b(ll l, ll r)
{
      ll ans = -1;
      while (l <= r) {
        ll m = l + (r - l) / 2;

        if(f(m)<x)
        {
            l = m+1;

        }
        else
        {
            r = m-1;
            ans = m;
        }
    }

    return ans;
}
int main()
{
    FAST

    ll t;
    cin>>t;


    while(t--)
    {
        cin>>x;
        ll tmp = b(0,1000000);

        ll tmp2 = f(tmp);

        if(tmp2-x==1)
            cout<<tmp<<endl;
        else
            cout<<tmp-1<<endl;

    }


    return 0;
}

