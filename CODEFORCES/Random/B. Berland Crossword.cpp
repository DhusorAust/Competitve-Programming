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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,u,r,d,l;
        cin>>n;
        cin>>u>>r>>d>>l;
        bool bol2 = false;
        bitset<4> b;
        for(ll i = 0;i<=15;i++)
        {
            b = i;
            int cnt;
            bool bol = true;
            cnt = b[3]+b[2];
            if(cnt>u || (n-2) < u-cnt )
            { bol = false; continue;}
            cnt = b[2]+b[1];
            if(cnt>r || (n-2) < r-cnt )
            { bol = false; continue;}
            cnt = b[1]+b[0];
            if(cnt>d || (n-2) < d-cnt )
            { bol = false; continue;}
            cnt = b[0]+b[3];
            if(cnt>l || (n-2) < l-cnt )
            { bol = false; continue;}
            if(bol)
            {
                bol2 = true;
                break;
            }
        }
        if(bol2)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}

