#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
//priority_queue<int, vector<int>, greater<int> > min_q;


int main()
{
    FAST

    ll t;
    cin>>t;

    while(t--)
    {
        string a, b;
        cin>>a>>b;
        ll n = a.size();
        ll m = b.size();
        ll ans = n+m;
        for(ll i = 0;i<n;i++)
        {
            for(ll j = n-i;j>=1;j--)
            {
                for(ll k = 0;k<m;k++)
                {
                    for(ll l = m-k;l>=1;l--)
                    {
                        if( a.substr(i,j) == b.substr(k,l))
                        {
                            //cout<<a.substr(i,j)<<endl;
                            ans = min(ans,n+m-2*j);
                            //cout<<a.substr(i,j)<<" "<<ans<<endl;
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}


