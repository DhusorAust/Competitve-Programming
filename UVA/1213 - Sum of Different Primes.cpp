#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);


ll isPrime[1130];
vector<ll> prime;
void sieve(ll n)
{
    isPrime[2] = 1;
    for(ll i=3;i<=n;i+=2)
        isPrime[i] = 1;
    for (ll p=3; p*p<=n; p+=2)
    {
        if (isPrime[p] == 1)
        {
            for (ll i=p*p; i<=n; i += 2*p)
                isPrime[i] = 0;
        }
    }
    prime.push_back(2);
    for(ll i=3;i<=n;i+=2)
    {
        if(isPrime[i])
            prime.push_back(i);
    }
}
ll n, k;
ll dp[190][1130][20];

ll f(ll i, ll n, ll k)
{
    if(dp[i][n][k] !=-1)
        return dp[i][n][k];
    if(i==prime.size())
        return dp[i][n][k] =   0;
    ll a = 0, b = 0, c = 0;
    b = f(i+1,n,k);
    if(n>=prime[i] && k>=1 )
    c = f(i+1,n-prime[i],k-1);
    if(n==prime[i] && k==0)
        a = 1;
    return dp[i][n][k] =a+b+c;
}

int main()
{

    FAST
    sieve(1120);
    while(cin>>n>>k)
    {
        if(n==0 && k==0)
        {
            break;
        }

        memset(dp, -1 , sizeof dp);

        cout <<f(0,n,k-1)<<endl;
    }

    return 0;
}

