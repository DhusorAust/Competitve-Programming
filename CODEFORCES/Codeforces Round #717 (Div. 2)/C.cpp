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
//priority_queue<int, vector<int>, greater<int> > min_q;
 ll n;
 ll arr[105];
 ll sum = 0;
 ll dp[105][200005];
ll f(ll i, ll s)
{
    if(dp[i][s]!=-1)
        return dp[i][s];
    if(i==n)
    {
        if(s==sum-s)
            return dp[i][s] = 1;
        return dp[i][s] = 0;
    }
    ll a, b;
    a = f(i+1,s);
    b = f(i+1,s+arr[i]);
    return dp[i][s] = max(a,b);
}
int main()
{
    FAST

    cin>>n;

    for(ll i = 0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];

    }
    if(sum%2)
    {
        cout<<"0"<<endl;
        return 0;
    }
    memset(dp,-1,sizeof dp);
    if(!f(0,0))
    {
        cout<<"0"<<endl;
        return 0;
    }

    ll cnt2 = INT_MAX;
    for(ll i =0 ;i<n;i++)
    {
        ll x = arr[i];
        ll cnt = 0;
        while(x%2==0)
        {
            x/=2;
            cnt++;
        }
        cnt2 = min(cnt2,cnt);
    }
    ll p = 1;
    while(cnt2--)
    {
        p*=2;
    }
    ll ans;
    for(ll i =0 ;i<n;i++)
    {
        arr[i]/=p;
        if(arr[i]%2)
            ans = i+1;
    }
    cout<<1<<endl<<ans<<endl;
    return 0;
}
