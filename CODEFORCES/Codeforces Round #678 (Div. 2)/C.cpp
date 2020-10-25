#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

#define mod 1000000007
ll n, x,x2, pos;
ll val(ll i)
{
    return i+1;
}
ll grt,sml;
vector<ll> vg,vs;
bool f()
{
    ll left  = 0;
    ll right = n;

    while(left<right)
    {
        ll m = (left+right)/2;
        if(val(m)<=x2)
        {
            if(val(m)!=x2)
                sml++;
            left = m+1;
            if(val(m)!=x2)
            vs.push_back(val(m));
        }
        else
        {
            grt++;
            right = m;
            vg.push_back(val(m));
        }
    }
    if(left>0 && val(left-1)==x2)
        return true;
    else
        return false;
}

int main()
{
    FAST

    ll fct[1009];

    fct[0] = 1;
    fct[1] = 1;
    for(ll i = 2;i<=1000;i++)
    {
        fct[i] = (fct[i-1]%mod*i%mod)%mod;
    }

   // cout<<fct[9]<<endl;

    cin>>n>>x>>pos;
    x2 = val(pos);
    bool a = f();
    //cout<<sml<<" "<<grt<<endl;


    ll smlhave,grthave;
    smlhave = x-1;
    grthave = n-x;

   // cout<<smlhave<<" "<<grthave<<endl;



    ll rem = n-sml-grt-1;

    ll fac1= 1, fac2 = 1;

    for(ll i = 0, j = smlhave;i<sml;i++,j--)
    {
        fac1 = (fac1%mod*j%mod)%mod;
    }


    for(ll i = 0, j = grthave;i<grt;i++,j--)
    {
        fac2 = (fac2%mod*j%mod)%mod;
    }

   // cout<<fac1<<" "<<fac2<<" "<<fct[rem]<<endl;

    ll ans = (fct[rem]%mod*fac1%mod)%mod;
    ans = (ans%mod*fac2%mod)%mod;
    cout<<ans<<endl;





    return 0;
}

