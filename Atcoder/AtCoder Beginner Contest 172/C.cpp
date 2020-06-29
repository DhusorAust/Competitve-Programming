#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> v,v1;
    v.push_back(0);
    v1.push_back(0);
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;

        v.push_back(x);
    }
    for(int i=0;i<m;i++)
    {
        ll x;
        cin>>x;

        v1.push_back(x);
    }
    for(int i=1;i<v.size();i++)
    {
        v[i] +=v[i-1];
    }

    for(int i=1;i<v1.size();i++)
    {
        v1[i] +=v1[i-1];
    }

    ll ans = 0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]<=k)
        {
            ll temp = k-v[i];

            ll pos = upper_bound(v1.begin(),v1.end(),temp) - v1.begin();

            ans = max(ans,pos+i-1);
            continue;
        }
        break;
    }
    cout<<ans<<endl;
    return 0;
}
