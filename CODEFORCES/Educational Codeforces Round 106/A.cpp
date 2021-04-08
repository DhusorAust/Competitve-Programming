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
       ll n, k1, k2;
       cin>>n>>k1>>k2;
       ll w, b;
       cin>>w>>b;

       ll mn1 = min(k1,k2);
       ll mn2 = min(n-k1,n-k2);

       ll x = max(k1,k2)-min(k1,k2);

       ll y = x/2;

       if(w<=mn1+y && b<=mn2+y)
          cout<<"yes"<<endl;
       else
        cout<<"no"<<endl;

    }

    return 0;
}

