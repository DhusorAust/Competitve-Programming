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
int n;
int arr[20];
int sum = 0;
int dp[(1 << 20) + 2];
int f(int mask)
{
    int tot = 0;
    for(int j=0;j<n;j++)
    {
        if(!check(mask,j))
            tot+=arr[j];
    }
    if (mask == (1 << n) - 1)
        return dp[mask] = 0;
    if(dp[mask]!=-1)
        return dp[mask];
    int mn = INT_MAX;
    for(int i=0;i<n;i++)
    {
        int a = 0;
        int cnt = 0;
        int mask2 = mask;
        if(!check(mask2,i))
        {
            mask2 = Set(mask2,i);
            cnt += arr[i];
        }
        if(!check(mask2,(i+1)%n))
        {
            mask2 = Set(mask2,(i+1)%n);
            cnt+=arr[(i+1)%n];
        }
        if(!check(mask2,(i+2)%n))
        {
            mask2 = Set(mask2,(i+2)%n);
            cnt+=arr[(i+2)%n];
        }
        if(cnt!=0)
        {
            a = f(mask2);
            mn = min(mn,a+tot-cnt);
        }
    }
    return dp[mask] = mn;
}
int main()
{
    FAST
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    memset(dp, -1 ,sizeof dp);
    cout<<f(0)<<endl;
    return 0;
}

