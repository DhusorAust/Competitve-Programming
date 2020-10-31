#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
ll arr[209];
ll n;
ll dp[409][209];

ll arr2(ll i)
{
    return i+1;
}

ll f (ll i, ll cnt)
{
    if(dp[i][cnt]!=-1)
        return dp[i][cnt];

    if(cnt==n)
        return dp[i][cnt] = 0;
    if(i==401)
        return dp[i][cnt] = INT_MAX;

    ll a = 0;
    ll b = 0;

    a = f(i+1,cnt+1);
    b = f(i+1,cnt);

    return dp[i][cnt] = min(a+abs(arr[cnt]-arr2(i)),b);

}


int main()
{
    FAST

    int t;
    cin>>t;

    while(t--)
    {
        memset(arr,0,sizeof arr);
        cin>>n;

        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr,arr+n);
        memset(dp, -1, sizeof dp);
        cout<< f(0,0)<<endl;
    }


    return 0;
}

