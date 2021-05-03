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
int main()
{
    FAST
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    ll dp[n][n];
    for(ll i = 0;i<n;i++)
    {
        dp[i][i] = 0;
    }
    for(ll i = 1;i<n;i++)
    {
        for(ll j = 0,k=i;k<n;j++,k++)
        {
            dp[j][k] = arr[k]-arr[j]+min(dp[j+1][k],dp[j][k-1]);
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}

