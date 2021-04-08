#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
//priority_queue<int, vector<int>, greater<int> > min_q;
ll dp[100009];
int main()
{
    FAST
    ll n, k;
    cin>>n>>k;
    ll arr[n];
    for(ll i = 0;i<n;i++)
    {
        cin>>arr[i];
        dp[arr[i]] = 1;
    }
    for(ll i = 0;i<=k;i++)
    {
        for(ll j =0 ;j<n;j++)
        {
            if(i-arr[j]>=0 && dp[i]==0)
            {
                if(!dp[i-arr[j]])
                    dp[i] = 1;
            }
        }
    }
    if(dp[k])
        printf("First\n");
    else
        printf("Second\n");
    return 0;
}

