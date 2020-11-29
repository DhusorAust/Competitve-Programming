#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
ll mod = 1000000007;
ll n2,n;
ll arr2[50];
ll dp[50][5][5];
ll r;

ll f(ll i, ll player, ll status)
{
    if(dp[i][player][status]!=-1)
        return dp[i][player][status]%mod;
    if(i==n2)
    {
        return dp[i][player][status] = 0;
    }

    ll a = 0, b = 0;

    if(i==0 || i%n!=0)
    {
        if(status==1)
        {
            if(arr2[i]!=1)
            {
                a = f(i+1,player,status);
            }

            b = f(i+1,player,1-status);
        }
        else
        {
            if(arr2[i]!=1)
            {
                a =  f(i+1,1-player,status);
            }

            b = f(i+1,1-player,1-status);
        }
    }
    else
    {
        if(status==1)
        {

            if(arr2[i]!=1)
            {
                a =  f(i+1,1-player,status);
            }

            b = f(i+1,1-player,1-status);
        }
        else
        {
            if(arr2[i]!=1)
            {
                a = f(i+1,player,status);
            }

            b = f(i+1,player,1-status);
        }
    }

    if(player==1)
    {
        if(status==1)
        {
            if(arr2[i]%2==0)
            {
                return dp[i][player][status] = (arr2[i]%mod+max(a,b)%mod)%mod;

            }
            else
            {
                return dp[i][player][status] = ((arr2[i]-1)%mod+max(a,b)%mod)%mod;
            }

        }
        else
        {
            if(arr2[i]%2==0)
            {
                return dp[i][player][status] = ((arr2[i]-1)%mod+max(a,b)%mod)%mod;
            }
            else
            {
                return dp[i][player][status] = (arr2[i]%mod+max(a,b)%mod)%mod;

            }
        }
    }
    else
    {
        return dp[i][player][status] = max(a,b)%mod;
    }
}

int main()
{
    FAST

    ll t;
    cin>>t;

    while(t--)
    {
        ll arr[100];
        cin>>n;


        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        ll q;
        cin>>q;

        while(q--)
        {
            cin>>r;
            arr2[0] = 0;
            for(ll i = 1,j = 0;i<=r;i++)
            {
                arr2[i] = arr[j];
                    j = (j+1)%n;
            }

            n2 = r+1;

            memset(dp,-1, sizeof dp);
            cout<<f(0,1,1)%mod<<endl;

        }
    }

    return 0;
}

