#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
int n, k;
int arr[1009];
int dp[1009][1009];
int f(int i, int Xor)
{
   if(i==n-1)
      return  dp[i][Xor] = arr[i]^Xor;

   int val1,val2;

   if(dp[i+1][Xor]==-1)
      dp[i+1][Xor]  = f(i+1,Xor);
   val1 = dp[i+1][Xor];

   if(dp[i+1][arr[i]^Xor]==-1)
        dp[i+1][arr[i]^Xor] = f(i+1,arr[i]^Xor);
   val2 =  dp[i+1][arr[i]^Xor];

   int a = max(val1,val2);

   return dp[i][Xor] =  max(a,arr[i]^Xor);
}
int main()
{
    FAST
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        memset(dp,-1, sizeof dp);
        cout<<max(k,f(0,k))<<endl;
    }
    return 0;
}

