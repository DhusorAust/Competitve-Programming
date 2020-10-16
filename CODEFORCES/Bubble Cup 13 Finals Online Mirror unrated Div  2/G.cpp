#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

int main()
{
    FAST
    ll n;
    cin>>n;
    map <ll,ll> m,m2;
    for(ll i=0;i<n;i++)
    {
        ll b,d;
        cin>>b>>d;
        m[b]++;
        m[d]--;
    }
    map<ll,ll> :: iterator it;
    ll i = 0;
    vector<ll> v;
    for(it = m.begin();it!=m.end();it++,i++)
    {
        v.push_back(it->second);
        m2[i] = it->first;
    }
    for(ll i=1;i<v.size();i++)
        v[i]+=v[i-1];
    ll maax= -100000000000000;
    ll year;
    for(ll i=0;i<v.size();i++)
    {
        if(v[i]>maax)
        {
            maax = v[i];
            year = m2[i];
        }
    }
    cout<<year<<" "<<maax<<endl;
    return 0;
}

