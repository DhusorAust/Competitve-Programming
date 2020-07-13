
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


vector<ll> z_function(string s) {
    ll n = (ll) s.length();
    vector<ll> z(n);
    z[0] = n;
    for (ll i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

ll modInv(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {

        ll q = a / m;
        ll t = m;

        m = a % m, a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
       x += m0;

    return x;
}


int main()
{

    ll t;
    cin>>t;

    while(t--)
    {
        string s;
        cin>>s;

        ll arr[26];

        for(ll i=0;i<26;i++)
        {
            cin>>arr[i];
        }

        ll n = s.length();

        vector<string> v;

        for(ll j = n-1;j>=0;j--)
        {
            for(ll i=0;i<=j;i++)
            {
                string tmp;
                tmp = s.substr(i,j-i+1);
                v.push_back(tmp);
            }
        }

        vector<string> v2;
        for(ll i=0;i<v.size();i++)
        {
            vector <ll> z = z_function(v[i]);
            for(ll j=0;j<z.size();j++)
            {
               if(z[j]!=0 && j+z[j]==z.size())
               {
                   string tmp;
                   if(j!=0)
                        tmp = v[i].substr(0,j);
                   else
                        tmp = v[i].substr(0,v[i].size());
                   v2.push_back(tmp);
               }
            }
        }

        ll sum = 0;

        for(ll i = 0;i<v2.size();i++)
        {
            for(ll j = 0;j<v2[i].size();j++)
            {
                sum+=arr[v2[i][j]-97];
            }
        }
      ll m = 998244353;
      ll a = v.size();
      ll tmp = modInv(a, m);
      sum = sum%m;
      ll ans = (sum*tmp)%m;
      cout<<ans<<endl;
    }
    return 0;
}
