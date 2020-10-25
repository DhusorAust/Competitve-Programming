
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
bool isSame(int a, int b)
{
    if(a> 0 && b>0 || a<0 && b<0)
        return true;
    return false;
}
int n;
int arr[100009];
int dp[100009];
void f(int i)
{
    if(i==n-1)
    {
        dp[i] = 1;
        return ;
    }
    f(i+1);
    if(!isSame(arr[i],arr[i+1]))
    {
        dp[i] = dp[i+1]+1;
    }
    else
    {
        dp[i] = 1;
    }
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
            cin>>arr[i];
        for(int i  = 0;i<n;i++)
            dp[i] = 1;
        f(0);
        for(int i=0;i<n;i++)
            cout<<dp[i]<<" ";
        cout<<endl;
    }
    return 0;
}

