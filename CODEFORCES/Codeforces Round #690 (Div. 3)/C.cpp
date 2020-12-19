#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
string inf  = "9999999999";
char c(ll i)
{
    return i+49;
}
ll n;
vector<ll> v;
ll f2(string s)
{
    ll sum = 0;
    ll m = s.size();
    ll tmp = 1;
    for(ll i = m-1;i>=0;i--)
    {
        sum+=tmp*(s[i]-48);
        tmp*=10;
    }
    return sum;
}
string f(ll i, ll sum, string s )
{
    if(i==10)
    {
        if(sum==n)
            return  s;
        else
            return inf;
    }
    string a = inf, b;

    b = f(i+1, sum, s);
    if(sum+v[i]<=n)
    {
       s.push_back(c(i));
       a =  f(i+1,sum+v[i],s);
    }
    string x = inf;
    if(sum==n)
         x = s;
    if(f2(x)<=f2(a) && f2(x)<=f2(b))
        return  x;
    if(f2(a)<=f2(x) && f2(a)<=f2(b))
        return  a;
    return  b;
}

int main()
{
    FAST
    for(ll i = 1;i<=9;i++)
    {
        v.push_back(i);
    }
    ll t;
    cin>>t;
    while(t--)
    {
       cin>>n;
       string s = "";
       string ans = f(0,0,s);
       if(ans==inf)
            cout<<-1<<endl;
       else
            cout<<ans<<endl;
    }

    return 0;
}

