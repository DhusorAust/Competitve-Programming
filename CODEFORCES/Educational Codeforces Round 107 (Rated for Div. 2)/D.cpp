#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fout freopen("output.txt","w",stdout)
#define fin  freopen("input.txt","r",stdin)
char f(ll a)
{
    return a+96;
}
int main()
{
    FAST
    ll n, k;
    cin>>n>>k;
    bool bol = false;
    ll cnt = 0;
    vector<ll> v;
    while(true)
    {
        if(bol)
            break;
        for(ll i = 1;i<=k;i++)
        {
            v.push_back(i);
            cnt++;
            if(cnt>=n)
            {
                bol = true;
                break;
            }
            for(ll j = i+1;j<=k;j++)
            {
                v.push_back(i);
                v.push_back(j);
                cnt+=2;
                if(cnt>=n)
                {
                    bol = true;
                    break;
                }
            }
            if(bol)
                break;
        }
    }
    for(ll i = 0;i<n;i++)
        cout<<f(v[i]);
    cout<<endl;
    return 0;
}


