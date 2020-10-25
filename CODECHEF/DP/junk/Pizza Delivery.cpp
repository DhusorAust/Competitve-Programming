#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
int n;
int arr1[501];
int arr2[501];
int dp[501][501][501];
int f(int n, int s, int step)
{
     if(dp[n][s][step]!=-1)
         return dp[n][s][step];
     if(s==0)
        return dp[n][s][step] = step;
     if(s<0)
         return dp[n][s][step] = INT_MAX;
     if(n<=0 && s>0)
        return dp[n][s][step] = INT_MAX;
     return  dp[n][s][step] = min(f(n-1,s,step),f(n,s-arr2[n-1],step+1));
}

int main()
{
    FAST
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr1[i];
            arr1[i]*=2;
        }
        for(int i=0;i<n;i++)
        {
            cin>>arr2[i];
        }
        memset(dp,-1,sizeof dp);
        int sum = 0;
        for(int i=0;i<n;i++)
        {
           sum+=f(n,arr1[i],0);
        }
        cout<<sum<<endl;
    }
    return 0;
}

