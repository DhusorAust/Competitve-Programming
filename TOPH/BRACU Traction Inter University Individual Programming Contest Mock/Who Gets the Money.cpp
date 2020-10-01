#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b);

ll power(ll x, ll y,  ll m);

ll modInverse(ll a, ll m)
{
    ll g = gcd(a, m);
    if (g != 1)
        return -1;
    else
    {
        return power(a, m-2, m);
    }
}

ll power(ll x,  ll y,  ll m)
{
    if (y == 0)
        return 1;
    ll p = power(x, y/2, m) % m;
    p = (p * p) % m;

    return (y%2 == 0)? p : (x * p) % m;
}


ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}


int main()
{

   ll n,p,r;
   cin>>n>>p>>r;


           ll tmp;
           if(n%2==0)
           {
                tmp = ((n/2)%p*(n+1)%p)%p;
           }
           else
           {
                tmp = ((n)%p*((n+1)/2)%p)%p;
           }


           ll tmp2 = (tmp*(2+(tmp-1)*2));
           tmp2 = (tmp2/2)%p;



          if(tmp2==r)
          {
              cout<<p-tmp2<<" "<<tmp2<<endl;
          }
          else
          {
              cout<<tmp2<<" "<<p-tmp2<<endl;
          }


  return 0;

}

