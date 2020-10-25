#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

string s;
#define mod 1000000007

ll f(ll i, ll sum)
{
    if(i==s.size())
        return 0;
    ll b = 0,c = 0;
    b = f(i+1,sum);
    sum*=10;
    ll a = (sum%mod+(s[i]-48)%mod)%mod;
    c = f(i+1,a);
    return a+b+c;
}

int main()
{
    FAST

    cin>>s;
    ll val = 0;
    ll n = s.size();
    ll k = 1;
    for(int i=n-1;i>=0;i--)
    {
        val+=((s[i]-48)%mod*k%mod)%mod;
        k = k*10;
        k = k%mod;
    }
    ll ans = f(0,0)-val;
    ans%=mod;

    cout<<ans<<endl;

    return 0;
}

