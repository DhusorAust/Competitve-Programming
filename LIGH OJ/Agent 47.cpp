#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
ll Set(ll N,ll pos){return N=N | (1<<pos);}
ll reset(ll N,ll pos){return N= N & ~(1<<pos);}
bool check(ll N,ll pos){return (bool)(N & (1<<pos));}
ll n;
ll arr[16];
char arr2[16][16];
ll dp[(1 << 16) + 2];
ll f(ll mask)
{
   if (mask == (1 << n) - 1)
        return dp[mask] = 0;
   if(dp[mask]!=-1)
        return dp[mask];
   ll mn2 = INT_MAX;
   for(ll i=0;i<n;i++)
   {
       ll a = INT_MAX;
       ll mn = INT_MAX;
       if(!check(mask,i))
       {
           mn =arr[i];
           for(ll j=0;j<n;j++)
           {
               if(check(mask,j) && arr2[j][i]!='0')
               {
                   ll div = arr[i]/(arr2[j][i]-48);
                   if(arr[i]%(arr2[j][i]-48)!=0)
                        div++;
                   mn = min(mn,div);
               }
           }
           ll mask2 = Set(mask,i);
           a = f(mask2)+mn;
       }
       mn2 = min(a,mn2);
   }
   return dp[mask] = mn2;
}
int main()
{
    FAST
    ll t;
    cin>>t;
    ll cnt2 = 0;
    while(t--)
    {
        cnt2++;
        cin>>n;
        for(ll i = 0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(ll i = 0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
            {
                cin>>arr2[i][j];
            }
        }
        memset(dp, -1, sizeof dp);
        cout<<"Case "<<cnt2<<": "<<f(0)<<endl;
    }
    return 0;
}

