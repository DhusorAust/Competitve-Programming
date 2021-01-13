#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
string s;
int n = 12;
int dp[(1 << 13) + 2];
int f(int mask)
{
   if(dp[mask]!=-1)
        return dp[mask];
   int mx = 0;
   for(int i=0;i<n;i++)
   {
       int a = 0, b = 0;
       if(i<= n-3 && check(mask,i) && check(mask,i+1) && !check(mask,i+2) )
       {
           int  mask2 = Set(mask,i+2);
           mask2 = reset(mask2,i+1);
           mask2 = reset(mask2,i);
           a = f(mask2);
       }
       if(i>=2 && check(mask,i) && check(mask,i-1) && !check(mask,i-2) )
       {
           int mask2 = Set(mask,i-2);
           mask2 = reset(mask2,i-1);
           mask2 = reset(mask2,i);
           b =  f(mask2);
       }
       mx = max(max(a,b),mx);
   }
   return dp[mask] = mx+1;
}



int main()
{
    FAST

    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        reverse(s.begin(),s.end());
        int mask = 0;
        int cnt = 0;
        for(int i = 0;i<n;i++)
        {
            if(s[i]=='o')
            {
                mask = Set(mask,i);
                cnt++;
            }
        }
        memset(dp,-1,sizeof dp);
        cout<<cnt-f(mask)+1<<endl;
    }

    return 0;
}



