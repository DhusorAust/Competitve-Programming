#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);



int main()
{
    FAST
    ll n;
    cin>>n;

    string s;
    cin>>s;

    ll ans = INT_MAX;
    for(ll i = 0;i<n;i++)
    {
        ll cnt = 0;
        for(ll j = 0;j<n;j++)
        {
            if(i==j)
                continue;
            if(j>i && s[j]=='R')
                cnt++;
            if(j<i && s[j]=='L')
                cnt++;
        }
        ans = min(ans,cnt);
    }

    cout<<ans<<endl;

    return 0;
}

