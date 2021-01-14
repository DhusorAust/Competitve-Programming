#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
int n;
int arr[14][14];
int dp[(1 << 14) + 2];
int f(int mask)
{
   if (mask == (1 << n) - 1)
        return dp[mask] = 0;
   if(dp[mask]!=-1)
        return dp[mask];
   int mn = INT_MAX;
   for(int i=0;i<n;i++)
   {
       int sum = arr[i][i];
       if(!check(mask,i))
       {
           for(int j=0;j<n;j++)
           {
               if(check(mask,j))
                    sum+=arr[i][j];
           }
           int mask2 = Set(mask,i);
           mn = min(mn,f(mask2)+sum);
       }
   }
   return dp[mask] = mn;
}

int main()
{
    int t;
    scanf("%d",&t);
    int cnt2 = 0;
    while(t--)
    {
        cnt2++;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }
        memset(dp, -1 , sizeof dp);
        printf("Case %d: %d\n",cnt2,f(0));
    }

    return 0;
}

