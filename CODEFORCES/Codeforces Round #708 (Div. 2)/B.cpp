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
        ll n,M;
        cin>>n>>M;
        ll arr[n], arr2[n];
        map<ll,ll> m;
        for(ll i = 0;i<n;i++)
        {
            cin>>arr[i];
            arr2[i] = arr[i]%M;
            m[arr2[i]]++;
        }
       /* for(ll i =0 ;i<M;i++)
        {
            cout<<i<<": "<<m[i]<<endl;;
        }
        cout<<endl;*/
        ll ans = 0;
        for(ll i = 1,j=M-1;i<=M/2;i++,j--)
        {
            if(M%2==0 && i==M/2) break;
            if(m[i] ==0 && m[j]==0)
                continue;
            if(m[i]==0)
            {
                ans+=m[j];
                continue;
            }

            if(m[j]==0)
            {
                ans+=m[i];
                continue;
            }


            if(m[i]== m[j])
                ans++;
            else if(m[i]>m[j])
            {
                ans++;
                ans += m[i]-m[j]-1;
            }
            else
            {
                ans++;
                ans += m[j]-m[i]-1;
            }
        }
        if(m[0]!=0)
            ans++;
        if(M%2==0 && m[M/2]!=0)
            ans++;
        cout<<ans<<endl;
    }

    return 0;
}

