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
ll arr[3009];
ll dp[3009][3009][5];
ll f(ll i, ll j, ll cnt)
{
    if(dp[i][j][cnt] != -1)
        return dp[i][j][cnt];
    if(i==j)
    {
        if(cnt==0)
            return dp[i][j][cnt] = arr[i];
        return dp[i][j][cnt] = 0;
    }
    ll a = f(i+1,j,1-cnt);
    ll b = f(i,j-1,1-cnt);
    if(cnt==0)
        return dp[i][j][cnt] = max(a+arr[i],b+arr[j]);
    return dp[i][j][cnt] = min(a,b);
}
int main()
{
    FAST
    memset(dp,-1,sizeof dp);
    cin>>n;
    ll sum = 0;
    for(ll i = 0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    cout<<2*f(0,n-1,0)-sum<<endl;
    return 0;
}
