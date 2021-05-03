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
#define mod 1000000007
ll dp[200100];
int main()
{
    for(ll i=0;i<=9;i++)
        dp[i] = 1;
    for(ll i = 10;i<=200010;i++)
        dp[i] = ((dp[i-10]%mod) + (dp[i-9]%mod))%mod;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n, m;
        scanf("%lld%lld",&n,&m);
        ll sum = 0;
        while(n!=0)
        {
            ll x = n%10;
            n/=10;
            sum = ((sum%mod) + (dp[m+x]%mod))%mod;
        }
        printf("%lld\n",sum);
    }
    return 0;
}

