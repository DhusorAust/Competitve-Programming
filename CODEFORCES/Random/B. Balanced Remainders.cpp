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
    while( t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        ll m[3] = {0};
        for(ll i = 0;i<n;i++)
        {
            cin>>arr[i];
            m[arr[i]%3]++;
        }
        ll cnt = 0;
        ll x = n/3;
        while(true)
        {
            bool bol = true;
            for(ll i = 0;i<3;i++)
            {
                if(m[i]>x)
                {
                    cnt+= m[i]-x;
                    m[ (i+1) %3]+=m[i]-x;
                    m[i] = x;
                    bol = false;
                }
            }
            if(bol)
                break;
        }
        cout<<cnt<<endl;
    }
    return 0;
}

