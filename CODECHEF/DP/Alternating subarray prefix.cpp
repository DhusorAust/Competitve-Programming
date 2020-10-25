#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);


bool isSame(int a, int b)
{
    if(a> 0 && b>0 || a<0 && b<0)
        return true;
    return false;
}
int main()
{
    FAST
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int dp[n];
        for(int i  = 0;i<n;i++)
            dp[i] = 1;
        for(int i = n-2;i>=0;i--)
        {
            if(!isSame(arr[i],arr[i+1]))
            {
                dp[i] = dp[i+1]+1;
            }
        }
        for(int i=0;i<n;i++)
            cout<<dp[i]<<" ";
        cout<<endl;
    }
    return 0;
}

