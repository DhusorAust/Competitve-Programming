#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
#define pb push_back
#define maax 1000000000000000000
int main()
{
    FAST
    int t;
    cin>>t;

    vector<ll> v;
    v.pb(1);

    for(ll i = 2;i<=maax;i*=2)
        v.pb(i);

    for(ll i = 1;i<v.size();i++)
        v[i]+=v[i-1];

    while(t--)
    {
       ll n;
       cin>>n;
       vector<ll> v2;

       while(n!=0)
       {
           v2.pb(n%2);
           n/=2;
       }

       ll sum = 0;

       for(ll i = 0;i<v2.size();i++)
       {
          if(v2[i]==1)
            sum+=v[i];
       }

       cout<<sum<<endl;
    }
    return 0;
}

