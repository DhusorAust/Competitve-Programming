#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
ll n;
double arr[3005];
double dp[3005][3005];

double f(ll i, ll cnt)
{
    if(i==n)
    {
        if(cnt>(n-cnt))
            return 1;
        else
            return 0;
    }
    if(dp[i][cnt]!=-1)
        return dp[i][cnt];
    double a = f(i+1,cnt+1);
    double b = f(i+1,cnt);
    return dp[i][cnt] = a*arr[i]+b*(1-arr[i]);
}

int main()
{
    FAST
    cin>>n;
    for(ll i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(ll i = 0;i<3005;i++)
    {
        for(ll j = 0;j<3005;j++)
        {
            dp[i][j] = -1;
        }
    }
    cout<<fixed<<setprecision(10)<<f(0,0)<<endl;
    return 0;
}

