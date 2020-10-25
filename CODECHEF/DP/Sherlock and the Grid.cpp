#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);


int main()
{
    FAST

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        string s[n];

        for(int i=0;i<n;i++)
        {
            cin>>s[i];
        }

        int dp[n][n];
        int dp2[n][n];


        memset(dp,0,sizeof dp);
        memset(dp2,0,sizeof dp2);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(s[i][j]=='#')
                {
                    dp[i][j]= 1;
                    dp2[i][j]= 1;
                }
            }
        }


        for(int i=0;i<n;i++)
        {
            for(int j=n-2;j>=0;j--)
            {
               dp[i][j] += dp[i][j+1];
            }
        }




        for(int j = 0;j<n;j++)
        {
            for(int i=n-2;i>=0;i--)
            {
               dp2[i][j] += dp2[i+1][j];
            }
        }



        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
               if(dp[i][j]==0 && dp2[i][j]==0)
                  cnt++;
            }
        }

        cout<<cnt<<endl;

    }
    return 0;
}

