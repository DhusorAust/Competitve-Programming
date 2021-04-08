#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
ll ans[10009];
int main()
{
    FAST
    ll t;
    cin>>t;
    while(t--)
    {
        memset(ans, -1 , sizeof ans);
        ll n, k;
        cin>>n>>k;
        ll arr[n];
        for(ll i = 0;i<n;i++)
        {
            cin>>arr[i];
        }
        ll cnt = 1;
        while(true)
        {
            bool b = true;
            for(ll i = 1;i<n;i++)
            {
                if(arr[i]>arr[i-1])
                {
                    b = false;
                    arr[i-1]++;
                    ans[cnt] = i;
                    cnt++;
                    break;
                }
            }
            if(b)
                break;
        }
        if(k>10005)
            cout<<-1<<endl;
        else
            cout<<ans[k]<<endl;
    }
    return 0;
}

