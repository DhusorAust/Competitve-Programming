#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,a,b,p,q;
    cin>>n>>a>>b>>p>>q;
    ll g = (a*b)/__gcd(a,b);
    ll A,B,G;
    A = n/a;
    B = n/b;
    G = n/g;
    A-=G;
    B-=G;
    ll ans = p*A+q*B+ G*(max(p,q));
    cout<<ans<<endl;
    return 0;
}
