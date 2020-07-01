#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll M;
    cin>>M;

    ll arr[M];

    map<ll,ll> m;
    set<ll> s;
    for(ll i=0;i<M;i++)
    {
        cin>>arr[i];
        m[arr[i]]++;
        s.insert(arr[i]);
    }

    set<ll> :: iterator it;
    vector<ll> v;

    for( it = s.begin() ; it != s.end() ; it++ )
    {
        v.push_back(*it);
    }

 /*   for( ll i = 0;i<v.size();i++ )
    {
        cout<<v[i]<<" "<<m[v[i]]<<endl;
    }*/

    ll n = v.size();
    ll ans[n];

    if(n==1)
    {
        cout<<v[0]*m[v[0]]<<endl;
        return 0;
    }

    ans[0] = v[0]*m[v[0]];
    if(v[1]-1==v[0])
        ans[1] = v[1]*m[v[1]];
    else
        ans[1] = v[1]*m[v[1]] + ans[0];

    ll maax = ans[0];
    ll ans2 = max(ans[0],ans[1]);

    for(ll i=2,j = 1;i<n;i++,j++)
    {
        if(v[i]-1== v[i-1])
        {
            ans[i] = maax+ v[i]*m[v[i]];
            maax = max(maax,ans[j]);
            ans2 = max(ans2,ans[i]);
        }
        else
        {    maax = max(maax,ans[j]);
             ans[i] = maax+ v[i]*m[v[i]];
             ans2 = max(ans2,ans[i]);
        }
    }

    cout<<ans2<<endl;

    return 0;
}
