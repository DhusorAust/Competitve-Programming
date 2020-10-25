
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
        int n , m;
        cin>>n>>m;

        int rows[n][m];
        int cols[m][n];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>rows[i][j];
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>cols[i][j];
            }
        }

        int ans[n][m];

        for(int i=0;i<n;i++)
        {
              int a = cols[0][i];
              int I;
              for(int k=0;k<n;k++)
              {
                    for(int j=0;j<m;j++)
                    {
                        if(rows[k][j]==a)
                        {   I = k;
                            break;
                        }
                    }
              }

              for(int k=0;k<m;k++)
              {
                  ans[i][k] = rows[I][k];
              }



        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }

    }



    return 0;
}
