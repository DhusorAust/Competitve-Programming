#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fout freopen("output.txt","w",stdout)
#define fin  freopen("input.txt","r",stdin)
//priority_queue<int, vector<int>, greater<int> > min_q;

 string longestPalindrome(string s) {
     int ans = 1;
     int I = 0;
     int n = s.size();
     int dp[n][n];
     memset(dp,0,sizeof dp);
     for(int i = 0;i<n;i++)
        dp[i][i] = 1;
     for(int i = 1;i<n;i++)
     {
         if(s[i]==s[i-1])
         {
             dp[i-1][i] = 1;
             I = i-1;
             ans = 2;
         }
     }
     for(int k = 3;k<=n;k++)
     {
         for(int i = 0,j = k-1;j<n;j++,i++)
         {
             if(s[i]==s[j] && dp[i+1][j-1])
             {
                 dp[i][j] = 1;
                 I = i;
                 ans = k;
             }
         }
     }
     return s.substr(I,ans);
}

int main()
{
    FAST
    string s;
    cin>>s;
    cout<<longestPalindrome(s)<<endl;
    return 0;
}

